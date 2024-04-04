#ifndef VDBFILE_H
#define VDBFILE_H

#include "VMPGlobal.h"

#define VDB_FILE_MAGIC '$bdv'
#define VDB_FILE_EXT "vdb"
#define VDB_FILE_VERSION 1

struct VDBHeader {
  int magic;
  int version;
  int pathoff;  // path buffer offset
  int pathsize;
  int rawoff;  // raw file buffer offset
  int rawsize;
  int adboff;  // adb file buffer offset
  int adbsize;
  int udoff;  // userdata file buffer offset
  int udsize;
};

class VDBFile {
 public:
  VDBFile();

  VMPManaDatabase *load(const QString &path);
  void save(VMPManaDatabase *vdb);
};

#endif  // VDBFILE_H
