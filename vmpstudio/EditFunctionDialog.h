#ifndef EDITBREAKPOINTDIALOG_H
#define EDITBREAKPOINTDIALOG_H

#include <QDialog>

#include "Bridge.h"
#include "VMPGlobal.h"

namespace Ui {
class EditFunctionDialog;
}

class EditFunctionDialog : public QDialog {
  Q_OBJECT

 public:
  explicit EditFunctionDialog(QWidget* parent, const VMPManaFunc* fn);
  ~EditFunctionDialog();

  std::vector<mana::Function*> analyzee;
  bool changed;

 public slots:
  void buttonOK();

 private:
  void splitFunction(const QString& name, const VMPManaFunc& func1,
                     addr_t midaddr);
  void procResult();

 private:
  Ui::EditFunctionDialog* ui;
};

#endif  // EDITBREAKPOINTDIALOG_H
