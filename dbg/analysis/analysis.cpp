#include "analysis.h"

#include "debugger.h"
#include "memory.h"

Analysis::Analysis(duint base, duint size) {
  mBase = base;
  mSize = size;
  mData = new unsigned char[mSize + MAX_DISASM_BUFFER];
  memset(mData, 0xCC, mSize + MAX_DISASM_BUFFER);
  MemReadDumb(base, mData, size);
}

Analysis::~Analysis() { delete[] mData; }