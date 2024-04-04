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

#ifdef _WIN32
#ifdef DLLIMPL
#define __MANA_API__ __declspec(dllexport)
#else
#ifdef _CONSOLE
#define __MANA_API__
#else
#define __MANA_API__ __declspec(dllimport)
#endif
#endif
#else
#define __MANA_API__ __attribute__((visibility("default")))
#endif
