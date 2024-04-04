#ifndef UVMSEOPTIONDIALOG_H
#define UVMSEOPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class UVMSEOptionDialog;
}

class UVMSEOptionDialog : public QDialog
{
  Q_OBJECT

public:
  explicit UVMSEOptionDialog(QWidget *parent = nullptr);
  ~UVMSEOptionDialog();

  static int depth;
  static int rvaStart;
  static int rvaEnd;

private slots:
 void onButtonApply();

private:
  Ui::UVMSEOptionDialog *ui;
};

#endif // UVMSEOPTIONDIALOG_H
