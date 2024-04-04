#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QWidget>

#include "Bridge.h"

class QVBoxLayout;
class CPUSideBar;
class CPUDisassembly;
class CPUMultiDump;
class CPUStack;
class CPURegistersViewA64;
class CPURegistersViewA32;
class CPURegistersViewX64;
class CPURegistersViewX86;
class CPUInfoBox;
class CPUArgumentWidget;
class CPUArgumentWidgetA64;
class CPUArgumentWidgetA32;
class CPUArgumentWidgetX64;
class CPUArgumentWidgetX86;
class DisassemblerGraphView;
class MHDetachedWindow;
class QScrollArea;
class DialogExecMap;

namespace Ui {
class CPUWidget;
}

class CPUWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CPUWidget(QWidget* parent = 0);
  ~CPUWidget();

  // Misc
  void setDefaultDisposition();

  void saveWindowSettings();
  void loadWindowSettings();

  void showExecMap();
  void hideExecMap();

  duint getSelectionVa();

  // Widget getters
  CPUSideBar* getSidebarWidget();
  CPUDisassembly* getDisasmWidget();
  DisassemblerGraphView* getGraphWidget();
  CPUMultiDump* getDumpWidget();
  CPUStack* getStackWidget();
  CPUInfoBox* getInfoBoxWidget();

 public slots:
  void setDisasmFocus();
  void setGraphFocus();
  void debugStateChangedSlot(DBGSTATE state);

 protected:
  void activeRegister(QScrollArea *regview);
  void activeArgument(CPUArgumentWidget *argview);

  CPUSideBar* mSideBar;
  CPUDisassembly* mDisas;
  DisassemblerGraphView* mGraph;
  MHDetachedWindow* mGraphWindow;
  CPUMultiDump* mDump;
  CPUStack* mStack;
  CPURegistersViewA64* mGeneralRegsA64;
  CPURegistersViewA32* mGeneralRegsA32;
  CPURegistersViewX64* mGeneralRegsX64;
  CPURegistersViewX86* mGeneralRegsX86;
  QScrollArea* mGeneralRegsArea;
  CPUInfoBox* mInfo;
  CPUArgumentWidgetA64* mArgumentWidgetA64;
  CPUArgumentWidgetA32* mArgumentWidgetA32;
  CPUArgumentWidgetX64* mArgumentWidgetX64;
  CPUArgumentWidgetX86* mArgumentWidgetX86;
  QScrollArea* mArgumentArea;
  DialogExecMap* mExecMap;

  int disasMode;

 private:
  Ui::CPUWidget* ui;

 private slots:
  void splitterMoved(int pos, int index);
  void attachGraph(QWidget* widget);
  void detachGraph();
};

#endif  // CPUWIDGET_H
