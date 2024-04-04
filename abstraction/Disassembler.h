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

#include <map>
#include <string>

#include <abstraction/CommDef.h>

namespace dbgapi {

// x86/x64 rflags bits
struct rfbits {
  uint64_t CF : 1, Rsv1 : 1, PF : 1, Rsv3 : 1, AF : 1, Rsv5 : 1, ZF : 1, SF : 1,
      TF : 1, IF : 1, DF : 1, OF : 1, IOPL : 2, NT : 1, RSV15 : 1, RF : 1,
      VM : 1, AC : 1, VIF : 1, VIP : 1, ID : 1, Rsv22 : 10, Rsv32 : 32;
};

class __MANA_API__ Disassembler {
 public:
  Disassembler(const char *arch);
  Disassembler(const char *arch, const char *triple);
  ~Disassembler();

  bool ready();

  int disassemble(unsigned int mc, unsigned long long addr = 0);
  int disassemble(unsigned int mc, std::string &text,
                  unsigned long long addr = 0);
  int disassemble(const unsigned char *mc, int size,
                  unsigned long long addr = 0);
  int disassemble(const unsigned char *mc, int size, std::string &text,
                  unsigned long long addr = 0);
  uint64_t branchTarget(const unsigned char *mc, uint64_t addr,
                        int *oplen = nullptr, const void *gprs = nullptr,
                        bool *isptr = nullptr);
  bool hitCondA64(const uint64_t *gprs, int n, int z, int c, int v,
                  unsigned mc);
  bool hitCondA32(const uint64_t *gprs, int n, int z, int c, int v, int t,
                  unsigned mc);
  bool hitCondX64(const uint64_t *gprs, uint64_t flags, unsigned char *mc);
  std::string demangle(const char *sym);

  std::string assemble(const char *asmcode, unsigned char opcode[20]);
  const char *parseOpcode(const char *asmcode, unsigned char opcode[20]);

  int name(unsigned opc, char str[32]);
  int maxopc();

  uint64_t dstAddr();  // destinate address for b/bl/cb/tb/call/jmp

  void *context() { return m_ctx; }

 protected:
  void *m_ctx;
};

} // end of dbgapi
