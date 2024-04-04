#ifndef TRACEREGISTERS_H
#define TRACEREGISTERS_H

#include "CPURegistersView.h"
#include "CPURegistersViewA32.h"
#include "CPURegistersViewX64.h"
#include "CPURegistersViewX86.h"

class TraceRegistersA64 : public RegistersViewA64 {
  Q_OBJECT
 public:
  TraceRegistersA64(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyFloatingPointValueToClipboard;
  QAction* wCM_CopyAll;
  QAction* wCM_FollowInDisassembly;
  QAction* wCM_FollowInDump;

public slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

protected slots:
 void onCopyToClipboardAction();
 void onCopyFloatingPointToClipboardAction();
 void onFollowInDisassembly();
 void onFollowInDump();
};

class TraceRegistersA32 : public RegistersViewA32 {
  Q_OBJECT
 public:
  TraceRegistersA32(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyFloatingPointValueToClipboard;
  QAction* wCM_CopyAll;
  QAction* wCM_FollowInDisassembly;
  QAction* wCM_FollowInDump;

public slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

protected slots:
 void onCopyToClipboardAction();
 void onCopyFloatingPointToClipboardAction();
 void onFollowInDisassembly();
 void onFollowInDump();
};

class TraceRegistersX64 : public RegistersViewX64 {
  Q_OBJECT
 public:
  TraceRegistersX64(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyFloatingPointValueToClipboard;
  QAction* wCM_CopyAll;
  QAction* wCM_FollowInDisassembly;
  QAction* wCM_FollowInDump;

public slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

protected slots:
 void onCopyToClipboardAction();
 void onCopyFloatingPointToClipboardAction();
 void onFollowInDisassembly();
 void onFollowInDump();
};

class TraceRegistersX86 : public RegistersViewX86 {
  Q_OBJECT
 public:
  TraceRegistersX86(QWidget* parent = 0);

  void setRegisters(REGDUMP* registers);
  void setActive(bool isActive);

  QAction* wCM_CopyToClipboard;
  QAction* wCM_CopyFloatingPointValueToClipboard;
  QAction* wCM_CopyAll;
  QAction* wCM_FollowInDisassembly;
  QAction* wCM_FollowInDump;

public slots:
  virtual void displayCustomContextMenuSlot(QPoint pos);

protected slots:
 void onCopyToClipboardAction();
 void onCopyFloatingPointToClipboardAction();
 void onFollowInDisassembly();
 void onFollowInDump();
};

#endif  // TRACEREGISTERS_H
