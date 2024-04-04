## X64Dbg

The GUI frontend open source project of A64Dbg and VMPStudio originally modified from x64dbg.

Support running on the following platforms:

 * Windows x86_64;
 * Windows arm64;
 * Intel macOS x86_64;
 * ARM macOS arm64;
 * Linux Ubuntu x86_64;
 * Linux Ubuntu arm64;

## Build

 * 1.open YunYooDbgCore.pro to build the abstract debug engine dynamic library;
 * 2.open gui/x64dbglib.pro to build the x64dbg common GUI controls static library;
 * 3.open A64Dbg.pro to build the A64Dbg main program;
 * 4.open VMPStudio.pro to build the VMPStudio main program;
 * NOTE: on Windows, 2/3/4 need the extra qmake parameter, and must select the x64 build Kit:
```
 QMAKE: -spec win32-clang-msvc
```

## DebugEngine

We make an abstraction layer for X64Dbg, you can implement the API in abstraction/*.h to customize your debug core.

## License

See ./README.X64DBG.md and the modified GPL3 license at ./LICENSE.
