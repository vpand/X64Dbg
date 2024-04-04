#include "UVMSEOptionDialog.h"
#include "ui_UVMSEOptionDialog.h"
#include "UVMTraceWidget.h"
#include "StringUtil.h"

int UVMSEOptionDialog::depth = 0;
int UVMSEOptionDialog::rvaStart = 0;
int UVMSEOptionDialog::rvaEnd = 0;

UVMSEOptionDialog::UVMSEOptionDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::UVMSEOptionDialog)
{
  ui->setupUi(this);
  ui->lineEditStart->setText("0x0");
  ui->lineEditEnd->setText("0x0");

  connect(ui->pushButtonApply, SIGNAL(clicked()), this, SLOT(onButtonApply()));
  connect(ui->spinBoxDepth, SIGNAL(valueChanged(int)), ui->horizontalSliderDepth, SLOT(setValue(int)));
  connect(ui->horizontalSliderDepth, SIGNAL(valueChanged(int)), ui->spinBoxDepth, SLOT(setValue(int)));

  ui->horizontalSliderDepth->setValue(depth);
  ui->lineEditStart->setText(QString("0x%1").arg(ToHexString(rvaStart)));
  ui->lineEditEnd->setText(QString("0x%1").arg(ToHexString(rvaEnd)));
}

UVMSEOptionDialog::~UVMSEOptionDialog()
{
  delete ui;
}

void UVMSEOptionDialog::onButtonApply() {
  accept();

  depth = ui->horizontalSliderDepth->value();
  rvaStart = ui->lineEditStart->text().toInt(nullptr, 16);
  rvaEnd = ui->lineEditEnd->text().toInt(nullptr, 16);
  uvmWin->uvmTraceOptions(depth, rvaStart, rvaEnd);
}
