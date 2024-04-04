#include "UVMTraceWidget.h"

#include "LogView.h"
#include "StdTable.h"
#include "UVMTraceBrowser.h"
#include "UVMTraceFileReader.h"
#include "UVMTraceRegisters.h"
#include "UVMSEOptionDialog.h"
#include "VMPBridgeMain.h"
#include "ui_TraceWidget.h"

// textobot httpsvr port
#define TB_HTTP_PORT "30330"

UVMTraceWidget *uvmWin;
int vmpstudioPort = 30332;

QString tools_dir() {
#if __APPLE__
  return VMPGlobal::inst()->exeDir() + "/../tools";
#elif __linux__
  return VMPGlobal::inst()->exeDir() + "/../uvmdbg-ndk/bin";
#else
  return VMPGlobal::inst()->exeDir() + "/tools";
#endif
}

QString svr_shell(const QString &cmds, bool result, bool timeout) {
  return uvmWin->uvmShell(cmds, result, timeout);
}

QByteArray svr_getfile(const QByteArray &path, const QString &outpath) {
  QByteArray buf;
  QEventLoop eloop;
  auto meta = std::make_pair(&buf, &eloop);
  uvmWin->uvmSend(uvmct_c2s_getfile, path.data(), path.size() + 1,
                  (uint64_t)&meta);
  eloop.exec();
  if (outpath.length()) {
    QFile file(outpath);
    if (file.open(QIODevice::WriteOnly)) {
      file.write(buf);
    }
  }
  return buf;
}

void svr_postfile(const QString &path, const QByteArray &remotepath) {
  QEventLoop eloop;
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly)) {
    return;
  }
  QByteArray filebuff = file.readAll();
  // size + filebuffer + path
  int bufsz = 4 + filebuff.length() + remotepath.length() + 1;
  char *buff = new char[bufsz];
  *(int *)buff = filebuff.length();
  memcpy(buff + 4, filebuff.data(), filebuff.length());
  strcpy(buff + 4 + filebuff.length(), remotepath.data());
  uvmWin->uvmSend(uvmct_c2s_postfile, buff, bufsz, (uint64_t)&eloop);
  eloop.exec();
  delete[] buff;
}

UVMTraceWidget::UVMTraceWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TraceWidget) {
  ui->setupUi(this);

  uvmWin = this;
  mTraceWidget = new TraceBrowser(this);
  mOverview = new StdTable(this);
  mInfo = new LogView(this);
  // disasm
  ui->mTopLeftUpperRightFrameLayout->addWidget(mTraceWidget);
  // registers
  mGeneralRegsA64 = new TraceRegistersA64(this);
  mGeneralRegsA64->setFixedWidth(1000);
  mGeneralRegsA64->ShowFPU(true);

  mGeneralRegsA32 = new TraceRegistersA32(this);
  mGeneralRegsA32->setFixedWidth(1000);
  mGeneralRegsA32->ShowFPU(true);

  mGeneralRegsX64 = new TraceRegistersX64(this);
  mGeneralRegsX64->setFixedWidth(1000);
  mGeneralRegsX64->ShowFPU(true);

  mGeneralRegsArea = new QScrollArea(this);
  mGeneralRegsArea->setFrameShape(QFrame::NoFrame);
  activeRegister(mGeneralRegsA64);

  mGeneralRegsArea->horizontalScrollBar()->setStyleSheet(
      ConfigHScrollBarStyle());
  mGeneralRegsArea->verticalScrollBar()->setStyleSheet(ConfigVScrollBarStyle());

  QPushButton *button_changeview = new QPushButton("", this);
  button_changeview->setStyleSheet(
      "Text-align:left;padding: 4px;padding-left: 10px;");
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsA64,
          SLOT(onChangeFPUViewAction()));
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsA32,
          SLOT(onChangeFPUViewAction()));
  connect(button_changeview, SIGNAL(clicked()), mGeneralRegsX64,
          SLOT(onChangeFPUViewAction()));
  connect(mTraceWidget, SIGNAL(selectionChanged(unsigned long long)), this,
          SLOT(traceSelectionChanged(unsigned long long)));
  connect(Bridge::getBridge(), SIGNAL(updateTraceBrowser()), this,
          SLOT(updateSlot()));
  connect(Bridge::getBridge(), SIGNAL(dbgStateChanged(DBGSTATE)), this,
          SLOT(debugStateChangedSlot(DBGSTATE)));
  connect(mTraceWidget, SIGNAL(addLog(QByteArray)), this,
          SLOT(addLogSlot(QByteArray)));
  connect(mInfo, SIGNAL(anchorClicked(QUrl)), this,
          SLOT(onAnchorClicked(QUrl)));

  mGeneralRegsA64->SetChangeButton(button_changeview);
  mGeneralRegsA32->SetChangeButton(button_changeview);
  mGeneralRegsX64->SetChangeButton(button_changeview);

  ui->mTopRightUpperFrameLayout->addWidget(button_changeview);
  ui->mTopRightUpperFrameLayout->addWidget(mGeneralRegsArea);
  // info
  ui->mTopLeftLowerFrameLayout->addWidget(mInfo);
  ui->mTopHSplitter->setSizes(QList<int>({1000, 1}));
  ui->mTopLeftVSplitter->setSizes(QList<int>({1000, 1}));

  // overview
  ui->mTopRightLowerFrameLayout->addWidget(mOverview);

  // set up overview
  mOverview->addColumnAt(0, "", true);
  mOverview->setShowHeader(false);
  mOverview->setRowCount(4);
  mOverview->setCellContent(0, 0, "hello");
  mOverview->setCellContent(1, 0, "world");
  mOverview->setCellContent(2, 0, "00000000");
  mOverview->setCellContent(3, 0,
                            "here we will list all control flow transfers");
  mOverview->hide();

#if STUDIO_ENABLE_URANIUMVM
  SCRIPTTYPEINFO info;
  strcpy_s(info.name, "UVMShell");
  info.id = 0;
  info.execute = [](const char *cmd) {
    GuiAddLogMessage(QString("(uvm) %1\n%2")
                         .arg(cmd)
                         .arg(uvmWin->uvmShell(cmd, true, true))
                         .toUtf8()
                         .data());
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);

#if __APPLE__
  QThread::create([] { UVMServer::start(); })->start();
#endif
#endif  // end of STUDIO_ENABLE_URANIUMVM
}

UVMTraceWidget::~UVMTraceWidget() {
#if STUDIO_ENABLE_URANIUMVM
  mUVMClient.close();
  mUVMServer.stop();
  if (m_fridasvr.isOpen()) {
    m_fridasvr.terminate();
    m_fridasvr.kill();
    m_fridasvr.waitForFinished();
  }

#if __APPLE__
  UVMServer::stop();
#endif
#endif  // end of STUDIO_ENABLE_URANIUMVM

  delete ui;
}

void UVMTraceWidget::detach() {
  if (!isAttached()) return;
  mRuntimeBase = 0;

  mUVMServer.disconnect();
  mRecordARMAll.clear();
  mRecordARMCur.clear();
  mRecordARM64All.clear();
  mRecordARM64Cur.clear();
  mRecordX64All.clear();
  mRecordX64Cur.clear();
  mRecordInds.clear();
  mPageBuffs.clear();
  mPageRawBuffs.clear();
  mRecordCur = 0;

  Bridge::getBridge()->updateTraceBrowser();
  updateSlot();
  GuiAddLogMessage("Detached from remote uvm debugee.\n");
}

static QString uvmserver_ip();
static void uvmclient_protocol(UVMSVR_CommandType type, const char *buf,
                               int bufsz, uint64_t extra);

void UVMTraceWidget::setupUVMServer() {
  // connect to remote uvmserver
  mUVMClient.connect(uvmserver_ip().toUtf8().data(), uvmclient_protocol);

  // create local vmpstudio uvmse server
  QThread::create([this]() {
    mUVMServer.start(
        [this]() {
          auto debugee = VMPGlobal::inst()->debugee;
          if (!debugee) {
            GuiAddLogMessage("There's no debugee module loaded by LightIDA.\n");
            return;
          }
          auto fname = QFileInfo(debugee->path).fileName().toUtf8();
          mUVMServer.send(udct_s2c_init, fname.data(), fname.length() + 1,
                          debugee->opcsize);
        },
        [this](UVMDBG_CommandType type, const char *buf, int bufsz,
               uint64_t extra) { parseUVMProtocol(type, buf, bufsz, extra); });
  })->start();

#if __APPLE__
  QString fridasvr(tools_dir() + "/frida-server");
  if (QFileInfo(fridasvr).exists()) {
    m_fridasvr.setProgram(fridasvr);
    m_fridasvr.start();
    if (m_fridasvr.waitForStarted()) {
      GuiAddLogMessage("Running local frida server...\n");
    } else {
      const QString msg = tr("Unable to start frida-server \"%1\": %2.\n")
                              .arg(fridasvr, m_fridasvr.errorString());
      GuiAddLogMessage(msg.toUtf8().data());
    }
  }
#endif
}

void UVMTraceWidget::parseUVMProtocol(UVMDBG_CommandType type, const char *buf,
                                      int bufsz, uint64_t extra) {
  switch (type) {
    case udct_disconnect: {
      mUVMServer.disconnect();
      GuiAddLogMessage("Disconnected to remote uvm client.\n");
      return;
    }
    case udct_c2s_ready: {
      mRuntimeBase = extra;
      GuiAddLogMessage(
          QString("Initialize image %1's runtime base as %2.\n")
              .arg(QFileInfo(VMPGlobal::inst()->debugee->path).fileName())
              .arg(ToPtrString(mRuntimeBase))
              .toUtf8()
              .data());
      if (VMPGlobal::inst()->isCloudPlatform()) {
        auto debugee = VMPGlobal::inst()->debugee;
        int *rvas = new int[2 * debugee->db->functions().size() + 1];
        int *rvaptr = rvas;
        for (auto &f : debugee->db->functions()) {
          *rvaptr++ = f.second.start - debugee->db->imageBase();
          *rvaptr++ = f.second.end - 4 - debugee->db->imageBase();
        }
        *rvaptr++ = 0;
        mUVMServer.send(udct_s2c_init, (char *)rvas, (char *)rvaptr - (char *)rvas, *(int *)"rva");
        delete[] rvas;
      }
      else {
        if (UVMSEOptionDialog::depth || (UVMSEOptionDialog::rvaStart && UVMSEOptionDialog::rvaEnd)) {
          uvmTraceOptions(UVMSEOptionDialog::depth, UVMSEOptionDialog::rvaStart,
                          UVMSEOptionDialog::rvaEnd);
        }
      }
      GuiExecuteOnGuiThread([] {
        // notify plugin
        VSPluginManager::inst()->sendEvent(vsp_event_sample_initialized);
      });
      return;
    }
    case udct_c2s_log: {
      GuiAddLogMessage(buf);
      return;
    }
    case udct_c2s_stopped: {
      switch (VMPGlobal::inst()->debugee->db->archType()) {
        case mana::ARM:
          updateRecord<RecordARM, arm_pcreg_record_header_t, arm_subregs_t>(
              &mRecordARMAll, &mRecordARMCur, buf, bufsz);
          break;
        case mana::ARM64:
          updateRecord<RecordARM64, arm64_pcreg_record_header_t,
                       arm64_subregs_t>(&mRecordARM64All, &mRecordARM64Cur, buf,
                                        bufsz);
          break;
        default:
          updateRecord<RecordX64, x64_pcreg_record_header_t,
                       x64_subregs_t>(&mRecordX64All, &mRecordX64Cur, buf,
                                      bufsz);
          break;
      }
      return;
    }
    case udct_c2s_memory: {
      mPageBuffs.insert({extra, std::string(buf, UVMPAGE_SIZE)});
      mPageRawBuffs.insert({extra, std::string(buf, UVMPAGE_SIZE)});
      // addLog(QString("Fetched memory page %1.\n").arg(ToPtrString(extra)));
      return;
    }
    default:
      break;
  }
  GuiAddLogMessage(QString("Unknown remote packet type %1 size %2.\n")
                       .arg(type)
                       .arg(bufsz)
                       .toUtf8()
                       .data());
}

void UVMTraceWidget::traceSelectionChanged(unsigned long long selinfo) {
  unsigned int *selinfoptr = (unsigned int *)&selinfo;
  unsigned int selection = selinfoptr[0];
  switch (selinfoptr[1]) {
    case 1:
      m_regctxindex--;
      if (m_regctxindex < 0) {
        m_regctxindex = 0;
      }
      break;
    case 2:
      m_regctxindex++;
      break;
    default:
      break;
  }
  auto debugee = VMPGlobal::inst()->debugee;
  auto trace = mTraceWidget->getTraceFile();
  if (!debugee || !mTraceWidget->isFileOpened()) return;
  if (debugee->db->archType() == mana::ARM64) {
    REGDUMPA64 regdump;
    memset(&regdump, 0, sizeof(regdump));
    auto rptr = (RecordItemARM64 *)trace->Registers(selection);
    if (!rptr) return;
    if (m_regctxindex >= rptr->second.size()) {
      m_regctxindex = rptr->second.size() - 1;
    }
    arm64_subregs_t &rvals = rptr->second[m_regctxindex];
    memcpy(&regdump.regcontext.gpr[0], rvals.gprs,
           sizeof(regdump.regcontext.gpr));
    regdump.flags |= (rvals.flags & 1) ? 0x80000000 : 0;
    regdump.flags |= (rvals.flags & 2) ? 0x40000000 : 0;
    regdump.flags |= (rvals.flags & 4) ? 0x20000000 : 0;
    regdump.flags |= (rvals.flags & 8) ? 0x10000000 : 0;
    regdump.regcontext.clr = rvals.gprs[30];
    regdump.regcontext.cip = rptr->first;
    regdump.n = (regdump.flags & 0x80000000) != 0;
    regdump.z = (regdump.flags & 0x40000000) != 0;
    regdump.c = (regdump.flags & 0x20000000) != 0;
    regdump.v = (regdump.flags & 0x10000000) != 0;
    mGeneralRegsA64->setRegisters(&regdump);
    GuiAddStatusBarMessage(QString("Loaded %1 register context %2/%3.\n")
                               .arg(ToPtrString(rptr->first))
                               .arg(m_regctxindex + 1)
                               .arg(rptr->second.size())
                               .toUtf8()
                               .data());
  } else if (debugee->db->archType() == mana::ARM) {
    REGDUMPA32 regdump;
    memset(&regdump, 0, sizeof(regdump));
    auto rptr = (RecordItemARM *)trace->Registers(selection);
    if (!rptr) return;
    if (m_regctxindex >= rptr->second.size()) {
      m_regctxindex = rptr->second.size() - 1;
    }
    arm_subregs_t &rvals = rptr->second[m_regctxindex];
    memcpy(&regdump.regcontext.gpr[0], rvals.gprs,
           sizeof(regdump.regcontext.gpr));
    regdump.flags = rvals.flags;
    regdump.regcontext.clr = rvals.gprs[14];
    regdump.regcontext.cip = rptr->first;
    regdump.n = (regdump.flags & 0x80000000) != 0;
    regdump.z = (regdump.flags & 0x40000000) != 0;
    regdump.c = (regdump.flags & 0x20000000) != 0;
    regdump.v = (regdump.flags & 0x10000000) != 0;
    regdump.t = (regdump.flags & 0x20) != 0;
    mGeneralRegsA32->setRegisters(&regdump);
    GuiAddStatusBarMessage(QString("Loaded %1 register context %2/%3.\n")
                               .arg(ToPtrString(rptr->first))
                               .arg(m_regctxindex + 1)
                               .arg(rptr->second.size())
                               .toUtf8()
                               .data());
  } else {
    REGDUMPX64 regdump;
    memset(&regdump, 0, sizeof(regdump));
    auto rptr = (RecordItemX64 *)trace->Registers(selection);
    if (!rptr) return;
    if (m_regctxindex >= rptr->second.size()) {
      m_regctxindex = rptr->second.size() - 1;
    }
    x64_subregs_t &rvals = rptr->second[m_regctxindex];
    rfbits *rflags = (rfbits *)&rvals.flags;
    regdump.regcontext.cax = rvals.rax;
    regdump.regcontext.ccx = rvals.rcx;
    regdump.regcontext.cdx = rvals.rdx;
    regdump.regcontext.cbx = rvals.rbx;
    regdump.regcontext.csp = rvals.rsp;
    regdump.regcontext.cbp = rvals.rbp;
    regdump.regcontext.csi = rvals.rsi;
    regdump.regcontext.cdi = rvals.rdi;
    regdump.regcontext.r8 = rvals.r8;
    regdump.regcontext.r9 = rvals.r9;
    regdump.regcontext.r10 = rvals.r10;
    regdump.regcontext.r11 = rvals.r11;
    regdump.regcontext.r12 = rvals.r12;
    regdump.regcontext.r13 = rvals.r13;
    regdump.regcontext.r14 = rvals.r14;
    regdump.regcontext.r15 = rvals.r15;
    regdump.regcontext.cip = rvals.rip;
    regdump.regcontext.eflags = rvals.flags;
    regdump.flags.c = rflags->CF;
    regdump.flags.p = rflags->PF;
    regdump.flags.a = rflags->AF;
    regdump.flags.z = rflags->ZF;
    regdump.flags.s = rflags->SF;
    regdump.flags.t = rflags->TF;
    regdump.flags.i = rflags->IF;
    regdump.flags.d = rflags->DF;
    regdump.flags.o = rflags->OF;
    mGeneralRegsX64->setRegisters(&regdump);
    GuiAddStatusBarMessage(QString("Loaded %1 register context %2/%3.\n")
                               .arg(ToPtrString(rptr->first))
                               .arg(m_regctxindex + 1)
                               .arg(rptr->second.size())
                               .toUtf8()
                               .data());
  }
}

void UVMTraceWidget::activeRegister(QScrollArea *regview) {
  QScrollArea *views[] = {
      mGeneralRegsA32,
      mGeneralRegsA64,
      mGeneralRegsX64,
  };
  for (size_t i = 0; i < sizeof(views) / sizeof(views[0]); i++) {
    if (views[i] == regview) {
      views[i]->setEnabled(true);
      views[i]->show();
      mGeneralRegsArea->takeWidget();
      mGeneralRegsArea->setWidget(views[i]);
    } else {
      views[i]->setEnabled(false);
      views[i]->hide();
    }
  }
}

void UVMTraceWidget::updateSlot() {
  auto debugee = VMPGlobal::inst()->debugee;
  if (!debugee || !isAttached()) {
    mGeneralRegsA32->setActive(false);
    mGeneralRegsA64->setActive(false);
    mGeneralRegsX64->setActive(false);
    return;
  }
  if (debugee->db->archType() == mana::ARM) {
    mGeneralRegsA32->setActive(mTraceWidget->isFileOpened());
  } else if (debugee->db->archType() == mana::ARM64) {
    mGeneralRegsA64->setActive(mTraceWidget->isFileOpened());
  } else {
    mGeneralRegsX64->setActive(mTraceWidget->isFileOpened());
  }
}

TraceBrowser *UVMTraceWidget::getTraceBrowser() { return mTraceWidget; }

void UVMTraceWidget::updateInfobox(unsigned long long selection,
                                   TraceFileReader *traceFile,
                                   const REGDUMP *registers) {}

void UVMTraceWidget::addLogSlot(QByteArray msg) { mInfo->addMsgToLogSlot(msg); }

void uvmclient_protocol(UVMSVR_CommandType type, const char *buf,
                        int bufsz, uint64_t extra) {
  switch (type) {
    case uvmct_s2c_init: {
      uvmWin->mUVMTriple = buf;
      GuiAddLogMessage(QString("Current connected uvmserver triple is %1.\n")
                           .arg(buf)
                           .toUtf8()
                           .data());
      break;
    }
    case uvmct_s2c_shell_result: {
      auto meta = (std::pair<QString *, QEventLoop *> *)extra;
      if (meta) {
        if (!bufsz) {
          buf = "";
        }
        meta->first[0] = buf;
        meta->second->quit();
      }
      break;
    }
    case uvmct_s2c_getfile_result: {
      auto meta = (std::pair<QByteArray *, QEventLoop *> *)extra;
      meta->first->setRawData(buf, bufsz);
      meta->second->quit();
      break;
    }
    case uvmct_s2c_postfile_result: {
      auto eloop = (QEventLoop *)extra;
      eloop->quit();
      break;
    }
    default:
      uvmWin->addLog(QString("Unknown uvmct: %1.\n").arg(type));
      return;
  }
}

QString uvmserver_ip() {
  auto bin = VMPGlobal::inst()->debugee->db;
  char ip[32];
  if (bin->fileType() == mana::MachO) {
    if (!BridgeSettingGet(VSSETTING_SECTION, VSSKEY_IOS_IP, ip, sizeof(ip))) {
      return "";
    }
  }
  else if (!BridgeSettingGet(VSSETTING_SECTION, VSSKEY_ANDROID_IP, ip, sizeof(ip))) {
    return "";
  }
  return ip;
}

bool UVMTraceWidget::connectedServer() {
  return mUVMClient.valid();
}

QString UVMTraceWidget::uvmShell(const QString &cmds, bool result,
                                 bool timeout) {
  if (!DbgIsDebugging()) {
    GuiAddLogMessage(
        "You should load a binary file before using remote uvm shell.\n");
    return "";
  }
  if (!mUVMClient.valid()) {
    GuiAddLogMessage(
        "Please set the remote device ip address in settings and keep the "
        "uvmserver running.\n");
    return QString();
  }
  auto cmd = timeout ? uvmct_c2s_shell_timeout : uvmct_c2s_shell;
  QByteArray buf = cmds.toUtf8();
  if (result) {
    QString str;
    QEventLoop eloop;
    auto meta = std::make_pair(&str, &eloop);
    uvmSend(cmd, buf.data(), buf.size() + 1, (uint64_t)&meta);
    eloop.exec();
    return str;
  }
  uvmSend(cmd, buf.data(), buf.size() + 1);
  return QString();
}

static QString adb_push(const QString &adb, const QString &path) {
  QString remotepath(
      QString("/data/local/tmp/%1").arg(QFileInfo(path).fileName()));
  svr_postfile(path, remotepath.toUtf8());
  return remotepath;
}

static void inject_remote_android(const QString &adb, const QString &loadercode,
                                  const QString &uvmroot, int pid,
                                  const QString &exe, bool is64) {
  QString loaderpath(QString("%1/uvmfire_loader%2.js")
                         .arg(VMPGlobal::inst()->tempDir())
                         .arg(is64 ? "64" : ""));
  QFile loaderfile(loaderpath);
  if (!loaderfile.open(QIODevice::WriteOnly)) {
    GuiAddLogMessage(
        QString("Failed to create file %1.\n").arg(loaderpath).toUtf8().data());
    return;
  }
  loaderfile.write(loadercode.toUtf8());
  loaderfile.close();

  QProcess proc;
  QString cmds;
  QStringList arg;
  cmds.append(QString("%1/frida-inject ").arg(uvmroot));
  if (pid) {
    cmds.append(QString("--pid=%1 ").arg(pid));
  } else {
    cmds.append(QString("--file=%1 ").arg(adb_push(adb, exe)));
  }
  cmds.append(QString("--script=%1 ").arg(adb_push(adb, loaderpath)));
  cmds.append("--eternalize");
#if 0
  arg.append("shell");
  arg.append("su");
  arg.append("-c");
  arg.append(cmds);
  proc.setProgram(adb);
  proc.setArguments(arg);
  proc.startDetached();
#else
  svr_shell(cmds, false, false);
#endif
  GuiAddLogMessage(
      QString("Injected loader code to target %1.\n").arg(pid).toUtf8().data());
}

static bool pickup_ipaddr(QString &locIP, QString &iosIP, bool android) {
  if (android) {
    locIP = UraniumVMServer::local_ip();
    return locIP.length();
  }

  char ip[56];
  if (!BridgeSettingGet(VSSETTING_SECTION, VSSKEY_IOS_IP, ip, sizeof(ip))) {
    GuiAddLogMessage(
        "You haven't configure the remote ios device ip address.\n");
    return false;
  }
  iosIP = ip;
  locIP = UraniumVMServer::local_ip();
  return iosIP.length() && locIP.length();
}

static void attach_remote_android(int pid, const QString &exe,
                                  const QString &argstring, mana::ArchType arch) {
  char adb[MAX_PATH];
  if (!BridgeSettingGet(VSSETTING_SECTION, VSSKEY_ANDROID_ADB, adb, MAX_PATH)) {
    GuiAddLogMessage("Please set adb full path in settings before attach operation.\n");
    return;
  }
  bool is64 = is_android_64(adb, pid, exe.toUtf8().data());
  bool arch_match = true;
  const char *uvmroot_suffix;
  switch (arch) {
    case mana::ARM:
      uvmroot_suffix = "";
      arch_match = is64 == false;
      break;
    case mana::ARM64:
      uvmroot_suffix = "64";
      arch_match = is64 == true;
      break;
    case mana::X86_64:
      uvmroot_suffix = "-x86_64";
      arch_match = is64 == true;
      break;
    default:
      uvmroot_suffix = "-x86";
      arch_match = is64 == false;
      break;
  }
  bool cloud = VMPGlobal::inst()->isCloudPlatform();
  if (!cloud && !arch_match) {
    GuiAddLogMessage("The loaded file's arch in VMPStudio is mismatch the process's arch.\n");
    return;
  }

  QString uvmroot =
      QString("/data/local/tmp/uvm-server%1").arg(uvmroot_suffix);
  QString uvmfire = QString("%1/libuvmfire.so").arg(uvmroot);
  QString uvmentry = "uvmfire_start";
  QString locIP, iosIP;
  if (!pickup_ipaddr(locIP, iosIP, true)) {
    GuiAddLogMessage("Failed to parse local ipv4 address.\n");
    return;
  }
  if (cloud) {
    uvmroot = "/data/local/tmp/a64dbg-server-x86_64.vp";
    uvmfire = uvmroot + "/libvpdbg.so";
    uvmentry = "vpfire_start";
  }
  if (!pid) {
    QString newexe = adb_push(adb, exe);
    // use linker insert method to block the whole program init to debug it
    QString cmds = QString("LD_PRELOAD=%1 ADIP=%2 %3 %4")
                       .arg(uvmfire)
                       .arg(locIP)
                       .arg(newexe)
                       .arg(argstring);
    svr_shell(cmds, false, false);
    GuiAddLogMessage(QString("Launched target '%1 %2'.\n")
                         .arg(exe)
                         .arg(argstring)
                         .toUtf8()
                         .data());
    return;
  }

  QString loadercode(
      QString("const libuvmfire = Module.load('%1');\n"
              "const uvmfire_start = new "
              "NativeFunction(libuvmfire.getExportByName('%4'), "
              "'void', ['pointer', 'int', 'int']);\n"
              "uvmfire_start(Memory.allocUtf8String('%2'), %3, 0);\n")
          .arg(uvmfire)
          .arg(locIP)
          .arg(vmpstudioPort)
          .arg(uvmentry));
  inject_remote_android(adb, loadercode, uvmroot, pid, exe, is64);
}

void inject_android_proc(const char *pid, mana::ArchType arch) {
  attach_remote_android(atoi(pid), "", "", arch);
}

static QString real_path(const QString &path) {
  QFileInfo finfo(path);
  return finfo.isSymLink() ? finfo.readLink() : finfo.absoluteFilePath();
}

static void attach_local(int pid, const QString &exe,
                         const QString &argstring) {
  QString uvmdir = tools_dir();
  QString injector(QString("%1/frida-inject").arg(uvmdir));
  QString uvmfire(QString("%1/uvmfire.dylib").arg(uvmdir));
  if (!QFileInfo(uvmfire).exists()) {
    GuiAddLogMessage(QString("There's no %1.\nContact us to buy a license.\n")
                         .arg(uvmfire)
                         .toUtf8()
                         .data());
    return;
  } else if (!pid) {
    // use dyld insert method to block the whole program init to debug it
    QStringList launchargs = argstring.split(" ");
    QStringList envs;
    QProcess debugee;
    envs.append(QString("DYLD_INSERT_LIBRARIES=%1").arg(uvmfire));
    debugee.setEnvironment(envs);
    debugee.setArguments(launchargs);
    debugee.setProgram(exe);
    debugee.startDetached();
    GuiAddLogMessage(QString("Launched target '%1 %2'.\n")
                         .arg(exe)
                         .arg(argstring)
                         .toUtf8()
                         .data());
    return;
  }

  QString loadercode(
      QString("const libuvmfire = Module.load('%1');\n"
              "const uvmfire_start = new "
              "NativeFunction(libuvmfire.getExportByName('uvmfire_start'), "
              "'void', ['pointer', 'int', 'int']);\n"
              "uvmfire_start(Memory.allocUtf8String('127.0.0.1'), %2, 0);\n")
          .arg(real_path(uvmfire))
          .arg(vmpstudioPort));

  QString loaderpath("/tmp/uvmfire_loader.js");
  QFile loaderfile(loaderpath);
  if (!loaderfile.open(QIODevice::WriteOnly)) {
    GuiAddLogMessage(
        QString("Failed to create file %1.\n").arg(loaderpath).toUtf8().data());
    return;
  }
  loaderfile.write(loadercode.toUtf8());
  loaderfile.close();

  QProcess proc;
  QStringList args;
  if (pid) {
    args.append(QString("--pid=%1").arg(pid));
  } else {
    args.append(QString("--file=%1").arg(exe));
  }
  args.append(QString("--script=%1").arg(loaderpath));
  args.append("--device=socket");
  args.append("--eternalize");
  proc.start(injector, args, QIODevice::ReadOnly);
  proc.waitForFinished();
  int ec = proc.exitCode();
  if (ec) {
    GuiAddLogMessage(QString("Failed to inject loader code to target: %1,%2.\n")
                         .arg(ec)
                         .arg(proc.readAll().data())
                         .toUtf8()
                         .data());
  } else {
    GuiAddLogMessage("Injected loader code to target.\n");
  }
}

static QString get_text_file(const QString &ip, const QString &path) {
  return tburl_request(ip.toUtf8().data(), "textfile", path.toUtf8().data())
      .data();
}

static std::string infoplist_bid(const char *plistbuff) {
  const char *bid = strstr(plistbuff, "CFBundleIdentifier");
  if (!bid) return "";

  while (*bid && *bid++ != '"')
    ;
  if (!*bid) return "";

  std::string tmpbid;
  while (*bid != '"') {
    tmpbid.push_back(*bid++);
  }
  return tmpbid;
}

static const char *TextobotFridaTemplate =
    "import frida\n"
    "import codecs\n"
    "\n"
    "def on_message(message, data):\n"
    "    print(message)\n"
    "\n"
    "def attach_target_process(device, pid):\n"
    "    print('Textobot for the target process %d' % pid)\n"
    "    try:\n"
    "        session = device.attach(pid)\n"
    "    except Exception as e:\n"
    "        print(e)\n"
    "\n"
    "    return session\n"
    "\n"
    "def fire_js(session):\n"
    "    jscode = '''%1'''\n"
    "    script = session.create_script(jscode)\n"
    "    script.on('message', on_message)\n"
    "    script.load()\n"
    "    return script\n"
    "\n"
    "def textobot_js_main(device, pid):\n"
    "    print('Textobot with frida ' + frida.__version__)\n"
    "    session = attach_target_process(device, pid)\n"
    "    if session:\n"
    "        fire_js(session)\n"
    "\n"
    "textobot_js_main(frida.get_remote_device(), %2)\n";

static void attach_remote_ios(int pid, const QString &exe) {
  QString locIP, iosIP;
  if (!pickup_ipaddr(locIP, iosIP, false)) {
    GuiAddLogMessage(QString("Invalid ip address, local %1, remote %2.\n")
                         .arg(locIP)
                         .arg(iosIP)
                         .toUtf8()
                         .data());
    return;
  }
  QString loadercode(
      QString("const libuvmfire = Module.load('/usr/lib/uvmfire.dylib');\n"
              "const uvmfire_start = new "
              "NativeFunction(libuvmfire.getExportByName('uvmfire_start'), "
              "'void', ['pointer', 'int', 'int']);\n"
              "uvmfire_start(Memory.allocUtf8String('%1'), %2, 0);\n")
          .arg(locIP)
          .arg(vmpstudioPort));
  if (pid) {
    tburl_request(iosIP.toUtf8().data(), "python",
                  QString(TextobotFridaTemplate)
                      .arg(loadercode)
                      .arg(pid)
                      .toUtf8()
                      .data());
  } else {
    if (!exe.length()) {
      GuiAddLogMessage(
          "Software bug detected, virtualization debug mode for iOS needs the "
          "target path.\n");
      return;
    }

    QString app(exe);
    int appidx = app.indexOf(".app");
    if (appidx < 0) {
      GuiAddLogMessage(
          QString("Virtualization debug mode for iOS only supports "
                  "app path process which contains Info.plist.\n"
                  "If you want to debug other process, you can load "
                  "/usr/lib/uvmfire.dylib and "
                  "call uvmfire_start(\"%1\", %2, 0) manually.\n")
              .arg(locIP)
              .arg(vmpstudioPort)
              .toUtf8()
              .data());
      return;
    }
    app = app.mid(0, appidx + 4);

    QString infoplist = get_text_file(iosIP, QString("%1/Info.plist").arg(app));
    if (!infoplist.length()) {
      GuiAddLogMessage(QString("Cannot get bundleID for %1, please make sure "
                               "https://gitee.com/geekneo/Textobot/blob/master/"
                               "iOS/Textobot.deb has been "
                               "installed to your remote iOS device.\n")
                           .arg(app)
                           .toUtf8()
                           .data());
      return;
    }
    std::string bid = infoplist_bid(infoplist.toUtf8().data());
    if (!bid.length()) {
      GuiAddLogMessage(QString("Failed to parse bundleID for %1:\n%2\n")
                           .arg(app)
                           .arg(infoplist)
                           .toUtf8()
                           .data());
      return;
    }

    tburl_request(iosIP.toUtf8().data(), "javascript",
                  QByteArray(bid.c_str()).toBase64().data(),
                  loadercode.toUtf8().data());
  }
  GuiAddLogMessage("Injected loader code to target.\n");
}

void inject_apple_proc(const char *pid) {
  if (strstr(uvmWin->mUVMTriple.data(), "mac")) {
    attach_local(atoi(pid), "", "");
  } else {
    attach_remote_ios(atoi(pid), "");
  }
}

void UVMTraceWidget::setBp(const VMPManaFunc &fn, bool set) {
  uint64_t addrs[2];
  char flags[8] = {0};
  addrs[0] = mRuntimeBase + fn.rvastart;
  addrs[1] = mRuntimeBase + fn.rvaend;
  flags[0] = !set;        // remove flag
  flags[1] = fn.thumb();  // thumb flag
  mUVMServer.send(udct_s2c_setbp, (char *)&addrs[0], sizeof(addrs),
                  *(uint64_t *)&flags[0]);
}

void UVMTraceWidget::uvmTraceStart(const VMPManaFunc &fn) {
  if (!isAttached()) {
    GuiAddLogMessage("Please attach a process before uvm tracing function.\n");
    return;
  }
  setBp(fn, true);
}

void UVMTraceWidget::uvmTraceStop(const VMPManaFunc &fn) {
  if (!isAttached()) return;
  setBp(fn, false);
}

void UVMTraceWidget::uvmTraceStart() {
  if (!isAttached()) {
    GuiAddLogMessage("Please attach a process before uvm tracing function.\n");
    return;
  }
  if (!VMPGlobal::inst()->isCloudPlatform()) {
    GuiAddLogMessage("Only yoophone platform supports module fully sampling.\n");
    return;
  }
  mUVMServer.send(udct_s2c_run, nullptr, 0, 0);
}

void UVMTraceWidget::uvmTraceStop() {
  if (!isAttached()) return;
  if (!VMPGlobal::inst()->isCloudPlatform()) {
    return;
  }
  mUVMServer.send(udct_s2c_pause, nullptr, 0, 0);
}

void UVMTraceWidget::uvmTraceOptions(int depth, int startrva, int endrva) {
  if (!isAttached()) {
    GuiAddLogMessage(QString("Pending uvm tracing options %1,%2,%3.\n").arg(depth)
                     .arg(ToHexString(startrva)).arg(ToHexString(endrva)).toUtf8().data());
    return;
  }
  int opts[3];
  opts[0] = depth;
  opts[1] = startrva;
  opts[2] = endrva;
  mUVMServer.send(udct_s2c_updatectx, (char *)&opts[0], sizeof(opts), 0);
}

template <typename RECORD, typename HDR, typename SUBREGS>
void UVMTraceWidget::updateRecord(RECORD *recordall, RECORD *recordcur,
                                  const char *buf, int bufsz) {
  int totals = 0, updated = 0;
  std::set<addr_t> pages;
  const uint64_t *ind = (uint64_t *)buf;
  size_t indcount = *ind++;
  if (!indcount) {
    return;
  }
  for (auto oldind : mRecordInds) {
    if (oldind.size() == indcount) {
      if (memcmp(&oldind[0], ind, indcount * sizeof(ind[0])) == 0) {
        // addLog(QString("Ignored dummy incoming sample data for %1.\n").arg(ToPtrString(ind[0])));
        return;
      }
    }
  }
  mRecordCur = (int)mRecordInds.size();
  mRecordInds.push_back(std::vector<uint64_t>());
  auto newind = mRecordInds.rbegin();
  newind->reserve(indcount);
  for (size_t i = 0; i < indcount; i++) {
    newind->push_back(*ind++);
  }
  const HDR *hdr = (HDR *)ind;
  recordcur->clear();
  while (hdr < (HDR *)(buf + bufsz)) {
    auto hitall = recordall->find(hdr->pc);
    if (hitall == recordall->end()) {
      hitall = recordall->insert({hdr->pc, std::vector<SUBREGS>()}).first;
    }
    auto hitcur = recordcur->insert({hdr->pc, std::vector<SUBREGS>()}).first;
    pages.insert(hdr->pc & ~UVMPAGE_MASK);

    const SUBREGS *srptr = &hdr->subregs[0];
    if (hitall->second.size() < 50000) {
      for (uint32_t i = 0; i < hdr->count; i++) {
        hitall->second.push_back(srptr[i]);
        updated++;
      }
    }
    for (uint32_t i = 0; i < hdr->count; i++) {
      hitcur->second.push_back(*srptr++);
    }
    hdr = (HDR *)srptr;
    totals++;
  }
  std::vector<addr_t> updatepages;
  for (auto p : pages) {
    if (mPageBuffs.find(p) == mPageBuffs.end()) {
      updatepages.push_back(p);
    }
  }
  if (updatepages.size()) {
    mUVMServer.send(udct_s2c_readmem, (char *)&updatepages[0],
                    updatepages.size() * sizeof(updatepages[0]), UVMPAGE_SIZE);
  }
  Bridge::getBridge()->updateTraceBrowser();
  addLog(QString("Total got %1 sampled instructions, updated %2 register "
                 "contexts, updated %3 memory pages, pc %4 indexs length "
                 "is %5.\n")
             .arg(totals)
             .arg(updated)
             .arg(updatepages.size())
             .arg(ToPtrString(newind->at(0)))
             .arg(newind->size()));
}

void UVMTraceWidget::debugStateChangedSlot(DBGSTATE state) {
  if (state == paused) {
    auto debugee = VMPGlobal::inst()->debugee;
    if (!debugee) {
      return;
    }
    if (!connectedServer()) {
      // lazy setup network after debugee module loaded
      setupUVMServer();
    }
    switch (debugee->db->archType()) {
      case mana::ARM:
        activeRegister(mGeneralRegsA32);
        break;
      case mana::ARM64:
        activeRegister(mGeneralRegsA64);
        break;
      default:
        activeRegister(mGeneralRegsX64);
        break;
    }
    return;
  }
  if (state == stopped) {
    mTraceWidget->resetSampleData();
    updateSlot();
    return;
  }
}

void UVMTraceWidget::onAnchorClicked(const QUrl &link) {
  if (link.scheme() == "x64dbg") {
    if (link.path() == "/address32" || link.path() == "/address64") {
      if (DbgIsDebugging()) {
        bool ok = false;
        auto address =
            duint(link.fragment(QUrl::DecodeReserved).toULongLong(&ok, 16));
        if (ok && DbgMemIsValidReadPtr(address)) {
          mTraceWidget->gotoAddress(address);
        }
      }
    }
  }
}
