#include "TraceFileSearch.h"

#include <QCoreApplication>

#include "StringUtil.h"
#include "TraceFileReader.h"
#include "zydis_wrapper.h"

static bool inRange(duint value, duint start, duint end) {
  return value >= start && value <= end;
}

int TraceFileSearchConstantRange(TraceFileReader* file, duint start,
                                 duint end) {
  int count = 0;
  Zydis cp;
  QString title;
  if (start == end)
    title = QCoreApplication::translate("TraceFileSearch", "Constant: %1")
                .arg(ToPtrString(start));
  else
    title = QCoreApplication::translate("TraceFileSearch", "Range: %1-%2")
                .arg(ToPtrString(start))
                .arg(ToPtrString(end));
  GuiReferenceInitialize(title.toUtf8().constData());
  GuiReferenceAddColumn(sizeof(duint) * 2, QCoreApplication::translate(
                                               "TraceFileSearch", "Address")
                                               .toUtf8()
                                               .constData());
  GuiReferenceAddColumn(sizeof(duint) * 2,
                        QCoreApplication::translate("TraceFileSearch", "Index")
                            .toUtf8()
                            .constData());
  GuiReferenceAddColumn(
      100, QCoreApplication::translate("TraceFileSearch", "Disassembly")
               .toUtf8()
               .constData());
  GuiReferenceSetRowCount(0);

  auto arch = DbgGlobal::inst()->inst()->debugee->db->info.arch;
  for (unsigned long long index = 0; index < file->Length(); index++) {
    bool found = false;
#define FINDREG(v) found |= inRange(v, start, end)
    // Registers
    if (arch == mana::X86_64) {
      REGISTERCONTEXTX64 &regcontext = ((REGDUMPX64 *)file->Registers(index))->regcontext;
      FINDREG(regcontext.cax);
      FINDREG(regcontext.ccx);
      FINDREG(regcontext.cdx);
      FINDREG(regcontext.cbx);
      FINDREG(regcontext.csp);
      FINDREG(regcontext.cbp);
      FINDREG(regcontext.csi);
      FINDREG(regcontext.cdi);
      FINDREG(regcontext.cip);
      FINDREG(regcontext.r8);
      FINDREG(regcontext.r9);
      FINDREG(regcontext.r10);
      FINDREG(regcontext.r11);
      FINDREG(regcontext.r12);
      FINDREG(regcontext.r13);
      FINDREG(regcontext.r14);
      FINDREG(regcontext.r15);
    } else if (arch == mana::X86) {
      REGISTERCONTEXTX64 &regcontext = ((REGDUMPX64 *)file->Registers(index))->regcontext;
      FINDREG(regcontext.cax);
      FINDREG(regcontext.ccx);
      FINDREG(regcontext.cdx);
      FINDREG(regcontext.cbx);
      FINDREG(regcontext.csp);
      FINDREG(regcontext.cbp);
      FINDREG(regcontext.csi);
      FINDREG(regcontext.cdi);
      FINDREG(regcontext.cip);
    } else if (arch == mana::ARM) {
      REGISTERCONTEXTA32 &regcontext = ((REGDUMPA32*)file->Registers(index))->regcontext;
      FINDREG(regcontext.clr);
      FINDREG(regcontext.csp);
      FINDREG(regcontext.cip);
      for (int i = 0; !found && i < 13; i++) {
        FINDREG(regcontext.gpr[i]);
      }
    } else {
      REGISTERCONTEXTA64 &regcontext = ((REGDUMPA64*)file->Registers(index))->regcontext;
      FINDREG(regcontext.clr);
      FINDREG(regcontext.csp);
      FINDREG(regcontext.cip);
      for (int i = 0; !found && i < 30; i++) {
        FINDREG(regcontext.gpr[i]);
      }
    }
#undef FINDREG
    // Memory
    duint memAddr[MAX_MEMORY_OPERANDS];
    duint memOldContent[MAX_MEMORY_OPERANDS];
    duint memNewContent[MAX_MEMORY_OPERANDS];
    bool isValid[MAX_MEMORY_OPERANDS];
    int memAccessCount = file->MemoryAccessCount(index);
    if (memAccessCount > 0) {
      file->MemoryAccessInfo(index, memAddr, memOldContent, memNewContent,
                             isValid);
      for (size_t i = 0; i < memAccessCount; i++) {
        found |= inRange(memAddr[i], start, end);
        found |= inRange(memOldContent[i], start, end);
        found |= inRange(memNewContent[i], start, end);
      }
    }
    // Constants: TO DO
    // Populate reference view
    if (found) {
      GuiReferenceSetRowCount(count + 1);
      GuiReferenceSetCellContent(
          count, 0,
          ToPtrString(regPCEx(file->Registers(index)))
              .toUtf8()
              .constData());
      GuiReferenceSetCellContent(
          count, 1, file->getIndexText(index).toUtf8().constData());
      unsigned char opcode[16];
      int opcodeSize = 0;
      file->OpCode(index, opcode, &opcodeSize);
      cp.Disassemble(regPCEx(file->Registers(index)), opcode, opcodeSize);
      GuiReferenceSetCellContent(count, 2, cp.InstructionText(true).c_str());
      // GuiReferenceSetCurrentTaskProgress; GuiReferenceSetProgress
      count++;
    }
  }
  return count;
}

int TraceFileSearchMemReference(TraceFileReader* file, duint address) {
  int count = 0;
  Zydis cp;
  GuiReferenceInitialize(
      QCoreApplication::translate("TraceFileSearch", "Reference")
          .toUtf8()
          .constData());
  GuiReferenceAddColumn(sizeof(duint) * 2, QCoreApplication::translate(
                                               "TraceFileSearch", "Address")
                                               .toUtf8()
                                               .constData());
  GuiReferenceAddColumn(sizeof(duint) * 2,
                        QCoreApplication::translate("TraceFileSearch", "Index")
                            .toUtf8()
                            .constData());
  GuiReferenceAddColumn(
      100, QCoreApplication::translate("TraceFileSearch", "Disassembly")
               .toUtf8()
               .constData());
  GuiReferenceSetRowCount(0);

  for (unsigned long long index = 0; index < file->Length(); index++) {
    bool found = false;
    // Memory
    duint memAddr[MAX_MEMORY_OPERANDS];
    duint memOldContent[MAX_MEMORY_OPERANDS];
    duint memNewContent[MAX_MEMORY_OPERANDS];
    bool isValid[MAX_MEMORY_OPERANDS];
    int memAccessCount = file->MemoryAccessCount(index);
    if (memAccessCount > 0) {
      file->MemoryAccessInfo(index, memAddr, memOldContent, memNewContent,
                             isValid);
      for (size_t i = 0; i < memAccessCount; i++) {
        found |= inRange(memAddr[i], address, address + sizeof(duint) - 1);
      }
      // Constants: TO DO
      // Populate reference view
      if (found) {
        GuiReferenceSetRowCount(count + 1);
        GuiReferenceSetCellContent(
            count, 0,
            ToPtrString(regPCEx(file->Registers(index)))
                .toUtf8()
                .constData());
        GuiReferenceSetCellContent(
            count, 1, file->getIndexText(index).toUtf8().constData());
        unsigned char opcode[16];
        int opcodeSize = 0;
        file->OpCode(index, opcode, &opcodeSize);
        cp.Disassemble(regPCEx(file->Registers(index)), opcode,
                       opcodeSize);
        GuiReferenceSetCellContent(count, 2, cp.InstructionText(true).c_str());
        // GuiReferenceSetCurrentTaskProgress; GuiReferenceSetProgress
        count++;
      }
    }
  }
  return count;
}
