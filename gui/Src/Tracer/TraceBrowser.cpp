#include "TraceBrowser.h"

#include <QFileDialog>

#include "BreakpointMenu.h"
#include "BrowseDialog.h"
#include "CachedFontMetrics.h"
#include "GotoDialog.h"
#include "LineEditDialog.h"
#include "MRUList.h"
#include "QBeaEngine.h"
#include "RichTextPainter.h"
#include "TraceFileReader.h"
#include "TraceFileSearch.h"
#include "WordEditDialog.h"
#include "main.h"
#include "SimpleTraceDialog.h"
#include "../bridge/_global.h"

#ifndef strcpy_s
#define strcpy_s strcpy
#endif

#ifndef PlaySoundA
#define PlaySoundA(...)
#endif

TraceBrowser::TraceBrowser(QWidget* parent) : AbstractTableView(parent) {
  mTraceFile = nullptr;
  addColumnAt(getCharWidth() * 2 * 2 + 8, "", false);              // index
  addColumnAt(getCharWidth() * 2 * sizeof(dsint) + 8, "", false);  // address
  addColumnAt(getCharWidth() * 2 * 12 + 8, "", false);             // bytes
  addColumnAt(getCharWidth() * 40, "", false);  // disassembly
  addColumnAt(getCharWidth() * 50, "", false);  // registers
  addColumnAt(getCharWidth() * 50, "", false);  // memory
  addColumnAt(1000, "", false);                 // comments
  loadColumnFromConfig("Trace");

  setShowHeader(false);  // hide header

  mSelection.firstSelectedIndex = 0;
  mSelection.fromIndex = 0;
  mSelection.toIndex = 0;
  setRowCount(0);
  mRvaDisplayBase = 0;
  mRvaDisplayEnabled = false;

  mAutoDisassemblyFollowSelection = false;

  mHighlightingMode = false;
  mPermanentHighlightingMode = false;
  mShowMnemonicBrief = false;

  mMRUList = new MRUList(this, "Recent Trace Files");
  connect(mMRUList, SIGNAL(openFile(QString)), this, SLOT(openSlot(QString)));
  mMRUList->load();

  setupRightClickContextMenu();

  Initialize();

  connect(Bridge::getBridge(), SIGNAL(updateTraceBrowser()), this,
          SLOT(updateSlot()));
  connect(Bridge::getBridge(), SIGNAL(openTraceFile(const QString&)), this,
          SLOT(openSlot(const QString&)));
  connect(Config(), SIGNAL(tokenizerConfigUpdated()), this,
          SLOT(tokenizerConfigUpdatedSlot()));
}

TraceBrowser::~TraceBrowser() {
  if (mTraceFile) {
    mTraceFile->Close();
    delete mTraceFile;
  }
}

bool TraceBrowser::isFileOpened() const {
  return mTraceFile && mTraceFile->Progress() == 100 &&
         mTraceFile->Length() > 0;
}

QString TraceBrowser::getAddrText(dsint cur_addr, char label[MAX_LABEL_SIZE],
                                  bool getLabel) {
  QString addrText = "";
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
  char label_[MAX_LABEL_SIZE] = "";
  if (getLabel && DbgGetLabelAt(cur_addr, SEG_DEFAULT, label_))  // has label
  {
    char module[MAX_MODULE_SIZE] = "";
    if (DbgGetModuleAt(cur_addr, module) &&
        !QString(label_).startsWith("JMP.&"))
      addrText += " <" + QString(module) + "." + QString(label_) + ">";
    else
      addrText += " <" + QString(label_) + ">";
  } else
    *label_ = 0;
  if (label) strcpy_s(label, label_);
  return addrText;
}

// The following function is modified from "RichTextPainter::List
// Disassembly::getRichBytes(const Instruction_t & instr) const" with patch and
// code folding features removed.
RichTextPainter::List TraceBrowser::getRichBytes(
    const Instruction_t& instr) const {
  RichTextPainter::List richBytes;
  std::vector<std::pair<size_t, bool>> realBytes;
  formatOpcodeString(instr, richBytes, realBytes);
  const duint cur_addr = instr.rva;

  if (!richBytes.empty() && richBytes.back().text.endsWith(' '))
    richBytes.back().text.chop(1);  // remove trailing space if exists

  for (size_t i = 0; i < richBytes.size(); i++) {
    auto byteIdx = realBytes[i].first;
    auto isReal = realBytes[i].second;
    RichTextPainter::CustomRichText_t& curByte = richBytes.at(i);
    DBGRELOCATIONINFO relocInfo;
    curByte.underlineColor = mDisassemblyRelocationUnderlineColor;
    if (DbgIsDebugging() &&
        DbgFunctions()->ModRelocationAtAddr(cur_addr + byteIdx, &relocInfo)) {
      bool prevInSameReloc =
          relocInfo.rva <
          cur_addr + byteIdx -
              DbgFunctions()->ModBaseFromAddr(cur_addr + byteIdx);
      curByte.underline = isReal;
      curByte.underlineConnectPrev = i > 0 && prevInSameReloc;
    } else {
      curByte.underline = false;
      curByte.underlineConnectPrev = false;
    }

    curByte.textColor = mBytesColor;
    curByte.textBackground = mBytesBackgroundColor;
  }
  return richBytes;
}

#define HANDLE_RANGE_TYPE(prefix, first, last)         \
  if (first == prefix##_BEGIN && last == prefix##_END) \
    first = prefix##_SINGLE;                           \
  if (last == prefix##_END && first != prefix##_SINGLE) first = last

/**
 * @brief       This method paints the graphic for functions/loops.
 *
 * @param[in]   painter     Pointer to the painter that allows painting by its
 * own
 * @param[in]   x           Rectangle x
 * @param[in]   y           Rectangle y
 * @param[in]   funcType    Type of drawing to make
 *
 * @return      Width of the painted data.
 */

int TraceBrowser::paintFunctionGraphic(QPainter* painter, int x, int y,
                                       Function_t funcType, bool loop) {
  if (loop && funcType == Function_none) return 0;
  if (loop)
    painter->setPen(mLoopPen);  // thick black line
  else
    painter->setPen(mFunctionPen);  // thick black line
  int height = getRowHeight();
  int x_add = 5;
  int y_add = 4;
  int end_add = 2;
  int line_width = 3;
  if (loop) {
    end_add = -1;
    x_add = 4;
  }
  switch (funcType) {
    case Function_single: {
      if (loop) y_add = height / 2 + 1;
      painter->drawLine(x + x_add + line_width, y + y_add, x + x_add,
                        y + y_add);
      painter->drawLine(x + x_add, y + y_add, x + x_add,
                        y + height - y_add - 1);
      if (loop) y_add = height / 2 - 1;
      painter->drawLine(x + x_add, y + height - y_add, x + x_add + line_width,
                        y + height - y_add);
    } break;

    case Function_start: {
      if (loop) y_add = height / 2 + 1;
      painter->drawLine(x + x_add + line_width, y + y_add, x + x_add,
                        y + y_add);
      painter->drawLine(x + x_add, y + y_add, x + x_add, y + height);
    } break;

    case Function_middle: {
      painter->drawLine(x + x_add, y, x + x_add, y + height);
    } break;

    case Function_loop_entry: {
      int trisize = 2;
      int y_start = (height - trisize * 2) / 2 + y;
      painter->drawLine(x + x_add, y_start, x + trisize + x_add,
                        y_start + trisize);
      painter->drawLine(x + trisize + x_add, y_start + trisize, x + x_add,
                        y_start + trisize * 2);

      painter->drawLine(x + x_add, y, x + x_add, y_start - 1);
      painter->drawLine(x + x_add, y_start + trisize * 2 + 2, x + x_add,
                        y + height);
    } break;

    case Function_end: {
      if (loop) y_add = height / 2 - 1;
      painter->drawLine(x + x_add, y, x + x_add, y + height - y_add);
      painter->drawLine(x + x_add, y + height - y_add, x + x_add + line_width,
                        y + height - y_add);
    } break;

    case Function_none: {
    } break;
  }
  return x_add + line_width + end_add;
}

QString TraceBrowser::paintContent(QPainter* painter, dsint rowBase,
                                   int rowOffset, int col, int x, int y, int w,
                                   int h) {
  if (!isFileOpened()) {
    return "";
  }
  if (mTraceFile->isError()) {
    GuiAddLogMessage(tr("An error occured when reading trace file.\r\n")
                         .toUtf8()
                         .constData());
    mTraceFile->Close();
    delete mTraceFile;
    mTraceFile = nullptr;
    setRowCount(0);
    return "";
  }
  if (mHighlightingMode) {
    QPen pen(mInstructionHighlightColor);
    pen.setWidth(2);
    painter->setPen(pen);
    QRect rect = viewport()->rect();
    rect.adjust(1, 1, -1, -1);
    painter->drawRect(rect);
  }

  duint index = rowBase + rowOffset;
  duint cur_addr;
  const REGDUMP *reg = mTraceFile->Registers(index);
  if (!reg) return "";

  cur_addr = regPCEx(reg);
  auto traceCount = DbgFunctions()->GetTraceRecordHitCount(cur_addr);
  bool wIsSelected =
      (index >= mSelection.fromIndex && index <= mSelection.toIndex);

  // Highlight if selected
  if (wIsSelected && traceCount)
    painter->fillRect(QRect(x, y, w, h),
                      QBrush(mTracedSelectedAddressBackgroundColor));
  else if (wIsSelected)
    painter->fillRect(QRect(x, y, w, h), QBrush(mSelectionColor));
  else if (traceCount) {
    // Color depending on how often a sequence of code is executed
    int exponent = 1;
    while (traceCount >>= 1)  // log2(traceCount)
      exponent++;
    int colorDiff = (exponent * exponent) / 2;

    // If the user has a light trace background color, substract
    if (mTracedAddressBackgroundColor.blue() > 160) colorDiff *= -1;

    painter->fillRect(
        QRect(x, y, w, h),
        QBrush(QColor(
            mTracedAddressBackgroundColor.red(),
            mTracedAddressBackgroundColor.green(),
            std::max(0, std::min(256, mTracedAddressBackgroundColor.blue() +
                                          colorDiff)))));
  }

  if (index >= mTraceFile->Length()) return "";

  const Instruction_t& inst = mTraceFile->Instruction(index);

  switch (static_cast<TableColumnIndex>(col)) {
    case Index: {
      return mTraceFile->getIndexText(index);
    }

    case Address: {
      QString addrText;
      char label[MAX_LABEL_SIZE] = "";
      if (!DbgIsDebugging()) {
        addrText = ToPtrString(cur_addr);
        // goto NotDebuggingLabel;
      } else
        addrText = getAddrText(cur_addr, label, true);
      BPXTYPE bpxtype = DbgGetBpxTypeAt(cur_addr);
      bool isbookmark = DbgGetBookmarkAt(nullptr, cur_addr);
      // todo: cip
      {
        if (!isbookmark)  // no bookmark
        {
          if (*label)  // label
          {
            if (bpxtype == bp_none)  // label only : fill label background
            {
              painter->setPen(mLabelColor);  // red -> address + label text
              painter->fillRect(
                  QRect(x, y, w, h),
                  QBrush(mLabelBackgroundColor));  // fill label background
            } else                                 // label + breakpoint
            {
              if (bpxtype & bp_normal)  // label + normal breakpoint
              {
                painter->setPen(mBreakpointColor);
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mBreakpointBackgroundColor));  // fill red
              } else if (bpxtype &
                         bp_hardware)  // label + hardware breakpoint only
              {
                painter->setPen(mHardwareBreakpointColor);
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mHardwareBreakpointBackgroundColor));  // fill ?
              } else  // other cases -> do as normal
              {
                painter->setPen(mLabelColor);  // red -> address + label text
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mLabelBackgroundColor));  // fill label background
              }
            }
          } else  // no label
          {
            if (bpxtype == bp_none)  // no label, no breakpoint
            {
            NotDebuggingLabel:
              QColor background;
              if (wIsSelected) {
                background = mSelectedAddressBackgroundColor;
                painter->setPen(
                    mSelectedAddressColor);  // black address
                                             // (DisassemblySelectedAddressColor)
              } else {
                background = mAddressBackgroundColor;
                painter->setPen(mAddressColor);  // DisassemblyAddressColor
              }
              if (background.alpha())
                painter->fillRect(QRect(x, y, w, h),
                                  QBrush(background));  // fill background
            } else                                      // breakpoint only
            {
              if (bpxtype & bp_normal)  // normal breakpoint
              {
                painter->setPen(mBreakpointColor);
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mBreakpointBackgroundColor));  // fill red
              } else if (bpxtype & bp_hardware)  // hardware breakpoint only
              {
                painter->setPen(mHardwareBreakpointColor);
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mHardwareBreakpointBackgroundColor));  // fill red
              } else  // other cases (memory breakpoint in disassembly) -> do as
                      // normal
              {
                QColor background;
                if (wIsSelected) {
                  background = mSelectedAddressBackgroundColor;
                  painter->setPen(
                      mSelectedAddressColor);  // black address
                                               // (DisassemblySelectedAddressColor)
                } else {
                  background = mAddressBackgroundColor;
                  painter->setPen(mAddressColor);
                }
                if (background.alpha())
                  painter->fillRect(QRect(x, y, w, h),
                                    QBrush(background));  // fill background
              }
            }
          }
        } else  // bookmark
        {
          if (*label)  // label + bookmark
          {
            if (bpxtype == bp_none)  // label + bookmark
            {
              painter->setPen(mLabelColor);  // red -> address + label text
              painter->fillRect(
                  QRect(x, y, w, h),
                  QBrush(mBookmarkBackgroundColor));  // fill label background
            } else  // label + breakpoint + bookmark
            {
              QColor color = mBookmarkBackgroundColor;
              if (!color.alpha())  // we don't want transparent text
                color = mAddressColor;
              painter->setPen(color);
              if (bpxtype & bp_normal)  // label + bookmark + normal breakpoint
              {
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mBreakpointBackgroundColor));  // fill red
              } else if (bpxtype & bp_hardware)  // label + bookmark + hardware
                                                 // breakpoint only
              {
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mHardwareBreakpointBackgroundColor));  // fill ?
              }
            }
          } else  // bookmark, no label
          {
            if (bpxtype == bp_none)  // bookmark only
            {
              painter->setPen(mBookmarkColor);  // black address
              painter->fillRect(
                  QRect(x, y, w, h),
                  QBrush(mBookmarkBackgroundColor));  // fill bookmark color
            } else                                    // bookmark + breakpoint
            {
              QColor color = mBookmarkBackgroundColor;
              if (!color.alpha())  // we don't want transparent text
                color = mAddressColor;
              painter->setPen(color);
              if (bpxtype & bp_normal)  // bookmark + normal breakpoint
              {
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mBreakpointBackgroundColor));  // fill red
              } else if (bpxtype &
                         bp_hardware)  // bookmark + hardware breakpoint only
              {
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mHardwareBreakpointBackgroundColor));  // fill red
              } else  // other cases (bookmark + memory breakpoint in
                      // disassembly) -> do as normal
              {
                painter->setPen(mBookmarkColor);  // black address
                painter->fillRect(
                    QRect(x, y, w, h),
                    QBrush(mBookmarkBackgroundColor));  // fill bookmark color
              }
            }
          }
        }
      }
      painter->drawText(QRect(x + 4, y, w - 4, h),
                        Qt::AlignVCenter | Qt::AlignLeft, addrText);
    }
      return "";

    case Opcode: {
      // draw functions
      Function_t funcType;
      FUNCTYPE funcFirst = DbgGetFunctionTypeAt(cur_addr);
      FUNCTYPE funcLast = DbgGetFunctionTypeAt(cur_addr + inst.length - 1);
      HANDLE_RANGE_TYPE(FUNC, funcFirst, funcLast);
      switch (funcFirst) {
        case FUNC_SINGLE:
          funcType = Function_single;
          break;
        case FUNC_NONE:
          funcType = Function_none;
          break;
        case FUNC_BEGIN:
          funcType = Function_start;
          break;
        case FUNC_MIDDLE:
          funcType = Function_middle;
          break;
        case FUNC_END:
          funcType = Function_end;
          break;
      }
      int funcsize = paintFunctionGraphic(painter, x, y, funcType, false);

      painter->setPen(mFunctionPen);

      XREFTYPE refType = DbgGetXrefTypeAt(cur_addr);
      char indicator;
      if (refType == XREF_JMP) {
        indicator = '>';
      } else if (refType == XREF_CALL) {
        indicator = '$';
      } else if (funcType != Function_none) {
        indicator = '.';
      } else {
        indicator = ' ';
      }

      int charwidth = getCharWidth();
      painter->drawText(QRect(x + funcsize, y, charwidth, h),
                        Qt::AlignVCenter | Qt::AlignLeft, QString(indicator));
      funcsize += charwidth;

      // draw jump arrows
      Instruction_t::BranchType branchType = inst.branchType;
      painter->setPen(mConditionalTruePen);
      int halfRow = getRowHeight() / 2 + 1;
      int jumpsize = 0;
      if ((branchType == Instruction_t::Conditional ||
           branchType == Instruction_t::Unconditional) &&
          index < mTraceFile->Length()) {
        duint next_addr;
        auto regptr = mTraceFile->Registers(index + 1);
        next_addr = regptr ? regPCEx(regptr) : 0;
        if (next_addr < cur_addr) {
          QPoint wPoints[] = {
              QPoint(x + funcsize, y + halfRow + 1),
              QPoint(x + funcsize + 2, y + halfRow - 1),
              QPoint(x + funcsize + 4, y + halfRow + 1),
          };
          jumpsize = 8;
          painter->drawPolyline(wPoints, 3);
        } else if (next_addr > cur_addr) {
          QPoint wPoints[] = {
              QPoint(x + funcsize, y + halfRow - 1),
              QPoint(x + funcsize + 2, y + halfRow + 1),
              QPoint(x + funcsize + 4, y + halfRow - 1),
          };
          jumpsize = 8;
          painter->drawPolyline(wPoints, 3);
        }
      }

      RichTextPainter::paintRichText(painter, x, y, getColumnWidth(col),
                                     getRowHeight(), jumpsize + funcsize,
                                     getRichBytes(inst), mFontMetrics);
      return "";
    }

    case Disassembly: {
      RichTextPainter::List richText;

      int loopsize = 0;
      int depth = 0;

      while (1)  // paint all loop depths
      {
        LOOPTYPE loopFirst = DbgGetLoopTypeAt(cur_addr, depth);
        LOOPTYPE loopLast = DbgGetLoopTypeAt(cur_addr + inst.length - 1, depth);
        HANDLE_RANGE_TYPE(LOOP, loopFirst, loopLast);
        if (loopFirst == LOOP_NONE) break;
        Function_t funcType;
        switch (loopFirst) {
          case LOOP_SINGLE:
            funcType = Function_single;
            break;
          case LOOP_BEGIN:
            funcType = Function_start;
            break;
          case LOOP_ENTRY:
            funcType = Function_loop_entry;
            break;
          case LOOP_MIDDLE:
            funcType = Function_middle;
            break;
          case LOOP_END:
            funcType = Function_end;
            break;
          default:
            break;
        }
        loopsize += paintFunctionGraphic(painter, x + loopsize, y, funcType,
                                         loopFirst != LOOP_SINGLE);
        depth++;
      }

      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(inst.tokens, richText,
                                        &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(inst.tokens, richText, 0);
      RichTextPainter::paintRichText(painter, x + loopsize, y,
                                     getColumnWidth(col) - 0, getRowHeight(), 4,
                                     richText, mFontMetrics);
      return "";
    }

    case Registers: {
      RichTextPainter::List richText;
      auto fakeInstruction = registersTokens(index);
      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(fakeInstruction, richText,
                                        &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(fakeInstruction, richText, 0);
      RichTextPainter::paintRichText(painter, x + 0, y, getColumnWidth(col) - 0,
                                     getRowHeight(), 4, richText, mFontMetrics);

      return "";
    }
    case Memory: {
      auto fakeInstruction = memoryTokens(index);
      RichTextPainter::List richText;
      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(fakeInstruction, richText,
                                        &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(fakeInstruction, richText, nullptr);
      RichTextPainter::paintRichText(painter, x + 0, y, getColumnWidth(col) - 0,
                                     getRowHeight(), 4, richText, mFontMetrics);

      return "";
    }
    case Comments: {
      int xinc = 3;
      int width;
      if (DbgIsDebugging()) {
        // TODO: draw arguments
        QString comment;
        bool autoComment = false;
        char label[MAX_LABEL_SIZE] = "";
        if (GetCommentFormat(cur_addr, comment, &autoComment)) {
          QColor backgroundColor;
          if (autoComment) {
            // TODO: autocomments from trace file will be much more helpful
            painter->setPen(mAutoCommentColor);
            backgroundColor = mAutoCommentBackgroundColor;
          } else  // user comment
          {
            painter->setPen(mCommentColor);
            backgroundColor = mCommentBackgroundColor;
          }

          width = mFontMetrics->width(comment);
          if (width > w) width = w;
          if (width)
            painter->fillRect(QRect(x + xinc, y, width, h),
                              QBrush(backgroundColor));  // fill comment color
          painter->drawText(QRect(x + xinc, y, width, h),
                            Qt::AlignVCenter | Qt::AlignLeft, comment);
        } else if (DbgGetLabelAt(cur_addr, SEG_DEFAULT,
                                 label))  // label but no comment
        {
          QString labelText(label);
          QColor backgroundColor;
          painter->setPen(mLabelColor);
          backgroundColor = mLabelBackgroundColor;

          width = mFontMetrics->width(labelText);
          if (width > w) width = w;
          if (width)
            painter->fillRect(QRect(x + xinc, y, width, h),
                              QBrush(backgroundColor));  // fill comment color
          painter->drawText(QRect(x + xinc, y, width, h),
                            Qt::AlignVCenter | Qt::AlignLeft, labelText);
        } else
          width = 0;
        x += width + 3;
      }
      if (mShowMnemonicBrief) {
        char brief[MAX_STRING_SIZE] = "";
        QString mnem;
        for (const ZydisTokenizer::SingleToken& token : inst.tokens.tokens) {
          if (token.type != ZydisTokenizer::TokenType::Space &&
              token.type != ZydisTokenizer::TokenType::Prefix) {
            mnem = token.text;
            break;
          }
        }
        if (mnem.isEmpty()) mnem = inst.instStr;

        int index = mnem.indexOf(' ');
        if (index != -1) mnem.truncate(index);
        DbgFunctions()->GetMnemonicBrief(mnem.toUtf8().constData(),
                                         MAX_STRING_SIZE, brief);

        painter->setPen(mMnemonicBriefColor);

        QString mnemBrief = brief;
        if (mnemBrief.length()) {
          width = mFontMetrics->width(mnemBrief);
          if (width > w) width = w;
          if (width)
            painter->fillRect(
                QRect(x, y, width, h),
                QBrush(mMnemonicBriefBackgroundColor));  // mnemonic brief
                                                         // background color
          painter->drawText(QRect(x, y, width, h),
                            Qt::AlignVCenter | Qt::AlignLeft, mnemBrief);
        }
      }
      return "";
    }

    default:
      return "";
  }
}

ZydisTokenizer::InstructionToken TraceBrowser::memoryTokens(
    unsigned long long atIndex) {
  duint MemoryAddress[MAX_MEMORY_OPERANDS];
  duint MemoryOldContent[MAX_MEMORY_OPERANDS];
  duint MemoryNewContent[MAX_MEMORY_OPERANDS];
  bool MemoryIsValid[MAX_MEMORY_OPERANDS];
  int MemoryOperandsCount;
  ZydisTokenizer::InstructionToken fakeInstruction =
      ZydisTokenizer::InstructionToken();

  MemoryOperandsCount = mTraceFile->MemoryAccessCount(atIndex);
  if (MemoryOperandsCount > 0) {
    mTraceFile->MemoryAccessInfo(atIndex, MemoryAddress, MemoryOldContent,
                                 MemoryNewContent, MemoryIsValid);
    std::vector<ZydisTokenizer::SingleToken> tokens;

    for (int i = 0; i < MemoryOperandsCount; i++) {
      ZydisTokenizer::TokenizeTraceMemory(MemoryAddress[i], MemoryOldContent[i],
                                          MemoryNewContent[i], tokens);
    }

    fakeInstruction.tokens.insert(fakeInstruction.tokens.begin(),
                                  tokens.begin(), tokens.end());
  }
  return fakeInstruction;
}

ZydisTokenizer::InstructionToken TraceBrowser::registersTokens(
    unsigned long long atIndex) {
  ZydisTokenizer::InstructionToken fakeInstruction =
      ZydisTokenizer::InstructionToken();
  const REGDUMP *nowraw = mTraceFile->Registers(atIndex);
  const REGDUMP *nextraw = (atIndex + 1 < mTraceFile->Length())
                     ? mTraceFile->Registers(atIndex + 1)
                     : nowraw;
  std::vector<ZydisTokenizer::SingleToken> tokens;

#define addRegValues(str, regnow, regnext) \
  if (atIndex == 0 || regnow != regnext) { \
    ZydisTokenizer::TokenizeTraceRegister(str, regnow, regnext, tokens); \
  };

  auto arch = DbgGlobal::inst()->currentArch();
  switch (arch) {
  case mana::X86:
  case mana::X86_64: {
    const REGDUMPX64 *now = (REGDUMPX64 *)nowraw;
    const REGDUMPX64 *next = (REGDUMPX64 *)nextraw;
    addRegValues(ArchValue("eax", "rax"), now->regcontext.cax, next->regcontext.cax);
    addRegValues(ArchValue("ebx", "rbx"), now->regcontext.cbx, next->regcontext.cbx);
    addRegValues(ArchValue("ecx", "rcx"), now->regcontext.ccx, next->regcontext.ccx);
    addRegValues(ArchValue("edx", "rdx"), now->regcontext.cdx, next->regcontext.cdx);
    addRegValues(ArchValue("esp", "rsp"), now->regcontext.csp, next->regcontext.csp);
    addRegValues(ArchValue("ebp", "rbp"), now->regcontext.cbp, next->regcontext.cbp);
    addRegValues(ArchValue("esi", "rsi"), now->regcontext.csi, next->regcontext.csi);
    addRegValues(ArchValue("edi", "rdi"), now->regcontext.cdi, next->regcontext.cdi);
    if (arch == mana::X86_64) {
      addRegValues("r8", now->regcontext.r8, next->regcontext.r8);
      addRegValues("r9", now->regcontext.r9, next->regcontext.r9);
      addRegValues("r10", now->regcontext.r10, next->regcontext.r10);
      addRegValues("r11", now->regcontext.r11, next->regcontext.r11);
      addRegValues("r12", now->regcontext.r12, next->regcontext.r12);
      addRegValues("r13", now->regcontext.r13, next->regcontext.r13);
      addRegValues("r14", now->regcontext.r14, next->regcontext.r14);
      addRegValues("r15", now->regcontext.r15, next->regcontext.r15);
    }
    break;
  }
  case mana::ARM: {
    const REGDUMPA32 *now = (REGDUMPA32 *)nowraw;
    const REGDUMPA32 *next = (REGDUMPA32 *)nextraw;
    addRegValues("r0", now->regcontext.gpr[0], next->regcontext.gpr[0]);
    addRegValues("r1", now->regcontext.gpr[1], next->regcontext.gpr[1]);
    addRegValues("r2", now->regcontext.gpr[2], next->regcontext.gpr[2]);
    addRegValues("r3", now->regcontext.gpr[3], next->regcontext.gpr[3]);
    addRegValues("r4", now->regcontext.gpr[4], next->regcontext.gpr[4]);
    addRegValues("r5", now->regcontext.gpr[5], next->regcontext.gpr[5]);
    addRegValues("r6", now->regcontext.gpr[6], next->regcontext.gpr[6]);
    addRegValues("r7", now->regcontext.gpr[7], next->regcontext.gpr[7]);
    addRegValues("r8", now->regcontext.gpr[8], next->regcontext.gpr[8]);
    addRegValues("r9", now->regcontext.gpr[9], next->regcontext.gpr[9]);
    addRegValues("r10", now->regcontext.gpr[10], next->regcontext.gpr[10]);
    addRegValues("r11", now->regcontext.gpr[11], next->regcontext.gpr[11]);
    addRegValues("fp", now->regcontext.gpr[12], next->regcontext.gpr[12]);
    addRegValues("lr", now->regcontext.clr, next->regcontext.clr);
    addRegValues("sp", now->regcontext.csp, next->regcontext.csp);
    addRegValues("pc", now->regcontext.cip, next->regcontext.cip);
    break;
  }
  case mana::ARM64: {
    const REGDUMPA64 *now = (REGDUMPA64 *)nowraw;
    const REGDUMPA64 *next = (REGDUMPA64 *)nextraw;
    addRegValues("x0", now->regcontext.gpr[0], next->regcontext.gpr[0]);
    addRegValues("x1", now->regcontext.gpr[1], next->regcontext.gpr[1]);
    addRegValues("x2", now->regcontext.gpr[2], next->regcontext.gpr[2]);
    addRegValues("x3", now->regcontext.gpr[3], next->regcontext.gpr[3]);
    addRegValues("x4", now->regcontext.gpr[4], next->regcontext.gpr[4]);
    addRegValues("x5", now->regcontext.gpr[5], next->regcontext.gpr[5]);
    addRegValues("x6", now->regcontext.gpr[6], next->regcontext.gpr[6]);
    addRegValues("x7", now->regcontext.gpr[7], next->regcontext.gpr[7]);
    addRegValues("x8", now->regcontext.gpr[8], next->regcontext.gpr[8]);
    addRegValues("x9", now->regcontext.gpr[9], next->regcontext.gpr[9]);
    addRegValues("x10", now->regcontext.gpr[10], next->regcontext.gpr[10]);
    addRegValues("x11", now->regcontext.gpr[11], next->regcontext.gpr[11]);
    addRegValues("x12", now->regcontext.gpr[12], next->regcontext.gpr[12]);
    addRegValues("x13", now->regcontext.gpr[13], next->regcontext.gpr[13]);
    addRegValues("x14", now->regcontext.gpr[14], next->regcontext.gpr[14]);
    addRegValues("x15", now->regcontext.gpr[15], next->regcontext.gpr[15]);
    addRegValues("x16", now->regcontext.gpr[16], next->regcontext.gpr[16]);
    addRegValues("x17", now->regcontext.gpr[17], next->regcontext.gpr[17]);
    addRegValues("x18", now->regcontext.gpr[18], next->regcontext.gpr[18]);
    addRegValues("x19", now->regcontext.gpr[19], next->regcontext.gpr[19]);
    addRegValues("x20", now->regcontext.gpr[20], next->regcontext.gpr[20]);
    addRegValues("x21", now->regcontext.gpr[21], next->regcontext.gpr[21]);
    addRegValues("x22", now->regcontext.gpr[22], next->regcontext.gpr[22]);
    addRegValues("x23", now->regcontext.gpr[23], next->regcontext.gpr[23]);
    addRegValues("x24", now->regcontext.gpr[24], next->regcontext.gpr[24]);
    addRegValues("x25", now->regcontext.gpr[25], next->regcontext.gpr[25]);
    addRegValues("x26", now->regcontext.gpr[26], next->regcontext.gpr[26]);
    addRegValues("x27", now->regcontext.gpr[27], next->regcontext.gpr[27]);
    addRegValues("x28", now->regcontext.gpr[28], next->regcontext.gpr[28]);
    addRegValues("fp", now->regcontext.gpr[29], next->regcontext.gpr[29]);
    addRegValues("lr", now->regcontext.clr, next->regcontext.clr);
    addRegValues("sp", now->regcontext.csp, next->regcontext.csp);
    addRegValues("pc", now->regcontext.cip, next->regcontext.cip);
    break;
  }
  default: break;
  }
  fakeInstruction.tokens.insert(fakeInstruction.tokens.begin(),
                                tokens.begin(), tokens.end());

  return fakeInstruction;
}

void TraceBrowser::prepareData() {
  auto viewables = getViewableRowsCount();
  int lines = 0;
  if (mTraceFile != nullptr) {
    if (mTraceFile->Progress() == 100) {
      if (mTraceFile->Length() < getTableOffset() + viewables)
        lines = mTraceFile->Length() - getTableOffset();
      else
        lines = viewables;
    }
  }
  setNbrOfLineToPrint(lines);
}

void TraceBrowser::setupRightClickContextMenu() {
  mMenuBuilder = new MenuBuilder(this);
  QAction* toggleRunTrace =
      makeShortcutAction(DIcon("trace.png"), tr("Start Run Trace"),
                         SLOT(toggleRunTraceSlot()), "ActionToggleRunTrace");
  mMenuBuilder->addAction(toggleRunTrace, [toggleRunTrace](QMenu*) {
    if (!DbgIsDebugging()) return false;
    if (DbgValFromString("tr.runtraceenabled()") == 1)
      toggleRunTrace->setText(tr("Stop Run Trace"));
    else
      toggleRunTrace->setText(tr("Start Run Trace"));
    return true;
  });
  auto mTraceFileIsNull = [this](QMenu*) { return mTraceFile == nullptr; };

  mMenuBuilder->addAction(makeAction(DIcon("folder-horizontal-open.png"),
                                     tr("Open"), SLOT(openFileSlot())),
                          mTraceFileIsNull);
  mMenuBuilder->addMenu(makeMenu(DIcon("recentfiles.png"), tr("Recent Files")),
                        [this](QMenu* menu) {
                          if (mTraceFile == nullptr) {
                            mMRUList->appendMenu(menu);
                            return true;
                          } else
                            return false;
                        });
  mMenuBuilder->addAction(
      makeAction(DIcon("fatal-error.png"), tr("Close"), SLOT(closeFileSlot())),
      [this](QMenu*) { return mTraceFile != nullptr; });
  mMenuBuilder->addAction(
      makeAction(DIcon("fatal-error.png"), tr("Close and delete"),
                 SLOT(closeDeleteSlot())),
      [this](QMenu*) { return mTraceFile != nullptr; });
  mMenuBuilder->addSeparator();
  auto isValid = [this](QMenu*) {
    return mTraceFile != nullptr && mTraceFile->Progress() == 100 &&
           mTraceFile->Length() > 0;
  };
  auto isDebugging = [this](QMenu*) {
    return mTraceFile != nullptr && mTraceFile->Progress() == 100 &&
           mTraceFile->Length() > 0 && DbgIsDebugging();
  };

  MenuBuilder* copyMenu = new MenuBuilder(this, isValid);
  copyMenu->addAction(
      makeShortcutAction(DIcon("copy_selection.png"), tr("&Selection"),
                         SLOT(copySelectionSlot()), "ActionCopy"));
  copyMenu->addAction(makeAction(DIcon("copy_selection.png"),
                                 tr("Selection to &File"),
                                 SLOT(copySelectionToFileSlot())));
  copyMenu->addAction(makeAction(DIcon("copy_selection_no_bytes.png"),
                                 tr("Selection (&No Bytes)"),
                                 SLOT(copySelectionNoBytesSlot())));
  copyMenu->addAction(makeAction(DIcon("copy_selection_no_bytes.png"),
                                 tr("Selection to File (No Bytes)"),
                                 SLOT(copySelectionToFileNoBytesSlot())));
  copyMenu->addAction(makeShortcutAction(DIcon("database-export.png"),
                                         tr("&Export Table"),
                                         SLOT(exportSlot()), "ActionExport"));
  copyMenu->addAction(makeShortcutAction(DIcon("copy_address.png"),
                                         tr("Address"), SLOT(copyCipSlot()),
                                         "ActionCopyAddress"));
  copyMenu->addAction(makeShortcutAction(DIcon("copy_address.png"), tr("&RVA"),
                                         SLOT(copyRvaSlot()), "ActionCopyRva"),
                      isDebugging);
  copyMenu->addAction(
      makeShortcutAction(DIcon("fileoffset.png"), tr("&File Offset"),
                         SLOT(copyFileOffsetSlot()), "ActionCopyFileOffset"),
      isDebugging);
  copyMenu->addAction(makeAction(DIcon("copy_disassembly.png"),
                                 tr("Disassembly"),
                                 SLOT(copyDisassemblySlot())));
  copyMenu->addAction(makeAction(DIcon("copy_address.png"), tr("Index"),
                                 SLOT(copyIndexSlot())));

  mMenuBuilder->addMenu(makeMenu(DIcon("copy.png"), tr("&Copy")), copyMenu);
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon(ArchValue("processor32.png", "processor-cpu.png")),
                         tr("&Follow in Disassembler"),
                         SLOT(followDisassemblySlot()), "ActionFollowDisasm"),
      isValid);

  mBreakpointMenu =
      new BreakpointMenu(this, getActionHelperFuncs(), [this, isValid]() {
        if (isValid(nullptr)) {
          auto reg = mTraceFile->Registers(getInitialSelection());
          return reg ? (ULONG_PTR)regPCEx(reg) : (ULONG_PTR)0;
        }
        else
          return (ULONG_PTR)0;
      });
  mBreakpointMenu->build(mMenuBuilder);
#if 0
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon("label.png"), tr("Label Current Address"),
                         SLOT(setLabelSlot()), "ActionSetLabel"),
      isDebugging);
#endif
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon("comment.png"), tr("&Comment"),
                         SLOT(setCommentSlot()), "ActionSetComment"),
      isDebugging);
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon("bookmark_toggle.png"), tr("Toggle Bookmark"),
                         SLOT(setBookmarkSlot()), "ActionToggleBookmark"),
      isDebugging);
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon("highlight.png"), tr("&Highlighting mode"),
                         SLOT(enableHighlightingModeSlot()),
                         "ActionHighlightingMode"),
      isValid);
#if 0
  mMenuBuilder->addAction(
      makeShortcutAction(DIcon("helpmnemonic.png"), tr("Help on mnemonic"),
                         SLOT(mnemonicHelpSlot()), "ActionHelpOnMnemonic"),
      isValid);
  QAction* mnemonicBrief = makeShortcutAction(
      DIcon("helpbrief.png"), tr("Show mnemonic brief"),
      SLOT(mnemonicBriefSlot()), "ActionToggleMnemonicBrief");
  mMenuBuilder->addAction(mnemonicBrief, [this, mnemonicBrief](QMenu*) {
    if (mShowMnemonicBrief)
      mnemonicBrief->setText(tr("Hide mnemonic brief"));
    else
      mnemonicBrief->setText(tr("Show mnemonic brief"));
    return true;
  });
#endif
  MenuBuilder* gotoMenu = new MenuBuilder(this, isValid);
  gotoMenu->addAction(
      makeShortcutAction(DIcon("goto.png"), tr("Expression"), SLOT(gotoSlot()),
                         "ActionGotoExpression"),
      isValid);
  gotoMenu->addAction(
      makeShortcutAction(DIcon("previous.png"), tr("Previous"),
                         SLOT(gotoPreviousSlot()), "ActionGotoPrevious"),
      [this](QMenu*) { return mHistory.historyHasPrev(); });
  gotoMenu->addAction(
      makeShortcutAction(DIcon("next.png"), tr("Next"), SLOT(gotoNextSlot()),
                         "ActionGotoNext"),
      [this](QMenu*) { return mHistory.historyHasNext(); });
  mMenuBuilder->addMenu(makeMenu(DIcon("goto.png"), tr("Go to")), gotoMenu);

#if 0
  MenuBuilder* searchMenu = new MenuBuilder(this, isValid);
  searchMenu->addAction(makeAction(DIcon("search_for_constant.png"),
                                   tr("Constant"), SLOT(searchConstantSlot())));
  searchMenu->addAction(makeAction(DIcon("memory-map.png"),
                                   tr("Memory Reference"),
                                   SLOT(searchMemRefSlot())));
  mMenuBuilder->addMenu(makeMenu(DIcon("search.png"), tr("&Search")),
                        searchMenu);
#endif

  // The following code adds a menu to view the information about currently
  // selected instruction. When info box is completed, remove me.
  MenuBuilder* infoMenu = new MenuBuilder(this, [this, isValid](QMenu* menu) {
    duint MemoryAddress[MAX_MEMORY_OPERANDS];
    duint MemoryOldContent[MAX_MEMORY_OPERANDS];
    duint MemoryNewContent[MAX_MEMORY_OPERANDS];
    bool MemoryIsValid[MAX_MEMORY_OPERANDS];
    int MemoryOperandsCount;
    unsigned long long index;

    if (!isValid(nullptr)) return false;
    index = getInitialSelection();
    MemoryOperandsCount = mTraceFile->MemoryAccessCount(index);
    if (MemoryOperandsCount > 0) {
      mTraceFile->MemoryAccessInfo(index, MemoryAddress, MemoryOldContent,
                                   MemoryNewContent, MemoryIsValid);
      bool RvaDisplayEnabled = mRvaDisplayEnabled;
      char nolabel[MAX_LABEL_SIZE];
      mRvaDisplayEnabled = false;
      for (int i = 0; i < MemoryOperandsCount; i++) {
        menu->addAction(QString("%1: %2 -> %3")
                            .arg(getAddrText(MemoryAddress[i], nolabel, false))
                            .arg(ToPtrString(MemoryOldContent[i]))
                            .arg(ToPtrString(MemoryNewContent[i])));
      }
      mRvaDisplayEnabled = RvaDisplayEnabled;
      menu->addSeparator();
    }
    menu->addAction(QString("ThreadID: %1").arg(mTraceFile->ThreadId(index)));
    return true;
  });
  mMenuBuilder->addMenu(makeMenu(tr("Information")), infoMenu);

  QAction* toggleAutoDisassemblyFollowSelection =
      makeAction(tr("Toggle Auto Disassembly Scroll (off)"),
                 SLOT(toggleAutoDisassemblyFollowSelectionSlot()));
  mMenuBuilder->addAction(toggleAutoDisassemblyFollowSelection,
                          [this, toggleAutoDisassemblyFollowSelection](QMenu*) {
                            if (!DbgIsDebugging()) return false;
                            if (mAutoDisassemblyFollowSelection)
                              toggleAutoDisassemblyFollowSelection->setText(
                                  tr("Toggle Auto Disassembly Scroll (on)"));
                            else
                              toggleAutoDisassemblyFollowSelection->setText(
                                  tr("Toggle Auto Disassembly Scroll (off)"));
                            return true;
                          });
}

void TraceBrowser::contextMenuEvent(QContextMenuEvent* event) {
  QMenu menu(this);
  mMenuBuilder->build(&menu);
  menu.exec(event->globalPos());
}

void TraceBrowser::mousePressEvent(QMouseEvent* event) {
  duint index = getIndexOffsetFromY(transY(event->y())) + getTableOffset();
  if (getGuiState() != AbstractTableView::NoState || !mTraceFile ||
      mTraceFile->Progress() < 100) {
    AbstractTableView::mousePressEvent(event);
    return;
  }
  switch (event->button()) {
    case Qt::LeftButton:
      if (index < getRowCount()) {
        if (mHighlightingMode || mPermanentHighlightingMode) {
          ZydisTokenizer::InstructionToken tokens;
          int columnPosition = 0;
          if (getColumnIndexFromX(event->x()) == Disassembly) {
            tokens = mTraceFile->Instruction(index).tokens;
            columnPosition = getColumnPosition(Disassembly);
          } else if (getColumnIndexFromX(event->x()) ==
                     TableColumnIndex::Registers) {
            tokens = registersTokens(index);
            columnPosition = getColumnPosition(Registers);
          } else if (getColumnIndexFromX(event->x()) == Memory) {
            tokens = memoryTokens(index);
            columnPosition = getColumnPosition(Memory);
          }
          ZydisTokenizer::SingleToken token;
          if (ZydisTokenizer::TokenFromX(
                  tokens, token, event->x() - columnPosition, mFontMetrics)) {
            if (ZydisTokenizer::IsHighlightableToken(token)) {
              if (!ZydisTokenizer::TokenEquals(&token, &mHighlightToken) ||
                  event->button() == Qt::RightButton)
                mHighlightToken = token;
              else
                mHighlightToken = ZydisTokenizer::SingleToken();
            } else if (!mPermanentHighlightingMode) {
              mHighlightToken = ZydisTokenizer::SingleToken();
            }
          } else if (!mPermanentHighlightingMode) {
            mHighlightToken = ZydisTokenizer::SingleToken();
          }
        }
        if (mHighlightingMode)  // disable highlighting mode after clicked
        {
          mHighlightingMode = false;
          reloadData();
        }
        if (event->modifiers() & Qt::ShiftModifier)
          expandSelectionUpTo(index);
        else
          setSingleSelection(index);
        mHistory.addVaToHistory(index);
        emit selectionChanged(getInitialSelection());
      }
      updateViewport();
      return;

      break;
    case Qt::MiddleButton:
      copyCipSlot();
      MessageBeep(MB_OK);
      break;
    case Qt::BackButton:
      gotoPreviousSlot();
      break;
    case Qt::ForwardButton:
      gotoNextSlot();
      break;
  }

  AbstractTableView::mousePressEvent(event);
}

void TraceBrowser::mouseDoubleClickEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton && mTraceFile != nullptr &&
      mTraceFile->Progress() == 100) {
    switch (getColumnIndexFromX(event->x())) {
      case Index:  // Index: follow
        followDisassemblySlot();
        break;
      case Address:  // Address: set RVA
        if (mRvaDisplayEnabled &&
            regPCEx(mTraceFile->Registers(getInitialSelection())) ==
                mRvaDisplayBase)
          mRvaDisplayEnabled = false;
        else {
          mRvaDisplayEnabled = true;
          mRvaDisplayBase =
              regPCEx(mTraceFile->Registers(getInitialSelection()));
        }
        reloadData();
        break;
      case Opcode:  // Opcode: Breakpoint
        mBreakpointMenu->toggleInt3BPActionSlot();
        break;
      case Disassembly:  // Instructions: follow
        followDisassemblySlot();
        break;
      case Comments:  // Comment
        setCommentSlot();
        break;
    }
  }
  AbstractTableView::mouseDoubleClickEvent(event);
}

void TraceBrowser::mouseMoveEvent(QMouseEvent* event) {
  dsint index = getIndexOffsetFromY(transY(event->y())) + getTableOffset();
  if ((event->buttons() & Qt::LeftButton) != 0 &&
      getGuiState() == AbstractTableView::NoState && mTraceFile != nullptr &&
      mTraceFile->Progress() == 100) {
    if (index < getRowCount()) {
      setSingleSelection(getInitialSelection());
      expandSelectionUpTo(index);
    }
    if (transY(event->y()) > this->height()) {
      verticalScrollBar()->triggerAction(QAbstractSlider::SliderSingleStepAdd);
    } else if (transY(event->y()) < 0) {
      verticalScrollBar()->triggerAction(QAbstractSlider::SliderSingleStepSub);
    }
    updateViewport();
  }
  AbstractTableView::mouseMoveEvent(event);
}

void TraceBrowser::keyPressEvent(QKeyEvent* event) {
  int key = event->key();
  auto curindex = getInitialSelection();
  auto visibleindex = curindex;
  if ((key == Qt::Key_Up || key == Qt::Key_Down) && mTraceFile &&
      mTraceFile->Progress() == 100) {
    if (key == Qt::Key_Up) {
      if (event->modifiers() == Qt::ShiftModifier) {
        if (curindex == getSelectionStart()) {
          if (getSelectionEnd() > 0) {
            visibleindex = getSelectionEnd() - 1;
            expandSelectionUpTo(visibleindex);
          }
        } else {
          if (getSelectionStart() > 0) {
            visibleindex = getSelectionStart() - 1;
            expandSelectionUpTo(visibleindex);
          }
        }
      } else {
        if (curindex > 0) {
          visibleindex = curindex - 1;
          setSingleSelection(visibleindex);
        }
      }
    } else {
      if (getSelectionEnd() + 1 < mTraceFile->Length()) {
        if (event->modifiers() == Qt::ShiftModifier) {
          visibleindex = getSelectionEnd() + 1;
          expandSelectionUpTo(visibleindex);
        } else {
          visibleindex = getSelectionEnd() + 1;
          setSingleSelection(visibleindex);
        }
      }
    }
    makeVisible(visibleindex);
    mHistory.addVaToHistory(visibleindex);
    updateViewport();

    emit selectionChanged(getInitialSelection());
  } else
    AbstractTableView::keyPressEvent(event);
}

void TraceBrowser::onSelectionChanged(unsigned long long selection) {
  if (mAutoDisassemblyFollowSelection) followDisassemblySlot();
}

void TraceBrowser::tokenizerConfigUpdatedSlot() {
  mPermanentHighlightingMode =
      ConfigBool("Disassembler", "PermanentHighlightingMode");
}

void TraceBrowser::expandSelectionUpTo(duint to) {
  if (to < mSelection.firstSelectedIndex) {
    mSelection.fromIndex = to;
  } else if (to > mSelection.firstSelectedIndex) {
    mSelection.toIndex = to;
  } else if (to == mSelection.firstSelectedIndex) {
    setSingleSelection(to);
  }
}

void TraceBrowser::setSingleSelection(duint index) {
  mSelection.firstSelectedIndex = index;
  mSelection.fromIndex = index;
  mSelection.toIndex = index;
}

duint TraceBrowser::getInitialSelection() {
  return mSelection.firstSelectedIndex;
}

duint TraceBrowser::getSelectionSize() {
  return mSelection.toIndex - mSelection.fromIndex + 1;
}

duint TraceBrowser::getSelectionStart() { return mSelection.fromIndex; }

duint TraceBrowser::getSelectionEnd() { return mSelection.toIndex; }

void TraceBrowser::makeVisible(duint index) {
  if (index < getTableOffset())
    setTableOffset(index);
  else if (index + 2 > getTableOffset() + getViewableRowsCount())
    setTableOffset(index - getViewableRowsCount() + 2);
}

void TraceBrowser::updateColors() {
  AbstractTableView::updateColors();
  // ZydisTokenizer::UpdateColors(); //Already called in disassembly
  mBackgroundColor = ConfigColor("DisassemblyBackgroundColor");

  mInstructionHighlightColor = ConfigColor("InstructionHighlightColor");
  mSelectionColor = ConfigColor("DisassemblySelectionColor");
  mCipBackgroundColor = ConfigColor("DisassemblyCipBackgroundColor");
  mCipColor = ConfigColor("DisassemblyCipColor");
  mBreakpointBackgroundColor =
      ConfigColor("DisassemblyBreakpointBackgroundColor");
  mBreakpointColor = ConfigColor("DisassemblyBreakpointColor");
  mHardwareBreakpointBackgroundColor =
      ConfigColor("DisassemblyHardwareBreakpointBackgroundColor");
  mHardwareBreakpointColor = ConfigColor("DisassemblyHardwareBreakpointColor");
  mBookmarkBackgroundColor = ConfigColor("DisassemblyBookmarkBackgroundColor");
  mBookmarkColor = ConfigColor("DisassemblyBookmarkColor");
  mLabelColor = ConfigColor("DisassemblyLabelColor");
  mLabelBackgroundColor = ConfigColor("DisassemblyLabelBackgroundColor");
  mSelectedAddressBackgroundColor =
      ConfigColor("DisassemblySelectedAddressBackgroundColor");
  mTracedAddressBackgroundColor =
      ConfigColor("DisassemblyTracedBackgroundColor");
  mSelectedAddressColor = ConfigColor("DisassemblySelectedAddressColor");
  mAddressBackgroundColor = ConfigColor("DisassemblyAddressBackgroundColor");
  mAddressColor = ConfigColor("DisassemblyAddressColor");
  mBytesColor = ConfigColor("DisassemblyBytesColor");
  mBytesBackgroundColor = ConfigColor("DisassemblyBytesBackgroundColor");
  mAutoCommentColor = ConfigColor("DisassemblyAutoCommentColor");
  mAutoCommentBackgroundColor =
      ConfigColor("DisassemblyAutoCommentBackgroundColor");
  mMnemonicBriefColor = ConfigColor("DisassemblyMnemonicBriefColor");
  mMnemonicBriefBackgroundColor =
      ConfigColor("DisassemblyMnemonicBriefBackgroundColor");
  mCommentColor = ConfigColor("DisassemblyCommentColor");
  mCommentBackgroundColor = ConfigColor("DisassemblyCommentBackgroundColor");
  mConditionalJumpLineTrueColor =
      ConfigColor("DisassemblyConditionalJumpLineTrueColor");
  mDisassemblyRelocationUnderlineColor =
      ConfigColor("DisassemblyRelocationUnderlineColor");
  mLoopColor = ConfigColor("DisassemblyLoopColor");
  mFunctionColor = ConfigColor("DisassemblyFunctionColor");

  auto a = mSelectionColor, b = mTracedAddressBackgroundColor;
  mTracedSelectedAddressBackgroundColor =
      QColor((a.red() + b.red()) / 2, (a.green() + b.green()) / 2,
             (a.blue() + b.blue()) / 2);

  mLoopPen = QPen(mLoopColor, 2);
  mFunctionPen = QPen(mFunctionColor, 2);
  mConditionalTruePen = QPen(mConditionalJumpLineTrueColor);
}

void TraceBrowser::openFileSlot() {
  BrowseDialog browse(
      this, tr("Open run trace file"), tr("Open trace file"),
      tr("Run trace files (*.%1);;All files (*.*)")
          .arg(ArchValue("trace32", "adt")), DbgGlobal::inst()->traceDir(), false);
  if (browse.exec() != QDialog::Accepted) return;
  emit openSlot(browse.path);
}

void TraceBrowser::openSlot(const QString& fileName) {
  if (mTraceFile != nullptr) {
    mTraceFile->Close();
    delete mTraceFile;
  }
  mTraceFile = new TraceFileReader(this);
  connect(mTraceFile, SIGNAL(parseFinished()), this, SLOT(parseFinishedSlot()));
  mFileName = fileName;
  mTraceFile->Open(fileName);
}

void TraceBrowser::toggleRunTraceSlot() {
  if (!DbgIsDebugging()) return;
  if (DbgValFromString("tr.runtraceenabled()") == 1)
    DbgCmdExec("StopRunTrace");
  else {
    QString defaultFileName("A64Dbg");
    QDateTime currentTime = QDateTime::currentDateTime();
#if 0
    char moduleName[MAX_MODULE_SIZE];
    duint defaultModule = DbgValFromString("mod.main()");
    if (DbgFunctions()->ModNameFromAddr(defaultModule, moduleName, false)) {
      defaultFileName = QString::fromUtf8(moduleName);
    }
#endif
    defaultFileName +=
        "-" + currentTime.date().toString(Qt::ISODate) +
        "_" + currentTime.time().toString("hh-mm-ss") +
        ArchValue(".trace32", ".adt");
    BrowseDialog browse(this, tr("Select stored file"),
                        tr("Store run trace to the following file"),
                        tr("Run trace files (*.%1);;All files (*.*)")
                        .arg(ArchValue("trace32", "adt")),
                        DbgGlobal::inst()->traceDir() + QDir::separator() + defaultFileName,
                        true);
    if (browse.exec() == QDialog::Accepted) {
      if (browse.path.contains(QChar('"')) || browse.path.contains(QChar('\'')))
        SimpleErrorBox(this, tr("Error"),
                       tr("File name contains invalid character."));
      else {
        // DbgCmdExec(QString("StartRunTrace %1").arg(browse.path));
        SimpleTraceDialog dialog;
        dialog.setTraceCommand(QString("StartRunTrace %1").arg(browse.path));
        dialog.setWindowTitle(tr("Trace record into..."));
        dialog.setWindowIcon(DIcon("traceinto.png"));
        dialog.exec();
      }
    }
  }
}

void TraceBrowser::closeFileSlot() {
  if (DbgValFromString("tr.runtraceenabled()") == 1) DbgCmdExec("StopRunTrace");
  mTraceFile->Close();
  delete mTraceFile;
  mTraceFile = nullptr;
  emit Bridge::getBridge()->updateTraceBrowser();
}

void TraceBrowser::closeDeleteSlot() {
  QMessageBox msgbox(QMessageBox::Critical, tr("Close and delete"),
                     tr("Are you really going to delete this file?"),
                     QMessageBox::Yes | QMessageBox::Cancel, this);
  if (msgbox.exec() == QMessageBox::Yes) {
    if (DbgValFromString("tr.runtraceenabled()") == 1)
      DbgCmdExecDirect("StopRunTrace");
    mTraceFile->Delete();
    delete mTraceFile;
    mTraceFile = nullptr;
    emit Bridge::getBridge()->updateTraceBrowser();
  }
}

void TraceBrowser::parseFinishedSlot() {
  if (mTraceFile->isError()) {
    SimpleErrorBox(this, tr("Error"), "Error when opening run trace file");
    delete mTraceFile;
    mTraceFile = nullptr;
    setRowCount(0);
  } else {
    if (mTraceFile->HashValue() && DbgIsDebugging())
      if (DbgFunctions()->DbGetHash() != mTraceFile->HashValue()) {
        SimpleWarningBox(
            this, tr("Trace file is recorded for another debuggee"),
            tr("Checksum is different for current trace file and the debugee. "
               "This probably means you have opened a wrong trace file. This "
               "trace file is recorded for \"%1\"")
                .arg(mTraceFile->ExePath()));
      }
    setRowCount(mTraceFile->Length());
    mMRUList->addEntry(mFileName);
    mMRUList->save();
  }
  setSingleSelection(0);
  makeVisible(0);
  emit Bridge::getBridge()->updateTraceBrowser();
  emit selectionChanged(getInitialSelection());
}

void TraceBrowser::mnemonicBriefSlot() {
  mShowMnemonicBrief = !mShowMnemonicBrief;
  reloadData();
}

void TraceBrowser::mnemonicHelpSlot() {
  unsigned char data[16] = {0xCC};
  int size;
  mTraceFile->OpCode(getInitialSelection(), data, &size);
  Zydis zydis;
  zydis.Disassemble(regPCEx(mTraceFile->Registers(getInitialSelection())),
                    data);
  DbgCmdExecDirect(QString("mnemonichelp %1").arg(zydis.Mnemonic().c_str()));
  emit displayLogWidget();
}

void TraceBrowser::gotoSlot() {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;
  GotoDialog gotoDlg(this, false, true);  // TODO: Cannot use when not debugging
  if (gotoDlg.exec() == QDialog::Accepted) {
    auto val = DbgValFromString(gotoDlg.expressionText.toUtf8().constData());
    if (val >= 0 && val < mTraceFile->Length()) {
      setSingleSelection(val);
      makeVisible(val);
      mHistory.addVaToHistory(val);
      updateViewport();
    }
  }
}

void TraceBrowser::gotoNextSlot() {
  if (mHistory.historyHasNext()) {
    auto index = mHistory.historyNext();
    setSingleSelection(index);
    makeVisible(index);
    updateViewport();
    emit selectionChanged(getInitialSelection());
  }
}

void TraceBrowser::gotoPreviousSlot() {
  if (mHistory.historyHasPrev()) {
    auto index = mHistory.historyPrev();
    setSingleSelection(index);
    makeVisible(index);
    updateViewport();
    emit selectionChanged(getInitialSelection());
  }
}

void TraceBrowser::copyCipSlot() {
  QString clipboard;
  for (auto i = getSelectionStart(); i <= getSelectionEnd(); i++) {
    if (i != getSelectionStart()) clipboard += "\r\n";
    clipboard += ToPtrString(regPCEx(mTraceFile->Registers(i)));
  }
  Bridge::CopyToClipboard(clipboard);
}

void TraceBrowser::copyIndexSlot() {
  QString clipboard;
  for (auto i = getSelectionStart(); i <= getSelectionEnd(); i++) {
    if (i != getSelectionStart()) clipboard += "\r\n";
    clipboard += mTraceFile->getIndexText(i);
  }
  Bridge::CopyToClipboard(clipboard);
}

void TraceBrowser::pushSelectionInto(bool copyBytes, QTextStream& stream,
                                     QTextStream* htmlStream) {
  const int addressLen = getColumnWidth(Address) / getCharWidth() - 1;
  const int bytesLen = getColumnWidth(Opcode) / getCharWidth() - 1;
  const int disassemblyLen = getColumnWidth(Disassembly) / getCharWidth() - 1;
  const int registersLen = getColumnWidth(Registers) / getCharWidth() - 1;
  const int memoryLen = getColumnWidth(Memory) / getCharWidth() - 1;
  if (htmlStream)
    *htmlStream << QString(
                       "<table "
                       "style=\"border-width:0px;border-color:#000000;font-"
                       "family:%1;font-size:%2px;\">")
                       .arg(font().family())
                       .arg(getRowHeight());
  for (unsigned long long i = getSelectionStart(); i <= getSelectionEnd();
       i++) {
    if (i != getSelectionStart()) stream << "\r\n";
    const Instruction_t& inst = mTraceFile->Instruction(i);
    duint cur_addr = inst.rva;
    QString address =
        getAddrText(cur_addr, 0, addressLen > sizeof(duint) * 2 + 1);
    QString bytes;
    QString bytesHTML;
    if (copyBytes)
      RichTextPainter::htmlRichText(getRichBytes(inst), bytesHTML, bytes);
    QString disassembly;
    QString htmlDisassembly;
    if (htmlStream) {
      RichTextPainter::List richText;
      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(inst.tokens, richText,
                                        &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(inst.tokens, richText, 0);
      RichTextPainter::htmlRichText(richText, htmlDisassembly, disassembly);
    } else {
      for (const auto& token : inst.tokens.tokens) disassembly += token.text;
    }
    QString fullComment;
    QString comment;
    bool autocomment;
    if (GetCommentFormat(cur_addr, comment, &autocomment))
      fullComment = " " + comment;

    QString registersText;
    QString registersHtml;
    ZydisTokenizer::InstructionToken regTokens = registersTokens(i);
    if (htmlStream) {
      RichTextPainter::List richText;
      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(regTokens, richText, &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(regTokens, richText, 0);
      RichTextPainter::htmlRichText(richText, registersHtml, registersText);
    } else {
      for (const auto& token : regTokens.tokens) registersText += token.text;
    }

    QString memoryText;
    QString memoryHtml;
    ZydisTokenizer::InstructionToken memTokens = memoryTokens(i);
    if (htmlStream) {
      RichTextPainter::List richText;
      if (mHighlightToken.text.length())
        ZydisTokenizer::TokenToRichText(memTokens, richText, &mHighlightToken);
      else
        ZydisTokenizer::TokenToRichText(memTokens, richText, 0);
      RichTextPainter::htmlRichText(richText, memoryHtml, memoryText);
    } else {
      for (const auto& token : memTokens.tokens) memoryText += token.text;
    }

    stream << mTraceFile->getIndexText(i) + " | " +
                  address.leftJustified(addressLen, QChar(' '), true);
    if (copyBytes)
      stream << " | " + bytes.leftJustified(bytesLen, QChar(' '), true);
    stream << " | " +
                  disassembly.leftJustified(disassemblyLen, QChar(' '), true);
    stream << " | " +
                  registersText.leftJustified(registersLen, QChar(' '), true);
    stream << " | " + memoryText.leftJustified(memoryLen, QChar(' '), true) +
                  " |" + fullComment;
    if (htmlStream) {
      *htmlStream << QString("<tr><td>%1</td><td>%2</td><td>")
                         .arg(mTraceFile->getIndexText(i),
                              address.toHtmlEscaped());
      if (copyBytes) *htmlStream << QString("%1</td><td>").arg(bytesHTML);
      *htmlStream << QString("%1</td><td>").arg(htmlDisassembly);
      *htmlStream << QString("%1</td><td>").arg(registersText);
      *htmlStream << QString("%1</td><td>").arg(memoryText);
      if (!comment.isEmpty()) {
        if (autocomment) {
          *htmlStream << QString("<span style=\"color:%1")
                             .arg(mAutoCommentColor.name());
          if (mAutoCommentBackgroundColor != Qt::transparent)
            *htmlStream << QString(";background-color:%2")
                               .arg(mAutoCommentBackgroundColor.name());
        } else {
          *htmlStream
              << QString("<span style=\"color:%1").arg(mCommentColor.name());
          if (mCommentBackgroundColor != Qt::transparent)
            *htmlStream << QString(";background-color:%2")
                               .arg(mCommentBackgroundColor.name());
        }
        *htmlStream << "\">" << comment.toHtmlEscaped() << "</span></td></tr>";
      } else {
        char label[MAX_LABEL_SIZE];
        if (DbgGetLabelAt(cur_addr, SEG_DEFAULT, label)) {
          comment = QString::fromUtf8(label);
          *htmlStream
              << QString("<span style=\"color:%1").arg(mLabelColor.name());
          if (mLabelBackgroundColor != Qt::transparent)
            *htmlStream << QString(";background-color:%2")
                               .arg(mLabelBackgroundColor.name());
          *htmlStream << "\">" << comment.toHtmlEscaped()
                      << "</span></td></tr>";
        } else
          *htmlStream << "</td></tr>";
      }
    }
  }
  if (htmlStream) *htmlStream << "</table>";
}

void TraceBrowser::copySelectionSlot(bool copyBytes) {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  QString selectionString = "";
  QString selectionHtmlString = "";
  QTextStream stream(&selectionString);
  QTextStream htmlStream(&selectionHtmlString);
  pushSelectionInto(copyBytes, stream, &htmlStream);
  Bridge::CopyToClipboard(selectionString, selectionHtmlString);
}

void TraceBrowser::copySelectionToFileSlot(bool copyBytes) {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "",
                                                  tr("Text Files (*.txt)"));
  if (fileName != "") {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
      QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
      return;
    }

    QTextStream stream(&file);
    pushSelectionInto(copyBytes, stream);
    file.close();
  }
}

void TraceBrowser::copySelectionSlot() { copySelectionSlot(true); }

void TraceBrowser::copySelectionToFileSlot() { copySelectionToFileSlot(true); }

void TraceBrowser::copySelectionNoBytesSlot() { copySelectionSlot(false); }

void TraceBrowser::copySelectionToFileNoBytesSlot() {
  copySelectionToFileSlot(false);
}

void TraceBrowser::copyDisassemblySlot() {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  QString clipboardHtml =
      QString("<div style=\"font-family: %1; font-size: %2px\">")
          .arg(font().family())
          .arg(getRowHeight());
  QString clipboard = "";
  for (auto i = getSelectionStart(); i <= getSelectionEnd(); i++) {
    if (i != getSelectionStart()) {
      clipboard += "\r\n";
      clipboardHtml += "<br/>";
    }
    RichTextPainter::List richText;
    const Instruction_t& inst = mTraceFile->Instruction(i);
    ZydisTokenizer::TokenToRichText(inst.tokens, richText, 0);
    RichTextPainter::htmlRichText(richText, clipboardHtml, clipboard);
  }
  clipboardHtml += QString("</div>");
  Bridge::CopyToClipboard(clipboard, clipboardHtml);
}

void TraceBrowser::copyRvaSlot() {
  QString text;
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  for (unsigned long long i = getSelectionStart(); i <= getSelectionEnd();
       i++) {
    duint cip = regPCEx(mTraceFile->Registers(i));
    duint base = DbgFunctions()->ModBaseFromAddr(cip);
    if (base) {
      if (i != getSelectionStart()) text += "\r\n";
      text += ToHexString(cip - base);
    } else {
      SimpleWarningBox(this, tr("Error!"), tr("Selection not in a module..."));
      return;
    }
  }
  Bridge::CopyToClipboard(text);
}

void TraceBrowser::copyFileOffsetSlot() {
  QString text;
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  for (unsigned long long i = getSelectionStart(); i <= getSelectionEnd();
       i++) {
    duint cip = regPCEx(mTraceFile->Registers(i));
    cip = DbgFunctions()->VaToFileOffset(cip);
    if (cip) {
      if (i != getSelectionStart()) text += "\r\n";
      text += ToHexString(cip);
    } else {
      SimpleErrorBox(this, tr("Error!"), tr("Selection not in a file..."));
      return;
    }
  }
  Bridge::CopyToClipboard(text);
}

void TraceBrowser::exportSlot() {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;
  std::vector<QString> headers;
  headers.reserve(getColumnCount());
  for (int i = 0; i < getColumnCount(); i++) headers.push_back(getColTitle(i));
  ExportCSV(
      getRowCount(), getColumnCount(), headers, [this](dsint row, dsint col) {
        QString temp;
        switch (col) {
          case Index:
            return mTraceFile->getIndexText(row);

          case Address: {
            if (!DbgIsDebugging())
              return ToPtrString(regPCEx(mTraceFile->Registers(row)));
            else
              return getAddrText(regPCEx(mTraceFile->Registers(row)), 0,
                                 true);
          }

          case Opcode: {
            for (auto i : getRichBytes(mTraceFile->Instruction(row)))
              temp += i.text;
            return temp;
          }

          case Disassembly: {
            for (auto i : mTraceFile->Instruction(row).tokens.tokens)
              temp += i.text;
            return temp;
          }

          case Registers: {
            for (auto i : registersTokens(row).tokens) temp += i.text;
            return temp;
          }
          case Memory: {
            for (auto i : memoryTokens(row).tokens) temp += i.text;
            return temp;
          }
          case Comments: {
            if (DbgIsDebugging()) {
              // TODO: draw arguments
              QString comment;
              bool autoComment = false;
              char label[MAX_LABEL_SIZE] = "";
              if (GetCommentFormat(regPCEx(mTraceFile->Registers(row)),
                                   comment, &autoComment)) {
                return QString(comment);
              } else if (DbgGetLabelAt(
                             regPCEx(mTraceFile->Registers(row)),
                             SEG_DEFAULT, label))  // label but no comment
              {
                return QString(label);
              }
            }
            return QString();
          }
          default:
            return QString();
        }
      });
}

void TraceBrowser::setCommentSlot() {
  if (!DbgIsDebugging() || mTraceFile == nullptr ||
      mTraceFile->Progress() < 100)
    return;
  duint wVA = regPCEx(mTraceFile->Registers(getInitialSelection()));
  LineEditDialog mLineEdit(this);
  mLineEdit.setTextMaxLength(MAX_COMMENT_SIZE - 2);
  QString addr_text = ToPtrString(wVA);
  char comment_text[MAX_COMMENT_SIZE] = "";
  if (DbgGetCommentAt(nullptr, (duint)wVA, comment_text)) {
    if (comment_text[0] == '\1')  // automatic comment
      mLineEdit.setText(QString(comment_text + 1));
    else
      mLineEdit.setText(QString(comment_text));
  }
  mLineEdit.setWindowTitle(tr("Add comment at ") + addr_text);
  if (mLineEdit.exec() != QDialog::Accepted) return;
  QString comment = mLineEdit.editText.replace('\r', "").replace('\n', "");
  if (!DbgSetCommentAt(nullptr, wVA, comment.toUtf8().constData()))
    SimpleErrorBox(this, tr("Error!"), tr("DbgSetCommentAt failed!"));

  static bool easter = isEaster();
  if (easter && comment.toLower() == "oep") {
    QFile file(":/icons/images/egg.wav");
    if (file.open(QIODevice::ReadOnly)) {
      QByteArray egg = file.readAll();
      PlaySoundA(egg.data(), 0, SND_MEMORY | SND_ASYNC | SND_NODEFAULT);
    }
  }

  GuiUpdateAllViews();
}

void TraceBrowser::setBookmarkSlot() {
  if (!DbgIsDebugging()) return;
  duint wVA = regPCEx(mTraceFile->Registers(getInitialSelection()));
  bool result;
  if (DbgGetBookmarkAt(nullptr, wVA))
    result = DbgSetBookmarkAt(nullptr, wVA, false);
  else
    result = DbgSetBookmarkAt(nullptr, wVA, true);
  if (!result) {
    QMessageBox msg(QMessageBox::Critical, tr("Error!"),
                    tr("DbgSetBookmarkAt failed!"));
    msg.setWindowIcon(DIcon("compile-error.png"));
    msg.setParent(this, Qt::Dialog);
    msg.setWindowFlags(msg.windowFlags() & (~Qt::WindowContextHelpButtonHint));
    msg.exec();
  }

  GuiUpdateAllViews();
}

void TraceBrowser::setLabelSlot() {
  if (!DbgIsDebugging() || mTraceFile == nullptr ||
      mTraceFile->Progress() < 100)
    return;
  duint wVA = regPCEx(mTraceFile->Registers(getInitialSelection()));
  LineEditDialog mLineEdit(this);
  mLineEdit.setTextMaxLength(MAX_LABEL_SIZE - 2);
  QString addr_text = ToPtrString(wVA);
  char label_text[MAX_COMMENT_SIZE] = "";
  if (DbgGetLabelAt((duint)wVA, SEG_DEFAULT, label_text))
    mLineEdit.setText(QString(label_text));
  mLineEdit.setWindowTitle(tr("Add label at ") + addr_text);
restart:
  if (mLineEdit.exec() != QDialog::Accepted) return;
  QByteArray utf8data = mLineEdit.editText.toUtf8();
  if (!utf8data.isEmpty() && DbgIsValidExpression(utf8data.constData()) &&
      DbgValFromString(utf8data.constData()) != wVA) {
    QMessageBox msg(QMessageBox::Warning, tr("The label may be in use"),
                    tr("The label \"%1\" may be an existing label or a valid "
                       "expression. Using such label might have undesired "
                       "effects. Do you still want to continue?")
                        .arg(mLineEdit.editText),
                    QMessageBox::Yes | QMessageBox::No, this);
    msg.setWindowIcon(DIcon("compile-warning.png"));
    msg.setParent(this, Qt::Dialog);
    msg.setWindowFlags(msg.windowFlags() & (~Qt::WindowContextHelpButtonHint));
    if (msg.exec() == QMessageBox::No) goto restart;
  }
  if (!DbgSetLabelAt(wVA, utf8data.constData()))
    SimpleErrorBox(this, tr("Error!"), tr("DbgSetLabelAt failed!"));

  GuiUpdateAllViews();
}

void TraceBrowser::enableHighlightingModeSlot() {
  if (mHighlightingMode)
    mHighlightingMode = false;
  else
    mHighlightingMode = true;
  reloadData();
}

void TraceBrowser::followDisassemblySlot() {
  if (mTraceFile == nullptr || mTraceFile->Progress() < 100) return;

  duint cip = regPCEx(mTraceFile->Registers(getInitialSelection()));
  if (DbgMemIsValidReadPtr(cip))
    DbgCmdExec(QString("dis ").append(ToPtrString(cip)));
  else
    GuiAddStatusBarMessage(tr("Cannot follow %1. Address is invalid.\n")
                               .arg(ToPtrString(cip))
                               .toUtf8()
                               .constData());
}

void TraceBrowser::searchConstantSlot() {
  WordEditDialog constantDlg(this);
  constantDlg.setup(tr("Constant"), 0, sizeof(duint));
  if (constantDlg.exec() == QDialog::Accepted) {
    TraceFileSearchConstantRange(mTraceFile, constantDlg.getVal(),
                                 constantDlg.getVal());
    emit displayReferencesWidget();
  }
}

void TraceBrowser::searchMemRefSlot() {
  WordEditDialog memRefDlg(this);
  memRefDlg.setup(tr("References"), 0, sizeof(duint));
  if (memRefDlg.exec() == QDialog::Accepted) {
    TraceFileSearchMemReference(mTraceFile, memRefDlg.getVal());
    emit displayReferencesWidget();
  }
}

void TraceBrowser::updateSlot() {
  if (mTraceFile && mTraceFile->Progress() == 100)  // && this->isVisible()
  {
    if (DbgValFromString("tr.runtraceenabled()") == 1) {
      mTraceFile->purgeLastPage();
      setRowCount(mTraceFile->Length());
    }
  } else
    setRowCount(0);
  reloadData();
}

void TraceBrowser::toggleAutoDisassemblyFollowSelectionSlot() {
  mAutoDisassemblyFollowSelection = !mAutoDisassemblyFollowSelection;
}
