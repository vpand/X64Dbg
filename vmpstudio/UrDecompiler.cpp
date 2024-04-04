#include "UrDecompiler.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
#include <QHBoxLayout>

#include "Bridge.h"
#include "BrowseDialog.h"
#include "Configuration.h"
#include "StdSearchListView.h"
#include "SourceViewerManager.h"
#include "VMPGlobal.h"
#include "UVMTraceWidget.h"
#include "ui_UrDecompiler.h"

UrDecompiler::UrDecompiler(QWidget* parent)
    : QWidget(parent), ui(new Ui::UrDecompiler) {
  ui->setupUi(this);
  setAutoFillBackground(false);

  // Set main layout
  mMainLayout = new QHBoxLayout;
  mMainLayout->setContentsMargins(0, 0, 0, 0);
  mMainLayout->addWidget(ui->mainSplitter);
  setLayout(mMainLayout);

  // Create reference view
  mSymbolList = new StdSearchListView(
    this, true, false,
    new StdTableSearchList(new StdTable(), new StdTable()));
  mSymbolList->setSearchStartCol(0);
  mSymbolList->enableMultiSelection(true);
  mSymbolList->setAddressColumn(0, true);
  mSymbolList->setDisassemblyPopupEnabled(false);
  int charwidth = mSymbolList->getCharWidth();
  mSymbolList->addColumnAt(290, tr("Function"), true);
  mSymbolList->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Address"), true);

  // Create source manager
  mSourceMgr = new SourceViewerManager(this);

  // Setup list splitter
  ui->mainSplitter->addWidget(mSymbolList);
  ui->mainSplitter->addWidget(mSourceMgr);
  ui->mainSplitter->setStretchFactor(0, 10);
  ui->mainSplitter->setStretchFactor(1, 90);

  // setup context menu
  setupContextMenu();

  // Signals and slots
  connect(Bridge::getBridge(), SIGNAL(repaintTableView()), this,
          SLOT(updateStyle()));
  connect(Bridge::getBridge(), SIGNAL(symbolRefreshCurrent()), this,
          SLOT(symbolRefreshCurrent()));
  connect(mSymbolList, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(symbolContextMenu(QMenu*)));
  connect(mSymbolList, SIGNAL(enterPressedSignal()), this,
          SLOT(enterPressedSlot()));
  connect(Config(), SIGNAL(colorsUpdated()), this, SLOT(updateStyle()));
  connect(Config(), SIGNAL(fontsUpdated()), this, SLOT(updateStyle()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(dbgStateChangedSlot(DBGSTATE)));
}

UrDecompiler::~UrDecompiler() {
  delete ui;
}

inline void saveSymbolsSplitter(QSplitter* splitter, QString name) {
  BridgeSettingSet("UrDecompilerSettings", (name + "Geometry").toUtf8().constData(),
                   splitter->saveGeometry().toBase64().data());
  BridgeSettingSet("UrDecompilerSettings", (name + "State").toUtf8().constData(),
                   splitter->saveState().toBase64().data());
}

inline void loadSymbolsSplitter(QSplitter* splitter, QString name) {
  char setting[MAX_SETTING_SIZE] = "";
  if (BridgeSettingGet("UrDecompilerSettings",
                       (name + "Geometry").toUtf8().constData(), setting))
    splitter->restoreGeometry(QByteArray::fromBase64(QByteArray(setting)));
  if (BridgeSettingGet("UrDecompilerSettings", (name + "State").toUtf8().constData(),
                       setting))
    splitter->restoreState(QByteArray::fromBase64(QByteArray(setting)));
  splitter->splitterMoved(1, 0);
}

void UrDecompiler::saveWindowSettings() {
  saveSymbolsSplitter(ui->mainSplitter, "mHUrDecompilerSplitter");
}

void UrDecompiler::loadWindowSettings() {
  loadSymbolsSplitter(ui->mainSplitter, "mHUrDecompilerSplitter");
}

void UrDecompiler::invalidateSymbolSource(duint base) {}

void UrDecompiler::setupContextMenu() {
  QIcon disassembler = DIcon(ArchValue("processor32.png", "processor-cpu.png"));
  // Symbols
  mFollowSymbolAction =
      new QAction(disassembler, tr("&Follow in Disassembler"), this);
  connect(mFollowSymbolAction, SIGNAL(triggered()), this, SLOT(symbolFollow()));

  mFollowSymbolDumpAction =
      new QAction(DIcon("dump.png"), tr("Follow in &Dump"), this);
  connect(mFollowSymbolDumpAction, SIGNAL(triggered()), this,
          SLOT(symbolFollowDump()));

  mDecompileAction =
      new QAction(DIcon("compile-warning.png"), tr("De&compile"), this);
  connect(mDecompileAction, SIGNAL(triggered()), this,
          SLOT(symbolDecompile()));

  mDynDecompileAction =
      new QAction(DIcon("compile.png"), tr("D&ynamic Decompile"), this);
  connect(mDynDecompileAction, SIGNAL(triggered()), this,
          SLOT(symbolDynDecompile()));

  mToggleBreakpoint =
      new QAction(DIcon("breakpoint.png"), tr("Toggle Breakpoint"), this);
  mToggleBreakpoint->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  this->addAction(mToggleBreakpoint);
  connect(mToggleBreakpoint, SIGNAL(triggered()), this,
          SLOT(toggleBreakpoint()));

  mPluginMenu = new QMenu(this);
  Bridge::getBridge()->emitMenuAddToList(this, mPluginMenu, GUI_SYMMOD_MENU);

  // Shortcuts
  refreshShortcutsSlot();
  connect(Config(), SIGNAL(shortcutsUpdated()), this,
          SLOT(refreshShortcutsSlot()));
}

void UrDecompiler::refreshShortcutsSlot() {
  mToggleBreakpoint->setShortcut(ConfigShortcut("ActionToggleBreakpoint"));
  // mDownloadSymbolsAction->setShortcut(ConfigShortcut("ActionDownloadSymbol"));
  // mDownloadAllSymbolsAction->setShortcut(
  //    ConfigShortcut("ActionDownloadAllSymbol"));
  // mFollowInMemMap->setShortcut(ConfigShortcut("ActionFollowMemMap"));
}

void UrDecompiler::updateStyle() {}

void UrDecompiler::symbolContextMenu(QMenu* wMenu) {
  if (!mSymbolList->mCurList->getRowCount()) return;
  wMenu->addAction(mDecompileAction);
  wMenu->addAction(mDynDecompileAction);
  wMenu->addSeparator();
  wMenu->addAction(mFollowSymbolAction);
  wMenu->addAction(mFollowSymbolDumpAction);
  wMenu->addSeparator();
  wMenu->addAction(mToggleBreakpoint);
}

void UrDecompiler::symbolRefreshCurrent() {}

void UrDecompiler::symbolFollow() {
  DbgCmdExec(QString("disasm " +
                     mSymbolList->mCurList->getCellContent(
                         mSymbolList->mCurList->getInitialSelection(), 0)));
}

void UrDecompiler::symbolFollowDump() {
  DbgCmdExecDirect(
      QString("dump " + mSymbolList->mCurList->getCellContent(
                            mSymbolList->mCurList->getInitialSelection(), 0)));
}

void UrDecompiler::enterPressedSlot() {
  symbolDecompile();
}

void UrDecompiler::toggleBreakpoint() {
  if (!DbgIsDebugging()) return;

  if (!mSymbolList->mCurList->getRowCount()) return;

  auto selection = mSymbolList->mCurList->getSelection();

  for (auto selectedIdx : selection) {
    QString addrText = mSymbolList->mCurList->getCellContent(selectedIdx, 0);
    duint wVA;
    if (!DbgFunctions()->ValFromString(addrText.toUtf8().constData(), &wVA))
      return;

    // Import means that the address is an IAT entry so we read the actual
    // function address
    if (mSymbolList->mCurList->getCellContent(selectedIdx, 1) == tr("Import"))
      DbgMemRead(wVA, &wVA, sizeof(wVA));

    if (!DbgMemIsValidReadPtr(wVA)) return;

    BPXTYPE wBpType = DbgGetBpxTypeAt(wVA);
    QString wCmd;

    if ((wBpType & bp_normal) == bp_normal) {
      wCmd = "bc " + ToPtrString(wVA);
    } else {
      wCmd = "bp " + ToPtrString(wVA);
    }

    DbgCmdExec(wCmd);
  }
}

void UrDecompiler::emptySearchResultSlot() {
  // No result after search
  mSymbolList->mCurList->setRowCount(0);
}

void UrDecompiler::reloadFunc() {
  dbgStateChangedSlot(paused);
}

void UrDecompiler::dbgStateChangedSlot(DBGSTATE state) {
  if (state == paused) {
    VMPManaDatabase* mdb = VMPGlobal::inst()->debugee;
    if (!mdb) {
      return;
    }
    mSymbolList->setRowCount(mdb->db->functions().size());
    auto fit = mdb->db->functions().begin();
    for (int i = 0; i < (int)mdb->db->functions().size(); i++, fit++) {
      auto fn = &fit->second;
      char addr[32];
      sprintf(addr, "%016llX", fit->first);
      std::string dmname =
          VMPGlobal::inst()->diser(fn)->demangle(fn->name.data());
      if (dmname.length()) {
        mSymbolList->setCellContent(i, 0, dmname.data());
      } else {
        mSymbolList->setCellContent(i, 0, fn->name.data());
      }
      mSymbolList->setCellContent(i, 1, addr);
    }
    mSymbolList->reloadData();
  } else if (state == stopped) {
    mSymbolList->setRowCount(0);
    mSymbolList->reloadData();
  }
}

void UrDecompiler::symbolDecompile() {
  if (!DbgIsDebugging()) return;

  auto addr = DbgValFromString(
      mSymbolList->mCurList
          ->getCellContent(mSymbolList->mCurList->getInitialSelection(), 1)
          .toUtf8()
          .constData());
  auto mdb = VMPGlobal::inst()->debugee;
  auto base = mdb->db->imageBase();
  auto func = mdb->rvaToFunction(addr - base, false);
  QString srcjson = QString("%1/%2.c").arg(VMPGlobal::inst()->tempDir(), func.func->name.data());
  if (retdec_main(mdb->path.toUtf8().data(), srcjson.toUtf8().data(),
                  base + func.rvastart, base + func.rvaend,
                  [](addr_t addr) { return VMPGlobal::inst()->addrName(addr); }) == 0) {
    mSourceMgr->loadSourceFile(srcjson, func.func->start);
  }
  else {
    GuiAddLogMessage(QString("Failed to decompile function %1.\n").arg(func.func->name.data()).toUtf8().data());
  }
}

void UrDecompiler::symbolDynDecompile() {
  if (!DbgIsDebugging()) return;

  auto addr = DbgValFromString(
      mSymbolList->mCurList
          ->getCellContent(mSymbolList->mCurList->getInitialSelection(), 1)
          .toUtf8()
          .constData());
  auto mdb = VMPGlobal::inst()->debugee;
  auto base = mdb->db->imageBase();
  auto func = mdb->rvaToFunction(addr - base, false);
  QByteArray srcjson = QString("%1/%2.dyn.c").arg(VMPGlobal::inst()->tempDir(), func.func->name.data()).toUtf8();
  urdec_params_t params;
  params.bin = VMPGlobal::inst()->debugee->db;
  params.start = base + func.rvastart;
  params.end = base + func.rvaend;
  params.srcpath = srcjson.data();
  params.pages = &uvmWin->mPageBuffs;
  params.rawpages = &uvmWin->mPageRawBuffs;
  params.indexs = &uvmWin->mRecordInds;
  params.rtbase = uvmWin->runtimeBase();
  params.regsarm = &uvmWin->mRecordARMCur;
  params.regsarm64 = &uvmWin->mRecordARM64Cur;
  params.index = uvmWin->mRecordCur;
  switch (mdb->db->archType()) {
  case mana::ARM: {
    if (!uvmWin->mRecordARMCur.size()) {
      GuiAddLogMessage("There's no UraniumVM arm register sample data.\n");
      return;
    }
    if (urdyndec_main(&params,
                      [](addr_t addr) { return VMPGlobal::inst()->addrName(addr); }) == 0) {
      mSourceMgr->loadSourceFile(srcjson, func.func->start);
      return;
    }
    break;
  }
  case mana::ARM64:
    if (!uvmWin->mRecordARM64Cur.size()) {
      GuiAddLogMessage("There's no UraniumVM arm64 register sample data.\n");
      return;
    }
    if (urdyndec_main(&params,
                      [](addr_t addr) { return VMPGlobal::inst()->addrName(addr); }) == 0) {
      mSourceMgr->loadSourceFile(srcjson, func.func->start);
      return;
    }
    break;
  default:
    GuiAddLogMessage("Dynamic Decompiler only supports arm/arm64 currently.\n");
    return;
  }
  GuiAddLogMessage(QString("Failed to decompile function %1.\n").arg(func.func->name.data()).toUtf8().data());
}
