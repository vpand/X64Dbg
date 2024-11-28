#include "CPUWidgetFile.h"

#include <QDesktopWidget>
#include <QScrollArea>
#include <QTabWidget>
#include <QVBoxLayout>

#include "CPUArgumentWidget.h"
#include "CPUDisassemblyFile.h"
#include "CPUInfoBox.h"
#include "CPUMultiDumpFile.h"
#include "CPUStack.h"
#include "Configuration.h"
#include "DisassemblerGraphView.h"
#include "EditFunctionDialog.h"
#include "UVMSEOptionDialog.h"
#include "LogView.h"
#include "StdSearchListView.h"
#include "TabWidget.h"
#include "VMPGlobal.h"
#include "UVMTraceWidget.h"
#include "ui_CPUWidget.h"

#define DbgGlobal VMPGlobal

CPUWidgetFile::CPUWidgetFile(QWidget* parent)
    : QWidget(parent), ui(new Ui::CPUWidget) {
  ui->setupUi(this);
  setDefaultDisposition();

  setStyleSheet(
      "AbstractTableView:focus, CPURegistersView:focus, "
      "StdSearchListView:focus { "
      "border: 1px solid #000000; }");

  mDisas = new CPUDisassemblyFile(this, true);

  mFuns = new StdSearchListView(
      this, true, false,
      new StdTableSearchList(new StdTable(), new StdTable()));
  mFuns->setSearchStartCol(0);
  mFuns->enableMultiSelection(true);
  mFuns->setAddressColumn(0, true);
  mFuns->setDisassemblyPopupEnabled(false);
  int charwidth = mFuns->getCharWidth();
  mFuns->addColumnAt(260, tr("Function"), true);
  mFuns->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Address"), true, "", StdTable::SortBy::AsHex);
  mFuns->addColumnAt(charwidth * 2 * sizeof(dsint), tr("Size"), true,  "", StdTable::SortBy::AsInt);

  mSects = new StdTable(this);
  mSects->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Start"), true, "", StdTable::SortBy::AsHex);
  mSects->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("End"), false, "", StdTable::SortBy::AsHex);
  mSects->addColumnAt(100, tr("Name"), true);

  mGraph = new DisassemblerGraphView(this);

  connect(mGraph, SIGNAL(detachGraph()), this, SLOT(detachGraph()));
  // connect(Bridge::getBridge(), SIGNAL(focusDisasm()), this,
  //        SLOT(setDisasmFocus()));
  connect(Bridge::getBridge(), SIGNAL(focusGraph()), this,
          SLOT(setGraphFocus()));

  ui->mTopLeftUpperHSplitter->setCollapsible(
      0, true);  // allow collapsing of the side bar

  ui->mTopLeftUpperLeftFrameLayout->addWidget(mFuns);
  ui->mTopLeftUpperRightFrameLayout->addWidget(mDisas);
  ui->mTopLeftUpperRightFrameLayout->addWidget(mGraph);
  mGraph->hide();
  disasMode = 2;
  mGraphWindow = nullptr;

  ui->mTopLeftVSplitter->setCollapsible(
      1, true);  // allow collapsing of the InfoBox
  connect(ui->mTopLeftVSplitter, SIGNAL(splitterMoved(int, int)), this,
          SLOT(splitterMoved(int, int)));

  mInfo = new CPUInfoBox();
  mInfo->setFixedWidth(2000);
  QScrollArea* modScrollArea = new QScrollArea(this);
  modScrollArea->setFrameShape(QFrame::NoFrame);
  modScrollArea->setWidget(mInfo);
  ui->mTopLeftLowerFrameLayout->addWidget(modScrollArea);
  int height = mInfo->getHeight();
  ui->mTopLeftLowerFrame->setMinimumHeight(height);

  connect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
          SLOT(disasmSelectionChanged(dsint)));

  mDump = new CPUMultiDumpFile(mDisas, 5, 0);  // dump widget

  mLogView = new LogView(this);
  mLogView->setFixedWidth(2000);
  mLogView->setFixedHeight(2000);
  mLogView->setWindowTitle(tr("Log"));
  mLogView->setWindowIcon(DIcon("log.png"));

  QScrollArea* upperScrollArea = new QScrollArea(this);
  upperScrollArea->setFrameShape(QFrame::NoFrame);
  upperScrollArea->setWidget(mLogView);

  ui->mBotLeftFrameLayout->addWidget(mDump);
  ui->mTopRightUpperFrameLayout->addWidget(upperScrollArea);

  ui->mTopRightVSplitter->setCollapsible(
      1, true);  // allow collapsing of the ArgumentWidget
  connect(ui->mTopRightVSplitter, SIGNAL(splitterMoved(int, int)), this,
          SLOT(splitterMoved(int, int)));

  ui->mTopRightVSplitter->setCollapsible(
      1, true);  // allow collapsing of the ArgumentWidget
  connect(ui->mTopRightVSplitter, SIGNAL(splitterMoved(int, int)), this,
          SLOT(splitterMoved(int, int)));

  ui->mTopRightLowerFrameLayout->addWidget(mSects);

  mStrings = new StdSearchListView(
      this, true, false,
      new StdTableSearchList(new StdTable(), new StdTable()));
  mStrings->setSearchStartCol(0);
  mStrings->enableMultiSelection(true);
  mStrings->setAddressColumn(0, true);
  mStrings->setDisassemblyPopupEnabled(false);
  mStrings->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Address"), true);
  mStrings->addColumnAt(300, tr("String"), true);
  ui->mBotRightFrameLayout->addWidget(mStrings);
  connect(Bridge::getBridge(), SIGNAL(updateDump()), this,
          SLOT(updateStringSlot()));

  connect(mFuns->stdList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(funcSelectionChanged(int)));
  connect(mFuns->stdSearchList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(funcSelectionChanged(int)));
  connect(mStrings->stdList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(strSelectionChanged(int)));
  connect(mStrings->stdSearchList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(strSelectionChanged(int)));
  connect(mFuns, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(funContextMenu(QMenu*)));
  connect(mSects, SIGNAL(contextMenuSignal(QPoint)), this,
          SLOT(sectContextMenu(QPoint)));
  connect(mStrings, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(strContextMenu(QMenu*)));
  setupContextMenu();
  detachGraph();
  mGraphWindow->hide();

  // load column config
  mDisas->loadColumnFromConfig("CPUDisassembly");
}

void CPUWidgetFile::setupContextMenu() {
  QMenu** menufollowdumpn[] = {
      &mMenuFunFollowDumpN,
      &mMenuSectFollowDumpN,
      &mMenuStrFollowDumpN,
  };
  const char* slotfollowdumpn[] = {SLOT(followFunInDumpNSlot()),
                                   SLOT(followSectInDumpNSlot()),
                                   SLOT(followStrInDumpNSlot())};
  QList<QAction*>* actionfollowdumpn[] = {
      &mActionFunFollowDumpN,
      &mActionSectFollowDumpN,
      &mActionStrFollowDumpN,
  };
  QIcon dumpicons[] = {
      DIcon("follow_in_dump1.png"), DIcon("follow_in_dump2.png"),
      DIcon("follow_in_dump3.png"), DIcon("follow_in_dump4.png"),
      DIcon("follow_in_dump5.png"),
  };
  QList<QString> tabNames;
  mDump->getTabNames(tabNames);
  for (size_t i = 0; i < sizeof(menufollowdumpn) / sizeof(menufollowdumpn[0]);
       i++) {
    QMenu* menu = makeMenu(DIcon("follow_in_dump.png"), tr("&Follow in Dump"));
    *menufollowdumpn[i] = menu;
    for (int t = 0; t < mDump->getMaxCPUTabs(); t++) {
      QAction* action =
          makeAction(dumpicons[t], tabNames[t], slotfollowdumpn[i]);
      menu->addAction(action);
      actionfollowdumpn[i]->push_back(action);
    }
  }
  mActionFunEdit =
      makeAction(DIcon("label.png"), "&Edit Function", SLOT(editFunSlot()));
  mActionFunTrace =
      makeAction(DIcon("trace.png"), "&Sample Function", SLOT(traceFunSlot()));
  mActionFunTraceStop =
      makeAction(DIcon("removestruct.png"), "Sample S&top", SLOT(traceFunStopSlot()));
  mActionFunTraceOption =
      makeAction(DIcon("settings.png"), "Sample &Options", SLOT(traceOptionSlot()));
  mActionFunDecompile =
      makeAction(DIcon("compile-warning.png"), "&Decompile Function", SLOT(decompileFunSlot()));
  mActionFunDynDecompile =
      makeAction(DIcon("compile.png"), "Dynamic De&compile", SLOT(dynamicDecompileFunSlot()));

}

inline void saveSplitter(QSplitter* splitter, QString name) {
  BridgeSettingSet("Main Window Settings",
                   (name + "Geometry").toUtf8().constData(),
                   splitter->saveGeometry().toBase64().data());
  BridgeSettingSet("Main Window Settings",
                   (name + "State").toUtf8().constData(),
                   splitter->saveState().toBase64().data());
}

inline void loadSplitter(QSplitter* splitter, QString name) {
  char setting[MAX_SETTING_SIZE] = "";
  if (BridgeSettingGet("Main Window Settings",
                       (name + "Geometry").toUtf8().constData(), setting))
    splitter->restoreGeometry(QByteArray::fromBase64(QByteArray(setting)));
  if (BridgeSettingGet("Main Window Settings",
                       (name + "State").toUtf8().constData(), setting))
    splitter->restoreState(QByteArray::fromBase64(QByteArray(setting)));
  splitter->splitterMoved(1, 0);
}

void CPUWidgetFile::saveWindowSettings() {
  saveSplitter(ui->mVSplitter, "mVSplitter");
  saveSplitter(ui->mTopHSplitter, "mTopHSplitter");
  saveSplitter(ui->mTopLeftVSplitter, "mTopLeftVSplitter");
  saveSplitter(ui->mTopLeftUpperHSplitter, "mTopLeftUpperHSplitter");
  saveSplitter(ui->mTopRightVSplitter, "mTopRightVSplitter");
  saveSplitter(ui->mBotHSplitter, "mBotHSplitter");
}

void CPUWidgetFile::loadWindowSettings() {
  loadSplitter(ui->mVSplitter, "mVSplitter");
  loadSplitter(ui->mTopHSplitter, "mTopHSplitter");
  loadSplitter(ui->mTopLeftVSplitter, "mTopLeftVSplitter");
  loadSplitter(ui->mTopLeftUpperHSplitter, "mTopLeftUpperHSplitter");
  loadSplitter(ui->mTopRightVSplitter, "mTopRightVSplitter");
  loadSplitter(ui->mBotHSplitter, "mBotHSplitter");
}

CPUWidgetFile::~CPUWidgetFile() {
  delete mGraphWindow;
  delete ui;
}

void CPUWidgetFile::setDefaultDisposition() {
  // This is magic, don't touch it...

  // Vertical Splitter
  ui->mVSplitter->setStretchFactor(0, 48);
  ui->mVSplitter->setStretchFactor(1, 62);

  // Top Horizontal Splitter
  ui->mTopHSplitter->setStretchFactor(0, 77);
  ui->mTopHSplitter->setStretchFactor(1, 23);

  // Bottom Horizontal Splitter
  ui->mBotHSplitter->setStretchFactor(0, 60);
  ui->mBotHSplitter->setStretchFactor(1, 40);

  // Top Right Vertical Splitter
  ui->mTopRightVSplitter->setStretchFactor(0, 87);
  ui->mTopRightVSplitter->setStretchFactor(1, 13);

  // Top Left Vertical Splitter
  ui->mTopLeftVSplitter->setStretchFactor(0, 99);
  ui->mTopLeftVSplitter->setStretchFactor(1, 1);

  // Top Left Upper Horizontal Splitter
  ui->mTopLeftUpperHSplitter->setStretchFactor(0, 36);
  ui->mTopLeftUpperHSplitter->setStretchFactor(1, 64);
}

void CPUWidgetFile::setDisasmFocus() {
  if (disasMode == 1) {
    mGraph->hide();
    mDisas->show();
    mFuns->show();
    disasMode = 0;
    connect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
    disconnect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
               SLOT(disasmSelectionChanged(dsint)));
  } else if (disasMode == 2) {
    activateWindow();
  }
  mDisas->setFocus();
}

void CPUWidgetFile::setGraphFocus() {
  if (disasMode == 0) {
    mDisas->hide();
    mFuns->hide();
    mGraph->show();
    disasMode = 1;
    disconnect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
               SLOT(disasmSelectionChanged(dsint)));
    connect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
  } else if (disasMode == 2) {
    mGraph->activateWindow();
  }
  mGraph->setFocus();
  mGraphWindow->activateWindow();
  mGraphWindow->show();
  mGraphWindow->setFocus();
}

void CPUWidgetFile::detachGraph() {
  if (mGraphWindow == nullptr) {
    mGraphWindow = new MHDetachedWindow(this);

    mGraphWindow->setWindowModality(Qt::NonModal);

    // Find Widget and connect
    connect(mGraphWindow, SIGNAL(OnClose(QWidget*)), this,
            SLOT(attachGraph(QWidget*)));

    mGraphWindow->setWindowTitle(tr("Graph"));
    mGraphWindow->setWindowIcon(mGraph->windowIcon());
    mGraphWindow->mNativeName = "";

    mGraph->setParent(mGraphWindow);
    ui->mTopLeftUpperRightFrameLayout->removeWidget(mGraph);

    // Create and show
    mGraphWindow->show();
    mGraphWindow->setCentralWidget(mGraph);

    // Needs to be done explicitly
    mGraph->showNormal();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int w = 800;
    int h = 600;
    int x = (screenGeometry.width() - w) / 2;
    int y = (screenGeometry.height() - h) / 3;
    mGraphWindow->showNormal();
    mGraphWindow->setGeometry(x, y, w, h);
    mGraphWindow->showNormal();
    Qt::WindowFlags flags = mGraphWindow->windowFlags();
    mGraphWindow->setWindowFlags(flags | Qt::WindowStaysOnTopHint);

    disasMode = 2;

    mDisas->show();
    mFuns->show();
    connect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
    connect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
  }
}

void CPUWidgetFile::attachGraph(QWidget* widget) {
#if 0
  mGraph->setParent(this);
  ui->mTopLeftUpperRightFrameLayout->addWidget(mGraph);
  mGraph->hide();
  mGraphWindow->close();
  disconnect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
             SLOT(disasmSelectionChanged(dsint)));
  delete mGraphWindow;
  mGraphWindow = nullptr;
  disasMode = 0;
#else
  // vmpstudio only support detach graph mode
  (void)widget;
  mGraphWindow->hide();
#endif
}

// This is used in run to selection
duint CPUWidgetFile::getSelectionVa() {
  if (disasMode < 2)
    return disasMode == 0 ? mDisas->getSelectedVa() : mGraph->get_cursor_pos();
  else
    return !mGraph->hasFocus() ? mDisas->getSelectedVa()
                               : mGraph->get_cursor_pos();
}

StdSearchListView* CPUWidgetFile::getSidebarWidget() { return mFuns; }

CPUDisassemblyFile* CPUWidgetFile::getDisasmWidget() { return mDisas; }

DisassemblerGraphView* CPUWidgetFile::getGraphWidget() { return mGraph; }

CPUMultiDumpFile* CPUWidgetFile::getDumpWidget() { return mDump; }

CPUInfoBox* CPUWidgetFile::getInfoBoxWidget() { return mInfo; }

StdSearchListView* CPUWidgetFile::getStackWidget() { return mStrings; }

void CPUWidgetFile::splitterMoved(int pos, int index) {
  Q_UNUSED(pos);
  Q_UNUSED(index);
  auto splitter = qobject_cast<QSplitter*>(sender());
  if (splitter == nullptr) {
  }  // ???
  else if (splitter->sizes().at(1) == 0) {
    splitter->handle(1)->setCursor(Qt::UpArrowCursor);
    splitter->setStyleSheet(
        "QSplitter::handle:vertical { border-top: 2px solid grey; }");
  } else {
    splitter->handle(1)->setCursor(Qt::SplitVCursor);
    splitter->setStyleSheet("");
  }
}

void CPUWidgetFile::updateStringSlot() {
  auto vg = VMPGlobal::inst();
  auto debugee = vg->debugee;
  if (!debugee) return;

  mStrings->setRowCount(debugee->strs.size());
  int r = 0;
  for (auto& s : debugee->strs) {
    char addr[32];
    sprintf(addr, "%016llX", vg->debugee->rtbase + s.first);
    QString str(s.second);
    str.replace('\n', '\t');
    mStrings->setCellContent(r, 0, addr);
    mStrings->setCellContent(r, 1, str);
    r++;
  }
  mStrings->repaint();
}

void CPUWidgetFile::reloadFunc() {
  auto vg = VMPGlobal::inst();
  auto mdb = vg->debugee;
  auto funcs = mdb->db->functions();
  auto winFn = getSidebarWidget();
  winFn->setRowCount(funcs.size());
  auto fit = funcs.begin();
  if (fit != funcs.end()) {
    mCurFunc = mdb->rvaToFunction(fit->first - mdb->rtbase, false);
  }
  for (int i = 0; i < (int)funcs.size(); i++, fit++) {
    auto fn = &fit->second;
    char addr[32], size[32];
    sprintf(addr, "%016llX", fit->first);
    sprintf(size, "%lld", fn->end - fit->first);
    std::string dmname =
        VMPGlobal::inst()->diser(fn)->demangle(fn->name.data());
    if (dmname.length()) {
      winFn->setCellContent(i, 0, dmname.data());
    } else {
      winFn->setCellContent(i, 0, fn->name.data());
    }
    winFn->setCellContent(i, 1, addr);
    winFn->setCellContent(i, 2, size);
  }
  winFn->reloadData();
}

void CPUWidgetFile::funcSelectionChanged(int index) {
  if (!DbgIsDebugging()) return;

  StdTable* table =
      sender() == mFuns->stdList() ? mFuns->stdList() : mFuns->stdSearchList();
  QString straddr = table->getCellContent(index, 1);
  addr_t addr = strtoul(straddr.toUtf8().data(), nullptr, 16);
  auto mdb = VMPGlobal::inst()->debugee;
  auto func = mdb->rvaToFunction(addr - mdb->rtbase, true);
  if (func) {
    auto sect = mdb->rvaToSection(func.rvastart);
    if (sect) {
      getInfoBoxWidget()->setInfoLine(
        0, QString("%1.%2 %3-%4 %5")
               .arg(sect->name.data())
               .arg(func.func->name.data())
               .arg(ToPtrString(addr))
               .arg(ToPtrString(mdb->rtbase + func.rvaend))
               .arg(func.rvaend - func.rvastart));
      getDisasmWidget()->disassembleAt(addr, false, -1);
      mCurFunc = func;
    }
  }
}

void CPUWidgetFile::strSelectionChanged(int index) {
  StdTable* table = sender() == mStrings->stdList() ? mStrings->stdList()
                                                    : mStrings->stdSearchList();
  QString straddr = table->getCellContent(index, 0);
  auto vg = VMPGlobal::inst();
  auto mdb = vg->debugee;
  addr_t addr = strtoul(straddr.toUtf8().data(), nullptr, 16);
  addr_t rva = addr - mdb->rtbase;
  auto found = mdb->strs.find(rva);
  if (found != mdb->strs.end()) {
    auto sect = mdb->rvaToSection(rva);
    getInfoBoxWidget()->setInfoLine(1, QString("%1.%2 %3 %4")
                                           .arg(sect->name.data())
                                           .arg(ToPtrString(addr))
                                           .arg(found->second)
                                           .arg(strlen(found->second)));
    getDumpWidget()->printDumpAtSlot(addr);
    mCurStr = addr;
  }
}

void CPUWidgetFile::funContextMenu(QMenu* wMenu) {
  if (!DbgIsDebugging()) return;
  wMenu->addAction(mActionFunTrace);
  wMenu->addAction(mActionFunTraceStop);
  wMenu->addAction(mActionFunTraceOption);
  wMenu->addSeparator();
  wMenu->addAction(mActionFunDecompile);
  wMenu->addAction(mActionFunDynDecompile);
  wMenu->addSeparator();
  wMenu->addAction(mActionFunEdit);
  wMenu->addMenu(mMenuFunFollowDumpN);
}

void CPUWidgetFile::sectContextMenu(QPoint pt) {
  if (!DbgIsDebugging()) return;
  QMenu wMenu(mSects);
  wMenu.addMenu(mMenuSectFollowDumpN);
  wMenu.addSeparator();
  QMenu* wCopyMenu = makeMenu(DIcon("copy.png"), "&Copy");
  mSects->setupCopyMenu(wCopyMenu);
  wMenu.addMenu(wCopyMenu);
  wMenu.exec(mSects->mapToGlobal(pt));
}

void CPUWidgetFile::strContextMenu(QMenu* wMenu) {
  if (!DbgIsDebugging()) return;
  wMenu->addMenu(mMenuStrFollowDumpN);
}

void CPUWidgetFile::editFunSlot() {
  EditFunctionDialog dlg(nullptr, &mCurFunc);
  dlg.exec();
}

void CPUWidgetFile::traceFunSlot() {
  uvmWin->uvmTraceStart(mCurFunc);
}

void CPUWidgetFile::traceOptionSlot() {
  UVMSEOptionDialog dlg;
  dlg.exec();
}

void CPUWidgetFile::traceFunStopSlot() {
  uvmWin->uvmTraceStop(mCurFunc);
}

void CPUWidgetFile::decompileFunSlot() {
  DbgCmdExec(QString("decompile %1").arg(ToPtrString(mCurFunc.func->start)));
}

void CPUWidgetFile::dynamicDecompileFunSlot() {
  DbgCmdExec(QString("urdyndec %1").arg(ToPtrString(mCurFunc.func->start)));
}

void CPUWidgetFile::followFunInDumpNSlot() {
  auto obj = sender();
  for (int i = 0; i < mActionFunFollowDumpN.size(); i++) {
    if (mActionFunFollowDumpN[i] == obj) {
      getDumpWidget()->printDumpAtNSlot(
          mCurFunc.rvastart + VMPGlobal::inst()->debugee->rtbase, i + 1);
      break;
    }
  }
}

void CPUWidgetFile::followSectInDumpNSlot() {
  auto obj = sender();
  for (int i = 0; i < mActionSectFollowDumpN.size(); i++) {
    if (mActionSectFollowDumpN[i] == obj) {
      int index = getSectWidget()->getInitialSelection();
      duint addr =
          strtoul(getSectWidget()->getCellContent(index, 0).toUtf8().data(),
                  nullptr, 16);
      getDumpWidget()->printDumpAtNSlot(addr, i + 1);
      break;
    }
  }
}

void CPUWidgetFile::followStrInDumpNSlot() {
  auto obj = sender();
  for (int i = 0; i < mActionStrFollowDumpN.size(); i++) {
    if (mActionStrFollowDumpN[i] == obj) {
      getDumpWidget()->printDumpAtNSlot(mCurStr, i + 1);
      break;
    }
  }
}
