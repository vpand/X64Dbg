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

#include <assert.h>

#include <map>
#include <set>
#include <string>
#include <vector>

#include <abstraction/CommDef.h>
#include <abstraction/ManaFile.h>

#define MANA_ANOYPREFIX "sub_"

#define INVALID_ADDR (addr_t)(-1)
#define MAGIC_FILE_ANA ('$bda' + 1) // +objc
#define MAGIC_FILE_EXT "adb"
#define MANA_FILE_VERSION 2

#if __APPLE__ || __linux__
typedef size_t addr_t;
#define ADDRFMT "%lx"
#else
typedef unsigned long long addr_t;
#define ADDRFMT "%llx"
#endif

namespace dbgapi {

class Disassembler;

namespace mana {

enum FileType {
  UnsupportFile,
  MachO,
  ELF,
  PE,
};

enum ArchType {
  UnsupportArch,
  ARMV5TE,
  ARM,
  ARM64,
  X86,
  X86_64,
};

enum SectType {
  TEXT,
  DATA,
};

enum InsnType {
  IDATA,
  NORMAL,
  JUMP,
  JCOND,
  CALL,
  RET,
};

struct Section {
  std::string name;
  SectType type;
  size_t foff;
  size_t size;
  addr_t addr;
};
typedef std::map<addr_t, Section> Sections;
typedef std::map<addr_t, const char *> SectionBuffs;

struct Import {
  std::string name;
  size_t foff;  // got/lazyptr fileoff
  int lib;
};
typedef std::vector<Import> Imports;

struct ImportInfos {
  std::vector<std::string> libs;
  std::vector<std::string> importfns;
  std::vector<size_t> importfoffs;
};

struct Insinfo;
typedef std::vector<Insinfo> Insinfos;
typedef std::vector<int> Insrefs;
typedef std::map<int, int> Loops;
typedef std::set<addr_t> Addresses;
struct Insinfo {
  struct {
    unsigned short type;
    unsigned short oplen;
  } info;
  int fnoff;
  Insrefs comins;
  Insrefs gouts;

  bool operator<(const Insinfo &I) const { return fnoff < I.fnoff; }
  const char *typeString() const;
};

struct __MANA_API__ Function {
  std::string name;
  addr_t start;
  addr_t end;
  Insinfos insns;
  Loops loops;
  Insrefs rets;     // return s
  Addresses getpc;  // call $+5
  Addresses difs;   // data in functions
  Addresses jdsts;  // jump destination in functions
  int flags;        // MFF_xxx

  Function() {
    start = INVALID_ADDR;
    end = INVALID_ADDR;
    flags = 0;
  }

  Function(const Function &F) {
    name = F.name;
    start = F.start;
    end = F.end;
    insns = F.insns;
    loops = F.loops;
    rets = F.rets;    // return s
    getpc = F.getpc;  // call $+5
    difs = F.difs;    // data in functions
    jdsts = F.jdsts;  // jump destination in functions
    flags = F.flags;  // MFF_xxx
  }

  bool isData() const {
    return insns.size() == 1 && insns[0].info.type == IDATA;
  }

  void reset() {
    insns.clear();
    loops.clear();
    rets.clear();
    getpc.clear();
    difs.clear();
    jdsts.clear();
  }

  bool operator<(const Function &F) const { return start < F.start; }
  bool operator==(const Function &F) const { return start == F.start; }

  Function &operator=(const Function &F) {
    name = F.name;
    start = F.start;
    end = F.end;
    insns = F.insns;
    loops = F.loops;
    rets = F.rets;    // return s
    getpc = F.getpc;  // call $+5
    difs = F.difs;    // data in functions
    jdsts = F.jdsts;  // jump destination in functions
    flags = F.flags;  // MFF_xxx
    return *this;
  }
};
typedef std::map<addr_t, Function> Functions;
typedef std::map<addr_t, Function *> ImportFunctions;

class __MANA_API__ Machine {
 public:
  Machine() {}
  virtual ~Machine() {}

  virtual int defaultConsume() { return 0; }
  virtual bool isCallReg(void *llvminst) { return 0; }
  virtual bool isCallMem(void *llvminst) { return 0; }
  virtual bool isCallPcrel(void *llvminst) { return 0; }
  virtual bool isJumpPcrel(void *llvminst) { return 0; }
  bool isCall(void *llvminst) {
    return isCallPcrel(llvminst) || isCallMem(llvminst) || isCallReg(llvminst);
  }

  virtual InsnType insnType(void *llvminst) { return IDATA; }
  virtual addr_t callee(void *llvminst, int opclen, addr_t pc) { return 0; }
  virtual addr_t jumpee(void *llvminst, int opclen, addr_t pc) { return 0; }
  virtual addr_t dstAddr(void *llvminst, int opclen, addr_t pc) { return 0; }

 protected:
  ArchType m_arch;
};

class __MANA_API__ MachineX86 : public Machine {
 public:
  MachineX86() { m_arch = X86_64; }
  virtual ~MachineX86() {}
};

class __MANA_API__ MachineARM64 : public Machine {
 public:
  MachineARM64() { m_arch = ARM64; }
  virtual ~MachineARM64() {}
};

class __MANA_API__ MachineARM : public Machine {
 public:
  MachineARM() { m_arch = ARM; }
  virtual ~MachineARM() {}
};

void insertDatas(ArchType arch, Functions &funcs);

typedef void (*analyze_progress_t)(const char *prefix, int cur, int max,
                                   int &tmp);
typedef int (*analyze_log_t)(const char *format, ...);

extern __MANA_API__ analyze_progress_t analyze_progress;
extern __MANA_API__ analyze_log_t analyze_log;

class __MANA_API__ Binary {
 public:
  Binary();
  virtual ~Binary();

  bool isCode(addr_t addr);
  bool isTextCode(addr_t addr);
  const Function *addrFunc(addr_t addr) const;
  const Section *addrSect(addr_t addr) const;
  const Section *nameSect(const char *name) const;
  const char *addrBuff(addr_t addr) const;

  bool valid() const;
  bool load(const char *dbpath);
  bool save(const char *dbpath, bool compress = false);
  void dump();
  const char *triple(bool thumb) const;
  const char *arch(bool thumb) const;

  FileType fileType() const;
  const char *fileTypeString() const;
  unsigned fileHash() const;

  ArchType archType() const;
  const char *archTypeString() const;

  Sections &sections();

  SectionBuffs &sectBuffers();

  Functions &functions();

  Function &insertFunc(addr_t addr);
  void analyzeFunc(Disassembler *diser, const char *opcodes, Function &func);

  std::vector<const char *> importLibs() const;
  std::vector<const char *> importMachOLibs() const;
  std::vector<const char *> importELFLibs() const;
  std::vector<const char *> importPELibs() const;

  void readObj(std::string &outs) const;

  addr_t imageBase() const;

  const char *filePath() const;
  const char *fileBuffer(size_t &size) const;

  bool analyze(const void *llvmbin);

  void setContext(void *ctx) { m_ctx = ctx; }
  void *context() { return m_ctx; }
 protected:
  void *m_ctx;
};

class __MANA_API__ MachoBinary : public Binary {
 public:
  MachoBinary() {}
  virtual ~MachoBinary() {}

  bool isEncrypted();
  ImportInfos parseImports();
};

class __MANA_API__ MachoARM64Binary : public MachoBinary, public MachineARM64 {
 public:
  MachoARM64Binary() {}
  virtual ~MachoARM64Binary() {}

  virtual bool isArm64e() const { return false; }
};

class __MANA_API__ MachoARMBinary : public MachoBinary, public MachineARM {
 public:
  MachoARMBinary() {}
  virtual ~MachoARMBinary() {}
};

class __MANA_API__ MachoX32Binary : public MachoBinary, public MachineX86 {
 public:
  MachoX32Binary() {}
  virtual ~MachoX32Binary() {}
};

class __MANA_API__ MachoX64Binary : public MachoX32Binary {
 public:
  MachoX64Binary() {}
  virtual ~MachoX64Binary() {}
};

class __MANA_API__ PEBinary : public Binary {
 public:
  PEBinary() {}
  virtual ~PEBinary() {}
};

class __MANA_API__ PEX32Binary : public PEBinary, public MachineX86 {
 public:
  PEX32Binary() {}
  virtual ~PEX32Binary() {}
};

class __MANA_API__ PEX64Binary : public PEX32Binary {
 public:
  PEX64Binary() {}
  virtual ~PEX64Binary() {}
};

class __MANA_API__ ELFBinary : public Binary {
 public:
  ELFBinary() {}
  virtual ~ELFBinary() {}

  ImportInfos parseImports();
};

class __MANA_API__ ELFX32Binary : public ELFBinary, public MachineX86 {
 public:
  ELFX32Binary() {}
  virtual ~ELFX32Binary() {}
};

class __MANA_API__ ELFX64Binary : public ELFX32Binary {
 public:
  ELFX64Binary() {}
  virtual ~ELFX64Binary() {}
};

class __MANA_API__ ELFARMBinary : public ELFBinary, public MachineARM {
 public:
  ELFARMBinary() {}
  virtual ~ELFARMBinary() {}
};

class __MANA_API__ ELFARM64Binary : public ELFBinary, public MachineARM64 {
 public:
  ELFARM64Binary() {}
  virtual ~ELFARM64Binary() {}
};

class __MANA_API__ KamiBinary : public Binary {
 public:
  KamiBinary() {}
  virtual ~KamiBinary() {}

  void initLLVM(const char *opcodes, int opcsize);
};

class __MANA_API__ AnyBinary : public Binary {
 public:
  AnyBinary() {}
  virtual ~AnyBinary() {}
};

__MANA_API__ Binary *New(const char *path, const char *triple = nullptr,
                         bool analyze = true);
__MANA_API__ void Delete(Binary *bin);
__MANA_API__ void compressDBFile(const char *dbpath);
__MANA_API__ ManaFile *uncompressDBFile(const char *dbpath);
__MANA_API__ bool compressBuffer(const char *buff, int size, std::string *out);
__MANA_API__ bool uncompressBuffer(const char *buff, int size, int realsize, std::string *out);

} // namespace mana
} // end of dbgapi
