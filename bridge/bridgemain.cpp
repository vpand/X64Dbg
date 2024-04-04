/**
 * \file bridgemain.cpp
 *
 * \brief Defines functions to initialize and start the Bridge and
 *        to interface with the GUI and the DBG.
 */
#include "bridgemain.h"

#include <stdio.h>

#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QTimer>
#include <abstraction/DebugEngine.hpp>

#include "../Bridge/Bridge.h"
#include "../a64dbg/a64dbg.h"
#include "../bridge/_global.h"
#include "../dbg/TraceRecord.h"
#include "../dbg/_dbgfunctions.h"
#include "CPUDisassembly.h"
#include "CPUWidget.h"
#include "MainWindow.h"
#include "StringUtil.h"
#include "Utf8Ini.h"
#include "MemoryPage.h"
#include "HyperTraceView.h"

// we treat all platform has this page size
#define page_size 0x1000

#if __APPLE__
#ifndef HINSTANCE
typedef void* HINSTANCE;
#endif
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
static duint bDisableGUIUpdate = 0;

static REGDUMPA32 regDumpA32;
static REGDUMPA64 regDumpA64;
static REGDUMPX64 regDumpX64;

LLDBEngine* lldb = nullptr;

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

static duint ModHash(DbgModule* m) {
  if (!m->hash) {
    m->hash = DbgGlobal::inst()->pathCRC(m->modulePath.data(), m);
  }
  return m->hash;
}

duint ModHashFromAddr(duint pageaddr) {
  for (auto& m : lldb->moduleList()) {
    if (m.startAddress <= pageaddr && pageaddr < m.endAddress) {
      return ModHash(&m) + pageaddr - m.startAddress;
    }
  }
  return 0;
}

duint ModHashFromName(const char* name) {
  for (auto& m : lldb->moduleList()) {
    if (m.moduleName == name) {
      return ModHash(&m);
    }
  }
  return 0;
}

duint ModBaseFromAddr(duint pageaddr) {
  for (auto& m : lldb->moduleList()) {
    if (m.startAddress <= pageaddr && pageaddr < m.endAddress) {
      return m.startAddress;
    }
  }
  return 0;
}

extern bool ModNameFromAddr(duint pageaddr, char* name, bool b) {
  for (auto& m : lldb->moduleList()) {
    if (m.startAddress <= pageaddr && pageaddr < m.endAddress) {
      strcpy(name, m.moduleName.data());
      return true;
    }
  }
  return false;
}

duint* regSPPtr() {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&regDumpA32.regcontext.csp;
    case mana::ARM64:
      return (duint*)&regDumpA64.regcontext.csp;
    default:
      return (duint*)&regDumpX64.regcontext.csp;
  }
}

duint* regLRPtr() {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&regDumpA32.regcontext.clr;
    case mana::ARM64:
      return (duint*)&regDumpA64.regcontext.clr;
    default:
      return nullptr;
  }
}

duint* regPCPtr() {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&regDumpA32.regcontext.cip;
    case mana::ARM64:
      return (duint*)&regDumpA64.regcontext.cip;
    default:
      return (duint*)&regDumpX64.regcontext.cip;
  }
}

duint* regIndex(int i) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&regDumpA32.regcontext.gpr[i];
    case mana::ARM64:
      return (duint*)&regDumpA64.regcontext.gpr[i];
    default:
      return (duint*)&regDumpX64.regcontext.cax;
  }
}

duint* regFloat(int i, REGFLOATTYPE t) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)regDumpA32.regcontext.neon[i];
    case mana::ARM64:
      return (duint*)regDumpA64.regcontext.neon[i];
    default:
      switch (t) {
        case RFT_MMX:
        case RFT_X87FPU:
          return (duint*)&regDumpX64.x87FPURegisters[i].data[0];
        case RFT_XMMX:
          return (duint*)&regDumpX64.regcontext.XmmRegisters[i].Low;
        case RFT_YMMX:
          return (duint*)&regDumpX64.regcontext.YmmRegisters[i].Low.Low;
        default:
          break;
      }
      return nullptr;
  }
}

duint* regSPPtrEx(const REGDUMP* regraw) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&((REGDUMPA32*)regraw)->regcontext.csp;
    case mana::ARM64:
      return (duint*)&((REGDUMPA64*)regraw)->regcontext.csp;
    default:
      return (duint*)&((REGDUMPX64*)regraw)->regcontext.csp;
  }
}

duint* regLRPtrEx(const REGDUMP* regraw) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&((REGDUMPA32*)regraw)->regcontext.clr;
    case mana::ARM64:
      return (duint*)&((REGDUMPA64*)regraw)->regcontext.clr;
    default:
      return nullptr;
  }
}

duint* regPCPtrEx(const REGDUMP* regraw) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&((REGDUMPA32*)regraw)->regcontext.cip;
    case mana::ARM64:
      return (duint*)&((REGDUMPA64*)regraw)->regcontext.cip;
    default:
      return (duint*)&((REGDUMPX64*)regraw)->regcontext.cip;
  }
}

duint* regIndexEx(const REGDUMP* regraw, int i) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)&((REGDUMPA32*)regraw)->regcontext.gpr[i];
    case mana::ARM64:
      return (duint*)&((REGDUMPA64*)regraw)->regcontext.gpr[i];
    default:
      return (duint*)&((REGDUMPX64*)regraw)->regcontext.cax;
  }
}

duint* regFloatEx(const REGDUMP* regraw, int i, REGFLOATTYPE t) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return (duint*)((REGDUMPA32*)regraw)->regcontext.neon[i];
    case mana::ARM64:
      return (duint*)((REGDUMPA64*)regraw)->regcontext.neon[i];
    default:
      switch (t) {
        case RFT_MMX:
        case RFT_X87FPU:
          return (duint*)&((REGDUMPX64*)regraw)->x87FPURegisters[i].data[0];
        case RFT_XMMX:
          return (duint*)&((REGDUMPX64*)regraw)->regcontext.XmmRegisters[i].Low;
        case RFT_YMMX:
          return (duint*)&((REGDUMPX64*)regraw)
              ->regcontext.YmmRegisters[i]
              .Low.Low;
        default:
          break;
      }
      return nullptr;
  }
}

void DbgGlobal::updatePlatform() {
  if (!lldb) return;

  auto platform = DbgGlobal::inst()->currentPlatform();
  switch (platform) {
    case pt_local_uraniumvm:
    case pt_local_mac: {  // Local macOS/Simulator
      lldb->command("plat select host");
      break;
    }
    case pt_remote_uraniumvm_ios:
    case pt_remote_ios: {  // Remote iOS
      lldb->command("plat select remote-ios");

      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote ios device ip address.\n");
        return;
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_IOS_PORT, &port)) {
        GuiAddLogMessage("You haven't configure the remote ios server port.\n");
        return;
      }
      lldb->command(QString("plat connect connect://%1:%2")
                        .arg(ip)
                        .arg(port)
                        .toUtf8()
                        .data());
      break;
    }
    case pt_remote_vp_android:
    case pt_remote_uraniumvm_android:
    case pt_remote_android: {  // Remote Android
      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote android device ip address.\n");
        return;
      }
      if (strcmp(ip, "127.0.0.1") == 0) {
        // user have forward tcp port, make it to localhost
        strcpy(ip, "localhost");
        lldb->command("plat select remote-android");
      }
      else {
        lldb->command("plat select remote-linux");
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_ANDROID_PORT,
                                &port)) {
        GuiAddLogMessage(
            "You haven't configure the remote android server port.\n");
        return;
      }
      lldb->command(QString("plat connect connect://%1:%2")
                        .arg(ip)
                        .arg(port)
                        .toUtf8()
                        .data());
      break;
    }
    case pt_local_vp_ios: {
      GuiAddLogMessage("You have selected an unrelease platform.\n");
      return;
    }
    case pt_invalid_platform:
      GuiAddLogMessage(
          "You have selected an unsupported platform on this system.\n");
      return;
  }
  switch (platform) {
    case pt_remote_vp_android:
    case pt_local_uraniumvm:
    case pt_remote_uraniumvm_ios:
    case pt_remote_uraniumvm_android:
      lldb->activeUraniumVM();
      break;
    default:
      lldb->activeLLDB();
      break;
  }
}

QByteArray adb_shell(const QString& adb, const QString& cmds, bool root) {
  return adb_shell(adb.toUtf8().data(), cmds.toUtf8().data(), root).data();
}

bool is_android_64(const QString& adb, int pid, const QString& exe) {
  return is_android_64(adb.toUtf8().data(), pid, exe.toUtf8().data());
}

void adb_pull(const QString& adb, const QString& rfile,
              const QString& locfile) {
  adb_pull(adb.toUtf8().data(), rfile.toUtf8().data(), locfile.toUtf8().data());
}

QString adb_push(const QString& adb, const QString& file) {
  return adb_push(adb.toUtf8().data(), file.toUtf8().data()).data();
}

void init_debugee_process(const char* pid);

static void launch_apk_file(const char* app) {
  char adb[MAX_PATH];
  if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_USB, adb,
                        MAX_PATH)) {
    GuiAddLogMessage(
        "Please set the android adb full path before use virtualization debug "
        "mode in the settings.\n");
    return;
  }
  auto march = adb_shell(adb, "uname -m", false);
  const char *basearch = march.data();
  bool is64 = is_android_64(adb, -1, "");
  if (strstr(basearch, "x86")) {
    basearch = is64 ? "x86_64" : "x86";
  }
  else {
    basearch = is64 ? "arm64" : "arm";
  }
  bool isvp = DbgGlobal::inst()->currentPlatform() == pt_remote_vp_android;
  const char *typesuffix = isvp ? "vp" : "uvm";
  QString uvmroot =
      QString("/data/local/tmp/a64dbg-server-%1.%2").arg(basearch).arg(typesuffix);
  const char* pathend = strrchr(app, '=');
  std::string apk(app, pathend - app);
  adb_shell(adb,
            QString("cd /data/local/tmp; rm AndroidManifest.xml; "
                    "%1/unzip %2 AndroidManifest.xml -d .; "
                    "%1/zip ./AndroidManifest.zip AndroidManifest.xml")
                .arg(uvmroot)
                .arg(apk.data()),
            false);
  QString locfile(
      QString("%1/AndroidManifest.zip").arg(DbgGlobal::inst()->tempDir()));
  QFile(locfile).remove();
  adb_pull(adb, "/data/local/tmp/AndroidManifest.zip", locfile);
  if (!QFileInfo(locfile).exists()) {
    GuiAddLogMessage(QString("Failed to parse %1's AndroidManifest.xml.\n")
                         .arg(apk.data())
                         .toUtf8()
                         .data());
    return;
  }

  QString aapt =
      QString("%1/uvmdbg-ndk/bin/aapt2").arg(DbgGlobal::inst()->exeDir());
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

  auto curpt = DbgGlobal::inst()->currentPlatform();
  QString tmpcfg(QString("%1/%2zygote.cfg").arg(DbgGlobal::inst()->tempDir())
                 .arg(isvp ? "vp" : "ad"));
  QFile cfgfile(tmpcfg);
  cfgfile.open(QIODevice::WriteOnly);
  if (curpt == pt_remote_android) {
    cfgfile.write(QString("%1").arg(pkgname).toUtf8().data());
  } else {
    cfgfile.write(QString("%1\n%2:%3")
                      .arg(pkgname)
                      .arg(lldb->uvmdbgPort())
                      .arg(UraniumVMServer::local_ip())
                      .toUtf8()
                      .data());
  }
  cfgfile.close();
  QString remotecfg = adb_push(adb, tmpcfg);

  QString startcmd(
      QString("am start -S -n %1/%2").arg(pkgname).arg(activity.data()));
  GuiAddLogMessage(QString("Launching %1 with %2.\n")
                       .arg(apk.data())
                       .arg(startcmd)
                       .toUtf8()
                       .data());
  adb_shell(adb, startcmd, false);

  // let debugee running a few seconds
  QByteArray pkgn(pkgname);
  int waitsecs = 2;
  if (DbgGlobal::inst()->isCloudPlatform()) {
    waitsecs = 10;
  }
  QTimer::singleShot(waitsecs * 1000, [remotecfg, pkgn, curpt]() {
    if (curpt == pt_remote_android) {
      char pid[16];
      lldb->commandResult(
          QString("plat shell cat /data/data/%1/cache/debugee.pid")
              .arg(pkgn.data())
              .toUtf8()
              .data(),
          pid, sizeof(pid));
      GuiAddLogMessage(QString("Attaching activity %1, pid %2...\n")
                           .arg(pkgn.data())
                           .arg(pid)
                           .toUtf8()
                           .data());
      init_debugee_process(pid);
    }
    // remove the temp cfg file
    lldb->command(QString("plat shell rm %1").arg(remotecfg).toUtf8().data());
  });
}

static void launch_debugee_file(const char* app) {
  if (DbgIsDebugging()) {
    GuiAddStatusBarMessage("Already debugging...\n");
    return;
  }

  switch (DbgGlobal::inst()->currentPlatform()) {
    case pt_remote_vp_android:
    case pt_remote_ios:
    case pt_remote_android:
    case pt_remote_uraniumvm_android:
      break;
    default:
      GuiAddLogMessage(
          "Current selected platform doesn't support launch application.\n");
      return;
  }

  GuiAddStatusBarMessage(
      QString("Launching remote %1...\n").arg(app).toUtf8().data());
  if (strstr(app, ".apk")) {
    launch_apk_file(app);
    return;
  }

  // start debugserver
  lldb->command(QString("plat shell /bin/sh -c \"debugserver *:30334 \"%1\"&\"")
                    .arg(app)
                    .toUtf8()
                    .data());

  char ip[64];
  BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip, sizeof(ip));
  lldb->launchFileiOS(ip, app);
  GuiAddRecentFile(app);
}

#if __APPLE__
std::string app_executable(const char* app);
#endif

static void init_debugee_file(const char* path) {
  if (QString(path).endsWith(".py")) {
    if (QFileInfo(path).exists()) {
      GuiAddRecentFile(path);
      GuiAddLogMessage(QString("Execute %1.\n").arg(path).toUtf8().data());
      ADPluginManager::inst()->adp_eval(path, nullptr, 0);
    } else {
      GuiAddLogMessage(
          QString("Python file %1 doesn't exist.\n").arg(path).toUtf8().data());
    }
    return;
  } else if (QString(path).endsWith(".cc") || QString(path).endsWith(".mm") ||
             QString(path).endsWith(".adc")) {
    if (!lldb->interpADCpp(path)) {
      GuiAddLogMessage(
          "Cannot interprete adcpp file, it's now in lldb mode.\n");
    }
    return;
  }

  if (DbgIsDebugging()) {
    GuiAddStatusBarMessage("Already debugging...\n");
    return;
  }

  auto platform = DbgGlobal::inst()->currentPlatform();
  if (!QFileInfo(path).exists()) {
    if (platform == pt_remote_ios &&
        (strstr(path, ".app/") || QString(path).endsWith(".app"))) {
      launch_debugee_file(path);
      return;
    }
    if (strstr(path, ".apk")) {
      launch_debugee_file(path);
      return;
    }
    if (platform == pt_local_mac) {
      GuiAddLogMessage(QString("Debugee file %1 doesn't exist.\n")
                           .arg(path)
                           .toUtf8()
                           .data());
    }
    return;
  }

#if __APPLE__
  std::string realpath;
  if (platform == pt_local_mac && QString(path).endsWith(".app")) {
    realpath = app_executable(path);
    path = realpath.data();
  }
#endif

  QString args, channel;
  Bridge::getBridge()->getStrWindow("Startup Arguments", &args);
  auto pt = DbgGlobal::inst()->currentPlatform();
  switch (pt) {
    case pt_local_mac: {  // Local macOS/Simulator
      break;
    }
    case pt_remote_ios: {  // Remote iOS
      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote ios device ip address.\n");
        return;
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_IOS_PORT, &port)) {
        GuiAddLogMessage("You haven't configure the remote ios server port.\n");
        return;
      }
      channel = QString("connect://%1:%2").arg(ip).arg(port);
      break;
    }
    case pt_remote_android: {  // Remote Android
      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote android device ip address.\n");
        return;
      }
      if (strcmp(ip, "127.0.0.1") == 0) {
        // user have forward tcp port, make it to localhost
        strcpy(ip, "localhost");
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_ANDROID_PORT,
                                &port)) {
        GuiAddLogMessage(
            "You haven't configure the remote android server port.\n");
        return;
      }
      channel = QString("connect://%1:%2").arg(ip).arg(port);
      break;
    }
    case pt_remote_vp_android:
    case pt_local_uraniumvm:
    case pt_remote_uraniumvm_ios:
    case pt_remote_uraniumvm_android: {
      break;
    }
    case pt_local_vp_ios: {
      GuiAddLogMessage("You have selected an unrelease platform.\n");
      return;
    }
    case pt_invalid_platform:
      GuiAddLogMessage(
          "You have selected an unsupported platform on this system.\n");
      return;
  }
  lldb->launchFile(pt, channel.toUtf8().data(), path, args.toUtf8().data());
  GuiAddRecentFile(path);
}

void init_debugee_process(const char* pid) {
  if (DbgIsDebugging()) {
    GuiAddStatusBarMessage("Already debugging...\n");
    return;
  }

  int pidval = atoi(pid);
  if (!pidval) {
    GuiAddLogMessage(
        QString("Debugee pid %1 is zero.\n").arg(pid).toUtf8().data());
    return;
  }

  const char* path = nullptr;
  QString channel;
  auto pt = DbgGlobal::inst()->currentPlatform();
  switch (pt) {
    case pt_local_mac: {  // Local macOS/Simulator
      GuiAddStatusBarMessage(QString("Attaching local process %1...\n")
        .arg(pid)
        .toUtf8()
        .data());
      break;
    }
    case pt_remote_ios: {  // Remote iOS
      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote ios device ip address.\n");
        return;
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_IOS_PORT, &port)) {
        GuiAddLogMessage("You haven't configure the remote ios server port.\n");
        return;
      }
      // user want to usbmux
      if (strcmp(ip, "127.0.0.1") == 0) {
        port += 1;
        GuiAddStatusBarMessage(QString("Attaching remote process %1...\n")
                                   .arg(pid)
                                   .toUtf8()
                                   .data());
        // start debugserver
        lldb->command(
            QString("plat shell /bin/sh -c \"debugserver *:%1 --attach %2&\"")
                .arg(port)
                .arg(pid)
                .toUtf8()
                .data());
      }
      channel = QString("connect://%1:%2").arg(ip).arg(port);
      break;
    }
    case pt_remote_android: {  // Remote Android
      char ip[MAX_SETTING_SIZE];
      if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_IP, ip)) {
        GuiAddLogMessage(
            "You haven't configure the remote android device ip address.\n");
        return;
      }
      if (strcmp(ip, "127.0.0.1") == 0) {
        // user have forward tcp port, make it to localhost
        strcpy(ip, "localhost");
      }
      duint port;
      if (!BridgeSettingGetUint(DBGSETTING_SECTION, DSSKEY_ANDROID_PORT,
                                &port)) {
        GuiAddLogMessage(
            "You haven't configure the remote android server port.\n");
        return;
      }
      channel = QString("connect://%1:%2").arg(ip).arg(port);
      break;
    }
    case pt_remote_vp_android:
    case pt_local_uraniumvm:
    case pt_remote_uraniumvm_android: {
      break;
    }
    case pt_remote_uraniumvm_ios: {
      while (*pid++ != ' ')
        ;
      path = pid;
      break;
    }
    case pt_local_vp_ios: {
      GuiAddLogMessage("You have selected an unrelease platform.\n");
      return;
    }
    case pt_invalid_platform:
      GuiAddLogMessage(
          "You have selected an unsupported platform on this system.\n");
      return;
  }
  lldb->attachProcess(pt, pidval, channel.toUtf8().data(), path);
}

static void detach_debuggee() {
  if (DbgIsDebugging()) {
    DbgGlobal::inst()->clearAll();
    lldb->shutdownInferior();
  }

  GuiSymbolUpdateModuleList(0, nullptr);
  GuiUpdateAllViews();
}

void load_module_sync(const QString& path, DbgModule* module) {
  if (lldb->isTracing()) {
    DbgGlobal::inst()->addModule(path, module);
    return;
  }
  QEventLoop eloop;
  QThread* anaThread = QThread::create(
      [module](const QString& path) {
        DbgGlobal::inst()->addModule(path, module);
      },
      path);
  anaThread->connect(anaThread, SIGNAL(finished()), &eloop, SLOT(quit()));
  anaThread->start();
  eloop.exec(QEventLoop::ExcludeUserInputEvents);
  delete anaThread;
}

void bp_set(const char* addr, bool oneshot = false,
            const char* cond = nullptr) {
  if (!DbgIsDebugging()) return;

  auto address = DbgValFromString(addr);
  // it's an async operation, so let the engine to refresh ui
  lldb->setBreakpoint(address, true, oneshot, cond);
}

void bp_unset(const char* addr) {
  uint64_t address = strtoul(addr, nullptr, 16);
  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == address) {
      lldb->removeBreakpoint(bp);

      GuiUpdateAllViews();
      return;
    }
  }
}

static void bp_enable(const char* addr) {
  uint64_t address = strtoul(addr, nullptr, 16);
  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == address) {
      bp.setEnabled(true);
      lldb->updateBreakpoint(bp);

      GuiUpdateAllViews();
      return;
    }
  }
}

static void bp_disable(const char* addr) {
  uint64_t address = strtoul(addr, nullptr, 16);
  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == address) {
      bp.setEnabled(false);
      lldb->updateBreakpoint(bp);

      GuiUpdateAllViews();
      return;
    }
  }
}

static void bp_cond(const char* addr_cond) {
  char* cond;
  uint64_t address = strtoul(addr_cond, &cond, 16);
  cond += 2;  // skip <, >
  if (strlen(cond) == 0) {
    return;
  }

  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == address) {
      bp.setCondition(cond);
      lldb->updateBreakpoint(bp);

      GuiUpdateAllViews();
      return;
    }
  }
}

static void bp_oneshot(const char* addr_status) {
  char* status;
  uint64_t address = strtoul(addr_status, &status, 16);
  status += 2;  // skip <, >
  int oneshot = atoi(status);
  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == address) {
      bp.setOneshot(oneshot);
      lldb->updateBreakpoint(bp);

      GuiUpdateAllViews();
      return;
    }
  }
}

void watch_set(const char* addr) {
  if (!DbgIsDebugging()) return;

  char* endptr;
  auto address = DbgValFromString(addr);
  int bitsize = 64;
  if (endptr[0] == ',') {
    endptr += 2;  // skip <, >
    int byte = atoi(endptr);
    if (byte) {
      bitsize = 8 * byte;
    }
  }
  for (auto& bp : lldb->breakpoints()) {
    // already there
    if (address == bp.address()) {
      return;
    }
  }
  // it's an async operation, so let the engine to refresh ui
  lldb->setWatchpoint(address, bitsize);
}

static void watch_unset(const char* index) {
  if (index[0] == '.') index++;
  for (auto& bp : lldb->breakpoints()) {
    if (bp.responseId() == index) {
      lldb->removeBreakpoint(bp);
      GuiUpdateWatchView();
      return;
    }
  }
}

static void sync_execmd(const char* cmd) {
  QEventLoop eloop;
  std::pair<QEventLoop*, const char*> p = {&eloop, cmd};
  GuiExecuteOnGuiThreadEx(
      [](void* ptr) {
        auto pinfo = (std::pair<QEventLoop*, const char*>*)ptr;
        lldb->commandResult(pinfo->second, nullptr, 0);
        pinfo->first->quit();
      },
      &p);
  eloop.exec();
}

static void list_function() {
  auto debugee = DbgGlobal::inst()->debugee;
  if (!debugee) return;

  GuiReferenceInitialize("CPU Functions");
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(8, "Size");
  GuiReferenceAddColumn(200, "Name");
  GuiReferenceSetRowCount(debugee->db->nfunc);
  for (int i = 0; i < debugee->db->nfunc; i++) {
    auto func = debugee->db->func(i);
    GuiReferenceSetCellContent(
        i, 0, ToPtrString(debugee->rtbase + func->rvastart).toUtf8().data());
    GuiReferenceSetCellContent(
        i, 1, QString("%1").arg(func->rvaend - func->rvastart).toUtf8().data());
    GuiReferenceSetCellContent(i, 2, debugee->db->string(func->name));
  }
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

  GuiReferenceInitialize("Bookmarks");
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
                                     .arg(m.second->db->string(func->name))
                                     .arg(bkrva - func->rvastart)
                                     .toUtf8()
                                     .data());
      index++;
    }
  }
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

  GuiReferenceInitialize("Comments");
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
                                     .arg(m.second->db->string(func->name))
                                     .arg(cmtrva - func->rvastart)
                                     .toUtf8()
                                     .data());
      GuiReferenceSetCellContent(index, 2,
                                 addrcmt[srva].toString().toUtf8().data());
      index++;
    }
  }
}

static void run_to_address(const char* addr) {
  if (!DbgIsDebugging()) return;

  if (addr[0]) {
    bp_set(addr + 1, true);  // skip < >
  }

  lldb->continueInferior();
}

static void switch_thread(const char* tid) { lldb->selectThread(tid); }

static void refresh_content(const char* expr) {
  if (strcmp(expr, "module") == 0) {
    lldb->reloadModules();
  } else if (strcmp(expr, "thread") == 0) {
    lldb->reloadThreads();
  } else {
    duint addr = DbgValFromString(expr);
    duint base = DbgMemFindBaseAddr(addr, nullptr);
    if (!DbgMemIsValidReadPtr(base)) {
      return;
    }
    auto found = DbgGlobal::inst()->dbgpages.find(base);
    if (found != DbgGlobal::inst()->dbgpages.end()) {
      DbgGlobal::inst()->dbgpages.erase(found);
    }
    // trigger reload page
    DbgMemRead(base, &addr, 4);
  }
}

static void dp_expr(const char* expr) {
  GuiDumpAt(DbgValFromString(expr));
  GuiFocusView(GUI_DUMP);
}

static void dis_expr(const char* expr) {
  GuiDisasmAt(DbgValFromString(expr), regPC());
  GuiFocusView(GUI_DISASSEMBLY);
}

static void asm_insn(const char* expr, const ManaFunc* mf) {
  Disassembler* diser = DbgGlobal::inst()->diser(mf);
  uint8_t opc[20];
  auto result = diser->assemble(expr, opc);
  if (opc[0]) {
    QString log(expr);
    log += " :";
    for (uint8_t i = 1; i <= opc[0]; i++) {
      char hex[8];
      sprintf(hex, " %02X", opc[i]);
      log += hex;
    }
    log += "\n";
    GuiAddLogMessage(log.toUtf8().data());
  } else {
    GuiAddLogMessage(result.data());
  }
}

static void asm_insn(const char* expr) {
  ManaFunc mf;
  mf.info.thumb = 0;
  asm_insn(expr, &mf);
}

static void tasm_insn(const char* expr) {
  ManaFunc mf;
  mf.info.thumb = 1;
  asm_insn(expr, &mf);
}

static bool animate_into(const char* cmds, bool into) {
  lldb->animateInto(into);
  return true;
}

static void trace_setlog(const char* cmd) { lldb->traceSetLog(cmd); }

static void trace_setcmd(const char* cmd) { lldb->traceSetCommand(cmd); }

static void trace_setswitchcond(const char* cmd) {
  lldb->traceSetSwitchCond(cmd);
}

static void trace_setlogfile(const char* cmd) { lldb->traceSetLogFile(cmd); }

static void trace_setcond(const char* cmd, bool into) {
  QStringList items = QString(cmd + 1).split(", .");
  lldb->traceSetBreakCond(items[0].toUtf8().data());
  lldb->traceSetBreakCount(items[1].toInt());
  lldb->traceSetInit(into);
  if (into)
    lldb->executeStepIn();
  else
    lldb->executeStepOver();
}

static void trace_record_start(const char* cmd) {
  QStringList itemsBreak = QString(cmd).split(", .");
  QStringList itemsRecord = itemsBreak[0].split(" .");
  lldb->traceSetBreakCond(itemsRecord[1].toUtf8().data());
  lldb->traceSetBreakCount(itemsBreak[1].toInt());
  lldb->traceSetRecordInit();
  _dbg_dbgenableRunTrace(true, itemsRecord[0].toUtf8().data());
  lldb->executeStepIn();
}

static void trace_record_stop() {
  lldb->traceStop(true);
  _dbg_dbgenableRunTrace(false, nullptr);
}

static void run2bbe() {
  if (!lldb->executeRunToBBE()) {
    GuiAddLogMessage(
        "Run to basicblock end needs UraniumVM virtualization debug mode.\n");
    return;
  }
}

static void adcpp_compile(const char* path) {
  if (!lldb->interpADCpp(path, true)) {
    GuiAddLogMessage(
        "ADCpp script system needs UraniumVM virtualization debug mode.\n");
    return;
  }
}

static void cmd_decompile(const char* saddr) {
  duint addr = strtoull(saddr, nullptr, 16);
  if (!addr) {
    auto mdb = DbgGlobal::inst()->debugee;
    QString src = mdb->pseudoPath();
    if (!QFileInfo(src).exists()) {
      QString* realpath = DbgGlobal::inst()->mapPath(mdb->path);
      if (!realpath) realpath = &mdb->path;
      if (retdec_main(realpath->toUtf8().data(), src.toUtf8().data(), 0, 0,
                      [mdb](addr_t addr) {
                        auto rva = addr - mdb->db->baseaddr;
                        auto func = mdb->rvaToFunction(rva, true);
                        return func ? mdb->db->string(func->name) : nullptr;
                      }) == 0) {
      } else {
        GuiAddLogMessage(QString("Failed to decompile module %1.\n")
                             .arg(*realpath)
                             .toUtf8()
                             .data());
      }
    }
    DbgGlobal::inst()->loadPseudoCode(src, mdb);
    return;
  }

  ManaDatabase* mdb = nullptr;
  for (auto& m : DbgGlobal::inst()->modules) {
    if (addr >= m.second->rtbase &&
        addr < m.second->rtbase + m.second->opcsize) {
      mdb = m.second;
      break;
    }
  }
  if (!mdb) {
    GuiAddLogMessage(QString("Failed to find module at address %1.\n")
                         .arg(ToPtrString(addr))
                         .toUtf8()
                         .data());
    return;
  }
  auto func = mdb->rvaToFunction(addr - mdb->rtbase, false);
  if (func) {
    QString srcjson = QString("%1/%2.c")
                          .arg(DbgGlobal::inst()->tempDir())
                          .arg(mdb->db->string(func->name));
    QString* realpath = DbgGlobal::inst()->mapPath(mdb->path);
    if (!realpath) realpath = &mdb->path;
    addr_t filebase = mdb->db->baseaddr;
    if (retdec_main(realpath->toUtf8().data(), srcjson.toUtf8().data(),
                    filebase + func->rvastart, filebase + func->rvaend,
                    [mdb](addr_t addr) {
                      auto rva = addr - mdb->db->baseaddr;
                      auto func = mdb->rvaToFunction(rva, true);
                      return func ? mdb->db->string(func->name) : nullptr;
                    }) == 0) {
      GuiLoadSourceFileEx(srcjson.toUtf8().data(),
                          mdb->rtbase + func->rvastart);
      DbgGlobal::inst()->loadPseudoCode(srcjson, mdb);
    } else {
      GuiAddLogMessage(QString("Failed to decompile function %1.\n")
                           .arg(mdb->db->string(func->name))
                           .toUtf8()
                           .data());
    }
  } else {
    GuiAddLogMessage(QString("Failed to find function at address %1.\n")
                         .arg(ToPtrString(addr))
                         .toUtf8()
                         .data());
  }
}

template <typename T>
static void search_binary(T* startbuff, T* endbuff, T value,
                          std::vector<void*>& results) {
  for (T* ptr = startbuff; ptr < endbuff;) {
    if (ptr[0] == value) {
      results.push_back(ptr);
      ptr += 1;
    } else {
      ptr = (T*)((char*)ptr + 1);
    }
  }
}

static void search_binary(duint start, int size, const uint8_t* buf,
                          int bufsz) {
  if (!start || !size) {
    GuiAddLogMessage(QString("Invalid search value: start=%1, size=%2.\n")
                         .arg(ToPtrString(start))
                         .arg(size)
                         .toUtf8()
                         .data());
    return;
  }
  auto debugee = DbgGlobal::inst()->debugee;
  if (!debugee) return;
  QString* path = DbgGlobal::inst()->mapPath(debugee->path);
  if (!path) path = &debugee->path;
  QFile file(*path);
  if (!file.open(QIODevice::ReadOnly)) {
    GuiAddLogMessage(
        QString("Failed to read %1.\n").arg(*path).toUtf8().data());
    return;
  }
  QByteArray fbuff = file.readAll();
  auto rva = start - debugee->rtbase;
  auto sect = debugee->rvaToSection(rva);
  if (!sect) {
    GuiAddLogMessage(QString("Failed to find section for %1.\n")
                           .arg(ToPtrString(start))
                           .toUtf8()
                           .data());
    return;
  }
  auto sectrva = sect->addr - debugee->db->baseaddr;
  int foff = sect->fileoff + (rva - sectrva);

  uint8_t* startbuff = (uint8_t*)fbuff.data() + foff;
  uint8_t* endbuff = startbuff + size;
  if (endbuff > (uint8_t*)fbuff.data() + fbuff.length()) {
    endbuff = (uint8_t*)fbuff.data() + fbuff.length();
  }
  std::vector<void*> results;
  switch (bufsz) {
    case 1:
      search_binary(startbuff, endbuff, buf[0], results);
      break;
    case 2:
      search_binary((uint16_t*)startbuff, (uint16_t*)endbuff, *(uint16_t*)buf,
                    results);
      break;
    case 4:
      search_binary((uint32_t*)startbuff, (uint32_t*)endbuff, *(uint32_t*)buf,
                    results);
      break;
    case 8:
      search_binary((uint64_t*)startbuff, (uint64_t*)endbuff, *(uint64_t*)buf,
                    results);
      break;
    default:
      for (auto ptr = startbuff; ptr < endbuff;) {
        if (memcmp(ptr, buf, bufsz) == 0) {
          results.push_back(ptr);
          ptr += bufsz;
        } else {
          ptr++;
        }
      }
      break;
  }

  GuiReferenceInitialize(QString("Search.%1.%2")
                             .arg(ToPtrString(start))
                             .arg(size)
                             .toUtf8()
                             .data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(200, "Value");
  GuiReferenceSetRowCount(results.size());
  int index = 0;
  for (auto& p : results) {
    duint pfoff = (char*)p - fbuff.data();
    if (pfoff < sect->fileoff || pfoff >= sect->fileoff + sect->size) {
      sect = debugee->foffToSection(pfoff);
      if (!sect) {
        continue;
      }
    }
    duint pfaddr = sect->addr + pfoff - sect->fileoff;
    duint prtaddr = debugee->rtbase + pfaddr - debugee->db->baseaddr;
    QString value;
    for (uint8_t* ptr = (uint8_t*)p; ptr < (uint8_t*)p + 16; ptr++) {
      char tmpbuf[8];
      sprintf(tmpbuf, "%02x ", *ptr);
      value += tmpbuf;
    }
    GuiReferenceSetCellContent(index, 0, ToPtrString(prtaddr).toUtf8().data());
    GuiReferenceSetCellContent(index, 1, value.toUtf8().data());
    index++;
  }
}

static void search_findasm(const char* infos) {
  // findasm \"%1\", %2, .%3, %4
  const char* asmcode = infos + 1;
  const char* strstart = asmcode;
  while (*strstart != '"') strstart++;
  *(char*)strstart = 0;
  unsigned char tmpopc[20];
  auto err = DbgGlobal::inst()->diser(nullptr)->assemble(asmcode, tmpopc);
  if (!tmpopc[0]) {
    GuiAddLogMessage(err.data());
    return;
  }

  strstart += 3;
  const char* strsize;
  duint start = strtoull(strstart, (char**)&strsize, 16);
  int size = strtol(strsize + 3, nullptr, 10);
  auto debugee = DbgGlobal::inst()->debugee;
  if (!size) {
    start = debugee->rtbase + debugee->db->func(0)->rvastart;
    size = debugee->opcsize;
  }
  if (start < debugee->rtbase || start > debugee->rtbase + debugee->opcsize) {
    GuiAddLogMessage(QString("Out of search range[%1, %2): start=%3, size=%4.\n")
                         .arg(ToPtrString(debugee->rtbase))
                         .arg(ToPtrString(debugee->rtbase + debugee->opcsize))
                         .arg(ToPtrString(start))
                         .arg(size)
                         .toUtf8()
                         .data());
    return;
  }
  search_binary(start, size, &tmpopc[1], tmpopc[0]);
}

static void search_calls(const char* infos) {
  // modcallfind %1, .%2, 0
  const char* strstart = infos;
  const char* strsize;
  duint start = strtoull(strstart, (char**)&strsize, 16);
  int size = strtol(strsize + 3, nullptr, 10);
  auto debugee = DbgGlobal::inst()->debugee;
  if (!size) {
    start = debugee->rtbase + debugee->db->func(0)->rvastart;
    size = debugee->opcsize;
  }
  if (start < debugee->rtbase || start > debugee->rtbase + debugee->opcsize) {
    GuiAddLogMessage(QString("Out of search range: start=%1, size=%2.\n")
                         .arg(ToPtrString(start).arg(size))
                         .toUtf8()
                         .data());
    return;
  }
  duint rvastart = start - debugee->rtbase;
  duint rvaend = rvastart + size;
  const ManaFunc* fn = debugee->rvaToFunction(rvastart, false);
  const ManaFunc* fnend = debugee->db->func(debugee->db->nfunc - 1);
  std::vector<int> rvas;
  for (; fn < fnend; fn++) {
    if (fn->rvastart >= rvaend) {
      break;
    }
    for (int i = 0; i < fn->ninsn; i++) {
      const ManaInsn* insn = debugee->db->insn(fn, i);
      if (insn->type == mana::CALL) {
        rvas.push_back(fn->rvastart + insn->fnoff);
      }
    }
  }
  auto richdiser = mainWindow->cpuWidget()->getDisasmWidget();
  GuiReferenceInitialize(QString("Search.%1.%2")
                             .arg(ToPtrString(start))
                             .arg(size)
                             .toUtf8()
                             .data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(200, "Value");
  GuiReferenceSetRowCount(rvas.size());
  QString* path = DbgGlobal::inst()->mapPath(debugee->path);
  if (!path) path = &debugee->path;
  QFile file(*path);
  if (!file.open(QIODevice::ReadOnly)) {
    GuiAddLogMessage(
        QString("Failed to read %1.\n").arg(*path).toUtf8().data());
    return;
  }
  QByteArray fbuff = file.readAll();
  int index = 0;
  for (auto r : rvas) {
    auto sect = debugee->rvaToSection(r);
    if (!sect) continue;
    auto sectrva = sect->addr - debugee->db->baseaddr;
    Instruction_t insn = richdiser->DisassembleAt(r, fbuff.data() + sect->fileoff + r - sectrva);
    GuiReferenceSetCellContent(
        index, 0, ToPtrString(debugee->rtbase + r).toUtf8().data());
    QString asmcode;
    for (auto& t : insn.tokens.tokens) {
      asmcode += t.text;
    }
    GuiReferenceSetCellContent(index, 1, asmcode.toUtf8().data());
    index++;
  }
}

static void search_pattern(const char* infos) {
  // findall %1, %2, .%3
  const char* strstart = infos;
  const char* strpat;
  duint start = strtoull(strstart, (char**)&strpat, 16);
  strpat += 2;
  QByteArray patbuff;
  while (*strpat && *strpat != ',') {
    char tmppat[4];
    tmppat[0] = *strpat++;
    tmppat[1] = *strpat++;
    tmppat[2] = 0;
    patbuff.push_back(strtoul(tmppat, nullptr, 16));
  }
  int size = !*strpat ? 0 : strtol(strpat + 3, nullptr, 10);
  auto debugee = DbgGlobal::inst()->debugee;
  if (!size) {
    start = debugee->rtbase + debugee->db->func(0)->rvastart;
    size = debugee->opcsize;
  }
  if (start < debugee->rtbase || start > debugee->rtbase + debugee->opcsize) {
    GuiAddLogMessage(QString("Out of search range: start=%1, size=%2.\n")
                         .arg(ToPtrString(start).arg(size))
                         .toUtf8()
                         .data());
    return;
  }
  search_binary(start, size, (uint8_t*)patbuff.data(), patbuff.size());
}

static void search_list_strs(const char* infos) {
  // ignore infos currently
  auto debugee = DbgGlobal::inst()->debugee;
  GuiReferenceInitialize(QString("Strings.%1")
                             .arg(QFileInfo(debugee->path).fileName())
                             .toUtf8()
                             .data());
  GuiReferenceAddColumn(18, "Address");
  GuiReferenceAddColumn(300, "String");
  GuiReferenceSetRowCount(debugee->strs.size());
  int index = 0;
  for (auto& s : debugee->strs) {
    GuiReferenceSetCellContent(index, 0, ToPtrString(s.first).toUtf8().data());
    GuiReferenceSetCellContent(index, 1, s.second.data());
    index++;
  }
}

static void reanalyze_debugee(const char* seladdr) {
  auto dg = DbgGlobal::inst();
  auto debugee = dg->debugee;
  if (!debugee) return;
  for (auto &m : lldb->moduleList()) {
    if (m.startAddress == debugee->rtbase) {
      QFile(dg->pathModule(m.modulePath.data(), &m)).remove();
      for (auto it = dg->modules.begin(); it != dg->modules.end(); it++) {
        if (debugee == it->second) {
          dg->modules.erase(it);
          dg->debugee = nullptr;
          break;
        }
      }
      break;
    }
  }
  GuiDisasmAt(strtoull(seladdr, nullptr, 16), regPC());
}

static void save_dumpdata(const char* dumpinfo) {
  // "savedata \"%1\",%2,%3"
  const char *path = dumpinfo;
  if (*path == '"') path++;
  char *ptr = (char *)path;
  while (*ptr != '"' && *ptr != ',') ptr++;
  *ptr++ = 0;
  if (*ptr == ',') ptr++;

  duint start = strtoull(ptr, &ptr, 16);
  duint bytes = strtoul(ptr + 1, nullptr, 16);
  if (!start || !bytes) {
    GuiAddLogMessage(QString("Invalid dump data parameters %1,%2.\n")
                     .arg(ToPtrString(start)).arg(bytes).toUtf8().data());
    return;
  }
  switch (DbgGlobal::inst()->currentPlatform()) {
  case pt_local_mac:
  case pt_remote_ios:
  case pt_remote_android:
    lldb->command(QString("mem read -b -r -o %1 0x%2 0x%3").arg(path)
                  .arg(ToHexString(start)).arg(ToHexString(start + bytes)).toUtf8().data());
    break;
  default: {
    FILE *fp = fopen_helper(path, "wb");
    if (fp) {
      char *tmpbuff = new char[bytes];
      lldb->readMemory(start, tmpbuff, bytes, true);
      fwrite(tmpbuff, 1, bytes, fp);
      fclose(fp);
      delete[] tmpbuff;
    }
    else {
      GuiAddLogMessage(QString("Failed to create file %1.\n").arg(path).toUtf8().data());
      return;
    }
    break;
  }
  }
  GuiAddLogMessage(QString("Dumped %1,%2 to file %3.\n").arg(ToPtrString(start))
                   .arg(bytes).arg(path).toUtf8().data());
}

static void hypertrace_add(const char *name) {
  switch (DbgGlobal::inst()->currentPlatform()) {
  case pt_remote_vp_android: {
    SYMBOLMODULEINFO smi;
    for (auto& m : lldb->moduleList()) {
      if (m.moduleName == name) {
        smi.base = m.startAddress;
        strncpy(smi.name, m.moduleName.data(), sizeof(smi.name));
        hypertraceView->addTraceModule(smi);
        lldb->hypertraceModule(&m, true);
        break;
      }
    }
    break;
  }
  default:
    GuiAddLogMessage("Only YooPhone platform supports hypertrace now.\n");
    break;
  }
}

static void hypertrace_del(const char *name) {
  switch (DbgGlobal::inst()->currentPlatform()) {
  case pt_remote_vp_android: {
    for (auto& m : lldb->moduleList()) {
      if (m.moduleName == name) {
        lldb->hypertraceModule(&m, false);
        break;
      }
    }
    break;
  }
  default:
    GuiAddLogMessage("Only YooPhone platform supports hypertrace now.\n");
    break;
  }
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
      {"adcc", [](const char* cmd) { adcpp_compile(cmd + 5); }},
      {"launch",
       [](const char* cmd) { launch_debugee_file(cmd + sizeof("launch")); }},
      {"attach",
       [](const char* cmd) { init_debugee_process(cmd + sizeof("attach")); }},
      {"asm", [](const char* cmd) { asm_insn(cmd + 4); }},
      {"tasm", [](const char* cmd) { tasm_insn(cmd + 4); }},
  };
  static const a64dbg_cmd_t adcmds_dbg[] = {
      {"bp",
       [](const char* cmd) {
         bp_set(cmd + 3);  // skip <bp >
       }},
      {"bc",
       [](const char* cmd) {
         bp_unset(cmd + 3);  // skip <bp >
       }},
      {"be",
       [](const char* cmd) {
         bp_enable(cmd + 3);  // skip <ba >
       }},
      {"bd",
       [](const char* cmd) {
         bp_disable(cmd + 3);  // skip <bd >
       }},
      {"SetBreakpointCondition",
       [](const char* cmd) {
         bp_cond(cmd + strlen("SetBreakpointCondition") +
                 1);  // skip <SetBreakpointCondition >
       }},
      {"SetBreakpointSingleshoot",
       [](const char* cmd) {
         bp_oneshot(cmd + strlen("SetBreakpointSingleshoot") + 1);
       }},
      {"AddWatch", [](const char* cmd) { watch_set(cmd + 9); }},
      {"DelWatch", [](const char* cmd) { watch_unset(cmd + 9); }},
      {"dump",
       [](const char* cmd) {
         char* index = nullptr;
         uint64_t addr = strtoul(cmd + 5, &index, 16);  // skip <dump >
         if (!addr) {
           if (cmd[5] != '[') {
             return;
           }
           addr = strtoul(cmd + 6, &index, 16);  // skip <dump [>
           if (!addr || index[0] != ']') {
             return;
           }
           index++;
           if (!DbgMemRead(addr, &addr, sizeof(addr))) {
             return;
           }
         }
         GuiDumpAtN(
             addr,
             (index && index[0] == ',') ? atoi(&index[3]) : 1);  // skip <, .>
         GuiFocusView(GUI_DUMP);
       }},
      {"sdump",
       [](const char* cmd) {
         GuiStackDumpAt(DbgValFromString(cmd + 6), regSP());
         GuiFocusView(GUI_STACK);
       }},
      {"disasm",
       [](const char* cmd) {
         duint addr = DbgValFromString(cmd + 7);
         const char *pat = strchr(cmd, ':');
         if (pat) {
           pat++;
           auto mdb = DbgGetModuleAtEx(addr);
           if (!mdb) return;
           for (int i = 0; i < mdb->db->nfunc; i++) {
             auto fn = mdb->db->func(i);
             auto fname = mdb->db->string(fn->name);
             if (strstr(fname, pat)) {
               addr = mdb->rtbase + fn->rvastart;
               break;
             }
           }
         }
         GuiDisasmAt(addr, regPC());
         GuiFocusView(GUI_DISASSEMBLY);
       }},
      {"detach", [](const char* cmd) { detach_debuggee(); }},
      {"stop", [](const char* cmd) { detach_debuggee(); }},
      {"sync", [](const char* cmd) { sync_execmd(cmd + 5); }},
      {"functionlist", [](const char* cmd) { list_function(); }},
      {"bookmarklist", [](const char* cmd) { list_bookmark(); }},
      {"commentlist", [](const char* cmd) { list_comment(); }},
      {"run",
       [](const char* cmd) {
         run_to_address(cmd +
                        3);  // only skip <run> to check whether has an address
       }},
      {"pause", [](const char* cmd) { lldb->interruptInferior(); }},
      {"StepInto", [](const char* cmd) { lldb->executeStepIn(); }},
      {"StepOver", [](const char* cmd) { lldb->executeStepOver(); }},
      {"rtr", [](const char* cmd) { lldb->executeStepOut(); }},
      {"rtbbe", [](const char* cmd) { run2bbe(); }},
      {"switchthread",
       [](const char* cmd) {
         switch_thread(
             cmd + sizeof("switchthread"));  // the extra <\0> means to skip < >
       }},
      {"refresh", [](const char* cmd) { refresh_content(cmd + 8); }},
      {"dp", [](const char* cmd) { dp_expr(cmd + 3); }},
      {"dis", [](const char* cmd) { dis_expr(cmd + 4); }},
      {"TraceSetLog",
       [](const char* cmd) { trace_setlog(cmd + sizeof("TraceSetLog")); }},
      {"TraceSetCommand",
       [](const char* cmd) { trace_setcmd(cmd + sizeof("TraceSetCommand")); }},
      {"TraceSetSwitchCondition",
       [](const char* cmd) {
         trace_setswitchcond(cmd + sizeof("TraceSetSwitchCondition"));
       }},
      {"TraceSetLogFile",
       [](const char* cmd) {
         trace_setlogfile(cmd + sizeof("TraceSetLogFile"));
       }},
      {"TraceIntoConditional",
       [](const char* cmd) {
         trace_setcond(cmd + sizeof("TraceIntoConditional"), true);
       }},
      {"TraceOverConditional",
       [](const char* cmd) {
         trace_setcond(cmd + sizeof("TraceOverConditional"), false);
       }},
      {"StartRunTrace",
       [](const char* cmd) {
         trace_record_start(cmd + sizeof("StartRunTrace"));
       }},
      {"StopRunTrace", [](const char* cmd) { trace_record_stop(); }},
      {"decompile",
       [](const char* cmd) { cmd_decompile(cmd + sizeof("decompile")); }},
      {"findasm",
       [](const char* cmd) { search_findasm(cmd + sizeof("findasm")); }},
      {"modcallfind",
       [](const char* cmd) { search_calls(cmd + sizeof("modcallfind")); }},
      {"findall",
       [](const char* cmd) { search_pattern(cmd + sizeof("findall")); }},
      {"findallmem",
       [](const char* cmd) { search_pattern(cmd + sizeof("findallmem")); }},
      {"strref",
       [](const char* cmd) { search_list_strs(cmd + sizeof("strref")); }},
      {"reanamod",
       [](const char* cmd) { reanalyze_debugee(cmd + sizeof("reanamod")); }},
      {"savedata",
       [](const char* cmd) { save_dumpdata(cmd + sizeof("savedata")); }},
      {"modhypertrace",
       [](const char* cmd) { hypertrace_add(cmd + sizeof("modhypertrace")); }},
      {"modhypertracedel",
       [](const char* cmd) { hypertrace_del(cmd + sizeof("modhypertracedel")); }},
  };

  // ignore everything if lldb hasn't running
  if (!lldb) return true;

  char cmdtype[128];
  int i = 0;
  for (; cmd[i] && cmd[i] != ' ' && i < sizeof(cmdtype); i++) {
    cmdtype[i] = cmd[i];
  }
  cmdtype[i] = 0;

  for (size_t c = 0; c < sizeof(adcmds_any) / sizeof(adcmds_any[0]); c++) {
    if (strcmp(cmdtype, adcmds_any[c].name) == 0) {
      adcmds_any[c].impl(cmd);
      // processed by a64dbg
      return true;
    }
  }

  for (size_t c = 0; c < sizeof(adcmds_dbg) / sizeof(adcmds_dbg[0]); c++) {
    if (strcmp(cmdtype, adcmds_dbg[c].name) == 0) {
      if (DbgIsDebugging()) {
        adcmds_dbg[c].impl(cmd);
      }
      // processed by a64dbg
      return true;
    }
  }

  // pass to lldb
  return false;
}

bool _dbg_dbgcmdexec(const char* cmd) {
  if (a64dbg_cmdexec(cmd)) return true;

  // raw lldb command
  // lldb->executeCommand(cmd);

  // python lldb command
  lldb->command(cmd);
  return true;
}

static void refresh_module(bool init) {
  auto modules = lldb->moduleList();
  // freed by SymbolView updator
  SYMBOLMODULEINFO* smi =
      (SYMBOLMODULEINFO*)BridgeAlloc(modules.size() * sizeof(smi[0]));
  int count = 0;
  for (auto& m : modules) {
    if (init) {
      ManaDatabase mdb;
      mdb.path = m.modulePath.data();
      if (QFileInfo(mdb.udPath()).exists()) {
        if (!DbgGlobal::inst()->hasModule(m.modulePath.data(), &m)) {
          load_module_sync(m.modulePath.data(), &m);
        }
      }
    }

    smi[count].base = m.startAddress;
    strncpy(smi[count].name, m.moduleName.data(), sizeof(smi->name));
    count++;
  }
  GuiSymbolUpdateModuleList(count, smi);
}

static void finished_analyze(bool initing, DbgModule* module) {
  if (initing) {
    GuiSetDebugState(DBGSTATE::initialized);
  }

  auto dg = DbgGlobal::inst();
  unsigned fcrc = dg->pathCRC(module->modulePath.data(), module);
  auto found = dg->modules.find(fcrc);
  if (found == dg->modules.end()) {
    GuiAddLogMessage(
        "Fatal software error, cannot find the current debuggee module.");
    return;
  }
  found->second->rtbase = module->startAddress;
  dg->debugee = found->second;

  GuiExecuteOnGuiThreadEx([](void* p) { GuiDisasmAt(0, regPC()); }, nullptr);
}

static const ManaFunc* search_func(addr_t addr, std::string& module,
                                   std::string& fname) {
  for (auto& m : DbgGlobal::inst()->modules) {
    if (m.second->rtbase < addr &&
        addr < m.second->rtbase + m.second->opcsize) {
      module = m.second->moduleName().toUtf8().data();
      auto func = m.second->rvaToFunction(addr - m.second->rtbase, false);
      if (func) {
        fname = m.second->db->string(func->name);
      }
      return func;
    }
  }
  return nullptr;
}

static bool travel_func(
    std::function<bool(const DbgModule* module, const ManaFile* mdb,
                       const ManaFunc* func)>
        callback) {
  for (auto& m : DbgGlobal::inst()->modules) {
    DbgModule module;
    QByteArray path = m.second->path.toUtf8();
    module.startAddress = m.second->rtbase;
    module.endAddress = m.second->rtbase + m.second->opcsize;
    module.modulePath = path.data();
    module.moduleName = "";
    module.triple = "";
    if (callback(&module, m.second->db, m.second->db->func(0))) {
      return true;
    }
  }
  return false;
}

MODULEPARTY check_party(const QString& path);

// DBG functions
const char* _dbg_dbginit() {
  static const DbgGuiOperator guiops = {
      .currentPlatform = [] { return DbgGlobal::inst()->currentPlatform(); },
      .addStatusMessage = [](const char* msg) { GuiAddStatusBarMessage(msg); },
      .addLogMessage = [](const char* msg) { GuiAddLogMessage(msg); },
      .addSymbolLogMessage = [](const char* msg) { GuiSymbolLogAdd(msg); },
      .updateAllViews = []() { GuiUpdateAllViews(); },
      .updateDisassemblyView = []() { GuiUpdateDisassemblyView(); },
      .updateRegisterView = [] { GuiUpdateRegisterView(); },
      .updateThreadView = [] { GuiUpdateThreadView(); },
      .updateBreakpointView = []() { GuiUpdateBreakpointsView(); },
      .updateWatchpointView = []() { GuiUpdateWatchView(); },
      .updateCallStack = []() { GuiUpdateCallStack(); },
      .updateArgumentWidget = []() { GuiUpdateArgumentWidget(); },
      .inputString =
          [](const char* title, std::string& result) {
            QString qstr;
            Bridge::getBridge()->getStrWindow(title, &qstr);
            result = qstr.toUtf8().data();
          },
      .refreshModule = [](bool init) { refresh_module(init); },
      .hasModule =
          [](const char* path, DbgModule* module) {
            return DbgGlobal::inst()->hasModule(path, module);
          },
      .addModule =
          [](const char* path, DbgModule* module) {
            DbgGlobal::inst()->addModule(path, module);
          },
      .loadModuleSync =
          [](const char* path, DbgModule* module) {
            load_module_sync(path, module);
          },
      .finishedAnalyze =
          [](bool initing, DbgModule* module) {
            finished_analyze(initing, module);
          },
      .stackDumpAt = [](addr_t addr) { GuiStackDumpAt(addr, regSP()); },
      .dumpAt = [](addr_t addr) { GuiDumpAt(addr); },
      .dumpAtN = [](addr_t addr, int index) { GuiDumpAtN(addr, index); },
      .disasmAt = [](addr_t addr) { GuiDisasmAt(addr, regPC()); },
      .updateEnable = [](bool now) { GuiUpdateEnable(now); },
      .updateDisable = []() { GuiUpdateDisable(); },
      .valPC = []() { return (addr_t)regPC(); },
      .valSP = []() { return (addr_t)regSP(); },
      .regContextA32 = []() { return (void*)&regDumpA32; },
      .regContextA64 = []() { return (void*)&regDumpA64; },
      .regContextX64 = []() { return (void*)&regDumpX64; },
      .runPython =
          [](const char* pycode, char* result, int size) {
            ADPluginManager::inst()->adp_eval(pycode, result, size);
          },
      .traceHitAddress = [](addr_t addr) { _dbg_dbgtraceexecute(addr); },
      .sendAdpInputEvent =
          [](int event, const void* ctx) {
            ADPluginManager::inst()->sendEvent((adp_event_t)event,
                                               (adp_input_t*)ctx);
          },
      .setInitStatus = []() { GuiSetDebugState(DBGSTATE::initialized); },
      .setRunningStatus = []() { GuiSetDebugState(DBGSTATE::running); },
      .setPauseStatus = []() { GuiSetDebugState(DBGSTATE::paused); },
      .setStoppedStatus = []() { GuiSetDebugState(DBGSTATE::stopped); },
      .focusSymmod = []() { GuiFocusView(GUI_SYMMOD); },
      .focusDisassembly = []() { GuiFocusView(GUI_DISASSEMBLY); },
      .runOnGuiThread =
          [](void (*callback)(void*), void* ctx) {
            GuiExecuteOnGuiThreadEx(callback, ctx);
          },
      .isUserModule =
          [](const char* path) { return check_party(path) == mod_user; },
      .searchFunc =
          [](addr_t addr, std::string& module, std::string& func) {
            return search_func(addr, module, func);
          },
      .travelFunc =
          [](std::function<bool(const DbgModule* module, const ManaFile* mdb,
                                const ManaFunc* func)>
                 callback) { return travel_func(callback); },
      .cfgiOSIP = []() -> std::string {
        char ip[56];
        if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_IOS_IP, ip,
                              sizeof(ip))) {
          return "";
        }
        return ip;
      },
      .cfgADBPath = []() -> std::string {
        char adb[MAX_PATH];
        if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_USB, adb,
                              MAX_PATH)) {
          return "";
        }
        return adb;
      },
      .mapPath =
          [](const char* path) {
            auto mappath = DbgGlobal::inst()->mapPath(path);
            if (mappath) return mappath->toStdString();
            return std::string();
          },
      .updateDumpView = []() { GuiUpdateDumpView(); },
      .updateTraceBrowser = []() { GuiUpdateTraceBrowser(); },
  };
  lldb = new LLDBEngine(&guiops);
  lldb->start();
  if (DbgGlobal::inst()->isCloudPlatform()) {
    UVMClient::cloudPort([](int port) {
      BridgeSettingSetUint(DBGSETTING_SECTION, DSSKEY_ANDROID_PORT, port);
      // connect to cloud platform
      DbgGlobal::inst()->updatePlatform();
    });
  }
  else {
    DbgGlobal::inst()->updateUSBForward();
    DbgGlobal::inst()->updatePlatform();
  }

  SCRIPTTYPEINFO info;
  strcpy_s(info.name, "LLDB");
  info.id = 0;
  info.execute = [](const char* cmd) {
    std::string logcmd("(lldb) ");
    logcmd += cmd;
    logcmd += '\n';
    GuiAddLogMessage(logcmd.c_str());
    if (!DbgCmdExecDirect(cmd)) return false;
    GuiFlushLog();
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);

  strcpy_s(info.name, "PyLLDB");
  info.id = 1;
  info.execute = [](const char* cmd) {
    std::string logcmd("(pylldb) ");
    logcmd += cmd;
    logcmd += '\n';
    GuiAddLogMessage(logcmd.c_str());
    if (!DbgCmdExecDirect(QString("script %1").arg(cmd).toUtf8().data()))
      return false;
    GuiFlushLog();
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);

  strcpy_s(info.name, "TarShell");
  info.id = 2;
  info.execute = [](const char* cmd) {
    std::string logcmd("(shell) ");
    logcmd += cmd;
    logcmd += '\n';
    GuiAddLogMessage(logcmd.c_str());
    if (!DbgCmdExecDirect(QString("plat shell %1").arg(cmd).toUtf8().data()))
      return false;
    GuiFlushLog();
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);

  strcpy_s(info.name, "ADCpp");
  info.id = 0;
  info.execute = [](const char* cmd) {
    std::string logcmd("(adcpp) ");
    logcmd += cmd;
    logcmd += '\n';
    GuiAddLogMessage(logcmd.c_str());
    lldb->interpADCpp(cmd);
    return true;
  };
  info.completeCommand = nullptr;
  GuiRegisterScriptLanguage(&info);
  return nullptr;
}

duint _dbg_memfindbaseaddr(duint addr, duint* size) {
  if (size) *size = page_size;
  return addr & ~(page_size - 1);
}

bool MemRead(duint addr, void* dest, size_t size) {
  auto global = DbgGlobal::inst();
  auto debugee = global->debugee;
  if (!debugee) {
    return false;
  }

  if (debugee->opcodes_cache && addr >= debugee->rtbase &&
      addr < debugee->rtbase + debugee->opcsize) {
    // read from file buffer if it's valid
    OpcodePage opmem(debugee->rtbase, debugee->opcsize);
    opmem.setAttributes(debugee->rtbase, debugee->opcsize, debugee);
    opmem.read(dest, addr - debugee->rtbase, size);
  } else {
    duint base = _dbg_memfindbaseaddr(addr, nullptr);
    auto found = global->dbgpages.find(base);
    if (found == global->dbgpages.end()) {
      // only cache atmost 100 pages
      if (global->dbgpages.size() > 100) {
        global->dbgpages.clear();
      }

      global->dbgpages.insert({base, {QByteArray(), QTime::currentTime()}});
      found = global->dbgpages.find(base);
      found->second.buffer.resize(page_size);
      lldb->readMemory(base, found->second.buffer.data(), page_size, true);
    }
    memcpy(dest, found->second.buffer.data() + addr - base, size);
  }
  return true;
}

static inline bool should_updatepg(duint addr, QByteArray& page, QTime& oldtm,
                                   ManaDatabase* debugee) {
  QTime curtm = QTime::currentTime();
  // no need to update code page
  if (debugee->rtbase <= addr && addr < debugee->rtbase + debugee->opcsize) {
    return false;
  }
  // update every 30s for non debugee opcode pages
  return oldtm.secsTo(curtm) > 30;
}

bool _dbg_memread(duint addr, void* dest, duint size, duint* read) {
  auto global = DbgGlobal::inst();
  auto debugee = global->debugee;
  if (!debugee) {
    return false;
  }

  if (debugee->opcodes_cache && addr >= debugee->rtbase &&
      addr < debugee->rtbase + debugee->opcsize) {
    MemRead(addr, dest, size);
  } else {
    duint base = _dbg_memfindbaseaddr(addr, nullptr);
    auto found = global->dbgpages.find(base);
    if (found == global->dbgpages.end() ||
        should_updatepg(addr, found->second.buffer, found->second.time,
                        debugee)) {
      // only cache atmost 100 pages
      if (global->dbgpages.size() > 100) {
        global->dbgpages.clear();
      }

      global->dbgpages.insert({base, {QByteArray(), QTime::currentTime()}});
      found = global->dbgpages.find(base);
      found->second.buffer.resize(page_size);
      found->second.buffer.fill(0);
      lldb->readMemory(base, found->second.buffer.data(), page_size, false);
      found->second.time = QTime::currentTime();
    }
    memcpy(dest, found->second.buffer.data() + addr - base, size);
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
  lldb->writeMemory(addr, src, size);

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
    lldb->shutdownInferior();
  }

  lldb->shutdown();
  delete lldb;
  lldb = nullptr;
  BridgeSettingFlush();
}

static bool is_pure_hex(const char* string) {
  // ToPtrString has this situation
  if (*(int *)string == *(int *)"0000") {
    return true;
  }
  for (const char* ptr = string; *ptr; ptr++) {
    switch (*ptr) {
    case 'x':
    case 'X':
      break;
    default:
      if (('0' <= *ptr && *ptr <= '9') ||
          ('a' <= *ptr && *ptr <= 'f') ||
          ('A' <= *ptr && *ptr <= 'F')) {
        break;
      }
      return false;
    }
  }
  return true;
}

bool _dbg_valfromstring_base(const char* string, duint* value) {
  if (strcmp(string, "cip") == 0) {
    *value = regPC();
  } else if (strcmp(string, "csp") == 0) {
    *value = regSP();
  } else if (strcmp(string, "clr") == 0) {
    *value = regLR();
  } else {
    if (is_pure_hex(string)) {
      *value = strtoul(string, nullptr, 16);
    }
    else if (strcmp(string, "tr.runtraceenabled()") == 0) {
      *value = lldb->isTracing();
    }
    else if (strstr(string, "{p:")) {
      // unimpl for x64dbg's argument format
      *value = 0;
      return false;
    }
    else {
      // finally, treat as a python string
      if (ADPluginManager::inst()->adp_expr_valid(string)) {
        char outval[32];
        ADPluginManager::inst()->adp_eval(string, outval, sizeof(outval));
        if (outval[0] == '<') {
          // it's a python object
          *value = 0;
          return false;
        }
        *value = strtoul(outval, nullptr, 10);
      }
      else {
        *value = 0;
        return false;
      }
    }
  }
  return true;
}

bool _dbg_valfromstring_a32(const char* string, duint* value) {
  switch (string[0]) {
    case 'r': {
      *value = regDumpA32.regcontext.gpr[atoi(&string[1])];
      return true;
    }
    case 'd': {
      *value = regDumpA32.regcontext.neon[atoi(&string[1])][0];
      return true;
    }
    case 'q': {
      *value = (duint)&regDumpA32.regcontext.neon[atoi(&string[1])][0];
      return true;
    }
    case 'l': {
      *value = regLR();
      return true;
    }
    case 's': {
      *value = regSP();
      return true;
    }
    case 'p': {
      *value = regPC();
      return true;
    }
    case '[': {
      *value = strtoul(string + 1, nullptr, 16);
      if (*value) {
        return DbgMemRead(*value, value, 4);
      }
      return false;
    }
    case 'N': {
      *value = regDumpA32.n;
      return true;
    }
    case 'Z': {
      *value = regDumpA32.z;
      return true;
    }
    case 'C': {
      *value = regDumpA32.c;
      return true;
    }
    case 'V': {
      *value = regDumpA32.v;
      return true;
    }
    case 'T': {
      *value = regDumpA32.t;
      return true;
    }
    default:
      return _dbg_valfromstring_base(string, value);
  }
}

bool _dbg_valfromstring_a64(const char* string, duint* value) {
  switch (string[0]) {
    case 'w': {
      *value = (uint32_t)regDumpA64.regcontext.gpr[atoi(&string[1])];
      return true;
    }
    case 'x': {
      *value = regDumpA64.regcontext.gpr[atoi(&string[1])];
      return true;
    }
    case 'd': {
      *value = regDumpA64.regcontext.neon[atoi(&string[1])][0];
      return true;
    }
    case 'q': {
      *value = (duint)&regDumpA64.regcontext.neon[atoi(&string[1])][0];
      return true;
    }
    case 'N': {
      *value = regDumpA64.n;
      return true;
    }
    case 'Z': {
      *value = regDumpA64.z;
      return true;
    }
    case 'C': {
      *value = regDumpA64.c;
      return true;
    }
    case 'V': {
      *value = regDumpA64.v;
      return true;
    }
    default:
      return _dbg_valfromstring_a32(string, value);
  }
}

bool _dbg_valfromstring_x86(const char* string, duint* value) {
#define checkReg(r, v)                            \
  if (strncmp(string, #r, sizeof(#r) - 1) == 0) { \
    *value = v;                                   \
    return true;                                  \
  }
  checkReg(eax, regDumpX64.regcontext.cax);
  checkReg(ebx, regDumpX64.regcontext.cbx);
  checkReg(ecx, regDumpX64.regcontext.ccx);
  checkReg(edx, regDumpX64.regcontext.cdx);
  checkReg(edi, regDumpX64.regcontext.cdi);
  checkReg(esi, regDumpX64.regcontext.csi);
  checkReg(ebp, regDumpX64.regcontext.cbp);
  checkReg(esp, regDumpX64.regcontext.csp);
  checkReg(eip, regDumpX64.regcontext.cip);
  checkReg(eflags, regDumpX64.regcontext.eflags);
#undef checkReg

  switch (string[0]) {
    case 's': {
      *value = regSP();
      return true;
    }
    case 'p': {
      *value = regPC();
      return true;
    }
    case '[': {
      *value = strtoul(string + 1, nullptr, 16);
      if (*value) {
        return DbgMemRead(*value, value, 8);
      }
      return false;
    }
    case '_': {
      switch (string[1]) {
        case 'c': {
          *value = regDumpX64.flags.c;
          return true;
        }
        case 'p': {
          *value = regDumpX64.flags.p;
          return true;
        }
        case 'a': {
          *value = regDumpX64.flags.a;
          return true;
        }
        case 'z': {
          *value = regDumpX64.flags.z;
          return true;
        }
        case 's': {
          *value = regDumpX64.flags.s;
          return true;
        }
        case 't': {
          *value = regDumpX64.flags.t;
          return true;
        }
        case 'i': {
          *value = regDumpX64.flags.i;
          return true;
        }
        case 'd': {
          *value = regDumpX64.flags.d;
          return true;
        }
        case 'o': {
          *value = regDumpX64.flags.o;
          return true;
        }
        default:
          return false;
      }
    }
    default: {
      if (strncmp(string, "mm", 2) == 0) {
        *value = regDumpX64.mmx[atoi(&string[2])];
        return true;
      } else if (strncmp(string, "xmm", 3) == 0) {
        *value = (duint)&regDumpX64.regcontext.XmmRegisters[atoi(&string[3])];
        return true;
      } else if (strncmp(string, "ymm", 3) == 0) {
        *value = (duint)&regDumpX64.regcontext.YmmRegisters[atoi(&string[3])];
        return true;
      }
      return _dbg_valfromstring_base(string, value);
    }
  }
}

bool _dbg_valfromstring_x64(const char* string, duint* value) {
#define checkReg(r, v)                            \
  if (strncmp(string, #r, sizeof(#r) - 1) == 0) { \
    *value = v;                                   \
    return true;                                  \
  }
  checkReg(rax, regDumpX64.regcontext.cax);
  checkReg(rbx, regDumpX64.regcontext.cbx);
  checkReg(rcx, regDumpX64.regcontext.ccx);
  checkReg(rdx, regDumpX64.regcontext.cdx);
  checkReg(rdi, regDumpX64.regcontext.cdi);
  checkReg(rsi, regDumpX64.regcontext.csi);
  checkReg(rbp, regDumpX64.regcontext.cbp);
  checkReg(rsp, regDumpX64.regcontext.csp);
  checkReg(r8, regDumpX64.regcontext.r8);
  checkReg(r9, regDumpX64.regcontext.r9);
  checkReg(r10, regDumpX64.regcontext.r10);
  checkReg(r11, regDumpX64.regcontext.r11);
  checkReg(r12, regDumpX64.regcontext.r12);
  checkReg(r13, regDumpX64.regcontext.r13);
  checkReg(r14, regDumpX64.regcontext.r14);
  checkReg(r15, regDumpX64.regcontext.r15);
  checkReg(rip, regDumpX64.regcontext.cip);
  checkReg(rflags, regDumpX64.regcontext.eflags);
#undef checkReg

  return _dbg_valfromstring_x86(string, value);
}

bool _dbg_valfromstring(const char* string, duint* value) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return _dbg_valfromstring_a32(string, value);
    case mana::ARM64:
      return _dbg_valfromstring_a64(string, value);
    case mana::X86:
      return _dbg_valfromstring_x86(string, value);
    case mana::X86_64:
      return _dbg_valfromstring_x64(string, value);
    default:
      return false;
  }
}

bool _dbg_isdebugging() {
  if (!lldb) {
    return false;
  }
  return lldb->isDebugging() && DbgGlobal::inst()->modules.size();
}

bool _dbg_isjumpgoingtoexecute_a64(duint addr) {
  unsigned int opcode;
  DbgMemRead(addr, &opcode, 4);
  return DbgGlobal::inst()->diser(nullptr)->hitCondA64(
      (uint64_t*)&regDumpA64.regcontext.gpr[0], regDumpA64.n, regDumpA64.z,
      regDumpA64.c, regDumpA64.v, opcode);
}

bool _dbg_isjumpgoingtoexecute_a32(duint addr) {
  auto dg = DbgGlobal::inst();
  if (!dg->debugee) return false;
  unsigned int opcode;
  DbgMemRead(addr, &opcode, 4);
  return dg->diser(regDumpA32.t)->hitCondA32(
      (uint64_t*)&regDumpA32.regcontext.gpr[0], regDumpA32.n, regDumpA32.z,
                  regDumpA32.c, regDumpA32.v, regDumpA32.t, opcode);
}

bool _dbg_isjumpgoingtoexecute_x86_64(duint addr) {
  unsigned char opcode[16];
  DbgMemRead(addr, &opcode, 16);
  return DbgGlobal::inst()->diser(nullptr)->hitCondX64(
      (uint64_t*)&regDumpX64.regcontext.cax, regDumpX64.regcontext.eflags,
      opcode);
}

bool _dbg_isjumpgoingtoexecute(duint addr) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return _dbg_isjumpgoingtoexecute_a32(addr);
    case mana::ARM64:
      return _dbg_isjumpgoingtoexecute_a64(addr);
    default:
      return _dbg_isjumpgoingtoexecute_x86_64(addr);
  }
}

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

BPXTYPE _dbg_bpgettypeat(duint addr) {
  for (auto& bp : lldb->breakpoints()) {
    if (bp.address() == addr) {
      if (bp.isOneShot()) return bp_exception;
      return bp.isEnabled() ? bp_normal : bp_hardware;  // make it color diff
    }
  }
  return bp_none;
}

bool _dbg_valtostring_a64(const char* string, duint value) {
  switch (string[0]) {
    case 'x': {
      regDumpA64.regcontext.gpr[atoi(&string[1])] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 'l': {
      regLRPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 's': {
      regSPPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 'p': {
      regPCPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    default:
      string += 1;
      break;
  }
  switch (string[0]) {
    case 'N': {
      regDumpA64.n = (char)value & 1;
      break;
    }
    case 'Z': {
      regDumpA64.z = (char)value & 1;
      break;
    }
    case 'C': {
      regDumpA64.c = (char)value & 1;
      break;
    }
    case 'V': {
      regDumpA64.v = (char)value & 1;
      break;
    }
    case 'q': {
      memcpy(&regDumpA64.regcontext.neon[atoi(&string[1])][0], (void*)value,
             16);
      QString cmd(QString("register write v%1 \"{").arg(string + 1));
      for (uint8_t* ptr = (uint8_t*)value; ptr < (uint8_t*)value + 16; ptr++) {
        char hex[8];
        sprintf(hex, " 0x%x", ptr[0]);
        cmd += hex;
      }
      cmd += " }\"";
      lldb->command(cmd.toUtf8().data());
      return true;
    }
    default:
      return false;
  }

  uint32_t& flags = regDumpA64.flags;
  flags &= ~0x80000000;
  flags &= ~0x40000000;
  flags &= ~0x20000000;
  flags &= ~0x10000000;
  flags |= (regDumpA64.n << 31);
  flags |= (regDumpA64.z << 30);
  flags |= (regDumpA64.c << 29);
  flags |= (regDumpA64.v << 28);
  lldb->command(QString("register write cpsr %1").arg(flags).toUtf8().data());
  return true;
}

bool _dbg_valtostring_a32(const char* string, duint value) {
  switch (string[0]) {
    case 'r': {
      regDumpA32.regcontext.gpr[atoi(&string[1])] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 'l': {
      regLRPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 's': {
      regSPPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    case 'p': {
      regPCPtr()[0] = value;
      lldb->command(QString("register write %1 %2")
                        .arg(string)
                        .arg(value)
                        .toUtf8()
                        .data());
      return true;
    }
    default:
      string += 1;
      break;
  }
  switch (string[0]) {
    case 'N': {
      regDumpA32.n = (char)value & 1;
      break;
    }
    case 'Z': {
      regDumpA32.z = (char)value & 1;
      break;
    }
    case 'C': {
      regDumpA32.c = (char)value & 1;
      break;
    }
    case 'V': {
      regDumpA32.v = (char)value & 1;
      break;
    }
    case 'T': {
      regDumpA32.t = (char)value & 1;
      break;
    }
    case 'q': {
      memcpy(&regDumpA32.regcontext.neon[atoi(&string[1])][0], (void*)value,
             16);
      QString cmd(QString("register write v%1 \"{").arg(string + 1));
      for (uint8_t* ptr = (uint8_t*)value; ptr < (uint8_t*)value + 16; ptr++) {
        char hex[8];
        sprintf(hex, " 0x%x", ptr[0]);
        cmd += hex;
      }
      cmd += " }\"";
      lldb->command(cmd.toUtf8().data());
      return true;
    }
    default:
      return false;
  }

  uint32_t& flags = regDumpA32.flags;
  flags &= ~0x80000000;
  flags &= ~0x40000000;
  flags &= ~0x20000000;
  flags &= ~0x10000000;
  flags &= ~0x00000020;
  flags |= (regDumpA32.n << 31);
  flags |= (regDumpA32.z << 30);
  flags |= (regDumpA32.c << 29);
  flags |= (regDumpA32.v << 28);
  flags |= (regDumpA32.t << 5);
  lldb->command(QString("register write cpsr %1").arg(flags).toUtf8().data());
  return true;
}

bool _dbg_valtostring_x86_64_base(const char* string, duint value) {
#define checkReg(r, v, size)                                           \
  if (strcmp(string, #r) == 0) {                                       \
    memcpy(v, (void*)value, size);                                     \
    QString cmd(QString("register write %1 \"{").arg(string));         \
    for (uint8_t* ptr = (uint8_t*)value; ptr < (uint8_t*)value + size; \
         ptr++) {                                                      \
      char hex[8];                                                     \
      sprintf(hex, " 0x%x", ptr[0]);                                   \
      cmd += hex;                                                      \
    }                                                                  \
    cmd += " }\"";                                                     \
    lldb->command(cmd.toUtf8().data());                                \
    return true;                                                       \
  }

  if (string[0] == '_') {
    rfbits* flags = (rfbits*)&regDumpX64.regcontext.eflags;
    switch (string[1]) {
      case 'c': {
        regDumpX64.flags.c = (bool)value;
        flags->CF = (bool)value;
        break;
      }
      case 'p': {
        regDumpX64.flags.p = (bool)value;
        flags->PF = (bool)value;
        break;
      }
      case 'a': {
        regDumpX64.flags.a = (bool)value;
        flags->AF = (bool)value;
        break;
      }
      case 'z': {
        regDumpX64.flags.z = (bool)value;
        flags->ZF = (bool)value;
        break;
      }
      case 's': {
        regDumpX64.flags.s = (bool)value;
        flags->SF = (bool)value;
        break;
      }
      case 't': {
        regDumpX64.flags.t = (bool)value;
        flags->TF = (bool)value;
        break;
      }
      case 'i': {
        regDumpX64.flags.i = (bool)value;
        flags->IF = (bool)value;
        break;
      }
      case 'd': {
        regDumpX64.flags.d = (bool)value;
        flags->DF = (bool)value;
        break;
      }
      case 'o': {
        regDumpX64.flags.o = (bool)value;
        flags->OF = (bool)value;
        break;
      }
      default:
        return false;
    }
    if (lldb->currentArch() == mana::X86)
      string = "eflags";
    else
      string = "rflags";
    lldb->command(QString("register write %1 %2")
                      .arg(string)
                      .arg(regDumpX64.regcontext.eflags)
                      .toUtf8()
                      .data());
  }

  checkReg(stmm0, &regDumpX64.x87FPURegisters[0].data[0], 10);
  checkReg(stmm1, &regDumpX64.x87FPURegisters[1].data[0], 10);
  checkReg(stmm2, &regDumpX64.x87FPURegisters[2].data[0], 10);
  checkReg(stmm3, &regDumpX64.x87FPURegisters[3].data[0], 10);
  checkReg(stmm4, &regDumpX64.x87FPURegisters[4].data[0], 10);
  checkReg(stmm5, &regDumpX64.x87FPURegisters[5].data[0], 10);
  checkReg(stmm6, &regDumpX64.x87FPURegisters[6].data[0], 10);
  checkReg(stmm7, &regDumpX64.x87FPURegisters[7].data[0], 10);
  checkReg(mm0, &regDumpX64.x87FPURegisters[0].data[0], 8);
  checkReg(mm1, &regDumpX64.x87FPURegisters[1].data[0], 8);
  checkReg(mm2, &regDumpX64.x87FPURegisters[2].data[0], 8);
  checkReg(mm3, &regDumpX64.x87FPURegisters[3].data[0], 8);
  checkReg(mm4, &regDumpX64.x87FPURegisters[4].data[0], 8);
  checkReg(mm5, &regDumpX64.x87FPURegisters[5].data[0], 8);
  checkReg(mm6, &regDumpX64.x87FPURegisters[6].data[0], 8);
  checkReg(mm7, &regDumpX64.x87FPURegisters[7].data[0], 8);
  for (int i = 0; i < 16; i++) {
    char name[8];
    sprintf(name, "xmm%d", i);
    checkReg(name, &regDumpX64.regcontext.XmmRegisters[i].Low, 16);
    sprintf(name, "ymm%d", i);
    checkReg(name, &regDumpX64.regcontext.YmmRegisters[i].Low, 32);
  }
  return false;
#undef checkReg
}

bool _dbg_valtostring_x64(const char* string, duint value) {
#define checkReg(r, v)                            \
  if (strcmp(string, #r) == 0) {                  \
    v = value;                                    \
    lldb->command(QString("register write %1 %2") \
                      .arg(string)                \
                      .arg(value)                 \
                      .toUtf8()                   \
                      .data());                   \
    return true;                                  \
  }
  checkReg(rax, regDumpX64.regcontext.cax);
  checkReg(rbx, regDumpX64.regcontext.cbx);
  checkReg(rcx, regDumpX64.regcontext.ccx);
  checkReg(rdx, regDumpX64.regcontext.cdx);
  checkReg(rdi, regDumpX64.regcontext.cdi);
  checkReg(rsi, regDumpX64.regcontext.csi);
  checkReg(rbp, regDumpX64.regcontext.cbp);
  checkReg(rsp, regDumpX64.regcontext.csp);
  checkReg(r8, regDumpX64.regcontext.r8);
  checkReg(r9, regDumpX64.regcontext.r9);
  checkReg(r10, regDumpX64.regcontext.r10);
  checkReg(r11, regDumpX64.regcontext.r11);
  checkReg(r12, regDumpX64.regcontext.r12);
  checkReg(r13, regDumpX64.regcontext.r13);
  checkReg(r14, regDumpX64.regcontext.r14);
  checkReg(r15, regDumpX64.regcontext.r15);
  checkReg(rip, regDumpX64.regcontext.cip);
  checkReg(sp, regDumpX64.regcontext.csp);
  checkReg(pc, regDumpX64.regcontext.cip);
#undef checkReg

  return _dbg_valtostring_x86_64_base(string, value);
}

bool _dbg_valtostring_x86(const char* string, duint value) {
#define checkReg(r, v)                            \
  if (strcmp(string, #r) == 0) {                  \
    v = value;                                    \
    lldb->command(QString("register write %1 %2") \
                      .arg(string)                \
                      .arg(value)                 \
                      .toUtf8()                   \
                      .data());                   \
    return true;                                  \
  }

  checkReg(eax, regDumpX64.regcontext.cax);
  checkReg(ebx, regDumpX64.regcontext.cbx);
  checkReg(ecx, regDumpX64.regcontext.ccx);
  checkReg(edx, regDumpX64.regcontext.cdx);
  checkReg(edi, regDumpX64.regcontext.cdi);
  checkReg(esi, regDumpX64.regcontext.csi);
  checkReg(ebp, regDumpX64.regcontext.cbp);
  checkReg(esp, regDumpX64.regcontext.csp);
  checkReg(eip, regDumpX64.regcontext.cip);
  checkReg(sp, regDumpX64.regcontext.csp);
  checkReg(pc, regDumpX64.regcontext.cip);
#undef checkReg

  return _dbg_valtostring_x86_64_base(string, value);
}

bool _dbg_valtostring(const char* string, duint value) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return _dbg_valtostring_a32(string, value);
    case mana::ARM64:
      return _dbg_valtostring_a64(string, value);
    case mana::X86:
      return _dbg_valtostring_x86(string, value);
    case mana::X86_64:
      return _dbg_valtostring_x64(string, value);
    default:
      return false;
  }
}

bool _dbg_memisvalidreadptr(duint addr) {
  // android may have low memory address
  switch (DbgGlobal::inst()->currentPlatform()) {
    case pt_remote_android:
    case pt_remote_vp_android:
    case pt_remote_uraniumvm_android:
      return addr >= 0x1000;
    default:
      break;
  }

  switch (lldb->currentArch()) {
    case mana::X86:
    case mana::ARM:
      return addr >= 0x1000;
  }
  return addr >= 0x100000000;
}

static void load_breakpoint(DbgBreakpoint bparams, BRIDGEBP* bp) {
  bp->active = true;  // always active now
  bp->addr = bparams.address();
  strncpy(bp->breakCondition, bparams.condition().data(),
          sizeof(bp->breakCondition));
  bp->commandCondition[0] = 0;
  bp->commandText[0] = 0;
  bp->enabled = bparams.isEnabled();
  bp->fastResume = false;
  bp->hitCount = 0;
  bp->hwSize = 8;
  bp->logCondition[0] = 0;
  bp->logText[0] = 0;
  bp->mod[0] = 0;
  bp->name[0] = 0;
  bp->silent = false;
  bp->singleshoot = bparams.isOneShot();
  bp->slot = 0;
  bp->type = bp_normal;
  bp->typeEx = 0;
  for (auto& m : DbgGlobal::inst()->modules) {
    if (m.second->rtbase < bp->addr &&
        bp->addr < m.second->rtbase + m.second->opcsize) {
      auto func = m.second->rvaToFunction(bp->addr - m.second->rtbase, false);
      if (!func) {
        break;
      }
      strncpy(bp->mod, QFileInfo(m.second->path).fileName().toUtf8().data(),
              sizeof(bp->mod));
      strncpy(bp->name, m.second->db->string(func->name), sizeof(bp->name));
    }
  }
}

int _dbg_getbplist(BPXTYPE type, BPMAP* bplist) {
  if (!lldb) return 0;

  auto bps = lldb->breakpoints();
  bplist->count = bps.size();
  bplist->bp = (BRIDGEBP*)BridgeAlloc(bplist->count * sizeof(bplist->bp[0]));
  for (size_t i = 0; i < bps.size(); i++) {
    if (bps[i].isBreakpoint()) {
      load_breakpoint(bps[i], &bplist->bp[i]);
    } else {
      bplist->count -= 1;
    }
  }
  return bps.size();
}

bool _dbg_dbgcmddirectexec(const char* cmd) { return _dbg_dbgcmdexec(cmd); }

duint _dbg_getbranchdestination(ManaDatabase* db, duint addr) {
  uint32_t opcode;
  if (!db || !DbgIsDebugging()) return 0;
  if (db->opcodes_cache) {
    if (addr <= db->rtbase || addr >= db->rtbase + db->opcsize) {
      return 0;
    }
    opcode = *(uint32*)(db->opcodes_cache + addr - db->rtbase);
  } else {
    DbgMemRead(addr, &opcode, sizeof(opcode));
  }
  return DbgGlobal::inst()->diser(nullptr)->branchTarget(
      (unsigned char*)&opcode, addr);
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
BRIDGE_IMPEXP bool DbgGetCommentAt(ManaDatabase* db, duint addr,
                                   char* text)  // comment (not live)
{
  if (!text || !addr) return false;
  if (!db) db = DbgGlobal::inst()->debugee;
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
  strncpy(text, found->toString().toUtf8().data(), MAX_COMMENT_SIZE);
  return true;
}

BRIDGE_IMPEXP bool DbgSetCommentAt(ManaDatabase* db, duint addr,
                                   const char* text) {
  if (!text || strlen(text) >= MAX_COMMENT_SIZE || !addr) return false;
  if (!db) db = DbgGlobal::inst()->debugee;
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

BRIDGE_IMPEXP void DbgClearCommentRange(ManaDatabase* db, duint start,
                                        duint end) {
  if (!db) db = DbgGlobal::inst()->debugee;
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
BRIDGE_IMPEXP bool DbgGetModuleAt(duint addr, char* text) {
  if (!text || !addr) return false;
  for (auto& m : lldb->moduleList()) {
    if (m.startAddress <= addr && addr < m.endAddress) {
      const char* name = strrchr(m.modulePath.data(), '/');
      if (!name) name = strrchr(m.modulePath.data(), '\\');
      if (name)
        strncpy(text, name + 1, MAX_MODULE_SIZE);
      else
        strncpy(text, m.modulePath.data(), MAX_MODULE_SIZE);
      return true;
    }
  }
  return false;
}

BRIDGE_IMPEXP ManaDatabase* DbgGetModuleAtEx(duint addr) {
  auto gd = DbgGlobal::inst();
  for (auto& m : gd->memModules) {
    if (m.first <= addr && addr < m.first + MemModule_Size) {
      return m.second;
    }
  }
  for (auto& m : lldb->moduleList()) {
    if (m.startAddress <= addr && addr < m.endAddress) {
      if (!gd->hasModule(m.modulePath.data(), &m)) {
        load_module_sync(m.modulePath.data(), &m);
      }
      auto mdb = gd->getModule(m.modulePath.data(), &m);
      if (!mdb) break;
      auto rva = addr - mdb->rtbase;
      if (rva && !mdb->rvaToSection(rva)) {
        break;
      }
      return mdb;
    }
  }
  return gd->createMemModule(addr);
}

BRIDGE_IMPEXP bool DbgGetBookmarkAt(ManaDatabase* db, duint addr) {
  if (!DbgIsDebugging()) return false;
  if (!addr) return false;
  if (!db) db = DbgGlobal::inst()->debugee;
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

BRIDGE_IMPEXP bool DbgSetBookmarkAt(ManaDatabase* db, duint addr,
                                    bool isbookmark) {
  if (!addr) return false;
  if (!db) db = DbgGlobal::inst()->debugee;
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

BRIDGE_IMPEXP void DbgClearBookmarkRange(ManaDatabase* db, duint start,
                                         duint end) {
  if (!db) db = DbgGlobal::inst()->debugee;
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
extern "C" __declspec(dllexport) REGDUMP* DbgGetRegDump(REGDUMP* regdump) {
  return DbgGetRegDumpEx(nullptr, 0);
}

BRIDGE_IMPEXP REGDUMP* DbgGetRegDumpEx(REGDUMP* regdump, size_t size) {
  switch (lldb->currentArch()) {
    case mana::ARM:
      return &regDumpA32;
    case mana::ARM64:
      return &regDumpA64;
    case mana::X86:
    case mana::X86_64:
      return &regDumpX64;
    default:
      abort();
  }
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
                                 void* user) {
  DbgModule module;
  if (!lldb->findModule(base, &module)) {
    return;
  }
  auto gd = DbgGlobal::inst();
  if (!gd->hasModule(module.modulePath.data(), &module)) {
    load_module_sync(module.modulePath.data(), &module);
  }
  auto manadb = gd->getModule(module.modulePath.data(), &module);
  if (!manadb) {
    return;
  }
  for (int i = 0; i < manadb->db->nfunc; i++) {
    SYMBOLPTR sinfo;
    sinfo.modbase = (duint)manadb;
    sinfo.symbol = manadb->db->func(i);
    cbSymbolEnum(&sinfo, user);
  }
}

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
  auto threads = lldb->threadList();
  list->count = threads.size();
  list->list = (THREADALLINFO*)BridgeAlloc(list->count * sizeof(list->list[0]));
  for (int i = 0; i < list->count; i++) {
    auto& td = threads[i];
    THREADALLINFO* tinfo = &list->list[i];
    memset(tinfo, 0, sizeof(tinfo[0]));
    tinfo->BasicInfo.ThreadNumber = i;
    tinfo->BasicInfo.ThreadId = td.tid;
    strncpy(tinfo->BasicInfo.threadName, td.name.data(),
            sizeof(tinfo->BasicInfo.threadName));
    tinfo->BasicInfo.Handle = (void*)(long)td.tid;
    tinfo->ThreadCip = td.addr;
    tinfo->WaitReason = _UserRequest;
    if (td.debugee) {
      list->CurrentThread = i;
    }
  }
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
  auto debugee = DbgGlobal::inst()->debugee;
  if (!debugee) return false;
  if (addr < debugee->rtbase || addr > debugee->rtbase + debugee->opcsize) {
    return false;
  }
  auto func = debugee->rvaToFunction(addr - debugee->rtbase, false);
  if (!func) return false;
  if (start) {
    *start = debugee->rtbase + func->rvastart;
  }
  if (end) {
    *end = debugee->rtbase + func->rvaend;
  }
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

BRIDGE_IMPEXP bool DbgGetWatchList(ListOf(WATCHINFO) list) {
  std::vector<WATCHINFO> vec;
  for (auto& w : lldb->breakpoints()) {
    if (w.isWatchpoint()) {
      vec.push_back(WATCHINFO());

      auto it = vec.rbegin();
      sprintf(it->Expression, "0x%llX", w.address());
      it->id = atoi(w.responseId().data());
      _dbg_memread(w.address(), &it->value, 8, nullptr);
      it->varType = TYPE_UINT;
      it->watchdogMode = MODE_CHANGED;
      it->WatchName[0] = 0;
      it->window = w.bitSize() / 8;
    }
  }
  if (vec.size()) {
    BridgeList<WATCHINFO>::CopyData(list, vec);
    return true;
  }
  return false;
}

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
  for (auto& debugee : DbgGlobal::inst()->modules) {
    auto mdb = debugee.second;
    if (mdb->rtbase < addr && addr < mdb->rtbase + mdb->opcsize) {
      auto rva = addr - mdb->rtbase;
      auto fn = mdb->rvaToFunction(rva, false);
      if (fn) {
        QByteArray ba = mdb->path.toUtf8();
        const char* name = strrchr(ba.data(), '/');
        if (!name) name = strrchr(ba.data(), '\\');
        if (name)
          name++;
        else
          name = ba.data();
        snprintf(text, MAX_STRING_SIZE, "%s.%s+%x", name,
                 mdb->db->string(fn->name), rva - fn->rvastart);
        return true;
      }
    }
    const char* str = mdb->vaToString(addr);
    if (str[0]) {
      size_t len = std::min((int)strlen(str), (int)MAX_STRING_SIZE - 1);
      strncpy(text, str, len);
      text[len] = 0;
      return true;
    }
  }
  return false;
}

static bool GetiOSApps(DBGPROCESSINFO** entries, int* count) {
  *entries = nullptr;
  *count = 0;

  char* buffs = lldb->commandResult(
      "platform shell find /var/containers/Bundle/Application -type d "
      "-maxdepth 2 -name \"*.app\"");
  QString listbuff(buffs);
  delete[] buffs;
  QStringList lists = listbuff.split('\n');
  for (auto it = lists.begin(); it != lists.end();) {
    if (it->indexOf(".app") <= 0 || it->indexOf(".app/Watch") > 0) {
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

static void inject_remote_android(const QString& adb, const QString& loadercode,
                                  const QString& uvmroot, int pid,
                                  const QString& exe, bool is64) {
  // we use Magisk Riru Framework to inject zygote now.
#if 0
  // frida cannot inject zygote, so let user do the job with lldb mode
  GuiAddLogMessage(QString(
    "You should call the following expression in lldb mode to "
    "inject our daemon to zygote%1 at least once:\n"
    "(lldb) p (void *)dlopen(\"%2/libadzygote.so\", 2)\n")
    .arg(is64 ? "64" : "").arg(uvmroot).toUtf8().data());
#endif
}

static bool GetApkApps(DBGPROCESSINFO** entries, int* count) {
  static DbgPlatformType last_pt = pt_invalid_platform;
  auto curpt = DbgGlobal::inst()->currentPlatform();
  char adb[MAX_PATH];
  if (!BridgeSettingGet(DBGSETTING_SECTION, DSSKEY_ANDROID_USB, adb,
                        MAX_PATH)) {
    GuiAddLogMessage(
        "Please set the android adb full path before use launch apk mode in "
        "the settings.\n");
    return false;
  }
  if (curpt != last_pt) {
    // print current selinux status, user should setenforce 0 to launch uvmdbg
    // activity
    lldb->command("platform shell getenforce");
    last_pt = curpt;

    DBGPROCESSINFO* procs;
    int pnum = 0;
    DbgFunctions()->GetProcessList(&procs, &pnum);
    if (!pnum) {
      GuiAddLogMessage("Failed to parse process list to inject zygote.\n");
      return false;
    }
    const char* codefmt =
        "const libuvmdbg = Module.load('%1');\n"
        "const uvmdbg_start = new "
        "NativeFunction(libuvmdbg.getExportByName('adzygote_main'), "
        "'void', ['int']);\n"
        "uvmdbg_start(%2);\n";
    bool is_lldb = curpt == pt_remote_android;
    for (int i = 0; i < pnum; i++) {
      if (strcmp(procs[i].szExeFile, "zygote") == 0) {
        inject_remote_android(
            adb,
            QString(codefmt)
                .arg("/data/local/tmp/a64dbg-server-arm.uvm/libadzygote.so")
                .arg(is_lldb),
            "/data/local/tmp/a64dbg-server-arm.uvm", (int)procs[i].dwProcessId,
            "", false);
      } else if (strcmp(procs[i].szExeFile, "zygote64") == 0) {
        inject_remote_android(
            adb,
            QString(codefmt)
                .arg("/data/local/tmp/a64dbg-server-arm64.uvm/libadzygote.so")
                .arg(is_lldb),
            "/data/local/tmp/a64dbg-server-arm64.uvm",
            (int)procs[i].dwProcessId, "", true);
      }
    }
    BridgeFree(procs);
  }

  *entries = nullptr;
  *count = 0;

  auto buffs = adb_shell(adb, "pm list packages -3 -f", true);
  if (buffs.find("Unrecognized") >= 0) {
    buffs = adb_shell(adb, "pm list packages -3 -f", false);
  }
  QString listbuff(buffs.data());
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

static const char* ps_command(DbgPlatformType pt) {
  switch (pt) {
    case pt_remote_android:
    case pt_remote_uraniumvm_android:
    case pt_remote_vp_android:
      return "platform shell ps";
    default:
      return "platform shell ps -e";
  }
}

MODULEPARTY check_party(const QString& path) {
  if (path.indexOf("/usr") == 0 || path.indexOf("/System") == 0 ||
      path.indexOf("/Library") == 0 || path.indexOf("/system") == 0) {
    return mod_system;
  }
  if (path.indexOf("/data") == 0) {
    return mod_user;
  }
  auto found = lldb->moduleMapPath(path.toUtf8().data());
  if (found) {
    if (path == found) {
      return mod_user;
    }
    return check_party(found);
  }
  return mod_user;
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

  fns.SectionFromAddr = [](duint addr, char* section) {
    auto debuggee = DbgGlobal::inst()->debugee;
    auto sect = debuggee->rvaToSection(addr - debuggee->rtbase);
    if (sect) {
      strcpy(section, debuggee->db->string(sect->info.name));
      return true;
    }
    return false;
  };
  fns.ModNameFromAddr = [](duint addr, char* modname, bool extension) {
    for (auto& m : lldb->moduleList()) {
      if (addr >= m.startAddress && addr < m.endAddress) {
        strcpy(modname, m.moduleName.data());
        return true;
      }
    }
    return false;
  };
  fns.ModBaseFromAddr = [](duint addr) -> duint {
    for (auto& m : lldb->moduleList()) {
      if (addr >= m.startAddress && addr < m.endAddress) {
        return m.startAddress;
      }
    }
    return 0;
  };
  fns.VaToFileOffset = [](duint addr) {
    for (auto& m : lldb->moduleList()) {
      if (addr >= m.startAddress && addr < m.endAddress) {
        return addr - m.startAddress;
      }
    }
    return addr;
  };
  fns.GetCallStack = [](DBGCALLSTACK* callstack) {
    if (!lldb->isDebugging()) {
      callstack->total = 0;
      callstack->entries = nullptr;
      return;
    }
    auto frames = lldb->frameList();
    callstack->total = frames.size();
    callstack->entries = (DBGCALLSTACKENTRY*)BridgeAlloc(
        callstack->total * sizeof(callstack->entries[0]));
    for (int i = 0; i < frames.size(); i++) {
      auto& frame = frames[i];
      callstack->entries[i].addr = frame.address;
      callstack->entries[i].to = frame.address;
      callstack->entries[i].from = frame.address;
      strncpy(callstack->entries[i].comment, frame.function.data(),
              sizeof(callstack->entries[i].comment));
    }
  };
  fns.ModGetParty = [](duint base) {
    auto debugee = DbgGlobal::inst()->debugee;
    if (debugee && debugee->rtbase <= base &&
        base < debugee->rtbase + debugee->opcsize) {
      return check_party(debugee->path);
    }
    for (auto& module : lldb->moduleList()) {
      if (module.startAddress <= base && base < module.endAddress) {
        return check_party(module.modulePath.data());
      }
    }
    return mod_user;
  };
  fns.PatchInRange = [](duint start, duint end) { return false; };
  fns.PatchGetEx = [](duint addr, DBGPATCHINFO* info) { return false; };
  fns.MemIsCodePage = [](duint addr, bool refresh) {
    for (auto& it : DbgGlobal::inst()->modules) {
      auto debugee = it.second;
      if (debugee->rvaToFunction(addr - debugee->rtbase, false)) {
        return true;
      }
    }
    for (auto& it : DbgGlobal::inst()->memModules) {
      auto debugee = it.second;
      if (debugee->rtbase < addr && addr < debugee->rtbase + debugee->opcsize) {
        return true;
      }
    }
    return false;
  };
  fns.GetTraceRecordType = [](duint pageAddress) {
    return _dbg_dbggetTraceRecordType(pageAddress);
  };
  fns.MemPatch = [](duint va, const unsigned char* src, duint size) {
    uint64_t base = _dbg_memfindbaseaddr(va, nullptr);
    auto found = DbgGlobal::inst()->dbgpages.find(base);
    if (found != DbgGlobal::inst()->dbgpages.end()) {
      memcpy(found->second.buffer.data() + va - base, src, size);
    }
    lldb->writeMemory(va, src, size);
    DbgGlobal::inst()->dbgpatches.insert({va, std::string((char*)src, size)});
    return true;
  };
  fns.GetBridgeBp = [](BPXTYPE type, duint addr, BRIDGEBP* bp) {
    for (auto& bkpt : lldb->breakpoints()) {
      if (addr == bkpt.address()) {
        load_breakpoint(bkpt, bp);
        return true;
      }
    }
    return false;
  };
  fns.IsDepEnabled = [] { return true; };
  fns.SymAutoComplete = [](const char* Search, char** Buffer, int MaxSymbols) {
    return 0;
  };
  fns.ModSymbolStatus = [](duint mod) { return MODSYMLOADED; };
  fns.WatchIsWatchdogTriggered = [](unsigned int id) { return false; };
  fns.ModPathFromAddr = [](duint addr, char* path, int size) {
    for (auto& m : lldb->moduleList()) {
      if (addr >= m.startAddress && addr < m.endAddress) {
        bool local = path[0] == 'l'; // indicate local path
        auto found = lldb->moduleMapPath(m.modulePath.data());
        if (local || !found) {
          strncpy(path, m.modulePath.data(), size);
        } else {
          strncpy(path, found, size);
        }
        if (local && !QFileInfo(path).exists()) {
          auto cachepath = DbgGlobal::inst()->mapPath(path);
          if (cachepath) {
            strncpy(path, cachepath->toUtf8().data(), size);
          }
        }
        return (int)strlen(path);
      }
    }
    return 0;
  };
  fns.GetTraceRecordHitCount = [](duint addr) -> unsigned int {
    return _dbg_dbggetTraceRecordHitCount(addr);
  };
  fns.ValFromString = [](const char* string, duint* value) {
    *value = DbgValFromString(string);
    return true;
  };
  fns.GetProcessList = [](DBGPROCESSINFO** entries, int* count) {
    if (count && count[0] == 'ios') {
      return GetiOSApps(entries, count);
    }
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
    auto pt = DbgGlobal::inst()->currentPlatform();
    auto callback = [entries, count](const char* buffs) {
      if (buffs) {
        QString listbuff(buffs);
        if (listbuff.indexOf("PID ") < 0) {
          GuiAddLogMessage(listbuff.toUtf8().data());
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
    // make android use ps -e command to get process list first
    char* buffs = lldb->commandResult(ps_command(pt_remote_ios));
    callback(buffs);
    delete[] buffs;
    if (!*count) {
      // try to make android use ps command to get process list second
      buffs = lldb->commandResult(ps_command(pt));
      callback(buffs);
      delete[] buffs;
    }
    return *entries != nullptr;
  };
  fns.AnimateCommand = [](const char* cmds) {
    if (strncmp(cmds, "StepInto;", 9) == 0) return animate_into(cmds, true);
    if (strncmp(cmds, "StepOver;", 9) == 0) return animate_into(cmds, false);
    return false;
  };
  fns.ModRelocationAtAddr = [](duint addr, DBGRELOCATIONINFO* relocation) {
    return false;
  };
  fns.GetSourceFromAddr = [](duint addr, char* szSourceFile, int* line) {
    auto &pseudos = DbgGlobal::inst()->pseudos;
    auto found = pseudos.end();
    for (auto it = pseudos.begin(); it != pseudos.end(); it++) {
      if (it->second == szSourceFile) {
        found = it;
        break;
      }
    }
    if (found == pseudos.end()) {
      return false;
    }
    auto mdb = found->first;
    if (!mdb->addrlines.size()) {
      return false;
    }
    auto it = mdb->addrlines.begin();
    for (;; it++) {
      auto nextit = it;
      nextit++;
      if (nextit == mdb->addrlines.end()) {
        break;
      }
      if (it->first <= addr && addr < nextit->first) {
        break;
      }
    }
    *line = it->second;
    return true;
  };
  fns.GetAddrFromLine = [](const char* szSourceFile, int line,
                           duint* displacement) {
    auto &pseudos = DbgGlobal::inst()->pseudos;
    auto found = pseudos.end();
    for (auto it = pseudos.begin(); it != pseudos.end(); it++) {
      if (it->second == szSourceFile) {
        found = it;
        break;
      }
    }
    if (found == pseudos.end()) {
      return (duint)0;
    }
    auto mdb = found->first;
    auto lineinfo = mdb->lineaddrs.find(line);
    if (lineinfo == mdb->lineaddrs.end()) {
      return mdb->rtbase;
    }
    *displacement = lineinfo->second;
    return lineinfo->second;
  };
  fns.GetAddrFromLineEx = [](duint base, const char* szSourceFile, int line) {
    auto &pseudos = DbgGlobal::inst()->pseudos;
    auto found = pseudos.end();
    for (auto it = pseudos.begin(); it != pseudos.end(); it++) {
      if (it->second == szSourceFile) {
        found = it;
        break;
      }
    }
    if (found == pseudos.end()) {
      return (duint)0;
    }
    auto mdb = found->first;
    auto lineinfo = mdb->lineaddrs.find(line);
    if (lineinfo == mdb->lineaddrs.end()) {
      return mdb->rtbase;
    }
    return lineinfo->second;
  };
  fns.Assemble = [](duint addr, unsigned char* dest, int* size,
                    const char* instruction, char* error) {
    auto diser = DbgGlobal::inst()->diser(nullptr);
    unsigned char tmpopc[20];
    auto err = diser->assemble(instruction, tmpopc);
    if (!tmpopc[0]) {
      snprintf(error, MAX_ERROR_SIZE, "%s", err.data());
      return false;
    }
    *size = tmpopc[0];
    memcpy(dest, &tmpopc[1], *size);
    return true;
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
  if (DbgIsDebugging()) {
    const ManaDatabase* mdb = (ManaDatabase*)symbolptr->modbase;
    bool validmdb = false;
    for (auto &m : DbgGlobal::inst()->modules) {
      if (m.second == mdb) {
        validmdb = true;
        break;
      }
    }
    if (!validmdb) {
      info->decoratedSymbol = "";
      info->undecoratedSymbol = "";
      return;
    }
    const ManaFunc* func = (ManaFunc*)symbolptr->symbol;
    info->addr = mdb->rtbase + func->rvastart;
    info->type = sym_symbol;
    if (mdb->db) {
      info->decoratedSymbol = (char*)mdb->db->string(func->name);
    }
    else {
      info->undecoratedSymbol = "";
    }
    info->undecoratedSymbol = info->decoratedSymbol;
  } else {
    info->decoratedSymbol = "";
    info->undecoratedSymbol = "";
  }
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
  bDisableGUIUpdate--;
  if (updateNow) GuiUpdateAllViews();
}

BRIDGE_IMPEXP void GuiUpdateDisable() { bDisableGUIUpdate++; }

BRIDGE_IMPEXP bool GuiIsUpdateDisabled() { return bDisableGUIUpdate > 0; }

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
