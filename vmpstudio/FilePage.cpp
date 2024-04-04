#include "FilePage.h"
#include "MiscUtil.h"
#include "VMPGlobal.h"

FilePage::FilePage(const QString& path, QObject* parent)
    : QObject(parent), mFp(nullptr), mBuff(nullptr), mSize(0) {
  open(path);
}

FilePage::~FilePage() {
  if (mFp) {
    fclose(mFp);
  }
  if (mBuff) {
    delete[] mBuff;
  }
}

bool FilePage::open(const QString& path) {
  if (path.length()) {
    if (mFp) {
      delete[] mBuff;
      fclose(mFp);
    }
    mFp = fopen_helper(path.toUtf8().data(), "rb+");
    if (mFp) {
      fseek(mFp, 0, SEEK_END);
      mSize = ftell(mFp);
      fseek(mFp, 0, SEEK_SET);
      mBuff = new char[mSize];
      fread(mBuff, 1, mSize, mFp);
    } else {
      mBuff = nullptr;
      mSize = 0;
    }
  }
  return mFp != nullptr;
}

bool FilePage::read(void* parDest, dsint parRVA, duint parSize) const {
  if (!mBuff) return mOpcPage->read(parDest, parRVA, parSize);
  memcpy(parDest, mBuff + parRVA, parSize);
  return true;
}

void* FilePage::read(dsint parRVA, duint parSize) const {
  if (!mBuff)
    return mOpcPage->read(parRVA, parSize);
  else
    return mBuff + parRVA;
}

bool FilePage::write(const void* parDest, dsint parRVA, duint parSize) {
  if (!mFp) return mOpcPage->write(parDest, parRVA, parSize);

  memcpy(mBuff + parRVA, parDest, parSize);
  fseek(mFp, parRVA, SEEK_SET);
  return fwrite(parDest, 1, parSize, mFp) == parSize;
}

duint FilePage::getSize() const { return mSize; }

duint FilePage::getBase() const { return mOpcPage ? mOpcPage->getBase() : 0; }

duint FilePage::va(dsint rva) const { return getBase() + rva; }

void FilePage::setAttributes(duint base, duint size) { mSize = size; }

void FilePage::setAttributes(VMPOpcodePage* page) {
  mOpcPage = page;
  setAttributes(mOpcPage->getBase(), mOpcPage->getSize());
}

bool FilePage::inRange(duint va) const {
  return va >= getBase() && va < getBase() + mSize;
}

VMPOpcodePage::VMPOpcodePage(duint parBase, duint parSize, QObject* parent)
    : QObject(parent), mBase(0), mSize(0) {
  Q_UNUSED(parBase);
  Q_UNUSED(parSize);
}

bool VMPOpcodePage::read(void* parDest, dsint parRVA, duint parSize) {
  if (0 && DbgIsDebugging()) {
    return DbgMemRead(mBase + parRVA, reinterpret_cast<unsigned char*>(parDest),
                      parSize);
  } else if (mDB->opcodes_cache) {
    memcpy(parDest, read(parRVA), parSize);
    return true;
  }
  memset(parDest, 0, parSize);
  return false;
}

void* VMPOpcodePage::read(dsint parRVA, duint parSize) {
  if (parRVA < 0) {
    return mDB->opcodes_cache;
  }

  dsint addr = mDB->db->imageBase() + parRVA;
  if (mSect && (addr < mSect->addr || addr >= mSect->addr + mSect->size)) {
    mSect = mDB->db->addrSect(addr);
  }
  if (!mSect) {
    // decached dylib from dyld_shared_cache may have this situation
    mSect = &mDB->db->sections().begin()->second;
    if (parRVA < mDB->opcsize) return mDB->opcodes_cache + parRVA;
    return mDB->opcodes_cache + mSect->foff;
  }
  return mDB->opcodes_cache + mSect->foff + addr - mSect->addr;
}

bool VMPOpcodePage::write(const void* parDest, dsint parRVA, duint parSize) {
  if (0 && DbgIsDebugging()) {
    mDB->dbgpatches.insert({va(parRVA), std::string((char*)parDest, parSize)});
    DbgMemWrite(va(parRVA), parDest, parSize);
  } else if (mDB->opcodes_cache) {
    mDB->patches.insert({parRVA, std::string((char*)parDest, parSize)});
    memcpy(read(parRVA), parDest, parSize);
  }

  GuiUpdatePatches();
  return true;
}

duint VMPOpcodePage::getSize() const { return mSize; }

duint VMPOpcodePage::getBase() const { return mBase; }

duint VMPOpcodePage::va(dsint rva) const { return mBase + rva; }

void VMPOpcodePage::setAttributes(duint base, duint size, VMPManaDatabase* db) {
  mBase = base;
  mSize = size;
  mDB = db;
  if (!db || !db->db->sections().size()) {
    mSect = nullptr;
    return;
  }
  mSect = &db->db->sections().begin()->second;

  for (auto& s : db->db->sections()) {
    if (s.second.type == mana::TEXT) {
      mSect = &s.second;
      break;
    }
  }
}

bool VMPOpcodePage::inRange(duint va) const {
  return va >= mBase && va < mBase + mSize;
}
