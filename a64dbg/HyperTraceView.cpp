#include "HyperTraceView.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
#include <QVBoxLayout>

#include "Bridge.h"
#include "BrowseDialog.h"
#include "Configuration.h"
#include "StdSearchListView.h"
#include "HyperTraceSymbolTable.h"
#include "HyperTraceManager.h"
#include "LogView.h"

#define QTextEdit LogView
#include "ui_HyperTraceView.h"

extern LLDBEngine *lldb;
HyperTraceView *hypertraceView;

enum {
  ColBase = 0,
  ColModule,
  ColParty,
  ColPath,
};

class HyperTraceModuleStdTable final : public StdTable {
 public:
  HyperTraceModuleStdTable() { Initialize(); }

  void updateColors() override {
    StdTable::updateColors();
    mSymbolUnloadedTextColor = ConfigColor("SymbolUnloadedTextColor");
    mSymbolLoadingTextColor = ConfigColor("SymbolLoadingTextColor");
    mSymbolLoadedTextColor = ConfigColor("SymbolLoadedTextColor");
    mSymbolUserTextColor = ConfigColor("SymbolUserTextColor");
    mSymbolSystemTextColor = ConfigColor("SymbolSystemTextColor");
  }

  QColor getCellColor(int r, int c) override {
    if (c == ColParty || c == ColPath) {
      if (DbgFunctions()->ModGetParty(getCellUserdata(r, ColBase)) !=
          mod_system)
        return mSymbolUserTextColor;
      else
        return mSymbolSystemTextColor;
    }
    return mTextColor;
  }

  QString getCellContent(int r, int c) override {
    return StdTable::getCellContent(r, c);
  }

 private:
  QColor mSymbolSystemTextColor;
  QColor mSymbolUserTextColor;
  QColor mSymbolUnloadedTextColor;
  QColor mSymbolLoadingTextColor;
  QColor mSymbolLoadedTextColor;
};

class HyperTraceSymbolSearchList : public AbstractSearchList {
 public:
  friend class HyperTraceView;

  HyperTraceSymbolSearchList() {
    mList = new HyperTraceSymbolTable();
    mList->setAddressColumn(0);
    mList->setAddressLabel(false);
    mSearchList = new HyperTraceSymbolTable();
    mSearchList->setAddressColumn(0);
    mSearchList->setAddressLabel(false);
  }

  void lock() override {
    mList->mMutex.lock();
    mSearchList->mMutex.lock();
  }

  void unlock() override {
    mSearchList->mMutex.unlock();
    mList->mMutex.unlock();
  }

  AbstractStdTable* list() const override { return mList; }

  AbstractStdTable* searchList() const override { return mSearchList; }

  void filter(const QString& filter, FilterType type,
              int startColumn) override {
    mSearchList->setRowCount(0);
    int newRowCount = 0;
    mSearchList->mData.clear();
    mSearchList->mData.reserve(mList->mData.size());
    int rows = mList->getRowCount();
    for (int i = 0; i < rows; i++) {
      if (rowMatchesFilter(filter, type, i, startColumn)) {
        newRowCount++;
        mSearchList->mData.push_back(mList->mData.at(i));
      }
    }
    mSearchList->setRowCount(newRowCount);
  }

  void addAction(QAction* action) {
    mList->addAction(action);
    mSearchList->addAction(action);
  }

 private:
  HyperTraceSymbolTable* mList;
  HyperTraceSymbolTable* mSearchList;
};

static void hypertraceDatabaseRecv(const hypertrace_database_t *db, int bytes) {
  hypertraceView->mDatabase.push_back(QByteArray());

  auto newdb = hypertraceView->mDatabase.rbegin();
  newdb->resize(bytes);
  memcpy(newdb->data(), db, bytes);
  if (db->type == HTT_SYSCALL) {
    hypertraceView->moduleSelectionChanged(0);
  }
  else {
    hypertraceView->moduleSelectionChanged(-1);
  }
}

HyperTraceView::HyperTraceView(QWidget* parent)
    : QWidget(parent), ui(new Ui::HyperTraceView) {
  hypertraceView = this;
  ui->setupUi(this);
  setAutoFillBackground(false);

  // Set main layout
  mMainLayout = new QVBoxLayout;
  mMainLayout->setContentsMargins(0, 0, 0, 0);
  mMainLayout->addWidget(ui->mainSplitter);
  setLayout(mMainLayout);

  // Create reference view
  mSymbolSearchList = new HyperTraceSymbolSearchList();
  mSymbolList = new SearchListView(this, mSymbolSearchList, true, true);
  mSymbolList->mSearchStartCol = 1;

  // Create module list
  mModuleList = new StdSearchListView(
      this, true, false,
      new StdTableSearchList(new HyperTraceModuleStdTable(), new HyperTraceModuleStdTable()));
  mModuleList->setSearchStartCol(ColBase);
  mModuleList->enableMultiSelection(true);
  mModuleList->setAddressColumn(ColBase, true);
  mModuleList->setDisassemblyPopupEnabled(false);
  int charwidth = mModuleList->getCharWidth();
  mModuleList->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Base"), true);
  mModuleList->addColumnAt(8 + charwidth * 15, tr("Module"), true);
  mModuleList->addColumnAt(8 + charwidth * 8, tr("Party"), true);
  mModuleList->addColumnAt(300, tr("Path"), true);
  mModuleList->loadColumnFromConfig("Module");
  addTraceSpecial();

  mMgrView = new HyperTraceManager(this);

  // Setup list splitter
  ui->listSplitter->addWidget(mMgrView);
  ui->listSplitter->addWidget(mModuleList);
  ui->listSplitter->addWidget(mSymbolList);

  // mModuleList : mSymbolList = 100 : 80
  ui->listSplitter->setStretchFactor(0, 40);
  ui->listSplitter->setStretchFactor(1, 100);
  ui->listSplitter->setStretchFactor(2, 80);

  // Setup log edit
  ui->symbolLogEdit->setFont(ConfigFont("Log"));

  QColor stdbgclr = ConfigColor("AbstractTableViewBackgroundColor");
  ui->symbolLogEdit->setStyleSheet(
      QString("QTextEdit { background-color: rgb(%1, %2, %3) }")
          .arg(stdbgclr.red())
          .arg(stdbgclr.green())
          .arg(stdbgclr.blue()));
  ui->symbolLogEdit->setUndoRedoEnabled(false);
  ui->symbolLogEdit->setReadOnly(true);
  // List : Log = 3 : 4
  ui->mainSplitter->setStretchFactor(0, 3);
  ui->mainSplitter->setStretchFactor(1, 4);

  // setup context menu
  setupContextMenu();

  // Signals and slots
  connect(Bridge::getBridge(), SIGNAL(repaintTableView()), this,
          SLOT(updateStyle()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(debugStateChangedSlot(DBGSTATE)));
  connect(mModuleList->stdList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(moduleSelectionChanged(int)));
  connect(mModuleList->stdSearchList(), SIGNAL(selectionChangedSignal(int)),
          this, SLOT(moduleSelectionChanged(int)));
  connect(mModuleList, SIGNAL(emptySearchResult()), this,
          SLOT(emptySearchResultSlot()));
  connect(mModuleList, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(moduleContextMenu(QMenu*)));
  connect(mModuleList, SIGNAL(enterPressedSignal()), this,
          SLOT(moduleFollow()));
  connect(mSymbolList, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(symbolContextMenu(QMenu*)));
  connect(mSymbolList, SIGNAL(enterPressedSignal()), this,
          SLOT(enterPressedSlot()));
  connect(Config(), SIGNAL(colorsUpdated()), this, SLOT(updateStyle()));
  connect(Config(), SIGNAL(fontsUpdated()), this, SLOT(updateStyle()));

  connect(mSymbolSearchList->list(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(funcSelectionChanged(int)));
  connect(mSymbolSearchList->searchList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(funcSelectionChanged(int)));
}

HyperTraceView::~HyperTraceView() {
  delete ui;
  delete mSymbolSearchList;
}

void HyperTraceView::setupContextMenu() {
  QIcon disassembler = DIcon(ArchValue("processor32.png", "processor-cpu.png"));
  // Symbols
  mDecompileSymbolAction =
      new QAction(DIcon("compile-warning.png"), tr("De&compile"), this);
  connect(mDecompileSymbolAction, SIGNAL(triggered()), this, SLOT(symbolDecompile()));

  mFollowSymbolAction =
      new QAction(disassembler, tr("&Follow in Disassembler"), this);
  connect(mFollowSymbolAction, SIGNAL(triggered()), this, SLOT(symbolFollow()));

  mFollowSymbolDumpAction =
      new QAction(DIcon("dump.png"), tr("Follow in &Dump"), this);
  connect(mFollowSymbolDumpAction, SIGNAL(triggered()), this,
          SLOT(symbolFollowDump()));

  mToggleBreakpoint =
      new QAction(DIcon("breakpoint.png"), tr("Toggle Breakpoint"), this);
  mToggleBreakpoint->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  this->addAction(mToggleBreakpoint);
  mSymbolSearchList->addAction(mToggleBreakpoint);
  connect(mToggleBreakpoint, SIGNAL(triggered()), this,
          SLOT(toggleBreakpoint()));

  mToggleBookmark =
      new QAction(DIcon("bookmark_toggle.png"), tr("Toggle Bookmark"), this);
  mToggleBookmark->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  this->addAction(mToggleBookmark);
  mSymbolSearchList->addAction(mToggleBookmark);
  connect(mToggleBookmark, SIGNAL(triggered()), this, SLOT(toggleBookmark()));

  // Modules
  mFollowModuleAction =
      new QAction(disassembler, tr("&Follow in Disassembler"), this);
  mFollowModuleAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  mFollowModuleAction->setShortcut(QKeySequence("enter"));
  connect(mFollowModuleAction, SIGNAL(triggered()), this, SLOT(moduleFollow()));

  mFollowModuleEntryAction = new QAction(
      disassembler, tr("Follow &Entry Point in Disassembler"), this);
  connect(mFollowModuleEntryAction, SIGNAL(triggered()), this,
          SLOT(moduleEntryFollow()));

  mUnTraceModuleAction = new QAction(
      DIcon("remove_analysis_from_selection.png"), tr("&Untrace Module"), this);
  connect(mUnTraceModuleAction, SIGNAL(triggered()), this,
          SLOT(moduleHyperTraceDel()));

  mCopyPathAction =
      new QAction(DIcon("copyfilepath.png"), tr("Copy File &Path"), this);
  mCopyPathAction->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mCopyPathAction);
  mModuleList->addAction(mCopyPathAction);
  connect(mCopyPathAction, SIGNAL(triggered()), this, SLOT(moduleCopyPath()));

  mPluginMenu = new QMenu(this);
  Bridge::getBridge()->emitMenuAddToList(this, mPluginMenu, GUI_SYMMOD_MENU);

  // Shortcuts
  refreshShortcutsSlot();
  connect(Config(), SIGNAL(shortcutsUpdated()), this,
          SLOT(refreshShortcutsSlot()));
}

void HyperTraceView::refreshShortcutsSlot() {
  mToggleBreakpoint->setShortcut(ConfigShortcut("ActionToggleBreakpoint"));
  mToggleBookmark->setShortcut(ConfigShortcut("ActionToggleBookmark"));
}

void HyperTraceView::updateStyle() {
  mModuleList->stdList()->reloadData();
  mModuleList->stdSearchList()->reloadData();
  ui->symbolLogEdit->setFont(ConfigFont("Log"));
  ui->symbolLogEdit->setStyleSheet(
      QString("QTextEdit { color: %1; background-color: %2 }")
          .arg(ConfigColor("AbstractTableViewTextColor").name(),
               ConfigColor("AbstractTableViewBackgroundColor").name()));
}

void HyperTraceView::debugStateChangedSlot(DBGSTATE state) {
  switch (state) {
  case initialized: {
    lldb->hypertraceInit(hypertraceDatabaseRecv);
    break;
  }
  case stopped: {
    mModuleBaseList.clear();
    clearDatabase();
    addTraceSpecial();
    break;
  }
  default:
    break;
  }
}

void HyperTraceView::clearDatabase() {
  mDatabase.clear();
  ui->symbolLogEdit->clear();
  moduleSelectionChanged(0);
}

void HyperTraceView::addMsgToSymbolLogSlot(const QString &msg) {
  ui->symbolLogEdit->moveCursor(QTextCursor::End);
  ui->symbolLogEdit->insertPlainText(msg);
}

void HyperTraceView::clearSymbolLogSlot() { ui->symbolLogEdit->clear(); }

void HyperTraceView::moduleSelectionChanged(int index) {
  setUpdatesEnabled(false);
  if (index < 0) {
    index = mModuleList->mCurList->getRowCount() - 1;
  }

  QString module = mModuleList->mCurList->getCellContent(index, ColModule);

  std::vector<HyperTraceSymbol> data;
  if (module == "$objc") {
    mSymbolSearchList->mList->mType = HTT_OBJC;
  }
  else if (module == "$http2") {
    mSymbolSearchList->mList->mType = HTT_HTTP2;
  }
  else if (module == "$syscall") {
    mSymbolSearchList->mList->mType = HTT_SYSCALL;
    for (auto &d : mDatabase) {
      auto db = (hypertrace_database_t *)d.data();
      if (db->type == HTT_SYSCALL) {
        for (unsigned int i = 0; i < db->count; i++) {
          data.push_back({(char *)db, &db->items[i], nullptr, nullptr});
        }
      }
    }
  }
  else {
    mSymbolSearchList->mList->mType = HTT_FUNCTION;
    QString strbase = mModuleList->mCurList->getCellContent(index, ColBase);
    duint base = DbgValFromString(strbase.toUtf8().data());
    for (auto &m : lldb->moduleList()) {
      if (base == m.startAddress) {
        for (auto &d : mDatabase) {
          auto db = (hypertrace_database_t *)d.data();
          if (db->type == HTT_FUNCTION) {
            for (unsigned int i = 0; i < db->count; i++) {
              auto addr = db->items[i].key;
              if (base < addr && addr < m.endAddress) {
                auto manadb = DbgGlobal::inst()->getModule(m.modulePath.data(), &m);
                if (!manadb) {
                  break;
                }
                for (int f = 0; f < manadb->db->nfunc; f++) {
                  auto fn = manadb->db->func(f);
                  if (addr == base + fn->rvastart) {
                    data.push_back({(char *)db, &db->items[i], manadb->db, fn});
                    break;
                  }
                }
              }
            }
          }
        }
        break;
      }
    }
  }

  mSymbolSearchList->lock();
  mSymbolSearchList->mSearchList->mType = mSymbolSearchList->mList->mType;
  mSymbolSearchList->mList->mData = std::move(data);
  mSymbolSearchList->mList->setRowCount(mSymbolSearchList->mList->mData.size());
  mSymbolSearchList->unlock();
  mSymbolSearchList->mList->setSingleSelection(0);
  mSymbolSearchList->mList->setTableOffset(0);
  mSymbolSearchList->mList->reloadData();
  if (!mSymbolList->isSearchBoxLocked())
    mSymbolList->clearFilter();
  else
    mSymbolList->refreshSearchList();

  setUpdatesEnabled(true);
}

void HyperTraceView::addTraceModule(const SYMBOLMODULEINFO &module) {
  QString modName(module.name);
  if (mModuleBaseList.find(modName) != mModuleBaseList.end()) {
    return;
  }

  auto stdlist = mModuleList->stdList();
  int i = stdlist->getRowCount();
  stdlist->setRowCount(i + 1);
  duint base = module.base;
  mModuleBaseList.insert(modName, base);
  int party = DbgFunctions()->ModGetParty(base);
  stdlist->setCellContent(i, ColBase, ToPtrString(base));
  stdlist->setCellUserdata(i, ColBase, base);
  stdlist->setCellContent(i, ColModule, modName);
  switch (party) {
    case 0:
      stdlist->setCellContent(i, ColParty, tr("User"));
      break;
    case 1:
      stdlist->setCellContent(i, ColParty, tr("System"));
      break;
    default:
      stdlist->setCellContent(i, ColParty, tr("Party: %1").arg(party));
      break;
  }
  char szModPath[MAX_PATH] = "";
  if (!DbgFunctions()->ModPathFromAddr(base, szModPath, _countof(szModPath)))
    *szModPath = '\0';
  stdlist->setCellContent(i, ColPath, szModPath);
  stdlist->reloadData();
}

void HyperTraceView::addTraceSpecial() {
  static const char *names[] = {
    "$syscall",
  };
  static const char *parties[] = {
    "System",
  };
  static const char *paths[] = {
    "Android AArch64 Syscall",
  };
  auto stdlist = mModuleList->stdList();
  stdlist->setRowCount(sizeof(names) / sizeof(names[0]));
  for (size_t i = 0; i < stdlist->getRowCount(); i++) {
    mModuleBaseList.insert(names[i], 0);
    stdlist->setCellContent(i, ColBase, ToPtrString(0));
    stdlist->setCellUserdata(i, ColBase, 0);
    stdlist->setCellContent(i, ColModule, names[i]);
    stdlist->setCellContent(i, ColParty, parties[i]);
    stdlist->setCellContent(i, ColPath, paths[i]);
  }
  stdlist->reloadData();
}

void HyperTraceView::symbolContextMenu(QMenu* wMenu) {
  if (!mSymbolList->mCurList->getRowCount()) return;
  wMenu->addAction(mDecompileSymbolAction);
  wMenu->addAction(mFollowSymbolAction);
  wMenu->addAction(mFollowSymbolDumpAction);
  if (mSymbolList->mCurList->getCellContent(
          mSymbolList->mCurList->getInitialSelection(), 1) == tr("Import"))
    wMenu->addAction(mFollowSymbolImportAction);
  wMenu->addSeparator();
  wMenu->addAction(mToggleBreakpoint);
  wMenu->addAction(mToggleBookmark);
}

void HyperTraceView::symbolRefreshCurrent() {
  mModuleList->stdList()->setSingleSelection(
      mModuleList->stdList()->getInitialSelection());
}

void HyperTraceView::symbolDecompile() {
  DbgCmdExec(QString("decompile " +
                     mSymbolList->mCurList->getCellContent(
                         mSymbolList->mCurList->getInitialSelection(), 0)));
}

void HyperTraceView::symbolFollow() {
  DbgCmdExec(QString("disasm " +
                     mSymbolList->mCurList->getCellContent(
                         mSymbolList->mCurList->getInitialSelection(), 0)));
}

void HyperTraceView::symbolFollowDump() {
  DbgCmdExecDirect(
      QString("dump " + mSymbolList->mCurList->getCellContent(
                            mSymbolList->mCurList->getInitialSelection(), 0)));
}

void HyperTraceView::symbolFollowImport() {
  auto addrText = mSymbolList->mCurList->getCellContent(
      mSymbolList->mCurList->getInitialSelection(), 0);
  auto addr =
      DbgValFromString(QString("[%1]").arg(addrText).toUtf8().constData());
  if (!DbgMemIsValidReadPtr(addr)) return;
  if (DbgFunctions()->MemIsCodePage(addr, false)) {
    DbgCmdExec(QString("disasm %1").arg(ToPtrString(addr)));
  } else {
    DbgCmdExecDirect(QString("dump %1").arg(ToPtrString(addr)));
    emit Bridge::getBridge()->getDumpAttention();
  }
}

void HyperTraceView::symbolSelectModule(duint base) {
  for (dsint i = 0; i < mModuleList->stdList()->getRowCount(); i++) {
    if (mModuleList->stdList()->getCellUserdata(i, ColBase) == base) {
      mModuleList->stdList()->setSingleSelection(i);
      mModuleList->stdSearchList()
          ->hide();  // This could be described as a hack, but you could also
                     // say it's like wiping sandpaper over your new white
                     // Tesla.
      mModuleList->clearFilter();
      break;
    }
  }
}

void HyperTraceView::enterPressedSlot() {
  auto addr = DbgValFromString(
      mSymbolList->mCurList
          ->getCellContent(mSymbolList->mCurList->getInitialSelection(), 0)
          .toUtf8()
          .constData());
  if (!DbgMemIsValidReadPtr(addr)) return;
  if (mSymbolList->mCurList->getCellContent(
          mSymbolList->mCurList->getInitialSelection(), 1) == tr("Import"))
    symbolFollowImport();
  else if (DbgFunctions()->MemIsCodePage(addr, false))
    symbolFollow();
  else {
    symbolFollowDump();
    emit Bridge::getBridge()->getDumpAttention();
  }
}

void HyperTraceView::moduleContextMenu(QMenu* wMenu) {
  if (!DbgIsDebugging() || !mModuleList->mCurList->getRowCount()) return;

  wMenu->addAction(mFollowModuleAction);
  wMenu->addAction(mFollowModuleEntryAction);
  // wMenu->addAction(mFollowInMemMap);
  // wMenu->addAction(mDownloadSymbolsAction);
  // wMenu->addAction(mDownloadAllSymbolsAction);
  duint modbase = DbgValFromString(
      mModuleList->mCurList
          ->getCellContent(mModuleList->mCurList->getInitialSelection(),
                           ColBase)
          .toUtf8()
          .constData());
  char szModPath[MAX_PATH] = "";
  if (DbgFunctions()->ModPathFromAddr(modbase, szModPath,
                                      _countof(szModPath))) {
    wMenu->addAction(mCopyPathAction);
  }
  wMenu->addSeparator();
  QMenu wCopyMenu(tr("&Copy"), this);
  wCopyMenu.setIcon(DIcon("copy.png"));
  mModuleList->mCurList->setupCopyMenu(&wCopyMenu);
  if (wCopyMenu.actions().length()) {
    wMenu->addSeparator();
    wMenu->addMenu(&wCopyMenu);
  }
  wMenu->addSeparator();
  wMenu->addAction(mUnTraceModuleAction);
  wMenu->addSeparator();
  DbgMenuPrepare(GUI_SYMMOD_MENU);
  wMenu->addActions(mPluginMenu->actions());
}

void HyperTraceView::moduleFollow() {
  DbgCmdExec(
      QString("disasm " +
              mModuleList->mCurList->getCellContent(
                  mModuleList->mCurList->getInitialSelection(), ColBase) +
              "+1000"));
}

void HyperTraceView::moduleEntryFollow() {
  DbgCmdExec(
      QString("disasm " +
              mModuleList->mCurList->getCellContent(
                  mModuleList->mCurList->getInitialSelection(), ColBase) +
              ":entry"));
}

void HyperTraceView::moduleCopyPath() {
  duint modbase = DbgValFromString(
      mModuleList->mCurList
          ->getCellContent(mModuleList->mCurList->getInitialSelection(),
                           ColBase)
          .toUtf8()
          .constData());
  char szModPath[MAX_PATH] = "";
  szModPath[0] = 'l'; // indicate local path
  if (DbgFunctions()->ModPathFromAddr(modbase, szModPath, _countof(szModPath)))
    Bridge::CopyToClipboard(szModPath);
}

void HyperTraceView::moduleHyperTraceDel() {
  QString modName = mModuleList->mCurList->getCellContent(
        mModuleList->mCurList->getInitialSelection(), ColModule);
  if (modName[0] == '$') {
    // syscall, etc.
    return;
  }
  auto found = mModuleBaseList.find(modName);
  if (found == mModuleBaseList.end()) {
    return;
  }
  mModuleBaseList.erase(found);

  auto stdlist = mModuleList->stdList();
  stdlist->setRowCount(mModuleBaseList.size());
  int i = 0;
  for (auto it = mModuleBaseList.begin(), end = mModuleBaseList.end(); it != end; it++, i++) {
    duint base = it.value();
    if (!base) continue; // special case
    int party = DbgFunctions()->ModGetParty(base);
    stdlist->setCellContent(i, ColBase, ToPtrString(base));
    stdlist->setCellUserdata(i, ColBase, base);
    stdlist->setCellContent(i, ColModule, it.key());
    switch (party) {
      case 0:
        stdlist->setCellContent(i, ColParty, tr("User"));
        break;
      case 1:
        stdlist->setCellContent(i, ColParty, tr("System"));
        break;
      default:
        stdlist->setCellContent(i, ColParty, tr("Party: %1").arg(party));
        break;
    }
    char szModPath[MAX_PATH] = "";
    if (!DbgFunctions()->ModPathFromAddr(base, szModPath, _countof(szModPath)))
      *szModPath = '\0';
    stdlist->setCellContent(i, ColPath, szModPath);
  }
  stdlist->reloadData();

  DbgCmdExec(QString("modhypertracedel %0").arg(modName));
}

void HyperTraceView::toggleBreakpoint() {
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

void HyperTraceView::toggleBookmark() {
  if (!DbgIsDebugging()) return;
  if (!mSymbolList->mCurList->getRowCount()) return;
  QString addrText = mSymbolList->mCurList->getCellContent(
      mSymbolList->mCurList->getInitialSelection(), 0);
  duint wVA;
  if (!DbgFunctions()->ValFromString(addrText.toUtf8().constData(), &wVA))
    return;
  if (!DbgMemIsValidReadPtr(wVA)) return;

  bool result;
  if (DbgGetBookmarkAt(nullptr, wVA))
    result = DbgSetBookmarkAt(nullptr, wVA, false);
  else
    result = DbgSetBookmarkAt(nullptr, wVA, true);
  if (!result) {
    QMessageBox msg(QMessageBox::Critical, tr("Error!"),
                    tr("DbgSetBookmarkAt failed!"));
    msg.setWindowIcon(DIcon("compile-error.png"));
    msg.setParent(this, Qt::Dialog);
    msg.setWindowFlags(msg.windowFlags() & (~Qt::WindowContextHelpButtonHint));
    msg.exec();
  }
  GuiUpdateAllViews();
}

void HyperTraceView::emptySearchResultSlot() {
  // No result after search
  mSymbolList->mCurList->setRowCount(0);
}

void HyperTraceView::selectionGetSlot(SELECTIONDATA* selection) {
  selection->start = selection->end =
      duint(mModuleList->mCurList
                ->getCellContent(mModuleList->mCurList->getInitialSelection(),
                                 ColBase)
                .toULongLong(nullptr, 16));
  Bridge::getBridge()->setResult(BridgeResult::SelectionGet, 1);
}

void HyperTraceView::funcSelectionChanged(int index) {
  if (!DbgIsDebugging()) return;

  HyperTraceSymbolTable* table = (HyperTraceSymbolTable *)(
      sender() == mSymbolSearchList->list() ? mSymbolSearchList->list() : mSymbolSearchList->searchList());
  if (index >= table->mData.size()) return;

  char *buff = table->mData[index].database;
  const hypertrace_item_t *item = table->mData[index].item;
  switch (table->mType) {
  case HTT_FUNCTION:
  case HTT_SYSCALL: {
    auto callinfos = (const hypertrace_callinfo_t *)(buff + item->detailoff);
    QString retinfo("return.to");
    for (auto &m : lldb->moduleList()) {
      if (m.startAddress < callinfos->retaddr && callinfos->retaddr < m.endAddress) {
        retinfo = m.moduleName.data();
        break;
      }
    }
    addMsgToSymbolLogSlot(QString("Total hits %1 %2 times %3 contexts.\n")
                          .arg(ToPtrString(item->key)).arg(item->hits).arg(item->detailcount));
    for (unsigned int i = 0; i < item->detailcount; i++, callinfos++) {
      addMsgToSymbolLogSlot(QString("%11.%1 : arg(%2, %3, %4, %5, %6, %7, %8, %9) [%10]\n")
          .arg(ToPtrString(callinfos->retaddr))
          .arg(ToPtrString(callinfos->args[0]))
          .arg(ToPtrString(callinfos->args[1]))
          .arg(ToPtrString(callinfos->args[2]))
          .arg(ToPtrString(callinfos->args[3]))
          .arg(ToPtrString(callinfos->args[4]))
          .arg(ToPtrString(callinfos->args[5]))
          .arg(ToPtrString(callinfos->args[6]))
          .arg(ToPtrString(callinfos->args[7]))
          .arg(i).arg(retinfo));
    }
    break;
  }
  default:
    break;
  }
}
