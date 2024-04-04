#ifndef TRACEREGISTERS_H
#define TRACEREGISTERS_H

#include "RegistersView.h"
#include "RegistersViewA32.h"
#include "RegistersViewX64.h"
#include "UVMGlobal.h"

class TraceRegistersA64 : public RegistersViewA64 {
  Q_OBJECT
 public:
  TraceRegistersA64(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

protected slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

  void onCopyToClipboardAction();

private:
  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyAll;
};

class TraceRegistersA32 : public RegistersViewA32 {
  Q_OBJECT
 public:
  TraceRegistersA32(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

protected slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

  void onCopyToClipboardAction();

private:
  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyAll;
};

class TraceRegistersX64 : public RegistersViewX64 {
  Q_OBJECT
 public:
  TraceRegistersX64(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

protected slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

  void onCopyToClipboardAction();

private:
  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyAll;
};

#endif  // TRACEREGISTERS_H
