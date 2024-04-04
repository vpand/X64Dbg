#ifndef SELECTSAMPLEDIALOG_H
#define SELECTSAMPLEDIALOG_H

#include <QDialog>
#include <QSet>

namespace Ui {
class SelectSampleDialog;
}

class UVMTraceBrowser;

class SelectSampleDialog : public QDialog {
  Q_OBJECT

 public:
  explicit SelectSampleDialog(UVMTraceBrowser *parent);
  ~SelectSampleDialog();

  int lastSelect = 0;
  QSet<int> allSelects;

 public slots:
  void onCurrentIndexChanged(int index);
  void onAddClicked();
  void onSearchClicked();
  void onKeypointAddClicked();
  void onKeypointRemoveClicked();
  void onAccepted();

 private:
  Ui::SelectSampleDialog *ui;
  UVMTraceBrowser *browser;
};

#endif  // SELECTSAMPLEDIALOG_H
