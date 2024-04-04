#ifndef TRACERECORD_H
#define TRACERECORD_H
// #include <zydis_wrapper.h>

#include "../bridge/bridgemain.h"
#include "_dbgfunctions.h"
#include "stringutils.h"
// #include "debugger.h"
// #include "jansson/jansson_x64dbg.h"

#include <QJsonObject>

class TraceRecordManager {
 public:
  enum TraceRecordByteType {
    InstructionBody = 0,
    InstructionHeading = 1,
    InstructionTailing = 2,
    InstructionOverlapped =
        3,  // The byte was executed with differing instruction base addresses
    DataByte,  // This and the following is not implemented yet.
    DataWord,
    DataDWord,
    DataQWord,
    DataFloat,
    DataDouble,
    DataLongDouble,
    DataXMM,
    DataYMM,
    DataMMX,
    DataMixed,            // the byte is accessed in multiple ways
    InstructionDataMixed  // the byte is both executed and written
  };

  /***************************************************************
   * Trace record data layout
   * TraceRecordNonoe: disable trace record
   * TraceRecordBitExec: single-bit, executed.
   * TraceRecordByteWithExecTypeAndCounter: 8-bit, YYXXXXXX
   *YY:=TraceRecordByteType_2bit, XXXXXX:=Hit count(6bit)
   * TraceRecordWordWithExecTypeAndCounter: 16-bit, YYXXXXXX XXXXXXXX
   *YY:=TraceRecordByteType_2bit, XX:=Hit count(14bit) Other: reserved for
   *future expanding
   **************************************************************/
  enum TraceRecordType {
    TraceRecordNone,
    TraceRecordBitExec,
    TraceRecordByteWithExecTypeAndCounter,
    TraceRecordWordWithExecTypeAndCounter
  };

  TraceRecordManager();
  ~TraceRecordManager();
  void clear();

  bool setTraceRecordType(duint pageAddress, TraceRecordType type);
  TraceRecordType getTraceRecordType(duint pageAddress);

  void TraceExecute(duint address, duint size);
  // void TraceAccess(duint address, unsigned char size, TraceRecordByteType
  // accessType);
  template <typename REGDMP, typename REGDMPWORD>
  void TraceExecuteRecord(const char *opbuff, int oplen,
                          REGDMPWORD &rtOldContext, bool *rtOldContextChanged);

  template <typename REGDMP, typename REGDMPWORD>
  void TraceExecuteRecord(duint cip, REGDMPWORD &rtOldContext, bool *rtOldContextChanged);

  unsigned int getHitCount(duint address);
  TraceRecordByteType getByteType(duint address);
  void increaseInstructionCounter();

  bool isRunTraceEnabled();
  bool enableRunTrace(bool enabled, const char* fileName);

  void saveToDb(QJsonObject &root);
  void loadFromDb(QJsonObject &root);

 public:
  template <typename REGDMP, typename REGDMPWORD>
  void TraceExecuteRecordInit(REGDMPWORD &rtOldContext, bool *rtOldContextChanged);

  enum TraceRecordByteType_2bit {
    _InstructionBody = 0,
    _InstructionHeading = 1,
    _InstructionTailing = 2,
    _InstructionOverlapped = 3
  };

  struct TraceRecordPage {
    void* rawPtr;
    duint rva;
    TraceRecordType dataType;
    unsigned int moduleIndex;
  };

  typedef union _REGDUMPWORDA64 {
    REGDUMPA64 registers;
    duint regword[sizeof(REGDUMPA64) / sizeof(duint)];
  } REGDUMPWORDA64;

  typedef union _REGDUMPWORDA32 {
    REGDUMPA32 registers;
    duint regword[sizeof(REGDUMPA32) / sizeof(duint)];
  } REGDUMPWORDA32;

  typedef union _REGDUMPWORDX64 {
    REGDUMPX64 registers;
    duint regword[sizeof(REGDUMPX64) / sizeof(duint)];
  } REGDUMPWORDX64;

  // Key := page base, value := trace record raw data
  std::unordered_map<duint, TraceRecordPage> TraceRecord;
  std::vector<std::string> ModuleNames;
  unsigned int getModuleIndex(const std::string& moduleName);
  unsigned int instructionCounter = 0;

  bool rtEnabled = false;
  bool rtPrevInstAvailable = false;
  HANDLE rtFile = nullptr;

  REGDUMPWORDA64 rtOldContextA64;
  bool rtOldContextChangedA64[sizeof(REGDUMPA64) / sizeof(duint)];
  REGDUMPWORDA32 rtOldContextA32;
  bool rtOldContextChangedA32[sizeof(REGDUMPA32) / sizeof(duint)];
  REGDUMPWORDX64 rtOldContextX64;
  bool rtOldContextChangedX64[sizeof(REGDUMPX64) / sizeof(duint)];

  DWORD rtOldThreadId;
  bool rtNeedThreadId;
  duint rtOldMemory[32];
  duint rtOldMemoryAddress[32];
  char rtOldOpcode[16];
  unsigned int rtRecordedInstructions;
  unsigned char rtOldOpcodeSize;
  unsigned char rtOldMemoryArrayCount;
};

void _dbg_dbgtraceexecute(duint CIP);

// exported to bridge
unsigned int _dbg_dbggetTraceRecordHitCount(duint address);
TRACERECORDBYTETYPE _dbg_dbggetTraceRecordByteType(duint address);
bool _dbg_dbgsetTraceRecordType(duint pageAddress, TRACERECORDTYPE type);
TRACERECORDTYPE _dbg_dbggetTraceRecordType(duint pageAddress);
bool _dbg_dbgenableRunTrace(bool enabled, const char* fileName);
bool _dbg_dbgisRunTraceEnabled();

#endif  // TRACERECORD_H
