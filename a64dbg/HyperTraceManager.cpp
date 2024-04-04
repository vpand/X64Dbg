#include "HyperTraceManager.h"
#include "HyperTraceView.h"
#include "ui_HyperTraceManager.h"
#include "../bridge/_global.h"
#include <QFileDialog>
#include <QFile>

extern dbgapi::LLDBEngine *lldb;

static void hypertraceOperate(hypertrace_type_t type, bool start) {
  auto pt = DbgGlobal::inst()->currentPlatform();
  switch (pt) {
  case pt_remote_vp_android:
    break;
  default:
    GuiAddLogMessage("Only YooPhone platform supports hypertrace now.\n");
    return;
  }
  if (start) {
    lldb->hypertraceStart(type);
  }
  else {
    lldb->hypertraceStop(type);
  }
}

HyperTraceManager::HyperTraceManager(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::HyperTraceManager) {
  ui->setupUi(this);
  connect(ui->pushButtonFuncStart, &QPushButton::clicked, this, &HyperTraceManager::onButtonFuncStart);
  connect(ui->pushButtonFuncStop, &QPushButton::clicked, this, &HyperTraceManager::onButtonFuncStop);
  connect(ui->pushButtonHTTP2Start, &QPushButton::clicked, this, &HyperTraceManager::onButtonHttp2Start);
  connect(ui->pushButtonHTTP2Stop, &QPushButton::clicked, this, &HyperTraceManager::onButtonHttp2Stop);
  connect(ui->pushButtonSyscallStart, &QPushButton::clicked, this, &HyperTraceManager::onButtonSyscallObjcStart);
  connect(ui->pushButtonSyscallStop, &QPushButton::clicked, this, &HyperTraceManager::onButtonSyscallObjcStop);
  connect(ui->pushButtonLoadHTD, &QPushButton::clicked, this, &HyperTraceManager::onButtonDatabaseLoad);
  connect(ui->pushButtonSaveHTD, &QPushButton::clicked, this, &HyperTraceManager::onButtonDatabaseSave);
  connect(ui->pushButtonClear, &QPushButton::clicked, this, &HyperTraceManager::onButtonDatabaseClear);
}

HyperTraceManager::~HyperTraceManager() {
  delete ui;
}

void HyperTraceManager::onButtonFuncStart() {
  hypertraceOperate(HTT_FUNCTION, true);
}

void HyperTraceManager::onButtonFuncStop() {
  hypertraceOperate(HTT_FUNCTION, false);
}

void HyperTraceManager::onButtonHttp2Start() {
  hypertraceOperate(HTT_HTTP2, true);
}

void HyperTraceManager::onButtonHttp2Stop() {
  hypertraceOperate(HTT_HTTP2, false);
}

void HyperTraceManager::onButtonSyscallObjcStart() {
  hypertraceOperate(HTT_SYSCALL, true);
}

void HyperTraceManager::onButtonSyscallObjcStop() {
  hypertraceOperate(HTT_SYSCALL, false);
}

struct htd_header_t {
  int magic;
  int count;
  int offsets[0];
};

static const int htd_magic = '$dth';

void HyperTraceManager::onButtonDatabaseLoad() {
  auto filename = QFileDialog::getOpenFileName(
      this, tr("Open file"), "", tr("HyperTrace Database (*.htd)"));
  if (!filename.length()) return;
  auto hdr = (htd_header_t *)mana::uncompressDBFile(filename.toUtf8().data());
  if (!hdr) {
    hypertraceView->addMsgToSymbolLogSlot(QString("Failed to load hypertrace database %1.\n").arg(filename));
    return;
  }
  if (hdr->magic == htd_magic) {
    onButtonDatabaseClear();
    for (int i = 0; i < hdr->count; i++) {
      hypertraceView->mDatabase.push_back(QByteArray());
      auto newdb = hypertraceView->mDatabase.rbegin();
      int *channel = (int *)((char *)hdr + hdr->offsets[i]);
      newdb->resize(channel[0]);
      memcpy(newdb->data(), &channel[1], channel[0]);
    }
    hypertraceView->moduleSelectionChanged(0);
  }
  else {
    hypertraceView->addMsgToSymbolLogSlot(QString("Invalid hypertrace database %1.\n").arg(filename));
  }
  free(hdr);
}

void HyperTraceManager::onButtonDatabaseSave() {
  if (!hypertraceView->mDatabase.size()) return;
  auto filename = QFileDialog::getSaveFileName(
      this, tr("Save file"), "", tr("HyperTrace Database (*.htd)"));
  if (!filename.length()) return;
  QByteArray tmpbuff;
  int bytes = sizeof(htd_header_t) + sizeof(int) * hypertraceView->mDatabase.size();
  for (auto &db : hypertraceView->mDatabase) {
    bytes += db.size();
  }
  tmpbuff.resize(bytes);
  htd_header_t *hdr = (htd_header_t *)tmpbuff.data();
  hdr->magic = htd_magic;
  hdr->count = hypertraceView->mDatabase.size();
  int i = 0, curoff = (char *)&hdr->offsets[hdr->count] - (char *)hdr;
  for (auto &db : hypertraceView->mDatabase) {
    hdr->offsets[i] = curoff;
    int *channel = (int *)((char *)hdr + curoff);
    channel[0] = db.size();
    memcpy(&channel[1], db.data(), db.size());
    curoff += sizeof(int) + db.size();
    i++;
  }
  QFile file(filename);
  if (file.open(QIODevice::WriteOnly)) {
    file.write(tmpbuff);
    file.close();
    mana::compressDBFile(filename.toUtf8().data());
    hypertraceView->addMsgToSymbolLogSlot(QString("Saved hypertrace database to %1.\n").arg(filename));
  }
  else {
    hypertraceView->addMsgToSymbolLogSlot(QString("Failed to save hypertrace database %1.\n").arg(filename));
  }
}

void HyperTraceManager::onButtonDatabaseClear() {
  hypertraceView->clearDatabase();
}
