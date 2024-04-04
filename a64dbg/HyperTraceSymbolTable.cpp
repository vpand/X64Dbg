#include "HyperTraceSymbolTable.h"
#include "HyperTraceSyscalls.cpp"

#include "Bridge.h"
#include "RichTextPainter.h"

HyperTraceSymbolTable::HyperTraceSymbolTable(QWidget* parent)
    : AbstractStdTable(parent), mMutex(QMutex::Recursive) {
  auto charwidth = getCharWidth();
  enableMultiSelection(true);
  setAddressColumn(0);
  addColumnAt(charwidth * 2 * sizeof(dsint) + 8, tr("Address"), true);
  addColumnAt(charwidth * sizeof(dsint) + 8, tr("Hits"), true);
  addColumnAt(charwidth * 80, tr("Symbol"), true);
  loadColumnFromConfig("Symbol");

  Initialize();
}

QString HyperTraceSymbolTable::getCellContent(int r, int c) {
  QMutexLocker lock(&mMutex);
  if (!isValidIndex(r, c)) return QString();

  auto &sym = mData[r];
  switch (mType) {
  case HTT_FUNCTION: {
    switch (c) {
    case ColAddr:
      return ToPtrString(sym.item->key);
    case ColHits:
      return ToDecString(sym.item->hits);
    case ColDecorated:
      return sym.module->string(sym.func->name);
    default:
      return QString();
    }
    break;
  }
  case HTT_SYSCALL: {
    switch (c) {
    case ColAddr:
      return ToDecString(sym.item->key);
    case ColHits:
      return ToDecString(sym.item->hits);
    case ColDecorated:
      return syscallName(sym.item->key);
    default:
      return QString();
    }
    break;
  }
  default:
    break;
  }
}

bool HyperTraceSymbolTable::isValidIndex(int r, int c) {
  QMutexLocker lock(&mMutex);
  return r >= 0 && r < mData.size() && c >= 0 && c <= ColDecorated;
}

void HyperTraceSymbolTable::sortRows(int column, bool ascending) {
  QMutexLocker lock(&mMutex);
  std::stable_sort(
      mData.begin(), mData.end(),
      [column, ascending](const HyperTraceSymbol& a, const HyperTraceSymbol& b) {
        switch (column) {
          case ColAddr:
            return ascending ? a.item->key < b.item->key
                             : a.item->key > b.item->key;
          case ColHits:
            return ascending ? a.item->hits < b.item->hits
                             : a.item->hits > b.item->hits;
          default:
            return false;
        }
      });
}
