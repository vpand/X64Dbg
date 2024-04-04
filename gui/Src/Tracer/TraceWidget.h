#ifndef TRACEWIDGET_H
#define TRACEWIDGET_H

#include <QWidget>

#include "Bridge.h"

class QVBoxLayout;
class CPUWidget;
class TraceRegistersA64;
class TraceRegistersA32;
class TraceRegistersX64;
class TraceRegistersX86;
class TraceBrowser;
class TraceFileReader;
class StdTable;
class QScrollArea;

namespace Ui {
class TraceWidget;
}

class TraceWidget : public QWidget {
  Q_OBJECT

 public:
  explicit TraceWidget(QWidget* parent);
  ~TraceWidget();

  TraceBrowser* getTraceBrowser();

 protected slots:
  void traceSelectionChanged(unsigned long long selection);
  void updateSlot();
  void debugStateChangedSlot(DBGSTATE state);

 protected:
  TraceBrowser* mTraceWidget;
  TraceRegistersA64* mGeneralRegsA64;
  TraceRegistersA32* mGeneralRegsA32;
  TraceRegistersX64* mGeneralRegsX64;
  TraceRegistersX86* mGeneralRegsX86;
  QScrollArea* mGeneralArea;
  StdTable* mInfo;
  StdTable* mOverview;

  void updateInfobox(unsigned long long selection, TraceFileReader* traceFile,
                     const REGDUMP* registers);

 private:
  void activeRegister(QScrollArea *regview);

  void updateInfobox(unsigned long long selection, TraceFileReader* traceFile,
                     const REGDUMPA64* registers);
  void updateInfobox(unsigned long long selection, TraceFileReader* traceFile,
                     const REGDUMPA32* registers);
  void updateInfobox32(unsigned long long selection, TraceFileReader* traceFile,
                       const REGDUMPX64* registers);
  void updateInfobox64(unsigned long long selection, TraceFileReader* traceFile,
                       const REGDUMPX64* registers);

 private:
  Ui::TraceWidget* ui;
};

#endif  // TRACEWIDGET_H
