#include "MemoryPage.h"

#include "../bridge/bridgemain.h"
#include <DebugEngine.hpp>

MemoryPage::MemoryPage(duint parBase, duint parSize, QObject* parent)
    : QObject(parent), mBase(0), mSize(0) {
  Q_UNUSED(parBase);
  Q_UNUSED(parSize);
}

bool MemoryPage::read(void* parDest, dsint parRVA, duint parSize) const {
  return DbgMemRead(mBase + parRVA, reinterpret_cast<unsigned char*>(parDest),
                    parSize);
}

bool MemoryPage::write(const void* parDest, dsint parRVA, duint parSize) {
  bool ret = DbgFunctions()->MemPatch(
      mBase + parRVA, reinterpret_cast<const unsigned char*>(parDest), parSize);
  GuiUpdatePatches();
  return ret;
}

duint MemoryPage::getSize() const { return mSize; }

duint MemoryPage::getBase() const { return mBase; }

duint MemoryPage::va(dsint rva) const { return mBase + rva; }

void MemoryPage::setAttributes(duint base, duint size) {
  mBase = base;
  mSize = size;
}

bool MemoryPage::inRange(duint va) const {
  return va >= mBase && va < mBase + mSize;
}

OpcodePage::OpcodePage(duint parBase, duint parSize, QObject* parent)
    : QObject(parent), mBase(0), mSize(0) {
  Q_UNUSED(parBase);
  Q_UNUSED(parSize);
}

bool OpcodePage::read(void* parDest, dsint parRVA, duint parSize) {
  if (!mDB) {
    return false;
  }
  if (mDB->opcodes_cache) {
    bool ok;
    memcpy(parDest, read(parRVA, &ok), parSize);
    return ok;
  }
  if (debugee || DbgIsDebugging()) {
    return DbgMemRead(mBase + parRVA, reinterpret_cast<unsigned char*>(parDest),
                      parSize);
  }
  memset(parDest, 0, parSize);
  return false;
}

void* OpcodePage::read(dsint parRVA, bool *ok) {
  *ok = false;
  if (parRVA < 0) {
    return mDB->opcodes_cache;
  }

  dsint addr = mDB->db->baseaddr + parRVA;
  if (mSect && (addr < mSect->addr || addr >= mSect->addr + mSect->size)) {
    mSect = nullptr;
    for (int i = 0; i < mDB->db->info.nsect; i++) {
      auto sect = mDB->db->sect(i);
      if (sect->addr <= addr && addr < sect->addr + sect->size) {
        mSect = sect;
        break;
      }
    }
  }
  if (!mSect) {
    mSect = mDB->db->sect(0);
  }
  char *result = mDB->opcodes_cache + mSect->fileoff + addr - mSect->addr;
  if (result >= mDB->opcodes_cache + mDB->opcsize) {
    return mDB->opcodes_cache;
  }
  *ok = true;
  return result;
}

bool OpcodePage::write(const void* parDest, dsint parRVA, duint parSize) {
  if (debugee || DbgIsDebugging()) {
    mDB->dbgpatches.insert({va(parRVA), std::string((char*)parDest, parSize)});
    DbgMemWrite(va(parRVA), parDest, parSize);
  } else if (mDB->opcodes_cache) {
    mDB->patches.insert({parRVA, std::string((char*)parDest, parSize)});
    bool ok;
    void *tarmem = read(parRVA, &ok);
    if (!ok) {
      return false;
    }
    memcpy(tarmem, parDest, parSize);
  }

  GuiUpdatePatches();
  return true;
}

duint OpcodePage::getSize() const { return mSize; }

duint OpcodePage::getBase() const { return mBase; }

duint OpcodePage::va(dsint rva) const { return mBase + rva; }

void OpcodePage::setAttributes(duint base, duint size, ManaDatabase* db,
                               bool dbgee) {
  mBase = base;
  mSize = size;
  mDB = db;
  debugee = dbgee;
  if (mDB) {
    mSect = mDB->db->sect(0);
    if (mDB->opcodes_cache) {
      // use file text section buffer
      debugee = false;
    }
  }
  else {
    return;
  }
  for (int i = 0; i < mDB->db->info.nsect; i++) {
    auto sect = mDB->db->sect(i);
    if (sect->info.type == mana::TEXT) {
      mSect = sect;
      break;
    }
  }
}

bool OpcodePage::inRange(duint va) const {
  return va >= mBase && va < mBase + mSize;
}
