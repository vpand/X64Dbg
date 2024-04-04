#include "AttachDialog.h"

#include <QFileInfo>
#include <QMenu>
#include <QMessageBox>

#include "StdIconSearchListView.h"
#include "StdTable.h"
#include "ui_AttachDialog.h"

AttachDialog::AttachDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AttachDialog) {
  ui->setupUi(this);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

  // Setup actions/shortcuts
  //
  // Enter key as shortcut for "Attach"
  mAttachAction = new QAction(tr("Attach"), this);
  mAttachAction->setShortcut(QKeySequence("enter"));
  connect(mAttachAction, SIGNAL(triggered()), this,
          SLOT(on_btnAttach_clicked()));

  // F5 as shortcut to refresh view
  mRefreshAction = new QAction(tr("Refresh"), this);
  mRefreshAction->setShortcut(ConfigShortcut("ActionRefresh"));
  ui->btnRefresh->setText(
      tr("Refresh") +
      QString(" (%1)").arg(mRefreshAction->shortcut().toString()));
  connect(mRefreshAction, SIGNAL(triggered()), this, SLOT(refresh()));
  this->addAction(mRefreshAction);
  connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));

  // Create search view (regex disabled)
  mSearchListView = new StdIconSearchListView(this, false, false);
  mSearchListView->mSearchStartCol = 0;
  ui->verticalLayout->insertWidget(0, mSearchListView);

  // setup process list
  int charwidth = mSearchListView->getCharWidth();
  mSearchListView->addColumnAt(
      charwidth * sizeof(int) * 2 + 8, tr("PID"), true, QString(),
      StdTable::SortBy::AsInt);
  mSearchListView->addColumnAt(150, tr("Name"), true);
  // mSearchListView->addColumnAt(300, tr("Title"), true);
  mSearchListView->addColumnAt(800, tr("Path"), true);
  // mSearchListView->addColumnAt(800, tr("Command Line Arguments"), true);
  mSearchListView->setDrawDebugOnly(false);

  connect(mSearchListView, SIGNAL(enterPressedSignal()), this,
          SLOT(on_btnAttach_clicked()));
  connect(mSearchListView, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(processListContextMenu(QMenu*)));

  // Highlight the search box
  mSearchListView->mCurList->setFocus();

  Config()->setupWindowPos(this);

  // Populate the process list atleast once
  refresh();
}

AttachDialog::~AttachDialog() {
  Config()->saveWindowPos(this);
  delete ui;
}

void AttachDialog::refresh() {
  QString filter = mSearchListView->filterText();
  mSearchListView->setRowCount(0);
  DBGPROCESSINFO* entries;
  int count = 0;
  if (!DbgFunctions()->GetProcessList(&entries, &count)) return;
  mSearchListView->setRowCount(count);
  for (int i = 0; i < count; i++) {
    QFileInfo fi(entries[i].szExeFile);
    mSearchListView->setCellContent(
        i, ColPid,
        QString().sprintf("%u", entries[i].dwProcessId));
    mSearchListView->setCellContent(i, ColName, fi.baseName());
    mSearchListView->setCellContent(i, ColPath, QString(entries[i].szExeFile));
  }
  mSearchListView->reloadData();
  mSearchListView->refreshSearchList(filter);
  if (entries) {
    BridgeFree(entries);
  }
}

void AttachDialog::on_btnAttach_clicked() {
  QString pid = mSearchListView->mCurList->getCellContent(
      mSearchListView->mCurList->getInitialSelection(), ColPid);
  QString path = mSearchListView->mCurList->getCellContent(
      mSearchListView->mCurList->getInitialSelection(), ColPath);
  DbgCmdExec(QString("attach %1 %2").arg(pid).arg(path));
  accept();
}

#if 0
void AttachDialog::on_btnFindWindow_clicked() {
  QString windowText;
retryFindWindow:
  if (!SimpleInputBox(this, tr("Find Window"), windowText, windowText,
                      tr("Enter window title or class name here.")))
    return;
  HWND hWndFound = FindWindowW(
      NULL,
      reinterpret_cast<LPCWSTR>(windowText.utf16()));  // Window Title first
  if (hWndFound == NULL)
    hWndFound = FindWindowW(reinterpret_cast<LPCWSTR>(windowText.utf16()),
                            NULL);  // Then try window class name
  if (hWndFound == NULL) {
    QMessageBox retryDialog(
        QMessageBox::Critical, tr("Find Window"),
        tr("Cannot find window \"%1\". Retry?").arg(windowText),
        QMessageBox::Cancel | QMessageBox::Retry, this);
    retryDialog.setWindowIcon(DIcon("compile-error.png"));
    if (retryDialog.exec() == QMessageBox::Retry) goto retryFindWindow;
  } else {
    DWORD pid, tid;
    if (tid = GetWindowThreadProcessId(hWndFound, &pid)) {
      refresh();
      QString pidText = QString().sprintf("%u", pid);
      bool found = false;
      for (int i = 0; i < mSearchListView->mCurList->getRowCount(); i++) {
        if (mSearchListView->mCurList->getCellContent(i, ColPid) == pidText) {
          mSearchListView->mCurList->setSingleSelection(i);
          found = true;
          break;
        }
      }
      if (!found) {
        QMessageBox hiddenProcessDialog(
            QMessageBox::Question, tr("Find Window"),
            tr("The PID of the window \"%1\" is %2, but it's hidden in the "
               "process list. Do you want to attach to it immediately?")
                .arg(windowText)
                .arg(pidText),
            QMessageBox::Yes | QMessageBox::No, this);
        if (hiddenProcessDialog.exec() == QMessageBox::Yes) {
          DbgCmdExec(QString("attach %1").arg(pid, 0, 16));
          accept();
        }
      }
    } else
      SimpleErrorBox(this, tr("Find Window"),
                     tr("GetWindowThreadProcessId() failed. Cannot get the PID "
                        "of the window."));
  }
}
#endif

void AttachDialog::processListContextMenu(QMenu* wMenu) {
  // Don't show menu options if nothing is listed
  if (!mSearchListView->mCurList->getRowCount()) return;

  wMenu->addAction(mAttachAction);
  wMenu->addAction(mRefreshAction);
}

LaunchDialog::LaunchDialog(int magic, QWidget* parent)
    : QDialog(parent), ui(new Ui::AttachDialog), mMagic(magic) {
  ui->setupUi(this);
  ui->btnAttach->setText("Launch");
  setWindowTitle("Launch Application");
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

  // Setup actions/shortcuts
  //
  // Enter key as shortcut for "Attach"
  mLaunchAction = new QAction(tr("Launch"), this);
  mLaunchAction->setShortcut(QKeySequence("enter"));
  connect(mLaunchAction, SIGNAL(triggered()), this,
          SLOT(on_btnAttach_clicked()));

  ui->btnRefresh->hide();

  // Create search view (regex disabled)
  mSearchListView = new StdIconSearchListView(this, false, false);
  mSearchListView->mSearchStartCol = 0;
  ui->verticalLayout->insertWidget(0, mSearchListView);

  // setup process list
  int charwidth = mSearchListView->getCharWidth();
  mSearchListView->addColumnAt(150, tr("Name"), true);
  mSearchListView->addColumnAt(800, tr("Path"), true);
  mSearchListView->setIconColumn(1);  // Name
  mSearchListView->setDrawDebugOnly(false);

  connect(mSearchListView, SIGNAL(enterPressedSignal()), this,
          SLOT(on_btnAttach_clicked()));
  connect(mSearchListView, SIGNAL(listContextMenuSignal(QMenu*)), this,
          SLOT(processListContextMenu(QMenu*)));

  // Highlight the search box
  mSearchListView->mCurList->setFocus();

  Config()->setupWindowPos(this);

  // Populate the process list atleast once
  refresh();
}

LaunchDialog::~LaunchDialog() {
  Config()->saveWindowPos(this);
  delete ui;
}

void LaunchDialog::refresh() {
  mSearchListView->setRowCount(0);
  DBGPROCESSINFO* entries;
  int count = mMagic;
  if (!DbgFunctions()->GetProcessList(&entries, &count)) return;
  mSearchListView->setRowCount(count);
  for (int i = 0; i < count; i++) {
    QFileInfo fi(entries[i].szExeFile);
    mSearchListView->setCellContent(i, ColName, fi.fileName());
    mSearchListView->setCellContent(i, ColPath, QString(entries[i].szExeFile));
  }
  mSearchListView->reloadData();
  mSearchListView->refreshSearchList();
  if (entries) {
    BridgeFree(entries);
  }
}

void LaunchDialog::on_btnAttach_clicked() {
  QString path = mSearchListView->mCurList->getCellContent(
      mSearchListView->mCurList->getInitialSelection(), ColPath);
  DbgCmdExec(QString("launch %1").arg(path));
  accept();
}

void LaunchDialog::processListContextMenu(QMenu* wMenu) {
  // Don't show menu options if nothing is listed
  if (!mSearchListView->mCurList->getRowCount()) return;

  wMenu->addAction(mLaunchAction);
}
