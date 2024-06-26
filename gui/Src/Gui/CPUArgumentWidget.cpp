#include "CPUArgumentWidget.h"

#include "Bridge.h"
#include "Configuration.h"
#include "ui_CPUArgumentWidget.h"

CPUArgumentWidget::CPUArgumentWidget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::CPUArgumentWidget),
      mTable(nullptr),
      mCurrentCallingConvention(-1),
      mStackOffset(0),
      mAllowUpdate(true) {
  ui->setupUi(this);
  setFixedWidth(800);
  setFixedHeight(800);
  mTable = ui->table;
  setupTable();
  refreshData();
  ui->checkBoxLock->setToolTip(tr("Refresh is automatic."));

  mFollowDisasm = new QAction(this);
  connect(mFollowDisasm, SIGNAL(triggered()), this, SLOT(followDisasmSlot()));
  mFollowAddrDisasm = new QAction(this);
  connect(mFollowAddrDisasm, SIGNAL(triggered()), this,
          SLOT(followDisasmSlot()));
  mFollowDump = new QAction(this);
  connect(mFollowDump, SIGNAL(triggered()), this, SLOT(followDumpSlot()));
  mFollowAddrDump = new QAction(this);
  connect(mFollowAddrDump, SIGNAL(triggered()), this, SLOT(followDumpSlot()));
  mFollowStack = new QAction(this);
  connect(mFollowStack, SIGNAL(triggered()), this, SLOT(followStackSlot()));
  mFollowAddrStack = new QAction(this);
  connect(mFollowAddrStack, SIGNAL(triggered()), this, SLOT(followStackSlot()));

  connect(Bridge::getBridge(), SIGNAL(repaintTableView()), this,
          SLOT(refreshData()));
  connect(Bridge::getBridge(), SIGNAL(disassembleAt(dsint, dsint)), this,
          SLOT(disassembleAtSlot(dsint, dsint)));
}

CPUArgumentWidget::~CPUArgumentWidget() { delete ui; }

void CPUArgumentWidget::updateStackOffset(bool iscall) {
  const auto& cur = mCallingConventions[mCurrentCallingConvention];
  mStackOffset = cur.getStackOffset() + (iscall ? 0 : cur.getCallOffset());
}

void CPUArgumentWidget::disassembleAtSlot(dsint addr, dsint cip) {
  Q_UNUSED(addr);
  if (mCurrentCallingConvention == -1)  // no calling conventions
  {
    mTable->setRowCount(0);
    mTable->reloadData();
    return;
  }
  BASIC_INSTRUCTION_INFO disasm;
  DbgDisasmFastAt(cip, &disasm);
  updateStackOffset(disasm.call);
  if (ui->checkBoxLock->checkState() == Qt::PartiallyChecked)  // Calls
  {
    mAllowUpdate = disasm.call;
    ui->spinArgCount->setEnabled(disasm.call);
    ui->comboCallingConvention->setEnabled(disasm.call);
  }
}

static QString stringFormatInline(const QString& format) {
  if (1 || !DbgFunctions()->StringFormatInline) {
    duint value = DbgValFromString(format.toUtf8().data());
    return QString("%1").arg(ToPtrString(value));
  }
  char result[MAX_SETTING_SIZE] = "";
  if (DbgFunctions()->StringFormatInline(format.toUtf8().constData(),
                                         MAX_SETTING_SIZE, result))
    return result;
  return CPUArgumentWidget::tr("[Formatting Error]");
}

void CPUArgumentWidget::refreshData() {
  if (!isEnabled()) return;

  if (!mAllowUpdate)  // view is locked
    return;

  if (mCurrentCallingConvention == -1 ||
      !DbgIsDebugging())  // no calling conventions
  {
    mTable->setRowCount(0);
    mTable->reloadData();
    return;
  }

  const auto& cur = mCallingConventions[mCurrentCallingConvention];
  int argCountStruct = int(cur.arguments.size());
  int argCount = std::min(argCountStruct, ui->spinArgCount->value());
  int stackCount = std::max(0, ui->spinArgCount->value() - argCountStruct);
  mTable->setRowCount(argCount + stackCount);
  mArgumentValues.clear();

  for (int i = 0; i < argCount; i++) {
    const auto& curArg = cur.arguments[i];
    auto data = stringFormatInline(curArg.getFormat());
    auto text = defaultArgFieldFormat(defaultArgName(curArg.name, i + 1), data);
    mArgumentValues.push_back(
        DbgValFromString(curArg.getExpression().toUtf8().constData()));
    mTable->setCellContent(i, 0, text);
  }

  auto stackLocation = cur.getStackLocation();
  for (int i = 0; i < stackCount; i++) {
    duint argOffset = mStackOffset + i * sizeof(duint);
    QString expr =
        argOffset
            ? QString("%1+%2").arg(stackLocation).arg(ToHexString(argOffset))
            : stackLocation;

    QString format = defaultArgFormat("", QString("[%1]").arg(expr));
    auto data = stringFormatInline(format);
    auto text =
        defaultArgFieldFormat(defaultArgName("", argCount + i + 1), data);
    mArgumentValues.push_back(DbgValFromString(expr.toUtf8().constData()));
    mTable->setCellContent(argCount + i, 0, text);
  }

  mTable->reloadData();
}

static void configAction(QMenu& wMenu, const QIcon& icon, QAction* action,
                         const QString& value, const QString& name) {
  action->setText(
      QApplication::translate("CPUArgumentWidget", "Follow %1 in %2")
          .arg(value)
          .arg(name));
  action->setIcon(icon);
  action->setObjectName(value);
  wMenu.addAction(action);
}

void CPUArgumentWidget::contextMenuSlot(QPoint pos) {
  if (!DbgIsDebugging()) return;
  auto selection = mTable->getInitialSelection();
  if (int(mArgumentValues.size()) <= selection) return;
  auto value = mArgumentValues[selection];
  QMenu wMenu(this);
  if (DbgMemIsValidReadPtr(value)) {
    duint valueAddr;
    DbgMemRead(value, (unsigned char*)&valueAddr, sizeof(valueAddr));

    auto valueText = ToHexString(value);
    auto valueAddrText = QString("[%1]").arg(valueText);
    auto inStackRange = [](duint addr) {
      auto csp = DbgValFromString("csp");
      duint size;
      auto base = DbgMemFindBaseAddr(csp, &size);
      return addr >= base && addr < base + size;
    };

    configAction(wMenu, DIcon(ArchValue("processor32.png", "processor64.png")),
                 mFollowDisasm, valueText, tr("Disassembler"));
    configAction(wMenu, DIcon("dump.png"), mFollowDump, valueText, tr("Dump"));
    if (inStackRange(value))
      configAction(wMenu, DIcon("stack.png"), mFollowStack, valueText,
                   tr("Stack"));
    if (DbgMemIsValidReadPtr(valueAddr)) {
      configAction(wMenu,
                   DIcon(ArchValue("processor32.png", "processor64.png")),
                   mFollowAddrDisasm, valueAddrText, tr("Disassembler"));
      configAction(wMenu, DIcon("dump.png"), mFollowDump, valueAddrText,
                   tr("Dump"));
      if (inStackRange(valueAddr))
        configAction(wMenu, DIcon("stack.png"), mFollowAddrStack, valueAddrText,
                     tr("Stack"));
    }
  }
  QMenu wCopyMenu(tr("&Copy"));
  wCopyMenu.setIcon(DIcon("copy.png"));
  mTable->setupCopyMenu(&wCopyMenu);
  if (wCopyMenu.actions().length()) {
    wMenu.addSeparator();
    wMenu.addMenu(&wCopyMenu);
  }
  wMenu.exec(mTable->mapToGlobal(pos));
}

void CPUArgumentWidget::followDisasmSlot() {
  QAction* action = qobject_cast<QAction*>(sender());
  if (!action) return;
  DbgCmdExec(QString("disasm %1").arg(action->objectName()));
}

void CPUArgumentWidget::followDumpSlot() {
  QAction* action = qobject_cast<QAction*>(sender());
  if (!action) return;
  DbgCmdExec(QString("dump %1").arg(action->objectName()));
}

void CPUArgumentWidget::followStackSlot() {
  QAction* action = qobject_cast<QAction*>(sender());
  if (!action) return;
  DbgCmdExec(QString("sdump %1").arg(action->objectName()));
}

void CPUArgumentWidget::setupTable() {
  connect(mTable, SIGNAL(contextMenuSignal(QPoint)), this,
          SLOT(contextMenuSlot(QPoint)));
  mTable->enableMultiSelection(false);
  mTable->setShowHeader(false);
  mTable->addColumnAt(0, "", false);
  mTable->reloadData();
}

void CPUArgumentWidget::on_comboCallingConvention_currentIndexChanged(
    int index) {
  mCurrentCallingConvention = index;
  const auto& cur = mCallingConventions[index];
  ui->spinArgCount->setValue(
      int(cur.arguments.size()) +
      cur.stackArgCount);  // set the default argument count
  if (!DbgIsDebugging()) return;
  BASIC_INSTRUCTION_INFO disasm;
  DbgDisasmFastAt(DbgValFromString("CIP"), &disasm);
  updateStackOffset(disasm.call);
  refreshData();
}

void CPUArgumentWidget::on_spinArgCount_valueChanged(int) {
  mTable->setTableOffset(0);  // reset the view to the first argument (fixes an
                              // ugly issue after refreshing)
  refreshData();
}

void CPUArgumentWidget::on_checkBoxLock_stateChanged(int) {
  switch (ui->checkBoxLock->checkState()) {
    case Qt::Checked:  // Locked, update disabled.
      refreshData();   // first refresh then lock
      ui->checkBoxLock->setText(tr("Locked"));
      ui->checkBoxLock->setToolTip(tr("Refresh is disabled."));
      ui->spinArgCount->setEnabled(false);
      ui->comboCallingConvention->setEnabled(false);
      mAllowUpdate = false;
      break;
    case Qt::PartiallyChecked:  // Locked, but still update when a call is
                                // encountered.
      refreshData();            // first refresh then lock
      ui->checkBoxLock->setText(tr("Calls"));
      ui->checkBoxLock->setToolTip(
          tr("Refresh is only done when executing a CALL instruction."));
      ui->spinArgCount->setEnabled(false);
      ui->comboCallingConvention->setEnabled(false);
      mAllowUpdate = false;
      break;
    case Qt::Unchecked:  // Unlocked, update enabled
      ui->checkBoxLock->setText(tr("Unlocked"));
      ui->checkBoxLock->setToolTip(tr("Refresh is automatic."));
      ui->spinArgCount->setEnabled(true);
      ui->comboCallingConvention->setEnabled(true);
      mAllowUpdate = true;
      refreshData();  // first lock then refresh
      break;
    default:
      break;
  }
}

void CPUArgumentWidgetA64::loadConfig() {
  CallingConvention a64(tr("Default (arm64 fastcall)"), 1);
  a64.addArgument(Argument("", "", "x0"));
  a64.addArgument(Argument("", "", "x1"));
  a64.addArgument(Argument("", "", "x2"));
  a64.addArgument(Argument("", "", "x3"));
  a64.addArgument(Argument("", "", "x4"));
  a64.addArgument(Argument("", "", "x5"));
  a64.addArgument(Argument("", "", "x6"));
  a64.addArgument(Argument("", "", "x7"));

  mCallingConventions.push_back(a64);
  ui->spinArgCount->setRange(4, 8);

  for (auto& cur : mCallingConventions)
    ui->comboCallingConvention->addItem(cur.name);
}

void CPUArgumentWidgetX64::loadConfig() {
  CallingConvention x64(tr("Default (amd64 system-v fastcall)"), 1);
  x64.addArgument(Argument("", "", "rdi"));
  x64.addArgument(Argument("", "", "rsi"));
  x64.addArgument(Argument("", "", "rdx"));
  x64.addArgument(Argument("", "", "rcx"));

  mCallingConventions.push_back(x64);
  ui->spinArgCount->setRange(4, 4);

  for (auto& cur : mCallingConventions)
    ui->comboCallingConvention->addItem(cur.name);
}

void CPUArgumentWidgetA32::loadConfig() {
  CallingConvention a64(tr("Default (arm fastcall)"), 1);
  a64.addArgument(Argument("", "", "r0"));
  a64.addArgument(Argument("", "", "r1"));
  a64.addArgument(Argument("", "", "r2"));
  a64.addArgument(Argument("", "", "r3"));

  mCallingConventions.push_back(a64);
  ui->spinArgCount->setRange(4, 4);

  for (auto& cur : mCallingConventions)
    ui->comboCallingConvention->addItem(cur.name);
}

void CPUArgumentWidgetX86::loadConfig() {
  ui->spinArgCount->setRange(0, 0);
}
