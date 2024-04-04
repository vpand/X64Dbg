#ifndef MEMORYPAGE_H
#define MEMORYPAGE_H

#include <QObject>

#include "../bridge/_global.h"
#include "Imports.h"

class MemoryPage : public QObject {
  Q_OBJECT
 public:
  explicit MemoryPage(duint parBase, duint parSize, QObject* parent = 0);

  bool read(void* parDest, dsint parRVA, duint parSize) const;
  bool write(const void* parDest, dsint parRVA, duint parSize);
  duint getSize() const;
  duint getBase() const;
  duint va(dsint rva) const;
  void setAttributes(duint base, duint size);
  bool inRange(duint va) const;

 private:
  duint mBase;
  duint mSize;
};

class OpcodePage : public QObject {
  Q_OBJECT
 public:
  explicit OpcodePage(duint parBase, duint parSize, QObject* parent = 0);

  bool read(void* parDest, dsint parRVA, duint parSize);
  void* read(dsint parRVA, bool *ok);
  bool write(const void* parDest, dsint parRVA, duint parSize);
  duint getSize() const;
  duint getBase() const;
  duint va(dsint rva) const;
  void setAttributes(duint base, duint size, ManaDatabase* db,
                     bool debugee = true);
  bool inRange(duint va) const;

 private:
  duint mBase;
  duint mSize;
  ManaDatabase* mDB;
  const ManaSect* mSect;
  bool debugee;
};

#endif  // MEMORYPAGE_H
