#include "VMPSymbolView.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
#include <QVBoxLayout>

#include "Bridge.h"
#include "BrowseDialog.h"
#include "Configuration.h"
#include "StdSearchListView.h"
#include "VMPBridgeMain.h"
#include "VMPGlobal.h"
#include "ZehSymbolTable.h"
#include "ui_VMPSymbolView.h"

enum {
  ColBase = 0,
  ColModule,
  ColPath,
};

class ModuleStdTable final : public StdTable {
 public:
  ModuleStdTable() { Initialize(); }

  void updateColors() override {
    StdTable::updateColors();
    mSymbolUnloadedTextColor = ConfigColor("SymbolUnloadedTextColor");
    mSymbolLoadingTextColor = ConfigColor("SymbolLoadingTextColor");
    mSymbolLoadedTextColor = ConfigColor("SymbolLoadedTextColor");
    mSymbolUserTextColor = ConfigColor("SymbolUserTextColor");
    mSymbolSystemTextColor = ConfigColor("SymbolSystemTextColor");
  }

  QColor getCellColor(int r, int c) override {
    if (c == ColPath) {
      if (DbgFunctions()->ModGetParty(getCellUserdata(r, ColBase)) !=
          mod_system)
        return mSymbolUserTextColor;
      else
        return mSymbolSystemTextColor;
    }
    if (c != ColModule) return mTextColor;
    switch (getStatus(r)) {
      default:
      case MODSYMUNLOADED:
        return mSymbolUnloadedTextColor;
      case MODSYMLOADING:
        return mSymbolLoadingTextColor;
      case MODSYMLOADED:
        return mSymbolLoadedTextColor;
    }
  }

  QString getCellContent(int r, int c) override {
    return StdTable::getCellContent(r, c);
  }

 private:
  MODULESYMBOLSTATUS getStatus(int r) {
    return DbgFunctions()->ModSymbolStatus(getCellUserdata(r, 0));
  }

  QColor mSymbolSystemTextColor;
  QColor mSymbolUserTextColor;
  QColor mSymbolUnloadedTextColor;
  QColor mSymbolLoadingTextColor;
  QColor mSymbolLoadedTextColor;
};

class SymbolSearchList : public AbstractSearchList {
 public:
  friend class VMPSymbolView;

  SymbolSearchList() {
    mList = new ZehSymbolTable();
    mList->setAddressColumn(0);
    mList->setAddressLabel(false);
    mSearchList = new ZehSymbolTable();
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

  AbstractStdTable *list() const override { return mList; }

  AbstractStdTable *searchList() const override { return mSearchList; }

  void filter(const QString &filter, FilterType type,
              int startColumn) override {
    mSearchList->setRowCount(0);
    int newRowCount = 0;
    mSearchList->mData.clear();
    mSearchList->mData.reserve(mList->mData.size());
    mSearchList->mModules = mList->mModules;
    int rows = mList->getRowCount();
    for (int i = 0; i < rows; i++) {
      if (rowMatchesFilter(filter, type, i, startColumn)) {
        newRowCount++;
        mSearchList->mData.push_back(mList->mData.at(i));
      }
    }
    mSearchList->setRowCount(newRowCount);
  }

  void addAction(QAction *action) {
    mList->addAction(action);
    mSearchList->addAction(action);
  }

 private:
  ZehSymbolTable *mList;
  ZehSymbolTable *mSearchList;
};

VMPSymbolView::VMPSymbolView(QWidget *parent)
    : QWidget(parent), ui(new Ui::VMPSymbolView) {
  ui->setupUi(this);
  setAutoFillBackground(false);

  // Set main layout
  mMainLayout = new QVBoxLayout;
  mMainLayout->setContentsMargins(0, 0, 0, 0);
  mMainLayout->addWidget(ui->mainSplitter);
  setLayout(mMainLayout);

  // Create reference view
  mSymbolSearchList = new SymbolSearchList();
  mSymbolList = new SearchListView(this, mSymbolSearchList, true, true);
  mSymbolList->mSearchStartCol = 1;

  // Create module list
  mModuleList = new StdSearchListView(
      this, true, false,
      new StdTableSearchList(new ModuleStdTable(), new ModuleStdTable()));
  mModuleList->setSearchStartCol(ColBase);
  mModuleList->enableMultiSelection(true);
  mModuleList->setAddressColumn(ColBase, true);
  mModuleList->setDisassemblyPopupEnabled(false);
  int charwidth = mModuleList->getCharWidth();
  mModuleList->addColumnAt(8 + charwidth * 2 * sizeof(dsint), tr("Base"), true);
  mModuleList->addColumnAt(300, tr("Module"), true);
  mModuleList->addColumnAt(8 + charwidth * 60, tr("Path"), true);

  // Setup list splitter
  ui->listSplitter->addWidget(mModuleList);
  ui->listSplitter->addWidget(mSymbolList);
#ifdef _WIN64
  // mModuleList : mSymbolList = 40 : 100
  ui->listSplitter->setStretchFactor(0, 40);
  ui->listSplitter->setStretchFactor(1, 100);
#else
  // mModuleList : mSymbolList = 30 : 100
  ui->listSplitter->setStretchFactor(0, 30);
  ui->listSplitter->setStretchFactor(1, 100);
#endif  //_WIN64

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
  // Log : List = 2 : 9
  ui->mainSplitter->setStretchFactor(1, 9);
  ui->mainSplitter->setStretchFactor(0, 2);

  // setup context menu
  setupContextMenu();

  // Signals and slots
  connect(Bridge::getBridge(), SIGNAL(repaintTableView()), this,
          SLOT(updateStyle()));
  connect(Bridge::getBridge(), SIGNAL(addMsgToSymbolLog(QString)), this,
          SLOT(addMsgToSymbolLogSlot(QString)));
  connect(Bridge::getBridge(), SIGNAL(clearLog()), this,
          SLOT(clearSymbolLogSlot()));
  connect(Bridge::getBridge(), SIGNAL(clearSymbolLog()), this,
          SLOT(clearSymbolLogSlot()));
  connect(Bridge::getBridge(), SIGNAL(selectionSymmodGet(SELECTIONDATA *)),
          this, SLOT(selectionGetSlot(SELECTIONDATA *)));
  connect(mModuleList->stdList(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(moduleSelectionChanged(int)));
  connect(mModuleList->stdSearchList(), SIGNAL(selectionChangedSignal(int)),
          this, SLOT(moduleSelectionChanged(int)));
  connect(mModuleList, SIGNAL(emptySearchResult()), this,
          SLOT(emptySearchResultSlot()));
  connect(mModuleList, SIGNAL(listContextMenuSignal(QMenu *)), this,
          SLOT(moduleContextMenu(QMenu *)));
  connect(Bridge::getBridge(), SIGNAL(setSymbolProgress(int)),
          ui->symbolProgress, SLOT(setValue(int)));
  connect(Bridge::getBridge(), SIGNAL(symbolSelectModule(duint)), this,
          SLOT(symbolSelectModule(duint)));
  connect(mSymbolList, SIGNAL(listContextMenuSignal(QMenu *)), this,
          SLOT(symbolContextMenu(QMenu *)));
  connect(Config(), SIGNAL(colorsUpdated()), this, SLOT(updateStyle()));
  connect(Config(), SIGNAL(fontsUpdated()), this, SLOT(updateStyle()));

  connect(mSymbolSearchList->list(), SIGNAL(selectionChangedSignal(int)), this,
          SLOT(funcSelectionChanged(int)));
  connect(mSymbolSearchList->searchList(), SIGNAL(selectionChangedSignal(int)),
          this, SLOT(funcSelectionChanged(int)));

  connect(&mVMPProcess, SIGNAL(readyReadStandardOutput()), this,
          SLOT(onReadProcessOutputData()));
  connect(&mVMPProcess, SIGNAL(readyReadStandardError()), this,
          SLOT(onReadProcessErrorData()));
  connect(&mVMPProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this,
          SLOT(onProcessFinished(int, QProcess::ExitStatus)));
  mVMPProcess.setReadChannelMode(QProcess::MergedChannels);
}

VMPSymbolView::~VMPSymbolView() {
  delete ui;
  delete mSymbolSearchList;
}

inline void saveSymbolsSplitter(QSplitter *splitter, QString name) {
  BridgeSettingSet("SymbolsSettings", (name + "Geometry").toUtf8().constData(),
                   splitter->saveGeometry().toBase64().data());
  BridgeSettingSet("SymbolsSettings", (name + "State").toUtf8().constData(),
                   splitter->saveState().toBase64().data());
}

inline void loadSymbolsSplitter(QSplitter *splitter, QString name) {
  char setting[MAX_SETTING_SIZE] = "";
  if (BridgeSettingGet("SymbolsSettings",
                       (name + "Geometry").toUtf8().constData(), setting))
    splitter->restoreGeometry(QByteArray::fromBase64(QByteArray(setting)));
  if (BridgeSettingGet("SymbolsSettings", (name + "State").toUtf8().constData(),
                       setting))
    splitter->restoreState(QByteArray::fromBase64(QByteArray(setting)));
  splitter->splitterMoved(1, 0);
}

void VMPSymbolView::saveWindowSettings() {
  saveSymbolsSplitter(ui->listSplitter, "mVSymbolsSplitter");
  saveSymbolsSplitter(ui->mainSplitter, "mHSymbolsLogSplitter");
}

void VMPSymbolView::loadWindowSettings() {
  loadSymbolsSplitter(ui->listSplitter, "mVSymbolsSplitter");
  loadSymbolsSplitter(ui->mainSplitter, "mHSymbolsLogSplitter");
}

void VMPSymbolView::setupContextMenu() {
  mToggleVMP =
      new QAction(DIcon("bookmark.png"), tr("Toggle VMP"), this);
  mToggleVMP->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  this->addAction(mToggleVMP);
  mSymbolSearchList->addAction(mToggleVMP);
  connect(mToggleVMP, SIGNAL(triggered()), this, SLOT(toggleVMP()));

  mToggleVMPSels =
      new QAction(DIcon("bookmarks.png"), tr("Toggle VMPs"), this);
  mToggleVMPSels->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  this->addAction(mToggleVMPSels);
  mSymbolSearchList->addAction(mToggleVMPSels);
  connect(mToggleVMPSels, SIGNAL(triggered()), this, SLOT(toggleVMPSels()));

  mAddModule = new QAction(DIcon("lib_load.png"), tr("&Add File"), this);
  mAddModule->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mAddModule);
  mModuleList->addAction(mAddModule);
  connect(mAddModule, SIGNAL(triggered()), this, SLOT(moduleAdd()));

  mAddModuleCfg =
      new QAction(DIcon("load-script.png"), tr("&Load Config"), this);
  mAddModuleCfg->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mAddModuleCfg);
  mModuleList->addAction(mAddModuleCfg);
  connect(mAddModuleCfg, SIGNAL(triggered()), this, SLOT(moduleAddCfg()));

  mDelModule = new QAction(DIcon("lib_free.png"), tr("&Delete File"), this);
  mDelModule->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mDelModule);
  mModuleList->addAction(mDelModule);
  connect(mDelModule, SIGNAL(triggered()), this, SLOT(moduleDelete()));

  mDelModuleAndCfg = new QAction(DIcon("remove_analysis_from_selection.png"),
                                 tr("D&elete Config"), this);
  mDelModuleAndCfg->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mDelModuleAndCfg);
  mModuleList->addAction(mDelModuleAndCfg);
  connect(mDelModuleAndCfg, SIGNAL(triggered()), this,
          SLOT(moduleDeleteAndCfg()));

  mVMPCommit = new QAction(DIcon("compile.png"), tr("&VMP Commit"), this);
  mVMPCommit->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mVMPCommit);
  mModuleList->addAction(mVMPCommit);
  connect(mVMPCommit, SIGNAL(triggered()), this, SLOT(moduleVMPCommit()));

  mVMPCancel = new QAction(DIcon("thread-kill.png"), tr("VMP &Cancel"), this);
  mVMPCancel->setShortcutContext(Qt::WidgetShortcut);
  this->addAction(mVMPCancel);
  mModuleList->addAction(mVMPCancel);
  connect(mVMPCancel, SIGNAL(triggered()), this, SLOT(moduleVMPCancel()));

  mPluginMenu = new QMenu(this);
  Bridge::getBridge()->emitMenuAddToList(this, mPluginMenu, GUI_SYMMOD_MENU);

  // Shortcuts
  refreshShortcutsSlot();
  connect(Config(), SIGNAL(shortcutsUpdated()), this,
          SLOT(refreshShortcutsSlot()));
}

void VMPSymbolView::refreshShortcutsSlot() {
  mToggleVMP->setShortcut(ConfigShortcut("ActionToggleBookmark"));
}

void VMPSymbolView::updateStyle() {
  mModuleList->stdList()->reloadData();
  mModuleList->stdSearchList()->reloadData();
  ui->symbolLogEdit->setFont(ConfigFont("Log"));
  ui->symbolLogEdit->setStyleSheet(
      QString("QTextEdit { color: %1; background-color: %2 }")
          .arg(ConfigColor("AbstractTableViewTextColor").name(),
               ConfigColor("AbstractTableViewBackgroundColor").name()));
}

void VMPSymbolView::addMsgToSymbolLogSlot(QString msg) {
  ui->symbolLogEdit->moveCursor(QTextCursor::End);
  ui->symbolLogEdit->insertPlainText(msg);
}

void VMPSymbolView::clearSymbolLogSlot() { ui->symbolLogEdit->clear(); }

void VMPSymbolView::getSymbolInfo(const SYMBOLPTR *symbolptr,
                                  SYMBOLINFO *info) {
  const FuncInfo *func = (FuncInfo *)symbolptr->symbol;
  info->addr = func->start;
  info->type = sym_symbol;
  info->decoratedSymbol = (char *)func->name.data();
  info->undecoratedSymbol = info->decoratedSymbol;
}

void VMPSymbolView::moduleSelectionChanged(int index) {
  if (index >= mModules.size()) return;
  setUpdatesEnabled(false);

  QString path = mModuleList->mCurList->getCellContent(index, ColPath);
  std::vector<SYMBOLPTR> data;
  auto mit = mModules.find(path);
  for (auto &fn : mit.value().funcs) {
    data.push_back({0, &fn});
  }
  mSymbolSearchList->lock();
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

void VMPSymbolView::updateSymbolList() {
  mCurFunc = nullptr;
  mCurCommit = mModules.end();
  mModuleList->stdList()->setRowCount(mModules.size());
  auto mit = mModules.begin();
  for (int i = 0; i < mModules.size(); i++) {
    mModuleList->stdList()->setCellContent(i, ColBase,
                                           ToPtrString(mit.value().base));
    mModuleList->stdList()->setCellContent(i, ColModule,
                                           QFileInfo(mit.key()).fileName());
    mModuleList->stdList()->setCellContent(i, ColPath, mit.key());
    mit++;
  }
  mModuleList->stdList()->reloadData();

  if (mModules.size()) {
    moduleSelectionChanged(0);
  } else {
    mSymbolSearchList->mList->setRowCount(0);
    mSymbolSearchList->mList->reloadData();
    mSymbolList->refreshSearchList();
  }
}

void VMPSymbolView::symbolContextMenu(QMenu *wMenu) {
  if (!mSymbolList->mCurList->getRowCount()) return;
  wMenu->addSeparator();
  wMenu->addAction(mToggleVMP);
  wMenu->addAction(mToggleVMPSels);
}

void VMPSymbolView::moduleContextMenu(QMenu *wMenu) {
  wMenu->addAction(mAddModule);
  wMenu->addAction(mDelModule);
  wMenu->addSeparator();
  wMenu->addAction(mAddModuleCfg);
  wMenu->addAction(mDelModuleAndCfg);
  wMenu->addSeparator();
  wMenu->addAction(mVMPCommit);
  wMenu->addAction(mVMPCancel);
}

void VMPSymbolView::symbolSelectModule(duint base) {
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

void VMPSymbolView::moduleCopyPath() {
  Bridge::CopyToClipboard(mModuleList->mCurList->getCellContent(
      mModuleList->mCurList->getInitialSelection(), ColPath));
}

void VMPSymbolView::toggleVMP() {
  if (!mCurFunc) return;
  if (mCurFunc->vmp) {
    mCurFunc->vmp = false;
    mCurFunc->name.erase(0, 4);
    addMsgToSymbolLogSlot(
        QString("Toggle %1 to normal function.\n").arg(mCurFunc->name.data()));
  } else {
    mCurFunc->vmp = true;
    mCurFunc->name.insert(0, "vmp$");
    addMsgToSymbolLogSlot(
        QString("Toggle %1 to vmp function.\n").arg(mCurFunc->name.data()));
  }

  GuiRepaintTableView();
}

void VMPSymbolView::toggleVMPSels() {
  if (!mCurSymTable) return;
  auto sels = mCurSymTable->getSelection();
  for (auto i : sels) {
    mCurFunc = (FuncInfo *)mCurSymTable->mData[i].symbol;
    if (mCurFunc->vmp) {
      mCurFunc->vmp = false;
      mCurFunc->name.erase(0, 4);
      addMsgToSymbolLogSlot(
        QString("Toggle %1 to normal function.\n").arg(mCurFunc->name.data()));
    } else {
      mCurFunc->vmp = true;
      mCurFunc->name.insert(0, "vmp$");
      addMsgToSymbolLogSlot(
        QString("Toggle %1 to vmp function.\n").arg(mCurFunc->name.data()));
    }
  }

  GuiRepaintTableView();
}

void VMPSymbolView::emptySearchResultSlot() {
  // No result after search
  mSymbolList->mCurList->setRowCount(0);
}

void VMPSymbolView::selectionGetSlot(SELECTIONDATA *selection) {
  selection->start = selection->end =
      duint(mModuleList->mCurList
                ->getCellContent(mModuleList->mCurList->getInitialSelection(),
                                 ColBase)
                .toULongLong(nullptr, 16));
  Bridge::getBridge()->setResult(BridgeResult::SelectionGet, 1);
}

void VMPSymbolView::funcSelectionChanged(int index) {
  ZehSymbolTable *table =
      (ZehSymbolTable *)(sender() == mSymbolSearchList->list()
                             ? mSymbolSearchList->list()
                             : mSymbolSearchList->searchList());
  if (!table->getRowCount() || index >= table->mData.size()) return;

  mCurSymTable = table;
  mCurFunc = (FuncInfo *)table->mData[index].symbol;
  addMsgToSymbolLogSlot(QString("%1 %2-%3 %4 %5\n")
                            .arg(mCurFunc->name.data())
                            .arg(ToPtrString(mCurFunc->start))
                            .arg(ToPtrString(mCurFunc->end))
                            .arg(mCurFunc->end - mCurFunc->start)
                            .arg(mCurFunc->vmp ? "vmp" : ""));
}

static bool filter_function(const mana::Function *fn) {
  if (fn->name[3] == '.') {
    // ignore import function
    return true;
  }
  if (fn->end - fn->start <= 16) {
    // ignore small function
    return true;
  }
  if (fn->name.find(' ') != std::string::npos) {
    // ignore compiler generated function
    return true;
  }
  return false;
}

void VMPSymbolView::moduleAdd() {
  auto file = QFileDialog::getOpenFileName(this, "Add VMP File");
  if (!file.length()) return;
  QEventLoop eloop;
  mana::Binary *bin = nullptr;
  QThread *anathread = QThread::create(
      [this, &bin, &eloop](QString path) {
        bin = mana::New(path.toUtf8().data());
        if (!bin) {
          return;
        }
        eloop.quit();
      },
      file);
  anathread->start();
  eloop.exec();
  delete anathread;
  if (!bin) {
    addMsgToSymbolLogSlot(QString("Unsupport input file %1.\n").arg(file));
    return;
  }
  auto mit = mModules.insert(file, ModuleInfo());
  ModuleInfo &minfo = mit.value();
  minfo.base = bin->imageBase();
  for (auto &f : bin->functions()) {
    if (filter_function(&f.second)) {
      continue;
    }
    minfo.funcs.push_back(FuncInfo());
    auto finfo = minfo.funcs.rbegin();
    finfo->name = f.second.name;
    finfo->start = f.second.start;
    finfo->end = f.second.end;
    finfo->vmp = false;
  }
  mana::Delete(bin);

  updateSymbolList();
  GuiAddLogMessage(
      QString("Added vmp module file %1.\n").arg(file).toUtf8().data());
}

void VMPSymbolView::moduleAddCfg() {
  auto cfgfile = QFileDialog::getOpenFileName(this, "Load VMP Config",
                                              VMPGlobal::inst()->usrdataDir(),
                                              "VMP Config (*.vmp.json)");
  if (!cfgfile.length()) return;
  QFile file(cfgfile);
  if (!file.open(QIODevice::ReadOnly)) {
    addMsgToSymbolLogSlot(
        QString("Failed to read vmp config %1.\n").arg(cfgfile));
    return;
  }
  QByteArray buff = file.readAll();
  QJsonDocument jdoc = QJsonDocument::fromJson(buff);
  QMap cfgs = jdoc.toVariant().toMap();
  auto fileit = cfgs.find("file");
  if (fileit == cfgs.end()) {
    addMsgToSymbolLogSlot(
        QString("Invalid vmp config %1. there's no 'file' item.\n")
            .arg(cfgfile));
    return;
  }
  QString filepath = fileit.value().toString();
  QEventLoop eloop;
  mana::Binary *bin = nullptr;
  QThread *anathread = QThread::create(
      [this, &bin, &eloop](QString path) {
        bin = mana::New(path.toUtf8().data());
        if (!bin) {
          return;
        }
        eloop.quit();
      },
      filepath);
  anathread->start();
  eloop.exec();
  delete anathread;
  if (!bin) {
    addMsgToSymbolLogSlot(QString("Unsupport input file %1.\n").arg(filepath));
    return;
  }

  std::set<std::string> vmpsyms;
  auto symsit = cfgs.find("symbols");
  if (symsit != cfgs.end()) {
    for (auto it : symsit->value<QJsonArray>()) {
      vmpsyms.insert(it.toString().toStdString());
    }
  }

  auto mit = mModules.insert(filepath, ModuleInfo());
  ModuleInfo &minfo = mit.value();
  minfo.base = bin->imageBase();
  for (auto &f : bin->functions()) {
    if (filter_function(&f.second)) {
      continue;
    }
    minfo.funcs.push_back(FuncInfo());
    auto finfo = minfo.funcs.rbegin();
    finfo->start = f.second.start;
    finfo->end = f.second.end;
    if (vmpsyms.find(f.second.name) == vmpsyms.end()) {
      finfo->name = f.second.name;
      finfo->vmp = false;
    } else {
      finfo->name = "vmp$" + f.second.name;
      finfo->vmp = true;
    }
  }
  mana::Delete(bin);

  updateSymbolList();
  GuiAddLogMessage(
      QString("Added vmp module file %1.\n").arg(filepath).toUtf8().data());
}

void VMPSymbolView::moduleDelete() {
  if (!mModules.size()) return;
  auto path = mModuleList->mCurList->getCellContent(
      mModuleList->mCurList->getInitialSelection(), ColPath);
  auto found = mModules.find(path);
  if (found != mModules.end()) {
    mModules.erase(found);
    updateSymbolList();
    GuiAddLogMessage(
        QString("Removed vmp module %1.\n").arg(path).toUtf8().data());
  }
}

void VMPSymbolView::moduleDeleteAndCfg() {
  if (!mModules.size()) return;
  auto path = mModuleList->mCurList->getCellContent(
      mModuleList->mCurList->getInitialSelection(), ColPath);
  auto found = mModules.find(path);
  if (found != mModules.end()) {
    QString vmpcfg =
        QString("%1/%2.vmp.json")
            .arg(VMPGlobal::inst()->usrdataDir(), QFileInfo(path).fileName());
    QFile(vmpcfg).remove();
    mModules.erase(found);
    updateSymbolList();
    GuiAddLogMessage(QString("Removed vmp module %1 and its vmp config %2.\n")
                         .arg(path)
                         .arg(vmpcfg)
                         .toUtf8()
                         .data());
  }
}

void VMPSymbolView::onReadProcessOutputData() {
  addMsgToSymbolLogSlot(mVMPProcess.readAllStandardOutput());
}

void VMPSymbolView::onReadProcessErrorData() {
  addMsgToSymbolLogSlot(mVMPProcess.readAllStandardError());
}

static const char *bin_dirname() {
#if __APPLE__
#if __x86_64__
  return "mac-x64";
#else
  return "mac-arm64";
#endif
#elif __linux__
#if __x86_64__
  return "linux-x64";
#else
  return "linux-aarch64";
#endif
#else
  return "win";
#endif
}

void VMPSymbolView::vmpCommit(const char *pvmproot, const char *libdirs,
                              duint rtstatic, const QString &path,
                              const ModuleInfo &minfo) {
  std::vector<const FuncInfo *> vmpfns;
  for (auto &f : minfo.funcs) {
    if (f.vmp) {
      vmpfns.push_back(&f);
    }
  }

  auto vg = VMPGlobal::inst();
  QString vmpcfg = QString("%1/%2.vmp.json")
                       .arg(vg->usrdataDir(), QFileInfo(path).fileName());
  QJsonObject root;
  root.insert("file", path);
  root.insert("level", "usrdef");
  QJsonArray syms;
  for (auto f : vmpfns) {
    std::string realname(f->name);
    realname.erase(0, 4);
    syms.append(realname.data());
  }
  root.insert("symbols", syms);
  QString ldirs(libdirs);
  QJsonArray dirs;
  for (auto &d : ldirs.split('\n')) {
    if (QFileInfo(d).exists()) {
      dirs.append(d);
    } else if (d.length()) {
      addMsgToSymbolLogSlot(
          QString("Ignoring invalid library directory %1.\n").arg(d));
    }
  }
  if (dirs.size()) {
    root.insert("libdirs", dirs);
  }
  if (rtstatic) {
    root.insert("rttype", "static");
  }
  QJsonDocument jdoc(root);
  QFile cfgfile(vmpcfg);
  if (cfgfile.open(QIODevice::WriteOnly)) {
    cfgfile.write(jdoc.toJson());
    cfgfile.close();
  } else {
    addMsgToSymbolLogSlot(
        QString("Failed to save uvmp config '%1'.").arg(vmpcfg));
    moduleVMPCancel();
    return;
  }

  QStringList args;
  QString pvmpprog = QString("%1/%2/phonevmp").arg(pvmproot).arg(bin_dirname());
#if _WIN32
  pvmpprog += ".exe";
#endif
  args.append(QString("--vmpcfg=%1").arg(vmpcfg));
  mVMPProcess.setProgram(pvmpprog);
  mVMPProcess.setArguments(args);
  mVMPProcess.start();
  if (mVMPProcess.waitForStarted()) {
    addMsgToSymbolLogSlot(
        QString("Running %1 %2...\n").arg(pvmpprog).arg(args[0]));
  } else {
    addMsgToSymbolLogSlot(QString("Failed to start phonevmp process : %1.\n")
                              .arg(mVMPProcess.errorString()));
  }
}

void VMPSymbolView::vmpCommit() {
  char pvmproot[MAX_PATH];
  if (!BridgeSettingGet(VSSETTING_SECTION, VSSKEY_PVMP_ROOT, pvmproot,
                        MAX_PATH)) {
    addMsgToSymbolLogSlot(
        "Please set the PhoneVMP toolchain's root path in settings.\n");
    moduleVMPCancel();
    return;
  }
  char libdirs[MAX_SETTING_SIZE];
  libdirs[0] = 0;
  BridgeSettingGet(VSSETTING_SECTION, VSSKEY_LIBDIRS, libdirs);
  duint rtstatic = 0;
  BridgeSettingGetUint(VSSETTING_SECTION, VSSKEY_STATICRT, &rtstatic);

  vmpCommit(pvmproot, libdirs, rtstatic, mCurCommit.key(), mCurCommit.value());
}

void VMPSymbolView::moduleVMPCommit() {
  if (!mModules.size()) {
    return;
  }
  if (mCurCommit != mModules.end()) {
    addMsgToSymbolLogSlot(
        "Already committing vmp operation, please wait a few minutes.\n");
    return;
  }

  mCurCommit = mModules.begin();
  vmpCommit();
}

void VMPSymbolView::moduleVMPCancel() {
  if (!mModules.size()) {
    return;
  }
  if (mCurCommit == mModules.end()) {
    return;
  }

  mCurCommit = mModules.end();
  mVMPProcess.terminate();
  mVMPProcess.kill();
  addMsgToSymbolLogSlot("Canceled vmp operations.\n");
}

void VMPSymbolView::onProcessFinished(int exitCode,
                                      QProcess::ExitStatus exitStatus) {
  if (mCurCommit != mModules.end()) {
    mCurCommit++;
  }
  if (mCurCommit != mModules.end()) {
    vmpCommit();
  } else {
    addMsgToSymbolLogSlot("Finished vmp operations.\n");
  }
}
