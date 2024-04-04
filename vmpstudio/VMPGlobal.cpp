#include "VMPGlobal.h"
#include "VMPBridgeMain.h"
#if __APPLE__ || __linux__
#include <dlfcn.h>
#endif
#include <stdio.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFileDialog>

#include "a64dbg.h"
#include "StringUtil.h"
#include "VDBFile.h"
#include "UVMTraceBrowser.h"
#include "UVMTraceWidget.h"

#define USE_FILE_OPCODES 1
#define USE_MEMORY_OPCODES 0

extern int currentCommander;

QString ToPtrString(duint Address) {
  char temp[32];
  if (VMPGlobal::inst()->addrSize() == 8) {
    sprintf_s(temp, "%016llX", Address);
  } else {
    sprintf_s(temp, "00000000%08X", (uint32_t)Address);
  }
  return QString(temp);
}

static void init_api(vsp_api_t *api) {
  // const char *(*version)();
  api->version = [] { return STUDIO_VERSION; };
  // void (*log)(const char *msg);
  api->log = [](const char *msg) { GuiAddLogMessage(msg); };
  // void (*logStatus)(const char *msg);
  api->logStatus = [](const char *msg) { GuiAddStatusBarMessage(msg); };
  // void (*gotoCPUAddress)(vspint addr);
  api->gotoCPUAddress = [](vspint addr) {
    GuiDisasmAt(addr, addr);
  };
  // void (*gotoTraceAddress)(vspint addr);
  api->gotoTraceAddress = [](vspint addr) {
    uvmWin->getTraceBrowser()->gotoAddress(addr);
  };
  // vsp_error_t (*getModule)(vsp_module_t *module);
  api->getModule = [](vsp_module_t *module) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    auto mdb = VMPGlobal::inst()->debugee;
    size_t size;
    module->path = mdb->db->filePath();
    module->imagebase = mdb->db->imageBase();
    module->buff = mdb->db->fileBuffer(size);
    module->size = size;
    return vsp_err_ok;
  };
  // vsp_error_t (*travelFunc)(void *context,
  //                    vsp_error_t (*handler)(void *context, const vsp_func_t *func));
  api->travelFunc = [](void *context,
                       vsp_error_t (*handler)(void *context, const vsp_func_t *func)) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    auto mdb = VMPGlobal::inst()->debugee;
    for (auto &mfit : mdb->db->functions()) {
      auto &mf = mfit.second;
      vsp_func_t vspf;
      vspf.start = mf.start;
      vspf.end = mf.end;
      vspf.name = mf.name.data();

      bool finished = false;
      switch (handler(context, &vspf)) {
        case vsp_err_failed:
        case vsp_err_break:
          finished = true;
          break;
        default:
          break;
      }
      if (finished) {
        break;
      }
    }
    return vsp_err_ok;
  };
  // vspint (*hasModule)();
  api->hasModule = []() {
    return (vspint)DbgIsDebugging();
  };
  // vsp_error_t (*readBytesFoff)(vspint foff, void *buff, vspint size);
  api->readBytesFoff = [](vspint foff, void *buff, vspint size) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    size_t fsize;
    const char *fbuff = VMPGlobal::inst()->debugee->db->fileBuffer(fsize);
    if (foff + size >= fsize) {
      return vsp_err_oor;
    }
    memcpy(buff, fbuff + foff, size);
    return vsp_err_ok;
  };
  // vsp_error_t (*readBytesAddr)(vspint addr, void *buff, vspint size);
  api->readBytesAddr = [](vspint addr, void *buff, vspint size) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    auto mdb = VMPGlobal::inst()->debugee;
    auto sect = mdb->db->addrSect(addr);
    if (!sect) {
      return vsp_err_oor;
    }
    vspint foff = sect->foff + addr - sect->addr;
    size_t fsize;
    const char *fbuff = mdb->db->fileBuffer(fsize);
    if (foff + size >= fsize) {
      return vsp_err_oor;
    }
    memcpy(buff, fbuff + foff, size);
    return vsp_err_ok;
  };
  // vsp_error_t (*gotoDumpAddress)(vspint addr, vspint index);
  api->gotoDumpAddress = [](vspint addr, vspint index) {
    if (index > 4) return vsp_err_oor;
    GuiDumpAtN(addr, index + 1);
    return vsp_err_ok;
  };
  // vsp_error_t (*getIntConfig)(const char *sect, const char *key, vspint
  // *value);
  api->getIntConfig = [](const char *sect, const char *key, vspint *value) {
    if (BridgeSettingGetUint(sect, key, (duint *)value)) {
      return vsp_err_ok;
    }
    return vsp_err_failed;
  };
  // vsp_error_t (*getConfig)(const char *sect, const char *key, char *cfg,
  //                          vspint cfgsize);
  api->getConfig = [](const char *sect, const char *key, char *cfg,
                      vspint cfgsize) {
    if (BridgeSettingGet(sect, key, cfg, cfgsize)) {
      return vsp_err_ok;
    }
    return vsp_err_failed;
  };
  // vsp_error_t (*setIntConfig)(const char *sect, const char *key, vspint
  // value);
  api->setIntConfig = [](const char *sect, const char *key, vspint value) {
    if (BridgeSettingSetUint(sect, key, value)) {
      return vsp_err_ok;
    }
    return vsp_err_failed;
  };
  // vsp_error_t (*setConfig)(const char *sect, const char *key, const char
  // *cfg);
  api->setConfig = [](const char *sect, const char *key, const char *cfg) {
    if (BridgeSettingSet(sect, key, cfg)) {
      return vsp_err_ok;
    }
    return vsp_err_failed;
  };
  // vsp_error_t (*inputString)(const char *title, char *text, vspint size);
  api->inputString = [](const char *title, char *text, vspint size) {
    QString qtxt;
    Bridge::getBridge()->getStrWindow(title, &qtxt);
    if (qtxt.length()) {
      strncpy(text, qtxt.toUtf8().data(), size);
      return vsp_err_ok;
    }
    return vsp_err_canceled;
  };
  // vsp_error_t (*inputInteger)(const char *title, vspint *value);
  api->inputInteger = [](const char *title, vspint *value) {
    QString qtxt;
    Bridge::getBridge()->getStrWindow(title, &qtxt);
    if (qtxt.length()) {
      *value = DbgValFromString(qtxt.toUtf8().data());
      return vsp_err_ok;
    }
    return vsp_err_canceled;
  };
  // vsp_error_t (*inputPath)(char *path, vspint size, vspint isdir,
  //                          vspint isopen);
  api->inputPath = [](char *path, vspint size, vspint isdir, vspint isopen) {
    QString result;
    if (isdir) {
      result = QFileDialog::getExistingDirectory();
    } else {
      if (isopen) {
        result = QFileDialog::getOpenFileName(nullptr, "Open file", "",
                                              "All files (*);;");
      } else {
        result = QFileDialog::getSaveFileName(nullptr, "Open file", "",
                                              "All files (*);;");
      }
    }
    if (!result.length()) return vsp_err_canceled;

    result = QDir::toNativeSeparators(result);
    strncpy(path, result.toUtf8().data(), size);
    return vsp_err_ok;
  };
  // vsp_error_t (*disassemble)(unsigned opcode, char *asmcode, vspint asmsize);
  api->disassemble = [](const void *opcode, char *asmcode, vspint asmsize) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    std::string code;
    if (!DbgGlobal::inst()->diser(nullptr)->disassemble((unsigned char *)opcode, 16, code)) {
      return vsp_err_failed;
    }
    strncpy(asmcode, code.data() + 1, asmsize);  // skip first <\t>
    for (int i = 0; i < (int)code.size() - 1 && i < (int)asmsize; i++) {
      if (asmcode[i] == '\t') {
        asmcode[i] = ' ';
      }
    }
    return vsp_err_ok;
  };
  // vsp_error_t (*assemble)(const char *asmcode, unsigned *opcode);
  api->assemble = [](const char *asmcode, void *opcode) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    uint8_t opc[20];
    opc[0] = 0;
    DbgGlobal::inst()->diser(nullptr)->assemble(asmcode, opc);
    if (opc[0]) {
      memcpy(opcode, &opc[0], 1 + opc[0]);
      return vsp_err_ok;
    }
    return vsp_err_failed;
  };
  // vsp_error_t (*setUVMBreakpoint)(vspint addr);
  api->setUVMBreakpoint = [](vspint addr) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    auto mdb = VMPGlobal::inst()->debugee;
    auto mf = mdb->rvaToFunction(addr - mdb->db->imageBase(), true);
    if (!mf.func) {
      return vsp_err_failed;
    }
    uvmWin->uvmTraceStart(mf);
    return vsp_err_ok;
  };
  // vsp_error_t (*unsetUVMBreakpoint)(vspint addr);
  api->unsetUVMBreakpoint = [](vspint addr) {
    if (!DbgIsDebugging()) {
      return vsp_err_failed;
    }
    auto mdb = VMPGlobal::inst()->debugee;
    auto mf = mdb->rvaToFunction(addr - mdb->db->imageBase(), true);
    if (!mf.func) {
      return vsp_err_failed;
    }
    uvmWin->uvmTraceStop(mf);
    return vsp_err_ok;
  };
  // vsp_error_t (*getSampleDatabase)(vsp_sdb_t *sdb);
  api->getSampleDatabase = [](vsp_sdb_t *sdb) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    sdb->rtbase = uvmWin->runtimeBase();
    sdb->totaltracks = uvmWin->mRecordInds.size();
    sdb->curtrack = uvmWin->mRecordCur;
    return vsp_err_ok;
  };
  // vsp_error_t (*getTrackIndexs)(vspint i, const vspint **indexs, vspint *size);
  api->getTrackIndexs = [](vspint i, const vspint **indexs, vspint *size) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    if (i >= uvmWin->mRecordInds.size()) {
      return vsp_err_oor;
    }
    *indexs = (vspint *)&uvmWin->mRecordInds[i][0];
    *size = uvmWin->mRecordInds[i].size();
    return vsp_err_ok;
  };
  // vsp_error_t (*getRecordInfo)(vspint addr, const void **handle, vspint *size);
  api->getRecordInfo = [](vspint addr, const void **handle, vspint *size) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    switch (VMPGlobal::inst()->debugee->db->archType()) {
      case mana::ARM: {
        auto found = uvmWin->mRecordARMAll.find(addr);
        if (found == uvmWin->mRecordARMAll.end()) {
          return vsp_err_oor;
        }
        *handle = &found->second;
        *size = found->second.size();
        break;
      }
      case mana::ARM64: {
        auto found = uvmWin->mRecordARM64All.find(addr);
        if (found == uvmWin->mRecordARM64All.end()) {
          return vsp_err_oor;
        }
        *handle = &found->second;
        *size = found->second.size();
        break;
      }
      default: {
        auto found = uvmWin->mRecordX64All.find(addr);
        if (found == uvmWin->mRecordX64All.end()) {
          return vsp_err_oor;
        }
        *handle = &found->second;
        *size = found->second.size();
        break;
      }
    }
    return vsp_err_ok;
  };
  // vsp_error_t (*getRegister)(const void *handle, vspint index, const char *regname, vspint *regvalue);
  api->getRegister = [](const void *handle, vspint index, const char *regname, vspint *regvalue) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    if (!handle) {
      return vsp_err_param;
    }
    switch (VMPGlobal::inst()->debugee->db->archType()) {
      case mana::ARM: {
        auto regs = (std::vector<arm_subregs_t> *)handle;
        if (index >= regs->size()) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        if (strcmp(regname, "fp") == 0) {
          *regvalue = regptr.gprs[12];
        } else if (strcmp(regname, "sp") == 0) {
          *regvalue = regptr.gprs[13];
        } else if (strcmp(regname, "lr") == 0) {
          *regvalue = regptr.gprs[14];
        } else if (regname[0] == 'r' && isdigit(regname[1])) {
          int i = atoi(&regname[1]);
          if (i > 14) {
            return vsp_err_oor;
          }
          *regvalue = regptr.gprs[i];
        } else if (strcmp(regname, "flags") == 0) {
          *regvalue = regptr.flags;
        } else {
          return vsp_err_failed;
        }
        break;
      }
      case mana::ARM64: {
        auto regs = (std::vector<arm64_subregs_t> *)handle;
        if (index >= regs->size()) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        if (strcmp(regname, "fp") == 0) {
          *regvalue = regptr.gprs[29];
        } else if (strcmp(regname, "lr") == 0) {
          *regvalue = regptr.gprs[30];
        } else if (regname[0] == 'x' && isdigit(regname[1])) {
          int i = atoi(&regname[1]);
          if (i > 30) {
            return vsp_err_oor;
          }
          *regvalue = regptr.gprs[i];
        } else if (strcmp(regname, "flags") == 0) {
          *regvalue = regptr.flags;
        } else {
          return vsp_err_failed;
        }
        break;
      }
      default: {
        auto regs = (std::vector<x64_subregs_t> *)handle;
        if (index >= regs->size()) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        if (strcmp(regname + 1, "ax") == 0) {
          *regvalue = regptr.rax;
        } else if (strcmp(regname + 1, "bx") == 0) {
          *regvalue = regptr.rbx;
        } else if (strcmp(regname + 1, "cx") == 0) {
          *regvalue = regptr.rcx;
        } else if (strcmp(regname + 1, "dx") == 0) {
          *regvalue = regptr.rdx;
        } else if (strcmp(regname + 1, "bp") == 0) {
          *regvalue = regptr.rbp;
        } else if (strcmp(regname + 1, "di") == 0) {
          *regvalue = regptr.rdi;
        } else if (strcmp(regname + 1, "si") == 0) {
          *regvalue = regptr.rsi;
        } else if (strcmp(regname + 1, "sp") == 0) {
          *regvalue = regptr.rsp;
        } else if (regname[0] == 'r' && isdigit(regname[1])) {
          int i = atoi(&regname[1]);
          if (i < 8 || i > 15) {
            return vsp_err_oor;
          }
          *regvalue = *(vspint *)(&regptr.r8 + i - 8);
        } else if (strcmp(regname, "flags") == 0) {
          *regvalue = regptr.flags;
        } else {
          return vsp_err_failed;
        }
        break;
      }
    }
    return vsp_err_ok;
  };
  // vsp_error_t (*getRegisterWithIndex)(const void *handle, vspint index, vspint regidx, vspint *regvalue);
  api->getRegisterWithIndex = [](const void *handle, vspint index, vspint regidx, vspint *regvalue) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    if (!handle) {
      return vsp_err_param;
    }
    switch (VMPGlobal::inst()->debugee->db->archType()) {
      case mana::ARM: {
        auto regs = (std::vector<arm_subregs_t> *)handle;
        if (index >= regs->size() || regidx > 14) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        *regvalue = regptr.gprs[regidx];
        break;
      }
      case mana::ARM64: {
        auto regs = (std::vector<arm64_subregs_t> *)handle;
        if (index >= regs->size() || regidx > 30) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        *regvalue = regptr.gprs[regidx];
        break;
      }
      default: {
        auto regs = (std::vector<x64_subregs_t> *)handle;
        if (index >= regs->size() || regidx > 15) {
          return vsp_err_oor;
        }
        auto &regptr = regs->at(index);
        *regvalue = *(vspint *)(&regptr.rax + regidx);
        break;
      }
    }
    return vsp_err_ok;
  };
  // vsp_error_t (*getMemoryPage)(vspint addr, vspint *pageaddr, const char **pagebuff, vspint *pagesize);
  api->getMemoryPage = [](vspint addr, vspint *pageaddr, const char **pagebuff, vspint *pagesize) {
    if (!uvmWin->isAttached()) {
      return vsp_err_failed;
    }
    duint page = addr & ~UVMPAGE_MASK;
    auto found = uvmWin->mPageBuffs.find(page);
    if (found == uvmWin->mPageBuffs.end()) {
      return vsp_err_failed;
    }
    *pagebuff = found->second.data();
    *pagesize = found->second.size();
    return vsp_err_ok;
  };
  // vsp_error_t (*command)(const char *cmd);
  api->command = [](const char *cmd) {
    uvmWin->uvmShell(cmd, false, false);
    return vsp_err_ok;
  };
  // vsp_error_t (*commandResult)(const char *cmd, char *result, vspint size);
  api->commandResult = [](const char *cmd, char *result, vspint size) {
    QString qresult = uvmWin->uvmShell(cmd, true, false);
    QByteArray arrresult = qresult.toUtf8();
    strncpy(result, arrresult.data(), size);
    return vsp_err_ok;
  };
  // vspint (*registerCommander)(const char *name,
  //                             void (*handler)(const char *cmd));
  api->registerCommander = [](const char *name,
                              bool (*handler)(const char *cmd)) {
    static int sid = 8;
    SCRIPTTYPEINFO sinfo;
    sinfo.id = sid++;
    sinfo.execute = handler;
    sinfo.completeCommand = nullptr;
    strncpy(sinfo.name, name, sizeof(sinfo.name));
    GuiRegisterScriptLanguage(&sinfo);
    return (vspint)sinfo.id;
  };
  // void (*unregisterCommander)(vspint idval);
  api->unregisterCommander = [](vspint idval) {
    GuiUnregisterScriptLanguage((int)idval);
  };
  // void (*attach)(vspint pid);
  api->attach = [](vspint pid) {
    char cmd[32];
    sprintf(cmd, "attach %d", pid);
    DbgCmdExec(cmd);
  };
  // void (*detach)();
  api->detach = []() {
    uvmWin->detach();
  };
  // vsp_file_t (*curFileType)();
  api->curFileType = []() {
    if (!DbgIsDebugging()) {
      return vsp_file_unknown;
    }
    return (vsp_file_t)VMPGlobal::inst()->debugee->db->fileType();
  };

  // vsp_arch_t (*curArchType)();
  api->curArchType = []() {
    if (!DbgIsDebugging()) {
      return vsp_arch_unsupport;
    }
    return (vsp_arch_t)VMPGlobal::inst()->debugee->db->archType();
  };

  // vspint (*curCommander)()
  api->curCommander = []() {
    return (vspint)currentCommander;
  };
}

static void *dynload(void *module, const char *name) {
#if __APPLE__ || __linux__
    return dlsym(module, name);
#else
    return GetProcAddress((HMODULE)module, name);
#endif
}

vsp_error_t VSPluginInstance::callEntry() {
  if (enable || shouldCall()) {
    if (entry) return entry(payload);
    else return VSPluginManager::inst()->vsp_main_py((char *)module, payload);
  }
  return vsp_err_failed;
}

void VSPluginManager::loadVSP(const QString &path) {
  QDir dir(path);
  if (!dir.exists()) {
    return;
  }

  dir.setFilter(QDir::Files);
  for (auto info : dir.entryInfoList()) {
    QString fullpath = info.absoluteFilePath();
    if (!fullpath.endsWith(".vsp")) {
      continue;
    }
#if __APPLE__ || __linux__
    void *mod = dlopen(fullpath.toUtf8().data(), RTLD_NOW);
#else
    HMODULE mod = LoadLibraryA(fullpath.toUtf8().data());
#endif
    if (!mod) {
#if _WIN32
#define dlerror() GetLastError()
#endif
      GuiAddLogMessage(QString("Failed to load plugin %1 : %2.\n")
                           .arg(fullpath)
                           .arg(dlerror())
                           .toUtf8()
                           .data());
      continue;
    }

    void *entry = dynload(mod, "vsp_main");
    if (!entry) {
      GuiAddLogMessage(
          QString("Giveup loading plugin %1, there's no vsp_main entry.\n")
              .arg(fullpath)
              .toUtf8()
              .data());
#if __APPLE__ || __linux__
      dlclose(mod);
#else
      FreeLibrary(mod);
#endif
      continue;
    }

    VSPluginInstance vsp;
    duint enable = 0;
    vsp.enable = true;
    vsp.path = fullpath;
    vsp.entry = (vsp_main_t)entry;
    vsp.module = mod;
    vsp.payload = &payload;
    auto name = vsp.name();
    if (!name.size()) {
      GuiAddLogMessage(QString("Ignored plugin %1 for empty module name.\n").arg(fullpath).toUtf8().data());
      continue;
    }
    if (BridgeSettingGetUint(CFGSECT_VSP, name.data(), &enable)) {
      vsp.enable = (bool)enable;
    } else {
      BridgeSettingSetUint(CFGSECT_VSP, name.data(), 1);
      vsp.enable = true;
    }
    vsps.push_back(vsp);
    vsp.invoke(vsp_event_loaded);
    GuiAddLogMessage(QString("Loaded plugin %1 with vspv%2.\n")
                         .arg(fullpath)
                         .arg(vsp.version().data())
                         .toUtf8()
                         .data());
  }
}

void VSPluginManager::loadVSPPython(const QString &path) {
  QDir dir(path);
  if (!dir.exists()) {
    return;
  }

  dir.setFilter(QDir::Files);
  for (auto info : dir.entryInfoList()) {
    QString filename = info.fileName();
    if (!(filename.endsWith(".py") || filename.endsWith(".pyc") ||
          filename.endsWith(".pyo"))) {
      continue;
    }

    VSPluginInstance vsp;
    duint enable = 0;
    vsp.enable = true;
    vsp.path = info.baseName();
    vsp.entry = nullptr;
    vsp.module = strdup(vsp.path.toUtf8().data());
    vsp.payload = &payload;
    auto name = vsp.name();
    if (!name.size()) {
      GuiAddLogMessage(QString("Ignored plugin %1 for empty module name.\n").arg(filename).toUtf8().data());
      continue;
    }
    if (BridgeSettingGetUint(CFGSECT_VSP, name.data(), &enable)) {
      vsp.enable = (bool)enable;
    } else {
      BridgeSettingSetUint(CFGSECT_VSP, name.data(), 1);
      vsp.enable = true;
    }
    vsps.push_back(vsp);
    vsp.invoke(vsp_event_loaded);
    GuiAddLogMessage(QString("Loaded plugin %1 with vspv%2.\n")
                         .arg(filename)
                         .arg(vsp.version().data())
                         .toUtf8()
                         .data());
  }
}

int VSPluginManager::loadVSP() {
  init_api(&api);
  payload.api = &api;

#if _WIN32
  ::SetDllDirectoryA(QString("%1\\python3").arg(VMPGlobal::inst()->exeDir()).toUtf8().data());
#endif

  auto dg = DbgGlobal::inst();
  QString dirpath1 = dg->exeDir() + PATH_SEP "plugin";
#if __linux__
  dirpath1 += "_vsp";
  // force to use embbeded python runtime
  dlopen((dg->exeDir() + "/../lib/libpython3.9.so").toUtf8().data(), RTLD_NOW);
#endif
  loadVSP(dirpath1);
  QString dirpath2 = dg->dataDir() + PATH_SEP "plugin";
  dg->createDir(dirpath2);
  loadVSP(dirpath2);

  // init python3 vsp
  vsp_eval = [](const char *expr, char *outbuff, int outsz) {
    return 0;
  };
  vsp_expr_valid = [](const char *expr) {
    return false;
  };
  vsp_main_py = [](const char *pymod, vsp_payload_t *vsp) {
    return vsp_err_unimpl;
  };
  for (auto &vsp : vsps) {
    if (vsp.path.endsWith("Python3.vsp")) {
      vsp_eval = (int (*)(const char *, char *, int))dynload(vsp.module, "vsp_eval");
      vsp_expr_valid = (bool (*)(const char *))dynload(vsp.module, "vsp_expr_valid");
      vsp_main_py = (vsp_error_t (*)(const char *, vsp_payload_t *))dynload(vsp.module, "vsp_main_py");
      break;
    }
  }
#if __APPLE__ || __linux__
  QByteArray syspath1 = dirpath1.toUtf8();
  QByteArray syspath2 = dirpath2.toUtf8();
#else
  QByteArray syspath1 = dirpath1.replace('\\', '/').toUtf8();
  QByteArray syspath2 = dirpath2.replace('\\', '/').toUtf8();
#endif
  vsp_eval(QString("sys.path.append('%1')\nsys.path.append('%2')")
           .arg(syspath1.data()).arg(syspath2.data()).toUtf8().data(), nullptr, 0);
  loadVSPPython(dirpath1);
  loadVSPPython(dirpath2);
  return (int)vsps.size();
}

void VSPluginManager::unloadVSP() {
  sendEvent(vsp_event_pre_unload);
  vsps.clear();
}

void VSPluginManager::sendEvent(vsp_event_t event) {
  for (auto &vsp : vsps) {
    vsp.invoke(event);
  }
}

void VSPluginManager::sendEvent(vsp_event_t event, void *ptr) {
  for (auto &vsp : vsps) {
    vsp.invoke(event, ptr);
  }
}

void VSPluginManager::sendEvent(vsp_event_t event, vsp_input_t *input) {
  for (auto &vsp : vsps) {
    vsp.invoke(event, input);
  }
}

bool VMPManaFunc::thumb() const {
  if (VMPGlobal::inst()->debugee->db->archType() == mana::ARM) {
    return func->start & 1;
  }
  return false;
}

const ManaFunc *ManaDatabase::rvaToFunction(duint rva, bool eq) {
  return nullptr;
}

const ManaSect *ManaDatabase::rvaToSection(duint rva) const { return nullptr; }

QString VMPManaDatabase::moduleName() {
  QFileInfo finfo(path);
  return finfo.baseName();
}

QString VMPManaDatabase::moduleDir() {
  QFileInfo finfo(path);
  return finfo.dir().path();
}

QString VMPManaDatabase::udPath() {
  return QString("%1/%2.json").arg(moduleDir()).arg(moduleName());
}

const mana::Section *VMPManaDatabase::rvaToSection(duint rva) const {
  return db->addrSect(db->imageBase() + rva);
}

VMPManaFunc VMPManaDatabase::cvtFunction(mana::Function *mf) {
  VMPManaFunc result;
  addr_t start = mf->start;
  if (db->archType() == mana::ARM) {
    if (start & 1) {
      start &= ~1;
    }
  }
  result.func = mf;
  result.rvastart = start - db->imageBase();
  result.rvaend = mf->end - db->imageBase();
  return result;
}

VMPManaFunc VMPManaDatabase::rvaToFunction(duint rva, bool eq) {
  addr_t addr = db->imageBase() + rva;
  if (func_cache.rvastart <= rva && rva < func_cache.rvaend) {
    if (eq) {
      return func_cache.rvastart == rva ? func_cache : VMPManaFunc();
    }
    return func_cache;
  }

  mana::Functions::const_iterator found = db->functions().end();
  if (eq) {
    found = db->functions().find(addr);
  } else {
    for (found = db->functions().begin(); found != db->functions().end();
         found++) {
      const mana::Function *fn = &found->second;
      if (found->first <= addr && addr < fn->end) {
        break;
      }
    }
  }
  if (found != db->functions().end()) {
    func_cache.func = (mana::Function *)&found->second;
    func_cache.rvastart = found->first - db->imageBase();
    func_cache.rvaend = func_cache.func->end - db->imageBase();
    return func_cache;
  }
  return VMPManaFunc();
}

const mana::Insinfo *VMPManaDatabase::rvaToInstruction(const VMPManaFunc *func,
                                                       duint dbrva) const {
  int frva = dbrva - func->rvastart;
  auto *insn = &func->func->insns[0];
  int low = 0;
  int high = (int)func->func->insns.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    auto *cur = &insn[mid];
    if (cur->fnoff > frva) {
      high = mid - 1;
    } else if (cur->fnoff + cur->info.oplen <= frva) {
      low = mid + 1;
    } else {
      return cur;
    }
  }
  return nullptr;
}

void VMPManaDatabase::init(const QString &path,
                           DbgModule *module) {
  this->path = path;
  func_cache.rvaend = 0;
  if (module) {
    rtbase = module->startAddress;
  } else {
    rtbase = db->imageBase();
  }
}

void VMPManaDatabase::close() {
  if (!db) return;

  if (usrdef.size()) {
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

  mana::Delete(db);
  db = nullptr;
  strs.clear();
  func_cache.rvaend = 0;

  if (opcodes_cache) {
    free(opcodes_cache);
    opcodes_cache = nullptr;
  }
}

static void parse_strings(duint base, const mana::Section *sect,
                          const unsigned char *ptr, int size) {
  auto vg = VMPGlobal::inst();
  for (int i = 0; i < size;) {
    if (isprint(ptr[0]) && isprint(ptr[1]) && isprint(ptr[2]) &&
        isprint(ptr[3])) {
      const unsigned char *str = ptr;
      int sectoff = i;
      i += 4;
      ptr += 4;
      while (i < size && *ptr) {
        if (isprint(*ptr) || *ptr == '\r' || *ptr == '\n' || *ptr == '\t') {
          i++;
          ptr++;
          continue;
        }
        break;
      }
      if (*ptr == 0) {
        vg->debugee->strs.insert({sect->addr - base + sectoff, (char *)str});
      }
    } else {
      i++;
      ptr++;
    }
  }
}

static void parse_strings() {
  auto vg = VMPGlobal::inst();
  auto debugee = vg->debugee;
  int prog = 1, progtmp;
  auto sects = debugee->db->sections();
  for (auto &s : sects) {
    mana::analyze_progress("LightIDA is parsing strings", prog++,
                           (int)sects.size(), progtmp);
    const mana::Section *sect = &s.second;
    if ((duint)(sect->foff + sect->size) >= (duint)debugee->opcsize ||
        (duint)sect->foff >= (duint)debugee->opcsize ||
        (duint)sect->size >= (duint)debugee->opcsize) {
      // invalid section, may it's encrypted.
      continue;
    }
    parse_strings(debugee->db->imageBase(), sect,
                  (unsigned char *)debugee->db->addrBuff(sect->addr),
                  s.second.size);
  }
  mana::analyze_progress("Finished string analyzing.\n", -1, -1, progtmp);
  GuiExecuteOnGuiThread([] {
    GuiUpdateDumpView();
    // notify plugin
    VSPluginManager::inst()->sendEvent(vsp_event_module_analyzed);
  });
}

void ParallelThread::run() {
  DbgGlobal *dg = DbgGlobal::inst();
  switch (type) {
    case COMPRESS_DATABASE: {
      parse_strings();

      QString dbfile = dg->pathModule(path, nullptr);
      mana::compressDBFile(dbfile.toUtf8().data());

      QFileInfo finfo(path);
      QVariantMap dbmeta;
      dbmeta.insert("file", path);
      dbmeta.insert("last_modify",
                    finfo.lastModified().toString("yyyy/MM/dd-hh:mm:ss"));
      QJsonDocument json = QJsonDocument::fromVariant(dbmeta);
      QFile file(dg->pathModuleMeta(path, nullptr));
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
    case PARSE_STRINGS: {
      parse_strings();
      break;
    }
    default:
      break;
  }
  type = NOP;
}

DbgGlobal *DbgGlobal::inst() { return (DbgGlobal *)VMPGlobal::inst(); }

DbgGlobal::DbgGlobal() {}

DbgGlobal::~DbgGlobal() {}

QString DbgGlobal::exePath() { return VMPGlobal::inst()->exePath(); }

QString DbgGlobal::exeDir() { return VMPGlobal::inst()->exeDir(); }

QString DbgGlobal::tempDir() { VMPGlobal::inst()->tempDir(); }

bool DbgGlobal::createDir(const QString &path) {
  return VMPGlobal::inst()->createDir(path);
}

QString DbgGlobal::dataDir() { return VMPGlobal::inst()->dataDir(); }

QString DbgGlobal::adbDir() { return VMPGlobal::inst()->adbDir(); }

QString DbgGlobal::usrdataDir() { return VMPGlobal::inst()->usrdataDir(); }

QString DbgGlobal::decacheDir(const QString &triple) {
  return VMPGlobal::inst()->decacheDir(triple);
}

QString DbgGlobal::cfgPath() { return VMPGlobal::inst()->cfgPath(); }

PlatformType DbgGlobal::currentPlatform() {
  duint curpt = pt_default_platform;
  BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_DEFAULT_PLATFORM, &curpt);
  return (PlatformType)curpt;
}

unsigned DbgGlobal::pathCRC(const QString &path,
                            DbgModule *module) {
  return VMPGlobal::inst()->pathCRC(path);
}

QString DbgGlobal::pathModule(const QString &path,
                              DbgModule *module) {
  return VMPGlobal::inst()->pathModule(path);
}

QString DbgGlobal::pathModuleMeta(const QString &path,
                                  DbgModule *module) {
  return VMPGlobal::inst()->pathModuleMeta(path);
}

bool DbgGlobal::hasModule(const QString &path,
                          DbgModule *module) {
  return VMPGlobal::inst()->hasModule(path);
}

void DbgGlobal::addModule(const QString &path,
                          DbgModule *module,
                          const QString *rtpath) {
  VMPGlobal::inst()->addModule(path);
}

ManaDatabase *DbgGlobal::getModule(const QString &path,
                                   DbgModule *module) {
  return (ManaDatabase *)VMPGlobal::inst()->getModule(path);
}

QString *DbgGlobal::mapPath(const QString &path) {
  return VMPGlobal::inst()->mapPath(path);
}

void DbgGlobal::clearAll() { VMPGlobal::inst()->clearAll(); }

Disassembler *DbgGlobal::diser(const ManaFunc *fn, ManaDatabase *mdb) {
  return VMPGlobal::inst()->diser(*fn);
}

VMPGlobal::VMPGlobal() {
  mana::analyze_progress = [](const char *prefix, int cur, int max, int &tmp) {
    char *msg = nullptr;
    if (max < 0) {
      msg = strdup(prefix);
    } else {
      long long prog = cur * 100ll / max;
      if (prog == tmp) {
        return;
      }
      tmp = (int)prog;

      msg =
          strdup(QString("%1 (%2%)...\n").arg(prefix).arg(tmp).toUtf8().data());
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

VMPGlobal::~VMPGlobal() {
  if (parallel.type != ParallelThread::NOP) {
    parallel.wait();
  }
  if (usbmuxUVMSvr.isOpen()) {
    usbmuxUVMSvr.terminate();
    usbmuxUVMSvr.kill();
    usbmuxUVMSvr.waitForFinished();
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

QString VMPGlobal::exePath() { return QCoreApplication::applicationFilePath(); }

QString VMPGlobal::exeDir() { return QCoreApplication::applicationDirPath(); }

QString VMPGlobal::tempDir() { return QDir::tempPath(); }

bool VMPGlobal::createDir(const QString &path) {
  QDir dir(path);
  if (!dir.exists()) {
    if (!dir.mkpath(path)) {
      return false;
    } else {
    }
  }
  return true;
}

QString VMPGlobal::dataDir() {
  QString dirpath = QDir::homePath() + PATH_SEP "VMPStudio";
  createDir(dirpath);
  return dirpath;
}

QString VMPGlobal::adbDir() {
  QString dirpath = dataDir() + PATH_SEP "database";
  createDir(dirpath);
  return dirpath;
}

QString VMPGlobal::usrdataDir() {
  QString dirpath = dataDir() + PATH_SEP "userdata";
  createDir(dirpath);
  return dirpath;
}

QString VMPGlobal::breakpadDir() {
  QString dirpath = dataDir() + PATH_SEP "breakpad";
  createDir(dirpath);
  return dirpath;
}

QString VMPGlobal::decacheDir(const QString &triple) {
  const char *name = "unknown";
  if (triple.indexOf("android") > 0)
    name = "android";
  else if (triple.indexOf("ios") > 0)
    name = "iOS";
  else if (triple.indexOf("mac") > 0)
    name = "macOS";
  QString dirpath = dataDir() + PATH_SEP "decache" PATH_SEP + name;
  createDir(dirpath);
  return dirpath;
}

QString VMPGlobal::cfgPath() { return dataDir() + PATH_SEP "vmpstudio.ini"; }

PlatformType VMPGlobal::currentPlatform() {
  duint curpt = pt_default_platform;
  BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_DEFAULT_PLATFORM, &curpt);
  return (PlatformType)curpt;
}

unsigned VMPGlobal::pathCRC(const QString &path) { return 0; }

QString VMPGlobal::pathModule(const QString &path) {
  unsigned fcrc = pathCRC(path);
  char fcrcstr[32];
  sprintf(fcrcstr, "%08x", fcrc);
  return QString("%1/%2." MAGIC_FILE_EXT).arg(adbDir()).arg(fcrcstr);
}

QString VMPGlobal::pathModuleMeta(const QString &path) {
  unsigned fcrc = pathCRC(path);
  char fcrcstr[32];
  sprintf(fcrcstr, "%08x", fcrc);
  return QString("%1/%2.json").arg(adbDir()).arg(fcrcstr);
}

bool VMPGlobal::hasModule(const QString &path) { return false; }

void VMPGlobal::addModule(const QString &path) {
  if (!QFileInfo(path).exists()) {
    return;
  }

  VDBFile vdb;
  // try to load exist vdb file
  VMPManaDatabase *adb = vdb.load(path);
  if (!adb) {
    // create a new vdb database
    int tmp = -1;
    auto bin = mana::New(path.toUtf8().data(), nullptr);
    if (!bin) {
      mana::analyze_progress("Unsupport input file.\n", -1, -1, tmp);
      return;
    }

    adb = new VMPManaDatabase;
    adb->db = bin;

    size_t bufsz;
    const char *binbuff = bin->fileBuffer(bufsz);
    adb->opcsize = bufsz;
    adb->opcodes_cache = (char *)malloc(adb->opcsize);
    memcpy(adb->opcodes_cache, binbuff, adb->opcsize);
    adb->init(path, nullptr);
  }
  debugee = adb;
  modules.insert({0, adb});

  parse_strings();
}

VMPManaDatabase *VMPGlobal::getModule(const QString &path) { return debugee; }

QString *VMPGlobal::mapPath(const QString &path) {
  auto found = decaches.find(path);
  return found == decaches.end() ? nullptr : &found->second;
}

void VMPGlobal::clearAll() {
  GuiSetDebugState(stopped);

  debugee = nullptr;
  for (auto &m : modules) {
    delete m.second;
  }
  modules.clear();
  dbgpatches.clear();
  dbgpages.clear();
  decaches.clear();

  // notify plugin
  VSPluginManager::inst()->sendEvent(vsp_event_module_closed);
}

Disassembler *VMPGlobal::diser(const ManaFunc &fn) {
  switch (debugee->db->archType()) {
    case mana::ARM:
      return fn.info.thumb ? diserT32 : diserA32;
    case mana::ARM64:
      return diserA64;
    default:
      return diserX64;
  }
}

Disassembler *VMPGlobal::diser(const mana::Function *fn) {
  ManaFunc func;
  if (!fn) fn = debugee->func_cache.func;
  func.info.thumb = fn ? (fn->start & 1) : 1;
  return diser(func);
}

void VMPGlobal::analyzeStrings() {
  parallel.type = ParallelThread::PARSE_STRINGS;
  parallel.start();
}

int VMPGlobal::addrSize() {
  if (debugee) {
    switch (debugee->db->archType()) {
      case mana::ARM64:
      case mana::X86_64:
        return 8;
      default:
        return 4;
    }
  }
  return 8;
}

bool VMPGlobal::isCloudPlatform() {
  duint currentSetting = 0;
  if (!BridgeSettingGetUint(VSSETTING_SECTION, VSSKEY_ANDROID_CLOUD, &currentSetting))
    return false;
  return currentSetting != 0;
}

void VMPGlobal::updateUSBForward() {
  if (isCloudPlatform()) {
    return;
  }

  char adb[MAX_PATH], mux[MAX_PATH];
  if (BridgeSettingGet(VSSETTING_SECTION, VSSKEY_IOS_TCPREPLAY, mux,
                       MAX_PATH)) {
    if (!usbmuxTBHttpSvr.isOpen()) {
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

      GuiAddLogMessage(QString("Forwarding textobot-server.%1 with %2.\n")
                         .arg(TB_HTTP_PORT)
                         .arg(mux)
                         .toUtf8()
                         .data());
    }
    if (!usbmuxUVMSvr.isOpen()) {
      QString tcpuvm(QString("%1:%1").arg(UVMSVR_PORT));
      QStringList argsuvm;
      if (QString(mux).endsWith(".py")) {
        argsuvm.append(mux);
        argsuvm.append(tcpuvm);
        usbmuxUVMSvr.start("/usr/bin/python", argsuvm);
      } else {
        argsuvm.append(tcpuvm);
        usbmuxUVMSvr.start(mux, argsuvm);
      }
      usbmuxUVMSvr.waitForStarted();
      }
      GuiAddLogMessage(QString("Forwarding uvm-server.%1 with %2.\n")
                         .arg(UVMSVR_PORT)
                         .arg(mux)
                         .toUtf8()
                         .data());
  }
  else if (BridgeSettingGet(VSSETTING_SECTION, VSSKEY_ANDROID_ADB, adb, MAX_PATH)) {
    QString tcp(QString("tcp:%1").arg(UVMSVR_PORT));
    QStringList args;
    args.append("forward");
    args.append(tcp);
    args.append(tcp);
    usbmuxUVMSvr.startDetached(adb, args);
    GuiAddLogMessage(QString("Forwarding uvm-server.%1 with %2.\n")
                         .arg(UVMSVR_PORT)
                         .arg(adb)
                         .toUtf8()
                         .data());
  }
}

const char *VMPGlobal::addrName(addr_t addr) {
  auto rva = addr - debugee->db->imageBase();
  auto func = debugee->rvaToFunction(rva, true);
  if (func.func) return func.func->name.data();
  return nullptr;
}
