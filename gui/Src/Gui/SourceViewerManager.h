#ifndef SOURCEVIEWERMANAGER_H
#define SOURCEVIEWERMANAGER_H

#include <QMap>
#include <QPushButton>
#include <QTabWidget>

#include "SourceView.h"

class SourceViewerManager : public QTabWidget {
  Q_OBJECT
 public:
  explicit SourceViewerManager(QWidget* parent = 0);

 public slots:
  void loadSourceFile(QString path, duint addr);
  void closeTab(int index);
  void closeAllTabs();
  void dbgStateChanged(DBGSTATE state);

 private:
  QPushButton* mCloseAllTabs;
};

#endif  // SOURCEVIEWERMANAGER_H
