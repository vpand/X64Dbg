#include "CPUWidget.h"

#include <QDesktopWidget>
#include <QTabWidget>
#include <QVBoxLayout>

#include "CPUArgumentWidget.h"
#include "CPUDisassembly.h"
#include "CPUInfoBox.h"
#include "CPUMultiDump.h"
#include "CPURegistersView.h"
#include "CPURegistersViewA32.h"
#include "CPURegistersViewX64.h"
#include "CPURegistersViewX86.h"
#include "CPUSideBar.h"
#include "CPUStack.h"
#include "Configuration.h"
#include "DisassemblerGraphView.h"
#include "TabWidget.h"
#include "DialogExecMap.h"
#include "ui_CPUWidget.h"

CPUWidget::CPUWidget(QWidget* parent) : QWidget(parent), ui(new Ui::CPUWidget) {
  ui->setupUi(this);
  setDefaultDisposition();

  setStyleSheet(
      "AbstractTableView:focus, CPURegistersView:focus, CPUSideBar:focus { "
      "border: 1px solid #000000; }");

  mDisas = new CPUDisassembly(this, true);
  mSideBar = new CPUSideBar(mDisas);
  mDisas->setSideBar(mSideBar);

  mArgumentWidgetA64 = new CPUArgumentWidgetA64(this);
  mArgumentWidgetA32 = new CPUArgumentWidgetA32(this);
  mArgumentWidgetX64 = new CPUArgumentWidgetX64(this);
  mArgumentWidgetX86 = new CPUArgumentWidgetX86(this);
  mArgumentArea = new QScrollArea(this);
  mArgumentArea->setFrameShape(QFrame::NoFrame);
  activeArgument(mArgumentWidgetA64);

  mGraph = new DisassemblerGraphView(nullptr);
  mExecMap = new DialogExecMap(mGraph, this);
  Qt::WindowFlags flags = mExecMap->windowFlags();
  mExecMap->setWindowFlags(flags |
                           Qt::WindowStaysOnTopHint |
                           Qt::WindowMinMaxButtonsHint |
                           Qt::WindowCloseButtonHint);
  mExecMap->hide();

  connect(mDisas, SIGNAL(tableOffsetChanged(dsint)), mSideBar,
          SLOT(changeTopmostAddress(dsint)));
  connect(mDisas, SIGNAL(viewableRowsChanged(int)), mSideBar,
          SLOT(setViewableRows(int)));
  connect(mDisas, SIGNAL(selectionChanged(dsint)), mSideBar,
          SLOT(setSelection(dsint)));
  connect(mGraph, SIGNAL(detachGraph()), this, SLOT(detachGraph()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), mSideBar,
          SLOT(debugStateChangedSlot(DBGSTATE)));
  connect(Bridge::getBridge(), SIGNAL(updateSideBar()), mSideBar,
          SLOT(reload()));
  connect(Bridge::getBridge(), SIGNAL(updateArgumentView()), mArgumentWidgetA64,
          SLOT(refreshData()));
  connect(Bridge::getBridge(), SIGNAL(updateArgumentView()), mArgumentWidgetA32,
          SLOT(refreshData()));
  connect(Bridge::getBridge(), SIGNAL(updateArgumentView()), mArgumentWidgetX64,
          SLOT(refreshData()));
  connect(Bridge::getBridge(), SIGNAL(updateArgumentView()), mArgumentWidgetX86,
          SLOT(refreshData()));
  // connect(Bridge::getBridge(), SIGNAL(focusDisasm()), this,
  //        SLOT(setDisasmFocus()));
  connect(Bridge::getBridge(), SIGNAL(focusGraph()), this,
          SLOT(setGraphFocus()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(debugStateChangedSlot(DBGSTATE)));

  mDisas->setCodeFoldingManager(mSideBar->getCodeFoldingManager());

  ui->mTopLeftUpperHSplitter->setCollapsible(
      0, true);  // allow collapsing of the side bar

  ui->mTopLeftUpperLeftFrameLayout->addWidget(mSideBar);
  ui->mTopLeftUpperRightFrameLayout->addWidget(mDisas);
  // ui->mTopLeftUpperRightFrameLayout->addWidget(mGraph);
  // mGraph->hide();
  disasMode = 2;
  mGraphWindow = nullptr;

  ui->mTopLeftVSplitter->setCollapsible(
      1, true);  // allow collapsing of the InfoBox
  connect(ui->mTopLeftVSplitter, SIGNAL(splitterMoved(int, int)), this,
          SLOT(splitterMoved(int, int)));

  mInfo = new CPUInfoBox();
  ui->mTopLeftLowerFrameLayout->addWidget(mInfo);
  int height = mInfo->getHeight();
  ui->mTopLeftLowerFrame->setMinimumHeight(height + 2);

  connect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
          SLOT(disasmSelectionChanged(dsint)));

  mDump = new CPUMultiDump(mDisas, 3, 0);  // dump widget
  ui->mBotLeftFrameLayout->addWidget(mDump);

  mGeneralRegsA64 = new CPURegistersViewA64(this);
  mGeneralRegsA64->setFixedWidth(1000);
  mGeneralRegsA64->ShowFPU(true);

  mGeneralRegsA32 = new CPURegistersViewA32(this);
  mGeneralRegsA32->setFixedWidth(1000);
  mGeneralRegsA32->ShowFPU(true);

  mGeneralRegsX64 = new CPURegistersViewX64(this);
  mGeneralRegsX64->setFixedWidth(1000);
  mGeneralRegsX64->ShowFPU(true);

  mGeneralRegsX86 = new CPURegistersViewX86(this);
  mGeneralRegsX86->setFixedWidth(1000);
  mGeneralRegsX86->ShowFPU(true);

  mGeneralRegsArea = new QScrollArea(this);
  mGeneralRegsArea->setFrameShape(QFrame::NoFrame);
  activeRegister(mGeneralRegsA64);

  QPushButton* button_changeview = new QPushButton("", this);
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsA64,
          SLOT(onChangeFPUViewAction()));
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsA32,
          SLOT(onChangeFPUViewAction()));
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsX64,
          SLOT(onChangeFPUViewAction()));
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsX86,
          SLOT(onChangeFPUViewAction()));
  mGeneralRegsA64->SetChangeButton(button_changeview);
  mGeneralRegsA32->SetChangeButton(button_changeview);
  mGeneralRegsX64->SetChangeButton(button_changeview);
  mGeneralRegsX86->SetChangeButton(button_changeview);

  ui->mTopRightVSplitter->setCollapsible(
      1, true);  // allow collapsing of the ArgumentWidget
  connect(ui->mTopRightVSplitter, SIGNAL(splitterMoved(int, int)), this,
          SLOT(splitterMoved(int, int)));

  ui->mTopRightUpperFrameLayout->addWidget(button_changeview);
  ui->mTopRightUpperFrameLayout->addWidget(mGeneralRegsArea);
  ui->mTopRightLowerFrameLayout->addWidget(mArgumentArea);

  mStack = new CPUStack(mDump, 0);  // stack widget
  ui->mBotRightFrameLayout->addWidget(mStack);

  // load column config
  mDisas->loadColumnFromConfig("CPUDisassembly");
  mStack->loadColumnFromConfig("CPUStack");
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

void CPUWidget::saveWindowSettings() {
  saveSplitter(ui->mVSplitter, "mVSplitter");
  saveSplitter(ui->mTopHSplitter, "mTopHSplitter");
  saveSplitter(ui->mTopLeftVSplitter, "mTopLeftVSplitter");
  saveSplitter(ui->mTopLeftUpperHSplitter, "mTopLeftUpperHSplitter");
  saveSplitter(ui->mTopRightVSplitter, "mTopRightVSplitter");
  saveSplitter(ui->mBotHSplitter, "mBotHSplitter");
}

void CPUWidget::loadWindowSettings() {
  loadSplitter(ui->mVSplitter, "mVSplitter");
  loadSplitter(ui->mTopHSplitter, "mTopHSplitter");
  loadSplitter(ui->mTopLeftVSplitter, "mTopLeftVSplitter");
  loadSplitter(ui->mTopLeftUpperHSplitter, "mTopLeftUpperHSplitter");
  loadSplitter(ui->mTopRightVSplitter, "mTopRightVSplitter");
  loadSplitter(ui->mBotHSplitter, "mBotHSplitter");
}

CPUWidget::~CPUWidget() {
  delete mGraphWindow;
  delete mExecMap;
  delete ui;
}

void CPUWidget::setDefaultDisposition() {
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

void CPUWidget::setDisasmFocus() {
  if (disasMode == 1) {
    mGraph->hide();
    mDisas->show();
    mSideBar->show();
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

void CPUWidget::setGraphFocus() {
  if (disasMode == 0) {
    mDisas->hide();
    mSideBar->hide();
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
}

void CPUWidget::detachGraph() {
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
    int w = 640;
    int h = 480;
    int x = (screenGeometry.width() - w) / 2;
    int y = (screenGeometry.height() - h) / 2;
    mGraphWindow->showNormal();
    mGraphWindow->setGeometry(x, y, w, h);
    mGraphWindow->showNormal();

    disasMode = 2;

    mDisas->show();
    mSideBar->show();
    connect(mDisas, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
    connect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
            SLOT(disasmSelectionChanged(dsint)));
  }
}

void CPUWidget::attachGraph(QWidget* widget) {
  mGraph->setParent(this);
  ui->mTopLeftUpperRightFrameLayout->addWidget(mGraph);
  mGraph->hide();
  mGraphWindow->close();
  disconnect(mGraph, SIGNAL(selectionChanged(dsint)), mInfo,
             SLOT(disasmSelectionChanged(dsint)));
  delete mGraphWindow;
  mGraphWindow = nullptr;
  disasMode = 0;
}

// This is used in run to selection
duint CPUWidget::getSelectionVa() {
  if (disasMode < 2)
    return disasMode == 0 ? mDisas->getSelectedVa() : mGraph->get_cursor_pos();
  else
    return !mGraph->hasFocus() ? mDisas->getSelectedVa()
                               : mGraph->get_cursor_pos();
}

CPUSideBar* CPUWidget::getSidebarWidget() { return mSideBar; }

CPUDisassembly* CPUWidget::getDisasmWidget() { return mDisas; }

DisassemblerGraphView* CPUWidget::getGraphWidget() { return mGraph; }

CPUMultiDump* CPUWidget::getDumpWidget() { return mDump; }

CPUInfoBox* CPUWidget::getInfoBoxWidget() { return mInfo; }

CPUStack* CPUWidget::getStackWidget() { return mStack; }

void CPUWidget::splitterMoved(int pos, int index) {
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

void CPUWidget::debugStateChangedSlot(DBGSTATE state) {
  if (state == initialized) {
    switch (DbgGlobal::inst()->currentArch()) {
    case mana::ARM:
      activeRegister(mGeneralRegsA32);
      activeArgument(mArgumentWidgetA32);
      break;
    case mana::ARM64:
      activeRegister(mGeneralRegsA64);
      activeArgument(mArgumentWidgetA64);
      break;
    case mana::X86:
      activeRegister(mGeneralRegsX86);
      activeArgument(mArgumentWidgetX86);
      break;
    case mana::X86_64:
      activeRegister(mGeneralRegsX64);
      activeArgument(mArgumentWidgetX64);
      break;
    }
    return;
  }
  if (state == stopped) {
    DbgGlobal::inst()->clearAll();
    GuiSymbolUpdateModuleList(0, nullptr);
    GuiUpdateAllViews();
    return;
  }
}

void CPUWidget::activeRegister(QScrollArea *regview) {
  QScrollArea *views[] = {
    mGeneralRegsA32, mGeneralRegsA64,
    mGeneralRegsX86, mGeneralRegsX64,
  };
  for (size_t i = 0; i < sizeof(views) / sizeof(views[0]); i++) {
    if (views[i] == regview) {
      views[i]->setEnabled(true);
      views[i]->show();
      mGeneralRegsArea->takeWidget();
      mGeneralRegsArea->setWidget(views[i]);
    }
    else {
      views[i]->setEnabled(false);
      views[i]->hide();
    }
  }
}

void CPUWidget::activeArgument(CPUArgumentWidget *argview) {
  CPUArgumentWidget *views[] = {
    mArgumentWidgetA32, mArgumentWidgetA64,
    mArgumentWidgetX86, mArgumentWidgetX64,
  };
  for (size_t i = 0; i < sizeof(views) / sizeof(views[0]); i++) {
    if (views[i] == argview) {
      views[i]->setEnabled(true);
      views[i]->show();
      mArgumentArea->takeWidget();
      mArgumentArea->setWidget(views[i]);
    }
    else {
      views[i]->setEnabled(false);
      views[i]->hide();
    }
  }
}

void CPUWidget::showExecMap() {
  mExecMap->syncToPC();
  mExecMap->showNormal();
}

void CPUWidget::hideExecMap() {
  mExecMap->hide();
}
