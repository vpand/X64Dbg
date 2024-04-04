#pragma once
#include <QThread>

#include "QBeaEngine.h"
#include "TraceFileReader.h"

class TraceFileParser : public QThread {
  Q_OBJECT
  friend class TraceFileReader;
  TraceFileParser(TraceFileReader* parent) : QThread(parent) {}
  static void readFileHeader(TraceFileReader* that);
  void run();
};

class TraceFilePage {
 public:
  TraceFilePage(TraceFileReader* parent, unsigned long long fileOffset,
                unsigned long long maxLength);
  unsigned long long Length() const;
  const REGDUMP* Registers(unsigned long long index) const;
  void OpCode(unsigned long long index, unsigned char* buffer,
              int* opcodeSize) const;
  const Instruction_t& Instruction(unsigned long long index,
                                   QBeaEngine& mDisasm);
  DWORD ThreadId(unsigned long long index) const;
  int MemoryAccessCount(unsigned long long index) const;
  void MemoryAccessInfo(unsigned long long index, duint* address,
                        duint* oldMemory, duint* newMemory,
                        bool* isValid) const;

  FILETIME lastAccessed;  // system user time

  void updateInstructions();

 private:
  template <typename REGDMP>
  void load(TraceFileReader* parent, unsigned long long fileOffset,
            unsigned long long maxLength, std::vector<REGDMP> &curregs);

 private:
  friend class TraceFileReader;
  TraceFileReader* mParent;
  std::vector<REGDUMPA64> mRegistersA64;
  std::vector<REGDUMPA32> mRegistersA32;
  std::vector<REGDUMPX64> mRegistersX64;
  QByteArray opcodes;
  std::vector<size_t> opcodeOffset;
  std::vector<unsigned char> opcodeSize;
  std::vector<Instruction_t> instructions;
  std::vector<size_t> memoryOperandOffset;
  std::vector<char> memoryFlags;
  std::vector<duint> memoryAddress;
  std::vector<duint> oldMemory;
  std::vector<duint> newMemory;
  std::vector<DWORD> threadId;
  unsigned long long length;
};
