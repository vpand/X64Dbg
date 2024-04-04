#pragma once

#include <QWidget>

#include "Bridge.h"

class QMenu;
class QHBoxLayout;
class StdSearchListView;
class SourceViewerManager;
class QVBoxLayout;

namespace Ui {
class UrDecompiler;
}

class UrDecompiler : public QWidget {
  Q_OBJECT

 public:
  explicit UrDecompiler(QWidget* parent = 0);
  ~UrDecompiler() override;
  void setupContextMenu();
  void saveWindowSettings();
  void loadWindowSettings();

  void invalidateSymbolSource(duint base);
  void reloadFunc();

 private slots:
  void updateStyle();
  void symbolFollow();
  void symbolFollowDump();
  void symbolDecompile();
  void symbolDynDecompile();
  void enterPressedSlot();
  void symbolContextMenu(QMenu* wMenu);
  void symbolRefreshCurrent();
  void toggleBreakpoint();
  void refreshShortcutsSlot();
  void emptySearchResultSlot();
  void dbgStateChangedSlot(DBGSTATE state);

 signals:
  void showReferences();

 private:
  Ui::UrDecompiler* ui;
  QHBoxLayout *mMainLayout;
  StdSearchListView* mSymbolList;
  SourceViewerManager* mSourceMgr;
  QAction* mFollowSymbolAction;
  QAction* mFollowSymbolDumpAction;
  QAction* mDecompileAction;
  QAction* mDynDecompileAction;
  QAction* mToggleBreakpoint;
  QMenu* mPluginMenu;

  static void cbSymbolEnum(SYMBOLINFO* symbol, void* user);
};
