#include "MainWindowCloseThread.h"

#include "Bridge.h"
#include "Imports.h"

MainWindowCloseThread::MainWindowCloseThread(QObject* parent)
    : QThread(parent) {}

void MainWindowCloseThread::run() {
  // DbgExit();
  Bridge::getBridge()->setDbgStopped();
  emit canClose();
}
