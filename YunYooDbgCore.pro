#-------------------------------------------------
#
# YunYoo debugengine core program project.
#
#-------------------------------------------------

##
## Pre-defined global variables
##

CONFIG += c++17 sdk_no_version_check

CONFIG(debug, debug|release) {
    DIR_SUFFIX = d
} else {
    DIR_SUFFIX =
}

!contains(QMAKE_HOST.arch, x86_64) {
    X64_BIN_DIR = $$PWD/bin/x32$${DIR_SUFFIX}      # Relative BIN path, 32-bit
    X64_GEN_DIR = $$PWD/gui_build/out32$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    TARGET = YunYooDbgCore
} else {
    X64_BIN_DIR = $$PWD/bin/x64$${DIR_SUFFIX}      # Relative BIN path, 64-bit
    X64_GEN_DIR = $$PWD/gui_build/out64$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
    TARGET = YunYooDbgCore
}

##
## QMake output directories
##
DESTDIR = $${X64_BIN_DIR}

#macx {
    OBJECTS_DIR = $${X64_GEN_DIR}
    MOC_DIR = $${X64_GEN_DIR}
    RCC_DIR = $${X64_GEN_DIR}
    UI_DIR = $${X64_GEN_DIR}
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
QMAKE_CXXFLAGS += -DWIN32_LEAN_AND_MEAN=1 -DDLLIMPL # Compiler
QMAKE_LFLAGS +=   # Linker
QMAKE_CXXFLAGS_RELEASE +=   # Compiler
QMAKE_LFLAGS_RELEASE +=   # Linker

# Build as a library
DEFINES += BUILD_LIB NOMINMAX
TEMPLATE = lib

##
## Includes
##
INCLUDEPATH += .

win32 {
  QMAKE_LFLAGS_DEBUG +=
  QMAKE_LFLAGS_RELEASE +=
}

##
## Libraries
##
macx {
  QMAKE_LFLAGS += -Xlinker -install_name -Xlinker @executable_path/libYunYooDbgCore.dylib
} win32 {
}

SOURCES += \
    ./abstraction/DebugEngine.cpp
    
HEADERS += \
    ./abstraction/CommDef.h \
    ./abstraction/DebugEngine.hpp \
    ./abstraction/Disassembler.h \
    ./abstraction/LLDBEngine.hpp \
    ./abstraction/MagicAna.hpp \
    ./abstraction/ManaFile.h \
    ./abstraction/HypertraceDef.h

##
## Libraries
##
LIBS +=

# Build for M1 macOS
macx {
!contains(QMAKE_HOST.arch, x86_64) {
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}}
