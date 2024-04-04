##
## The VMPStudio main program project.
##

CONFIG += c++17 sdk_no_version_check

gui_root = ./gui

CONFIG(debug, debug|release) {
    DIR_SUFFIX = d
} else {
    DIR_SUFFIX =
}

!contains(QMAKE_HOST.arch, x86_64) {
} else {
}

!contains(QMAKE_HOST.arch, x86_64) {
    X64_BIN_DIR = $$PWD/bin/x32$${DIR_SUFFIX}      # Relative BIN path, 32-bit
    X64_GEN_DIR = $$PWD/gui_build/out32$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    VMP_GEN_DIR = $$PWD/gui_build/vmp_out32$${DIR_SUFFIX}
    TARGET = VMPStudio
} else {
    X64_BIN_DIR = $$PWD/bin/x64$${DIR_SUFFIX}      # Relative BIN path, 64-bit
    X64_GEN_DIR = $$PWD/gui_build/out64$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    VMP_GEN_DIR = $$PWD/gui_build/vmp_out64$${DIR_SUFFIX}
    TARGET = VMPStudio
}

##
## QMake output directories
##
DESTDIR = $${X64_BIN_DIR}

#macx {
    OBJECTS_DIR = $${VMP_GEN_DIR}
    MOC_DIR = $${VMP_GEN_DIR}
    RCC_DIR = $${VMP_GEN_DIR}
    UI_DIR = $${VMP_GEN_DIR}
#}

##
## QT libraries
##
QT += core gui network 

# QT5 requires widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

##
## Build flags
##
# Generate debug symbols in release mode
QMAKE_CXXFLAGS += -DVMP_STUDIO=1 # Compiler
QMAKE_LFLAGS +=   # Linker
QMAKE_CXXFLAGS_RELEASE +=   # Compiler
QMAKE_LFLAGS_RELEASE +=   # Linker

##
## Includes
##
INCLUDEPATH += \
    $${gui_root}/.. \
    $${gui_root}/Src \
    $${gui_root}/Src/Gui \
    $${gui_root}/Src/BasicView \
    $${gui_root}/Src/Disassembler \
    $${gui_root}/Src/Memory \
    $${gui_root}/Src/Bridge \
    $${gui_root}/Src/Global \
    $${gui_root}/Src/Utils \
    $${gui_root}/Src/ThirdPartyLibs/ldconvert \
    $${gui_root}/../zydis_wrapper \
    $${gui_root}/../zydis_wrapper/zydis/include \
    $${gui_root}/../bridge \
    ./vmpstudio \
    ./dbg \
    ./dbg/lz4 \
    ./a64dbg \
    $${VMP_GEN_DIR} \
    $${X64_GEN_DIR}

win32 {
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
  SOURCES += breakpad/mac.m
  INCLUDEPATH += breakpad/mac/Breakpad.framework/Headers
} win32 {
  QMAKE_LFLAGS += /libpath:$${X64_BIN_DIR} $${PWD}/a64dbg/unimpl.obj \
    user32.lib x64dbglib.lib YunYooDbgCore.lib /libpath:$${PWD}/breakpad/win/lib \
    common.lib crash_generation_client.lib exception_handler.lib
  SOURCES += breakpad/win.cpp
  INCLUDEPATH += breakpad/win/include
  RC_ICONS = $${gui_root}/VMP.ico
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
    $${gui_root}/resource.qrc

SOURCES += \
    $${gui_root}/Src/Disassembler/QBeaEngine.cpp \
    $${gui_root}/Src/Gui/RegistersView.cpp \
    $${gui_root}/Src/Gui/RegistersViewA32.cpp \
    $${gui_root}/Src/Gui/RegistersViewX64.cpp \
    $${gui_root}/Src/Gui/AssembleDialog.cpp \
    $${gui_root}/Src/Gui/CPUInfoBox.cpp \
    $${gui_root}/Src/Gui/DebugStatusLabel.cpp \
    $${gui_root}/Src/Utils/StringUtil.cpp \
    $${gui_root}/Src/Gui/DisassemblerGraphView.cpp \
    $${gui_root}/Src/Gui/DisassemblyPopup.cpp

HEADERS += \
    $${gui_root}/Src/Disassembler/QBeaEngine.h \
    $${gui_root}/Src/Gui/RegistersView.h \
    $${gui_root}/Src/Gui/RegistersViewA32.h \
    $${gui_root}/Src/Gui/RegistersViewX64.h \
    $${gui_root}/Src/Gui/AssembleDialog.h \
    $${gui_root}/Src/Gui/CPUInfoBox.h \
    $${gui_root}/Src/Gui/DebugStatusLabel.h \
    $${gui_root}/Src/Utils/StringUtil.h \
    $${gui_root}/Src/Gui/DisassemblerGraphView.h \
    $${gui_root}/Src/Gui/DisassemblyPopup.h

FORMS += \

include(vmpstudio/VMPStudio.pri)

##
## Libraries
##
LIBS +=

# Build for M1 macOS
macx {
!contains(QMAKE_HOST.arch, x86_64) {
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}}
