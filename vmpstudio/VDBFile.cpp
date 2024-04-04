#include "VDBFile.h"

#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>

VDBFile::VDBFile() {}

VMPManaDatabase *VDBFile::load(const QString &rawpath) {
  QFileInfo finfo(rawpath);
  QString pdir = finfo.dir().path();
  QString name = finfo.baseName();
  QString vdbpath = rawpath.endsWith("." VDB_FILE_EXT)
                        ? rawpath
                        : QString("%1/%2." VDB_FILE_EXT).arg(pdir).arg(name);
  if (!QFileInfo(vdbpath).exists()) {
    return nullptr;
  }

  int tmpprog;
  mana::analyze_progress("LightIDA is uncompressing database...", -1, -1,
                         tmpprog);
  VDBHeader *vhdr =
      (VDBHeader *)mana::uncompressDBFile(vdbpath.toUtf8().data());
  if (!vhdr) {
    return nullptr;
  }
  QJsonDocument jdoc = QJsonDocument::fromJson((char *)vhdr + vhdr->udoff);
  VMPManaDatabase *vdb = new VMPManaDatabase;
  auto kami = (mana::KamiBinary *)mana::New(nullptr); // create an empty kimafile
  vdb->isvdb = true;
  vdb->db = kami;
  if (!vdb->db->analyze((char*)vhdr + vhdr->adboff)) {
    mana::Delete(kami);
    return nullptr;
  }
  vdb->init((char *)vhdr + vhdr->pathoff, nullptr);
  vdb->usrdef = jdoc.toVariant().toMap();
  vdb->opcsize = vhdr->rawsize;
  vdb->opcodes_cache = (char *)malloc(vdb->opcsize);
  memcpy(vdb->opcodes_cache, (char *)vhdr + vhdr->rawoff, vdb->opcsize);
  free(vhdr);
  kami->initLLVM(vdb->opcodes_cache, vdb->opcsize);
  return vdb;
}

void VDBFile::save(VMPManaDatabase *db) {
  QEventLoop eloop;
  QThread *saveThread = QThread::create(
      [](VMPManaDatabase *vdb) {
        QString vdbpath =
            QString("%1/%2.vdb").arg(vdb->moduleDir()).arg(vdb->moduleName());
        int prog = 1, tmpprog, totalprog = 3;
        mana::analyze_progress("LightIDA is saving adb database", prog++,
                               totalprog, tmpprog);
        if (!vdb->db->save(vdbpath.toUtf8().data())) {
          mana::analyze_progress(
              "Failed to save database, maybe permission denied.", -1, -1,
              tmpprog);
          return;
        }
        QFile adbfile(vdbpath);
        adbfile.open(QIODevice::ReadOnly);
        QByteArray adbbuff = adbfile.readAll();
        adbfile.close();

        QJsonDocument jdoc = QJsonDocument::fromVariant(vdb->usrdef);
        QByteArray udbuff = jdoc.toJson();
        QByteArray pathbuff = vdb->path.toUtf8();

        mana::analyze_progress("LightIDA is saving vdb database", prog++,
                               totalprog, tmpprog);
        /*
         * header
         * path
         * raw
         * adb
         * userdata
         */
        VDBHeader vhdr;
        vhdr.magic = VDB_FILE_MAGIC;
        vhdr.version = VDB_FILE_VERSION;
        vhdr.pathoff = sizeof(vhdr);
        vhdr.pathsize = pathbuff.size() + 1;
        vhdr.rawoff = vhdr.pathoff + vhdr.pathsize;
        vhdr.rawsize = vdb->opcsize;
        vhdr.adboff = vhdr.rawoff + vhdr.rawsize;
        vhdr.adbsize = adbbuff.size();
        vhdr.udoff = vhdr.adboff + vhdr.adbsize;
        vhdr.udsize = udbuff.size();
        QFile vdbfile(vdbpath);
        if (!vdbfile.open(QIODevice::WriteOnly)) {
          mana::analyze_progress(
              "Failed to save vdb database, maybe permission denied.", -1, -1,
              tmpprog);
          return;
        }
        vdbfile.write((char *)&vhdr, sizeof(vhdr));
        vdbfile.write(pathbuff.data(), vhdr.pathsize);
        vdbfile.write(vdb->opcodes_cache, vdb->opcsize);
        vdbfile.write(adbbuff);
        vdbfile.write(udbuff);
        vdbfile.close();

        mana::compressDBFile(vdbpath.toUtf8().data());
        mana::analyze_progress(
            QString("Saved database to %1.").arg(vdbpath).toUtf8().data(), -1,
            -1, tmpprog);
      },
      db);
  saveThread->connect(saveThread, SIGNAL(finished()), &eloop, SLOT(quit()));
  saveThread->start();
  eloop.exec();
  delete saveThread;
}
