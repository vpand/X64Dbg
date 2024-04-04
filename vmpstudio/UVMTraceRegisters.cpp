#include "UVMTraceRegisters.h"
#include "MiscUtil.h"

template <typename REGVIEW>
static QAction* setupAction(const QIcon& icon, const QString& text,
                            REGVIEW* this_object) {
  QAction* action = new QAction(icon, text, this_object);
  action->setShortcutContext(Qt::WidgetShortcut);
  this_object->addAction(action);
  return action;
}

////////////////////////////////// ARM64 //////////////////////////////////

TraceRegistersA64::TraceRegistersA64(QWidget* parent)
    : RegistersViewA64(parent) {
  setContextMenuPolicy(Qt::CustomContextMenu);

  wCM_CopyToClipboard = setupAction(DIcon("copy.png"), tr("Copy value"), this);
  wCM_CopyAll =
      setupAction(DIcon("copy-alt.png"), tr("Copy all registers"), this);
  connect(wCM_CopyToClipboard, SIGNAL(triggered()), this,
          SLOT(onCopyToClipboardAction()));
  connect(wCM_CopyAll, SIGNAL(triggered()), this, SLOT(onCopyAllAction()));
  connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
          SLOT(displayCustomContextMenuSlot(QPoint)));
}

void TraceRegistersA64::setRegisters(REGDUMP* registers) {
  this->RegistersViewA64::setRegisters(registers);
}

void TraceRegistersA64::setActive(bool isActive) {
  this->isActive = isActive;
  this->RegistersViewA64::setRegisters(&this->wRegDumpStruct);
}

void TraceRegistersA64::displayCustomContextMenuSlot(QPoint pos) {
  if (!isActive) return;
  QMenu wMenu(this);
  wMenu.addAction(wCM_CopyToClipboard);
  wMenu.addAction(wCM_CopyAll);
  wMenu.exec(this->mapToGlobal(pos));
}

void TraceRegistersA64::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

////////////////////////////////// ARM //////////////////////////////////

TraceRegistersA32::TraceRegistersA32(QWidget* parent)
    : RegistersViewA32(parent) {
  setContextMenuPolicy(Qt::CustomContextMenu);

  wCM_CopyToClipboard = setupAction(DIcon("copy.png"), tr("Copy value"), this);
  wCM_CopyAll =
      setupAction(DIcon("copy-alt.png"), tr("Copy all registers"), this);
  connect(wCM_CopyToClipboard, SIGNAL(triggered()), this,
          SLOT(onCopyToClipboardAction()));
  connect(wCM_CopyAll, SIGNAL(triggered()), this, SLOT(onCopyAllAction()));
  connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
          SLOT(displayCustomContextMenuSlot(QPoint)));
}

void TraceRegistersA32::setRegisters(REGDUMP* registers) {
  this->RegistersViewA32::setRegisters(registers);
}

void TraceRegistersA32::setActive(bool isActive) {
  this->isActive = isActive;
  this->RegistersViewA32::setRegisters(&this->wRegDumpStruct);
}

void TraceRegistersA32::displayCustomContextMenuSlot(QPoint pos) {
  if (!isActive) return;
  QMenu wMenu(this);
  wMenu.addAction(wCM_CopyToClipboard);
  wMenu.addAction(wCM_CopyAll);
  wMenu.exec(this->mapToGlobal(pos));
}

void TraceRegistersA32::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

////////////////////////////////// X86_64 //////////////////////////////////

TraceRegistersX64::TraceRegistersX64(QWidget* parent)
    : RegistersViewX64(parent) {
  setContextMenuPolicy(Qt::CustomContextMenu);

  wCM_CopyToClipboard = setupAction(DIcon("copy.png"), tr("Copy value"), this);
  wCM_CopyAll =
      setupAction(DIcon("copy-alt.png"), tr("Copy all registers"), this);
  connect(wCM_CopyToClipboard, SIGNAL(triggered()), this,
          SLOT(onCopyToClipboardAction()));
  connect(wCM_CopyAll, SIGNAL(triggered()), this, SLOT(onCopyAllAction()));
  connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
          SLOT(displayCustomContextMenuSlot(QPoint)));
}

void TraceRegistersX64::setRegisters(REGDUMP* registers) {
  this->RegistersViewX64::setRegisters(registers);
}

void TraceRegistersX64::setActive(bool isActive) {
  this->isActive = isActive;
  this->RegistersViewX64::setRegisters(&this->wRegDumpStruct);
}

void TraceRegistersX64::displayCustomContextMenuSlot(QPoint pos) {
  if (!isActive) return;
  QMenu wMenu(this);
  wMenu.addAction(wCM_CopyToClipboard);
  wMenu.addAction(wCM_CopyAll);
  wMenu.exec(this->mapToGlobal(pos));
}

void TraceRegistersX64::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}
