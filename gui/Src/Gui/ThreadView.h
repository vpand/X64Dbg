#ifndef THREADVIEW_H
#define THREADVIEW_H

#include <QMenu>

#include "StdTable.h"

class ThreadView : public StdTable {
  Q_OBJECT
 public:
  explicit ThreadView(StdTable* parent = 0);
  QString paintContent(QPainter* painter, dsint rowBase, int rowOffset, int col,
                       int x, int y, int w, int h);
  void setupContextMenu();

 public slots:
  void updateThreadList();
  void doubleClickedSlot();
  void ExecCommand();
  void GoToThreadEntry();
  void contextMenuSlot(const QPoint& pos);
  void SetNameSlot();
  void refreshList();

 private:
  QAction* makeCommandAction(QAction* action, const QString& command);
  duint mCurrentThreadId;
  MenuBuilder* mMenuBuilder;
};

#endif  // THREADVIEW_H
