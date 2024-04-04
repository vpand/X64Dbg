#ifndef TRACEWIDGET_H
#define TRACEWIDGET_H

#include <QWidget>

#include "UVMGlobal.h"
#include "VMPBridge.h"
#include "VMPGlobal.h"

class QVBoxLayout;
class QScrollArea;
class CPUWidget;
class TraceRegistersA64;
class TraceRegistersA32;
class TraceRegistersX64;
class TraceBrowser;
class TraceFileReader;
class StdTable;
class LogView;
class QEventLoop;

namespace Ui {
class TraceWidget;
}

class UVMTraceWidget : public QWidget {
  Q_OBJECT

 public:
  explicit UVMTraceWidget(QWidget* parent);
  ~UVMTraceWidget();

  TraceBrowser* getTraceBrowser();
  void addLog(const QString& msg) { addLogSlot(msg.toUtf8()); }
  bool connectedServer();
  QString uvmShell(const QString& cmds, bool result, bool timeout);
  int uvmSend(UVMSVR_CommandType type, const char* buf, size_t bufsz,
              uint64_t extra = 0) {
    return mUVMClient.send(type, buf, bufsz, extra);
  }

  // uraniumvm tracer
  void uvmTraceStart(const VMPManaFunc& fn);
  void uvmTraceStop(const VMPManaFunc& fn);
  void uvmTraceOptions(int depth, int startrva, int endrva);
  
  // yoophone tracer
  void uvmTraceStart();
  void uvmTraceStop();

  bool isAttached() { return mRuntimeBase != 0; }
  uint64_t runtimeBase() { return mRuntimeBase; }

  void detach();

  std::string mUVMTriple;
  UVMClient mUVMClient;
  UraniumVMServer mUVMServer;
  RecordARM mRecordARMAll;
  RecordARM mRecordARMCur;
  RecordARM64 mRecordARM64All;
  RecordARM64 mRecordARM64Cur;
  RecordX64 mRecordX64All;
  RecordX64 mRecordX64Cur;
  RecordIndexs mRecordInds;
  PageBuffers mPageBuffs;
  PageBuffers mPageRawBuffs;
  int mRecordCur = 0;
  uint64_t mRuntimeBase = 0;
  int mCGRenderDepth = 0; // call graph render depth

 public slots:
  void traceSelectionChanged(unsigned long long selection);
  void updateSlot();
  void addLogSlot(QByteArray msg);
  void debugStateChangedSlot(DBGSTATE state);
  void onAnchorClicked(const QUrl& link);

 protected:
  TraceBrowser* mTraceWidget;
  TraceRegistersA64* mGeneralRegsA64;
  TraceRegistersA32* mGeneralRegsA32;
  TraceRegistersX64* mGeneralRegsX64;
  QScrollArea* mGeneralRegsArea;
  LogView* mInfo;
  StdTable* mOverview;
  QProcess m_fridasvr;
  int m_regctxindex = 0;

  void activeRegister(QScrollArea* regview);
  void updateInfobox(unsigned long long selection, TraceFileReader* traceFile,
                     const REGDUMP* registers);
  void setupUVMServer();
  void parseUVMProtocol(UVMDBG_CommandType type, const char* buf, int bufsz,
                        uint64_t extra);
  void setBp(const VMPManaFunc& fn, bool set);

  template <typename RECORD, typename HDR, typename SUBREGS>
  void updateRecord(RECORD* recordall, RECORD* recordcur, const char* buf,
                    int bufsz);

 private:
  Ui::TraceWidget* ui;
};

extern UVMTraceWidget* uvmWin;
extern int vmpstudioPort; // port for device side

#endif  // TRACEWIDGET_H
