lld-link: error: undefined symbol: dyld_shared_cache_extract_dylibs_progress
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\bridge\_global.cpp:362
>>>               debug\_global.obj:(?addModule@DbgGlobal@@QEAAXAEBVQString@@PEAVModule@Internal@Debugger@@@Z)

lld-link: error: undefined symbol: __imp__NSConcreteGlobalBlock
>>> referenced by debug\_global.obj:(.block_isa_init)

lld-link: error: undefined symbol: ??0Zydis@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:100
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:50
>>>               debug\QBeaEngine.obj:(?DisassembleBack@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:137
>>>               debug\QBeaEngine.obj:(?DisassembleNext@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:11
>>>               debug\ZydisTokenizer.obj:(??0ZydisTokenizer@@QEAA@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:2039
>>>               debug\CPUDisassembly.obj:(?mnemonicHelpSlot@CPUDisassembly@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassemblyFile.cpp:1952
>>>               debug\CPUDisassemblyFile.obj:(?mnemonicHelpSlot@CPUDisassemblyFile@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\DisassemblerGraphView.cpp:2513
>>>               debug\DisassemblerGraphView.obj:(?mnemonicHelpSlot@DisassemblerGraphView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:164
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceBrowser.cpp:1366
>>>               debug\TraceBrowser.obj:(?mnemonicHelpSlot@TraceBrowser@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceFileSearch.cpp:16
>>>               debug\TraceFileSearch.obj:(?TraceFileSearchConstantRange@@YAHPEAVTraceFileReader@@_K1@Z)
>>> referenced 1 more times

lld-link: error: undefined symbol: ?Disassemble@Zydis@@QEAA_N_KPEBEH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:254
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:182
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceFileSearch.cpp:96
>>>               debug\TraceFileSearch.obj:(?TraceFileSearchConstantRange@@YAHPEAVTraceFileReader@@_K1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceFileSearch.cpp:154
>>>               debug\TraceFileSearch.obj:(?TraceFileSearchMemReference@@YAHPEAVTraceFileReader@@_K@Z)

lld-link: error: undefined symbol: ?IsBranchType@Zydis@@QEBA_NZZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:258
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:447
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:455
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:457
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:459
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:461
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:529
>>>               debug\ZydisTokenizer.obj:(?tokenizeImmOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\zydis_wrapper\zydis_wrapper.h:111
>>>               debug\ZydisTokenizer.obj:(?IsInt3@Zydis@@QEBA_NXZ)

lld-link: error: undefined symbol: ?IsBranchGoingToExecute@Zydis@@QEBA_N_K0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:259
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)

lld-link: error: undefined symbol: ?OpCount@Zydis@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:269
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:153
>>>               debug\ZydisTokenizer.obj:(?Tokenize@ZydisTokenizer@@QEAA_N_KPEBEHAEAUInstructionToken@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:188
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)

lld-link: error: undefined symbol: ?ResolveOpValue@Zydis@@QEBA_KHAEBV?$function@$$A6A_KW4ZydisRegister@@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:271
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)

lld-link: error: undefined symbol: ??AZydis@@QEBAAEBUZydisDecodedOperand@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:272
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:273
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:278
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:282
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:288
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:289
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:301
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:302
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:158
>>>               debug\ZydisTokenizer.obj:(?Tokenize@ZydisTokenizer@@QEAA_N_KPEBEHAEAUInstructionToken@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:189
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)
>>> referenced 4 more times

lld-link: error: undefined symbol: ?MemSizeName@Zydis@@QEBAPEBDH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:273
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:549
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)

lld-link: error: undefined symbol: ?RegName@Zydis@@QEBAPEBDW4ZydisRegister@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:278
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:302
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:522
>>>               debug\ZydisTokenizer.obj:(?tokenizeRegOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:566
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:597
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:603
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)

lld-link: error: undefined symbol: ??1Zydis@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:311
>>>               debug\TraceWidget.obj:(?updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceWidget.cpp:311
>>>               debug\TraceWidget.obj:(?dtor$85@?0??updateInfobox@TraceWidget@@IEAAX_KPEAVTraceFileReader@@AEBUREGDUMPA64@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:112
>>>               debug\QBeaEngine.obj:(?DisassembleBack@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:112
>>>               debug\QBeaEngine.obj:(?dtor$45@?0??DisassembleBack@QBeaEngine@@QEAAKPEBE_K11H@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:166
>>>               debug\QBeaEngine.obj:(?DisassembleNext@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:166
>>>               debug\QBeaEngine.obj:(?dtor$25@?0??DisassembleNext@QBeaEngine@@QEAAKPEBE_K11H@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.h:13
>>>               debug\QBeaEngine.obj:(??1ZydisTokenizer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:2043
>>>               debug\CPUDisassembly.obj:(?mnemonicHelpSlot@CPUDisassembly@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:2043
>>>               debug\CPUDisassembly.obj:(?dtor$12@?0??mnemonicHelpSlot@CPUDisassembly@@QEAAXXZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassemblyFile.cpp:1956
>>>               debug\CPUDisassemblyFile.obj:(?mnemonicHelpSlot@CPUDisassemblyFile@@QEAAXXZ)
>>> referenced 11 more times

lld-link: error: undefined symbol: ?GlobalInitialize@Zydis@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\main.cpp:110
>>>               debug\main.obj:(main)

lld-link: error: undefined symbol: ?DisassembleSafe@Zydis@@QEAA_N_KPEBEH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:93
>>>               debug\QBeaEngine.obj:(?DisassembleBack@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:152
>>>               debug\QBeaEngine.obj:(?DisassembleNext@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:146
>>>               debug\ZydisTokenizer.obj:(?Tokenize@ZydisTokenizer@@QEAA_N_KPEBEHAEAUInstructionToken@1@@Z)

lld-link: error: undefined symbol: ?Size@Zydis@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:97
>>>               debug\QBeaEngine.obj:(?DisassembleBack@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\QBeaEngine.cpp:155
>>>               debug\QBeaEngine.obj:(?DisassembleNext@QBeaEngine@@QEAAKPEBE_K11H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:257
>>>               debug\ZydisTokenizer.obj:(?Size@ZydisTokenizer@@QEBAHXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:586
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:185
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:217
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)

lld-link: error: undefined symbol: ?IsNop@Zydis@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:150
>>>               debug\ZydisTokenizer.obj:(?Tokenize@ZydisTokenizer@@QEAA_N_KPEBEHAEAUInstructionToken@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\LocalVarsView.cpp:183
>>>               debug\LocalVarsView.obj:(?updateSlot@LocalVarsView@@QEAAXXZ)

lld-link: error: undefined symbol: ?GetInstr@Zydis@@QEBAPEBUZydisDecodedInstruction@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:416
>>>               debug\ZydisTokenizer.obj:(?tokenizePrefix@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:534
>>>               debug\ZydisTokenizer.obj:(?tokenizeImmOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:641
>>>               debug\ZydisTokenizer.obj:(?tokenizePtrOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)

lld-link: error: undefined symbol: ?Mnemonic@Zydis@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:444
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:2041
>>>               debug\CPUDisassembly.obj:(?mnemonicHelpSlot@CPUDisassembly@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassemblyFile.cpp:1954
>>>               debug\CPUDisassemblyFile.obj:(?mnemonicHelpSlot@CPUDisassemblyFile@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\DisassemblerGraphView.cpp:2515
>>>               debug\DisassemblerGraphView.obj:(?mnemonicHelpSlot@DisassemblerGraphView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceBrowser.cpp:1369
>>>               debug\TraceBrowser.obj:(?mnemonicHelpSlot@TraceBrowser@@QEAAXXZ)

lld-link: error: undefined symbol: ?IsUnusual@Zydis@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:453
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)

lld-link: error: undefined symbol: ?IsPushPop@Zydis@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:463
>>>               debug\ZydisTokenizer.obj:(?tokenizeMnemonic@ZydisTokenizer@@AEAA_NXZ)

lld-link: error: undefined symbol: ?Address@Zydis@@QEBA_KXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:384
>>>               debug\ZydisTokenizer.obj:(?printValue@ZydisTokenizer@@AEBA?AVQString@@AEBUTokenValue@1@_NH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Disassembler\ZydisTokenizer.cpp:586
>>>               debug\ZydisTokenizer.obj:(?tokenizeMemOperand@ZydisTokenizer@@AEAA_NAEBUZydisDecodedOperand@@@Z)

lld-link: error: undefined symbol: __imp_PlaySoundA
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:975
>>>               debug\CPUDisassembly.obj:(?setCommentSlot@CPUDisassembly@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassemblyFile.cpp:885
>>>               debug\CPUDisassemblyFile.obj:(?setCommentSlot@CPUDisassemblyFile@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceBrowser.cpp:1738
>>>               debug\TraceBrowser.obj:(?setCommentSlot@TraceBrowser@@QEAAXXZ)

lld-link: error: undefined symbol: ?Disassemble@Zydis@@QEAA_N_KQEBE@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassembly.cpp:2040
>>>               debug\CPUDisassembly.obj:(?mnemonicHelpSlot@CPUDisassembly@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\CPUDisassemblyFile.cpp:1953
>>>               debug\CPUDisassemblyFile.obj:(?mnemonicHelpSlot@CPUDisassemblyFile@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Gui\DisassemblerGraphView.cpp:2514
>>>               debug\DisassemblerGraphView.obj:(?mnemonicHelpSlot@DisassemblerGraphView@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceBrowser.cpp:1367
>>>               debug\TraceBrowser.obj:(?mnemonicHelpSlot@TraceBrowser@@QEAAXXZ)

lld-link: error: undefined symbol: ?InstructionText@Zydis@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceFileSearch.cpp:97
>>>               debug\TraceFileSearch.obj:(?TraceFileSearchConstantRange@@YAHPEAVTraceFileReader@@_K1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\gui\Src\Tracer\TraceFileSearch.cpp:156
>>>               debug\TraceFileSearch.obj:(?TraceFileSearchMemReference@@YAHPEAVTraceFileReader@@_K@Z)

lld-link: error: undefined symbol: ?openEditor@EditorManager@Core@@SAPEAVIEditor@2@AEBVQString@@VId@Utils@@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\breakhandler.cpp:1412
>>>               debug\breakhandler.obj:(?gotoLocation@BreakHandler@Internal@Debugger@@AEBAXAEBV?$QPointer@VBreakpointItem@Internal@Debugger@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\breakhandler.cpp:2530
>>>               debug\breakhandler.obj:(?gotoLocation@BreakpointManager@Internal@Debugger@@AEBAXAEBV?$QPointer@VGlobalBreakpointItem@Internal@Debugger@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\imageviewer.cpp:139
>>>               debug\imageviewer.obj:(?openImageViewer@@YAXAEBVQImage@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\basefilewizardfactory.cpp:187
>>>               debug\basefilewizardfactory.obj:(?postGenerateOpenEditors@BaseFileWizardFactory@Core@@KA_NAEBV?$QList@VGeneratedFile@Core@@@@PEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsreuse.cpp:244
>>>               debug\cpptoolsreuse.obj:(?switchHeaderSource@CppTools@@YAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttreewidget.cpp:496
>>>               debug\projecttreewidget.obj:(?openItem@ProjectTreeWidget@Internal@ProjectExplorer@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:643
>>>               debug\foldernavigationwidget.obj:(?openItem@FolderNavigationWidget@Internal@ProjectExplorer@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1125
>>>               debug\vcsbaseeditor.obj:(?jumpToChangeFromDiff@VcsBaseEditorWidget@VcsBase@@AEAAXVQTextCursor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsoutputwindow.cpp:209
>>>               debug\vcsoutputwindow.obj:(?contextMenuEvent@OutputWindowPlainTextEdit@Internal@VcsBase@@MEAAXPEAVQContextMenuEvent@@@Z)

lld-link: error: undefined symbol: ??0RegisterPostMortemAction@Internal@Debugger@@QEAA@PEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggeractions.cpp:560
>>>               debug\debuggeractions.obj:(??0DebuggerSettings@Internal@Debugger@@QEAA@XZ)

lld-link: error: undefined symbol: ?kit@KitManager@ProjectExplorer@@SAPEAVKit@2@VId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerdialogs.cpp:163
>>>               debug\debuggerdialogs.obj:(?displayName@StartApplicationParameters@Internal@Debugger@@QEBA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1278
>>>               debug\debuggerplugin.obj:(?parseArgument@DebuggerPluginPrivate@Internal@Debugger@@QEAA_NAEAVconst_iterator@?$QList@VQString@@@@AEBV45@PEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwindow.cpp:568
>>>               debug\projectwindow.obj:(?handleImportBuild@ProjectWindowPrivate@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwindow.cpp:545
>>>               debug\projectwindow.obj:(?handleManageKits@ProjectWindowPrivate@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:526
>>>               debug\targetsetuppage.obj:(?import@TargetSetupPage@ProjectExplorer@@AEAAXAEBVFilePath@Utils@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:80
>>>               debug\kitchooser.obj:(?onCurrentIndexChanged@KitChooser@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:144
>>>               debug\kitchooser.obj:(?currentKit@KitChooser@ProjectExplorer@@QEBAPEAVKit@2@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:792
>>>               debug\target.obj:(?fromMap@Target@ProjectExplorer@@AEAA_NAEBV?$QMap@VQString@@VQVariant@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsettingspanel.cpp:271
>>>               debug\targetsettingspanel.obj:(?data@TargetItem@Internal@ProjectExplorer@@UEBA?AVQVariant@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsettingspanel.cpp:276
>>>               debug\targetsettingspanel.obj:(?data@TargetItem@Internal@ProjectExplorer@@UEBA?AVQVariant@@HH@Z)
>>> referenced 5 more times

lld-link: error: undefined symbol: ?extensionLibraryName@CdbEngine@Internal@Debugger@@SA?AVQString@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerdialogs.cpp:597
>>>               debug\debuggerdialogs.obj:(?cdbRemoteHelp@Internal@Debugger@@YA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerdialogs.cpp:599
>>>               debug\debuggerdialogs.obj:(?cdbRemoteHelp@Internal@Debugger@@YA?AVQString@@XZ)

lld-link: error: undefined symbol: ?currentTextEditor@BaseTextEditor@TextEditor@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:192
>>>               debug\debuggerengine.obj:(?dragToLine@LocationMark@Internal@Debugger@@EEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2383
>>>               debug\debuggerengine.obj:(?handleExecRunToLine@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2391
>>>               debug\debuggerengine.obj:(?handleExecRunToSelectedFunction@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2374
>>>               debug\debuggerengine.obj:(?handleExecJumpToLine@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2422
>>>               debug\debuggerengine.obj:(?handleAddToWatchWindow@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1888
>>>               debug\debuggerplugin.obj:(?toggleBreakpointHelper@DebuggerPluginPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:986
>>>               debug\debuggertooltipmanager.obj:(?updateVisibleToolTips@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:457
>>>               debug\debuggertooltipmanager.obj:(?leaveEvent@DebuggerToolTipWidget@Internal@Debugger@@UEAAXPEAVQEvent@@@Z)

lld-link: error: undefined symbol: ?textDocument@BaseTextEditor@TextEditor@@QEBAPEAVTextDocument@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:193
>>>               debug\debuggerengine.obj:(?dragToLine@LocationMark@Internal@Debugger@@EEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2384
>>>               debug\debuggerengine.obj:(?handleExecRunToLine@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2375
>>>               debug\debuggerengine.obj:(?handleExecJumpToLine@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1891
>>>               debug\debuggerplugin.obj:(?toggleBreakpointHelper@DebuggerPluginPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:2044
>>>               debug\debuggerplugin.obj:(?openTextEditor@Internal@Debugger@@YAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:992
>>>               debug\debuggertooltipmanager.obj:(?updateVisibleToolTips@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:117
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:128
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:293
>>>               debug\highlighter.obj:(?reload@Highlighter@TextEditor@@SAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:408
>>>               debug\cppincludehierarchy.obj:(?perform@CppIncludeHierarchyWidget@Internal@CppEditor@@QEAAXXZ)
>>> referenced 3 more times

lld-link: error: undefined symbol: ?textCursor@BaseTextEditor@TextEditor@@QEBA?AVQTextCursor@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2393
>>>               debug\debuggerengine.obj:(?handleExecRunToSelectedFunction@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2424
>>>               debug\debuggerengine.obj:(?handleAddToWatchWindow@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:129
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1249
>>>               debug\vcsbaseeditor.obj:(?lineNumberOfCurrentEditor@VcsBaseEditor@VcsBase@@SAHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?editorWidget@BaseTextEditor@TextEditor@@QEBAPEAVTextEditorWidget@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:2430
>>>               debug\debuggerengine.obj:(?handleAddToWatchWindow@DebuggerEngine@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1001
>>>               debug\debuggertooltipmanager.obj:(?updateVisibleToolTips@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1249
>>>               debug\debuggertooltipmanager.obj:(?slotEditorOpened@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXPEAVIEditor@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1294
>>>               debug\debuggertooltipmanager.obj:(?leavingDebugMode@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1295
>>>               debug\debuggertooltipmanager.obj:(?leavingDebugMode@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:458
>>>               debug\debuggertooltipmanager.obj:(?leaveEvent@DebuggerToolTipWidget@Internal@Debugger@@UEAAXPEAVQEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:101
>>>               debug\sourceagent.obj:(?setContent@SourceAgent@Internal@Debugger@@QEAAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:107
>>>               debug\sourceagent.obj:(?setContent@SourceAgent@Internal@Debugger@@QEAAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:295
>>>               debug\highlighter.obj:(?reload@Highlighter@TextEditor@@SAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:242
>>>               debug\editorconfiguration.obj:(?configureEditor@EditorConfiguration@ProjectExplorer@@QEBAXPEAVBaseTextEditor@TextEditor@@@Z)
>>> referenced 4 more times

lld-link: error: undefined symbol: ?closeDocuments@EditorManager@Core@@SA_NAEBV?$QList@PEAVIDocument@Core@@@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerengine.cpp:1628
>>>               debug\debuggerengine.obj:(?cleanupViews@DebuggerEnginePrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:141
>>>               debug\disassembleragent.obj:(??1DisassemblerAgentPrivate@Internal@Debugger@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\memoryagent.cpp:272
>>>               debug\memoryagent.obj:(??1MemoryAgent@Internal@Debugger@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:68
>>>               debug\sourceagent.obj:(??1SourceAgentPrivate@Internal@Debugger@@QEAA@XZ)

lld-link: error: undefined symbol: ??0KitAspect@ProjectExplorer@@IEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerkitinformation.cpp:138
>>>               debug\debuggerkitinformation.obj:(??0DebuggerKitAspect@Debugger@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:104
>>>               debug\kitinformation.obj:(??0SysRootKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:313
>>>               debug\kitinformation.obj:(??0ToolChainKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:696
>>>               debug\kitinformation.obj:(??0DeviceTypeKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:828
>>>               debug\kitinformation.obj:(??0DeviceKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:1086
>>>               debug\kitinformation.obj:(??0EnvironmentKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:148
>>>               debug\qtkitinformation.obj:(??0QtKitAspect@QtSupport@@QEAA@XZ)

lld-link: error: undefined symbol: ??1KitAspect@ProjectExplorer@@MEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerkitinformation.cpp:144
>>>               debug\debuggerkitinformation.obj:(?dtor$7@?0???0DebuggerKitAspect@Debugger@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerkitinformation.h:37
>>>               debug\debuggerkitinformation.obj:(??1DebuggerKitAspect@Debugger@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:112
>>>               debug\kitinformation.obj:(?dtor$7@?0???0SysRootKitAspect@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:325
>>>               debug\kitinformation.obj:(?dtor$9@?0???0ToolChainKitAspect@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:703
>>>               debug\kitinformation.obj:(?dtor$7@?0???0DeviceTypeKitAspect@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:837
>>>               debug\kitinformation.obj:(?dtor$9@?0???0DeviceKitAspect@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:1093
>>>               debug\kitinformation.obj:(?dtor$7@?0???0EnvironmentKitAspect@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.h:47
>>>               debug\kitinformation.obj:(??1SysRootKitAspect@ProjectExplorer@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.h:68
>>>               debug\kitinformation.obj:(??1ToolChainKitAspect@ProjectExplorer@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.h:115
>>>               debug\kitinformation.obj:(??1DeviceTypeKitAspect@ProjectExplorer@@UEAA@XZ)
>>> referenced 4 more times

lld-link: error: undefined symbol: ??0KitAspectWidget@ProjectExplorer@@QEAA@PEAVKit@1@PEBVKitAspect@1@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerkitinformation.cpp:61
>>>               debug\debuggerkitinformation.obj:(??0DebuggerKitAspectWidget@Internal@Debugger@@QEAA@PEAVKit@ProjectExplorer@@PEBVKitAspect@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:72
>>>               debug\kitinformation.obj:(??0SysRootKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:203
>>>               debug\kitinformation.obj:(??0ToolChainKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:658
>>>               debug\kitinformation.obj:(??0DeviceTypeKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:764
>>>               debug\kitinformation.obj:(??0DeviceKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:997
>>>               debug\kitinformation.obj:(??0EnvironmentKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:55
>>>               debug\qtkitinformation.obj:(??0QtKitAspectWidget@Internal@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@PEBVKitAspect@4@@Z)

lld-link: error: undefined symbol: ?msgManage@KitAspectWidget@ProjectExplorer@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerkitinformation.cpp:72
>>>               debug\debuggerkitinformation.obj:(??0DebuggerKitAspectWidget@Internal@Debugger@@QEAA@PEAVKit@ProjectExplorer@@PEBVKitAspect@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetupwidget.cpp:74
>>>               debug\targetsetupwidget.obj:(??0TargetSetupWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:54
>>>               debug\kitchooser.obj:(??0KitChooser@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:237
>>>               debug\kitinformation.obj:(??0ToolChainKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:768
>>>               debug\kitinformation.obj:(??0DeviceKitAspectWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@PEBVKitAspect@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:65
>>>               debug\qtkitinformation.obj:(??0QtKitAspectWidget@Internal@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@PEBVKitAspect@4@@Z)

lld-link: error: undefined symbol: ?weight@KitAspect@ProjectExplorer@@UEBAHPEBVKit@2@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7ToolChainKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceTypeKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?addToEnvironment@KitAspect@ProjectExplorer@@UEBAXPEBVKit@2@AEAVEnvironment@Utils@@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceTypeKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?createOutputParsers@KitAspect@ProjectExplorer@@UEBA?AV?$QList@PEAVOutputLineParser@Utils@@@@PEBVKit@2@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceTypeKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?displayNamePostfix@KitAspect@ProjectExplorer@@UEBA?AVQString@@PEBVKit@2@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceTypeKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?supportedPlatforms@KitAspect@ProjectExplorer@@UEBA?AV?$QSet@VId@Utils@@@@PEBVKit@2@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7ToolChainKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?availableFeatures@KitAspect@ProjectExplorer@@UEBA?AV?$QSet@VId@Utils@@@@PEBVKit@2@@Z
>>> referenced by debug\debuggerkitinformation.obj:(??_7DebuggerKitAspect@Debugger@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7SysRootKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7DeviceKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ??0EditorManagerPlaceHolder@Core@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggermainwindow.cpp:196
>>>               debug\debuggermainwindow.obj:(??0DebuggerMainWindowPrivate@Utils@@QEAA@PEAVDebuggerMainWindow@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editmode.cpp:61
>>>               debug\editmode.obj:(??0EditMode@Internal@Core@@QEAA@XZ)

lld-link: error: undefined symbol: ??0Console@Internal@Debugger@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:730
>>>               debug\debuggerplugin.obj:(??0DebuggerPluginPrivate@Internal@Debugger@@QEAA@AEBVQStringList@@@Z)

lld-link: error: undefined symbol: ??1Console@Internal@Debugger@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1202
>>>               debug\debuggerplugin.obj:(?dtor$75@?0???0DebuggerPluginPrivate@Internal@Debugger@@QEAA@AEBVQStringList@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1207
>>>               debug\debuggerplugin.obj:(??1DebuggerPluginPrivate@Internal@Debugger@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1207
>>>               debug\debuggerplugin.obj:(?dtor$11@?0???1DebuggerPluginPrivate@Internal@Debugger@@UEAA@XZ@4HA)

lld-link: error: undefined symbol: ?kit@KitManager@ProjectExplorer@@SAPEAVKit@2@AEBV?$function@$$A6A_NPEBVKit@ProjectExplorer@@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1279
>>>               debug\debuggerplugin.obj:(?parseArgument@DebuggerPluginPrivate@Internal@Debugger@@QEAA_NAEAVconst_iterator@?$QList@VQString@@@@AEBV45@PEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1219
>>>               debug\debuggerplugin.obj:(?guessKitFromAbis@Internal@Debugger@@YAPEAVKit@ProjectExplorer@@AEBV?$QVector@VAbi@ProjectExplorer@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1225
>>>               debug\debuggerplugin.obj:(?guessKitFromAbis@Internal@Debugger@@YAPEAVKit@ProjectExplorer@@AEBV?$QVector@VAbi@ProjectExplorer@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:557
>>>               debug\debuggerplugin.obj:(?findUniversalCdbKit@Internal@Debugger@@YAPEAVKit@ProjectExplorer@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:559
>>>               debug\debuggerplugin.obj:(?findUniversalCdbKit@Internal@Debugger@@YAPEAVKit@ProjectExplorer@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:422
>>>               debug\targetsetuppage.obj:(?updateVisibility@TargetSetupPage@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?defaultKit@KitManager@ProjectExplorer@@SAPEAVKit@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1235
>>>               debug\debuggerplugin.obj:(?guessKitFromAbis@Internal@Debugger@@YAPEAVKit@ProjectExplorer@@AEBV?$QVector@VAbi@ProjectExplorer@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\unstartedappwatcherdialog.cpp:106
>>>               debug\unstartedappwatcherdialog.obj:(??0UnstartedAppWatcherDialog@Internal@Debugger@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\unstartedappwatcherdialog.cpp:107
>>>               debug\unstartedappwatcherdialog.obj:(??0UnstartedAppWatcherDialog@Internal@Debugger@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectimporter.cpp:174
>>>               debug\projectimporter.obj:(?preferredTarget@ProjectImporter@ProjectExplorer@@UEAAPEAVTarget@2@AEBV?$QList@PEAVTarget@ProjectExplorer@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:376
>>>               debug\targetsetuppage.obj:(?selectAtLeastOneEnabledKit@TargetSetupPage@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:183
>>>               debug\kitmanagerconfigwidget.obj:(?discard@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:198
>>>               debug\kitmanagerconfigwidget.obj:(?isDirty@KitManagerConfigWidget@Internal@ProjectExplorer@@QEBA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmodel.cpp:310
>>>               debug\kitmodel.obj:(?changeDefaultKit@KitModel@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\project.cpp:261
>>>               debug\project.obj:(?addTargetForDefaultKit@Project@ProjectExplorer@@QEAAPEAVTarget@2@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\uicgenerator.cpp:59
>>>               debug\uicgenerator.obj:(?command@UicGenerator@QtSupport@@MEBA?AVFilePath@Utils@@XZ)
>>> referenced 1 more times

lld-link: error: undefined symbol: ?canRunStartupProject@ProjectExplorerPlugin@ProjectExplorer@@SA_NVId@Utils@@PEAVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1405
>>>               debug\debuggerplugin.obj:(?updatePresetState@DebuggerPluginPrivate@Internal@Debugger@@QEAAXXZ)

lld-link: error: undefined symbol: ?fromEditor@TextEditorWidget@TextEditor@@SAPEAV12@PEBVIEditor@Core@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1778
>>>               debug\debuggerplugin.obj:(?editorOpened@DebuggerPluginPrivate@Internal@Debugger@@QEAAXPEAVIEditor@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:284
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:244
>>>               debug\disassembleragent.obj:(?configureMimeType@DisassemblerAgentPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:714
>>>               debug\texteditoractionhandler.obj:(??0TextEditorActionHandler@TextEditor@@QEAA@VId@Utils@@0IAEBV?$function@$$A6APEAVTextEditorWidget@TextEditor@@PEAVIEditor@Core@@@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:134
>>>               debug\refactoringchanges.obj:(?openEditor@RefactoringChanges@TextEditor@@KAPEAVTextEditorWidget@2@AEBVQString@@_NHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:161
>>>               debug\refactoringchanges.obj:(??0RefactoringFile@TextEditor@@IEAA@AEBVQString@@AEBV?$QSharedPointer@VRefactoringChangesData@TextEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:270
>>>               debug\editorconfiguration.obj:(?setUseGlobalSettings@EditorConfiguration@ProjectExplorer@@QEAAX_N@Z)

lld-link: error: undefined symbol: ?textDocument@TextEditorWidget@TextEditor@@QEBAPEAVTextDocument@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1900
>>>               debug\debuggerplugin.obj:(?requestMark@DebuggerPluginPrivate@Internal@Debugger@@QEAAXPEAVTextEditorWidget@TextEditor@@HW4TextMarkRequestKind@5@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1794
>>>               debug\debuggerplugin.obj:(?requestContextMenu@DebuggerPluginPrivate@Internal@Debugger@@QEAAXPEAVTextEditorWidget@TextEditor@@HPEAVQMenu@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1163
>>>               debug\debuggertooltipmanager.obj:(?slotTooltipOverrideRequested@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXPEAVTextEditorWidget@TextEditor@@AEBVQPoint@@HPEA_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceutils.cpp:231
>>>               debug\sourceutils.obj:(?cppExpressionAt@Internal@Debugger@@YA?AVQString@@PEAVTextEditorWidget@TextEditor@@HPEAH1PEAV3@11@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:51
>>>               debug\plaintexteditorfactory.obj:(?finalizeInitialization@PlainTextEditorWidget@TextEditor@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:153
>>>               debug\refactoringchanges.obj:(??0RefactoringFile@TextEditor@@IEAA@PEAVTextEditorWidget@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:361
>>>               debug\refactoringchanges.obj:(?indentOrReindent@RefactoringFile@TextEditor@@IEAAXP8RefactoringChangesData@2@EBAXAEBVQTextCursor@@AEBVQString@@PEBVTextDocument@2@@ZAEBV?$QVector@U?$QPair@VQTextCursor@@V1@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:197
>>>               debug\codeassistant.obj:(?requestProposal@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistReason@2@W4AssistKind@2@PEAVIAssistProvider@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:199
>>>               debug\codeassistant.obj:(?requestProposal@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistReason@2@W4AssistKind@2@PEAVIAssistProvider@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:201
>>>               debug\codeassistant.obj:(?requestProposal@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistReason@2@W4AssistKind@2@PEAVIAssistProvider@2@@Z)
>>> referenced 60 more times

lld-link: error: undefined symbol: ?projectExplorerSettings@ProjectExplorerPlugin@ProjectExplorer@@SAAEBVProjectExplorerSettings@Internal@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:1923
>>>               debug\debuggerplugin.obj:(?updateDebugWithoutDeployMenu@DebuggerPluginPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\userfileaccessor.cpp:310
>>>               debug\userfileaccessor.obj:(??0UserFileAccessor@Internal@ProjectExplorer@@QEAA@PEAVProject@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:97
>>>               debug\buildmanager.obj:(?queue@ProjectExplorer@@YAHAEBV?$QList@PEAVProject@ProjectExplorer@@@@AEBV?$QList@VId@Utils@@@@W4ConfigSelection@1@PEBVRunConfiguration@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:342
>>>               debug\buildmanager.obj:(?deployProjects@BuildManager@ProjectExplorer@@SAXAEBV?$QList@PEAVProject@ProjectExplorer@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:352
>>>               debug\buildmanager.obj:(?potentiallyBuildForRunConfig@BuildManager@ProjectExplorer@@SA?AW4BuildForRunConfigStatus@2@PEAVRunConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:655
>>>               debug\buildmanager.obj:(?nextBuildQueue@BuildManager@ProjectExplorer@@CAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:743
>>>               debug\buildmanager.obj:(?buildQueueAppend@BuildManager@ProjectExplorer@@CA_NAEBV?$QList@PEAVBuildStep@ProjectExplorer@@@@VQStringList@@AEBV4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:631
>>>               debug\target.obj:(?updateDefaultRunConfigurations@Target@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\abstractprocessstep.cpp:229
>>>               debug\abstractprocessstep.obj:(?doRun@AbstractProcessStep@ProjectExplorer@@MEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\runconfigurationaspects.cpp:112
>>>               debug\runconfigurationaspects.obj:(?calculateUseTerminal@TerminalAspect@ProjectExplorer@@AEAAXXZ)
>>> referenced 2 more times

lld-link: error: undefined symbol: ?createSearchableWrapper@ItemViewFind@Core@@SAPEAVQFrame@@PEAVQAbstractItemView@@W4ColorOption@12@W4FetchOption@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:2018
>>>               debug\debuggerplugin.obj:(?addSearch@DebuggerPluginPrivate@Internal@Debugger@@QEAAPEAVQWidget@@PEAVBaseTreeView@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppoutline.cpp:100
>>>               debug\cppoutline.obj:(??0CppOutlineWidget@Internal@CppEditor@@QEAA@PEAVCppEditorWidget@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:117
>>>               debug\cpptypehierarchy.obj:(??0CppTypeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\environmentwidget.cpp:227
>>>               debug\environmentwidget.obj:(??0EnvironmentWidget@ProjectExplorer@@QEAA@PEAVQWidget@@W4Type@01@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttreewidget.cpp:220
>>>               debug\projecttreewidget.obj:(??0ProjectTreeWidget@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsoutline.cpp:122
>>>               debug\qmljsoutline.obj:(??0QmlJSOutlineWidget@Internal@QmlJSEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?openEditorWithContents@EditorManager@Core@@SAPEAVIEditor@2@VId@Utils@@PEAVQString@@AEBVQByteArray@@AEBV6@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:2038
>>>               debug\debuggerplugin.obj:(?openTextEditor@Internal@Debugger@@YAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:281
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:93
>>>               debug\sourceagent.obj:(?setContent@SourceAgent@Internal@Debugger@@QEAAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:692
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:703
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:217
>>>               debug\vcsbaseclient.obj:(?createVcsEditor@VcsBaseClientImpl@VcsBase@@QEBAPEAVVcsBaseEditorWidget@2@VId@Utils@@VQString@@AEBV6@PEAVQTextCodec@@PEBD2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditorcontroller.cpp:75
>>>               debug\diffeditorcontroller.obj:(?findOrCreateDocument@DiffEditorController@DiffEditor@@SAPEAVIDocument@Core@@AEBVQString@@0@Z)

lld-link: error: undefined symbol: ?setFallbackSaveAsFileName@TextDocument@TextEditor@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerplugin.cpp:2044
>>>               debug\debuggerplugin.obj:(?openTextEditor@Internal@Debugger@@YAXAEBVQString@@0@Z)

lld-link: error: undefined symbol: ?createGdbEngine@Internal@Debugger@@YAPEAVDebuggerEngine@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:553
>>>               debug\debuggerruncontrol.obj:(?start@DebuggerRunTool@Debugger@@UEAAXXZ)

lld-link: error: undefined symbol: ?createCdbEngine@Internal@Debugger@@YAPEAVDebuggerEngine@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:560
>>>               debug\debuggerruncontrol.obj:(?start@DebuggerRunTool@Debugger@@UEAAXXZ)

lld-link: error: undefined symbol: ?createUvscEngine@Internal@Debugger@@YAPEAVDebuggerEngine@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:570
>>>               debug\debuggerruncontrol.obj:(?start@DebuggerRunTool@Debugger@@UEAAXXZ)

lld-link: error: undefined symbol: ?createQmlEngine@Internal@Debugger@@YAPEAVDebuggerEngine@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:587
>>>               debug\debuggerruncontrol.obj:(?start@DebuggerRunTool@Debugger@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:589
>>>               debug\debuggerruncontrol.obj:(?start@DebuggerRunTool@Debugger@@UEAAXXZ)

lld-link: error: undefined symbol: ?printItem@Console@Internal@Debugger@@QEAAXW4ItemType@ConsoleItem@23@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:984
>>>               debug\debuggerruncontrol.obj:(?showMessage@DebuggerRunTool@Debugger@@QEAAXAEBVQString@@HH@Z)

lld-link: error: undefined symbol: ?qtPackageSourcePath@BaseQtVersion@QtSupport@@QEBA?AVFilePath@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:898
>>>               debug\debuggerruncontrol.obj:(??0DebuggerRunTool@Debugger@@QEAA@PEAVRunControl@ProjectExplorer@@W4AllowTerminal@01@@Z)

lld-link: error: undefined symbol: ?createPdbEngine@Internal@Debugger@@YAPEAVDebuggerEngine@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:954
>>>               debug\debuggerruncontrol.obj:(??0DebuggerRunTool@Debugger@@QEAA@PEAVRunControl@ProjectExplorer@@W4AllowTerminal@01@@Z)

lld-link: error: undefined symbol: ?startRunControl@ProjectExplorerPlugin@ProjectExplorer@@SAXPEAVRunControl@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggerruncontrol.cpp:960
>>>               debug\debuggerruncontrol.obj:(?startRunControl@DebuggerRunTool@Debugger@@QEAAXXZ)

lld-link: error: undefined symbol: ?toolTipPosition@TextEditorWidget@TextEditor@@QEBA?AVQPoint@@AEBVQTextCursor@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:893
>>>               debug\debuggertooltipmanager.obj:(?positionShow@DebuggerToolTipHolder@Internal@Debugger@@QEAAXPEBVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppfunctiondecldeflink.cpp:287
>>>               debug\cppfunctiondecldeflink.obj:(?apply@FunctionDeclDefLink@Internal@CppEditor@@QEAAXPEAVCppEditorWidget@23@_N@Z)

lld-link: error: undefined symbol: ?convertPosition@TextEditorWidget@TextEditor@@QEBAXHPEAH0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1170
>>>               debug\debuggertooltipmanager.obj:(?slotTooltipOverrideRequested@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXPEAVTextEditorWidget@TextEditor@@AEBVQPoint@@HPEA_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppeditoroutline.cpp:171
>>>               debug\cppeditoroutline.obj:(?modelIndex@CppEditorOutline@CppTools@@QEAA?AVQModelIndex@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppelementevaluator.cpp:364
>>>               debug\cppelementevaluator.obj:(?execute@CppElementEvaluator@CppTools@@AEAA?AV?$QFuture@V?$QSharedPointer@VCppElement@CppTools@@@@@@P812@EAA?AV3@AEBVSnapshot@CPlusPlus@@AEBVLookupItem@5@AEBVLookupContext@5@@Z@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:881
>>>               debug\vcsbaseeditor.obj:(?slotJumpToEntry@VcsBaseEditorWidget@VcsBase@@AEAAXH@Z)

lld-link: error: undefined symbol: ?instance@EditorManager@Core@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1265
>>>               debug\debuggertooltipmanager.obj:(?debugModeEntered@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\debuggertooltipmanager.cpp:1299
>>>               debug\debuggertooltipmanager.obj:(?leavingDebugMode@DebuggerToolTipManagerPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:57
>>>               debug\openeditorsview.obj:(??0OpenEditorsWidget@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\designmode.cpp:88
>>>               debug\designmode.obj:(??0DesignMode@Core@@AEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:292
>>>               debug\editortoolbar.obj:(?setToolbarCreationFlags@EditorToolBar@Core@@QEAAXW4ToolbarCreationFlags@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:207
>>>               debug\texteditoractionhandler.obj:(??0TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAA@VId@Utils@@0I@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinfiles.cpp:57
>>>               debug\findinfiles.obj:(??0FindInFiles@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findincurrentfile.cpp:43
>>>               debug\findincurrentfile.obj:(??0FindInCurrentFile@Internal@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinopenfiles.cpp:42
>>>               debug\findinopenfiles.obj:(??0FindInOpenFiles@Internal@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinopenfiles.cpp:44
>>>               debug\findinopenfiles.obj:(??0FindInOpenFiles@Internal@TextEditor@@QEAA@XZ)
>>> referenced 22 more times

lld-link: error: undefined symbol: ?removeMark@TextDocument@TextEditor@@QEAAXPEAVTextMark@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:196
>>>               debug\disassembleragent.obj:(?resetLocation@DisassemblerAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:319
>>>               debug\disassembleragent.obj:(?updateLocationMarker@DisassemblerAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:339
>>>               debug\disassembleragent.obj:(?removeBreakpointMarker@DisassemblerAgent@Internal@Debugger@@QEAAXAEBV?$QPointer@VBreakpointItem@Internal@Debugger@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:117
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:96
>>>               debug\textmark.obj:(??1TextMark@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:546
>>>               debug\qmljseditordocument.obj:(?cleanMarks@Internal@QmlJSEditor@@YAXPEAV?$QVector@PEAVTextMark@TextEditor@@@@PEAVTextDocument@TextEditor@@@Z)

lld-link: error: undefined symbol: ?setReadOnly@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:285
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:713
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:160
>>>               debug\vcsbaseeditor.obj:(?finalizeInitialization@VcsBaseEditor@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:750
>>>               debug\vcsbaseeditor.obj:(?setForceReadOnly@VcsBaseEditorWidget@VcsBase@@QEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:151
>>>               debug\diffeditor.obj:(??0DiffEditor@Internal@0@AEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:640
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:650
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:62
>>>               debug\unifieddiffeditorwidget.obj:(??0UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setRequestMarkEnabled@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:286
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:102
>>>               debug\sourceagent.obj:(?setContent@SourceAgent@Internal@Debugger@@QEAAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:156
>>>               debug\qmljseditor.obj:(?finalizeInitialization@QmlJSEditorWidget@QmlJSEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?activateEditorForDocument@EditorManager@Core@@SAPEAVIEditor@2@PEAVIDocument@2@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:300
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)

lld-link: error: undefined symbol: ?setPlainText@TextDocument@TextEditor@@QEAA_NAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:303
>>>               debug\disassembleragent.obj:(?setContentsToDocument@DisassemblerAgent@Internal@Debugger@@AEAAXAEBVDisassemblerLines@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:719
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1176
>>>               debug\vcsbaseeditor.obj:(?reportCommandFinished@VcsBaseEditorWidget@VcsBase@@QEAAX_NHAEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1341
>>>               debug\vcsbaseeditor.obj:(?setPlainText@VcsBaseEditorWidget@VcsBase@@UEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?configureGenericHighlighter@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:245
>>>               debug\disassembleragent.obj:(?configureMimeType@DisassemblerAgentPrivate@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:295
>>>               debug\highlighter.obj:(?reload@Highlighter@TextEditor@@SAXXZ)

lld-link: error: undefined symbol: ?staticMetaObject@TextDocument@TextEditor@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:524
>>>               debug\disassembleragent.obj:(??$qobject_cast@PEAVTextDocument@TextEditor@@@@YAPEAVTextDocument@TextEditor@@PEAVQObject@@@Z)
>>> referenced by debug\textmark.obj
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\cppeditordocument.obj:(??$connect@P8TextDocument@TextEditor@@EAAXXZP8CppEditorDocument@Internal@CppEditor@@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVTextDocument@TextEditor@@P834@EAAXXZPEBVCppEditorDocument@Internal@CppEditor@@P8567@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:533
>>>               debug\cppeditorwidget.obj:(??$qobject_cast@PEBVTextDocument@TextEditor@@@@YAPEBVTextDocument@TextEditor@@PEBVQObject@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\qmljseditordocument.obj:(??$connect@P8TextDocument@TextEditor@@EAAXXZP8QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVTextDocument@TextEditor@@P834@EAAXXZPEBVQmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@P8567@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by debug\diffeditorwidgetcontroller.obj
>>> referenced by debug\moc_cppeditordocument.obj:(?staticMetaObject@CppEditorDocument@Internal@CppEditor@@2UQMetaObject@@B)
>>> referenced by debug\moc_qmljseditordocument.obj:(?staticMetaObject@QmlJSEditorDocument@QmlJSEditor@@2UQMetaObject@@B)

lld-link: error: undefined symbol: ?addMark@TextDocument@TextEditor@@QEAA_NPEAVTextMark@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:365
>>>               debug\disassembleragent.obj:(?updateBreakpointMarker@DisassemblerAgent@Internal@Debugger@@QEAAXAEBV?$QPointer@VBreakpointItem@Internal@Debugger@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:321
>>>               debug\disassembleragent.obj:(?updateLocationMarker@DisassemblerAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:128
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:338
>>>               debug\textmark.obj:(?add@TextMarkRegistry@TextEditor@@SAXPEAVTextMark@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:358
>>>               debug\textmark.obj:(?editorOpened@TextMarkRegistry@TextEditor@@AEAAXPEAVIEditor@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:562
>>>               debug\qmljseditordocument.obj:(?createTextMarks@QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@QEAAXAEBV?$QList@VDiagnosticMessage@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:579
>>>               debug\qmljseditordocument.obj:(?createTextMarks@QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@QEAAXAEBVSemanticInfo@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:585
>>>               debug\qmljseditordocument.obj:(?createTextMarks@QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@QEAAXAEBVSemanticInfo@QmlJSTools@@@Z)

lld-link: error: undefined symbol: ?currentDocument@EditorManager@Core@@SAPEAVIDocument@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:327
>>>               debug\disassembleragent.obj:(?updateLocationMarker@DisassemblerAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\vcsmanager.cpp:272
>>>               debug\vcsmanager.obj:(?findVersionControlForDirectory@VcsManager@Core@@SAPEAVIVersionControl@2@AEBVQString@@PEAV4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:341
>>>               debug\editortoolbar.obj:(?makeEditorWritable@EditorToolBar@Core@@CAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\externaltool.cpp:568
>>>               debug\externaltool.obj:(?run@ExternalToolRunner@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsreuse.cpp:239
>>>               debug\cpptoolsreuse.obj:(?switchHeaderSource@CppTools@@YAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttreewidget.cpp:439
>>>               debug\projecttreewidget.obj:(?syncFromDocumentManager@ProjectTreeWidget@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttree.cpp:192
>>>               debug\projecttree.obj:(?setCurrent@ProjectTree@ProjectExplorer@@AEAAXPEAVNode@2@PEAVProject@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttree.cpp:156
>>>               debug\projecttree.obj:(?updateFromDocumentManager@ProjectTree@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:251
>>>               debug\vcsbaseplugin.obj:(?slotStateChanged@StateListener@Internal@VcsBase@@QEAAXXZ)

lld-link: error: undefined symbol: ?currentEditor@EditorManager@Core@@SAPEAVIEditor@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\disassembleragent.cpp:328
>>>               debug\disassembleragent.obj:(?updateLocationMarker@DisassemblerAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editmode.cpp:108
>>>               debug\editmode.obj:(?grabEditorManager@EditMode@Internal@Core@@AEAAXVId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editmode.cpp:109
>>>               debug\editmode.obj:(?grabEditorManager@EditMode@Internal@Core@@AEAAXVId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:872
>>>               debug\editorview.obj:(?saveState@SplitterOrView@Internal@Core@@QEBA?AVQByteArray@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:66
>>>               debug\openeditorsview.obj:(??0OpenEditorsWidget@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:111
>>>               debug\openeditorsview.obj:(?closeDocument@OpenEditorsWidget@Internal@Core@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:329
>>>               debug\editortoolbar.obj:(?fillListContextMenu@EditorToolBar@Core@@AEAAXPEAVQMenu@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\outputpanemanager.cpp:613
>>>               debug\outputpanemanager.obj:(?slotHide@OutputPaneManager@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:56
>>>               debug\linenumberfilter.obj:(?prepareSearch@LineNumberFilter@Internal@TextEditor@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:91
>>>               debug\linenumberfilter.obj:(?accept@LineNumberFilter@Internal@TextEditor@@UEBAXULocatorFilterEntry@Core@@PEAVQString@@PEAH2@Z)
>>> referenced 12 more times

lld-link: error: undefined symbol: ??0FindToolBarPlaceHolder@Core@@QEAA@PEAVQWidget@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:430
>>>               debug\logwindow.obj:(??0LogWindow@Internal@Debugger@@QEAA@PEAVDebuggerEngine@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:655
>>>               debug\logwindow.obj:(??0GlobalLogWindow@Internal@Debugger@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:102
>>>               debug\editorview.obj:(??0EditorView@Internal@Core@@QEAA@PEAVSplitterOrView@12@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\outputpanemanager.cpp:366
>>>               debug\outputpanemanager.obj:(??0OutputPaneManager@Internal@Core@@AEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ??0BaseTextFind@Core@@QEAA@PEAVQPlainTextEdit@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:435
>>>               debug\logwindow.obj:(??0LogWindow@Internal@Debugger@@QEAA@PEAVDebuggerEngine@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:439
>>>               debug\logwindow.obj:(??0LogWindow@Internal@Debugger@@QEAA@PEAVDebuggerEngine@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:660
>>>               debug\logwindow.obj:(??0GlobalLogWindow@Internal@Debugger@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\logwindow.cpp:664
>>>               debug\logwindow.obj:(??0GlobalLogWindow@Internal@Debugger@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\messageoutputwindow.cpp:72
>>>               debug\messageoutputwindow.obj:(??0MessageOutputWindow@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\compileoutputwindow.cpp:149
>>>               debug\compileoutputwindow.obj:(??0CompileOutputWindow@Internal@ProjectExplorer@@QEAA@PEAVQAction@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:427
>>>               debug\appoutputpane.obj:(?createNewOutputWindow@AppOutputPane@Internal@ProjectExplorer@@QEAAXPEAVRunControl@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsoutputwindow.cpp:127
>>>               debug\vcsoutputwindow.obj:(??0OutputWindowPlainTextEdit@Internal@VcsBase@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?activateEditor@EditorManager@Core@@SAXPEAVIEditor@2@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:104
>>>               debug\sourceagent.obj:(?setContent@SourceAgent@Internal@Debugger@@QEAAXAEBVQString@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:133
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:98
>>>               debug\linenumberfilter.obj:(?accept@LineNumberFilter@Internal@TextEditor@@UEBAXULocatorFilterEntry@Core@@PEAVQString@@PEAH2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:644
>>>               debug\vcsbaseplugin.obj:(?raiseSubmitEditor@VcsBasePluginPrivate@VcsBase@@IEBA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:478
>>>               debug\vcsbasesubmiteditor.obj:(?promptSubmit@VcsBaseSubmitEditor@VcsBase@@QEAA?AW4PromptSubmitResult@12@PEAVVcsBasePluginPrivate@2@PEA_N_N2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:215
>>>               debug\vcsbaseclient.obj:(?createVcsEditor@VcsBaseClientImpl@VcsBase@@QEBAPEAVVcsBaseEditorWidget@2@VId@Utils@@VQString@@AEBV6@PEAVQTextCodec@@PEBD2@Z)

lld-link: error: undefined symbol: ?setTextCursor@BaseTextEditor@TextEditor@@QEAAXAEBVQTextCursor@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceagent.cpp:132
>>>               debug\sourceagent.obj:(?updateLocationMarker@SourceAgent@Internal@Debugger@@QEAAXXZ)

lld-link: error: undefined symbol: ?characterAt@TextEditorWidget@TextEditor@@QEBA?AVQChar@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceutils.cpp:241
>>>               debug\sourceutils.obj:(?cppExpressionAt@Internal@Debugger@@YA?AVQString@@PEAVTextEditorWidget@TextEditor@@HPEAH1PEAV3@11@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:47
>>>               debug\textdocumentmanipulator.obj:(?characterAt@TextDocumentManipulator@TextEditor@@UEBA?AVQChar@@H@Z)

lld-link: error: undefined symbol: ?document@TextDocument@TextEditor@@QEBAPEAVQTextDocument@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\sourceutils.cpp:292
>>>               debug\sourceutils.obj:(?getLocationContext@Internal@Debugger@@YA?AVContextData@12@PEAVTextDocument@TextEditor@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:44
>>>               debug\cppeditor.obj:(?decorateEditor@CppEditor@Internal@1@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:112
>>>               debug\cppeditordocument.obj:(??0CppEditorDocument@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:184
>>>               debug\cppeditordocument.obj:(?invalidateFormatterCache@CppEditorDocument@Internal@CppEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:209
>>>               debug\cppeditordocument.obj:(?onReloadFinished@CppEditorDocument@Internal@CppEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:247
>>>               debug\cppeditordocument.obj:(?onFilePathChanged@CppEditorDocument@Internal@CppEditor@@AEAAXAEBVFilePath@Utils@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:164
>>>               debug\cppeditordocument.obj:(?contentsText@CppEditorDocument@Internal@CppEditor@@AEBA?AVQByteArray@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:255
>>>               debug\cppeditordocument.obj:(?scheduleProcessDocument@CppEditorDocument@Internal@CppEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:332
>>>               debug\cppeditordocument.obj:(?contentsRevision@CppEditorDocument@Internal@CppEditor@@AEBAIXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:436
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)
>>> referenced 21 more times

lld-link: error: undefined symbol: ?useProjectsDirectory@DocumentManager@Core@@SA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\iwizardfactory.cpp:236
>>>               debug\iwizardfactory.obj:(?runPath@IWizardFactory@Core@@QEBA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?projectsDirectory@DocumentManager@Core@@SA?AVFilePath@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\iwizardfactory.cpp:236
>>>               debug\iwizardfactory.obj:(?runPath@IWizardFactory@Core@@QEBA?AVQString@@AEBV3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:921
>>>               debug\foldernavigationwidget.obj:(?updateProjectsDirectoryRoot@FolderNavigationWidgetFactory@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:110
>>>               debug\gettingstartedwelcomepage.obj:(?copyToAlternativeLocation@ExamplesWelcomePage@Internal@QtSupport@@CA?AVQString@@AEBVQFileInfo@@AEAVQStringList@@AEBV6@@Z)

lld-link: error: undefined symbol: ?fileDialogLastVisitedDirectory@DocumentManager@Core@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\iwizardfactory.cpp:236
>>>               debug\iwizardfactory.obj:(?runPath@IWizardFactory@Core@@QEBA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?fileDialogInitialDirectory@DocumentManager@Core@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\iwizardfactory.cpp:241
>>>               debug\iwizardfactory.obj:(?runPath@IWizardFactory@Core@@QEBA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?openEditorAt@EditorManager@Core@@SAPEAVIEditor@2@AEBVQString@@HHVId@Utils@@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\outputwindow.cpp:156
>>>               debug\outputwindow.obj:(??R<lambda_2>@?0???0OutputWindow@Core@@QEAA@VContext@2@AEBVQString@@PEAVQWidget@@@Z@QEBA?A?<auto>@@AEBVFilePath@Utils@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:130
>>>               debug\refactoringchanges.obj:(?openEditor@RefactoringChanges@TextEditor@@KAPEAVTextEditorWidget@2@AEBVQString@@_NHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:438
>>>               debug\cppincludehierarchy.obj:(?onItemActivated@CppIncludeHierarchyWidget@Internal@CppEditor@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:250
>>>               debug\cpptypehierarchy.obj:(?onItemActivated@CppTypeHierarchyWidget@Internal@CppEditor@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:125
>>>               debug\cppcurrentdocumentfilter.obj:(?accept@CppCurrentDocumentFilter@Internal@CppTools@@UEBAXULocatorFilterEntry@Core@@PEAVQString@@PEAH2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:158
>>>               debug\cpplocatorfilter.obj:(?accept@CppLocatorFilter@Internal@CppTools@@UEBAXULocatorFilterEntry@Core@@PEAVQString@@PEAH2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppvirtualfunctionproposalitem.cpp:43
>>>               debug\cppvirtualfunctionproposalitem.obj:(?apply@VirtualFunctionProposalItem@CppTools@@UEBAXAEAVTextDocumentManipulatorInterface@TextEditor@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:179
>>>               debug\symbolsfindfilter.obj:(?openEditor@SymbolsFindFilter@Internal@CppTools@@AEAAXAEBVSearchResultItem@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\showineditortaskhandler.cpp:46
>>>               debug\showineditortaskhandler.obj:(?handle@ShowInEditorTaskHandler@Internal@ProjectExplorer@@UEAAXAEBVTask@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\taskwindow.cpp:229
>>>               debug\taskwindow.obj:(?mouseReleaseEvent@TaskView@Internal@ProjectExplorer@@EEAAXPEAVQMouseEvent@@@Z)
>>> referenced 2 more times

lld-link: error: undefined symbol: ?instance@DocumentManager@Core@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\vcsmanager.cpp:160
>>>               debug\vcsmanager.obj:(?extensionsInitialized@VcsManager@Core@@SAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:328
>>>               debug\textmark.obj:(??0TextMarkRegistry@TextEditor@@AEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:330
>>>               debug\textmark.obj:(??0TextMarkRegistry@TextEditor@@AEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppmodelmanager.cpp:559
>>>               debug\cppmodelmanager.obj:(?initCppTools@CppModelManager@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppmodelmanager.cpp:634
>>>               debug\cppmodelmanager.obj:(??0CppModelManager@CppTools@@AEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:838
>>>               debug\foldernavigationwidget.obj:(??0FolderNavigationWidgetFactory@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ??0AddToVcsDialog@Internal@Core@@QEAA@PEAVQWidget@@AEBVQString@@AEBVQStringList@@1@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\vcsmanager.cpp:421
>>>               debug\vcsmanager.obj:(?promptToAdd@VcsManager@Core@@SAXAEBVQString@@AEBVQStringList@@@Z)

lld-link: error: undefined symbol: ??1AddToVcsDialog@Internal@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\vcsmanager.cpp:436
>>>               debug\vcsmanager.obj:(?promptToAdd@VcsManager@Core@@SAXAEBVQString@@AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\vcsmanager.cpp:436
>>>               debug\vcsmanager.obj:(?dtor$40@?0??promptToAdd@VcsManager@Core@@SAXAEBVQString@@AEBVQStringList@@@Z@4HA)

lld-link: error: undefined symbol: ?instance@EditorManagerPrivate@Internal@Core@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:134
>>>               debug\editorview.obj:(??0EditorView@Internal@Core@@QEAA@PEAVSplitterOrView@12@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?placeholderText@EditorManagerPrivate@Internal@Core@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:137
>>>               debug\editorview.obj:(??0EditorView@Internal@Core@@QEAA@PEAVSplitterOrView@12@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?activateEditorForDocument@EditorManagerPrivate@Internal@Core@@SAPEAVIEditor@3@PEAVEditorView@23@PEAVIDocument@3@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:521
>>>               debug\editorview.obj:(?goBackInNavigationHistory@EditorView@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:553
>>>               debug\editorview.obj:(?goForwardInNavigationHistory@EditorView@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:582
>>>               debug\editorview.obj:(?goToEditLocation@EditorView@Internal@Core@@QEAAXAEBUEditLocation@23@@Z)

lld-link: error: undefined symbol: ?openEditor@EditorManagerPrivate@Internal@Core@@SAPEAVIEditor@3@PEAVEditorView@23@AEBVQString@@VId@Utils@@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:529
>>>               debug\editorview.obj:(?goBackInNavigationHistory@EditorView@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:561
>>>               debug\editorview.obj:(?goForwardInNavigationHistory@EditorView@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:589
>>>               debug\editorview.obj:(?goToEditLocation@EditorView@Internal@Core@@QEAAXAEBUEditLocation@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:902
>>>               debug\editorview.obj:(?restoreState@SplitterOrView@Internal@Core@@QEAAXAEBVQByteArray@@@Z)

lld-link: error: undefined symbol: ?closeEditorOrDocument@EditorManagerPrivate@Internal@Core@@SAXPEAVIEditor@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:216
>>>               debug\editorview.obj:(?closeCurrentEditor@EditorView@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?activateEditorForEntry@EditorManagerPrivate@Internal@Core@@SA_NPEAVEditorView@23@PEAUEntry@DocumentModel@3@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:348
>>>               debug\editorview.obj:(?listSelectionActivated@EditorView@Internal@Core@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:910
>>>               debug\editorview.obj:(?restoreState@SplitterOrView@Internal@Core@@QEAAXAEBVQByteArray@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorswindow.cpp:175
>>>               debug\openeditorswindow.obj:(?selectEditor@OpenEditorsWindow@Internal@Core@@CAXPEAVQTreeWidgetItem@@@Z)

lld-link: error: undefined symbol: ?updateActions@EditorManagerPrivate@Internal@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:363
>>>               debug\editorview.obj:(?splitHorizontally@EditorView@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:368
>>>               debug\editorview.obj:(?splitVertically@EditorView@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:377
>>>               debug\editorview.obj:(?closeSplit@EditorView@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?splitNewWindow@EditorManagerPrivate@Internal@Core@@SAXPEAVEditorView@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:372
>>>               debug\editorview.obj:(?splitNewWindow@EditorView@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?closeView@EditorManagerPrivate@Internal@Core@@SAXPEAVEditorView@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:376
>>>               debug\editorview.obj:(?closeSplit@EditorView@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?openEditorAt@EditorManagerPrivate@Internal@Core@@SAPEAVIEditor@3@PEAVEditorView@23@AEBVQString@@HHVId@Utils@@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:384
>>>               debug\editorview.obj:(?openDroppedFiles@EditorView@Internal@Core@@AEAAXAEBV?$QList@UFileSpec@DropSupport@Utils@@@@@Z)

lld-link: error: undefined symbol: ?currentEditorView@EditorManagerPrivate@Internal@Core@@SAPEAVEditorView@23@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:276
>>>               debug\editorview.obj:(?paintEvent@EditorView@Internal@Core@@MEAAXPEAVQPaintEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:746
>>>               debug\editorview.obj:(?unsplitAll@SplitterOrView@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?setCurrentView@EditorManagerPrivate@Internal@Core@@SAXPEAVEditorView@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:304
>>>               debug\editorview.obj:(?focusInEvent@EditorView@Internal@Core@@MEAAXPEAVQFocusEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:839
>>>               debug\editorview.obj:(?unsplit@SplitterOrView@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?addSaveAndCloseEditorActions@EditorManager@Core@@SAXPEAVQMenu@@PEAUEntry@DocumentModel@2@PEAVIEditor@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:356
>>>               debug\editorview.obj:(?fillListContextMenu@EditorView@Internal@Core@@AEBAXPEAVQMenu@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:119
>>>               debug\openeditorsview.obj:(?contextMenuRequested@OpenEditorsWidget@Internal@Core@@AEAAXVQPoint@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:332
>>>               debug\editortoolbar.obj:(?fillListContextMenu@EditorToolBar@Core@@AEAAXPEAVQMenu@@@Z)

lld-link: error: undefined symbol: ?addNativeDirAndOpenWithActions@EditorManager@Core@@SAXPEAVQMenu@@PEAUEntry@DocumentModel@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:358
>>>               debug\editorview.obj:(?fillListContextMenu@EditorView@Internal@Core@@AEBAXPEAVQMenu@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:123
>>>               debug\openeditorsview.obj:(?contextMenuRequested@OpenEditorsWidget@Internal@Core@@AEAAXVQPoint@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:336
>>>               debug\editortoolbar.obj:(?fillListContextMenu@EditorToolBar@Core@@AEAAXPEAVQMenu@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:742
>>>               debug\foldernavigationwidget.obj:(?contextMenuEvent@FolderNavigationWidget@Internal@ProjectExplorer@@MEAAXPEAVQContextMenuEvent@@@Z)

lld-link: error: undefined symbol: ?duplicateEditor@EditorManagerPrivate@Internal@Core@@SAPEAVIEditor@3@PEAV43@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:705
>>>               debug\editorview.obj:(?split@SplitterOrView@Internal@Core@@QEAAXW4Orientation@Qt@@_N@Z)

lld-link: error: undefined symbol: ?activateView@EditorManagerPrivate@Internal@Core@@SAXPEAVEditorView@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:731
>>>               debug\editorview.obj:(?split@SplitterOrView@Internal@Core@@QEAAXW4Orientation@Qt@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:837
>>>               debug\editorview.obj:(?unsplit@SplitterOrView@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?emptyView@EditorManagerPrivate@Internal@Core@@SA?BV?$QList@PEAVIEditor@Core@@@@PEAVEditorView@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:622
>>>               debug\editorview.obj:(??1SplitterOrView@Internal@Core@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:778
>>>               debug\editorview.obj:(?unsplitAll_helper@SplitterOrView@Internal@Core@@AEAA?BV?$QList@PEAVIEditor@Core@@@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:814
>>>               debug\editorview.obj:(?unsplit@SplitterOrView@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?deleteEditors@EditorManagerPrivate@Internal@Core@@SAXAEBV?$QList@PEAVIEditor@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:622
>>>               debug\editorview.obj:(??1SplitterOrView@Internal@Core@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:768
>>>               debug\editorview.obj:(?unsplitAll@SplitterOrView@Internal@Core@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:840
>>>               debug\editorview.obj:(?unsplit@SplitterOrView@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?setCurrentEditor@EditorManagerPrivate@Internal@Core@@SAXPEAVIEditor@3@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorview.cpp:919
>>>               debug\editorview.obj:(?restoreState@SplitterOrView@Internal@Core@@QEAAXAEBVQByteArray@@@Z)

lld-link: error: undefined symbol: ?createLocatorInputWidget@LocatorManager@Core@@SAPEAVQWidget@@PEAV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorwindow.cpp:61
>>>               debug\editorwindow.obj:(??0EditorWindow@Internal@Core@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?updateWindowTitleForDocument@EditorManagerPrivate@Internal@Core@@SAXPEAVIDocument@3@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\editorwindow.cpp:110
>>>               debug\editorwindow.obj:(?updateWindowTitle@EditorWindow@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?filePathKey@DocumentManager@Core@@SA?AVQString@@AEBV3@W4ResolveMode@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\documentmodel.cpp:99
>>>               debug\documentmodel.obj:(?addEntry@DocumentModelPrivate@Internal@Core@@QEAAXPEAUEntry@DocumentModel@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\documentmodel.cpp:329
>>>               debug\documentmodel.obj:(?itemChanged@DocumentModelPrivate@Internal@Core@@QEAAXPEAVIDocument@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\documentmodel.cpp:218
>>>               debug\documentmodel.obj:(?indexOfFilePath@DocumentModelPrivate@Internal@Core@@QEBA?AV?$optional@H@std@@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\documentmodel.cpp:235
>>>               debug\documentmodel.obj:(?removeDocument@DocumentModelPrivate@Internal@Core@@QEAAXH@Z)

lld-link: error: undefined symbol: ?closeDocuments@EditorManager@Core@@SA_NAEBV?$QList@PEAUEntry@DocumentModel@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:108
>>>               debug\openeditorsview.obj:(?closeDocument@OpenEditorsWidget@Internal@Core@@AEAAXAEBVQModelIndex@@@Z)

lld-link: error: undefined symbol: ?addPinEditorActions@EditorManager@Core@@SAXPEAVQMenu@@PEAUEntry@DocumentModel@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:121
>>>               debug\openeditorsview.obj:(?contextMenuRequested@OpenEditorsWidget@Internal@Core@@AEAAXVQPoint@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:334
>>>               debug\editortoolbar.obj:(?fillListContextMenu@EditorToolBar@Core@@AEAAXPEAVQMenu@@@Z)

lld-link: error: undefined symbol: ?activateEditorForEntry@EditorManager@Core@@SAXPEAUEntry@DocumentModel@2@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\openeditorsview.cpp:103
>>>               debug\openeditorsview.obj:(?activateEditor@OpenEditorsWidget@Internal@Core@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:322
>>>               debug\editortoolbar.obj:(?changeActiveEditor@EditorToolBar@Core@@CAXH@Z)

lld-link: error: undefined symbol: ?maxTextFileSize@EditorManager@Core@@SA_JXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editormanager\ieditorfactory.cpp:177
>>>               debug\ieditorfactory.obj:(?preferredEditorFactories@IEditorFactory@Core@@SA?BV?$QList@PEAVIEditorFactory@Core@@@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?getSaveFileNameWithExtension@DocumentManager@Core@@SA?AVQString@@AEBV3@00@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\dialogs\shortcutsettings.cpp:485
>>>               debug\shortcutsettings.obj:(?exportAction@ShortcutSettingsWidget@Internal@Core@@EEAAXXZ)

lld-link: error: undefined symbol: ?cleanup@ProgressManagerPrivate@Internal@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:244
>>>               debug\progressmanager.obj:(??1ProgressManagerPrivate@Internal@Core@@UEAA@XZ)

lld-link: error: undefined symbol: ?initInternal@ProgressManagerPrivate@Internal@Core@@AEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:301
>>>               debug\progressmanager.obj:(?init@ProgressManagerPrivate@Internal@Core@@QEAAXXZ)

lld-link: error: undefined symbol: ?setApplicationProgressRange@ProgressManagerPrivate@Internal@Core@@AEAAXHH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:439
>>>               debug\progressmanager.obj:(?disconnectApplicationTask@ProgressManagerPrivate@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:384
>>>               debug\progressmanager.obj:(?doAddTask@ProgressManagerPrivate@Internal@Core@@QEAAPEAVFutureProgress@3@AEBV?$QFuture@X@@AEBVQString@@VId@Utils@@V?$QFlags@W4ProgressFlag@ProgressManager@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:386
>>>               debug\progressmanager.obj:(?doAddTask@ProgressManagerPrivate@Internal@Core@@QEAAPEAVFutureProgress@3@AEBV?$QFuture@X@@AEBVQString@@VId@Utils@@V?$QFlags@W4ProgressFlag@ProgressManager@Core@@@@@Z)

lld-link: error: undefined symbol: ?setApplicationProgressValue@ProgressManagerPrivate@Internal@Core@@AEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:440
>>>               debug\progressmanager.obj:(?disconnectApplicationTask@ProgressManagerPrivate@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:386
>>>               debug\progressmanager.obj:(?doAddTask@ProgressManagerPrivate@Internal@Core@@QEAAPEAVFutureProgress@3@AEBV?$QFuture@X@@AEBVQString@@VId@Utils@@V?$QFlags@W4ProgressFlag@ProgressManager@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:387
>>>               debug\progressmanager.obj:(?doAddTask@ProgressManagerPrivate@Internal@Core@@QEAAPEAVFutureProgress@3@AEBV?$QFuture@X@@AEBVQString@@VId@Utils@@V?$QFlags@W4ProgressFlag@ProgressManager@Core@@@@@Z)

lld-link: error: undefined symbol: ?setApplicationProgressVisible@ProgressManagerPrivate@Internal@Core@@AEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:444
>>>               debug\progressmanager.obj:(?disconnectApplicationTask@ProgressManagerPrivate@Internal@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:391
>>>               debug\progressmanager.obj:(?doAddTask@ProgressManagerPrivate@Internal@Core@@QEAAPEAVFutureProgress@3@AEBV?$QFuture@X@@AEBVQString@@VId@Utils@@V?$QFlags@W4ProgressFlag@ProgressManager@Core@@@@@Z)

lld-link: error: undefined symbol: ?doSetApplicationLabel@ProgressManagerPrivate@Internal@Core@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\progressmanager\progressmanager.cpp:726
>>>               debug\progressmanager.obj:(?setApplicationLabel@ProgressManager@Core@@SAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?addContextObject@MainWindow@Internal@Core@@QEAAXPEAVIContext@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\modemanager.cpp:208
>>>               debug\modemanager.obj:(?appendMode@ModeManagerPrivate@Core@@QEAAXPEAVIMode@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:700
>>>               debug\icore.obj:(?addContextObject@ICore@Core@@SAXPEAVIContext@2@@Z)

lld-link: error: undefined symbol: ?removeContextObject@MainWindow@Internal@Core@@QEAAXPEAVIContext@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\modemanager.cpp:266
>>>               debug\modemanager.obj:(?removeMode@ModeManager@Core@@CAXPEAVIMode@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:713
>>>               debug\icore.obj:(?removeContextObject@ICore@Core@@SAXPEAVIContext@2@@Z)

lld-link: error: undefined symbol: ?defaultTextCodec@EditorManager@Core@@SAPEAVQTextCodec@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\generatedfile.cpp:132
>>>               debug\generatedfile.obj:(?write@GeneratedFile@Core@@QEBA_NPEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\textdocument.cpp:65
>>>               debug\textdocument.obj:(??0BaseTextDocument@Core@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinfiles.cpp:72
>>>               debug\findinfiles.obj:(?files@FindInFiles@TextEditor@@MEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findincurrentfile.cpp:62
>>>               debug\findincurrentfile.obj:(?files@FindInCurrentFile@Internal@TextEditor@@MEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinopenfiles.cpp:67
>>>               debug\findinopenfiles.obj:(?files@FindInOpenFiles@Internal@TextEditor@@MEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:96
>>>               debug\refactoringchanges.obj:(?createFile@RefactoringChanges@TextEditor@@QEBA_NAEBVQString@@0_N1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:183
>>>               debug\refactoringchanges.obj:(?mutableDocument@RefactoringFile@TextEditor@@IEBAPEAVQTextDocument@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:340
>>>               debug\cppeditorwidget.obj:(?getCurrentDocument@Internal@CppEditor@@YA?AV?$unique_ptr@VQTextDocument@@U?$default_delete@VQTextDocument@@@std@@@std@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:66
>>>               debug\cppfindreferences.obj:(?getSource@@YA?AVQByteArray@@AEBVFilePath@Utils@@AEBVWorkingCopy@CppTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppsourceprocessor.cpp:119
>>>               debug\cppsourceprocessor.obj:(??0CppSourceProcessor@Internal@CppTools@@QEAA@AEBVSnapshot@CPlusPlus@@V?$function@$$A6AXAEBV?$QSharedPointer@VDocument@CPlusPlus@@@@@Z@std@@@Z)
>>> referenced 7 more times

lld-link: error: undefined symbol: ?defaultLineEnding@EditorManager@Core@@SA?AW4LineTerminationMode@TextFileFormat@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\generatedfile.cpp:133
>>>               debug\generatedfile.obj:(?write@GeneratedFile@Core@@QEBA_NPEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\textdocument.cpp:66
>>>               debug\textdocument.obj:(??0BaseTextDocument@Core@@QEAA@PEAVQObject@@@Z)

lld-link: error: undefined symbol: ??0PluginDetailsView@ExtensionSystem@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\plugindialog.cpp:151
>>>               debug\plugindialog.obj:(?openDetails@PluginDialog@Internal@Core@@AEAAXPEAVPluginSpec@ExtensionSystem@@@Z)

lld-link: error: undefined symbol: ?update@PluginDetailsView@ExtensionSystem@@QEAAXPEAVPluginSpec@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\plugindialog.cpp:153
>>>               debug\plugindialog.obj:(?openDetails@PluginDialog@Internal@Core@@AEAAXPEAVPluginSpec@ExtensionSystem@@@Z)

lld-link: error: undefined symbol: ??0PluginErrorView@ExtensionSystem@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\plugindialog.cpp:170
>>>               debug\plugindialog.obj:(?openErrorDetails@PluginDialog@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?update@PluginErrorView@ExtensionSystem@@QEAAXPEAVPluginSpec@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\plugindialog.cpp:172
>>>               debug\plugindialog.obj:(?openErrorDetails@PluginDialog@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?currentDialog@NewDialog@Internal@Core@@SAPEAVQWidget@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:178
>>>               debug\icore.obj:(?isNewItemDialogRunning@ICore@Core@@SA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:189
>>>               debug\icore.obj:(?newItemDialog@ICore@Core@@SAPEAVQWidget@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:189
>>>               debug\icore.obj:(?newItemDialog@ICore@Core@@SAPEAVQWidget@@XZ)

lld-link: error: undefined symbol: ??0NewDialog@Internal@Core@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:241
>>>               debug\icore.obj:(?showNewItemDialog@ICore@Core@@SAXAEBVQString@@AEBV?$QList@PEAVIWizardFactory@Core@@@@0AEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ?setWizardFactories@NewDialog@Internal@Core@@QEAAXV?$QList@PEAVIWizardFactory@Core@@@@AEBVQString@@AEBV?$QMap@VQString@@VQVariant@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:244
>>>               debug\icore.obj:(?showNewItemDialog@ICore@Core@@SAXAEBVQString@@AEBV?$QList@PEAVIWizardFactory@Core@@@@0AEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ?showDialog@NewDialog@Internal@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:246
>>>               debug\icore.obj:(?showNewItemDialog@ICore@Core@@SAXAEBVQString@@AEBV?$QList@PEAVIWizardFactory@Core@@@@0AEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ?executeSettingsDialog@Internal@Core@@YA_NPEAVQWidget@@VId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:262
>>>               debug\icore.obj:(?showOptionsDialog@ICore@Core@@SA_NVId@Utils@@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?currentContextObject@MainWindow@Internal@Core@@QEBAPEAVIContext@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:580
>>>               debug\icore.obj:(?currentContextObject@ICore@Core@@SAPEAVIContext@2@XZ)

lld-link: error: undefined symbol: ?contextObject@MainWindow@Internal@Core@@QEBAPEAVIContext@3@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:599
>>>               debug\icore.obj:(?contextObject@ICore@Core@@SAPEAVIContext@2@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?statusBar@MainWindow@Internal@Core@@QEBAPEAVQStatusBar@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:625
>>>               debug\icore.obj:(?statusBar@ICore@Core@@SAPEAVQStatusBar@@XZ)

lld-link: error: undefined symbol: ?infoBar@MainWindow@Internal@Core@@QEBAPEAVInfoBar@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:632
>>>               debug\icore.obj:(?infoBar@ICore@Core@@SAPEAVInfoBar@Utils@@XZ)

lld-link: error: undefined symbol: ?updateAdditionalContexts@MainWindow@Internal@Core@@QEAAXAEBVContext@3@0W4ContextPriority@ICore@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:665
>>>               debug\icore.obj:(?updateAdditionalContexts@ICore@Core@@SAXAEBVContext@2@0W4ContextPriority@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:675
>>>               debug\icore.obj:(?addAdditionalContext@ICore@Core@@SAXAEBVContext@2@W4ContextPriority@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:684
>>>               debug\icore.obj:(?removeAdditionalContext@ICore@Core@@SAXAEBVContext@2@@Z)

lld-link: error: undefined symbol: ?openFiles@MainWindow@Internal@Core@@SAPEAVIDocument@3@AEBVQStringList@@W4OpenFilesFlags@ICore@3@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:738
>>>               debug\icore.obj:(?openFiles@ICore@Core@@SAXAEBVQStringList@@W4OpenFilesFlags@12@@Z)

lld-link: error: undefined symbol: ?addPreCloseListener@MainWindow@Internal@Core@@QEAAXAEBV?$function@$$A6A_NXZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:750
>>>               debug\icore.obj:(?addPreCloseListener@ICore@Core@@SAXAEBV?$function@$$A6A_NXZ@std@@@Z)

lld-link: error: undefined symbol: ?restart@MainWindow@Internal@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:822
>>>               debug\icore.obj:(?restart@ICore@Core@@SAXXZ)

lld-link: error: undefined symbol: ?saveSettings@MainWindow@Internal@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:829
>>>               debug\icore.obj:(?saveSettings@ICore@Core@@SAXW4SaveSettingsReason@12@@Z)

lld-link: error: undefined symbol: ?additionalAboutInformation@MainWindow@Internal@Core@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:839
>>>               debug\icore.obj:(?additionalAboutInformation@ICore@Core@@SA?AVQStringList@@XZ)

lld-link: error: undefined symbol: ?appendAboutInformation@MainWindow@Internal@Core@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\icore.cpp:846
>>>               debug\icore.obj:(?appendAboutInformation@ICore@Core@@SAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?makeFileWritable@EditorManagerPrivate@Internal@Core@@SA?AW4MakeWritableResult@23@PEAVIDocument@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:342
>>>               debug\editortoolbar.obj:(?makeEditorWritable@EditorToolBar@Core@@CAXXZ)

lld-link: error: undefined symbol: ?slotCloseCurrentEditorOrDocument@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\editortoolbar.cpp:260
>>>               debug\editortoolbar.obj:(?closeEditor@EditorToolBar@Core@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:275
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?instance@CorePlugin@Internal@Core@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\helpmanager.cpp:46
>>>               debug\helpmanager.obj:(?checkInstance@HelpManager@Core@@YA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\plugininstallwizard.cpp:252
>>>               debug\plugininstallwizard.obj:(?checkContents@CheckArchivePage@Internal@Core@@QEAAXAEAV?$QFutureInterface@UArchiveIssue@CheckArchivePage@Internal@Core@@@@@Z)

lld-link: error: undefined symbol: ??0OptionsPopup@Core@@QEAA@PEAVQWidget@@AEBV?$QVector@VId@Utils@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\outputpanemanager.cpp:218
>>>               debug\outputpanemanager.obj:(?filterOutputButtonClicked@IOutputPane@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?saveModifiedDocument@DocumentManager@Core@@SA_NPEAVIDocument@2@AEBVQString@@PEA_N12PEAV?$QList@PEAVIDocument@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\externaltool.cpp:570
>>>               debug\externaltool.obj:(?run@ExternalToolRunner@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?expectFileChange@DocumentManager@Core@@SAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\externaltool.cpp:574
>>>               debug\externaltool.obj:(?run@ExternalToolRunner@Internal@Core@@AEAAXXZ)

lld-link: error: undefined symbol: ?unexpectFileChange@DocumentManager@Core@@SAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\externaltool.cpp:612
>>>               debug\externaltool.obj:(?finished@ExternalToolRunner@Internal@Core@@AEAAXHW4ExitStatus@QProcess@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\externaltool.cpp:620
>>>               debug\externaltool.obj:(?error@ExternalToolRunner@Internal@Core@@AEAAXW4ProcessError@QProcess@@@Z)

lld-link: error: undefined symbol: ??0ILocatorFilter@Core@@QEAA@PEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:54
>>>               debug\menubarfilter.obj:(??0MenuBarFilter@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:46
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:42
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:42
>>>               debug\cpplocatorfilter.obj:(??0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)

lld-link: error: undefined symbol: ?setId@ILocatorFilter@Core@@IEAAXVId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:55
>>>               debug\menubarfilter.obj:(??0MenuBarFilter@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:47
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppclassesfilter.cpp:35
>>>               debug\cppclassesfilter.obj:(??0CppClassesFilter@CppTools@@QEAA@PEAVCppLocatorData@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:43
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfunctionsfilter.cpp:37
>>>               debug\cppfunctionsfilter.obj:(??0CppFunctionsFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:109
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:43
>>>               debug\cpplocatorfilter.obj:(??0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:42
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:41
>>>               debug\currentprojectfilter.obj:(??0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ?setDisplayName@ILocatorFilter@Core@@IEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:56
>>>               debug\menubarfilter.obj:(??0MenuBarFilter@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:48
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppclassesfilter.cpp:36
>>>               debug\cppclassesfilter.obj:(??0CppClassesFilter@CppTools@@QEAA@PEAVCppLocatorData@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:44
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfunctionsfilter.cpp:38
>>>               debug\cppfunctionsfilter.obj:(??0CppFunctionsFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:110
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:44
>>>               debug\cpplocatorfilter.obj:(??0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:43
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:42
>>>               debug\currentprojectfilter.obj:(??0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ?setShortcutString@ILocatorFilter@Core@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:57
>>>               debug\menubarfilter.obj:(??0MenuBarFilter@Internal@Core@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:50
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppclassesfilter.cpp:37
>>>               debug\cppclassesfilter.obj:(??0CppClassesFilter@CppTools@@QEAA@PEAVCppLocatorData@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:45
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfunctionsfilter.cpp:39
>>>               debug\cppfunctionsfilter.obj:(??0CppFunctionsFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:111
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:45
>>>               debug\cpplocatorfilter.obj:(??0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:44
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:43
>>>               debug\currentprojectfilter.obj:(??0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ??1ILocatorFilter@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:61
>>>               debug\menubarfilter.obj:(?dtor$13@?0???0MenuBarFilter@Internal@Core@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.h:42
>>>               debug\menubarfilter.obj:(??1MenuBarFilter@Internal@Core@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:52
>>>               debug\linenumberfilter.obj:(?dtor$11@?0???0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.h:41
>>>               debug\linenumberfilter.obj:(??1LineNumberFilter@Internal@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:61
>>>               debug\cppcurrentdocumentfilter.obj:(?dtor$23@?0???0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.h:47
>>>               debug\cppcurrentdocumentfilter.obj:(??1CppCurrentDocumentFilter@Internal@CppTools@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:47
>>>               debug\cpplocatorfilter.obj:(?dtor$10@?0???0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:49
>>>               debug\cpplocatorfilter.obj:(??1CppLocatorFilter@Internal@CppTools@@UEAA@XZ)

lld-link: error: undefined symbol: ?locatorHasFocus@LocatorManager@Core@@SA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\coreplugin\menubarfilter.cpp:59
>>>               debug\menubarfilter.obj:(??R<lambda_0>@?0???0MenuBarFilter@Internal@Core@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?saveState@ILocatorFilter@Core@@UEBA?AVQByteArray@@XZ
>>> referenced by debug\menubarfilter.obj:(??_7MenuBarFilter@Internal@Core@@6B@)
>>> referenced by debug\linenumberfilter.obj:(??_7LineNumberFilter@Internal@TextEditor@@6B@)
>>> referenced by debug\cppclassesfilter.obj:(??_7CppClassesFilter@CppTools@@6B@)
>>> referenced by debug\cppcurrentdocumentfilter.obj:(??_7CppCurrentDocumentFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppfunctionsfilter.obj:(??_7CppFunctionsFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppincludesfilter.obj:(??_7CppIncludesFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cpplocatorfilter.obj:(??_7CppLocatorFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfilter.obj:(??_7AllProjectsFilter@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfilter.obj:(??_7CurrentProjectFilter@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?restoreState@ILocatorFilter@Core@@UEAAXAEBVQByteArray@@@Z
>>> referenced by debug\menubarfilter.obj:(??_7MenuBarFilter@Internal@Core@@6B@)
>>> referenced by debug\linenumberfilter.obj:(??_7LineNumberFilter@Internal@TextEditor@@6B@)
>>> referenced by debug\cppclassesfilter.obj:(??_7CppClassesFilter@CppTools@@6B@)
>>> referenced by debug\cppcurrentdocumentfilter.obj:(??_7CppCurrentDocumentFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppfunctionsfilter.obj:(??_7CppFunctionsFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppincludesfilter.obj:(??_7CppIncludesFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cpplocatorfilter.obj:(??_7CppLocatorFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfilter.obj:(??_7AllProjectsFilter@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfilter.obj:(??_7CurrentProjectFilter@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?openConfigDialog@ILocatorFilter@Core@@UEAA_NPEAVQWidget@@AEA_N@Z
>>> referenced by debug\menubarfilter.obj:(??_7MenuBarFilter@Internal@Core@@6B@)
>>> referenced by debug\linenumberfilter.obj:(??_7LineNumberFilter@Internal@TextEditor@@6B@)
>>> referenced by debug\cppclassesfilter.obj:(??_7CppClassesFilter@CppTools@@6B@)
>>> referenced by debug\cppcurrentdocumentfilter.obj:(??_7CppCurrentDocumentFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppfunctionsfilter.obj:(??_7CppFunctionsFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppincludesfilter.obj:(??_7CppIncludesFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cpplocatorfilter.obj:(??_7CppLocatorFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfilter.obj:(??_7AllProjectsFilter@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfilter.obj:(??_7CurrentProjectFilter@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ??0TextEditorFactory@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:56
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1038
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:56
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ?addHoverHandler@TextEditorFactory@TextEditor@@QEAAXPEAVBaseHoverHandler@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:66
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1057
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setDocumentCreator@TextEditorFactory@TextEditor@@QEAAXAEBV?$function@$$A6APEAVTextDocument@TextEditor@@XZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:68
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1049
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:66
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ?setEditorWidgetCreator@TextEditorFactory@TextEditor@@QEAAXAEBV?$function@$$A6APEAVQWidget@@XZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:71
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1050
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:75
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ?setUseGenericHighlighter@TextEditorFactory@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:72
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?setEditorActionHandlers@TextEditorFactory@TextEditor@@QEAAXI@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:74
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorFactory@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1060
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:63
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ??1TextEditorFactory@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:78
>>>               debug\plaintexteditorfactory.obj:(?dtor$25@?0???0PlainTextEditorFactory@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.h:32
>>>               debug\plaintexteditorfactory.obj:(??1PlainTextEditorFactory@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1065
>>>               debug\qmljseditor.obj:(?dtor$41@?0???0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.h:147
>>>               debug\qmljseditor.obj:(??1QmlJSEditorFactory@QmlJSEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:85
>>>               debug\basevcseditorfactory.obj:(?dtor$24@?0???0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.h:38
>>>               debug\basevcseditorfactory.obj:(??1VcsEditorFactory@VcsBase@@UEAA@XZ)

lld-link: error: undefined symbol: ??0TextDocument@TextEditor@@QEAA@VId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:69
>>>               debug\plaintexteditorfactory.obj:(??R<lambda_0>@?0???0PlainTextEditorFactory@TextEditor@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:106
>>>               debug\cppeditordocument.obj:(??0CppEditorDocument@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:596
>>>               debug\qmljseditordocument.obj:(??0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:67
>>>               debug\basevcseditorfactory.obj:(??R<lambda_0>@?0???0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@2@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@5@@Z@QEBA@XZ)

lld-link: error: undefined symbol: ??0TextEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:49
>>>               debug\plaintexteditorfactory.obj:(??0PlainTextEditorWidget@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:45
>>>               debug\snippeteditor.obj:(??0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:142
>>>               debug\cppeditorwidget.obj:(??0CppEditorWidget@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:108
>>>               debug\qmljseditor.obj:(??0QmlJSEditorWidget@QmlJSEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:620
>>>               debug\vcsbaseeditor.obj:(??0VcsBaseEditorWidget@VcsBase@@IEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:93
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\selectabletexteditorwidget.cpp:39
>>>               debug\selectabletexteditorwidget.obj:(??0SelectableTextEditorWidget@Internal@DiffEditor@@QEAA@VId@Utils@@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ??1TextEditorWidget@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\plaintexteditorfactory.cpp:47
>>>               debug\plaintexteditorfactory.obj:(??1PlainTextEditorWidget@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:51
>>>               debug\snippeteditor.obj:(?dtor$7@?0???0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.h:33
>>>               debug\snippeteditor.obj:(??1SnippetEditorWidget@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:144
>>>               debug\cppeditorwidget.obj:(?dtor$6@?0???0CppEditorWidget@Internal@CppEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:275
>>>               debug\cppeditorwidget.obj:(??1CppEditorWidget@Internal@CppEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:111
>>>               debug\qmljseditor.obj:(?dtor$12@?0???0QmlJSEditorWidget@QmlJSEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.h:55
>>>               debug\qmljseditor.obj:(??1QmlJSEditorWidget@QmlJSEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:622
>>>               debug\vcsbaseeditor.obj:(?dtor$6@?0???0VcsBaseEditorWidget@VcsBase@@IEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:747
>>>               debug\vcsbaseeditor.obj:(??1VcsBaseEditorWidget@VcsBase@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:747
>>>               debug\vcsbaseeditor.obj:(?dtor$4@?0???1VcsBaseEditorWidget@VcsBase@@UEAA@XZ@4HA)
>>> referenced 4 more times

lld-link: error: undefined symbol: ?event@TextEditorWidget@TextEditor@@MEAA_NPEAVQEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:767
>>>               debug\cppeditorwidget.obj:(?event@CppEditorWidget@Internal@CppEditor@@MEAA_NPEAVQEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:904
>>>               debug\qmljseditor.obj:(?event@QmlJSEditorWidget@QmlJSEditor@@MEAA_NPEAVQEvent@@@Z)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?timerEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQTimerEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?mousePressEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQMouseEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?mouseReleaseEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQMouseEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1016
>>>               debug\vcsbaseeditor.obj:(?mouseReleaseEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?mouseDoubleClickEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQMouseEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1025
>>>               debug\vcsbaseeditor.obj:(?mouseDoubleClickEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:425
>>>               debug\sidebysidediffeditorwidget.obj:(?mouseDoubleClickEvent@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:149
>>>               debug\unifieddiffeditorwidget.obj:(?mouseDoubleClickEvent@UnifiedDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQMouseEvent@@@Z)

lld-link: error: undefined symbol: ?mouseMoveEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQMouseEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:973
>>>               debug\vcsbaseeditor.obj:(?mouseMoveEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:995
>>>               debug\vcsbaseeditor.obj:(?mouseMoveEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?wheelEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQWheelEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:911
>>>               debug\qmljseditor.obj:(?wheelEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQWheelEvent@@@Z)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?keyPressEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQKeyEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:771
>>>               debug\cppeditorwidget.obj:(?processKeyNormally@CppEditorWidget@Internal@CppEditor@@AEAAXPEAVQKeyEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:891
>>>               debug\cppeditorwidget.obj:(?keyPressEvent@CppEditorWidget@Internal@CppEditor@@MEAAXPEAVQKeyEvent@@@Z)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1035
>>>               debug\vcsbaseeditor.obj:(?keyPressEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQKeyEvent@@@Z)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:434
>>>               debug\sidebysidediffeditorwidget.obj:(?keyPressEvent@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQKeyEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:158
>>>               debug\unifieddiffeditorwidget.obj:(?keyPressEvent@UnifiedDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQKeyEvent@@@Z)

lld-link: error: undefined symbol: ?keyReleaseEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQKeyEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?focusInEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQFocusEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:630
>>>               debug\sidebysidediffeditorwidget.obj:(?focusInEvent@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQFocusEvent@@@Z)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?focusOutEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQFocusEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:59
>>>               debug\snippeteditor.obj:(?focusOutEvent@SnippetEditorWidget@TextEditor@@MEAAXPEAVQFocusEvent@@@Z)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?leaveEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?paintEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQPaintEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:507
>>>               debug\sidebysidediffeditorwidget.obj:(?paintEvent@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXPEAVQPaintEvent@@@Z)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?resizeEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQResizeEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:922
>>>               debug\qmljseditor.obj:(?resizeEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQResizeEvent@@@Z)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?contextMenuEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQContextMenuEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?dragEnterEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQDragEnterEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?dropEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQDropEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?showEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQShowEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?changeEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?inputMethodEvent@TextEditorWidget@TextEditor@@MEAAXPEAVQInputMethodEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?viewportEvent@TextEditorWidget@TextEditor@@MEAA_NPEAVQEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?createMimeDataFromSelection@TextEditorWidget@TextEditor@@MEBAPEAVQMimeData@@XZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?canInsertFromMimeData@TextEditorWidget@TextEditor@@MEBA_NPEBVQMimeData@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?insertFromMimeData@TextEditorWidget@TextEditor@@MEAAXPEBVQMimeData@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?doSetTextCursor@TextEditorWidget@TextEditor@@MEAAXAEBVQTextCursor@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?aboutToOpen@TextEditorWidget@TextEditor@@UEAAXAEBVQString@@0@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?openFinishedSuccessfully@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?restoreState@TextEditorWidget@TextEditor@@UEAAXAEBVQByteArray@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:192
>>>               debug\sidebysidediffeditorwidget.obj:(?restoreState@SideDiffEditorWidget@Internal@DiffEditor@@QEAAXXZ)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:113
>>>               debug\unifieddiffeditorwidget.obj:(?restoreState@UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAAXXZ)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?createAssistInterface@TextEditorWidget@TextEditor@@UEBAPEAVAssistInterface@2@W4AssistKind@2@W4AssistReason@2@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:976
>>>               debug\cppeditorwidget.obj:(?createAssistInterface@CppEditorWidget@Internal@CppEditor@@UEBAPEAVAssistInterface@TextEditor@@W4AssistKind@5@W4AssistReason@5@@Z)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?extraAreaWidth@TextEditorWidget@TextEditor@@UEBAHPEAH@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:108
>>>               debug\sidebysidediffeditorwidget.obj:(?extraAreaWidth@SideDiffEditorWidget@Internal@DiffEditor@@MEBAHPEAH@Z)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?extraAreaPaintEvent@TextEditorWidget@TextEditor@@UEAAXPEAVQPaintEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?extraAreaLeaveEvent@TextEditorWidget@TextEditor@@UEAAXPEAVQEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?extraAreaContextMenuEvent@TextEditorWidget@TextEditor@@UEAAXPEAVQContextMenuEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?extraAreaMouseEvent@TextEditorWidget@TextEditor@@UEAAXPEAVQMouseEvent@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?copy@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?paste@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:288
>>>               debug\cppeditorwidget.obj:(?paste@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpplocalrenaming.cpp:93
>>>               debug\cpplocalrenaming.obj:(?handlePaste@CppLocalRenaming@Internal@CppEditor@@QEAA_NXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?cut@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:294
>>>               debug\cppeditorwidget.obj:(?cut@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpplocalrenaming.cpp:102
>>>               debug\cpplocalrenaming.obj:(?handleCut@CppLocalRenaming@Internal@CppEditor@@QEAA_NXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?selectAll@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:300
>>>               debug\cppeditorwidget.obj:(?selectAll@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?autoIndent@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?rewrapParagraph@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?unCommentSelection@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?autoFormat@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?encourageApply@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1061
>>>               debug\cppeditorwidget.obj:(?encourageApply@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?setDisplaySettings@TextEditorWidget@TextEditor@@UEAAXAEBVDisplaySettings@2@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:102
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:128
>>>               debug\diffeditor.obj:(?setDisplaySettings@DescriptionEditorWidget@Internal@DiffEditor@@MEAAXAEBVDisplaySettings@TextEditor@@@Z)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:162
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:216
>>>               debug\sidebysidediffeditorwidget.obj:(?setDisplaySettings@SideDiffEditorWidget@Internal@DiffEditor@@UEAAXAEBVDisplaySettings@TextEditor@@@Z)
>>> referenced 2 more times

lld-link: error: undefined symbol: ?setMarginSettings@TextEditorWidget@TextEditor@@UEAAXAEBVMarginSettings@2@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:133
>>>               debug\diffeditor.obj:(?setMarginSettings@DescriptionEditorWidget@Internal@DiffEditor@@MEAAXAEBVMarginSettings@TextEditor@@@Z)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?selectBlockUp@TextEditorWidget@TextEditor@@UEAA_NXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:471
>>>               debug\cppeditorwidget.obj:(?selectBlockUp@CppEditorWidget@Internal@CppEditor@@UEAA_NXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?selectBlockDown@TextEditorWidget@TextEditor@@UEAA_NXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:485
>>>               debug\cppeditorwidget.obj:(?selectBlockDown@CppEditorWidget@Internal@CppEditor@@UEAA_NXZ)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?findUsages@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?renameSymbolUnderCursor@TextEditorWidget@TextEditor@@UEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?paintBlock@TextEditorWidget@TextEditor@@MEBAXPEAVQPainter@@AEBVQTextBlock@@AEBVQPointF@@AEBV?$QVector@UFormatRange@QTextLayout@@@@AEBVQRect@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\selectabletexteditorwidget.cpp:140
>>>               debug\selectabletexteditorwidget.obj:(?paintBlock@SelectableTextEditorWidget@Internal@DiffEditor@@EEBAXPEAVQPainter@@AEBVQTextBlock@@AEBVQPointF@@AEBV?$QVector@UFormatRange@QTextLayout@@@@AEBVQRect@@@Z)

lld-link: error: undefined symbol: ?plainTextFromSelection@TextEditorWidget@TextEditor@@MEBA?AVQString@@AEBVQTextCursor@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?lineNumber@TextEditorWidget@TextEditor@@MEBA?AVQString@@H@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:682
>>>               debug\vcsbaseeditor.obj:(?lineNumber@VcsBaseEditorWidget@VcsBase@@MEBA?AVQString@@H@Z)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?lineNumberDigits@TextEditorWidget@TextEditor@@MEBAHXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:686
>>>               debug\vcsbaseeditor.obj:(?lineNumberDigits@VcsBaseEditorWidget@VcsBase@@MEBAHXZ)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?selectionVisible@TextEditorWidget@TextEditor@@MEBA_NH@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?replacementVisible@TextEditorWidget@TextEditor@@MEBA_NH@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?replacementPenColor@TextEditorWidget@TextEditor@@MEBA?AVQColor@@H@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?triggerPendingUpdates@TextEditorWidget@TextEditor@@MEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?applyFontSettings@TextEditorWidget@TextEditor@@MEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:504
>>>               debug\qmljseditor.obj:(?applyFontSettings@QmlJSEditorWidget@QmlJSEditor@@MEAAXXZ)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:137
>>>               debug\diffeditor.obj:(?applyFontSettings@DescriptionEditorWidget@Internal@DiffEditor@@MEAAXXZ)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:221
>>>               debug\sidebysidediffeditorwidget.obj:(?applyFontSettings@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXXZ)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?findLinkAt@TextEditorWidget@TextEditor@@MEAAXAEBVQTextCursor@@$$QEAV?$function@$$A6AXAEBULink@Utils@@@Z@std@@_N2@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?foldReplacementText@TextEditorWidget@TextEditor@@MEBA?AVQString@@AEBVQTextBlock@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1009
>>>               debug\qmljseditor.obj:(?foldReplacementText@QmlJSEditorWidget@QmlJSEditor@@MEBA?AVQString@@AEBVQTextBlock@@@Z)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?drawCollapsedBlockPopup@TextEditorWidget@TextEditor@@MEAAXAEAVQPainter@@AEBVQTextBlock@@VQPointF@@AEBVQRect@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?slotCursorPositionChanged@TextEditorWidget@TextEditor@@MEAAXXZ
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\cppeditorwidget.obj:(??_7CppEditorWidget@Internal@CppEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?slotCodeStyleSettingsChanged@TextEditorWidget@TextEditor@@MEAAXAEBVQVariant@@@Z
>>> referenced by debug\plaintexteditorfactory.obj:(??_7PlainTextEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\snippeteditor.obj:(??_7SnippetEditorWidget@TextEditor@@6BQObject@@@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditorWidget@QmlJSEditor@@6BQObject@@@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditorWidget@VcsBase@@6BQObject@@@)
>>> referenced by debug\diffeditor.obj:(??_7DescriptionEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\selectabletexteditorwidget.obj:(??_7SelectableTextEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\sidebysidediffeditorwidget.obj:(??_7SideDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)
>>> referenced by debug\unifieddiffeditorwidget.obj:(??_7UnifiedDiffEditorWidget@Internal@DiffEditor@@6BQObject@@@)

lld-link: error: undefined symbol: ?optionalActions@TextEditorWidget@TextEditor@@QEAAIXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:642
>>>               debug\texteditoractionhandler.obj:(?updateOptionalActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?displaySettings@TextEditorWidget@TextEditor@@QEBAAEBVDisplaySettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:626
>>>               debug\texteditoractionhandler.obj:(?updateActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:628
>>>               debug\texteditoractionhandler.obj:(?updateActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:386
>>>               debug\texteditoractionhandler.obj:(??R<lambda_43>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:403
>>>               debug\texteditoractionhandler.obj:(??R<lambda_45>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:55
>>>               debug\codestyleeditor.obj:(??0CodeStyleEditor@TextEditor@@QEAA@PEAVICodeStylePreferencesFactory@1@PEAVICodeStylePreferences@1@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:96
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:124
>>>               debug\diffeditor.obj:(?setDisplaySettings@DescriptionEditorWidget@Internal@DiffEditor@@MEAAXAEBVDisplaySettings@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:157
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:211
>>>               debug\sidebysidediffeditorwidget.obj:(?setDisplaySettings@SideDiffEditorWidget@Internal@DiffEditor@@UEAAXAEBVDisplaySettings@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:55
>>>               debug\unifieddiffeditorwidget.obj:(??0UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced 1 more times

lld-link: error: undefined symbol: ?undo@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:217
>>>               debug\texteditoractionhandler.obj:(??R<lambda_0>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?redo@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:219
>>>               debug\texteditoractionhandler.obj:(??R<lambda_1>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?lineNumberFilter@TextEditorPlugin@Internal@TextEditor@@SAPEAVLineNumberFilter@23@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:229
>>>               debug\texteditoractionhandler.obj:(??R<lambda_6>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?shortcutString@ILocatorFilter@Core@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:229
>>>               debug\texteditoractionhandler.obj:(??R<lambda_6>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?show@LocatorManager@Core@@SAXAEBVQString@@HH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:234
>>>               debug\texteditoractionhandler.obj:(??R<lambda_6>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?print@TextEditorWidget@TextEditor@@QEAAXPEAVQPrinter@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:238
>>>               debug\texteditoractionhandler.obj:(??R<lambda_7>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:241
>>>               debug\texteditoractionhandler.obj:(??R<lambda_8>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteEndOfLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:244
>>>               debug\texteditoractionhandler.obj:(??R<lambda_9>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteEndOfWord@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:247
>>>               debug\texteditoractionhandler.obj:(??R<lambda_10>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteEndOfWordCamelCase@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:251
>>>               debug\texteditoractionhandler.obj:(??R<lambda_11>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteStartOfLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:254
>>>               debug\texteditoractionhandler.obj:(??R<lambda_12>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteStartOfWord@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:259
>>>               debug\texteditoractionhandler.obj:(??R<lambda_13>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?deleteStartOfWordCamelCase@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:263
>>>               debug\texteditoractionhandler.obj:(??R<lambda_14>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoBlockStartWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:267
>>>               debug\texteditoractionhandler.obj:(??R<lambda_15>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoBlockEndWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:271
>>>               debug\texteditoractionhandler.obj:(??R<lambda_16>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?moveLineUp@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:274
>>>               debug\texteditoractionhandler.obj:(??R<lambda_17>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?moveLineDown@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:277
>>>               debug\texteditoractionhandler.obj:(??R<lambda_18>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?copyLineUp@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:280
>>>               debug\texteditoractionhandler.obj:(??R<lambda_19>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?copyLineDown@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:283
>>>               debug\texteditoractionhandler.obj:(??R<lambda_20>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?joinLines@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:286
>>>               debug\texteditoractionhandler.obj:(??R<lambda_21>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?insertLineAbove@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:289
>>>               debug\texteditoractionhandler.obj:(??R<lambda_22>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?insertLineBelow@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:293
>>>               debug\texteditoractionhandler.obj:(??R<lambda_23>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?switchUtf8bom@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:297
>>>               debug\texteditoractionhandler.obj:(??R<lambda_24>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?indent@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:300
>>>               debug\texteditoractionhandler.obj:(??R<lambda_25>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?unindent@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:302
>>>               debug\texteditoractionhandler.obj:(??R<lambda_26>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?openLinkUnderCursor@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:306
>>>               debug\texteditoractionhandler.obj:(??R<lambda_27>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:323
>>>               debug\texteditoractionhandler.obj:(??R<lambda_31>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?openLinkUnderCursorInNextSplit@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:310
>>>               debug\texteditoractionhandler.obj:(??R<lambda_28>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:327
>>>               debug\texteditoractionhandler.obj:(??R<lambda_32>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?viewPageUp@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:334
>>>               debug\texteditoractionhandler.obj:(??R<lambda_33>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?viewPageDown@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:338
>>>               debug\texteditoractionhandler.obj:(??R<lambda_34>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?viewLineUp@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:342
>>>               debug\texteditoractionhandler.obj:(??R<lambda_35>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?viewLineDown@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:346
>>>               debug\texteditoractionhandler.obj:(??R<lambda_36>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?selectEncoding@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:354
>>>               debug\texteditoractionhandler.obj:(??R<lambda_37>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?circularPaste@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:357
>>>               debug\texteditoractionhandler.obj:(??R<lambda_38>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?pasteWithoutFormat@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:361
>>>               debug\texteditoractionhandler.obj:(??R<lambda_39>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?cleanWhitespace@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:397
>>>               debug\texteditoractionhandler.obj:(??R<lambda_44>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?cutLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:419
>>>               debug\texteditoractionhandler.obj:(??R<lambda_47>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?copyLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:423
>>>               debug\texteditoractionhandler.obj:(??R<lambda_48>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?duplicateSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:427
>>>               debug\texteditoractionhandler.obj:(??R<lambda_49>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?duplicateSelectionAndComment@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:432
>>>               debug\texteditoractionhandler.obj:(??R<lambda_50>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?uppercaseSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:436
>>>               debug\texteditoractionhandler.obj:(??R<lambda_51>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?lowercaseSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:442
>>>               debug\texteditoractionhandler.obj:(??R<lambda_52>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?sortSelectedLines@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:447
>>>               debug\texteditoractionhandler.obj:(??R<lambda_53>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?fold@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:453
>>>               debug\texteditoractionhandler.obj:(??R<lambda_54>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?unfold@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:456
>>>               debug\texteditoractionhandler.obj:(??R<lambda_55>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?unfoldAll@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:459
>>>               debug\texteditoractionhandler.obj:(??R<lambda_56>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?zoomF@TextEditorWidget@TextEditor@@QEAAXM@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:463
>>>               debug\texteditoractionhandler.obj:(??R<lambda_57>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:467
>>>               debug\texteditoractionhandler.obj:(??R<lambda_58>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?zoomReset@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:471
>>>               debug\texteditoractionhandler.obj:(??R<lambda_59>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoBlockStart@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:476
>>>               debug\texteditoractionhandler.obj:(??R<lambda_60>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoBlockEnd@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:480
>>>               debug\texteditoractionhandler.obj:(??R<lambda_61>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?selectWordUnderCursor@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:493
>>>               debug\texteditoractionhandler.obj:(??R<lambda_64>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoDocumentStart@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:498
>>>               debug\texteditoractionhandler.obj:(??R<lambda_65>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoDocumentEnd@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:501
>>>               debug\texteditoractionhandler.obj:(??R<lambda_66>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoLineStart@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:504
>>>               debug\texteditoractionhandler.obj:(??R<lambda_67>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoLineEnd@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:507
>>>               debug\texteditoractionhandler.obj:(??R<lambda_68>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:510
>>>               debug\texteditoractionhandler.obj:(??R<lambda_69>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousLine@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:513
>>>               debug\texteditoractionhandler.obj:(??R<lambda_70>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousCharacter@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:517
>>>               debug\texteditoractionhandler.obj:(??R<lambda_71>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextCharacter@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:520
>>>               debug\texteditoractionhandler.obj:(??R<lambda_72>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousWord@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:523
>>>               debug\texteditoractionhandler.obj:(??R<lambda_73>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextWord@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:526
>>>               debug\texteditoractionhandler.obj:(??R<lambda_74>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousWordCamelCase@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:530
>>>               debug\texteditoractionhandler.obj:(??R<lambda_75>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextWordCamelCase@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:534
>>>               debug\texteditoractionhandler.obj:(??R<lambda_76>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoLineStartWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:540
>>>               debug\texteditoractionhandler.obj:(??R<lambda_77>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoLineEndWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:544
>>>               debug\texteditoractionhandler.obj:(??R<lambda_78>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextLineWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:548
>>>               debug\texteditoractionhandler.obj:(??R<lambda_79>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousLineWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:552
>>>               debug\texteditoractionhandler.obj:(??R<lambda_80>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousCharacterWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:556
>>>               debug\texteditoractionhandler.obj:(??R<lambda_81>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextCharacterWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:560
>>>               debug\texteditoractionhandler.obj:(??R<lambda_82>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousWordWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:564
>>>               debug\texteditoractionhandler.obj:(??R<lambda_83>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextWordWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:568
>>>               debug\texteditoractionhandler.obj:(??R<lambda_84>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoPreviousWordCamelCaseWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:572
>>>               debug\texteditoractionhandler.obj:(??R<lambda_85>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?gotoNextWordCamelCaseWithSelection@TextEditorWidget@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditoractionhandler.cpp:576
>>>               debug\texteditoractionhandler.obj:(??R<lambda_86>@?0??createActions@TextEditorActionHandlerPrivate@Internal@TextEditor@@QEAAXXZ@QEBA?A?<auto>@@PEAVTextEditorWidget@4@@Z)

lld-link: error: undefined symbol: ?setPriority@ILocatorFilter@Core@@IEAAXW4Priority@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:49
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:46
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:113
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)

lld-link: error: undefined symbol: ?setIncludedByDefault@ILocatorFilter@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:51
>>>               debug\linenumberfilter.obj:(??0LineNumberFilter@Internal@TextEditor@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppclassesfilter.cpp:38
>>>               debug\cppclassesfilter.obj:(??0CppClassesFilter@CppTools@@QEAA@PEAVCppLocatorData@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:47
>>>               debug\cppcurrentdocumentfilter.obj:(??0CppCurrentDocumentFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfunctionsfilter.cpp:40
>>>               debug\cppfunctionsfilter.obj:(??0CppFunctionsFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:112
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:46
>>>               debug\cpplocatorfilter.obj:(??0CppLocatorFilter@Internal@CppTools@@QEAA@PEAVCppLocatorData@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:45
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:44
>>>               debug\currentprojectfilter.obj:(??0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ?addCurrentPositionToNavigationHistory@EditorManager@Core@@SAXAEBVQByteArray@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\linenumberfilter.cpp:93
>>>               debug\linenumberfilter.obj:(?accept@LineNumberFilter@Internal@TextEditor@@UEBAXULocatorFilterEntry@Core@@PEAVQString@@PEAH2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppoutline.cpp:164
>>>               debug\cppoutline.obj:(?updateTextCursor@CppOutlineWidget@Internal@CppEditor@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppeditoroutline.cpp:241
>>>               debug\cppeditoroutline.obj:(?gotoSymbolInEditor@CppEditorOutline@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:278
>>>               debug\qmljseditor.obj:(?jumpToOutlineElement@QmlJSEditorWidget@QmlJSEditor@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsoutline.cpp:239
>>>               debug\qmljsoutline.obj:(??R<lambda_3>@?0??updateTextCursor@QmlJSOutlineWidget@Internal@QmlJSEditor@@AEAAXAEBVQModelIndex@@@Z@QEBA?A?<auto>@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:883
>>>               debug\vcsbaseeditor.obj:(?slotJumpToEntry@VcsBaseEditorWidget@VcsBase@@AEAAXH@Z)

lld-link: error: undefined symbol: ?openFindDialog@Find@Core@@SAXPEAVIFindFilter@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinfiles.cpp:227
>>>               debug\findinfiles.obj:(?findOnFileSystem@FindInFiles@TextEditor@@SAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?validChanged@IFindFilter@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinfiles.cpp:118
>>>               debug\findinfiles.obj:(?setValid@FindInFiles@TextEditor@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?defaultShortcut@IFindFilter@Core@@UEBA?AVQKeySequence@@XZ
>>> referenced by debug\findinfiles.obj:(??_7FindInFiles@TextEditor@@6B@)
>>> referenced by debug\basefilefind.obj:(??_7BaseFileFind@TextEditor@@6B@)
>>> referenced by debug\findincurrentfile.obj:(??_7FindInCurrentFile@Internal@TextEditor@@6B@)
>>> referenced by debug\findinopenfiles.obj:(??_7FindInOpenFiles@Internal@TextEditor@@6B@)
>>> referenced by debug\symbolsfindfilter.obj:(??_7SymbolsFindFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfind.obj:(??_7AllProjectsFind@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfind.obj:(??_7CurrentProjectFind@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?supportedFindFlags@IFindFilter@Core@@UEBA?AV?$QFlags@W4FindFlag@Core@@@@XZ
>>> referenced by debug\findinfiles.obj:(??_7FindInFiles@TextEditor@@6B@)
>>> referenced by debug\basefilefind.obj:(??_7BaseFileFind@TextEditor@@6B@)
>>> referenced by debug\findincurrentfile.obj:(??_7FindInCurrentFile@Internal@TextEditor@@6B@)
>>> referenced by debug\findinopenfiles.obj:(??_7FindInOpenFiles@Internal@TextEditor@@6B@)
>>> referenced by debug\symbolsfindfilter.obj:(??_7SymbolsFindFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfind.obj:(??_7AllProjectsFind@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfind.obj:(??_7CurrentProjectFind@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ??0IFindFilter@Core@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:167
>>>               debug\basefilefind.obj:(??0BaseFileFind@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:62
>>>               debug\symbolsfindfilter.obj:(??0SymbolsFindFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z)

lld-link: error: undefined symbol: ??1IFindFilter@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:169
>>>               debug\basefilefind.obj:(?dtor$5@?0???0BaseFileFind@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:171
>>>               debug\basefilefind.obj:(??1BaseFileFind@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:68
>>>               debug\symbolsfindfilter.obj:(?dtor$7@?0???0SymbolsFindFilter@Internal@CppTools@@QEAA@PEAVCppModelManager@2@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.h:50
>>>               debug\symbolsfindfilter.obj:(??1SymbolsFindFilter@Internal@CppTools@@UEAA@XZ)

lld-link: error: undefined symbol: ?instance@SearchResultWindow@Core@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:229
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:324
>>>               debug\basefilefind.obj:(?doReplace@BaseFileFind@TextEditor@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:266
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:415
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:364
>>>               debug\cppeditorwidget.obj:(?onReplaceUsagesClicked@Internal@CppEditor@@YAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:315
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:391
>>>               debug\cppfindreferences.obj:(?onReplaceButtonClicked@CppFindReferences@Internal@CppTools@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:366
>>>               debug\cppfindreferences.obj:(?findAll_helper@CppFindReferences@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@PEAVSymbol@CPlusPlus@@AEBVLookupContext@7@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:713
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:726
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced 5 more times

lld-link: error: undefined symbol: ?descriptionForFindFlags@IFindFilter@Core@@SA?AVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:229
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:241
>>>               debug\symbolsfindfilter.obj:(?toolTip@SymbolsFindFilter@Internal@CppTools@@AEBA?AVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ?startNewSearch@SearchResultWindow@Core@@QEAAPEAVSearchResult@2@AEBVQString@@00W4SearchMode@12@W4PreserveCaseMode@12@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:229
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:415
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:315
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:713
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:101
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:872
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:875
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?setTextToReplace@SearchResult@Core@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:233
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:418
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:321
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:719
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:878
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?setSearchAgainSupported@SearchResult@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:234
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:419
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:327
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:103
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ?setUserData@SearchResult@Core@@QEAAXAEBVQVariant@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:243
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:340
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:566
>>>               debug\cppfindreferences.obj:(?displayResults@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:119
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ?activated@SearchResult@Core@@QEAAXAEBVSearchResultItem@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:244
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:431
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:362
>>>               debug\cppfindreferences.obj:(?findAll_helper@CppFindReferences@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@PEAVSymbol@CPlusPlus@@AEBVLookupContext@7@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:729
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:104
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:882
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?replaceButtonClicked@SearchResult@Core@@QEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:249
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:420
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:325
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:723
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:879
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?visibilityChanged@SearchResult@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:251
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)

lld-link: error: undefined symbol: ?searchAgainRequested@SearchResult@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:253
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:422
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:328
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:108
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ?requestEnabledCheck@SearchResult@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:255
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:257
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)

lld-link: error: undefined symbol: ?enabledChanged@IFindFilter@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:255
>>>               debug\basefilefind.obj:(?runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findincurrentfile.cpp:88
>>>               debug\findincurrentfile.obj:(?handleFileChange@FindInCurrentFile@Internal@TextEditor@@AEAAXPEAVIEditor@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findincurrentfile.cpp:94
>>>               debug\findincurrentfile.obj:(?handleFileChange@FindInCurrentFile@Internal@TextEditor@@AEAAXPEAVIEditor@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinopenfiles.cpp:100
>>>               debug\findinopenfiles.obj:(?updateEnabledState@FindInOpenFiles@Internal@TextEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:213
>>>               debug\symbolsfindfilter.obj:(?onTaskStarted@SymbolsFindFilter@Internal@CppTools@@AEAAXVId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:220
>>>               debug\symbolsfindfilter.obj:(?onAllTasksFinished@SymbolsFindFilter@Internal@CppTools@@AEAAXVId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:110
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfind.cpp:105
>>>               debug\allprojectsfind.obj:(?handleFileListChanged@AllProjectsFind@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfind.cpp:96
>>>               debug\currentprojectfind.obj:(?handleProjectChanged@CurrentProjectFind@Internal@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?staticMetaObject@SearchResult@Core@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXAEBVSearchResultItem@2@@ZV<lambda_0>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@2@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXAEBVSearchResultItem@4@@ZPEBV0@V<lambda_0>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@4@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXXZV<lambda_1>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@2@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXXZPEBV0@V<lambda_1>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@4@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXXZV<lambda_2>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@2@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXXZPEBV0@V<lambda_2>@?0??runNewSearch@BaseFileFind@TextEditor@@AEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@W4SearchMode@SearchResultWindow@4@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAX_N@ZV<lambda_3>@?0??runSearch@BaseFileFind@TextEditor@@AEAAXPEAV12@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAX_N@ZPEBV0@V<lambda_3>@?0??runSearch@BaseFileFind@TextEditor@@AEAAXPEAV34@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXH@ZV<lambda_6>@?0??runSearch@BaseFileFind@TextEditor@@AEAAXPEAV12@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXH@ZPEBV0@V<lambda_6>@?0??runSearch@BaseFileFind@TextEditor@@AEAAXPEAV34@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@ZP8BaseFileFind@TextEditor@@EAAX012@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@ZPEBVBaseFileFind@TextEditor@@P878@EAAX123@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAX_N@ZP8BaseFileFind@TextEditor@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAX_N@ZPEBVBaseFileFind@TextEditor@@P856@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\basefilefind.obj:(??$connect@P8SearchResult@Core@@EAAXXZP8QFutureWatcherBase@@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXXZPEBVQFutureWatcherBase@@P85@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\cppeditorwidget.obj:(??$connect@P8SearchResult@Core@@EAAXXZV<lambda_12>@?0??findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@56@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXXZPEBV0@V<lambda_12>@?0??findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@78@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\cppeditorwidget.obj:(??$connect@P8SearchResult@Core@@EAAXAEBVSearchResultItem@2@@ZV<lambda_13>@?0??findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@67@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVSearchResult@Core@@P834@EAAXAEBVSearchResultItem@4@@ZPEBV0@V<lambda_13>@?0??findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@89@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced 16 more times

lld-link: error: undefined symbol: ?notifyFilesChangedInternally@DocumentManager@Core@@SAXAEBVQStringList@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:323
>>>               debug\basefilefind.obj:(?doReplace@BaseFileFind@TextEditor@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)

lld-link: error: undefined symbol: ?staticMetaObject@IFindFilter@Core@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\basefilefind.obj:(??$connect@P8IFindFilter@Core@@EAAX_N@ZP8SearchResult@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVIFindFilter@Core@@P834@EAAX_N@ZPEBVSearchResult@4@P854@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\symbolsfindfilter.obj:(??$connect@P8IFindFilter@Core@@EAAX_N@ZP8SearchResult@2@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVIFindFilter@Core@@P834@EAAX_N@ZPEBVSearchResult@4@P854@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by debug\moc_basefilefind.obj:(?staticMetaObject@BaseFileFind@TextEditor@@2UQMetaObject@@B)
>>> referenced by debug\moc_symbolsfindfilter.obj:(?staticMetaObject@SymbolsFindFilter@Internal@CppTools@@2UQMetaObject@@B)

lld-link: error: undefined symbol: ?userData@SearchResult@Core@@QEBA?AVQVariant@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:264
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:425
>>>               debug\basefilefind.obj:(?openEditor@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@AEBVSearchResultItem@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:525
>>>               debug\basefilefind.obj:(?getAdditionalParameters@BaseFileFind@TextEditor@@KA?AVQVariant@@PEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:397
>>>               debug\cppfindreferences.obj:(?onReplaceButtonClicked@CppFindReferences@Internal@CppTools@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:453
>>>               debug\cppfindreferences.obj:(?searchAgain@CppFindReferences@Internal@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:573
>>>               debug\cppfindreferences.obj:(?searchFinished@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:527
>>>               debug\cppfindreferences.obj:(?displayResults@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:124
>>>               debug\symbolsfindfilter.obj:(?startSearch@SymbolsFindFilter@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@@Z)

lld-link: error: undefined symbol: ?cancelled@SearchResult@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:272
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:776
>>>               debug\cppfindreferences.obj:(?createWatcher@CppFindReferences@Internal@CppTools@@AEAAXAEBV?$QFuture@VUsage@CPlusPlus@@@@PEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:106
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:886
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?paused@SearchResult@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:274
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:778
>>>               debug\cppfindreferences.obj:(?createWatcher@CppFindReferences@Internal@CppTools@@AEAAXAEBV?$QFuture@VUsage@CPlusPlus@@@@PEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:107
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:888
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?countChanged@SearchResult@Core@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:292
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)

lld-link: error: undefined symbol: ?popup@SearchResult@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:296
>>>               debug\basefilefind.obj:(?runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:435
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:377
>>>               debug\cppfindreferences.obj:(?findAll_helper@CppFindReferences@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@PEAVSymbol@CPlusPlus@@AEBVLookupContext@7@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:755
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:152
>>>               debug\symbolsfindfilter.obj:(?startSearch@SymbolsFindFilter@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:896
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ??0ReadOnlyFilesDialog@Core@@QEAA@AEBV?$QList@VFilePath@Utils@@@@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:479
>>>               debug\basefilefind.obj:(?replaceAll@BaseFileFind@TextEditor@@SA?AVQStringList@@AEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)

lld-link: error: undefined symbol: ?setShowFailWarning@ReadOnlyFilesDialog@Core@@QEAAX_NAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:480
>>>               debug\basefilefind.obj:(?replaceAll@BaseFileFind@TextEditor@@SA?AVQStringList@@AEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:277
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)

lld-link: error: undefined symbol: ?exec@ReadOnlyFilesDialog@Core@@UEAAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:481
>>>               debug\basefilefind.obj:(?replaceAll@BaseFileFind@TextEditor@@SA?AVQStringList@@AEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:278
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)

lld-link: error: undefined symbol: ??1ReadOnlyFilesDialog@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:482
>>>               debug\basefilefind.obj:(?replaceAll@BaseFileFind@TextEditor@@SA?AVQStringList@@AEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:482
>>>               debug\basefilefind.obj:(?dtor$39@?0??replaceAll@BaseFileFind@TextEditor@@SA?AVQStringList@@AEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:279
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:279
>>>               debug\refactoringchanges.obj:(?dtor$18@?0??apply@RefactoringFile@TextEditor@@QEAA_NXZ@4HA)

lld-link: error: undefined symbol: ?openEditorAtSearchResult@EditorManager@Core@@SAXAEBVSearchResultItem@2@VId@Utils@@V?$QFlags@W4OpenEditorFlag@EditorManager@Core@@@@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:431
>>>               debug\basefilefind.obj:(?openEditor@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@AEBVSearchResultItem@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:433
>>>               debug\cppeditorwidget.obj:(??R<lambda_13>@?0??findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@23@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z@QEBA?A?<auto>@@AEBVSearchResultItem@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:363
>>>               debug\cppfindreferences.obj:(??R<lambda_0>@?0??findAll_helper@CppFindReferences@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@PEAVSymbol@CPlusPlus@@AEBVLookupContext@8@@Z@QEBA?A?<auto>@@AEBVSearchResultItem@6@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:731
>>>               debug\cppfindreferences.obj:(??R<lambda_3>@?0??findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z@QEBA?A?<auto>@@AEBVSearchResultItem@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:884
>>>               debug\qmljsfindreferences.obj:(??R<lambda_0>@?0??displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z@QEBA?A?<auto>@@AEBVSearchResultItem@Core@@@Z)

lld-link: error: undefined symbol: ?restart@SearchResult@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:450
>>>               debug\basefilefind.obj:(?searchAgain@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:457
>>>               debug\cppfindreferences.obj:(?searchAgain@CppFindReferences@Internal@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:227
>>>               debug\symbolsfindfilter.obj:(?searchAgain@SymbolsFindFilter@Internal@CppTools@@AEAAXXZ)

lld-link: error: undefined symbol: ?setSearchAgainEnabled@SearchResult@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:456
>>>               debug\basefilefind.obj:(?recheckEnabled@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:110
>>>               debug\symbolsfindfilter.obj:(?findAll@SymbolsFindFilter@Internal@CppTools@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfind.cpp:106
>>>               debug\currentprojectfind.obj:(?recheckEnabled@CurrentProjectFind@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfind.cpp:110
>>>               debug\currentprojectfind.obj:(?recheckEnabled@CurrentProjectFind@Internal@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?openedTextDocumentContents@TextDocument@TextEditor@@SA?AV?$QMap@VQString@@V1@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:82
>>>               debug\basefilefind.obj:(?executeSearch@InternalEngine@?A0x8407F9D1@Internal@TextEditor@@UEAA?AV?$QFuture@V?$QList@VFileSearchResult@Utils@@@@@@AEBVFileFindParameters@3@PEAVBaseFileFind@3@@Z)

lld-link: error: undefined symbol: ?textDocumentFlagsForFindFlags@Core@@YA?AV?$QFlags@W4FindFlag@QTextDocument@@@@V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:82
>>>               debug\basefilefind.obj:(?executeSearch@InternalEngine@?A0x8407F9D1@Internal@TextEditor@@UEAA?AV?$QFuture@V?$QList@VFileSearchResult@Utils@@@@@@AEBVFileFindParameters@3@PEAVBaseFileFind@3@@Z)

lld-link: error: undefined symbol: ?addResults@SearchResult@Core@@QEAAXAEBV?$QList@VSearchResultItem@Core@@@@W4AddMode@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:219
>>>               debug\basefilefind.obj:(?displayResult@TextEditor@@YAXPEAV?$QFutureWatcher@V?$QList@VFileSearchResult@Utils@@@@@@PEAVSearchResult@Core@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:165
>>>               debug\symbolsfindfilter.obj:(?addResults@SymbolsFindFilter@Internal@CppTools@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?finishSearch@SearchResult@Core@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basefilefind.cpp:287
>>>               debug\basefilefind.obj:(??R<lambda_5>@?0??runSearch@BaseFileFind@TextEditor@@AEAAXPEAVSearchResult@Core@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:430
>>>               debug\cppeditorwidget.obj:(?findRenameCallback@Internal@CppEditor@@YAXPEAVCppEditorWidget@12@AEBVQTextCursor@@AEBV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:461
>>>               debug\cppfindreferences.obj:(?searchAgain@CppFindReferences@Internal@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:359
>>>               debug\cppfindreferences.obj:(?findAll_helper@CppFindReferences@Internal@CppTools@@AEAAXPEAVSearchResult@Core@@PEAVSymbol@CPlusPlus@@AEBVLookupContext@7@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:571
>>>               debug\cppfindreferences.obj:(?searchFinished@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:777
>>>               debug\cppfindreferences.obj:(??R<lambda_6>@?0??createWatcher@CppFindReferences@Internal@CppTools@@AEAAXAEBV?$QFuture@VUsage@CPlusPlus@@@@PEAVSearchResult@Core@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\symbolsfindfilter.cpp:171
>>>               debug\symbolsfindfilter.obj:(?finish@SymbolsFindFilter@Internal@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:914
>>>               debug\qmljsfindreferences.obj:(?searchFinished@FindReferences@QmlJSEditor@@AEAAXXZ)

lld-link: error: undefined symbol: ?staticMetaObject@IFindSupport@Core@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:524
>>>               debug\basefilefind.obj:(??$qobject_cast@PEAVIFindSupport@Core@@@@YAPEAVIFindSupport@Core@@PEAVQObject@@@Z)

lld-link: error: undefined symbol: ??0FormatDescription@TextEditor@@QEAA@W4TextStyle@1@AEBVQString@@1AEBVQColor@@W4ShowControls@01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:134
>>>               debug\texteditorsettings.obj:(?initialFormats@TextEditorSettingsPrivate@Internal@TextEditor@@CA?AV?$vector@VFormatDescription@TextEditor@@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@XZ)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@W4GlobalColor@Qt@@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAW4GlobalColor@Qt@@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@AEBVQColor@@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3AEBVQColor@@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@VQColor@@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAVQColor@@@Z)

lld-link: error: undefined symbol: ??0FontSettingsPage@TextEditor@@QEAA@PEAVFontSettings@1@AEBV?$vector@VFormatDescription@TextEditor@@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??0BehaviorSettingsPage@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??0DisplaySettingsPage@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??0HighlighterSettingsPage@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??0SnippetsSettingsPage@Internal@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??0CompletionSettingsPage@Internal@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??1SnippetsSettingsPage@Internal@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(?dtor$9@?0???0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??1TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??1HighlighterSettingsPage@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(?dtor$10@?0???0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??1TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??1DisplaySettingsPage@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(?dtor$11@?0???0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??1TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??1BehaviorSettingsPage@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(?dtor$12@?0???0TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:61
>>>               debug\texteditorsettings.obj:(??1TextEditorSettingsPrivate@Internal@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?behaviorSettings@BehaviorSettingsPage@TextEditor@@QEBAAEBVBehaviorSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:385
>>>               debug\texteditorsettings.obj:(??R<lambda_1>@?0???0TextEditorSettings@TextEditor@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:423
>>>               debug\texteditorsettings.obj:(?behaviorSettings@TextEditorSettings@TextEditor@@SAAEBVBehaviorSettings@2@XZ)

lld-link: error: undefined symbol: ?typingSettings@BehaviorSettingsPage@TextEditor@@QEBAAEBVTypingSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:415
>>>               debug\texteditorsettings.obj:(?typingSettings@TextEditorSettings@TextEditor@@SAAEBVTypingSettings@2@XZ)

lld-link: error: undefined symbol: ?storageSettings@BehaviorSettingsPage@TextEditor@@QEBAAEBVStorageSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:419
>>>               debug\texteditorsettings.obj:(?storageSettings@TextEditorSettings@TextEditor@@SAAEBVStorageSettings@2@XZ)

lld-link: error: undefined symbol: ?marginSettings@DisplaySettingsPage@TextEditor@@QEBAAEBVMarginSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:427
>>>               debug\texteditorsettings.obj:(?marginSettings@TextEditorSettings@TextEditor@@SAAEBVMarginSettings@2@XZ)

lld-link: error: undefined symbol: ?displaySettings@DisplaySettingsPage@TextEditor@@QEBAAEBVDisplaySettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:431
>>>               debug\texteditorsettings.obj:(?displaySettings@TextEditorSettings@TextEditor@@SAAEBVDisplaySettings@2@XZ)

lld-link: error: undefined symbol: ?completionSettings@CompletionSettingsPage@Internal@TextEditor@@QEAAAEBVCompletionSettings@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:435
>>>               debug\texteditorsettings.obj:(?completionSettings@TextEditorSettings@TextEditor@@SAAEBVCompletionSettings@2@XZ)

lld-link: error: undefined symbol: ?highlighterSettings@HighlighterSettingsPage@TextEditor@@QEBAAEBVHighlighterSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:439
>>>               debug\texteditorsettings.obj:(?highlighterSettings@TextEditorSettings@TextEditor@@SAAEBVHighlighterSettings@2@XZ)

lld-link: error: undefined symbol: ?extraEncodingSettings@BehaviorSettingsPage@TextEditor@@QEBAAEBVExtraEncodingSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:443
>>>               debug\texteditorsettings.obj:(?extraEncodingSettings@TextEditorSettings@TextEditor@@SAAEBVExtraEncodingSettings@2@XZ)

lld-link: error: undefined symbol: ?commentsSettings@CompletionSettingsPage@Internal@TextEditor@@QEAAAEBVCommentsSettings@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:447
>>>               debug\texteditorsettings.obj:(?commentsSettings@TextEditorSettings@TextEditor@@SAAEBVCommentsSettings@2@XZ)

lld-link: error: undefined symbol: ?codeStyle@BehaviorSettingsPage@TextEditor@@QEBAPEAVICodeStylePreferences@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:470
>>>               debug\texteditorsettings.obj:(?codeStyle@TextEditorSettings@TextEditor@@SAPEAVICodeStylePreferences@2@XZ)

lld-link: error: undefined symbol: ?codeStylePool@BehaviorSettingsPage@TextEditor@@QEBAPEAVCodeStylePool@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:491
>>>               debug\texteditorsettings.obj:(?codeStylePool@TextEditorSettings@TextEditor@@SAPEAVCodeStylePool@2@XZ)

lld-link: error: undefined symbol: ?setFontZoom@FontSettingsPage@TextEditor@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\texteditorsettings.cpp:517
>>>               debug\texteditorsettings.obj:(?setFontZoom@TextEditor@@YAXH@Z)

lld-link: error: undefined symbol: ??0FormatDescription@TextEditor@@QEAA@W4TextStyle@1@AEBVQString@@1AEBVFormat@1@W4ShowControls@01@@Z
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@VFormat@2@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAVFormat@4@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@AEAVFormat@2@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3AEAVFormat@4@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@AEAVFormat@2@W4ShowControls@12@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3AEAVFormat@4@$$QEAW4ShowControls@34@@Z)

lld-link: error: undefined symbol: ??0FormatDescription@TextEditor@@QEAA@W4TextStyle@1@AEBVQString@@1W4ShowControls@01@@Z
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@W4ShowControls@12@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAW4ShowControls@34@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3@Z)

lld-link: error: undefined symbol: ??0FormatDescription@TextEditor@@QEAA@W4TextStyle@1@AEBVQString@@1AEBVQColor@@W4UnderlineStyle@QTextCharFormat@@W4ShowControls@01@@Z
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@W4GlobalColor@Qt@@W4UnderlineStyle@QTextCharFormat@@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAW4GlobalColor@Qt@@$$QEAW4UnderlineStyle@QTextCharFormat@@@Z)
>>> referenced by C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\include\xmemory:671
>>>               debug\texteditorsettings.obj:(??$construct@VFormatDescription@TextEditor@@W4TextStyle@2@VQString@@V4@VQColor@@W4UnderlineStyle@QTextCharFormat@@W4ShowControls@12@@?$_Default_allocator_traits@V?$allocator@VFormatDescription@TextEditor@@@std@@@std@@SAXAEAV?$allocator@VFormatDescription@TextEditor@@@1@QEAVFormatDescription@TextEditor@@$$QEAW4TextStyle@4@$$QEAVQString@@3$$QEAVQColor@@$$QEAW4UnderlineStyle@QTextCharFormat@@$$QEAW4ShowControls@34@@Z)

lld-link: error: undefined symbol: ?openedTextDocumentEncodings@TextDocument@TextEditor@@SA?AV?$QMap@VQString@@PEAVQTextCodec@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findincurrentfile.cpp:59
>>>               debug\findincurrentfile.obj:(?files@FindInCurrentFile@Internal@TextEditor@@MEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\findinopenfiles.cpp:58
>>>               debug\findinopenfiles.obj:(?files@FindInOpenFiles@Internal@TextEditor@@MEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfind.cpp:74
>>>               debug\allprojectsfind.obj:(?filesForProjects@AllProjectsFind@Internal@ProjectExplorer@@IEBAPEAVFileIterator@Utils@@AEBVQStringList@@0AEBV?$QList@PEAVProject@ProjectExplorer@@@@@Z)

lld-link: error: undefined symbol: ?removeMarkFromMarksCache@TextDocument@TextEditor@@QEAAXPEAVTextMark@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.cpp:40
>>>               debug\textdocumentlayout.obj:(??1TextBlockUserData@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.cpp:576
>>>               debug\textdocumentlayout.obj:(?documentReloaded@TextDocumentLayout@TextEditor@@QEAAXV?$QList@PEAVTextMark@TextEditor@@@@PEAVTextDocument@2@@Z)

lld-link: error: undefined symbol: ??1State@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.cpp:46
>>>               debug\textdocumentlayout.obj:(??1TextBlockUserData@TextEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.cpp:46
>>>               debug\textdocumentlayout.obj:(?dtor$9@?0???1TextBlockUserData@TextEditor@@UEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:322
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:326
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:342
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:351
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:322
>>>               debug\highlighter.obj:(?dtor$12@?0??highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:326
>>>               debug\highlighter.obj:(?dtor$23@?0??highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:342
>>>               debug\highlighter.obj:(?dtor$42@?0??highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:351
>>>               debug\highlighter.obj:(?dtor$49@?0??highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z@4HA)
>>> referenced 2 more times

lld-link: error: undefined symbol: ??0State@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.h:65
>>>               debug\textdocumentlayout.obj:(??0TextBlockUserData@TextEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:318
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by debug\cpphighlighter.obj
>>> referenced by debug\cppcodeformatter.obj
>>> referenced by debug\qmljshighlighter.obj
>>> referenced by debug\diffandloghighlighter.obj
>>> referenced by debug\selectabletexteditorwidget.obj

lld-link: error: undefined symbol: ??0Repository@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:58
>>>               debug\highlighter.obj:(?highlightRepository@@YAPEAVRepository@KSyntaxHighlighting@@XZ)

lld-link: error: undefined symbol: ?addCustomSearchPath@Repository@KSyntaxHighlighting@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:59
>>>               debug\highlighter.obj:(?highlightRepository@@YAPEAVRepository@KSyntaxHighlighting@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:63
>>>               debug\highlighter.obj:(?highlightRepository@@YAPEAVRepository@KSyntaxHighlighting@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:265
>>>               debug\highlighter.obj:(?addCustomHighlighterPath@Highlighter@TextEditor@@SAXAEBVFilePath@Utils@@@Z)

lld-link: error: undefined symbol: ??0AbstractHighlighter@KSyntaxHighlighting@@IEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:136
>>>               debug\highlighter.obj:(??0Highlighter@TextEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ??1AbstractHighlighter@KSyntaxHighlighting@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:140
>>>               debug\highlighter.obj:(?dtor$7@?0???0Highlighter@TextEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.h:38
>>>               debug\highlighter.obj:(??1Highlighter@TextEditor@@UEAA@XZ)

lld-link: error: undefined symbol: ?definitionForName@Repository@KSyntaxHighlighting@@QEBA?AVDefinition@2@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:143
>>>               debug\highlighter.obj:(?definitionForName@Highlighter@TextEditor@@SA?AVDefinition@KSyntaxHighlighting@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?definitionsForFileName@Repository@KSyntaxHighlighting@@QEBA?AV?$QVector@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:202
>>>               debug\highlighter.obj:(?definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z)

lld-link: error: undefined symbol: ?isValid@Definition@KSyntaxHighlighting@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:213
>>>               debug\highlighter.obj:(?definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:193
>>>               debug\highlighter.obj:(?definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:224
>>>               debug\highlighter.obj:(?rememberDefinitionForDocument@Highlighter@TextEditor@@SAXAEBVDefinition@KSyntaxHighlighting@@PEBVTextDocument@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:313
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ??0Definition@KSyntaxHighlighting@@QEAA@AEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:215
>>>               debug\highlighter.obj:(?definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:195
>>>               debug\highlighter.obj:(?definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qlist.h:492
>>>               debug\highlighter.obj:(?node_copy@?$QList@VDefinition@KSyntaxHighlighting@@@@AEAAXPEAUNode@1@00@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qlist.h:465
>>>               debug\highlighter.obj:(?node_construct@?$QList@VDefinition@KSyntaxHighlighting@@@@AEAAXPEAUNode@1@AEBVDefinition@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ??1Definition@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:215
>>>               debug\highlighter.obj:(?definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:216
>>>               debug\highlighter.obj:(?definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:215
>>>               debug\highlighter.obj:(?dtor$47@?0??definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:215
>>>               debug\highlighter.obj:(?dtor$50@?0??definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:216
>>>               debug\highlighter.obj:(?dtor$54@?0??definitionsForFileName@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVFilePath@Utils@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:195
>>>               debug\highlighter.obj:(?definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:196
>>>               debug\highlighter.obj:(?definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:195
>>>               debug\highlighter.obj:(?dtor$15@?0??definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:195
>>>               debug\highlighter.obj:(?dtor$18@?0??definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:196
>>>               debug\highlighter.obj:(?dtor$22@?0??definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z@4HA)
>>> referenced 5 more times

lld-link: error: undefined symbol: ?definitionsForMimeType@Repository@KSyntaxHighlighting@@QEBA?AV?$QVector@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:188
>>>               debug\highlighter.obj:(?definitionsForMimeType@Highlighter@TextEditor@@SA?AV?$QList@VDefinition@KSyntaxHighlighting@@@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?name@Definition@KSyntaxHighlighting@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:237
>>>               debug\highlighter.obj:(?rememberDefinitionForDocument@Highlighter@TextEditor@@SAXAEBVDefinition@KSyntaxHighlighting@@PEBVTextDocument@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:242
>>>               debug\highlighter.obj:(?rememberDefinitionForDocument@Highlighter@TextEditor@@SAXAEBVDefinition@KSyntaxHighlighting@@PEBVTextDocument@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:249
>>>               debug\highlighter.obj:(?rememberDefinitionForDocument@Highlighter@TextEditor@@SAXAEBVDefinition@KSyntaxHighlighting@@PEBVTextDocument@2@@Z)

lld-link: error: undefined symbol: ??0DefinitionDownloader@KSyntaxHighlighting@@QEAA@PEAVRepository@1@PEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:269
>>>               debug\highlighter.obj:(?downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z)

lld-link: error: undefined symbol: ?done@DefinitionDownloader@KSyntaxHighlighting@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:271
>>>               debug\highlighter.obj:(?downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z)

lld-link: error: undefined symbol: ?informationMessage@DefinitionDownloader@KSyntaxHighlighting@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:279
>>>               debug\highlighter.obj:(?downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z)

lld-link: error: undefined symbol: ?start@DefinitionDownloader@KSyntaxHighlighting@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:286
>>>               debug\highlighter.obj:(?downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z)

lld-link: error: undefined symbol: ?reload@Repository@KSyntaxHighlighting@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:290
>>>               debug\highlighter.obj:(?reload@Highlighter@TextEditor@@SAXXZ)

lld-link: error: undefined symbol: ?syntaxHighlighter@TextDocument@TextEditor@@QEBAPEAVSyntaxHighlighter@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:293
>>>               debug\highlighter.obj:(?reload@Highlighter@TextEditor@@SAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:174
>>>               debug\cppeditordocument.obj:(?applyFontSettings@CppEditorDocument@Internal@CppEditor@@MEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:411
>>>               debug\cppeditordocument.obj:(??R<lambda_3>@?0??processor@CppEditorDocument@Internal@CppEditor@@AEAAPEAVBaseEditorDocumentProcessor@CppTools@@XZ@QEBA?A?<auto>@@V?$QSharedPointer@VDocument@CPlusPlus@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\semantichighlighter.cpp:150
>>>               debug\semantichighlighter.obj:(?onHighlighterResultAvailable@SemanticHighlighter@CppTools@@AEAAXHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\semantichighlighter.cpp:160
>>>               debug\semantichighlighter.obj:(?onHighlighterFinished@SemanticHighlighter@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemantichighlighter.cpp:532
>>>               debug\qmljssemantichighlighter.obj:(?applyResults@SemanticHighlighter@QmlJSEditor@@AEAAXHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemantichighlighter.cpp:543
>>>               debug\qmljssemantichighlighter.obj:(?finished@SemanticHighlighter@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1049
>>>               debug\vcsbaseeditor.obj:(?slotActivateAnnotation@VcsBaseEditorWidget@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:788
>>>               debug\vcsbaseeditor.obj:(?setHighlightingEnabled@VcsBaseEditorWidget@VcsBase@@QEAAX_N@Z)

lld-link: error: undefined symbol: ??1Repository@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:300
>>>               debug\highlighter.obj:(?handleShutdown@Highlighter@TextEditor@@SAXXZ)

lld-link: error: undefined symbol: ?definition@AbstractHighlighter@KSyntaxHighlighting@@QEBA?AVDefinition@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:313
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ??4State@KSyntaxHighlighting@@QEAAAEAV01@AEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:322
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:326
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.h:153
>>>               debug\highlighter.obj:(?setSyntaxState@TextBlockUserData@TextEditor@@QEAAXVState@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?highlightLine@AbstractHighlighter@KSyntaxHighlighting@@IEAA?AVState@2@AEBVQString@@AEBV32@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:326
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ??9State@KSyntaxHighlighting@@QEBA_NAEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:342
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ??0State@KSyntaxHighlighting@@QEAA@AEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:343
>>>               debug\highlighter.obj:(?highlightBlock@Highlighter@TextEditor@@MEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textdocumentlayout.h:151
>>>               debug\highlighter.obj:(?syntaxState@TextBlockUserData@TextEditor@@QEAA?AVState@KSyntaxHighlighting@@XZ)

lld-link: error: undefined symbol: ??0Theme@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:355
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?textStyle@Format@KSyntaxHighlighting@@QEBA?AW4TextStyle@Theme@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:356
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?hasTextColor@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:358
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?textColor@Format@KSyntaxHighlighting@@QEBA?AVQColor@@AEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:359
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?hasBackgroundColor@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:360
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:361
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:373
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:374
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?isBold@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:380
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?isItalic@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:382
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?isUnderline@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:384
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?isStrikeThrough@Format@KSyntaxHighlighting@@QEBA_NAEBVTheme@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:386
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ??1Theme@KSyntaxHighlighting@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:388
>>>               debug\highlighter.obj:(?applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:388
>>>               debug\highlighter.obj:(?dtor$72@?0??applyFormat@Highlighter@TextEditor@@MEAAXHHAEBVFormat@KSyntaxHighlighting@@@Z@4HA)

lld-link: error: undefined symbol: ?isValid@FoldingRegion@KSyntaxHighlighting@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:392
>>>               debug\highlighter.obj:(?applyFolding@Highlighter@TextEditor@@MEAAXHHVFoldingRegion@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?type@FoldingRegion@KSyntaxHighlighting@@QEBA?AW4Type@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:399
>>>               debug\highlighter.obj:(?applyFolding@Highlighter@TextEditor@@MEAAXHHVFoldingRegion@KSyntaxHighlighting@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\highlighter.cpp:407
>>>               debug\highlighter.obj:(?applyFolding@Highlighter@TextEditor@@MEAAXHHVFoldingRegion@KSyntaxHighlighting@@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@Theme@KSyntaxHighlighting@@2UQMetaObject@@B
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\3rdparty\syntax-highlighting\src\lib\theme.h:153
>>>               debug\highlighter.obj:(?qt_getEnumMetaObject@KSyntaxHighlighting@@YAPEBUQMetaObject@@W4TextStyle@Theme@1@@Z)

lld-link: error: undefined symbol: ??8Definition@KSyntaxHighlighting@@QEBA_NAEBV01@@Z
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qlist.h:1090
>>>               debug\highlighter.obj:(?contains_impl@?$QList@VDefinition@KSyntaxHighlighting@@@@AEBA_NAEBVDefinition@KSyntaxHighlighting@@UNotArrayCompatibleLayout@QListData@@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@DefinitionDownloader@KSyntaxHighlighting@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\highlighter.obj:(??$connect@P8DefinitionDownloader@KSyntaxHighlighting@@EAAXXZV<lambda_0>@?0??downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVDefinitionDownloader@KSyntaxHighlighting@@P834@EAAXXZPEBV0@V<lambda_0>@?0??downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\highlighter.obj:(??$connect@P8DefinitionDownloader@KSyntaxHighlighting@@EAAXAEBVQString@@@ZV<lambda_1>@?0??downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVDefinitionDownloader@KSyntaxHighlighting@@P834@EAAXAEBVQString@@@ZPEBV0@V<lambda_1>@?0??downloadDefinitions@Highlighter@TextEditor@@SAXV?$function@$$A6AXXZ@std@@@Z@W4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?setDefinition@AbstractHighlighter@KSyntaxHighlighting@@UEAAXAEBVDefinition@2@@Z
>>> referenced by debug\highlighter.obj:(??_7Highlighter@TextEditor@@6BAbstractHighlighter@KSyntaxHighlighting@@@)

lld-link: error: undefined symbol: ?setTheme@AbstractHighlighter@KSyntaxHighlighting@@UEAAXAEBVTheme@2@@Z
>>> referenced by debug\highlighter.obj:(??_7Highlighter@TextEditor@@6BAbstractHighlighter@KSyntaxHighlighting@@@)

lld-link: error: undefined symbol: ??0ReadOnlyFilesDialog@Core@@QEAA@AEBVFilePath@Utils@@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:273
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)

lld-link: error: undefined symbol: ??0FileChangeBlocker@Core@@QEAA@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:334
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:543
>>>               debug\foldernavigationwidget.obj:(?removeCurrentItem@FolderNavigationWidget@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectmodels.cpp:673
>>>               debug\projectmodels.obj:(?dropMimeData@FlatModel@Internal@ProjectExplorer@@UEAA_NPEBVQMimeData@@W4DropAction@Qt@@HHAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditorwidgetcontroller.cpp:164
>>>               debug\diffeditorwidgetcontroller.obj:(?patch@DiffEditorWidgetController@Internal@DiffEditor@@AEAAX_NHH@Z)

lld-link: error: undefined symbol: ??1FileChangeBlocker@Core@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:341
>>>               debug\refactoringchanges.obj:(?apply@RefactoringFile@TextEditor@@QEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\refactoringchanges.cpp:341
>>>               debug\refactoringchanges.obj:(?dtor$61@?0??apply@RefactoringFile@TextEditor@@QEAA_NXZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:556
>>>               debug\foldernavigationwidget.obj:(?removeCurrentItem@FolderNavigationWidget@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:556
>>>               debug\foldernavigationwidget.obj:(?dtor$30@?0??removeCurrentItem@FolderNavigationWidget@Internal@ProjectExplorer@@QEAAXXZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectmodels.cpp:684
>>>               debug\projectmodels.obj:(?dropMimeData@FlatModel@Internal@ProjectExplorer@@UEAA_NPEBVQMimeData@@W4DropAction@Qt@@HHAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectmodels.cpp:684
>>>               debug\projectmodels.obj:(?dtor$143@?0??dropMimeData@FlatModel@Internal@ProjectExplorer@@UEAA_NPEBVQMimeData@@W4DropAction@Qt@@HHAEBVQModelIndex@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditorwidgetcontroller.cpp:169
>>>               debug\diffeditorwidgetcontroller.obj:(?patch@DiffEditorWidgetController@Internal@DiffEditor@@AEAAX_NHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditorwidgetcontroller.cpp:169
>>>               debug\diffeditorwidgetcontroller.obj:(?dtor$69@?0??patch@DiffEditorWidgetController@Internal@DiffEditor@@AEAAX_NHH@Z@4HA)

lld-link: error: undefined symbol: ?setContextHelpItem@TextEditorWidget@TextEditor@@QEAAXAEBVHelpItem@Core@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basehoverhandler.cpp:47
>>>               debug\basehoverhandler.obj:(?checkPriority@BaseHoverHandler@TextEditor@@QEAAXPEAVTextEditorWidget@2@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basehoverhandler.cpp:106
>>>               debug\basehoverhandler.obj:(?propagateHelpId@BaseHoverHandler@TextEditor@@IEAAXPEAVTextEditorWidget@2@AEBV?$function@$$A6AXAEBVHelpItem@Core@@@Z@std@@@Z)

lld-link: error: undefined symbol: ?extraSelectionTooltip@TextEditorWidget@TextEditor@@QEBA?AVQString@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\basehoverhandler.cpp:124
>>>               debug\basehoverhandler.obj:(?identifyMatch@BaseHoverHandler@TextEditor@@MEAAXPEAVTextEditorWidget@2@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\colorpreviewhoverhandler.cpp:323
>>>               debug\colorpreviewhoverhandler.obj:(?identifyMatch@ColorPreviewHoverHandler@TextEditor@@EEAAXPEAVTextEditorWidget@2@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\resourcepreviewhoverhandler.cpp:164
>>>               debug\resourcepreviewhoverhandler.obj:(?identifyMatch@ResourcePreviewHoverHandler@Internal@CppEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@HV?$function@$$A6AXH@Z@std@@@Z)

lld-link: error: undefined symbol: ?setupFallBackEditor@TextEditorWidget@TextEditor@@QEAAXVId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:46
>>>               debug\snippeteditor.obj:(??0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:94
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\selectabletexteditorwidget.cpp:41
>>>               debug\selectabletexteditorwidget.obj:(??0SelectableTextEditorWidget@Internal@DiffEditor@@QEAA@VId@Utils@@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setHighlightCurrentLine@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:48
>>>               debug\snippeteditor.obj:(??0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setLineNumbersVisible@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:49
>>>               debug\snippeteditor.obj:(??0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setParenthesesMatchingEnabled@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\snippets\snippeteditor.cpp:50
>>>               debug\snippeteditor.obj:(??0SnippetEditorWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?position@TextEditorWidget@TextEditor@@QEBAHW4TextPositionOperation@2@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:156
>>>               debug\codeassistant.obj:(?invoke@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistKind@2@PEAVIAssistProvider@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:305
>>>               debug\codeassistant.obj:(?displayProposal@CodeAssistantPrivate@TextEditor@@QEAAXPEAVIAssistProposal@2@W4AssistReason@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:315
>>>               debug\codeassistant.obj:(?displayProposal@CodeAssistantPrivate@TextEditor@@QEAAXPEAVIAssistProposal@2@W4AssistReason@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:370
>>>               debug\codeassistant.obj:(?handlePrefixExpansion@CodeAssistantPrivate@TextEditor@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:439
>>>               debug\codeassistant.obj:(?notifyChange@CodeAssistantPrivate@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:442
>>>               debug\codeassistant.obj:(?notifyChange@CodeAssistantPrivate@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:416
>>>               debug\codeassistant.obj:(??R<lambda_2>@?0??identifyActivationSequence@CodeAssistantPrivate@TextEditor@@QEAAPEAVCompletionAssistProvider@3@XZ@QEBA?A?<auto>@@PEAV43@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:38
>>>               debug\textdocumentmanipulator.obj:(?currentPosition@TextDocumentManipulator@TextEditor@@UEBAHXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:43
>>>               debug\textdocumentmanipulator.obj:(?positionAt@TextDocumentManipulator@TextEditor@@UEBAHW4TextPositionOperation@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:968
>>>               debug\cppeditorwidget.obj:(?createAssistInterface@CppEditorWidget@Internal@CppEditor@@UEBAPEAVAssistInterface@TextEditor@@W4AssistKind@5@W4AssistReason@5@@Z)
>>> referenced 16 more times

lld-link: error: undefined symbol: ?textAt@TextEditorWidget@TextEditor@@QEBA?AVQString@@HH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:156
>>>               debug\codeassistant.obj:(?invoke@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistKind@2@PEAVIAssistProvider@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:315
>>>               debug\codeassistant.obj:(?displayProposal@CodeAssistantPrivate@TextEditor@@QEAAXPEAVIAssistProposal@2@W4AssistReason@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:371
>>>               debug\codeassistant.obj:(?handlePrefixExpansion@CodeAssistantPrivate@TextEditor@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:442
>>>               debug\codeassistant.obj:(?notifyChange@CodeAssistantPrivate@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:416
>>>               debug\codeassistant.obj:(??R<lambda_2>@?0??identifyActivationSequence@CodeAssistantPrivate@TextEditor@@QEAAPEAVCompletionAssistProvider@3@XZ@QEBA?A?<auto>@@PEAV43@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:51
>>>               debug\textdocumentmanipulator.obj:(?textAt@TextDocumentManipulator@TextEditor@@UEBA?AVQString@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:123
>>>               debug\textdocumentmanipulator.obj:(?textIsDifferentAt@TextDocumentManipulator@TextEditor@@AEBA_NHHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?keepAutoCompletionHighlight@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:463
>>>               debug\codeassistant.obj:(?destroyContext@CodeAssistantPrivate@TextEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:331
>>>               debug\codeassistant.obj:(?displayProposal@CodeAssistantPrivate@TextEditor@@QEAAXPEAVIAssistProposal@2@W4AssistReason@2@@Z)

lld-link: error: undefined symbol: ?hasBlockSelection@TextEditorWidget@TextEditor@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:193
>>>               debug\codeassistant.obj:(?requestProposal@CodeAssistantPrivate@TextEditor@@QEAAXW4AssistReason@2@W4AssistKind@2@PEAVIAssistProvider@2@@Z)

lld-link: error: undefined symbol: ?cursorRect@TextEditorWidget@TextEditor@@QEBA?AVQRect@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:348
>>>               debug\codeassistant.obj:(?displayProposal@CodeAssistantPrivate@TextEditor@@QEAAXPEAVIAssistProposal@2@W4AssistReason@2@@Z)

lld-link: error: undefined symbol: ?setCursorPosition@TextEditorWidget@TextEditor@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:384
>>>               debug\codeassistant.obj:(?handlePrefixExpansion@CodeAssistantPrivate@TextEditor@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:62
>>>               debug\textdocumentmanipulator.obj:(?setCursorPosition@TextDocumentManipulator@TextEditor@@UEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcompletionassist.cpp:457
>>>               debug\cppcompletionassist.obj:(?makeCorrection@CppAssistProposal@@UEAAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcompletionassist.cpp:459
>>>               debug\cppcompletionassist.obj:(?makeCorrection@CppAssistProposal@@UEAAXPEAVTextEditorWidget@TextEditor@@@Z)

lld-link: error: undefined symbol: ?replace@TextEditorWidget@TextEditor@@QEAAXHAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\codeassistant.cpp:385
>>>               debug\codeassistant.obj:(?handlePrefixExpansion@CodeAssistantPrivate@TextEditor@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcompletionassist.cpp:458
>>>               debug\cppcompletionassist.obj:(?makeCorrection@CppAssistProposal@@UEAAXPEAVTextEditorWidget@TextEditor@@@Z)

lld-link: error: undefined symbol: ?setAutoCompleteSkipPosition@TextEditorWidget@TextEditor@@QEAAXAEBVQTextCursor@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:68
>>>               debug\textdocumentmanipulator.obj:(?setAutoCompleteSkipPosition@TextDocumentManipulator@TextEditor@@UEAAXH@Z)

lld-link: error: undefined symbol: ?insertCodeSnippet@TextEditorWidget@TextEditor@@QEAAXAEBVQTextCursor@@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:84
>>>               debug\textdocumentmanipulator.obj:(?insertCodeSnippet@TextDocumentManipulator@TextEditor@@UEAAXHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?autoIndent@TextDocument@TextEditor@@QEAAXAEBVQTextCursor@@VQChar@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codeassist\textdocumentmanipulator.cpp:117
>>>               debug\textdocumentmanipulator.obj:(?autoIndent@TextDocumentManipulator@TextEditor@@UEAAXHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppdocumentationcommenthelper.cpp:316
>>>               debug\cppdocumentationcommenthelper.obj:(?trySplitComment@Internal@CppEditor@@YA_NPEAVTextEditorWidget@TextEditor@@AEBVSnapshot@CPlusPlus@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:918
>>>               debug\cppeditorwidget.obj:(?handleStringSplitting@CppEditorWidget@Internal@CppEditor@@IEBA_NPEAVQKeyEvent@@@Z)

lld-link: error: undefined symbol: ??0TabSettingsWidget@TextEditor@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\simplecodestylepreferenceswidget.cpp:39
>>>               debug\simplecodestylepreferenceswidget.obj:(??0SimpleCodeStylePreferencesWidget@TextEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setTabSettings@TabSettingsWidget@TextEditor@@QEAAXAEBVTabSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\simplecodestylepreferenceswidget.cpp:52
>>>               debug\simplecodestylepreferenceswidget.obj:(?setPreferences@SimpleCodeStylePreferencesWidget@TextEditor@@QEAAXPEAVICodeStylePreferences@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\simplecodestylepreferenceswidget.cpp:64
>>>               debug\simplecodestylepreferenceswidget.obj:(?setPreferences@SimpleCodeStylePreferencesWidget@TextEditor@@QEAAXPEAVICodeStylePreferences@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\simplecodestylepreferenceswidget.cpp:64
>>>               debug\simplecodestylepreferenceswidget.obj:(?setPreferences@SimpleCodeStylePreferencesWidget@TextEditor@@QEAAXPEAVICodeStylePreferences@2@@Z)

lld-link: error: undefined symbol: ??0CodeStyleSelectorWidget@TextEditor@@QEAA@PEAVICodeStylePreferencesFactory@1@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:52
>>>               debug\codestyleeditor.obj:(??0CodeStyleEditor@TextEditor@@QEAA@PEAVICodeStylePreferencesFactory@1@PEAVICodeStylePreferences@1@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setCodeStyle@CodeStyleSelectorWidget@TextEditor@@QEAAXPEAVICodeStylePreferences@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:53
>>>               debug\codestyleeditor.obj:(??0CodeStyleEditor@TextEditor@@QEAA@PEAVICodeStylePreferencesFactory@1@PEAVICodeStylePreferences@1@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setCodeStyle@TextEditorWidget@TextEditor@@QEAAXPEAVICodeStylePreferences@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:78
>>>               debug\codestyleeditor.obj:(??0CodeStyleEditor@TextEditor@@QEAA@PEAVICodeStylePreferencesFactory@1@PEAVICodeStylePreferences@1@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:243
>>>               debug\editorconfiguration.obj:(?configureEditor@EditorConfiguration@ProjectExplorer@@QEBAXPEAVBaseTextEditor@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:256
>>>               debug\editorconfiguration.obj:(?deconfigureEditor@EditorConfiguration@ProjectExplorer@@QEBAXPEAVBaseTextEditor@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:641
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:651
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:67
>>>               debug\unifieddiffeditorwidget.obj:(??0UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?indenter@TextDocument@TextEditor@@QEBAPEAVIndenter@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:87
>>>               debug\codestyleeditor.obj:(?updatePreview@CodeStyleEditor@TextEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\codestyleeditor.cpp:93
>>>               debug\codestyleeditor.obj:(?updatePreview@CodeStyleEditor@TextEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:234
>>>               debug\cppeditordocument.obj:(?onFilePathChanged@CppEditorDocument@Internal@CppEditor@@AEAAXAEBVFilePath@Utils@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:427
>>>               debug\cppeditordocument.obj:(?tabSettings@CppEditorDocument@Internal@CppEditor@@UEBA?AVTabSettings@TextEditor@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:435
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:462
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpprefactoringchanges.cpp:69
>>>               debug\cpprefactoringchanges.obj:(?indentSelection@CppRefactoringChangesData@CppTools@@UEBAXAEBVQTextCursor@@AEBVQString@@PEBVTextDocument@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpprefactoringchanges.cpp:84
>>>               debug\cpprefactoringchanges.obj:(?reindentSelection@CppRefactoringChangesData@CppTools@@UEBAXAEBVQTextCursor@@AEBVQString@@PEBVTextDocument@TextEditor@@@Z)

lld-link: error: undefined symbol: ?duplicateMimeData@TextEditorWidget@TextEditor@@SAPEAVQMimeData@@PEBV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\circularclipboardassist.cpp:71
>>>               debug\circularclipboardassist.obj:(?apply@ClipboardProposalItem@Internal@TextEditor@@UEBAXAEAVTextDocumentManipulatorInterface@3@H@Z)

lld-link: error: undefined symbol: ?textDocumentForFilePath@TextDocument@TextEditor@@SAPEAV12@AEBVFilePath@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:336
>>>               debug\textmark.obj:(?add@TextMarkRegistry@TextEditor@@SAXPEAVTextMark@2@@Z)

lld-link: error: undefined symbol: ?fontSettings@TextDocument@TextEditor@@QEBAAEBVFontSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:129
>>>               debug\textmark.obj:(?paintAnnotation@TextMark@TextEditor@@UEBAXAEAVQPainter@@PEAVQRectF@@NNAEBVQPointF@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpplocalrenaming.cpp:295
>>>               debug\cpplocalrenaming.obj:(?textCharFormat@CppLocalRenaming@Internal@CppEditor@@AEBA?AVQTextCharFormat@@W4TextStyle@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:170
>>>               debug\cppuseselectionsupdater.obj:(?toExtraSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEAA?AV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QVector@URange@CursorInfo@CppTools@@@@W4TextStyle@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\semantichighlighter.cpp:192
>>>               debug\semantichighlighter.obj:(?updateFormatMapFromFontSettings@SemanticHighlighter@CppTools@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:375
>>>               debug\qmljseditor.obj:(?updateUses@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:656
>>>               debug\qmljseditordocument.obj:(?applyFontSettings@QmlJSEditorDocument@QmlJSEditor@@MEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:222
>>>               debug\sidebysidediffeditorwidget.obj:(?applyFontSettings@SideDiffEditorWidget@Internal@DiffEditor@@MEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:586
>>>               debug\sidebysidediffeditorwidget.obj:(?customDrawCollapsedBlockPopup@SideDiffEditorWidget@Internal@DiffEditor@@IEAAXAEAVQPainter@@AEBVQTextBlock@@VQPointF@@AEBVQRect@@@Z)

lld-link: error: undefined symbol: ?moveMark@TextDocument@TextEditor@@QEAAXPEAVTextMark@2@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:195
>>>               debug\textmark.obj:(?move@TextMark@TextEditor@@UEAAXH@Z)

lld-link: error: undefined symbol: ?updateMark@TextDocument@TextEditor@@QEAAXPEAVTextMark@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:203
>>>               debug\textmark.obj:(?updateMarker@TextMark@TextEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?marks@TextDocument@TextEditor@@QEBA?AV?$QList@PEAVTextMark@TextEditor@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:371
>>>               debug\textmark.obj:(?documentRenamed@TextMarkRegistry@TextEditor@@AEAAXPEAVIDocument@Core@@AEBVQString@@1@Z)

lld-link: error: undefined symbol: ?instance@TextEditorPlugin@Internal@TextEditor@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\textmark.cpp:347
>>>               debug\textmark.obj:(?instance@TextMarkRegistry@TextEditor@@CAPEAV12@XZ)

lld-link: error: undefined symbol: ?qHash@@YAIAEBVQColor@@@Z
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qhashfunctions.h:119
>>>               debug\textmark.obj:(??$qHash@VQColor@@@@YAIAEBVQColor@@I@Z)

lld-link: error: undefined symbol: ?currentTextEditorWidget@TextEditorWidget@TextEditor@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:50
>>>               debug\formattexteditor.obj:(?formatCurrentFile@TextEditor@@YAXAEBVCommand@1@HH@Z)

lld-link: error: undefined symbol: ?executable@Command@TextEditor@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:64
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)

lld-link: error: undefined symbol: ?processing@Command@TextEditor@@QEBA?AW4Processing@12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:67
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)

lld-link: error: undefined symbol: ?options@Command@TextEditor@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:85
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:115
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)

lld-link: error: undefined symbol: ?pipeAddsNewline@Command@TextEditor@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:150
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)

lld-link: error: undefined symbol: ?returnsCRLF@Command@TextEditor@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\texteditor\formattexteditor.cpp:154
>>>               debug\formattexteditor.obj:(?format@TextEditor@@YA?AVFormatTask@1@V21@@Z)

lld-link: error: undefined symbol: ??0BaseTextEditor@TextEditor@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:38
>>>               debug\cppeditor.obj:(??0CppEditor@Internal@0@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1016
>>>               debug\qmljseditor.obj:(??0QmlJSEditor@0@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:156
>>>               debug\vcsbaseeditor.obj:(??0VcsBaseEditor@VcsBase@@QEAA@XZ)

lld-link: error: undefined symbol: ?addContext@BaseTextEditor@TextEditor@@QEAAXVId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:39
>>>               debug\cppeditor.obj:(??0CppEditor@Internal@0@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1017
>>>               debug\qmljseditor.obj:(??0QmlJSEditor@0@QEAA@XZ)

lld-link: error: undefined symbol: ??1BaseTextEditor@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:40
>>>               debug\cppeditor.obj:(?dtor$3@?0???0CppEditor@Internal@0@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.h:33
>>>               debug\cppeditor.obj:(??1CppEditor@Internal@0@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1018
>>>               debug\qmljseditor.obj:(?dtor$3@?0???0QmlJSEditor@0@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.h:137
>>>               debug\qmljseditor.obj:(??1QmlJSEditor@0@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.h:73
>>>               debug\vcsbaseeditor.obj:(??1VcsBaseEditor@VcsBase@@UEAA@XZ)

lld-link: error: undefined symbol: ?setSyntaxHighlighter@TextDocument@TextEditor@@QEAAXPEAVSyntaxHighlighter@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:43
>>>               debug\cppeditor.obj:(?decorateEditor@CppEditor@Internal@1@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:108
>>>               debug\cppeditordocument.obj:(??0CppEditorDocument@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:715
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1068
>>>               debug\qmljseditor.obj:(?decorateEditor@QmlJSEditorFactory@QmlJSEditor@@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:600
>>>               debug\qmljseditordocument.obj:(??0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:738
>>>               debug\vcsbaseeditor.obj:(?init@VcsBaseEditorWidget@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1054
>>>               debug\vcsbaseeditor.obj:(?slotActivateAnnotation@VcsBaseEditorWidget@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:114
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setIndenter@TextDocument@TextEditor@@QEAAXPEAVIndenter@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:44
>>>               debug\cppeditor.obj:(?decorateEditor@CppEditor@Internal@1@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:112
>>>               debug\cppeditordocument.obj:(??0CppEditorDocument@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1069
>>>               debug\qmljseditor.obj:(?decorateEditor@QmlJSEditorFactory@QmlJSEditor@@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:601
>>>               debug\qmljseditordocument.obj:(??0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setAutoCompleter@TextEditorWidget@TextEditor@@QEAAXPEAVAutoCompleter@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditor.cpp:46
>>>               debug\cppeditor.obj:(?decorateEditor@CppEditor@Internal@1@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1071
>>>               debug\qmljseditor.obj:(?decorateEditor@QmlJSEditorFactory@QmlJSEditor@@SAXPEAVTextEditorWidget@TextEditor@@@Z)

lld-link: error: undefined symbol: ?contextHelp@BaseTextEditor@TextEditor@@UEBAXAEBV?$function@$$A6AXAEBVHelpItem@Core@@@Z@std@@@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?setContextHelp@BaseTextEditor@TextEditor@@UEAAXAEBVHelpItem@Core@@@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?document@BaseTextEditor@TextEditor@@UEBAPEAVIDocument@Core@@XZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?duplicate@BaseTextEditor@TextEditor@@UEAAPEAVIEditor@Core@@XZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?saveState@BaseTextEditor@TextEditor@@UEBA?AVQByteArray@@XZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?restoreState@BaseTextEditor@TextEditor@@UEAAXAEBVQByteArray@@@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?currentLine@BaseTextEditor@TextEditor@@UEBAHXZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?currentColumn@BaseTextEditor@TextEditor@@UEBAHXZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?gotoLine@BaseTextEditor@TextEditor@@UEAAXHH_N@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?toolBar@BaseTextEditor@TextEditor@@UEAAPEAVQWidget@@XZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?position@BaseTextEditor@TextEditor@@UEBAHW4TextPositionOperation@2@H@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?convertPosition@BaseTextEditor@TextEditor@@UEBAXHPEAH0@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?selectedText@BaseTextEditor@TextEditor@@UEBA?AVQString@@XZ
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?remove@BaseTextEditor@TextEditor@@UEAAXH@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?insert@BaseTextEditor@TextEditor@@UEAAXAEBVQString@@@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?replace@BaseTextEditor@TextEditor@@UEAAXHAEBVQString@@@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?setCursorPosition@BaseTextEditor@TextEditor@@UEAAXH@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?select@BaseTextEditor@TextEditor@@UEAAXH@Z
>>> referenced by debug\cppeditor.obj:(??_7CppEditor@Internal@0@6B@)
>>> referenced by debug\qmljseditor.obj:(??_7QmlJSEditor@0@6B@)
>>> referenced by debug\vcsbaseeditor.obj:(??_7VcsBaseEditor@VcsBase@@6B@)

lld-link: error: undefined symbol: ?tabSettingsChanged@TextDocument@TextEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:114
>>>               debug\cppeditordocument.obj:(??0CppEditorDocument@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:598
>>>               debug\qmljseditordocument.obj:(??0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ??1TextDocument@TextEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:131
>>>               debug\cppeditordocument.obj:(?dtor$30@?0???0CppEditorDocument@Internal@CppEditor@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.h:44
>>>               debug\cppeditordocument.obj:(??1CppEditorDocument@Internal@CppEditor@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:602
>>>               debug\qmljseditordocument.obj:(?dtor$16@?0???0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:604
>>>               debug\qmljseditordocument.obj:(??1QmlJSEditorDocument@QmlJSEditor@@UEAA@XZ)

lld-link: error: undefined symbol: ?instance@CppEditorPlugin@Internal@CppEditor@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:146
>>>               debug\cppeditordocument.obj:(?quickFixAssistProvider@CppEditorDocument@Internal@CppEditor@@UEBAPEAVIAssistProvider@TextEditor@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:153
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:780
>>>               debug\cppeditorwidget.obj:(?addRefactoringActions@Internal@CppEditor@@YAXPEAVQMenu@@PEAVAssistInterface@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:391
>>>               debug\cppincludehierarchy.obj:(??0CppIncludeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:126
>>>               debug\cpptypehierarchy.obj:(??0CppTypeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?quickFixProvider@CppEditorPlugin@Internal@CppEditor@@QEBAPEAVCppQuickFixAssistProvider@23@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:146
>>>               debug\cppeditordocument.obj:(?quickFixAssistProvider@CppEditorDocument@Internal@CppEditor@@UEBAPEAVIAssistProvider@TextEditor@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:780
>>>               debug\cppeditorwidget.obj:(?addRefactoringActions@Internal@CppEditor@@YAXPEAVQMenu@@PEAVAssistInterface@TextEditor@@@Z)

lld-link: error: undefined symbol: ?applyFontSettings@TextDocument@TextEditor@@MEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:177
>>>               debug\cppeditordocument.obj:(?applyFontSettings@CppEditorDocument@Internal@CppEditor@@MEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:655
>>>               debug\qmljseditordocument.obj:(?applyFontSettings@QmlJSEditorDocument@QmlJSEditor@@MEAAXXZ)

lld-link: error: undefined symbol: ?tabSettings@TextDocument@TextEditor@@UEBA?AVTabSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:427
>>>               debug\cppeditordocument.obj:(?tabSettings@CppEditorDocument@Internal@CppEditor@@UEBA?AVTabSettings@TextEditor@@XZ)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?storageSettings@TextDocument@TextEditor@@QEBAAEBVStorageSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:466
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)

lld-link: error: undefined symbol: ?setStorageSettings@TextDocument@TextEditor@@QEAAXAEBVStorageSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:471
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:468
>>>               debug\cppeditordocument.obj:(??R<lambda_0>@?0??save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV5@_N@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?save@TextDocument@TextEditor@@UEAA_NPEAVQString@@AEBV3@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditordocument.cpp:474
>>>               debug\cppeditordocument.obj:(?save@CppEditorDocument@Internal@CppEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?open@TextDocument@TextEditor@@UEAA?AW4OpenResult@IDocument@Core@@PEAVQString@@AEBV6@1@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?contents@TextDocument@TextEditor@@UEBA?AVQByteArray@@XZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?setContents@TextDocument@TextEditor@@UEAA_NAEBVQByteArray@@@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?setFilePath@TextDocument@TextEditor@@UEAAXAEBVFilePath@Utils@@@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?isFileReadOnly@TextDocument@TextEditor@@UEBA_NXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?fallbackSaveAsPath@TextDocument@TextEditor@@UEBA?AVQString@@XZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?fallbackSaveAsFileName@TextDocument@TextEditor@@UEBA?AVQString@@XZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?shouldAutoSave@TextDocument@TextEditor@@UEBA_NXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?isModified@TextDocument@TextEditor@@UEBA_NXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?isSaveAsAllowed@TextDocument@TextEditor@@UEBA_NXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?reload@TextDocument@TextEditor@@UEAA_NPEAVQString@@W4ReloadFlag@IDocument@Core@@W4ChangeType@56@@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?checkPermissions@TextDocument@TextEditor@@UEAAXXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?plainText@TextDocument@TextEditor@@UEBA?AVQString@@XZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?textAt@TextDocument@TextEditor@@UEBA?AVQString@@HH@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?characterAt@TextDocument@TextEditor@@UEBA?AVQChar@@H@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?reload@TextDocument@TextEditor@@UEAA_NPEAVQString@@@Z
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?triggerPendingUpdates@TextDocument@TextEditor@@UEAAXXZ
>>> referenced by debug\cppeditordocument.obj:(??_7CppEditorDocument@Internal@CppEditor@@6B@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:664
>>>               debug\qmljseditordocument.obj:(?triggerPendingUpdates@QmlJSEditorDocument@QmlJSEditor@@MEAAXXZ)

lld-link: error: undefined symbol: ?setLanguageSettingsId@TextEditorWidget@TextEditor@@QEAAXVId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:149
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:110
>>>               debug\qmljseditor.obj:(??0QmlJSEditorWidget@QmlJSEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?outlineSortingChanged@CppEditorPlugin@Internal@CppEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:153
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)

lld-link: error: undefined symbol: ?insertExtraToolBarWidget@TextEditorWidget@TextEditor@@QEAAPEAVQAction@@W4Side@12@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:216
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:225
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:241
>>>               debug\cppeditorwidget.obj:(?finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:247
>>>               debug\cppeditorwidget.obj:(??R<lambda_0>@?0??finalizeInitialization@CppEditorWidget@Internal@CppEditor@@EEAAXXZ@QEBA?A?<auto>@@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:555
>>>               debug\qmljseditor.obj:(?createToolBar@QmlJSEditorWidget@QmlJSEditor@@IEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:584
>>>               debug\vcsbaseeditor.obj:(?entriesComboBox@VcsBaseEditorWidgetPrivate@Internal@VcsBase@@QEAAPEAVQComboBox@@XZ)

lld-link: error: undefined symbol: ?staticMetaObject@CppEditorPlugin@Internal@CppEditor@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\cppeditorwidget.obj:(??$connect@P8CppEditorPlugin@Internal@CppEditor@@EAAX_N@ZP8CppEditorOutline@CppTools@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVCppEditorPlugin@Internal@CppEditor@@P8345@EAAX_N@ZPEBVCppEditorOutline@CppTools@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\cppincludehierarchy.obj:(??$connect@P8CppEditorPlugin@Internal@CppEditor@@EAAXXZP8CppIncludeHierarchyWidget@23@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVCppEditorPlugin@Internal@CppEditor@@P8345@EAAXXZPEBVCppIncludeHierarchyWidget@45@P8645@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\cpptypehierarchy.obj:(??$connect@P8CppEditorPlugin@Internal@CppEditor@@EAAXXZP8CppTypeHierarchyWidget@23@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVCppEditorPlugin@Internal@CppEditor@@P8345@EAAXXZPEBVCppTypeHierarchyWidget@45@P8645@EAAXXZW4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?CodeWarningsSelection@TextEditorWidget@TextEditor@@2VId@Utils@@A
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:312
>>>               debug\cppeditorwidget.obj:(?onCodeWarningsUpdated@CppEditorWidget@Internal@CppEditor@@AEAAXIV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QList@URefactorMarker@TextEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:263
>>>               debug\cppeditorwidget.obj:(?finalizeInitializationAfterDuplication@CppEditorWidget@Internal@CppEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppelementevaluator.cpp:418
>>>               debug\cppelementevaluator.obj:(?checkDiagnosticMessage@CppElementEvaluator@CppTools@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\extracompiler.cpp:273
>>>               debug\extracompiler.obj:(?updateIssues@ExtraCompilerPrivate@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:228
>>>               debug\qmljseditor.obj:(?updateCodeWarnings@QmlJSEditorWidget@QmlJSEditor@@AEAAXV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:235
>>>               debug\qmljseditor.obj:(?updateCodeWarnings@QmlJSEditorWidget@QmlJSEditor@@AEAAXV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:237
>>>               debug\qmljseditor.obj:(?updateCodeWarnings@QmlJSEditorWidget@QmlJSEditor@@AEAAXV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:274
>>>               debug\qmljshoverhandler.obj:(?matchDiagnosticMessage@QmlJSHoverHandler@QmlJSEditor@@AEAA_NPEAVQmlJSEditorWidget@2@H@Z)

lld-link: error: undefined symbol: ?setExtraSelections@TextEditorWidget@TextEditor@@QEAAXVId@Utils@@AEBV?$QList@UExtraSelection@QTextEdit@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:312
>>>               debug\cppeditorwidget.obj:(?onCodeWarningsUpdated@CppEditorWidget@Internal@CppEditor@@AEAAXIV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QList@URefactorMarker@TextEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:264
>>>               debug\cppeditorwidget.obj:(?finalizeInitializationAfterDuplication@CppEditorWidget@Internal@CppEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:616
>>>               debug\cppeditorwidget.obj:(??R<lambda_3>@?0??renameSymbolUnderCursor@CppEditorWidget@Internal@CppEditor@@UEAAXXZ@QEBA?A?<auto>@@AEBVQString@@AEBVSourceLocationsContainer@ClangBackEnd@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpplocalrenaming.cpp:289
>>>               debug\cpplocalrenaming.obj:(?updateEditorWidgetWithSelections@CppLocalRenaming@Internal@CppEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:192
>>>               debug\cppuseselectionsupdater.obj:(?updateUseSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEAA?AV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QVector@URange@CursorInfo@CppTools@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:202
>>>               debug\cppuseselectionsupdater.obj:(?updateUnusedSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEAAXAEBV?$QVector@URange@CursorInfo@CppTools@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\extracompiler.cpp:273
>>>               debug\extracompiler.obj:(?updateIssues@ExtraCompilerPrivate@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:382
>>>               debug\qmljseditor.obj:(?updateUses@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:228
>>>               debug\qmljseditor.obj:(?updateCodeWarnings@QmlJSEditorWidget@QmlJSEditor@@AEAAXV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:235
>>>               debug\qmljseditor.obj:(?updateCodeWarnings@QmlJSEditorWidget@QmlJSEditor@@AEAAXV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z)
>>> referenced 5 more times

lld-link: error: undefined symbol: ?refactorMarkers@TextEditorWidget@TextEditor@@QEBA?AV?$QList@URefactorMarker@TextEditor@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:314
>>>               debug\cppeditorwidget.obj:(?onCodeWarningsUpdated@CppEditorWidget@Internal@CppEditor@@AEAAXIV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QList@URefactorMarker@TextEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppfunctiondecldeflink.cpp:294
>>>               debug\cppfunctiondecldeflink.obj:(?hideMarker@FunctionDeclDefLink@Internal@CppEditor@@QEAAXPEAVCppEditorWidget@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppfunctiondecldeflink.cpp:303
>>>               debug\cppfunctiondecldeflink.obj:(?showMarker@FunctionDeclDefLink@Internal@CppEditor@@QEAAXPEAVCppEditorWidget@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:325
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:349
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:829
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?setRefactorMarkers@TextEditorWidget@TextEditor@@QEAAXAEBV?$QList@URefactorMarker@TextEditor@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:314
>>>               debug\cppeditorwidget.obj:(?onCodeWarningsUpdated@CppEditorWidget@Internal@CppEditor@@AEAAXIV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QList@URefactorMarker@TextEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppfunctiondecldeflink.cpp:294
>>>               debug\cppfunctiondecldeflink.obj:(?hideMarker@FunctionDeclDefLink@Internal@CppEditor@@QEAAXPEAVCppEditorWidget@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppfunctiondecldeflink.cpp:339
>>>               debug\cppfunctiondecldeflink.obj:(?showMarker@FunctionDeclDefLink@Internal@CppEditor@@QEAAXPEAVCppEditorWidget@23@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:347
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:349
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:829
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?setIfdefedOutBlocks@TextEditorWidget@TextEditor@@QEAAXAEBV?$QList@VBlockRange@TextEditor@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:324
>>>               debug\cppeditorwidget.obj:(?onIfdefedOutBlocksUpdated@CppEditorWidget@Internal@CppEditor@@AEAAXIV?$QList@VBlockRange@TextEditor@@@@@Z)

lld-link: error: undefined symbol: ?extraSelections@TextEditorWidget@TextEditor@@QEBA?AV?$QList@UExtraSelection@QTextEdit@@@@VId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:264
>>>               debug\cppeditorwidget.obj:(?finalizeInitializationAfterDuplication@CppEditorWidget@Internal@CppEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:184
>>>               debug\cppuseselectionsupdater.obj:(?currentUseSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEBA?AV?$QList@UExtraSelection@QTextEdit@@@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppelementevaluator.cpp:418
>>>               debug\cppelementevaluator.obj:(?checkDiagnosticMessage@CppElementEvaluator@CppTools@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:274
>>>               debug\qmljshoverhandler.obj:(?matchDiagnosticMessage@QmlJSHoverHandler@QmlJSEditor@@AEAA_NPEAVQmlJSEditorWidget@2@H@Z)

lld-link: error: undefined symbol: ?behaviorSettings@TextEditorWidget@TextEditor@@QEBAAEBVBehaviorSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:470
>>>               debug\cppeditorwidget.obj:(?selectBlockUp@CppEditorWidget@Internal@CppEditor@@UEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:484
>>>               debug\cppeditorwidget.obj:(?selectBlockDown@CppEditorWidget@Internal@CppEditor@@UEAA_NXZ)

lld-link: error: undefined symbol: ?alwaysOpenLinksInNextSplit@TextEditorWidget@TextEditor@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:712
>>>               debug\cppeditorwidget.obj:(?switchDeclarationDefinition@CppEditorWidget@Internal@CppEditor@@QEAAX_N@Z)

lld-link: error: undefined symbol: ?openLink@TextEditorWidget@TextEditor@@IEAA_NAEBULink@Utils@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:712
>>>               debug\cppeditorwidget.obj:(?switchDeclarationDefinition@CppEditorWidget@Internal@CppEditor@@QEAAX_N@Z)

lld-link: error: undefined symbol: ?appendStandardContextMenuActions@TextEditorWidget@TextEditor@@QEAAXPEAVQMenu@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:872
>>>               debug\cppeditorwidget.obj:(?contextMenuEvent@CppEditorWidget@Internal@CppEditor@@MEAAXPEAVQContextMenuEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:883
>>>               debug\qmljseditor.obj:(?contextMenuEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQContextMenuEvent@@@Z)

lld-link: error: undefined symbol: ??0CppPreProcessorDialog@Internal@CppEditor@@QEAA@AEBVQString@@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1082
>>>               debug\cppeditorwidget.obj:(?showPreProcessorWidget@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?exec@CppPreProcessorDialog@Internal@CppEditor@@UEAAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1083
>>>               debug\cppeditorwidget.obj:(?showPreProcessorWidget@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?extraPreprocessorDirectives@CppPreProcessorDialog@Internal@CppEditor@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1084
>>>               debug\cppeditorwidget.obj:(?showPreProcessorWidget@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ??1CppPreProcessorDialog@Internal@CppEditor@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1089
>>>               debug\cppeditorwidget.obj:(?showPreProcessorWidget@CppEditorWidget@Internal@CppEditor@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1089
>>>               debug\cppeditorwidget.obj:(?dtor$11@?0??showPreProcessorWidget@CppEditorWidget@Internal@CppEditor@@UEAAXXZ@4HA)

lld-link: error: undefined symbol: ?invokeAssist@TextEditorWidget@TextEditor@@QEAAXW4AssistKind@2@PEAVIAssistProvider@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:1093
>>>               debug\cppeditorwidget.obj:(?invokeTextEditorWidgetAssist@CppEditorWidget@Internal@CppEditor@@UEAAXW4AssistKind@TextEditor@@PEAVIAssistProvider@5@@Z)

lld-link: error: undefined symbol: ?addResult@SearchResult@Core@@QEAAXAEBVQString@@0VTextRange@Search@2@AEBVQVariant@@W4Style@SearchResultColor@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:400
>>>               debug\cppeditorwidget.obj:(?addSearchResults@Internal@CppEditor@@YAXV?$vector@VUsage@CppTools@@V?$allocator@VUsage@CppTools@@@std@@@std@@AEAVSearchResult@Core@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?CodeSemanticsSelection@TextEditorWidget@TextEditor@@2VId@Utils@@A
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppeditorwidget.cpp:616
>>>               debug\cppeditorwidget.obj:(??R<lambda_3>@?0??renameSymbolUnderCursor@CppEditorWidget@Internal@CppEditor@@UEAAXXZ@QEBA?A?<auto>@@AEBVQString@@AEBVSourceLocationsContainer@ClangBackEnd@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpplocalrenaming.cpp:289
>>>               debug\cpplocalrenaming.obj:(?updateEditorWidgetWithSelections@CppLocalRenaming@Internal@CppEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:184
>>>               debug\cppuseselectionsupdater.obj:(?currentUseSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEBA?AV?$QList@UExtraSelection@QTextEdit@@@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:192
>>>               debug\cppuseselectionsupdater.obj:(?updateUseSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEAA?AV?$QList@UExtraSelection@QTextEdit@@@@AEBV?$QVector@URange@CursorInfo@CppTools@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:382
>>>               debug\qmljseditor.obj:(?updateUses@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)

lld-link: error: undefined symbol: ??0TextEditorLinkLabel@TextEditor@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:353
>>>               debug\cppincludehierarchy.obj:(??0CppIncludeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:89
>>>               debug\cpptypehierarchy.obj:(??0CppTypeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?createSearchableWrapper@ItemViewFind@Core@@SAPEAVQFrame@@PEAV12@W4ColorOption@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:387
>>>               debug\cppincludehierarchy.obj:(??0CppIncludeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?includeHierarchyRequested@CppEditorPlugin@Internal@CppEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:391
>>>               debug\cppincludehierarchy.obj:(??0CppIncludeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?setLink@TextEditorLinkLabel@TextEditor@@QEAAXULink@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:412
>>>               debug\cppincludehierarchy.obj:(?perform@CppIncludeHierarchyWidget@Internal@CppEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:195
>>>               debug\cpptypehierarchy.obj:(?displayHierarchy@CppTypeHierarchyWidget@Internal@CppEditor@@AEAAXXZ)

lld-link: error: undefined symbol: ??0ItemViewFind@Core@@QEAA@PEAVQAbstractItemView@@HW4FetchOption@01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:295
>>>               debug\cppincludehierarchy.obj:(??0IncludeFinder@Internal@CppEditor@@QEAA@PEAVQAbstractItemView@@PEAVCppIncludeHierarchyModel@12@@Z)

lld-link: error: undefined symbol: ?findIncremental@ItemViewFind@Core@@UEAA?AW4Result@IFindSupport@2@AEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:300
>>>               debug\cppincludehierarchy.obj:(?findIncremental@IncludeFinder@Internal@CppEditor@@EEAA?AW4Result@IFindSupport@Core@@AEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ?findStep@ItemViewFind@Core@@UEAA?AW4Result@IFindSupport@2@AEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:307
>>>               debug\cppincludehierarchy.obj:(?findStep@IncludeFinder@Internal@CppEditor@@EEAA?AW4Result@IFindSupport@Core@@AEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z)

lld-link: error: undefined symbol: ??1ItemViewFind@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppincludehierarchy.cpp:291
>>>               debug\cppincludehierarchy.obj:(??1IncludeFinder@Internal@CppEditor@@UEAA@XZ)

lld-link: error: undefined symbol: ?metaObject@ItemViewFind@Core@@UEBAPEBUQMetaObject@@XZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?qt_metacast@ItemViewFind@Core@@UEAAPEAXPEBD@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?qt_metacall@ItemViewFind@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?supportsReplace@ItemViewFind@Core@@UEBA_NXZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?supportedFindFlags@ItemViewFind@Core@@UEBA?AV?$QFlags@W4FindFlag@Core@@@@XZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?resetIncrementalSearch@ItemViewFind@Core@@UEAAXXZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?clearHighlights@ItemViewFind@Core@@UEAAXXZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?currentFindString@ItemViewFind@Core@@UEBA?AVQString@@XZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?completedFindString@ItemViewFind@Core@@UEBA?AVQString@@XZ
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?highlightAll@ItemViewFind@Core@@UEAAXAEBVQString@@V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?replace@IFindSupport@Core@@UEAAXAEBVQString@@0V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?replaceStep@IFindSupport@Core@@UEAA_NAEBVQString@@0V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?replaceAll@IFindSupport@Core@@UEAAHAEBVQString@@0V?$QFlags@W4FindFlag@Core@@@@@Z
>>> referenced by debug\cppincludehierarchy.obj:(??_7IncludeFinder@Internal@CppEditor@@6B@)

lld-link: error: undefined symbol: ?correspondingHeaderOrSource@CppTools@@YA?AVQString@@AEBV2@PEA_NW4CacheUsage@1@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppinsertvirtualmethods.cpp:672
>>>               debug\cppinsertvirtualmethods.obj:(??0InsertVirtualMethodsOp@Internal@CppEditor@@QEAA@AEBVCppQuickFixInterface@12@PEAVInsertVirtualMethodsDialog@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:3122
>>>               debug\cppquickfixes.obj:(?match@InsertDefFromDecl@Internal@CppEditor@@UEAAXAEBVCppQuickFixInterface@23@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:6431
>>>               debug\cppquickfixes.obj:(?match@MoveFuncDefOutside@Internal@CppEditor@@UEAAXAEBVCppQuickFixInterface@23@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:6518
>>>               debug\cppquickfixes.obj:(?match@MoveAllFuncDefOutside@Internal@CppEditor@@UEAAXAEBVCppQuickFixInterface@23@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:6674
>>>               debug\cppquickfixes.obj:(?match@MoveFuncDefToDecl@Internal@CppEditor@@UEAAXAEBVCppQuickFixInterface@23@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:3632
>>>               debug\cppquickfixes.obj:(??0GetterSetterRefactoringHelper@?A0x2EE00FEC@Internal@CppEditor@@QEAA@PEAVCppQuickFixOperation@2@AEBVQString@@PEAVClass@CPlusPlus@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:5521
>>>               debug\cppquickfixes.obj:(?findDeclaration@ExtractLiteralAsParameterOp@?A0x2EE00FEC@Internal@CppEditor@@QEAA?AUFoundDeclaration@1?A0x2EE00FEC@23@AEBVCppRefactoringChanges@CppTools@@PEAVFunctionDefinitionAST@CPlusPlus@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixes.cpp:3442
>>>               debug\cppquickfixes.obj:(?perform@InsertDefsOperation@Internal@CppEditor@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsreuse.cpp:242
>>>               debug\cpptoolsreuse.obj:(?switchHeaderSource@CppTools@@YAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\insertionpointlocator.cpp:542
>>>               debug\insertionpointlocator.obj:(?methodDefinition@InsertionPointLocator@CppTools@@QEBA?BV?$QList@VInsertionLocation@CppTools@@@@PEAVSymbol@CPlusPlus@@_NAEBVQString@@@Z)

lld-link: error: undefined symbol: ?cutForwardNavigationHistory@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppoutline.cpp:163
>>>               debug\cppoutline.obj:(?updateTextCursor@CppOutlineWidget@Internal@CppEditor@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppeditoroutline.cpp:240
>>>               debug\cppeditoroutline.obj:(?gotoSymbolInEditor@CppEditorOutline@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:277
>>>               debug\qmljseditor.obj:(?jumpToOutlineElement@QmlJSEditorWidget@QmlJSEditor@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsoutline.cpp:238
>>>               debug\qmljsoutline.obj:(??R<lambda_3>@?0??updateTextCursor@QmlJSOutlineWidget@Internal@QmlJSEditor@@AEAAXAEBVQModelIndex@@@Z@QEBA?A?<auto>@@0@Z)

lld-link: error: undefined symbol: ?gotoLine@TextEditorWidget@TextEditor@@QEAAXHH_N0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppoutline.cpp:167
>>>               debug\cppoutline.obj:(?updateTextCursor@CppOutlineWidget@Internal@CppEditor@@AEAAXAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppeditoroutline.cpp:242
>>>               debug\cppeditoroutline.obj:(?gotoSymbolInEditor@CppEditorOutline@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:884
>>>               debug\vcsbaseeditor.obj:(?slotJumpToEntry@VcsBaseEditorWidget@VcsBase@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1179
>>>               debug\vcsbaseeditor.obj:(?reportCommandFinished@VcsBaseEditorWidget@VcsBase@@QEAAX_NHAEBVQVariant@@@Z)

lld-link: error: undefined symbol: ??0CppQuickFixSettingsWidget@Internal@CppEditor@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixsettingspage.cpp:47
>>>               debug\cppquickfixsettingspage.obj:(?widget@CppQuickFixSettingsPage@Internal@CppEditor@@UEAAPEAVQWidget@@XZ)

lld-link: error: undefined symbol: ?loadSettings@CppQuickFixSettingsWidget@Internal@CppEditor@@QEAAXPEAVCppQuickFixSettings@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixsettingspage.cpp:48
>>>               debug\cppquickfixsettingspage.obj:(?widget@CppQuickFixSettingsPage@Internal@CppEditor@@UEAAPEAVQWidget@@XZ)

lld-link: error: undefined symbol: ?saveSettings@CppQuickFixSettingsWidget@Internal@CppEditor@@QEAAXPEAVCppQuickFixSettings@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppquickfixsettingspage.cpp:55
>>>               debug\cppquickfixsettingspage.obj:(?apply@CppQuickFixSettingsPage@Internal@CppEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?typeHierarchyRequested@CppEditorPlugin@Internal@CppEditor@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cpptypehierarchy.cpp:126
>>>               debug\cpptypehierarchy.obj:(??0CppTypeHierarchyWidget@Internal@CppEditor@@QEAA@XZ)

lld-link: error: undefined symbol: ?UnusedSymbolSelection@TextEditorWidget@TextEditor@@2VId@Utils@@A
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cppeditor\cppuseselectionsupdater.cpp:202
>>>               debug\cppuseselectionsupdater.obj:(?updateUnusedSelections@CppUseSelectionsUpdater@Internal@CppEditor@@AEAAXAEBV?$QVector@URange@CursorInfo@CppTools@@@@@Z)

lld-link: error: undefined symbol: ?licenseTemplate@CppFileSettings@Internal@CppTools@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\abstracteditorsupport.cpp:60
>>>               debug\abstracteditorsupport.obj:(?licenseTemplate@AbstractEditorSupport@CppTools@@SA?AVQString@@AEBV3@0@Z)

lld-link: error: undefined symbol: ?usePragmaOnce@CppToolsPlugin@Internal@CppTools@@SA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\abstracteditorsupport.cpp:72
>>>               debug\abstracteditorsupport.obj:(?usePragmaOnce@AbstractEditorSupport@CppTools@@SA_NXZ)

lld-link: error: undefined symbol: ?instance@CppToolsPlugin@Internal@CppTools@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\builtineditordocumentprocessor.cpp:175
>>>               debug\builtineditordocumentprocessor.obj:(??0BuiltinEditorDocumentProcessor@CppTools@@QEAA@PEAVTextDocument@TextEditor@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsreuse.cpp:275
>>>               debug\cpptoolsreuse.obj:(?codeModelSettings@CppTools@@YAPEAVCppCodeModelSettings@1@XZ)

lld-link: error: undefined symbol: ?codeModelSettings@CppToolsPlugin@Internal@CppTools@@QEAAPEAVCppCodeModelSettings@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\builtineditordocumentprocessor.cpp:175
>>>               debug\builtineditordocumentprocessor.obj:(??0BuiltinEditorDocumentProcessor@CppTools@@QEAA@PEAVTextDocument@TextEditor@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsreuse.cpp:275
>>>               debug\cpptoolsreuse.obj:(?codeModelSettings@CppTools@@YAPEAVCppCodeModelSettings@1@XZ)

lld-link: error: undefined symbol: ?sync@ClangDiagnosticConfigsWidget@CppTools@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\clangdiagnosticconfigsselectionwidget.cpp:82
>>>               debug\clangdiagnosticconfigsselectionwidget.obj:(?onButtonClicked@ClangDiagnosticConfigsSelectionWidget@CppTools@@AEAAXXZ)

lld-link: error: undefined symbol: ?configs@ClangDiagnosticConfigsWidget@CppTools@@QEBA?AV?$QVector@VClangDiagnosticConfig@CppTools@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\clangdiagnosticconfigsselectionwidget.cpp:104
>>>               debug\clangdiagnosticconfigsselectionwidget.obj:(?onButtonClicked@ClangDiagnosticConfigsSelectionWidget@CppTools@@AEAAXXZ)

lld-link: error: undefined symbol: ?currentConfig@ClangDiagnosticConfigsWidget@CppTools@@QEBA?BVClangDiagnosticConfig@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\clangdiagnosticconfigsselectionwidget.cpp:105
>>>               debug\clangdiagnosticconfigsselectionwidget.obj:(?onButtonClicked@ClangDiagnosticConfigsSelectionWidget@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\clangdiagnosticconfigsselectionwidget.cpp:106
>>>               debug\clangdiagnosticconfigsselectionwidget.obj:(?onButtonClicked@ClangDiagnosticConfigsSelectionWidget@CppTools@@AEAAXXZ)

lld-link: error: undefined symbol: ?prepareSearch@ILocatorFilter@Core@@UEAAXAEBVQString@@@Z
>>> referenced by debug\cppclassesfilter.obj:(??_7CppClassesFilter@CppTools@@6B@)
>>> referenced by debug\cppcurrentdocumentfilter.obj:(??_7CppCurrentDocumentFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cppfunctionsfilter.obj:(??_7CppFunctionsFilter@Internal@CppTools@@6B@)
>>> referenced by debug\cpplocatorfilter.obj:(??_7CppLocatorFilter@Internal@CppTools@@6B@)

lld-link: error: undefined symbol: ??0CppCodeStylePreferencesWidget@Internal@CppTools@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcodestylepreferencesfactory.cpp:102
>>>               debug\cppcodestylepreferencesfactory.obj:(?createEditor@CppCodeStylePreferencesFactory@CppTools@@UEBAPEAVQWidget@@PEAVICodeStylePreferences@TextEditor@@PEAV3@@Z)

lld-link: error: undefined symbol: ?setCodeStyle@CppCodeStylePreferencesWidget@Internal@CppTools@@QEAAXPEAVCppCodeStylePreferences@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcodestylepreferencesfactory.cpp:104
>>>               debug\cppcodestylepreferencesfactory.obj:(?createEditor@CppCodeStylePreferencesFactory@CppTools@@UEBAPEAVQWidget@@PEAVICodeStylePreferences@TextEditor@@PEAV3@@Z)

lld-link: error: undefined symbol: ?createRegExp@ILocatorFilter@Core@@SA?AVQRegularExpression@@AEBVQString@@W4CaseSensitivity@Qt@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:68
>>>               debug\cppcurrentdocumentfilter.obj:(?matchesFor@CppCurrentDocumentFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:74
>>>               debug\cpplocatorfilter.obj:(?matchesFor@CppLocatorFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:77
>>>               debug\cpplocatorfilter.obj:(?matchesFor@CppLocatorFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?highlightInfo@ILocatorFilter@Core@@SA?AUHighlightInfo@LocatorFilterEntry@2@AEBVQRegularExpressionMatch@@W4DataType@342@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:97
>>>               debug\cppcurrentdocumentfilter.obj:(?matchesFor@CppCurrentDocumentFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppcurrentdocumentfilter.cpp:100
>>>               debug\cppcurrentdocumentfilter.obj:(?matchesFor@CppCurrentDocumentFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:111
>>>               debug\cpplocatorfilter.obj:(??R<lambda_0>@?0??matchesFor@CppLocatorFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z@QEBA@AEBV?$QSharedPointer@VIndexItem@CppTools@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:115
>>>               debug\cpplocatorfilter.obj:(??R<lambda_0>@?0??matchesFor@CppLocatorFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z@QEBA@AEBV?$QSharedPointer@VIndexItem@CppTools@@@@@Z)

lld-link: error: undefined symbol: ?setAdditionalReplaceWidget@SearchResult@Core@@QEAAXPEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:324
>>>               debug\cppfindreferences.obj:(?findUsages@CppFindReferences@Internal@CppTools@@AEAAXPEAVSymbol@CPlusPlus@@AEBVLookupContext@5@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:722
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)

lld-link: error: undefined symbol: ?additionalReplaceWidget@SearchResult@Core@@QEBAPEAVQWidget@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:401
>>>               debug\cppfindreferences.obj:(?onReplaceButtonClicked@CppFindReferences@Internal@CppTools@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:580
>>>               debug\cppfindreferences.obj:(?searchFinished@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@@Z)

lld-link: error: undefined symbol: ?fromSettings@CppFileSettings@Internal@CppTools@@QEAAXPEAVQSettings@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:406
>>>               debug\cppfindreferences.obj:(?onReplaceButtonClicked@CppFindReferences@Internal@CppTools@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsjsextension.cpp:75
>>>               debug\cpptoolsjsextension.obj:(?classToFileName@CppToolsJsExtension@Internal@CppTools@@QEBA?AVQString@@AEBV4@0@Z)

lld-link: error: undefined symbol: ?renameFile@ProjectExplorerPlugin@ProjectExplorer@@SAXPEAVNode@2@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:446
>>>               debug\cppfindreferences.obj:(?onReplaceButtonClicked@CppFindReferences@Internal@CppTools@@AEAAXAEBVQString@@AEBV?$QList@VSearchResultItem@Core@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectmodels.cpp:236
>>>               debug\projectmodels.obj:(?setData@FlatModel@Internal@ProjectExplorer@@UEAA_NAEBVQModelIndex@@AEBVQVariant@@H@Z)

lld-link: error: undefined symbol: ?addResult@SearchResult@Core@@QEAAXAEBVQString@@H0HHAEBVQVariant@@W4Style@SearchResultColor@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:744
>>>               debug\cppfindreferences.obj:(?findMacroUses@CppFindReferences@Internal@CppTools@@AEAAXAEBVMacro@CPlusPlus@@AEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppfindreferences.cpp:546
>>>               debug\cppfindreferences.obj:(?displayResults@@YAXPEAVSearchResult@Core@@PEAV?$QFutureWatcher@VUsage@CPlusPlus@@@@HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsfindreferences.cpp:908
>>>               debug\qmljsfindreferences.obj:(?displayResults@FindReferences@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ??1Iterator@BaseFileFilter@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:71
>>>               debug\cppincludesfilter.obj:(?dtor$11@?0???0CppIncludesIterator@Internal@CppTools@@QEAA@VSnapshot@CPlusPlus@@AEBV?$QSet@VQString@@@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:46
>>>               debug\cppincludesfilter.obj:(??1CppIncludesIterator@Internal@CppTools@@UEAA@XZ)

lld-link: error: undefined symbol: ??0BaseFileFilter@Core@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:108
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:41
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:40
>>>               debug\currentprojectfilter.obj:(??0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ?instance@ProjectExplorerPlugin@ProjectExplorer@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:115
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:47
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfind.cpp:48
>>>               debug\allprojectsfind.obj:(??0AllProjectsFind@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\runconfigurationaspects.cpp:68
>>>               debug\runconfigurationaspects.obj:(??0TerminalAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparser.cpp:258
>>>               debug\customparser.obj:(??0SelectionWidget@?A0x762B73E@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:69
>>>               debug\projectwelcomepage.obj:(??0ProjectModel@Internal@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\makestep.cpp:402
>>>               debug\makestep.obj:(?createConfigWidget@MakeStep@ProjectExplorer@@UEAAPEAVQWidget@@XZ)

lld-link: error: undefined symbol: ?fileListChanged@ProjectExplorerPlugin@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:115
>>>               debug\cppincludesfilter.obj:(??0CppIncludesFilter@Internal@CppTools@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:47
>>>               debug\allprojectsfilter.obj:(??0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfind.cpp:48
>>>               debug\allprojectsfind.obj:(??0AllProjectsFind@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ??1BaseFileFilter@Core@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:130
>>>               debug\cppincludesfilter.obj:(?dtor$25@?0???0CppIncludesFilter@Internal@CppTools@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.h:33
>>>               debug\cppincludesfilter.obj:(??1CppIncludesFilter@Internal@CppTools@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:50
>>>               debug\allprojectsfilter.obj:(?dtor$12@?0???0AllProjectsFilter@Internal@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.h:35
>>>               debug\allprojectsfilter.obj:(??1AllProjectsFilter@Internal@ProjectExplorer@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:48
>>>               debug\currentprojectfilter.obj:(?dtor$12@?0???0CurrentProjectFilter@Internal@ProjectExplorer@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.h:39
>>>               debug\currentprojectfilter.obj:(??1CurrentProjectFilter@Internal@ProjectExplorer@@UEAA@XZ)

lld-link: error: undefined symbol: ?staticMetaObject@ProjectExplorerPlugin@ProjectExplorer@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\cppincludesfilter.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8CppIncludesFilter@Internal@CppTools@@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVCppIncludesFilter@Internal@CppTools@@P8567@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\allprojectsfilter.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8AllProjectsFilter@Internal@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVAllProjectsFilter@Internal@4@P8564@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\allprojectsfind.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8AllProjectsFind@Internal@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVAllProjectsFind@Internal@4@P8564@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectexplorer.h:68
>>>               debug\foldernavigationwidget.obj:(?tr@ProjectExplorerPlugin@ProjectExplorer@@SA?AVQString@@PEBD0H@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\runconfigurationaspects.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8TerminalAspect@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVTerminalAspect@4@P854@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\customparser.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8SelectionWidget@?A0x762B73E@Internal@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVSelectionWidget@?A0x762B73E@Internal@4@P85?A0x762B73E@64@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\projectwelcomepage.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZP8ProjectModel@Internal@2@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBVProjectModel@Internal@4@P8564@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\makestep.obj:(??$connect@P8ProjectExplorerPlugin@ProjectExplorer@@EAAXXZV<lambda_4>@?0??createConfigWidget@MakeStep@2@UEAAPEAVQWidget@@XZ@@QObject@@SA?AVConnection@QMetaObject@@PEBVProjectExplorerPlugin@ProjectExplorer@@P834@EAAXXZPEBV0@V<lambda_4>@?0??createConfigWidget@MakeStep@4@UEAAPEAVQWidget@@XZ@W4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?setFileIterator@BaseFileFilter@Core@@IEAAXPEAVIterator@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:159
>>>               debug\cppincludesfilter.obj:(?markOutdated@CppIncludesFilter@Internal@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:147
>>>               debug\cppincludesfilter.obj:(?prepareSearch@CppIncludesFilter@Internal@CppTools@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:52
>>>               debug\allprojectsfilter.obj:(?markFilesAsOutOfDate@AllProjectsFilter@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:61
>>>               debug\allprojectsfilter.obj:(?prepareSearch@AllProjectsFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:50
>>>               debug\currentprojectfilter.obj:(?markFilesAsOutOfDate@CurrentProjectFilter@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:57
>>>               debug\currentprojectfilter.obj:(?prepareSearch@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?prepareSearch@BaseFileFilter@Core@@UEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppincludesfilter.cpp:149
>>>               debug\cppincludesfilter.obj:(?prepareSearch@CppIncludesFilter@Internal@CppTools@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:63
>>>               debug\allprojectsfilter.obj:(?prepareSearch@AllProjectsFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:59
>>>               debug\currentprojectfilter.obj:(?prepareSearch@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?matchesFor@BaseFileFilter@Core@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z
>>> referenced by debug\cppincludesfilter.obj:(??_7CppIncludesFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfilter.obj:(??_7AllProjectsFilter@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfilter.obj:(??_7CurrentProjectFilter@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?accept@BaseFileFilter@Core@@UEBAXULocatorFilterEntry@2@PEAVQString@@PEAH2@Z
>>> referenced by debug\cppincludesfilter.obj:(??_7CppIncludesFilter@Internal@CppTools@@6B@)
>>> referenced by debug\allprojectsfilter.obj:(??_7AllProjectsFilter@Internal@ProjectExplorer@@6B@)
>>> referenced by debug\currentprojectfilter.obj:(??_7CurrentProjectFilter@Internal@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?caseSensitivity@ILocatorFilter@Core@@SA?AW4CaseSensitivity@Qt@@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpplocatorfilter.cpp:71
>>>               debug\cpplocatorfilter.obj:(?matchesFor@CppLocatorFilter@Internal@CppTools@@UEAA?AV?$QList@ULocatorFilterEntry@Core@@@@AEAV?$QFutureInterface@ULocatorFilterEntry@Core@@@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?visibleEditors@EditorManager@Core@@SA?AV?$QList@PEAVIEditor@Core@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cppmodelmanager.cpp:1046
>>>               debug\cppmodelmanager.obj:(?updateCppEditorDocuments@CppModelManager@CppTools@@QEBAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\cpptoolsbridgeqtcreatorimplementation.cpp:91
>>>               debug\cpptoolsbridgeqtcreatorimplementation.obj:(?visibleEditors@CppToolsBridgeQtCreatorImplementation@Internal@CppTools@@UEBA?AV?$QList@PEAVIEditor@Core@@@@XZ)

lld-link: error: undefined symbol: ?incrementalApplyExtraAdditionalFormats@SemanticHighlighter@TextEditor@@YAXPEAVSyntaxHighlighter@2@AEBV?$QFuture@VHighlightingResult@TextEditor@@@@HHAEBV?$QHash@HVQTextCharFormat@@@@AEBV?$function@$$A6A?BV?$QList@U?$pair@VHighlightingResult@TextEditor@@VQTextBlock@@@std@@@@AEBVHighlightingResult@TextEditor@@AEBVQTextBlock@@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\semantichighlighter.cpp:152
>>>               debug\semantichighlighter.obj:(?onHighlighterResultAvailable@SemanticHighlighter@CppTools@@AEAAXHH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemantichighlighter.cpp:532
>>>               debug\qmljssemantichighlighter.obj:(?applyResults@SemanticHighlighter@QmlJSEditor@@AEAAXHH@Z)

lld-link: error: undefined symbol: ?clearExtraAdditionalFormatsUntilEnd@SemanticHighlighter@TextEditor@@YAXPEAVSyntaxHighlighter@2@AEBV?$QFuture@VHighlightingResult@TextEditor@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\cpptools\semantichighlighter.cpp:163
>>>               debug\semantichighlighter.obj:(?onHighlighterFinished@SemanticHighlighter@CppTools@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemantichighlighter.cpp:543
>>>               debug\qmljssemantichighlighter.obj:(?finished@SemanticHighlighter@QmlJSEditor@@AEAAXXZ)

lld-link: error: undefined symbol: ?buildPropertiesSettings@ProjectExplorerPlugin@ProjectExplorer@@SAAEBVBuildPropertiesSettings@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildaspects.cpp:126
>>>               debug\buildaspects.obj:(??0SeparateDebugInfoAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildpropertiessettingspage.cpp:49
>>>               debug\buildpropertiessettingspage.obj:(??0BuildPropertiesSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildpropertiessettingspage.cpp:97
>>>               debug\buildpropertiessettingspage.obj:(?apply@BuildPropertiesSettingsWidget@Internal@ProjectExplorer@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtbuildaspects.cpp:47
>>>               debug\qtbuildaspects.obj:(??0QmlDebuggingAspect@QtSupport@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtbuildaspects.cpp:80
>>>               debug\qtbuildaspects.obj:(??0QtQuickCompilerAspect@QtSupport@@QEAA@XZ)

lld-link: error: undefined symbol: ?openTerminal@FileUtils@Core@@SAXAEBVQString@@AEBVEnvironment@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildaspects.cpp:58
>>>               debug\buildaspects.obj:(??R<lambda_0>@?0???0BuildDirectoryAspect@ProjectExplorer@@QEAA@PEBVBuildConfiguration@2@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\environmentwidget.cpp:313
>>>               debug\environmentwidget.obj:(??R<lambda_2>@?0???0EnvironmentWidget@ProjectExplorer@@QEAA@PEAVQWidget@@W4Type@12@0@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\devicesupport\desktopdevice.cpp:66
>>>               debug\desktopdevice.obj:(??R<lambda_0>@?0???0DesktopDevice@ProjectExplorer@@IEAA@XZ@QEBA?A?<auto>@@AEBVEnvironment@Utils@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?setBuildPropertiesSettings@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVBuildPropertiesSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildpropertiessettingspage.cpp:106
>>>               debug\buildpropertiessettingspage.obj:(?apply@BuildPropertiesSettingsWidget@Internal@ProjectExplorer@@UEAAXXZ)

lld-link: error: undefined symbol: ?defaultBuildDirectoryTemplate@ProjectExplorerPlugin@ProjectExplorer@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildpropertiessettingspage.cpp:71
>>>               debug\buildpropertiessettingspage.obj:(??R<lambda_1>@?0???0BuildPropertiesSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildpropertiessettingspage.cpp:76
>>>               debug\buildpropertiessettingspage.obj:(??R<lambda_2>@?0???0BuildPropertiesSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?customParsers@ProjectExplorerPlugin@ProjectExplorer@@SA?BV?$QList@VCustomParserSettings@ProjectExplorer@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:52
>>>               debug\customparserssettingspage.obj:(??0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customtoolchain.cpp:86
>>>               debug\customtoolchain.obj:(?customParserSettings@CustomToolChain@ProjectExplorer@@AEBA?AVCustomParserSettings@2@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customtoolchain.cpp:291
>>>               debug\customtoolchain.obj:(?fromMap@CustomToolChain@ProjectExplorer@@UEAA_NAEBV?$QMap@VQString@@VQVariant@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customtoolchain.cpp:404
>>>               debug\customtoolchain.obj:(??0CustomToolChainConfigWidget@Internal@ProjectExplorer@@QEAA@PEAVCustomToolChain@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparser.cpp:192
>>>               debug\customparser.obj:(?createFromId@CustomParser@Internal@ProjectExplorer@@SAPEAV123@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparser.cpp:288
>>>               debug\customparser.obj:(?updateUi@SelectionWidget@?A0x762B73E@Internal@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?setCustomParsers@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBV?$QList@VCustomParserSettings@ProjectExplorer@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:120
>>>               debug\customparserssettingspage.obj:(?apply@CustomParsersSettingsWidget@Internal@ProjectExplorer@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customtoolchain.cpp:294
>>>               debug\customtoolchain.obj:(?fromMap@CustomToolChain@ProjectExplorer@@UEAA_NAEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ??0CustomParserConfigDialog@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:74
>>>               debug\customparserssettingspage.obj:(??R<lambda_1>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:94
>>>               debug\customparserssettingspage.obj:(??R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?setSettings@CustomParserConfigDialog@Internal@ProjectExplorer@@QEAAXAEBVCustomParserSettings@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:75
>>>               debug\customparserssettingspage.obj:(??R<lambda_1>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:95
>>>               debug\customparserssettingspage.obj:(??R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?settings@CustomParserConfigDialog@Internal@ProjectExplorer@@QEBA?AVCustomParserSettings@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:77
>>>               debug\customparserssettingspage.obj:(??R<lambda_1>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:97
>>>               debug\customparserssettingspage.obj:(??R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:98
>>>               debug\customparserssettingspage.obj:(??R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ??1CustomParserConfigDialog@Internal@ProjectExplorer@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:82
>>>               debug\customparserssettingspage.obj:(??R<lambda_1>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:82
>>>               debug\customparserssettingspage.obj:(?dtor$17@?0???R<lambda_1>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:99
>>>               debug\customparserssettingspage.obj:(??R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparserssettingspage.cpp:99
>>>               debug\customparserssettingspage.obj:(?dtor$16@?0???R<lambda_3>@?0???0CustomParsersSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ@4HA)

lld-link: error: undefined symbol: ?kitAspects@KitManager@ProjectExplorer@@SA?BV?$QList@PEAVKitAspect@ProjectExplorer@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\filterkitaspectsdialog.cpp:89
>>>               debug\filterkitaspectsdialog.obj:(??0FilterKitAspectsModel@Internal@ProjectExplorer@@QEAA@PEBVKit@2@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:257
>>>               debug\kit.obj:(?validate@Kit@ProjectExplorer@@QEBA?AV?$QVector@VTask@ProjectExplorer@@@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:270
>>>               debug\kit.obj:(?fix@Kit@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:275
>>>               debug\kit.obj:(?setup@Kit@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:283
>>>               debug\kit.obj:(?upgrade@Kit@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:332
>>>               debug\kit.obj:(?weight@Kit@ProjectExplorer@@QEBAHXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:492
>>>               debug\kit.obj:(?addToEnvironment@Kit@ProjectExplorer@@QEBAXAEAVEnvironment@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:498
>>>               debug\kit.obj:(?createOutputParsers@Kit@ProjectExplorer@@QEBA?AV?$QList@PEAVOutputLineParser@Utils@@@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:515
>>>               debug\kit.obj:(?toHtml@Kit@ProjectExplorer@@QEBA?AVQString@@AEBV?$QVector@VTask@ProjectExplorer@@@@AEBV3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:553
>>>               debug\kit.obj:(?makeSticky@Kit@ProjectExplorer@@QEAAXXZ)
>>> referenced 6 more times

lld-link: error: undefined symbol: ?irrelevantAspects@KitManager@ProjectExplorer@@SA?BV?$QSet@VId@Utils@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\filterkitaspectsdialog.cpp:91
>>>               debug\filterkitaspectsdialog.obj:(??0FilterKitAspectsModel@Internal@ProjectExplorer@@QEAA@PEBVKit@2@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:591
>>>               debug\kit.obj:(?irrelevantAspects@Kit@ProjectExplorer@@QEBA?AV?$QSet@VId@Utils@@@@XZ)

lld-link: error: undefined symbol: ?kits@KitManager@ProjectExplorer@@SA?BV?$QList@PEAVKit@ProjectExplorer@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectimporter.cpp:85
>>>               debug\projectimporter.obj:(??1ProjectImporter@ProjectExplorer@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectimporter.cpp:125
>>>               debug\projectimporter.obj:(?import@ProjectImporter@ProjectExplorer@@UEAA?BV?$QList@VBuildInfo@ProjectExplorer@@@@AEBVFilePath@Utils@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectimporter.cpp:384
>>>               debug\projectimporter.obj:(?hasKitWithTemporaryData@ProjectImporter@ProjectExplorer@@IEBA_NVId@Utils@@AEBVQVariant@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:252
>>>               debug\targetsetuppage.obj:(?setupWidgets@TargetSetupPage@ProjectExplorer@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:225
>>>               debug\kit.obj:(?clone@Kit@ProjectExplorer@@QEBAPEAV12@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:310
>>>               debug\kit.obj:(?fileSystemFriendlyName@Kit@ProjectExplorer@@QEBA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:119
>>>               debug\kitchooser.obj:(?populate@KitChooser@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:628
>>>               debug\kitinformation.obj:(?kitsWereLoaded@ToolChainKitAspect@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:645
>>>               debug\kitinformation.obj:(?toolChainRemoved@ToolChainKitAspect@ProjectExplorer@@AEAAXPEAVToolChain@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:638
>>>               debug\kitinformation.obj:(?toolChainUpdated@ToolChainKitAspect@ProjectExplorer@@AEAAXPEAVToolChain@2@@Z)
>>> referenced 11 more times

lld-link: error: undefined symbol: ?registerKit@KitManager@ProjectExplorer@@SAPEAVKit@2@AEBV?$function@$$A6AXPEAVKit@ProjectExplorer@@@Z@std@@VId@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectimporter.cpp:324
>>>               debug\projectimporter.obj:(?createTemporaryKit@ProjectImporter@ProjectExplorer@@IEBAPEAVKit@2@AEBV?$function@$$A6AXPEAVKit@ProjectExplorer@@@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:172
>>>               debug\kitmanagerconfigwidget.obj:(?apply@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\project.cpp:725
>>>               debug\project.obj:(?createTargetFromMap@Project@ProjectExplorer@@IEAAXAEBV?$QMap@VQString@@VQVariant@@@@H@Z)

lld-link: error: undefined symbol: ?instance@KitManager@ProjectExplorer@@SAPEAV12@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:203
>>>               debug\targetsetuppage.obj:(??0TargetSetupPage@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:212
>>>               debug\targetsetuppage.obj:(??0TargetSetupPage@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:222
>>>               debug\targetsetuppage.obj:(?initializePage@TargetSetupPage@ProjectExplorer@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:68
>>>               debug\kitchooser.obj:(??0KitChooser@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:323
>>>               debug\kitinformation.obj:(??0ToolChainKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:835
>>>               debug\kitinformation.obj:(??0DeviceKitAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:964
>>>               debug\kitinformation.obj:(?kitsWereLoaded@DeviceKitAspect@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:966
>>>               debug\kitinformation.obj:(?kitsWereLoaded@DeviceKitAspect@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:114
>>>               debug\kitmanagerconfigwidget.obj:(??0KitManagerConfigWidget@Internal@ProjectExplorer@@QEAA@PEAVKit@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmodel.cpp:113
>>>               debug\kitmodel.obj:(??0KitModel@Internal@ProjectExplorer@@QEAA@PEAVQBoxLayout@@PEAVQObject@@@Z)
>>> referenced 16 more times

lld-link: error: undefined symbol: ?isLoaded@KitManager@ProjectExplorer@@SA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:219
>>>               debug\targetsetuppage.obj:(?initializePage@TargetSetupPage@ProjectExplorer@@UEAAXXZ)

lld-link: error: undefined symbol: ?sortKits@KitManager@ProjectExplorer@@SA?AV?$QList@PEAVKit@ProjectExplorer@@@@AEBV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsetuppage.cpp:252
>>>               debug\targetsetuppage.obj:(?setupWidgets@TargetSetupPage@ProjectExplorer@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitchooser.cpp:119
>>>               debug\kitchooser.obj:(?populate@KitChooser@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmodel.cpp:108
>>>               debug\kitmodel.obj:(??0KitModel@Internal@ProjectExplorer@@QEAA@PEAVQBoxLayout@@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\targetsettingspanel.cpp:793
>>>               debug\targetsettingspanel.obj:(?rebuildContents@TargetGroupItemPrivate@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?notifyAboutUpdate@KitManager@ProjectExplorer@@CAXPEAVKit@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kit.cpp:641
>>>               debug\kit.obj:(?kitUpdated@Kit@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:169
>>>               debug\kitmanagerconfigwidget.obj:(?apply@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?notifyAboutUpdate@KitAspect@ProjectExplorer@@IEAAXPEAVKit@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:639
>>>               debug\kitinformation.obj:(?toolChainUpdated@ToolChainKitAspect@ProjectExplorer@@AEAAXPEAVToolChain@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitinformation.cpp:972
>>>               debug\kitinformation.obj:(?deviceUpdated@DeviceKitAspect@ProjectExplorer@@AEAAXVId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:363
>>>               debug\qtkitinformation.obj:(?qtVersionsChanged@QtKitAspect@QtSupport@@AEAAXAEBV?$QList@H@@00@Z)

lld-link: error: undefined symbol: ?addToMacroExpander@KitAspect@ProjectExplorer@@UEBAXPEAVKit@2@PEAVMacroExpander@Utils@@@Z
>>> referenced by debug\kitinformation.obj:(??_7DeviceTypeKitAspect@ProjectExplorer@@6B@)
>>> referenced by debug\kitinformation.obj:(??_7EnvironmentKitAspect@ProjectExplorer@@6B@)

lld-link: error: undefined symbol: ?addToLayout@KitAspectWidget@ProjectExplorer@@QEAAXAEAVLayoutBuilder@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:231
>>>               debug\kitmanagerconfigwidget.obj:(?addAspectToWorkingCopy@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXPEAVKitAspect@3@@Z)

lld-link: error: undefined symbol: ?kitInformationId@KitAspectWidget@ProjectExplorer@@QEBA?AVId@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:239
>>>               debug\kitmanagerconfigwidget.obj:(?updateVisibility@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\miniprojecttargetselector.cpp:597
>>>               debug\miniprojecttargetselector.obj:(?updateKit@KitAreaWidget@Internal@ProjectExplorer@@AEAAXPEAVKit@3@@Z)

lld-link: error: undefined symbol: ?setVisible@KitAspectWidget@ProjectExplorer@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:242
>>>               debug\kitmanagerconfigwidget.obj:(?updateVisibility@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?setDefaultKit@KitManager@ProjectExplorer@@SAXPEAVKit@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:176
>>>               debug\kitmanagerconfigwidget.obj:(?apply@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?deregisterKit@KitManager@ProjectExplorer@@SAXPEAVKit@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitmanagerconfigwidget.cpp:270
>>>               debug\kitmanagerconfigwidget.obj:(?removeKit@KitManagerConfigWidget@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?setIrrelevantAspects@KitManager@ProjectExplorer@@SAXAEBV?$QSet@VId@Utils@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\kitoptionspage.cpp:160
>>>               debug\kitoptionspage.obj:(??R<lambda_1>@?0???0KitOptionsPageWidget@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?saveModifiedFiles@ProjectExplorerPlugin@ProjectExplorer@@SA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:95
>>>               debug\buildmanager.obj:(?queue@ProjectExplorer@@YAHAEBV?$QList@PEAVProject@ProjectExplorer@@@@AEBV?$QList@VId@Utils@@@@W4ConfigSelection@1@PEBVRunConfiguration@1@@Z)

lld-link: error: undefined symbol: ?allRunControls@ProjectExplorerPlugin@ProjectExplorer@@SA?AV?$QList@PEAVRunControl@ProjectExplorer@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildmanager.cpp:139
>>>               debug\buildmanager.obj:(?queue@ProjectExplorer@@YAHAEBV?$QList@PEAVProject@ProjectExplorer@@@@AEBV?$QList@VId@Utils@@@@W4ConfigSelection@1@PEBVRunConfiguration@1@@Z)

lld-link: error: undefined symbol: ?targetSelector@ProjectExplorerPlugin@ProjectExplorer@@SAPEAVMiniProjectTargetSelector@Internal@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:297
>>>               debug\target.obj:(?addBuildConfiguration@Target@ProjectExplorer@@QEAAXPEAVBuildConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:322
>>>               debug\target.obj:(?removeBuildConfiguration@Target@ProjectExplorer@@QEAA_NPEAVBuildConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:362
>>>               debug\target.obj:(?addDeployConfiguration@Target@ProjectExplorer@@QEAAXPEAVDeployConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:387
>>>               debug\target.obj:(?removeDeployConfiguration@Target@ProjectExplorer@@QEAA_NPEAVDeployConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:433
>>>               debug\target.obj:(?addRunConfiguration@Target@ProjectExplorer@@QEAAXPEAVRunConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:453
>>>               debug\target.obj:(?removeRunConfiguration@Target@ProjectExplorer@@QEAAXPEAVRunConfiguration@2@@Z)

lld-link: error: undefined symbol: ?updateActions@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:343
>>>               debug\target.obj:(?setActiveBuildConfiguration@Target@ProjectExplorer@@AEAAXPEAVBuildConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\target.cpp:469
>>>               debug\target.obj:(?setActiveRunConfiguration@Target@ProjectExplorer@@QEAAXPEAVRunConfiguration@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\project.cpp:309
>>>               debug\project.obj:(?setActiveTarget@Project@ProjectExplorer@@AEAAXPEAVTarget@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildconfiguration.cpp:246
>>>               debug\buildconfiguration.obj:(??R<lambda_9>@?0???0BuildConfiguration@ProjectExplorer@@IEAA@PEAVTarget@2@VId@Utils@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?setFiles@ProjectWizardPage@Internal@ProjectExplorer@@QEAAXAEBVQStringList@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:112
>>>               debug\projectfilewizardextension.obj:(?firstExtensionPageShown@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAAXAEBV?$QList@VGeneratedFile@Core@@@@AEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ?initializeProjectTree@ProjectWizardPage@Internal@ProjectExplorer@@QEAAXPEAVNode@3@AEBVQStringList@@W4WizardKind@IWizardFactory@Core@@W4ProjectAction@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:135
>>>               debug\projectfilewizardextension.obj:(?firstExtensionPageShown@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAAXAEBV?$QList@VGeneratedFile@Core@@@@AEBV?$QMap@VQString@@VQVariant@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:141
>>>               debug\projectfilewizardextension.obj:(??R<lambda_1>@?0??firstExtensionPageShown@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAAXAEBV?$QList@VGeneratedFile@Core@@@@AEBV?$QMap@VQString@@VQVariant@@@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?initializeVersionControls@ProjectWizardPage@Internal@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:147
>>>               debug\projectfilewizardextension.obj:(?firstExtensionPageShown@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAAXAEBV?$QList@VGeneratedFile@Core@@@@AEBV?$QMap@VQString@@VQVariant@@@@@Z)

lld-link: error: undefined symbol: ??0ProjectWizardPage@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:170
>>>               debug\projectfilewizardextension.obj:(?extensionPages@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAA?AV?$QList@PEAVQWizardPage@@@@PEBVIWizardFactory@Core@@@Z)

lld-link: error: undefined symbol: ?runVersionControl@ProjectWizardPage@Internal@ProjectExplorer@@QEAA_NAEBV?$QList@VGeneratedFile@Core@@@@PEAVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:180
>>>               debug\projectfilewizardextension.obj:(?processFiles@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAA_NAEBV?$QList@VGeneratedFile@Core@@@@PEA_NPEAVQString@@@Z)

lld-link: error: undefined symbol: ?currentNode@ProjectWizardPage@Internal@ProjectExplorer@@QEBAPEAVFolderNode@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:204
>>>               debug\projectfilewizardextension.obj:(?processProject@ProjectFileWizardExtension@Internal@ProjectExplorer@@AEAA_NAEBV?$QList@VGeneratedFile@Core@@@@PEA_NPEAVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:244
>>>               debug\projectfilewizardextension.obj:(?applyCodeStyle@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEBAXPEAVGeneratedFile@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectfilewizardextension.cpp:141
>>>               debug\projectfilewizardextension.obj:(??R<lambda_1>@?0??firstExtensionPageShown@ProjectFileWizardExtension@Internal@ProjectExplorer@@UEAAXAEBV?$QList@VGeneratedFile@Core@@@@AEBV?$QMap@VQString@@VQVariant@@@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?updateWindowTitles@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:137
>>>               debug\session.obj:(??0SessionManager@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:139
>>>               debug\session.obj:(??0SessionManager@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:141
>>>               debug\session.obj:(??0SessionManager@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:990
>>>               debug\session.obj:(?loadSession@SessionManager@ProjectExplorer@@SA_NAEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:317
>>>               debug\vcsbaseplugin.obj:(?slotStateChanged@StateListener@Internal@VcsBase@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:281
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setWindowTitleAdditionHandler@EditorManager@Core@@SAXV?$function@$$A6A?AVQString@@AEBV1@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:148
>>>               debug\session.obj:(??0SessionManager@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:154
>>>               debug\session.obj:(??1SessionManager@ProjectExplorer@@UEAA@XZ)

lld-link: error: undefined symbol: ?setSessionTitleHandler@EditorManager@Core@@SAXV?$function@$$A6A?AVQString@@AEBV1@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:150
>>>               debug\session.obj:(??0SessionManager@ProjectExplorer@@QEAA@PEAVQObject@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:155
>>>               debug\session.obj:(??1SessionManager@ProjectExplorer@@UEAA@XZ)

lld-link: error: undefined symbol: ?saveState@EditorManager@Core@@SA?AVQByteArray@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:477
>>>               debug\session.obj:(?save@SessionManager@ProjectExplorer@@SA_NXZ)

lld-link: error: undefined symbol: ?closeAllEditors@EditorManager@Core@@SA_N_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:965
>>>               debug\session.obj:(?loadSession@SessionManager@ProjectExplorer@@SA_NAEBVQString@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:271
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:273
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?restoreState@EditorManager@Core@@SA_NAEBVQByteArray@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:868
>>>               debug\session.obj:(?restoreEditors@SessionManagerPrivate@ProjectExplorer@@QEAAXAEBVPersistentSettingsReader@Utils@@@Z)

lld-link: error: undefined symbol: ?openProjects@ProjectExplorerPlugin@ProjectExplorer@@SA?AVOpenProjectResult@12@AEBVQStringList@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:882
>>>               debug\session.obj:(?restoreProjects@SessionManagerPrivate@ProjectExplorer@@QEAAXAEBVQStringList@@@Z)

lld-link: error: undefined symbol: ?showOpenProjectError@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVOpenProjectResult@12@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\session.cpp:884
>>>               debug\session.obj:(?restoreProjects@SessionManagerPrivate@ProjectExplorer@@QEAAXAEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:215
>>>               debug\gettingstartedwelcomepage.obj:(?openProject@ExamplesWelcomePage@Internal@QtSupport@@SAXPEBVExampleItem@23@@Z)

lld-link: error: undefined symbol: ?fileIterator@BaseFileFilter@Core@@IEAA?AV?$QSharedPointer@VIterator@BaseFileFilter@Core@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:56
>>>               debug\allprojectsfilter.obj:(?prepareSearch@AllProjectsFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:54
>>>               debug\currentprojectfilter.obj:(?prepareSearch@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ??0ListIterator@BaseFileFilter@Core@@QEAA@AEBV?$QList@VFilePath@Utils@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\allprojectsfilter.cpp:61
>>>               debug\allprojectsfilter.obj:(?prepareSearch@AllProjectsFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfilter.cpp:57
>>>               debug\currentprojectfilter.obj:(?prepareSearch@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?addDocument@DocumentManager@Core@@SAXPEAVIDocument@2@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\project.cpp:146
>>>               debug\project.obj:(??0ProjectDocument@ProjectExplorer@@QEAA@AEBVQString@@AEBVFilePath@Utils@@PEAVProject@1@@Z)

lld-link: error: undefined symbol: ?buildDirectoryTemplate@ProjectExplorerPlugin@ProjectExplorer@@SA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\project.cpp:389
>>>               debug\project.obj:(?copySteps@Project@ProjectExplorer@@SA_NPEAVTarget@2@0@Z)

lld-link: error: undefined symbol: ?updateRunActions@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\buildconfiguration.cpp:247
>>>               debug\buildconfiguration.obj:(??R<lambda_9>@?0???0BuildConfiguration@ProjectExplorer@@IEAA@PEAVTarget@2@VId@Utils@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\runconfiguration.cpp:266
>>>               debug\runconfiguration.obj:(?update@RunConfiguration@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:726
>>>               debug\appoutputpane.obj:(?slotRunControlFinished2@AppOutputPane@Internal@ProjectExplorer@@AEAAXPEAVRunControl@3@@Z)

lld-link: error: undefined symbol: ?languageSettingsId@TextEditorWidget@TextEditor@@QEBA?AVId@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:243
>>>               debug\editorconfiguration.obj:(?configureEditor@EditorConfiguration@ProjectExplorer@@QEBAXPEAVBaseTextEditor@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:256
>>>               debug\editorconfiguration.obj:(?deconfigureEditor@EditorConfiguration@ProjectExplorer@@QEBAXPEAVBaseTextEditor@TextEditor@@@Z)

lld-link: error: undefined symbol: ?setTypingSettings@TextEditorWidget@TextEditor@@QEAAXAEBVTypingSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:308
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:316
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:284
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VTextEditorSettings@TextEditor@@VEditorConfiguration@ProjectExplorer@@@ProjectExplorer@@YAXPEBVTextEditorSettings@TextEditor@@PEBVEditorConfiguration@0@PEAVTextEditorWidget@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:284
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VEditorConfiguration@ProjectExplorer@@VTextEditorSettings@TextEditor@@@ProjectExplorer@@YAXPEBVEditorConfiguration@0@PEBVTextEditorSettings@TextEditor@@PEAVTextEditorWidget@3@@Z)

lld-link: error: undefined symbol: ?setStorageSettings@TextEditorWidget@TextEditor@@QEAAXAEBVStorageSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:309
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:317
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:286
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VTextEditorSettings@TextEditor@@VEditorConfiguration@ProjectExplorer@@@ProjectExplorer@@YAXPEBVTextEditorSettings@TextEditor@@PEBVEditorConfiguration@0@PEAVTextEditorWidget@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:286
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VEditorConfiguration@ProjectExplorer@@VTextEditorSettings@TextEditor@@@ProjectExplorer@@YAXPEBVEditorConfiguration@0@PEBVTextEditorSettings@TextEditor@@PEAVTextEditorWidget@3@@Z)

lld-link: error: undefined symbol: ?setBehaviorSettings@TextEditorWidget@TextEditor@@QEAAXAEBVBehaviorSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:310
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:318
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:288
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VTextEditorSettings@TextEditor@@VEditorConfiguration@ProjectExplorer@@@ProjectExplorer@@YAXPEBVTextEditorSettings@TextEditor@@PEBVEditorConfiguration@0@PEAVTextEditorWidget@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:288
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VEditorConfiguration@ProjectExplorer@@VTextEditorSettings@TextEditor@@@ProjectExplorer@@YAXPEBVEditorConfiguration@0@PEBVTextEditorSettings@TextEditor@@PEAVTextEditorWidget@3@@Z)

lld-link: error: undefined symbol: ?setExtraEncodingSettings@TextEditorWidget@TextEditor@@QEAAXAEBVExtraEncodingSettings@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:311
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:319
>>>               debug\editorconfiguration.obj:(?switchSettings@EditorConfiguration@ProjectExplorer@@AEBAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:290
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VTextEditorSettings@TextEditor@@VEditorConfiguration@ProjectExplorer@@@ProjectExplorer@@YAXPEBVTextEditorSettings@TextEditor@@PEBVEditorConfiguration@0@PEAVTextEditorWidget@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\editorconfiguration.cpp:290
>>>               debug\editorconfiguration.obj:(??$switchSettings_helper@VEditorConfiguration@ProjectExplorer@@VTextEditorSettings@TextEditor@@@ProjectExplorer@@YAXPEBVEditorConfiguration@0@PEBVTextEditorSettings@TextEditor@@PEAVTextEditorWidget@3@@Z)

lld-link: error: undefined symbol: ?appOutputSettings@ProjectExplorerPlugin@ProjectExplorer@@SAAEBVAppOutputSettings@Internal@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:129
>>>               debug\applicationlauncher.obj:(??0ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAA@PEAVApplicationLauncher@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:751
>>>               debug\appoutputpane.obj:(??0AppOutputSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ)

lld-link: error: undefined symbol: ?instance@WinDebugInterface@Internal@ProjectExplorer@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:160
>>>               debug\applicationlauncher.obj:(??0ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAA@PEAVApplicationLauncher@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:163
>>>               debug\applicationlauncher.obj:(??0ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAA@PEAVApplicationLauncher@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:302
>>>               debug\applicationlauncher.obj:(?cannotRetrieveLocalDebugOutput@ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:357
>>>               debug\applicationlauncher.obj:(?start@ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAAXAEBVRunnable@3@AEBV?$QSharedPointer@$$CBVIDevice@ProjectExplorer@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:358
>>>               debug\applicationlauncher.obj:(?start@ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAAXAEBVRunnable@3@AEBV?$QSharedPointer@$$CBVIDevice@ProjectExplorer@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:733
>>>               debug\appoutputpane.obj:(?slotRunControlFinished2@AppOutputPane@Internal@ProjectExplorer@@AEAAXPEAVRunControl@3@@Z)

lld-link: error: undefined symbol: ?cannotRetrieveDebugOutput@WinDebugInterface@Internal@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:160
>>>               debug\applicationlauncher.obj:(??0ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAA@PEAVApplicationLauncher@2@@Z)

lld-link: error: undefined symbol: ?debugOutput@WinDebugInterface@Internal@ProjectExplorer@@QEAAX_JAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\applicationlauncher.cpp:163
>>>               debug\applicationlauncher.obj:(??0ApplicationLauncherPrivate@Internal@ProjectExplorer@@QEAA@PEAVApplicationLauncher@2@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@WinDebugInterface@Internal@ProjectExplorer@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\applicationlauncher.obj:(??$connect@P8WinDebugInterface@Internal@ProjectExplorer@@EAAXXZP8ApplicationLauncherPrivate@23@EAAXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVWinDebugInterface@Internal@ProjectExplorer@@P8345@EAAXXZPEBVApplicationLauncherPrivate@45@P8645@EAAXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\applicationlauncher.obj:(??$connect@P8WinDebugInterface@Internal@ProjectExplorer@@EAAX_JAEBVQString@@@ZP8ApplicationLauncherPrivate@23@EAAX01@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVWinDebugInterface@Internal@ProjectExplorer@@P8345@EAAX_JAEBVQString@@@ZPEBVApplicationLauncherPrivate@45@P8745@EAAX12@ZW4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?renamedFile@DocumentManager@Core@@SAXAEBVQString@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:232
>>>               debug\foldernavigationwidget.obj:(?setData@FolderNavigationModel@Internal@ProjectExplorer@@UEAA_NAEBVQModelIndex@@AEBVQVariant@@H@Z)

lld-link: error: undefined symbol: ?removeFile@FileUtils@Core@@SAXAEBVQString@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:544
>>>               debug\foldernavigationwidget.obj:(?removeCurrentItem@FolderNavigationWidget@Internal@ProjectExplorer@@QEAAXXZ)

lld-link: error: undefined symbol: ?projectFileGlobs@ProjectExplorerPlugin@ProjectExplorer@@SA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:815
>>>               debug\foldernavigationwidget.obj:(?projectFilesInDirectory@FolderNavigationWidget@Internal@ProjectExplorer@@SA?AVQStringList@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?isProjectFile@ProjectExplorerPlugin@ProjectExplorer@@SA_NAEBVFilePath@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:729
>>>               debug\foldernavigationwidget.obj:(?contextMenuEvent@FolderNavigationWidget@Internal@ProjectExplorer@@MEAAXPEAVQContextMenuEvent@@@Z)

lld-link: error: undefined symbol: ?createDiffAgainstCurrentFileAction@TextDocument@TextEditor@@SAPEAVQAction@@PEAVQObject@@AEBV?$function@$$A6A?AVFilePath@Utils@@XZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:755
>>>               debug\foldernavigationwidget.obj:(?contextMenuEvent@FolderNavigationWidget@Internal@ProjectExplorer@@MEAAXPEAVQContextMenuEvent@@@Z)

lld-link: error: undefined symbol: ?openProject@ProjectExplorerPlugin@ProjectExplorer@@SA?AVOpenProjectResult@12@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\foldernavigationwidget.cpp:772
>>>               debug\foldernavigationwidget.obj:(?contextMenuEvent@FolderNavigationWidget@Internal@ProjectExplorer@@MEAAXPEAVQContextMenuEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:205
>>>               debug\gettingstartedwelcomepage.obj:(?openProject@ExamplesWelcomePage@Internal@QtSupport@@SAXPEBVExampleItem@23@@Z)

lld-link: error: undefined symbol: ?displayNameChanged@IFindFilter@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfind.cpp:97
>>>               debug\currentprojectfind.obj:(?handleProjectChanged@CurrentProjectFind@Internal@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\currentprojectfind.cpp:48
>>>               debug\currentprojectfind.obj:(??R<lambda_0>@?0???0CurrentProjectFind@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@PEAVProject@3@@Z)

lld-link: error: undefined symbol: ?cancelMsvcToolChainDetection@MsvcToolChain@Internal@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\toolchainmanager.cpp:237
>>>               debug\toolchainmanager.obj:(?aboutToShutdown@ToolChainManager@ProjectExplorer@@SAXXZ)

lld-link: error: undefined symbol: ?setProjectsDirectory@DocumentManager@Core@@SAXAEBVFilePath@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\baseprojectwizarddialog.cpp:132
>>>               debug\baseprojectwizarddialog.obj:(?slotAccepted@BaseProjectWizardDialog@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?setUseProjectsDirectory@DocumentManager@Core@@SAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\baseprojectwizarddialog.cpp:134
>>>               debug\baseprojectwizarddialog.obj:(?slotAccepted@BaseProjectWizardDialog@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?runRunConfiguration@ProjectExplorerPlugin@ProjectExplorer@@SAXPEAVRunConfiguration@2@VId@Utils@@_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\miniprojecttargetselector.cpp:381
>>>               debug\miniprojecttargetselector.obj:(?mouseReleaseEvent@GenericListWidget@Internal@ProjectExplorer@@EEAAXPEAVQMouseEvent@@@Z)

lld-link: error: undefined symbol: ?settingsChanged@ProjectExplorerPlugin@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\runconfigurationaspects.cpp:68
>>>               debug\runconfigurationaspects.obj:(??0TerminalAspect@ProjectExplorer@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\makestep.cpp:402
>>>               debug\makestep.obj:(?createConfigWidget@MakeStep@ProjectExplorer@@UEAAPEAVQWidget@@XZ)

lld-link: error: undefined symbol: ?setProjectExplorerSettings@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVProjectExplorerSettings@Internal@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:607
>>>               debug\appoutputpane.obj:(?optionallyPromptToStop@AppOutputPane@Internal@ProjectExplorer@@AEAA_NPEAVRunControl@3@@Z)

lld-link: error: undefined symbol: ?stop@WinDebugInterface@Internal@ProjectExplorer@@QEAA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:733
>>>               debug\appoutputpane.obj:(?slotRunControlFinished2@AppOutputPane@Internal@ProjectExplorer@@AEAAXPEAVRunControl@3@@Z)

lld-link: error: undefined symbol: ?setAppOutputSettings@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVAppOutputSettings@Internal@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\appoutputpane.cpp:805
>>>               debug\appoutputpane.obj:(?apply@AppOutputSettingsWidget@Internal@ProjectExplorer@@UEAAXXZ)

lld-link: error: undefined symbol: ??0DeviceSettingsWidget@Internal@ProjectExplorer@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\devicesupport\devicesettingspage.cpp:43
>>>               debug\devicesettingspage.obj:(??R<lambda_0>@?0???0DeviceSettingsPage@Internal@ProjectExplorer@@QEAA@XZ@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?customParsersChanged@ProjectExplorerPlugin@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\customparser.cpp:258
>>>               debug\customparser.obj:(??0SelectionWidget@?A0x762B73E@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?recentProjectsChanged@ProjectExplorerPlugin@ProjectExplorer@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:69
>>>               debug\projectwelcomepage.obj:(??0ProjectModel@Internal@ProjectExplorer@@QEAA@PEAVQObject@@@Z)

lld-link: error: undefined symbol: ?recentProjects@ProjectExplorerPlugin@ProjectExplorer@@SA?AV?$QList@U?$QPair@VQString@@V1@@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:75
>>>               debug\projectwelcomepage.obj:(?rowCount@ProjectModel@Internal@ProjectExplorer@@UEBAHAEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:79
>>>               debug\projectwelcomepage.obj:(?data@ProjectModel@Internal@ProjectExplorer@@UEBA?AVQVariant@@AEBVQModelIndex@@H@Z)

lld-link: error: undefined symbol: ?openNewProjectDialog@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:151
>>>               debug\projectwelcomepage.obj:(?newProject@ProjectWelcomePage@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:572
>>>               debug\projectwelcomepage.obj:(??R<lambda_2>@?0???0SessionsPage@Internal@ProjectExplorer@@QEAA@PEAVProjectWelcomePage@23@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?openOpenProjectDialog@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:155
>>>               debug\projectwelcomepage.obj:(?openProject@ProjectWelcomePage@Internal@ProjectExplorer@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:579
>>>               debug\projectwelcomepage.obj:(??R<lambda_3>@?0???0SessionsPage@Internal@ProjectExplorer@@QEAA@PEAVProjectWelcomePage@23@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?openProjectWelcomePage@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:169
>>>               debug\projectwelcomepage.obj:(?openProjectAt@ProjectWelcomePage@Internal@ProjectExplorer@@AEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:492
>>>               debug\projectwelcomepage.obj:(?editorEvent@ProjectDelegate@Internal@ProjectExplorer@@UEAA_NPEAVQEvent@@PEAVQAbstractItemModel@@AEBVQStyleOptionViewItem@@AEBVQModelIndex@@@Z)

lld-link: error: undefined symbol: ?removeFromRecentProjects@ProjectExplorerPlugin@ProjectExplorer@@SAXAEBVQString@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:505
>>>               debug\projectwelcomepage.obj:(??R<lambda_1>@?0??editorEvent@ProjectDelegate@Internal@ProjectExplorer@@UEAA_NPEAVQEvent@@PEAVQAbstractItemModel@@AEBVQStyleOptionViewItem@@AEBVQModelIndex@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?clearRecentProjects@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:513
>>>               debug\projectwelcomepage.obj:(??R<lambda_2>@?0??editorEvent@ProjectDelegate@Internal@ProjectExplorer@@UEAA_NPEAVQEvent@@PEAVQAbstractItemModel@@AEBVQStyleOptionViewItem@@AEBVQModelIndex@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?showSessionManager@ProjectExplorerPlugin@ProjectExplorer@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projectwelcomepage.cpp:566
>>>               debug\projectwelcomepage.obj:(??R<lambda_1>@?0???0SessionsPage@Internal@ProjectExplorer@@QEAA@PEAVProjectWelcomePage@23@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ??0SessionNameInputDialog@Internal@ProjectExplorer@@QEAA@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:210
>>>               debug\sessionmodel.obj:(?newSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:220
>>>               debug\sessionmodel.obj:(?cloneSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:241
>>>               debug\sessionmodel.obj:(?renameSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?setActionText@SessionNameInputDialog@Internal@ProjectExplorer@@QEAAXAEBVQString@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:212
>>>               debug\sessionmodel.obj:(?newSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:222
>>>               debug\sessionmodel.obj:(?cloneSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:243
>>>               debug\sessionmodel.obj:(?renameSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?value@SessionNameInputDialog@Internal@ProjectExplorer@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:261
>>>               debug\sessionmodel.obj:(?runSessionNameInputDialog@SessionModel@Internal@ProjectExplorer@@AEAAXPEAVSessionNameInputDialog@23@V?$function@$$A6AXAEBVQString@@@Z@std@@@Z)

lld-link: error: undefined symbol: ?isSwitchToRequested@SessionNameInputDialog@Internal@ProjectExplorer@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:270
>>>               debug\sessionmodel.obj:(?runSessionNameInputDialog@SessionModel@Internal@ProjectExplorer@@AEAAXPEAVSessionNameInputDialog@23@V?$function@$$A6AXAEBVQString@@@Z@std@@@Z)

lld-link: error: undefined symbol: ?setValue@SessionNameInputDialog@Internal@ProjectExplorer@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:223
>>>               debug\sessionmodel.obj:(?cloneSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\sessionmodel.cpp:244
>>>               debug\sessionmodel.obj:(?renameSession@SessionModel@Internal@ProjectExplorer@@QEAAXPEAVQWidget@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?setDefaultLocationForNewFiles@DocumentManager@Core@@SAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttree.cpp:217
>>>               debug\projecttree.obj:(?sessionChanged@ProjectTree@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttree.cpp:220
>>>               debug\projecttree.obj:(?sessionChanged@ProjectTree@ProjectExplorer@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\projectexplorer\projecttree.cpp:225
>>>               debug\projecttree.obj:(?sessionChanged@ProjectTree@ProjectExplorer@@AEAAXXZ)

lld-link: error: undefined symbol: ?quickToolBar@QmlJSEditorPlugin@Internal@QmlJSEditor@@SAPEAVQuickToolBar@3@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:132
>>>               debug\qmljseditor.obj:(?finalizeInitialization@QmlJSEditorWidget@QmlJSEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?isValid@SemanticInfo@QmlJSTools@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:316
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:490
>>>               debug\qmljseditor.obj:(?setSelectedElements@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:684
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:726
>>>               debug\qmljseditor.obj:(?findLinkAt@QmlJSEditorWidget@QmlJSEditor@@MEAAXAEBVQTextCursor@@$$QEAV?$function@$$A6AXAEBULink@Utils@@@Z@std@@_N2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:823
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1000
>>>               debug\qmljseditor.obj:(?foldReplacementText@QmlJSEditorWidget@QmlJSEditor@@MEBA?AVQString@@AEBVQTextBlock@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:212
>>>               debug\qmljshoverhandler.obj:(?identifyMatch@QmlJSHoverHandler@QmlJSEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:65
>>>               debug\qmloutlinemodel.obj:(?data@QmlOutlineItem@Internal@QmlJSEditor@@UEBA?AVQVariant@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:384
>>>               debug\qmloutlinemodel.obj:(?flags@QmlOutlineModel@Internal@QmlJSEditor@@UEBA?AV?$QFlags@W4ItemFlag@Qt@@@@AEBVQModelIndex@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:407
>>>               debug\qmloutlinemodel.obj:(?update@QmlOutlineModel@Internal@QmlJSEditor@@QEAAXAEBVSemanticInfo@QmlJSTools@@@Z)
>>> referenced 1 more times

lld-link: error: undefined symbol: ?declaringMemberNoProperties@SemanticInfo@QmlJSTools@@QEBAPEAVNode@AST@QmlJS@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:318
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:319
>>>               debug\qmljseditor.obj:(?updateContextPane@QmlJSEditorWidget@QmlJSEditor@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:942
>>>               debug\qmljseditor.obj:(?semanticInfoUpdated@QmlJSEditorWidget@QmlJSEditor@@AEAAXAEBVSemanticInfo@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:824
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:874
>>>               debug\qmljseditor.obj:(?contextMenuEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQContextMenuEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:914
>>>               debug\qmljseditor.obj:(?wheelEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQWheelEvent@@@Z)

lld-link: error: undefined symbol: ?className@FakeMetaObject@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:699
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:701
>>>               debug\qmljseditor.obj:(?inspectElementUnderCursor@QmlJSEditorWidget@QmlJSEditor@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:646
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:570
>>>               debug\qmljseditor.obj:(?processProperty@CodeModelInspector@QmlJSEditor@@UEAA_NAEBVQString@@PEBVValue@QmlJS@@AEBVPropertyInfo@5@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:803
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildContextProperties@?A0x81E322E8@@YAXAEBV?$QSharedPointer@VDocument@CPlusPlus@@@@AEAVTypeOfExpression@CPlusPlus@@AEBV?$QList@VContextProperty@?A0x81E322E8@@@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@PEAV?$QHash@VQString@@V1@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:676
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1143
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1152
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1088
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced 10 more times

lld-link: error: undefined symbol: ?astNodeAt@SemanticInfo@QmlJSTools@@QEBAPEAVNode@AST@QmlJS@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:627
>>>               debug\qmljseditor.obj:(?findCppComponentToInspect@QmlJSEditor@@YAPEBVCppComponentValue@QmlJS@@AEBVSemanticInfo@QmlJSTools@@I@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:730
>>>               debug\qmljseditor.obj:(?findLinkAt@QmlJSEditorWidget@QmlJSEditor@@MEAAXAEBVQTextCursor@@$$QEAV?$function@$$A6AXAEBULink@Utils@@@Z@std@@_N2@Z)

lld-link: error: undefined symbol: ?rangePath@SemanticInfo@QmlJSTools@@QEBA?AV?$QList@PEAVNode@AST@QmlJS@@@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:630
>>>               debug\qmljseditor.obj:(?findCppComponentToInspect@QmlJSEditor@@YAPEBVCppComponentValue@QmlJS@@AEBVSemanticInfo@QmlJSTools@@I@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:769
>>>               debug\qmljseditor.obj:(?findLinkAt@QmlJSEditorWidget@QmlJSEditor@@MEAAXAEBVQTextCursor@@$$QEAV?$function@$$A6AXAEBULink@Utils@@@Z@std@@_N2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:825
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:216
>>>               debug\qmljshoverhandler.obj:(?identifyMatch@QmlJSHoverHandler@QmlJSEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:244
>>>               debug\qmljscomponentfromobjectdef.obj:(?matchComponentFromObjectDefQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:69
>>>               debug\qmloutlinemodel.obj:(?data@QmlOutlineItem@Internal@QmlJSEditor@@UEBA?AVQVariant@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscompletionassist.cpp:516
>>>               debug\qmljscompletionassist.obj:(?perform@QmlJSCompletionAssistProcessor@Internal@QmlJSEditor@@UEAAPEAVIAssistProposal@TextEditor@@PEBVAssistInterface@5@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljswrapinloader.cpp:184
>>>               debug\qmljswrapinloader.obj:(?matchWrapInLoaderQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)

lld-link: error: undefined symbol: ?scopeChain@SemanticInfo@QmlJSTools@@QEBA?AVScopeChain@QmlJS@@AEBV?$QList@PEAVNode@AST@QmlJS@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:630
>>>               debug\qmljseditor.obj:(?findCppComponentToInspect@QmlJSEditor@@YAPEBVCppComponentValue@QmlJS@@AEBVSemanticInfo@QmlJSTools@@I@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:769
>>>               debug\qmljseditor.obj:(?findLinkAt@QmlJSEditorWidget@QmlJSEditor@@MEAAXAEBVQTextCursor@@$$QEAV?$function@$$A6AXAEBULink@Utils@@@Z@std@@_N2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:825
>>>               debug\qmljseditor.obj:(?showContextPane@QmlJSEditorWidget@QmlJSEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:219
>>>               debug\qmljshoverhandler.obj:(?identifyMatch@QmlJSHoverHandler@QmlJSEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@HV?$function@$$A6AXH@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:71
>>>               debug\qmloutlinemodel.obj:(?data@QmlOutlineItem@Internal@QmlJSEditor@@UEBA?AVQVariant@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscompletionassist.cpp:519
>>>               debug\qmljscompletionassist.obj:(?perform@QmlJSCompletionAssistProcessor@Internal@QmlJSEditor@@UEAAPEAVIAssistProposal@TextEditor@@PEBVAssistInterface@5@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemantichighlighter.cpp:165
>>>               debug\qmljssemantichighlighter.obj:(??0CollectionTask@?A0xF6715106@QmlJSEditor@@QEAA@V?$QFutureInterface@VHighlightingResult@TextEditor@@@@AEBVSemanticInfo@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljswrapinloader.cpp:98
>>>               debug\qmljswrapinloader.obj:(?findFreeName@?$Operation@VUiObjectDefinition@AST@QmlJS@@@?A0x26A71CC@QmlJSEditor@@QEAA?AVQString@@AEBV3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljswrapinloader.cpp:98
>>>               debug\qmljswrapinloader.obj:(?findFreeName@?$Operation@VUiObjectBinding@AST@QmlJS@@@?A0x26A71CC@QmlJSEditor@@QEAA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?superclassName@FakeMetaObject@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:644
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1181
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1102
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1102
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:253
>>>               debug\qmljslink.obj:(?workaroundQEasingCurve@QmlJS@@YAXAEAVCppQmlTypes@1@@Z)

lld-link: error: undefined symbol: ?toString@ComponentVersion@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1220
>>>               debug\qmljsinterpreter.obj:(?qualifiedName@CppQmlTypes@QmlJS@@SA?AVQString@@AEBV3@0VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:2077
>>>               debug\qmljsinterpreter.obj:(?dump@Imports@QmlJS@@QEBAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:406
>>>               debug\qmljslink.obj:(?importNonFile@LinkPrivate@QmlJS@@QEAA?AVImport@2@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVImportInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:499
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:535
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:539
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsmodelmanagerinterface.cpp:797
>>>               debug\qmljsmodelmanagerinterface.obj:(?modulePath@QmlJS@@YA?AVQString@@AEBVImportInfo@1@AEBVQStringList@@@Z)

lld-link: error: undefined symbol: ??1ComponentVersion@LanguageUtils@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?dtor$57@?0??inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:648
>>>               debug\qmljseditor.obj:(?dtor$62@?0??inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser_p.h:127
>>>               debug\qmljseditor.obj:(??1Import@QmlDirParser@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.h:124
>>>               debug\qmljseditor.obj:(??1ModuleApiInfo@QmlJS@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.h:1020
>>>               debug\qmljseditor.obj:(??1ImportInfo@QmlJS@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:105
>>>               debug\qmljshoverhandler.obj:(?getModuleName@QmlJSEditor@@YA?AVQString@@AEBVScopeChain@QmlJS@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@PEBVObjectValue@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:106
>>>               debug\qmljshoverhandler.obj:(?getModuleName@QmlJSEditor@@YA?AVQString@@AEBVScopeChain@QmlJS@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@PEBVObjectValue@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:119
>>>               debug\qmljshoverhandler.obj:(?getModuleName@QmlJSEditor@@YA?AVQString@@AEBVScopeChain@QmlJS@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@PEBVObjectValue@4@@Z)
>>> referenced 108 more times

lld-link: error: undefined symbol: ?enumeratorCount@FakeMetaObject@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:659
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:209
>>>               debug\qmljsinterpreter.obj:(??0CppComponentValue@QmlJS@@QEAA@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@AEBVQString@@1AEBVComponentVersion@LanguageUtils@@2HPEAVValueOwner@1@1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:240
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?enumeratorOffset@FakeMetaObject@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:660
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:240
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?enumerator@FakeMetaObject@LanguageUtils@@QEBA?AVFakeMetaEnum@2@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:662
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:211
>>>               debug\qmljsinterpreter.obj:(??0CppComponentValue@QmlJS@@QEAA@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@AEBVQString@@1AEBVComponentVersion@LanguageUtils@@2HPEAVValueOwner@1@1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:242
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:458
>>>               debug\qmljsinterpreter.obj:(?getEnum@CppComponentValue@QmlJS@@QEBA?AVFakeMetaEnum@LanguageUtils@@AEBVQString@@PEAPEBV12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:563
>>>               debug\qmljsinterpreter.obj:(?name@QmlEnumValue@QmlJS@@QEBA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:567
>>>               debug\qmljsinterpreter.obj:(?keys@QmlEnumValue@QmlJS@@QEBA?AVQStringList@@XZ)

lld-link: error: undefined symbol: ?name@FakeMetaEnum@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:664
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:212
>>>               debug\qmljsinterpreter.obj:(??0CppComponentValue@QmlJS@@QEAA@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@AEBVQString@@1AEBVComponentVersion@LanguageUtils@@2HPEAVValueOwner@1@1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:563
>>>               debug\qmljsinterpreter.obj:(?name@QmlEnumValue@QmlJS@@QEBA?AVQString@@XZ)

lld-link: error: undefined symbol: ?keys@FakeMetaEnum@LanguageUtils@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:665
>>>               debug\qmljseditor.obj:(?inspectCppComponent@QmlJSEditor@@YA?AVQString@@PEBVCppComponentValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:567
>>>               debug\qmljsinterpreter.obj:(?keys@QmlEnumValue@QmlJS@@QEBA?AVQStringList@@XZ)

lld-link: error: undefined symbol: ?quickFixAssistProvider@QmlJSEditorPlugin@Internal@QmlJSEditor@@SAPEAVQmlJSQuickFixAssistProvider@23@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:843
>>>               debug\qmljseditor.obj:(?contextMenuEvent@QmlJSEditorWidget@QmlJSEditor@@MEAAXPEAVQContextMenuEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:625
>>>               debug\qmljseditordocument.obj:(?quickFixAssistProvider@QmlJSEditorDocument@QmlJSEditor@@UEBAPEAVIAssistProvider@TextEditor@@XZ)

lld-link: error: undefined symbol: ?rangeAt@SemanticInfo@QmlJSTools@@QEBAPEAVNode@AST@QmlJS@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1002
>>>               debug\qmljseditor.obj:(?foldReplacementText@QmlJSEditorWidget@QmlJSEditor@@MEBA?AVQString@@AEBVQTextBlock@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:108
>>>               debug\qmljsquickfixes.obj:(?matchSplitInitializerQuickFix@?A0x141109A6@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)

lld-link: error: undefined symbol: ?setEditorCreator@TextEditorFactory@TextEditor@@QEAAXAEBV?$function@$$A6APEAVBaseTextEditor@TextEditor@@XZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1051
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:83
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ?setAutoCompleterCreator@TextEditorFactory@TextEditor@@QEAAXAEBV?$function@$$A6APEAVAutoCompleter@TextEditor@@XZ@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1052
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setCommentDefinition@TextEditorFactory@TextEditor@@QEAAXVCommentDefinition@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1053
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setParenthesesMatchingEnabled@TextEditorFactory@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1054
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setCodeFoldingSupported@TextEditorFactory@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1055
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?setCompletionAssistProvider@TextEditorFactory@TextEditor@@QEAAXPEAVCompletionAssistProvider@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1058
>>>               debug\qmljseditor.obj:(??0QmlJSEditorFactory@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ??0Indenter@Internal@QmlJSEditor@@QEAA@PEAVQTextDocument@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:1069
>>>               debug\qmljseditor.obj:(?decorateEditor@QmlJSEditorFactory@QmlJSEditor@@SAXPEAVTextEditorWidget@TextEditor@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:601
>>>               debug\qmljseditordocument.obj:(??0QmlJSEditorDocument@QmlJSEditor@@QEAA@VId@Utils@@@Z)

lld-link: error: undefined symbol: ?parameterNames@FakeMetaMethod@LanguageUtils@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:603
>>>               debug\qmljseditor.obj:(?stringifyFunctionParameters@CodeModelInspector@QmlJSEditor@@AEBA?AVQString@@PEBVValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:136
>>>               debug\qmljsinterpreter.obj:(?namedArgumentCount@MetaFunction@QmlJS@@UEBAHXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:140
>>>               debug\qmljsinterpreter.obj:(?argumentName@MetaFunction@QmlJS@@UEBA?AVQString@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:141
>>>               debug\qmljsinterpreter.obj:(?argumentName@MetaFunction@QmlJS@@UEBA?AVQString@@H@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:490
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?parameterTypes@FakeMetaMethod@LanguageUtils@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditor.cpp:604
>>>               debug\qmljseditor.obj:(?stringifyFunctionParameters@CodeModelInspector@QmlJSEditor@@AEBA?AVQString@@PEBVValue@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:491
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?astPath@SemanticInfo@QmlJSTools@@QEBA?AV?$QList@PEAVNode@AST@QmlJS@@@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljshoverhandler.cpp:221
>>>               debug\qmljshoverhandler.obj:(?identifyMatch@QmlJSHoverHandler@QmlJSEditor@@EEAAXPEAVTextEditorWidget@TextEditor@@HV?$function@$$A6AXH@Z@std@@@Z)

lld-link: error: undefined symbol: ?isCursorOn@QmlJSRefactoringFile@QmlJSTools@@QEBA_NPEAVUiQualifiedId@AST@QmlJS@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:248
>>>               debug\qmljscomponentfromobjectdef.obj:(?matchComponentFromObjectDefQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:256
>>>               debug\qmljscomponentfromobjectdef.obj:(?matchComponentFromObjectDefQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljswrapinloader.cpp:188
>>>               debug\qmljswrapinloader.obj:(?matchWrapInLoaderQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljswrapinloader.cpp:196
>>>               debug\qmljswrapinloader.obj:(?matchWrapInLoaderQuickFix@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)

lld-link: error: undefined symbol: ??0QmlJSRefactoringChanges@QmlJSTools@@QEAA@PEAVModelManagerInterface@QmlJS@@AEBVSnapshot@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:267
>>>               debug\qmljscomponentfromobjectdef.obj:(?performComponentFromObjectDef@QmlJSEditor@@YAXAEBVQString@@PEAVUiObjectDefinition@AST@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:831
>>>               debug\qmloutlinemodel.obj:(?reparentNodes@QmlOutlineModel@Internal@QmlJSEditor@@AEAAXPEAVQmlOutlineItem@23@HV?$QList@PEAVQmlOutlineItem@Internal@QmlJSEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfix.cpp:52
>>>               debug\qmljsquickfix.obj:(?perform@QmlJSQuickFixOperation@QmlJSEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?file@QmlJSRefactoringChanges@QmlJSTools@@QEBA?AV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:270
>>>               debug\qmljscomponentfromobjectdef.obj:(?performComponentFromObjectDef@QmlJSEditor@@YAXAEBVQString@@PEAVUiObjectDefinition@AST@QmlJS@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmloutlinemodel.cpp:833
>>>               debug\qmloutlinemodel.obj:(?reparentNodes@QmlOutlineModel@Internal@QmlJSEditor@@AEAAXPEAVQmlOutlineItem@23@HV?$QList@PEAVQmlOutlineItem@Internal@QmlJSEditor@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfix.cpp:54
>>>               debug\qmljsquickfix.obj:(?perform@QmlJSQuickFixOperation@QmlJSEditor@@UEAAXXZ)

lld-link: error: undefined symbol: ?qmljsDocument@QmlJSRefactoringFile@QmlJSTools@@QEBA?AV?$QSharedPointer@$$CBVDocument@QmlJS@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:105
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:108
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:145
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)

lld-link: error: undefined symbol: ?go@ComponentNameDialog@Internal@QmlJSEditor@@SA_NPEAVQString@@00AEBVQStringList@@1AEBV4@PEAV5@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:133
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)

lld-link: error: undefined symbol: ?startOf@QmlJSRefactoringFile@QmlJSTools@@QEBAIAEBVSourceLocation@QmlJS@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:147
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:149
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:154
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljscomponentfromobjectdef.cpp:155
>>>               debug\qmljscomponentfromobjectdef.obj:(?performChanges@Operation@?A0x812D351D@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:86
>>>               debug\qmljsquickfixes.obj:(?performChanges@SplitInitializerOperation@?A0x141109A6@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:91
>>>               debug\qmljsquickfixes.obj:(?performChanges@SplitInitializerOperation@?A0x141109A6@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:95
>>>               debug\qmljsquickfixes.obj:(?performChanges@SplitInitializerOperation@?A0x141109A6@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:95
>>>               debug\qmljsquickfixes.obj:(?performChanges@SplitInitializerOperation@?A0x141109A6@QmlJSEditor@@UEAAXV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@AEBVQmlJSRefactoringChanges@QmlJSTools@@@Z)

lld-link: error: undefined symbol: ?isCursorOn@QmlJSRefactoringFile@QmlJSTools@@QEBA_NVSourceLocation@QmlJS@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixes.cpp:160
>>>               debug\qmljsquickfixes.obj:(?matchAddAnalysisMessageSuppressionCommentQuickFix@?A0x141109A6@QmlJSEditor@@YAXAEBV?$QSharedPointer@$$CBVQmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@@@AEAV?$QList@V?$QSharedPointer@VQuickFixOperation@TextEditor@@@@@@@Z)

lld-link: error: undefined symbol: ?file@QmlJSRefactoringChanges@QmlJSTools@@SA?AV?$QSharedPointer@VQmlJSRefactoringFile@QmlJSTools@@@@PEAVTextEditorWidget@TextEditor@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljsquickfixassist.cpp:55
>>>               debug\qmljsquickfixassist.obj:(??0QmlJSQuickFixAssistInterface@Internal@QmlJSEditor@@QEAA@PEAVQmlJSEditorWidget@2@W4AssistReason@TextEditor@@@Z)

lld-link: error: undefined symbol: ?setRootScopeChain@SemanticInfo@QmlJSTools@@QEAAXV?$QSharedPointer@$$CBVScopeChain@QmlJS@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemanticinfoupdater.cpp:116
>>>               debug\qmljssemanticinfoupdater.obj:(?makeNewSemanticInfo@SemanticInfoUpdater@Internal@QmlJSEditor@@AEAA?AVSemanticInfo@QmlJSTools@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVSnapshot@QmlJS@@@Z)

lld-link: error: undefined symbol: ?jsonManager@QmlJSEditorPlugin@Internal@QmlJSEditor@@SAPEAVJsonSchemaManager@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljssemanticinfoupdater.cpp:119
>>>               debug\qmljssemanticinfoupdater.obj:(?makeNewSemanticInfo@SemanticInfoUpdater@Internal@QmlJSEditor@@AEAA?AVSemanticInfo@QmlJSTools@@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVSnapshot@QmlJS@@@Z)

lld-link: error: undefined symbol: ?revision@SemanticInfo@QmlJSTools@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:508
>>>               debug\qmljseditordocument.obj:(?acceptNewSemanticInfo@QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@QEAAXAEBVSemanticInfo@QmlJSTools@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:611
>>>               debug\qmljseditordocument.obj:(?isSemanticInfoOutdated@QmlJSEditorDocument@QmlJSEditor@@QEBA_NXZ)

lld-link: error: undefined symbol: ??0CreatorCodeFormatter@QmlJSTools@@QEAA@AEBVTabSettings@TextEditor@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljseditor\qmljseditordocument.cpp:469
>>>               debug\qmljseditordocument.obj:(?invalidateFormatterCache@QmlJSEditorDocumentPrivate@Internal@QmlJSEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?completionAssistProvider@TextDocument@TextEditor@@UEBAPEAVCompletionAssistProvider@2@XZ
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ?functionHintAssistProvider@TextDocument@TextEditor@@UEBAPEAVCompletionAssistProvider@2@XZ
>>> referenced by debug\qmljseditordocument.obj:(??_7QmlJSEditorDocument@QmlJSEditor@@6B@)

lld-link: error: undefined symbol: ??0ExamplesListModel@Internal@QtSupport@@QEAA@PEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:268
>>>               debug\gettingstartedwelcomepage.obj:(??0ExamplesPageWidget@Internal@QtSupport@@QEAA@_N@Z)

lld-link: error: undefined symbol: ??0ExamplesListModelFilter@Internal@QtSupport@@QEAA@PEAVExamplesListModel@12@_NPEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:271
>>>               debug\gettingstartedwelcomepage.obj:(??0ExamplesPageWidget@Internal@QtSupport@@QEAA@_N@Z)

lld-link: error: undefined symbol: ?selectExampleSet@ExampleSetModel@Internal@QtSupport@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\gettingstartedwelcomepage.cpp:292
>>>               debug\gettingstartedwelcomepage.obj:(??0ExamplesPageWidget@Internal@QtSupport@@QEAA@_N@Z)

lld-link: error: undefined symbol: ?isQmlDebuggingSupported@BaseQtVersion@QtSupport@@SA_NPEBVKit@ProjectExplorer@@PEAVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtbuildaspects.cpp:57
>>>               debug\qtbuildaspects.obj:(??R<lambda_0>@?0??addToLayout@QmlDebuggingAspect@QtSupport@@UEAAXAEAVLayoutBuilder@Utils@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?isQtQuickCompilerSupported@BaseQtVersion@QtSupport@@SA_NPEBVKit@ProjectExplorer@@PEAVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtbuildaspects.cpp:90
>>>               debug\qtbuildaspects.obj:(??R<lambda_1>@?0??addToLayout@QtQuickCompilerAspect@QtSupport@@EEAAXAEAVLayoutBuilder@Utils@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?qtVersion@BaseQtVersion@QtSupport@@QEBA?AVQtVersionNumber@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtcppkitinfo.cpp:36
>>>               debug\qtcppkitinfo.obj:(??0CppKitInfo@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:389
>>>               debug\qtkitinformation.obj:(??R<lambda_6>@?0??qtVersionPredicate@QtKitAspect@QtSupport@@SA?AV?$function@$$A6A_NPEBVKit@ProjectExplorer@@@Z@std@@AEBV?$QSet@VId@Utils@@@@AEBVQtVersionNumber@3@1@Z@QEBA@PEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:501
>>>               debug\qtversionmanager.obj:(?documentationFiles@QtSupport@@YA?AVQStringList@@AEBV?$QList@PEAVBaseQtVersion@QtSupport@@@@_N@Z)

lld-link: error: undefined symbol: ??0QtVersionNumber@QtSupport@@QEAA@HHH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtcppkitinfo.cpp:36
>>>               debug\qtcppkitinfo.obj:(??0CppKitInfo@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@@Z)

lld-link: error: undefined symbol: ??MQtVersionNumber@QtSupport@@QEBA_NAEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtcppkitinfo.cpp:36
>>>               debug\qtcppkitinfo.obj:(??0CppKitInfo@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:390
>>>               debug\qtkitinformation.obj:(??R<lambda_6>@?0??qtVersionPredicate@QtKitAspect@QtSupport@@SA?AV?$function@$$A6A_NPEBVKit@ProjectExplorer@@@Z@std@@AEBV?$QSet@VId@Utils@@@@AEBVQtVersionNumber@3@1@Z@QEBA@PEBVKit@ProjectExplorer@@@Z)

lld-link: error: undefined symbol: ?qmakeCommand@BaseQtVersion@QtSupport@@QEBA?AVFilePath@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtprojectimporter.cpp:57
>>>               debug\qtprojectimporter.obj:(?findOrCreateQtVersion@QtProjectImporter@QtSupport@@IEBA?AVQtVersionData@12@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:312
>>>               debug\qtkitinformation.obj:(??R<lambda_3>@?0??addToMacroExpander@QtKitAspect@QtSupport@@UEBAXPEAVKit@ProjectExplorer@@PEAVMacroExpander@Utils@@@Z@QEBA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:256
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:337
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:359
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:436
>>>               debug\qtversionmanager.obj:(??R<lambda_5>@?0??findSystemQt@QtSupport@@YAXXZ@QEBA?A?<auto>@@PEBVBaseQtVersion@2@@Z)

lld-link: error: undefined symbol: ?uniqueId@BaseQtVersion@QtSupport@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtprojectimporter.cpp:61
>>>               debug\qtprojectimporter.obj:(?findOrCreateQtVersion@QtProjectImporter@QtSupport@@IEBA?AVQtVersionData@12@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtprojectimporter.cpp:86
>>>               debug\qtprojectimporter.obj:(??R<lambda_2>@?0??createTemporaryKit@QtProjectImporter@QtSupport@@IEBAPEAVKit@ProjectExplorer@@AEBVQtVersionData@23@AEBV?$function@$$A6AXPEAVKit@ProjectExplorer@@@Z@std@@@Z@QEBA@PEAV45@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:188
>>>               debug\qtkitinformation.obj:(?setup@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:190
>>>               debug\qtkitinformation.obj:(?setup@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:333
>>>               debug\qtkitinformation.obj:(?qtVersionId@QtKitAspect@QtSupport@@SAHPEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:352
>>>               debug\qtkitinformation.obj:(?setQtVersion@QtKitAspect@QtSupport@@SAXPEAVKit@ProjectExplorer@@PEBVBaseQtVersion@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:61
>>>               debug\qtkitinformation.obj:(??0QtKitAspectWidget@Internal@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@PEBVKitAspect@4@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:207
>>>               debug\qtversionmanager.obj:(?restoreQtVersions@QtSupport@@YA_NXZ)
>>> referenced 24 more times

lld-link: error: undefined symbol: ?createQtVersionFromQMakePath@QtVersionFactory@QtSupport@@SAPEAVBaseQtVersion@2@AEBVFilePath@Utils@@_NAEBVQString@@PEAV6@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtprojectimporter.cpp:68
>>>               debug\qtprojectimporter.obj:(?findOrCreateQtVersion@QtProjectImporter@QtSupport@@IEBA?AVQtVersionData@12@AEBVFilePath@Utils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:440
>>>               debug\qtversionmanager.obj:(?findSystemQt@QtSupport@@YAXXZ)

lld-link: error: undefined symbol: ?displayName@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtprojectimporter.cpp:88
>>>               debug\qtprojectimporter.obj:(??R<lambda_2>@?0??createTemporaryKit@QtProjectImporter@QtSupport@@IEBAPEAVKit@ProjectExplorer@@AEBVQtVersionData@23@AEBV?$function@$$A6AXPEAVKit@ProjectExplorer@@@Z@std@@@Z@QEBA@PEAV45@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:267
>>>               debug\qtkitinformation.obj:(?displayNamePostfix@QtKitAspect@QtSupport@@UEBA?AVQString@@PEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:273
>>>               debug\qtkitinformation.obj:(?toUserOutput@QtKitAspect@QtSupport@@UEBA?AV?$QList@U?$QPair@VQString@@V1@@@@@PEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:306
>>>               debug\qtkitinformation.obj:(??R<lambda_2>@?0??addToMacroExpander@QtKitAspect@QtSupport@@UEBAXPEAVKit@ProjectExplorer@@PEAVMacroExpander@Utils@@@Z@QEBA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:97
>>>               debug\qtkitinformation.obj:(?itemNameFor@QtKitAspectWidget@Internal@QtSupport@@CA?AVQString@@PEBVBaseQtVersion@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:99
>>>               debug\qtkitinformation.obj:(?itemNameFor@QtKitAspectWidget@Internal@QtSupport@@CA?AVQString@@PEBVBaseQtVersion@3@@Z)

lld-link: error: undefined symbol: ?autodetectionSource@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:185
>>>               debug\qtkitinformation.obj:(?setup@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:331
>>>               debug\qtkitinformation.obj:(??R<lambda_4>@?0??qtVersionId@QtKitAspect@QtSupport@@SAHPEBVKit@ProjectExplorer@@@Z@QEBA?A?<auto>@@PEBVBaseQtVersion@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:258
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:296
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:339
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:346
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:347
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:348
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:361
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?mkspec@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:216
>>>               debug\qtkitinformation.obj:(?fix@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z)

lld-link: error: undefined symbol: ?createMacroExpander@BaseQtVersion@QtSupport@@SA?AV?$unique_ptr@VMacroExpander@Utils@@U?$default_delete@VMacroExpander@Utils@@@std@@@std@@AEBV?$function@$$A6APEBVBaseQtVersion@QtSupport@@XZ@4@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:292
>>>               debug\qtkitinformation.obj:(??0QtMacroSubProvider@QtSupport@@QEAA@PEAVKit@ProjectExplorer@@@Z)

lld-link: error: undefined symbol: ?features@BaseQtVersion@QtSupport@@QEBA?AV?$QSet@VId@Utils@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:403
>>>               debug\qtkitinformation.obj:(?availableFeatures@QtKitAspect@QtSupport@@UEBA?AV?$QSet@VId@Utils@@@@PEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:392
>>>               debug\qtkitinformation.obj:(??R<lambda_6>@?0??qtVersionPredicate@QtKitAspect@QtSupport@@SA?AV?$function@$$A6A_NPEBVKit@ProjectExplorer@@@Z@std@@AEBV?$QSet@VId@Utils@@@@AEBVQtVersionNumber@3@1@Z@QEBA@PEBVKit@ProjectExplorer@@@Z)

lld-link: error: undefined symbol: ?qtAbis@BaseQtVersion@QtSupport@@QEBA?AV?$QVector@VAbi@ProjectExplorer@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:412
>>>               debug\qtkitinformation.obj:(?weight@QtKitAspect@QtSupport@@EEBAHPEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:413
>>>               debug\qtkitinformation.obj:(?weight@QtKitAspect@QtSupport@@EEBAHPEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:169
>>>               debug\qtkitinformation.obj:(??R<lambda_0>@?0??setup@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z@QEBA?A?<auto>@@PEBVBaseQtVersion@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:180
>>>               debug\qtkitinformation.obj:(??R<lambda_7>@?0??setup@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z@QEBA?A?<auto>@@PEBVBaseQtVersion@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:219
>>>               debug\qtkitinformation.obj:(??R<lambda_1>@?0??fix@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z@QEBA?A?<auto>@@PEBVToolChain@5@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:233
>>>               debug\qtkitinformation.obj:(??R<lambda_8>@?0??fix@QtKitAspect@QtSupport@@UEAAXPEAVKit@ProjectExplorer@@@Z@QEBA?A?<auto>@@PEBVToolChain@5@1@Z)

lld-link: error: undefined symbol: ??OQtVersionNumber@QtSupport@@QEBA_NAEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtkitinformation.cpp:391
>>>               debug\qtkitinformation.obj:(??R<lambda_6>@?0??qtVersionPredicate@QtKitAspect@QtSupport@@SA?AV?$function@$$A6A_NPEBVKit@ProjectExplorer@@@Z@std@@AEBV?$QSet@VId@Utils@@@@AEBVQtVersionNumber@3@1@Z@QEBA@PEBVKit@ProjectExplorer@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)

lld-link: error: undefined symbol: ??8QtVersionNumber@QtSupport@@QEBA_NAEBV01@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:93
>>>               debug\qtversionmanager.obj:(?qtVersionNumberCompare@QtSupport@@YA_NPEAVBaseQtVersion@1@0@Z)

lld-link: error: undefined symbol: ?allQtVersionFactories@QtVersionFactory@QtSupport@@SA?BV?$QList@PEAVQtVersionFactory@QtSupport@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:178
>>>               debug\qtversionmanager.obj:(?restoreQtVersions@QtSupport@@YA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:247
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?canRestore@QtVersionFactory@QtSupport@@QEAA_NAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:205
>>>               debug\qtversionmanager.obj:(?restoreQtVersions@QtSupport@@YA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:284
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?restore@QtVersionFactory@QtSupport@@QEAAPEAVBaseQtVersion@2@AEBVQString@@AEBV?$QMap@VQString@@VQVariant@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:206
>>>               debug\qtversionmanager.obj:(?restoreQtVersions@QtSupport@@YA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:305
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:320
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?unexpandedDisplayName@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:302
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?isAutodetected@BaseQtVersion@QtSupport@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:306
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:321
>>>               debug\qtversionmanager.obj:(?updateFromInstaller@QtVersionManager@QtSupport@@AEAAX_N@Z)

lld-link: error: undefined symbol: ?type@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:379
>>>               debug\qtversionmanager.obj:(?saveQtVersions@QtSupport@@YAXXZ)

lld-link: error: undefined symbol: ?docsPath@BaseQtVersion@QtSupport@@QEBA?AVFilePath@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:479
>>>               debug\qtversionmanager.obj:(?documentationFiles@QtSupport@@YA?AV?$QList@U?$pair@VQString@@V1@@std@@@@PEAVBaseQtVersion@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qtversionmanager.cpp:479
>>>               debug\qtversionmanager.obj:(?documentationFiles@QtSupport@@YA?AV?$QList@U?$pair@VQString@@V1@@std@@@@PEAVBaseQtVersion@1@@Z)

lld-link: error: undefined symbol: ?binPath@BaseQtVersion@QtSupport@@QEBA?AVFilePath@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qmldumptool.cpp:60
>>>               debug\qmldumptool.obj:(?toolForVersion@QmlDumpTool@QtSupport@@SA?AVQString@@PEBVBaseQtVersion@2@_N@Z)

lld-link: error: undefined symbol: ?hasQmlDump@BaseQtVersion@QtSupport@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qmldumptool.cpp:86
>>>               debug\qmldumptool.obj:(?pathAndEnvironment@QmlDumpTool@QtSupport@@SAXPEBVKit@ProjectExplorer@@_NPEAVQString@@PEAVEnvironment@Utils@@@Z)

lld-link: error: undefined symbol: ??0QMakeParser@@QEAA@PEAVProFileCache@@PEAVQMakeVfs@@PEAVQMakeParserHandler@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:80
>>>               debug\profilereader.obj:(??0ProFileReader@QtSupport@@QEAA@PEAVQMakeGlobals@@PEAVQMakeVfs@@@Z)

lld-link: error: undefined symbol: ??0ProFileEvaluator@@QEAA@PEAVQMakeGlobals@@PEAVQMakeParser@@PEAVQMakeVfs@@PEAVQMakeHandler@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:80
>>>               debug\profilereader.obj:(??0ProFileReader@QtSupport@@QEAA@PEAVQMakeGlobals@@PEAVQMakeVfs@@@Z)

lld-link: error: undefined symbol: ?setExtraConfigs@ProFileEvaluator@@QEAAXAEBVQStringList@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:81
>>>               debug\profilereader.obj:(??0ProFileReader@QtSupport@@QEAA@PEAVQMakeGlobals@@PEAVQMakeVfs@@@Z)

lld-link: error: undefined symbol: ??1ProFileEvaluator@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:82
>>>               debug\profilereader.obj:(?dtor$12@?0???0ProFileReader@QtSupport@@QEAA@PEAVQMakeGlobals@@PEAVQMakeVfs@@@Z@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:87
>>>               debug\profilereader.obj:(??1ProFileReader@QtSupport@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:87
>>>               debug\profilereader.obj:(?dtor$10@?0???1ProFileReader@QtSupport@@UEAA@XZ@4HA)

lld-link: error: undefined symbol: ??0ProFileCache@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:143
>>>               debug\profilereader.obj:(?cache@ProFileCacheManager@QtSupport@@QEAAPEAVProFileCache@@XZ)

lld-link: error: undefined symbol: ??1ProFile@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\proparser\proitems.h:523
>>>               debug\profilereader.obj:(?deref@ProFile@@QEAAXXZ)

lld-link: error: undefined symbol: ??1ProFileCache@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:152
>>>               debug\profilereader.obj:(?clear@ProFileCacheManager@QtSupport@@AEAAXXZ)

lld-link: error: undefined symbol: ?discardFiles@ProFileCache@@QEAAXAEBVQString@@PEAVQMakeVfs@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:157
>>>               debug\profilereader.obj:(?discardFiles@ProFileCacheManager@QtSupport@@QEAAXAEBVQString@@PEAVQMakeVfs@@@Z)

lld-link: error: undefined symbol: ?discardFile@ProFileCache@@QEAAXAEBVQString@@PEAVQMakeVfs@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\profilereader.cpp:161
>>>               debug\profilereader.obj:(?discardFile@ProFileCacheManager@QtSupport@@QEAAXAEBVQString@@PEAVQMakeVfs@@@Z)

lld-link: error: undefined symbol: ?uicCommand@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\uicgenerator.cpp:63
>>>               debug\uicgenerator.obj:(?command@UicGenerator@QtSupport@@MEBA?AVFilePath@Utils@@XZ)

lld-link: error: undefined symbol: ?qscxmlcCommand@BaseQtVersion@QtSupport@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\qscxmlcgenerator.cpp:83
>>>               debug\qscxmlcgenerator.obj:(?command@QScxmlcGenerator@QtSupport@@MEBA?AVFilePath@Utils@@XZ)

lld-link: error: undefined symbol: ?setTypeIdsSuffix@JsonWizardPageFactory@ProjectExplorer@@IEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:73
>>>               debug\translationwizardpage.obj:(??0TranslationWizardPageFactory@Internal@QtSupport@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcsconfigurationpage.cpp:51
>>>               debug\vcsconfigurationpage.obj:(??0VcsConfigurationPageFactory@Internal@VcsBase@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:66
>>>               debug\vcscommandpage.obj:(??0VcsCommandPageFactory@Internal@VcsBase@@QEAA@XZ)

lld-link: error: undefined symbol: ??1JsonWizardPageFactory@ProjectExplorer@@UEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:74
>>>               debug\translationwizardpage.obj:(?dtor$4@?0???0TranslationWizardPageFactory@Internal@QtSupport@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.h:33
>>>               debug\translationwizardpage.obj:(??1TranslationWizardPageFactory@Internal@QtSupport@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcsconfigurationpage.cpp:52
>>>               debug\vcsconfigurationpage.obj:(?dtor$4@?0???0VcsConfigurationPageFactory@Internal@VcsBase@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcsconfigurationpage.h:42
>>>               debug\vcsconfigurationpage.obj:(??1VcsConfigurationPageFactory@Internal@VcsBase@@UEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:67
>>>               debug\vcscommandpage.obj:(?dtor$4@?0???0VcsCommandPageFactory@Internal@VcsBase@@QEAA@XZ@4HA)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.h:38
>>>               debug\vcscommandpage.obj:(??1VcsCommandPageFactory@Internal@VcsBase@@UEAA@XZ)

lld-link: error: undefined symbol: ?stringValue@JsonWizard@ProjectExplorer@@QEBA?AVQString@@AEBV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:158
>>>               debug\translationwizardpage.obj:(?updateLineEdit@TranslationWizardPage@Internal@QtSupport@@AEAAXXZ)

lld-link: error: undefined symbol: ?expander@JsonWizard@ProjectExplorer@@QEAAPEAVMacroExpander@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:131
>>>               debug\translationwizardpage.obj:(?initializePage@TranslationWizardPage@Internal@QtSupport@@EEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcsconfigurationpage.cpp:147
>>>               debug\vcsconfigurationpage.obj:(?initializePage@VcsConfigurationPage@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:230
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:254
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:263
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:271
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:280
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:285
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:297
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:299
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)
>>> referenced 2 more times

lld-link: error: undefined symbol: ?setValue@JsonWizard@ProjectExplorer@@QEAAXAEBVQString@@AEBVQVariant@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:146
>>>               debug\translationwizardpage.obj:(?validatePage@TranslationWizardPage@Internal@QtSupport@@EEAA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qtsupport\translationwizardpage.cpp:149
>>>               debug\translationwizardpage.obj:(?validatePage@TranslationWizardPage@Internal@QtSupport@@EEAA_NXZ)

lld-link: error: undefined symbol: ?setWindowTitleVcsTopicHandler@EditorManager@Core@@SAXV?$function@$$A6A?AVQString@@AEBV1@@Z@std@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:217
>>>               debug\vcsbaseplugin.obj:(??0StateListener@Internal@VcsBase@@QEAA@PEAVQObject@@@Z)

lld-link: error: undefined symbol: ?instance@VcsPlugin@Internal@VcsBase@@SAPEAV123@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:484
>>>               debug\vcsbaseplugin.obj:(??0VcsBasePluginPrivate@VcsBase@@IEAA@AEBVContext@Core@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:680
>>>               debug\vcsbaseplugin.obj:(?sshPrompt@VcsBase@@YA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:194
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:222
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:269
>>>               debug\vcsbasesubmiteditor.obj:(?createUserFields@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:537
>>>               debug\vcsbasesubmiteditor.obj:(?promptForNickName@VcsBaseSubmitEditor@VcsBase@@AEAA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:123
>>>               debug\vcsbasesubmiteditor.obj:(?submitMessageCheckScript@VcsBase@@YA?AVQString@@XZ)

lld-link: error: undefined symbol: ?submitEditorAboutToClose@VcsPlugin@Internal@VcsBase@@QEAAXPEAVVcsBaseSubmitEditor@3@PEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:485
>>>               debug\vcsbaseplugin.obj:(??0VcsBasePluginPrivate@VcsBase@@IEAA@AEBVContext@Core@@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@VcsPlugin@Internal@VcsBase@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbaseplugin.obj:(??$connect@P8VcsPlugin@Internal@VcsBase@@EAAXPEAVVcsBaseSubmitEditor@3@PEA_N@ZP8VcsBasePluginPrivate@3@EAAX01@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVVcsPlugin@Internal@VcsBase@@P8345@EAAXPEAVVcsBaseSubmitEditor@5@PEA_N@ZPEBVVcsBasePluginPrivate@5@P875@EAAX12@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbasesubmiteditor.obj:(??$connect@P8VcsPlugin@Internal@VcsBase@@EAAXAEBVCommonVcsSettings@23@@ZP8VcsBaseSubmitEditor@3@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVVcsPlugin@Internal@VcsBase@@P8345@EAAXAEBVCommonVcsSettings@45@@ZPEBVVcsBaseSubmitEditor@5@P875@EAAX1@ZW4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?saveAllModifiedDocuments@DocumentManager@Core@@SA_NAEBVQString@@PEA_N01PEAV?$QList@PEAVIDocument@Core@@@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:566
>>>               debug\vcsbaseplugin.obj:(?promptBeforeCommit@VcsBasePluginPrivate@VcsBase@@IEAA_NXZ)

lld-link: error: undefined symbol: ?settings@VcsPlugin@Internal@VcsBase@@QEBA?AVCommonVcsSettings@23@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseplugin.cpp:680
>>>               debug\vcsbaseplugin.obj:(?sshPrompt@VcsBase@@YA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:194
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:123
>>>               debug\vcsbasesubmiteditor.obj:(?submitMessageCheckScript@VcsBase@@YA?AVQString@@XZ)

lld-link: error: undefined symbol: ?addTask@ShellCommand@Core@@MEAAXAEAV?$QFuture@X@@@Z
>>> referenced by debug\vcsbaseplugin.obj:(??_7ShellCommand@Core@@6B@)
>>> referenced by debug\vcscommand.obj:(??_7VcsCommand@VcsBase@@6B@)
>>> referenced by debug\vcsbaseclient.obj

lld-link: error: undefined symbol: ?coreAboutToClose@ShellCommand@Core@@MEAAXXZ
>>> referenced by debug\vcsbaseplugin.obj:(??_7ShellCommand@Core@@6B@)
>>> referenced by debug\vcscommand.obj
>>> referenced by debug\vcsbaseclient.obj

lld-link: error: undefined symbol: ?staticMetaObject@JsonWizard@ProjectExplorer@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:524
>>>               debug\vcsconfigurationpage.obj:(??$qobject_cast@PEAVJsonWizard@ProjectExplorer@@@@YAPEAVJsonWizard@ProjectExplorer@@PEAVQObject@@@Z)
>>> referenced by debug\vcscommandpage.obj

lld-link: error: undefined symbol: ?boolFromVariant@JsonWizard@ProjectExplorer@@SA_NAEBVQVariant@@PEAVMacroExpander@Utils@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\wizard\vcscommandpage.cpp:297
>>>               debug\vcscommandpage.obj:(?delayedInitialize@VcsCommandPage@Internal@VcsBase@@AEAAXXZ)

lld-link: error: undefined symbol: ?OtherSelection@TextEditorWidget@TextEditor@@2VId@Utils@@A
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:276
>>>               debug\vcsbaseeditor.obj:(?highlightCurrentContents@ChangeTextCursorHandler@Internal@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:447
>>>               debug\vcsbaseeditor.obj:(?highlightCurrentContents@UrlTextCursorHandler@Internal@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:990
>>>               debug\vcsbaseeditor.obj:(?mouseMoveEvent@VcsBaseEditorWidget@VcsBase@@MEAAXPEAVQMouseEvent@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:365
>>>               debug\sidebysidediffeditorwidget.obj:(?clearAll@SideDiffEditorWidget@Internal@DiffEditor@@QEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?setCodeFoldingSupported@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:737
>>>               debug\vcsbaseeditor.obj:(?init@VcsBaseEditorWidget@VcsBase@@UEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditor.cpp:104
>>>               debug\diffeditor.obj:(??0DescriptionEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:179
>>>               debug\sidebysidediffeditorwidget.obj:(??0SideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:83
>>>               debug\unifieddiffeditorwidget.obj:(??0UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z)

lld-link: error: undefined symbol: ?setRevisionsVisible@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:741
>>>               debug\vcsbaseeditor.obj:(?init@VcsBaseEditorWidget@VcsBase@@UEAAXXZ)

lld-link: error: undefined symbol: ?finished@ShellCommand@Utils@@QEAAX_NHAEBVQVariant@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1334
>>>               debug\vcsbaseeditor.obj:(?setCommand@VcsBaseEditorWidget@VcsBase@@QEAAXPEAVVcsCommand@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:68
>>>               debug\vcscommand.obj:(??0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:459
>>>               debug\vcsbaseclient.obj:(?status@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@0AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:574
>>>               debug\vcsbaseclient.obj:(?commit@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@01@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasediffeditorcontroller.cpp:117
>>>               debug\vcsbasediffeditorcontroller.obj:(??0VcsCommandResultProxy@VcsBase@@QEAA@PEAVVcsCommand@1@PEAVVcsBaseDiffEditorControllerPrivate@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:261
>>>               debug\shellcommand.obj:(?run@ShellCommand@Utils@@AEAAXAEAV?$QFutureInterface@X@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommandpage.cpp:92
>>>               debug\shellcommandpage.obj:(?start@ShellCommandPage@Utils@@QEAAXPEAVShellCommand@2@@Z)

lld-link: error: undefined symbol: ?firstVisibleBlockNumber@TextEditorWidget@TextEditor@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1251
>>>               debug\vcsbaseeditor.obj:(?lineNumberOfCurrentEditor@VcsBaseEditor@VcsBase@@SAHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?lastVisibleBlockNumber@TextEditorWidget@TextEditor@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1252
>>>               debug\vcsbaseeditor.obj:(?lineNumberOfCurrentEditor@VcsBaseEditor@VcsBase@@SAHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?centerVisibleBlockNumber@TextEditorWidget@TextEditor@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseeditor.cpp:1254
>>>               debug\vcsbaseeditor.obj:(?lineNumberOfCurrentEditor@VcsBaseEditor@VcsBase@@SAHAEBVQString@@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@ShellCommand@Utils@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbaseeditor.obj:(??$connect@P8ShellCommand@Utils@@EAAX_NHAEBVQVariant@@@ZP8VcsBaseEditorWidget@VcsBase@@EAAX0H1@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAX_NHAEBVQVariant@@@ZPEBVVcsBaseEditorWidget@VcsBase@@P867@EAAX1H2@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\vcscommand.obj:(??$connect@P8ShellCommand@Utils@@EAAXXZV<lambda_1>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAXXZPEBV0@V<lambda_1>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\vcscommand.obj:(??$connect@P8ShellCommand@Utils@@EAAX_NHAEBVQVariant@@@ZV<lambda_2>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAX_NHAEBVQVariant@@@ZPEBV0@V<lambda_2>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\vcsbaseclient.obj:(??$connect@P8ShellCommand@Utils@@EAAX_NHAEBVQVariant@@@ZV<lambda_2>@?0??commit@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@23@Z@@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAX_NHAEBVQVariant@@@ZPEBV0@V<lambda_2>@?0??commit@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@56@Z@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbaseclient.obj:(??$connect@P8ShellCommand@Utils@@EAAXAEBVQString@@@ZP8VcsBaseEditorWidget@VcsBase@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAXAEBVQString@@@ZPEBVVcsBaseEditorWidget@VcsBase@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbaseclient.obj:(??$connect@P8ShellCommand@Utils@@EAAXAEBVQVariant@@@ZP8VcsBaseClient@VcsBase@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAXAEBVQVariant@@@ZPEBVVcsBaseClient@VcsBase@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:304
>>>               debug\vcsbaseclient.obj:(??$connect@P8ShellCommand@Utils@@EAAX_NHAEBVQVariant@@@ZP6AXXZ@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAX_NHAEBVQVariant@@@ZPEBV0@P6AXXZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbaseclient.obj:(??$connect@P8ShellCommand@Utils@@EAAXAEBVQString@@@ZP8VcsBaseClient@VcsBase@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAXAEBVQString@@@ZPEBVVcsBaseClient@VcsBase@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbasediffeditorcontroller.obj:(??$connect@P8ShellCommand@Utils@@EAAXAEBVQString@@@ZP8VcsCommandResultProxy@VcsBase@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAXAEBVQString@@@ZPEBVVcsCommandResultProxy@VcsBase@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:264
>>>               debug\vcsbasediffeditorcontroller.obj:(??$connect@P8ShellCommand@Utils@@EAAX_NHAEBVQVariant@@@ZP8VcsCommandResultProxy@VcsBase@@EAAX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVShellCommand@Utils@@P834@EAAX_NHAEBVQVariant@@@ZPEBVVcsCommandResultProxy@VcsBase@@P867@EAAX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced 6 more times

lld-link: error: undefined symbol: ?descriptionEdit@SubmitEditorWidget@VcsBase@@QEBAPEAVCompletingTextEdit@Utils@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:150
>>>               debug\vcsbasesubmiteditor.obj:(??0VcsBaseSubmitEditorPrivate@VcsBase@@QEAA@PEAVSubmitEditorWidget@1@PEAVVcsBaseSubmitEditor@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:151
>>>               debug\vcsbasesubmiteditor.obj:(??0VcsBaseSubmitEditorPrivate@VcsBase@@QEAA@PEAVSubmitEditorWidget@1@PEAVVcsBaseSubmitEditor@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:170
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:547
>>>               debug\vcsbasesubmiteditor.obj:(?slotInsertNickName@VcsBaseSubmitEditor@VcsBase@@AEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:401
>>>               debug\vcsbasesubmiteditor.obj:(?setFileModel@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z)

lld-link: error: undefined symbol: ?addDescriptionEditContextMenuAction@SubmitEditorWidget@VcsBase@@QEAAXPEAVQAction@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:200
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:206
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:213
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)

lld-link: error: undefined symbol: ?settingsChanged@VcsPlugin@Internal@VcsBase@@QEAAXAEBVCommonVcsSettings@23@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:222
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)

lld-link: error: undefined symbol: ??0BaseTextFind@Core@@QEAA@PEAVQTextEdit@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:234
>>>               debug\vcsbasesubmiteditor.obj:(?setParameters@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVVcsBaseSubmitEditorParameters@2@@Z)

lld-link: error: undefined symbol: ?nickNameModel@VcsPlugin@Internal@VcsBase@@QEAAPEAVQStandardItemModel@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:269
>>>               debug\vcsbasesubmiteditor.obj:(?createUserFields@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:537
>>>               debug\vcsbasesubmiteditor.obj:(?promptForNickName@VcsBaseSubmitEditor@VcsBase@@AEAA?AVQString@@XZ)

lld-link: error: undefined symbol: ?nickNameList@NickNameDialog@Internal@VcsBase@@SA?AVQStringList@@PEBVQStandardItemModel@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:271
>>>               debug\vcsbasesubmiteditor.obj:(?createUserFields@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?addSubmitFieldWidget@SubmitEditorWidget@VcsBase@@QEAAXPEAVSubmitFieldWidget@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:281
>>>               debug\vcsbasesubmiteditor.obj:(?createUserFields@VcsBaseSubmitEditor@VcsBase@@AEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?setLineWrapWidth@SubmitEditorWidget@VcsBase@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:321
>>>               debug\vcsbasesubmiteditor.obj:(?setLineWrapWidth@VcsBaseSubmitEditor@VcsBase@@QEAAXH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:189
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setLineWrap@SubmitEditorWidget@VcsBase@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:314
>>>               debug\vcsbasesubmiteditor.obj:(?setLineWrap@VcsBaseSubmitEditor@VcsBase@@QEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:188
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?submitFieldWidgets@SubmitEditorWidget@VcsBase@@QEBA?AV?$QList@PEAVSubmitFieldWidget@VcsBase@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:551
>>>               debug\vcsbasesubmiteditor.obj:(?slotSetFieldNickName@VcsBaseSubmitEditor@VcsBase@@AEAAXH@Z)

lld-link: error: undefined symbol: ?registerActions@SubmitEditorWidget@VcsBase@@QEAAXPEAVQAction@@000@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:288
>>>               debug\vcsbasesubmiteditor.obj:(?registerActions@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVQAction@@000@Z)

lld-link: error: undefined symbol: ?fileListSelectionMode@SubmitEditorWidget@VcsBase@@QEBA?AW4SelectionMode@QAbstractItemView@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:296
>>>               debug\vcsbasesubmiteditor.obj:(?fileListSelectionMode@VcsBaseSubmitEditor@VcsBase@@QEBA?AW4SelectionMode@QAbstractItemView@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:174
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setFileListSelectionMode@SubmitEditorWidget@VcsBase@@QEAAXW4SelectionMode@QAbstractItemView@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:301
>>>               debug\vcsbasesubmiteditor.obj:(?setFileListSelectionMode@VcsBaseSubmitEditor@VcsBase@@QEAAXW4SelectionMode@QAbstractItemView@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:187
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?isEmptyFileListEnabled@SubmitEditorWidget@VcsBase@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:305
>>>               debug\vcsbasesubmiteditor.obj:(?isEmptyFileListEnabled@VcsBaseSubmitEditor@VcsBase@@QEBA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:178
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setEmptyFileListEnabled@SubmitEditorWidget@VcsBase@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:309
>>>               debug\vcsbasesubmiteditor.obj:(?setEmptyFileListEnabled@VcsBaseSubmitEditor@VcsBase@@QEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:191
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?lineWrap@SubmitEditorWidget@VcsBase@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:312
>>>               debug\vcsbasesubmiteditor.obj:(?lineWrap@VcsBaseSubmitEditor@VcsBase@@QEBA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:175
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?lineWrapWidth@SubmitEditorWidget@VcsBase@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:317
>>>               debug\vcsbasesubmiteditor.obj:(?lineWrapWidth@VcsBaseSubmitEditor@VcsBase@@QEBAHXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:176
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?checkedFiles@SubmitEditorWidget@VcsBase@@QEBA?AVQStringList@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:362
>>>               debug\vcsbasesubmiteditor.obj:(?checkedFiles@VcsBaseSubmitEditor@VcsBase@@QEBA?AVQStringList@@XZ)

lld-link: error: undefined symbol: ?fileModel@SubmitEditorWidget@VcsBase@@QEBAPEAVSubmitFileModel@2@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:378
>>>               debug\vcsbasesubmiteditor.obj:(?setFileModel@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:409
>>>               debug\vcsbasesubmiteditor.obj:(?fileModel@VcsBaseSubmitEditor@VcsBase@@QEBAPEAVSubmitFileModel@2@XZ)

lld-link: error: undefined symbol: ?selectedRows@SubmitEditorWidget@VcsBase@@QEBA?AV?$QList@H@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:382
>>>               debug\vcsbasesubmiteditor.obj:(?setFileModel@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z)

lld-link: error: undefined symbol: ?setFileModel@SubmitEditorWidget@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:384
>>>               debug\vcsbasesubmiteditor.obj:(?setFileModel@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z)

lld-link: error: undefined symbol: ?setSelectedRows@SubmitEditorWidget@VcsBase@@QEAAXAEBV?$QList@H@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:386
>>>               debug\vcsbasesubmiteditor.obj:(?setFileModel@VcsBaseSubmitEditor@VcsBase@@QEAAXPEAVSubmitFileModel@2@@Z)

lld-link: error: undefined symbol: ?descriptionText@SubmitEditorWidget@VcsBase@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:439
>>>               debug\vcsbasesubmiteditor.obj:(?description@VcsBaseSubmitEditor@VcsBase@@IEBA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:173
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setDescriptionText@SubmitEditorWidget@VcsBase@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:443
>>>               debug\vcsbasesubmiteditor.obj:(?setDescription@VcsBaseSubmitEditor@VcsBase@@IEAAXAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:186
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?isDescriptionMandatory@SubmitEditorWidget@VcsBase@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:447
>>>               debug\vcsbasesubmiteditor.obj:(?isDescriptionMandatory@VcsBaseSubmitEditor@VcsBase@@IEBA_NXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:177
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?setDescriptionMandatory@SubmitEditorWidget@VcsBase@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:451
>>>               debug\vcsbasesubmiteditor.obj:(?setDescriptionMandatory@VcsBaseSubmitEditor@VcsBase@@IEAAX_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:190
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ??0NickNameDialog@Internal@VcsBase@@QEAA@PEAVQStandardItemModel@@PEAVQWidget@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:537
>>>               debug\vcsbasesubmiteditor.obj:(?promptForNickName@VcsBaseSubmitEditor@VcsBase@@AEAA?AVQString@@XZ)

lld-link: error: undefined symbol: ?nickName@NickNameDialog@Internal@VcsBase@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasesubmiteditor.cpp:540
>>>               debug\vcsbasesubmiteditor.obj:(?promptForNickName@VcsBaseSubmitEditor@VcsBase@@AEAA?AVQString@@XZ)

lld-link: error: undefined symbol: ?setDuplicatedSupported@TextEditorFactory@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:64
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ?setMarksVisible@TextEditorFactory@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\basevcseditorfactory.cpp:84
>>>               debug\basevcseditorfactory.obj:(??0VcsEditorFactory@VcsBase@@QEAA@PEBVVcsBaseEditorParameters@1@V?$function@$$A6APEAVQWidget@@XZ@std@@V?$function@$$A6AXAEBVQString@@0@Z@4@@Z)

lld-link: error: undefined symbol: ??0ShellCommand@Core@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:45
>>>               debug\vcscommand.obj:(??0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z)

lld-link: error: undefined symbol: ?started@ShellCommand@Utils@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:64
>>>               debug\vcscommand.obj:(??0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:235
>>>               debug\shellcommand.obj:(?run@ShellCommand@Utils@@AEAAXAEAV?$QFutureInterface@X@@@Z)

lld-link: error: undefined symbol: ?append@OutputProxy@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:49
>>>               debug\vcscommand.obj:(??R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:335
>>>               debug\shellcommand.obj:(?runFullySynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:342
>>>               debug\shellcommand.obj:(?runFullySynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:383
>>>               debug\shellcommand.obj:(??R<lambda_2>@?0??runSynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@3@AEBVCommandLine@3@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z@QEBA?A?<auto>@@2@Z)

lld-link: error: undefined symbol: ?appendSilently@OutputProxy@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:51
>>>               debug\vcscommand.obj:(??R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:340
>>>               debug\shellcommand.obj:(?runFullySynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)

lld-link: error: undefined symbol: ?appendError@OutputProxy@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:53
>>>               debug\vcscommand.obj:(??R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:307
>>>               debug\shellcommand.obj:(?runCommand@ShellCommand@Utils@@UEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:371
>>>               debug\shellcommand.obj:(??R<lambda_1>@?0??runSynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@3@AEBVCommandLine@3@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z@QEBA?A?<auto>@@2@Z)

lld-link: error: undefined symbol: ?appendCommand@OutputProxy@Utils@@QEAAXAEBVQString@@AEBVCommandLine@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:55
>>>               debug\vcscommand.obj:(??R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:290
>>>               debug\shellcommand.obj:(?runCommand@ShellCommand@Utils@@UEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)

lld-link: error: undefined symbol: ?appendMessage@OutputProxy@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcscommand.cpp:57
>>>               debug\vcscommand.obj:(??R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@AEBVQString@@AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:304
>>>               debug\shellcommand.obj:(?runCommand@ShellCommand@Utils@@UEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)

lld-link: error: undefined symbol: ?staticMetaObject@OutputProxy@Utils@@2UQMetaObject@@B
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:343
>>>               debug\vcscommand.obj:(??$connect@P8OutputProxy@Utils@@EAAXAEBVQString@@@ZV<lambda_1>@?0???R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@0AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ@@QObject@@SA?AVConnection@QMetaObject@@PEBVOutputProxy@Utils@@P834@EAAXAEBVQString@@@ZPEBV0@V<lambda_1>@?0???R<lambda_0>@?0???0VcsCommand@VcsBase@@QEAA@1AEBVQProcessEnvironment@@@Z@QEBA?A?<auto>@@XZ@W4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:304
>>>               debug\vcscommand.obj:(??$connect@P8OutputProxy@Utils@@EAAXAEBVQString@@@ZP6AX0@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVOutputProxy@Utils@@P834@EAAXAEBVQString@@@ZPEBV0@P6AX1@ZW4ConnectionType@Qt@@@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qobject.h:304
>>>               debug\vcscommand.obj:(??$connect@P8OutputProxy@Utils@@EAAXAEBVQString@@AEBVCommandLine@2@@ZP6AX01@Z@QObject@@SA?AVConnection@QMetaObject@@PEBVOutputProxy@Utils@@P834@EAAXAEBVQString@@AEBVCommandLine@4@@ZPEBV0@P6AX12@ZW4ConnectionType@Qt@@@Z)

lld-link: error: undefined symbol: ?metaObject@OutputProxy@Utils@@UEBAPEBUQMetaObject@@XZ
>>> referenced by debug\vcscommand.obj:(??_7OutputProxy@Utils@@6B@)
>>> referenced by debug\shellcommand.obj

lld-link: error: undefined symbol: ?qt_metacast@OutputProxy@Utils@@UEAAPEAXPEBD@Z
>>> referenced by debug\vcscommand.obj:(??_7OutputProxy@Utils@@6B@)
>>> referenced by debug\shellcommand.obj

lld-link: error: undefined symbol: ?qt_metacall@OutputProxy@Utils@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by debug\vcscommand.obj:(??_7OutputProxy@Utils@@6B@)
>>> referenced by debug\shellcommand.obj

lld-link: error: undefined symbol: ?stdOutText@ShellCommand@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:101
>>>               debug\vcsbaseclient.obj:(?createCommand@VcsBaseClientImpl@VcsBase@@QEBAPEAVVcsCommand@2@AEBVQString@@PEAVVcsBaseEditorWidget@2@W4JobOutputBindMode@12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:469
>>>               debug\vcsbaseclient.obj:(?emitParsedStatus@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbasediffeditorcontroller.cpp:115
>>>               debug\vcsbasediffeditorcontroller.obj:(??0VcsCommandResultProxy@VcsBase@@QEAA@PEAVVcsCommand@1@PEAVVcsBaseDiffEditorControllerPrivate@1@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:257
>>>               debug\shellcommand.obj:(?run@ShellCommand@Utils@@AEAAXAEAV?$QFutureInterface@X@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:385
>>>               debug\shellcommand.obj:(??R<lambda_2>@?0??runSynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@3@AEBVCommandLine@3@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z@QEBA?A?<auto>@@2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommandpage.cpp:84
>>>               debug\shellcommandpage.obj:(?start@ShellCommandPage@Utils@@QEAAXPEAVShellCommand@2@@Z)

lld-link: error: undefined symbol: ?toolBar@TextEditorWidget@TextEditor@@QEAAPEAVQToolBar@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:363
>>>               debug\vcsbaseclient.obj:(?diff@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@1@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:404
>>>               debug\vcsbaseclient.obj:(?log@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@AEBVQStringList@@1_N@Z)

lld-link: error: undefined symbol: ?success@ShellCommand@Utils@@QEAAXAEBVQVariant@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:435
>>>               debug\vcsbaseclient.obj:(?revertFile@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@00AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:448
>>>               debug\vcsbaseclient.obj:(?revertAll@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@0AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\vcsbase\vcsbaseclient.cpp:553
>>>               debug\vcsbaseclient.obj:(?update@VcsBaseClient@VcsBase@@UEAAXAEBVQString@@0AEBVQStringList@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:263
>>>               debug\shellcommand.obj:(?run@ShellCommand@Utils@@AEAAXAEAV?$QFutureInterface@X@@@Z)

lld-link: error: undefined symbol: ?clearUniqueId@EditorManager@Core@@SAXPEAVIDocument@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditordocument.cpp:237
>>>               debug\diffeditordocument.obj:(?save@DiffEditorDocument@Internal@DiffEditor@@UEAA_NPEAVQString@@AEBV4@_N@Z)

lld-link: error: undefined symbol: ?saveDocument@EditorManager@Core@@SA_NPEAVIDocument@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditordocument.cpp:308
>>>               debug\diffeditordocument.obj:(?selectEncoding@DiffEditorDocument@Internal@DiffEditor@@QEAA_NXZ)

lld-link: error: undefined symbol: ?reload@TextDocument@TextEditor@@QEAA_NPEAVQString@@AEBV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\diffeditorwidgetcontroller.cpp:195
>>>               debug\diffeditorwidgetcontroller.obj:(?patch@DiffEditorWidgetController@Internal@DiffEditor@@AEAAX_NHH@Z)

lld-link: error: undefined symbol: ?saveState@TextEditorWidget@TextEditor@@QEBA?AVQByteArray@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:186
>>>               debug\sidebysidediffeditorwidget.obj:(?saveState@SideDiffEditorWidget@Internal@DiffEditor@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\unifieddiffeditorwidget.cpp:105
>>>               debug\unifieddiffeditorwidget.obj:(?saveState@UnifiedDiffEditorWidget@Internal@DiffEditor@@QEAAXXZ)

lld-link: error: undefined symbol: ?convertToPlainText@TextEditorWidget@TextEditor@@KA?AVQString@@AEBV3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:286
>>>               debug\sidebysidediffeditorwidget.obj:(?plainTextFromSelection@SideDiffEditorWidget@Internal@DiffEditor@@MEBA?AVQString@@AEBVQTextCursor@@@Z)

lld-link: error: undefined symbol: ?setBlockSelection@TextEditorWidget@TextEditor@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:362
>>>               debug\sidebysidediffeditorwidget.obj:(?clearAll@SideDiffEditorWidget@Internal@DiffEditor@@QEAAXAEBVQString@@@Z)

lld-link: error: undefined symbol: ?highlightScrollBarController@TextEditorWidget@TextEditor@@QEBAPEAVHighlightScrollBarController@Core@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:660
>>>               debug\sidebysidediffeditorwidget.obj:(??R<lambda_1>@?0???0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?setScrollArea@HighlightScrollBarController@Core@@QEAAXPEAVQAbstractScrollArea@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\diffeditor\sidebysidediffeditorwidget.cpp:662
>>>               debug\sidebysidediffeditorwidget.obj:(??R<lambda_1>@?0???0SideBySideDiffEditorWidget@Internal@DiffEditor@@QEAA@PEAVQWidget@@@Z@QEBA?A?<auto>@@XZ)

lld-link: error: undefined symbol: ?useCommonSymbolPaths@SymbolPathsDialog@Internal@Debugger@@SA_NAEA_N0AEAVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\debugger\shared\cdbsymbolpathlisteditor.cpp:171
>>>               debug\cdbsymbolpathlisteditor.obj:(?setupSymbolPaths@CdbSymbolPathListEditor@Internal@Debugger@@AEAAXXZ)

lld-link: error: undefined symbol: ?terminate@ShellCommand@Utils@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:203
>>>               debug\shellcommand.obj:(?cancel@ShellCommand@Utils@@QEAAXXZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:354
>>>               debug\shellcommand.obj:(?runSynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@2@AEBVCommandLine@2@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z)

lld-link: error: undefined symbol: ?stdErrText@ShellCommand@Utils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:258
>>>               debug\shellcommand.obj:(?run@ShellCommand@Utils@@AEAAXAEAV?$QFutureInterface@X@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommand.cpp:372
>>>               debug\shellcommand.obj:(??R<lambda_1>@?0??runSynchronous@ShellCommand@Utils@@AEAA?AVSynchronousProcessResponse@3@AEBVCommandLine@3@V?$QSharedPointer@VOutputProxy@Utils@@@@HAEBVQString@@AEBV?$function@$$A6A?AW4Result@SynchronousProcessResponse@Utils@@H@Z@std@@@Z@QEBA?A?<auto>@@2@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\utils\shellcommandpage.cpp:88
>>>               debug\shellcommandpage.obj:(?start@ShellCommandPage@Utils@@QEAAXPEAVShellCommand@2@@Z)

lld-link: error: undefined symbol: ?metaObject@ShellCommand@Utils@@UEBAPEBUQMetaObject@@XZ
>>> referenced by debug\shellcommand.obj:(??_7ShellCommand@Utils@@6B@)

lld-link: error: undefined symbol: ?qt_metacast@ShellCommand@Utils@@UEAAPEAXPEBD@Z
>>> referenced by debug\shellcommand.obj:(??_7ShellCommand@Utils@@6B@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_shellcommand.cpp:86
>>>               debug\moc_shellcommand.obj:(?qt_metacast@ShellCommand@Core@@UEAAPEAXPEBD@Z)

lld-link: error: undefined symbol: ?qt_metacall@ShellCommand@Utils@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by debug\shellcommand.obj:(??_7ShellCommand@Utils@@6B@)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_shellcommand.cpp:91
>>>               debug\moc_shellcommand.obj:(?qt_metacall@ShellCommand@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ??0ComponentVersion@LanguageUtils@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:126
>>>               debug\qmldirparser.obj:(??R<lambda_0>@?0??parse@QmlDirParser@@QEAA_NAEBVQString@@@Z@QEBA?A?<auto>@@PEBV3@HV?$QFlags@W4Flag@Import@QmlDirParser@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:129
>>>               debug\qmldirparser.obj:(??R<lambda_0>@?0??parse@QmlDirParser@@QEAA_NAEBVQString@@@Z@QEBA?A?<auto>@@PEBV3@HV?$QFlags@W4Flag@Import@QmlDirParser@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser_p.h:135
>>>               debug\qmldirparser.obj:(??0Import@QmlDirParser@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsbind.cpp:174
>>>               debug\qmljsbind.obj:(?endVisit@Bind@QmlJS@@MEAAXPEAVUiProgram@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsbind.cpp:180
>>>               debug\qmljsbind.obj:(?visit@Bind@QmlJS@@MEAA_NPEAVUiImport@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:44
>>>               debug\qmljsfindexportedcpptypes.obj:(??0ExportedQmlType@?A0x81E322E8@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:676
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:195
>>>               debug\qmljsdocument.obj:(?importFile@CollectDirectives@?A0xC5EDBE12@@UEAAXAEBVQString@@0HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1236
>>>               debug\qmljsinterpreter.obj:(?objectByCppName@CppQmlTypes@QmlJS@@QEBAPEBVCppComponentValue@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1146
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced 20 more times

lld-link: error: undefined symbol: ?isValid@ComponentVersion@LanguageUtils@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:132
>>>               debug\qmldirparser.obj:(??R<lambda_0>@?0??parse@QmlDirParser@@QEAA_NAEBVQString@@@Z@QEBA?A?<auto>@@PEBV3@HV?$QFlags@W4Flag@Import@QmlDirParser@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsbind.cpp:192
>>>               debug\qmljsbind.obj:(?visit@Bind@QmlJS@@MEAA_NPEAVUiImport@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1129
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:432
>>>               debug\qmljslink.obj:(?importNonFile@LinkPrivate@QmlJS@@QEAA?AVImport@2@AEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVImportInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:493
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:533
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:588
>>>               debug\qmljslink.obj:(?importLibrary@LinkPrivate@QmlJS@@QEAA_NAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@AEBVQString@@PEAVImport@2@PEAVObjectValue@2@1_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:384
>>>               debug\qmljslink.obj:(?findBestModuleApi@QmlJS@@YA?AVModuleApiInfo@1@AEBV?$QList@VModuleApiInfo@QmlJS@@@@AEBVComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:624
>>>               debug\qmljslink.obj:(?loadQmldirComponents@LinkPrivate@QmlJS@@QEAAXPEAVObjectValue@2@VComponentVersion@LanguageUtils@@AEBVLibraryInfo@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsmodelmanagerinterface.cpp:796
>>>               debug\qmljsmodelmanagerinterface.obj:(?modulePath@QmlJS@@YA?AVQString@@AEBVImportInfo@1@AEBVQStringList@@@Z)
>>> referenced 2 more times

lld-link: error: undefined symbol: ?NoVersion@ComponentVersion@LanguageUtils@@2HB
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:77
>>>               debug\qmldirparser.obj:(?parseImportVersion@@YA?AVComponentVersion@LanguageUtils@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:403
>>>               debug\qmljsdocument.obj:(?insert@Snapshot@QmlJS@@QEAAXAEBV?$QSharedPointer@$$CBVDocument@QmlJS@@@@_N@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:473
>>>               debug\qmljsdocument.obj:(?insertLibraryInfo@Snapshot@QmlJS@@QEAAXAEBVQString@@AEBVLibraryInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:474
>>>               debug\qmljsdocument.obj:(?insertLibraryInfo@Snapshot@QmlJS@@QEAAXAEBVQString@@AEBVLibraryInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:488
>>>               debug\qmljsdocument.obj:(?insertLibraryInfo@Snapshot@QmlJS@@QEAAXAEBVQString@@AEBVLibraryInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:491
>>>               debug\qmljsdocument.obj:(?insertLibraryInfo@Snapshot@QmlJS@@QEAAXAEBVQString@@AEBVLibraryInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsimportdependencies.cpp:132
>>>               debug\qmljsimportdependencies.obj:(??0ImportKey@QmlJS@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsimportdependencies.cpp:132
>>>               debug\qmljsimportdependencies.obj:(??0ImportKey@QmlJS@@QEAA@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsimportdependencies.cpp:429
>>>               debug\qmljsimportdependencies.obj:(?toString@ImportKey@QmlJS@@QEBA?AVQString@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsimportdependencies.cpp:429
>>>               debug\qmljsimportdependencies.obj:(?toString@ImportKey@QmlJS@@QEBA?AVQString@@XZ)

lld-link: error: undefined symbol: ?MaxVersion@ComponentVersion@LanguageUtils@@2HB
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:79
>>>               debug\qmldirparser.obj:(?parseImportVersion@@YA?AVComponentVersion@LanguageUtils@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:85
>>>               debug\qmldirparser.obj:(?parseImportVersion@@YA?AVComponentVersion@LanguageUtils@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1199
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1089
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1089
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:670
>>>               debug\qmljslink.obj:(?loadImplicitDefaultImports@LinkPrivate@QmlJS@@QEAAXPEAVImports@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:625
>>>               debug\qmljslink.obj:(?loadQmldirComponents@LinkPrivate@QmlJS@@QEAAXPEAVObjectValue@2@VComponentVersion@LanguageUtils@@AEBVLibraryInfo@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ??0ComponentVersion@LanguageUtils@@QEAA@HH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:83
>>>               debug\qmldirparser.obj:(?parseImportVersion@@YA?AVComponentVersion@LanguageUtils@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\parser\qmldirparser.cpp:87
>>>               debug\qmldirparser.obj:(?parseImportVersion@@YA?AVComponentVersion@LanguageUtils@@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsbind.cpp:182
>>>               debug\qmljsbind.obj:(?visit@Bind@QmlJS@@MEAA_NPEAVUiImport@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:370
>>>               debug\qmljsfindexportedcpptypes.obj:(?checkForQmlRegisterType@FindExportsVisitor@?A0x81E322E8@@IEAA_NPEAVCallAST@CPlusPlus@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:670
>>>               debug\qmljslink.obj:(?loadImplicitDefaultImports@LinkPrivate@QmlJS@@QEAAXPEAVImports@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:625
>>>               debug\qmljslink.obj:(?loadQmldirComponents@LinkPrivate@QmlJS@@QEAAXPEAVObjectValue@2@VComponentVersion@LanguageUtils@@AEBVLibraryInfo@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:633
>>>               debug\qmljslink.obj:(?loadQmldirComponents@LinkPrivate@QmlJS@@QEAAXPEAVObjectValue@2@VComponentVersion@LanguageUtils@@AEBVLibraryInfo@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljscheck.cpp:693
>>>               debug\qmljscheck.obj:(?visit@Check@QmlJS@@MEAA_NPEAVUiImport@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:101
>>>               debug\qmljstypedescriptionreader.obj:(?readDocument@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiProgram@AST@2@@Z)

lld-link: error: undefined symbol: ?updateFingerprint@FakeMetaObject@LanguageUtils@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:880
>>>               debug\qmljsfindexportedcpptypes.obj:(??RFindExportedCppTypes@QmlJS@@QEAA?AVQStringList@@AEBV?$QSharedPointer@VDocument@CPlusPlus@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:886
>>>               debug\qmljsfindexportedcpptypes.obj:(??RFindExportedCppTypes@QmlJS@@QEAA?AVQStringList@@AEBV?$QSharedPointer@VDocument@CPlusPlus@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:245
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?addExport@FakeMetaObject@LanguageUtils@@QEAAXAEBVQString@@0VComponentVersion@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:766
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildExportedQmlObjects@?A0x81E322E8@@YAXAEAVTypeOfExpression@CPlusPlus@@AEBV?$QList@VExportedQmlType@?A0x81E322E8@@@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@PEAV?$QList@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:676
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:243
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:576
>>>               debug\qmljstypedescriptionreader.obj:(?readExports@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setIsCreatable@FakeMetaObject@LanguageUtils@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:768
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildExportedQmlObjects@?A0x81E322E8@@YAXAEAVTypeOfExpression@CPlusPlus@@AEBV?$QList@VExportedQmlType@?A0x81E322E8@@@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@PEAV?$QList@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:229
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?setIsSingleton@FakeMetaObject@LanguageUtils@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:769
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildExportedQmlObjects@?A0x81E322E8@@YAXAEAVTypeOfExpression@CPlusPlus@@AEBV?$QList@VExportedQmlType@?A0x81E322E8@@@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@PEAV?$QList@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:227
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?setClassName@FakeMetaObject@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:771
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildExportedQmlObjects@?A0x81E322E8@@YAXAEAVTypeOfExpression@CPlusPlus@@AEBV?$QList@VExportedQmlType@?A0x81E322E8@@@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@PEAV?$QList@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:674
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:215
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ??0FakeMetaObject@LanguageUtils@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:668
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:197
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ??0FakeMetaMethod@LanguageUtils@@QEAA@AEBVQString@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:685
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)

lld-link: error: undefined symbol: ?setMethodType@FakeMetaMethod@LanguageUtils@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:688
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:690
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:283
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:285
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?addParameter@FakeMetaMethod@LanguageUtils@@QEAAXAEBVQString@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:695
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:405
>>>               debug\qmljstypedescriptionreader.obj:(?readParameter@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@PEAVFakeMetaMethod@LanguageUtils@@@Z)

lld-link: error: undefined symbol: ?addMethod@FakeMetaObject@LanguageUtils@@QEAAXAEBVFakeMetaMethod@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:697
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:311
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ??0FakeMetaProperty@LanguageUtils@@QEAA@AEBVQString@@0_N11H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:706
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:352
>>>               debug\qmljstypedescriptionreader.obj:(?readProperty@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?addProperty@FakeMetaObject@LanguageUtils@@QEAAXAEBVFakeMetaProperty@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:709
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:352
>>>               debug\qmljstypedescriptionreader.obj:(?readProperty@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ??0FakeMetaEnum@LanguageUtils@@QEAA@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:724
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)

lld-link: error: undefined symbol: ?addKey@FakeMetaEnum@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:728
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:653
>>>               debug\qmljstypedescriptionreader.obj:(?readEnumValues@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@PEAVFakeMetaEnum@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:663
>>>               debug\qmljstypedescriptionreader.obj:(?readEnumValues@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@PEAVFakeMetaEnum@LanguageUtils@@@Z)

lld-link: error: undefined symbol: ?addEnum@FakeMetaObject@LanguageUtils@@QEAAXAEBVFakeMetaEnum@2@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:730
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:375
>>>               debug\qmljstypedescriptionreader.obj:(?readEnum@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setSuperclassName@FakeMetaObject@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsfindexportedcpptypes.cpp:739
>>>               debug\qmljsfindexportedcpptypes.obj:(?buildFakeMetaObject@?A0x81E322E8@@YA?AV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@PEAVClass@CPlusPlus@@PEAV?$QHash@PEAVClass@CPlusPlus@@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@@AEAVTypeOfExpression@3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:217
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?fingerprint@FakeMetaObject@LanguageUtils@@QEBA?AVQByteArray@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:359
>>>               debug\qmljsdocument.obj:(?calculateFingerprint@LibraryInfo@QmlJS@@QEBA?AVQByteArray@@XZ)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsmodelmanagerinterface.cpp:1228
>>>               debug\qmljsmodelmanagerinterface.obj:(?rescanExports@QmlJS@@YA_NAEBVQString@@AEAVFindExportedCppTypes@1@AEAV?$QHash@VQString@@UCppData@ModelManagerInterface@QmlJS@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsmodelmanagerinterface.cpp:1230
>>>               debug\qmljsmodelmanagerinterface.obj:(?rescanExports@QmlJS@@YA_NAEBVQString@@AEAVFindExportedCppTypes@1@AEAV?$QHash@VQString@@UCppData@ModelManagerInterface@QmlJS@@@@@Z)

lld-link: error: undefined symbol: ?addToHash@ComponentVersion@LanguageUtils@@QEBAXAEAVQCryptographicHash@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:569
>>>               debug\qmljsdocument.obj:(?addToHash@ModuleApiInfo@QmlJS@@QEBAXAEAVQCryptographicHash@@@Z)

lld-link: error: undefined symbol: ?exports@FakeMetaObject@LanguageUtils@@QEBA?AV?$QList@VExport@FakeMetaObject@LanguageUtils@@@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:428
>>>               debug\qmljsdocument.obj:(?insertLibraryInfo@Snapshot@QmlJS@@QEAAXAEBVQString@@AEBVLibraryInfo@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1128
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1077
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1077
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsplugindumper.cpp:517
>>>               debug\qmljsplugindumper.obj:(?getHighestExportVersion@@YAXAEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@AEBVQString@@1PEA_NPEAVComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:605
>>>               debug\qmljstypedescriptionreader.obj:(?readMetaObjectRevisions@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ??0ComponentVersion@LanguageUtils@@QEAA@AEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsdocument.cpp:202
>>>               debug\qmljsdocument.obj:(?importModule@CollectDirectives@?A0xC5EDBE12@@UEAAXAEBVQString@@00HH@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:563
>>>               debug\qmljstypedescriptionreader.obj:(?readExports@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:512
>>>               debug\qmljstypedescriptionreader.obj:(?readNumericVersionBinding@TypeDescriptionReader@QmlJS@@AEAA?AVComponentVersion@LanguageUtils@@PEAVUiScriptBinding@AST@2@@Z)

lld-link: error: undefined symbol: ?keyCount@FakeMetaEnum@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:244
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?key@FakeMetaEnum@LanguageUtils@@QEBA?AVQString@@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:245
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?methodCount@FakeMetaObject@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:256
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:257
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:267
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:483
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:484
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?method@FakeMetaObject@LanguageUtils@@QEBA?AVFakeMetaMethod@2@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:258
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:268
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:271
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:485
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?revision@FakeMetaMethod@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:269
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?methodName@FakeMetaMethod@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:271
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:501
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:305
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?methodType@FakeMetaMethod@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:274
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:278
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:486
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?access@FakeMetaMethod@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:274
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:278
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:486
>>>               debug\qmljsinterpreter.obj:(?signalScope@CppComponentValue@QmlJS@@QEBAPEBVObjectValue@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?propertyCount@FakeMetaObject@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:291
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?property@FakeMetaObject@LanguageUtils@@QEBA?AVFakeMetaProperty@2@H@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:292
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:516
>>>               debug\qmljsinterpreter.obj:(?isWritable@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:446
>>>               debug\qmljsinterpreter.obj:(?isListProperty@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:525
>>>               debug\qmljsinterpreter.obj:(?isPointer@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:437
>>>               debug\qmljsinterpreter.obj:(?propertyType@CppComponentValue@QmlJS@@QEBA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?revision@FakeMetaProperty@LanguageUtils@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:293
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?name@FakeMetaProperty@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:295
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?typeName@FakeMetaProperty@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:303
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:437
>>>               debug\qmljsinterpreter.obj:(?propertyType@CppComponentValue@QmlJS@@QEBA?AVQString@@AEBV3@@Z)

lld-link: error: undefined symbol: ?attachedTypeName@FakeMetaObject@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:318
>>>               debug\qmljsinterpreter.obj:(?processMembers@CppComponentValue@QmlJS@@UEBAXPEAVMemberProcessor@2@@Z)

lld-link: error: undefined symbol: ?propertyIndex@FakeMetaObject@LanguageUtils@@QEBAHAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:515
>>>               debug\qmljsinterpreter.obj:(?isWritable@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:445
>>>               debug\qmljsinterpreter.obj:(?isListProperty@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:524
>>>               debug\qmljsinterpreter.obj:(?isPointer@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:436
>>>               debug\qmljsinterpreter.obj:(?propertyType@CppComponentValue@QmlJS@@QEBA?AVQString@@AEBV3@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:531
>>>               debug\qmljsinterpreter.obj:(?hasLocalProperty@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:539
>>>               debug\qmljsinterpreter.obj:(?hasProperty@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)

lld-link: error: undefined symbol: ?isWritable@FakeMetaProperty@LanguageUtils@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:516
>>>               debug\qmljsinterpreter.obj:(?isWritable@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)

lld-link: error: undefined symbol: ?isList@FakeMetaProperty@LanguageUtils@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:446
>>>               debug\qmljsinterpreter.obj:(?isListProperty@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)

lld-link: error: undefined symbol: ?isPointer@FakeMetaProperty@LanguageUtils@@QEBA_NXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:525
>>>               debug\qmljsinterpreter.obj:(?isPointer@CppComponentValue@QmlJS@@QEBA_NAEBVQString@@@Z)

lld-link: error: undefined symbol: ?defaultPropertyName@FakeMetaObject@LanguageUtils@@QEBA?AVQString@@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:430
>>>               debug\qmljsinterpreter.obj:(?defaultPropertyName@CppComponentValue@QmlJS@@QEBA?AVQString@@XZ)

lld-link: error: undefined symbol: ?enumeratorIndex@FakeMetaObject@LanguageUtils@@QEBAHAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:455
>>>               debug\qmljsinterpreter.obj:(?getEnum@CppComponentValue@QmlJS@@QEBA?AVFakeMetaEnum@LanguageUtils@@AEBVQString@@PEAPEBV12@@Z)

lld-link: error: undefined symbol: ??0FakeMetaEnum@LanguageUtils@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:462
>>>               debug\qmljsinterpreter.obj:(?getEnum@CppComponentValue@QmlJS@@QEBA?AVFakeMetaEnum@LanguageUtils@@AEBVQString@@PEAPEBV12@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:358
>>>               debug\qmljstypedescriptionreader.obj:(?readEnum@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ??OLanguageUtils@@YA_NAEBVComponentVersion@0@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1129
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1134
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1165
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsplugindumper.cpp:519
>>>               debug\qmljsplugindumper.obj:(?getHighestExportVersion@@YAXAEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@AEBVQString@@1PEA_NPEAVComponentVersion@LanguageUtils@@@Z)

lld-link: error: undefined symbol: ??NLanguageUtils@@YA_NAEBVComponentVersion@0@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1160
>>>               debug\qmljsinterpreter.obj:(?createObjectsForImport@CppQmlTypes@QmlJS@@QEAA?AV?$QList@PEBVCppComponentValue@QmlJS@@@@AEBVQString@@VComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:384
>>>               debug\qmljslink.obj:(?findBestModuleApi@QmlJS@@YA?AVModuleApiInfo@1@AEBV?$QList@VModuleApiInfo@QmlJS@@@@AEBVComponentVersion@LanguageUtils@@@Z)

lld-link: error: undefined symbol: ??0Export@FakeMetaObject@LanguageUtils@@QEAA@XZ
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qhash.h:657
>>>               debug\qmljsinterpreter.obj:(?value@?$QHash@VQString@@VExport@FakeMetaObject@LanguageUtils@@@@QEBA?BVExport@FakeMetaObject@LanguageUtils@@AEBVQString@@@Z)

lld-link: error: undefined symbol: ??8LanguageUtils@@YA_NAEBVComponentVersion@0@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1087
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QList@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljsinterpreter.cpp:1087
>>>               debug\qmljsinterpreter.obj:(??$load@V?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@@CppQmlTypes@QmlJS@@QEAAXAEBVQString@@AEBV?$QHash@VQString@@V?$QSharedPointer@$$CBVFakeMetaObject@LanguageUtils@@@@@@0@Z)
>>> referenced by E:\Software\Qt\5.15.2\msvc2019_64\include\QtCore\qpair.h:115
>>>               debug\qmljscheck.obj:(??$?8VQString@@VComponentVersion@LanguageUtils@@@@YA_NAEBU?$QPair@VQString@@VComponentVersion@LanguageUtils@@@@0@Z)

lld-link: error: undefined symbol: ??MLanguageUtils@@YA_NAEBVComponentVersion@0@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:384
>>>               debug\qmljslink.obj:(?findBestModuleApi@QmlJS@@YA?AVModuleApiInfo@1@AEBV?$QList@VModuleApiInfo@QmlJS@@@@AEBVComponentVersion@LanguageUtils@@@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljslink.cpp:635
>>>               debug\qmljslink.obj:(?loadQmldirComponents@LinkPrivate@QmlJS@@QEAAXPEAVObjectValue@2@VComponentVersion@LanguageUtils@@AEBVLibraryInfo@2@AEBVQString@@@Z)

lld-link: error: undefined symbol: ?setDefaultPropertyName@FakeMetaObject@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:219
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?setAttachedTypeName@FakeMetaObject@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:225
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ?setIsComposite@FakeMetaObject@LanguageUtils@@QEAAX_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:231
>>>               debug\qmljstypedescriptionreader.obj:(?readComponent@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@@Z)

lld-link: error: undefined symbol: ??0FakeMetaMethod@LanguageUtils@@QEAA@XZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:280
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setMethodName@FakeMetaMethod@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:297
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setReturnType@FakeMetaMethod@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:299
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setRevision@FakeMetaMethod@LanguageUtils@@QEAAXH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:301
>>>               debug\qmljstypedescriptionreader.obj:(?readSignalOrMethod@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@_NV?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setName@FakeMetaEnum@LanguageUtils@@QEAAXAEBVQString@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:370
>>>               debug\qmljstypedescriptionreader.obj:(?readEnum@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiObjectDefinition@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?setExportMetaObjectRevision@FakeMetaObject@LanguageUtils@@QEAAXHH@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\qmljs\qmljstypedescriptionreader.cpp:629
>>>               debug\qmljstypedescriptionreader.obj:(?readMetaObjectRevisions@TypeDescriptionReader@QmlJS@@AEAAXPEAVUiScriptBinding@AST@2@V?$QSharedPointer@VFakeMetaObject@LanguageUtils@@@@@Z)

lld-link: error: undefined symbol: ?saveDocument@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:268
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?saveDocumentAs@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:269
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?revertToSaved@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:270
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?closeOtherDocuments@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:276
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?splitSideBySide@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:277
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?gotoOtherSplit@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:278
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?goBackInNavigationHistory@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:279
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?goForwardInNavigationHistory@EditorManager@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager.cpp:280
>>>               debug\moc_editormanager.obj:(?qt_static_metacall@EditorManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?saveDocument@EditorManagerPrivate@Internal@Core@@SA_NPEAVIDocument@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:113
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?saveDocumentAs@EditorManagerPrivate@Internal@Core@@SA_NPEAVIDocument@3@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:115
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?split@EditorManagerPrivate@Internal@Core@@SAXW4Orientation@Qt@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:117
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?removeAllSplits@EditorManagerPrivate@Internal@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:118
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?gotoPreviousSplit@EditorManagerPrivate@Internal@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:119
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?gotoNextSplit@EditorManagerPrivate@Internal@Core@@SAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:120
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?handleDocumentStateChange@EditorManagerPrivate@Internal@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:121
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?editorAreaDestroyed@EditorManagerPrivate@Internal@Core@@QEAAXPEAVQObject@@@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_editormanager_p.cpp:122
>>>               debug\moc_editormanager_p.obj:(?qt_static_metacall@EditorManagerPrivate@Internal@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?clearRecentFiles@DocumentManager@Core@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_documentmanager.cpp:103
>>>               debug\moc_documentmanager.obj:(?qt_static_metacall@DocumentManager@Core@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?qt_metacast@ILocatorFilter@Core@@UEAAPEAXPEBD@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_menubarfilter.cpp:86
>>>               debug\moc_menubarfilter.obj:(?qt_metacast@MenuBarFilter@Internal@Core@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_linenumberfilter.cpp:86
>>>               debug\moc_linenumberfilter.obj:(?qt_metacast@LineNumberFilter@Internal@TextEditor@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppcurrentdocumentfilter.cpp:86
>>>               debug\moc_cppcurrentdocumentfilter.obj:(?qt_metacast@CppCurrentDocumentFilter@Internal@CppTools@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cpplocatorfilter.cpp:86
>>>               debug\moc_cpplocatorfilter.obj:(?qt_metacast@CppLocatorFilter@Internal@CppTools@@UEAAPEAXPEBD@Z)

lld-link: error: undefined symbol: ?qt_metacall@ILocatorFilter@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_menubarfilter.cpp:91
>>>               debug\moc_menubarfilter.obj:(?qt_metacall@MenuBarFilter@Internal@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_linenumberfilter.cpp:91
>>>               debug\moc_linenumberfilter.obj:(?qt_metacall@LineNumberFilter@Internal@TextEditor@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppcurrentdocumentfilter.cpp:91
>>>               debug\moc_cppcurrentdocumentfilter.obj:(?qt_metacall@CppCurrentDocumentFilter@Internal@CppTools@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cpplocatorfilter.cpp:91
>>>               debug\moc_cpplocatorfilter.obj:(?qt_metacall@CppLocatorFilter@Internal@CppTools@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?staticMetaObject@ILocatorFilter@Core@@2UQMetaObject@@B
>>> referenced by debug\moc_menubarfilter.obj:(?staticMetaObject@MenuBarFilter@Internal@Core@@2UQMetaObject@@B)
>>> referenced by debug\moc_linenumberfilter.obj:(?staticMetaObject@LineNumberFilter@Internal@TextEditor@@2UQMetaObject@@B)
>>> referenced by debug\moc_cppcurrentdocumentfilter.obj:(?staticMetaObject@CppCurrentDocumentFilter@Internal@CppTools@@2UQMetaObject@@B)
>>> referenced by debug\moc_cpplocatorfilter.obj:(?staticMetaObject@CppLocatorFilter@Internal@CppTools@@2UQMetaObject@@B)

lld-link: error: undefined symbol: ?inSnippetMode@TextEditorWidget@TextEditor@@QEAAXPEA_N@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_texteditor.cpp:239
>>>               debug\moc_texteditor.obj:(?qt_static_metacall@TextEditorWidget@TextEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?verticalBlockSelectionFirstColumn@TextEditorWidget@TextEditor@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_texteditor.cpp:360
>>>               debug\moc_texteditor.obj:(?qt_static_metacall@TextEditorWidget@TextEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?verticalBlockSelectionLastColumn@TextEditorWidget@TextEditor@@QEBAHXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_texteditor.cpp:361
>>>               debug\moc_texteditor.obj:(?qt_static_metacall@TextEditorWidget@TextEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?qt_metacast@IFindFilter@Core@@UEAAPEAXPEBD@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_basefilefind.cpp:220
>>>               debug\moc_basefilefind.obj:(?qt_metacast@BaseFileFind@TextEditor@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_symbolsfindfilter.cpp:109
>>>               debug\moc_symbolsfindfilter.obj:(?qt_metacast@SymbolsFindFilter@Internal@CppTools@@UEAAPEAXPEBD@Z)

lld-link: error: undefined symbol: ?qt_metacall@IFindFilter@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_basefilefind.cpp:225
>>>               debug\moc_basefilefind.obj:(?qt_metacall@BaseFileFind@TextEditor@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_symbolsfindfilter.cpp:114
>>>               debug\moc_symbolsfindfilter.obj:(?qt_metacall@SymbolsFindFilter@Internal@CppTools@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?qt_metacast@TextDocument@TextEditor@@UEAAPEAXPEBD@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppeditordocument.cpp:174
>>>               debug\moc_cppeditordocument.obj:(?qt_metacast@CppEditorDocument@Internal@CppEditor@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_qmljseditordocument.cpp:136
>>>               debug\moc_qmljseditordocument.obj:(?qt_metacast@QmlJSEditorDocument@QmlJSEditor@@UEAAPEAXPEBD@Z)

lld-link: error: undefined symbol: ?qt_metacall@TextDocument@TextEditor@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppeditordocument.cpp:179
>>>               debug\moc_cppeditordocument.obj:(?qt_metacall@CppEditorDocument@Internal@CppEditor@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_qmljseditordocument.cpp:141
>>>               debug\moc_qmljseditordocument.obj:(?qt_metacall@QmlJSEditorDocument@QmlJSEditor@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?currentItemChanged@CppQuickFixProjectSettingsWidget@Internal@CppEditor@@AEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppquickfixprojectsettingswidget.cpp:76
>>>               debug\moc_cppquickfixprojectsettingswidget.obj:(?qt_static_metacall@CppQuickFixProjectSettingsWidget@Internal@CppEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?buttonCustomClicked@CppQuickFixProjectSettingsWidget@Internal@CppEditor@@AEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppquickfixprojectsettingswidget.cpp:77
>>>               debug\moc_cppquickfixprojectsettingswidget.obj:(?qt_static_metacall@CppQuickFixProjectSettingsWidget@Internal@CppEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?currentCustomItemChanged@CppQuickFixSettingsWidget@Internal@CppEditor@@AEAAXPEAVQListWidgetItem@@0@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppquickfixsettingswidget.cpp:85
>>>               debug\moc_cppquickfixsettingswidget.obj:(?qt_static_metacall@CppQuickFixSettingsWidget@Internal@CppEditor@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?qt_metacast@BaseFileFilter@Core@@UEAAPEAXPEBD@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppincludesfilter.cpp:86
>>>               debug\moc_cppincludesfilter.obj:(?qt_metacast@CppIncludesFilter@Internal@CppTools@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_allprojectsfilter.cpp:86
>>>               debug\moc_allprojectsfilter.obj:(?qt_metacast@AllProjectsFilter@Internal@ProjectExplorer@@UEAAPEAXPEBD@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_currentprojectfilter.cpp:86
>>>               debug\moc_currentprojectfilter.obj:(?qt_metacast@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAPEAXPEBD@Z)

lld-link: error: undefined symbol: ?qt_metacall@BaseFileFilter@Core@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_cppincludesfilter.cpp:91
>>>               debug\moc_cppincludesfilter.obj:(?qt_metacall@CppIncludesFilter@Internal@CppTools@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_allprojectsfilter.cpp:91
>>>               debug\moc_allprojectsfilter.obj:(?qt_metacall@AllProjectsFilter@Internal@ProjectExplorer@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_currentprojectfilter.cpp:91
>>>               debug\moc_currentprojectfilter.obj:(?qt_metacall@CurrentProjectFilter@Internal@ProjectExplorer@@UEAAHW4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?staticMetaObject@BaseFileFilter@Core@@2UQMetaObject@@B
>>> referenced by debug\moc_cppincludesfilter.obj:(?staticMetaObject@CppIncludesFilter@Internal@CppTools@@2UQMetaObject@@B)
>>> referenced by debug\moc_allprojectsfilter.obj:(?staticMetaObject@AllProjectsFilter@Internal@ProjectExplorer@@2UQMetaObject@@B)
>>> referenced by debug\moc_currentprojectfilter.obj:(?staticMetaObject@CurrentProjectFilter@Internal@ProjectExplorer@@2UQMetaObject@@B)

lld-link: error: undefined symbol: ?updateSubmitAction@SubmitEditorWidget@VcsBase@@QEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:121
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)

lld-link: error: undefined symbol: ?descriptionTextChanged@SubmitEditorWidget@VcsBase@@IEAAXXZ
>>> referenced by E:\VM.CODES\YUNYOO\a64dbg\x64dbg\src\build-x64dbg-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\debug\moc_submiteditorwidget.cpp:122
>>>               debug\moc_submiteditorwidget.obj:(?qt_static_metacall@SubmitEditorWidget@VcsBase@@CAXPEAVQObject@@W4Call@QMetaObject@@HPEAPEAX@Z)