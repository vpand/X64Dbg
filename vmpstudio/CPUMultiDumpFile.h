#ifndef CPUMULTIDUMP_H
#define CPUMULTIDUMP_H

#include <QWidget>

#include "Bridge.h"
#include "DisassemblyFile.h"
#include "MemoryPage.h"
#include "TabWidget.h"

class CPUDumpFile;
class WatchView;
class StructWidget;
class CPUDisassemblyFile;
class LocalVarsView;
class VMPManaDatabase;

class CPUMultiDumpFile : public MHTabWidget {
  Q_OBJECT
 public:
  explicit CPUMultiDumpFile(CPUDisassemblyFile* disas, int nbCpuDumpTabs = 1,
                            QWidget* parent = 0);
  CPUDumpFile* getCurrentCPUDump();
  void getTabNames(QList<QString>& names);
  int getMaxCPUTabs();
  void resetDatabase(VMPManaDatabase* mdb);
  QMenu* mDumpPluginMenu;

 signals:
  void displayReferencesWidget();

 public slots:
  void updateCurrentTabSlot(int tabIndex);
  void printDumpAtSlot(dsint parVa);
  void printDumpAtNSlot(duint parVa, int index);
  void selectionGetSlot(SELECTIONDATA* selectionData);
  void selectionSetSlot(const SELECTIONDATA* selectionData);
  void dbgStateChangedSlot(DBGSTATE dbgState);
  void openChangeTabTitleDialogSlot(int tabIndex);
  void displayReferencesWidgetSlot();
  void focusCurrentDumpSlot();
  void showDisassemblyTabSlot(duint selectionStart, duint selectionEnd,
                              duint firstAddress);
  void getDumpAttention();

 private:
  CPUDumpFile* mCurrentCPUDump;
  VMPOpcodePage mMemPage;
  bool mInitAllDumpTabs;
  uint mMaxCPUDumpTabs;

  WatchView* mWatch;
  LocalVarsView* mLocalVars;
  StructWidget* mStructWidget;
  CPUDisassemblyFile* mDisassembly = nullptr;

  int GetDumpWindowIndex(int dump);
  int GetWatchWindowIndex();
  void SwitchToDumpWindow();
  void SwitchToWatchWindow();
};

#endif  // CPUMULTIDUMP_H
