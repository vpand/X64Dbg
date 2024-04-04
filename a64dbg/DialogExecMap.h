#ifndef DIALOGEXECMAP_H
#define DIALOGEXECMAP_H

#include <QDialog>
#include <abstraction/DebugEngine.hpp>

#include "bridge/_global.h"

using namespace dbgapi;

namespace Ui {
class DialogExecMap;
}

class DisassemblerGraphView;

class DialogExecMap : public QDialog {
  Q_OBJECT

 public:
  explicit DialogExecMap(DisassemblerGraphView *gview,
                         QWidget *parent = nullptr);
  ~DialogExecMap();

  void syncToPC();

 public slots:
  void syncToPCSlot();
  void valueChangedPCSlot(int value);
  void valueChangedBBSlot(int value);
  void valueChangedBLSlot(int value);
  void debugStateChangedSlot(DBGSTATE state);

 private:
  bool syncToPCImpl();
  void loadDyndecSource();
  void freeResource();
  void updateSummery();

 private:
  Ui::DialogExecMap *ui;
  bool mDisableUpdatePC = false;
  bool mDisableUpdateBB = false;

  QString mModulePath;
  RecordARM mRecordARMAll;
  RecordARM mRecordARMCur;
  RecordARM64 mRecordARM64All;
  RecordARM64 mRecordARM64Cur;
  RecordIndexs mRecordInds;
  PageBuffers mPageBuffs;
  PageBuffers mPageRawBuffs;
  int mRecordCur = -1;
  uint64_t mRuntimeBase;

  mana::Binary *mModuleBin = nullptr;
  mana::Function *mAutoGenFunc = nullptr;
  std::string *mAutoGenFuncOpcodes = nullptr;
  std::vector<std::pair<int, int>> mAutoGenFuncBBS;
  std::vector<int> mBBInds;
  std::vector<int> mBLInds;
  std::vector<std::pair<int, int>> mRecordIndsMinMaxRVA;
};

#endif  // DIALOGEXECMAP_H
