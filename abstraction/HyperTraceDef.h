///////////////////////////////////YUNYOO.CN//////////////////////////////////////
//                                                                               *
// This file is part of A64Dbg and VMPStudio gui frontend project.               *
//                                                                               *
// Copyright(C) 2022 YunYoo Corp., ALL RIGHTS RESERVED.                          *
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

enum hypertrace_type_t {
    HTT_FUNCTION,
    HTT_OBJC,
    HTT_SYSCALL,
    HTT_HTTP2,
};

struct hypertrace_buffer_t {
  unsigned int size;
  unsigned int boff; // offset from hypertrace_database_t
};

struct hypertrace_callinfo_t {
  unsigned long long retaddr;
  unsigned long long args[8];
};

struct hypertrace_objcinfo_t : public hypertrace_callinfo_t {
  hypertrace_buffer_t classname;
  hypertrace_buffer_t selname;
};

struct hypertrace_item_t {
  unsigned long long key; // address for function/objc, sysno for syscall, index for http2
  unsigned int hits; // total execution hit count
  unsigned int reserved;
  unsigned int detailcount; // callinfo/objcinfo/syscall detail count, max to 1024
  unsigned int detailoff; // offset from hypertrace_database_t
};

struct hypertrace_database_t {
  unsigned char type; // hypertrace_type_t
  unsigned char reserved[3];
  unsigned int count;
  hypertrace_item_t items[0];
};
