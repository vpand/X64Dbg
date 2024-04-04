#pragma once

#include <QWidget>

#include "Bridge.h"

class QMenu;
class StdSearchListView;
class SearchListView;
class HyperTraceSymbolSearchList;
class HyperTraceManager;
class QVBoxLayout;

namespace Ui {
class HyperTraceView;
}

class HyperTraceView : public QWidget {
  Q_OBJECT

 public:
  explicit HyperTraceView(QWidget* parent = 0);
  ~HyperTraceView() override;
  void setupContextMenu();
  void addTraceModule(const SYMBOLMODULEINFO &module);
  void clearDatabase();

  QVector<QByteArray> mDatabase;

 public slots:
  void updateStyle();
  void debugStateChangedSlot(DBGSTATE state);
  void addMsgToSymbolLogSlot(const QString &msg);
  void clearSymbolLogSlot();
  void moduleSelectionChanged(int index);
  void symbolDecompile();
  void symbolFollow();
  void symbolFollowDump();
  void symbolFollowImport();
  void symbolSelectModule(duint base);
  void enterPressedSlot();
  void symbolContextMenu(QMenu* wMenu);
  void symbolRefreshCurrent();
  void moduleContextMenu(QMenu* wMenu);
  void moduleFollow();
  void moduleEntryFollow();
  void moduleHyperTraceDel();
  void moduleCopyPath();
  void toggleBreakpoint();
  void toggleBookmark();
  void refreshShortcutsSlot();
  void emptySearchResultSlot();
  void selectionGetSlot(SELECTIONDATA* selection);
  void funcSelectionChanged(int index);

 signals:
  void showReferences();

private:
  void addTraceSpecial();

 private:
  Ui::HyperTraceView* ui;
  QVBoxLayout* mMainLayout;
  QVBoxLayout* mSymbolLayout;
  HyperTraceManager* mMgrView;
  QWidget* mSymbolPlaceHolder;
  SearchListView* mSymbolList;
  StdSearchListView* mModuleList;
  HyperTraceSymbolSearchList* mSymbolSearchList;
  QMap<QString, duint> mModuleBaseList;
  QAction* mDecompileSymbolAction;
  QAction* mFollowSymbolAction;
  QAction* mFollowSymbolDumpAction;
  QAction* mFollowSymbolImportAction;
  QAction* mToggleBreakpoint;
  QAction* mToggleBookmark;
  QAction* mFollowModuleAction;
  QAction* mFollowModuleEntryAction;
  QAction* mUnTraceModuleAction;
  QAction* mCopyPathAction;
  QMenu* mPluginMenu;
};

extern HyperTraceView *hypertraceView;
