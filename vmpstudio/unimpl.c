
void abort(void);

#if __APPLE__

#define unimpl(n) \
  void __attribute__((weak)) n(void) { abort(); }

#define trueimpl(n) \
  long n(void) { return 1; }

#define falseimpl(n) \
  long n(void) { return 0; }

#define negimpl(n) \
  long n(void) { return 0; }

falseimpl(
    _ZN15ADPluginManager9sendEventE11adp_event_tPv)  // ", referenced from:
    //    __ZN9DbgGlobal9addModuleERK7QStringPN8Debugger8Internal6ModuleE in
    //    _global.o
    falseimpl(_ZN15ADPluginManager9unloadADPEv)  // ", referenced from:
    //    _main in main.o
    falseimpl(_ZN15ExtensionSystem13PluginManagerC1Ev)  // ", referenced from:
    //    __Z12_dbg_dbginitv in VMPBridgeMain.o
    falseimpl(
        _ZN15ProjectExplorer3AbiC1ERKNS0_12ArchitectureERKNS0_2OSERKNS0_8OSFlavorERKNS0_12BinaryFormatEhRK7QString)  // ", referenced from:
    //    __ZN8Debugger8Internal21DebuggerRunParametersC2Ev in VMPBridgeMain.o
    falseimpl(_ZN5Utils13ProcessHandleC1Ev)  // ", referenced from:
    //    __ZN8Debugger8Internal21DebuggerRunParametersC2Ev in VMPBridgeMain.o
    falseimpl(_ZN5Utils13ProcessHandleC1Ex)  // ", referenced from:
    //    __ZL20init_debugee_processPKc in VMPBridgeMain.o
    falseimpl(_ZN5Utils8FilePath8fromUtf8EPKci)  // ", referenced from:
    //    __ZL17init_debugee_filePKc in VMPBridgeMain.o
    falseimpl(_ZN5Utils8FilePathC1Ev)  // ", referenced from:
    //    __ZN8Debugger8Internal21DebuggerRunParametersC2Ev in VMPBridgeMain.o
    //    __ZN15ProjectExplorer8RunnableC2Ev in VMPBridgeMain.o
    falseimpl(_ZN5Zydis11DisassembleEmPKh)  // ", referenced from:
    //    __ZN14CPUDisassembly16mnemonicHelpSlotEv in CPUDisassembly.o
    //    __ZN18CPUDisassemblyFile16mnemonicHelpSlotEv in CPUDisassemblyFile.o
    //    __ZN21DisassemblerGraphView16mnemonicHelpSlotEv in
    //    DisassemblerGraphView.o
    falseimpl(_ZN5Zydis11DisassembleEmPKhi)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    falseimpl(_ZN5Zydis15DisassembleSafeEmPKhi)  // ", referenced from:
    //    __ZN10QBeaEngine15DisassembleBackEPKhyyyi in QBeaEngine.o
    //    __ZN10QBeaEngine15DisassembleNextEPKhyyyi in QBeaEngine.o
    falseimpl(_ZN5Zydis16GlobalInitializeEv)  // ", referenced from:
    //    _main in main.o
    falseimpl(_ZN5ZydisC1Ev)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    //    __ZN10QBeaEngine15DisassembleBackEPKhyyyi in QBeaEngine.o
    //    __ZN10QBeaEngine15DisassembleNextEPKhyyyi in QBeaEngine.o
    //    __ZN14CPUDisassembly16mnemonicHelpSlotEv in CPUDisassembly.o
    //    __ZN18CPUDisassemblyFile16mnemonicHelpSlotEv in CPUDisassemblyFile.o
    //    __ZN21DisassemblerGraphView16mnemonicHelpSlotEv in
    //    DisassemblerGraphView.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    //    ...
    falseimpl(_ZN5ZydisD1Ev)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    //    __ZN10QBeaEngine15DisassembleBackEPKhyyyi in QBeaEngine.o
    //    __ZN10QBeaEngine15DisassembleNextEPKhyyyi in QBeaEngine.o
    //    __ZN14CPUDisassembly16mnemonicHelpSlotEv in CPUDisassembly.o
    //    __ZN18CPUDisassemblyFile16mnemonicHelpSlotEv in CPUDisassemblyFile.o
    //    __ZN21DisassemblerGraphView16mnemonicHelpSlotEv in
    //    DisassemblerGraphView.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    //    ...
    falseimpl(
        _ZN8Debugger8Internal10LldbEngine24executeDebuggerCommandExERK7QStringNSt3__18functionIFvRKNS0_16DebuggerResponseEEEE)  // ", referenced from:
    //    __ZZL11sync_execmdPKcENK4$_26clEPv in VMPBridgeMain.o
    //    __ZZ12DbgFunctionsENK4$_24clEPP14DBGPROCESSINFOPi in VMPBridgeMain.o
    falseimpl(_ZN8Debugger8Internal10LldbEngineC1Ev)  // ", referenced from:
    //    __Z12_dbg_dbginitv in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal14BreakpointItem10setEnabledEb)  // ", referenced
                                                              // from:
    //    __ZL9bp_enablePKc in VMPBridgeMain.o
    //    __ZL10bp_disablePKc in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal14DebuggerEngine16setRunParametersERKNS0_21DebuggerRunParametersE)  // ", referenced from:
    //    __ZL17init_debugee_filePKc in VMPBridgeMain.o
    //    __ZL20init_debugee_processPKc in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal14DebuggerEngine5startEv)  // ", referenced from:
    //    __Z12_dbg_dbginitv in VMPBridgeMain.o
    falseimpl(_ZN8Debugger8Internal14DebuggerPluginC1Ev)  // ", referenced from:
    //    __Z12_dbg_dbginitv in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal14ThreadsHandler10setThreadsERKNS0_5GdbMiE)  // ",
                                                                          // referenced
                                                                          // from:
    //    __ZZL15refresh_contentPKcENK4$_27clERKN8Debugger8Internal16DebuggerResponseE
    //    in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal15DebuggerCommand3argEPKci)  // ", referenced from:
    //    __Z12_dbg_memreadyPvyPy in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal15DebuggerCommand3argEPKcy)  // ", referenced from:
    //    __Z12_dbg_memreadyPvyPy in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal17BreakpointManager25createBreakpointForEngineERKNS0_20BreakpointParametersEPNS0_14DebuggerEngineE)  // ", referenced from:
    //    __Z6bp_setPKcbS0_ in VMPBridgeMain.o
    //    __Z9watch_setPKc in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal20BreakpointParametersC1ENS0_14BreakpointTypeE)  // ", referenced from:
    //    __Z6bp_setPKcbS0_ in VMPBridgeMain.o
    //    __Z9watch_setPKc in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal20GlobalBreakpointItem10setEnabledEbb)  // ",
                                                                     // referenced
                                                                     // from:
    //    __ZL9bp_enablePKc in VMPBridgeMain.o
    //    __ZL10bp_disablePKc in VMPBridgeMain.o
    falseimpl(
        _ZN8Debugger8Internal20GlobalBreakpointItem13setParametersERKNS0_20BreakpointParametersE)  // ", referenced from:
    //    __ZL7bp_condPKc in VMPBridgeMain.o
    //    __ZL10bp_oneshotPKc in VMPBridgeMain.o
    falseimpl(_ZNK5Utils13ProcessHandle3pidEv)  // ", referenced from:
    //    __ZL20init_debugee_processPKc in VMPBridgeMain.o
    falseimpl(
        _ZNK5Utils8TreeItem18forChildrenAtLevelEiRKNSt3__18functionIFvPS0_EEE)  // ", referenced from:
    //    __ZNK5Utils9TreeModelIJNS_13TypedTreeItemIN8Debugger8Internal10ThreadItemENS_8TreeItemEEES4_EE15forItemsAtLevelILi1EZNKS3_14ThreadsHandler7threadsEvEUl8QPointerIS4_EE_EEvRKT0_
    //    in VMPBridgeMain.o
    falseimpl(_ZNK5Zydis11MemSizeNameEi)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    falseimpl(_ZNK5Zydis12IsBranchTypeEz)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    falseimpl(
        _ZNK5Zydis14ResolveOpValueEiRKNSt3__18functionIFm13ZydisRegisterEEE)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    falseimpl(_ZNK5Zydis22IsBranchGoingToExecuteEmm)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    falseimpl(_ZNK5Zydis4SizeEv)  // ", referenced from:
    //    __ZN10QBeaEngine15DisassembleBackEPKhyyyi in QBeaEngine.o
    //    __ZN10QBeaEngine15DisassembleNextEPKhyyyi in QBeaEngine.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    falseimpl(_ZNK5Zydis5IsNopEv)  // ", referenced from:
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    falseimpl(_ZNK5Zydis7AddressEv)  // ", referenced from:
    //    __ZNK14ZydisTokenizer10printValueERKNS_10TokenValueEbi in
    //    ZydisTokenizer.o
    falseimpl(_ZNK5Zydis7OpCountEv)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    falseimpl(_ZNK5Zydis7RegNameE13ZydisRegister)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    falseimpl(_ZNK5Zydis8MnemonicEv)  // ", referenced from:
    //    __ZN14CPUDisassembly16mnemonicHelpSlotEv in CPUDisassembly.o
    //    __ZN18CPUDisassemblyFile16mnemonicHelpSlotEv in CPUDisassemblyFile.o
    //    __ZN21DisassemblerGraphView16mnemonicHelpSlotEv in
    //    DisassemblerGraphView.o
    falseimpl(_ZNK5ZydisixEi)  // ", referenced from:
    //    __ZN11TraceWidget13updateInfoboxEyP15TraceFileReaderRK10REGDUMPA64 in
    //    TraceWidget.o
    //    __ZN13LocalVarsView10updateSlotEv in LocalVarsView.o
    falseimpl(
        _ZNK8Debugger8Internal12BreakHandler11breakpointsEv)  // ", referenced
                                                              // from:
    //    __Z6bp_setPKcbS0_ in VMPBridgeMain.o
    //    __Z8bp_unsetPKc in VMPBridgeMain.o
    //    __Z9watch_setPKc in VMPBridgeMain.o
    //    __Z16_dbg_bpgettypeaty in VMPBridgeMain.o
    //    __Z14_dbg_getbplist7BPXTYPEP5BPMAP in VMPBridgeMain.o
    //    _DbgGetWatchList in VMPBridgeMain.o
    //    __ZL9bp_enablePKc in VMPBridgeMain.o
    //    ...
    falseimpl(
        _ZNK8Debugger8Internal12StackHandler7frameAtEi)  // ", referenced from:
    //    __ZZ12DbgFunctionsENK3$_9clEP12DBGCALLSTACK in VMPBridgeMain.o
    //    __ZZ12DbgFunctionsENK4$_10clEy in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal12StackHandler9stackSizeEv)  // ", referenced
                                                           // from:
    //    __ZZ12DbgFunctionsENK3$_9clEP12DBGCALLSTACK in VMPBridgeMain.o
    //    __ZZ12DbgFunctionsENK4$_10clEy in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal14BreakpointItem16globalBreakpointEv)  // ",
                                                                     // referenced
                                                                     // from:
    //    __Z14_dbg_getbplist7BPXTYPEP5BPMAP in VMPBridgeMain.o
    //    _DbgGetWatchList in VMPBridgeMain.o
    //    __ZL9bp_enablePKc in VMPBridgeMain.o
    //    __ZL10bp_disablePKc in VMPBridgeMain.o
    //    __ZL7bp_condPKc in VMPBridgeMain.o
    //    __ZL10bp_oneshotPKc in VMPBridgeMain.o
    //    __ZZ12DbgFunctionsENK4$_16clE7BPXTYPEyP8BRIDGEBP in VMPBridgeMain.o
    //    ...
    falseimpl(
        _ZNK8Debugger8Internal14BreakpointItem19requestedParametersEv)  // ",
                                                                        // referenced
                                                                        // from:
    //    _DbgGetWatchList in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal14DebuggerEngine12breakHandlerEv)  // ",
                                                                 // referenced
                                                                 // from:
    //    __Z6bp_setPKcbS0_ in VMPBridgeMain.o
    //    __Z8bp_unsetPKc in VMPBridgeMain.o
    //    __Z9watch_setPKc in VMPBridgeMain.o
    //    __Z16_dbg_bpgettypeaty in VMPBridgeMain.o
    //    __Z14_dbg_getbplist7BPXTYPEP5BPMAP in VMPBridgeMain.o
    //    _DbgGetWatchList in VMPBridgeMain.o
    //    __ZL9bp_enablePKc in VMPBridgeMain.o
    //    ...
    falseimpl(
        _ZNK8Debugger8Internal14DebuggerEngine12stackHandlerEv)  // ",
                                                                 // referenced
                                                                 // from:
    //    __ZZ12DbgFunctionsENK3$_9clEP12DBGCALLSTACK in VMPBridgeMain.o
    //    __ZZ12DbgFunctionsENK4$_10clEy in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal14DebuggerEngine14threadsHandlerEv)  // ",
                                                                   // referenced
                                                                   // from:
    //    _DbgGetThreadList in VMPBridgeMain.o
    //    __ZL13switch_threadPKc in VMPBridgeMain.o
    //    __ZZL15refresh_contentPKcENK4$_27clERKN8Debugger8Internal16DebuggerResponseE
    //    in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal14DebuggerEngine5stateEv)  // ", referenced from:
    //    __Z16_dbg_isdebuggingv in VMPBridgeMain.o
    falseimpl(
        _ZNK8Debugger8Internal14ThreadsHandler13currentThreadEv)  // ",
                                                                  // referenced
                                                                  // from:
    //    _DbgGetThreadList in VMPBridgeMain.o
    falseimpl(_ZNK8Debugger8Internal5GdbMiixEPKc)  // ", referenced from:
    //    __ZZZ12DbgFunctionsENK4$_24clEPP14DBGPROCESSINFOPiENKUlRKN8Debugger8Internal16DebuggerResponseEE_clES8_
    //    in VMPBridgeMain.o
    //    __ZZ12_dbg_memreadyPvyPyENK3$_3clERKN8Debugger8Internal16DebuggerResponseE
    //    in VMPBridgeMain.o
    falseimpl(str2ld)  // ", referenced from:
//    __ZN16CPURegistersView17displayEditDialogEv in CPURegistersView.o

#endif
