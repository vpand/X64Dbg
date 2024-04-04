#ifndef FILEPAGE_H
#define FILEPAGE_H

#include <QObject>
#include <QString>

#include "Imports.h"
#include "MemoryPage.h"

struct VMPManaDatabase;

class VMPOpcodePage : public QObject {
  Q_OBJECT
 public:
  explicit VMPOpcodePage(duint parBase, duint parSize, QObject* parent = 0);

  bool read(void* parDest, dsint parRVA, duint parSize);
  void* read(dsint parRVA, duint parSize = 0);
  bool write(const void* parDest, dsint parRVA, duint parSize);
  duint getSize() const;
  duint getBase() const;
  VMPManaDatabase* dataBase() const { return mDB; }
  duint va(dsint rva) const;
  void setAttributes(duint base, duint size, VMPManaDatabase* db);
  bool inRange(duint va) const;

 private:
  duint mBase;
  duint mSize;
  VMPManaDatabase* mDB;
  const mana::Section* mSect;
};

class FilePage : public QObject {
  Q_OBJECT
 public:
  explicit FilePage(const QString& path, QObject* parent = 0);
  ~FilePage();

  bool open(const QString& path);
  bool read(void* parDest, dsint parRVA, duint parSize) const;
  void* read(dsint parRVA, duint parSize) const;
  bool write(const void* parDest, dsint parRVA, duint parSize);
  duint getSize() const;
  duint getBase() const;
  duint va(dsint rva) const;
  void setAttributes(duint base, duint size);
  void setAttributes(VMPOpcodePage* page);
  bool inRange(duint va) const;

 private:
  FILE* mFp;
  char* mBuff;
  duint mSize;
  VMPOpcodePage* mOpcPage;
};

#endif  // FILEPAGE_H
