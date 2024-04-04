#include "CPUMultiDumpFile.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QTabBar>

#include "Bridge.h"
#include "CPUDisassemblyFile.h"
#include "CPUDumpFile.h"
#include "LocalVarsView.h"
#include "StructWidget.h"
#include "WatchView.h"

CPUMultiDumpFile::CPUMultiDumpFile(CPUDisassemblyFile* disas, int nbCpuDumpTabs,
                                   QWidget* parent)
    : MHTabWidget(parent, true), mMemPage(0, 0) {
  setWindowTitle("CPUMultiDumpFile");
  mMaxCPUDumpTabs = nbCpuDumpTabs;
  mInitAllDumpTabs = false;

  mDumpPluginMenu = new QMenu(this);
  mDumpPluginMenu->setIcon(DIcon("plugin.png"));
  Bridge::getBridge()->emitMenuAddToList(this, mDumpPluginMenu, GUI_DUMP_MENU);

  for (uint i = 0; i < mMaxCPUDumpTabs; i++) {
    CPUDumpFile* cpuDump = new CPUDumpFile(disas, this);
    // cpuDump->loadColumnFromConfig(QString("CPUDump%1").arg(i + 1)); //TODO:
    // needs a workaround because the columns change
    connect(cpuDump, SIGNAL(displayReferencesWidget()), this,
            SLOT(displayReferencesWidgetSlot()));
    connect(cpuDump, SIGNAL(showDisassemblyTab(duint, duint, duint)), this,
            SLOT(showDisassemblyTabSlot(duint, duint, duint)));
    auto nativeTitle = QString("Dump ") + QString::number(i + 1);
    this->addTabEx(cpuDump, DIcon("dump.png"),
                   tr("Dump ") + QString::number(i + 1), nativeTitle);
    cpuDump->setWindowTitle(nativeTitle);
  }

  mCurrentCPUDump = dynamic_cast<CPUDumpFile*>(currentWidget());

  mWatch = nullptr;  // new WatchView(this);
#if 0
  // mMaxCPUDumpTabs++;
  auto nativeTitle = QString("Watch 1");
  this->addTabEx(mWatch, DIcon("animal-dog.png"),
                 tr("Watch ") + QString::number(1), nativeTitle);
  mWatch->setWindowTitle(nativeTitle);
  mWatch->loadColumnFromConfig("Watch1");
#endif

  mLocalVars = nullptr;  // new LocalVarsView(this);
  // this->addTabEx(mLocalVars, DIcon("localvars.png"), tr("Locals"), "Locals");

  mStructWidget = nullptr;  // new StructWidget(this);
  // this->addTabEx(mStructWidget, mStructWidget->windowIcon(),
  // mStructWidget->windowTitle(), "Struct");

  connect(this, SIGNAL(currentChanged(int)), this,
          SLOT(updateCurrentTabSlot(int)));
  connect(tabBar(), SIGNAL(OnDoubleClickTabIndex(int)), this,
          SLOT(openChangeTabTitleDialogSlot(int)));

  connect(Bridge::getBridge(), SIGNAL(dumpAt(dsint)), this,
          SLOT(printDumpAtSlot(dsint)));
  connect(Bridge::getBridge(), SIGNAL(dumpAtN(duint, int)), this,
          SLOT(printDumpAtNSlot(duint, int)));
  connect(Bridge::getBridge(), SIGNAL(selectionDumpGet(SELECTIONDATA*)), this,
          SLOT(selectionGetSlot(SELECTIONDATA*)));
  connect(Bridge::getBridge(), SIGNAL(selectionDumpSet(const SELECTIONDATA*)),
          this, SLOT(selectionSetSlot(const SELECTIONDATA*)));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(dbgStateChangedSlot(DBGSTATE)));
  connect(Bridge::getBridge(), SIGNAL(focusDump()), this,
          SLOT(focusCurrentDumpSlot()));
  connect(Bridge::getBridge(), SIGNAL(getDumpAttention()), this,
          SLOT(getDumpAttention()));

  connect(mCurrentCPUDump, SIGNAL(selectionUpdated()), mCurrentCPUDump,
          SLOT(selectionUpdatedSlot()));
}

CPUDumpFile* CPUMultiDumpFile::getCurrentCPUDump() { return mCurrentCPUDump; }

// Only get tab names for all dump tabs!
void CPUMultiDumpFile::getTabNames(QList<QString>& names) {
  names.clear();
  int i;
  int index;
  // placeholders
  for (i = 0; i < getMaxCPUTabs(); i++)
    names.push_back(QString("Dump %1").arg(i + 1));
  // enumerate all tabs
  for (i = 0; i < QTabWidget::count(); i++) {
    if (!getNativeName(i).startsWith("Dump ")) continue;
    index = getNativeName(i).mid(5).toInt() - 1;
    if (index < getMaxCPUTabs()) names[index] = this->tabBar()->tabText(i);
  }
  // enumerate all detached windows
  for (i = 0; i < windows().count(); i++) {
    QString nativeName =
        dynamic_cast<MHDetachedWindow*>(windows()[i]->parent())->mNativeName;
    if (nativeName.startsWith("Dump ")) {
      index = nativeName.mid(5).toInt() - 1;
      if (index < getMaxCPUTabs())
        names[index] = dynamic_cast<MHDetachedWindow*>(windows()[i]->parent())
                           ->windowTitle();
    }
  }
}

int CPUMultiDumpFile::getMaxCPUTabs() { return mMaxCPUDumpTabs; }

int CPUMultiDumpFile::GetDumpWindowIndex(int dump) {
  QString dumpNativeName = QString("Dump ") + QString::number(dump);
  for (int i = 0; i < count(); i++) {
    if (getNativeName(i) == dumpNativeName) return i;
  }
  return 2147483647;
}

int CPUMultiDumpFile::GetWatchWindowIndex() {
  QString watchNativeName = QString("Watch 1");
  for (int i = 0; i < count(); i++) {
    if (getNativeName(i) == watchNativeName) return i;
  }
  return 2147483647;
}

void CPUMultiDumpFile::SwitchToDumpWindow() {
  if (!mCurrentCPUDump) setCurrentIndex(GetDumpWindowIndex(1));
}

void CPUMultiDumpFile::SwitchToWatchWindow() {
  if (mCurrentCPUDump) setCurrentIndex(GetWatchWindowIndex());
}

void CPUMultiDumpFile::updateCurrentTabSlot(int tabIndex) {
  CPUDumpFile* t = qobject_cast<CPUDumpFile*>(widget(tabIndex));
  mCurrentCPUDump = t;
}

void CPUMultiDumpFile::printDumpAtSlot(dsint parVa) {
  if (mInitAllDumpTabs) {
    CPUDumpFile* cpuDump = NULL;
    for (int i = 0; i < count(); i++) {
      if (!getNativeName(i).startsWith("Dump ")) continue;
      cpuDump = qobject_cast<CPUDumpFile*>(widget(i));
      if (cpuDump) {
        cpuDump->mHistory.historyClear();
        cpuDump->mHistory.addVaToHistory(parVa);
        cpuDump->printDumpAt(parVa);
      }
    }

    mInitAllDumpTabs = false;
  } else {
    SwitchToDumpWindow();
    mCurrentCPUDump->printDumpAt(parVa);
    mCurrentCPUDump->mHistory.addVaToHistory(parVa);
  }
}

void CPUMultiDumpFile::printDumpAtNSlot(duint parVa, int index) {
  int tabindex = GetDumpWindowIndex(index);
  if (tabindex == 2147483647) return;
  CPUDumpFile* current = qobject_cast<CPUDumpFile*>(widget(tabindex));
  if (!current) return;
  setCurrentIndex(tabindex);
  current->updateMemPage(&mMemPage);
  current->printDumpAt(parVa);
  current->mHistory.addVaToHistory(parVa);
}

void CPUMultiDumpFile::selectionGetSlot(SELECTIONDATA* selectionData) {
  SwitchToDumpWindow();
  mCurrentCPUDump->selectionGet(selectionData);
}

void CPUMultiDumpFile::selectionSetSlot(const SELECTIONDATA* selectionData) {
  SwitchToDumpWindow();
  mCurrentCPUDump->selectionSet(selectionData);
}

void CPUMultiDumpFile::dbgStateChangedSlot(DBGSTATE dbgState) {
  if (dbgState == initialized) mInitAllDumpTabs = true;
}

void CPUMultiDumpFile::openChangeTabTitleDialogSlot(int tabIndex) {
  bool bUserPressedOk;
  QString sCurrentTabName = tabBar()->tabText(tabIndex);

  QString sNewTabName = QInputDialog::getText(
      this, tr("Change Tab %1 Name").arg(tabIndex + 1), tr("Tab Name"),
      QLineEdit::Normal, sCurrentTabName, &bUserPressedOk,
      Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
  if (bUserPressedOk) {
    if (sNewTabName.length() != 0) tabBar()->setTabText(tabIndex, sNewTabName);
  }
}

void CPUMultiDumpFile::displayReferencesWidgetSlot() {
  emit displayReferencesWidget();
}

void CPUMultiDumpFile::focusCurrentDumpSlot() {
  SwitchToDumpWindow();
  mCurrentCPUDump->setFocus();
}

void CPUMultiDumpFile::showDisassemblyTabSlot(duint selectionStart,
                                              duint selectionEnd,
                                              duint firstAddress) {
  Q_UNUSED(firstAddress);  // TODO: implement setTableOffset(firstAddress)
  if (!mDisassembly) {
    mDisassembly = new CPUDisassemblyFile(this, false);
    this->addTabEx(mDisassembly,
                   DIcon(ArchValue("processor32.png", "processor-cpu.png")),
                   tr("Disassembly"), "DumpDisassembly");
    mDisassembly->resetDatabase(mMemPage.dataBase());
  }
  // Set CIP
  auto clearHistory = mDisassembly->getBase() == 0;
  mDisassembly->disassembleAtSlot(selectionStart,
                                  Bridge::getBridge()->mLastCip);
  if (clearHistory) mDisassembly->historyClear();
  // Make the address visisble in memory
  mDisassembly->disassembleAt(selectionStart, true, -1);
  // Set selection to match the dump
  mDisassembly->setSingleSelection(selectionStart - mDisassembly->getBase());
  mDisassembly->expandSelectionUpTo(selectionEnd - mDisassembly->getBase());
  // Show the tab
  setCurrentWidget(mDisassembly);
}

void CPUMultiDumpFile::getDumpAttention() { mCurrentCPUDump->getAttention(); }

void CPUMultiDumpFile::resetDatabase(VMPManaDatabase* mdb) {
  if (!mdb) {
    mMemPage.setAttributes(0, 0, nullptr);
    for (int i = 1; i <= getMaxCPUTabs(); i++) {
      printDumpAtNSlot(0, i);
    }
    return;
  }

  mInitAllDumpTabs = false;
  mMemPage.setAttributes(mdb->rtbase, mdb->opcsize, mdb);
  CPUDumpFile* cpuDump = NULL;
  for (int i = 0; i < count(); i++) {
    if (!getNativeName(i).startsWith("Dump ")) continue;
    cpuDump = qobject_cast<CPUDumpFile*>(widget(i));
    if (cpuDump) {
      cpuDump->updateMemPage(&mMemPage);
    }
  }

  size_t sectcount = mdb->db->sections().size();
  int index = 1, i = sectcount > 2 ? 2 : 0;
  auto sit = mdb->db->sections().begin();
  for (; index <= getMaxCPUTabs() && i < (int)sectcount; i++, sit++) {
    auto sect = &sit->second;
    printDumpAtNSlot(sect->addr, index++);
  }
  setCurrentIndex(0);
}
