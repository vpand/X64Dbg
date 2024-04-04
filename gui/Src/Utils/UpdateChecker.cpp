#include "UpdateChecker.h"

#include <QDateTime>
#include <QDesktopServices>
#include <QIcon>
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDir>
#include <QJsonDocument>

#include "Bridge.h"
#include "MiscUtil.h"
#include "StringUtil.h"

UpdateChecker::UpdateChecker(QWidget* parent)
    : QObject(parent), mParent(parent) {
}

void UpdateChecker::checkForUpdates() {
  QString dirpath = QDir::homePath() + PATH_SEP "VPAssistant";
  QString vpacfgfile = dirpath + PATH_SEP "/config.json";
  QFile udfile(vpacfgfile);
  if (udfile.open(QIODevice::ReadOnly)) {
    QByteArray udbuff = udfile.readAll();
    QJsonDocument json = QJsonDocument::fromJson(udbuff);
    auto vpacfg = json.toVariant().toMap();
    auto vpaexe = vpacfg.find("vpaexe");
    if (vpaexe != vpacfg.end()) {
      QProcess vpaproc;
      vpaproc.setProgram(vpaexe->toString());
      vpaproc.startDetached();
      return;
    }
  }
  QMessageBox::information(nullptr, "VP Assistant",
    "Our maintenance tool VPAssistant is missing, you can download "
    "it at https://vpand.com/ and retry.");
}
