#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QWidget>

#include "ActionHelpers.h"
#include "Bridge.h"
#include "VMPGlobal.h"

class QVBoxLayout;
class StdSearchListView;
class CPUDisassemblyFile;
class CPUMultiDumpFile;
class CPUStack;
class CPURegistersView;
class CPUInfoBox;
class StdTable;
class DisassemblerGraphView;
class MHDetachedWindow;
class LogView;

namespace Ui {
class CPUWidget;
}

class CPUWidgetFile : public QWidget, public ActionHelper<CPUWidgetFile> {
  Q_OBJECT

 public:
  explicit CPUWidgetFile(QWidget* parent = 0);
  ~CPUWidgetFile();

  // Misc
  void setDefaultDisposition();

  void saveWindowSettings();
  void loadWindowSettings();

  duint getSelectionVa();

  // Widget getters
  StdSearchListView* getSidebarWidget();
  CPUDisassemblyFile* getDisasmWidget();
  DisassemblerGraphView* getGraphWidget();
  CPUMultiDumpFile* getDumpWidget();
  StdSearchListView* getStackWidget();
  CPUInfoBox* getInfoBoxWidget();
  StdTable* getSectWidget() { return mSects; }

  void reloadFunc();

 public slots:
  void setDisasmFocus();
  void setGraphFocus();
  void updateStringSlot();
  void editFunSlot();
  void traceFunSlot();
  void traceFunStopSlot();
  void traceOptionSlot();
  void followFunInDumpNSlot();
  void followSectInDumpNSlot();
  void followStrInDumpNSlot();
  void decompileFunSlot();
  void dynamicDecompileFunSlot();
  void funContextMenu(QMenu* wMenu);
  void sectContextMenu(QPoint pt);
  void strContextMenu(QMenu* wMenu);
  void funcSelectionChanged(int index);
  void strSelectionChanged(int index);

 protected:
  void setupContextMenu();

 protected:
  StdSearchListView* mFuns;
  CPUDisassemblyFile* mDisas;
  DisassemblerGraphView* mGraph;
  MHDetachedWindow* mGraphWindow;
  CPUMultiDumpFile* mDump;
  StdSearchListView* mStrings;
  LogView* mLogView;
  CPUInfoBox* mInfo;
  StdTable* mSects;

  VMPManaFunc mCurFunc;
  duint mCurStr;

  QAction* mActionFunEdit;
  QMenu* mMenuFunFollowDumpN;
  QList<QAction*> mActionFunFollowDumpN;
  QMenu* mMenuSectFollowDumpN;
  QList<QAction*> mActionSectFollowDumpN;
  QMenu* mMenuStrFollowDumpN;
  QList<QAction*> mActionStrFollowDumpN;

  // uvm studio
  QAction* mActionFunTrace;
  QAction* mActionFunTraceStop;
  QAction* mActionFunTraceOption;
  QAction* mActionFunDecompile;
  QAction* mActionFunDynDecompile;

  int disasMode;

 private:
  Ui::CPUWidget* ui;

 private slots:
  void splitterMoved(int pos, int index);
  void attachGraph(QWidget* widget);
  void detachGraph();
};

#endif  // CPUWIDGET_H
