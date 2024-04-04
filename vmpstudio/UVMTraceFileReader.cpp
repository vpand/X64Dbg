#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>

#include "MiscUtil.h"
#include "StringUtil.h"
#include "UVMTraceFileReaderInternal.h"
#include "UVMTraceWidget.h"
#include "VMPGlobal.h"

static inline mana::ArchType curArch() {
  auto debugee = VMPGlobal::inst()->debugee;
  if (!debugee) return mana::ARM64;
  return debugee->db->archType();
}

TraceFileReader::TraceFileReader(QObject* parent) : QObject(parent) {
  length = 0;
  progress = 0;
  error = true;
  parser = nullptr;
  lastAccessedPage = new TraceFilePage(this, 0, 0);
  lastAccessedIndexOffset = 0;
  hashValue = 0;
  EXEPath.clear();

  int maxModuleSize = (int)ConfigUint("Disassembler", "MaxModuleSize");
  mDisasm = new QBeaEngine(maxModuleSize);
  connect(Config(), SIGNAL(tokenizerConfigUpdated()), this,
          SLOT(tokenizerUpdatedSlot()));
  connect(Config(), SIGNAL(colorsUpdated()), this,
          SLOT(tokenizerUpdatedSlot()));
}

TraceFileReader::~TraceFileReader() {
  delete lastAccessedPage;
  delete mDisasm;
}

bool TraceFileReader::Open(const QString& fileName) {
  if (parser != NULL && parser->isRunning())  // Trace file parser is busy
  {
    parser->requestInterruption();
    parser->wait();
  }
  error = true;
  traceFile.setFileName(fileName);
  traceFile.open(QFile::ReadOnly);
  if (traceFile.isReadable()) {
    parser = new TraceFileParser(this);
    connect(parser, SIGNAL(finished()), this, SLOT(parseFinishedSlot()));
    progress.store(0);
    traceFile.moveToThread(parser);
    parser->start();
    return true;
  } else {
    progress.store(0);
    emit parseFinished();
    return false;
  }
}

void TraceFileReader::Close() { getPage(0, nullptr)->clear(); }

bool TraceFileReader::Delete() {
  if (parser != NULL) {
    parser->requestInterruption();
    parser->wait();
  }
  bool value = traceFile.remove();
  progress.store(0);
  length = 0;
  fileIndex.clear();
  hashValue = 0;
  EXEPath.clear();
  error = false;
  return value;
}

void TraceFileReader::parseFinishedSlot() {
  if (!error)
    progress.store(100);
  else
    progress.store(0);
  delete parser;
  parser = nullptr;
  emit parseFinished();

  // for(auto i : fileIndex)
  // GuiAddLogMessage(QString("%1;%2;%3\r\n").arg(i.first).arg(i.second.first).arg(i.second.second).toUtf8().constData());
}

// Return if the file read was error
bool TraceFileReader::isError() const { return false; }

// Return 100 when loading is completed
int TraceFileReader::Progress() const { return 100; }

// Return the count of instructions
unsigned long long TraceFileReader::Length() {
  return getPage(0, nullptr)->Length();
}

QString TraceFileReader::getIndexText(unsigned long long index) const {
  QString indexString;
  indexString = QString::number(index, 10).toUpper();
  if (length < 16) return indexString;
  int digits;
  digits = floor(log2(length - 1) / 4) + 1;
  digits -= indexString.size();
  while (digits > 0) {
    indexString = '0' + indexString;
    digits = digits - 1;
  }
  return indexString;
}

// Return the hash value of executable to be matched against current executable
duint TraceFileReader::HashValue() const { return hashValue; }

// Return the executable name of executable
const QString& TraceFileReader::ExePath() const { return EXEPath; }

// Return the registers context at a given index
const REGDUMP* TraceFileReader::Registers(unsigned long long index) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  return page->Registers(index - base);
}

static duint regpc_value(const REGDUMP* rd) {
  auto arch = curArch();
  if (arch == mana::ARM64) {
    auto ptr = (RecordItemARM64*)rd;
    return ptr->first;
  } else if (arch == mana::ARM) {
    auto ptr = (RecordItemARM*)rd;
    return ptr->first;
  } else {
    auto ptr = (RecordItemX64*)rd;
    return ptr->first;
  }
}

static uint32 regflags_value(const REGDUMP* rd) {
  auto arch = curArch();
  if (arch == mana::ARM64) {
    auto ptr = (RecordItemARM64*)rd;
    return ptr->second[0].flags;
  } else if (arch == mana::ARM) {
    auto ptr = (RecordItemARM*)rd;
    return ptr->second[0].flags;
  } else {
    auto ptr = (RecordItemX64*)rd;
    return ptr->second[0].flags;
  }
}

duint TraceFileReader::RegPC(const REGDUMP* rd, bool runtime) {
  if (!rd) return 0;
  if (!VMPGlobal::inst()->debugee) return 0;
  auto pc = regpc_value(rd);
  if (runtime) return pc;
  return VMPGlobal::inst()->debugee->db->imageBase() + pc -
         uvmWin->runtimeBase();
}

// Return the opcode at a given index. buffer must be 16 bytes long.
void TraceFileReader::OpCode(unsigned long long index, unsigned char* buffer,
                             int* opcodeSize) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  if (page == nullptr) {
    memset(buffer, 0, 16);
    *opcodeSize = 0;
    return;
  } else
    page->OpCode(index - base, buffer, opcodeSize);
}

// Return the disassembled instruction at a given index.
const Instruction_t& TraceFileReader::Instruction(unsigned long long index) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  // The caller must guarantee page is not null, most likely they have already
  // called some other getters.
  return page->Instruction(index - base, *mDisasm);
}

// Return the thread id at a given index
DWORD TraceFileReader::ThreadId(unsigned long long index) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  if (page == nullptr)
    return 0;
  else
    return page->ThreadId(index - base);
}

// Return the number of recorded memory accesses at a given index
int TraceFileReader::MemoryAccessCount(unsigned long long index) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  if (page == nullptr)
    return 0;
  else
    return page->MemoryAccessCount(index - base);
}

// Return the memory access info at a given index
void TraceFileReader::MemoryAccessInfo(unsigned long long index, duint* address,
                                       duint* oldMemory, duint* newMemory,
                                       bool* isValid) {
  unsigned long long base;
  TraceFilePage* page = getPage(index, &base);
  if (page == nullptr)
    return;
  else
    return page->MemoryAccessInfo(index - base, address, oldMemory, newMemory,
                                  isValid);
}

// Used internally to get the page for the given index and read from disk if
// necessary
TraceFilePage* TraceFileReader::getPage(unsigned long long index,
                                        unsigned long long* base) {
  if (base) *base = 0;
  return lastAccessedPage;
}

void TraceFileReader::tokenizerUpdatedSlot() {
  mDisasm->UpdateConfig();
  for (auto& i : pages) i.second.updateInstructions();
}

// Parser

static bool checkKey(const QJsonObject& root, const QString& key,
                     const QString& value) {
  const auto obj = root.find(key);
  if (obj == root.constEnd()) throw std::wstring(L"Unspecified");
  QJsonValue val = obj.value();
  if (val.isString())
    if (val.toString() == value) return true;
  return false;
}

void TraceFileParser::readFileHeader(TraceFileReader* that) {
  LARGE_INTEGER header;
  bool ok;
  if (that->traceFile.read((char*)&header, 8) != 8)
    throw std::wstring(L"Unspecified");
  if (header.LowPart != MAKEFOURCC('T', 'R', 'A', 'C'))
    throw std::wstring(L"File type mismatch");
  if (header.HighPart > 16384) throw std::wstring(L"Header info is too big");
  QByteArray jsonData = that->traceFile.read(header.HighPart);
  if (jsonData.size() != header.HighPart)
    throw std::wstring(L"JSON header is corrupted");
  QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
  if (jsonDoc.isNull()) throw std::wstring(L"JSON header is corrupted");
  const QJsonObject jsonRoot = jsonDoc.object();

  const auto ver = jsonRoot.find("ver");
  if (ver == jsonRoot.constEnd()) throw std::wstring(L"Version not supported");
  QJsonValue verVal = ver.value();
  if (verVal.toInt(0) != 1) throw std::wstring(L"Version not supported");
  checkKey(jsonRoot, "arch", ArchValue("x86", "x64"));
  checkKey(jsonRoot, "compression", "");
  const auto hashAlgorithmObj = jsonRoot.find("hashAlgorithm");
  if (hashAlgorithmObj != jsonRoot.constEnd()) {
    QJsonValue hashAlgorithmVal = hashAlgorithmObj.value();
    if (hashAlgorithmVal.toString() == "murmurhash") {
      const auto hashObj = jsonRoot.find("hash");
      if (hashObj != jsonRoot.constEnd()) {
        QJsonValue hashVal = hashObj.value();
        QString a = hashVal.toString();
        if (a.startsWith("0x")) {
          a = a.mid(2);
#ifdef _WIN64
          that->hashValue = a.toLongLong(&ok, 16);
#else  // x86
          that->hashValue = a.toLong(&ok, 16);
#endif  //_WIN64
          if (!ok) that->hashValue = 0;
        }
      }
    }
  }
  const auto pathObj = jsonRoot.find("path");
  if (pathObj != jsonRoot.constEnd()) {
    QJsonValue pathVal = pathObj.value();
    that->EXEPath = pathVal.toString();
  }
}

static bool readBlock(QFile& traceFile) {
#if 0
  if (!traceFile.isReadable()) throw std::wstring(L"File is not readable");
  unsigned char blockType;
  unsigned char
      changedCountFlags[3];  // reg changed count, mem accessed count, flags
  if (traceFile.read((char*)&blockType, 1) != 1)
    throw std::wstring(L"Read block type failed");
  if (blockType == 0) {
    if (traceFile.read((char*)&changedCountFlags, 3) != 3)
      throw std::wstring(L"Read flags failed");
    // skipping: thread id, registers
    if (traceFile.seek(traceFile.pos() +
                       ((changedCountFlags[2] & 0x80) ? 4 : 0) +
                       (changedCountFlags[2] & 0x0F) +
                       changedCountFlags[0] * (1 + sizeof(duint))) == false)
      throw std::wstring(L"Unspecified");
    QByteArray memflags;
    memflags = traceFile.read(changedCountFlags[1]);
    if (memflags.length() < changedCountFlags[1])
      throw std::wstring(L"Read memory flags failed");
    unsigned int skipOffset = 0;
    for (unsigned char i = 0; i < changedCountFlags[1]; i++)
      skipOffset += ((memflags[i] & 1) == 1) ? 2 : 3;
    if (traceFile.seek(traceFile.pos() + skipOffset * sizeof(duint)) == false)
      throw std::wstring(L"Unspecified");
    // Gathered information, build index
    if (changedCountFlags[0] ==
        (FIELD_OFFSET(REGDUMP, lastError) + sizeof(DWORD)) / sizeof(duint))
      return true;
    else
      return false;
  } else
    throw std::wstring(L"Unsupported block type");
#endif
  return false;
}

void TraceFileParser::run() {
  TraceFileReader* that = dynamic_cast<TraceFileReader*>(parent());
  unsigned long long index = 0;
  unsigned long long lastIndex = 0;
  if (that == NULL) {
    return;  // Error
  }
  try {
    if (that->traceFile.size() == 0) throw std::wstring(L"File is empty");
    // Process file header
    readFileHeader(that);
    // Update progress
    that->progress.store(that->traceFile.pos() * 100 / that->traceFile.size());
    // Process file content
    while (!that->traceFile.atEnd()) {
      quint64 blockStart = that->traceFile.pos();
      bool isPageBoundary = readBlock(that->traceFile);
      if (isPageBoundary) {
        if (lastIndex != 0)
          that->fileIndex.back().second.second = index - (lastIndex - 1);
        that->fileIndex.push_back(
            std::make_pair(index, TraceFileReader::Range(blockStart, 0)));
        lastIndex = index + 1;
        // Update progress
        that->progress.store(that->traceFile.pos() * 100 /
                             that->traceFile.size());
        if (that->progress == 100) that->progress = 99;
        if (this->isInterruptionRequested() &&
            !that->traceFile.atEnd())  // Cancel loading
          throw std::wstring(L"Canceled");
      }
      index++;
    }
    if (index > 0)
      that->fileIndex.back().second.second = index - (lastIndex - 1);
    that->error = false;
    that->length = index;
    that->progress = 100;
  } catch (const std::wstring& errReason) {
    // MessageBox(0, errReason.c_str(), L"debug", MB_ICONERROR);
    that->error = true;
  } catch (std::bad_alloc&) {
    that->error = true;
  }

  that->traceFile.moveToThread(that->thread());
}

// Remove last page from memory and read from disk again to show updates
void TraceFileReader::purgeLastPage() {
  unsigned long long index = 0;
  unsigned long long lastIndex = 0;
  bool isBlockExist = false;
  if (length > 0) {
    index = fileIndex.back().first;
    const auto lastpage = pages.find(Range(index, index));
    if (lastpage != pages.cend()) {
      // Purge last accessed page
      if (index == lastAccessedIndexOffset) lastAccessedPage = nullptr;
      // Remove last page from page cache
      pages.erase(lastpage);
    }
    // Seek start of last page
    traceFile.seek(fileIndex.back().second.first);
    // Remove last page from file index cache
    fileIndex.pop_back();
  }
  try {
    while (!traceFile.atEnd()) {
      quint64 blockStart = traceFile.pos();
      bool isPageBoundary = readBlock(traceFile);
      if (isPageBoundary) {
        if (lastIndex != 0)
          fileIndex.back().second.second = index - (lastIndex - 1);
        fileIndex.push_back(
            std::make_pair(index, TraceFileReader::Range(blockStart, 0)));
        lastIndex = index + 1;
        isBlockExist = true;
      }
      index++;
    }
    if (isBlockExist) fileIndex.back().second.second = index - (lastIndex - 1);
    error = false;
    length = index;
  } catch (std::wstring& errReason) {
    error = true;
  }
}

// TraceFilePage
TraceFilePage::TraceFilePage(TraceFileReader* parent,
                             unsigned long long fileOffset,
                             unsigned long long maxLength) {
  lastOpcodes = nullptr;
  lastPage = 0;
}

unsigned long long TraceFilePage::Length() {
  auto arch = curArch();
  size_t realsize;
  if (arch == mana::ARM64)
    realsize = uvmWin->mRecordARM64Cur.size();
   else if (arch == mana::ARM)
    realsize = uvmWin->mRecordARMCur.size();
  else
    realsize = uvmWin->mRecordX64Cur.size();
  if (mRegisters.size() == realsize) return realsize;

  mRegisters.clear();
  if (arch == mana::ARM64) {
    for (auto& it : uvmWin->mRecordARM64Cur) {
      mRegisters.push_back(&it);
    }
  } else if (arch == mana::ARM) {
    for (auto& it : uvmWin->mRecordARMCur) {
      mRegisters.push_back(&it);
    }
  } else {
    for (auto& it : uvmWin->mRecordX64Cur) {
      mRegisters.push_back(&it);
    }
  }
  return mRegisters.size();
}

const REGDUMP* TraceFilePage::Registers(unsigned long long index) {
  if (index >= Length()) return nullptr;
  return mRegisters.at(index);
}

duint TraceFilePage::OpCode(unsigned long long index, unsigned char* buffer,
                            int* opcodeSize) {
  if (index < this->opcodeSize.size()) {
    *opcodeSize = this->opcodeSize.at(index);
  } else {
    auto arch = curArch();
    if (arch == mana::X86 || arch == mana::X86_64) {
      *opcodeSize = 16;
    }
    else {
      *opcodeSize = 4;
    }
  }

  duint pc = regpc_value(Registers(index));
  duint page = pc & ~UVMPAGE_MASK;
  if (page && page == lastPage) {
    memcpy(buffer, lastOpcodes + pc - page, *opcodeSize);
    return pc;
  }
  auto found = uvmWin->mPageBuffs.find(page);
  if (found != uvmWin->mPageBuffs.end()) {
    lastPage = page;
    lastOpcodes = found->second.data();
    memcpy(buffer, lastOpcodes + pc - page, *opcodeSize);
  } else {
    memset(buffer, 0, *opcodeSize);
    return 0;
  }
  return pc;
}

const Instruction_t& TraceFilePage::Instruction(unsigned long long index,
                                                QBeaEngine& mDisasm) {
  size_t inscount = Length();
  if (instructions.size() != inscount) {
    instructions.clear();
    opcodeSize.clear();
    instructions.reserve(inscount);
    auto arch = curArch();
    auto imagebase = VMPGlobal::inst()->debugee->db->imageBase();
    bool isarm = arch == mana::ARM;
    for (unsigned long long i = 0; i < inscount; i++) {
      unsigned char tmpbuff[16];
      int tmplen;
      duint pc = OpCode(i, tmpbuff, &tmplen);
      if (!pc) {
        static Instruction_t emptyi;
        return emptyi;
      }
      instructions.emplace_back(mDisasm.DisassembleAt(
          tmpbuff, tmplen, pc - uvmWin->runtimeBase(),
          isarm ? ((regflags_value(Registers(i)) & 0x20) != 0) : false));
      opcodeSize.push_back(instructions.rbegin()->opcodeSize);
    }
  }
  return instructions.at(index);
}

DWORD TraceFilePage::ThreadId(unsigned long long index) const { return 0; }

int TraceFilePage::MemoryAccessCount(unsigned long long index) const {
  return 0;
}

void TraceFilePage::MemoryAccessInfo(unsigned long long index, duint* address,
                                     duint* oldMemory, duint* newMemory,
                                     bool* isValid) const {}

void TraceFilePage::updateInstructions() { instructions.clear(); }

void TraceFilePage::clear() {
  instructions.clear();
  mRegisters.clear();
  opcodeSize.clear();
}
