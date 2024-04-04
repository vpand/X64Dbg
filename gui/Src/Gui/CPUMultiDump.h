#ifndef CPUMULTIDUMP_H
#define CPUMULTIDUMP_H

#include <QWidget>

#include "Bridge.h"
#include "TabWidget.h"

class CPUDump;
class WatchView;
class StructWidget;
class CPUDisassembly;
class LocalVarsView;
class SourceView;

class CPUMultiDump : public MHTabWidget {
  Q_OBJECT
 public:
  explicit CPUMultiDump(CPUDisassembly* disas, int nbCpuDumpTabs = 1,
                        QWidget* parent = 0);
  CPUDump* getCurrentCPUDump();
  void getTabNames(QList<QString>& names);
  int getMaxCPUTabs();
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
  void disassembleAtSlot(dsint addr, dsint pc);
  void loadPseudoSourceSlot(const QString &src, duint base);

 private:
  CPUDump* mCurrentCPUDump;
  bool mInitAllDumpTabs;
  uint mMaxCPUDumpTabs;

  WatchView* mWatch;
  LocalVarsView* mLocalVars;
  StructWidget* mStructWidget;
  CPUDisassembly* mDisassembly = nullptr;
  SourceView* mSourceView;

  int GetDumpWindowIndex(int dump);
  int GetWatchWindowIndex();
  void SwitchToDumpWindow();
  void SwitchToWatchWindow();
};

#endif  // CPUMULTIDUMP_H
