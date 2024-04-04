#include "AboutDialog.h"

#include <StringUtil.h>

#include <QDesktopServices>
#include <QUrl>

#include "UpdateChecker.h"
#include "VMPGlobal.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(UpdateChecker* updateChecker, QWidget* parent)
    : mUpdateChecker(updateChecker), QDialog(parent), ui(new Ui::AboutDialog) {
  ui->setupUi(this);
  // set window flags
  setModal(true);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);

  QPalette palet(this->palette());
   palet.setColor(QPalette::Background, QColor(0xFF, 0xFF, 0xFF));
   this->setPalette(palet);

  ui->lblVersion->setText(QString(STUDIO_VERSION) + ", " +
                          ToDateString(GetCompileDate()) + ", " __TIME__);
}

AboutDialog::~AboutDialog() { delete ui; }

void AboutDialog::on_btnCheckUpdates_clicked() {
  mUpdateChecker->checkForUpdates();
}
