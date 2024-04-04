#-------------------------------------------------
#
# The A64Dbg main program project.
#
#-------------------------------------------------

##
## Pre-defined global variables
##

CONFIG += c++17 sdk_no_version_check

gui_root = ./gui

CONFIG(debug, debug|release) {
    DIR_SUFFIX = d
} else {
    DIR_SUFFIX =
}

!contains(QMAKE_HOST.arch, x86_64) {
    X64_BIN_DIR = $$PWD/bin/x32$${DIR_SUFFIX}      # Relative BIN path, 32-bit
    X64_GEN_DIR = $$PWD/gui_build/out32$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    A64_GEN_DIR = $$PWD/gui_build/a64_out32$${DIR_SUFFIX}
    TARGET = A64Dbg
} else {
    X64_BIN_DIR = $$PWD/bin/x64$${DIR_SUFFIX}      # Relative BIN path, 64-bit
    X64_GEN_DIR = $$PWD/gui_build/out64$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    A64_GEN_DIR = $$PWD/gui_build/a64_out64$${DIR_SUFFIX}
    TARGET = A64Dbg
}

##
## QMake output directories
##
DESTDIR = $${X64_BIN_DIR}

#macx {
    OBJECTS_DIR = $${A64_GEN_DIR}
    MOC_DIR = $${A64_GEN_DIR}
    RCC_DIR = $${A64_GEN_DIR}
    UI_DIR = $${A64_GEN_DIR}
#}

##
## QT libraries
##
QT += core gui network concurrent xml

# QT5 requires widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

##
## Build flags
##
# Generate debug symbols in release mode
QMAKE_CXXFLAGS += -DWIN32_LEAN_AND_MEAN=1  # Compiler
QMAKE_LFLAGS +=   # Linker
QMAKE_CXXFLAGS_RELEASE +=   # Compiler
QMAKE_LFLAGS_RELEASE +=   # Linker

# Build as a library
#DEFINES += BUILD_LIB NOMINMAX
#TEMPLATE = lib

##
## Includes
##
INCLUDEPATH += \
    ./ \
    ./gui/Src \
    ./gui/Src/Gui \
    ./gui/Src/BasicView \
    ./gui/Src/Disassembler \
    ./gui/Src/Memory \
    ./gui/Src/Bridge \
    ./gui/Src/Global \
    ./gui/Src/Utils \
    ./gui/Src/ThirdPartyLibs/ldconvert \
    ./zydis_wrapper \
    ./zydis_wrapper/zydis/include \
    ./a64dbg \
    ./dbg \
    ./dbg/lz4 \
    $${A64_GEN_DIR} \
    $${X64_GEN_DIR}

win32 {
  QMAKE_LFLAGS_DEBUG +=
  QMAKE_LFLAGS_RELEASE +=
}

linux {
  QMAKE_CXXFLAGS += -fshort-wchar
}

##
## Libraries
##
macx {
  QMAKE_LFLAGS += -Wl,-rpath,@executable_path -Wl,-exported_symbol -Wl,_main \
    -L$${X64_BIN_DIR} -L$${X64_BIN_DIR}/A64Dbg.app/Contents/MacOS \
    -lx64dbglib -lYunYooDbgCore -framework AppKit -F$${PWD}/breakpad/mac -framework Breakpad
  SOURCES += ./bridge/bridgeobjc.mm breakpad/mac.m
  INCLUDEPATH += breakpad/mac/Breakpad.framework/Headers
} win32 {
  QMAKE_LFLAGS += /libpath:$${X64_BIN_DIR} $${PWD}/a64dbg/unimpl.obj \
  user32.lib x64dbglib.lib YunYooDbgCore.lib /libpath:$${PWD}/breakpad/win/lib \
  common.lib crash_generation_client.lib exception_handler.lib
SOURCES += breakpad/win.cpp
INCLUDEPATH += breakpad/win/include
  RC_ICONS = $${gui_root}/DBG.ico
} linux {
  QMAKE_LFLAGS_RELEASE += -Wl,--version-script=$$PWD/ld.version
  QMAKE_LFLAGS += -Wl,--no-undefined -Wl,--no-demangle @$$PWD/ld.extra.txt
  QMAKE_LIBDIR += $${X64_BIN_DIR}
  QMAKE_LIBS += -lx64dbglib -lYunYooDbgCore -ldl -lpthread -lbreakpad_client
  SOURCES += breakpad/linux.cpp
  INCLUDEPATH += breakpad/linux/include
  !contains(QMAKE_HOST.arch, x86_64) {
    QMAKE_LIBDIR += $${PWD}/breakpad/linux/arm64
  } else {
    QMAKE_LIBDIR += $${PWD}/breakpad/linux/x64
  }
}

# Resources, sources, headers, and forms
RESOURCES += \
    ./gui/resource.qrc

SOURCES += \
    ./a64dbg/a64dbg.cpp \
    ./a64dbg/HyperTraceView.cpp \
    ./a64dbg/HyperTraceSymbolTable.cpp \
    ./bridge/bridgemain.cpp \
    ./bridge/_global.cpp \
    ./gui/Src/main.cpp \
    ./gui/Src/Gui/AboutDialog.cpp \
    ./gui/Src/Gui/CPURegistersView.cpp \
    ./gui/Src/Gui/CPURegistersViewA32.cpp \
    ./gui/Src/Gui/CPURegistersViewX86.cpp \
    ./gui/Src/Gui/CPURegistersViewX64.cpp \
    ./gui/Src/Gui/RegistersView.cpp \
    ./gui/Src/Gui/RegistersViewA32.cpp \
    ./gui/Src/Gui/RegistersViewX86.cpp \
    ./gui/Src/Gui/RegistersViewX64.cpp \
    ./gui/Src/Tracer/TraceRegisters.cpp \
    ./gui/Src/Tracer/TraceWidget.cpp \
    ./gui/Src/Gui/MainWindow.cpp \
    ./gui/Src/Gui/CPUWidget.cpp \
    ./gui/Src/BasicView/Disassembly.cpp \
    ./gui/Src/Disassembler/QBeaEngine.cpp \
    ./gui/Src/Gui/CPUDisassembly.cpp \
    ./gui/Src/Gui/CPUDump.cpp \
    ./gui/Src/Gui/CPUMultiDump.cpp \
    ./gui/Src/Gui/AssembleDialog.cpp \
    ./gui/Src/Gui/EditFloatRegister.cpp \
    ./gui/Src/Bridge/Bridge.cpp \
    ./gui/Src/Gui/CPUInfoBox.cpp \
    ./gui/Src/Gui/DebugStatusLabel.cpp \
    ./gui/Src/Utils/StringUtil.cpp \
    ./gui/Src/Gui/DisassemblerGraphView.cpp \
    ./gui/Src/Gui/DisassemblyPopup.cpp \
    ./gui/Src/Tracer/TraceBrowser.cpp \
    ./gui/Src/Tracer/TraceFileReader.cpp \
    ./gui/Src/Tracer/TraceFileSearch.cpp \
    ./dbg/TraceRecord.cpp \
    ./dbg/stringutils_dbg.cpp \
    ./dbg/stringformat.cpp \
    a64dbg/DialogExecMap.cpp \
    a64dbg/HyperTraceManager.cpp
    
HEADERS += \
    ./a64dbg/a64dbg.h \
    ./a64dbg/HyperTraceView.h \
    ./a64dbg/HyperTraceSymbolTable.h \
    ./bridge/bridgemain.h \
    ./bridge/_global.h \
    ./gui/Src/main.h \
    ./gui/Src/Gui/AboutDialog.h \
    ./gui/Src/Gui/CPURegistersView.h \
    ./gui/Src/Gui/CPURegistersViewA32.h \
    ./gui/Src/Gui/CPURegistersViewX86.h \
    ./gui/Src/Gui/CPURegistersViewX64.h \
    ./gui/Src/Gui/RegistersView.h \
    ./gui/Src/Gui/RegistersViewA32.h \
    ./gui/Src/Gui/RegistersViewX86.h \
    ./gui/Src/Gui/RegistersViewX64.h \
    ./gui/Src/Tracer/TraceRegisters.h \
    ./gui/Src/Tracer/TraceWidget.h \
    ./gui/Src/Gui/MainWindow.h \
    ./gui/Src/Gui/CPUWidget.h \
    ./gui/Src/BasicView/Disassembly.h \
    ./gui/Src/Disassembler/QBeaEngine.h \
    ./gui/Src/Gui/CPUDisassembly.h \
    ./gui/Src/Gui/CPUDump.h \
    ./gui/Src/Gui/CPUMultiDump.h \
    ./gui/Src/Gui/AssembleDialog.h \
    ./gui/Src/Gui/EditFloatRegister.h \
    ./gui/Src/Bridge/Bridge.h \
    ./gui/Src/Gui/CPUInfoBox.h \
    ./gui/Src/Gui/DebugStatusLabel.h \
    ./gui/Src/Utils/StringUtil.h \
    ./gui/Src/Gui/DisassemblerGraphView.h \
    ./gui/Src/Gui/DisassemblyPopup.h \
    ./gui/Src/Tracer/TraceBrowser.h \
    ./gui/Src/Tracer/TraceFileReader.h \
    ./gui/Src/Tracer/TraceFileReaderInternal.h \
    ./gui/Src/Tracer/TraceFileSearch.h \
    ./dbg/TraceRecord.h \
    ./dbg/stringutils.h \
    ./dbg/stringformat.h \
    a64dbg/DialogExecMap.h \
    a64dbg/HyperTraceManager.h

##
## Libraries
##
LIBS +=

# Build for M1 macOS
macx {
!contains(QMAKE_HOST.arch, x86_64) {
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}}

FORMS += \
  a64dbg/DialogExecMap.ui \
  a64dbg/HyperTraceManager.ui \
  a64dbg/HyperTraceView.ui
