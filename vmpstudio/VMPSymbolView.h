#ifndef VMPSYMBOLVIEW_H
#define VMPSYMBOLVIEW_H

#include <QProcess>
#include <QWidget>

#include "Bridge.h"

class QMenu;
class StdSearchListView;
class SearchListView;
class SymbolSearchList;
class QVBoxLayout;
class ZehSymbolTable;

namespace Ui {
class VMPSymbolView;
}

class VMPSymbolView : public QWidget {
  Q_OBJECT

 public:
  explicit VMPSymbolView(QWidget* parent = 0);
  ~VMPSymbolView() override;
  void setupContextMenu();
  void saveWindowSettings();
  void loadWindowSettings();

  static void getSymbolInfo(const SYMBOLPTR* symbolptr, SYMBOLINFO* info);
 private slots:
  void updateStyle();
  void addMsgToSymbolLogSlot(QString msg);
  void clearSymbolLogSlot();
  void moduleSelectionChanged(int index);
  void symbolSelectModule(duint base);
  void symbolContextMenu(QMenu* wMenu);
  void moduleContextMenu(QMenu* wMenu);
  void moduleCopyPath();
  void toggleVMP();
  void toggleVMPSels();
  void refreshShortcutsSlot();
  void emptySearchResultSlot();
  void selectionGetSlot(SELECTIONDATA* selection);
  void funcSelectionChanged(int index);
  void moduleAdd();
  void moduleAddCfg();
  void moduleDelete();
  void moduleDeleteAndCfg();
  void moduleVMPCommit();
  void moduleVMPCancel();
  void onReadProcessOutputData();
  void onReadProcessErrorData();
  void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

 signals:
  void showReferences();

 private:
  void updateSymbolList();

  struct FuncInfo {
    duint start;
    duint end;
    std::string name;
    bool vmp;
  };
  struct ModuleInfo {
    duint base;
    QVector<FuncInfo> funcs;
  };
  QMap<QString, ModuleInfo> mModules;
  QProcess mVMPProcess;
  void vmpCommit(const char* pvmproot, const char* libdirs, duint rtstatic,
                 const QString& path, const ModuleInfo& minfo);
  void vmpCommit();

 private:
  Ui::VMPSymbolView* ui;
  QVBoxLayout* mMainLayout;
  QVBoxLayout* mSymbolLayout;
  QWidget* mSymbolPlaceHolder;
  SearchListView* mSymbolList;
  StdSearchListView* mModuleList;
  SymbolSearchList* mSymbolSearchList;
  QAction* mAddModule;
  QAction* mDelModule;
  QAction* mAddModuleCfg;
  QAction* mDelModuleAndCfg;
  QAction* mToggleVMP;
  QAction* mToggleVMPSels;
  QAction* mVMPCommit;
  QAction* mVMPCancel;
  QMenu* mPluginMenu;
  ZehSymbolTable* mCurSymTable = nullptr;
  FuncInfo* mCurFunc = nullptr;
  QMap<QString, ModuleInfo>::iterator mCurCommit;
};

#endif  // VMPSYMBOLVIEW_H
