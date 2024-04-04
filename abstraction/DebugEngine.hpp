///////////////////////////////////YUNYOO.CN//////////////////////////////////////
//                                                                               *
// This file is part of A64Dbg and VMPStudio gui frontend project. *
//                                                                               *
// Copyright(C) 2021 YunYoo Corp., ALL RIGHTS RESERVED. *
//                                                                               *
// Internet: yunyoo.cn *
//                                                                               *
// This code is distributed "as is", part of YUNYOO.CN and without warranty of *
// any kind, expressed or implied, including, but not limited to warranty of *
// fitness for any particular purpose. In no event will YUNYOO.CN be liable to *
// you for any special, incidental, indirect, consequential or any other *
// damages caused by the use, misuse, or the inability to use of this code, *
// including anylost profits or lost savings, even if YUNYOO.CN has been advised
// * of the possibility of such damages. *
//                                                                               *
///////////////////////////////////////*//////////////////////////////////////////

#pragma once

#include <abstraction/Disassembler.h>
#include <abstraction/LLDBEngine.hpp>
#include <functional>

namespace dbgapi {

// some extra utils

std::string __MANA_API__ tburl_request(const char *ip, const char *command,
                                       const char *body);
std::string __MANA_API__ tburl_request(const char *ip, const char *command,
                                       const char *param, const char *body);
bool __MANA_API__ tbget_file_ex(const char *ip, const char *path,
                                const char *savepath);

bool __MANA_API__ is_android_64(const char *adb, int pid, const char *exe);

void __MANA_API__ adb_pull(const char *adb, const char *rfile,
                           const char *locfile);
std::string __MANA_API__ adb_push(const char *adb, const char *file);
std::string __MANA_API__ adb_shell(const char *adb, const char *cmd, bool root);

// uvmdbg command type

enum UVMDBG_CommandType {
  udct_disconnect,

  udct_s2c_init,
  udct_s2c_modules,
  udct_s2c_threads,
  udct_s2c_callstack,
  udct_s2c_readmem,
  udct_s2c_writemem,
  udct_s2c_setbp,
  udct_s2c_run,
  udct_s2c_pause,
  udct_s2c_stepinto,
  udct_s2c_stepover,
  udct_s2c_stepout,
  udct_s2c_stepbbend,
  udct_s2c_updatectx,
  udct_s2c_switchthread,
  udct_s2c_runadc,

  udct_c2s_ready,
  udct_c2s_modules,
  udct_c2s_bpsetted,
  udct_c2s_stopped,
  udct_c2s_bphited,
  udct_c2s_memory,
  udct_c2s_threads,
  udct_c2s_callstack,
  udct_c2s_switchthread,
  udct_c2s_log,
  udct_c2s_adcoutput,
};

// uraniumvm server command type

enum UVMSVR_CommandType {
  uvmct_s2c_init,
  uvmct_s2c_shell_result,
  uvmct_s2c_getfile_result,
  uvmct_s2c_postfile_result,

  uvmct_c2s_shell,
  uvmct_c2s_shell_timeout,
  uvmct_c2s_getfile,
  uvmct_c2s_postfile,
};

// UraniumVM trace server running inside VMPStudio
class __MANA_API__ UraniumVMServer {
 public:
  UraniumVMServer();
  ~UraniumVMServer();

  void start(
      std::function<void()> income,
      std::function<void(UVMDBG_CommandType, const char *, int, uint64_t)>
          protocol);
  void stop();
  int send(UVMDBG_CommandType type, const char *buf = nullptr, size_t bufsz = 0,
           uint64_t extra = 0);
  void disconnect();

  static const char *local_ip();

 protected:
  void *m_ctx;
};

#if __APPLE__
// UVM helper server running inside M1 macOS's VMPStudio
class __MANA_API__ UVMServer {
 public:
  UVMServer();
  ~UVMServer();

  static void start();
  static void stop();
};
#endif

// client of UVMServer
class __MANA_API__ UVMClient {
 public:
  UVMClient();
  ~UVMClient();

  void connect(
      const char *remoteip,
      std::function<void(UVMSVR_CommandType, const char *, int, uint64_t)>
          protocol);
  void close();
  int send(UVMSVR_CommandType type, const char *buf, size_t bufsz,
           uint64_t extra = 0);
  bool valid();

  static void cloudPort(std::function<void(int)> callback);

 protected:
  void *m_ctx;
};

// for VMPStudio
class __MANA_API__ UraniumEngine : public LLDBEngine {
 public:
  UraniumEngine(const DbgGuiOperator *guiops);
  ~UraniumEngine();
};

// sub regs

#pragma pack(push)
#pragma pack(1)

struct arm_subregs_t {
  uint32_t flags;
  uint32_t gprs[15];
};

struct arm64_subregs_t {
  uint32_t flags;
  uint64_t gprs[31];
};

struct x64_subregs_t {
  uint64_t flags;
  uint64_t rax;
  uint64_t rbx;
  uint64_t rcx;
  uint64_t rdx;
  uint64_t rbp;
  uint64_t rsi;
  uint64_t rdi;
  uint64_t r8;
  uint64_t r9;
  uint64_t r10;
  uint64_t r11;
  uint64_t r12;
  uint64_t r13;
  uint64_t r14;
  uint64_t r15;
  uint64_t rsp;
  uint64_t rip;
};

struct arm_pcreg_record_header_t {
  uint64_t pc;
  uint32_t count;
  arm_subregs_t subregs[0];
};

struct arm64_pcreg_record_header_t {
  uint64_t pc;
  uint32_t count;
  arm64_subregs_t subregs[0];
};

struct x64_pcreg_record_header_t {
  uint64_t pc;
  uint32_t count;
  x64_subregs_t subregs[0];
};

#pragma pack(pop)  // end of byte align

typedef std::pair<addr_t, std::vector<arm_subregs_t>> RecordItemARM;
typedef std::pair<addr_t, std::vector<arm64_subregs_t>> RecordItemARM64;
typedef std::pair<addr_t, std::vector<x64_subregs_t>> RecordItemX64;

typedef std::map<addr_t, std::vector<arm_subregs_t>> RecordARM;
typedef std::map<addr_t, std::vector<arm64_subregs_t>> RecordARM64;
typedef std::map<addr_t, std::vector<x64_subregs_t>> RecordX64;

typedef std::vector<std::vector<uint64_t>> RecordIndexs;
typedef std::map<addr_t, std::string> PageBuffers;

typedef std::function<const char *(addr_t)> addr2name_cb_t;

// decompiler

#define UVMPAGE_SIZE 0x1000
#define UVMPAGE_MASK (UVMPAGE_SIZE - 1)
#define UVMSAMPLE_DBMAGIC 'sdb$'
#define UVMSAMPLE_DBVERSION 2

enum sample_operator_t {
  SOT_LOAD,
  SOT_SAVE,
  SOT_DIFFER,
  SOT_COMBINE,
  SOT_EXECUTED_PCBBS,
  SOT_COMBINED_PCBBS,
  SOT_REWRITED_PCBBS,
  SOT_REWRITED_SAVE,
  SOT_REWRITED_SAVE_CLEAR,
  SOT_DYNDEC_SAVE,
  SOT_CALL_ADDRESSES,
  SOT_CALL_GRAPH,
};

struct sample_dbfun_t {
  mana::Function *fun = nullptr;
  std::string *opc = nullptr;
  const char *rawopc = nullptr;
};

struct sample_params_t {
  mana::Binary *bin = nullptr;
  addr_t rtbase;
  PageBuffers *pages = nullptr;
  PageBuffers *rawpages = nullptr;
  RecordIndexs *indexs = nullptr;
  int index;

  RecordARM *regsarm = nullptr;
  RecordARM64 *regsarm64 = nullptr;
  RecordX64 *regsx64 = nullptr;
  const char *outpath = nullptr;
  sample_operator_t opr;
  int *index2 = nullptr;
  int index2count;
  int cgrenderdepth;

  addr2name_cb_t addr2name;

  std::set<addr_t> opr_indexs;
  sample_dbfun_t opr_func;
};

struct urdec_params_t : public sample_params_t {
  const char *srcpath = nullptr;
  addr_t start;
  addr_t end;
};

// retargetable decompiler main entry (https://github.com/avast/retdec/)
int __MANA_API__ retdec_main(
    const char *input, const char *output = nullptr, addr_t start = 0,
    addr_t end = 0, addr2name_cb_t addr2name = nullptr);

// uranium dynamic decompiler main entry
int __MANA_API__
urdyndec_main(urdec_params_t *params, addr2name_cb_t addr2name = nullptr);

// sample database operations
int __MANA_API__ sampledb_main(sample_params_t *params);

}  // namespace dbgapi
