macx {
} win32 {
}

INCLUDEPATH +=

HEADERS += $$PWD/VMPGlobal.h \
  $$PWD/MainWindow.h \
  $$PWD/SelectSampleDialog.h \
  $$PWD/SettingsDialog.h \
  $$PWD/AboutDialog.h \
  $$PWD/UVMSEOptionDialog.h \
  $$PWD/VDBFile.h \
  $$PWD/VMPBridgeMain.h \
  $$PWD/VMPBridge.h \
  $$PWD/CPUWidgetFile.h \
  $$PWD/CPUMultiDumpFile.h \
  $$PWD/DisassemblyFile.h \
  $$PWD/HexDumpFile.h \
  $$PWD/CPUDisassemblyFile.h \
  $$PWD/CPUDumpFile.h \
  $$PWD/FilePage.h \
  $$PWD/UVMGlobal.h \
  $$PWD/UVMTraceBrowser.h \
  $$PWD/UVMTraceFileReader.h \
  $$PWD/UVMTraceFileReaderInternal.h \
  $$PWD/UVMTraceFileSearch.h \
  $$PWD/UVMTraceRegisters.h \
  $$PWD/UVMTraceWidget.h \
  $$PWD/EditFunctionDialog.h \
  $$PWD/UrDecompiler.h \
  $$PWD/VMPSymbolView.h

SOURCES += \
  $$PWD/SelectSampleDialog.cpp \
  $$PWD/UVMSEOptionDialog.cpp \
  $$PWD/VDBFile.cpp \
  $$PWD/unimpl.c \
  $$PWD/main.cpp \
  $$PWD/VMPGlobal.cpp \
  $$PWD/MainWindow.cpp \
  $$PWD/SettingsDialog.cpp \
  $$PWD/AboutDialog.cpp \
  $$PWD/VMPBridgeMain.cpp \
  $$PWD/VMPBridge.cpp \
  $$PWD/CPUWidgetFile.cpp \
  $$PWD/CPUMultiDumpFile.cpp \
  $$PWD/DisassemblyFile.cpp \
  $$PWD/HexDumpFile.cpp \
  $$PWD/CPUDisassemblyFile.cpp \
  $$PWD/CPUDumpFile.cpp \
  $$PWD/FilePage.cpp \
  $$PWD/UVMGlobal.cpp \
  $$PWD/UVMTraceBrowser.cpp \
  $$PWD/UVMTraceFileReader.cpp \
  $$PWD/UVMTraceFileSearch.cpp \
  $$PWD/UVMTraceRegisters.cpp \
  $$PWD/UVMTraceWidget.cpp \
  $$PWD/EditFunctionDialog.cpp \
  $$PWD/UrDecompiler.cpp \
  $$PWD/VMPSymbolView.cpp

FORMS += \
  $$PWD/MainWindow.ui \
  $$PWD/SelectSampleDialog.ui \
  $$PWD/SettingsDialog.ui \
  $$PWD/AboutDialog.ui \
  $$PWD/EditFunctionDialog.ui \
  $$PWD/UVMSEOptionDialog.ui \
  $$PWD/UrDecompiler.ui \
  $$PWD/VMPSymbolView.ui
