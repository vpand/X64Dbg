#ifndef _GLOBAL_H
#define _GLOBAL_H

#if __linux__
// define this macro to disable include quuid.h
#ifndef QUUID_H
#define QUUID_H
class QUuid {};
#endif
#endif

#include <windows_stub.h>

#include <abstraction/DebugEngine.hpp>
using namespace dbgapi;

#include <QProcess>
#include <QVariantMap>

#include "bridgemain.h"

#if 0
//GUI typedefs
typedef int (*GUIGUIINIT)(int, char**);
typedef void* (*GUISENDMESSAGE)(GUIMSG type, void* param1, void* param2);
typedef const char* (*GUITRANSLATETEXT)(const char* source);

//GUI functions
extern GUIGUIINIT _gui_guiinit;
extern GUISENDMESSAGE _gui_sendmessage;
extern GUITRANSLATETEXT _gui_translate_text;

//DBG typedefs
typedef const char* (*DBGDBGINIT)();
typedef duint(*DBGMEMFINDBASEADDR)(duint addr, duint* size);
typedef bool (*DBGMEMREAD)(duint addr, void* dest, duint size, duint* read);
typedef bool (*DBGMEMWRITE)(duint addr, const void* src, duint size, duint* written);
typedef bool (*DBGDBGCMDEXEC)(const char* cmd);
typedef bool (*DBGMEMMAP)(MEMMAP* memmap);
typedef void (*DBGDBGEXITSIGNAL)();
typedef bool (*DBGVALFROMSTRING)(const char* string, duint* value);
typedef bool (*DBGISDEBUGGING)();
typedef bool (*DBGISJUMPGOINGTOEXECUTE)(duint addr);
typedef bool (*DBGADDRINFOGET)(duint addr, SEGMENTREG segment, BRIDGE_ADDRINFO* addrinfo);
typedef bool (*DBGADDRINFOSET)(duint addr, BRIDGE_ADDRINFO* addrinfo);
typedef bool(*DBGENCODETYPESET)(duint addr, duint size, ENCODETYPE type);
typedef BPXTYPE(*DBGBPGETTYPEAT)(duint addr);
typedef bool (*DBGGETREGDUMP)(REGDUMP* regdump);
typedef bool (*DBGVALTOSTRING)(const char* string, duint value);
typedef bool (*DBGMEMISVALIDREADPTR)(duint addr);
typedef int (*DBGGETBPLIST)(BPXTYPE type, BPMAP* bplist);
typedef bool (*DBGDBGCMDEXECDIRECT)(const char* cmd);
typedef duint(*DBGGETBRANCHDESTINATION)(duint addr);
typedef duint(*DBGSENDMESSAGE)(DBGMSG type, void* param1, void* param2);

//DBG functions
extern DBGDBGINIT _dbg_dbginit;
extern DBGMEMFINDBASEADDR _dbg_memfindbaseaddr;
extern DBGMEMREAD _dbg_memread;
extern DBGMEMWRITE _dbg_memwrite;
extern DBGDBGCMDEXEC _dbg_dbgcmdexec;
extern DBGMEMMAP _dbg_memmap;
extern DBGDBGEXITSIGNAL _dbg_dbgexitsignal;
extern DBGVALFROMSTRING _dbg_valfromstring;
extern DBGISDEBUGGING _dbg_isdebugging;
extern DBGISJUMPGOINGTOEXECUTE _dbg_isjumpgoingtoexecute;
extern DBGADDRINFOGET _dbg_addrinfoget;
extern DBGADDRINFOSET _dbg_addrinfoset;
extern DBGENCODETYPESET _dbg_encodetypeset;
extern DBGBPGETTYPEAT _dbg_bpgettypeat;
extern DBGGETREGDUMP _dbg_getregdump;
extern DBGVALTOSTRING _dbg_valtostring;
extern DBGMEMISVALIDREADPTR _dbg_memisvalidreadptr;
extern DBGGETBPLIST _dbg_getbplist;
extern DBGDBGCMDEXECDIRECT _dbg_dbgcmddirectexec;
extern DBGGETBRANCHDESTINATION _dbg_getbranchdestination;
extern DBGSENDMESSAGE _dbg_sendmessage;
#endif

#include <QString>
#include <QThread>
#include <QTime>
#include <map>

#if 0  // def _WIN32
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif

class ParallelThread : public QThread {
 public:
  ParallelThread() {}
  ~ParallelThread() {}

  enum parallel_type {
    COMPRESS_DATABASE,
    PARSE_STRINGS,
    NOP,
  };

  parallel_type type = NOP;
  QString path;
  DbgModule *module = nullptr;

  virtual void run();
};

#define UDKEY_COMMENT "comment"
#define UDKEY_BOOKMARK "bookmark"

#define MemModule_Prefix "/memory/module/"
#define MemModule_Size 0x1000

struct ManaDatabase {
  std::map<int, std::string> patches;  // patches for text opcodes
  std::map<uint64_t, std::string>
      dbgpatches;                 // patches for text opcodes when debugging
  QVariantMap usrdef;             // user define data like comment/bookmark
  QString path;                   // this module fullpath
  duint rtbase = 0;               // runtime base address
  ManaFile *db = nullptr;         // analyzed database
  char *opcodes_cache = nullptr;  // text opcodes cached from file buffer
  int opcsize = 0;
  const ManaFunc *func_cache = nullptr;
  std::vector<std::pair<duint, std::string>> strs;  // string from debugee file
  std::map<duint, int> addrlines; // pseudo code addr2line
  std::map<int, duint> lineaddrs; // pseudo code line2addr
  unsigned pathcrc;

  void init(const QString &path, DbgModule *module, unsigned fcrc);
  void init(duint page, ManaFile *db, char *opcbuf);
  void close();
  ~ManaDatabase() { close(); }

  QString moduleName();
  QString udPath();
  QString pseudoPath();
  void loadPseudoCode(const QString &path, bool init);

  const ManaSect *rvaToSection(duint rva) const;
  const ManaSect *foffToSection(duint foff) const;
  const ManaFunc *rvaToFunction(duint rva, bool eq);
  const ManaInsn *rvaToInstruction(const ManaFunc *func, duint rva) const;
  const char *vaToString(duint va);

 private:
  void parse_strings(duint base, const ManaSect *sect, const char *ptr);
  void parse_strings(const QString &path);
};

struct DbgPageCache {
  QByteArray buffer;
  QTime time;
};

class DbgGlobal {
 public:
  DbgGlobal();
  ~DbgGlobal();

  static DbgGlobal *inst();

  bool createDir(const QString &path);
  void loadPseudoCode(const QString &path, ManaDatabase *mdb, bool reload = false);
  void insertPseudoCode(const QString &path, ManaDatabase *mdb);

  QString exePath();
  QString exeDir();
  QString tempDir();
  QString dataDir();
  QString adbDir();
  QString traceDir();
  QString usrdataDir();
  QString includeDir();
  QString breakpadDir();
  QString decacheDir(const QString &triple);
  QString cfgPath();
  QString licensePath();
  DbgPlatformType currentPlatform();
  mana::ArchType currentArch();
  bool isCloudPlatform();
  void updatePlatform();
  void updateUSBForward();

  unsigned pathCRC(const QString &path, DbgModule *module);
  QString pathModule(const QString &path, DbgModule *module);
  QString pathModuleMeta(const QString &path, DbgModule *module);
  bool hasModule(const QString &path, DbgModule *module);
  void addModule(const QString &path, DbgModule *module,
                 const QString *rtpath = nullptr);
  ManaDatabase *getModule(const QString &path, DbgModule *module);
  QString *mapPath(const QString &path);

  void clearAll();
  Disassembler *diser(const ManaFunc *fn, ManaDatabase *adb = nullptr);
  Disassembler *diser(bool thumb) { return thumb ? diserT32 : diserA32; }
  ManaDatabase *createMemModule(duint addr);

 public:
  std::map<unsigned, ManaDatabase *> modules;
  ParallelThread parallel;
  ManaDatabase *debugee = nullptr;
  std::map<uint64_t, std::string>
      dbgpatches;  // patches for memory when debugging
  std::map<uint64_t, DbgPageCache> dbgpages;  // pages for memory cache
  std::map<QString, QString> decaches;        // decache map from dyld cache
  std::map<ManaDatabase *, QString> pseudos;  // decompiled psuedo code map
 private:
  Disassembler *diserA64 = nullptr;
  Disassembler *diserA32 = nullptr;
  Disassembler *diserT32 = nullptr;
  Disassembler *diserX64 = nullptr;
  QProcess usbmuxLLDBSvr;
  QProcess usbmuxDbgSvr;
  QProcess usbmuxTBHttpSvr;
 public:
  std::map<uint64_t, ManaDatabase *> memModules;
};

#endif  // _GLOBAL_H
