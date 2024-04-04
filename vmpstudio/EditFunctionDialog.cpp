#include "EditFunctionDialog.h"

#include "CPUWidgetFile.h"
#include "Configuration.h"
#include "MainWindow.h"
#include "MiscUtil.h"
#include "StringUtil.h"
#include "VMPGlobal.h"
#include "UrDecompiler.h"
#include "ui_EditFunctionDialog.h"

EditFunctionDialog::EditFunctionDialog(QWidget *parent, const VMPManaFunc *fn)
    : QDialog(parent), ui(new Ui::EditFunctionDialog) {
  ui->setupUi(this);
  auto vg = VMPGlobal::inst();
  auto mdb = vg->debugee;
  if (*fn) {
    std::string name = vg->diser(fn->func)->demangle(fn->func->name.data());
    ui->editFunctionName->setText(name.size() ? name.data()
                                              : fn->func->name.data());
    ui->editStart->setText(ToPtrString(mdb->rtbase + fn->rvastart));
    ui->editEnd->setText(ToPtrString(mdb->rtbase + fn->rvaend));
    if (fn->thumb()) {
      ui->checkBoxThumb->setChecked(true);
    } else {
      ui->checkBoxThumb->setChecked(false);
    }

    changed = false;
  }
  if (mdb->db->archType() != mana::ARM) {
    ui->checkBoxThumb->hide();
  }
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);
  setWindowIcon(DIcon("label.png"));
  connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(buttonOK()));

  Config()->setupWindowPos(this);
}

EditFunctionDialog::~EditFunctionDialog() {
  Config()->saveWindowPos(this);
  delete ui;
}

void EditFunctionDialog::splitFunction(const QString &name,
                                       const VMPManaFunc &func1,
                                       addr_t midaddr) {
  auto vg = VMPGlobal::inst();
  auto mdb = vg->debugee;
  GuiAddLogMessage(QString("Create new function %1 %2,%3.\n")
                       .arg(name)
                       .arg(ToPtrString(midaddr))
                       .arg(ToPtrString(func1.func->end))
                       .toUtf8()
                       .data());
  auto &newfunc = mdb->db->insertFunc(midaddr);
  newfunc.name = name.toUtf8().data();
  newfunc.start = midaddr | ui->checkBoxThumb->isChecked();
  newfunc.end = func1.func->end;
  GuiAddLogMessage(QString("Reset %1's end from %2 to %3.\n")
                       .arg(func1.func->name.data())
                       .arg(ToPtrString(func1.func->end))
                       .arg(ToPtrString(midaddr))
                       .toUtf8()
                       .data());
  func1.func->end = midaddr;
  analyzee.push_back(&newfunc);
  analyzee.push_back(func1.func);
}

void EditFunctionDialog::buttonOK() {
  auto vg = VMPGlobal::inst();
  auto mdb = vg->debugee;
  QString name = ui->editFunctionName->text();
  if (!name.size()) {
    GuiAddLogMessage("Empty name.\n");
    return;
  }
  addr_t start = strtoul(ui->editStart->text().toUtf8().data(), nullptr, 16);
  addr_t end = strtoul(ui->editEnd->text().toUtf8().data(), nullptr, 16);
  if (start >= end) {
    GuiAddLogMessage("Invalid function address, start >= end.\n");
    return;
  }
  VMPManaFunc func1 = mdb->rvaToFunction(start - mdb->rtbase, false);
  VMPManaFunc func2 = mdb->rvaToFunction(end - 1 - mdb->rtbase, false);
  if (!func1) {
    GuiAddLogMessage(QString("Invalid function start address %1.\n")
                         .arg(start)
                         .toUtf8()
                         .data());
    return;
  }
  if (!func2) {
    GuiAddLogMessage(
        QString("Invalid function end address %1.\n").arg(end).toUtf8().data());
    return;
  }
  if (!(func1 == func2 || func1.rvaend == func2.rvastart)) {
    GuiAddLogMessage(
        "Invalid function start and end address, they must be in the same or "
        "in the near function.\n");
    return;
  }
  mdb->func_cache.reset();

  if (func1 == func2 && func1.rvastart + mdb->rtbase == start &&
      func1.rvaend + mdb->rtbase == end) {
    if (name == func1.func->name.data()) {
      if (mdb->db->archType() == mana::ARM) {
        if (ui->checkBoxThumb->isChecked()) {
          if (!func1.thumb()) {
            func1.func->start |= 1;
            GuiAddLogMessage(QString("Changed %1 to thumb function.\n")
                                 .arg(name)
                                 .toUtf8()
                                 .data());
            changed = true;
            return;
          }
        } else {
          if (func1.thumb()) {
            func1.func->start &= ~1;
            GuiAddLogMessage(QString("Changed %1 to arm function.\n")
                                 .arg(name)
                                 .toUtf8()
                                 .data());
            changed = true;
            return;
          }
        }
      }
      GuiAddLogMessage("Nothing changed.\n");
    } else {
      GuiAddLogMessage(QString("Renamed function from %1 to %2.\n")
                           .arg(func1.func->name.data())
                           .arg(name)
                           .toUtf8()
                           .data());
      func1.func->name = name.toUtf8().data();
      changed = true;
      return;
    }
    return;
  }

  mana::Functions &dbfns = mdb->db->functions();
  if (func1 == func2) {
    if (start == func1.rvastart + mdb->rtbase) {
      func1.func->name = name.toUtf8().data();
      func1.func->start |= ui->checkBoxThumb->isChecked();
      splitFunction(name + "_splited", func1, end);
    } else if (end == func1.func->end) {
      if (name == func1.func->name.data()) {
        GuiAddLogMessage(QString("There already has function %1.\n")
                             .arg(name)
                             .toUtf8()
                             .data());
        return;
      }
      splitFunction(name, func1, start);
    } else {
      if (name == func1.func->name.data()) {
        GuiAddLogMessage(QString("There already has function %1.\n")
                             .arg(name)
                             .toUtf8()
                             .data());
        return;
      }
      splitFunction(name, func1, start);
      VMPManaFunc newfunc =
          mdb->rvaToFunction(start - mdb->db->imageBase(), true);
      splitFunction((func1.func->name + "_splited").data(), newfunc, end);
    }
  } else {
    if (start == func1.rvastart + mdb->rtbase) {
      func1.func->name = name.toUtf8().data();
      func1.func->start |= ui->checkBoxThumb->isChecked();
      func1.func->end = end;
      func2.func->start = end | func2.thumb();
      analyzee.push_back(func1.func);
      analyzee.push_back(&dbfns.insert({end, func2.func[0]}).first->second);
      dbfns.erase(dbfns.find(func2.rvastart + mdb->db->imageBase()));
    } else if (end == func2.func->end) {
      if (name == func1.func->name.data() || name == func2.func->name.data()) {
        GuiAddLogMessage(QString("There already has function %1.\n")
                             .arg(name)
                             .toUtf8()
                             .data());
        return;
      }
      func1.func->end = start;
      func2.func->name = name.toUtf8().data();
      func2.func->start = start | ui->checkBoxThumb->isChecked();
      analyzee.push_back(func1.func);
      analyzee.push_back(&dbfns.insert({start, func2.func[0]}).first->second);
      dbfns.erase(dbfns.find(func2.rvastart + mdb->db->imageBase()));
    } else {
      if (name == func1.func->name.data() || name == func2.func->name.data()) {
        GuiAddLogMessage(QString("There already has function %1.\n")
                             .arg(name)
                             .toUtf8()
                             .data());
        return;
      }
      GuiAddLogMessage(QString("Create new function %1 %2,%3.\n")
                           .arg(name)
                           .arg(ToPtrString(start))
                           .arg(ToPtrString(end))
                           .toUtf8()
                           .data());
      auto &newfunc = dbfns.insert({start, mana::Function()}).first->second;
      newfunc.name = name.toUtf8().data();
      newfunc.start = start | ui->checkBoxThumb->isChecked();
      newfunc.end = end;
      GuiAddLogMessage(QString("Reset %1's end from %2 to %3.\n")
                           .arg(func1.func->name.data())
                           .arg(ToPtrString(func1.func->end))
                           .arg(ToPtrString(start))
                           .toUtf8()
                           .data());
      func1.func->end = start;
      GuiAddLogMessage(QString("Reset %1's start from %2 to %3.\n")
                           .arg(func2.func->name.data())
                           .arg(ToPtrString(func2.func->start))
                           .arg(ToPtrString(end))
                           .toUtf8()
                           .data());
      func2.func->start = end | func2.thumb();
      analyzee.push_back(&newfunc);
      analyzee.push_back(func1.func);
      analyzee.push_back(&dbfns.insert({end, func2.func[0]}).first->second);
      dbfns.erase(dbfns.find(func2.rvastart + mdb->db->imageBase()));
    }
  }
  changed = true;
  procResult();
}

void EditFunctionDialog::procResult() {
  if (changed) {
    mainWin->cpuWidget()->reloadFunc();
    mainWin->urdecWidget()->reloadFunc();
  }
  if (analyzee.size()) {
    QThread *anathread = QThread::create(
        [](std::vector<mana::Function *> fns) {
          int tmpprog;
          auto *vg = VMPGlobal::inst();
          auto *mdb = vg->debugee;
          for (auto &f : fns) {
            mana::analyze_progress(QString("Analyzing %1...\n")
                                       .arg(f->name.data())
                                       .toUtf8()
                                       .data(),
                                   -1, -1, tmpprog);
            f->reset();
            auto func = mdb->cvtFunction(f);
            mdb->db->analyzeFunc(
                VMPGlobal::inst()->diser(f),
                mdb->db->addrBuff(func.rvastart + mdb->db->imageBase()), *f);
          }
          mana::analyze_progress("Finished re-analyzing functions.\n", -1, -1,
                                 tmpprog);
        },
        analyzee);
    QEventLoop eloop;
    anathread->connect(anathread, SIGNAL(finished()), &eloop, SLOT(quit()));
    anathread->start();
    eloop.exec();
    delete anathread;
    GuiUpdateDisassemblyView();
  }
}
