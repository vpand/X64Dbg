/**
 * \file bridgemain.cpp
 *
 * \brief Defines functions to initialize and start the Bridge and
 *        to interface with the GUI and the DBG.
 */
#include "VMPBridgeMain.h"

#include <stdio.h>

#include <QEventLoop>
#include <QFileDialog>
#include <QTimer>
#include <QSet>

#include "../Bridge/Bridge.h"
#include "../dbg/_dbgfunctions.h"
#include "StringUtil.h"
#include "MiscUtil.h"
#include "UVMTraceWidget.h"
#include "Utf8Ini.h"
#include "VDBFile.h"
#include "VMPGlobal.h"
#include "VMPSymbolView.h"

#define DbgGlobal VMPGlobal

#if __APPLE__
typedef void* HINSTANCE;
#else
#define long int64_t
// make suer long is 8 byte
char byte_size_check[sizeof(long) - 8];
#endif

#define EnterCriticalSection(...)
#define LeaveCriticalSection(...)
#define _snprintf_s snprintf

static Utf8Ini settings;
static CRITICAL_SECTION csIni;
static CRITICAL_SECTION csTranslate;
static bool bDisableGUIUpdate;

UraniumEngine* uranius;

#define CHECK_GUI_UPDATE_DISABLED \
  if (bDisableGUIUpdate) return;

#ifdef _WIN64
#define dbg_lib L"x64dbg.dll"
#define gui_lib L"x64gui.dll"
#else
#define dbg_lib L"x32dbg.dll"
#define gui_lib L"x32gui.dll"
#endif  // _WIN64

// GUI functions
extern "C" int _gui_guiinit(int, char**);
void* _gui_sendmessage(GUIMSG type, void* param1, void* param2);
const char* _gui_translate_text(const char* source);

static void load_module_sync(const QString& path) {
  QEventLoop eloop;
  QThread* anaThread = QThread::create(
      [](const QString& path) { DbgGlobal::inst()->addModule(path); }, path);
  anaThread->connect(anaThread, SIGNAL(finished()), &eloop, SLOT(quit()));
  anaThread->start();
  eloop.exec();
  delete anaThread;
}

void init_debugee_process(const char* pid);

bool is_android_64(int pid, const QString& exe) {
  if (pid) {
    QByteArray outs;
    if (pid > 0)
      outs = svr_shell(QString("cat /proc/%1/maps").arg(pid), true, false)
                 .toUtf8();
    else
      outs = svr_shell(QString("cat /proc/self/maps"), true, false).toUtf8();

    auto addr = strtoull(outs.data(), nullptr, 16);
    if (addr > 0x100000000ll) return true;
    return strstr(outs.data(), "lib64") != nullptr;
  }
  auto debugee = VMPGlobal::inst()->debugee;
  if (debugee) {
    switch (debugee->db->archType()) {
    case mana::ARM64:
    case mana::X86_64:
      return true;
    default:
      return false;
    }
  }
  mana::ELFBinary* elf =
      (mana::ELFBinary*)mana::New(exe.toUtf8().data(), nullptr, false);
  if (!elf) return true;
  switch (elf->archType()) {
    case mana::ARM64:
    case mana::X86_64:
      return true;
    default:
      return false;
  }
}

static const char* process_ip(std::vector<std::string>& ips,
                              std::string& locip) {
  if (ips.size() == 1) {
    locip = ips[0];
    return locip.data();
  }
  if (ips.size() > 1) {
    QString qtxt;
    Bridge::getBridge()->getStrWindow("Input WLAN IPv4 Address", &qtxt);
    locip = qtxt.toStdString();
    return locip.data();
  }
  return nullptr;
}

QString tools_dir();

static void launch_apk_file(const char* app) {
  auto debugee = VMPGlobal::inst()->debugee;
  if (!debugee) {
    GuiAddLogMessage("You should load an android elf file before launch apk.\n");
    return;
  }
  const char *uvmroot_suffix;
  switch (debugee->db->archType()) {
    case mana::ARM:
      uvmroot_suffix = "";
      break;
    case mana::ARM64:
      uvmroot_suffix = "64";
      break;
    case mana::X86_64:
      uvmroot_suffix = "-x86_64";
      break;
    default:
      uvmroot_suffix = "-x86";
      break;
  }

  int waitsecs = 2;
  QString uvmroot =
      QString("/data/local/tmp/uvm-server%1").arg(uvmroot_suffix);
  if (VMPGlobal::inst()->isCloudPlatform()) {
    waitsecs = 10;
    uvmroot = "/data/local/tmp/a64dbg-server-x86_64.vp";
  }
  const char* pathend = strrchr(app, '=');
  std::string apk(app, pathend - app);
  svr_shell(QString("cd /data/local/tmp; rm AndroidManifest.xml; "
                    "%1/unzip %2 AndroidManifest.xml -d .; "
                    "%1/zip ./AndroidManifest.zip AndroidManifest.xml")
                .arg(uvmroot)
                .arg(apk.data()),
            true, false);
  QString locfile(
      QString("%1/AndroidManifest.zip").arg(DbgGlobal::inst()->tempDir()));
  QFile(locfile).remove();
  svr_getfile("/data/local/tmp/AndroidManifest.zip", locfile);
  if (!QFileInfo(locfile).exists()) {
    GuiAddLogMessage(QString("Failed to parse %1's AndroidManifest.xml.\n")
                         .arg(apk.data())
                         .toUtf8()
                         .data());
    return;
  }

  QString aapt = QString("%1/aapt2").arg(tools_dir());
  QProcess proc;
  QStringList args;
  args.append("dump");
#ifdef _WIN32
  aapt += ".exe";
#else
  args.append("xmltree");
#endif
  args.append("--file");
  args.append("AndroidManifest.xml");
  args.append(locfile);
  proc.start(aapt, args, QIODevice::ReadOnly);
  proc.waitForFinished();
  proc.kill();
  proc.terminate();
  QByteArray xmls = proc.readAll();
  const char *intent_launcher_flag = "android.intent.category.LAUNCHER";
  const char *activity_flag = "E: activity";
  const char* ptr = strstr(xmls.data(), intent_launcher_flag);
  if (!ptr) {
    GuiAddLogMessage(xmls.data());
    return;
  }
  for (const char *ptrstart = ptr; *(long*)ptr-- != *(long*)activity_flag;) {
    if (ptr <= xmls.data()) {
      while (*ptrstart++ != '\n');
      ptr = strstr(ptrstart, intent_launcher_flag);
      if (!ptr) {
        GuiAddLogMessage(xmls.data());
        return;
      }
      while (*(long*)ptr-- != *(long*)activity_flag) {
        if (ptr <= ptrstart) {
          GuiAddLogMessage(xmls.data());
          return;
        }
      }
      break;
    }
  }
  const char *activity_prefix = ptr;
  ptr = strstr(ptr, "android:name");
  if (!ptr) {
    GuiAddLogMessage("Failed to parse launch activity.\n");
    return;
  }
  ptr = strchr(ptr, '"') + 1;
  std::string activity(ptr, strchr(ptr, '"') - ptr);
  if (strncmp(activity.data(), "android.", 8) == 0) {
    ptr = strchr(strstr(activity_prefix, "=\""), '"') + 1;
    activity = std::string(ptr, strchr(ptr, '"') - ptr);
  }
  const char* pkgname = pathend + 1;
  for (char* ptr = (char*)pkgname; *ptr; ptr++) {
    if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
      *ptr = 0;
      break;
    }
  }

  QString tmpcfg(QString("%1/uvmzygote.cfg").arg(DbgGlobal::inst()->tempDir()));
  QFile cfgfile(tmpcfg);
  cfgfile.open(QIODevice::WriteOnly);
  cfgfile.write(QString("%1\n%2:%3")
                      .arg(pkgname)
                      .arg(vmpstudioPort)
                      .arg(UraniumVMServer::local_ip())
                      .toUtf8()
                      .data());
  cfgfile.close();
  const char* remotecfg = "/data/local/tmp/uvmzygote.cfg";
  svr_postfile(tmpcfg, remotecfg);

  QString startcmd(
      QString("am start -S -n %1/%2").arg(pkgname).arg(activity.data()));
  GuiAddLogMessage(QString("Launching %1 with %2.\n")
                       .arg(apk.data())
                       .arg(startcmd)
                       .toUtf8()
                       .data());
  svr_shell(startcmd, false, false);

  // let debugee running a few seconds
  QTimer::singleShot(waitsecs * 1000, [remotecfg]() {
    // remove the temp cfg file
    svr_shell(QString("rm %1").arg(remotecfg), false, false);
  });
}

static void launch_debugee_file(const char* app) {
  if (strstr(app, ".apk")) {
    auto selinux_status = svr_shell("getenforce", true, false);
    if (selinux_status.startsWith("Enforcing")) {
      GuiAddLogMessage(
          "Cannot launching uvm zygote with selinux ENFORCING, please use 'setenforce 0' to disable it.\n");
      return;
    }
    GuiAddStatusBarMessage(
        QString("Launching remote %1...\n").arg(app).toUtf8().data());
    launch_apk_file(app);
    return;
  }
}

extern void inject_android_proc(const char* pid, mana::ArchType arch);
extern void inject_apple_proc(const char* pid);

void init_debugee_process(const char* pid) {
  if (!DbgIsDebugging()) {
    GuiAddLogMessage("You need to load a file before using uvm studio.\n");
    return;
  }
  if (uvmWin->isAttached()) {
    GuiAddLogMessage("You have already attached a uvm debugee.\n");
    return;
  }
  auto debugee = VMPGlobal::inst()->debugee;
  switch (debugee->db->fileType()) {
    case mana::ELF:
      inject_android_proc(pid, debugee->db->archType());
      break;
    case mana::MachO:
      inject_apple_proc(pid);
      break;
    default:
      GuiAddLogMessage("Unsupport uvm attach for this kind of input file.\n");
      return;
  }
}

static void init_debugee_file(const char* path) {
  if (QString(path).endsWith(".py")) {
    if (QFileInfo(path).exists()) {
      GuiAddRecentFile(path);
      GuiAddLogMessage(QString("Execute %1.\n").arg(path).toUtf8().data());
      VSPluginManager::inst()->vsp_eval(path, nullptr, 0);
    } else {
      GuiAddLogMessage(
          QString("Python file %1 doesn't exist.\n").arg(path).toUtf8().data());
    }
    return;
  }

  if (!QFileInfo(path).exists()) {
    GuiAddLogMessage(
        QString("Debugee file %1 doesn't exist.\n").arg(path).toUtf8().data());
    return;
  }

  if (DbgIsDebugging()) {
    VMPGlobal::inst()->clearAll();
  }

  GuiSetDebugState(initialized);
  if (!VMPGlobal::inst()->hasModule(path)) {
    load_module_sync(path);
  }
  GuiSetDebugState(paused);

  GuiAddRecentFile(path);
}

static void detach_uvm() { uvmWin->detach(); }

static void detach_debuggee() {
  detach_uvm();
  VMPGlobal::inst()->clearAll();
}

static void save_debuggee() {
  VDBFile vdb;
  vdb.save(VMPGlobal::inst()->debugee);
}

static void save_file() {
  auto filename =
      QFileDialog::getSaveFileName(nullptr, "Save file", "", "All files (*);;");
  if (!filename.length()) return;
  filename = QDir::toNativeSeparators(
      filename);  // convert to native path format (with backlashes)

  auto debugee = VMPGlobal::inst()->debugee;
  QFile file(filename);
  if (file.open(QIODevice::WriteOnly)) {
    file.write(debugee->opcodes_cache, debugee->opcsize);
    GuiAddRecentFile(filename.toUtf8().data());
    GuiAddLogMessage(
        QString("Saved file to %1.\n").arg(filename).toUtf8().data());
  } else {
    GuiAddLogMessage(
        QString("Failed to create %1.\n").arg(filename).toUtf8().data());
  }
}

static QString name_indexd(const char* name) {
  static int index = 0;
  return QString("%1 %2").arg(name).arg(++index);
}

static void list_function() {
  auto debugee = DbgGlobal::inst()->debugee;
  GuiReferenceInitialize(name_indexd("Functions").toUtf8().data());
  GuiReferenceAddColumn(18, "RVA");
  GuiReferenceAddColumn(8, "Size");
  GuiReferenceAddColumn(18, "Section");
  GuiReferenceAddColumn(200, "Name");
  GuiReferenceSetRowCount(debugee->db->functions().size());
  int i = 0;
  const mana::Section* lastsect = nullptr;
  for (auto f : debugee->db->functions()) {
    auto& func = f.second;
    if (!lastsect || f.first < lastsect->addr ||
        f.first >= lastsect->addr + lastsect->size) {
      lastsect = debugee->db->addrSect(f.first);
    }
    GuiReferenceSetCellContent(
        i, 0, ToPtrString(f.first - debugee->db->imageBase()).toUtf8().data());
    GuiReferenceSetCellContent(
        i, 1, QString("%1").arg(func.end - f.first).toUtf8().data());
    GuiReferenceSetCellContent(i, 2, lastsect->name.data());
    GuiReferenceSetCellContent(i, 3, func.name.data());
    i++;
  }
  GuiFocusView(GUI_LOG);
}

static void list_import() {
  int count = 0;
  auto fns = VMPGlobal::inst()->debugee->db->functions();
  for (auto& f : fns) {
    if (f.second.flags & MFF_IMPORT) {
      count++;
    }
  }

  GuiReferenceInitialize(name_indexd("Imports").toUtf8().data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(200, "Name");
  GuiReferenceSetRowCount(count);
  int index = 0;
  for (auto& f : fns) {
    if (!(f.second.flags & MFF_IMPORT)) {
      continue;
    }
    GuiReferenceSetCellContent(index, 0, ToPtrString(f.first).toUtf8().data());
    GuiReferenceSetCellContent(index, 1, f.second.name.data());

    index++;
  }
  GuiFocusView(GUI_LOG);
}

static void list_export() {
  int count = 0;
  auto fns = VMPGlobal::inst()->debugee->db->functions();
  for (auto& f : fns) {
    if (f.second.flags & MFF_EXPORT) {
      count++;
    }
  }

  GuiReferenceInitialize(name_indexd("Exports").toUtf8().data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(200, "Name");
  GuiReferenceSetRowCount(count);
  int index = 0;
  for (auto& f : fns) {
    if (!(f.second.flags & MFF_EXPORT)) {
      continue;
    }
    GuiReferenceSetCellContent(index, 0, ToPtrString(f.first).toUtf8().data());
    GuiReferenceSetCellContent(index, 1, f.second.name.data());

    index++;
  }
  GuiFocusView(GUI_LOG);
}

static void list_module() {
  auto libs = VMPGlobal::inst()->debugee->db->importLibs();
  GuiReferenceInitialize("Libraries");
  GuiReferenceAddColumn(6, "Index");
  GuiReferenceAddColumn(200, "Name");
  GuiReferenceSetRowCount(libs.size());
  for (size_t i = 0; i < libs.size(); i++) {
    GuiReferenceSetCellContent(i, 0, QString("%1").arg(i + 1).toUtf8().data());
    GuiReferenceSetCellContent(i, 1, libs[i]);
  }
  GuiFocusView(GUI_LOG);
}

static void list_bookmark() {
  int count = 0;
  for (auto& m : DbgGlobal::inst()->modules) {
    auto bms = m.second->usrdef.find(UDKEY_BOOKMARK);
    if (bms == m.second->usrdef.end()) {
      continue;
    }
    QVariantMap& addrbkmk = *(QVariantMap*)&*bms;
    count += addrbkmk.size();
  }

  GuiReferenceInitialize(name_indexd("Bookmarks").toUtf8().data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(6, "Status");
  GuiReferenceAddColumn(200, "Funcoff");
  GuiReferenceSetRowCount(count);
  int index = 0;
  for (auto& m : DbgGlobal::inst()->modules) {
    auto bms = m.second->usrdef.find(UDKEY_BOOKMARK);
    if (bms == m.second->usrdef.end()) {
      continue;
    }
    QVariantMap& addrbkmk = *(QVariantMap*)&*bms;
    for (auto& srva : addrbkmk.keys()) {
      duint bkrva = srva.toInt(nullptr, 16);
      auto func = m.second->rvaToFunction(bkrva, false);
      GuiReferenceSetCellContent(
          index, 0, ToPtrString(m.second->rtbase + bkrva).toUtf8().data());
      GuiReferenceSetCellContent(index, 1,
                                 addrbkmk[srva].toBool() ? "On" : "Off");
      GuiReferenceSetCellContent(index, 2,
                                 QString("%1+%2")
                                     .arg(func.func->name.data())
                                     .arg(bkrva - func.rvastart)
                                     .toUtf8()
                                     .data());
      index++;
    }
  }
  GuiFocusView(GUI_LOG);
}

static void list_comment() {
  int count = 0;
  for (auto& m : DbgGlobal::inst()->modules) {
    auto cmt = m.second->usrdef.find(UDKEY_COMMENT);
    if (cmt == m.second->usrdef.end()) {
      continue;
    }
    QVariantMap& addrcmt = *(QVariantMap*)&*cmt;
    count += addrcmt.size();
  }

  GuiReferenceInitialize(name_indexd("Comments").toUtf8().data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(64, "Funcoff");
  GuiReferenceAddColumn(20, "Comment");
  GuiReferenceSetRowCount(count);
  int index = 0;
  for (auto& m : DbgGlobal::inst()->modules) {
    auto cmt = m.second->usrdef.find(UDKEY_COMMENT);
    if (cmt == m.second->usrdef.end()) {
      continue;
    }
    QVariantMap& addrcmt = *(QVariantMap*)&*cmt;
    for (auto& srva : addrcmt.keys()) {
      duint cmtrva = srva.toInt(nullptr, 16);
      auto func = m.second->rvaToFunction(cmtrva, false);
      GuiReferenceSetCellContent(
          index, 0, ToPtrString(m.second->rtbase + cmtrva).toUtf8().data());
      GuiReferenceSetCellContent(index, 1,
                                 QString("%1+%2")
                                     .arg(func.func->name.data())
                                     .arg(cmtrva - func.rvastart)
                                     .toUtf8()
                                     .data());
      GuiReferenceSetCellContent(index, 2,
                                 addrcmt[srva].toString().toUtf8().data());
      index++;
    }
  }
  GuiFocusView(GUI_LOG);
}

void list_readobj() {
  std::string outs;
  VMPGlobal::inst()->debugee->db->readObj(outs);

  QStringList lines = QString(outs.data()).split("\n");
  while (lines.size() && lines.begin()->size() < 2) {
    lines.pop_front();
  }
  GuiReferenceInitialize(name_indexd("Readobj").toUtf8().data());
  GuiReferenceAddColumn(6, "Row");
  GuiReferenceAddColumn(200, "Line");
  GuiReferenceSetRowCount(lines.size());
  for (int i = 0; i < lines.size(); i++) {
    GuiReferenceSetCellContent(i, 0, QString("%1").arg(i + 1).toUtf8().data());
    GuiReferenceSetCellContent(i, 1, lines[i].toUtf8().data());
  }
  GuiFocusView(GUI_LOG);
}

void list_readobjc(const char* mode) {
  QFileInfo dsdump(QString("%1/dsdump").arg(VMPGlobal::inst()->exeDir()));
  if (!dsdump.exists()) {
    GuiAddLogMessage("Unsupport readobjc function on this running platform.\n");
    return;
  }
  auto debugee = VMPGlobal::inst()->debugee;
  if (!QFileInfo(debugee->path).exists()) {
    GuiAddLogMessage(QString("The file %1 doesn't exist.\n")
                         .arg(debugee->path)
                         .toUtf8()
                         .data());
    return;
  }
  QProcess proc;
  QStringList args;
  args.append(mode);
  args.append("--verbose=5");
  args.append(debugee->path);
  proc.start(dsdump.absoluteFilePath(), args, QIODevice::ReadOnly);
  if (!proc.waitForFinished(10 * 1000)) {
    GuiAddLogMessage(QString("Failed to launch %1, %2.\n")
                         .arg(dsdump.path())
                         .arg(proc.errorString())
                         .toUtf8()
                         .data());
    return;
  }
  QString outs(proc.readAll());
  QStringList lines = outs.split("\n");
  while (lines.size() && lines.begin()->size() < 2) {
    lines.pop_front();
  }
  GuiReferenceInitialize(
      name_indexd(strstr(mode, "objc") ? "Objective-C Dumper" : "Swift Dumper")
          .toUtf8()
          .data());
  GuiReferenceAddColumn(6, "Row");
  GuiReferenceAddColumn(200, "Line");
  GuiReferenceSetRowCount(lines.size());
  for (int i = 0; i < lines.size(); i++) {
    GuiReferenceSetCellContent(i, 0, QString("%1").arg(i + 1).toUtf8().data());
    GuiReferenceSetCellContent(i, 1, lines[i].toUtf8().data());
  }
  GuiFocusView(GUI_LOG);
}

static uint64_t parse_addr(const char* expr, const char** end) {
  const char* tmp;
  const char*& index = end ? *end : tmp;

  uint64_t addr = strtoul(expr, (char**)&index, 16);
  if (!addr) {
    if (expr[0] != '[') {
      return 0;
    }
    addr = strtoul(expr + 1, (char**)&index, 16);  // skip <[>
    if (!addr || index[0] != ']') {
      return 0;
    }
    index++;
    if (!DbgMemRead(addr, &addr, VMPGlobal::inst()->addrSize())) {
      return addr;
    }
  }
  return addr;
}

static void retdec_decompile(const char* saddr) {
  auto addr = DbgValFromString(saddr);
  auto mdb = VMPGlobal::inst()->debugee;
  if (!mdb) return;
  auto base = mdb->db->imageBase();
  auto func = mdb->rvaToFunction(addr - base, false);
  if (!func) {
    GuiAddLogMessage(QString("Failed to find function at address %1.\n")
                         .arg(ToPtrString(addr))
                         .toUtf8()
                         .data());
    return;
  }
  QString srcjson = QString("%1/%2.c").arg(VMPGlobal::inst()->tempDir(),
                                           func.func->name.data());
  if (retdec_main(mdb->path.toUtf8().data(), srcjson.toUtf8().data(),
                  base + func.rvastart, base + func.rvaend, [](addr_t addr) {
                    return VMPGlobal::inst()->addrName(addr);
                  }) == 0) {
    GuiLoadSourceFileEx(srcjson.toUtf8().data(), func.func->start);
  } else {
    GuiAddLogMessage(QString("Failed to decompile function %1.\n")
                         .arg(func.func->name.data())
                         .toUtf8()
                         .data());
  }
}

static void urdyndec_decompile(const char* saddr) {
  auto addr = DbgValFromString(saddr);
  auto mdb = VMPGlobal::inst()->debugee;
  if (!mdb) return;
  auto base = mdb->db->imageBase();
  auto func = mdb->rvaToFunction(addr - base, false);
  if (!func) {
    GuiAddLogMessage(QString("Failed to find function at address %1.\n")
                         .arg(ToPtrString(addr))
                         .toUtf8()
                         .data());
    return;
  }
  QByteArray srcjson =
      QString("%1/%2.dyn.c")
          .arg(VMPGlobal::inst()->tempDir(), func.func->name.data())
          .toUtf8();
  urdec_params_t params;
  params.bin = VMPGlobal::inst()->debugee->db;
  params.start = base + func.rvastart;
  params.end = base + func.rvaend;
  params.srcpath = srcjson.data();
  params.pages = &uvmWin->mPageBuffs;
  params.rawpages = &uvmWin->mPageRawBuffs;
  params.indexs = &uvmWin->mRecordInds;
  params.rtbase = uvmWin->runtimeBase();
  params.regsarm = &uvmWin->mRecordARMCur;
  params.regsarm64 = &uvmWin->mRecordARM64Cur;
  params.index = uvmWin->mRecordCur;
  switch (mdb->db->archType()) {
    case mana::ARM: {
      if (!uvmWin->mRecordARMCur.size()) {
        GuiAddLogMessage("There's no UraniumVM arm register sample data.\n");
        return;
      }
      if (urdyndec_main(&params, [](addr_t addr) {
                          return VMPGlobal::inst()->addrName(addr);
                        }) == 0) {
        GuiLoadSourceFileEx(srcjson.data(), func.func->start);
        return;
      }
      break;
    }
    case mana::ARM64:
      if (!uvmWin->mRecordARM64Cur.size()) {
        GuiAddLogMessage("There's no UraniumVM arm64 register sample data.\n");
        return;
      }
      if (urdyndec_main(&params, [](addr_t addr) {
                          return VMPGlobal::inst()->addrName(addr);
                        }) == 0) {
        GuiLoadSourceFileEx(srcjson.data(), func.func->start);
        return;
      }
      break;
    default:
      GuiAddLogMessage(
          "Dynamic Decompiler only supports arm/arm64 currently.\n");
      return;
  }
  GuiAddLogMessage(QString("Failed to decompile function %1.\n")
                       .arg(func.func->name.data())
                       .toUtf8()
                       .data());
}

static duint bridge_node_addr(duint entry, const mana::Insinfos &insns,
                             const mana::Insrefs &highfnoff, size_t i) {
  if (i >= insns.size()) return 0;
  if (highfnoff.size() != insns.size()) {
    return entry + insns[i].fnoff;
  }
  int offs[2] = { insns[i].fnoff, highfnoff[i] };
  return entry + *(addr_t *)&offs[0];
}

void show_graph_func(duint base, duint entry, const mana::Function* func,
                     const char* fileOpcodes, const QSet<int> *keypoints = nullptr) {
  BridgeCFGraph graph(entry);
  graph.userdata = (void*)base;
  auto& insns = func->insns;
  auto& highfnoff = func->rets; // reuse as the high32 bits of fnoff value
  const char* rtOpcodes = nullptr;
  duint lastPage = 0;
  auto arch = VMPGlobal::inst()->debugee->db->archType();
  for (size_t i = 0; i < insns.size();) {
    BridgeCFNode node(entry, entry, entry);
    for (bool bbend = false; i < insns.size() && !bbend; i++) {
      auto curi = &insns[i];
      if (curi->comins.size()) {
        if (node.instrs.size()) {
          bbend = true;
          node.split = true;
          node.brtrue = entry + curi->fnoff;
          break;
        } else {
          // bb start
          // or
          // bl abort/__stack_chk_failed
        }
      }
      BridgeCFInstruction brinsn;
      if (highfnoff.size() != insns.size()) {
        brinsn.addr = entry + curi->fnoff;
        memcpy(brinsn.data, fileOpcodes + curi->fnoff, sizeof(brinsn.data) - 1);
      }
      else {
        brinsn.addr = bridge_node_addr(entry, insns, highfnoff, i); // file address
        addr_t rtaddr = uvmWin->runtimeBase() + brinsn.addr - base; // runtime address
        duint page = rtaddr & ~UVMPAGE_MASK;
        if (page && page == lastPage) {
          memcpy(brinsn.data, rtOpcodes + rtaddr - page, sizeof(brinsn.data) - 1);
        }
        else {
          auto found = uvmWin->mPageBuffs.find(page);
          if (found != uvmWin->mPageBuffs.end()) {
            lastPage = page;
            rtOpcodes = found->second.data();
            memcpy(brinsn.data, rtOpcodes + rtaddr - page, sizeof(brinsn.data) - 1);
          } else {
            memset(brinsn.data, 0, sizeof(brinsn.data));
            GuiAddLogMessage(QString("Cannot find memory page at %1 for %2 (%3).\n")
                             .arg(i).arg(ToPtrString(rtaddr)).arg(ToPtrString(brinsn.addr))
                             .toUtf8().data());
          }
        }
      }
      if (arch == mana::ARM) {
        brinsn.data[sizeof(brinsn.data) - 1] = func->start & 1;  // for arm/thumb flag
      }
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
                      .arg(ToPtrString(bridge_node_addr(entry, insns, highfnoff, i)))
                      .toUtf8()
                      .data());
              continue;
            }
            gouts.push_back(i);
          }
          bbend = true;
          if (gouts.size()) {
            if (gouts.size() >= 2) {
              node.brfalse = bridge_node_addr(entry, insns, highfnoff, gouts[0]);
              node.brtrue = bridge_node_addr(entry, insns, highfnoff, gouts[1]);
              for (size_t i = 2; i < gouts.size(); i++) {
                node.exits.push_back(bridge_node_addr(entry, insns, highfnoff, gouts[i]));
              }
            } else {
              node.brtrue = bridge_node_addr(entry, insns, highfnoff, gouts[0]);
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
    if (keypoints) {
      // render keypoint node to indirectcall color
      for (auto &i : node.instrs) {
        if (keypoints->find(i.addr - base) != keypoints->end()) {
          node.indirectcall = true;
          break;
        }
      }
    }
    graph.AddNode(node);
  }
  BridgeCFGraphList glist = graph.ToGraphList();
  GuiLoadGraph(&glist, entry);
}

static void show_graph(const char* saddr) {
  auto addr = DbgValFromString(saddr);
  auto mdb = VMPGlobal::inst()->debugee;
  if (!mdb) return;
  auto base = mdb->db->imageBase();
  auto func = mdb->rvaToFunction(addr - base, false);
  if (!func) {
    GuiAddLogMessage(QString("Failed to find function at address %1.\n")
                         .arg(ToPtrString(addr))
                         .toUtf8()
                         .data());
    return;
  }
  auto entry = mdb->db->imageBase() + func.rvastart;
  show_graph_func(mdb->db->imageBase(), entry, func.func,
                  mdb->db->addrBuff(entry));
}

struct a64dbg_cmd_t {
  const char* name;
  std::function<void(const char*)> impl;
};

static bool a64dbg_cmdexec(const char* cmd) {
  static const a64dbg_cmd_t adcmds_any[] = {
      {"init",
       [](const char* cmd) {
         *(char*)(cmd + strlen(cmd) - 1) = 0;  // remove <">
         init_debugee_file(cmd + 6);           // skip <init ">
       }},
      {"launch",
       [](const char* cmd) { launch_debugee_file(cmd + sizeof("launch")); }},
      {"attach",
       [](const char* cmd) { init_debugee_process(cmd + sizeof("attach")); }},
  };
  static const a64dbg_cmd_t adcmds_dbg[] = {
      {"dump",
       [](const char* cmd) {
         const char* index = nullptr;
         uint64_t addr = parse_addr(cmd + 5, &index);
         GuiDumpAtN(
             addr,
             (index && index[0] == ',') ? atoi(&index[3]) : 1);  // skip <, .>
         GuiFocusView(GUI_DUMP);
       }},
      {"disasm",
       [](const char* cmd) {
         uint64_t addr = parse_addr(cmd + 7, nullptr);
         GuiDisasmAt(0, addr);
         GuiFocusView(GUI_DISASSEMBLY);
       }},
      {"detach", [](const char* cmd) { detach_debuggee(); }},
      {"uvmdetach", [](const char* cmd) { detach_uvm(); }},
      {"stop", [](const char* cmd) { detach_debuggee(); }},
      {"close", [](const char* cmd) { detach_debuggee(); }},
      {"save", [](const char* cmd) { save_debuggee(); }},
      {"bookmarklist", [](const char* cmd) { list_bookmark(); }},
      {"commentlist", [](const char* cmd) { list_comment(); }},
      {"functionlist", [](const char* cmd) { list_function(); }},
      {"list_import", [](const char* cmd) { list_import(); }},
      {"list_export", [](const char* cmd) { list_export(); }},
      {"list_module", [](const char* cmd) { list_module(); }},
      {"readobj", [](const char* cmd) { list_readobj(); }},
      {"readobjc", [](const char* cmd) { list_readobjc("--objc"); }},
      {"readswift", [](const char* cmd) { list_readobjc("--swift"); }},
      {"savefile", [](const char* cmd) { save_file(); }},
      {"decompile",
       [](const char* cmd) { retdec_decompile(cmd + sizeof("decompile")); }},
      {"urdyndec",
       [](const char* cmd) { urdyndec_decompile(cmd + sizeof("urdyndec")); }},
      {"graph", [](const char* cmd) { show_graph(cmd + sizeof("graph")); }},
  };

  char cmdtype[128];
  int i = 0;
  for (; cmd[i] && cmd[i] != ' ' && i < sizeof(cmdtype); i++) {
    cmdtype[i] = cmd[i];
  }
  cmdtype[i] = 0;

  for (size_t c = 0; c < sizeof(adcmds_any) / sizeof(adcmds_any[0]); c++) {
    if (strcmp(cmdtype, adcmds_any[c].name) == 0) {
      adcmds_any[c].impl(cmd);
      // processed
      return true;
    }
  }

  for (size_t c = 0; c < sizeof(adcmds_dbg) / sizeof(adcmds_dbg[0]); c++) {
    if (strcmp(cmdtype, adcmds_dbg[c].name) == 0) {
      if (DbgIsDebugging()) {
        adcmds_dbg[c].impl(cmd);
      }
      // processed
      return true;
    }
  }

  return false;
}

bool _dbg_dbgcmdexec(const char* cmd) {
  if (a64dbg_cmdexec(cmd)) return true;
  GuiAddLogMessage(QString("unimpl command : %1\n").arg(cmd).toUtf8().data());
  return false;
}

// DBG functions
const char* _dbg_dbginit() {
  if (VMPGlobal::inst()->isCloudPlatform()) {
    UVMClient::cloudPort([](int port) {
      vmpstudioPort = port;
    });
  }
  else {
    VMPGlobal::inst()->updateUSBForward();
  }

  SCRIPTTYPEINFO info;
  strcpy_s(info.name, "Action");
  info.id = 0;
  info.execute = [](const char* cmd) {
    std::string logcmd("(action) ");
    logcmd += cmd;
    logcmd += '\n';
    GuiAddLogMessage(logcmd.c_str());
    if (!DbgCmdExecDirect(cmd)) return false;
    GuiFlushLog();
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);

  return 0;
}

duint _dbg_memfindbaseaddr(duint addr, duint* size) {
  if (size) *size = PAGE_SIZE;
  return addr & ~(PAGE_SIZE - 1);
}

static inline bool should_updatepg(duint addr, QByteArray& page, QTime& oldtm,
                                   ManaDatabase* debugee) {
  QTime curtm = QTime::currentTime();
  // no need to update code page
  if (addr <= debugee->rtbase && addr < debugee->rtbase + debugee->opcsize) {
    return false;
  }
  // update every 30s for non debugee opcode pages
  return curtm.secsTo(oldtm) > 30;
}

bool _dbg_memread(duint addr, void* dest, duint size, duint* read) {
  auto global = DbgGlobal::inst();
  auto debugee = global->debugee;
  if (!debugee) {
    return false;
  }

  if (debugee->opcodes_cache && addr >= debugee->rtbase &&
      addr < debugee->rtbase + debugee->opcsize) {
    // read from file buffer if it's valid
    memcpy(dest, debugee->opcodes_cache + addr - debugee->rtbase, size);
  } else {
    memset(dest, 0, size);
  }
  if (read) {
    *read = size;
  }
  return true;
}

bool _dbg_memwrite(duint addr, const void* src, duint size, duint* written) {
  auto global = DbgGlobal::inst();
  auto debugee = global->debugee;
  if (!debugee) {
    return false;
  }

  if (debugee->opcodes_cache && addr >= debugee->rtbase &&
      addr < debugee->rtbase + debugee->opcsize) {
    // write to file buffer if it's valid
    memcpy(debugee->opcodes_cache + addr - debugee->rtbase, src, size);
  } else {
    duint base = _dbg_memfindbaseaddr(addr, nullptr);
    auto found = global->dbgpages.find(base);
    if (found != global->dbgpages.end()) {
      memcpy((char*)found->second.buffer.data() + addr - base, src, size);
    }
  }
  if (written) {
    *written = size;
  }
  return true;
}

bool _dbg_memmap(MEMMAP* memmap) { return 0; }

void _dbg_dbgexitsignal() {
  if (DbgIsDebugging()) {
    VMPGlobal::inst()->clearAll();
  }

  delete uranius;
  BridgeSettingFlush();
}

bool _dbg_valfromstring(const char* string, duint* value) {
  *value = strtoul(string, nullptr, 16);
  return false;
}

bool _dbg_isdebugging() { return VMPGlobal::inst()->debugee != nullptr; }

bool _dbg_isjumpgoingtoexecute(duint addr) { return false; }

bool _dbg_addrinfoget(duint addr, SEGMENTREG segment,
                      BRIDGE_ADDRINFO* addrinfo) {
#if 0
#define case_string(f)       \
  if (addrinfo->flags & f) { \
    logs += (char*)#f + 4;   \
    logs += " ";             \
  }
  std::string logs("Unimpl address infoget for ");
  case_string(flagmodule);
  case_string(flaglabel);
  case_string(flagcomment);
  case_string(flagbookmark);
  case_string(flagfunction);
  case_string(flagloop);
  case_string(flagargs);
  case_string(flagNoFuncOffset);
  logs += ".\n";
  GuiAddLogMessage(logs.c_str());
#endif
  return false;
}

bool _dbg_addrinfoset(duint addr, BRIDGE_ADDRINFO* addrinfo) { return 0; }
bool _dbg_encodetypeset(duint addr, duint size, ENCODETYPE type) { return 0; }

BPXTYPE _dbg_bpgettypeat(duint addr) { return bp_none; }

bool _dbg_getregdump(REGDUMP* regdump) { return false; }

bool _dbg_valtostring(const char* string, duint value) { return false; }

bool _dbg_memisvalidreadptr(duint addr) {
  auto debugee = VMPGlobal::inst()->debugee;
  return debugee->db->addrBuff(addr) != nullptr;
}

int _dbg_getbplist(BPXTYPE type, BPMAP* bplist) { return 0; }

bool _dbg_dbgcmddirectexec(const char* cmd) { return _dbg_dbgcmdexec(cmd); }

duint _dbg_getbranchdestination(ManaDatabase* dbraw, duint addr) {
  auto vg = VMPGlobal::inst();
  VMPManaDatabase* db = (VMPManaDatabase*)dbraw;
  auto opcode = db->db->addrBuff(addr);
  return vg->diser(nullptr)->branchTarget((unsigned char*)&opcode, addr);
}

static const char* dbgmsg_name(DBGMSG type) {
#define case_string(n) \
  case n:              \
    return (char*)(#n) + 4;

  switch (type) {
    case_string(DBG_SCRIPT_LOAD)  // ,           // param1=const char* filename)
                                  // // ,      param2=unused
        case_string(DBG_SCRIPT_UNLOAD)  // ,         // param1=unused) // ,
                                        // param2=unused
        case_string(DBG_SCRIPT_RUN)   // ,            // param1=int destline) //
                                      // ,              param2=unused
        case_string(DBG_SCRIPT_STEP)  // ,           // param1=unused) // ,
                                      // param2=unused
        case_string(DBG_SCRIPT_BPTOGGLE)  // ,       // param1=int line) // ,
                                          // param2=unused
        case_string(DBG_SCRIPT_BPGET)     // ,          // param1=int line) // ,
                                          // param2=unused
        case_string(DBG_SCRIPT_CMDEXEC)   // ,        // param1=const char*
                                          // command) // ,       param2=unused
        case_string(DBG_SCRIPT_ABORT)     // ,          // param1=unused) // ,
                                          // param2=unused
        case_string(DBG_SCRIPT_GETLINETYPE)  // ,    // param1=int line) // ,
                                             // param2=unused
        case_string(DBG_SCRIPT_SETIP)  // ,          // param1=int line) // ,
                                       // param2=unused
        case_string(DBG_SCRIPT_GETBRANCHINFO)  // ,  // param1=int line) // ,
                                               // param2=SCRIPTBRANCH* info
        case_string(DBG_SYMBOL_ENUM)  // ,           // param1=SYMBOLCBINFO*
                                      // cbInfo) // ,      param2=unused
        case_string(DBG_ASSEMBLE_AT)  // ,  // param1=duint addr) // ,
                                      // param2=const char* instruction
        case_string(DBG_MODBASE_FROM_NAME)  // ,  // param1=const char* modname)
                                            // // ,       param2=unused
        case_string(DBG_DISASM_AT)          // ,  // param1=duint addr) // ,
                                            // param2=DISASM_INSTR* instr
        case_string(DBG_STACK_COMMENT_GET)  // ,    // param1=duint addr) // ,
                                            // param2=STACK_COMMENT* comment
        case_string(DBG_GET_THREAD_LIST)    // ,      // param1=THREADALLINFO*
                                            // list) // ,       param2=unused
        case_string(
            DBG_SETTINGS_UPDATED)  // ,     // param1=unused) // , param2=unused
        case_string(
            DBG_DISASM_FAST_AT)  // ,       // param1=duint addr) // ,
                                 // param2=BASIC_INSTRUCTION_INFO* basicinfo
        case_string(DBG_MENU_ENTRY_CLICKED)  // ,   // param1=int hEntry) // ,
                                             // param2=unused
        case_string(
            DBG_FUNCTION_GET)  // ,         // param1=FUNCTION_LOOP_INFO* info)
                               // // ,  param2=unused
        case_string(
            DBG_FUNCTION_OVERLAPS)  // ,    // param1=FUNCTION_LOOP_INFO* info)
                                    // // ,  param2=unused
        case_string(
            DBG_FUNCTION_ADD)  // ,         // param1=FUNCTION_LOOP_INFO* info)
                               // // ,  param2=unused
        case_string(
            DBG_FUNCTION_DEL)  // ,         // param1=FUNCTION_LOOP_INFO* info)
                               // // ,  param2=unused
        case_string(
            DBG_LOOP_GET)  // ,             // param1=FUNCTION_LOOP_INFO* info)
                           // // ,  param2=unused
        case_string(
            DBG_LOOP_OVERLAPS)  // ,        // param1=FUNCTION_LOOP_INFO* info)
                                // // ,  param2=unused
        case_string(
            DBG_LOOP_ADD)  // ,             // param1=FUNCTION_LOOP_INFO* info)
                           // // ,  param2=unused
        case_string(
            DBG_LOOP_DEL)  // ,             // param1=FUNCTION_LOOP_INFO* info)
                           // // ,  param2=unused
        case_string(
            DBG_IS_RUN_LOCKED)  // ,        // param1=unused) // , param2=unused
        case_string(DBG_IS_BP_DISABLED)  // ,       // param1=duint addr) // ,
                                         // param2=unused
        case_string(DBG_SET_AUTO_COMMENT_AT)  // ,  // param1=duint addr) // ,
                                              // param2=const char* text
        case_string(DBG_DELETE_AUTO_COMMENT_RANGE)  // ,  // param1=duint start)
                                                    // // , param2=duint end
        case_string(DBG_SET_AUTO_LABEL_AT)  // ,  // param1=duint addr) // ,
                                            // param2=const char* text
        case_string(DBG_DELETE_AUTO_LABEL_RANGE)  // ,  // param1=duint start)
                                                  // // , param2=duint end
        case_string(DBG_SET_AUTO_BOOKMARK_AT)  // ,  // param1=duint addr) // ,
                                               // param2=const char* text
        case_string(
            DBG_DELETE_AUTO_BOOKMARK_RANGE)    // ,  // param1=duint start) // ,
                                               // param2=duint end
        case_string(DBG_SET_AUTO_FUNCTION_AT)  // ,  // param1=duint addr) // ,
                                               // param2=const char* text
        case_string(
            DBG_DELETE_AUTO_FUNCTION_RANGE)  // ,  // param1=duint start) // ,
                                             // param2=duint end
        case_string(
            DBG_GET_STRING_AT)  // ,  // param1=duint addr) // , param2=unused
        case_string(
            DBG_GET_FUNCTIONS)      // ,  // param1=unused) // , param2=unused
        case_string(DBG_WIN_EVENT)  // ,      // param1=MSG* message) // ,
                                    // param2=long* result
        case_string(DBG_WIN_EVENT_GLOBAL)  // ,    // param1=MSG* message) // ,
                                           // param2=unused
        case_string(
            DBG_INITIALIZE_LOCKS)  // ,    // param1=unused) // , param2=unused
        case_string(
            DBG_DEINITIALIZE_LOCKS)  // ,  // param1=unused) // , param2=unused
        case_string(DBG_GET_TIME_WASTED_COUNTER)  // ,  // param1=unused) // ,
                                                  // param2=unused
        case_string(DBG_SYMBOL_ENUM_FROMCACHE)    // ,  // param1=SYMBOLCBINFO*
                                                  // cbInfo) // , param2=unused
        case_string(DBG_DELETE_COMMENT_RANGE)  // ,   // param1=duint start) //
                                               // , param2=duint end
        case_string(DBG_DELETE_LABEL_RANGE)    // ,  // param1=duint start) // ,
                                               // param2=duint end
        case_string(DBG_DELETE_BOOKMARK_RANGE)  // ,  // param1=duint start) //
                                                // , param2=duint end
        case_string(DBG_GET_XREF_COUNT_AT)  // ,      // param1=duint addr) // ,
                                            // param2=unused
        case_string(DBG_GET_XREF_TYPE_AT)  // ,       // param1=duint addr) // ,
                                           // param2=unused
        case_string(DBG_XREF_ADD)          // ,      // param1=duint addr) // ,
                                           // param2=duint from
        case_string(
            DBG_XREF_DEL_ALL)  // ,  // param1=duint addr) // , param2=unused
        case_string(DBG_XREF_GET)  // ,      // param1=duint addr) // ,
                                   // param2=XREF_INFO* info
        case_string(DBG_GET_ENCODE_TYPE_BUFFER)  // ,  // param1=duint addr) //
                                                 // , param2=unused
        case_string(DBG_ENCODE_TYPE_GET)  // ,  // param1=duint addr) // ,
                                          // param2=duint size
        case_string(DBG_DELETE_ENCODE_TYPE_RANGE)  // ,  // param1=duint start)
                                                   // // , param2=duint end
        case_string(DBG_ENCODE_SIZE_GET)  // ,         // param1=duint addr) //
                                          // , param2=duint codesize
        case_string(DBG_DELETE_ENCODE_TYPE_SEG)  // ,  // param1=duint addr) //
                                                 // , param2=unused
        case_string(
            DBG_RELEASE_ENCODE_TYPE_BUFFER)  // ,  // param1=void* buffer) // ,
                                             // param2=unused
        case_string(DBG_ARGUMENT_GET)  // ,        // param1=FUNCTION* info) //
                                       // ,            param2=unused
        case_string(DBG_ARGUMENT_OVERLAPS)  // ,   // param1=FUNCTION* info) //
                                            // ,            param2=unused
        case_string(DBG_ARGUMENT_ADD)  // ,        // param1=FUNCTION* info) //
                                       // ,            param2=unused
        case_string(DBG_ARGUMENT_DEL)  // ,        // param1=FUNCTION* info) //
                                       // ,            param2=unused
        case_string(DBG_GET_WATCH_LIST)  // ,      // param1=ListOf(WATCHINFO))
                                         // // ,         param2=unused
        case_string(
            DBG_SELCHANGED)  // ,          // param1=hWindow) // , param2=VA
        case_string(
            DBG_GET_PROCESS_HANDLE)  // ,  // param1=unused) // , param2=unused
        case_string(
            DBG_GET_THREAD_HANDLE)  // ,   // param1=unused) // , param2=unused
        case_string(
            DBG_GET_PROCESS_ID)  // ,      // param1=unused) // , param2=unused
        case_string(
            DBG_GET_THREAD_ID)  // ,       // param1=unused) // , param2=unused
        case_string(DBG_GET_PEB_ADDRESS)  // ,     // param1=DWORD ProcessId) //
                                          // ,           param2=unused
        case_string(DBG_GET_TEB_ADDRESS)  // ,     // param1=DWORD ThreadId) //
                                          // ,            param2=unused
        case_string(DBG_ANALYZE_FUNCTION)  // ,  // param1=BridgeCFGraphList*
                                           // graph) // ,  param2=duint entry
        case_string(
            DBG_MENU_PREPARE)  // ,      // param1=int hMenu) // , param2=unused
        case_string(DBG_GET_SYMBOL_INFO)  // ,   // param1=void* symbol) // ,
                                          // param2=SYMBOLINFO* info
        case_string(
            DBG_GET_DEBUG_ENGINE)  // ,  // param1=unused) // , param2-unused
  }
  return "?";
}

duint _dbg_sendmessage(DBGMSG type, void* param1, void* param2) {
#if 0
  char unimplmsg[128];
  sprintf(unimplmsg, "Unimpl debugger message: %s %p %p\n",
          dbgmsg_name(type), param1, param2);
  GuiAddLogMessage(unimplmsg);
#endif
  return 0;
}

BRIDGE_IMPEXP const wchar_t* BridgeInit() { return 0; }

BRIDGE_IMPEXP const wchar_t* BridgeStart() {
  if (!_dbg_dbginit || !_gui_guiinit)
    return L"\"_dbg_dbginit\" || \"_gui_guiinit\" was not loaded yet, call "
           L"BridgeInit!";
  int errorLine = 0;
  BridgeSettingRead(&errorLine);
  _dbg_sendmessage(DBG_INITIALIZE_LOCKS, nullptr,
                   nullptr);  // initialize locks before any other thread than
                              // the main thread are started
  _gui_guiinit(0, 0);         // remove arguments
  if (!BridgeSettingFlush()) return L"Failed to save settings!";
  _dbg_sendmessage(
      DBG_DEINITIALIZE_LOCKS, nullptr,
      nullptr);  // deinitialize locks when only one thread is left (hopefully)
  return 0;
}

BRIDGE_IMPEXP void* BridgeAlloc(size_t size) {
  unsigned char* ptr = (unsigned char*)malloc(size);
  memset(ptr, 0, size);
  return ptr;
}

BRIDGE_IMPEXP void BridgeFree(void* ptr) {
  if (ptr) free(ptr);
}

BRIDGE_IMPEXP bool BridgeSettingGet(const char* section, const char* key,
                                    char* value, int vsize) {
  if (!section || !key || !value) return false;
  EnterCriticalSection(&csIni);
  auto foundValue = settings.GetValue(section, key);
  bool result = foundValue.length() > 0;
  if (result) strncpy(value, foundValue.c_str(), vsize);
  LeaveCriticalSection(&csIni);
  return result;
}

BRIDGE_IMPEXP bool BridgeSettingGetUint(const char* section, const char* key,
                                        duint* value) {
  if (!section || !key || !value) return false;
  char newvalue[MAX_SETTING_SIZE] = "";
  if (!BridgeSettingGet(section, key, newvalue)) return false;
#ifdef _WIN64
  int ret = sscanf_s(newvalue, "%llX", value);
#else
  int ret = sscanf_s(newvalue, "%X", value);
#endif  //_WIN64
  if (ret) return true;
  return false;
}

BRIDGE_IMPEXP bool BridgeSettingSet(const char* section, const char* key,
                                    const char* value) {
  bool success = false;
  if (section) {
    EnterCriticalSection(&csIni);
    if (!key)
      success = settings.ClearSection(section);
    else if (!value)
      success = settings.SetValue(section, key, "");
    else
      success = settings.SetValue(section, key, value);
    LeaveCriticalSection(&csIni);
  }
  return success;
}

BRIDGE_IMPEXP bool BridgeSettingSetUint(const char* section, const char* key,
                                        duint value) {
  if (!section || !key) return false;
  char newvalue[32] = "";
#ifdef _WIN64
  sprintf_s(newvalue, "%llX", value);
#else
  sprintf_s(newvalue, "%X", value);
#endif  //_WIN64
  return BridgeSettingSet(section, key, newvalue);
}

BRIDGE_IMPEXP bool BridgeSettingFlush() {
  EnterCriticalSection(&csIni);
  std::string iniData = settings.Serialize();
  LeaveCriticalSection(&csIni);
  bool success = false;
#if 0
    HANDLE hFile = CreateFileW(szIniFile, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if(hFile != INVALID_HANDLE_VALUE)
    {
        SetEndOfFile(hFile);
        DWORD written = 0;
        if(WriteFile(hFile, iniData.c_str(), (DWORD)iniData.length(), &written, nullptr))
            success = true;
        CloseHandle(hFile);
    }
#else
  auto initpath = DbgGlobal::inst()->cfgPath();
  FILE* fp = fopen_helper(initpath.toUtf8().data(), "w");
  if (fp) {
    fwrite(iniData.c_str(), 1, iniData.length(), fp);
    fclose(fp);
    success = true;
  }
#endif
  return success;
}

BRIDGE_IMPEXP bool BridgeSettingRead(int* errorLine) {
  if (errorLine) *errorLine = 0;
  bool success = false;
  std::string iniData;
#if 0
    HANDLE hFile = CreateFileW(szIniFile, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if(hFile != INVALID_HANDLE_VALUE)
    {
        DWORD fileSize = GetFileSize(hFile, nullptr);
        if(fileSize)
        {
            unsigned char utf8bom[] = { 0xEF, 0xBB, 0xBF };
            char* fileData = (char*)BridgeAlloc(sizeof(utf8bom) + fileSize + 1);
            DWORD read = 0;
            if(ReadFile(hFile, fileData, fileSize, &read, nullptr))
            {
                success = true;
                if(!memcmp(fileData, utf8bom, sizeof(utf8bom)))
                    iniData.assign(fileData + sizeof(utf8bom));
                else
                    iniData.assign(fileData);
            }
            BridgeFree(fileData);
        }
        CloseHandle(hFile);
    }
#else
  auto initpath = DbgGlobal::inst()->cfgPath();
  FILE* hFile = fopen_helper(initpath.toUtf8().data(), "r");
  if (hFile != nullptr) {
    fseek(hFile, 0, SEEK_END);
    DWORD fileSize = ftell(hFile);
    fseek(hFile, 0, SEEK_SET);
    if (fileSize) {
      unsigned char utf8bom[] = {0xEF, 0xBB, 0xBF};
      char* fileData = (char*)BridgeAlloc(sizeof(utf8bom) + fileSize + 1);
      DWORD read = 0;
      fread(fileData, 1, fileSize, hFile);
      if (1) {
        success = true;
        if (!memcmp(fileData, utf8bom, sizeof(utf8bom)))
          iniData.assign(fileData + sizeof(utf8bom));
        else
          iniData.assign(fileData);
      }
      BridgeFree(fileData);
    }
    fclose(hFile);
  }
#endif
  if (success)  // if we failed to read the file, the current settings are
                // better than none at all
  {
    EnterCriticalSection(&csIni);
    int errline = 0;
    success = settings.Deserialize(iniData, errline);
    if (errorLine) *errorLine = errline;
    LeaveCriticalSection(&csIni);
  }
  return success;
}

BRIDGE_IMPEXP int BridgeGetDbgVersion() { return DBG_VERSION; }

BRIDGE_IMPEXP bool BridgeIsProcessElevated() {
#if 0
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID SecurityIdentifier;
    if(!AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &SecurityIdentifier))
        return 0;

    BOOL IsAdminMember;
    if(!CheckTokenMembership(NULL, SecurityIdentifier, &IsAdminMember))
        IsAdminMember = FALSE;

    FreeSid(SecurityIdentifier);
    return !!IsAdminMember;
#else
  return false;
#endif
}

BRIDGE_IMPEXP bool DbgMemRead(duint va, void* dest, duint size) {
#ifdef _DEBUG
  if (IsBadWritePtr(dest, size)) {
    GuiAddLogMessage("DbgMemRead with invalid boundaries!\n");
    __debugbreak();
    return false;
  }
#endif  //_DEBUG

  if (!_dbg_memread(va, dest, size, 0)) {
    // Zero the buffer on failure
    memset(dest, 0, size);
    return false;
  }

  return true;
}

BRIDGE_IMPEXP bool DbgMemWrite(duint va, const void* src, duint size) {
#ifdef _DEBUG
  if (IsBadReadPtr(src, size)) {
    GuiAddLogMessage("DbgMemWrite with invalid boundaries!\n");
    __debugbreak();
    return false;
  }
#endif  //_DEBUG
  return _dbg_memwrite(va, src, size, 0);
}

// FIXME, not exactly base if it still does a find?
BRIDGE_IMPEXP duint DbgMemGetPageSize(duint base) {
  duint size = 0;
  _dbg_memfindbaseaddr(base, &size);
  return size;
}

BRIDGE_IMPEXP duint DbgMemFindBaseAddr(duint addr, duint* size) {
  return _dbg_memfindbaseaddr(addr, size);
}

BRIDGE_IMPEXP bool DbgCmdExec(const char* cmd) { return _dbg_dbgcmdexec(cmd); }

// FIXME
BRIDGE_IMPEXP bool DbgMemMap(MEMMAP* memmap) { return _dbg_memmap(memmap); }

BRIDGE_IMPEXP bool DbgIsValidExpression(const char* expression) {
  duint value = 0;
  return _dbg_valfromstring(expression, &value);
}

BRIDGE_IMPEXP bool DbgIsDebugging() { return _dbg_isdebugging(); }

BRIDGE_IMPEXP bool DbgIsJumpGoingToExecute(duint addr) {
  return _dbg_isjumpgoingtoexecute(addr);
}

// FIXME required size of arg _text_?
BRIDGE_IMPEXP bool DbgGetLabelAt(duint addr, SEGMENTREG segment,
                                 char* text)  //(module.)+label
{
#if 0
  if (!text || !addr) return false;
  BRIDGE_ADDRINFO info;
  memset(&info, 0, sizeof(info));
  info.flags = flaglabel | flagNoFuncOffset;
  if (!_dbg_addrinfoget(addr, segment, &info)) {
    duint addr_ = 0;
    if (!DbgMemIsValidReadPtr(addr)) return false;
    DbgMemRead(addr, (unsigned char*)&addr_, sizeof(duint));
    BRIDGE_ADDRINFO ptrinfo = info;
    if (!_dbg_addrinfoget(addr_, SEG_DEFAULT, &ptrinfo)) return false;
    _snprintf_s(info.label, _TRUNCATE, "&%s", ptrinfo.label);
  }
  strcpy_s(text, info.label);
  return true;
#else
  return false;
#endif
}

BRIDGE_IMPEXP bool DbgSetLabelAt(duint addr, const char* text) {
  if (!text || strlen(text) >= MAX_LABEL_SIZE || !addr) return false;
  BRIDGE_ADDRINFO info;
  memset(&info, 0, sizeof(info));
  info.flags = flaglabel;
  strcpy_s(info.label, text);
  if (!_dbg_addrinfoset(addr, &info)) return false;
  return true;
}

BRIDGE_IMPEXP void DbgClearLabelRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_LABEL_RANGE, (void*)start, (void*)end);
}

// FIXME required size of arg _text_?
BRIDGE_IMPEXP bool DbgGetCommentAt(ManaDatabase* adb, duint addr,
                                   char* text)  // comment (not live)
{
  if (!text || !addr) return false;
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return false;

  duint rva = addr - db->rtbase;
  auto cmmt = db->usrdef.find(UDKEY_COMMENT);
  if (cmmt == db->usrdef.end()) {
    return false;
  }
  QVariantMap& addrcmmt = *(QVariantMap*)&*cmmt;
  auto found = addrcmmt.find(ToPtrString(rva));
  if (found == addrcmmt.end()) {
    return false;
  }
  strcpy(text, found->toString().toUtf8().data());
  return true;
}

BRIDGE_IMPEXP bool DbgSetCommentAt(ManaDatabase* adb, duint addr,
                                   const char* text) {
  if (!text || strlen(text) >= MAX_COMMENT_SIZE || !addr) return false;
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return false;

  duint rva = addr - db->rtbase;
  auto cmmt = db->usrdef.find(UDKEY_COMMENT);
  if (cmmt == db->usrdef.end()) {
    cmmt = db->usrdef.insert(UDKEY_COMMENT, QVariantMap());
  }
  QVariantMap& addrcmmt = *(QVariantMap*)&*cmmt;
  addrcmmt.insert(ToPtrString(rva), text);
  return true;
}

BRIDGE_IMPEXP void DbgClearCommentRange(ManaDatabase* adb, duint start,
                                        duint end) {
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return;

  duint rvastart = start - db->rtbase;
  duint rvaend = end - db->rtbase;
  auto cmmt = db->usrdef.find(UDKEY_COMMENT);
  if (cmmt == db->usrdef.end()) {
    return;
  }
  QVariantMap& addrcmmt = *(QVariantMap*)&*cmmt;
  for (duint rva = rvastart + 4 - rvastart % 4; rva < rvaend; rva += 4) {
    auto found = addrcmmt.find(ToPtrString(rva));
    if (found != addrcmmt.end()) {
      addrcmmt.erase(found);
    }
  }
}

// FIXME required size of arg _text_?
BRIDGE_IMPEXP bool DbgGetModuleAt(duint addr, char* text) { return false; }

BRIDGE_IMPEXP ManaDatabase* DbgGetModuleAtEx(duint addr) {
  return (ManaDatabase*)VMPGlobal::inst()->getModule("");
}

BRIDGE_IMPEXP bool DbgGetBookmarkAt(ManaDatabase* adb, duint addr) {
  if (!DbgIsDebugging()) return false;
  if (!addr) return false;
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return false;

  duint rva = addr - db->rtbase;
  auto bkmk = db->usrdef.find(UDKEY_BOOKMARK);
  if (bkmk == db->usrdef.end()) {
    return false;
  }
  QVariantMap& addrbkmk = *(QVariantMap*)&*bkmk;
  auto found = addrbkmk.find(ToPtrString(rva));
  if (found == addrbkmk.end()) {
    return false;
  }
  return found->toBool();
}

BRIDGE_IMPEXP bool DbgSetBookmarkAt(ManaDatabase* adb, duint addr,
                                    bool isbookmark) {
  if (!addr) return false;
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return false;

  duint rva = addr - db->rtbase;
  auto bkmk = db->usrdef.find(UDKEY_BOOKMARK);
  if (bkmk == db->usrdef.end()) {
    bkmk = db->usrdef.insert(UDKEY_BOOKMARK, QVariantMap());
  }
  QVariantMap& addrbkmk = *(QVariantMap*)&*bkmk;
  addrbkmk.insert(ToPtrString(rva), isbookmark);
  return true;
}

BRIDGE_IMPEXP void DbgClearBookmarkRange(ManaDatabase* adb, duint start,
                                         duint end) {
  auto db = DbgGlobal::inst()->debugee;
  if (!db) return;

  duint rvastart = start - db->rtbase;
  duint rvaend = end - db->rtbase;
  auto bkmk = db->usrdef.find(UDKEY_BOOKMARK);
  if (bkmk == db->usrdef.end()) {
    return;
  }
  QVariantMap& addrbkmk = *(QVariantMap*)&*bkmk;
  for (duint rva = rvastart + 4 - rvastart % 4; rva < rvaend; rva += 4) {
    auto found = addrbkmk.find(ToPtrString(rva));
    if (found != addrbkmk.end()) {
      addrbkmk.erase(found);
    }
  }
}

// FIXME return on success?
BRIDGE_IMPEXP const char* DbgInit() { return _dbg_dbginit(); }

BRIDGE_IMPEXP void DbgExit() {
  _dbg_dbgexitsignal();  // send exit signal to debugger
}

BRIDGE_IMPEXP BPXTYPE DbgGetBpxTypeAt(duint addr) {
  return _dbg_bpgettypeat(addr);
}

BRIDGE_IMPEXP duint DbgValFromString(const char* string) {
  duint value = 0;
  _dbg_valfromstring(string, &value);
  return value;
}

// deprecated api, only provided for binary compatibility
extern "C" __declspec(dllexport) bool DbgGetRegDump(REGDUMP* regdump) {
  typedef struct {
    REGISTERCONTEXT regcontext;
    FLAGS flags;
    X87FPUREGISTER x87FPURegisters[8];
    duint mmx[8];
    MXCSRFIELDS MxCsrFields;
    X87STATUSWORDFIELDS x87StatusWordFields;
    X87CONTROLWORDFIELDS x87ControlWordFields;
    LASTERROR lastError;
  } REGDUMP_OLD;
  return DbgGetRegDumpEx(regdump, sizeof(REGDUMP_OLD));
}

BRIDGE_IMPEXP bool DbgGetRegDumpEx(REGDUMP* regdump, size_t size) {
  if (size == sizeof(REGDUMP)) return _dbg_getregdump(regdump);

  if (size > sizeof(REGDUMP)) __debugbreak();

  REGDUMP temp;
  if (!_dbg_getregdump(&temp)) {
    memset(regdump, 0, size);
    return false;
  }
  memcpy(regdump, &temp, size);
  return true;
}

// FIXME all
BRIDGE_IMPEXP bool DbgValToString(const char* string, duint value) {
  return _dbg_valtostring(string, value);
}

BRIDGE_IMPEXP bool DbgMemIsValidReadPtr(duint addr) {
  return _dbg_memisvalidreadptr(addr);
}

// FIXME return
BRIDGE_IMPEXP int DbgGetBpList(BPXTYPE type, BPMAP* list) {
  return _dbg_getbplist(type, list);
}

// FIXME all
BRIDGE_IMPEXP bool DbgCmdExecDirect(const char* cmd) {
  return _dbg_dbgcmddirectexec(cmd);
}

BRIDGE_IMPEXP FUNCTYPE DbgGetFunctionTypeAt(duint addr) {
  BRIDGE_ADDRINFO info;
  memset(&info, 0, sizeof(info));
  info.flags = flagfunction;
  if (!_dbg_addrinfoget(addr, SEG_DEFAULT, &info)) return FUNC_NONE;
  duint start = info.function.start;
  duint end = info.function.end;
  if (start == end || info.function.instrcount == 1)
    return FUNC_SINGLE;
  else if (addr == start)
    return FUNC_BEGIN;
  else if (addr == end)
    return FUNC_END;
  return FUNC_MIDDLE;
}

// FIXME depth
BRIDGE_IMPEXP LOOPTYPE DbgGetLoopTypeAt(duint addr, int depth) {
  BRIDGE_ADDRINFO info;
  memset(&info, 0, sizeof(info));
  info.flags = flagloop;
  info.loop.depth = depth;
  if (!_dbg_addrinfoget(addr, SEG_DEFAULT, &info)) return LOOP_NONE;
  duint start = info.loop.start;
  duint end = info.loop.end;
  if (start == end || info.loop.instrcount == 1)
    return LOOP_SINGLE;
  else if (addr == start)
    return LOOP_BEGIN;
  else if (addr == end)
    return LOOP_END;
  return LOOP_MIDDLE;
}

BRIDGE_IMPEXP duint DbgGetBranchDestination(ManaDatabase* db, duint addr) {
  return _dbg_getbranchdestination(db, addr);
}

BRIDGE_IMPEXP void DbgScriptLoad(const char* filename) {
  _dbg_sendmessage(DBG_SCRIPT_LOAD, (void*)filename, 0);
}

// FIXME every?
BRIDGE_IMPEXP void DbgScriptUnload() {
  _dbg_sendmessage(DBG_SCRIPT_UNLOAD, 0, 0);
}

// FIXME "the script?"; destline
BRIDGE_IMPEXP void DbgScriptRun(int destline) {
  _dbg_sendmessage(DBG_SCRIPT_RUN, (void*)(duint)destline, 0);
}

BRIDGE_IMPEXP void DbgScriptStep() { _dbg_sendmessage(DBG_SCRIPT_STEP, 0, 0); }

BRIDGE_IMPEXP bool DbgScriptBpToggle(int line) {
  if (_dbg_sendmessage(DBG_SCRIPT_BPTOGGLE, (void*)(duint)line, 0)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgScriptBpGet(int line) {
  if (_dbg_sendmessage(DBG_SCRIPT_BPGET, (void*)(duint)line, 0)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgScriptCmdExec(const char* command) {
  if (_dbg_sendmessage(DBG_SCRIPT_CMDEXEC, (void*)command, 0)) return true;
  return false;
}

BRIDGE_IMPEXP void DbgScriptAbort() {
  _dbg_sendmessage(DBG_SCRIPT_ABORT, 0, 0);
}

BRIDGE_IMPEXP SCRIPTLINETYPE DbgScriptGetLineType(int line) {
  return (SCRIPTLINETYPE)_dbg_sendmessage(DBG_SCRIPT_GETLINETYPE,
                                          (void*)(duint)line, 0);
}

BRIDGE_IMPEXP void DbgScriptSetIp(int line) {
  _dbg_sendmessage(DBG_SCRIPT_SETIP, (void*)(duint)line, 0);
}

// FIXME non-null?
BRIDGE_IMPEXP bool DbgScriptGetBranchInfo(int line, SCRIPTBRANCH* info) {
  return !!_dbg_sendmessage(DBG_SCRIPT_GETBRANCHINFO, (void*)(duint)line, info);
}

// FIXME all
BRIDGE_IMPEXP void DbgSymbolEnum(duint base, CBSYMBOLENUM cbSymbolEnum,
                                 void* user) {}

// FIXME all
BRIDGE_IMPEXP void DbgSymbolEnumFromCache(duint base, CBSYMBOLENUM cbSymbolEnum,
                                          void* user) {
  DbgSymbolEnum(base, cbSymbolEnum, user);
}

BRIDGE_IMPEXP bool DbgAssembleAt(duint addr, const char* instruction) {
  if (_dbg_sendmessage(DBG_ASSEMBLE_AT, (void*)addr, (void*)instruction))
    return true;
  return false;
}

BRIDGE_IMPEXP duint DbgModBaseFromName(const char* name) {
  return _dbg_sendmessage(DBG_MODBASE_FROM_NAME, (void*)name, 0);
}

BRIDGE_IMPEXP void DbgDisasmAt(duint addr, DISASM_INSTR* instr) {
  if (!_dbg_sendmessage(DBG_DISASM_AT, (void*)addr, instr)) {
    memset(instr, 0, sizeof(instr[0]));
  }
}

BRIDGE_IMPEXP bool DbgStackCommentGet(duint addr, STACK_COMMENT* comment) {
  return !!_dbg_sendmessage(DBG_STACK_COMMENT_GET, (void*)addr, comment);
}

BRIDGE_IMPEXP void DbgGetThreadList(THREADLIST* list) {
  list->count = 0;
  list->list = nullptr;
}

BRIDGE_IMPEXP void DbgSettingsUpdated() {
  _dbg_sendmessage(DBG_SETTINGS_UPDATED, 0, 0);
}

BRIDGE_IMPEXP void DbgDisasmFastAt(duint addr,
                                   BASIC_INSTRUCTION_INFO* basicinfo) {
  _dbg_sendmessage(DBG_DISASM_FAST_AT, (void*)addr, basicinfo);
}

BRIDGE_IMPEXP void DbgMenuEntryClicked(int hEntry) {
  _dbg_sendmessage(DBG_MENU_ENTRY_CLICKED, (void*)(duint)hEntry, 0);
}

// FIXME not sure
BRIDGE_IMPEXP bool DbgFunctionGet(duint addr, duint* start, duint* end) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  if (!_dbg_sendmessage(DBG_FUNCTION_GET, &info, 0)) return false;
  if (start) *start = info.start;
  if (end) *end = info.end;
  return true;
}

// FIXME brief, return
BRIDGE_IMPEXP bool DbgFunctionOverlaps(duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  if (!_dbg_sendmessage(DBG_FUNCTION_OVERLAPS, &info, 0)) return false;
  return true;
}

// FIXME brief, return
BRIDGE_IMPEXP bool DbgFunctionAdd(duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  info.manual = false;
  if (!_dbg_sendmessage(DBG_FUNCTION_ADD, &info, 0)) return false;
  return true;
}

// FIXME brief, return
BRIDGE_IMPEXP bool DbgFunctionDel(duint addr) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  if (!_dbg_sendmessage(DBG_FUNCTION_DEL, &info, 0)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgArgumentGet(duint addr, duint* start, duint* end) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  if (!_dbg_sendmessage(DBG_ARGUMENT_GET, &info, 0)) return false;
  if (start) *start = info.start;
  if (end) *end = info.end;
  return true;
}

BRIDGE_IMPEXP bool DbgArgumentOverlaps(duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  if (!_dbg_sendmessage(DBG_ARGUMENT_OVERLAPS, &info, 0)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgArgumentAdd(duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  info.manual = false;
  if (!_dbg_sendmessage(DBG_ARGUMENT_ADD, &info, 0)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgArgumentDel(duint addr) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  if (!_dbg_sendmessage(DBG_ARGUMENT_DEL, &info, 0)) return false;
  return true;
}

// FIXME depth
BRIDGE_IMPEXP bool DbgLoopGet(int depth, duint addr, duint* start, duint* end) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  info.depth = depth;
  if (!_dbg_sendmessage(DBG_LOOP_GET, &info, 0)) return false;
  if (start) *start = info.start;
  if (end) *end = info.end;
  return true;
}

// FIXME brief, depth, return
BRIDGE_IMPEXP bool DbgLoopOverlaps(int depth, duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  info.depth = depth;
  if (!_dbg_sendmessage(DBG_LOOP_OVERLAPS, &info, 0)) return false;
  return true;
}

// FIXME brief, return
BRIDGE_IMPEXP bool DbgLoopAdd(duint start, duint end) {
  FUNCTION_LOOP_INFO info;
  info.start = start;
  info.end = end;
  info.manual = false;
  if (!_dbg_sendmessage(DBG_LOOP_ADD, &info, 0)) return false;
  return true;
}

// FIXME brief, brief
BRIDGE_IMPEXP bool DbgLoopDel(int depth, duint addr) {
  FUNCTION_LOOP_INFO info;
  info.addr = addr;
  info.depth = depth;
  if (!_dbg_sendmessage(DBG_LOOP_DEL, &info, 0)) return false;
  return true;
}

BRIDGE_IMPEXP size_t DbgGetXrefCountAt(duint addr) {
  return _dbg_sendmessage(DBG_GET_XREF_COUNT_AT, (void*)addr, 0);
}

BRIDGE_IMPEXP XREFTYPE DbgGetXrefTypeAt(duint addr) {
  return (XREFTYPE)_dbg_sendmessage(DBG_GET_XREF_TYPE_AT, (void*)addr, 0);
}

BRIDGE_IMPEXP bool DbgXrefAdd(duint addr, duint from) {
  if (!_dbg_sendmessage(DBG_XREF_ADD, (void*)addr, (void*)from)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgXrefDelAll(duint addr) {
  if (!_dbg_sendmessage(DBG_XREF_DEL_ALL, (void*)addr, 0)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgXrefGet(duint addr, XREF_INFO* info) {
  if (!_dbg_sendmessage(DBG_XREF_GET, (void*)addr, info)) return false;
  return true;
}

BRIDGE_IMPEXP bool DbgGetWatchList(ListOf(WATCHINFO) list) { return false; }

// FIXME all
BRIDGE_IMPEXP bool DbgIsRunLocked() {
  if (_dbg_sendmessage(DBG_IS_RUN_LOCKED, 0, 0)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgIsBpDisabled(duint addr) {
  if (_dbg_sendmessage(DBG_IS_BP_DISABLED, (void*)addr, 0)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgSetAutoCommentAt(duint addr, const char* text) {
  if (_dbg_sendmessage(DBG_SET_AUTO_COMMENT_AT, (void*)addr, (void*)text))
    return true;
  return false;
}

// FIXME brief
BRIDGE_IMPEXP void DbgClearAutoCommentRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_AUTO_COMMENT_RANGE, (void*)start, (void*)end);
}

BRIDGE_IMPEXP bool DbgSetAutoLabelAt(duint addr, const char* text) {
  if (_dbg_sendmessage(DBG_SET_AUTO_LABEL_AT, (void*)addr, (void*)text))
    return true;
  return false;
}

// FIXME brief
BRIDGE_IMPEXP void DbgClearAutoLabelRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_AUTO_LABEL_RANGE, (void*)start, (void*)end);
}

BRIDGE_IMPEXP bool DbgSetAutoBookmarkAt(duint addr) {
  if (_dbg_sendmessage(DBG_SET_AUTO_BOOKMARK_AT, (void*)addr, 0)) return true;
  return false;
}

// FIXME brief
BRIDGE_IMPEXP void DbgClearAutoBookmarkRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_AUTO_BOOKMARK_RANGE, (void*)start, (void*)end);
}

BRIDGE_IMPEXP bool DbgSetAutoFunctionAt(duint start, duint end) {
  if (_dbg_sendmessage(DBG_SET_AUTO_FUNCTION_AT, (void*)start, (void*)end))
    return true;
  return false;
}

// FIXME brief
BRIDGE_IMPEXP void DbgClearAutoFunctionRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_AUTO_FUNCTION_RANGE, (void*)start, (void*)end);
}

// FIXME size of the buffer?
BRIDGE_IMPEXP bool DbgGetStringAt(duint addr, char* text) {
  if (_dbg_sendmessage(DBG_GET_STRING_AT, (void*)addr, text)) return true;
  return false;
}

static bool GetApkApps(DBGPROCESSINFO** entries, int* count) {
  *entries = nullptr;
  *count = 0;

  QString listbuff = svr_shell("pm list packages -3 -f", true, false);
  QStringList lists = listbuff.split('\n');
  for (auto it = lists.begin(); it != lists.end();) {
    if (!it->startsWith("pack")) {
      it = lists.erase(it);
      continue;
    }
    it++;
  }
  *count = lists.size();
  *entries = (DBGPROCESSINFO*)BridgeAlloc(*count * sizeof(**entries));
  for (int i = 0; i < lists.size(); i++) {
    auto ent = &entries[0][i];
    auto path = lists[i].toUtf8();
    const char* ptr = path.data();
    memset(ent, 0, sizeof(*ent));
    while (*ptr != '/') ptr++;
    strcpy(ent->szExeFile, ptr);
  }

  return *entries != nullptr;
}

static const char* ps_command(PlatformType pt) {
  switch (pt) {
    case pt_remote_android:
    case pt_remote_uraniumvm_android:
    case pt_remote_vp_android:
      return "ps";
    default:
      return "LANG=zh_CN.UTF-8 ps -e";
  }
}

static void* nop_impl() { return nullptr; }

BRIDGE_IMPEXP const DBGFUNCTIONS* DbgFunctions() {
  static DBGFUNCTIONS fns = {nullptr};
  if (fns.SectionFromAddr) {
    return &fns;
  }

  void** ptr = (void**)&fns;
  for (size_t i = 0; i < sizeof(fns) / sizeof(ptr[0]); i++) {
    ptr[i] = (void*)nop_impl;
  }
  fns.ValFromString = [](const char* string, duint* value) {
    *value = DbgValFromString(string);
    return true;
  };
  fns.GetProcessList = [](DBGPROCESSINFO** entries, int* count) {
    if (count && count[0] == 'apk') {
      return GetApkApps(entries, count);
    }

    *entries = nullptr;
    *count = 0;
#ifdef _WIN32
    if (DbgGlobal::inst()->currentPlatform() == pt_local_mac) {
      GuiAddLogMessage("Suggest you to use X64Dbg to debug windows program.\n");
      return false;
    }
#endif
    auto callback = [entries, count](const QString& listbuff) {
      if (1) {
        if (listbuff.indexOf("PID ") < 0) {
          if (listbuff.length()) {
            GuiAddLogMessage(listbuff.toUtf8().data());
          } else {
            GuiAddLogMessage("Failed to get process list.\n");
          }
          return;
        }
        QStringList lists = listbuff.split('\n');
        /*
macOS:
% ps -e
PID TTY           TIME CMD
1 ??         4:51.65 /sbin/launchd
67 ??         0:05.84 /usr/sbin/syslogd
68 ??         0:07.61 /usr/libexec/UserEventAgent (System)

iPhone:~ root# ps -e
2020-12-27 12:01:41.964 ps[3093:20389] [Enable]
2020-12-27 12:01:41.965 ps[3093:20389] [Enable]
PID TTY           TIME CMD
1 ??         0:07.92 /sbin/launchd
90 ??         0:06.82 /usr/libexec/securityd
104 ??         0:10.95 /usr/libexec/trustd
315 ??         0:00.39 /usr/libexec/amfid

Android:
$ ps -e
USER           PID  PPID     VSZ    RSS WCHAN            ADDR S NAME
root             1     0   11580   2016 SyS_epoll_wait      0 S init
root             2     0       0      0 kthreadd            0 S [kthreadd]
root             3     2       0      0 smpboot_thread_fn   0 S [ksoftirqd/0]
        */
        long nameoff = 0;
        while (lists[0].indexOf("PID ") < 0) {
          lists.erase(lists.begin());
        }
        QByteArray hdrline = lists[0].toUtf8();
        int hdrlen = hdrline.size();
        for (char* p = hdrline.data(); *p; p++) {
          if (*(int*)p == *(int*)" CMD" || *(int*)p == *(int*)" NAME") {
            nameoff = p - hdrline.data() + 1;
            break;
          }
        }
        lists.erase(lists.begin());

        *count = lists.size();
        if (!*count) {
          return;
        }
        *entries = (DBGPROCESSINFO*)BridgeAlloc(*count * sizeof(**entries));
        for (int i = 0; i < lists.size(); i++) {
          QByteArray lbuff = lists[i].toUtf8();
          // invalid line
          if (lbuff.size() < nameoff) {
            *count = i;
            break;
          }
          const char* str = lbuff.data();
          // parse pid
          if (isalpha(*str)) {
            while (*str != ' ') str++;
          }
          while (*str && *str == ' ') str++;
          entries[0][i].dwProcessId = (DWORD)atoi(str);
          if (!entries[0][i].dwProcessId) {
            memset(&entries[0][i], 0, sizeof(entries[0][i]));
            continue;
          }
          // parse name
          str = lbuff.data() + nameoff;
          if (str[-1] != ' ') {
            str = lbuff.data() + lbuff.size();
            while (*str != ' ') str--;
            str++;
          }
          strncpy(entries[0][i].szExeFile, str,
                  sizeof(entries[0][i].szExeFile));
          entries[0][i].szExeArgs[0] = 0;
          entries[0][i].szExeMainWindowTitle[0] = 0;
        }
      }
    };
    QString result = svr_shell(ps_command(pt_remote_ios), true, false);
    callback(result);
    if (!*count) {
      // make android use ps command to get process list
      result = svr_shell(ps_command(pt_remote_android), true, false);
      callback(result);
    }
    return *entries != nullptr;
  };
  fns.ModBaseFromAddr = [](duint addr) -> duint {
    if (DbgIsDebugging()) {
      return VMPGlobal::inst()->debugee->db->imageBase();
    }
    return 0;
  };
  fns.VaToFileOffset = [](duint addr) {
    duint result = 0;
    if (!DbgIsDebugging()) return result;
    for (auto& s : VMPGlobal::inst()->debugee->db->sections()) {
      if (addr >= s.second.addr && addr < s.second.addr + s.second.size) {
        result = s.second.foff + addr - s.second.addr;
        break;
      }
    }
    return result;
  };
  return &fns;
}

BRIDGE_IMPEXP bool DbgWinEvent(MSG* message, long* result) {
  if (_dbg_sendmessage(DBG_WIN_EVENT, message, result)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgWinEventGlobal(MSG* message) {
  if (_dbg_sendmessage(DBG_WIN_EVENT_GLOBAL, message, 0)) return true;
  return false;
}

BRIDGE_IMPEXP bool DbgIsRunning() { return !DbgIsRunLocked(); }

BRIDGE_IMPEXP duint DbgGetTimeWastedCounter() {
  return _dbg_sendmessage(DBG_GET_TIME_WASTED_COUNTER, nullptr, nullptr);
}

BRIDGE_IMPEXP ARGTYPE DbgGetArgTypeAt(duint addr) {
  BRIDGE_ADDRINFO info;
  memset(&info, 0, sizeof(info));
  info.flags = flagargs;
  if (!_dbg_addrinfoget(addr, SEG_DEFAULT, &info)) return ARG_NONE;
  duint start = info.args.start;
  duint end = info.args.end;
  if (start == end || info.args.instrcount == 1)
    return ARG_SINGLE;
  else if (addr == start)
    return ARG_BEGIN;
  else if (addr == end)
    return ARG_END;
  return ARG_MIDDLE;
}

BRIDGE_IMPEXP void* DbgGetEncodeTypeBuffer(duint addr, duint* size) {
  return (void*)_dbg_sendmessage(DBG_GET_ENCODE_TYPE_BUFFER, (void*)addr, size);
}

BRIDGE_IMPEXP void DbgReleaseEncodeTypeBuffer(void* buffer) {
  _dbg_sendmessage(DBG_RELEASE_ENCODE_TYPE_BUFFER, buffer, nullptr);
}

BRIDGE_IMPEXP ENCODETYPE DbgGetEncodeTypeAt(duint addr, duint size) {
  return (ENCODETYPE)_dbg_sendmessage(DBG_ENCODE_TYPE_GET, (void*)addr,
                                      (void*)size);
}

BRIDGE_IMPEXP duint DbgGetEncodeSizeAt(duint addr, duint codesize) {
  return _dbg_sendmessage(DBG_ENCODE_SIZE_GET, (void*)addr, (void*)codesize);
}

BRIDGE_IMPEXP bool DbgSetEncodeType(duint addr, duint size, ENCODETYPE type) {
  return _dbg_encodetypeset(addr, size, type);
}

BRIDGE_IMPEXP void DbgDelEncodeTypeRange(duint start, duint end) {
  _dbg_sendmessage(DBG_DELETE_ENCODE_TYPE_RANGE, (void*)start, (void*)end);
}

BRIDGE_IMPEXP void DbgDelEncodeTypeSegment(duint start) {
  _dbg_sendmessage(DBG_DELETE_ENCODE_TYPE_SEG, (void*)start, 0);
}

BRIDGE_IMPEXP void DbgSelChanged(int hWindow, duint VA) {
  _dbg_sendmessage(DBG_SELCHANGED, (void*)hWindow, (void*)VA);
}

BRIDGE_IMPEXP HANDLE DbgGetProcessHandle() {
  return (HANDLE)_dbg_sendmessage(DBG_GET_PROCESS_HANDLE, nullptr, nullptr);
}

BRIDGE_IMPEXP HANDLE DbgGetThreadHandle() {
  return (HANDLE)_dbg_sendmessage(DBG_GET_THREAD_HANDLE, nullptr, nullptr);
}

BRIDGE_IMPEXP DWORD DbgGetProcessId() {
  return (DWORD)_dbg_sendmessage(DBG_GET_PROCESS_ID, nullptr, nullptr);
}

BRIDGE_IMPEXP DWORD DbgGetThreadId() {
  return (DWORD)_dbg_sendmessage(DBG_GET_THREAD_ID, nullptr, nullptr);
}

BRIDGE_IMPEXP duint DbgGetPebAddress(DWORD ProcessId) {
  return (duint)_dbg_sendmessage(DBG_GET_PEB_ADDRESS, (void*)ProcessId,
                                 nullptr);
}

BRIDGE_IMPEXP duint DbgGetTebAddress(DWORD ThreadId) {
  return (duint)_dbg_sendmessage(DBG_GET_TEB_ADDRESS, (void*)ThreadId, nullptr);
}

BRIDGE_IMPEXP bool DbgAnalyzeFunction(duint entry, BridgeCFGraphList* graph) {
  return !!_dbg_sendmessage(DBG_ANALYZE_FUNCTION, (void*)entry, graph);
}

BRIDGE_IMPEXP duint DbgEval(const char* expression, bool* success) {
  duint value = 0;
  auto res = _dbg_valfromstring(expression, &value);
  if (success) *success = res;
  return value;
}

BRIDGE_IMPEXP void DbgMenuPrepare(GUIMENUTYPE hMenu) {
  _dbg_sendmessage(DBG_MENU_PREPARE, (void*)hMenu, nullptr);
}

BRIDGE_IMPEXP void DbgGetSymbolInfo(const SYMBOLPTR* symbolptr,
                                    SYMBOLINFO* info) {
  memset(info, 0, sizeof(info[0]));
  VMPSymbolView::getSymbolInfo(symbolptr, info);
}

BRIDGE_IMPEXP DEBUG_ENGINE DbgGetDebugEngine() {
  return (DEBUG_ENGINE)_dbg_sendmessage(DBG_GET_DEBUG_ENGINE, nullptr, nullptr);
}

BRIDGE_IMPEXP const char* GuiTranslateText(const char* Source) {
  EnterCriticalSection(&csTranslate);
  const char* text = _gui_translate_text(Source);
  LeaveCriticalSection(&csTranslate);
  return text;
}

BRIDGE_IMPEXP void GuiDisasmAt(duint addr, duint cip) {
  if (!addr) addr = cip;

  _gui_sendmessage(GUI_DISASSEMBLE_AT, (void*)addr, (void*)cip);
}

BRIDGE_IMPEXP void GuiSetDebugState(DBGSTATE state) {
  _gui_sendmessage(GUI_SET_DEBUG_STATE, (void*)state, (void*)false);
}

BRIDGE_IMPEXP void GuiSetDebugStateFast(DBGSTATE state) {
  _gui_sendmessage(GUI_SET_DEBUG_STATE, (void*)state, (void*)true);
}

BRIDGE_IMPEXP void GuiAddLogMessage(const char* msg) {
  _gui_sendmessage(GUI_ADD_MSG_TO_LOG, (void*)msg, 0);
}

BRIDGE_IMPEXP void GuiLogClear() { _gui_sendmessage(GUI_CLEAR_LOG, 0, 0); }

BRIDGE_IMPEXP void GuiUpdateEnable(bool updateNow) {
  bDisableGUIUpdate = false;
  if (updateNow) GuiUpdateAllViews();
}

BRIDGE_IMPEXP void GuiUpdateDisable() { bDisableGUIUpdate = true; }

BRIDGE_IMPEXP bool GuiIsUpdateDisabled() { return bDisableGUIUpdate; }

BRIDGE_IMPEXP void GuiUpdateAllViews() {
  CHECK_GUI_UPDATE_DISABLED
  GuiUpdateRegisterView();
  GuiUpdateDisassemblyView();
  GuiUpdateBreakpointsView();
  GuiUpdateDumpView();
  GuiUpdateWatchView();
  GuiUpdateThreadView();
  GuiUpdateSideBar();
  // Patches are not refreshed here, see #1407
  GuiUpdateCallStack();
  GuiRepaintTableView();
  GuiUpdateSEHChain();
  GuiUpdateArgumentWidget();
  GuiUpdateMemoryView();
  GuiUpdateGraphView();
  GuiUpdateTypeWidget();
  GuiUpdateTraceBrowser();
}

BRIDGE_IMPEXP void GuiUpdateRegisterView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_REGISTER_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateDisassemblyView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_DISASSEMBLY_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateBreakpointsView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_BREAKPOINTS_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateWindowTitle(const char* filename) {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_WINDOW_TITLE, (void*)filename, 0);
}

BRIDGE_IMPEXP HWND GuiGetWindowHandle() {
  return (HWND)_gui_sendmessage(GUI_GET_WINDOW_HANDLE, 0, 0);
}

BRIDGE_IMPEXP void GuiDumpAt(duint va) {
  _gui_sendmessage(GUI_DUMP_AT, (void*)va, 0);
}

BRIDGE_IMPEXP void GuiScriptAdd(int count, const char** lines) {
  _gui_sendmessage(GUI_SCRIPT_ADD, (void*)(duint)count, (void*)lines);
}

BRIDGE_IMPEXP void GuiScriptClear() {
  _gui_sendmessage(GUI_SCRIPT_CLEAR, 0, 0);
}

BRIDGE_IMPEXP void GuiScriptSetIp(int line) {
  _gui_sendmessage(GUI_SCRIPT_SETIP, (void*)(duint)line, 0);
}

BRIDGE_IMPEXP void GuiScriptError(int line, const char* message) {
  _gui_sendmessage(GUI_SCRIPT_ERROR, (void*)(duint)line, (void*)message);
}

BRIDGE_IMPEXP void GuiScriptSetTitle(const char* title) {
  _gui_sendmessage(GUI_SCRIPT_SETTITLE, (void*)title, 0);
}

BRIDGE_IMPEXP void GuiScriptSetInfoLine(int line, const char* info) {
  _gui_sendmessage(GUI_SCRIPT_SETINFOLINE, (void*)(duint)line, (void*)info);
}

BRIDGE_IMPEXP void GuiScriptMessage(const char* message) {
  _gui_sendmessage(GUI_SCRIPT_MESSAGE, (void*)message, 0);
}

BRIDGE_IMPEXP int GuiScriptMsgyn(const char* message) {
  return (int)(duint)_gui_sendmessage(GUI_SCRIPT_MSGYN, (void*)message, 0);
}

BRIDGE_IMPEXP void GuiScriptEnableHighlighting(bool enable) {
  _gui_sendmessage(GUI_SCRIPT_ENABLEHIGHLIGHTING, (void*)(duint)enable, 0);
}

BRIDGE_IMPEXP void GuiSymbolLogAdd(const char* message) {
  _gui_sendmessage(GUI_SYMBOL_LOG_ADD, (void*)message, 0);
}

BRIDGE_IMPEXP void GuiSymbolLogClear() {
  _gui_sendmessage(GUI_SYMBOL_LOG_CLEAR, 0, 0);
}

BRIDGE_IMPEXP void GuiSymbolSetProgress(int percent) {
  _gui_sendmessage(GUI_SYMBOL_SET_PROGRESS, (void*)(duint)percent, 0);
}

BRIDGE_IMPEXP void GuiSymbolUpdateModuleList(int count,
                                             SYMBOLMODULEINFO* modules) {
  _gui_sendmessage(GUI_SYMBOL_UPDATE_MODULE_LIST, (void*)(duint)count,
                   (void*)modules);
}

BRIDGE_IMPEXP void GuiReferenceAddColumn(int width, const char* title) {
  _gui_sendmessage(GUI_REF_ADDCOLUMN, (void*)(duint)width, (void*)title);
}

BRIDGE_IMPEXP void GuiSymbolRefreshCurrent() {
  _gui_sendmessage(GUI_SYMBOL_REFRESH_CURRENT, 0, 0);
}

BRIDGE_IMPEXP void GuiReferenceSetRowCount(int count) {
  _gui_sendmessage(GUI_REF_SETROWCOUNT, (void*)(duint)count, 0);
}

BRIDGE_IMPEXP int GuiReferenceGetRowCount() {
  return (int)(duint)_gui_sendmessage(GUI_REF_GETROWCOUNT, 0, 0);
}

BRIDGE_IMPEXP int GuiReferenceSearchGetRowCount() {
  return (int)(duint)(_gui_sendmessage(GUI_REF_SEARCH_GETROWCOUNT, 0, 0));
}

BRIDGE_IMPEXP void GuiReferenceDeleteAllColumns() {
  _gui_sendmessage(GUI_REF_DELETEALLCOLUMNS, 0, 0);
}

BRIDGE_IMPEXP void GuiReferenceInitialize(const char* name) {
  _gui_sendmessage(GUI_REF_INITIALIZE, (void*)name, 0);
}

BRIDGE_IMPEXP void GuiReferenceSetCellContent(int row, int col,
                                              const char* str) {
  CELLINFO info;
  info.row = row;
  info.col = col;
  info.str = str;
  _gui_sendmessage(GUI_REF_SETCELLCONTENT, &info, 0);
}

BRIDGE_IMPEXP char* GuiReferenceGetCellContent(int row, int col) {
  return (char*)_gui_sendmessage(GUI_REF_GETCELLCONTENT, (void*)(duint)row,
                                 (void*)(duint)col);
}

BRIDGE_IMPEXP char* GuiReferenceSearchGetCellContent(int row, int col) {
  return (char*)_gui_sendmessage(GUI_REF_SEARCH_GETCELLCONTENT, (void*)row,
                                 (void*)col);
}

BRIDGE_IMPEXP void GuiReferenceReloadData() {
  _gui_sendmessage(GUI_REF_RELOADDATA, 0, 0);
}

BRIDGE_IMPEXP void GuiReferenceSetSingleSelection(int index, bool scroll) {
  _gui_sendmessage(GUI_REF_SETSINGLESELECTION, (void*)(duint)index,
                   (void*)(duint)scroll);
}

BRIDGE_IMPEXP void GuiReferenceSetProgress(int progress) {
  _gui_sendmessage(GUI_REF_SETPROGRESS, (void*)(duint)progress, 0);
}

BRIDGE_IMPEXP void GuiReferenceSetCurrentTaskProgress(int progress,
                                                      const char* taskTitle) {
  _gui_sendmessage(GUI_REF_SETCURRENTTASKPROGRESS, (void*)(duint)progress,
                   (void*)taskTitle);
}

BRIDGE_IMPEXP void GuiReferenceSetSearchStartCol(int col) {
  _gui_sendmessage(GUI_REF_SETSEARCHSTARTCOL, (void*)(duint)col, 0);
}

BRIDGE_IMPEXP void GuiStackDumpAt(duint addr, duint csp) {
  if (!addr) addr = csp;

  _gui_sendmessage(GUI_STACK_DUMP_AT, (void*)addr, (void*)csp);
}

BRIDGE_IMPEXP void GuiUpdateDumpView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_DUMP_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateWatchView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_WATCH_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateMemoryView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_MEMORY_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateThreadView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_THREAD_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiAddRecentFile(const char* file) {
  _gui_sendmessage(GUI_ADD_RECENT_FILE, (void*)file, 0);
}

BRIDGE_IMPEXP void GuiSetLastException(unsigned int exception) {
  _gui_sendmessage(GUI_SET_LAST_EXCEPTION, (void*)(duint)exception, 0);
}

BRIDGE_IMPEXP bool GuiGetDisassembly(duint addr, char* text) {
  return !!_gui_sendmessage(GUI_GET_DISASSEMBLY, (void*)addr, text);
}

BRIDGE_IMPEXP int GuiMenuAdd(int hMenu, const char* title) {
  return (int)(duint)_gui_sendmessage(GUI_MENU_ADD, (void*)(duint)hMenu,
                                      (void*)title);
}

BRIDGE_IMPEXP int GuiMenuAddEntry(int hMenu, const char* title) {
  return (int)(duint)_gui_sendmessage(GUI_MENU_ADD_ENTRY, (void*)(duint)hMenu,
                                      (void*)title);
}

BRIDGE_IMPEXP void GuiMenuAddSeparator(int hMenu) {
  _gui_sendmessage(GUI_MENU_ADD_SEPARATOR, (void*)(duint)hMenu, 0);
}

BRIDGE_IMPEXP void GuiMenuClear(int hMenu) {
  _gui_sendmessage(GUI_MENU_CLEAR, (void*)(duint)hMenu, 0);
}

BRIDGE_IMPEXP void GuiMenuRemove(int hEntryMenu) {
  _gui_sendmessage(GUI_MENU_REMOVE, (void*)(duint)hEntryMenu, 0);
}

BRIDGE_IMPEXP bool GuiSelectionGet(GUISELECTIONTYPE hWindow,
                                   SELECTIONDATA* selection) {
  return !!_gui_sendmessage(GUI_SELECTION_GET, (void*)(duint)hWindow,
                            selection);
}

BRIDGE_IMPEXP bool GuiSelectionSet(GUISELECTIONTYPE hWindow,
                                   const SELECTIONDATA* selection) {
  return !!_gui_sendmessage(GUI_SELECTION_SET, (void*)(duint)hWindow,
                            (void*)selection);
}

BRIDGE_IMPEXP bool GuiGetLineWindow(const char* title, char* text) {
  return !!_gui_sendmessage(GUI_GETLINE_WINDOW, (void*)title, text);
}

BRIDGE_IMPEXP void GuiAutoCompleteAddCmd(const char* cmd) {
  _gui_sendmessage(GUI_AUTOCOMPLETE_ADDCMD, (void*)cmd, 0);
}

BRIDGE_IMPEXP void GuiAutoCompleteDelCmd(const char* cmd) {
  _gui_sendmessage(GUI_AUTOCOMPLETE_DELCMD, (void*)cmd, 0);
}

BRIDGE_IMPEXP void GuiAutoCompleteClearAll() {
  _gui_sendmessage(GUI_AUTOCOMPLETE_CLEARALL, 0, 0);
}

BRIDGE_IMPEXP void GuiAddStatusBarMessage(const char* msg) {
  _gui_sendmessage(GUI_ADD_MSG_TO_STATUSBAR, (void*)msg, 0);
}

BRIDGE_IMPEXP void GuiUpdateSideBar() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_SIDEBAR, 0, 0);
}

BRIDGE_IMPEXP void GuiRepaintTableView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_REPAINT_TABLE_VIEW, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdatePatches() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_PATCHES, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateCallStack() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_CALLSTACK, 0, 0);
}

BRIDGE_IMPEXP void GuiUpdateSEHChain() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_SEHCHAIN, 0, 0);
}

extern "C" __declspec(dllexport) void GuiLoadSourceFile(const char* path,
                                                        int line) {
  return;
}

BRIDGE_IMPEXP void GuiLoadSourceFileEx(const char* path, duint addr) {
  _gui_sendmessage(GUI_LOAD_SOURCE_FILE, (void*)path, (void*)addr);
  GuiFocusView(GUI_DECOMPILER);
}

BRIDGE_IMPEXP void GuiMenuSetIcon(int hMenu, const ICONDATA* icon) {
  _gui_sendmessage(GUI_MENU_SET_ICON, (void*)hMenu, (void*)icon);
}

BRIDGE_IMPEXP void GuiMenuSetEntryIcon(int hEntry, const ICONDATA* icon) {
  _gui_sendmessage(GUI_MENU_SET_ENTRY_ICON, (void*)hEntry, (void*)icon);
}

BRIDGE_IMPEXP void GuiMenuSetEntryChecked(int hEntry, bool checked) {
  _gui_sendmessage(GUI_MENU_SET_ENTRY_CHECKED, (void*)hEntry, (void*)checked);
}

BRIDGE_IMPEXP void GuiMenuSetVisible(int hMenu, bool visible) {
  _gui_sendmessage(GUI_MENU_SET_VISIBLE, (void*)hMenu, (void*)visible);
}

BRIDGE_IMPEXP void GuiMenuSetEntryVisible(int hEntry, bool visible) {
  _gui_sendmessage(GUI_MENU_SET_ENTRY_VISIBLE, (void*)hEntry, (void*)visible);
}

BRIDGE_IMPEXP void GuiMenuSetName(int hMenu, const char* name) {
  _gui_sendmessage(GUI_MENU_SET_NAME, (void*)hMenu, (void*)name);
}

BRIDGE_IMPEXP void GuiMenuSetEntryName(int hEntry, const char* name) {
  _gui_sendmessage(GUI_MENU_SET_ENTRY_NAME, (void*)hEntry, (void*)name);
}

BRIDGE_IMPEXP void GuiMenuSetEntryHotkey(int hEntry, const char* hack) {
  _gui_sendmessage(GUI_MENU_SET_ENTRY_HOTKEY, (void*)hEntry, (void*)hack);
}

BRIDGE_IMPEXP void GuiShowCpu() { _gui_sendmessage(GUI_SHOW_CPU, 0, 0); }

BRIDGE_IMPEXP void GuiAddQWidgetTab(void* qWidget) {
  _gui_sendmessage(GUI_ADD_QWIDGET_TAB, qWidget, nullptr);
}

BRIDGE_IMPEXP void GuiShowQWidgetTab(void* qWidget) {
  _gui_sendmessage(GUI_SHOW_QWIDGET_TAB, qWidget, nullptr);
}

BRIDGE_IMPEXP void GuiCloseQWidgetTab(void* qWidget) {
  _gui_sendmessage(GUI_CLOSE_QWIDGET_TAB, qWidget, nullptr);
}

BRIDGE_IMPEXP void GuiExecuteOnGuiThread(GUICALLBACK cbGuiThread) {
  GuiExecuteOnGuiThreadEx((GUICALLBACKEX)cbGuiThread, nullptr);
}

BRIDGE_IMPEXP void GuiUpdateTimeWastedCounter() {
  _gui_sendmessage(GUI_UPDATE_TIME_WASTED_COUNTER, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiSetGlobalNotes(const char* text) {
  _gui_sendmessage(GUI_SET_GLOBAL_NOTES, (void*)text, nullptr);
}

BRIDGE_IMPEXP void GuiGetGlobalNotes(char** text) {
  _gui_sendmessage(GUI_GET_GLOBAL_NOTES, text, nullptr);
}

BRIDGE_IMPEXP void GuiSetDebuggeeNotes(const char* text) {
  _gui_sendmessage(GUI_SET_DEBUGGEE_NOTES, (void*)text, nullptr);
}

BRIDGE_IMPEXP void GuiGetDebuggeeNotes(char** text) {
  _gui_sendmessage(GUI_GET_DEBUGGEE_NOTES, text, nullptr);
}

BRIDGE_IMPEXP void GuiDumpAtN(duint va, int index) {
  _gui_sendmessage(GUI_DUMP_AT_N, (void*)va, (void*)index);
}

BRIDGE_IMPEXP void GuiDisplayWarning(const char* title, const char* text) {
  _gui_sendmessage(GUI_DISPLAY_WARNING, (void*)title, (void*)text);
}

BRIDGE_IMPEXP void GuiRegisterScriptLanguage(SCRIPTTYPEINFO* info) {
  _gui_sendmessage(GUI_REGISTER_SCRIPT_LANG, (void*)info, nullptr);
}

BRIDGE_IMPEXP void GuiUnregisterScriptLanguage(int id) {
  _gui_sendmessage(GUI_UNREGISTER_SCRIPT_LANG, (void*)id, nullptr);
}

BRIDGE_IMPEXP void GuiUpdateArgumentWidget() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_ARGUMENT_VIEW, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiFocusView(int hWindow) {
  _gui_sendmessage(GUI_FOCUS_VIEW, (void*)hWindow, nullptr);
}

BRIDGE_IMPEXP bool GuiLoadGraph(BridgeCFGraphList* graph, duint addr) {
  return !!_gui_sendmessage(GUI_LOAD_GRAPH, graph, (void*)addr);
}

BRIDGE_IMPEXP duint GuiGraphAt(duint addr) {
  return (duint)_gui_sendmessage(GUI_GRAPH_AT, (void*)addr, nullptr);
}

BRIDGE_IMPEXP void GuiUpdateGraphView() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_GRAPH_VIEW, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiDisableLog() {
  _gui_sendmessage(GUI_SET_LOG_ENABLED, (void*)0, nullptr);
}

BRIDGE_IMPEXP void GuiEnableLog() {
  _gui_sendmessage(GUI_SET_LOG_ENABLED, (void*)1, nullptr);
}

BRIDGE_IMPEXP void GuiAddFavouriteTool(const char* name,
                                       const char* description) {
  _gui_sendmessage(GUI_ADD_FAVOURITE_TOOL, (void*)name, (void*)description);
}

BRIDGE_IMPEXP void GuiAddFavouriteCommand(const char* name,
                                          const char* shortcut) {
  _gui_sendmessage(GUI_ADD_FAVOURITE_COMMAND, (void*)name, (void*)shortcut);
}

BRIDGE_IMPEXP void GuiSetFavouriteToolShortcut(const char* name,
                                               const char* shortcut) {
  _gui_sendmessage(GUI_SET_FAVOURITE_TOOL_SHORTCUT, (void*)name,
                   (void*)shortcut);
}

BRIDGE_IMPEXP void GuiFoldDisassembly(duint startAddress, duint length) {
  _gui_sendmessage(GUI_FOLD_DISASSEMBLY, (void*)startAddress, (void*)length);
}

BRIDGE_IMPEXP void GuiSelectInMemoryMap(duint addr) {
  _gui_sendmessage(GUI_SELECT_IN_MEMORY_MAP, (void*)addr, nullptr);
}

BRIDGE_IMPEXP void GuiGetActiveView(ACTIVEVIEW* activeView) {
  _gui_sendmessage(GUI_GET_ACTIVE_VIEW, activeView, nullptr);
}

BRIDGE_IMPEXP void GuiAddInfoLine(const char* infoLine) {
  _gui_sendmessage(GUI_ADD_INFO_LINE, (void*)infoLine, nullptr);
}

BRIDGE_IMPEXP void GuiProcessEvents() {
  _gui_sendmessage(GUI_PROCESS_EVENTS, nullptr, nullptr);
}

BRIDGE_IMPEXP void* GuiTypeAddNode(void* parent, const TYPEDESCRIPTOR* type) {
  return _gui_sendmessage(GUI_TYPE_ADDNODE, parent, (void*)type);
}

BRIDGE_IMPEXP bool GuiTypeClear() {
  return !!_gui_sendmessage(GUI_TYPE_CLEAR, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiUpdateTypeWidget() {
  _gui_sendmessage(GUI_UPDATE_TYPE_WIDGET, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiCloseApplication() {
  _gui_sendmessage(GUI_CLOSE_APPLICATION, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiFlushLog() {
  _gui_sendmessage(GUI_FLUSH_LOG, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiReferenceAddCommand(const char* title,
                                          const char* command) {
  _gui_sendmessage(GUI_REF_ADDCOMMAND, (void*)title, (void*)command);
}

BRIDGE_IMPEXP void GuiUpdateTraceBrowser() {
  CHECK_GUI_UPDATE_DISABLED
  _gui_sendmessage(GUI_UPDATE_TRACE_BROWSER, nullptr, nullptr);
}

BRIDGE_IMPEXP void GuiOpenTraceFile(const char* fileName) {
  _gui_sendmessage(GUI_OPEN_TRACE_FILE, (void*)fileName, nullptr);
}

BRIDGE_IMPEXP void GuiInvalidateSymbolSource(duint base) {
  _gui_sendmessage(GUI_INVALIDATE_SYMBOL_SOURCE, (void*)base, nullptr);
}

BRIDGE_IMPEXP void GuiExecuteOnGuiThreadEx(GUICALLBACKEX cbGuiThread,
                                           void* userdata) {
  _gui_sendmessage(GUI_EXECUTE_ON_GUI_THREAD, (void*)cbGuiThread, userdata);
}

BRIDGE_IMPEXP void GuiGetCurrentGraph(BridgeCFGraphList* graphList) {
  _gui_sendmessage(GUI_GET_CURRENT_GRAPH, graphList, nullptr);
}

BRIDGE_IMPEXP void GuiShowReferences() { _gui_sendmessage(GUI_SHOW_REF, 0, 0); }

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  return TRUE;
}
