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

namespace dbgapi {

#pragma pack(push)
#pragma pack(1)

typedef char smana8;
typedef short smana16;
typedef int smana32;
typedef long long smana64;
typedef unsigned char umana8;
typedef unsigned short umana16;
typedef unsigned int umana32;
typedef unsigned long long umana64;

#define StructCheck(name, sz) \
  static const int __check##name[sizeof(name) == (sz) ? 1 : -1] = {0}

struct ManaSect {
  struct {
    umana8 type;
    umana16 name;
    umana8 reserved;
  } info;
  umana32 fileoff;
  umana32 size;
  umana64 addr;
};
StructCheck(ManaSect, 5 * sizeof(umana32));

struct ManaInsn {
  umana32 type : 3;
  umana32 oplen : 4;
  umana32 ngout : 3;
  umana32 ncomin : 22;
  umana64 gooff : 34;
  umana64 fnoff : 30;

  umana32 opcodeSize() const { return oplen + 1; }
};
StructCheck(ManaInsn, 3 * sizeof(umana32));

struct ManaLoop1 {
  umana8 from;
  umana8 to;
};
StructCheck(ManaLoop1, 2 * sizeof(umana8));

struct ManaLoop2 {
  umana16 from;
  umana16 to;
};
StructCheck(ManaLoop2, 2 * sizeof(umana16));

struct ManaLoop4 {
  umana32 from;
  umana32 to;
};
StructCheck(ManaLoop4, 2 * sizeof(umana32));

enum ManaFuncFlag {
  MFF_EXPORT = 0x1,
  MFF_IMPORT = 0x2,
};

struct ManaFunc {
  umana32 name;
  umana32 rvastart;
  umana32 rvaend;
  umana32 ninsn;
  struct {
    umana16 nloop;
    umana8 thumb;
    umana8 flags;
  } info;
  umana32 insnoff;
  umana32 loopoff;

  umana32 sizeofIndex() const {
    if (ninsn <= 0xFF) return 1;
    if (ninsn <= 0xFFFF) return 2;
    if (ninsn <= 0xFFFFFF) return 4;
    return -1;
  }

  umana32 cominOffset(const ManaInsn *insn) const {
    return insn->gooff + sizeofIndex() * insn->ngout;
  }
};
StructCheck(ManaFunc, 7 * sizeof(umana32));

struct ManaFile {
  umana32 magic;
  umana32 version;
  umana32 filehash;
  struct {
    umana8 filetype;
    umana8 arch;
    umana8 nsect;
    umana8 reserved;
  } info;
  umana64 baseaddr;
  umana32 nfunc;
  umana32 stroff;
  umana32 funcoff;

  const ManaSect *sect(int i) const {
    return (ManaSect *)((char *)this + sizeof(*this)) + i;
  }

  const ManaFunc *func(int i) const {
    return (ManaFunc *)((char *)this + funcoff) + i;
  }

  const ManaInsn *insn(const ManaFunc *fn, int i) const {
    return (ManaInsn *)((char *)this + fn->insnoff) + i;
  }

  const ManaLoop1 *loop1(const ManaFunc *fn, int i) const {
    return (ManaLoop1 *)((char *)this + fn->loopoff) + i;
  }

  const ManaLoop2 *loop2(const ManaFunc *fn, int i) const {
    return (ManaLoop2 *)((char *)this + fn->loopoff) + i;
  }

  const ManaLoop4 *loop4(const ManaFunc *fn, int i) const {
    return (ManaLoop4 *)((char *)this + fn->loopoff) + i;
  }

  const umana8 *index1(umana32 off) const {
    return (umana8 *)((char *)this + off);
  }

  const umana16 *index2(umana32 off) const {
    return (umana16 *)((char *)this + off);
  }

  const umana32 *index4(umana32 off) const {
    return (umana32 *)((char *)this + off);
  }

  const char *string(int off) const { return (char *)this + stroff + off; }

  umana64 address(umana32 rva) const { return baseaddr + rva; }
};
StructCheck(ManaFile, 9 * sizeof(umana32));

#pragma pack(pop)

} // end of dbgapi
