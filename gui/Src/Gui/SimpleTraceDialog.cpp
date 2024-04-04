#include "SimpleTraceDialog.h"

#include <QMessageBox>

#include "Bridge.h"
#include "BrowseDialog.h"
#include "MiscUtil.h"
#include <MagicAna.hpp>
#include "ui_SimpleTraceDialog.h"

SimpleTraceDialog::SimpleTraceDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::SimpleTraceDialog) {
  ui->setupUi(this);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);
  duint setting;
  if (!BridgeSettingGetUint("Engine", "MaxTraceCount", &setting))
    setting = 10000;
  ui->spinMaxTraceCount->setValue(int(setting));
  auto debugee = DbgGlobal::inst()->debugee;
  auto arch = debugee ? debugee->db->info.arch : mana::ARM64;
  switch (arch) {
  case mana::ARM: {
    ui->editBreakCondition->setPlaceholderText(
        tr("Example: %1").arg("arm.r0 == 0 and arm.r1 == 0"));
    ui->editLogText->setPlaceholderText(
        tr("Example: %1").arg("'%x, %x' % (arm.lr, arm.pc)"));
    ui->editLogCondition->setPlaceholderText(
        tr("Example: %1").arg("arm.r0 == 0 and arm.r1 == 0"));
    ui->editCommandText->setPlaceholderText(
        tr("Example: %1").arg("arm.r0=4;stepover()"));
    ui->editCommandCondition->setPlaceholderText(
        tr("Example: %1").arg("arm.r0 == 0 or arm.r1 == 1"));
    break;
  }
  case mana::ARM64: {
    ui->editBreakCondition->setPlaceholderText(
        tr("Example: %1").arg("arm64.x0 == 0 and arm64.x1 == 0"));
    ui->editLogText->setPlaceholderText(
        tr("Example: %1").arg("'%x, %x' % (arm64.lr, arm64.pc)"));
    ui->editLogCondition->setPlaceholderText(
        tr("Example: %1").arg("arm64.x0 == 0 and arm64.x1 == 0"));
    ui->editCommandText->setPlaceholderText(
        tr("Example: %1").arg("arm64.x0=4;stepover()"));
    ui->editCommandCondition->setPlaceholderText(
        tr("Example: %1").arg("arm64.x0 == 0 or arm64.x1 == 1"));
    break;
  }
  case mana::X86: {
    ui->editBreakCondition->setPlaceholderText(
        tr("Example: %1").arg("x86.eax == 0 and x86.ecx == 0"));
    ui->editLogText->setPlaceholderText(
        tr("Example: %1").arg("'%x, %x' % (x86.edi, x86.esi)"));
    ui->editLogCondition->setPlaceholderText(
        tr("Example: %1").arg("x86.eax == 0 and x86.ecx == 0"));
    ui->editCommandText->setPlaceholderText(
        tr("Example: %1").arg("x86.eax=4;stepover()"));
    ui->editCommandCondition->setPlaceholderText(
        tr("Example: %1").arg("x86.eax == 0 or x86.ecx == 1"));
    break;
  }
  case mana::X86_64: {
    ui->editBreakCondition->setPlaceholderText(
        tr("Example: %1").arg("x64.rax == 0 and x64.rcx == 0"));
    ui->editLogText->setPlaceholderText(
        tr("Example: %1").arg("'%x, %x' % (x64.rdi, x64.rsi)"));
    ui->editLogCondition->setPlaceholderText(
        tr("Example: %1").arg("x64.rax == 0 and x64.rcx == 0"));
    ui->editCommandText->setPlaceholderText(
        tr("Example: %1").arg("x64.rax=4;stepover()"));
    ui->editCommandCondition->setPlaceholderText(
        tr("Example: %1").arg("x64.rax == 0 or x64.rcx == 1"));
    break;
  }
  }
  ui->editSwitchCondition->setPlaceholderText("Example: addrmod(nextpc())['party'] == 'sys'");
}

SimpleTraceDialog::~SimpleTraceDialog() { delete ui; }

void SimpleTraceDialog::setTraceCommand(const QString& command) {
  mTraceCommand = command;
  if (command.startsWith("StartRunTrace")) {
    auto logtitle = ui->lblLogText->text().replace("Log", "Record");
    auto logcond = ui->lblLogCondition->text().replace("Lo&g", "Record");
    ui->lblLogText->setText(logtitle);
    ui->lblLogCondition->setText(logcond);
  }
}

static QString escapeText(QString str) {
#if 0
  str.replace(QChar('\\'), QString("\\\\"));
  str.replace(QChar('"'), QString("\\\""));
#endif
  return str;
}

void SimpleTraceDialog::on_btnOk_clicked() {
  if (!mLogFile.isEmpty() && ui->editLogText->text().isEmpty()) {
    QMessageBox msgyn(QMessageBox::Warning, tr("Trace log file"),
                      tr("It appears you have set the log file, but not the "
                         "log text. <b>This will result in an empty log</b>. "
                         "Do you really want to continue?"),
                      QMessageBox::Yes | QMessageBox::No, this);
    msgyn.setWindowIcon(DIcon("compile-warning.png"));
    msgyn.setParent(this, Qt::Dialog);
    msgyn.setWindowFlags(msgyn.windowFlags() &
                         (~Qt::WindowContextHelpButtonHint));
    if (msgyn.exec() == QMessageBox::No) return;
  }
  auto logText = ui->editLogText->addHistoryClear();
  auto logCondition = ui->editLogCondition->addHistoryClear();
  if (!DbgCmdExecDirect(QString("TraceSetLog \"%1\", .%2")
                            .arg(escapeText(logText), escapeText(logCondition))
                            .toUtf8()
                            .constData())) {
    SimpleWarningBox(this, tr("Error"),
                     tr("Failed to set log text/condition!"));
    return;
  }
  auto commandText = ui->editCommandText->addHistoryClear();
  auto commandCondition = ui->editCommandCondition->addHistoryClear();
  if (!DbgCmdExecDirect(
          QString("TraceSetCommand \"%1\", .%2")
              .arg(escapeText(commandText), escapeText(commandCondition))
              .toUtf8()
              .constData())) {
    SimpleWarningBox(this, tr("Error"),
                     tr("Failed to set command text/condition!"));
    return;
  }
  auto switchCondition = ui->editSwitchCondition->addHistoryClear();
  if (!DbgCmdExecDirect(QString("TraceSetSwitchCondition %1")
                            .arg(escapeText(switchCondition))
                            .toUtf8()
                            .constData())) {
    SimpleWarningBox(this, tr("Error"), tr("Failed to set switch condition!"));
    return;
  }
  if (!DbgCmdExecDirect(QString("TraceSetLogFile %1")
                            .arg(escapeText(mLogFile))
                            .toUtf8()
                            .constData())) {
    SimpleWarningBox(this, tr("Error"), tr("Failed to set log file!"));
    return;
  }
  auto breakCondition = ui->editBreakCondition->addHistoryClear();
  auto maxTraceCount = ui->spinMaxTraceCount->value();
  if (!DbgCmdExecDirect(QString("%1 .%2, .%3")
                            .arg(mTraceCommand, escapeText(breakCondition))
                            .arg(maxTraceCount)
                            .toUtf8()
                            .constData())) {
    SimpleWarningBox(this, tr("Error"), tr("Failed to start trace!"));
    return;
  }
  accept();
}

void SimpleTraceDialog::on_btnLogFile_clicked() {
  BrowseDialog browse(this, tr("Trace log file"),
                      tr("Enter the path to the log file."),
                      tr("Log Files (*.txt *.log);;All Files (*.*)"),
                      QCoreApplication::applicationDirPath(), true);
  if (browse.exec() == QDialog::Accepted)
    mLogFile = browse.path;
  else
    mLogFile.clear();
}
