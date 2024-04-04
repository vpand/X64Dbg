#include "DialogExecMap.h"

#include <QDir>
#include <QFileInfo>
#include <QScrollArea>

#include "Bridge/Bridge.h"
#include "DisassemblerGraphView.h"
#include "Utils/StringUtil.h"
#include "ui_DialogExecMap.h"

DialogExecMap::DialogExecMap(DisassemblerGraphView *gview, QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogExecMap) {
  ui->setupUi(this);
  ui->verticalLayout->addWidget(gview);
  gview->setParent(this);
  gview->showNormal();
  ui->horizontalSliderPCChains->setSingleStep(1);
  ui->horizontalSliderPCChains->setMinimum(1);
  ui->horizontalSliderBBChains->setSingleStep(1);
  ui->horizontalSliderBBChains->setMinimum(1);
  ui->horizontalSliderBLChains->setSingleStep(1);
  ui->horizontalSliderBLChains->setMinimum(1);
  connect(ui->horizontalSliderPCChains, SIGNAL(valueChanged(int)), this,
          SLOT(valueChangedPCSlot(int)));
  connect(ui->horizontalSliderBBChains, SIGNAL(valueChanged(int)), this,
          SLOT(valueChangedBBSlot(int)));
  connect(ui->horizontalSliderBLChains, SIGNAL(valueChanged(int)), this,
          SLOT(valueChangedBLSlot(int)));
  connect(ui->pushButtonSync2PC, SIGNAL(clicked()), this, SLOT(syncToPCSlot()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(debugStateChangedSlot(DBGSTATE)));
}

DialogExecMap::~DialogExecMap() {
  freeResource();
  if (mModuleBin) {
    mana::Delete(mModuleBin);
  }
  delete ui;
}

void DialogExecMap::debugStateChangedSlot(DBGSTATE state) {
  if (state == stopped) {
    freeResource();
    mModulePath.clear();
    if (mModuleBin) {
      mana::Delete(mModuleBin);
      mModuleBin = nullptr;
    }
  }
}

void DialogExecMap::freeResource() {
  if (mAutoGenFunc) {
    delete mAutoGenFunc;
    mAutoGenFunc = nullptr;
  }
  if (mAutoGenFuncOpcodes) {
    delete mAutoGenFuncOpcodes;
    mAutoGenFuncOpcodes = nullptr;
  }
  mAutoGenFuncBBS.clear();
  mBBInds.clear();
  mBLInds.clear();
  mRecordCur = -1;
}

void DialogExecMap::valueChangedPCSlot(int value) {
  if (mDisableUpdatePC || !DbgIsDebugging() || !mRecordInds.size()) return;
  value--;
  auto sdbaddr = mRecordInds[mRecordCur][value];
  GuiDisasmAt(DbgGlobal::inst()->debugee->rtbase + sdbaddr - mRuntimeBase, 0);
  int prog = 1;
  auto fnrva = sdbaddr - mRecordInds[mRecordCur][0];
  for (auto &bbi : mBBInds) {
    auto &bb = mAutoGenFuncBBS[bbi];
    auto &istart = mAutoGenFunc->insns[bb.first];
    auto &iend = mAutoGenFunc->insns[bb.second];
    if (istart.fnoff <= fnrva && fnrva <= iend.fnoff) {
      mDisableUpdateBB = true;
      ui->horizontalSliderBBChains->setValue(prog);
      mDisableUpdateBB = false;
      break;
    }
    prog++;
  }
  updateSummery();
}

void DialogExecMap::valueChangedBBSlot(int value) {
  if (mDisableUpdateBB || !DbgIsDebugging() || !mRecordInds.size()) return;
  value--;
  auto sdbaddr =
      mRecordInds[mRecordCur][0] +
      mAutoGenFunc->insns[mAutoGenFuncBBS[mBBInds[value]].first].fnoff;
  GuiDisasmAt(DbgGlobal::inst()->debugee->rtbase + sdbaddr - mRuntimeBase, 0);
  int prog = 1;
  for (auto &pc : mRecordInds[mRecordCur]) {
    if (pc == sdbaddr) {
      mDisableUpdatePC = true;
      ui->horizontalSliderPCChains->setValue(prog);
      mDisableUpdatePC = false;
      break;
    }
    prog++;
  }
  updateSummery();
}

void DialogExecMap::valueChangedBLSlot(int value) {
  if (!DbgIsDebugging() || !mRecordInds.size()) return;
  ui->lineEditSummery->setText(
      QString("bl %1/%2").arg(value).arg(mBLInds.size()));
  value--;
  auto sdbaddr = mRecordInds[mRecordCur][mBLInds[value]];
  GuiDisasmAt(DbgGlobal::inst()->debugee->rtbase + sdbaddr - mRuntimeBase, 0);

  mDisableUpdatePC = true;
  mDisableUpdateBB = true;
  int prog = 1;
  for (auto &pc : mRecordInds[mRecordCur]) {
    if (pc == sdbaddr) {
      ui->horizontalSliderPCChains->setValue(prog);
      break;
    }
    prog++;
  }

  prog = 1;
  auto fnrva = sdbaddr - mRecordInds[mRecordCur][0];
  for (auto &bbi : mBBInds) {
    auto &bb = mAutoGenFuncBBS[bbi];
    auto &istart = mAutoGenFunc->insns[bb.first];
    auto &iend = mAutoGenFunc->insns[bb.second];
    if (istart.fnoff <= fnrva && fnrva <= iend.fnoff) {
      ui->horizontalSliderBBChains->setValue(prog);
      break;
    }
    prog++;
  }
  mDisableUpdatePC = false;
  mDisableUpdateBB = false;
}

void DialogExecMap::updateSummery() {
  ui->lineEditSummery->setText(QString("pc %1/%2, bb %3/%4")
                                   .arg(ui->horizontalSliderPCChains->value())
                                   .arg(mRecordInds[mRecordCur].size())
                                   .arg(ui->horizontalSliderBBChains->value())
                                   .arg(mBBInds.size()));
}

static void dbgaddr2node(duint dbgbase, duint dbgaddr, duint sdbbase,
                         duint sdbentry, const mana::Function *func,
                         const PageBuffers &pages, BridgeCFNode &node) {
  auto dbgentry = dbgbase + sdbentry - sdbbase;
  auto &insns = func->insns;
  auto curpage = sdbentry & ~UVMPAGE_MASK;
  auto mempage = pages.find(curpage);
  auto pcrva = dbgaddr - dbgbase;
  auto entryrva = sdbentry - sdbbase;
  auto pcfnoff = pcrva - entryrva;
  size_t starti = 0, prebbi = 0;
  for (auto &ii : insns) {
    if (ii.comins.size()) {
      prebbi = starti;
    }
    if (pcfnoff == ii.fnoff) {
      break;
    }
    starti++;
  }
  starti = prebbi;

  for (size_t i = starti; i < insns.size();) {
    for (bool bbend = false; i < insns.size() && !bbend; i++) {
      auto curi = &insns[i];
      if (curi->comins.size()) {
        if (node.instrs.size()) {
          bbend = true;
          node.split = true;
          node.brtrue = dbgentry + curi->fnoff;
          break;
        } else {
          // bb start
          // or
          // bl abort/__stack_chk_failed
        }
      }
      BridgeCFInstruction brinsn;
      brinsn.addr = sdbentry + curi->fnoff;
      auto pageaddr = brinsn.addr & ~UVMPAGE_MASK;
      if (pageaddr != curpage) {
        curpage = pageaddr;
        mempage = pages.find(curpage);
      }
      memcpy(brinsn.data, mempage->second.data() + brinsn.addr - curpage,
             sizeof(brinsn.data) - 1);
      brinsn.data[sizeof(brinsn.data) - 1] =
          func->start & 1;  // for arm/thumb flag
      // convert to debugee address
      brinsn.addr = dbgbase + brinsn.addr - sdbbase;
      node.instrs.push_back(brinsn);
      node.icount++;
      switch (curi->info.type) {
        case mana::JUMP:
        case mana::JCOND: {
          std::vector<int> gouts;
          for (auto i : curi->gouts) {
            if ((size_t)i >= insns.size()) {
              GuiAddLogMessage(
                  QString("Warning, bad gouts insn index %1 at %2.\n")
                      .arg(i)
                      .arg(ToPtrString(dbgentry + curi->fnoff))
                      .toUtf8()
                      .data());
              continue;
            }
            gouts.push_back(i);
          }
          bbend = true;
          if (gouts.size()) {
            if (gouts.size() >= 2) {
              node.brfalse = dbgentry + insns[gouts[0]].fnoff;
              node.brtrue = dbgentry + insns[gouts[1]].fnoff;
              for (size_t i = 2; i < gouts.size(); i++) {
                node.exits.push_back(dbgentry + insns[gouts[i]].fnoff);
              }
            } else {
              node.brtrue = dbgentry + insns[gouts[0]].fnoff;
            }
          } else {
            node.terminal = true;
          }
          break;
        }
        case mana::RET:
          bbend = true;
          node.terminal = true;
          break;
        default:
          break;
      }
    }
    node.start = node.instrs.begin()->addr;
    node.end = node.instrs.rbegin()->addr;
    if (node.brfalse) node.exits.push_back(node.brfalse);
    if (node.brtrue) node.exits.push_back(node.brtrue);
    break;
  }
}

static void show_graph_func(duint dbgbase, duint pc, duint sdbbase,
                            duint sdbentry, const mana::Function *func,
                            const PageBuffers &pages) {
  auto dbgentry = dbgbase + sdbentry - sdbbase;
  BridgeCFGraph graph(dbgentry);
  graph.userdata = (void *)dbgbase;

  // level 0
  BridgeCFNode node0(dbgentry, dbgentry, dbgentry);
  dbgaddr2node(dbgbase, pc, sdbbase, sdbentry, func, pages, node0);
  graph.AddNode(node0);
  // entry node
  if (pc != dbgentry) {
    BridgeCFNode nodee(dbgentry, dbgentry, dbgentry);
    nodee.brtrue = node0.start;
    nodee.exits.push_back(nodee.brtrue);
    graph.AddNode(nodee);
  }
  // level 1
  for (auto &dbgaddr1 : node0.exits) {
    BridgeCFNode node1(dbgentry, dbgentry, dbgentry);
    dbgaddr2node(dbgbase, dbgaddr1, sdbbase, sdbentry, func, pages, node1);
    graph.AddNode(node1);
    // level 2
    for (auto &dbgaddr2 : node1.exits) {
      BridgeCFNode node2(dbgentry, dbgentry, dbgentry);
      dbgaddr2node(dbgbase, dbgaddr2, sdbbase, sdbentry, func, pages, node2);
      graph.AddNode(node2);
      // level 3
      for (auto &dbgaddr3 : node2.exits) {
        BridgeCFNode node3(dbgentry, dbgentry, dbgentry);
        dbgaddr2node(dbgbase, dbgaddr3, sdbbase, sdbentry, func, pages, node3);
        graph.AddNode(node3);
      }
    }
  }
  BridgeCFGraphList glist = graph.ToGraphList();
  GuiLoadGraph(&glist, dbgentry);
}

bool DialogExecMap::syncToPCImpl() {
  auto debugee = DbgGlobal::inst()->debugee;
  auto pc = regPC();
  auto rva = pc - debugee->rtbase;
  int index = 0;
  for (auto &range : mRecordIndsMinMaxRVA) {
    if (range.first <= rva && rva < range.second) {
      break;
    }
    index++;
  }
  if (index >= mRecordInds.size()) {
    ui->lineEditSummery->setText("No pc sample found.");
    return false;
  }
  if (index != mRecordCur) {
    freeResource();
    mRecordCur = index;

    sample_params_t params;
    params.pages = &mPageBuffs;
    params.rawpages = &mPageRawBuffs;
    params.rtbase = mRuntimeBase;
    params.regsarm = &mRecordARMAll;
    params.regsarm64 = &mRecordARM64All;
    params.bin = mModuleBin;
    params.index = mRecordCur;
    params.index2 = nullptr;
    params.index2count = 0;
    params.indexs = &mRecordInds;
    params.opr = SOT_EXECUTED_PCBBS;
    if (sampledb_main(&params) != 0) {
      ui->lineEditSummery->setText("Bad license.");
      return false;
    }
    mAutoGenFunc = params.opr_func.fun;
    mAutoGenFuncOpcodes = params.opr_func.opc;
    int curi = 0;
    std::map<int, int> bbendrvas;
    for (size_t i = 0; i < mAutoGenFunc->insns.size(); i++) {
      auto &ii = mAutoGenFunc->insns[i];
      switch (ii.info.type) {
        case mana::JCOND:
        case mana::JUMP:
        case mana::RET: {
          bbendrvas.insert(
              {mRecordInds[mRecordCur][0] - mRuntimeBase + ii.fnoff,
               mAutoGenFuncBBS.size()});
          mAutoGenFuncBBS.push_back({curi, i});
          curi = i + 1;
          break;
        }
        default:
          break;
      }
    }
    if (curi < mAutoGenFunc->insns.size()) {
      bbendrvas.insert(
          {mRecordInds[mRecordCur][0] - mRuntimeBase +
               mAutoGenFunc->insns[mAutoGenFunc->insns.size() - 1].fnoff,
           mAutoGenFuncBBS.size()});
      mAutoGenFuncBBS.push_back({curi, (int)mAutoGenFunc->insns.size() - 1});
    }
    for (auto pc : mRecordInds[mRecordCur]) {
      auto pcrva = pc - mRuntimeBase;
      auto found = bbendrvas.find(pcrva);
      if (found != bbendrvas.end()) {
        mBBInds.push_back(found->second);
      }
    }

    params.opr = SOT_CALL_ADDRESSES;
    if (sampledb_main(&params) != 0) {
      ui->lineEditSummery->setText("Bad license.");
      return false;
    }
    for (size_t i = 0; i < mRecordInds[mRecordCur].size(); i++) {
      if (params.opr_indexs.find(mRecordInds[mRecordCur][i]) !=
          params.opr_indexs.end()) {
        mBLInds.push_back(i);
      }
    }

    ui->horizontalSliderPCChains->setMaximum(mRecordInds[mRecordCur].size());
    ui->horizontalSliderBBChains->setMaximum(mBBInds.size());
    ui->horizontalSliderBLChains->setMaximum(mBLInds.size());
  }

  QString summery;
  int prog = 1;
  for (auto &pc : mRecordInds[mRecordCur]) {
    if (pc - mRuntimeBase == rva) {
      ui->horizontalSliderPCChains->setValue(prog);
      summery +=
          QString("pc %1/%2, ").arg(prog).arg(mRecordInds[mRecordCur].size());
      break;
    }
    prog++;
  }

  prog = 1;
  auto fnrva = rva - (mRecordInds[mRecordCur][0] - mRuntimeBase);
  for (auto &bbi : mBBInds) {
    auto &bb = mAutoGenFuncBBS[bbi];
    auto &istart = mAutoGenFunc->insns[bb.first];
    auto &iend = mAutoGenFunc->insns[bb.second];
    if (istart.fnoff <= fnrva && fnrva <= iend.fnoff) {
      ui->horizontalSliderBBChains->setValue(prog);
      summery += QString("bb %1/%2").arg(prog).arg(mBBInds.size());
      break;
    }
    prog++;
  }

  ui->lineEditSummery->setText(summery);

  show_graph_func(debugee->rtbase, pc, mRuntimeBase, mRecordInds[mRecordCur][0],
                  mAutoGenFunc, mPageRawBuffs);
  return true;
}

void DialogExecMap::syncToPC() {
  if (!DbgIsDebugging()) return;
  auto debugee = DbgGlobal::inst()->debugee;
  if (!debugee) return;

  auto mdb = debugee->db;
  if (!mdb) return;
  QString mpath = debugee->path;
  QString *mappath = DbgGlobal::inst()->mapPath(mpath);
  if (mappath) mpath = *mappath;
  if (mpath == mModulePath) {
    syncToPCImpl();
    return;
  }

  QFileInfo finfo(mpath);
  QString sdbpath = finfo.dir().path() + "/" + finfo.baseName() + ".sdb";
  if (!QFileInfo(sdbpath).exists()) {
    ui->lineEditSummery->setText("No sdb found.");
    return;
  }

  freeResource();
  mRecordIndsMinMaxRVA.clear();
  if (mModuleBin) {
    mana::Delete(mModuleBin);
  }
  mModuleBin = mana::New(mpath.toUtf8().data(), nullptr, false);

  QByteArray sdbpathbuff = sdbpath.toUtf8();
  sample_params_t params;
  params.bin = mModuleBin;
  params.pages = &mPageBuffs;
  params.rawpages = &mPageRawBuffs;
  params.indexs = &mRecordInds;
  params.index = 0;
  params.regsarm = &mRecordARMAll;
  params.regsarm64 = &mRecordARM64All;
  params.outpath = sdbpathbuff.data();
  params.opr = SOT_LOAD;
  if (sampledb_main(&params) == 0) {
    mRuntimeBase = params.rtbase;
    size_t pchits = 0;
    switch (mdb->info.arch) {
      case mana::ARM:
        pchits = mRecordARMAll.size();
        break;
      case mana::ARM64:
        pchits = mRecordARM64All.size();
        break;
      default:
        return;
    }
    GuiAddLogMessage(QString("Loaded sample data from %1, runtime base %2, pc "
                             "hits %3, pc chains %4.\n")
                         .arg(mpath.data())
                         .arg(ToPtrString(mRuntimeBase))
                         .arg(pchits)
                         .arg(mRecordInds.size())
                         .toUtf8()
                         .data());
    mModulePath = mpath;
    for (auto &inds : mRecordInds) {
      auto min = inds[0], max = inds[0];
      for (auto pc : inds) {
        if (max < pc) {
          max = pc;
        }
      }
      mRecordIndsMinMaxRVA.push_back({min - mRuntimeBase, max - mRuntimeBase});
    }
    if (syncToPCImpl()) {
      loadDyndecSource();
    }
  } else {
    mRecordInds.clear();
    ui->lineEditSummery->setText("Failed to load sdb.");
  }
}

void DialogExecMap::loadDyndecSource() {
  QFileInfo finfo(mModulePath);
  QDir dir(finfo.dir());
  dir.setFilter(QDir::Dirs);
  QString rvamap;
  QString dyndecdir;
  for (auto info : dir.entryInfoList()) {
    QString filename = info.fileName();
    if (filename.startsWith(finfo.baseName())) {
      rvamap = info.absoluteFilePath() + "/rva.map";
      if (QFileInfo(rvamap).exists()) {
        dyndecdir = info.absoluteFilePath();
        break;
      }
    }
  }
  if (!dyndecdir.length()) {
    return;
  }
  QString adsrc = dyndecdir + "/a64dbg.c";
  if (!QFileInfo(adsrc).exists()) {
    QDir dir(dyndecdir);
    dir.setFilter(QDir::Files);
    QFile adsrcfile(adsrc);
    adsrcfile.open(QIODevice::WriteOnly);
    QFile rvamapfile(rvamap);
    rvamapfile.open(QIODevice::ReadOnly);
    std::map<int, int> rva2orig;
    while (true) {
      int rvas[2];
      if (!rvamapfile.read((char *)&rvas[0], sizeof(rvas))) {
        break;
      }
      rva2orig.insert({rvas[0], rvas[1]});
    }
    auto mdb = DbgGlobal::inst()->debugee;
    for (auto info : dir.entryInfoList()) {
      QString filename = info.fileName();
      if (filename.endsWith(".c") && filename != "a64dbg.c") {
        QFile srcfile(info.absoluteFilePath());
        if (srcfile.open(QIODevice::ReadOnly)) {
          QByteArray srcbuff = srcfile.readAll();
          const char *ptr = srcbuff.data();
          while (true) {
            const char *saddr = strstr(ptr, "// 0x");
            if (!saddr) {
              adsrcfile.write(ptr);
              break;
            }
            saddr += 3;
            adsrcfile.write(ptr, saddr - ptr);
            duint addr = strtoull(saddr, (char **)&ptr, 16);
            duint rva = addr - mdb->db->baseaddr;
            auto foundrva = rva2orig.find(rva);
            if (foundrva != rva2orig.end()) {
              char newsaddr[32];
              sprintf(newsaddr, "0x%llx", mdb->db->baseaddr + foundrva->second);
              adsrcfile.write(newsaddr);
            } else {
              GuiAddLogMessage(QString("Warning, cannot find rvamap for %1.\n")
                                   .arg(ToHexString(rva))
                                   .toUtf8()
                                   .data());
            }
          }
        }
      }
    }
    adsrcfile.close();
  }
  DbgGlobal::inst()->loadPseudoCode(adsrc, DbgGlobal::inst()->debugee, true);
}

void DialogExecMap::syncToPCSlot() { syncToPC(); }
