#include "TraceRegisters.h"
#include "StringUtil.h"
#include "MiscUtil.h"

template <typename RegistersView>
static QAction* setupAction(const QIcon& icon, const QString& text,
                            RegistersView* this_object) {
  QAction* action = new QAction(icon, text, this_object);
  action->setShortcutContext(Qt::WidgetShortcut);
  this_object->addAction(action);
  return action;
}

template <typename RegistersView>
static QAction* setupAction(const QString& text, RegistersView* this_object) {
  QAction* action = new QAction(text, this_object);
  action->setShortcutContext(Qt::WidgetShortcut);
  this_object->addAction(action);
  return action;
}

template <typename RegisterView>
void InitTraceRegisterMenu(RegisterView *parent) {
  parent->wCM_CopyToClipboard = setupAction(DIcon("copy.png"), parent->tr("Copy value"), parent);
  parent->wCM_CopyFloatingPointValueToClipboard =
      setupAction(DIcon("copy.png"), parent->tr("Copy floating point value"), parent);
  parent->wCM_CopyAll =
      setupAction(DIcon("copy-alt.png"), parent->tr("Copy all registers"), parent);
  parent->wCM_FollowInDisassembly =
      new QAction(DIcon(QString("processor%1.png").arg(ArchValue("32", "64"))),
                  parent->tr("Follow in Disassembler"), parent);
  parent->wCM_FollowInDump = new QAction(DIcon("dump.png"), parent->tr("Follow in Dump"), parent);

  // Context Menu
  parent->setContextMenuPolicy(Qt::CustomContextMenu);

  parent->connect(parent, SIGNAL(customContextMenuRequested(QPoint)), parent,
          SLOT(displayCustomContextMenuSlot(QPoint)));
  parent->connect(parent->wCM_CopyToClipboard, SIGNAL(triggered()), parent,
          SLOT(onCopyToClipboardAction()));
  parent->connect(parent->wCM_CopyFloatingPointValueToClipboard, SIGNAL(triggered()), parent,
          SLOT(onCopyFloatingPointToClipboardAction()));
  parent->connect(parent->wCM_CopyAll, SIGNAL(triggered()), parent, SLOT(onCopyAllAction()));
  parent->connect(parent->wCM_FollowInDisassembly, SIGNAL(triggered()), parent,
          SLOT(onFollowInDisassembly()));
  parent->connect(parent->wCM_FollowInDump, SIGNAL(triggered()), parent, SLOT(onFollowInDump()));
}

TraceRegistersA64::TraceRegistersA64(QWidget* parent) : RegistersViewA64(parent) {
  InitTraceRegisterMenu(this);
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
  const QAction* selectedAction = nullptr;

  if (mSelected != UNKNOWN) {
    if (mCANSTOREADDRESS.contains(mSelected)) {
      duint addr = (*((duint*)registerValue(&wRegDumpStruct, mSelected)));
      if (DbgMemIsValidReadPtr(addr)) {
        wMenu.addAction(wCM_FollowInDump);
        wMenu.addAction(wCM_FollowInDisassembly);
        wMenu.addSeparator();
      }
    }

    wMenu.addAction(wCM_CopyToClipboard);
    if (mFPUx87_80BITSDISPLAY.contains(mSelected)) {
      wMenu.addAction(wCM_CopyFloatingPointValueToClipboard);
    }
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  } else {
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  }
}

void TraceRegistersA64::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

void TraceRegistersA64::onCopyFloatingPointToClipboardAction() {
  Bridge::CopyToClipboard(ToLongDoubleString(
      ((X87FPUREGISTER*)registerValue(&wRegDumpStruct, mSelected))->data));
}

void TraceRegistersA64::onFollowInDisassembly() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("disasm %s", addr.toUtf8().constData()));
  }
}

void TraceRegistersA64::onFollowInDump() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("dump %s", addr.toUtf8().constData()));
  }
}

TraceRegistersA32::TraceRegistersA32(QWidget* parent) : RegistersViewA32(parent) {
  InitTraceRegisterMenu(this);
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
  const QAction* selectedAction = nullptr;

  if (mSelected != UNKNOWN) {
    if (mCANSTOREADDRESS.contains(mSelected)) {
      duint addr = (*((duint*)registerValue(&wRegDumpStruct, mSelected)));
      if (DbgMemIsValidReadPtr(addr)) {
        wMenu.addAction(wCM_FollowInDump);
        wMenu.addAction(wCM_FollowInDisassembly);
        wMenu.addSeparator();
      }
    }

    wMenu.addAction(wCM_CopyToClipboard);
    if (mFPUx87_80BITSDISPLAY.contains(mSelected)) {
      wMenu.addAction(wCM_CopyFloatingPointValueToClipboard);
    }
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  } else {
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  }
}

void TraceRegistersA32::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

void TraceRegistersA32::onCopyFloatingPointToClipboardAction() {
  Bridge::CopyToClipboard(ToLongDoubleString(
      ((X87FPUREGISTER*)registerValue(&wRegDumpStruct, mSelected))->data));
}

void TraceRegistersA32::onFollowInDisassembly() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("disasm %s", addr.toUtf8().constData()));
  }
}

void TraceRegistersA32::onFollowInDump() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("dump %s", addr.toUtf8().constData()));
  }
}

TraceRegistersX64::TraceRegistersX64(QWidget* parent) : RegistersViewX64(parent) {
  InitTraceRegisterMenu(this);
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
  const QAction* selectedAction = nullptr;

  if (mSelected != UNKNOWN) {
    if (mCANSTOREADDRESS.contains(mSelected)) {
      duint addr = (*((duint*)registerValue(&wRegDumpStruct, mSelected)));
      if (DbgMemIsValidReadPtr(addr)) {
        wMenu.addAction(wCM_FollowInDump);
        wMenu.addAction(wCM_FollowInDisassembly);
        wMenu.addSeparator();
      }
    }

    wMenu.addAction(wCM_CopyToClipboard);
    if (mFPUx87_80BITSDISPLAY.contains(mSelected)) {
      wMenu.addAction(wCM_CopyFloatingPointValueToClipboard);
    }
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  } else {
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  }
}

void TraceRegistersX64::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

void TraceRegistersX64::onCopyFloatingPointToClipboardAction() {
  Bridge::CopyToClipboard(ToLongDoubleString(
      ((X87FPUREGISTER*)registerValue(&wRegDumpStruct, mSelected))->data));
}

void TraceRegistersX64::onFollowInDisassembly() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("disasm %s", addr.toUtf8().constData()));
  }
}

void TraceRegistersX64::onFollowInDump() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("dump %s", addr.toUtf8().constData()));
  }
}

TraceRegistersX86::TraceRegistersX86(QWidget* parent) : RegistersViewX86(parent) {
  InitTraceRegisterMenu(this);
}

void TraceRegistersX86::setRegisters(REGDUMP* registers) {
  this->RegistersViewX86::setRegisters(registers);
}

void TraceRegistersX86::setActive(bool isActive) {
  this->isActive = isActive;
  this->RegistersViewX86::setRegisters(&this->wRegDumpStruct);
}

void TraceRegistersX86::displayCustomContextMenuSlot(QPoint pos) {
  if (!isActive) return;
  QMenu wMenu(this);
  const QAction* selectedAction = nullptr;

  if (mSelected != UNKNOWN) {
    if (mCANSTOREADDRESS.contains(mSelected)) {
      duint addr = (*((duint*)registerValue(&wRegDumpStruct, mSelected)));
      if (DbgMemIsValidReadPtr(addr)) {
        wMenu.addAction(wCM_FollowInDump);
        wMenu.addAction(wCM_FollowInDisassembly);
        wMenu.addSeparator();
      }
    }

    wMenu.addAction(wCM_CopyToClipboard);
    if (mFPUx87_80BITSDISPLAY.contains(mSelected)) {
      wMenu.addAction(wCM_CopyFloatingPointValueToClipboard);
    }
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  } else {
    wMenu.addAction(wCM_CopyAll);
    wMenu.exec(this->mapToGlobal(pos));
  }
}

void TraceRegistersX86::onCopyToClipboardAction() {
  Bridge::CopyToClipboard(GetRegStringValueFromValue(
      mSelected, registerValue(&wRegDumpStruct, mSelected)));
}

void TraceRegistersX86::onCopyFloatingPointToClipboardAction() {
  Bridge::CopyToClipboard(ToLongDoubleString(
      ((X87FPUREGISTER*)registerValue(&wRegDumpStruct, mSelected))->data));
}

void TraceRegistersX86::onFollowInDisassembly() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("disasm %s", addr.toUtf8().constData()));
  }
}

void TraceRegistersX86::onFollowInDump() {
  if (mCANSTOREADDRESS.contains(mSelected)) {
    QString addr =
        QString("%1")
            .arg((*((duint*)registerValue(&wRegDumpStruct, mSelected))),
                 mRegisterPlaces[mSelected].valuesize, 16, QChar('0'))
            .toUpper();
    if (DbgMemIsValidReadPtr(
            (*((duint*)registerValue(&wRegDumpStruct, mSelected)))))
      DbgCmdExec(QString().sprintf("dump %s", addr.toUtf8().constData()));
  }
}
