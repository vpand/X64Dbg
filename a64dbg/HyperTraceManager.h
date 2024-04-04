#ifndef HYPERTRACEMANAGER_H
#define HYPERTRACEMANAGER_H

#include <QWidget>

namespace Ui {
class HyperTraceManager;
}

class HyperTraceManager : public QWidget
{
  Q_OBJECT

public:
  explicit HyperTraceManager(QWidget *parent = nullptr);
  ~HyperTraceManager();

public slots:
  void onButtonFuncStart();
  void onButtonFuncStop();
  void onButtonHttp2Start();
  void onButtonHttp2Stop();
  void onButtonSyscallObjcStart();
  void onButtonSyscallObjcStop();
  void onButtonDatabaseLoad();
  void onButtonDatabaseSave();
  void onButtonDatabaseClear();

private:
  Ui::HyperTraceManager *ui;
};

#endif // HYPERTRACEMANAGER_H
