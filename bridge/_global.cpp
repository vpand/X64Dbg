#include "_global.h"

#include <stdio.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

#include "../a64dbg/a64dbg.h"
#include "Bridge.h"

#define USE_FILE_OPCODES 1
#define USE_MEMORY_OPCODES !USE_FILE_OPCODES

extern LLDBEngine *lldb;

#if __APPLE__
#else
#define sleep(s) ::Sleep(s * 1000)
#endif

QString ManaDatabase::moduleName() {
  QFileInfo finfo(path);
  return finfo.fileName();
}

QString ManaDatabase::udPath() {
  char fcrcstr[32];
  sprintf(fcrcstr, "%08x", pathcrc);
  return QString("%1/%2-%3.json")
      .arg(DbgGlobal::inst()->usrdataDir())
      .arg(moduleName())
      .arg(fcrcstr);
}

QString ManaDatabase::pseudoPath() {
  return QString("%1/%2.c")
      .arg(DbgGlobal::inst()->usrdataDir())
      .arg(moduleName());
}

const ManaSect *ManaDatabase::rvaToSection(duint rva) const {
  auto sect = db->sect(0);
  duint fileaddr = db->baseaddr + rva;
  for (int i = 0; i < db->info.nsect; i++) {
    if (sect[i].addr <= fileaddr && fileaddr < sect[i].addr + sect[i].size) {
      return &sect[i];
    }
  }
  return nullptr;
}

const ManaSect *ManaDatabase::foffToSection(duint foff) const {
  auto sect = db->sect(0);
  for (int i = 0; i < db->info.nsect; i++) {
    if (sect[i].fileoff <= foff && foff < sect[i].fileoff + sect[i].size) {
      return &sect[i];
    }
  }
  return nullptr;
}

const ManaFunc *ManaDatabase::rvaToFunction(duint rva, bool eq) {
  if (!db->nfunc) return nullptr;
  if (func_cache && func_cache->rvastart <= rva && rva < func_cache->rvaend) {
    if (eq) {
      return func_cache->rvastart == rva ? func_cache : nullptr;
    }
    return func_cache;
  }

  auto *func = db->func(0);
  int low = 0;
  int high = db->nfunc - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    auto *cur = &func[mid];
    if (cur->rvastart > rva) {
      high = mid - 1;
    } else if (cur->rvaend <= rva) {
      low = mid + 1;
    } else {
      func_cache = cur;
      if (eq) {
        return rva == cur->rvastart ? cur : nullptr;
      }
      return cur;
    }
  }
  return nullptr;
}

const char *ManaDatabase::vaToString(duint va) {
  int low = 0;
  int high = (int)strs.size() - 1;
  if (high < 0 || va < strs[0].first ||
      va >= strs[high].first + strs[high].second.size()) {
    return "";
  }
  while (low <= high) {
    int mid = (low + high) / 2;
    auto *cur = &strs[mid];
    if (cur->first > va) {
      high = mid - 1;
    } else if (cur->first + cur->second.size() <= va) {
      low = mid + 1;
    } else {
      return cur->second.data() + va - cur->first;
    }
  }
  return "";
}

const ManaInsn *ManaDatabase::rvaToInstruction(const ManaFunc *func,
                                               duint dbrva) const {
  unsigned int rva = (unsigned int)dbrva;
  unsigned int frva = rva - func->rvastart;
  if (db->info.arch == mana::ARM64) {
    return db->insn(func, frva / 4);
  }
  auto *insn = db->insn(func, 0);
  int low = 0;
  int high = func->ninsn - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    auto *cur = &insn[mid];
    if (cur->fnoff > frva) {
      high = mid - 1;
    } else if (cur->fnoff + cur->opcodeSize() <= frva) {
      low = mid + 1;
    } else {
      return cur;
    }
  }
  return nullptr;
}

static void bp_set(ManaDatabase *module, duint addr, bool enable,
                   const char *cond) {
  lldb->setBreakpoint(addr, enable, false, cond);
}

#if _WIN32
static bool is_print(char c) {
  QChar qc(c);
  return c > 0 && qc.isPrint();
}
#define isprint is_print
#endif

void ManaDatabase::parse_strings(duint base, const ManaSect *sect,
                                 const char *ptr) {
  ptr += sect->fileoff;
  for (umana32 i = 0; i < sect->size;) {
    if (isprint(ptr[0]) && isprint(ptr[1]) && isprint(ptr[2]) &&
        isprint(ptr[3])) {
      const char *str = ptr;
      int sectoff = i;
      i += 4;
      ptr += 4;
      while (i < sect->size && *ptr) {
        if (isprint(*ptr) || *ptr == '\r' || *ptr == '\n' || *ptr == '\t') {
          if (*ptr == '\r' || *ptr == '\n') {
            *(char *)&*ptr = ' ';
          }
          i++;
          ptr++;
          continue;
        }
        break;
      }
      if (*ptr == 0) {
        strs.emplace_back(
            std::make_pair(rtbase + sect->addr - base + sectoff, ""));
        strs.rbegin()->second = str;
      }
    } else {
      i++;
      ptr++;
    }
  }
}

void ManaDatabase::parse_strings(const QString &path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly)) {
    auto found = DbgGlobal::inst()->mapPath(path);
    if (found) {
      parse_strings(*found);
    }
    return;
  }
  QByteArray buff = file.readAll();
  for (int i = 0; i < db->info.nsect; i++) {
    const ManaSect *sect = db->sect(i);
    if ((duint)(sect->fileoff + sect->size) >= (duint)buff.size() ||
        (duint)sect->fileoff >= (duint)buff.size() ||
        (duint)sect->size >= (duint)buff.size()) {
      // invalid section, may it's encrypted.
      continue;
    }
    parse_strings(db->baseaddr, db->sect(i), buff.data());
  }
  GuiAddLogMessage(QString("Parsed %1 strings in %2.\n")
                       .arg(strs.size())
                       .arg(path)
                       .toUtf8()
                       .data());
}

void ManaDatabase::loadPseudoCode(const QString &path, bool init) {
  QFile srcfile(path);
  if (!srcfile.open(QIODevice::ReadOnly)) {
    return;
  }
  QByteArray buffs = srcfile.readAll();
  QStringList lines = QString(buffs).split('\n');
  duint lastaddr = rtbase;
  for (int i = 0; i < lines.size(); i++) {
    // retdec has 2 format, json or c, we use the simple c format currently
    int addridx = lines[i].indexOf("// 0x");
    if (addridx < 0) {
      lineaddrs.insert({i + 1, lastaddr});
      continue;
    }
    QString saddr = lines[i].mid(addridx + 3, 16);
    duint fileaddr = saddr.toULongLong(nullptr, 16);
    lastaddr = rtbase + fileaddr - db->baseaddr;
    lineaddrs.insert({i + 1, lastaddr});
    addrlines.insert({lastaddr, i + 1});
  }

  if (this == DbgGlobal::inst()->debugee) {
    emit Bridge::getBridge()->loadPseudoSource(path, rtbase);
  }
  if (init) {
    DbgGlobal::inst()->insertPseudoCode(path, this);
  }
}

void ManaDatabase::init(const QString &path, DbgModule *module, unsigned fcrc) {
  DbgGlobal::inst()->debugee = this;
  this->path = path;
  this->pathcrc = fcrc;
  if (module) {
    rtbase = module->startAddress;
  } else {
    rtbase = db->baseaddr;
  }
  QFile udfile(udPath());
  if (udfile.open(QIODevice::ReadOnly)) {
    QByteArray udbuff = udfile.readAll();
    QJsonDocument json = QJsonDocument::fromJson(udbuff);
    usrdef = json.toVariant().toMap();

    auto bps = usrdef.find("breakpoint");
    if (bps != usrdef.end()) {
      for (auto it : bps->value<QJsonArray>()) {
        QJsonObject info = it.toObject();
        bp_set(this, rtbase + info["rva"].toInt(), info["enable"].toBool(),
               info["cond"].toString().toUtf8().data());
      }
      GuiUpdateBreakpointsView();
    }
  }

  parse_strings(path);
  loadPseudoCode(pseudoPath(), true);
}

void ManaDatabase::init(duint page, ManaFile *db, char *opcbuf) {
  DbgGlobal::inst()->debugee = this;
  this->path = MemModule_Prefix;
  this->db = db;
  this->pathcrc = 0;
  this->rtbase = page;
  this->opcodes_cache = opcbuf;
  this->opcsize = MemModule_Size;
}

void ManaDatabase::close() {
  if (!db) return;
  if (path.startsWith(MemModule_Prefix)) {
    free(db);
    free(opcodes_cache);
    db = nullptr;
    opcodes_cache = nullptr;
    return;
  }

  QJsonArray bprva;
  for (auto &bp : lldb->breakpoints()) {
    auto rva = bp.address() - rtbase;
    if (rvaToFunction(rva, false)) {
      if (bp.isOneShot()) {
        continue;
      }
      QJsonObject bpinfo;
      bpinfo.insert("rva", QJsonValue((int)(bp.address() - rtbase)));
      bpinfo.insert("enable", QJsonValue(bp.isEnabled()));
      bpinfo.insert("cond", QJsonValue(bp.condition().data()));
      bprva.append(bpinfo);
    }
  }

  bool forcesave = false;
  auto found = usrdef.find("breakpoint");
  if (found != usrdef.end()) {
    forcesave = true;
    usrdef.erase(found);
  }
  if (bprva.size()) {
    usrdef.insert("breakpoint", bprva);
  }
  if (forcesave || usrdef.size()) {
    QJsonDocument json = QJsonDocument::fromVariant(usrdef);
    QFile file(udPath());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QByteArray metadata = json.toJson();
      file.write(metadata.data(), metadata.size());
    }
    usrdef.clear();
  }
  if (patches.size()) {
    QFile file(path);
    if (file.open(QIODevice::ReadWrite | QIODevice::ExistingOnly)) {
      for (auto &p : patches) {
        file.seek(p.first);
        file.write(p.second.data(), p.second.size());
      }
    }
    patches.clear();
  }

  free(db);
  db = nullptr;

  if (opcodes_cache) {
    free(opcodes_cache);
    opcodes_cache = nullptr;
  }
}

void ParallelThread::run() {
  DbgGlobal *dg = DbgGlobal::inst();
  switch (type) {
    case COMPRESS_DATABASE: {
      QString dbfile = dg->pathModule(path, module);
      mana::compressDBFile(dbfile.toUtf8().data());

      QFileInfo finfo(path);
      QVariantMap dbmeta;
      dbmeta.insert("file", path);
      dbmeta.insert("last_modify",
                    finfo.lastModified().toString("yyyy/MM/dd-hh:mm:ss"));
      QJsonDocument json = QJsonDocument::fromVariant(dbmeta);
      QFile file(dg->pathModuleMeta(path, module));
      if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QByteArray metadata = json.toJson();
        file.write(metadata.data(), metadata.size());
      }
      GuiExecuteOnGuiThreadEx(
          [](void *p) {
            GuiAddLogMessage((char *)p);
            free(p);
          },
          strdup(QString("Generated database file : %1\n")
                     .arg(dbfile)
                     .toUtf8()
                     .data()));
      break;
    }
    default:
      break;
  }
  type = NOP;
}

DbgGlobal *DbgGlobal::inst() {
  static DbgGlobal global;
  return &global;
}

DbgGlobal::DbgGlobal() {
  mana::analyze_progress = [](const char *prefix, int cur, int max, int &tmp) {
    char *msg = nullptr;
    if (max < 0) {
      msg = strdup(prefix);
    } else {
      int prog = cur * 100 / max;
      if (prog == tmp) {
        return;
      }
      tmp = prog;

      msg = strdup(
          QString("%1 (%2%)...\n").arg(prefix).arg(prog).toUtf8().data());
    }
    GuiExecuteOnGuiThreadEx(
        [](void *p) {
          GuiAddStatusBarMessage((char *)p);
          free(p);
        },
        msg);
  };

  diserA64 = new Disassembler("arm64");
  diserA32 = new Disassembler("arm");
  diserT32 = new Disassembler("thumb");
  diserX64 = new Disassembler("");
}

DbgGlobal::~DbgGlobal() {
  if (parallel.type != ParallelThread::NOP) {
    parallel.wait();
  }
  if (usbmuxLLDBSvr.isOpen()) {
    usbmuxLLDBSvr.terminate();
    usbmuxLLDBSvr.kill();
    usbmuxLLDBSvr.waitForFinished();
  }
  if (usbmuxDbgSvr.isOpen()) {
    usbmuxDbgSvr.terminate();
    usbmuxDbgSvr.kill();
    usbmuxDbgSvr.waitForFinished();
  }
  if (usbmuxTBHttpSvr.isOpen()) {
    usbmuxTBHttpSvr.terminate();
    usbmuxTBHttpSvr.kill();
    usbmuxTBHttpSvr.waitForFinished();
  }
  clearAll();

  delete diserA64;
  delete diserA32;
  delete diserT32;
  delete diserX64;
}

QString DbgGlobal::exePath() { return QCoreApplication::applicationFilePath(); }

QString DbgGlobal::exeDir() { return QCoreApplication::applicationDirPath(); }

QString DbgGlobal::tempDir() { return QDir::tempPath(); }

bool DbgGlobal::createDir(const QString &path) {
  QDir dir(path);
  if (!dir.exists()) {
    if (!dir.mkpath(path)) {
      return false;
    } else {
    }
  }
  return true;
}

QString DbgGlobal::dataDir() {
  QString dirpath = QDir::homePath() + PATH_SEP "A64Dbg";
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::adbDir() {
  QString dirpath = dataDir() + PATH_SEP "database";
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::traceDir() {
  QString dirpath = dataDir() + PATH_SEP "trace";
  createDir(dirpath);
  return dirpath;
}

static const char *ud_prefix() {
  switch (DbgGlobal::inst()->currentPlatform()) {
    case pt_local_mac:
    case pt_local_uraniumvm:
      switch (DbgGlobal::inst()->currentArch()) {
        case mana::ArchType::ARM:
          return "macos-arm";
        case mana::ArchType::ARM64:
          return "macos-arm64";
        case mana::ArchType::X86:
          return "macos-x86";
        case mana::ArchType::X86_64:
          return "macos-x64";
        default:
          break;
      }
      break;
    case pt_remote_ios:
    case pt_remote_uraniumvm_ios:
      switch (DbgGlobal::inst()->currentArch()) {
        case mana::ArchType::ARM:
          return "ios-arm";
        case mana::ArchType::ARM64:
          return "ios-arm64";
        case mana::ArchType::X86:
          return "ios-x86";
        case mana::ArchType::X86_64:
          return "ios-x64";
        default:
          break;
      }
      break;
    case pt_remote_android:
    case pt_remote_uraniumvm_android:
      switch (DbgGlobal::inst()->currentArch()) {
        case mana::ArchType::ARM:
          return "android-arm";
        case mana::ArchType::ARM64:
          return "android-arm64";
        case mana::ArchType::X86:
          return "android-x86";
        case mana::ArchType::X86_64:
          return "android-x64";
        default:
          break;
      }
      break;
    case pt_local_vp_ios:
      switch (DbgGlobal::inst()->currentArch()) {
        case mana::ArchType::ARM:
          return "vpios-arm";
        case mana::ArchType::ARM64:
          return "vpios-arm64";
        case mana::ArchType::X86:
          return "vpios-x86";
        case mana::ArchType::X86_64:
          return "vpios-x64";
        default:
          break;
      }
      break;
    case pt_remote_vp_android:
      switch (DbgGlobal::inst()->currentArch()) {
        case mana::ArchType::ARM:
          return "vpandroid-arm";
        case mana::ArchType::ARM64:
          return "vpandroid-arm64";
        case mana::ArchType::X86:
          return "vpandroid-x86";
        case mana::ArchType::X86_64:
          return "vpandroid-x64";
        default:
          break;
      }
      break;
    default:
      break;
  }
  return nullptr;
}

QString DbgGlobal::usrdataDir() {
  QString dirpath = dataDir() + PATH_SEP "userdata";
  const char *udpref = ud_prefix();
  if (udpref) dirpath += QString("-") + udpref;
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::includeDir() {
  QString dirpath = dataDir() + PATH_SEP "include";
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::breakpadDir() {
  QString dirpath = dataDir() + PATH_SEP "breakpad";
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::decacheDir(const QString &triple) {
  const char *name = "unknown";
  if (isCloudPlatform())
    name = "yoophone";
  else if (triple.indexOf("android") > 0)
    name = "android";
  else if (triple.indexOf("ios") > 0)
    name = "iOS";
  else if (triple.indexOf("mac") > 0)
    name = "macOS";
  QString dirpath =
      dataDir() + PATH_SEP "decache" PATH_SEP + name + PATH_SEP + triple;
  createDir(dirpath);
  return dirpath;
}

QString DbgGlobal::cfgPath() { return dataDir() + PATH_SEP "a64dbg.ini"; }

QString DbgGlobal::licensePath() {
  return dataDir() + PATH_SEP "uvmdbg.license";
}

DbgPlatformType DbgGlobal::currentPlatform() {
  duint curpt = pt_default_platform;
  BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_DEFAULT_PLATFORM, &curpt);

#if __APPLE__
  // macOS support all
#else
  // other platform doesn't support ios simulator
  if (curpt == pt_local_vp_ios) {
    return pt_invalid_platform;
  }
#endif

  switch (curpt) {
    case pt_local_uraniumvm:
    case pt_remote_uraniumvm_ios:
    case pt_remote_uraniumvm_android:
    case pt_local_vp_ios:
    case pt_remote_vp_android:
      if (!QFileInfo(licensePath()).exists()) {
        static bool warned = false;
        if (!warned) {
          warned = true;
          QString warnmsg = QString(
                                "There's no %1.\n\n"
                                "If you need the fully virtualization uvmdbg "
                                "based on UraniumVM, "
                                "please contact us to buy a license.\n")
                                .arg(licensePath());
          GuiAddLogMessage(warnmsg.toUtf8());
        }
      }
      break;
    default:
      break;
  }
  return (DbgPlatformType)curpt;
}

mana::ArchType DbgGlobal::currentArch() { return lldb->currentArch(); }

bool DbgGlobal::isCloudPlatform() {
  duint currentSetting = 0;
  if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_CLOUD_PLATFORM, &currentSetting))
    return false;
  return currentSetting != 0;
}

static bool use_cache_file(const QString &path, DbgModule *module) {
  QString triple(module->triple.data());
  QString dadir = DbgGlobal::inst()->decacheDir(triple);
  if (triple.indexOf("ios") > 0) {
    // file not in cache dir on ios platform always use cache
    return !path.contains("iOS DeviceSupport") && !path.startsWith(dadir);
  }
  if (QFileInfo(path).exists()) {
    // libs in system always use cache
    if (triple.indexOf("mac") > 0 && path.startsWith("/usr/lib/system")) {
      return true;
    }
    return false;
  }
  // file doesn't exist always use cache
  return true;
}

static void cache_file_suffix(DbgPlatformType pt, const QString &path, QString &newpath) {
  switch (pt) {
  case pt_remote_android:
  case pt_remote_uraniumvm_android:
  case pt_remote_vp_android: {
    // android may have the same name lib in different load namespace(like houdini namespace), so...
    if (path.contains("lib64/arm64/") || path.contains("lib/arm/")) {
      QByteArray utf8path = path.toUtf8();
      newpath.append(QString("-%1").arg(lldb->crc(utf8path.data(), utf8path.size())));
    }
    break;
  }
  default:
    break;
  }
}

unsigned DbgGlobal::pathCRC(const QString &path, DbgModule *module) {
  QFileInfo finfo(path);
  if (use_cache_file(path, module)) {
    // try to map to the decache file
    auto mappath = mapPath(path);
    if (!mappath) {
      if (!module) return 0;

      QString newpath(QString("%1/%2")
                          .arg(decacheDir(module->triple.data()))
                          .arg(finfo.fileName()));
      cache_file_suffix(currentPlatform(), path, newpath);
      if (QFileInfo(newpath).exists()) {
        decaches.insert({path, newpath});
        return pathCRC(newpath, module);
      }
      return 0;
    }
    return pathCRC(*mappath, module);
  }
  QString fcrcmeta(QDir::toNativeSeparators(path));
  fcrcmeta.append(QString("-%1-%2")
                      .arg(finfo.size())
                      .arg(finfo.lastModified().toSecsSinceEpoch()));
  QByteArray crcmeta = fcrcmeta.toUtf8();
  return lldb->crc(crcmeta.data(), (int)crcmeta.size());
}

QString DbgGlobal::pathModule(const QString &path, DbgModule *module) {
  unsigned fcrc = pathCRC(path, module);
  char fcrcstr[32];
  sprintf(fcrcstr, "%08x", fcrc);
  return QString("%1/%2." MAGIC_FILE_EXT).arg(adbDir()).arg(fcrcstr);
}

QString DbgGlobal::pathModuleMeta(const QString &path, DbgModule *module) {
  unsigned fcrc = pathCRC(path, module);
  char fcrcstr[32];
  sprintf(fcrcstr, "%08x", fcrc);
  return QString("%1/%2.json").arg(adbDir()).arg(fcrcstr);
}

static bool need_realsize_check(DbgModule *module, DbgPlatformType ptype) {
  // local platform no need to check real size for system module
  if (ptype == pt_local_mac ||
      ptype == pt_local_vp_ios ||
      ptype == pt_local_uraniumvm) {
    QString path(module->modulePath.data());
    if (path.startsWith("/usr") || path.startsWith("/System")) {
      return false;
    }
    return true;
  }

  // files in /usr directory isn't encrpted on iOS, so...
  if (strstr(module->modulePath.data(), "/usr")) {
    return true;
  }
  // non-ios platform should check real size
  return strstr(module->triple.data(), "ios") == nullptr;
}

#define FAT_MAGIC 0xcafebabe
#define FAT_CIGAM 0xbebafeca
#define FAT_MAGIC_64 0xcafebabf
#define FAT_CIGAM_64 0xbfbafeca

static bool is_fat_file(const char *buff) {
  switch (*(uint32_t *)buff) {
  case FAT_MAGIC:
  case FAT_MAGIC_64:
  case FAT_CIGAM:
  case FAT_CIGAM_64:
    return true;
  default:
    return false;
  };
}

bool DbgGlobal::hasModule(const QString &path, DbgModule *module) {
  unsigned fcrc = pathCRC(path, module);
  if (modules.find(fcrc) == modules.end()) {
    QString dbfile = pathModule(path, module);
    QString metafile = pathModuleMeta(path, module);
    if (QFileInfo(dbfile).exists() && QFileInfo(metafile).exists()) {
      QFile mfile(metafile);
      if (!mfile.open(QIODevice::ReadOnly)) {
        GuiAddLogMessage(QString("Failed to read meta file %1.\n")
                             .arg(metafile)
                             .toUtf8()
                             .data());
        return false;
      }
      QByteArray metabuff = mfile.readAll();
      QJsonDocument json = QJsonDocument::fromJson(metabuff);
      QString rawfile = json.object().value("file").toString();
      QFile rfile(rawfile);
      if (module->realSize && need_realsize_check(module, currentPlatform()) &&
          rfile.size() != module->realSize) {
        GuiAddLogMessage(QString("Local cache file for module %1 is out of "
                                 "date(l=%2, r=%3), will re-download it.\n")
                             .arg(path)
                             .arg(rfile.size())
                             .arg(module->realSize)
                             .toUtf8()
                             .data());
        rfile.remove();
        return false;
      }
      if (!rfile.open(QIODevice::ReadOnly)) {
        GuiAddLogMessage(QString("Failed to read raw file %1.\n")
                             .arg(rawfile)
                             .toUtf8()
                             .data());
        return false;
      }
      // we will always re-analyze fat file
      char magic[4];
      rfile.read(magic, sizeof(magic));
      if (is_fat_file(magic)) {
        // let addModule process this situation
        return false;
      }
      rfile.seek(0);

      ManaDatabase *adb = new ManaDatabase;
      adb->db = mana::uncompressDBFile(dbfile.toUtf8().data());
      if (!adb->db || adb->db->magic != MAGIC_FILE_ANA ||
          adb->db->version != MANA_FILE_VERSION) {
        delete adb;
        GuiAddLogMessage(QString("Failed to load database file %1 for %2.\n")
                             .arg(dbfile)
                             .arg(path)
                             .toUtf8()
                             .data());
        return false;
      }
      int totalsz = 0;
      for (int i = 0; i < adb->db->info.nsect; i++) {
        auto sect = adb->db->sect(i);
        if (sect->info.type == mana::TEXT) {
          int fileoff = sect->fileoff + sect->size;
          if (totalsz < fileoff) {
            totalsz = fileoff;
          }
        }
      }
      adb->opcsize = totalsz;
      if (USE_MEMORY_OPCODES) {
        module->endAddress = module->startAddress + totalsz;
        adb->opcodes_cache = nullptr;
      } else {
        adb->opcodes_cache = (char *)malloc(totalsz);
        rfile.read(adb->opcodes_cache, totalsz);
      }
      modules.insert({fcrc, adb});
      adb->init(path, module, fcrc);
      GuiAddLogMessage(QString("Loaded database file %1 for %2.\n")
                           .arg(dbfile)
                           .arg(path)
                           .toUtf8()
                           .data());
    } else {
      return false;
    }
  }
  return true;
}

bool tbget_file_ex(const QString &ip, const QString &path,
                   const QString &savepath) {
  return tbget_file_ex(ip.toUtf8().data(), path.toUtf8().data(),
                       savepath.toUtf8().data());
}

void adb_pull(const QString &adb, const QString &rfile, const QString &locfile);
MODULEPARTY check_party(const QString &path);

void DbgGlobal::addModule(const QString &path, DbgModule *module,
                          const QString *rtpath) {
  QString triple(module->triple.data());
  QString dadir = decacheDir(triple);
  if (use_cache_file(path, module)) {
    QString newpath = dadir + PATH_SEP + module->moduleName.data();
    cache_file_suffix(currentPlatform(), path, newpath);
    // already pre-downloaded
    if (QFileInfo(newpath).exists()) {
      decaches.insert({path, newpath});
      addModule(newpath, module, &path);
      return;
    }
    // should decache
    QString icachepath;
    if (triple.indexOf("macos") > 0) {
      if (triple.indexOf("arm64") >= 0) {
        icachepath = "/System/Library/dyld/dyld_shared_cache_arm64e";
      } else {
        icachepath = "/private/var/db/dyld/dyld_shared_cache_x86_64";
      }
    } else if (triple.indexOf("ios") > 0) {
      // always use the name dyld_shared_cache_arm64 even for dyld_shared_cache_arm64e
      icachepath = QString("%1/decache/iOS/arm64-apple-ios/dyld_shared_cache_arm64").arg(dataDir());
      if (!QFileInfo(icachepath).exists()) {
        static bool warned = false;
        if (!warned) {
          warned = true;
          GuiExecuteOnGuiThreadEx(
              [](void *p) {
                char *path = (char *)p;
                QMessageBox::warning(
                    nullptr, "Missing dyld cache",
                    QString("There's no %1.\n\nPlease download it at:\n"
                            "/System/Library/Caches/com.apple.dyld\nin remote "
                            "device to:\n%1")
                        .arg(path));
                free(p);
              },
              strdup(icachepath.toUtf8().data()));
        }
        icachepath.clear();
      }
    }
    if (icachepath.length()) {
      if (!QFileInfo(icachepath).exists()) {
        icachepath = "/System/Volumes/Preboot/Cryptexes/OS" + icachepath;
      }
      lldb->decacheDyld(icachepath.toUtf8().data(), dadir.toUtf8().data(),
                        module->moduleName.data());
      if (!QFileInfo(newpath).exists()) {
#if __APPLE__
        GuiAddLogMessage(QString("Failed to extract %1 from %2, please put the "
                                 "dyld cache file in there.\n")
                             .arg(module->moduleName.data())
                             .arg(icachepath)
                             .toUtf8()
                             .data());
#else
        GuiAddLogMessage(
            QString("Unsupport extract %1 from %2 on windows, please put the "
                    "dyld decache file %1 in %3.\n")
                .arg(module->moduleName.data())
                .arg(icachepath)
                .arg(dadir)
                .toUtf8()
                .data());
#endif
      } else {
        decaches.insert({path, newpath});
        addModule(newpath, module, &path);
        return;
      }
    }
    // should pull from remote device for ios/android
    if (triple.indexOf("macos") < 0) {
      GuiAddLogMessage(QString("Downloading %1 from remote device.\n")
                           .arg(module->moduleName.data())
                           .toUtf8()
                           .data());
      auto pt = currentPlatform();
      if (pt == pt_remote_uraniumvm_ios) {
        char ip[56];
        BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip, sizeof(ip));
        tbget_file_ex(ip, path, newpath);
        QFile file(newpath);
        if (file.size() < 1024) {
          file.remove();
        }
      } else if (pt == pt_remote_uraniumvm_android ||
                 pt == pt_remote_vp_android) {
        char adb[MAX_PATH];
        BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_USB, adb, MAX_PATH);
        adb_pull(adb, path, newpath);
      } else {
        DbgCmdExec(QString("sync plat get-file \"%1\" \"%2\"")
                       .arg(path)
                       .arg(newpath)
                       .toUtf8()
                       .data());
      }
      if (!QFileInfo(newpath).exists()) {
        GuiAddLogMessage(QString("Failed to download %1 from remote device.\n")
                             .arg(module->moduleName.data())
                             .toUtf8()
                             .data());
      } else {
        decaches.insert({path, newpath});
        addModule(newpath, module, &path);
      }
      return;
    }
    GuiAddLogMessage(QString("Unsupport triple %1 currently.\n")
                         .arg(module->triple.data())
                         .toUtf8()
                         .data());
    return;
  }

  int tmp = -1;
  auto bin =
      mana::New(path.toUtf8().data(), module ? module->triple.data() : nullptr);
  if (!bin) {
    mana::analyze_progress("Unsupport input file.\n", -1, -1, tmp);
    return;
  }
  unsigned fcrc = pathCRC(path, module);
  QString dbfile = pathModule(path, module);
  if (!bin->save(dbfile.toUtf8().data())) {
    mana::Delete(bin);
    mana::analyze_progress("Failed to save database file.\n", -1, -1, tmp);
    return;
  }

  ManaDatabase *adb = new ManaDatabase;
  QFile file(dbfile);
  file.open(QIODevice::ReadOnly);
  adb->db = (ManaFile *)malloc(file.size());
  file.read((char *)adb->db, file.size());
  file.close();

  int totalsz = 0;
  for (int i = 0; i < adb->db->info.nsect; i++) {
    auto sect = adb->db->sect(i);
    if (sect->info.type == mana::TEXT) {
      int fileoff = sect->fileoff + sect->size;
      if (totalsz < fileoff) {
        totalsz = fileoff;
      }
    }
  }
  adb->opcsize = totalsz;
  if (USE_MEMORY_OPCODES) {
    module->endAddress = module->startAddress + totalsz;
    adb->opcodes_cache = nullptr;  // fetch dynamicall from debugee
  } else {
    size_t bufsz;
    adb->opcodes_cache = (char *)malloc(totalsz);
    memcpy(adb->opcodes_cache, bin->fileBuffer(bufsz), totalsz);
  }
  modules.insert({fcrc, adb});
  adb->init(rtpath ? *rtpath : path, module, fcrc);
  mana::Delete(bin);

  // notify plugin
  GuiExecuteOnGuiThreadEx(
      [](void *p) {
        ManaDatabase *adb = (ManaDatabase *)p;
        adp_module_t adpm;
        QByteArray pathbuff = adb->path.toUtf8();
        adpm.start = adb->rtbase;
        adpm.end = adpm.start + adb->opcsize;
        adpm.hasadb = true;
        adpm.path = pathbuff.data();
        ADPluginManager::inst()->sendEvent(adp_event_module_analyzed, &adpm);
      },
      adb);

  parallel.type = ParallelThread::COMPRESS_DATABASE;
  parallel.path = path;
  parallel.module = module;
  // parallel.start();
  parallel.run();
}

ManaDatabase *DbgGlobal::getModule(const QString &path, DbgModule *module) {
  unsigned fcrc = pathCRC(path, module);
  auto found = modules.find(fcrc);
  return found == modules.end() ? nullptr : found->second;
}

QString *DbgGlobal::mapPath(const QString &path) {
  auto found = decaches.find(path);
  return found == decaches.end() ? nullptr : &found->second;
}

void DbgGlobal::clearAll() {
  debugee = nullptr;
  for (auto &m : modules) {
    delete m.second;
  }
  for (auto &m : memModules) {
    delete m.second;
  }
  modules.clear();
  memModules.clear();
  dbgpatches.clear();
  dbgpages.clear();
  decaches.clear();
  pseudos.clear();
}

Disassembler *DbgGlobal::diser(const ManaFunc *fn, ManaDatabase *adb) {
  if (!adb) adb = debugee;
  if (!adb) {
    return diserA64;
  }
  switch (adb->db->info.arch) {
    case mana::ARM:
      if (!fn && DbgIsDebugging()) {
        return DbgValFromString("T") ? diserT32 : diserA32;
      }
      if (!fn) fn = adb->func_cache;
      if (!fn) return diserT32;
      return fn->info.thumb ? diserT32 : diserA32;
    case mana::ARM64:
      return diserA64;
    default:
      return diserX64;
  }
}

void DbgGlobal::updateUSBForward() {
  if (usbmuxLLDBSvr.isOpen()) {
    usbmuxLLDBSvr.terminate();
    usbmuxLLDBSvr.kill();
    usbmuxLLDBSvr.waitForFinished();
  }
  if (usbmuxDbgSvr.isOpen()) {
    usbmuxDbgSvr.terminate();
    usbmuxDbgSvr.kill();
    usbmuxDbgSvr.waitForFinished();
  }
  if (usbmuxTBHttpSvr.isOpen()) {
    usbmuxTBHttpSvr.terminate();
    usbmuxTBHttpSvr.kill();
    usbmuxTBHttpSvr.waitForFinished();
  }

  if (isCloudPlatform()) {
    return;
  }

  auto platform = currentPlatform();
  char adb[MAX_PATH], mux[MAX_PATH];
  if ((platform == pt_remote_ios || platform == pt_remote_uraniumvm_ios) &&
      BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_USB, mux, MAX_PATH)) {
    duint port;
    BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_IOS_PORT, &port);
    QString tcp1(QString("%1:%1").arg(port));
    QString tcp2(QString("%1:%1").arg(port + 1));
    QStringList args1, args2;
    if (QString(mux).endsWith(".py")) {
      args1.append(mux);
      args1.append(tcp1);
      args2.append(mux);
      args2.append(tcp2);
      usbmuxLLDBSvr.start("/usr/bin/python", args1);
      usbmuxDbgSvr.start("/usr/bin/python", args2);
    } else {
      args1.append(tcp1);
      args2.append(tcp2);
      usbmuxLLDBSvr.start(mux, args1);
      usbmuxDbgSvr.start(mux, args2);
    }
    usbmuxLLDBSvr.waitForStarted();
    usbmuxDbgSvr.waitForStarted();
    if (platform == pt_remote_uraniumvm_ios) {
      QString tcptb(QString("%1:%1").arg(TB_HTTP_PORT));
      QStringList argstb;
      if (QString(mux).endsWith(".py")) {
        argstb.append(mux);
        argstb.append(tcptb);
        usbmuxTBHttpSvr.start("/usr/bin/python", argstb);
      } else {
        argstb.append(tcptb);
        usbmuxTBHttpSvr.start(mux, argstb);
      }
      usbmuxTBHttpSvr.waitForStarted();
    }
    sleep(2);
    GuiAddLogMessage(
        QString("Forwarding lldb-server.%1 and debugserver.%2 with %3.\n")
            .arg(port)
            .arg(port + 1)
            .arg(mux)
            .toUtf8()
            .data());
    return;
  }
  if ((platform == pt_remote_android ||
       platform == pt_remote_uraniumvm_android ||
       platform == pt_remote_vp_android) &&
      BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_USB, adb, MAX_PATH)) {
    duint port;
    BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_ANDROID_PORT, &port);
    QProcess proc;
    QString tcp(QString("tcp:%1").arg(port));
    QStringList args;
    args.append("forward");
    args.append(tcp);
    args.append(tcp);
    proc.startDetached(adb, args);
    GuiAddLogMessage(QString("Forwarding lldb-server.%1 with %2.\n")
                         .arg(port)
                         .arg(adb)
                         .toUtf8()
                         .data());
    sleep(2);
    return;
  }
}

void DbgGlobal::loadPseudoCode(const QString &path, ManaDatabase *mdb, bool reload) {
  auto found = pseudos.find(mdb);
  if (found == pseudos.end()) {
    mdb->loadPseudoCode(path, false);
    pseudos.insert({mdb, path});
  } else if (reload && found->second != path) {
    pseudos.erase(found);
    mdb->lineaddrs.clear();
    mdb->addrlines.clear();
    loadPseudoCode(path, mdb, reload);
  }
}

void DbgGlobal::insertPseudoCode(const QString &path, ManaDatabase *mdb) {
  if (pseudos.find(mdb) == pseudos.end()) {
    pseudos.insert({mdb, path});
  }
}

ManaDatabase *DbgGlobal::createMemModule(duint addr) {
  if (!DbgMemIsValidReadPtr(addr)) {
    return nullptr;
  }

  duint page = addr & ~(MemModule_Size - 1);
  auto found = memModules.find(page);
  if (found != memModules.end()) {
    return found->second;
  }
  char *opcbuf = (char *)malloc(MemModule_Size);
  lldb->readMemory(page, opcbuf, MemModule_Size, true);

  Disassembler *diser;
  int defconsumed;
  switch (currentArch()) {
    case mana::ARM: {
      diser = DbgValFromString("T") ? diserT32 : diserA32;
      defconsumed = 4;
      addr &= ~1;
      break;
    }
    case mana::ARM64: {
      diser = diserA64;
      defconsumed = 4;
      break;
    }
    default:
      diser = diserX64;
      defconsumed = 1;
      break;
  }
  duint dbsize = 0;
  std::map<duint, int> poffoplen;
  for (duint a = page; a < addr;) {
    int consumed =
        diser->disassemble((unsigned char *)(opcbuf + a - page), 16, a);
    if (!consumed) {
      consumed = defconsumed;
    }
    while (a + consumed > addr) consumed--;
    poffoplen.insert({a - page, consumed});
    a += consumed;
  }
  for (duint a = addr; a < page + MemModule_Size;) {
    int consumed =
        diser->disassemble((unsigned char *)(opcbuf + a - page), 16, a);
    if (!consumed) {
      consumed = defconsumed;
    }
    poffoplen.insert({a - page, consumed});
    a += consumed;
  }
  /*
   * memory module database layout
   * 1.ManaFile header
   * 2.ManaSect header
   * 3.ManaFunc Header
   * 4.ManaInsn List...
   */
  dbsize = sizeof(ManaFile) + sizeof(ManaSect) + sizeof(ManaFunc) +
           poffoplen.size() * sizeof(ManaInsn);
  ManaDatabase *adb = new ManaDatabase;
  ManaFile *db = (ManaFile *)malloc(dbsize);
  memset(db, 0, dbsize);
  db->baseaddr = page;
  db->info.arch = currentArch();
  db->info.nsect = 1;
  db->nfunc = 1;
  db->funcoff = sizeof(ManaFile) + sizeof(ManaSect);
  ManaSect *msect = (ManaSect *)&db[1];
  msect->addr = page;
  msect->fileoff = 0;
  msect->size = MemModule_Size;
  msect->info.type = mana::TEXT;
  ManaFunc *mfn = (ManaFunc *)&msect[1];
  mfn->rvastart = 0;
  mfn->rvaend = MemModule_Size;
  mfn->ninsn = (int)poffoplen.size();
  mfn->info.thumb = diser == diserT32;
  mfn->insnoff = db->funcoff + sizeof(*mfn);
  ManaInsn *minsn = (ManaInsn *)&mfn[1];
  for (auto &i : poffoplen) {
    minsn->type = mana::NORMAL;
    minsn->fnoff = i.first;
    minsn->oplen = i.second - 1;
    minsn++;
  }
  adb->init(page, db, opcbuf);
  memModules.insert({page, adb});
  return adb;
}
