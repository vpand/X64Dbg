#include "CloseDialog.h"

#include <QCloseEvent>

#include "MiscUtil.h"
#include "ui_CloseDialog.h"

CloseDialog::CloseDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::CloseDialog) {
  ui->setupUi(this);
  setModal(true);
  setWindowFlags(windowFlags() & ~(Qt::WindowContextHelpButtonHint |
                                   Qt::WindowCloseButtonHint) |
                 Qt::MSWindowsFixedSizeDialogHint);
  SetApplicationIcon(QDialog::winId());
  bCanClose = false;
}

CloseDialog::~CloseDialog() { delete ui; }

void CloseDialog::allowClose() { bCanClose = true; }

void CloseDialog::closeEvent(QCloseEvent* event) {
  if (bCanClose)
    event->accept();
  else
    event->ignore();
}
