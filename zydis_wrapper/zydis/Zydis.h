#ifndef __FAKE_ZYDIS_H__
#define __FAKE_ZYDIS_H__

enum ZydisFlagAction {
  ZYDIS_CPUFLAG_ACTION_NONE,
  ZYDIS_CPUFLAG_ACTION_MODIFIED,
  ZYDIS_CPUFLAG_ACTION_SET_0,
  ZYDIS_CPUFLAG_ACTION_SET_1,
  ZYDIS_CPUFLAG_ACTION_TESTED,
};

struct ZydisAccessFlag {
  ZydisFlagAction action;
};

struct ZydisDecodedInstruction {
  int attributes;
  int operandWidth;
  ZydisAccessFlag accessedFlags[0];
};
enum ZydisRegister {
  /*case*/ ZYDIS_REGISTER_RAX,
  // return registers.regcontext.cax;
  /*case*/ ZYDIS_REGISTER_RCX,
  // return registers.regcontext.ccx;
  /*case*/ ZYDIS_REGISTER_RDX,
  // return registers.regcontext.cdx;
  /*case*/ ZYDIS_REGISTER_RBX,
  // return registers.regcontext.cbx;
  /*case*/ ZYDIS_REGISTER_RSP,
  // return registers.regcontext.csp;
  /*case*/ ZYDIS_REGISTER_RBP,
  // return registers.regcontext.cbp;
  /*case*/ ZYDIS_REGISTER_RSI,
  // return registers.regcontext.csi;
  /*case*/ ZYDIS_REGISTER_RDI,
  // return registers.regcontext.cdi;
  /*case*/ ZYDIS_REGISTER_R8,
  // return registers.regcontext.r8;
  /*case*/ ZYDIS_REGISTER_R9,
  // return registers.regcontext.r9;
  /*case*/ ZYDIS_REGISTER_R10,
  // return registers.regcontext.r10;
  /*case*/ ZYDIS_REGISTER_R11,
  // return registers.regcontext.r11;
  /*case*/ ZYDIS_REGISTER_R12,
  // return registers.regcontext.r12;
  /*case*/ ZYDIS_REGISTER_R13,
  // return registers.regcontext.r13;
  /*case*/ ZYDIS_REGISTER_R14,
  // return registers.regcontext.r14;
  /*case*/ ZYDIS_REGISTER_R15,
  // return registers.regcontext.r15;
  /*case*/ ZYDIS_REGISTER_R8D,
  // return registers.regcontext.r8 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R9D,
  // return registers.regcontext.r9 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R10D,
  // return registers.regcontext.r10 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R11D,
  // return registers.regcontext.r11 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R12D,
  // return registers.regcontext.r12 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R13D,
  // return registers.regcontext.r13 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R15D,
  // return registers.regcontext.r15 & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_R8W,
  // return registers.regcontext.r8 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R9W,
  // return registers.regcontext.r9 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R10W,
  // return registers.regcontext.r10 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R11W,
  // return registers.regcontext.r11 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R12W,
  // return registers.regcontext.r12 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R13W,
  // return registers.regcontext.r13 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R15W,
  // return registers.regcontext.r15 & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_R8B,
  // return registers.regcontext.r8 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R9B,
  // return registers.regcontext.r9 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R10B,
  // return registers.regcontext.r10 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R11B,
  // return registers.regcontext.r11 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R12B,
  // return registers.regcontext.r12 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R13B,
  // return registers.regcontext.r13 & 0xFF;
  /*case*/ ZYDIS_REGISTER_R15B,
  // return registers.regcontext.r15 & 0xFF;
  /*case*/ ZYDIS_REGISTER_EAX,
  // return registers.regcontext.cax & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_ECX,
  // return registers.regcontext.ccx & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_EDX,
  // return registers.regcontext.cdx & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_EBX,
  // return registers.regcontext.cbx & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_ESP,
  // return registers.regcontext.csp & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_EBP,
  // return registers.regcontext.cbp & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_ESI,
  // return registers.regcontext.csi & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_EDI,
  // return registers.regcontext.cdi & 0xFFFFFFFF;
  /*case*/ ZYDIS_REGISTER_AX,
  // return registers.regcontext.cax & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_CX,
  // return registers.regcontext.ccx & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_DX,
  // return registers.regcontext.cdx & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_BX,
  // return registers.regcontext.cbx & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_SP,
  // return registers.regcontext.csp & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_BP,
  // return registers.regcontext.cbp & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_SI,
  // return registers.regcontext.csi & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_DI,
  // return registers.regcontext.cdi & 0xFFFF;
  /*case*/ ZYDIS_REGISTER_AL,
  // return registers.regcontext.cax & 0xFF;
  /*case*/ ZYDIS_REGISTER_CL,
  // return registers.regcontext.ccx & 0xFF;
  /*case*/ ZYDIS_REGISTER_DL,
  // return registers.regcontext.cdx & 0xFF;
  /*case*/ ZYDIS_REGISTER_BL,
  // return registers.regcontext.cbx & 0xFF;
  /*case*/ ZYDIS_REGISTER_AH,
  // return (registers.regcontext.cax & 0xFF00) >> 8;
  /*case*/ ZYDIS_REGISTER_CH,
  // return (registers.regcontext.ccx & 0xFF00) >> 8;
  /*case*/ ZYDIS_REGISTER_DH,
  // return (registers.regcontext.cdx & 0xFF00) >> 8;
  /*case*/ ZYDIS_REGISTER_BH,
};
struct ZydisMnemonic {};

enum ZydisOperandType {
  ZYDIS_OPERAND_TYPE_REGISTER,
  ZYDIS_OPERAND_TYPE_IMMEDIATE,
  ZYDIS_OPERAND_TYPE_MEMORY,
  ZYDIS_OPERAND_TYPE_POINTER,
};
struct ZydisRegisterInfo {
  ZydisRegister value;
};
struct ZydisOperandValue {
  union {
    long u;
  } value;
};
struct ZydisMemdip {
  int value;
};
struct ZydisOperandMemory {
  ZydisRegister base;
  ZydisRegister index;
  int scale;
  ZydisRegister segment;
  ZydisMemdip disp;
  int offset;
};
struct ZydisDecodedOperand {
  ZydisOperandType type;
  int accessedFlags;
  ZydisRegisterInfo reg;
  ZydisOperandValue imm;
  int size;
  ZydisOperandMemory mem;
  ZydisOperandMemory ptr;
};
struct ZydisDecoder {};
struct ZydisCPUFlag {
  ZydisCPUFlag(int i) {}
};
struct ZydisFormatter {};

enum ZydisRegisterClass {
  ZYDIS_REGCLASS_X87,
  ZYDIS_REGCLASS_MMX,
  ZYDIS_REGCLASS_XMM,
  ZYDIS_REGCLASS_YMM,
  ZYDIS_REGCLASS_ZMM,
};

#define ZYDIS_REGISTER_MAX_VALUE 0
#define ZYDIS_CPUFLAG_MAX_VALUE 0

#define ZYDIS_ATTRIB_HAS_LOCK 0
#define ZYDIS_ATTRIB_HAS_REP 0
#define ZYDIS_ATTRIB_HAS_REPE 0
#define ZYDIS_ATTRIB_HAS_REPNE 0
#define ZYDIS_ATTRIB_HAS_BOUND 0
#define ZYDIS_ATTRIB_HAS_XACQUIRE 0
#define ZYDIS_ATTRIB_HAS_XRELEASE 0

#define ZYDIS_REGISTER_RFLAGS 0
#define ZYDIS_REGISTER_EFLAGS 0
#define ZYDIS_REGISTER_FLAGS 0
#define ZYDIS_REGISTER_RIP 0
#define ZYDIS_REGISTER_NONE 0
#define ZYDIS_REGISTER_FS 0
#define ZYDIS_REGISTER_GS 0

#define ZydisRegisterGetClass(...) 0

#endif  // end of __FAKE_ZYDIS_H__
