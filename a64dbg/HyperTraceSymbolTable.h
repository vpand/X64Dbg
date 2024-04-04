#pragma once

#include <QMutex>
#include <abstraction/DebugEngine.hpp>
#include "AbstractStdTable.h"

struct hypertrace_item_t;

struct HyperTraceSymbol {
  char *database;
  const hypertrace_item_t *item;
  const dbgapi::ManaFile *module;
  const dbgapi::ManaFunc *func;
};

class HyperTraceSymbolTable : public AbstractStdTable {
  Q_OBJECT
 public:
  HyperTraceSymbolTable(QWidget* parent = nullptr);

  QString getCellContent(int r, int c) override;
  bool isValidIndex(int r, int c) override;
  void sortRows(int column, bool ascending) override;

  friend class HyperTraceView;
  friend class SearchListViewSymbols;
  friend class HyperTraceSymbolSearchList;

 private:
  std::vector<HyperTraceSymbol> mData;
  QMutex mMutex;
  int mType;

  enum { ColAddr, ColHits, ColDecorated};
};
