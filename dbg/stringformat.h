#ifndef _STRINGFORMAT_H
#define _STRINGFORMAT_H

//#include "_global.h"
#include "stringutils.h"
#include "bridge/bridgemain.h"

extern duint ModHashFromAddr(duint pageaddr);
extern duint ModHashFromName(const char *name);
extern duint ModBaseFromAddr(duint pageaddr);
extern bool ModNameFromAddr(duint pageaddr, char *name, bool b);
extern bool MemRead(duint addr, void *ptr, size_t size);

typedef const char* FormatValueType;
typedef std::vector<FormatValueType> FormatValueVector;

String stringformat(String format, const FormatValueVector& values);
String stringformatinline(String format);

#endif  //_STRINGFORMAT_H
