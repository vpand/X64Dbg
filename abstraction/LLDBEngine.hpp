///////////////////////////////////YUNYOO.CN//////////////////////////////////////
//                                                                               *
// This file is part of A64Dbg and VMPStudio gui frontend project.               *
//                                                                               *
// Copyright(C) 2021 YunYoo Corp., ALL RIGHTS RESERVED.                          *
//                                                                               *
// Internet: yunyoo.cn                                                           *
//                                                                               *
// This code is distributed "as is", part of YUNYOO.CN and without warranty of   *
// any kind, expressed or implied, including, but not limited to warranty of     *
// fitness for any particular purpose. In no event will YUNYOO.CN be liable to   *
// you for any special, incidental, indirect, consequential or any other         *
// damages caused by the use, misuse, or the inability to use of this code,      *
// including anylost profits or lost savings, even if YUNYOO.CN has been advised *
// of the possibility of such damages.                                           *
//                                                                               *
///////////////////////////////////////*//////////////////////////////////////////


#pragma once

#include <functional>
#include <abstraction/MagicAna.hpp>
#include <abstraction/HyperTraceDef.h>

namespace dbgapi {

enum DbgPlatformType {
  pt_local_mac,                 // Local macOS/Simulator
  pt_remote_ios,                // Remote iOS
  pt_remote_android,            // Remote Android
  pt_local_vp_ios,              // Local VP iOS Simulator
  pt_remote_vp_android,         // Remote VP Android Emulator
  pt_local_uraniumvm,           // Local UraniumVM
  pt_remote_uraniumvm_ios,      // Remote UraniumVM iOS
  pt_remote_uraniumvm_android,  // Remote UraniumVM Android
  pt_invalid_platform,
};

struct DbgModule {
  addr_t startAddress;
  addr_t endAddress;
  int realSize;
  unsigned hash;
  std::string moduleName;
  std::string modulePath;
  std::string triple;
};

struct DbgFrame {
  addr_t address;
  std::string function;
};

struct DbgThread {
  int tid;
  bool debugee;
  addr_t addr;
  std::string name;
};

struct DbgGuiOperator {
  DbgPlatformType (*currentPlatform)();
  void (*addStatusMessage)(const char *msg);
  void (*addLogMessage)(const char *msg);
  void (*addSymbolLogMessage)(const char *msg);
  void (*updateAllViews)();
  void (*updateDisassemblyView)();
  void (*updateRegisterView)();
  void (*updateThreadView)();
  void (*updateBreakpointView)();
  void (*updateWatchpointView)();
  void (*updateCallStack)();
  void (*updateArgumentWidget)();
  void (*inputString)(const char *title, std::string &result);
  void (*refreshModule)(bool init);
  bool (*hasModule)(const char *path, DbgModule *module);
  void (*addModule)(const char *path, DbgModule *module);
  void (*loadModuleSync)(const char *path, DbgModule *module);
  void (*finishedAnalyze)(bool initing, DbgModule *module);
  void (*stackDumpAt)(addr_t addr);
  void (*dumpAt)(addr_t addr);
  void (*dumpAtN)(addr_t addr, int index);
  void (*disasmAt)(addr_t addr);
  void (*updateEnable)(bool now);
  void (*updateDisable)();
  addr_t (*valPC)();
  addr_t (*valSP)();
  void *(*regContextA32)();
  void *(*regContextA64)();
  void *(*regContextX64)();
  void (*runPython)(const char *pycode, char *result, int size);
  void (*traceHitAddress)(addr_t addr);
  void (*sendAdpInputEvent)(int event, const void *ctx);
  void (*setInitStatus)();
  void (*setRunningStatus)();
  void (*setPauseStatus)();
  void (*setStoppedStatus)();
  void (*focusSymmod)();
  void (*focusDisassembly)();
  void (*runOnGuiThread)(void (*callback)(void *), void *ctx);
  bool (*isUserModule)(const char *path);
  const ManaFunc *(*searchFunc)(addr_t addr, std::string &module, std::string &func);
  bool (*travelFunc)(std::function<bool(const DbgModule *module, const ManaFile *mdb, const ManaFunc *func)> callback);
  std::string (*cfgiOSIP)();
  std::string (*cfgADBPath)();
  std::string (*mapPath)(const char *path);
  void (*updateDumpView)();
  void (*updateTraceBrowser)();
};

struct __MANA_API__ DbgBreakpoint {
  addr_t address();
  bool isEnabled();
  bool isOneShot();
  bool isBreakpoint();
  bool isWatchpoint();
  int bitSize();
  std::string condition();
  void setEnabled(bool enable);
  void setOneshot(bool oneshot);
  void setCondition(const char *cond);
  std::string responseId();
  std::string moduleName();
  std::string functionName();


  DbgBreakpoint(void *ctx) {
    m_ctx = ctx;
  }
  void *context() {
    return m_ctx;
  }
 protected:
  void *m_ctx;
};

class __MANA_API__ LLDBEngine {
 public:
  LLDBEngine();
  LLDBEngine(const DbgGuiOperator *guiops);
  ~LLDBEngine();

  void start();
  void shutdown();

  mana::ArchType currentArch();
  void command(const char *cmd);
  bool commandResult(const char *cmd, char *buff, int size);
  char *commandResult(const char *cmd);
  int readMemory(addr_t addr, void *buff, int size, bool sync);
  int writeMemory(addr_t addr, const void *buff, int size);
  void setBreakpoint(addr_t addr, bool enable, bool oneshot, const char *cond);
  void setWatchpoint(addr_t addr, int bitsize);
  void removeBreakpoint(DbgBreakpoint bp);
  void updateBreakpoint(DbgBreakpoint bp);
  std::vector<DbgBreakpoint> breakpoints();
  std::vector<DbgModule> moduleList();
  std::vector<DbgThread> threadList();
  std::vector<DbgFrame> frameList();
  const char *moduleMapPath(const char *path);
  bool findModule(addr_t base, DbgModule *module);
  void hypertraceInit(std::function<void(const hypertrace_database_t *db, int bytes)> dbrecv);
  void hypertraceModule(DbgModule *module, bool on);
  void hypertraceStart(hypertrace_type_t type);
  void hypertraceStop(hypertrace_type_t type);
  bool interpADCpp(const char *code, bool compile = false);
  void decacheDyld(const char *dyldcache, const char *outdir, const char *name);
  unsigned crc(const char *buff, int size);
  void activeUraniumVM();
  void activeLLDB();
  unsigned uvmdbgPort();
  void launchFileiOS(const char *ip, const char *app);
  void launchFile(DbgPlatformType pt, const char *channel, const char *file,
                  const char *args);
  void attachProcess(DbgPlatformType pt, int pidval, const char *channel,
                     const char *path);
  void continueInferior();
  void interruptInferior();
  void shutdownInferior();
  bool isDebugging();
  bool isTracing();
  void selectThread(const char *tid);
  void reloadModules();
  void reloadThreads();
  void animateInto(bool into);
  void traceSetLog(const char *log);
  void traceSetCommand(const char *command);
  void traceSetSwitchCond(const char *cond);
  void traceSetLogFile(const char *file);
  void traceSetBreakCond(const char *cond);
  void traceSetBreakCount(int count);
  void traceSetInit(bool into);
  void traceSetRecordInit();
  void traceStop(bool force);
  void executeStepIn();
  void executeStepOver();
  void executeStepOut();
  bool executeRunToBBE();

public:
  const DbgGuiOperator *guiOperator;
};

} // end of dbgapi
