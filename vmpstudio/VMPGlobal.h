#ifndef _VMPGLOBAL_H
#define _VMPGLOBAL_H

#define STUDIO_VERSION "1.10.0"
#define STUDIO_RELEASE 1

#define STUDIO_ENABLE_URANIUMVM 1
#define STUDIO_ENABLE_PHONEVMP 1
#define STUDIO_ENABLE_DECOMPILER 1

// release
#if STUDIO_RELEASE
#define STUDIO_BUILD_INFO ""
#else
// service patch
#define STUDIO_BUILD_INFO " [SP %3]"
#endif

#include "vspdef.hpp"

#define CFGSECT_VSP "VSPlugin"

#define UVMSVR_PORT 30334

#include <abstraction/DebugEngine.hpp>
using namespace dbgapi;

#include "../bridge/_global.h"

#define PlatformType DbgPlatformType

typedef vsp_error_t (*vsp_main_t)(vsp_payload_t *vsp);

struct VSPluginInstance {
  QString path;
  vsp_main_t entry;
  vsp_payload_t *payload;
  void *module;
  bool enable;

  bool isPython() {
    return entry == nullptr;
  }

  void resetPayload() {
    memset(&payload->input, 0, sizeof(payload->input));
    memset(&payload->result, 0, sizeof(payload->result));
  }

  vsp_error_t invoke(vsp_event_t event) {
    resetPayload();
    payload->event = event;
    return callEntry();
  }

  void invoke(vsp_event_t event, void *ptr) {
    resetPayload();
    payload->event = event;
    payload->input.ptr = ptr;
    callEntry();
  }

  void invoke(vsp_event_t event, vsp_input_t *input) {
    resetPayload();
    payload->event = event;
    payload->input = *input;
    callEntry();
  }

  std::string invokeConstString(vsp_event_t event) {
    if (invoke(event) != vsp_err_ok) {
      return "";
    }
    if (isPython()) {
      std::string result = payload->result.str_dyn;
      free(payload->result.str_dyn);
      return result;
    }
    return payload->result.str_const;
  }

  std::string version() { return invokeConstString(vsp_event_version); }

  std::string info(std::string *desc) {
    if (invoke(vsp_event_vspinfo) != vsp_err_ok) {
      *desc = "";
      return "";
    }
    *desc = (char *)payload->result.ptr.p1;
    if (isPython()) {
      std::string result = (char *)payload->result.ptr.p0;
      free(payload->result.ptr.p0);
      free(payload->result.ptr.p1);
      return result;
    }
    return (char *)payload->result.ptr.p0;
  }

  std::string name() { return invokeConstString(vsp_event_menuname); }

 private:
  bool shouldCall() {
    switch (payload->event) {
      case vsp_event_loaded:
      case vsp_event_pre_unload:
      case vsp_event_version:
      case vsp_event_vspinfo:
      case vsp_event_menuname:
        return true;
      default:
        return false;
    }
  }

  vsp_error_t callEntry();
};

class VSPluginManager {
 public:
  static VSPluginManager *inst() {
    static VSPluginManager mgr;
    return &mgr;
  }

  int loadVSP();
  void unloadVSP();

  void sendEvent(vsp_event_t event);
  void sendEvent(vsp_event_t event, void *ptr);
  void sendEvent(vsp_event_t event, vsp_input_t *input);

  std::vector<VSPluginInstance> vsps;
  int (*vsp_eval)(const char *expr, char *outbuff, int outsz);
  bool (*vsp_expr_valid)(const char *expr);
  vsp_error_t (*vsp_main_py)(const char *pymod, vsp_payload_t *vsp);

 protected:
  VSPluginManager() {}
  ~VSPluginManager() {}

  void loadVSP(const QString &dir);
  void loadVSPPython(const QString &dir);

  vsp_api_t api;
  vsp_payload_t payload;
};

struct VMPManaFunc {
  mana::Function *func;
  umana32 rvastart;
  umana32 rvaend;

  VMPManaFunc() { reset(); }

  VMPManaFunc(const VMPManaFunc &f) {
    func = f.func;
    rvastart = f.rvastart;
    rvaend = f.rvaend;
  }

  VMPManaFunc &operator=(const VMPManaFunc &f) {
    func = f.func;
    rvastart = f.rvastart;
    rvaend = f.rvaend;
    return *this;
  }

  void reset() {
    func = nullptr;
    rvastart = 0;
    rvaend = 0;
  }

  bool thumb() const;
  bool operator==(const VMPManaFunc &f) const { return func == f.func; }
  operator bool() const { return func != nullptr; }
};

struct VMPManaDatabase {
  std::map<int, std::string> patches;  // patches for text opcodes
  std::map<uint64_t, std::string>
      dbgpatches;                 // patches for text opcodes when debugging
  QVariantMap usrdef;             // user define data like comment/bookmark
  QString path;                   // this module fullpath
  duint rtbase = 0;               // runtime base address
  mana::Binary *db = nullptr;     // analyzed database
  char *opcodes_cache = nullptr;  // text opcodes cached from file buffer
  int opcsize = 0;
  VMPManaFunc func_cache;              // the last operated function
  std::map<duint, const char *> strs;  // strings in file
  bool isvdb = false;

  void init(const QString &path, DbgModule *module);
  void close();
  ~VMPManaDatabase() { close(); }

  QString moduleName();
  QString moduleDir();
  QString udPath();

  const mana::Section *rvaToSection(duint rva) const;
  VMPManaFunc rvaToFunction(duint rva, bool eq);
  VMPManaFunc cvtFunction(mana::Function *mf);
  const mana::Insinfo *rvaToInstruction(const VMPManaFunc *func,
                                        duint rva) const;
};

class VMPGlobal {
 public:
  VMPGlobal();
  ~VMPGlobal();

  static VMPGlobal *inst() {
    static VMPGlobal global;
    return &global;
  }

  bool createDir(const QString &path);

  QString exePath();
  QString exeDir();
  QString tempDir();
  QString dataDir();
  QString adbDir();
  QString usrdataDir();
  QString breakpadDir();
  QString decacheDir(const QString &triple);
  QString cfgPath();
  PlatformType currentPlatform();

  bool isCloudPlatform();
  void updateUSBForward();

  unsigned pathCRC(const QString &path);
  QString pathModule(const QString &path);
  QString pathModuleMeta(const QString &path);
  bool hasModule(const QString &path);
  void addModule(const QString &path);
  VMPManaDatabase *getModule(const QString &path);
  QString *mapPath(const QString &path);

  void clearAll();
  Disassembler *diser(const ManaFunc &fn);
  Disassembler *diser(const mana::Function *fn);
  int addrSize();

  const char *addrName(addr_t addr);

 private:
  void analyzeStrings();

 public:
  std::map<unsigned, VMPManaDatabase *> modules;
  ParallelThread parallel;
  VMPManaDatabase *debugee = nullptr;
  std::map<uint64_t, std::string>
      dbgpatches;  // patches for memory when debugging
  std::map<uint64_t, DbgPageCache> dbgpages;  // pages for memory cache
  std::map<QString, QString> decaches;        // decache map from dyld cache
  QProcess usbmuxTBHttpSvr;
  QProcess usbmuxUVMSvr;

 private:
  Disassembler *diserA64 = nullptr;
  Disassembler *diserA32 = nullptr;
  Disassembler *diserT32 = nullptr;
  Disassembler *diserX64 = nullptr;
};

// run a shell command in the remote uvmserver side
QString svr_shell(const QString &cmds, bool result, bool timeout);

// get a remote file
QByteArray svr_getfile(const QByteArray &path, const QString &outpath = "");

// post a file to remote
void svr_postfile(const QString &path, const QByteArray &remotepath);

#endif  // _VMPGLOBAL_H
