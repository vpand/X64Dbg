#include "HexDumpFile.h"

#include <QMessageBox>

#include "Bridge.h"
#include "Configuration.h"
#include "StringUtil.h"

static int getStringMaxLength(HexDumpFile::DataDescriptor desc);
static int byteStringMaxLength(HexDumpFile::ByteViewMode mode);
static int wordStringMaxLength(HexDumpFile::WordViewMode mode);
static int dwordStringMaxLength(HexDumpFile::DwordViewMode mode);
static int qwordStringMaxLength(HexDumpFile::QwordViewMode mode);
static int twordStringMaxLength(HexDumpFile::TwordViewMode mode);

HexDumpFile::HexDumpFile(QWidget* parent) : AbstractTableView(parent) {
  memset(&mSelection, 0, sizeof(SelectionData));

  setDrawDebugOnly(false);

  mGuiState = HexDumpFile::NoState;

  setRowCount(0);

  mMemPage = new FilePage("");
  mForceColumn = -1;

  clearDescriptors();

  mBackgroundColor = ConfigColor("HexDumpBackgroundColor");
  mTextColor = ConfigColor("HexDumpTextColor");
  mSelectionColor = ConfigColor("HexDumpSelectionColor");

  mRvaDisplayEnabled = false;
  mSyncAddrExpression = "";
  mNonprintReplace = QChar('.');  // QChar(0x25CA);
  mNullReplace = QChar('.');      // QChar(0x2022);

  const auto updateCacheDataSize = 0x1000;
  mUpdateCacheData.resize(updateCacheDataSize);
  mUpdateCacheTemp.resize(updateCacheDataSize);

  setupCopyMenu();

  Initialize();
}

HexDumpFile::~HexDumpFile() { delete mMemPage; }

void HexDumpFile::updateColors() {
  AbstractTableView::updateColors();

  mBackgroundColor = ConfigColor("HexDumpBackgroundColor");
  mTextColor = ConfigColor("HexDumpTextColor");
  mSelectionColor = ConfigColor("HexDumpSelectionColor");

  mModifiedBytesColor = ConfigColor("HexDumpModifiedBytesColor");
  mModifiedBytesBackgroundColor =
      ConfigColor("HexDumpModifiedBytesBackgroundColor");
  mRestoredBytesColor = ConfigColor("HexDumpRestoredBytesColor");
  mRestoredBytesBackgroundColor =
      ConfigColor("HexDumpRestoredBytesBackgroundColor");
  mByte00Color = ConfigColor("HexDumpByte00Color");
  mByte00BackgroundColor = ConfigColor("HexDumpByte00BackgroundColor");
  mByte7FColor = ConfigColor("HexDumpByte7FColor");
  mByte7FBackgroundColor = ConfigColor("HexDumpByte7FBackgroundColor");
  mByteFFColor = ConfigColor("HexDumpByteFFColor");
  mByteFFBackgroundColor = ConfigColor("HexDumpByteFFBackgroundColor");
  mByteIsPrintColor = ConfigColor("HexDumpByteIsPrintColor");
  mByteIsPrintBackgroundColor =
      ConfigColor("HexDumpByteIsPrintBackgroundColor");

  mUserModuleCodePointerHighlightColor =
      ConfigColor("HexDumpUserModuleCodePointerHighlightColor");
  mUserModuleDataPointerHighlightColor =
      ConfigColor("HexDumpUserModuleDataPointerHighlightColor");
  mSystemModuleCodePointerHighlightColor =
      ConfigColor("HexDumpSystemModuleCodePointerHighlightColor");
  mSystemModuleDataPointerHighlightColor =
      ConfigColor("HexDumpSystemModuleDataPointerHighlightColor");
  mUnknownCodePointerHighlightColor =
      ConfigColor("HexDumpUnknownCodePointerHighlightColor");
  mUnknownDataPointerHighlightColor =
      ConfigColor("HexDumpUnknownDataPointerHighlightColor");

  reloadData();
}

void HexDumpFile::updateFonts() {
  duint setting;
  if (BridgeSettingGetUint("Gui", "NonprintReplaceCharacter", &setting))
    mNonprintReplace = QChar(uint(setting));
  if (BridgeSettingGetUint("Gui", "NullReplaceCharacter", &setting))
    mNullReplace = QChar(uint(setting));
  setFont(ConfigFont("HexDump"));
  invalidateCachedFont();
}

void HexDumpFile::updateShortcuts() {
  AbstractTableView::updateShortcuts();
  mCopyAddress->setShortcut(ConfigShortcut("ActionCopyAddress"));
  mCopyRva->setShortcut(ConfigShortcut("ActionCopyRva"));
  mCopySelection->setShortcut(ConfigShortcut("ActionCopy"));
}

void HexDumpFile::updateDumpSlot() {
  if (mSyncAddrExpression.length() && DbgFunctions()->ValFromString) {
    duint syncAddr;
    if (DbgFunctions()->ValFromString(mSyncAddrExpression.toUtf8().constData(),
                                      &syncAddr) &&
        DbgMemIsValidReadPtr(syncAddr)) {
      printDumpAt(syncAddr, false, false, true);
    }
  }
  UpdateCache cur;
  cur.memBase = mMemPage->getBase();
  cur.memSize = mMemPage->getSize();
  if (cur.memBase) {
    cur.rva = getTableOffsetRva();
    cur.size = getBytePerRowCount() * getViewableRowsCount();
    if (cur.size < mUpdateCacheData.size()) {
      if (mMemPage->read(mUpdateCacheTemp.data(), cur.rva, cur.size)) {
        if (mUpdateCache == cur &&
            memcmp(mUpdateCacheData.data(), mUpdateCacheTemp.data(),
                   cur.size) == 0) {
          // same view and same data, do not reload
          return;
        } else {
          mUpdateCache = cur;
          mUpdateCacheData.swap(mUpdateCacheTemp);
#ifdef DEBUG
          OutputDebugStringA(QString("[x64dbg] %1[%2] %3[%4]")
                                 .arg(ToPtrString(mUpdateCache.memBase))
                                 .arg(ToHexString(mUpdateCache.memSize))
                                 .arg(ToPtrString(mUpdateCache.rva))
                                 .arg(ToHexString(mUpdateCache.size))
                                 .toUtf8()
                                 .constData());
#endif  // DEBUG
        }
      }
    }
  }
  reloadData();
}

void HexDumpFile::copySelectionSlot() {
  Bridge::CopyToClipboard(makeCopyText());
}

void HexDumpFile::printDumpAt(dsint parVA, bool select, bool repaint,
                              bool updateTableOffset) {
  duint wSize = mMemPage->getSize();
  auto wBase = mMemPage->getBase();  // get memory base
  if (!wSize) {
    setRowCount(0);
    return;
  }
  dsint wRVA = parVA - wBase;  // calculate rva
  int wBytePerRowCount =
      getBytePerRowCount();  // get the number of bytes per row
  dsint wRowCount;

  // Byte offset used to be aligned on the given RVA
  mByteOffset = (int)((dsint)wRVA % (dsint)wBytePerRowCount);
  mByteOffset = mByteOffset > 0 ? wBytePerRowCount - mByteOffset : 0;

  // Compute row count
  wRowCount = wSize / wBytePerRowCount;
  wRowCount += mByteOffset > 0 ? 1 : 0;

  if (mRvaDisplayEnabled && mMemPage->getBase() != mRvaDisplayPageBase)
    mRvaDisplayEnabled = false;

  setRowCount(wRowCount);  // set the number of rows

  if (updateTableOffset) {
    setTableOffset(-1);  // make sure the requested address is always first
    setTableOffset((wRVA + mByteOffset) /
                   wBytePerRowCount);  // change the displayed offset
  }

  if (select) {
    setSingleSelection(wRVA);
    dsint wEndingAddress =
        wRVA + getSizeOf(mDescriptor.at(0).data.itemSize) - 1;
    expandSelectionUpTo(wEndingAddress);
  }

  if (repaint) reloadData();
}

void HexDumpFile::printDumpAt(dsint parVA) { printDumpAt(parVA, true); }

void HexDumpFile::gotoPreviousSlot() { printDumpAt(mHistory.historyPrev()); }

void HexDumpFile::gotoNextSlot() { printDumpAt(mHistory.historyNext()); }

duint HexDumpFile::rvaToVa(dsint rva) const { return mMemPage->va(rva); }

duint HexDumpFile::getTableOffsetRva() const {
  return getTableOffset() * getBytePerRowCount() - mByteOffset;
}

QString HexDumpFile::makeAddrText(duint va) const {
  char label[MAX_LABEL_SIZE] = "";
  QString addrText = "";
  dsint cur_addr = va;
  if (mRvaDisplayEnabled)  // RVA display
  {
    dsint rva = cur_addr - mRvaDisplayBase;
    if (rva == 0) {
#ifdef _WIN64
      addrText = "$ ==>            ";
#else
      addrText = "$ ==>    ";
#endif  //_WIN64
    } else if (rva > 0) {
#ifdef _WIN64
      addrText = "$+" + QString("%1").arg(rva, -15, 16, QChar(' ')).toUpper();
#else
      addrText = "$+" + QString("%1").arg(rva, -7, 16, QChar(' ')).toUpper();
#endif  //_WIN64
    } else if (rva < 0) {
#ifdef _WIN64
      addrText = "$-" + QString("%1").arg(-rva, -15, 16, QChar(' ')).toUpper();
#else
      addrText = "$-" + QString("%1").arg(-rva, -7, 16, QChar(' ')).toUpper();
#endif  //_WIN64
    }
  }
  addrText += ToPtrString(cur_addr);
  if (DbgGetLabelAt(cur_addr, SEG_DEFAULT, label))  // has label
  {
    char module[MAX_MODULE_SIZE] = "";
    if (DbgGetModuleAt(cur_addr, module) && !QString(label).startsWith("JMP.&"))
      addrText += " <" + QString(module) + "." + QString(label) + ">";
    else
      addrText += " <" + QString(label) + ">";
  } else
    *label = 0;
  return std::move(addrText);
}

QString HexDumpFile::makeCopyText() {
  dsint deltaRowBase = getSelectionStart() % getBytePerRowCount() + mByteOffset;
  if (deltaRowBase >= getBytePerRowCount())
    deltaRowBase -= getBytePerRowCount();
  auto curRow = getSelectionStart() - deltaRowBase;
  QString result;
  while (curRow <= getSelectionEnd()) {
    for (int col = 0; col < getColumnCount(); col++) {
      if (col) result += " ";
      RichTextPainter::List richText;
      getColumnRichText(col, curRow, richText);
      QString colText;
      for (auto& r : richText) colText += r.text;
      if (col + 1 == getColumnCount())
        result += colText;
      else
        result += colText.leftJustified(getColumnWidth(col) / getCharWidth(),
                                        QChar(' '), true);
    }
    curRow += getBytePerRowCount();
    result += "\n";
  }
  return std::move(result);
}

void HexDumpFile::setupCopyMenu() {
  // Copy -> Data
  mCopySelection =
      new QAction(DIcon("copy_selection.png"), tr("&Selected lines"), this);
  connect(mCopySelection, SIGNAL(triggered(bool)), this,
          SLOT(copySelectionSlot()));
  mCopySelection->setShortcutContext(Qt::WidgetShortcut);
  addAction(mCopySelection);

  // Copy -> Address
  mCopyAddress = new QAction(DIcon("copy_address.png"), tr("&Address"), this);
  connect(mCopyAddress, SIGNAL(triggered()), this, SLOT(copyAddressSlot()));
  mCopyAddress->setShortcutContext(Qt::WidgetShortcut);
  addAction(mCopyAddress);

  // Copy -> RVA
  mCopyRva = new QAction(DIcon("copy_address.png"), "&RVA", this);
  connect(mCopyRva, SIGNAL(triggered()), this, SLOT(copyRvaSlot()));
  mCopyRva->setShortcutContext(Qt::WidgetShortcut);
  addAction(mCopyRva);
}

void HexDumpFile::copyAddressSlot() {
  QString addrText = ToPtrString(rvaToVa(getInitialSelection()));
  Bridge::CopyToClipboard(addrText);
}

void HexDumpFile::copyRvaSlot() {
  duint addr = rvaToVa(getInitialSelection());
  duint base = DbgFunctions()->ModBaseFromAddr(addr);
  if (base) {
    QString addrText = ToHexString(addr - base);
    Bridge::CopyToClipboard(addrText);
  } else
    QMessageBox::warning(this, tr("Error!"),
                         tr("Selection not in a module..."));
}

void HexDumpFile::mouseMoveEvent(QMouseEvent* event) {
  bool wAccept = true;

  int x = event->x();
  int y = event->y();

  if (mGuiState == HexDumpFile::MultiRowsSelectionState) {
    // qDebug() << "State = MultiRowsSelectionState";

    if ((transY(y) >= 0) && y <= this->height()) {
      int wColIndex = getColumnIndexFromX(x);

      if (mForceColumn != -1) {
        wColIndex = mForceColumn;
        x = getColumnPosition(mForceColumn) + 1;
      }

      if (wColIndex > 0)  // No selection for first column (addresses)
      {
        dsint wStartingAddress = getItemStartingAddress(x, y);
        dsint dataSize =
            getSizeOf(mDescriptor.at(wColIndex - 1).data.itemSize) - 1;
        dsint wEndingAddress = wStartingAddress + dataSize;

        if (wEndingAddress < (dsint)mMemPage->getSize()) {
          if (wStartingAddress < getInitialSelection()) {
            expandSelectionUpTo(wStartingAddress);
            mSelection.toIndex += dataSize;
            emit selectionUpdated();
          } else
            expandSelectionUpTo(wEndingAddress);

          mGuiState = HexDumpFile::MultiRowsSelectionState;

          updateViewport();
        }
      } else {
        dsint wStartingAddress =
            getItemStartingAddress(getColumnPosition(1) + 1, y);
        dsint dataSize = getSizeOf(mDescriptor.at(0).data.itemSize) *
                             mDescriptor.at(0).itemCount -
                         1;
        dsint wEndingAddress = wStartingAddress + dataSize;

        if (wEndingAddress < (dsint)mMemPage->getSize()) {
          if (wStartingAddress < getInitialSelection()) {
            expandSelectionUpTo(wStartingAddress);
            mSelection.toIndex += dataSize;
            emit selectionUpdated();
          } else
            expandSelectionUpTo(wEndingAddress);

          mGuiState = HexDumpFile::MultiRowsSelectionState;

          updateViewport();
        }
      }

      wAccept = true;
    } else if (y > this->height() &&
               mGuiState == HexDumpFile::MultiRowsSelectionState) {
      verticalScrollBar()->triggerAction(QAbstractSlider::SliderSingleStepAdd);
    } else if (transY(y) < 0 &&
               mGuiState == HexDumpFile::MultiRowsSelectionState) {
      verticalScrollBar()->triggerAction(QAbstractSlider::SliderSingleStepSub);
    }
  }

  if (wAccept == true) AbstractTableView::mouseMoveEvent(event);
}

void HexDumpFile::mousePressEvent(QMouseEvent* event) {
  if (event->buttons() == Qt::MiddleButton)  // copy address to clipboard
  {
    if (!DbgIsDebugging()) return;
    MessageBeep(MB_OK);
    QString addrText = ToPtrString(rvaToVa(getInitialSelection()));
    Bridge::CopyToClipboard(addrText);
    return;
  }
  // qDebug() << "HexDumpFile::mousePressEvent";

  int x = event->x();
  int y = event->y();

  bool wAccept = false;

  if (((event->buttons() & Qt::LeftButton) != 0) &&
      ((event->buttons() & Qt::RightButton) == 0)) {
    if (getGuiState() == AbstractTableView::NoState) {
      if (y > getHeaderHeight() && y <= this->height()) {
        int wColIndex = getColumnIndexFromX(x);

        if (mForceColumn != -1) {
          wColIndex = mForceColumn;
          x = getColumnPosition(mForceColumn) + 1;
        }

        if (wColIndex > 0 && mDescriptor.at(wColIndex - 1).isData ==
                                 true)  // No selection for first column
                                        // (addresses) and no data columns
        {
          dsint wStartingAddress = getItemStartingAddress(x, y);
          dsint dataSize =
              getSizeOf(mDescriptor.at(wColIndex - 1).data.itemSize) - 1;
          dsint wEndingAddress = wStartingAddress + dataSize;

          if (wEndingAddress < (dsint)mMemPage->getSize()) {
            bool bUpdateTo = false;
            if (!(event->modifiers() & Qt::ShiftModifier))
              setSingleSelection(wStartingAddress);
            else if (getInitialSelection() > wEndingAddress) {
              wEndingAddress -= dataSize;
              bUpdateTo = true;
            }
            expandSelectionUpTo(wEndingAddress);
            if (bUpdateTo) {
              mSelection.toIndex += dataSize;
              emit selectionUpdated();
            }

            mGuiState = HexDumpFile::MultiRowsSelectionState;

            updateViewport();
          }
        } else if (wColIndex == 0) {
          dsint wStartingAddress =
              getItemStartingAddress(getColumnPosition(1) + 1, y);
          dsint dataSize = getSizeOf(mDescriptor.at(0).data.itemSize) *
                               mDescriptor.at(0).itemCount -
                           1;
          dsint wEndingAddress = wStartingAddress + dataSize;

          if (wEndingAddress < (dsint)mMemPage->getSize()) {
            bool bUpdateTo = false;
            if (!(event->modifiers() & Qt::ShiftModifier))
              setSingleSelection(wStartingAddress);
            else if (getInitialSelection() > wEndingAddress) {
              wEndingAddress -= dataSize;
              bUpdateTo = true;
            }
            expandSelectionUpTo(wEndingAddress);
            if (bUpdateTo) {
              mSelection.toIndex += dataSize;
              emit selectionUpdated();
            }

            mGuiState = HexDumpFile::MultiRowsSelectionState;

            updateViewport();
          }
        }

        wAccept = true;
      }
    }
  }

  if (wAccept == false) AbstractTableView::mousePressEvent(event);
}

void HexDumpFile::mouseReleaseEvent(QMouseEvent* event) {
  bool wAccept = true;

  if ((event->buttons() & Qt::LeftButton) == 0) {
    if (mGuiState == HexDumpFile::MultiRowsSelectionState) {
      mGuiState = HexDumpFile::NoState;

      updateViewport();

      wAccept = false;
    }
  }
  if ((event->button() & Qt::BackButton) != 0)  // Go to previous/next history
  {
    wAccept = true;
    printDumpAt(mHistory.historyPrev());
  } else if ((event->button() & Qt::ForwardButton) != 0) {
    wAccept = true;
    printDumpAt(mHistory.historyNext());
  }

  if (wAccept == true) AbstractTableView::mouseReleaseEvent(event);
}

void HexDumpFile::keyPressEvent(QKeyEvent* event) {
  int key = event->key();
  dsint selStart = getInitialSelection();
  char granularity = 1;  // Size of a data word.
  char action = 0;       // Where to scroll the scrollbar
  Qt::KeyboardModifiers modifiers = event->modifiers();
  for (int i = 0; i < mDescriptor.size(); i++)  // Find the first data column
  {
    if (mDescriptor.at(i).isData) {
      granularity = getSizeOf(mDescriptor.at(i).data.itemSize);
      break;
    }
  }
  if (modifiers == 0)  // No modifier
  {
    // selStart -= selStart % granularity; //Align the selection to word
    // boundary. TODO: Unaligned data?
    switch (key) {
      case Qt::Key_Left: {
        selStart -= granularity;
        if (0 <= selStart) action = -1;
      } break;
      case Qt::Key_Right: {
        selStart += granularity;
        if (mMemPage->getSize() > selStart) action = 1;
      } break;
      case Qt::Key_Up: {
        selStart -= getBytePerRowCount();
        if (0 <= selStart) action = -1;
      } break;
      case Qt::Key_Down: {
        selStart += getBytePerRowCount();
        if (mMemPage->getSize() > selStart) action = 1;
      } break;
      default:
        AbstractTableView::keyPressEvent(event);
    }

    if (action != 0) {
      // Check if selection is out of viewport. Step the scrollbar if necessary.
      // (TODO)
      if (action == 1 &&
          selStart >= getViewableRowsCount() * getBytePerRowCount() +
                          getTableOffsetRva())
        verticalScrollBar()->triggerAction(
            QAbstractSlider::SliderSingleStepAdd);
      else if (action == -1 && selStart < getTableOffsetRva())
        verticalScrollBar()->triggerAction(
            QAbstractSlider::SliderSingleStepSub);
      setSingleSelection(selStart);
      if (granularity > 1) expandSelectionUpTo(selStart + granularity - 1);
      reloadData();
    }
  } else if (modifiers == Qt::ControlModifier ||
             modifiers == (Qt::ControlModifier | Qt::AltModifier)) {
    duint offsetVa = rvaToVa(getTableOffsetRva());
    switch (key) {
      case Qt::Key_Left:
        action = (modifiers & Qt::AltModifier) ? -1 : -granularity;
        break;
      case Qt::Key_Right:
        action = (modifiers & Qt::AltModifier) ? 1 : granularity;
        break;
      case Qt::Key_Up:
        action = 0;
        verticalScrollBar()->triggerAction(
            QAbstractSlider::SliderSingleStepSub);
        break;
      case Qt::Key_Down:
        action = 0;
        verticalScrollBar()->triggerAction(
            QAbstractSlider::SliderSingleStepAdd);
        break;
    }
    if (action != 0) {
      offsetVa += action;
      if (mMemPage->inRange(offsetVa)) printDumpAt(offsetVa, false);
    }
  } else if (modifiers == Qt::ShiftModifier) {
    // TODO
  }
  /*
      Let's keep the old code for a while until nobody remembers previous
     behaviour. if(key == Qt::Key_Left || (key == Qt::Key_Up && control))
     //TODO: see if Ctrl+Up is redundant
      {
          duint offsetVa = rvaToVa(getTableOffsetRva()) - 1;
          if(mMemPage->inRange(offsetVa))
              printDumpAt(offsetVa, false);
      }
      else if(key == Qt::Key_Right || (key == Qt::Key_Down && control)) //TODO:
     see if Ctrl+Down is redundant
      {
          duint offsetVa = rvaToVa(getTableOffsetRva()) + 1;
          if(mMemPage->inRange(offsetVa))
              printDumpAt(offsetVa, false);
      }
      else
          AbstractTableView::keyPressEvent(event);
  */
}

QString HexDumpFile::paintContent(QPainter* painter, dsint rowBase,
                                  int rowOffset, int col, int x, int y, int w,
                                  int h) {
  // Reset byte offset when base address is reached
  if (rowBase == 0 && mByteOffset != 0)
    printDumpAt(mMemPage->getBase(), false, false);

  // Compute RVA
  int wBytePerRowCount = getBytePerRowCount();
  dsint wRva = (rowBase + rowOffset) * wBytePerRowCount - mByteOffset;

  if (col && mDescriptor.at(col - 1).isData)
    printSelected(painter, rowBase, rowOffset, col, x, y, w, h);

  RichTextPainter::List richText;
  getColumnRichText(col, wRva, richText);
  RichTextPainter::paintRichText(painter, x, y, w, h, 4, richText,
                                 mFontMetrics);

  return QString();
}

void HexDumpFile::printSelected(QPainter* painter, dsint rowBase, int rowOffset,
                                int col, int x, int y, int w, int h) {
  if ((col > 0) && ((col - 1) < mDescriptor.size())) {
    ColumnDescriptor curDescriptor = mDescriptor.at(col - 1);
    int wBytePerRowCount = getBytePerRowCount();
    dsint wRva = (rowBase + rowOffset) * wBytePerRowCount - mByteOffset;
    int wItemPixWidth = getItemPixelWidth(curDescriptor);
    int wCharWidth = getCharWidth();
    if (wItemPixWidth == wCharWidth) x += 4;

    for (int i = 0; i < curDescriptor.itemCount; i++) {
      int wSelectionX = x + i * wItemPixWidth;
      if (isSelected(wRva + i * getSizeOf(curDescriptor.data.itemSize)) ==
          true) {
        int wSelectionWidth = wItemPixWidth > w - (wSelectionX - x)
                                  ? w - (wSelectionX - x)
                                  : wItemPixWidth;
        wSelectionWidth = wSelectionWidth < 0 ? 0 : wSelectionWidth;
        painter->setPen(mTextColor);
        painter->fillRect(QRect(wSelectionX, y, wSelectionWidth, h),
                          QBrush(mSelectionColor));
      }
      int separator = curDescriptor.separator;
      if (i && separator && !(i % separator)) {
        painter->setPen(mSeparatorColor);
        painter->drawLine(wSelectionX, y, wSelectionX, y + h);
      }
    }
  }
}

/************************************************************************************
                                Selection Management
************************************************************************************/
void HexDumpFile::expandSelectionUpTo(dsint rva) {
  if (rva < mSelection.firstSelectedIndex) {
    mSelection.fromIndex = rva;
    mSelection.toIndex = mSelection.firstSelectedIndex;
    emit selectionUpdated();
  } else if (rva > mSelection.firstSelectedIndex) {
    mSelection.fromIndex = mSelection.firstSelectedIndex;
    mSelection.toIndex = rva;
    emit selectionUpdated();
  } else if (rva == mSelection.firstSelectedIndex) {
    setSingleSelection(rva);
  }
}

void HexDumpFile::setSingleSelection(dsint rva) {
  mSelection.firstSelectedIndex = rva;
  mSelection.fromIndex = rva;
  mSelection.toIndex = rva;
  emit selectionUpdated();
}

dsint HexDumpFile::getInitialSelection() const {
  return mSelection.firstSelectedIndex;
}

dsint HexDumpFile::getSelectionStart() const { return mSelection.fromIndex; }

dsint HexDumpFile::getSelectionEnd() const { return mSelection.toIndex; }

bool HexDumpFile::isSelected(dsint rva) const {
  return rva >= mSelection.fromIndex && rva <= mSelection.toIndex;
}

void HexDumpFile::getColumnRichText(int col, dsint rva,
                                    RichTextPainter::List& richText) {
  RichTextPainter::CustomRichText_t curData;
  curData.underline = false;
  curData.flags = RichTextPainter::FlagAll;
  curData.textColor = mTextColor;
  curData.textBackground = Qt::transparent;
  curData.underlineColor = Qt::transparent;

  RichTextPainter::CustomRichText_t spaceData;
  spaceData.underline = false;
  spaceData.flags = RichTextPainter::FlagNone;
  spaceData.underlineColor = Qt::transparent;

  if (!col)  // address
  {
    curData.text = makeAddrText(rvaToVa(rva));
    richText.push_back(curData);
  } else if (mDescriptor.at(col - 1).isData == true) {
    const ColumnDescriptor& desc = mDescriptor.at(col - 1);
    int wI;

    int wByteCount = getSizeOf(desc.data.itemSize);
    int wBufferByteCount = desc.itemCount * wByteCount;

    wBufferByteCount = wBufferByteCount > (dsint)(mMemPage->getSize() - rva)
                           ? mMemPage->getSize() - rva
                           : wBufferByteCount;

    byte_t* wData = (byte_t*)mMemPage->read(rva, wBufferByteCount);

    if (desc.textCodec)  // convert the row bytes to unicode
    {
      // This might produce invalid characters in variables-width encodings.
      // This is currently ignored.
      curData.text = desc.textCodec->toUnicode(
          QByteArray((const char*)wData, wBufferByteCount));
      curData.text.replace('\t', "\\t");
      curData.text.replace('\f', "\\f");
      curData.text.replace('\v', "\\v");
      curData.text.replace('\n', "\\n");
      curData.text.replace('\r', "\\r");
      richText.push_back(curData);
    } else {
      for (wI = 0;
           wI < desc.itemCount && (rva + wI) < (dsint)mMemPage->getSize();
           wI++) {
        curData.text.clear();
        curData.textColor = mTextColor;
        curData.textBackground = Qt::transparent;
        curData.flags = RichTextPainter::FlagAll;

        int maxLen = getStringMaxLength(desc.data);
        if ((rva + wI + wByteCount - 1) < (dsint)mMemPage->getSize()) {
          toString(desc.data, rva + wI * wByteCount, wData + wI * wByteCount,
                   curData);
          if (curData.text.length() < maxLen) {
            spaceData.text =
                QString(' ').repeated(maxLen - curData.text.length());
            richText.push_back(spaceData);
          }
          if (wI % sizeof(duint) == 0 && wByteCount == 1 &&
              desc.data.byteMode == HexByte)  // pointer underlining
          {
            auto ptr = *(duint*)(wData + wI * wByteCount);
            if (spaceData.underline = curData.underline =
                    DbgMemIsValidReadPtr(ptr)) {
              auto codePage =
                  false;         // DbgFunctions()->MemIsCodePage(ptr, false);
              auto modbase = 0;  // DbgFunctions()->ModBaseFromAddr(ptr);
              if (modbase) {
                if (DbgFunctions()->ModGetParty(modbase) == 1)  // system
                  spaceData.underlineColor = curData.underlineColor =
                      codePage ? mSystemModuleCodePointerHighlightColor
                               : mSystemModuleDataPointerHighlightColor;
                else  // user
                  spaceData.underlineColor = curData.underlineColor =
                      codePage ? mUserModuleCodePointerHighlightColor
                               : mUserModuleDataPointerHighlightColor;
              } else
                spaceData.underlineColor = curData.underlineColor =
                    codePage ? mUnknownCodePointerHighlightColor
                             : mUnknownDataPointerHighlightColor;
            }
          }
          richText.push_back(curData);
          if (maxLen) {
            spaceData.text = QString(' ');
            if (wI % sizeof(duint) == sizeof(duint) - 1)
              spaceData.underline = false;
            richText.push_back(spaceData);
          }
        } else {
          curData.text = QString("?").rightJustified(maxLen, ' ');
          if (maxLen) curData.text.append(' ');
          richText.push_back(curData);
        }
      }
    }
  }
}

void HexDumpFile::toString(
    DataDescriptor desc, duint rva, byte_t* data,
    RichTextPainter::CustomRichText_t& richText)  // convert data to string
{
  switch (desc.itemSize) {
    case Byte: {
      byteToString(rva, *((byte_t*)data), desc.byteMode, richText);
    } break;

    case Word: {
      wordToString(rva, *((uint16*)data), desc.wordMode, richText);
    } break;

    case Dword: {
      dwordToString(rva, *((uint32*)data), desc.dwordMode, richText);
    } break;

    case Qword: {
      qwordToString(rva, *((uint64*)data), desc.qwordMode, richText);
    } break;

    case Tword: {
      twordToString(rva, data, desc.twordMode, richText);
    } break;

    default: {
    } break;
  }

  if (desc.itemSize == Byte)  // byte patches are handled in byteToString
    return;

  dsint start = rvaToVa(rva);
  dsint end = start + getSizeOf(desc.itemSize) - 1;
}

void HexDumpFile::byteToString(duint rva, byte_t byte, ByteViewMode mode,
                               RichTextPainter::CustomRichText_t& richText) {
  QString wStr = "";

  switch (mode) {
    case HexByte: {
      wStr = ToByteString((unsigned char)byte);
    } break;

    case AsciiByte: {
      QChar wChar = QChar::fromLatin1((char)byte);

      if (wChar.isPrint())
        wStr = QString(wChar);
      else if (!wChar.unicode())
        wStr = mNullReplace;
      else
        wStr = mNonprintReplace;
    } break;

    case SignedDecByte: {
      wStr = QString::number((int)((char)byte));
    } break;

    case UnsignedDecByte: {
      wStr = QString::number((unsigned int)byte);
    } break;

    default: {
    } break;
  }

  richText.text = wStr;

  DBGPATCHINFO patchInfo;
  if (0 && DbgFunctions()->PatchGetEx(rvaToVa(rva), &patchInfo)) {
    if (byte == patchInfo.newbyte) {
      richText.textColor = mModifiedBytesColor;
      richText.textBackground = mModifiedBytesBackgroundColor;
    } else {
      richText.textColor = mRestoredBytesColor;
      richText.textBackground = mRestoredBytesBackgroundColor;
    }
  } else {
    switch (byte) {
      case 0x00:
        richText.textColor = mByte00Color;
        richText.textBackground = mByte00BackgroundColor;
        break;
      case 0x7F:
        richText.textColor = mByte7FColor;
        richText.textBackground = mByte7FBackgroundColor;
        break;
      case 0xFF:
        richText.textColor = mByteFFColor;
        richText.textBackground = mByteFFBackgroundColor;
        break;
      default:
        if (isprint(byte) || isspace(byte)) {
          richText.textColor = mByteIsPrintColor;
          richText.textBackground = mByteIsPrintBackgroundColor;
        }
        break;
    }
  }
}

void HexDumpFile::wordToString(duint rva, uint16 word, WordViewMode mode,
                               RichTextPainter::CustomRichText_t& richText) {
  Q_UNUSED(rva);
  QString wStr;

  switch (mode) {
    case HexWord: {
      wStr = ToWordString((unsigned short)word);
    } break;

    case UnicodeWord: {
      QChar wChar = QChar::fromLatin1((char)word & 0xFF);
      if (wChar.isPrint() && (word >> 8) == 0)
        wStr = QString(wChar);
      else if (!wChar.unicode())
        wStr = mNullReplace;
      else
        wStr = mNonprintReplace;
    } break;

    case SignedDecWord: {
      wStr = QString::number((int)((short)word));
    } break;

    case UnsignedDecWord: {
      wStr = QString::number((unsigned int)word);
    } break;

    default: {
    } break;
  }

  richText.text = wStr;
}

void HexDumpFile::dwordToString(duint rva, uint32 dword, DwordViewMode mode,
                                RichTextPainter::CustomRichText_t& richText) {
  Q_UNUSED(rva);
  QString wStr;

  switch (mode) {
    case HexDword: {
      wStr =
          QString("%1").arg((unsigned int)dword, 8, 16, QChar('0')).toUpper();
    } break;

    case SignedDecDword: {
      wStr = QString::number((int)dword);
    } break;

    case UnsignedDecDword: {
      wStr = QString::number((unsigned int)dword);
    } break;

    case FloatDword: {
      wStr = ToFloatString(&dword);
    } break;

    default: {
    } break;
  }

  richText.text = wStr;
}

void HexDumpFile::qwordToString(duint rva, uint64 qword, QwordViewMode mode,
                                RichTextPainter::CustomRichText_t& richText) {
  Q_UNUSED(rva);
  QString wStr;

  switch (mode) {
    case HexQword: {
      wStr = QString("%1")
                 .arg((unsigned long long)qword, 16, 16, QChar('0'))
                 .toUpper();
    } break;

    case SignedDecQword: {
      wStr = QString::number((long long)qword);
    } break;

    case UnsignedDecQword: {
      wStr = QString::number((unsigned long long)qword);
    } break;

    case DoubleQword: {
      wStr = ToDoubleString(&qword);
    } break;

    default: {
    } break;
  }

  richText.text = wStr;
}

void HexDumpFile::twordToString(duint rva, void* tword, TwordViewMode mode,
                                RichTextPainter::CustomRichText_t& richText) {
  Q_UNUSED(rva);
  QString wStr;

  switch (mode) {
    case FloatTword: {
      wStr = ToLongDoubleString(tword);
    } break;

    default: {
    } break;
  }

  richText.text = wStr;
}

int HexDumpFile::getSizeOf(DataSize size) { return int(size); }

static int getStringMaxLength(HexDumpFile::DataDescriptor desc) {
  int wLength = 0;

  switch (desc.itemSize) {
    case HexDumpFile::Byte: {
      wLength = byteStringMaxLength(desc.byteMode);
    } break;

    case HexDumpFile::Word: {
      wLength = wordStringMaxLength(desc.wordMode);
    } break;

    case HexDumpFile::Dword: {
      wLength = dwordStringMaxLength(desc.dwordMode);
    } break;

    case HexDumpFile::Qword: {
      wLength = qwordStringMaxLength(desc.qwordMode);
    } break;

    case HexDumpFile::Tword: {
      wLength = twordStringMaxLength(desc.twordMode);
    } break;

    default: {
    } break;
  }

  return wLength;
}

static int byteStringMaxLength(HexDumpFile::ByteViewMode mode) {
  int wLength = 0;

  switch (mode) {
    case HexDumpFile::HexByte: {
      wLength = 2;
    } break;

    case HexDumpFile::AsciiByte: {
      wLength = 0;
    } break;

    case HexDumpFile::SignedDecByte: {
      wLength = 4;
    } break;

    case HexDumpFile::UnsignedDecByte: {
      wLength = 3;
    } break;

    default: {
    } break;
  }

  return wLength;
}

static int wordStringMaxLength(HexDumpFile::WordViewMode mode) {
  int wLength = 0;

  switch (mode) {
    case HexDumpFile::HexWord: {
      wLength = 4;
    } break;

    case HexDumpFile::UnicodeWord: {
      wLength = 0;
    } break;

    case HexDumpFile::SignedDecWord: {
      wLength = 6;
    } break;

    case HexDumpFile::UnsignedDecWord: {
      wLength = 5;
    } break;

    default: {
    } break;
  }

  return wLength;
}

static int dwordStringMaxLength(HexDumpFile::DwordViewMode mode) {
  int wLength = 0;

  switch (mode) {
    case HexDumpFile::HexDword: {
      wLength = 8;
    } break;

    case HexDumpFile::SignedDecDword: {
      wLength = 11;
    } break;

    case HexDumpFile::UnsignedDecDword: {
      wLength = 10;
    } break;

    case HexDumpFile::FloatDword: {
      wLength = 13;
    } break;

    default: {
    } break;
  }

  return wLength;
}

static int qwordStringMaxLength(HexDumpFile::QwordViewMode mode) {
  int wLength = 0;

  switch (mode) {
    case HexDumpFile::HexQword: {
      wLength = 16;
    } break;

    case HexDumpFile::SignedDecQword: {
      wLength = 20;
    } break;

    case HexDumpFile::UnsignedDecQword: {
      wLength = 20;
    } break;

    case HexDumpFile::DoubleQword: {
      wLength = 23;
    } break;

    default: {
    } break;
  }

  return wLength;
}

static int twordStringMaxLength(HexDumpFile::TwordViewMode mode) {
  int wLength = 0;

  switch (mode) {
    case HexDumpFile::FloatTword: {
      wLength = 29;
    } break;

    default: {
    } break;
  }

  return wLength;
}

int HexDumpFile::getItemIndexFromX(int x) const {
  int wColIndex = getColumnIndexFromX(x);

  if (wColIndex > 0) {
    int wColStartingPos = getColumnPosition(wColIndex);
    int wRelativeX = x - wColStartingPos;

    int wItemPixWidth = getItemPixelWidth(mDescriptor.at(wColIndex - 1));
    int wCharWidth = getCharWidth();
    if (wItemPixWidth == wCharWidth) wRelativeX -= 4;

    int wItemIndex = wRelativeX / wItemPixWidth;

    wItemIndex = wItemIndex < 0 ? 0 : wItemIndex;
    wItemIndex = wItemIndex > (mDescriptor.at(wColIndex - 1).itemCount - 1)
                     ? (mDescriptor.at(wColIndex - 1).itemCount - 1)
                     : wItemIndex;

    return wItemIndex;
  } else {
    return 0;
  }
}

dsint HexDumpFile::getItemStartingAddress(int x, int y) {
  int wRowOffset = getIndexOffsetFromY(transY(y));
  int wItemIndex = getItemIndexFromX(x);
  int wColIndex = getColumnIndexFromX(x);
  dsint wStartingAddress = 0;

  if (wColIndex > 0) {
    wColIndex -= 1;
    wStartingAddress =
        (getTableOffset() + wRowOffset) *
            (mDescriptor.at(wColIndex).itemCount *
             getSizeOf(mDescriptor.at(wColIndex).data.itemSize)) +
        wItemIndex * getSizeOf(mDescriptor.at(wColIndex).data.itemSize) -
        mByteOffset;
  }

  return wStartingAddress;
}

int HexDumpFile::getBytePerRowCount() const {
  return mDescriptor.at(0).itemCount *
         getSizeOf(mDescriptor.at(0).data.itemSize);
}

int HexDumpFile::getItemPixelWidth(ColumnDescriptor desc) const {
  int wCharWidth = getCharWidth();
  int wItemPixWidth = getStringMaxLength(desc.data) * wCharWidth + wCharWidth;

  return wItemPixWidth;
}

void HexDumpFile::appendDescriptor(int width, QString title, bool clickable,
                                   ColumnDescriptor descriptor) {
  addColumnAt(width, title, clickable);
  mDescriptor.append(descriptor);
}

// Clears the descriptors, append a new descriptor and fix the tableOffset (use
// this instead of clearDescriptors()
void HexDumpFile::appendResetDescriptor(int width, QString title,
                                        bool clickable,
                                        ColumnDescriptor descriptor) {
  setAllowPainting(false);
  if (mDescriptor.size()) {
    dsint wRVA = getTableOffset() * getBytePerRowCount() - mByteOffset;
    clearDescriptors();
    appendDescriptor(width, title, clickable, descriptor);
    printDumpAt(rvaToVa(wRVA), true, false);
  } else
    appendDescriptor(width, title, clickable, descriptor);
  setAllowPainting(true);
}

void HexDumpFile::clearDescriptors() {
  deleteAllColumns();
  mDescriptor.clear();
  int charwidth = getCharWidth();
  addColumnAt(8 + charwidth * 2 * sizeof(duint), tr("Address"),
              false);  // address
}

void HexDumpFile::debugStateChanged(DBGSTATE state) {
  if (state == stopped) {
    mMemPage->setAttributes(0, 0);
    setRowCount(0);
    reloadData();
  }
}
