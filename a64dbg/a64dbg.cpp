#include "a64dbg.h"

#include <BasicView/StdTable.h>
#include <Bridge.h>
#include <MainWindow.h>
#include <bridge/_global.h>
#include <dbg/_dbgfunctions.h>
#include <abstraction/DebugEngine.hpp>
#include <Utils/StringUtil.h>

#include <QFileDialog>

#if __APPLE__ || __linux__
#include <dlfcn.h>
#endif

extern int currentCommander;
extern LLDBEngine *lldb;
extern void bp_set(const char *addr, bool oneshot = false,
                   const char *cond = nullptr);
extern void bp_unset(const char *addr);
extern void watch_set(const char *addr);
extern MODULEPARTY check_party(const QString &path);
extern bool MemRead(duint addr, void *dest, size_t size);

static void init_api(adp_api_t *api) {
  memset(api, 0, sizeof(*api));

  // const char *(*version)();
  api->version = [] { return A64DBG_VERSION; };

  // void (*log)(const char *msg);
  api->log = [](const char *msg) { GuiAddLogMessage(msg); };

  // void (*logStatus)(const char *msg);
  api->logStatus = [](const char *msg) { GuiAddStatusBarMessage(msg); };

  // void (*focusCPU)();
  api->focusCPU = [] { GuiFocusView(GUI_DISASSEMBLY); };

  // void (*focusLog)();
  api->focusLog = [] { GuiFocusView(GUI_LOG); };

  // void (*gotoCPUAdderss)(adpint addr);
  api->gotoCPUAdderss = [](adpint addr) {
    GuiDisasmAt(addr, DbgValFromString("pc"));
  };

  // void (*travelModule)(adp_error_t (*handler)(const adp_module_t *module));
  api->travelModule = [](void *context, adp_error_t (*handler)(void *context, const adp_module_t *module)) {
    auto dg = DbgGlobal::inst();
    for (auto &m : lldb->moduleList()) {
      unsigned fcrc = dg->pathCRC(m.modulePath.data(), &m);
      adp_module_t adpm;
      adpm.start = m.startAddress;
      adpm.end = m.endAddress;
      adpm.path = m.modulePath.data();
      adpm.hasadb = dg->modules.find(fcrc) != dg->modules.end();
      adpm.issys = DbgFunctions()->ModGetParty(adpm.start) == mod_system;

      bool finished = false;
      switch (handler(context, &adpm)) {
        case adp_err_failed:
        case adp_err_break:
          finished = true;
          break;
        default:
          break;
      }
      if (finished) {
        break;
      }
    }
  };

  // void (*travelFunc)(const adp_module_t *module,
  //                    adp_error_t (*handler)(const adp_func_t *func));
  api->travelFunc = [](void *context, const adp_module_t *module,
                       adp_error_t (*handler)(void *context, const adp_func_t *func)) {
    if (!module->hasadb) {
      return;
    }

    for (auto &m : lldb->moduleList()) {
      if (m.modulePath == module->path) {
        auto dg = DbgGlobal::inst();
        auto mdb = dg->getModule(module->path, &m);
        for (unsigned i = 0; i < mdb->db->nfunc; i++) {
          auto mf = mdb->db->func(i);
          adp_func_t adpf;
          adpf.rvastart = mf->rvastart;
          adpf.rvaend = mf->rvaend;
          adpf.name = mdb->db->string(mf->name);

          bool finished = false;
          switch (handler(context, &adpf)) {
          case adp_err_failed:
          case adp_err_break:
            finished = true;
            break;
          default:
            break;
          }
          if (finished) {
            break;
          }
        }
        break;
      }
    }
  };

  // adpint (*isDebugging)();
  api->isDebugging = [] { return (adpint)DbgIsDebugging(); };

  // adp_error_t (*gotoDumpAddress)(adpint addr, adpint index);
  api->gotoDumpAddress = [](adpint addr, adpint index) {
    if (index > 2) return adp_err_oor;
    GuiDumpAtN(addr, index + 1);
    return adp_err_ok;
  };

  // adp_error_t (*getIntConfig)(const char *sect, const char *key, adpint
  // *value);
  api->getIntConfig = [](const char *sect, const char *key, adpint *value) {
    if (BridgeSettingGetUint(sect, key, (duint *)value)) {
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*getConfig)(const char *sect, const char *key, char *cfg,
  //                          adpint cfgsize);
  api->getConfig = [](const char *sect, const char *key, char *cfg,
                      adpint cfgsize) {
    if (BridgeSettingGet(sect, key, cfg, cfgsize)) {
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*setIntConfig)(const char *sect, const char *key, adpint
  // value);
  api->setIntConfig = [](const char *sect, const char *key, adpint value) {
    if (BridgeSettingSetUint(sect, key, value)) {
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*setConfig)(const char *sect, const char *key, const char
  // *cfg);
  api->setConfig = [](const char *sect, const char *key, const char *cfg) {
    if (BridgeSettingSet(sect, key, cfg)) {
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*inputString)(const char *title, char *text, adpint size);
  api->inputString = [](const char *title, char *text, adpint size) {
    QString qtxt;
    Bridge::getBridge()->getStrWindow(title, &qtxt);
    if (qtxt.length()) {
      strncpy(text, qtxt.toUtf8().data(), size);
      return adp_err_ok;
    }
    return adp_err_canceled;
  };

  // adp_error_t (*inputInteger)(const char *title, adpint *value);
  api->inputInteger = [](const char *title, adpint *value) {
    QString qtxt;
    Bridge::getBridge()->getStrWindow(title, &qtxt);
    if (qtxt.length()) {
      *value = DbgValFromString(qtxt.toUtf8().data());
      return adp_err_ok;
    }
    return adp_err_canceled;
  };

  // adp_error_t (*inputPath)(char *path, adpint size, adpint isdir,
  //                          adpint isopen);
  api->inputPath = [](char *path, adpint size, adpint isdir, adpint isopen) {
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
    if (!result.length()) return adp_err_canceled;

    result = QDir::toNativeSeparators(result);
    strncpy(path, result.toUtf8().data(), size);
    return adp_err_ok;
  };

  // adp_error_t (*disassemble)(unsigned opcode, char *asmcode, adpint asmsize);
  api->disassemble = [](const void *opcode, char *asmcode, adpint asmsize) {
    std::string code;
    if (!DbgGlobal::inst()->diser(nullptr)->disassemble((unsigned char *)opcode, 16, code)) {
      return adp_err_failed;
    }
    strncpy(asmcode, code.data() + 1, asmsize);  // skip first <\t>
    for (int i = 0; i < (int)code.size() - 1 && i < (int)asmsize; i++) {
      if (asmcode[i] == '\t') {
        asmcode[i] = ' ';
      }
    }
    return adp_err_ok;
  };

  // adp_error_t (*assemble)(const char *asmcode, unsigned *opcode);
  api->assemble = [](const char *asmcode, void *opcode) {
    uint8_t opc[20];
    opc[0] = 0;
    DbgGlobal::inst()->diser(nullptr)->assemble(asmcode, opc);
    if (opc[0]) {
      memcpy(opcode, &opc[0], 1 + opc[0]);
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*getRegister)(const char *regname, adpint *regvalue);
  api->getRegister = [](const char *regname, adpint *regvalue) {
    *regvalue = DbgValFromString(regname);
    return adp_err_ok;
  };

  // adp_error_t (*setRegister)(const char *regname, adpint regvalue);
  api->setRegister = [](const char *regname, adpint regvalue) {
    if (DbgValToString(regname, regvalue)) {
      return adp_err_ok;
    }
    return adp_err_failed;
  };

  // adp_error_t (*readMemory)(adpint addr, adp_bytes_t *buff, adpint *readed);
  api->readMemory = [](adpint addr, adp_bytes_t *buff, adpint *readed) {
    if (!Bridge::getBridge()->isMainThread()) {
      return adp_err_thread;
    }
    if (!DbgIsDebugging()) {
      return adp_err_failed;
    }
    if (MemRead(addr, buff->ptr, buff->len)) {
      *readed = buff->len;
    }
    else {
      *readed = 0;
    }
    if (*readed)
      return adp_err_ok;
    else
      return adp_err_failed;
  };

  // adp_error_t (*writeMemory)(adpint addr, const adp_bytes_t *buff,
  //                            adpint *writed);
  api->writeMemory = [](adpint addr, const adp_bytes_t *buff, adpint *writed) {
    if (DbgMemWrite(addr, buff->ptr, buff->len)) {
      *writed = buff->len;
      return adp_err_ok;
    }
    *writed = 0;
    return adp_err_failed;
  };

  // adp_error_t (*stepDebugee)(adpint isinto);
  api->stepDebugee = [](adpint isinto) {
    DbgCmdExec(isinto ? "StepInto" : "StepOver");
    return adp_err_ok;
  };

  // adp_error_t (*continueDebugee)();
  api->continueDebugee = [] {
    DbgCmdExec("run");
    return adp_err_ok;
  };

  // adp_error_t (*pauseDebugee)();
  api->pauseDebugee = [] {
    DbgCmdExec("pause");
    return adp_err_ok;
  };

  // adp_error_t (*setBreakpoint)(adpint addr, adpint isoneshot,
  //                              const char *condexpr);
  api->setBreakpoint = [](adpint addr, adpint isoneshot, const char *condexpr) {
    char saddr[32];
    sprintf(saddr, "0x%llx", addr);
    bp_set(saddr, (bool)isoneshot, condexpr);
    return adp_err_ok;
  };

  // adp_error_t (*unsetBreakpoint)(adpint addr);
  api->unsetBreakpoint = [](adpint addr) {
    char saddr[32];
    sprintf(saddr, "0x%llx", addr);
    bp_unset(saddr);
    return adp_err_ok;
  };

  // adp_error_t (*setWatchpoint)(adpint addr, adpint size);
  api->setWatchpoint = [](adpint addr, adpint size) {
    char expr[64];
    sprintf(expr, "0x%llx, %d", addr, size);
    watch_set(expr);
    return adp_err_ok;
  };

  // adp_error_t (*unsetWatchpoint)(adpint addr);
  api->unsetWatchpoint = [](adpint addr) {
    char saddr[32];
    sprintf(saddr, "0x%llx", addr);
    bp_unset(saddr);
    GuiUpdateWatchView();
    return adp_err_ok;
  };

  // adp_error_t (*lldbCommand)(const char *cmd);
  api->lldbCommand = [](const char *cmd) {
    DbgCmdExec(cmd);
    return adp_err_ok;
  };

  // adp_error_t (*lldbCommandResult)(const char *cmd, char *result, adpint
  // size);
  api->lldbCommandResult = [](const char *cmd, char *result, adpint size) {
    if (!Bridge::getBridge()->isMainThread()) {
      return adp_err_thread;
    }
    result[0] = 0;
    lldb->commandResult(cmd, result, (int)size);
    return adp_err_ok;
  };

  // adpint (*registerCommander)(const char *name,
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
    return (adpint)sinfo.id;
  };

  // void (*unregisterCommander)(adpint idval);
  api->unregisterCommander = [](adpint idval) {
    GuiUnregisterScriptLanguage((int)idval);
  };

  // void (*attach)(adpint pid);
  api->attach = [](adpint pid) {
    char cmd[32];
    sprintf(cmd, "attach %d", pid);
    DbgCmdExec(cmd);
  };

  // void (*detach)();
  api->detach = []() { DbgCmdExec("detach"); };

  // adp_platform_t (*curPlatform)();
  api->curPlatform = []() {
    return (adp_platform_t)DbgGlobal::inst()->currentPlatform();
  };

  // adp_arch_t (*curArch)();
  api->curArch = []() {
    return (adp_arch_t)lldb->currentArch();
  };

  // adpint (*curCommander)()
  api->curCommander = []() {
    return (adpint)currentCommander;
  };

  // adp_error_t (*addrModule)(adpint addr, adp_module_t *module);
  api->addrModule = [](adpint addr, adp_module_t *module) {
    auto dg = DbgGlobal::inst();
    auto debugee = dg->debugee;
    if (!debugee) {
      return adp_err_notfound;
    }
    if (debugee->rtbase <= addr && addr < debugee->rtbase + debugee->opcsize) {
      module->start = debugee->rtbase;
      module->end = debugee->rtbase + debugee->opcsize;
      module->path = strdup(debugee->path.toUtf8().data());
      module->hasadb = true;
      module->issys = check_party(debugee->path) == mod_system;
      return adp_err_ok;
    }
    for (auto &m : lldb->moduleList()) {
      auto &cur = m;
      if (cur.startAddress <= addr && addr < cur.endAddress) {
        unsigned fcrc = dg->pathCRC(cur.modulePath.data(), &cur);
        module->start = cur.startAddress;
        module->end = cur.endAddress;
        auto mappath = lldb->moduleMapPath(cur.modulePath.data());
        if (mappath) {
          module->path = strdup(mappath);
        }
        else {
          module->path = strdup(cur.modulePath.data());
        }
        module->hasadb = dg->modules.find(fcrc) != dg->modules.end();
        module->issys = check_party(module->path) == mod_system;
        return adp_err_ok;
      }
    }
    return adp_err_notfound;
  };

  // adpint (*nextPC)();
  api->nextPC = []() {
    unsigned char opbuff[16];
    adpint pc = regPC();
    if (!MemRead(pc, opbuff, sizeof(opbuff))) {
      return (adpint)0;
    }
    auto diser = DbgGlobal::inst()->diser(nullptr);
    int oplen = 0;
    bool isptr = false;
    adpint target = diser->branchTarget(&opbuff[0], pc, &oplen, DbgGetRegDumpEx(nullptr, 0), &isptr);
    if (!oplen) {
      return (adpint)0;
    }
    if (target != INVALID_ADDR) {
      if (isptr) {
        adpint result = 0;
        switch (lldb->currentArch()) {
          case mana::ARM64:
          case mana::X86_64:
            MemRead(target, &result, 8);
            break;
          default:
            MemRead(target, &result, 4);
            break;
        }
        return result;
      }
      if (DbgIsJumpGoingToExecute(pc)) {
        return target;
      }
    }
    return pc + oplen;
  };

  // void (*runADCpp)(const char *code);
  api->runADCpp = [](const char *code) {
    if (!lldb->interpADCpp(code)) {
      GuiAddLogMessage("Current platform debug mode doesn't support adcpp.\n");
    }
  };

  // void (*getComment)(adpint addr, char *comm, adpint size);
  api->getComment = [](adpint addr, char *comm, adpint size) {
    for (auto& m : DbgGlobal::inst()->modules) {
      auto db = m.second;
      if (db->rtbase <= addr && addr < db->rtbase + db->opcsize) {
        DbgGetCommentAt(db, addr, comm);
        break;
      }
    }
  };

  // void (*setComment)(adpint addr, const char *comm);
  api->setComment = [](adpint addr, const char *comm) {
    for (auto& m : DbgGlobal::inst()->modules) {
      auto db = m.second;
      if (db->rtbase <= addr && addr < db->rtbase + db->opcsize) {
        DbgSetCommentAt(db, addr, comm);
        break;
      }
    }
  };
}

static void *dynload(void *module, const char *name) {
#if __APPLE__ || __linux__
    return dlsym(module, name);
#else
    return GetProcAddress((HMODULE)module, name);
#endif
}

adp_error_t ADPluginInstance::callEntry() {
  if (enable || shouldCall()) {
    if (entry) return entry(payload);
    else return ADPluginManager::inst()->adp_main_py((char *)module, payload);
  }
  return adp_err_failed;
}

void ADPluginManager::loadADP(const QString &path) {
  QDir dir(path);
  if (!dir.exists()) {
    return;
  }

  dir.setFilter(QDir::Files);
  for (auto info : dir.entryInfoList()) {
    QString fullpath = info.absoluteFilePath();
    if (!fullpath.endsWith(".adp")) {
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

    void *entry = dynload(mod, "adp_main");
    if (!entry) {
      GuiAddLogMessage(
          QString("Giveup loading plugin %1, there's no adp_main entry.\n")
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

    ADPluginInstance adp;
    duint enable = 0;
    adp.enable = true;
    adp.path = fullpath;
    adp.entry = (adp_main_t)entry;
    adp.module = mod;
    adp.payload = &payload;
    auto name = adp.name();
    if (!name.size()) {
      GuiAddLogMessage(QString("Ignored plugin %1 for empty module name.\n").arg(fullpath).toUtf8().data());
      continue;
    }
    if (BridgeSettingGetUint(CFGSECT_ADP, name.data(), &enable)) {
      adp.enable = (bool)enable;
    } else {
      BridgeSettingSetUint(CFGSECT_ADP, name.data(), 1);
      adp.enable = true;
    }
    adps.push_back(adp);
    adp.invoke(adp_event_loaded);
    GuiAddLogMessage(QString("Loaded plugin %1 with adpv%2.\n")
                         .arg(fullpath)
                         .arg(adp.version().data())
                         .toUtf8()
                         .data());
  }
}

void ADPluginManager::loadADPPython(const QString &path) {
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

    ADPluginInstance adp;
    duint enable = 0;
    adp.enable = true;
    adp.path = info.baseName();
    adp.entry = nullptr;
    adp.module = strdup(adp.path.toUtf8().data());
    adp.payload = &payload;
    auto name = adp.name();
    if (!name.size()) {
      GuiAddLogMessage(QString("Ignored plugin %1 for empty module name.\n").arg(filename).toUtf8().data());
      continue;
    }
    if (BridgeSettingGetUint(CFGSECT_ADP, name.data(), &enable)) {
      adp.enable = (bool)enable;
    } else {
      BridgeSettingSetUint(CFGSECT_ADP, name.data(), 1);
      adp.enable = true;
    }
    adps.push_back(adp);
    adp.invoke(adp_event_loaded);
    GuiAddLogMessage(QString("Loaded plugin %1 with adpv%2.\n")
                         .arg(filename)
                         .arg(adp.version().data())
                         .toUtf8()
                         .data());
  }
}

int ADPluginManager::loadADP() {
  init_api(&api);
  payload.api = &api;

#if _WIN32
  ::SetDllDirectoryA(QString("%1\\lldb").arg(DbgGlobal::inst()->exeDir()).toUtf8().data());
#endif

  auto dg = DbgGlobal::inst();
  QString dirpath1 = dg->exeDir() + PATH_SEP "plugin";
#if __linux__
  // force to use embbeded python runtime
  dlopen((dg->exeDir() + "/../lib/libpython3.9.so").toUtf8().data(), RTLD_NOW);
#endif
  loadADP(dirpath1);
  QString dirpath2 = dg->dataDir() + PATH_SEP "plugin";
  dg->createDir(dirpath2);
  loadADP(dirpath2);

  // init python3 adp
  adp_eval = [](const char *expr, char *outbuff, int outsz) {
    return 0;
  };
  adp_expr_valid = [](const char *expr) {
    return false;
  };
  adp_main_py = [](const char *pymod, adp_payload_t *adp) {
    return adp_err_unimpl;
  };
  for (auto &adp : adps) {
    if (adp.path.endsWith("Python3.adp")) {
      adp_eval = (int (*)(const char *, char *, int))dynload(adp.module, "adp_eval");
      adp_expr_valid = (bool (*)(const char *))dynload(adp.module, "adp_expr_valid");
      adp_main_py = (adp_error_t (*)(const char *, adp_payload_t *))dynload(adp.module, "adp_main_py");
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
  adp_eval(QString("sys.path.append('%1')\nsys.path.append('%2')")
           .arg(syspath1.data()).arg(syspath2.data()).toUtf8().data(), nullptr, 0);
  loadADPPython(dirpath1);
  loadADPPython(dirpath2);
  return (int)adps.size();
}

void ADPluginManager::unloadADP() {
  sendEvent(adp_event_pre_unload);
  adps.clear();
}

void ADPluginManager::sendEvent(adp_event_t event) {
  for (auto &adp : adps) {
    adp.invoke(event);
  }
}

void ADPluginManager::sendEvent(adp_event_t event, void *ptr) {
  for (auto &adp : adps) {
    adp.invoke(event, ptr);
  }
}

void ADPluginManager::sendEvent(adp_event_t event, adp_input_t *input) {
  for (auto &adp : adps) {
    adp.invoke(event, input);
  }
}

ADPluginView::ADPluginView() : StdTable(nullptr) {
  setDrawDebugOnly(false);
  setWindowTitle("ADPlugin Manager");
  int charwidth = getCharWidth();

  addColumnAt(8 + charwidth * 2 * 8, tr("Name"), false, tr("Name"));
  addColumnAt(8 + charwidth * 2 * 6, tr("Status"), false, tr("Status"));
  addColumnAt(8 + charwidth * 2 * 8, tr("Version"), false, tr("Version"));
  addColumnAt(8 + charwidth * 2 * 20, tr("Description"), false,
              tr("Description"));
  addColumnAt(8 + charwidth * 2 * 36, tr("Path"), false, tr("Path"));

  auto adpmgr = ADPluginManager::inst();
  setRowCount(adpmgr->adps.size());
  for (size_t i = 0; i < adpmgr->adps.size(); i++) {
    ADPluginInstance *adp = &adpmgr->adps[i];
    std::string version, desc;
    version = adp->info(&desc);
    setCellContent(i, 0, adp->name().data());
    setCellContent(i, 1, adp->enable ? "On" : "Off");
    setCellContent(i, 2, version.data());
    setCellContent(i, 3, desc.data());
    setCellContent(i, 4, adp->path);
    setCellUserdata(i, 0, (duint)adp);
  }

  resize(1000, 400);
  connect(this, SIGNAL(contextMenuSignal(QPoint)), this,
          SLOT(contextMenuSlot(QPoint)));
}

void ADPluginView::enableSlot() {
  int sel = getInitialSelection();
  ADPluginInstance *adp = (ADPluginInstance *)getCellUserdata(sel, 0);
  if (!adp->path.length()) {
    return;
  }
  adp->enable = true;
  setCellContent(sel, 1, "On");
  BridgeSettingSetUint(CFGSECT_ADP, adp->name().data(), 1);
  reloadData();
}

void ADPluginView::disableSlot() {
  int sel = getInitialSelection();
  ADPluginInstance *adp = (ADPluginInstance *)getCellUserdata(sel, 0);
  if (!adp->path.length()) {
    return;
  }
  setCellContent(sel, 1, "Off");
  BridgeSettingSetUint(CFGSECT_ADP, adp->name().data(), 0);
  reloadData();
  adp->enable = false;
}

void ADPluginView::deleteSlot() {
  int sel = getInitialSelection();
  ADPluginInstance *adp = (ADPluginInstance *)getCellUserdata(sel, 0);
  if (!adp->path.length()) {
    return;
  }

  QFile file(adp->path);
  if (file.remove()) {
    GuiAddLogMessage(
        QString("Deleted plugin %1.\n").arg(adp->path).toUtf8().data());

    setCellContent(sel, 1, "Deleted");
    BridgeSettingSetUint(CFGSECT_ADP, adp->name().data(), 1);  // for future load
  } else {
    GuiAddLogMessage(
        QString("Failed to delete plugin file %1, just disabled it.\n")
            .arg(adp->path)
            .toUtf8()
            .data());

    setCellContent(sel, 1, "Off");
    BridgeSettingSetUint(CFGSECT_ADP, adp->name().data(), 0);
  }
  reloadData();

  adp->path = "";
  adp->enable = false;
}

void ADPluginView::contextMenuSlot(const QPoint &pos) {
  if (!ADPluginManager::inst()->adps.size()) {
    return;
  }

  QMenu wMenu(this);  // create context menuQ
  QAction *actEnable = new QAction(tr("&Enable"), &wMenu);
  connect(actEnable, SIGNAL(triggered()), this, SLOT(enableSlot()));
  QAction *actDisable = new QAction(tr("&Disable"), &wMenu);
  connect(actDisable, SIGNAL(triggered()), this, SLOT(disableSlot()));
  wMenu.addAction(actEnable);
  wMenu.addAction(actDisable);
  wMenu.addSeparator();

  QAction *actDelete = new QAction(tr("D&elete"), &wMenu);
  connect(actDelete, SIGNAL(triggered()), this, SLOT(deleteSlot()));
  wMenu.addAction(actDelete);
  wMenu.addSeparator();

  QMenu wCopyMenu(tr("&Copy"), this);
  wCopyMenu.setIcon(DIcon("copy.png"));
  setupCopyMenu(&wCopyMenu);
  if (wCopyMenu.actions().length()) {
    wMenu.addSeparator();
    wMenu.addMenu(&wCopyMenu);
  }

  wMenu.exec(mapToGlobal(pos));  // execute context menu
}
