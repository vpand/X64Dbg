#include "SelectSampleDialog.h"

#include "UVMTraceWidget.h"
#include "UVMTraceBrowser.h"
#include "ui_SelectSampleDialog.h"
#include "StringUtil.h"

SelectSampleDialog::SelectSampleDialog(TraceBrowser *parent)
    : QDialog(parent), ui(new Ui::SelectSampleDialog), browser(parent) {
  ui->setupUi(this);

  for (size_t i = 0; i < uvmWin->mRecordInds.size(); i++) {
    addr_t min = -1, max = 0;
    for (auto addr : uvmWin->mRecordInds[i]) {
      if (min > addr) min = addr;
      if (max < addr) max = addr;
    }
    ui->comboBox->addItem(QString("Index %1, %2 %3 Chains, %4 - %5")
                              .arg(i)
                              .arg(ToHexString(uvmWin->mRecordInds[i][0] - uvmWin->runtimeBase()))
                              .arg(uvmWin->mRecordInds[i].size())
                              .arg(ToHexString(min))
                              .arg(ToHexString(max)));
  }
  for (auto rva : browser->keypoints()) {
    ui->comboBoxKeypoints->addItem(QString("%1").arg(ToHexString(rva)));
  }
  ui->comboBox->setCurrentIndex(uvmWin->mRecordCur);
  ui->textEdit->append(QString("Current sample data index is %1.\n").arg(uvmWin->mRecordCur));
  ui->horizontalSliderCGDepth->setValue(uvmWin->mCGRenderDepth);

  connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this,
          SLOT(onCurrentIndexChanged(int)));
  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onAddClicked()));
  connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(onSearchClicked()));
  connect(ui->pushButtonKeypointAdd, SIGNAL(clicked()), this, SLOT(onKeypointAddClicked()));
  connect(ui->pushButtonKeypointRemove, SIGNAL(clicked()), this, SLOT(onKeypointRemoveClicked()));
  connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAccepted()));
  connect(ui->spinBoxCGDepth, SIGNAL(valueChanged(int)), ui->horizontalSliderCGDepth, SLOT(setValue(int)));
  connect(ui->horizontalSliderCGDepth, SIGNAL(valueChanged(int)), ui->spinBoxCGDepth, SLOT(setValue(int)));
}

SelectSampleDialog::~SelectSampleDialog() { delete ui; }

void SelectSampleDialog::onCurrentIndexChanged(int index) {
  lastSelect = index;

  auto &inds = uvmWin->mRecordInds[index];
  std::set<addr_t> pcs;
  for (auto a : inds) {
    pcs.insert(a);
  }
  ui->textEdit->append(QString("Index : %1\nPC Chains : %2\nAddress Hit : %3\n")
                           .arg(index)
                           .arg(inds.size())
                           .arg(pcs.size()));

  if (browser) {
    browser->selectSample(index);
  }
}

void SelectSampleDialog::onAddClicked() {
  allSelects.insert(lastSelect);
  ui->textEdit->append(QString("Added index %1 to combine.\n").arg(lastSelect));
}

void SelectSampleDialog::onSearchClicked() {
  for (int i = 0; i < ui->comboBox->count(); i++) {
    QString ind = ui->comboBox->itemText(i);
    if (ind.contains(ui->lineEditIndexSearch->text())) {
      ui->textEdit->append(QString("Search result: %1.\n").arg(ind));
    }
  }
}

void SelectSampleDialog::onKeypointAddClicked() {
  int rva = ui->lineEditKeypoint->text().toInt(nullptr, 16);
  if (!rva) {
    ui->textEdit->append(QString("Invalid input keypoint hex rva: %1.\n")
                         .arg(ui->lineEditKeypoint->text()));
    return;
  }
  auto found = browser->keypoints().find(rva);
  if (found != browser->keypoints().end()) {
    ui->textEdit->append(QString("Input keypoint hex rva has already been added: %1.\n")
                         .arg(ui->lineEditKeypoint->text()));
    return;
  }
  browser->keypoints().insert(rva);
  ui->comboBoxKeypoints->addItem(QString("%1").arg(ToHexString(rva)));
  ui->textEdit->append(QString("New keypoint %1 has been added.\n").arg(ToHexString(rva)));
}

void SelectSampleDialog::onKeypointRemoveClicked() {
  if (ui->comboBoxKeypoints->count() == 0) {
    return;
  }
  QString cur = ui->comboBoxKeypoints->currentText();
  int rva = cur.toInt(nullptr, 16);
  ui->comboBoxKeypoints->removeItem(ui->comboBoxKeypoints->currentIndex());
  browser->keypoints().erase(browser->keypoints().find(rva));
  ui->textEdit->append(QString("Current keypoint %1 has been removed.\n").arg(cur));
  return;
}

void SelectSampleDialog::onAccepted() {
  int depth = ui->horizontalSliderCGDepth->value();
  if (uvmWin->mCGRenderDepth != depth) {
    uvmWin->mCGRenderDepth = depth;
    GuiAddLogMessage(QString("Set call graph render depth to %1.\n").arg(uvmWin->mCGRenderDepth).toUtf8().data());
  }
}
