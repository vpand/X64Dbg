#include "TraceRecord.h"

#include "disasm_fast.h"
#include "disasm_helper.h"
// #include "memory.h"
// #include "module.h"
// #include "plugin_loader.h"
#include "stringformat.h"
// #include "thread.h"
// #include "threading.h"
#include "value.h"
#include "../bridge/_global.h"
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

#define dprintf(...)
#define dputs(...)
#define emalloc(size, ...) malloc(size)
#define efree(ptr, ...) free(ptr)

#if __APPLE__ || __linux__
#define InterlockedIncrement(ptr) (*ptr)++

#include <sys/fcntl.h>
#include <sys/stat.h>
#undef CreateFileA
#define CreateFileA(path, ...) CreateFileAImpl(path)
static HANDLE CreateFileAImpl(const char *path) {
  int fd = open(path, O_APPEND | O_CREAT | O_RDWR, S_IRWXU);
  return (HANDLE)(long)fd;
}

#undef WriteFile
static void WriteFile(HANDLE fp, const void *ptr, size_t size, DWORD *written, void *ptr2) {
  (void)ptr2;
  *written = write((int)(long)fp, ptr, size);
  fsync((int)(long)fp);
}

#undef GetFileSizeEx
static bool GetFileSizeEx(HANDLE fp, LARGE_INTEGER *size) {
  struct stat st;
  fstat((int)(long)fp, &st);
  size->QuadPart = st.st_size;
  return true;
}

#undef CloseHandle
#define CloseHandle(fp) close((int)(long)fp)

#endif

#define EXCLUSIVE_ACQUIRE(...)
#define SHARED_ACQUIRE(...)
#define SHARED_RELEASE()
#define ThreadGetId(...) 0

#define MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP (512 * 3)

static TraceRecordManager trmgr;

TraceRecordManager::TraceRecordManager() { ModuleNames.emplace_back(""); }

TraceRecordManager::~TraceRecordManager() { clear(); }

void TraceRecordManager::clear() {
  EXCLUSIVE_ACQUIRE(LockTraceRecord);
  for (auto i = TraceRecord.begin(); i != TraceRecord.end(); ++i)
    efree(i->second.rawPtr, "TraceRecordManager");
  TraceRecord.clear();
  ModuleNames.clear();
  ModuleNames.emplace_back("");
}

static void dbgtracebrowserneedsupdate() {
  static QTime time = QTime::currentTime();
  QTime curtime = QTime::currentTime();
  if (time.secsTo(curtime) > 0) {
    time = curtime;
    GuiUpdateTraceBrowser();
  }
}

bool TraceRecordManager::setTraceRecordType(duint pageAddress,
                                            TraceRecordType type) {
  EXCLUSIVE_ACQUIRE(LockTraceRecord);
  pageAddress &= ~((duint)4096 - 1);
  auto pageInfo = TraceRecord.find(ModHashFromAddr(pageAddress));
  if (pageInfo == TraceRecord.end()) {
    if (type != TraceRecordType::TraceRecordNone) {
      TraceRecordPage newPage;
      char modName[MAX_MODULE_SIZE];
      switch (type) {
        case TraceRecordBitExec:
          newPage.rawPtr = emalloc(4096 / 8, "TraceRecordManager");
          memset(newPage.rawPtr, 0, 4096 / 8);
          break;
        case TraceRecordByteWithExecTypeAndCounter:
          newPage.rawPtr = emalloc(4096, "TraceRecordManager");
          memset(newPage.rawPtr, 0, 4096);
          break;
        case TraceRecordWordWithExecTypeAndCounter:
          newPage.rawPtr = emalloc(4096 * 2, "TraceRecordManager");
          memset(newPage.rawPtr, 0, 4096 * 2);
          break;
        default:
          return false;
      }
      newPage.dataType = type;
      if (ModNameFromAddr(pageAddress, modName, true)) {
        newPage.rva = pageAddress - ModBaseFromAddr(pageAddress);
        newPage.moduleIndex = getModuleIndex(std::string(modName));
      } else
        newPage.moduleIndex = ~0;

      auto inserted = TraceRecord.insert(
          std::make_pair(ModHashFromAddr(pageAddress), newPage));
      if (inserted.second ==
          false)  // we failed to insert new page into the map
      {
        efree(newPage.rawPtr);
        return false;
      }
      return true;
    } else
      return true;
  } else {
    if (type == TraceRecordType::TraceRecordNone) {
      if (pageInfo != TraceRecord.end()) {
        efree(pageInfo->second.rawPtr, "TraceRecordManager");
        TraceRecord.erase(pageInfo);
      }
      return true;
    } else
      return pageInfo->second.dataType ==
             type;  // Can't covert between data types
  }
}

TraceRecordManager::TraceRecordType TraceRecordManager::getTraceRecordType(
    duint pageAddress) {
  SHARED_ACQUIRE(LockTraceRecord);
  if (!TraceRecord.size()) return TraceRecordNone;

  pageAddress &= ~((duint)4096 - 1);
  auto pageInfo = TraceRecord.find(ModHashFromAddr(pageAddress));
  if (pageInfo == TraceRecord.end())
    return TraceRecordNone;
  else
    return pageInfo->second.dataType;
}

void TraceRecordManager::TraceExecute(duint address, duint size) {
  SHARED_ACQUIRE(LockTraceRecord);
  if (size == 0) return;
  duint base = address & ~((duint)4096 - 1);
  auto pageInfoIterator = TraceRecord.find(ModHashFromAddr(base));
  if (pageInfoIterator == TraceRecord.end()) return;
  TraceRecordPage pageInfo;
  pageInfo = pageInfoIterator->second;
  duint offset = address - base;
  bool isMixed;
  if ((offset + size) >
      4096)  // execution crossed page boundary, splitting into 2 sub calls.
             // Noting that byte type may be mislabelled.
  {
    SHARED_RELEASE();
    TraceExecute(address, 4096 - offset);
    TraceExecute(base + 4096, size + offset - 4096);
    return;
  }
  isMixed = false;
  switch (pageInfo.dataType) {
    case TraceRecordType::TraceRecordBitExec:
      for (unsigned char i = 0; i < size; i++)
        *((char*)pageInfo.rawPtr + (i + offset) / 8) |= 1 << ((i + offset) % 8);
      break;

    case TraceRecordType::TraceRecordByteWithExecTypeAndCounter:
      for (unsigned char i = 0; i < size; i++) {
        TraceRecordByteType_2bit currentByteType;
        if (isMixed)
          currentByteType = TraceRecordByteType_2bit::_InstructionOverlapped;
        else if (i == 0)
          currentByteType = TraceRecordByteType_2bit::_InstructionHeading;
        else if (i == size - 1)
          currentByteType = TraceRecordByteType_2bit::_InstructionTailing;
        else
          currentByteType = TraceRecordByteType_2bit::_InstructionBody;

        char* data = (char*)pageInfo.rawPtr + offset + i;
        if (*data == 0) {
          *data = (char)currentByteType << 6 | 1;
        } else {
          isMixed |= (*data & 0xC0) >> 6 == currentByteType;
          *data = ((char)currentByteType << 6) |
                  ((*data & 0x3F) == 0x3F ? 0x3F : (*data & 0x3F) + 1);
        }
      }
      if (isMixed)
        for (unsigned char i = 0; i < size; i++)
          *((char*)pageInfo.rawPtr + i + offset) |= 0xC0;
      break;

    case TraceRecordType::TraceRecordWordWithExecTypeAndCounter:
      for (unsigned char i = 0; i < size; i++) {
        TraceRecordByteType_2bit currentByteType;
        if (isMixed)
          currentByteType = TraceRecordByteType_2bit::_InstructionOverlapped;
        else if (i == 0)
          currentByteType = TraceRecordByteType_2bit::_InstructionHeading;
        else if (i == size - 1)
          currentByteType = TraceRecordByteType_2bit::_InstructionTailing;
        else
          currentByteType = TraceRecordByteType_2bit::_InstructionBody;

        short* data = (short*)pageInfo.rawPtr + offset + i;
        if (*data == 0) {
          *data = (char)currentByteType << 14 | 1;
        } else {
          isMixed |= (*data & 0xC0) >> 6 == currentByteType;
          *data = ((char)currentByteType << 14) |
                  ((*data & 0x3FFF) == 0x3FFF ? 0x3FFF : (*data & 0x3FFF) + 1);
        }
      }
      if (isMixed)
        for (unsigned char i = 0; i < size; i++)
          *((short*)pageInfo.rawPtr + i + offset) |= 0xC000;
      break;

    default:
      break;
  }
}

// See https://www.felixcloutier.com/x86/FXSAVE.html, max 512 bytes
#define memoryContentSize 512

static void HandleZydisOperand(const Zydis& cp, int opindex,
                               DISASM_ARGTYPE* argType, duint* value,
                               unsigned char memoryContent[memoryContentSize],
                               unsigned char* memorySize) {
  *value = cp.ResolveOpValue(opindex, [&cp](ZydisRegister reg) {
    auto regName = cp.RegName(reg);
    return regName ? getregister(nullptr, regName)
                   : 0;  // TODO: temporary needs enums + caching
  });
  const auto& op = cp[opindex];
  switch (op.type) {
    case ZYDIS_OPERAND_TYPE_REGISTER:
      *argType = arg_normal;
      break;

    case ZYDIS_OPERAND_TYPE_IMMEDIATE:
      *argType = arg_normal;
      break;

    case ZYDIS_OPERAND_TYPE_POINTER:
      *argType = arg_normal;
      break;

    case ZYDIS_OPERAND_TYPE_MEMORY:
#if 0
    {
      *argType = arg_memory;
      const auto& mem = op.mem;
      if (mem.segment == ArchValue(ZYDIS_REGISTER_FS, ZYDIS_REGISTER_GS)) {
        *value += ThreadGetLocalBase(ThreadGetId(hActiveThread));
      }
      *memorySize = op.size / 8;
      if (*memorySize <= memoryContentSize && DbgMemIsValidReadPtr(*value)) {
        MemRead(*value, memoryContent, max(op.size / 8, sizeof(duint)));
      }
    }
#endif
    break;

    default:
      __debugbreak();
  }
}

template <typename REGDMP, typename REGDMPWORD>
void TraceRecordManager::TraceExecuteRecord(const char *opbuff, int oplen,
                                            REGDMPWORD &rtOldContext,
                                            bool *rtOldContextChanged) {
  if (!isRunTraceEnabled()) return;
  unsigned char WriteBuffer[4096];
  unsigned char* WriteBufferPtr = WriteBuffer;
  // Get current data
  REGDMPWORD newContext;
  // DISASM_INSTR newInstruction;
  DWORD newThreadId;
  const size_t memoryArrayCount = 32;
  duint newMemory[memoryArrayCount];
  duint newMemoryAddress[memoryArrayCount];
  duint oldMemory[memoryArrayCount];
  unsigned char newMemoryArrayCount = 0;
  memcpy(&newContext.registers, DbgGetRegDumpEx(&newContext.registers, sizeof(REGDMP)), sizeof(REGDMP));
  newThreadId = ThreadGetId(hActiveThread);
#if 0
  // Don't try to resolve memory values for invalid/lea/nop instructions
  if (newInstruction.Success() && !newInstruction.IsNop() &&
      newInstruction.GetId() != ZYDIS_MNEMONIC_LEA) {
    DISASM_ARGTYPE argType;
    duint value;
    unsigned char memoryContent[memoryContentSize];
    unsigned char memorySize;
    for (int i = 0; i < newInstruction.OpCount(); i++) {
      memset(memoryContent, 0, sizeof(memoryContent));
      HandleZydisOperand(newInstruction, i, &argType, &value, memoryContent,
                         &memorySize);
      // check for overflow of the memory buffer
      if (newMemoryArrayCount * sizeof(duint) + memorySize >
          memoryArrayCount * sizeof(duint))
        continue;
      // TODO: Implicit memory access by push and pop instructions
      // TODO: Support memory value of ??? for invalid memory access
      if (argType == arg_memory) {
        if (memorySize <= sizeof(duint)) {
          memcpy(&newMemory[newMemoryArrayCount], memoryContent, sizeof(duint));
          newMemoryAddress[newMemoryArrayCount] = value;
          newMemoryArrayCount++;
        } else
          for (unsigned char index = 0;
               index < memorySize / sizeof(duint) +
                           ((memorySize % sizeof(duint)) > 0 ? 1 : 0);
               index++) {
            memcpy(&newMemory[newMemoryArrayCount],
                   memoryContent + sizeof(duint) * index, sizeof(duint));
            newMemoryAddress[newMemoryArrayCount] =
                value + sizeof(duint) * index;
            newMemoryArrayCount++;
          }
      }
    }
    if (newInstruction.GetId() == ZYDIS_MNEMONIC_PUSH ||
        newInstruction.GetId() == ZYDIS_MNEMONIC_PUSHF ||
        newInstruction.GetId() == ZYDIS_MNEMONIC_PUSHFD ||
        newInstruction.GetId() == ZYDIS_MNEMONIC_PUSHFQ ||
        newInstruction.GetId() ==
            ZYDIS_MNEMONIC_CALL  // TODO: far call accesses 2 stack entries
    ) {
      MemRead(newContext.registers.regcontext.csp - sizeof(duint),
              &newMemory[newMemoryArrayCount], sizeof(duint));
      newMemoryAddress[newMemoryArrayCount] =
          newContext.registers.regcontext.csp - sizeof(duint);
      newMemoryArrayCount++;
    } else if (newInstruction.GetId() == ZYDIS_MNEMONIC_POP ||
               newInstruction.GetId() == ZYDIS_MNEMONIC_POPF ||
               newInstruction.GetId() == ZYDIS_MNEMONIC_POPFD ||
               newInstruction.GetId() == ZYDIS_MNEMONIC_POPFQ ||
               newInstruction.GetId() == ZYDIS_MNEMONIC_RET) {
      MemRead(newContext.registers.regcontext.csp,
              &newMemory[newMemoryArrayCount], sizeof(duint));
      newMemoryAddress[newMemoryArrayCount] =
          newContext.registers.regcontext.csp;
      newMemoryArrayCount++;
    }
    // TODO: PUSHAD/POPAD
    assert(newMemoryArrayCount < memoryArrayCount);
  }
#endif
  if (rtPrevInstAvailable) {
    for (unsigned char i = 0; i < rtOldMemoryArrayCount; i++) {
      MemRead(rtOldMemoryAddress[i], oldMemory + i, sizeof(duint));
    }
    // Delta compress registers
    // Data layout is Structure of Arrays to gather the same type of data in
    // continuous memory to improve RLE compression performance. 1byte:block
    // type,1byte:reg changed count,1byte:memory accessed
    // count,1byte:flags,4byte/none:threadid,string:opcode,1byte[]:position,ptrbyte[]:regvalue,1byte[]:flags,ptrbyte[]:address,ptrbyte[]:oldmem,ptrbyte[]:newmem

    // Always record state of LAST INSTRUCTION! (NOT current instruction)
    unsigned char changed = 0;
    for (unsigned char i = 0; i < _countof(rtOldContext.regword); i++) {
      // rtRecordedInstructions - 1 hack: always record full registers dump at
      // first instruction (recorded at 2nd instruction execution time) prints
      // ASCII table in run trace at first instruction :)
      if (rtOldContext.regword[i] != newContext.regword[i] ||
          rtOldContextChanged[i] ||
          ((rtRecordedInstructions - 1) %
               MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP ==
           0))
        changed++;
    }
    unsigned char blockFlags = 0;
    if (newThreadId != rtOldThreadId ||
        ((rtRecordedInstructions - 1) % MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP ==
         0))
      blockFlags = 0x80;
    blockFlags |= rtOldOpcodeSize;

    WriteBufferPtr[0] = 0;                      // 1byte: block type
    WriteBufferPtr[1] = changed;                // 1byte: registers changed
    WriteBufferPtr[2] = rtOldMemoryArrayCount;  // 1byte: memory accesses count
    WriteBufferPtr[3] = blockFlags;             // 1byte: flags and opcode size
    WriteBufferPtr += 4;
    if (newThreadId != rtOldThreadId || rtNeedThreadId ||
        ((rtRecordedInstructions - 1) % MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP ==
         0)) {
      memcpy(WriteBufferPtr, &rtOldThreadId, sizeof(rtOldThreadId));
      WriteBufferPtr += sizeof(rtOldThreadId);
      rtNeedThreadId = (newThreadId != rtOldThreadId);
    }
    memcpy(WriteBufferPtr, rtOldOpcode, rtOldOpcodeSize);
    WriteBufferPtr += rtOldOpcodeSize;
    int lastChangedPosition = -1;                             //-1
    for (int i = 0; i < _countof(rtOldContext.regword); i++)  // 1byte: position
    {
      if (rtOldContext.regword[i] != newContext.regword[i] ||
          rtOldContextChanged[i] ||
          ((rtRecordedInstructions - 1) %
               MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP ==
           0)) {
        WriteBufferPtr[0] = (unsigned char)(i - lastChangedPosition - 1);
        WriteBufferPtr++;
        lastChangedPosition = i;
      }
    }
    for (unsigned char i = 0; i < _countof(rtOldContext.regword);
         i++)  // ptrbyte: newvalue
    {
      if (rtOldContext.regword[i] != newContext.regword[i] ||
          rtOldContextChanged[i] ||
          ((rtRecordedInstructions - 1) %
               MAX_INSTRUCTIONS_TRACED_FULL_REG_DUMP ==
           0)) {
        memcpy(WriteBufferPtr, &rtOldContext.regword[i], sizeof(duint));
        WriteBufferPtr += sizeof(duint);
      }
      rtOldContextChanged[i] =
          (rtOldContext.regword[i] != newContext.regword[i]);
    }
    for (unsigned char i = 0; i < rtOldMemoryArrayCount; i++)  // 1byte: flags
    {
      unsigned char memoryOperandFlags = 0;
      if (rtOldMemory[i] ==
          oldMemory[i])  // bit 0: memory is unchanged, no new memory is saved
        memoryOperandFlags |= 1;
      // proposed flags: is memory valid, is memory zero
      WriteBufferPtr[0] = memoryOperandFlags;
      WriteBufferPtr += 1;
    }
    for (unsigned char i = 0; i < rtOldMemoryArrayCount;
         i++)  // ptrbyte: address
    {
      memcpy(WriteBufferPtr, &rtOldMemoryAddress[i], sizeof(duint));
      WriteBufferPtr += sizeof(duint);
    }
    for (unsigned char i = 0; i < rtOldMemoryArrayCount;
         i++)  // ptrbyte: old content
    {
      memcpy(WriteBufferPtr, &rtOldMemory[i], sizeof(duint));
      WriteBufferPtr += sizeof(duint);
    }
    for (unsigned char i = 0; i < rtOldMemoryArrayCount;
         i++)  // ptrbyte: new content
    {
      if (rtOldMemory[i] != oldMemory[i]) {
        memcpy(WriteBufferPtr, &oldMemory[i], sizeof(duint));
        WriteBufferPtr += sizeof(duint);
      }
    }
  }
  // Switch context buffers
  rtOldThreadId = newThreadId;
  rtOldContext = newContext;
  rtOldMemoryArrayCount = newMemoryArrayCount;
  memcpy(rtOldMemory, newMemory, sizeof(newMemory));
  memcpy(rtOldMemoryAddress, newMemoryAddress, sizeof(newMemoryAddress));
  memcpy(rtOldOpcode, opbuff, oplen);
  rtOldOpcodeSize = oplen;
  // Write to file
  if (rtPrevInstAvailable) {
    if (WriteBufferPtr - WriteBuffer <= sizeof(WriteBuffer)) {
      DWORD written;
      WriteFile(rtFile, WriteBuffer, WriteBufferPtr - WriteBuffer, &written,
                NULL);
      if (written < DWORD(WriteBufferPtr - WriteBuffer))  // Disk full?
      {
        CloseHandle(rtFile);
        String error = stringformatinline(
            StringUtils::sprintf("{winerror@%d}", GetLastError()));
        dprintf(
            QT_TRANSLATE_NOOP("DBG",
                              "Run trace has stopped unexpectedly because "
                              "WriteFile() failed. GetLastError() = %s.\r\n"),
            error.c_str());
        rtEnabled = false;
      }
    } else
      __debugbreak();  // Buffer overrun?
  }
  rtPrevInstAvailable = true;
  rtRecordedInstructions++;

  dbgtracebrowserneedsupdate();
}

unsigned int TraceRecordManager::getHitCount(duint address) {
  SHARED_ACQUIRE(LockTraceRecord);
  if (!TraceRecord.size()) return 0;

  duint base = address & ~((duint)4096 - 1);
  auto pageInfoIterator = TraceRecord.find(ModHashFromAddr(base));
  if (pageInfoIterator == TraceRecord.end())
    return 0;
  else {
    TraceRecordPage pageInfo = pageInfoIterator->second;
    duint offset = address - base;
    switch (pageInfo.dataType) {
      case TraceRecordType::TraceRecordBitExec:
        return ((char*)pageInfo.rawPtr)[offset / 8] & (1 << (offset % 8)) ? 1
                                                                          : 0;
      case TraceRecordType::TraceRecordByteWithExecTypeAndCounter:
        return ((char*)pageInfo.rawPtr)[offset] & 0x3F;
      case TraceRecordType::TraceRecordWordWithExecTypeAndCounter:
        return ((short*)pageInfo.rawPtr)[offset] & 0x3FFF;
      default:
        return 0;
    }
  }
}

TraceRecordManager::TraceRecordByteType TraceRecordManager::getByteType(
    duint address) {
  SHARED_ACQUIRE(LockTraceRecord);
  duint base = address & ~((duint)4096 - 1);
  auto pageInfoIterator = TraceRecord.find(ModHashFromAddr(base));
  if (pageInfoIterator == TraceRecord.end())
    return TraceRecordByteType::InstructionHeading;
  else {
    TraceRecordPage pageInfo = pageInfoIterator->second;
    duint offset = address - base;
    switch (pageInfo.dataType) {
      case TraceRecordType::TraceRecordBitExec:
      default:
        return TraceRecordByteType::InstructionHeading;
      case TraceRecordType::TraceRecordByteWithExecTypeAndCounter:
        return (TraceRecordByteType)(
            (((char*)pageInfo.rawPtr)[offset] & 0xC0) >> 6);
      case TraceRecordType::TraceRecordWordWithExecTypeAndCounter:
        return (TraceRecordByteType)(
            (((short*)pageInfo.rawPtr)[offset] & 0xC000) >> 14);
    }
  }
}

void TraceRecordManager::increaseInstructionCounter() {
  InterlockedIncrement((volatile long*)&instructionCounter);
}

#define json_object_set_new(root, key, val) root.insert(key, val)
#define json_object_set json_object_set_new
#define json_integer(val) QJsonValue(val)
#define json_string(val) QJsonValue(val)
#define json_hex(val) QJsonValue((qint64)val)

#define json_array_append_new(arr, val) arr.append(val)
#define json_array_size(arr) arr.size()

#define json_decref(j)

bool TraceRecordManager::enableRunTrace(bool enabled, const char* fileName) {
  if (enabled) {
    if (rtEnabled) enableRunTrace(false, NULL);  // re-enable run trace
    if (!DbgIsDebugging()) return false;
    rtFile = CreateFileA(fileName,
                         FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_DELETE,
                         NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (rtFile && rtFile != INVALID_HANDLE_VALUE) {
      LARGE_INTEGER size;
      if (GetFileSizeEx(rtFile, &size)) {
        if (size.QuadPart != 0) {
#if __APPLE__ || __linux__
          lseek((int)(long)rtFile, 0, SEEK_END);
#else
          SetFilePointer(rtFile, 0, 0, FILE_END);
#endif
        } else  // file is empty, write some file header
        {
          // ADT$, SIZE, JSON header
          QJsonObject root;
          json_object_set_new(root, "ver", json_integer(1));
          json_object_set_new(root, "hashAlgorithm", json_string("murmurhash"));
          json_object_set_new(root, "hash",
                              json_hex(0/*dbgfunctionsget()->DbGetHash()*/));
          json_object_set_new(root, "compression", json_string(""));      
          switch (DbgGlobal::inst()->debugee->db->info.arch) {
          case mana::ARM:
            json_object_set_new(root, "arch", "arm");
            break;
          case mana::ARM64:
            json_object_set_new(root, "arch", "arm64");
            break;
          case mana::X86:
            json_object_set_new(root, "arch", "x86");
            break;
          default:
            json_object_set_new(root, "arch", "x64");
            break;
          }
          char path[MAX_PATH];
          // ModPathFromAddr(dbgdebuggedbase(), path, MAX_PATH);
          path[0] = 0;
          json_object_set_new(root, "path", json_string(path));
          QJsonDocument jdoc(root);
          QByteArray headerinfo = jdoc.toJson();
          size_t headerinfosize = headerinfo.size();
          LARGE_INTEGER header;
          DWORD written;
          header.LowPart = '$TDA';
          header.HighPart = headerinfosize;
          WriteFile(rtFile, &header, 8, &written, nullptr);
          if (written < 8)  // read-only?
          {
            CloseHandle(rtFile);
            dputs(QT_TRANSLATE_NOOP("DBG",
                                    "Run trace failed to start because file "
                                    "header cannot be written."));
            return false;
          }
          WriteFile(rtFile, headerinfo, headerinfosize, &written, nullptr);
          // json_free(headerinfo);
          // json_decref(root);
          if (written < headerinfosize)  // disk-full?
          {
            CloseHandle(rtFile);
            dputs(QT_TRANSLATE_NOOP("DBG",
                                    "Run trace failed to start because file "
                                    "header cannot be written."));
            return false;
          }
        }
      }
      rtPrevInstAvailable = false;
      rtEnabled = true;
      rtRecordedInstructions = 0;
      rtNeedThreadId = true;
      switch (DbgGlobal::inst()->debugee->db->info.arch) {
      case mana::ARM:
        TraceExecuteRecordInit<REGDUMPA32, REGDUMPWORDA32>(rtOldContextA32, rtOldContextChangedA32);
        break;
      case mana::ARM64:
        TraceExecuteRecordInit<REGDUMPA64, REGDUMPWORDA64>(rtOldContextA64, rtOldContextChangedA64);
        break;
      default:
        TraceExecuteRecordInit<REGDUMPX64, REGDUMPWORDX64>(rtOldContextX64, rtOldContextChangedX64);
        break;
      }
      GuiOpenTraceFile(fileName);
      return true;
    } else {
      String error = stringformatinline(
          StringUtils::sprintf("{winerror@%d}", GetLastError()));
      dprintf(
          QT_TRANSLATE_NOOP(
              "DBG", "Cannot create run trace file. GetLastError() = %s.\r\n"),
          error.c_str());
      return false;
    }
  } else {
    if (rtEnabled) {
      if (rtFile) {
        CloseHandle(rtFile);
      }
      GuiUpdateTraceBrowser();
      rtFile = nullptr;
      rtPrevInstAvailable = false;
      rtEnabled = false;
      dputs(QT_TRANSLATE_NOOP("DBG", "Run trace stopped."));
    }
    return true;
  }
}

template <typename REGDMP, typename REGDMPWORD>
void TraceRecordManager::TraceExecuteRecordInit(REGDMPWORD &rtOldContext, bool *rtOldContextChanged) {
  for (size_t i = 0; i < _countof(rtOldContext.regword); i++)
    rtOldContextChanged[i] = true;
  dprintf(QT_TRANSLATE_NOOP("DBG", "Run trace started. File: %s\r\n"),
          fileName);
  TraceExecuteRecord<REGDMP, REGDMPWORD>(regPC(), rtOldContext, rtOldContextChanged);
}

void TraceRecordManager::saveToDb(QJsonObject &root) {
  EXCLUSIVE_ACQUIRE(LockTraceRecord);
  QJsonArray jsonTraceRecords;
  const char* byteToHex = "0123456789ABCDEF";
  for (auto i : TraceRecord) {
    QJsonObject jsonObj;
    if (i.second.moduleIndex != ~0) {
      json_object_set_new(
          jsonObj, "module",
          json_string(ModuleNames[i.second.moduleIndex].c_str()));
      json_object_set_new(jsonObj, "rva", json_hex(i.second.rva));
    } else {
      json_object_set_new(jsonObj, "module", json_string(""));
      json_object_set_new(jsonObj, "rva", json_hex(i.first));
    }
    json_object_set_new(jsonObj, "type", json_hex((duint)i.second.dataType));
    auto ptr = (unsigned char*)i.second.rawPtr;
    duint size = 0;
    switch (i.second.dataType) {
      case TraceRecordType::TraceRecordBitExec:
        size = 4096 / 8;
        break;
      case TraceRecordType::TraceRecordByteWithExecTypeAndCounter:
        size = 4096;
        break;
      case TraceRecordType::TraceRecordWordWithExecTypeAndCounter:
        size = 4096 * 2;
        break;
      default:
        __debugbreak();  // We have encountered an error condition.
    }
    auto hex = StringUtils::ToCompressedHex(ptr, size);
    json_object_set_new(jsonObj, "data", json_string(hex.c_str()));
    json_array_append_new(jsonTraceRecords, jsonObj);
  }
  if (json_array_size(jsonTraceRecords))
    json_object_set(root, "tracerecord", jsonTraceRecords);

  // Notify garbage collector
  json_decref(jsonTraceRecords);
}

#define json_object_get(root, key) root.find(key)
#define json_hex_value(val) val->toInt()
#define json_string_value(val) val->toString()

void TraceRecordManager::loadFromDb(QJsonObject &root) {
  EXCLUSIVE_ACQUIRE(LockTraceRecord);
  // get the root object
  QJsonObject::iterator tracerecord = json_object_get(root, "tracerecord");

  // return if nothing found
  if (tracerecord == root.end()) return;

  QJsonArray arr = tracerecord.value().toArray();
  for(size_t i = 0; i < arr.size(); i++) {
    QJsonObject value = arr[i].toObject();
    TraceRecordPage currentPage;
    size_t size;
    currentPage.dataType =
        (TraceRecordType)json_hex_value(json_object_get(value, "type"));
    currentPage.rva = (duint)json_hex_value(json_object_get(value, "rva"));
    switch (currentPage.dataType) {
      case TraceRecordType::TraceRecordBitExec:
        size = 4096 / 8;
        break;
      case TraceRecordType::TraceRecordByteWithExecTypeAndCounter:
        size = 4096;
        break;
      case TraceRecordType::TraceRecordWordWithExecTypeAndCounter:
        size = 4096 * 2;
        break;
      default:
        size = 0;
        break;
    }
    if (size != 0) {
      currentPage.rawPtr = emalloc(size, "TraceRecordManager");
      QString p = json_string_value(json_object_get(value, "data"));
      std::vector<unsigned char> data;
      if (StringUtils::FromCompressedHex(p.toUtf8().data(), data) && data.size() == size) {
        memcpy(currentPage.rawPtr, data.data(), size);
        QString moduleName =
            json_string_value(json_object_get(value, "module"));
        duint key;
        if (moduleName.length()) {
          currentPage.moduleIndex = getModuleIndex(std::string(moduleName.toUtf8().data()));
          key = currentPage.rva + ModHashFromName(moduleName.toUtf8().data());
        } else {
          currentPage.moduleIndex = ~0;
          key = currentPage.rva;
        }
        TraceRecord.insert(std::make_pair(key, currentPage));
      } else
        efree(currentPage.rawPtr, "TraceRecordManager");
    }
  }
}

unsigned int TraceRecordManager::getModuleIndex(const std::string& moduleName) {
  auto iterator = std::find(ModuleNames.begin(), ModuleNames.end(), moduleName);
  if (iterator != ModuleNames.end())
    return (unsigned int)(iterator - ModuleNames.begin());
  else {
    ModuleNames.push_back(moduleName);
    return (unsigned int)(ModuleNames.size() - 1);
  }
}

bool TraceRecordManager::isRunTraceEnabled() { return rtEnabled; }

template <typename REGDMP, typename REGDMPWORD>
void TraceRecordManager::TraceExecuteRecord(duint CIP, REGDMPWORD &rtOldContext, bool *rtOldContextChanged) {
  if (getTraceRecordType(CIP) !=
      TraceRecordManager::TraceRecordType::TraceRecordNone) {
    // Zydis instruction;
    unsigned char data[MAX_DISASM_BUFFER];
    if (MemRead(CIP, data, MAX_DISASM_BUFFER)) {
      // instruction.DisassembleSafe(CIP, data, MAX_DISASM_BUFFER);
      ManaFunc tmpfn;
      ManaFunc *fn = nullptr;
      if (sizeof(REGDMP) == sizeof(REGDUMPA32)) {
        fn = &tmpfn;
        fn->info.thumb = ((REGDUMPA32 *)DbgGetRegDumpEx(nullptr, 0))->t;
      }
      int opsize = DbgGlobal::inst()->diser(fn)->disassemble(&data[0], 16);
      if (isRunTraceEnabled()) {
        TraceExecute(CIP, opsize);
        TraceExecuteRecord<REGDMP, REGDMPWORD>((char *)&data[0], opsize, rtOldContext, rtOldContextChanged);
      } else {
        TraceExecute(CIP, opsize);
      }
    }
  } else {
#if 0
    if (isRunTraceEnabled()) {
      // Zydis instruction;
      unsigned char data[MAX_DISASM_BUFFER];
      if (MemRead(CIP, data, MAX_DISASM_BUFFER)) {
        // instruction.DisassembleSafe(CIP, data, MAX_DISASM_BUFFER);
        TraceExecuteRecord<REGDMP, REGDMPWORD>((char *)&data[0], rtOldContext, rtOldContextChanged);
      }
    }
#else
    setTraceRecordType(CIP, TraceRecordWordWithExecTypeAndCounter);
    TraceExecuteRecord<REGDMP, REGDMPWORD>(CIP, rtOldContext, rtOldContextChanged);
    return;
#endif
  }
  increaseInstructionCounter();
}

void _dbg_dbgtraceexecute(duint CIP) {
  if (!_dbg_dbgisRunTraceEnabled()) return;

  auto debugee = DbgGlobal::inst()->debugee;
  if (!debugee) return;

  switch (debugee->db->info.arch) {
  case mana::ARM:
    trmgr.TraceExecuteRecord<REGDUMPA32, TraceRecordManager::REGDUMPWORDA32>(
          CIP,
          trmgr.rtOldContextA32,
          trmgr.rtOldContextChangedA32);
    break;
  case mana::ARM64:
    trmgr.TraceExecuteRecord<REGDUMPA64, TraceRecordManager::REGDUMPWORDA64>(
          CIP,
          trmgr.rtOldContextA64,
          trmgr.rtOldContextChangedA64);
    break;
  default:
    trmgr.TraceExecuteRecord<REGDUMPX64, TraceRecordManager::REGDUMPWORDX64>(
          CIP,
          trmgr.rtOldContextX64,
          trmgr.rtOldContextChangedX64);
    break;
  }
}

unsigned int _dbg_dbggetTraceRecordHitCount(duint address) {
  return trmgr.getHitCount(address);
}

TRACERECORDBYTETYPE _dbg_dbggetTraceRecordByteType(duint address) {
  return (TRACERECORDBYTETYPE)trmgr.getByteType(address);
}

bool _dbg_dbgsetTraceRecordType(duint pageAddress, TRACERECORDTYPE type) {
  return trmgr.setTraceRecordType(
      pageAddress, (TraceRecordManager::TraceRecordType)type);
}

TRACERECORDTYPE _dbg_dbggetTraceRecordType(duint pageAddress) {
  return (TRACERECORDTYPE)trmgr.getTraceRecordType(pageAddress);
}

// When disabled, file name is not relevant and can be NULL
bool _dbg_dbgenableRunTrace(bool enabled, const char* fileName) {
  return trmgr.enableRunTrace(enabled, fileName);
}

bool _dbg_dbgisRunTraceEnabled() { return trmgr.isRunTraceEnabled(); }
