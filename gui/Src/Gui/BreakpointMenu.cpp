#include "BreakpointMenu.h"

#include <QAction>
#include <QMessageBox>

#include "Breakpoints.h"
#include "MenuBuilder.h"
#include "MiscUtil.h"
#include "StringUtil.h"

BreakpointMenu::BreakpointMenu(QWidget* parent, ActionHelperFuncs funcs,
                               GetSelectionFunc getSelection)
    : QObject(parent), ActionHelperProxy(funcs), mGetSelection(getSelection) {}

void BreakpointMenu::build(MenuBuilder* builder) {
  QAction* toggleBreakpointAction = makeShortcutAction(
      DIcon("breakpoint_toggle.png"), tr("Toggle"),
      std::bind(&BreakpointMenu::toggleInt3BPActionSlot, this),
      "ActionToggleBreakpoint");
  QAction* editSoftwareBreakpointAction =
      makeShortcutAction(DIcon("breakpoint_edit_alt.png"), tr("Edit"),
                         std::bind(&BreakpointMenu::editSoftBpActionSlot, this),
                         "ActionEditBreakpoint");
#if 0
  QAction* setHwBreakpointAction = makeShortcutAction(
      DIcon("breakpoint_execute.png"), tr("Set Hardware on Execution"),
      std::bind(&BreakpointMenu::toggleHwBpActionSlot, this), "ActionSetHwBpE");
  QAction* removeHwBreakpointAction =
      makeShortcutAction(DIcon("breakpoint_remove.png"), tr("Remove Hardware"),
                         std::bind(&BreakpointMenu::toggleHwBpActionSlot, this),
                         "ActionRemoveHwBp");

  QMenu* replaceSlotMenu = makeMenu(DIcon("breakpoint_execute.png"),
                                    tr("Set Hardware on Execution"));
  // Replacement slot menu are only used when the breakpoints are full, so using
  // "Unknown" as the placeholder. Might want to change this in case we display
  // the menu when there are still free slots.
  QAction* replaceSlot0Action = makeMenuAction(
      replaceSlotMenu, DIcon("breakpoint_execute_slot1.png"),
      tr("Replace Slot 0 (Unknown)"),
      std::bind(&BreakpointMenu::setHwBpOnSlot0ActionSlot, this));
  QAction* replaceSlot1Action = makeMenuAction(
      replaceSlotMenu, DIcon("breakpoint_execute_slot2.png"),
      tr("Replace Slot 1 (Unknown)"),
      std::bind(&BreakpointMenu::setHwBpOnSlot1ActionSlot, this));
  QAction* replaceSlot2Action = makeMenuAction(
      replaceSlotMenu, DIcon("breakpoint_execute_slot3.png"),
      tr("Replace Slot 2 (Unknown)"),
      std::bind(&BreakpointMenu::setHwBpOnSlot2ActionSlot, this));
  QAction* replaceSlot3Action = makeMenuAction(
      replaceSlotMenu, DIcon("breakpoint_execute_slot4.png"),
      tr("Replace Slot 3 (Unknown)"),
      std::bind(&BreakpointMenu::setHwBpOnSlot3ActionSlot, this));
#endif
  builder->addMenu(makeMenu(DIcon("breakpoint.png"), tr("Breakpoint")),
                   [=](QMenu* menu) {
                     auto selection = mGetSelection();
                     if (selection == 0) return false;
                     BPXTYPE bpType = DbgGetBpxTypeAt(selection);
                     if ((bpType & bp_normal) == bp_normal ||
                         (bpType & bp_hardware) == bp_hardware)
                       editSoftwareBreakpointAction->setText(tr("Edit"));
                     else
                       editSoftwareBreakpointAction->setText(
                           tr("Set Conditional Breakpoint"));
                     menu->addAction(editSoftwareBreakpointAction);

                     menu->addAction(toggleBreakpointAction);
#if 0
                     if ((bpType & bp_hardware) == bp_hardware) {
                       menu->addAction(removeHwBreakpointAction);
                     } else {
                       BPMAP bpList;
                       DbgGetBpList(bp_hardware, &bpList);

                       // get enabled hwbp count
                       int enabledCount = bpList.count;
                       for (int i = 0; i < bpList.count; i++)
                         if (!bpList.bp[i].enabled) enabledCount--;

                       if (enabledCount < 4) {
                         menu->addAction(setHwBreakpointAction);
                       } else {
                         for (int i = 0; i < bpList.count; i++) {
                           if (bpList.bp[i].enabled) {
                             switch (bpList.bp[i].slot) {
                               case 0:
                                 replaceSlot0Action->setText(
                                     tr("Replace Slot %1 (0x%2)")
                                         .arg(1)
                                         .arg(ToPtrString(bpList.bp[i].addr)));
                                 break;
                               case 1:
                                 replaceSlot1Action->setText(
                                     tr("Replace Slot %1 (0x%2)")
                                         .arg(2)
                                         .arg(ToPtrString(bpList.bp[i].addr)));
                                 break;
                               case 2:
                                 replaceSlot2Action->setText(
                                     tr("Replace Slot %1 (0x%2)")
                                         .arg(3)
                                         .arg(ToPtrString(bpList.bp[i].addr)));
                                 break;
                               case 3:
                                 replaceSlot3Action->setText(
                                     tr("Replace Slot %1 (0x%2)")
                                         .arg(4)
                                         .arg(ToPtrString(bpList.bp[i].addr)));
                                 break;
                               default:
                                 break;
                             }
                           }
                         }
                         menu->addMenu(replaceSlotMenu);
                       }
                       if (bpList.count) BridgeFree(bpList.bp);
                     }
#endif
                     return true;
                   });
}

void BreakpointMenu::toggleInt3BPActionSlot() {
  if (!DbgIsDebugging()) return;
  duint wVA = mGetSelection();
  BPXTYPE wBpType = DbgGetBpxTypeAt(wVA);
  QString wCmd;

  if ((wBpType & bp_normal) == bp_normal) {
    wCmd = "bc " + ToPtrString(wVA);
  } else {
    if (DbgFunctions()->IsDepEnabled() &&
        !DbgFunctions()->MemIsCodePage(wVA, false)) {
      QMessageBox msgyn(QMessageBox::Warning,
                        tr("Current address is not executable"),
                        tr("Setting software breakpoint here may result in "
                           "crash. Do you really want to continue?"),
                        QMessageBox::Yes | QMessageBox::No, (QWidget*)parent());
      msgyn.setWindowIcon(DIcon("compile-warning.png"));
      msgyn.setParent((QWidget*)parent(), Qt::Dialog);
      msgyn.setWindowFlags(msgyn.windowFlags() &
                           (~Qt::WindowContextHelpButtonHint));
      if (msgyn.exec() == QMessageBox::No) return;
    }
    wCmd = "bp " + ToPtrString(wVA);
  }

  DbgCmdExec(wCmd);
  // emit Disassembly::repainted();
}

void BreakpointMenu::editSoftBpActionSlot() {
  auto selection = mGetSelection();
  if (selection == 0) return;
  BPXTYPE bpType = DbgGetBpxTypeAt(selection);
  if ((bpType & bp_hardware) == bp_hardware)
    Breakpoints::editBP(bp_hardware, ToHexString(selection),
                        dynamic_cast<QWidget*>(parent()));
  else if ((bpType & bp_normal) == bp_normal)
    Breakpoints::editBP(bp_normal, ToHexString(selection),
                        dynamic_cast<QWidget*>(parent()));
  else {
    DbgCmdExecDirect(
        QString("bp %1").arg(ToHexString(selection)));  // Blocking call
    if (!Breakpoints::editBP(bp_normal, ToHexString(selection),
                             dynamic_cast<QWidget*>(parent())))
      Breakpoints::removeBP(bp_normal, selection);
  }
}

void BreakpointMenu::toggleHwBpActionSlot() {
  duint wVA = mGetSelection();
  BPXTYPE wBpType = DbgGetBpxTypeAt(wVA);
  QString wCmd;

  if ((wBpType & bp_hardware) == bp_hardware) {
    wCmd = "bphwc " + ToPtrString(wVA);
  } else {
    wCmd = "bphws " + ToPtrString(wVA);
  }

  DbgCmdExec(wCmd);
}

void BreakpointMenu::setHwBpOnSlot0ActionSlot() {
  setHwBpAt(mGetSelection(), 0);
}

void BreakpointMenu::setHwBpOnSlot1ActionSlot() {
  setHwBpAt(mGetSelection(), 1);
}

void BreakpointMenu::setHwBpOnSlot2ActionSlot() {
  setHwBpAt(mGetSelection(), 2);
}

void BreakpointMenu::setHwBpOnSlot3ActionSlot() {
  setHwBpAt(mGetSelection(), 3);
}

void BreakpointMenu::setHwBpAt(duint va, int slot) {
  int wI = 0;
  int wSlotIndex = -1;
  BPMAP wBPList;
  QString wCmd = "";

  DbgGetBpList(bp_hardware, &wBPList);

  // Find index of slot slot in the list
  for (wI = 0; wI < wBPList.count; wI++) {
    if (wBPList.bp[wI].slot == (unsigned short)slot) {
      wSlotIndex = wI;
      break;
    }
  }

  if (wSlotIndex < 0)  // Slot not used
  {
    wCmd = "bphws " + ToPtrString(va);
    DbgCmdExec(wCmd);
  } else  // Slot used
  {
    wCmd = "bphwc " + ToPtrString((duint)(wBPList.bp[wSlotIndex].addr));
    DbgCmdExec(wCmd);

    Sleep(200);

    wCmd = "bphws " + ToPtrString(va);
    DbgCmdExec(wCmd);
  }
  if (wBPList.count) BridgeFree(wBPList.bp);
}
