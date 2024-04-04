//
//  unimpl.cpp
//  A64Dbg
//
//  Created by GeekNeo on 2020/11/12.
//  Copyright © 2020 YunYoo. All rights reserved.
//

extern "C" void abort(void);

#if __APPLE__ || __linux__

#define unimpl(n) \
  extern "C" void __attribute__((weak)) n(void) { abort(); }

#define trueimpl(n) \
  extern "C" bool n(void) { return true; }

#define falseimpl(n) \
  extern "C" bool n(void) { return false; }

#define negimpl(n) \
  extern "C" bool n(void) { return false; }

#if __linux__
unimpl(_ZNK5Zydis14ResolveOpValueEiRKSt8functionIFm13ZydisRegisterEE);
unimpl(_ZNK5Zydis8MnemonicB5cxx11Ev);
unimpl(_ZNK5Zydis15InstructionTextB5cxx11Eb);
unimpl(_Z11getregisterPiPKc);
#endif

unimpl(_ZN5Zydis11DisassembleEmPKh);
unimpl(_ZN5Zydis11DisassembleEmPKhi);
unimpl(_ZN5Zydis15DisassembleSafeEmPKhi);
falseimpl(_ZN5Zydis16GlobalInitializeEv);
falseimpl(_ZN5ZydisC1Ev);
falseimpl(_ZN5ZydisD1Ev);
unimpl(_ZNK5Zydis10BytesGroupEPhS0_S0_S0_S0_);
unimpl(_ZNK5Zydis11MemSizeNameEi);
unimpl(_ZNK5Zydis12IsBranchTypeEz);
unimpl(_ZNK5Zydis14ResolveOpValueEiRKNSt3__18functionIFm13ZydisRegisterEEE);
unimpl(_ZNK5Zydis15InstructionTextEb);
unimpl(_ZNK5Zydis20getVectorElementTypeEi);
unimpl(_ZNK5Zydis22IsBranchGoingToExecuteEmm);
unimpl(_ZNK5Zydis4SizeEv);
unimpl(_ZNK5Zydis5IsNopEv);
unimpl(_ZNK5Zydis7AddressEv);
unimpl(_ZNK5Zydis7OpCountEv);
unimpl(_ZNK5Zydis7RegInfoEPh);
unimpl(_ZNK5Zydis7RegNameE13ZydisRegister);
unimpl(_ZNK5Zydis7SuccessEv);
unimpl(_ZNK5Zydis8FlagNameE12ZydisCPUFlag);
unimpl(_ZNK5Zydis8GetInstrEv);
unimpl(_ZNK5Zydis8MnemonicEv);
unimpl(_ZNK5Zydis9IsPushPopEv);
unimpl(_ZNK5Zydis9IsUnusualEv);
unimpl(_ZNK5ZydisixEi);
unimpl(ld2str);
unimpl(str2ld);

unimpl(_Z5qHashRK6QColor);  // ", referenced from:
                            //__Z5qHashI6QColorEjRKT_j in textmark.o
unimpl(
    _ZN10QmlJSTools12SemanticInfo17setRootScopeChainE14QSharedPointerIKN5QmlJS10ScopeChainEE);  // ", referenced from:
                                                                                                //__ZN11QmlJSEditor8Internal19SemanticInfoUpdater19makeNewSemanticInfoERK14QSharedPointerIKN5QmlJS8DocumentEERKNS3_8SnapshotE in qmljssemanticinfoupdater.o
unimpl(
    _ZN10QmlJSTools20CreatorCodeFormatterC1ERKN10TextEditor11TabSettingsE);  // ", referenced from:
                                                                             //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate24invalidateFormatterCacheEv in qmljseditordocument.o
unimpl(
    _ZN10QmlJSTools23QmlJSRefactoringChanges4fileEPN10TextEditor16TextEditorWidgetERK14QSharedPointerIKN5QmlJS8DocumentEE);  // ", referenced from:
                                                                                                                             //__ZN11QmlJSEditor8Internal28QmlJSQuickFixAssistInterfaceC2EPNS_17QmlJSEditorWidgetEN10TextEditor12AssistReasonE in qmljsquickfixassist.o
unimpl(
    _ZN10QmlJSTools23QmlJSRefactoringChangesC1EPN5QmlJS21ModelManagerInterfaceERKNS1_8SnapshotE);  // ", referenced from:
                                                                                                   //__ZN11QmlJSEditor29performComponentFromObjectDefERK7QStringPN5QmlJS3AST18UiObjectDefinitionE in qmljscomponentfromobjectdef.o
                                                                                                   //__ZN11QmlJSEditor8Internal15QmlOutlineModel13reparentNodesEPNS0_14QmlOutlineItemEi5QListIS3_E in qmloutlinemodel.o
                                                                                                   //__ZN11QmlJSEditor22QmlJSQuickFixOperation7performEv in qmljsquickfix.o
unimpl(
    _ZN10TextEditor14BaseTextEditor10addContextEN5Utils2IdE);  // ", referenced
                                                               // from:
                                                               //__ZN9CppEditor8Internal9CppEditorC2Ev
                                                               // in cppeditor.o
                                                               //__ZN11QmlJSEditor11QmlJSEditorC2Ev
                                                               // in
                                                               // qmljseditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor12restoreStateERK10QByteArray);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor14BaseTextEditorE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN9CppEditor8Internal9CppEditorE
                                                                    // in
                                                                    // moc_cppeditor.o
                                                                    //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                                    // in
                                                                    // moc_qmljseditor.o
                                                                    //__ZTVN7VcsBase13VcsBaseEditorE
                                                                    // in
                                                                    // moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor13setTextCursorERK11QTextCursor);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv
                                                                      // in
                                                                      // sourceagent.o
unimpl(
    _ZN10TextEditor14BaseTextEditor14setContextHelpERKN4Core8HelpItemE);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN10TextEditor14BaseTextEditorE
                                                                          // in
                                                                          // moc_texteditor.o
                                                                          //__ZTVN9CppEditor8Internal9CppEditorE
                                                                          // in
                                                                          // moc_cppeditor.o
                                                                          //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                                          // in
                                                                          // moc_qmljseditor.o
                                                                          //__ZTVN7VcsBase13VcsBaseEditorE
                                                                          // in
                                                                          // moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor17currentTextEditorEv);  // ", referenced
                                                            // from:
                                                            //__ZN8Debugger8Internal12LocationMark10dragToLineEi
                                                            // in
                                                            // debuggerengine.o
                                                            //__ZN8Debugger8Internal14DebuggerEngine19handleExecRunToLineEv
                                                            // in
                                                            // debuggerengine.o
                                                            //__ZN8Debugger8Internal14DebuggerEngine31handleExecRunToSelectedFunctionEv
                                                            // in
                                                            // debuggerengine.o
                                                            //__ZN8Debugger8Internal14DebuggerEngine20handleExecJumpToLineEv
                                                            // in
                                                            // debuggerengine.o
                                                            //__ZN8Debugger8Internal14DebuggerEngine22handleAddToWatchWindowEv
                                                            // in
                                                            // debuggerengine.o
                                                            //__ZN8Debugger8Internal21DebuggerPluginPrivate22toggleBreakpointHelperEv
                                                            // in
                                                            // debuggerplugin.o
                                                            //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate21updateVisibleToolTipsEv
                                                            // in
                                                            // debuggertooltipmanager.o
                                                            //...
unimpl(
    _ZN10TextEditor14BaseTextEditor17setCursorPositionEi);  // ", referenced
                                                            // from:
                                                            //__ZTVN10TextEditor14BaseTextEditorE
                                                            // in
                                                            // moc_texteditor.o
                                                            //__ZTVN9CppEditor8Internal9CppEditorE
                                                            // in
                                                            // moc_cppeditor.o
                                                            //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                            // in
                                                            // moc_qmljseditor.o
                                                            //__ZTVN7VcsBase13VcsBaseEditorE
                                                            // in
                                                            // moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor6insertERK7QString);  // ", referenced from:
                                                         //__ZTVN10TextEditor14BaseTextEditorE
                                                         // in moc_texteditor.o
                                                         //__ZTVN9CppEditor8Internal9CppEditorE
                                                         // in moc_cppeditor.o
                                                         //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                         // in moc_qmljseditor.o
                                                         //__ZTVN7VcsBase13VcsBaseEditorE
                                                         // in
                                                         // moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor6removeEi);  // ", referenced from:
                                                //__ZTVN10TextEditor14BaseTextEditorE
                                                // in moc_texteditor.o
                                                //__ZTVN9CppEditor8Internal9CppEditorE
                                                // in moc_cppeditor.o
                                                //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                // in moc_qmljseditor.o
                                                //__ZTVN7VcsBase13VcsBaseEditorE
                                                // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor6selectEi);  // ", referenced from:
                                                //__ZTVN10TextEditor14BaseTextEditorE
                                                // in moc_texteditor.o
                                                //__ZTVN9CppEditor8Internal9CppEditorE
                                                // in moc_cppeditor.o
                                                //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                // in moc_qmljseditor.o
                                                //__ZTVN7VcsBase13VcsBaseEditorE
                                                // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor7replaceEiRK7QString);  // ", referenced
                                                           // from:
                                                           //__ZTVN10TextEditor14BaseTextEditorE
                                                           // in
                                                           // moc_texteditor.o
                                                           //__ZTVN9CppEditor8Internal9CppEditorE
                                                           // in moc_cppeditor.o
                                                           //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                           // in
                                                           // moc_qmljseditor.o
                                                           //__ZTVN7VcsBase13VcsBaseEditorE
                                                           // in
                                                           // moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor7toolBarEv);  // ", referenced from:
                                                 //__ZTVN10TextEditor14BaseTextEditorE
                                                 // in moc_texteditor.o
                                                 //__ZTVN9CppEditor8Internal9CppEditorE
                                                 // in moc_cppeditor.o
                                                 //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                 // in moc_qmljseditor.o
                                                 //__ZTVN7VcsBase13VcsBaseEditorE
                                                 // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor8gotoLineEiib);  // ", referenced from:
                                                    //__ZTVN10TextEditor14BaseTextEditorE
                                                    // in moc_texteditor.o
                                                    //__ZTVN9CppEditor8Internal9CppEditorE
                                                    // in moc_cppeditor.o
                                                    //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                    // in moc_qmljseditor.o
                                                    //__ZTVN7VcsBase13VcsBaseEditorE
                                                    // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditor9duplicateEv);  // ", referenced from:
                                                   //__ZTVN10TextEditor14BaseTextEditorE
                                                   // in moc_texteditor.o
                                                   //__ZTVN9CppEditor8Internal9CppEditorE
                                                   // in moc_cppeditor.o
                                                   //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                   // in moc_qmljseditor.o
                                                   //__ZTVN7VcsBase13VcsBaseEditorE
                                                   // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditorC2Ev);  // ", referenced from:
                                           //__ZN9CppEditor8Internal9CppEditorC2Ev
                                           // in cppeditor.o
                                           //__ZN11QmlJSEditor11QmlJSEditorC2Ev
                                           // in qmljseditor.o
                                           //__ZN7VcsBase13VcsBaseEditorC2Ev
                                           // in vcsbaseeditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditorD0Ev);  // ", referenced from:
                                           //__ZTVN10TextEditor14BaseTextEditorE
                                           // in moc_texteditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditorD1Ev);  // ", referenced from:
                                           //__ZTVN10TextEditor14BaseTextEditorE
                                           // in moc_texteditor.o
unimpl(
    _ZN10TextEditor14BaseTextEditorD2Ev);  // ", referenced from:
                                           //__ZN9CppEditor8Internal9CppEditorC2Ev
                                           // in cppeditor.o
                                           //__ZN11QmlJSEditor11QmlJSEditorC2Ev
                                           // in qmljseditor.o
                                           //__ZN9CppEditor8Internal9CppEditorD2Ev
                                           // in moc_cppeditor.o
                                           //__ZN11QmlJSEditor11QmlJSEditorD2Ev
                                           // in moc_qmljseditor.o
                                           //__ZN7VcsBase13VcsBaseEditorD2Ev
                                           // in moc_vcsbaseeditor.o
unimpl(
    _ZN10TextEditor16FontSettingsPage11setFontZoomEi);  // ", referenced from:
                                                        //__ZN10TextEditorL11setFontZoomEi
                                                        // in
                                                        // texteditorsettings.o
unimpl(
    _ZN10TextEditor16FontSettingsPageC1EPNS_12FontSettingsERKNSt3__16vectorINS_17FormatDescriptionENS3_9allocatorIS5_EEEE);  // ", referenced from:
                                                                                                                             //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev in texteditorsettings.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10autoFormatEv);  // ", referenced from:
                                                       //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                       // in
                                                       // plaintexteditorfactory.o
                                                       //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                       // in diffeditor.o
                                                       //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                       // in
                                                       // sidebysidediffeditorwidget.o
                                                       //__ZTVN10TextEditor16TextEditorWidgetE
                                                       // in moc_texteditor.o
                                                       //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                       // in moc_snippeteditor.o
                                                       //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                       // in
                                                       // moc_cppeditorwidget.o
                                                       //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                       // in moc_qmljseditor.o
                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10autoIndentEv);  // ", referenced from:
                                                       //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                       // in
                                                       // plaintexteditorfactory.o
                                                       //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                       // in diffeditor.o
                                                       //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                       // in
                                                       // sidebysidediffeditorwidget.o
                                                       //__ZTVN10TextEditor16TextEditorWidgetE
                                                       // in moc_texteditor.o
                                                       //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                       // in moc_snippeteditor.o
                                                       //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                       // in
                                                       // moc_cppeditorwidget.o
                                                       //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                       // in moc_qmljseditor.o
                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10copyLineUpEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_19clEPNS_16TextEditorWidgetE
                                                       // in
                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10deleteLineEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_8clEPNS_16TextEditorWidgetE
                                                       // in
                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10findLinkAtERK11QTextCursorONSt3__18functionIFvRKN5Utils4LinkEEEEbb);  // ", referenced from:
                                                                                                             //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                                             //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                                             //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                                             //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                                             //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                                             //__ZTVN7VcsBase19VcsBaseEditorWidgetE in moc_vcsbaseeditor.o
                                                                                                             //__ZTVN10DiffEditor8Internal26SelectableTextEditorWidgetE in moc_selectabletexteditorwidget.o
                                                                                                             //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10findUsagesEv);  // ", referenced from:
                                                       //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                       // in
                                                       // plaintexteditorfactory.o
                                                       //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                       // in diffeditor.o
                                                       //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                       // in
                                                       // sidebysidediffeditorwidget.o
                                                       //__ZTVN10TextEditor16TextEditorWidgetE
                                                       // in moc_texteditor.o
                                                       //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                       // in moc_snippeteditor.o
                                                       //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                       // in moc_vcsbaseeditor.o
                                                       //__ZTVN10DiffEditor8Internal26SelectableTextEditorWidgetE
                                                       // in
                                                       // moc_selectabletexteditorwidget.o
                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10fromEditorEPKN4Core7IEditorE);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN8Debugger8Internal21DebuggerPluginPrivate12editorOpenedEPN4Core7IEditorE
                                                                       // in
                                                                       // debuggerplugin.o
                                                                       //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE
                                                                       // in
                                                                       // disassembleragent.o
                                                                       //__ZN8Debugger8Internal24DisassemblerAgentPrivate17configureMimeTypeEv
                                                                       // in
                                                                       // disassembleragent.o
                                                                       //__ZN10TextEditor23TextEditorActionHandlerC2EN5Utils2IdES2_jRKNSt3__18functionIFPNS_16TextEditorWidgetEPN4Core7IEditorEEEE
                                                                       // in
                                                                       // texteditoractionhandler.o
                                                                       //__ZN10TextEditor18RefactoringChanges10openEditorERK7QStringbii
                                                                       // in
                                                                       // refactoringchanges.o
                                                                       //__ZN10TextEditor15RefactoringFileC2ERK7QStringRK14QSharedPointerINS_22RefactoringChangesDataEE
                                                                       // in
                                                                       // refactoringchanges.o
                                                                       //__ZN15ProjectExplorer19EditorConfiguration20setUseGlobalSettingsEb
                                                                       // in
                                                                       // editorconfiguration.o
                                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10leaveEventEP6QEvent);  // ", referenced
                                                              // from:
                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                              // in
                                                              // plaintexteditorfactory.o
                                                              //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                              // in diffeditor.o
                                                              //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                              // in
                                                              // sidebysidediffeditorwidget.o
                                                              //__ZTVN10TextEditor16TextEditorWidgetE
                                                              // in
                                                              // moc_texteditor.o
                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                              // in
                                                              // moc_snippeteditor.o
                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                              // in
                                                              // moc_cppeditorwidget.o
                                                              //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                              // in
                                                              // moc_qmljseditor.o
                                                              //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10moveLineUpEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_17clEPNS_16TextEditorWidgetE
                                                       // in
                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10paintEventEP11QPaintEvent);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZN10DiffEditor8Internal20SideDiffEditorWidget10paintEventEP11QPaintEvent
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZTVN10TextEditor16TextEditorWidgetE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                    // in
                                                                    // moc_snippeteditor.o
                                                                    //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                    // in
                                                                    // moc_cppeditorwidget.o
                                                                    //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                    // in
                                                                    // moc_qmljseditor.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10timerEventEP11QTimerEvent);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZTVN10TextEditor16TextEditorWidgetE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                    // in
                                                                    // moc_snippeteditor.o
                                                                    //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                    // in
                                                                    // moc_cppeditorwidget.o
                                                                    //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                    // in
                                                                    // moc_qmljseditor.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget10viewLineUpEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_35clEPNS_16TextEditorWidgetE
                                                       // in
                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10viewPageUpEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_33clEPNS_16TextEditorWidgetE
                                                       // in
                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget10wheelEventEP11QWheelEvent);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZN11QmlJSEditor17QmlJSEditorWidget10wheelEventEP11QWheelEvent
                                                                    // in
                                                                    // qmljseditor.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZTVN10TextEditor16TextEditorWidgetE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                    // in
                                                                    // moc_snippeteditor.o
                                                                    //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                    // in
                                                                    // moc_cppeditorwidget.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget11aboutToOpenERK7QStringS3_);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZTVN10TextEditor16TextEditorWidgetE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                    // in
                                                                    // moc_snippeteditor.o
                                                                    //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                    // in
                                                                    // moc_cppeditorwidget.o
                                                                    //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                    // in
                                                                    // moc_qmljseditor.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget11changeEventEP6QEvent);  // ", referenced
                                                               // from:
                                                               //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                               // in
                                                               // plaintexteditorfactory.o
                                                               //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                               // in
                                                               // diffeditor.o
                                                               //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                               // in
                                                               // sidebysidediffeditorwidget.o
                                                               //__ZTVN10TextEditor16TextEditorWidgetE
                                                               // in
                                                               // moc_texteditor.o
                                                               //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                               // in
                                                               // moc_snippeteditor.o
                                                               //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                               // in
                                                               // moc_cppeditorwidget.o
                                                               //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                               // in
                                                               // moc_qmljseditor.o
                                                               //...
unimpl(
    _ZN10TextEditor16TextEditorWidget11gotoLineEndEv);  // ", referenced from:
                                                        //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_68clEPNS_16TextEditorWidgetE
                                                        // in
                                                        // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget11resizeEventEP12QResizeEvent);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                      // in
                                                                      // plaintexteditorfactory.o
                                                                      //__ZN11QmlJSEditor17QmlJSEditorWidget11resizeEventEP12QResizeEvent
                                                                      // in
                                                                      // qmljseditor.o
                                                                      //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                      // in
                                                                      // diffeditor.o
                                                                      //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZTVN10TextEditor16TextEditorWidgetE
                                                                      // in
                                                                      // moc_texteditor.o
                                                                      //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                      // in
                                                                      // moc_snippeteditor.o
                                                                      //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                      // in
                                                                      // moc_cppeditorwidget.o
                                                                      //...
unimpl(
    _ZN10TextEditor16TextEditorWidget11setReadOnlyEb);  // ", referenced from:
                                                        //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE
                                                        // in
                                                        // disassembleragent.o
                                                        //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv
                                                        // in qmljseditor.o
                                                        //__ZN7VcsBase13VcsBaseEditor22finalizeInitializationEv
                                                        // in vcsbaseeditor.o
                                                        //__ZN7VcsBase19VcsBaseEditorWidget16setForceReadOnlyEb
                                                        // in vcsbaseeditor.o
                                                        //__ZN10DiffEditor8Internal10DiffEditorC2Ev
                                                        // in diffeditor.o
                                                        //__ZN10DiffEditor8Internal26SideBySideDiffEditorWidgetC2EP7QWidget
                                                        // in
                                                        // sidebysidediffeditorwidget.o
                                                        //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidgetC2EP7QWidget
                                                        // in
                                                        // unifieddiffeditorwidget.o
                                                        //...
unimpl(
    _ZN10TextEditor16TextEditorWidget12copyLineDownEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_20clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12focusInEventEP11QFocusEvent);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                      // in
                                                                      // plaintexteditorfactory.o
                                                                      //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                      // in
                                                                      // diffeditor.o
                                                                      //__ZN10DiffEditor8Internal20SideDiffEditorWidget12focusInEventEP11QFocusEvent
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZTVN10TextEditor16TextEditorWidgetE
                                                                      // in
                                                                      // moc_texteditor.o
                                                                      //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                      // in
                                                                      // moc_snippeteditor.o
                                                                      //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                      // in
                                                                      // moc_cppeditorwidget.o
                                                                      //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                      // in
                                                                      // moc_qmljseditor.o
                                                                      //...
unimpl(
    _ZN10TextEditor16TextEditorWidget12gotoBlockEndEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_61clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12gotoNextLineEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_69clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12gotoNextWordEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_74clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12invokeAssistENS_10AssistKindEPNS_15IAssistProviderE);  // ", referenced from:
                                                                                              //__ZZN10TextEditor8Internal16TextEditorPlugin10initializeERK11QStringListP7QStringENK3$_0clEv in texteditorplugin.o
                                                                                              //__ZZN10TextEditor8Internal16TextEditorPlugin10initializeERK11QStringListP7QStringENK3$_2clEv in texteditorplugin.o
                                                                                              //__ZZN10TextEditor8Internal16TextEditorPlugin10initializeERK11QStringListP7QStringENK3$_3clEv in texteditorplugin.o
                                                                                              //__ZN9CppEditor8Internal15CppEditorWidget28invokeTextEditorWidgetAssistEN10TextEditor10AssistKindEPNS2_15IAssistProviderE in cppeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12moveLineDownEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_18clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12restoreStateERK10QByteArray);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                      // in
                                                                      // plaintexteditorfactory.o
                                                                      //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                      // in
                                                                      // diffeditor.o
                                                                      //__ZN10DiffEditor8Internal20SideDiffEditorWidget12restoreStateEv
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidget12restoreStateEv
                                                                      // in
                                                                      // unifieddiffeditorwidget.o
                                                                      //__ZTVN10TextEditor16TextEditorWidgetE
                                                                      // in
                                                                      // moc_texteditor.o
                                                                      //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                      // in
                                                                      // moc_snippeteditor.o
                                                                      //...
unimpl(
    _ZN10TextEditor16TextEditorWidget12setCodeStyleEPNS_21ICodeStylePreferencesE);  // ", referenced from:
                                                                                    //__ZN10TextEditor15CodeStyleEditorC2EPNS_28ICodeStylePreferencesFactoryEPNS_21ICodeStylePreferencesEP7QWidget in codestyleeditor.o
                                                                                    //__ZNK15ProjectExplorer19EditorConfiguration15configureEditorEPN10TextEditor14BaseTextEditorE in editorconfiguration.o
                                                                                    //__ZNK15ProjectExplorer19EditorConfiguration17deconfigureEditorEPN10TextEditor14BaseTextEditorE in editorconfiguration.o
                                                                                    //__ZN10DiffEditor8Internal26SideBySideDiffEditorWidgetC2EP7QWidget in sidebysidediffeditorwidget.o
                                                                                    //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidgetC2EP7QWidget in unifieddiffeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12viewLineDownEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_36clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget12viewPageDownEv);  // ", referenced from:
                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_34clEPNS_16TextEditorWidgetE
                                                         // in
                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget13circularPasteEv);  // ", referenced from:
                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_38clEPNS_16TextEditorWidgetE
                                                          // in
                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget13focusOutEventEP11QFocusEvent);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                       // in
                                                                       // plaintexteditorfactory.o
                                                                       //__ZN10TextEditor19SnippetEditorWidget13focusOutEventEP11QFocusEvent
                                                                       // in
                                                                       // snippeteditor.o
                                                                       //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                       // in
                                                                       // diffeditor.o
                                                                       //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                       // in
                                                                       // sidebysidediffeditorwidget.o
                                                                       //__ZTVN10TextEditor16TextEditorWidgetE
                                                                       // in
                                                                       // moc_texteditor.o
                                                                       //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                       // in
                                                                       // moc_cppeditorwidget.o
                                                                       //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                       // in
                                                                       // moc_qmljseditor.o
                                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget13gotoLineStartEv);  // ", referenced from:
                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_67clEPNS_16TextEditorWidgetE
                                                          // in
                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget13inSnippetModeEPb);  // ", referenced
                                                           // from:
                                                           //__ZN10TextEditor16TextEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                           // in
                                                           // moc_texteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget13keyPressEventEP9QKeyEvent);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZN9CppEditor8Internal15CppEditorWidget18processKeyNormallyEP9QKeyEvent
                                                                    // in
                                                                    // cppeditorwidget.o
                                                                    //__ZN9CppEditor8Internal15CppEditorWidget13keyPressEventEP9QKeyEvent
                                                                    // in
                                                                    // cppeditorwidget.o
                                                                    //__ZN7VcsBase19VcsBaseEditorWidget13keyPressEventEP9QKeyEvent
                                                                    // in
                                                                    // vcsbaseeditor.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZN10DiffEditor8Internal20SideDiffEditorWidget13keyPressEventEP9QKeyEvent
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidget13keyPressEventEP9QKeyEvent
                                                                    // in
                                                                    // unifieddiffeditorwidget.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget13selectBlockUpEv);  // ", referenced from:
                                                          //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                          // in
                                                          // plaintexteditorfactory.o
                                                          //__ZN9CppEditor8Internal15CppEditorWidget13selectBlockUpEv
                                                          // in
                                                          // cppeditorwidget.o
                                                          //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                          // in diffeditor.o
                                                          //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                          // in
                                                          // sidebysidediffeditorwidget.o
                                                          //__ZTVN10TextEditor16TextEditorWidgetE
                                                          // in moc_texteditor.o
                                                          //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                          // in
                                                          // moc_snippeteditor.o
                                                          //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                          // in
                                                          // moc_qmljseditor.o
                                                          //...
unimpl(
    _ZN10TextEditor16TextEditorWidget13switchUtf8bomEv);  // ", referenced from:
                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_24clEPNS_16TextEditorWidgetE
                                                          // in
                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget13viewportEventEP6QEvent);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                 // in
                                                                 // plaintexteditorfactory.o
                                                                 //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                 // in
                                                                 // diffeditor.o
                                                                 //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                 // in
                                                                 // sidebysidediffeditorwidget.o
                                                                 //__ZTVN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // moc_texteditor.o
                                                                 //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                 // in
                                                                 // moc_snippeteditor.o
                                                                 //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                 // in
                                                                 // moc_cppeditorwidget.o
                                                                 //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                 // in
                                                                 // moc_qmljseditor.o
                                                                 //...
unimpl(
    _ZN10TextEditor16TextEditorWidget14OtherSelectionE);  // ", referenced from:
                                                          //__ZN7VcsBase8Internal23ChangeTextCursorHandler24highlightCurrentContentsEv
                                                          // in vcsbaseeditor.o
                                                          //__ZN7VcsBase8Internal20UrlTextCursorHandler24highlightCurrentContentsEv
                                                          // in vcsbaseeditor.o
                                                          //__ZN7VcsBase19VcsBaseEditorWidget14mouseMoveEventEP11QMouseEvent
                                                          // in vcsbaseeditor.o
                                                          //__ZN10DiffEditor8Internal20SideDiffEditorWidget8clearAllERK7QString
                                                          // in
                                                          // sidebysidediffeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget14dragEnterEventEP15QDragEnterEvent);  // ", referenced from:
                                                                            //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                            // in
                                                                            // plaintexteditorfactory.o
                                                                            //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                            // in
                                                                            // diffeditor.o
                                                                            //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                            // in
                                                                            // sidebysidediffeditorwidget.o
                                                                            //__ZTVN10TextEditor16TextEditorWidgetE
                                                                            // in
                                                                            // moc_texteditor.o
                                                                            //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                            // in
                                                                            // moc_snippeteditor.o
                                                                            //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                            // in
                                                                            // moc_cppeditorwidget.o
                                                                            //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                            // in
                                                                            // moc_qmljseditor.o
                                                                            //...
unimpl(
    _ZN10TextEditor16TextEditorWidget14encourageApplyEv);  // ", referenced
                                                           // from:
                                                           //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                           // in
                                                           // plaintexteditorfactory.o
                                                           //__ZN9CppEditor8Internal15CppEditorWidget14encourageApplyEv
                                                           // in
                                                           // cppeditorwidget.o
                                                           //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                           // in diffeditor.o
                                                           //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                           // in
                                                           // sidebysidediffeditorwidget.o
                                                           //__ZTVN10TextEditor16TextEditorWidgetE
                                                           // in
                                                           // moc_texteditor.o
                                                           //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                           // in
                                                           // moc_snippeteditor.o
                                                           //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                           // in
                                                           // moc_qmljseditor.o
                                                           //...
unimpl(
    _ZN10TextEditor16TextEditorWidget14gotoBlockStartEv);  // ", referenced
                                                           // from:
                                                           //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_60clEPNS_16TextEditorWidgetE
                                                           // in
                                                           // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget14mouseMoveEventEP11QMouseEvent);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                        // in
                                                                        // plaintexteditorfactory.o
                                                                        //__ZN7VcsBase19VcsBaseEditorWidget14mouseMoveEventEP11QMouseEvent
                                                                        // in
                                                                        // vcsbaseeditor.o
                                                                        //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                        // in
                                                                        // diffeditor.o
                                                                        //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                        // in
                                                                        // sidebysidediffeditorwidget.o
                                                                        //__ZTVN10TextEditor16TextEditorWidgetE
                                                                        // in
                                                                        // moc_texteditor.o
                                                                        //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                        // in
                                                                        // moc_snippeteditor.o
                                                                        //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                        // in
                                                                        // moc_cppeditorwidget.o
                                                                        //...
unimpl(
    _ZN10TextEditor16TextEditorWidget14selectEncodingEv);  // ", referenced
                                                           // from:
                                                           //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_37clEPNS_16TextEditorWidgetE
                                                           // in
                                                           // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15cleanWhitespaceEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_44clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15deleteEndOfLineEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_9clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15deleteEndOfWordEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_10clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15doSetTextCursorERK11QTextCursor);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                          // in
                                                                          // plaintexteditorfactory.o
                                                                          //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                          // in
                                                                          // diffeditor.o
                                                                          //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                          // in
                                                                          // sidebysidediffeditorwidget.o
                                                                          //__ZTVN10TextEditor16TextEditorWidgetE
                                                                          // in
                                                                          // moc_texteditor.o
                                                                          //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                          // in
                                                                          // moc_snippeteditor.o
                                                                          //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                          // in
                                                                          // moc_cppeditorwidget.o
                                                                          //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                          // in
                                                                          // moc_qmljseditor.o
                                                                          //...
unimpl(
    _ZN10TextEditor16TextEditorWidget15gotoDocumentEndEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_66clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15insertLineAboveEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_22clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15insertLineBelowEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_23clEPNS_16TextEditorWidgetE
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15keyReleaseEventEP9QKeyEvent);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                      // in
                                                                      // plaintexteditorfactory.o
                                                                      //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                      // in
                                                                      // diffeditor.o
                                                                      //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZTVN10TextEditor16TextEditorWidgetE
                                                                      // in
                                                                      // moc_texteditor.o
                                                                      //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                      // in
                                                                      // moc_snippeteditor.o
                                                                      //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                      // in
                                                                      // moc_cppeditorwidget.o
                                                                      //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                      // in
                                                                      // moc_qmljseditor.o
                                                                      //...
unimpl(
    _ZN10TextEditor16TextEditorWidget15mousePressEventEP11QMouseEvent);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                         // in
                                                                         // plaintexteditorfactory.o
                                                                         //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                         // in
                                                                         // diffeditor.o
                                                                         //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                         // in
                                                                         // sidebysidediffeditorwidget.o
                                                                         //__ZTVN10TextEditor16TextEditorWidgetE
                                                                         // in
                                                                         // moc_texteditor.o
                                                                         //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                         // in
                                                                         // moc_snippeteditor.o
                                                                         //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                         // in
                                                                         // moc_cppeditorwidget.o
                                                                         //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                         // in
                                                                         // moc_qmljseditor.o
                                                                         //...
unimpl(
    _ZN10TextEditor16TextEditorWidget15msgTextTooLargeEy);  // ", referenced
                                                            // from:
                                                            //__ZN10TextEditor12TextDocument12setPlainTextERK7QString
                                                            // in textdocument.o
                                                            //__ZN10TextEditor12TextDocument12setPlainTextERK7QString
                                                            // in textdocument.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15optionalActionsEv);  // ", referenced
                                                            // from:
                                                            //__ZN10TextEditor8Internal30TextEditorActionHandlerPrivate21updateOptionalActionsEv
                                                            // in
                                                            // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget15rewrapParagraphEv);  // ", referenced
                                                            // from:
                                                            //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                            // in
                                                            // plaintexteditorfactory.o
                                                            //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                            // in diffeditor.o
                                                            //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                            // in
                                                            // sidebysidediffeditorwidget.o
                                                            //__ZTVN10TextEditor16TextEditorWidgetE
                                                            // in
                                                            // moc_texteditor.o
                                                            //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                            // in
                                                            // moc_snippeteditor.o
                                                            //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                            // in
                                                            // moc_cppeditorwidget.o
                                                            //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                            // in
                                                            // moc_qmljseditor.o
                                                            //...
unimpl(
    _ZN10TextEditor16TextEditorWidget15selectBlockDownEv);  // ", referenced
                                                            // from:
                                                            //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                            // in
                                                            // plaintexteditorfactory.o
                                                            //__ZN9CppEditor8Internal15CppEditorWidget15selectBlockDownEv
                                                            // in
                                                            // cppeditorwidget.o
                                                            //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                            // in diffeditor.o
                                                            //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                            // in
                                                            // sidebysidediffeditorwidget.o
                                                            //__ZTVN10TextEditor16TextEditorWidgetE
                                                            // in
                                                            // moc_texteditor.o
                                                            //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                            // in
                                                            // moc_snippeteditor.o
                                                            //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                            // in
                                                            // moc_qmljseditor.o
                                                            //...
unimpl(
    _ZN10TextEditor16TextEditorWidget15showContextMenuEv);  // ", referenced
                                                            // from:
                                                            //__ZZN10TextEditor8Internal16TextEditorPlugin10initializeERK11QStringListP7QStringENK3$_4clEv
                                                            // in
                                                            // texteditorplugin.o
unimpl(
    _ZN10TextEditor16TextEditorWidget16contextMenuEventEP17QContextMenuEvent);  // ", referenced from:
                                                                                //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                //__ZTVN10DiffEditor8Internal26SelectableTextEditorWidgetE in moc_selectabletexteditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget16gotoPreviousLineEv);  // ", referenced
                                                             // from:
                                                             //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_70clEPNS_16TextEditorWidgetE
                                                             // in
                                                             // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget16gotoPreviousWordEv);  // ", referenced
                                                             // from:
                                                             //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_73clEPNS_16TextEditorWidgetE
                                                             // in
                                                             // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget16inputMethodEventEP17QInputMethodEvent);  // ", referenced from:
                                                                                //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                //...
unimpl(
    _ZN10TextEditor16TextEditorWidget16setAutoCompleterEPNS_13AutoCompleterE);  // ", referenced from:
                                                                                //__ZN9CppEditor8Internal9CppEditor14decorateEditorEPN10TextEditor16TextEditorWidgetE in cppeditor.o
                                                                                //__ZN11QmlJSEditor18QmlJSEditorFactory14decorateEditorEPN10TextEditor16TextEditorWidgetE in qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17applyFontSettingsEv);  // ", referenced
                                                              // from:
                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                              // in
                                                              // plaintexteditorfactory.o
                                                              //__ZN11QmlJSEditor17QmlJSEditorWidget17applyFontSettingsEv
                                                              // in
                                                              // qmljseditor.o
                                                              //__ZN10DiffEditor8Internal23DescriptionEditorWidget17applyFontSettingsEv
                                                              // in diffeditor.o
                                                              //__ZN10DiffEditor8Internal20SideDiffEditorWidget17applyFontSettingsEv
                                                              // in
                                                              // sidebysidediffeditorwidget.o
                                                              //__ZTVN10TextEditor16TextEditorWidgetE
                                                              // in
                                                              // moc_texteditor.o
                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                              // in
                                                              // moc_snippeteditor.o
                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                              // in
                                                              // moc_cppeditorwidget.o
                                                              //...
unimpl(
    _ZN10TextEditor16TextEditorWidget17deleteStartOfLineEv);  // ", referenced
                                                              // from:
                                                              //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_12clEPNS_16TextEditorWidgetE
                                                              // in
                                                              // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17deleteStartOfWordEv);  // ", referenced
                                                              // from:
                                                              //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_13clEPNS_16TextEditorWidgetE
                                                              // in
                                                              // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17duplicateMimeDataEPK9QMimeData);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZNK10TextEditor8Internal21ClipboardProposalItem5applyERNS_32TextDocumentManipulatorInterfaceEi
                                                                         // in
                                                                         // circularclipboardassist.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17gotoDocumentStartEv);  // ", referenced
                                                              // from:
                                                              //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_65clEPNS_16TextEditorWidgetE
                                                              // in
                                                              // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17gotoNextCharacterEv);  // ", referenced
                                                              // from:
                                                              //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_72clEPNS_16TextEditorWidgetE
                                                              // in
                                                              // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17insertCodeSnippetERK11QTextCursorRK7QString);  // ", referenced from:
                                                                                      //__ZN10TextEditor23TextDocumentManipulator17insertCodeSnippetEiRK7QString in textdocumentmanipulator.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17mouseReleaseEventEP11QMouseEvent);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                           // in
                                                                           // plaintexteditorfactory.o
                                                                           //__ZN7VcsBase19VcsBaseEditorWidget17mouseReleaseEventEP11QMouseEvent
                                                                           // in
                                                                           // vcsbaseeditor.o
                                                                           //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                           // in
                                                                           // diffeditor.o
                                                                           //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                           // in
                                                                           // sidebysidediffeditorwidget.o
                                                                           //__ZTVN10TextEditor16TextEditorWidgetE
                                                                           // in
                                                                           // moc_texteditor.o
                                                                           //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                           // in
                                                                           // moc_snippeteditor.o
                                                                           //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                           // in
                                                                           // moc_cppeditorwidget.o
                                                                           //...
unimpl(
    _ZN10TextEditor16TextEditorWidget17setBlockSelectionEb);  // ", referenced
                                                              // from:
                                                              //__ZN10DiffEditor8Internal20SideDiffEditorWidget8clearAllERK7QString
                                                              // in
                                                              // sidebysidediffeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17setCursorPositionEi);  // ", referenced
                                                              // from:
                                                              //__ZN10TextEditor20CodeAssistantPrivate21handlePrefixExpansionERK7QString
                                                              // in
                                                              // codeassistant.o
                                                              //__ZN10TextEditor23TextDocumentManipulator17setCursorPositionEi
                                                              // in
                                                              // textdocumentmanipulator.o
                                                              //__ZN17CppAssistProposal14makeCorrectionEPN10TextEditor16TextEditorWidgetE
                                                              // in
                                                              // cppcompletionassist.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17setMarginSettingsERKNS_14MarginSettingsE);  // ", referenced from:
                                                                                   //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                   //__ZN10DiffEditor8Internal23DescriptionEditorWidget17setMarginSettingsERKN10TextEditor14MarginSettingsE in diffeditor.o
                                                                                   //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                   //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                   //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                   //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                   //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                   //...
unimpl(
    _ZN10TextEditor16TextEditorWidget17setTypingSettingsERKNS_14TypingSettingsE);  // ", referenced from:
                                                                                   //__ZNK15ProjectExplorer19EditorConfiguration14switchSettingsEPN10TextEditor16TextEditorWidgetE in editorconfiguration.o
                                                                                   //__ZN15ProjectExplorerL21switchSettings_helperIN10TextEditor18TextEditorSettingsENS_19EditorConfigurationEEEvPKT_PKT0_PNS1_16TextEditorWidgetE in editorconfiguration.o
                                                                                   //__ZN15ProjectExplorerL21switchSettings_helperINS_19EditorConfigurationEN10TextEditor18TextEditorSettingsEEEvPKT_PKT0_PNS2_16TextEditorWidgetE in editorconfiguration.o
unimpl(
    _ZN10TextEditor16TextEditorWidget17sortSelectedLinesEv);  // ", referenced
                                                              // from:
                                                              //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_53clEPNS_16TextEditorWidgetE
                                                              // in
                                                              // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18convertToPlainTextERK7QString);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZNK10DiffEditor8Internal20SideDiffEditorWidget22plainTextFromSelectionERK11QTextCursor
                                                                        // in
                                                                        // sidebysidediffeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18duplicateSelectionEv);  // ", referenced
                                                               // from:
                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_49clEPNS_16TextEditorWidgetE
                                                               // in
                                                               // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18insertFromMimeDataEPK9QMimeData);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                          // in
                                                                          // plaintexteditorfactory.o
                                                                          //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                          // in
                                                                          // diffeditor.o
                                                                          //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                          // in
                                                                          // sidebysidediffeditorwidget.o
                                                                          //__ZTVN10TextEditor16TextEditorWidgetE
                                                                          // in
                                                                          // moc_texteditor.o
                                                                          //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                          // in
                                                                          // moc_snippeteditor.o
                                                                          //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                          // in
                                                                          // moc_cppeditorwidget.o
                                                                          //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                          // in
                                                                          // moc_qmljseditor.o
                                                                          //...
unimpl(
    _ZN10TextEditor16TextEditorWidget18lowercaseSelectionEv);  // ", referenced
                                                               // from:
                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_52clEPNS_16TextEditorWidgetE
                                                               // in
                                                               // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18pasteWithoutFormatEv);  // ", referenced
                                                               // from:
                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_39clEPNS_16TextEditorWidgetE
                                                               // in
                                                               // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18setContextHelpItemERKN4Core8HelpItemE);  // ", referenced from:
                                                                                //__ZN10TextEditor16BaseHoverHandler13checkPriorityEPNS_16TextEditorWidgetEiNSt3__18functionIFviEEE in basehoverhandler.o
                                                                                //__ZN10TextEditor16BaseHoverHandler15propagateHelpIdEPNS_16TextEditorWidgetERKNSt3__18functionIFvRKN4Core8HelpItemEEEE in basehoverhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18setDisplaySettingsERKNS_15DisplaySettingsE);  // ", referenced from:
                                                                                     //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                     //__ZN10DiffEditor8Internal23DescriptionEditorWidgetC2EP7QWidget in diffeditor.o
                                                                                     //__ZN10DiffEditor8Internal23DescriptionEditorWidget18setDisplaySettingsERKN10TextEditor15DisplaySettingsE in diffeditor.o
                                                                                     //__ZN10DiffEditor8Internal20SideDiffEditorWidgetC2EP7QWidget in sidebysidediffeditorwidget.o
                                                                                     //__ZN10DiffEditor8Internal20SideDiffEditorWidget18setDisplaySettingsERKN10TextEditor15DisplaySettingsE in sidebysidediffeditorwidget.o
                                                                                     //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidgetC2EP7QWidget in unifieddiffeditorwidget.o
                                                                                     //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidget18setDisplaySettingsERKN10TextEditor15DisplaySettingsE in unifieddiffeditorwidget.o
                                                                                     //...
unimpl(
    _ZN10TextEditor16TextEditorWidget18setExtraSelectionsEN5Utils2IdERK5QListIN9QTextEdit14ExtraSelectionEE);  // ", referenced from:
                                                                                                               //__ZN9CppEditor8Internal15CppEditorWidget21onCodeWarningsUpdatedEj5QListIN9QTextEdit14ExtraSelectionEERKS2_IN10TextEditor14RefactorMarkerEE in cppeditorwidget.o
                                                                                                               //__ZN9CppEditor8Internal15CppEditorWidget38finalizeInitializationAfterDuplicationEPN10TextEditor16TextEditorWidgetE in cppeditorwidget.o
                                                                                                               //__ZZN9CppEditor8Internal15CppEditorWidget23renameSymbolUnderCursorEvENK3$_0clERK7QStringRKN12ClangBackEnd24SourceLocationsContainerEi in cppeditorwidget.o
                                                                                                               //__ZN9CppEditor8Internal16CppLocalRenaming32updateEditorWidgetWithSelectionsEv in cpplocalrenaming.o
                                                                                                               //__ZN9CppEditor8Internal23CppUseSelectionsUpdater19updateUseSelectionsERK7QVectorIN8CppTools10CursorInfo5RangeEE in cppuseselectionsupdater.o
                                                                                                               //__ZN9CppEditor8Internal23CppUseSelectionsUpdater22updateUnusedSelectionsERK7QVectorIN8CppTools10CursorInfo5RangeEE in cppuseselectionsupdater.o
                                                                                                               //__ZN15ProjectExplorer20ExtraCompilerPrivate12updateIssuesEv in extracompiler.o
                                                                                                               //...
unimpl(
    _ZN10TextEditor16TextEditorWidget18setRefactorMarkersERK5QListINS_14RefactorMarkerEE);  // ", referenced from:
                                                                                            //__ZN9CppEditor8Internal15CppEditorWidget21onCodeWarningsUpdatedEj5QListIN9QTextEdit14ExtraSelectionEERKS2_IN10TextEditor14RefactorMarkerEE in cppeditorwidget.o
                                                                                            //__ZN9CppEditor8Internal19FunctionDeclDefLink10hideMarkerEPNS0_15CppEditorWidgetE in cppfunctiondecldeflink.o
                                                                                            //__ZN9CppEditor8Internal19FunctionDeclDefLink10showMarkerEPNS0_15CppEditorWidgetE in cppfunctiondecldeflink.o
                                                                                            //__ZN11QmlJSEditor17QmlJSEditorWidget17updateContextPaneEv in qmljseditor.o
                                                                                            //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv in qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18setStorageSettingsERKNS_15StorageSettingsE);  // ", referenced from:
                                                                                     //__ZNK15ProjectExplorer19EditorConfiguration14switchSettingsEPN10TextEditor16TextEditorWidgetE in editorconfiguration.o
                                                                                     //__ZN15ProjectExplorerL21switchSettings_helperIN10TextEditor18TextEditorSettingsENS_19EditorConfigurationEEEvPKT_PKT0_PNS1_16TextEditorWidgetE in editorconfiguration.o
                                                                                     //__ZN15ProjectExplorerL21switchSettings_helperINS_19EditorConfigurationEN10TextEditor18TextEditorSettingsEEEvPKT_PKT0_PNS2_16TextEditorWidgetE in editorconfiguration.o
unimpl(
    _ZN10TextEditor16TextEditorWidget18unCommentSelectionEv);  // ", referenced
                                                               // from:
                                                               //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                               // in
                                                               // plaintexteditorfactory.o
                                                               //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                               // in
                                                               // diffeditor.o
                                                               //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                               // in
                                                               // sidebysidediffeditorwidget.o
                                                               //__ZTVN10TextEditor16TextEditorWidgetE
                                                               // in
                                                               // moc_texteditor.o
                                                               //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                               // in
                                                               // moc_snippeteditor.o
                                                               //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                               // in
                                                               // moc_cppeditorwidget.o
                                                               //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                               // in
                                                               // moc_qmljseditor.o
                                                               //...
unimpl(
    _ZN10TextEditor16TextEditorWidget18uppercaseSelectionEv);  // ", referenced
                                                               // from:
                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_51clEPNS_16TextEditorWidgetE
                                                               // in
                                                               // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget19extraAreaLeaveEventEP6QEvent);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                       // in
                                                                       // plaintexteditorfactory.o
                                                                       //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                       // in
                                                                       // diffeditor.o
                                                                       //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                       // in
                                                                       // sidebysidediffeditorwidget.o
                                                                       //__ZTVN10TextEditor16TextEditorWidgetE
                                                                       // in
                                                                       // moc_texteditor.o
                                                                       //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                       // in
                                                                       // moc_snippeteditor.o
                                                                       //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                       // in
                                                                       // moc_cppeditorwidget.o
                                                                       //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                       // in
                                                                       // moc_qmljseditor.o
                                                                       //...
unimpl(
    _ZN10TextEditor16TextEditorWidget19extraAreaMouseEventEP11QMouseEvent);  // ", referenced from:
                                                                             //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                             //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                             //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                             //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                             //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                             //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                             //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                             //...
unimpl(
    _ZN10TextEditor16TextEditorWidget19extraAreaPaintEventEP11QPaintEvent);  // ", referenced from:
                                                                             //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                             //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                             //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                             //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                             //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                             //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                             //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                             //...
unimpl(
    _ZN10TextEditor16TextEditorWidget19openLinkUnderCursorEv);  // ", referenced
                                                                // from:
                                                                //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_27clEPNS_16TextEditorWidgetE
                                                                // in
                                                                // texteditoractionhandler.o
                                                                //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_31clEPNS_16TextEditorWidgetE
                                                                // in
                                                                // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget19setBehaviorSettingsERKNS_16BehaviorSettingsE);  // ", referenced from:
                                                                                       //__ZNK15ProjectExplorer19EditorConfiguration14switchSettingsEPN10TextEditor16TextEditorWidgetE in editorconfiguration.o
                                                                                       //__ZN15ProjectExplorerL21switchSettings_helperIN10TextEditor18TextEditorSettingsENS_19EditorConfigurationEEEvPKT_PKT0_PNS1_16TextEditorWidgetE in editorconfiguration.o
                                                                                       //__ZN15ProjectExplorerL21switchSettings_helperINS_19EditorConfigurationEN10TextEditor18TextEditorSettingsEEEvPKT_PKT0_PNS2_16TextEditorWidgetE in editorconfiguration.o
unimpl(
    _ZN10TextEditor16TextEditorWidget19setIfdefedOutBlocksERK5QListINS_10BlockRangeEE);  // ", referenced from:
                                                                                         //__ZN9CppEditor8Internal15CppEditorWidget25onIfdefedOutBlocksUpdatedEj5QListIN10TextEditor10BlockRangeEE in cppeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget19setRevisionsVisibleEb);  // ", referenced
                                                                // from:
                                                                //__ZN7VcsBase19VcsBaseEditorWidget4initEv
                                                                // in
                                                                // vcsbaseeditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget19setupFallBackEditorEN5Utils2IdE);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                                                          // in
                                                                          // snippeteditor.o
                                                                          //__ZN10DiffEditor8Internal23DescriptionEditorWidgetC2EP7QWidget
                                                                          // in
                                                                          // diffeditor.o
                                                                          //__ZN10DiffEditor8Internal26SelectableTextEditorWidgetC2EN5Utils2IdEP7QWidget
                                                                          // in
                                                                          // selectabletexteditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21CodeWarningsSelectionE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN9CppEditor8Internal15CppEditorWidget21onCodeWarningsUpdatedEj5QListIN9QTextEdit14ExtraSelectionEERKS2_IN10TextEditor14RefactorMarkerEE
                                                                 // in
                                                                 // cppeditorwidget.o
                                                                 //__ZN9CppEditor8Internal15CppEditorWidget38finalizeInitializationAfterDuplicationEPN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // cppeditorwidget.o
                                                                 //__ZN8CppTools19CppElementEvaluator22checkDiagnosticMessageEi
                                                                 // in
                                                                 // cppelementevaluator.o
                                                                 //__ZN15ProjectExplorer20ExtraCompilerPrivate12updateIssuesEv
                                                                 // in
                                                                 // extracompiler.o
                                                                 //__ZN11QmlJSEditor17QmlJSEditorWidget18updateCodeWarningsE14QSharedPointerIKN5QmlJS8DocumentEE
                                                                 // in
                                                                 // qmljseditor.o
                                                                 //__ZN11QmlJSEditor17QmlJSHoverHandler22matchDiagnosticMessageEPNS_17QmlJSEditorWidgetEi
                                                                 // in
                                                                 // qmljshoverhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21UnusedSymbolSelectionE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN9CppEditor8Internal23CppUseSelectionsUpdater22updateUnusedSelectionsERK7QVectorIN8CppTools10CursorInfo5RangeEE
                                                                 // in
                                                                 // cppuseselectionsupdater.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21gotoNextWordCamelCaseEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_76clEPNS_16TextEditorWidgetE
                                                                  // in
                                                                  // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21gotoPreviousCharacterEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_71clEPNS_16TextEditorWidgetE
                                                                  // in
                                                                  // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21mouseDoubleClickEventEP11QMouseEvent);  // ", referenced from:
                                                                               //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                               //__ZN7VcsBase19VcsBaseEditorWidget21mouseDoubleClickEventEP11QMouseEvent in vcsbaseeditor.o
                                                                               //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                               //__ZN10DiffEditor8Internal20SideDiffEditorWidget21mouseDoubleClickEventEP11QMouseEvent in sidebysidediffeditorwidget.o
                                                                               //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidget21mouseDoubleClickEventEP11QMouseEvent in unifieddiffeditorwidget.o
                                                                               //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                               //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                               //...
unimpl(
    _ZN10TextEditor16TextEditorWidget21selectWordUnderCursorEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_64clEPNS_16TextEditorWidgetE
                                                                  // in
                                                                  // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21setLanguageSettingsIdEN5Utils2IdE);  // ", referenced from:
                                                                            //__ZN9CppEditor8Internal15CppEditorWidget22finalizeInitializationEv
                                                                            // in
                                                                            // cppeditorwidget.o
                                                                            //__ZN11QmlJSEditor17QmlJSEditorWidgetC2Ev
                                                                            // in
                                                                            // qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21setLineNumbersVisibleEb);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                                                  // in
                                                                  // snippeteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21setRequestMarkEnabledEb);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE
                                                                  // in
                                                                  // disassembleragent.o
                                                                  //__ZN8Debugger8Internal11SourceAgent10setContentERK7QStringS4_
                                                                  // in
                                                                  // sourceagent.o
                                                                  //__ZN11QmlJSEditor17QmlJSEditorWidget22finalizeInitializationEv
                                                                  // in
                                                                  // qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget21triggerPendingUpdatesEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                  // in
                                                                  // plaintexteditorfactory.o
                                                                  //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                  // in
                                                                  // diffeditor.o
                                                                  //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                  // in
                                                                  // sidebysidediffeditorwidget.o
                                                                  //__ZTVN10TextEditor16TextEditorWidgetE
                                                                  // in
                                                                  // moc_texteditor.o
                                                                  //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                  // in
                                                                  // moc_snippeteditor.o
                                                                  //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                  // in
                                                                  // moc_cppeditorwidget.o
                                                                  //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                  // in
                                                                  // moc_qmljseditor.o
                                                                  //...
unimpl(
    _ZN10TextEditor16TextEditorWidget22CodeSemanticsSelectionE);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZZN9CppEditor8Internal15CppEditorWidget23renameSymbolUnderCursorEvENK3$_0clERK7QStringRKN12ClangBackEnd24SourceLocationsContainerEi
                                                                  // in
                                                                  // cppeditorwidget.o
                                                                  //__ZN9CppEditor8Internal16CppLocalRenaming32updateEditorWidgetWithSelectionsEv
                                                                  // in
                                                                  // cpplocalrenaming.o
                                                                  //__ZNK9CppEditor8Internal23CppUseSelectionsUpdater20currentUseSelectionsEv
                                                                  // in
                                                                  // cppuseselectionsupdater.o
                                                                  //__ZN9CppEditor8Internal23CppUseSelectionsUpdater19updateUseSelectionsERK7QVectorIN8CppTools10CursorInfo5RangeEE
                                                                  // in
                                                                  // cppuseselectionsupdater.o
                                                                  //__ZN11QmlJSEditor17QmlJSEditorWidget10updateUsesEv
                                                                  // in
                                                                  // qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget23currentTextEditorWidgetEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN10TextEditor17formatCurrentFileERKNS_7CommandEii
                                                                    // in
                                                                    // formattexteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget23drawCollapsedBlockPopupER8QPainterRK10QTextBlock7QPointFRK5QRect);  // ", referenced from:
                                                                                                           //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                                           //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                                           //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                                           //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                                           //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                                           //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                                           //__ZTVN7VcsBase19VcsBaseEditorWidgetE in moc_vcsbaseeditor.o
                                                                                                           //...
unimpl(
    _ZN10TextEditor16TextEditorWidget23renameSymbolUnderCursorEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                    // in
                                                                    // plaintexteditorfactory.o
                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZTVN10TextEditor16TextEditorWidgetE
                                                                    // in
                                                                    // moc_texteditor.o
                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                    // in
                                                                    // moc_snippeteditor.o
                                                                    //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                                    // in
                                                                    // moc_vcsbaseeditor.o
                                                                    //__ZTVN10DiffEditor8Internal26SelectableTextEditorWidgetE
                                                                    // in
                                                                    // moc_selectabletexteditorwidget.o
                                                                    //...
unimpl(
    _ZN10TextEditor16TextEditorWidget23setCodeFoldingSupportedEb);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN7VcsBase19VcsBaseEditorWidget4initEv
                                                                    // in
                                                                    // vcsbaseeditor.o
                                                                    //__ZN10DiffEditor8Internal23DescriptionEditorWidgetC2EP7QWidget
                                                                    // in
                                                                    // diffeditor.o
                                                                    //__ZN10DiffEditor8Internal20SideDiffEditorWidgetC2EP7QWidget
                                                                    // in
                                                                    // sidebysidediffeditorwidget.o
                                                                    //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidgetC2EP7QWidget
                                                                    // in
                                                                    // unifieddiffeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget23setHighlightCurrentLineEb);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                                                    // in
                                                                    // snippeteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget24deleteEndOfWordCamelCaseEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_11clEPNS_16TextEditorWidgetE
                                                                     // in
                                                                     // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget24gotoLineEndWithSelectionEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_78clEPNS_16TextEditorWidgetE
                                                                     // in
                                                                     // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget24insertExtraToolBarWidgetENS0_4SideEP7QWidget);  // ", referenced from:
                                                                                       //__ZN9CppEditor8Internal15CppEditorWidget22finalizeInitializationEv in cppeditorwidget.o
                                                                                       //__ZZN9CppEditor8Internal15CppEditorWidget22finalizeInitializationEvENK3$_7clEP7QWidget in cppeditorwidget.o
                                                                                       //__ZN11QmlJSEditor17QmlJSEditorWidget13createToolBarEv in qmljseditor.o
                                                                                       //__ZN7VcsBase8Internal26VcsBaseEditorWidgetPrivate15entriesComboBoxEv in vcsbaseeditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget24openFinishedSuccessfullyEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                     // in
                                                                     // plaintexteditorfactory.o
                                                                     //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                     // in
                                                                     // diffeditor.o
                                                                     //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                     // in
                                                                     // sidebysidediffeditorwidget.o
                                                                     //__ZTVN10TextEditor16TextEditorWidgetE
                                                                     // in
                                                                     // moc_texteditor.o
                                                                     //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                     // in
                                                                     // moc_snippeteditor.o
                                                                     //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                     // in
                                                                     // moc_cppeditorwidget.o
                                                                     //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                     // in
                                                                     // moc_qmljseditor.o
                                                                     //...
unimpl(
    _ZN10TextEditor16TextEditorWidget24setExtraEncodingSettingsERKNS_21ExtraEncodingSettingsE);  // ", referenced from:
                                                                                                 //__ZNK15ProjectExplorer19EditorConfiguration14switchSettingsEPN10TextEditor16TextEditorWidgetE in editorconfiguration.o
                                                                                                 //__ZN15ProjectExplorerL21switchSettings_helperIN10TextEditor18TextEditorSettingsENS_19EditorConfigurationEEEvPKT_PKT0_PNS1_16TextEditorWidgetE in editorconfiguration.o
                                                                                                 //__ZN15ProjectExplorerL21switchSettings_helperINS_19EditorConfigurationEN10TextEditor18TextEditorSettingsEEEvPKT_PKT0_PNS2_16TextEditorWidgetE in editorconfiguration.o
unimpl(
    _ZN10TextEditor16TextEditorWidget25extraAreaContextMenuEventEP17QContextMenuEvent);  // ", referenced from:
                                                                                         //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                         //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                         //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                         //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                         //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                         //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                         //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                         //...
unimpl(
    _ZN10TextEditor16TextEditorWidget25gotoBlockEndWithSelectionEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_16clEPNS_16TextEditorWidgetE
                                                                      // in
                                                                      // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget25gotoNextLineWithSelectionEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_79clEPNS_16TextEditorWidgetE
                                                                      // in
                                                                      // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget25gotoNextWordWithSelectionEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_84clEPNS_16TextEditorWidgetE
                                                                      // in
                                                                      // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget25gotoPreviousWordCamelCaseEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_75clEPNS_16TextEditorWidgetE
                                                                      // in
                                                                      // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget25slotCursorPositionChangedEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                      // in
                                                                      // plaintexteditorfactory.o
                                                                      //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                      // in
                                                                      // diffeditor.o
                                                                      //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                      // in
                                                                      // sidebysidediffeditorwidget.o
                                                                      //__ZTVN10TextEditor16TextEditorWidgetE
                                                                      // in
                                                                      // moc_texteditor.o
                                                                      //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                      // in
                                                                      // moc_snippeteditor.o
                                                                      //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                      // in
                                                                      // moc_cppeditorwidget.o
                                                                      //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                      // in
                                                                      // moc_qmljseditor.o
                                                                      //...
unimpl(
    _ZN10TextEditor16TextEditorWidget26deleteStartOfWordCamelCaseEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_14clEPNS_16TextEditorWidgetE
                                                                       // in
                                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget26gotoLineStartWithSelectionEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_77clEPNS_16TextEditorWidgetE
                                                                       // in
                                                                       // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget27configureGenericHighlighterEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN8Debugger8Internal24DisassemblerAgentPrivate17configureMimeTypeEv
                                                                        // in
                                                                        // disassembleragent.o
                                                                        //__ZN10TextEditor11Highlighter6reloadEv
                                                                        // in
                                                                        // highlighter.o
unimpl(
    _ZN10TextEditor16TextEditorWidget27gotoBlockStartWithSelectionEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_15clEPNS_16TextEditorWidgetE
                                                                        // in
                                                                        // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget27keepAutoCompletionHighlightEb);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN10TextEditor20CodeAssistantPrivate14destroyContextEv
                                                                        // in
                                                                        // codeassistant.o
                                                                        //__ZN10TextEditor20CodeAssistantPrivate15displayProposalEPNS_15IAssistProposalENS_12AssistReasonE
                                                                        // in
                                                                        // codeassistant.o
unimpl(
    _ZN10TextEditor16TextEditorWidget27setAutoCompleteSkipPositionERK11QTextCursor);  // ", referenced from:
                                                                                      //__ZN10TextEditor23TextDocumentManipulator27setAutoCompleteSkipPositionEi in textdocumentmanipulator.o
unimpl(
    _ZN10TextEditor16TextEditorWidget28duplicateSelectionAndCommentEv);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_50clEPNS_16TextEditorWidgetE
                                                                         // in
                                                                         // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget28slotCodeStyleSettingsChangedERK8QVariant);  // ", referenced from:
                                                                                   //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                   //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                   //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                   //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                   //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                   //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                   //__ZTVN7VcsBase19VcsBaseEditorWidgetE in moc_vcsbaseeditor.o
                                                                                   //...
unimpl(
    _ZN10TextEditor16TextEditorWidget29gotoPreviousLineWithSelectionEv);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_80clEPNS_16TextEditorWidgetE
                                                                          // in
                                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget29gotoPreviousWordWithSelectionEv);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_83clEPNS_16TextEditorWidgetE
                                                                          // in
                                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget29setParenthesesMatchingEnabledEb);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                                                          // in
                                                                          // snippeteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget30gotoNextCharacterWithSelectionEv);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_82clEPNS_16TextEditorWidgetE
                                                                           // in
                                                                           // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget30openLinkUnderCursorInNextSplitEv);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_28clEPNS_16TextEditorWidgetE
                                                                           // in
                                                                           // texteditoractionhandler.o
                                                                           //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_32clEPNS_16TextEditorWidgetE
                                                                           // in
                                                                           // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget32appendStandardContextMenuActionsEP5QMenu);  // ", referenced from:
                                                                                   //__ZN9CppEditor8Internal15CppEditorWidget16contextMenuEventEP17QContextMenuEvent in cppeditorwidget.o
                                                                                   //__ZN11QmlJSEditor17QmlJSEditorWidget16contextMenuEventEP17QContextMenuEvent in qmljseditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget34gotoNextWordCamelCaseWithSelectionEv);  // ", referenced from:
                                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_86clEPNS_16TextEditorWidgetE in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget34gotoPreviousCharacterWithSelectionEv);  // ", referenced from:
                                                                               //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_81clEPNS_16TextEditorWidgetE in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget38gotoPreviousWordCamelCaseWithSelectionEv);  // ", referenced from:
                                                                                   //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_85clEPNS_16TextEditorWidgetE in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget3cutEv);  // ", referenced from:
                                               //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                               // in plaintexteditorfactory.o
                                               //__ZN9CppEditor8Internal15CppEditorWidget3cutEv
                                               // in cppeditorwidget.o
                                               //__ZN9CppEditor8Internal16CppLocalRenaming9handleCutEv
                                               // in cpplocalrenaming.o
                                               //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                               // in diffeditor.o
                                               //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                               // in
                                               // sidebysidediffeditorwidget.o
                                               //__ZTVN10TextEditor16TextEditorWidgetE
                                               // in moc_texteditor.o
                                               //__ZTVN10TextEditor19SnippetEditorWidgetE
                                               // in moc_snippeteditor.o
                                               //...
unimpl(
    _ZN10TextEditor16TextEditorWidget4copyEv);  // ", referenced from:
                                                //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                // in plaintexteditorfactory.o
                                                //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                // in diffeditor.o
                                                //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                // in
                                                // sidebysidediffeditorwidget.o
                                                //__ZTVN10TextEditor16TextEditorWidgetE
                                                // in moc_texteditor.o
                                                //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                // in moc_snippeteditor.o
                                                //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                // in moc_cppeditorwidget.o
                                                //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                // in moc_qmljseditor.o
                                                //...
unimpl(
    _ZN10TextEditor16TextEditorWidget4foldEv);  // ", referenced from:
                                                //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_54clEPNS_16TextEditorWidgetE
                                                // in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget4redoEv);  // ", referenced from:
                                                //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_1clEPNS_16TextEditorWidgetE
                                                // in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget4undoEv);  // ", referenced from:
                                                //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_0clEPNS_16TextEditorWidgetE
                                                // in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget5eventEP6QEvent);  // ", referenced from:
                                                        //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                        // in
                                                        // plaintexteditorfactory.o
                                                        //__ZN9CppEditor8Internal15CppEditorWidget5eventEP6QEvent
                                                        // in cppeditorwidget.o
                                                        //__ZN11QmlJSEditor17QmlJSEditorWidget5eventEP6QEvent
                                                        // in qmljseditor.o
                                                        //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                        // in diffeditor.o
                                                        //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                        // in
                                                        // sidebysidediffeditorwidget.o
                                                        //__ZTVN10TextEditor16TextEditorWidgetE
                                                        // in moc_texteditor.o
                                                        //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                        // in
                                                        // moc_snippeteditor.o
                                                        //...
unimpl(
    _ZN10TextEditor16TextEditorWidget5pasteEv);  // ", referenced from:
                                                 //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                 // in plaintexteditorfactory.o
                                                 //__ZN9CppEditor8Internal15CppEditorWidget5pasteEv
                                                 // in cppeditorwidget.o
                                                 //__ZN9CppEditor8Internal16CppLocalRenaming11handlePasteEv
                                                 // in cpplocalrenaming.o
                                                 //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                 // in diffeditor.o
                                                 //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                 // in
                                                 // sidebysidediffeditorwidget.o
                                                 //__ZTVN10TextEditor16TextEditorWidgetE
                                                 // in moc_texteditor.o
                                                 //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                 // in moc_snippeteditor.o
                                                 //...
unimpl(
    _ZN10TextEditor16TextEditorWidget5printEP8QPrinter);  // ", referenced from:
                                                          //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_7clEPNS_16TextEditorWidgetE
                                                          // in
                                                          // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget5zoomFEf);  // ", referenced from:
                                                 //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_57clEPNS_16TextEditorWidgetE
                                                 // in texteditoractionhandler.o
                                                 //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_58clEPNS_16TextEditorWidgetE
                                                 // in texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget6indentEv);  // ", referenced from:
                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_25clEPNS_16TextEditorWidgetE
                                                  // in
                                                  // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget6unfoldEv);  // ", referenced from:
                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_55clEPNS_16TextEditorWidgetE
                                                  // in
                                                  // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget7cutLineEv);  // ", referenced from:
                                                   //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_47clEPNS_16TextEditorWidgetE
                                                   // in
                                                   // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget7replaceEiRK7QString);  // ", referenced
                                                             // from:
                                                             //__ZN10TextEditor20CodeAssistantPrivate21handlePrefixExpansionERK7QString
                                                             // in
                                                             // codeassistant.o
                                                             //__ZN17CppAssistProposal14makeCorrectionEPN10TextEditor16TextEditorWidgetE
                                                             // in
                                                             // cppcompletionassist.o
unimpl(
    _ZN10TextEditor16TextEditorWidget7toolBarEv);  // ", referenced from:
                                                   //__ZN7VcsBase13VcsBaseClient4diffERK7QStringRK11QStringListS6_
                                                   // in vcsbaseclient.o
                                                   //__ZN7VcsBase13VcsBaseClient3logERK7QStringRK11QStringListS6_b
                                                   // in vcsbaseclient.o
unimpl(
    _ZN10TextEditor16TextEditorWidget8copyLineEv);  // ", referenced from:
                                                    //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_48clEPNS_16TextEditorWidgetE
                                                    // in
                                                    // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget8gotoLineEiibb);  // ", referenced from:
                                                       //__ZN9CppEditor8Internal16CppOutlineWidget16updateTextCursorERK11QModelIndex
                                                       // in cppoutline.o
                                                       //__ZN8CppTools16CppEditorOutline18gotoSymbolInEditorEv
                                                       // in cppeditoroutline.o
                                                       //__ZN7VcsBase19VcsBaseEditorWidget15slotJumpToEntryEi
                                                       // in vcsbaseeditor.o
                                                       //__ZN7VcsBase19VcsBaseEditorWidget21reportCommandFinishedEbiRK8QVariant
                                                       // in vcsbaseeditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidget8openLinkERKN5Utils4LinkEb);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN9CppEditor8Internal15CppEditorWidget27switchDeclarationDefinitionEb
                                                                   // in
                                                                   // cppeditorwidget.o
unimpl(
    _ZN10TextEditor16TextEditorWidget8unindentEv);  // ", referenced from:
                                                    //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_26clEPNS_16TextEditorWidgetE
                                                    // in
                                                    // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget9dropEventEP10QDropEvent);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                 // in
                                                                 // plaintexteditorfactory.o
                                                                 //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                 // in
                                                                 // diffeditor.o
                                                                 //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                 // in
                                                                 // sidebysidediffeditorwidget.o
                                                                 //__ZTVN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // moc_texteditor.o
                                                                 //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                 // in
                                                                 // moc_snippeteditor.o
                                                                 //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                 // in
                                                                 // moc_cppeditorwidget.o
                                                                 //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                 // in
                                                                 // moc_qmljseditor.o
                                                                 //...
unimpl(
    _ZN10TextEditor16TextEditorWidget9joinLinesEv);  // ", referenced from:
                                                     //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_21clEPNS_16TextEditorWidgetE
                                                     // in
                                                     // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget9selectAllEv);  // ", referenced from:
                                                     //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                     // in
                                                     // plaintexteditorfactory.o
                                                     //__ZN9CppEditor8Internal15CppEditorWidget9selectAllEv
                                                     // in cppeditorwidget.o
                                                     //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                     // in diffeditor.o
                                                     //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                     // in
                                                     // sidebysidediffeditorwidget.o
                                                     //__ZTVN10TextEditor16TextEditorWidgetE
                                                     // in moc_texteditor.o
                                                     //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                     // in moc_snippeteditor.o
                                                     //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                     // in moc_qmljseditor.o
                                                     //...
unimpl(
    _ZN10TextEditor16TextEditorWidget9showEventEP10QShowEvent);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                 // in
                                                                 // plaintexteditorfactory.o
                                                                 //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                 // in
                                                                 // diffeditor.o
                                                                 //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                 // in
                                                                 // sidebysidediffeditorwidget.o
                                                                 //__ZTVN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // moc_texteditor.o
                                                                 //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                 // in
                                                                 // moc_snippeteditor.o
                                                                 //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                 // in
                                                                 // moc_cppeditorwidget.o
                                                                 //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                 // in
                                                                 // moc_qmljseditor.o
                                                                 //...
unimpl(
    _ZN10TextEditor16TextEditorWidget9unfoldAllEv);  // ", referenced from:
                                                     //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_56clEPNS_16TextEditorWidgetE
                                                     // in
                                                     // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidget9zoomResetEv);  // ", referenced from:
                                                     //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_59clEPNS_16TextEditorWidgetE
                                                     // in
                                                     // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor16TextEditorWidgetC2EP7QWidget);  // ", referenced from:
                                                     //__ZN10TextEditor21PlainTextEditorWidgetC2Ev
                                                     // in
                                                     // plaintexteditorfactory.o
                                                     //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                                     // in snippeteditor.o
                                                     //__ZN9CppEditor8Internal15CppEditorWidgetC2Ev
                                                     // in cppeditorwidget.o
                                                     //__ZN11QmlJSEditor17QmlJSEditorWidgetC2Ev
                                                     // in qmljseditor.o
                                                     //__ZN7VcsBase19VcsBaseEditorWidgetC2Ev
                                                     // in vcsbaseeditor.o
                                                     //__ZN10DiffEditor8Internal23DescriptionEditorWidgetC2EP7QWidget
                                                     // in diffeditor.o
                                                     //__ZN10DiffEditor8Internal26SelectableTextEditorWidgetC2EN5Utils2IdEP7QWidget
                                                     // in
                                                     // selectabletexteditorwidget.o
                                                     //...
unimpl(
    _ZN10TextEditor16TextEditorWidgetD0Ev);  // ", referenced from:
                                             //__ZTVN10TextEditor16TextEditorWidgetE
                                             // in moc_texteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidgetD1Ev);  // ", referenced from:
                                             //__ZTVN10TextEditor16TextEditorWidgetE
                                             // in moc_texteditor.o
unimpl(
    _ZN10TextEditor16TextEditorWidgetD2Ev);  // ", referenced from:
                                             //__ZN10TextEditor21PlainTextEditorWidgetD2Ev
                                             // in plaintexteditorfactory.o
                                             //__ZN10TextEditor19SnippetEditorWidgetC2EP7QWidget
                                             // in snippeteditor.o
                                             //__ZN9CppEditor8Internal15CppEditorWidgetC2Ev
                                             // in cppeditorwidget.o
                                             //__ZN9CppEditor8Internal15CppEditorWidgetD2Ev
                                             // in cppeditorwidget.o
                                             //__ZN11QmlJSEditor17QmlJSEditorWidgetC2Ev
                                             // in qmljseditor.o
                                             //__ZN7VcsBase19VcsBaseEditorWidgetC2Ev
                                             // in vcsbaseeditor.o
                                             //__ZN7VcsBase19VcsBaseEditorWidgetD2Ev
                                             // in vcsbaseeditor.o
                                             //...
unimpl(
    _ZN10TextEditor17FormatDescriptionC1ENS_9TextStyleERK7QStringS4_NS0_12ShowControlsE);  // ", referenced from:
                                                                                           //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_NS2_12ShowControlsEEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                           //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_EEEvPT_DpOT0_ in texteditorsettings.o
unimpl(
    _ZN10TextEditor17FormatDescriptionC1ENS_9TextStyleERK7QStringS4_RK6QColorN15QTextCharFormat14UnderlineStyleENS0_12ShowControlsE);  // ", referenced from:
                                                                                                                                       //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_N2Qt11GlobalColorEN15QTextCharFormat14UnderlineStyleEEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                                                                       //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_6QColorN15QTextCharFormat14UnderlineStyleENS2_12ShowControlsEEEEvPT_DpOT0_ in texteditorsettings.o
unimpl(
    _ZN10TextEditor17FormatDescriptionC1ENS_9TextStyleERK7QStringS4_RK6QColorNS0_12ShowControlsE);  // ", referenced from:
                                                                                                    //__ZN10TextEditor8Internal25TextEditorSettingsPrivate14initialFormatsEv in texteditorsettings.o
                                                                                                    //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_N2Qt11GlobalColorEEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                                    //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_RK6QColorEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                                    //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_6QColorEEEvPT_DpOT0_ in texteditorsettings.o
unimpl(
    _ZN10TextEditor17FormatDescriptionC1ENS_9TextStyleERK7QStringS4_RKNS_6FormatENS0_12ShowControlsE);  // ", referenced from:
                                                                                                        //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_NS1_6FormatEEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                                        //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_RNS1_6FormatEEEEvPT_DpOT0_ in texteditorsettings.o
                                                                                                        //__ZNSt3__19allocatorIN10TextEditor17FormatDescriptionEE9constructIS2_JNS1_9TextStyleE7QStringS6_RNS1_6FormatENS2_12ShowControlsEEEEvPT_DpOT0_ in texteditorsettings.o
unimpl(
    _ZN10TextEditor17TabSettingsWidget14setTabSettingsERKNS_11TabSettingsE);  // ", referenced from:
                                                                              //__ZN10TextEditor32SimpleCodeStylePreferencesWidget14setPreferencesEPNS_21ICodeStylePreferencesE in simplecodestylepreferenceswidget.o
unimpl(
    _ZN10TextEditor17TabSettingsWidgetC1EP7QWidget);  // ", referenced from:
                                                      //__ZN10TextEditor32SimpleCodeStylePreferencesWidgetC2EP7QWidget
                                                      // in
                                                      // simplecodestylepreferenceswidget.o
unimpl(
    _ZN10TextEditor17TabSettingsWidgetD0Ev);  // ", referenced from:
                                              //__ZTVN10TextEditor17TabSettingsWidgetE
                                              // in moc_tabsettingswidget.o
unimpl(
    _ZN10TextEditor17TabSettingsWidgetD1Ev);  // ", referenced from:
                                              //__ZTVN10TextEditor17TabSettingsWidgetE
                                              // in moc_tabsettingswidget.o
unimpl(
    _ZN10TextEditor17TextEditorFactory15addHoverHandlerEPNS_16BaseHoverHandlerE);  // ", referenced from:
                                                                                   //__ZN10TextEditor22PlainTextEditorFactoryC2Ev in plaintexteditorfactory.o
                                                                                   //__ZN9CppEditor8Internal15CppEditorPlugin21extensionsInitializedEv in cppeditorplugin.o
                                                                                   //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactory15setMarksVisibleEb);  // ", referenced
                                                             // from:
                                                             //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE
                                                             // in
                                                             // basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory16setEditorCreatorERKNSt3__18functionIFPNS_14BaseTextEditorEvEEE);  // ", referenced from:
                                                                                                          //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev in cppeditorplugin.o
                                                                                                          //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
                                                                                                          //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE in basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory18setDocumentCreatorERKNSt3__18functionIFPNS_12TextDocumentEvEEE);  // ", referenced from:
                                                                                                          //__ZN10TextEditor22PlainTextEditorFactoryC2Ev in plaintexteditorfactory.o
                                                                                                          //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev in cppeditorplugin.o
                                                                                                          //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
                                                                                                          //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE in basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory20setCommentDefinitionEN5Utils17CommentDefinitionE);  // ", referenced from:
                                                                                            //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev in cppeditorplugin.o
                                                                                            //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactory22setDuplicatedSupportedEb);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE
                                                                    // in
                                                                    // basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory22setEditorWidgetCreatorERKNSt3__18functionIFP7QWidgetvEEE);  // ", referenced from:
                                                                                                    //__ZN10TextEditor22PlainTextEditorFactoryC2Ev in plaintexteditorfactory.o
                                                                                                    //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev in cppeditorplugin.o
                                                                                                    //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
                                                                                                    //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE in basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory23setAutoCompleterCreatorERKNSt3__18functionIFPNS_13AutoCompleterEvEEE);  // ", referenced from:
                                                                                                                //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev in cppeditorplugin.o
                                                                                                                //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactory23setCodeFoldingSupportedEb);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev
                                                                     // in
                                                                     // cppeditorplugin.o
                                                                     //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE
                                                                     // in
                                                                     // qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactory23setEditorActionHandlersEj);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN10TextEditor22PlainTextEditorFactoryC2Ev
                                                                     // in
                                                                     // plaintexteditorfactory.o
                                                                     //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev
                                                                     // in
                                                                     // cppeditorplugin.o
                                                                     //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE
                                                                     // in
                                                                     // qmljseditor.o
                                                                     //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE
                                                                     // in
                                                                     // basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory24setUseGenericHighlighterEb);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN10TextEditor22PlainTextEditorFactoryC2Ev
                                                                      // in
                                                                      // plaintexteditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactory27setCompletionAssistProviderEPNS_24CompletionAssistProviderE);  // ", referenced from:
                                                                                                       //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE in qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactory29setParenthesesMatchingEnabledEb);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev
                                                                           // in
                                                                           // cppeditorplugin.o
                                                                           //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE
                                                                           // in
                                                                           // qmljseditor.o
unimpl(
    _ZN10TextEditor17TextEditorFactoryC2Ev);  // ", referenced from:
                                              //__ZN10TextEditor22PlainTextEditorFactoryC2Ev
                                              // in plaintexteditorfactory.o
                                              //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev
                                              // in cppeditorplugin.o
                                              //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE
                                              // in qmljseditor.o
                                              //__ZN7VcsBase16VcsEditorFactoryC2EPKNS_23VcsBaseEditorParametersENSt3__18functionIFP7QWidgetvEEENS5_IFvRK7QStringSC_EEE
                                              // in basevcseditorfactory.o
unimpl(
    _ZN10TextEditor17TextEditorFactoryD2Ev);  // ", referenced from:
                                              //__ZN10TextEditor22PlainTextEditorFactoryD2Ev
                                              // in texteditorplugin.o
                                              //__ZN10TextEditor22PlainTextEditorFactoryC2Ev
                                              // in plaintexteditorfactory.o
                                              //__ZN10TextEditor22PlainTextEditorFactoryD2Ev
                                              // in plaintexteditorfactory.o
                                              //__ZN9CppEditor8Internal16CppEditorFactoryC2Ev
                                              // in cppeditorplugin.o
                                              //__ZN9CppEditor8Internal16CppEditorFactoryD2Ev
                                              // in cppeditorplugin.o
                                              //__ZN11QmlJSEditor18QmlJSEditorFactoryC2EN5Utils2IdE
                                              // in qmljseditor.o
                                              //__ZN11QmlJSEditor18QmlJSEditorFactoryD2Ev
                                              // in qmljseditor.o
                                              //...
unimpl(
    _ZN10TextEditor19DisplaySettingsPageC1Ev);  // ", referenced from:
                                                //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                // in texteditorsettings.o
unimpl(
    _ZN10TextEditor19DisplaySettingsPageD1Ev);  // ", referenced from:
                                                //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                // in texteditorsettings.o
                                                //__ZN10TextEditor8Internal25TextEditorSettingsPrivateD2Ev
                                                // in texteditorsettings.o
unimpl(
    _ZN10TextEditor19TextEditorLinkLabel7setLinkEN5Utils4LinkE);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN9CppEditor8Internal25CppIncludeHierarchyWidget7performEv
                                                                  // in
                                                                  // cppincludehierarchy.o
                                                                  //__ZN9CppEditor8Internal22CppTypeHierarchyWidget16displayHierarchyEv
                                                                  // in
                                                                  // cpptypehierarchy.o
unimpl(
    _ZN10TextEditor19TextEditorLinkLabelC1EP7QWidget);  // ", referenced from:
                                                        //__ZN9CppEditor8Internal25CppIncludeHierarchyWidgetC2Ev
                                                        // in
                                                        // cppincludehierarchy.o
                                                        //__ZN9CppEditor8Internal22CppTypeHierarchyWidgetC2Ev
                                                        // in cpptypehierarchy.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPage5applyEv);  // ", referenced from:
                                                     //__ZTVN10TextEditor20BehaviorSettingsPageE
                                                     // in
                                                     // moc_behaviorsettingspage.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPage6finishEv);  // ", referenced from:
                                                      //__ZTVN10TextEditor20BehaviorSettingsPageE
                                                      // in
                                                      // moc_behaviorsettingspage.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPage6widgetEv);  // ", referenced from:
                                                      //__ZTVN10TextEditor20BehaviorSettingsPageE
                                                      // in
                                                      // moc_behaviorsettingspage.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPageC1Ev);  // ", referenced from:
                                                 //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                 // in texteditorsettings.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPageD0Ev);  // ", referenced from:
                                                 //__ZTVN10TextEditor20BehaviorSettingsPageE
                                                 // in
                                                 // moc_behaviorsettingspage.o
unimpl(
    _ZN10TextEditor20BehaviorSettingsPageD1Ev);  // ", referenced from:
                                                 //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                 // in texteditorsettings.o
                                                 //__ZN10TextEditor8Internal25TextEditorSettingsPrivateD2Ev
                                                 // in texteditorsettings.o
                                                 //__ZTVN10TextEditor20BehaviorSettingsPageE
                                                 // in
                                                 // moc_behaviorsettingspage.o
unimpl(
    _ZN10TextEditor22BehaviorSettingsWidgetD0Ev);  // ", referenced from:
                                                   //__ZTVN10TextEditor22BehaviorSettingsWidgetE
                                                   // in
                                                   // moc_behaviorsettingswidget.o
unimpl(
    _ZN10TextEditor22BehaviorSettingsWidgetD1Ev);  // ", referenced from:
                                                   //__ZTVN10TextEditor22BehaviorSettingsWidgetE
                                                   // in
                                                   // moc_behaviorsettingswidget.o
unimpl(
    _ZN10TextEditor23CodeStyleSelectorWidget12setCodeStyleEPNS_21ICodeStylePreferencesE);  // ", referenced from:
                                                                                           //__ZN10TextEditor15CodeStyleEditorC2EPNS_28ICodeStylePreferencesFactoryEPNS_21ICodeStylePreferencesEP7QWidget in codestyleeditor.o
unimpl(
    _ZN10TextEditor23CodeStyleSelectorWidgetC1EPNS_28ICodeStylePreferencesFactoryEP7QWidget);  // ", referenced from:
                                                                                               //__ZN10TextEditor15CodeStyleEditorC2EPNS_28ICodeStylePreferencesFactoryEPNS_21ICodeStylePreferencesEP7QWidget in codestyleeditor.o
unimpl(
    _ZN10TextEditor23CodeStyleSelectorWidgetD0Ev);  // ", referenced from:
                                                    //__ZTVN10TextEditor23CodeStyleSelectorWidgetE
                                                    // in
                                                    // moc_codestyleselectorwidget.o
unimpl(
    _ZN10TextEditor23CodeStyleSelectorWidgetD1Ev);  // ", referenced from:
                                                    //__ZTVN10TextEditor23CodeStyleSelectorWidgetE
                                                    // in
                                                    // moc_codestyleselectorwidget.o
unimpl(
    _ZN10TextEditor23HighlighterSettingsPageC1Ev);  // ", referenced from:
                                                    //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                    // in texteditorsettings.o
unimpl(
    _ZN10TextEditor23HighlighterSettingsPageD1Ev);  // ", referenced from:
                                                    //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                    // in texteditorsettings.o
                                                    //__ZN10TextEditor8Internal25TextEditorSettingsPrivateD2Ev
                                                    // in texteditorsettings.o
unimpl(
    _ZN10TextEditor8Internal15ColorSchemeEditD0Ev);  // ", referenced from:
                                                     //__ZTVN10TextEditor8Internal15ColorSchemeEditE
                                                     // in moc_colorschemeedit.o
unimpl(
    _ZN10TextEditor8Internal15ColorSchemeEditD1Ev);  // ", referenced from:
                                                     //__ZTVN10TextEditor8Internal15ColorSchemeEditE
                                                     // in moc_colorschemeedit.o
unimpl(
    _ZN10TextEditor8Internal20SnippetsSettingsPageC1Ev);  // ", referenced from:
                                                          //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                          // in
                                                          // texteditorsettings.o
unimpl(
    _ZN10TextEditor8Internal20SnippetsSettingsPageD1Ev);  // ", referenced from:
                                                          //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                          // in
                                                          // texteditorsettings.o
                                                          //__ZN10TextEditor8Internal25TextEditorSettingsPrivateD2Ev
                                                          // in
                                                          // texteditorsettings.o
unimpl(
    _ZN10TextEditor8Internal22CompletionSettingsPage16commentsSettingsEv);  // ", referenced from:
                                                                            //__ZN10TextEditor18TextEditorSettings16commentsSettingsEv
                                                                            // in
                                                                            // texteditorsettings.o
unimpl(
    _ZN10TextEditor8Internal22CompletionSettingsPage18completionSettingsEv);  // ", referenced from:
                                                                              //__ZN10TextEditor18TextEditorSettings18completionSettingsEv in texteditorsettings.o
unimpl(
    _ZN10TextEditor8Internal22CompletionSettingsPageC1Ev);  // ", referenced
                                                            // from:
                                                            //__ZN10TextEditor8Internal25TextEditorSettingsPrivateC2Ev
                                                            // in
                                                            // texteditorsettings.o
unimpl(
    _ZN11QMakeParser10initializeEv);  // ", referenced from:
                                      //__ZN9QtSupport8Internal15QtSupportPlugin10initializeERK11QStringListP7QString
                                      // in qtsupportplugin.o
unimpl(
    _ZN11QMakeParserC2EP12ProFileCacheP8QMakeVfsP18QMakeParserHandler);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN9QtSupport13ProFileReaderC2EP12QMakeGlobalsP8QMakeVfs
                                                                         // in
                                                                         // profilereader.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBar10setEnabledEb);  // ", referenced from:
                                                    //__ZTVN11QmlJSEditor12QuickToolBarE
                                                    // in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBar11isAvailableEPN10TextEditor16TextEditorWidgetE14QSharedPointerIKN5QmlJS8DocumentEEPNS5_3AST4NodeE);  // ", referenced from:
                                                                                                                                        //__ZTVN11QmlJSEditor12QuickToolBarE in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBar5applyEPN10TextEditor16TextEditorWidgetE14QSharedPointerIKN5QmlJS8DocumentEEPKNS5_10ScopeChainEPNS5_3AST4NodeEbb);  // ", referenced from:
                                                                                                                                                      //__ZTVN11QmlJSEditor12QuickToolBarE in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBar6widgetEv);  // ", referenced from:
                                               //__ZTVN11QmlJSEditor12QuickToolBarE
                                               // in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBarD0Ev);  // ", referenced from:
                                          //__ZTVN11QmlJSEditor12QuickToolBarE
                                          // in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor12QuickToolBarD1Ev);  // ", referenced from:
                                          //__ZTVN11QmlJSEditor12QuickToolBarE
                                          // in moc_quicktoolbar.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin10initializeERK11QStringListP7QString);  // ", referenced from:
                                                                                         //__ZTVN11QmlJSEditor8Internal17QmlJSEditorPluginE in moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin11jsonManagerEv);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN11QmlJSEditor8Internal19SemanticInfoUpdater19makeNewSemanticInfoERK14QSharedPointerIKN5QmlJS8DocumentEERKNS3_8SnapshotE
                                                                   // in
                                                                   // qmljssemanticinfoupdater.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin12quickToolBarEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN11QmlJSEditor17QmlJSEditorWidget22finalizeInitializationEv
                                                                    // in
                                                                    // qmljseditor.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin15aboutToShutdownEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN11QmlJSEditor8Internal17QmlJSEditorPluginE
                                                                       // in
                                                                       // moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin21extensionsInitializedEv);  // ", referenced from:
                                                                             //__ZTVN11QmlJSEditor8Internal17QmlJSEditorPluginE in moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPlugin22quickFixAssistProviderEv);  // ", referenced from:
                                                                              //__ZN11QmlJSEditor17QmlJSEditorWidget16contextMenuEventEP17QContextMenuEvent in qmljseditor.o
                                                                              //__ZNK11QmlJSEditor19QmlJSEditorDocument22quickFixAssistProviderEv in qmljseditordocument.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPluginC1Ev);  // ", referenced from:
                                                        //_qt_plugin_instance in
                                                        // moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPluginD0Ev);  // ", referenced from:
                                                        //__ZTVN11QmlJSEditor8Internal17QmlJSEditorPluginE
                                                        // in
                                                        // moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal17QmlJSEditorPluginD1Ev);  // ", referenced from:
                                                        //__ZTVN11QmlJSEditor8Internal17QmlJSEditorPluginE
                                                        // in
                                                        // moc_qmljseditorplugin.o
unimpl(
    _ZN11QmlJSEditor8Internal19ComponentNameDialog2goEP7QStringS3_S3_RK11QStringListS6_RKS2_PS4_P7QWidget);  // ", referenced from:
                                                                                                             //__ZN11QmlJSEditor12_GLOBAL__N_19Operation14performChangesE14QSharedPointerIN10QmlJSTools20QmlJSRefactoringFileEERKNS3_23QmlJSRefactoringChangesE in qmljscomponentfromobjectdef.o
unimpl(
    _ZN11QmlJSEditor8Internal19ComponentNameDialogD0Ev);  // ", referenced from:
                                                          //__ZTVN11QmlJSEditor8Internal19ComponentNameDialogE
                                                          // in
                                                          // moc_qmljscomponentnamedialog.o
unimpl(
    _ZN11QmlJSEditor8Internal19ComponentNameDialogD1Ev);  // ", referenced from:
                                                          //__ZTVN11QmlJSEditor8Internal19ComponentNameDialogE
                                                          // in
                                                          // moc_qmljscomponentnamedialog.o
unimpl(
    _ZN11QmlJSEditor8Internal8IndenterC1EP13QTextDocument);  // ", referenced
                                                             // from:
                                                             //__ZN11QmlJSEditor18QmlJSEditorFactory14decorateEditorEPN10TextEditor16TextEditorWidgetE
                                                             // in qmljseditor.o
                                                             //__ZN11QmlJSEditor19QmlJSEditorDocumentC2EN5Utils2IdE
                                                             // in
                                                             // qmljseditordocument.o
unimpl(
    _ZN12ProFileCache11discardFileERK7QStringP8QMakeVfs);  // ", referenced
                                                           // from:
                                                           //__ZN9QtSupport19ProFileCacheManager11discardFileERK7QStringP8QMakeVfs
                                                           // in profilereader.o
unimpl(
    _ZN12ProFileCache12discardFilesERK7QStringP8QMakeVfs);  // ", referenced
                                                            // from:
                                                            //__ZN9QtSupport19ProFileCacheManager12discardFilesERK7QStringP8QMakeVfs
                                                            // in
                                                            // profilereader.o
unimpl(_ZN12ProFileCacheC1Ev);  // ", referenced from:
                                //__ZN9QtSupport19ProFileCacheManager5cacheEv in
                                // profilereader.o
unimpl(_ZN12ProFileCacheD1Ev);  // ", referenced from:
                                //__ZN9QtSupport19ProFileCacheManager5clearEv in
                                // profilereader.o
unimpl(
    _ZN13LanguageUtils12FakeMetaEnum6addKeyERK7QString);  // ", referenced from:
                                                          //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                          // in
                                                          // qmljsfindexportedcpptypes.o
                                                          //__ZN5QmlJS21TypeDescriptionReader14readEnumValuesEPNS_3AST15UiScriptBindingEPN13LanguageUtils12FakeMetaEnumE
                                                          // in
                                                          // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils12FakeMetaEnum7setNameERK7QString);  // ", referenced
                                                           // from:
                                                           //__ZN5QmlJS21TypeDescriptionReader8readEnumEPNS_3AST18UiObjectDefinitionE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                           // in
                                                           // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils12FakeMetaEnumC1ERK7QString);  // ", referenced from:
                                                     //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                     // in
                                                     // qmljsfindexportedcpptypes.o
unimpl(
    _ZN13LanguageUtils12FakeMetaEnumC1Ev);  // ", referenced from:
                                            //__ZNK5QmlJS17CppComponentValue7getEnumERK7QStringPPKS0_
                                            // in qmljsinterpreter.o
                                            //__ZN5QmlJS21TypeDescriptionReader8readEnumEPNS_3AST18UiObjectDefinitionE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                            // in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethod11setRevisionEi);  // ", referenced from:
                                                         //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                         // in
                                                         // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethod12addParameterERK7QStringS3_);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                      // in
                                                                      // qmljsfindexportedcpptypes.o
                                                                      //__ZN5QmlJS21TypeDescriptionReader13readParameterEPNS_3AST18UiObjectDefinitionEPN13LanguageUtils14FakeMetaMethodE
                                                                      // in
                                                                      // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethod13setMethodNameERK7QString);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                    // in
                                                                    // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethod13setMethodTypeEi);  // ", referenced
                                                           // from:
                                                           //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                           // in
                                                           // qmljsfindexportedcpptypes.o
                                                           //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                           // in
                                                           // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethod13setReturnTypeERK7QString);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                    // in
                                                                    // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethodC1ERK7QStringS3_);  // ", referenced from:
                                                          //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                          // in
                                                          // qmljsfindexportedcpptypes.o
unimpl(
    _ZN13LanguageUtils14FakeMetaMethodC1Ev);  // ", referenced from:
                                              //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                              // in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject11addPropertyERKNS_16FakeMetaPropertyE);  // ", referenced from:
                                                                                //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE in qmljsfindexportedcpptypes.o
                                                                                //__ZN5QmlJS21TypeDescriptionReader12readPropertyEPNS_3AST18UiObjectDefinitionE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject12setClassNameERK7QString);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN12_GLOBAL__N_123buildExportedQmlObjectsERN9CPlusPlus16TypeOfExpressionERK5QListINS_15ExportedQmlTypeEEP5QHashIPNS0_5ClassE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEEPS3_ISE_E
                                                                   // in
                                                                   // qmljsfindexportedcpptypes.o
                                                                   //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                   // in
                                                                   // qmljsfindexportedcpptypes.o
                                                                   //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                                   // in
                                                                   // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject14setIsCompositeEb);  // ", referenced
                                                            // from:
                                                            //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                            // in
                                                            // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject14setIsCreatableEb);  // ", referenced
                                                            // from:
                                                            //__ZN12_GLOBAL__N_123buildExportedQmlObjectsERN9CPlusPlus16TypeOfExpressionERK5QListINS_15ExportedQmlTypeEEP5QHashIPNS0_5ClassE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEEPS3_ISE_E
                                                            // in
                                                            // qmljsfindexportedcpptypes.o
                                                            //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                            // in
                                                            // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject14setIsSingletonEb);  // ", referenced
                                                            // from:
                                                            //__ZN12_GLOBAL__N_123buildExportedQmlObjectsERN9CPlusPlus16TypeOfExpressionERK5QListINS_15ExportedQmlTypeEEP5QHashIPNS0_5ClassE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEEPS3_ISE_E
                                                            // in
                                                            // qmljsfindexportedcpptypes.o
                                                            //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                            // in
                                                            // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject17setSuperclassNameERK7QString);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                        // in
                                                                        // qmljsfindexportedcpptypes.o
                                                                        //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                                        // in
                                                                        // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject17updateFingerprintEv);  // ", referenced
                                                               // from:
                                                               //__ZN5QmlJS20FindExportedCppTypesclERK14QSharedPointerIN9CPlusPlus8DocumentEE
                                                               // in
                                                               // qmljsfindexportedcpptypes.o
                                                               //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                               // in
                                                               // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject19setAttachedTypeNameERK7QString);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                                                          // in
                                                                          // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject22setDefaultPropertyNameERK7QString);  // ", referenced from:
                                                                             //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject27setExportMetaObjectRevisionEii);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZN5QmlJS21TypeDescriptionReader23readMetaObjectRevisionsEPNS_3AST15UiScriptBindingE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                          // in
                                                                          // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject6ExportC1Ev);  // ", referenced from:
                                                     //__ZNK5QHashI7QStringN13LanguageUtils14FakeMetaObject6ExportEE5valueERKS0_
                                                     // in qmljsinterpreter.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject7addEnumERKNS_12FakeMetaEnumE);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                       // in
                                                                       // qmljsfindexportedcpptypes.o
                                                                       //__ZN5QmlJS21TypeDescriptionReader8readEnumEPNS_3AST18UiObjectDefinitionE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                       // in
                                                                       // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject9addExportERK7QStringS3_NS_16ComponentVersionE);  // ", referenced from:
                                                                                        //__ZN12_GLOBAL__N_123buildExportedQmlObjectsERN9CPlusPlus16TypeOfExpressionERK5QListINS_15ExportedQmlTypeEEP5QHashIPNS0_5ClassE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEEPS3_ISE_E in qmljsfindexportedcpptypes.o
                                                                                        //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE in qmljsfindexportedcpptypes.o
                                                                                        //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE in qmljstypedescriptionreader.o
                                                                                        //__ZN5QmlJS21TypeDescriptionReader11readExportsEPNS_3AST15UiScriptBindingE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObject9addMethodERKNS_14FakeMetaMethodE);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                           // in
                                                                           // qmljsfindexportedcpptypes.o
                                                                           //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                           // in
                                                                           // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils14FakeMetaObjectC1Ev);  // ", referenced from:
                                              //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                              // in qmljsfindexportedcpptypes.o
                                              //__ZN5QmlJS21TypeDescriptionReader13readComponentEPNS_3AST18UiObjectDefinitionE
                                              // in qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils16ComponentVersion10MaxVersionE);  // ", referenced from:
                                                         //__ZL18parseImportVersionRK7QString
                                                         // in qmldirparser.o
                                                         //__ZN5QmlJS11CppQmlTypes4loadI5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRK7QStringRKT_SB_
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZN5QmlJS11CppQmlTypes4loadI5QHashI7QString14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRKS3_RKT_SB_
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZN5QmlJS11LinkPrivate26loadImplicitDefaultImportsEPNS_7ImportsE
                                                         // in qmljslink.o
                                                         //__ZN5QmlJS11LinkPrivate20loadQmldirComponentsEPNS_11ObjectValueEN13LanguageUtils16ComponentVersionERKNS_11LibraryInfoERK7QString
                                                         // in qmljslink.o
unimpl(
    _ZN13LanguageUtils16ComponentVersion9NoVersionE);  // ", referenced from:
                                                       //__ZL18parseImportVersionRK7QString
                                                       // in qmldirparser.o
                                                       //__ZN5QmlJS8Snapshot6insertERK14QSharedPointerIKNS_8DocumentEEb
                                                       // in qmljsdocument.o
                                                       //__ZN5QmlJS8Snapshot17insertLibraryInfoERK7QStringRKNS_11LibraryInfoE
                                                       // in qmljsdocument.o
                                                       //__ZN5QmlJS9ImportKeyC2Ev
                                                       // in
                                                       // qmljsimportdependencies.o
                                                       //__ZNK5QmlJS9ImportKey8toStringEv
                                                       // in
                                                       // qmljsimportdependencies.o
unimpl(
    _ZN13LanguageUtils16ComponentVersionC1ERK7QString);  // ", referenced from:
                                                         //__ZN12_GLOBAL__N_117CollectDirectives12importModuleERK7QStringS3_S3_ii
                                                         // in qmljsdocument.o
                                                         //__ZN5QmlJS21TypeDescriptionReader11readExportsEPNS_3AST15UiScriptBindingE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                         // in
                                                         // qmljstypedescriptionreader.o
                                                         //__ZN5QmlJS21TypeDescriptionReader25readNumericVersionBindingEPNS_3AST15UiScriptBindingE
                                                         // in
                                                         // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtils16ComponentVersionC1Eii);  // ", referenced from:
                                                 //__ZL18parseImportVersionRK7QString
                                                 // in qmldirparser.o
                                                 //__ZN5QmlJS4Bind5visitEPNS_3AST8UiImportE
                                                 // in qmljsbind.o
                                                 //__ZN12_GLOBAL__N_118FindExportsVisitor23checkForQmlRegisterTypeEPN9CPlusPlus7CallASTE
                                                 // in
                                                 // qmljsfindexportedcpptypes.o
                                                 //__ZN5QmlJS11LinkPrivate26loadImplicitDefaultImportsEPNS_7ImportsE
                                                 // in qmljslink.o
                                                 //__ZN5QmlJS11LinkPrivate20loadQmldirComponentsEPNS_11ObjectValueEN13LanguageUtils16ComponentVersionERKNS_11LibraryInfoERK7QString
                                                 // in qmljslink.o
                                                 //__ZN5QmlJS5Check5visitEPNS_3AST8UiImportE
                                                 // in qmljscheck.o
                                                 //__ZN5QmlJS21TypeDescriptionReader12readDocumentEPNS_3AST9UiProgramE
                                                 // in
                                                 // qmljstypedescriptionreader.o
                                                 //...
unimpl(
    _ZN13LanguageUtils16ComponentVersionC1Ev);  // ", referenced from:
                                                //__ZZN12QmlDirParser5parseERK7QStringENK3$_7clEPS1_i6QFlagsINS_6Import4FlagEE
                                                // in qmldirparser.o
                                                //__ZN12QmlDirParser6ImportC2Ev
                                                // in qmldirparser.o
                                                //__ZN5QmlJS4Bind8endVisitEPNS_3AST9UiProgramE
                                                // in qmljsbind.o
                                                //__ZN5QmlJS4Bind5visitEPNS_3AST8UiImportE
                                                // in qmljsbind.o
                                                //__ZN12_GLOBAL__N_115ExportedQmlTypeC2Ev
                                                // in
                                                // qmljsfindexportedcpptypes.o
                                                //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                // in
                                                // qmljsfindexportedcpptypes.o
                                                //__ZN12_GLOBAL__N_117CollectDirectives10importFileERK7QStringS3_ii
                                                // in qmljsdocument.o
                                                //...
unimpl(
    _ZN13LanguageUtils16ComponentVersionD1Ev);  // ", referenced from:
                                                //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                // in qmljseditor.o
                                                //__ZN5QmlJS13ModuleApiInfoD2Ev
                                                // in qmljseditor.o
                                                //__ZN12QmlDirParser6ImportD2Ev
                                                // in qmljseditor.o
                                                //__ZN5QmlJS10ImportInfoD2Ev
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditorL13getModuleNameERKN5QmlJS10ScopeChainERK14QSharedPointerIKNS0_8DocumentEEPKNS0_11ObjectValueE
                                                // in qmljshoverhandler.o
                                                //__ZN5QmlJS10ImportInfoD2Ev
                                                // in qmljshoverhandler.o
                                                //__ZN12QmlDirParser6ImportD2Ev
                                                // in qmljshoverhandler.o
                                                //...
unimpl(
    _ZN13LanguageUtils16FakeMetaPropertyC1ERK7QStringS3_bbbi);  // ", referenced
                                                                // from:
                                                                //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                                // in
                                                                // qmljsfindexportedcpptypes.o
                                                                //__ZN5QmlJS21TypeDescriptionReader12readPropertyEPNS_3AST18UiObjectDefinitionE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                                // in
                                                                // qmljstypedescriptionreader.o
unimpl(
    _ZN13LanguageUtilseqERKNS_16ComponentVersionES2_);  // ", referenced from:
                                                        //__ZN5QmlJS11CppQmlTypes4loadI5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRK7QStringRKT_SB_
                                                        // in qmljsinterpreter.o
                                                        //__ZN5QmlJS11CppQmlTypes4loadI5QHashI7QString14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRKS3_RKT_SB_
                                                        // in qmljsinterpreter.o
                                                        //__ZeqI7QStringN13LanguageUtils16ComponentVersionEEbRK5QPairIT_T0_ES8_
                                                        // in qmljscheck.o
unimpl(
    _ZN13LanguageUtilsgtERKNS_16ComponentVersionES2_);  // ", referenced from:
                                                        //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                        // in qmljsinterpreter.o
                                                        //__ZL23getHighestExportVersionRK5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEERK7QStringSA_PbPNS1_16ComponentVersionE
                                                        // in
                                                        // qmljsplugindumper.o
unimpl(
    _ZN13LanguageUtilsleERKNS_16ComponentVersionES2_);  // ", referenced from:
                                                        //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                        // in qmljsinterpreter.o
                                                        //__ZN5QmlJSL17findBestModuleApiERK5QListINS_13ModuleApiInfoEERKN13LanguageUtils16ComponentVersionE
                                                        // in qmljslink.o
unimpl(
    _ZN13LanguageUtilsltERKNS_16ComponentVersionES2_);  // ", referenced from:
                                                        //__ZN5QmlJSL17findBestModuleApiERK5QListINS_13ModuleApiInfoEERKN13LanguageUtils16ComponentVersionE
                                                        // in qmljslink.o
                                                        //__ZN5QmlJS11LinkPrivate20loadQmldirComponentsEPNS_11ObjectValueEN13LanguageUtils16ComponentVersionERKNS_11LibraryInfoERK7QString
                                                        // in qmljslink.o
unimpl(
    _ZN15ExtensionSystem15PluginErrorView6updateEPNS_10PluginSpecE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN4Core8Internal12PluginDialog16openErrorDetailsEv
                                                                      // in
                                                                      // plugindialog.o
unimpl(
    _ZN15ExtensionSystem15PluginErrorViewC1EP7QWidget);  // ", referenced from:
                                                         //__ZN4Core8Internal12PluginDialog16openErrorDetailsEv
                                                         // in plugindialog.o
unimpl(
    _ZN15ExtensionSystem15PluginErrorViewD0Ev);  // ", referenced from:
                                                 //__ZTVN15ExtensionSystem15PluginErrorViewE
                                                 // in moc_pluginerrorview.o
unimpl(
    _ZN15ExtensionSystem15PluginErrorViewD1Ev);  // ", referenced from:
                                                 //__ZTVN15ExtensionSystem15PluginErrorViewE
                                                 // in moc_pluginerrorview.o
unimpl(
    _ZN15ExtensionSystem17PluginDetailsView6updateEPNS_10PluginSpecE);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN4Core8Internal12PluginDialog11openDetailsEPN15ExtensionSystem10PluginSpecE
                                                                        // in
                                                                        // plugindialog.o
unimpl(
    _ZN15ExtensionSystem17PluginDetailsViewC1EP7QWidget);  // ", referenced
                                                           // from:
                                                           //__ZN4Core8Internal12PluginDialog11openDetailsEPN15ExtensionSystem10PluginSpecE
                                                           // in plugindialog.o
unimpl(
    _ZN15ExtensionSystem17PluginDetailsViewD0Ev);  // ", referenced from:
                                                   //__ZTVN15ExtensionSystem17PluginDetailsViewE
                                                   // in moc_plugindetailsview.o
unimpl(
    _ZN15ExtensionSystem17PluginDetailsViewD1Ev);  // ", referenced from:
                                                   //__ZTVN15ExtensionSystem17PluginDetailsViewE
                                                   // in moc_plugindetailsview.o
unimpl(
    _ZN15ExtensionSystem19PluginErrorOverviewC1EP7QWidget);  // ", referenced
                                                             // from:
                                                             //__ZN4Core8Internal10CorePlugin21extensionsInitializedEv
                                                             // in coreplugin.o
unimpl(
    _ZN15ExtensionSystem19PluginErrorOverviewD0Ev);  // ", referenced from:
                                                     //__ZTVN15ExtensionSystem19PluginErrorOverviewE
                                                     // in
                                                     // moc_pluginerroroverview.o
unimpl(
    _ZN15ExtensionSystem19PluginErrorOverviewD1Ev);  // ", referenced from:
                                                     //__ZTVN15ExtensionSystem19PluginErrorOverviewE
                                                     // in
                                                     // moc_pluginerroroverview.o
unimpl(
    _ZN15ProjectExplorer10JsonWizard15boolFromVariantERK8QVariantPN5Utils13MacroExpanderE);  // ", referenced from:
                                                                                             //__ZN7VcsBase8Internal14VcsCommandPage17delayedInitializeEv in vcscommandpage.o
unimpl(
    _ZN15ProjectExplorer10JsonWizard16staticMetaObjectE);  // ", referenced
                                                           // from:
                                                           //__Z12qobject_castIPN15ProjectExplorer10JsonWizardEET_P7QObject
                                                           // in
                                                           // vcsconfigurationpage.o
                                                           //__Z12qobject_castIPN15ProjectExplorer10JsonWizardEET_P7QObject
                                                           // in
                                                           // vcscommandpage.o
unimpl(
    _ZN15ProjectExplorer10JsonWizard8expanderEv);  // ", referenced from:
                                                   //__ZN9QtSupport8Internal21TranslationWizardPage14initializePageEv
                                                   // in translationwizardpage.o
                                                   //__ZN7VcsBase20VcsConfigurationPage14initializePageEv
                                                   // in vcsconfigurationpage.o
                                                   //__ZN7VcsBase8Internal14VcsCommandPage17delayedInitializeEv
                                                   // in vcscommandpage.o
unimpl(
    _ZN15ProjectExplorer10JsonWizard8setValueERK7QStringRK8QVariant);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN9QtSupport8Internal21TranslationWizardPage12validatePageEv
                                                                       // in
                                                                       // translationwizardpage.o
unimpl(
    _ZN15ProjectExplorer10KitManager10defaultKitEv);  // ", referenced from:
                                                      //__ZN8Debugger8InternalL16guessKitFromAbisERK7QVectorIN15ProjectExplorer3AbiEE
                                                      // in debuggerplugin.o
                                                      //__ZN8Debugger8Internal25UnstartedAppWatcherDialogC2EP7QWidget
                                                      // in
                                                      // unstartedappwatcherdialog.o
                                                      //__ZN15ProjectExplorer15ProjectImporter15preferredTargetERK5QListIPNS_6TargetEE
                                                      // in projectimporter.o
                                                      //__ZN15ProjectExplorer15TargetSetupPage26selectAtLeastOneEnabledKitEv
                                                      // in targetsetuppage.o
                                                      //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget7discardEv
                                                      // in
                                                      // kitmanagerconfigwidget.o
                                                      //__ZNK15ProjectExplorer8Internal22KitManagerConfigWidget7isDirtyEv
                                                      // in
                                                      // kitmanagerconfigwidget.o
                                                      //__ZN15ProjectExplorer8Internal8KitModel16changeDefaultKitEv
                                                      // in kitmodel.o
                                                      //...
unimpl(
    _ZN15ProjectExplorer10KitManager10kitAspectsEv);  // ", referenced from:
                                                      //__ZN15ProjectExplorer8Internal21FilterKitAspectsModelC2EPKNS_3KitEP7QObject
                                                      // in
                                                      // filterkitaspectsdialog.o
                                                      //__ZNK15ProjectExplorer3Kit8validateEv
                                                      // in kit.o
                                                      //__ZN15ProjectExplorer3Kit3fixEv
                                                      // in kit.o
                                                      //__ZN15ProjectExplorer3Kit5setupEv
                                                      // in kit.o
                                                      //__ZN15ProjectExplorer3Kit7upgradeEv
                                                      // in kit.o
                                                      //__ZNK15ProjectExplorer3Kit6weightEv
                                                      // in kit.o
                                                      //__ZNK15ProjectExplorer3Kit16addToEnvironmentERN5Utils11EnvironmentE
                                                      // in kit.o
                                                      //...
unimpl(
    _ZN15ProjectExplorer10KitManager11registerKitERKNSt3__18functionIFvPNS_3KitEEEEN5Utils2IdE);  // ", referenced from:
                                                                                                  //__ZNK15ProjectExplorer15ProjectImporter18createTemporaryKitERKNSt3__18functionIFvPNS_3KitEEEE in projectimporter.o
                                                                                                  //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget5applyEv in kitmanagerconfigwidget.o
                                                                                                  //__ZN15ProjectExplorer7Project19createTargetFromMapERK4QMapI7QString8QVariantEi in project.o
unimpl(
    _ZN15ProjectExplorer10KitManager13deregisterKitEPNS_3KitE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZNK15ProjectExplorer15ProjectImporter13removeProjectEPNS_3KitE
                                                                 // in
                                                                 // projectimporter.o
                                                                 //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget9removeKitEv
                                                                 // in
                                                                 // kitmanagerconfigwidget.o
unimpl(
    _ZN15ProjectExplorer10KitManager13setDefaultKitEPNS_3KitE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget5applyEv
                                                                 // in
                                                                 // kitmanagerconfigwidget.o
unimpl(
    _ZN15ProjectExplorer10KitManager17irrelevantAspectsEv);  // ", referenced
                                                             // from:
                                                             //__ZN15ProjectExplorer8Internal21FilterKitAspectsModelC2EPKNS_3KitEP7QObject
                                                             // in
                                                             // filterkitaspectsdialog.o
                                                             //__ZNK15ProjectExplorer3Kit17irrelevantAspectsEv
                                                             // in kit.o
unimpl(
    _ZN15ProjectExplorer10KitManager17notifyAboutUpdateEPNS_3KitE);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN15ProjectExplorer3Kit10kitUpdatedEv
                                                                     // in kit.o
                                                                     //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget5applyEv
                                                                     // in
                                                                     // kitmanagerconfigwidget.o
unimpl(
    _ZN15ProjectExplorer10KitManager20setIrrelevantAspectsERK4QSetIN5Utils2IdEE);  // ", referenced from:
                                                                                   //__ZZN15ProjectExplorer8Internal20KitOptionsPageWidgetC1EvENK3$_1clEv in kitoptionspage.o
unimpl(
    _ZN15ProjectExplorer10KitManager3kitEN5Utils2IdE);  // ", referenced from:
                                                        //__ZNK8Debugger8Internal26StartApplicationParameters11displayNameEv
                                                        // in debuggerdialogs.o
                                                        //__ZN8Debugger8Internal21DebuggerPluginPrivate13parseArgumentERN5QListI7QStringE14const_iteratorERKS5_PS3_
                                                        // in debuggerplugin.o
                                                        //__ZN15ProjectExplorer8Internal20ProjectWindowPrivate17handleImportBuildEv
                                                        // in projectwindow.o
                                                        //__ZN15ProjectExplorer8Internal20ProjectWindowPrivate16handleManageKitsEv
                                                        // in projectwindow.o
                                                        //__ZN15ProjectExplorer15TargetSetupPage6importERKN5Utils8FilePathEb
                                                        // in targetsetuppage.o
                                                        //__ZN15ProjectExplorer10KitChooser21onCurrentIndexChangedEv
                                                        // in kitchooser.o
                                                        //__ZNK15ProjectExplorer10KitChooser10currentKitEv
                                                        // in kitchooser.o
                                                        //...
unimpl(
    _ZN15ProjectExplorer10KitManager3kitERKNSt3__18functionIFbPKNS_3KitEEEE);  // ", referenced from:
                                                                               //__ZN8Debugger8Internal21DebuggerPluginPrivate13parseArgumentERN5QListI7QStringE14const_iteratorERKS5_PS3_ in debuggerplugin.o
                                                                               //__ZN8Debugger8InternalL16guessKitFromAbisERK7QVectorIN15ProjectExplorer3AbiEE in debuggerplugin.o
                                                                               //__ZN8Debugger8InternalL19findUniversalCdbKitEv in debuggerplugin.o
                                                                               //__ZN15ProjectExplorer15TargetSetupPage16updateVisibilityEv in targetsetuppage.o
unimpl(
    _ZN15ProjectExplorer10KitManager4kitsEv);  // ", referenced from:
                                               //__ZN15ProjectExplorer15ProjectImporterD2Ev
                                               // in projectimporter.o
                                               //__ZN15ProjectExplorer15ProjectImporter6importERKN5Utils8FilePathEb
                                               // in projectimporter.o
                                               //__ZNK15ProjectExplorer15ProjectImporter14makePersistentEPNS_3KitE
                                               // in projectimporter.o
                                               //__ZNK15ProjectExplorer15ProjectImporter23hasKitWithTemporaryDataEN5Utils2IdERK8QVariant
                                               // in projectimporter.o
                                               //__ZN15ProjectExplorerL13hasOtherUsersEN5Utils2IdERK8QVariantPNS_3KitE
                                               // in projectimporter.o
                                               //__ZN15ProjectExplorer15TargetSetupPage12setupWidgetsERK7QString
                                               // in targetsetuppage.o
                                               //__ZNK15ProjectExplorer3Kit5cloneEb
                                               // in kit.o
                                               //...
unimpl(
    _ZN15ProjectExplorer10KitManager8instanceEv);  // ", referenced from:
                                                   //__ZN15ProjectExplorer15TargetSetupPageC2EP7QWidget
                                                   // in targetsetuppage.o
                                                   //__ZN15ProjectExplorer15TargetSetupPage14initializePageEv
                                                   // in targetsetuppage.o
                                                   //__ZN15ProjectExplorer10KitChooserC2EP7QWidget
                                                   // in kitchooser.o
                                                   //__ZN15ProjectExplorer18ToolChainKitAspectC2Ev
                                                   // in kitinformation.o
                                                   //__ZN15ProjectExplorer15DeviceKitAspectC2Ev
                                                   // in kitinformation.o
                                                   //__ZN15ProjectExplorer15DeviceKitAspect14kitsWereLoadedEv
                                                   // in kitinformation.o
                                                   //__ZN15ProjectExplorer8Internal22KitManagerConfigWidgetC2EPNS_3KitE
                                                   // in
                                                   // kitmanagerconfigwidget.o
                                                   //...
unimpl(
    _ZN15ProjectExplorer10KitManager8isLoadedEv);  // ", referenced from:
                                                   //__ZN15ProjectExplorer15TargetSetupPage14initializePageEv
                                                   // in targetsetuppage.o
unimpl(
    _ZN15ProjectExplorer10KitManager8sortKitsERK5QListIPNS_3KitEE);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN15ProjectExplorer15TargetSetupPage12setupWidgetsERK7QString
                                                                     // in
                                                                     // targetsetuppage.o
                                                                     //__ZN15ProjectExplorer10KitChooser8populateEv
                                                                     // in
                                                                     // kitchooser.o
                                                                     //__ZN15ProjectExplorer8Internal8KitModelC2EP10QBoxLayoutP7QObject
                                                                     // in
                                                                     // kitmodel.o
                                                                     //__ZN15ProjectExplorer8Internal22TargetGroupItemPrivate15rebuildContentsEv
                                                                     // in
                                                                     // targetsettingspanel.o
unimpl(
    _ZN15ProjectExplorer10KitManagerD0Ev);  // ", referenced from:
                                            //__ZTVN15ProjectExplorer10KitManagerE
                                            // in moc_kitmanager.o
unimpl(
    _ZN15ProjectExplorer10KitManagerD1Ev);  // ", referenced from:
                                            //__ZTVN15ProjectExplorer10KitManagerE
                                            // in moc_kitmanager.o
unimpl(
    _ZN15ProjectExplorer15KitAspectWidget10setVisibleEb);  // ", referenced
                                                           // from:
                                                           //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget16updateVisibilityEv
                                                           // in
                                                           // kitmanagerconfigwidget.o
unimpl(
    _ZN15ProjectExplorer15KitAspectWidget11addToLayoutERN5Utils13LayoutBuilderE);  // ", referenced from:
                                                                                   //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget22addAspectToWorkingCopyEPNS_9KitAspectE in kitmanagerconfigwidget.o
unimpl(
    _ZN15ProjectExplorer15KitAspectWidget9msgManageEv);  // ", referenced from:
                                                         //__ZN8Debugger8Internal23DebuggerKitAspectWidgetC2EPN15ProjectExplorer3KitEPKNS2_9KitAspectE
                                                         // in
                                                         // debuggerkitinformation.o
                                                         //__ZN15ProjectExplorer8Internal17TargetSetupWidgetC2EPNS_3KitERKN5Utils8FilePathE
                                                         // in
                                                         // targetsetupwidget.o
                                                         //__ZN15ProjectExplorer10KitChooserC2EP7QWidget
                                                         // in kitchooser.o
                                                         //__ZN15ProjectExplorer8Internal24ToolChainKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                         // in kitinformation.o
                                                         //__ZN15ProjectExplorer8Internal21DeviceKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                         // in kitinformation.o
                                                         //__ZN9QtSupport8Internal17QtKitAspectWidgetC2EPN15ProjectExplorer3KitEPKNS2_9KitAspectE
                                                         // in
                                                         // qtkitinformation.o
unimpl(
    _ZN15ProjectExplorer15KitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN8Debugger8Internal23DebuggerKitAspectWidgetC2EPN15ProjectExplorer3KitEPKNS2_9KitAspectE
                                                                         // in
                                                                         // debuggerkitinformation.o
                                                                         //__ZN15ProjectExplorer8Internal22SysRootKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                                         // in
                                                                         // kitinformation.o
                                                                         //__ZN15ProjectExplorer8Internal24ToolChainKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                                         // in
                                                                         // kitinformation.o
                                                                         //__ZN15ProjectExplorer8Internal25DeviceTypeKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                                         // in
                                                                         // kitinformation.o
                                                                         //__ZN15ProjectExplorer8Internal21DeviceKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                                         // in
                                                                         // kitinformation.o
                                                                         //__ZN15ProjectExplorer8Internal26EnvironmentKitAspectWidgetC2EPNS_3KitEPKNS_9KitAspectE
                                                                         // in
                                                                         // kitinformation.o
                                                                         //__ZN9QtSupport8Internal17QtKitAspectWidgetC2EPN15ProjectExplorer3KitEPKNS2_9KitAspectE
                                                                         // in
                                                                         // qtkitinformation.o
                                                                         //...
unimpl(
    _ZN15ProjectExplorer17JsonWizardFactory19registerPageFactoryEPNS_21JsonWizardPageFactoryE);  // ", referenced from:
                                                                                                 //__ZN9QtSupport8Internal15QtSupportPlugin10initializeERK11QStringListP7QString in qtsupportplugin.o
                                                                                                 //__ZN7VcsBase8Internal9VcsPlugin10initializeERK11QStringListP7QString in vcsplugin.o
unimpl(
    _ZN15ProjectExplorer21JsonWizardPageFactory16setTypeIdsSuffixERK7QString);  // ", referenced from:
                                                                                //__ZN9QtSupport8Internal28TranslationWizardPageFactoryC2Ev in translationwizardpage.o
                                                                                //__ZN7VcsBase8Internal27VcsConfigurationPageFactoryC2Ev in vcsconfigurationpage.o
                                                                                //__ZN7VcsBase8Internal21VcsCommandPageFactoryC2Ev in vcscommandpage.o
unimpl(
    _ZN15ProjectExplorer21JsonWizardPageFactoryD2Ev);  // ", referenced from:
                                                       //__ZN9QtSupport8Internal28TranslationWizardPageFactoryC2Ev
                                                       // in
                                                       // translationwizardpage.o
                                                       //__ZN9QtSupport8Internal28TranslationWizardPageFactoryD2Ev
                                                       // in
                                                       // translationwizardpage.o
                                                       //__ZN7VcsBase8Internal27VcsConfigurationPageFactoryC2Ev
                                                       // in
                                                       // vcsconfigurationpage.o
                                                       //__ZN7VcsBase8Internal27VcsConfigurationPageFactoryD2Ev
                                                       // in
                                                       // vcsconfigurationpage.o
                                                       //__ZN7VcsBase8Internal21VcsCommandPageFactoryC2Ev
                                                       // in vcscommandpage.o
                                                       //__ZN7VcsBase8Internal21VcsCommandPageFactoryD2Ev
                                                       // in vcscommandpage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin10initializeERK11QStringListP7QString);  // ", referenced from:
                                                                                        //__ZTVN15ProjectExplorer21ProjectExplorerPluginE in moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin10renameFileEPNS_4NodeERK7QString);  // ", referenced from:
                                                                                    //__ZN8CppTools8Internal17CppFindReferences22onReplaceButtonClickedERK7QStringRK5QListIN4Core16SearchResultItemEEb in cppfindreferences.o
                                                                                    //__ZN15ProjectExplorer8Internal9FlatModel7setDataERK11QModelIndexRK8QVarianti in projectmodels.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin11openProjectERK7QString);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer8Internal22FolderNavigationWidget16contextMenuEventEP17QContextMenuEvent
                                                                           // in
                                                                           // foldernavigationwidget.o
                                                                           //__ZN9QtSupport8Internal19ExamplesWelcomePage11openProjectEPKNS0_11ExampleItemE
                                                                           // in
                                                                           // gettingstartedwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin12openProjectsERK11QStringList);  // ", referenced from:
                                                                                 //__ZN15ProjectExplorer21SessionManagerPrivate15restoreProjectsERK11QStringList in session.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin13customParsersEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC2Ev
                                                                    // in
                                                                    // customparserssettingspage.o
                                                                    //__ZNK15ProjectExplorer15CustomToolChain20customParserSettingsEv
                                                                    // in
                                                                    // customtoolchain.o
                                                                    //__ZN15ProjectExplorer15CustomToolChain7fromMapERK4QMapI7QString8QVariantE
                                                                    // in
                                                                    // customtoolchain.o
                                                                    //__ZN15ProjectExplorer8Internal27CustomToolChainConfigWidgetC2EPNS_15CustomToolChainE
                                                                    // in
                                                                    // customtoolchain.o
                                                                    //__ZN15ProjectExplorer8Internal12CustomParser12createFromIdEN5Utils2IdE
                                                                    // in
                                                                    // customparser.o
                                                                    //__ZN15ProjectExplorer8Internal12_GLOBAL__N_115SelectionWidget8updateUiEv
                                                                    // in
                                                                    // customparser.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin13isProjectFileERKN5Utils8FilePathE);  // ", referenced from:
                                                                                      //__ZN15ProjectExplorer8Internal22FolderNavigationWidget16contextMenuEventEP17QContextMenuEvent in foldernavigationwidget.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin13updateActionsEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN15ProjectExplorer6Target27setActiveBuildConfigurationEPNS_18BuildConfigurationE
                                                                    // in
                                                                    // target.o
                                                                    //__ZN15ProjectExplorer6Target25setActiveRunConfigurationEPNS_16RunConfigurationE
                                                                    // in
                                                                    // target.o
                                                                    //__ZN15ProjectExplorer7Project15setActiveTargetEPNS_6TargetE
                                                                    // in
                                                                    // project.o
                                                                    //__ZZN15ProjectExplorer18BuildConfigurationC1EPNS_6TargetEN5Utils2IdEENK3$_9clEv
                                                                    // in
                                                                    // buildconfiguration.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin14allRunControlsEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN15ProjectExplorerL5queueERK5QListIPNS_7ProjectEERKS0_IN5Utils2IdEENS_15ConfigSelectionEPKNS_16RunConfigurationE
                                                                     // in
                                                                     // buildmanager.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin14recentProjectsEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZNK15ProjectExplorer8Internal12ProjectModel8rowCountERK11QModelIndex
                                                                     // in
                                                                     // projectwelcomepage.o
                                                                     //__ZNK15ProjectExplorer8Internal12ProjectModel4dataERK11QModelIndexi
                                                                     // in
                                                                     // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin14showQtSettingsEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN9QtSupport8Internal15QtSupportPlugin10initializeERK11QStringListP7QString
                                                                     // in
                                                                     // qtsupportplugin.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin14targetSelectorEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN15ProjectExplorer6Target21addBuildConfigurationEPNS_18BuildConfigurationE
                                                                     // in
                                                                     // target.o
                                                                     //__ZN15ProjectExplorer6Target24removeBuildConfigurationEPNS_18BuildConfigurationE
                                                                     // in
                                                                     // target.o
                                                                     //__ZN15ProjectExplorer6Target22addDeployConfigurationEPNS_19DeployConfigurationE
                                                                     // in
                                                                     // target.o
                                                                     //__ZN15ProjectExplorer6Target25removeDeployConfigurationEPNS_19DeployConfigurationE
                                                                     // in
                                                                     // target.o
                                                                     //__ZN15ProjectExplorer6Target19addRunConfigurationEPNS_16RunConfigurationE
                                                                     // in
                                                                     // target.o
                                                                     //__ZN15ProjectExplorer6Target22removeRunConfigurationEPNS_16RunConfigurationE
                                                                     // in
                                                                     // target.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin15aboutToShutdownEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN15ProjectExplorer21ProjectExplorerPluginE
                                                                      // in
                                                                      // moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin15startRunControlEPNS_10RunControlE);  // ", referenced from:
                                                                                      //__ZN8Debugger15DebuggerRunTool15startRunControlEv in debuggerruncontrol.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin16projectFileGlobsEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN15ProjectExplorer8Internal22FolderNavigationWidget23projectFilesInDirectoryERK7QString
                                                                       // in
                                                                       // foldernavigationwidget.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin16setCustomParsersERK5QListINS_20CustomParserSettingsEE);  // ", referenced from:
                                                                                                          //__ZN15ProjectExplorer8Internal27CustomParsersSettingsWidget5applyEv in customparserssettingspage.o
                                                                                                          //__ZN15ProjectExplorer15CustomToolChain7fromMapERK4QMapI7QString8QVariantE in customtoolchain.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin16updateRunActionsEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZZN15ProjectExplorer18BuildConfigurationC1EPNS_6TargetEN5Utils2IdEENK3$_9clEv
                                                                       // in
                                                                       // buildconfiguration.o
                                                                       //__ZN15ProjectExplorer16RunConfiguration6updateEv
                                                                       // in
                                                                       // runconfiguration.o
                                                                       //__ZN15ProjectExplorer8Internal13AppOutputPane23slotRunControlFinished2EPNS_10RunControlE
                                                                       // in
                                                                       // appoutputpane.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin17appOutputSettingsEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN15ProjectExplorer8Internal26ApplicationLauncherPrivateC2EPNS_19ApplicationLauncherE
                                                                        // in
                                                                        // applicationlauncher.o
                                                                        //__ZN15ProjectExplorer8Internal23AppOutputSettingsWidgetC2Ev
                                                                        // in
                                                                        // appoutputpane.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin17runStartupProjectEN5Utils2IdEb);  // ", referenced from:
                                                                                   //__ZZN8Debugger8Internal21DebuggerPluginPrivateC1ERK11QStringListENK3$_2clEv in debuggerplugin.o
                                                                                   //__ZZN8Debugger8Internal21DebuggerPluginPrivateC1ERK11QStringListENK3$_3clEv in debuggerplugin.o
                                                                                   //__ZZN8Debugger8Internal21DebuggerPluginPrivateC1ERK11QStringListENK3$_4clEv in debuggerplugin.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin17saveModifiedFilesEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN15ProjectExplorerL5queueERK5QListIPNS_7ProjectEERKS0_IN5Utils2IdEENS_15ConfigSelectionEPKNS_16RunConfigurationE
                                                                        // in
                                                                        // buildmanager.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin18showSessionManagerEv);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZZN15ProjectExplorer8Internal12SessionsPageC1EPNS0_18ProjectWelcomePageEENKUlvE_clEv
                                                                         // in
                                                                         // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin19clearRecentProjectsEv);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZZN15ProjectExplorer8Internal15ProjectDelegate11editorEventEP6QEventP18QAbstractItemModelRK20QStyleOptionViewItemRK11QModelIndexENKUlvE0_clEv
                                                                          // in
                                                                          // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin19runRunConfigurationEPNS_16RunConfigurationEN5Utils2IdEb);  // ", referenced from:
                                                                                                            //__ZN15ProjectExplorer8Internal17GenericListWidget17mouseReleaseEventEP11QMouseEvent in miniprojecttargetselector.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin20canRunStartupProjectEN5Utils2IdEP7QString);  // ", referenced from:
                                                                                              //__ZN8Debugger8Internal21DebuggerPluginPrivate17updatePresetStateEv in debuggerplugin.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin20openNewProjectDialogEv);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer8Internal18ProjectWelcomePage10newProjectEv
                                                                           // in
                                                                           // projectwelcomepage.o
                                                                           //__ZZN15ProjectExplorer8Internal12SessionsPageC1EPNS0_18ProjectWelcomePageEENKUlvE0_clEv
                                                                           // in
                                                                           // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin20setAppOutputSettingsERKNS_8Internal17AppOutputSettingsE);  // ", referenced from:
                                                                                                            //__ZN15ProjectExplorer8Internal23AppOutputSettingsWidget5applyEv in appoutputpane.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin20showOpenProjectErrorERKNS0_17OpenProjectResultE);  // ", referenced from:
                                                                                                    //__ZN15ProjectExplorer21SessionManagerPrivate15restoreProjectsERK11QStringList in session.o
                                                                                                    //__ZN9QtSupport8Internal19ExamplesWelcomePage11openProjectEPKNS0_11ExampleItemE in gettingstartedwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin21extensionsInitializedEv);  // ", referenced from:
                                                                            //__ZTVN15ProjectExplorer21ProjectExplorerPluginE
                                                                            // in
                                                                            // moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin21openOpenProjectDialogEv);  // ", referenced from:
                                                                            //__ZN15ProjectExplorer8Internal18ProjectWelcomePage11openProjectEv
                                                                            // in
                                                                            // projectwelcomepage.o
                                                                            //__ZZN15ProjectExplorer8Internal12SessionsPageC1EPNS0_18ProjectWelcomePageEENKUlvE1_clEv
                                                                            // in
                                                                            // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin22buildDirectoryTemplateEv);  // ", referenced from:
                                                                             //__ZN15ProjectExplorer7Project9copyStepsEPNS_6TargetES2_ in project.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin22openProjectWelcomePageERK7QString);  // ", referenced from:
                                                                                      //__ZN15ProjectExplorer8Internal18ProjectWelcomePage13openProjectAtEi in projectwelcomepage.o
                                                                                      //__ZN15ProjectExplorer8Internal15ProjectDelegate11editorEventEP6QEventP18QAbstractItemModelRK20QStyleOptionViewItemRK11QModelIndex in projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin23buildPropertiesSettingsEv);  // ", referenced from:
                                                                              //__ZN15ProjectExplorer23SeparateDebugInfoAspectC2Ev in buildaspects.o
                                                                              //__ZN15ProjectExplorer8Internal29BuildPropertiesSettingsWidgetC2Ev in buildpropertiessettingspage.o
                                                                              //__ZN15ProjectExplorer8Internal29BuildPropertiesSettingsWidget5applyEv in buildpropertiessettingspage.o
                                                                              //__ZN9QtSupport18QmlDebuggingAspectC2Ev in qtbuildaspects.o
                                                                              //__ZN9QtSupport21QtQuickCompilerAspectC2Ev in qtbuildaspects.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin23projectExplorerSettingsEv);  // ", referenced from:
                                                                              //__ZN8Debugger8Internal21DebuggerPluginPrivate28updateDebugWithoutDeployMenuEv in debuggerplugin.o
                                                                              //__ZN15ProjectExplorer8Internal16UserFileAccessorC2EPNS_7ProjectE in userfileaccessor.o
                                                                              //__ZN15ProjectExplorerL5queueERK5QListIPNS_7ProjectEERKS0_IN5Utils2IdEENS_15ConfigSelectionEPKNS_16RunConfigurationE in buildmanager.o
                                                                              //__ZN15ProjectExplorer12BuildManager14deployProjectsERK5QListIPNS_7ProjectEE in buildmanager.o
                                                                              //__ZN15ProjectExplorer12BuildManager28potentiallyBuildForRunConfigEPNS_16RunConfigurationE in buildmanager.o
                                                                              //__ZN15ProjectExplorer12BuildManager14nextBuildQueueEv in buildmanager.o
                                                                              //__ZN15ProjectExplorer12BuildManager16buildQueueAppendERK5QListIPNS_9BuildStepEE11QStringListRKS7_ in buildmanager.o
                                                                              //...
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin24removeFromRecentProjectsERK7QStringS3_);  // ", referenced from:
                                                                                           //__ZZN15ProjectExplorer8Internal15ProjectDelegate11editorEventEP6QEventP18QAbstractItemModelRK20QStyleOptionViewItemRK11QModelIndexENKUlvE_clEv in projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin26setBuildPropertiesSettingsERKNS_23BuildPropertiesSettingsE);  // ", referenced from:
                                                                                                               //__ZN15ProjectExplorer8Internal29BuildPropertiesSettingsWidget5applyEv in buildpropertiessettingspage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin26setProjectExplorerSettingsERKNS_8Internal23ProjectExplorerSettingsE);  // ", referenced from:
                                                                                                                        //__ZN15ProjectExplorer8Internal13AppOutputPane22optionallyPromptToStopEPNS_10RunControlE in appoutputpane.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin29defaultBuildDirectoryTemplateEv);  // ", referenced from:
                                                                                    //__ZZN15ProjectExplorer8Internal29BuildPropertiesSettingsWidgetC1EvENKUlvE_clEv in buildpropertiessettingspage.o
                                                                                    //__ZZN15ProjectExplorer8Internal29BuildPropertiesSettingsWidgetC1EvENKUlvE0_clEv in buildpropertiessettingspage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin8instanceEv);  // ", referenced
                                                              // from:
                                                              //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                                              // in
                                                              // debuggerplugin.o
                                                              //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                              // in
                                                              // cppincludesfilter.o
                                                              //__ZN15ProjectExplorer8Internal17AllProjectsFilterC2Ev
                                                              // in
                                                              // allprojectsfilter.o
                                                              //__ZN15ProjectExplorer8Internal15AllProjectsFindC2Ev
                                                              // in
                                                              // allprojectsfind.o
                                                              //__ZN15ProjectExplorer14TerminalAspectC2Ev
                                                              // in
                                                              // runconfigurationaspects.o
                                                              //__ZN15ProjectExplorer8Internal12_GLOBAL__N_115SelectionWidgetC2EP7QWidget
                                                              // in
                                                              // customparser.o
                                                              //__ZN15ProjectExplorer8Internal12ProjectModelC2EP7QObject
                                                              // in
                                                              // projectwelcomepage.o
                                                              //...
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPluginC1Ev);  // ", referenced from:
                                                       //_qt_plugin_instance in
                                                       // moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPluginD0Ev);  // ", referenced from:
                                                       //__ZTVN15ProjectExplorer21ProjectExplorerPluginE
                                                       // in
                                                       // moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPluginD1Ev);  // ", referenced from:
                                                       //__ZTVN15ProjectExplorer21ProjectExplorerPluginE
                                                       // in
                                                       // moc_projectexplorer.o
unimpl(
    _ZN15ProjectExplorer8Internal16DeviceTestDialog6rejectEv);  // ", referenced
                                                                // from:
                                                                //__ZTVN15ProjectExplorer8Internal16DeviceTestDialogE
                                                                // in
                                                                // moc_devicetestdialog.o
unimpl(
    _ZN15ProjectExplorer8Internal16DeviceTestDialogD0Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN15ProjectExplorer8Internal16DeviceTestDialogE
                                                           // in
                                                           // moc_devicetestdialog.o
unimpl(
    _ZN15ProjectExplorer8Internal16DeviceTestDialogD1Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN15ProjectExplorer8Internal16DeviceTestDialogE
                                                           // in
                                                           // moc_devicetestdialog.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPage17runVersionControlERK5QListIN4Core13GeneratedFileEEP7QString);  // ", referenced from:
                                                                                                                     //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension12processFilesERK5QListIN4Core13GeneratedFileEEPbP7QString in projectfilewizardextension.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPage21initializeProjectTreeEPNS_4NodeERK11QStringListN4Core14IWizardFactory10WizardKindENS_13ProjectActionE);  // ", referenced from:
                                                                                                                                                               //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension23firstExtensionPageShownERK5QListIN4Core13GeneratedFileEERK4QMapI7QString8QVariantE in projectfilewizardextension.o
                                                                                                                                                               //__ZZN15ProjectExplorer8Internal26ProjectFileWizardExtension23firstExtensionPageShownERK5QListIN4Core13GeneratedFileEERK4QMapI7QString8QVariantEENK3$_0clEv in projectfilewizardextension.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPage25initializeVersionControlsEv);  // ", referenced from:
                                                                                     //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension23firstExtensionPageShownERK5QListIN4Core13GeneratedFileEERK4QMapI7QString8QVariantE in projectfilewizardextension.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPage8setFilesERK11QStringList);  // ", referenced from:
                                                                                 //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension23firstExtensionPageShownERK5QListIN4Core13GeneratedFileEERK4QMapI7QString8QVariantE in projectfilewizardextension.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPageC1EP7QWidget);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension14extensionPagesEPKN4Core14IWizardFactoryE
                                                                    // in
                                                                    // projectfilewizardextension.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPageD0Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN15ProjectExplorer8Internal17ProjectWizardPageE
                                                            // in
                                                            // moc_projectwizardpage.o
unimpl(
    _ZN15ProjectExplorer8Internal17ProjectWizardPageD1Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN15ProjectExplorer8Internal17ProjectWizardPageE
                                                            // in
                                                            // moc_projectwizardpage.o
unimpl(
    _ZN15ProjectExplorer8Internal20DeviceSettingsWidget12saveSettingsEv);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer8Internal20DeviceSettingsWidget5applyEv
                                                                           // in
                                                                           // moc_devicesettingswidget.o
unimpl(
    _ZN15ProjectExplorer8Internal20DeviceSettingsWidgetC1Ev);  // ", referenced
                                                               // from:
                                                               //__ZZN15ProjectExplorer8Internal18DeviceSettingsPageC1EvENK3$_0clEv
                                                               // in
                                                               // devicesettingspage.o
unimpl(
    _ZN15ProjectExplorer8Internal20DeviceSettingsWidgetD0Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN15ProjectExplorer8Internal20DeviceSettingsWidgetE
                                                               // in
                                                               // moc_devicesettingswidget.o
unimpl(
    _ZN15ProjectExplorer8Internal20DeviceSettingsWidgetD1Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN15ProjectExplorer8Internal20DeviceSettingsWidgetE
                                                               // in
                                                               // moc_devicesettingswidget.o
unimpl(
    _ZN15ProjectExplorer8Internal22SessionNameInputDialog13setActionTextERK7QStringS4_);  // ", referenced from:
                                                                                          //__ZN15ProjectExplorer8Internal12SessionModel10newSessionEP7QWidget in sessionmodel.o
                                                                                          //__ZN15ProjectExplorer8Internal12SessionModel12cloneSessionEP7QWidgetRK7QString in sessionmodel.o
                                                                                          //__ZN15ProjectExplorer8Internal12SessionModel13renameSessionEP7QWidgetRK7QString in sessionmodel.o
unimpl(
    _ZN15ProjectExplorer8Internal22SessionNameInputDialog8setValueERK7QString);  // ", referenced from:
                                                                                 //__ZN15ProjectExplorer8Internal12SessionModel12cloneSessionEP7QWidgetRK7QString in sessionmodel.o
                                                                                 //__ZN15ProjectExplorer8Internal12SessionModel13renameSessionEP7QWidgetRK7QString in sessionmodel.o
unimpl(
    _ZN15ProjectExplorer8Internal22SessionNameInputDialogC1EP7QWidget);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN15ProjectExplorer8Internal12SessionModel10newSessionEP7QWidget
                                                                         // in
                                                                         // sessionmodel.o
                                                                         //__ZN15ProjectExplorer8Internal12SessionModel12cloneSessionEP7QWidgetRK7QString
                                                                         // in
                                                                         // sessionmodel.o
                                                                         //__ZN15ProjectExplorer8Internal12SessionModel13renameSessionEP7QWidgetRK7QString
                                                                         // in
                                                                         // sessionmodel.o
unimpl(
    _ZN15ProjectExplorer8Internal24CustomParserConfigDialog11setSettingsERKNS_20CustomParserSettingsE);  // ", referenced from:
                                                                                                         //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE_clEv in customparserssettingspage.o
                                                                                                         //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE1_clEv in customparserssettingspage.o
unimpl(
    _ZN15ProjectExplorer8Internal24CustomParserConfigDialogC1EP7QWidget);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE_clEv
                                                                           // in
                                                                           // customparserssettingspage.o
                                                                           //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE1_clEv
                                                                           // in
                                                                           // customparserssettingspage.o
unimpl(
    _ZN15ProjectExplorer8Internal24CustomParserConfigDialogD0Ev);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZTVN15ProjectExplorer8Internal24CustomParserConfigDialogE
                                                                   // in
                                                                   // moc_customparserconfigdialog.o
unimpl(
    _ZN15ProjectExplorer8Internal24CustomParserConfigDialogD1Ev);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE_clEv
                                                                   // in
                                                                   // customparserssettingspage.o
                                                                   //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE1_clEv
                                                                   // in
                                                                   // customparserssettingspage.o
                                                                   //__ZTVN15ProjectExplorer8Internal24CustomParserConfigDialogE
                                                                   // in
                                                                   // moc_customparserconfigdialog.o
unimpl(
    _ZN15ProjectExplorer8Internal28DeviceFactorySelectionDialogD0Ev);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN15ProjectExplorer8Internal28DeviceFactorySelectionDialogE
                                                                       // in
                                                                       // moc_devicefactoryselectiondialog.o
unimpl(
    _ZN15ProjectExplorer8Internal28DeviceFactorySelectionDialogD1Ev);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN15ProjectExplorer8Internal28DeviceFactorySelectionDialogE
                                                                       // in
                                                                       // moc_devicefactoryselectiondialog.o
unimpl(
    _ZN15ProjectExplorer9KitAspect17notifyAboutUpdateEPNS_3KitE);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN15ProjectExplorer18ToolChainKitAspect16toolChainUpdatedEPNS_9ToolChainE
                                                                   // in
                                                                   // kitinformation.o
                                                                   //__ZN15ProjectExplorer15DeviceKitAspect13deviceUpdatedEN5Utils2IdE
                                                                   // in
                                                                   // kitinformation.o
                                                                   //__ZN9QtSupport11QtKitAspect17qtVersionsChangedERK5QListIiES4_S4_
                                                                   // in
                                                                   // qtkitinformation.o
falseimpl(
    _ZN15ProjectExplorer9KitAspectC2Ev);  // ", referenced from:
                                          //__ZN8Debugger17DebuggerKitAspectC2Ev
                                          // in debuggerkitinformation.o
                                          //__ZN15ProjectExplorer16SysRootKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer18ToolChainKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer19DeviceTypeKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer15DeviceKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer20EnvironmentKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN9QtSupport11QtKitAspectC2Ev
                                          // in qtkitinformation.o
                                          //...
unimpl(
    _ZN15ProjectExplorer9KitAspectD0Ev);  // ", referenced from:
                                          //__ZTVN15ProjectExplorer9KitAspectE
                                          // in moc_kitmanager.o
unimpl(
    _ZN15ProjectExplorer9KitAspectD1Ev);  // ", referenced from:
                                          //__ZTVN15ProjectExplorer9KitAspectE
                                          // in moc_kitmanager.o
unimpl(
    _ZN15ProjectExplorer9KitAspectD2Ev);  // ", referenced from:
                                          //__ZN8Debugger17DebuggerKitAspectC2Ev
                                          // in debuggerkitinformation.o
                                          //__ZN8Debugger17DebuggerKitAspectD2Ev
                                          // in debuggerplugin.o
                                          //__ZN15ProjectExplorer16SysRootKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer18ToolChainKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer19DeviceTypeKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer15DeviceKitAspectC2Ev
                                          // in kitinformation.o
                                          //__ZN15ProjectExplorer20EnvironmentKitAspectC2Ev
                                          // in kitinformation.o
                                          //...
unimpl(
    _ZN16ProFileEvaluator10initializeEv);  // ", referenced from:
                                           //__ZN9QtSupport8Internal15QtSupportPlugin10initializeERK11QStringListP7QString
                                           // in qtsupportplugin.o
unimpl(
    _ZN16ProFileEvaluator15setExtraConfigsERK11QStringList);  // ", referenced
                                                              // from:
                                                              //__ZN9QtSupport13ProFileReaderC2EP12QMakeGlobalsP8QMakeVfs
                                                              // in
                                                              // profilereader.o
unimpl(
    _ZN16ProFileEvaluatorC2EP12QMakeGlobalsP11QMakeParserP8QMakeVfsP12QMakeHandler);  // ", referenced from:
                                                                                      //__ZN9QtSupport13ProFileReaderC2EP12QMakeGlobalsP8QMakeVfs in profilereader.o
unimpl(
    _ZN16ProFileEvaluatorD2Ev);  // ", referenced from:
                                 //__ZN9QtSupport13ProFileReaderC2EP12QMakeGlobalsP8QMakeVfs
                                 // in profilereader.o
                                 //__ZN9QtSupport13ProFileReaderD2Ev in
                                 // profilereader.o
unimpl(
    _ZN19KSyntaxHighlighting10DefinitionC1ERKS0_);  // ", referenced from:
                                                    //__ZN10TextEditor11Highlighter22definitionsForFileNameERKN5Utils8FilePathE
                                                    // in highlighter.o
                                                    //__ZN10TextEditor11Highlighter22definitionsForMimeTypeERK7QString
                                                    // in highlighter.o
                                                    //__ZN5QListIN19KSyntaxHighlighting10DefinitionEE9node_copyEPNS2_4NodeES4_S4_
                                                    // in highlighter.o
                                                    //__ZN5QListIN19KSyntaxHighlighting10DefinitionEE14node_constructEPNS2_4NodeERKS1_
                                                    // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting10DefinitionD1Ev);  // ", referenced from:
                                                //__ZN10TextEditor11Highlighter22definitionsForFileNameERKN5Utils8FilePathE
                                                // in highlighter.o
                                                //__ZN10TextEditor11Highlighter22definitionsForMimeTypeERK7QString
                                                // in highlighter.o
                                                //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                                // in highlighter.o
                                                //__ZN5QListIN19KSyntaxHighlighting10DefinitionEE13node_destructEPNS2_4NodeES4_
                                                // in highlighter.o
                                                //__ZN7QVectorIN19KSyntaxHighlighting10DefinitionEE8destructEPS1_S3_
                                                // in highlighter.o
                                                //__ZN5QListIN19KSyntaxHighlighting10DefinitionEE9node_copyEPNS2_4NodeES4_S4_
                                                // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting10Repository19addCustomSearchPathERK7QString);  // ", referenced from:
                                                                            //__Z19highlightRepositoryv
                                                                            // in
                                                                            // highlighter.o
                                                                            //__ZN10TextEditor11Highlighter24addCustomHighlighterPathERKN5Utils8FilePathE
                                                                            // in
                                                                            // highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting10Repository6reloadEv);  // ", referenced from:
                                                     //__ZN10TextEditor11Highlighter6reloadEv
                                                     // in highlighter.o
unimpl(_ZN19KSyntaxHighlighting10RepositoryC1Ev);  // ", referenced from:
                                                   //__Z19highlightRepositoryv
                                                   // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting10RepositoryD1Ev);  // ", referenced from:
                                                //__ZN10TextEditor11Highlighter14handleShutdownEv
                                                // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting19AbstractHighlighter13highlightLineERK7QStringRKNS_5StateE);  // ", referenced from:
                                                                                           //__ZN10TextEditor11Highlighter14highlightBlockERK7QString in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting19AbstractHighlighter13setDefinitionERKNS_10DefinitionE);  // ", referenced from:
                                                                                       //__ZTVN10TextEditor11HighlighterE in moc_highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting19AbstractHighlighter8setThemeERKNS_5ThemeE);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZTVN10TextEditor11HighlighterE
                                                                           // in
                                                                           // moc_highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting19AbstractHighlighterC2Ev);  // ", referenced from:
                                                         //__ZN10TextEditor11HighlighterC2Ev
                                                         // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting19AbstractHighlighterD2Ev);  // ", referenced from:
                                                         //__ZN10TextEditor11HighlighterC2Ev
                                                         // in highlighter.o
                                                         //__ZN10TextEditor11HighlighterD2Ev
                                                         // in moc_highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting20DefinitionDownloader16staticMetaObjectE);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN7QObject7connectIMN19KSyntaxHighlighting20DefinitionDownloaderEFvvEZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEEE3$_0EENS7_9enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESK_PKS_SD_N2Qt14ConnectionTypeE
                                                                         // in
                                                                         // highlighter.o
                                                                         //__ZN7QObject7connectIMN19KSyntaxHighlighting20DefinitionDownloaderEFvRK7QStringEZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEEE3$_1EENSA_9enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESN_PKS_SG_N2Qt14ConnectionTypeE
                                                                         // in
                                                                         // highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting20DefinitionDownloader18informationMessageERK7QString);  // ", referenced from:
                                                                                     //__ZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEE in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting20DefinitionDownloader4doneEv);  // ", referenced
                                                             // from:
                                                             //__ZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEE
                                                             // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting20DefinitionDownloader5startEv);  // ", referenced
                                                              // from:
                                                              //__ZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEE
                                                              // in
                                                              // highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting20DefinitionDownloaderC1EPNS_10RepositoryEP7QObject);  // ", referenced from:
                                                                                   //__ZN10TextEditor11Highlighter19downloadDefinitionsENSt3__18functionIFvvEEE in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5StateC1ERKS0_);  // ", referenced from:
                                              //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                              // in highlighter.o
                                              //__ZN10TextEditor17TextBlockUserData11syntaxStateEv
                                              // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5StateC1Ev);  // ", referenced from:
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in textdocument.o
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in textdocument.o
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in textdocumentlayout.o
                                          //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                          // in highlighter.o
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in highlighter.o
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in cpphighlighter.o
                                          //__ZN10TextEditor17TextBlockUserDataC2Ev
                                          // in cppcodeformatter.o
                                          //...
unimpl(
    _ZN19KSyntaxHighlighting5StateD1Ev);  // ", referenced from:
                                          //__ZN10TextEditor17TextBlockUserDataD2Ev
                                          // in textdocumentlayout.o
                                          //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                          // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5StateaSERKS0_);  // ", referenced from:
                                              //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                              // in highlighter.o
                                              //__ZN10TextEditor17TextBlockUserData14setSyntaxStateEN19KSyntaxHighlighting5StateE
                                              // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5Theme16staticMetaObjectE);  // ", referenced from:
                                                         //__ZN19KSyntaxHighlighting20qt_getEnumMetaObjectENS_5Theme9TextStyleE
                                                         // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5ThemeC1Ev);  // ", referenced from:
                                          //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                          // in highlighter.o
unimpl(
    _ZN19KSyntaxHighlighting5ThemeD1Ev);  // ", referenced from:
                                          //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                          // in highlighter.o
unimpl(_ZN20FilePropertiesDialogD0Ev);  // ", referenced from:
                                        //__ZTV20FilePropertiesDialog in
                                        // moc_filepropertiesdialog.o
unimpl(_ZN20FilePropertiesDialogD1Ev);  // ", referenced from:
                                        //__ZTV20FilePropertiesDialog in
                                        // moc_filepropertiesdialog.o
unimpl(
    _ZN4Core11IFindFilter11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN10TextEditor12BaseFileFind11qt_metacallEN11QMetaObject4CallEiPPv
                                                                   // in
                                                                   // moc_basefilefind.o
                                                                   //__ZN8CppTools8Internal17SymbolsFindFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                   // in
                                                                   // moc_symbolsfindfilter.o
unimpl(
    _ZN4Core11IFindFilter11qt_metacastEPKc);  // ", referenced from:
                                              //__ZN10TextEditor12BaseFileFind11qt_metacastEPKc
                                              // in moc_basefilefind.o
                                              //__ZN8CppTools8Internal17SymbolsFindFilter11qt_metacastEPKc
                                              // in moc_symbolsfindfilter.o
unimpl(
    _ZN4Core11IFindFilter12validChangedEb);  // ", referenced from:
                                             //__ZN10TextEditor11FindInFiles8setValidEb
                                             // in findinfiles.o
unimpl(
    _ZN4Core11IFindFilter14enabledChangedEb);  // ", referenced from:
                                               //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                               // in basefilefind.o
                                               //__ZN10TextEditor8Internal17FindInCurrentFile16handleFileChangeEPN4Core7IEditorE
                                               // in findincurrentfile.o
                                               //__ZN10TextEditor8Internal15FindInOpenFiles18updateEnabledStateEv
                                               // in findinopenfiles.o
                                               //__ZN8CppTools8Internal17SymbolsFindFilter13onTaskStartedEN5Utils2IdE
                                               // in symbolsfindfilter.o
                                               //__ZN8CppTools8Internal17SymbolsFindFilter18onAllTasksFinishedEN5Utils2IdE
                                               // in symbolsfindfilter.o
                                               //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                               // in symbolsfindfilter.o
                                               //__ZN15ProjectExplorer8Internal15AllProjectsFind21handleFileListChangedEv
                                               // in allprojectsfind.o
                                               //...
unimpl(
    _ZN4Core11IFindFilter16staticMetaObjectE);  // ", referenced from:
                                                //__ZN7QObject7connectIMN4Core11IFindFilterEFvbEMNS1_12SearchResultEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESC_PKNSB_IT0_E6ObjectESH_N2Qt14ConnectionTypeE
                                                // in basefilefind.o
                                                //__ZN7QObject7connectIMN4Core11IFindFilterEFvbEMNS1_12SearchResultEFvbEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESC_PKNSB_IT0_E6ObjectESH_N2Qt14ConnectionTypeE
                                                // in symbolsfindfilter.o
                                                //__ZN10TextEditor12BaseFileFind16staticMetaObjectE
                                                // in moc_basefilefind.o
                                                //__ZN8CppTools8Internal17SymbolsFindFilter16staticMetaObjectE
                                                // in moc_symbolsfindfilter.o
unimpl(
    _ZN4Core11IFindFilter18displayNameChangedEv);  // ", referenced from:
                                                   //__ZN15ProjectExplorer8Internal18CurrentProjectFind20handleProjectChangedEv
                                                   // in currentprojectfind.o
                                                   //__ZZN15ProjectExplorer8Internal18CurrentProjectFindC1EvENK3$_0clEPNS_7ProjectE
                                                   // in currentprojectfind.o
unimpl(
    _ZN4Core11IFindFilter23descriptionForFindFlagsE6QFlagsINS_8FindFlagEE);  // ", referenced from:
                                                                             //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE in basefilefind.o
                                                                             //__ZNK8CppTools8Internal17SymbolsFindFilter7toolTipE6QFlagsIN4Core8FindFlagEE in symbolsfindfilter.o
unimpl(
    _ZN4Core11IFindFilterC2Ev);  // ", referenced from:
                                 //__ZN10TextEditor12BaseFileFindC2Ev in
                                 // basefilefind.o
                                 //__ZN8CppTools8Internal17SymbolsFindFilterC2EPNS_15CppModelManagerE
                                 // in symbolsfindfilter.o
unimpl(
    _ZN4Core11IFindFilterD2Ev);  // ", referenced from:
                                 //__ZN10TextEditor12BaseFileFindC2Ev in
                                 // basefilefind.o
                                 //__ZN10TextEditor12BaseFileFindD2Ev in
                                 // basefilefind.o
                                 //__ZN8CppTools8Internal17SymbolsFindFilterC2EPNS_15CppModelManagerE
                                 // in symbolsfindfilter.o
                                 //__ZN8CppTools8Internal17SymbolsFindFilterD2Ev
                                 // in moc_symbolsfindfilter.o
unimpl(
    _ZN4Core12BaseTextFindC1EP14QPlainTextEdit);  // ", referenced from:
                                                  //__ZN8Debugger8Internal9LogWindowC2EPNS0_14DebuggerEngineE
                                                  // in logwindow.o
                                                  //__ZN8Debugger8Internal15GlobalLogWindowC2Ev
                                                  // in logwindow.o
                                                  //__ZN4Core8Internal19MessageOutputWindowC2Ev
                                                  // in messageoutputwindow.o
                                                  //__ZN15ProjectExplorer8Internal19CompileOutputWindowC2EP7QAction
                                                  // in compileoutputwindow.o
                                                  //__ZN15ProjectExplorer8Internal13AppOutputPane21createNewOutputWindowEPNS_10RunControlE
                                                  // in appoutputpane.o
                                                  //__ZN7VcsBase8Internal25OutputWindowPlainTextEditC2EP7QWidget
                                                  // in vcsoutputwindow.o
unimpl(
    _ZN4Core12BaseTextFindC1EP9QTextEdit);  // ", referenced from:
                                            //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE
                                            // in vcsbasesubmiteditor.o
unimpl(
    _ZN4Core12IFindSupport10replaceAllERK7QStringS3_6QFlagsINS_8FindFlagEE);  // ", referenced from:
                                                                              //__ZTVN9BinEditor8Internal13BinEditorFindE in bineditorplugin.o
                                                                              //__ZTVN9CppEditor8Internal13IncludeFinderE in cppincludehierarchy.o
unimpl(
    _ZN4Core12IFindSupport11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN9BinEditor8Internal13BinEditorFind11qt_metacallEN11QMetaObject4CallEiPPv
                                                                    // in
                                                                    // bineditorplugin.o
unimpl(
    _ZN4Core12IFindSupport11qt_metacastEPKc);  // ", referenced from:
                                               //__ZN9BinEditor8Internal13BinEditorFind11qt_metacastEPKc
                                               // in bineditorplugin.o
unimpl(
    _ZN4Core12IFindSupport11replaceStepERK7QStringS3_6QFlagsINS_8FindFlagEE);  // ", referenced from:
                                                                               //__ZTVN9BinEditor8Internal13BinEditorFindE in bineditorplugin.o
                                                                               //__ZTVN9CppEditor8Internal13IncludeFinderE in cppincludehierarchy.o
unimpl(
    _ZN4Core12IFindSupport16staticMetaObjectE);  // ", referenced from:
                                                 //__Z12qobject_castIPN4Core12IFindSupportEET_P7QObject
                                                 // in basefilefind.o
                                                 //__ZN9BinEditor8Internal13BinEditorFind16staticMetaObjectE
                                                 // in bineditorplugin.o
unimpl(
    _ZN4Core12IFindSupport17showWrapIndicatorEP7QWidget);  // ", referenced
                                                           // from:
                                                           //__ZN9BinEditor8Internal13BinEditorFind15findIncrementalERK7QString6QFlagsIN4Core8FindFlagEE
                                                           // in
                                                           // bineditorplugin.o
                                                           //__ZN9BinEditor8Internal13BinEditorFind8findStepERK7QString6QFlagsIN4Core8FindFlagEE
                                                           // in
                                                           // bineditorplugin.o
unimpl(
    _ZN4Core12IFindSupport7replaceERK7QStringS3_6QFlagsINS_8FindFlagEE);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN9BinEditor8Internal13BinEditorFindE
                                                                          // in
                                                                          // bineditorplugin.o
                                                                          //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                                          // in
                                                                          // cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                                    // in
                                                                    // cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind11qt_metacastEPKc);  // ", referenced from:
                                               //__ZTVN9CppEditor8Internal13IncludeFinderE
                                               // in cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind12highlightAllERK7QString6QFlagsINS_8FindFlagEE);  // ", referenced from:
                                                                             //__ZTVN9CppEditor8Internal13IncludeFinderE in cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind15clearHighlightsEv);  // ", referenced from:
                                                 //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                 // in cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind15findIncrementalERK7QString6QFlagsINS_8FindFlagEE);  // ", referenced from:
                                                                                //__ZN9CppEditor8Internal13IncludeFinder15findIncrementalERK7QString6QFlagsIN4Core8FindFlagEE in cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind22resetIncrementalSearchEv);  // ", referenced from:
                                                        //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                        // in
                                                        // cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind23createSearchableWrapperEP17QAbstractItemViewNS0_11ColorOptionENS0_11FetchOptionE);  // ", referenced from:
                                                                                                                //__ZN8Debugger8Internal21DebuggerPluginPrivate9addSearchEPN5Utils12BaseTreeViewE in debuggerplugin.o
                                                                                                                //__ZN9CppEditor8Internal16CppOutlineWidgetC2EPNS0_15CppEditorWidgetE in cppoutline.o
                                                                                                                //__ZN9CppEditor8Internal22CppTypeHierarchyWidgetC2Ev in cpptypehierarchy.o
                                                                                                                //__ZN15ProjectExplorer17EnvironmentWidgetC2EP7QWidgetNS0_4TypeES2_ in environmentwidget.o
                                                                                                                //__ZN15ProjectExplorer8Internal17ProjectTreeWidgetC2EP7QWidget in projecttreewidget.o
                                                                                                                //__ZN11QmlJSEditor8Internal18QmlJSOutlineWidgetC2EP7QWidget in qmljsoutline.o
unimpl(
    _ZN4Core12ItemViewFind23createSearchableWrapperEPS0_NS0_11ColorOptionE);  // ", referenced from:
                                                                              //__ZN9CppEditor8Internal25CppIncludeHierarchyWidgetC2Ev in cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFind8findStepERK7QString6QFlagsINS_8FindFlagEE);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN9CppEditor8Internal13IncludeFinder8findStepERK7QString6QFlagsIN4Core8FindFlagEE
                                                                        // in
                                                                        // cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFindC2EP17QAbstractItemViewiNS0_11FetchOptionE);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN9CppEditor8Internal13IncludeFinderC2EP17QAbstractItemViewPNS0_24CppIncludeHierarchyModelE
                                                                        // in
                                                                        // cppincludehierarchy.o
unimpl(
    _ZN4Core12ItemViewFindD2Ev);  // ", referenced from:
                                  //__ZN9CppEditor8Internal13IncludeFinderD2Ev
                                  // in cppincludehierarchy.o
unimpl(
    _ZN4Core12OptionsPopupC1EP7QWidgetRK7QVectorIN5Utils2IdEE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN4Core11IOutputPane25filterOutputButtonClickedEv
                                                                 // in
                                                                 // outputpanemanager.o
unimpl(
    _ZN4Core12SearchResult10addResultsERK5QListINS_16SearchResultItemEENS0_7AddModeE);  // ", referenced from:
                                                                                        //__ZN10TextEditorL13displayResultEP14QFutureWatcherI5QListIN5Utils16FileSearchResultEEEPN4Core12SearchResultEi in basefilefind.o
                                                                                        //__ZN8CppTools8Internal17SymbolsFindFilter10addResultsEii in symbolsfindfilter.o
unimpl(
    _ZN4Core12SearchResult11setUserDataERK8QVariant);  // ", referenced from:
                                                       //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                       // in basefilefind.o
                                                       //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb
                                                       // in cppfindreferences.o
                                                       //__ZL14displayResultsPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEEii
                                                       // in cppfindreferences.o
                                                       //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                       // in symbolsfindfilter.o
unimpl(
    _ZN4Core12SearchResult12countChangedEi);  // ", referenced from:
                                              //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                              // in basefilefind.o
unimpl(
    _ZN4Core12SearchResult12finishSearchEb);  // ", referenced from:
                                              //__ZZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultEENK3$_5clEv
                                              // in basefilefind.o
                                              //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                              // in cppeditorwidget.o
                                              //__ZN8CppTools8Internal17CppFindReferences11searchAgainEv
                                              // in cppfindreferences.o
                                              //__ZN8CppTools8Internal17CppFindReferences14findAll_helperEPN4Core12SearchResultEPN9CPlusPlus6SymbolERKNS5_13LookupContextE
                                              // in cppfindreferences.o
                                              //__ZL14searchFinishedPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEE
                                              // in cppfindreferences.o
                                              //__ZZN8CppTools8Internal17CppFindReferences13createWatcherERK7QFutureIN9CPlusPlus5UsageEEPN4Core12SearchResultEENK3$_6clEv
                                              // in cppfindreferences.o
                                              //__ZN8CppTools8Internal17SymbolsFindFilter6finishEv
                                              // in symbolsfindfilter.o
                                              //...
unimpl(
    _ZN4Core12SearchResult16setTextToReplaceERK7QString);  // ", referenced
                                                           // from:
                                                           //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                           // in basefilefind.o
                                                           //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                                           // in
                                                           // cppeditorwidget.o
                                                           //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb
                                                           // in
                                                           // cppfindreferences.o
                                                           //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb
                                                           // in
                                                           // cppfindreferences.o
                                                           //__ZN11QmlJSEditor14FindReferences14displayResultsEii
                                                           // in
                                                           // qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult16staticMetaObjectE);  // ", referenced from:
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvRKNS1_16SearchResultItemEEZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsINS1_8FindFlagEENS1_18SearchResultWindow10SearchModeEE3$_0EENSt3__19enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESS_PKS_SL_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvRK7QStringRK5QListINS1_16SearchResultItemEEbEMN10TextEditor12BaseFileFindEFvS5_SA_bEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESL_PKNSK_IT0_E6ObjectESQ_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvbEMN10TextEditor12BaseFileFindEFvbEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESD_PKNSC_IT0_E6ObjectESI_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvvEZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsINS1_8FindFlagEENS1_18SearchResultWindow10SearchModeEE3$_1EENSt3__19enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESP_PKS_SI_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvvEZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsINS1_8FindFlagEENS1_18SearchResultWindow10SearchModeEE3$_2EENSt3__19enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESP_PKS_SI_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvvEM18QFutureWatcherBaseFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESC_PKNSB_IT0_E6ObjectESH_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //__ZN7QObject7connectIMN4Core12SearchResultEFvbEZN10TextEditor12BaseFileFind9runSearchEPS2_E3$_3EENSt3__19enable_ifIXeqsr9QtPrivate15FunctionPointerIT0_EE13ArgumentCountngLi1EEN11QMetaObject10ConnectionEE4typeEPKN9QtPrivate15FunctionPointerIT_E6ObjectESI_PKS_SB_N2Qt14ConnectionTypeE
                                                 // in basefilefind.o
                                                 //...
unimpl(
    _ZN4Core12SearchResult17visibilityChangedEb);  // ", referenced from:
                                                   //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                   // in basefilefind.o
unimpl(
    _ZN4Core12SearchResult19requestEnabledCheckEv);  // ", referenced from:
                                                     //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                     // in basefilefind.o
unimpl(
    _ZN4Core12SearchResult20replaceButtonClickedERK7QStringRK5QListINS_16SearchResultItemEEb);  // ", referenced from:
                                                                                                //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE in basefilefind.o
                                                                                                //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString in cppeditorwidget.o
                                                                                                //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb in cppfindreferences.o
                                                                                                //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb in cppfindreferences.o
                                                                                                //__ZN11QmlJSEditor14FindReferences14displayResultsEii in qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult20searchAgainRequestedEv);  // ", referenced from:
                                                      //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                      // in basefilefind.o
                                                      //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                                      // in cppeditorwidget.o
                                                      //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb
                                                      // in cppfindreferences.o
                                                      //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                      // in symbolsfindfilter.o
unimpl(
    _ZN4Core12SearchResult21setSearchAgainEnabledEb);  // ", referenced from:
                                                       //__ZN10TextEditor12BaseFileFind14recheckEnabledEPN4Core12SearchResultE
                                                       // in basefilefind.o
                                                       //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                       // in symbolsfindfilter.o
                                                       //__ZN15ProjectExplorer8Internal18CurrentProjectFind14recheckEnabledEv
                                                       // in
                                                       // currentprojectfind.o
unimpl(
    _ZN4Core12SearchResult23setSearchAgainSupportedEb);  // ", referenced from:
                                                         //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                         // in basefilefind.o
                                                         //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                                         // in cppeditorwidget.o
                                                         //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb
                                                         // in
                                                         // cppfindreferences.o
                                                         //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                         // in
                                                         // symbolsfindfilter.o
unimpl(
    _ZN4Core12SearchResult26setAdditionalReplaceWidgetEP7QWidget);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb
                                                                    // in
                                                                    // cppfindreferences.o
                                                                    //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb
                                                                    // in
                                                                    // cppfindreferences.o
unimpl(
    _ZN4Core12SearchResult5popupEv);  // ", referenced from:
                                      //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                      // in basefilefind.o
                                      //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                      // in cppeditorwidget.o
                                      //__ZN8CppTools8Internal17CppFindReferences14findAll_helperEPN4Core12SearchResultEPN9CPlusPlus6SymbolERKNS5_13LookupContextE
                                      // in cppfindreferences.o
                                      //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb
                                      // in cppfindreferences.o
                                      //__ZN8CppTools8Internal17SymbolsFindFilter11startSearchEPN4Core12SearchResultE
                                      // in symbolsfindfilter.o
                                      //__ZN11QmlJSEditor14FindReferences14displayResultsEii
                                      // in qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult6pausedEb);  // ", referenced from:
                                       //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                       // in basefilefind.o
                                       //__ZN8CppTools8Internal17CppFindReferences13createWatcherERK7QFutureIN9CPlusPlus5UsageEEPN4Core12SearchResultE
                                       // in cppfindreferences.o
                                       //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                       // in symbolsfindfilter.o
                                       //__ZN11QmlJSEditor14FindReferences14displayResultsEii
                                       // in qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult7restartEv);  // ", referenced from:
                                        //__ZN10TextEditor12BaseFileFind11searchAgainEPN4Core12SearchResultE
                                        // in basefilefind.o
                                        //__ZN8CppTools8Internal17CppFindReferences11searchAgainEv
                                        // in cppfindreferences.o
                                        //__ZN8CppTools8Internal17SymbolsFindFilter11searchAgainEv
                                        // in symbolsfindfilter.o
unimpl(
    _ZN4Core12SearchResult9activatedERKNS_16SearchResultItemE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                                                 // in
                                                                 // basefilefind.o
                                                                 //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                                                 // in
                                                                 // cppeditorwidget.o
                                                                 //__ZN8CppTools8Internal17CppFindReferences14findAll_helperEPN4Core12SearchResultEPN9CPlusPlus6SymbolERKNS5_13LookupContextE
                                                                 // in
                                                                 // cppfindreferences.o
                                                                 //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb
                                                                 // in
                                                                 // cppfindreferences.o
                                                                 //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                                 // in
                                                                 // symbolsfindfilter.o
                                                                 //__ZN11QmlJSEditor14FindReferences14displayResultsEii
                                                                 // in
                                                                 // qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult9addResultERK7QStringS3_NS_6Search9TextRangeERK8QVariantNS_17SearchResultColor5StyleE);  // ", referenced from:
                                                                                                                   //__ZN9CppEditor8InternalL16addSearchResultsENSt3__16vectorIN8CppTools5UsageENS1_9allocatorIS4_EEEERN4Core12SearchResultERK7QString in cppeditorwidget.o
unimpl(
    _ZN4Core12SearchResult9addResultERK7QStringiS3_iiRK8QVariantNS_17SearchResultColor5StyleE);  // ", referenced from:
                                                                                                 //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb in cppfindreferences.o
                                                                                                 //__ZL14displayResultsPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEEii in cppfindreferences.o
                                                                                                 //__ZN11QmlJSEditor14FindReferences14displayResultsEii in qmljsfindreferences.o
unimpl(
    _ZN4Core12SearchResult9cancelledEv);  // ", referenced from:
                                          //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                          // in basefilefind.o
                                          //__ZN8CppTools8Internal17CppFindReferences13createWatcherERK7QFutureIN9CPlusPlus5UsageEEPN4Core12SearchResultE
                                          // in cppfindreferences.o
                                          //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE
                                          // in symbolsfindfilter.o
                                          //__ZN11QmlJSEditor14FindReferences14displayResultsEii
                                          // in qmljsfindreferences.o
unimpl(
    _ZN4Core12ShellCommand11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN7VcsBase10VcsCommand11qt_metacallEN11QMetaObject4CallEiPPv
                                                                    // in
                                                                    // moc_vcscommand.o
unimpl(
    _ZN4Core12ShellCommand11qt_metacastEPKc);  // ", referenced from:
                                               //__ZN7VcsBase10VcsCommand11qt_metacastEPKc
                                               // in moc_vcscommand.o
unimpl(
    _ZN4Core12ShellCommand16staticMetaObjectE);  // ", referenced from:
                                                 //__ZN7VcsBase10VcsCommand16staticMetaObjectE
                                                 // in moc_vcscommand.o
unimpl(
    _ZN4Core12ShellCommand7addTaskER7QFutureIvE);  // ", referenced from:
                                                   //__ZTVN7VcsBase10VcsCommandE
                                                   // in moc_vcscommand.o
unimpl(
    _ZN4Core12ShellCommandC2ERK7QStringRK19QProcessEnvironment);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN7VcsBase10VcsCommandC2ERK7QStringRK19QProcessEnvironment
                                                                  // in
                                                                  // vcscommand.o
unimpl(
    _ZN4Core13EditorManager10openEditorERK7QStringN5Utils2IdE6QFlagsINS0_14OpenEditorFlagEEPb);  // ", referenced from:
                                                                                                 //__ZNK8Debugger8Internal12BreakHandler12gotoLocationERK8QPointerINS0_14BreakpointItemEE in breakhandler.o
                                                                                                 //__ZNK8Debugger8Internal17BreakpointManager12gotoLocationERK8QPointerINS0_20GlobalBreakpointItemEE in breakhandler.o
                                                                                                 //__ZN8Debugger8Internal14DebuggerEngine12gotoLocationERKNS0_8LocationE in debuggerengine.o
                                                                                                 //__ZL15openImageViewerRK6QImage in imageviewer.o
                                                                                                 //__ZN4Core21BaseFileWizardFactory23postGenerateOpenEditorsERK5QListINS_13GeneratedFileEEP7QString in basefilewizardfactory.o
                                                                                                 //__ZN8CppTools8Internal14CppToolsPlugin29switchHeaderSourceInNextSplitEv in cpptoolsplugin.o
                                                                                                 //__ZN8CppTools18switchHeaderSourceEv in cpptoolsreuse.o
                                                                                                 //...
unimpl(
    _ZN4Core13EditorManager12openEditorAtERK7QStringiiN5Utils2IdE6QFlagsINS0_14OpenEditorFlagEEPb);  // ", referenced from:
                                                                                                     //__ZZN4Core12OutputWindowC1ENS_7ContextERK7QStringP7QWidgetENK3$_2clERKN5Utils8FilePathEii in outputwindow.o
                                                                                                     //__ZN10TextEditor18RefactoringChanges10openEditorERK7QStringbii in refactoringchanges.o
                                                                                                     //__ZN9CppEditor8Internal25CppIncludeHierarchyWidget15onItemActivatedERK11QModelIndex in cppincludehierarchy.o
                                                                                                     //__ZN9CppEditor8Internal22CppTypeHierarchyWidget15onItemActivatedERK11QModelIndex in cpptypehierarchy.o
                                                                                                     //__ZNK8CppTools8Internal24CppCurrentDocumentFilter6acceptEN4Core18LocatorFilterEntryEP7QStringPiS6_ in cppcurrentdocumentfilter.o
                                                                                                     //__ZNK8CppTools8Internal16CppLocatorFilter6acceptEN4Core18LocatorFilterEntryEP7QStringPiS6_ in cpplocatorfilter.o
                                                                                                     //__ZNK8CppTools27VirtualFunctionProposalItem5applyERN10TextEditor32TextDocumentManipulatorInterfaceEi in cppvirtualfunctionproposalitem.o
                                                                                                     //...
unimpl(
    _ZN4Core13EditorManager12restoreStateERK10QByteArray);  // ", referenced
                                                            // from:
                                                            //__ZN15ProjectExplorer21SessionManagerPrivate14restoreEditorsERKN5Utils24PersistentSettingsReaderE
                                                            // in session.o
unimpl(
    _ZN4Core13EditorManager12saveDocumentEPNS_9IDocumentE);  // ", referenced
                                                             // from:
                                                             //__ZN10DiffEditor8Internal18DiffEditorDocument14selectEncodingEv
                                                             // in
                                                             // diffeditordocument.o
unimpl(
    _ZN4Core13EditorManager12saveDocumentEv);  // ", referenced from:
                                               //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                               // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager13clearUniqueIdEPNS_9IDocumentE);  // ", referenced
                                                              // from:
                                                              //__ZN10DiffEditor8Internal18DiffEditorDocument4saveEP7QStringRKS2_b
                                                              // in
                                                              // diffeditordocument.o
unimpl(
    _ZN4Core13EditorManager13currentEditorEv);  // ", referenced from:
                                                //__ZZN8Debugger8Internal21DebuggerPluginPrivateC1ERK11QStringListENK3$_6clEN5Utils2IdES7_
                                                // in debuggerplugin.o
                                                //__ZN8Debugger8Internal17DisassemblerAgent20updateLocationMarkerEv
                                                // in disassembleragent.o
                                                //__ZN4Core8Internal8EditMode17grabEditorManagerEN5Utils2IdE
                                                // in editmode.o
                                                //__ZNK4Core8Internal14SplitterOrView9saveStateEv
                                                // in editorview.o
                                                //__ZN4Core8Internal17OpenEditorsWidgetC2Ev
                                                // in openeditorsview.o
                                                //__ZN4Core8Internal17OpenEditorsWidget13closeDocumentERK11QModelIndex
                                                // in openeditorsview.o
                                                //__ZN4Core13EditorToolBar19fillListContextMenuEP5QMenu
                                                // in editortoolbar.o
                                                //...
unimpl(
    _ZN4Core13EditorManager13revertToSavedEv);  // ", referenced from:
                                                //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager14activateEditorEPNS_7IEditorE6QFlagsINS0_14OpenEditorFlagEE);  // ", referenced from:
                                                                                           //__ZN8Debugger8Internal11SourceAgent10setContentERK7QStringS4_ in sourceagent.o
                                                                                           //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv in sourceagent.o
                                                                                           //__ZNK10TextEditor8Internal16LineNumberFilter6acceptEN4Core18LocatorFilterEntryEP7QStringPiS6_ in linenumberfilter.o
                                                                                           //__ZNK7VcsBase20VcsBasePluginPrivate17raiseSubmitEditorEv in vcsbaseplugin.o
                                                                                           //__ZN7VcsBase19VcsBaseSubmitEditor12promptSubmitEPNS_20VcsBasePluginPrivateEPbbb in vcsbasesubmiteditor.o
                                                                                           //__ZNK7VcsBase17VcsBaseClientImpl15createVcsEditorEN5Utils2IdE7QStringRKS3_P10QTextCodecPKcS5_ in vcsbaseclient.o
unimpl(
    _ZN4Core13EditorManager14closeDocumentsERK5QListIPNS_13DocumentModel5EntryEE);  // ", referenced from:
                                                                                    //__ZN4Core8Internal17OpenEditorsWidget13closeDocumentERK11QModelIndex in openeditorsview.o
falseimpl(
    _ZN4Core13EditorManager14closeDocumentsERK5QListIPNS_9IDocumentEEb);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZN8Debugger8Internal21DebuggerEnginePrivate12cleanupViewsEv
                                                                          // in
                                                                          // debuggerengine.o
                                                                          //__ZN8Debugger8Internal24DisassemblerAgentPrivateD2Ev
                                                                          // in
                                                                          // disassembleragent.o
                                                                          //__ZN8Debugger8Internal11MemoryAgentD2Ev
                                                                          // in
                                                                          // memoryagent.o
                                                                          //__ZN8Debugger8Internal18SourceAgentPrivateD2Ev
                                                                          // in
                                                                          // sourceagent.o
unimpl(
    _ZN4Core13EditorManager14gotoOtherSplitEv);  // ", referenced from:
                                                 //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                 // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager14saveDocumentAsEv);  // ", referenced from:
                                                 //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                 // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager14visibleEditorsEv);  // ", referenced from:
                                                 //__ZNK8CppTools15CppModelManager24updateCppEditorDocumentsEb
                                                 // in cppmodelmanager.o
                                                 //__ZNK8CppTools8Internal37CppToolsBridgeQtCreatorImplementation14visibleEditorsEv
                                                 // in
                                                 // cpptoolsbridgeqtcreatorimplementation.o
unimpl(
    _ZN4Core13EditorManager15closeAllEditorsEb);  // ", referenced from:
                                                  //__ZN15ProjectExplorer14SessionManager11loadSessionERK7QStringb
                                                  // in session.o
                                                  //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                  // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager15currentDocumentEv);  // ", referenced from:
                                                  //__ZN8Debugger8Internal17DisassemblerAgent20updateLocationMarkerEv
                                                  // in disassembleragent.o
                                                  //__ZN4Core10VcsManager30findVersionControlForDirectoryERK7QStringPS1_
                                                  // in vcsmanager.o
                                                  //__ZN4Core13EditorToolBar18makeEditorWritableEv
                                                  // in editortoolbar.o
                                                  //__ZN4Core8Internal18ExternalToolRunner3runEv
                                                  // in externaltool.o
                                                  //__ZN10TextEditor12TextDocument19currentTextDocumentEv
                                                  // in textdocument.o
                                                  //__ZN10TextEditor12TextDocument19currentTextDocumentEv
                                                  // in textdocument.o
                                                  //__ZN8CppTools8Internal14CppToolsPlugin29switchHeaderSourceInNextSplitEv
                                                  // in cpptoolsplugin.o
                                                  //...
unimpl(
    _ZN4Core13EditorManager15maxTextFileSizeEv);  // ", referenced from:
                                                  //__ZN4Core14IEditorFactory24preferredEditorFactoriesERK7QString
                                                  // in ieditorfactory.o
                                                  //__ZN10TextEditor12TextDocument12setPlainTextERK7QString
                                                  // in textdocument.o
                                                  //__ZN10TextEditor12TextDocument12setPlainTextERK7QString
                                                  // in textdocument.o
unimpl(
    _ZN4Core13EditorManager15splitSideBySideEv);  // ", referenced from:
                                                  //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                  // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager16defaultTextCodecEv);  // ", referenced from:
                                                   //__ZNK4Core13GeneratedFile5writeEP7QString
                                                   // in generatedfile.o
                                                   //__ZNK10TextEditor11FindInFiles5filesERK11QStringListS3_RK8QVariant
                                                   // in findinfiles.o
                                                   //__ZNK10TextEditor8Internal17FindInCurrentFile5filesERK11QStringListS4_RK8QVariant
                                                   // in findincurrentfile.o
                                                   //__ZNK10TextEditor8Internal15FindInOpenFiles5filesERK11QStringListS4_RK8QVariant
                                                   // in findinopenfiles.o
                                                   //__ZNK10TextEditor18RefactoringChanges10createFileERK7QStringS3_bb
                                                   // in refactoringchanges.o
                                                   //__ZNK10TextEditor15RefactoringFile15mutableDocumentEv
                                                   // in refactoringchanges.o
                                                   //__ZN9CppEditor8InternalL18getCurrentDocumentERK7QString
                                                   // in cppeditorwidget.o
                                                   //...
unimpl(
    _ZN4Core13EditorManager17defaultLineEndingEv);  // ", referenced from:
                                                    //__ZNK4Core13GeneratedFile5writeEP7QString
                                                    // in generatedfile.o
unimpl(
    _ZN4Core13EditorManager18updateWindowTitlesEv);  // ", referenced from:
                                                     //__ZN15ProjectExplorer14SessionManagerC2EP7QObject
                                                     // in session.o
                                                     //__ZN15ProjectExplorer14SessionManager11loadSessionERK7QStringb
                                                     // in session.o
                                                     //__ZN7VcsBase8Internal13StateListener16slotStateChangedEv
                                                     // in vcsbaseplugin.o
                                                     //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                     // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager19addPinEditorActionsEP5QMenuPNS_13DocumentModel5EntryE);  // ", referenced from:
                                                                                      //__ZN4Core8Internal17OpenEditorsWidget20contextMenuRequestedE6QPoint in openeditorsview.o
                                                                                      //__ZN4Core13EditorToolBar19fillListContextMenuEP5QMenu in editortoolbar.o
unimpl(
    _ZN4Core13EditorManager19closeOtherDocumentsEv);  // ", referenced from:
                                                      //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                      // in moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager22activateEditorForEntryEPNS_13DocumentModel5EntryE6QFlagsINS0_14OpenEditorFlagEE);  // ", referenced from:
                                                                                                                //__ZN4Core8Internal17OpenEditorsWidget14activateEditorERK11QModelIndex in openeditorsview.o
                                                                                                                //__ZN4Core13EditorToolBar18changeActiveEditorEi in editortoolbar.o
unimpl(
    _ZN4Core13EditorManager22addCloseEditorListenerERKNSt3__18functionIFbPNS_7IEditorEEEE);  // ", referenced from:
                                                                                             //__ZN7VcsBase8Internal9VcsPlugin10initializeERK11QStringListP7QString in vcsplugin.o
unimpl(
    _ZN4Core13EditorManager22openEditorWithContentsEN5Utils2IdEP7QStringRK10QByteArrayRKS3_6QFlagsINS0_14OpenEditorFlagEE);  // ", referenced from:
                                                                                                                             //__ZN8Debugger8Internal14openTextEditorERK7QStringS3_ in debuggerplugin.o
                                                                                                                             //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE in disassembleragent.o
                                                                                                                             //__ZN8Debugger8Internal11SourceAgent10setContentERK7QStringS4_ in sourceagent.o
                                                                                                                             //__ZN9BinEditor8Internal18FactoryServiceImpl19createEditorServiceERK7QStringb in bineditorplugin.o
                                                                                                                             //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv in qmljseditor.o
                                                                                                                             //__ZNK7VcsBase17VcsBaseClientImpl15createVcsEditorEN5Utils2IdE7QStringRKS3_P10QTextCodecPKcS5_ in vcsbaseclient.o
                                                                                                                             //__ZN10DiffEditor20DiffEditorController20findOrCreateDocumentERK7QStringS3_ in diffeditorcontroller.o
                                                                                                                             //...
unimpl(
    _ZN4Core13EditorManager22setSessionTitleHandlerENSt3__18functionIF7QStringRKS3_EEE);  // ", referenced from:
                                                                                          //__ZN15ProjectExplorer14SessionManagerC2EP7QObject in session.o
                                                                                          //__ZN15ProjectExplorer14SessionManagerD2Ev in session.o
unimpl(
    _ZN4Core13EditorManager22skipOpeningBigTextFileERK7QString);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN10DiffEditor8Internal23DiffEditorPluginPrivate17diffExternalFilesEv
                                                                  // in
                                                                  // diffeditorplugin.o
unimpl(
    _ZN4Core13EditorManager24openEditorAtSearchResultERKNS_16SearchResultItemEN5Utils2IdE6QFlagsINS0_14OpenEditorFlagEEPb);  // ", referenced from:
                                                                                                                             //__ZN10TextEditor12BaseFileFind10openEditorEPN4Core12SearchResultERKNS1_16SearchResultItemE in basefilefind.o
                                                                                                                             //__ZZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QStringENK4$_13clERKN4Core16SearchResultItemE in cppeditorwidget.o
                                                                                                                             //__ZZN8CppTools8Internal17CppFindReferences14findAll_helperEPN4Core12SearchResultEPN9CPlusPlus6SymbolERKNS5_13LookupContextEENK3$_0clERKNS2_16SearchResultItemE in cppfindreferences.o
                                                                                                                             //__ZZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringbENK3$_3clERKN4Core16SearchResultItemE in cppfindreferences.o
                                                                                                                             //__ZZN11QmlJSEditor14FindReferences14displayResultsEiiENK3$_0clERKN4Core16SearchResultItemE in qmljsfindreferences.o
unimpl(
    _ZN4Core13EditorManager25activateEditorForDocumentEPNS_9IDocumentE6QFlagsINS0_14OpenEditorFlagEE);  // ", referenced from:
                                                                                                        //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE in disassembleragent.o
                                                                                                        //__ZN10DiffEditor8Internal21DiffEditorServiceImpl9diffFilesERK7QStringS4_ in diffeditorplugin.o
                                                                                                        //__ZN10DiffEditor8Internal21DiffEditorServiceImpl17diffModifiedFilesERK11QStringList in diffeditorplugin.o
                                                                                                        //__ZN10DiffEditor8Internal23DiffEditorPluginPrivate15diffCurrentFileEv in diffeditorplugin.o
                                                                                                        //__ZN10DiffEditor8Internal23DiffEditorPluginPrivate13diffOpenFilesEv in diffeditorplugin.o
                                                                                                        //__ZN10DiffEditor8Internal23DiffEditorPluginPrivate17diffExternalFilesEv in diffeditorplugin.o
unimpl(
    _ZN4Core13EditorManager25goBackInNavigationHistoryEv);  // ", referenced
                                                            // from:
                                                            //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                            // in
                                                            // moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager27cutForwardNavigationHistoryEv);  // ", referenced
                                                              // from:
                                                              //__ZN9CppEditor8Internal16CppOutlineWidget16updateTextCursorERK11QModelIndex
                                                              // in cppoutline.o
                                                              //__ZN8CppTools16CppEditorOutline18gotoSymbolInEditorEv
                                                              // in
                                                              // cppeditoroutline.o
                                                              //__ZN11QmlJSEditor17QmlJSEditorWidget20jumpToOutlineElementEi
                                                              // in
                                                              // qmljseditor.o
                                                              //__ZZN11QmlJSEditor8Internal18QmlJSOutlineWidget16updateTextCursorERK11QModelIndexENK3$_3clES4_
                                                              // in
                                                              // qmljsoutline.o
unimpl(
    _ZN4Core13EditorManager28addSaveAndCloseEditorActionsEP5QMenuPNS_13DocumentModel5EntryEPNS_7IEditorE);  // ", referenced from:
                                                                                                            //__ZNK4Core8Internal10EditorView19fillListContextMenuEP5QMenu in editorview.o
                                                                                                            //__ZN4Core8Internal17OpenEditorsWidget20contextMenuRequestedE6QPoint in openeditorsview.o
                                                                                                            //__ZN4Core13EditorToolBar19fillListContextMenuEP5QMenu in editortoolbar.o
unimpl(
    _ZN4Core13EditorManager28goForwardInNavigationHistoryEv);  // ", referenced
                                                               // from:
                                                               //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                               // in
                                                               // moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager29setWindowTitleAdditionHandlerENSt3__18functionIF7QStringRKS3_EEE);  // ", referenced from:
                                                                                                 //__ZN15ProjectExplorer14SessionManagerC2EP7QObject in session.o
                                                                                                 //__ZN15ProjectExplorer14SessionManagerD2Ev in session.o
unimpl(
    _ZN4Core13EditorManager29setWindowTitleVcsTopicHandlerENSt3__18functionIF7QStringRKS3_EEE);  // ", referenced from:
                                                                                                 //__ZN7VcsBase8Internal13StateListenerC2EP7QObject in vcsbaseplugin.o
unimpl(
    _ZN4Core13EditorManager30addNativeDirAndOpenWithActionsEP5QMenuPNS_13DocumentModel5EntryE);  // ", referenced from:
                                                                                                 //__ZNK4Core8Internal10EditorView19fillListContextMenuEP5QMenu in editorview.o
                                                                                                 //__ZN4Core8Internal17OpenEditorsWidget20contextMenuRequestedE6QPoint in openeditorsview.o
                                                                                                 //__ZN4Core13EditorToolBar19fillListContextMenuEP5QMenu in editortoolbar.o
                                                                                                 //__ZN15ProjectExplorer8Internal22FolderNavigationWidget16contextMenuEventEP17QContextMenuEvent in foldernavigationwidget.o
unimpl(
    _ZN4Core13EditorManager32slotCloseCurrentEditorOrDocumentEv);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN4Core13EditorToolBar11closeEditorEv
                                                                   // in
                                                                   // editortoolbar.o
                                                                   //__ZN4Core13EditorManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                   // in
                                                                   // moc_editormanager.o
unimpl(
    _ZN4Core13EditorManager37addCurrentPositionToNavigationHistoryERK10QByteArray);  // ", referenced from:
                                                                                     //__ZNK10TextEditor8Internal16LineNumberFilter6acceptEN4Core18LocatorFilterEntryEP7QStringPiS6_ in linenumberfilter.o
                                                                                     //__ZN9CppEditor8Internal16CppOutlineWidget16updateTextCursorERK11QModelIndex in cppoutline.o
                                                                                     //__ZN8CppTools16CppEditorOutline18gotoSymbolInEditorEv in cppeditoroutline.o
                                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget20jumpToOutlineElementEi in qmljseditor.o
                                                                                     //__ZZN11QmlJSEditor8Internal18QmlJSOutlineWidget16updateTextCursorERK11QModelIndexENK3$_3clES4_ in qmljsoutline.o
                                                                                     //__ZN7VcsBase19VcsBaseEditorWidget15slotJumpToEntryEi in vcsbaseeditor.o
unimpl(
    _ZN4Core13EditorManager8instanceEv);  // ", referenced from:
                                          //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                          // in debuggerplugin.o
                                          //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate16debugModeEnteredEv
                                          // in debuggertooltipmanager.o
                                          //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate16leavingDebugModeEv
                                          // in debuggertooltipmanager.o
                                          //__ZN4Core8Internal17OpenEditorsWidgetC2Ev
                                          // in openeditorsview.o
                                          //__ZN4Core10DesignModeC2Ev in
                                          // designmode.o
                                          //__ZN4Core13EditorToolBar23setToolbarCreationFlagsENS0_20ToolbarCreationFlagsE
                                          // in editortoolbar.o
                                          //__ZN10TextEditor8Internal30TextEditorActionHandlerPrivateC2EN5Utils2IdES3_j
                                          // in texteditoractionhandler.o
                                          //...
unimpl(
    _ZN4Core13EditorManager9saveStateEv);  // ", referenced from:
                                           //__ZN15ProjectExplorer14SessionManager4saveEv
                                           // in session.o
unimpl(_ZN4Core13EditorManagerD0Ev);  // ", referenced from:
                                      //__ZTVN4Core13EditorManagerE in
                                      // moc_editormanager.o
unimpl(_ZN4Core13EditorManagerD1Ev);  // ", referenced from:
                                      //__ZTVN4Core13EditorManagerE in
                                      // moc_editormanager.o
unimpl(
    _ZN4Core14BaseFileFilter10matchesForER16QFutureInterfaceINS_18LocatorFilterEntryEERK7QString);  // ", referenced from:
                                                                                                    //__ZTVN8CppTools8Internal17CppIncludesFilterE in moc_cppincludesfilter.o
                                                                                                    //__ZTVN15ProjectExplorer8Internal17AllProjectsFilterE in moc_allprojectsfilter.o
                                                                                                    //__ZTVN15ProjectExplorer8Internal20CurrentProjectFilterE in moc_currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN8CppTools8Internal17CppIncludesFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_cppincludesfilter.o
                                                                      //__ZN15ProjectExplorer8Internal17AllProjectsFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_allprojectsfilter.o
                                                                      //__ZN15ProjectExplorer8Internal20CurrentProjectFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter11qt_metacastEPKc);  // ", referenced from:
                                                 //__ZN8CppTools8Internal17CppIncludesFilter11qt_metacastEPKc
                                                 // in moc_cppincludesfilter.o
                                                 //__ZN15ProjectExplorer8Internal17AllProjectsFilter11qt_metacastEPKc
                                                 // in moc_allprojectsfilter.o
                                                 //__ZN15ProjectExplorer8Internal20CurrentProjectFilter11qt_metacastEPKc
                                                 // in
                                                 // moc_currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter12ListIteratorC1ERK5QListIN5Utils8FilePathEE);  // ", referenced from:
                                                                            //__ZN15ProjectExplorer8Internal17AllProjectsFilter13prepareSearchERK7QString
                                                                            // in
                                                                            // allprojectsfilter.o
                                                                            //__ZN15ProjectExplorer8Internal20CurrentProjectFilter13prepareSearchERK7QString
                                                                            // in
                                                                            // currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter12fileIteratorEv);  // ", referenced from:
                                                //__ZN15ProjectExplorer8Internal17AllProjectsFilter13prepareSearchERK7QString
                                                // in allprojectsfilter.o
                                                //__ZN15ProjectExplorer8Internal20CurrentProjectFilter13prepareSearchERK7QString
                                                // in currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter13prepareSearchERK7QString);  // ", referenced from:
                                                          //__ZN8CppTools8Internal17CppIncludesFilter13prepareSearchERK7QString
                                                          // in
                                                          // cppincludesfilter.o
                                                          //__ZN15ProjectExplorer8Internal17AllProjectsFilter13prepareSearchERK7QString
                                                          // in
                                                          // allprojectsfilter.o
                                                          //__ZN15ProjectExplorer8Internal20CurrentProjectFilter13prepareSearchERK7QString
                                                          // in
                                                          // currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter15setFileIteratorEPNS0_8IteratorE);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN8CppTools8Internal17CppIncludesFilter12markOutdatedEv
                                                                 // in
                                                                 // cppincludesfilter.o
                                                                 //__ZN8CppTools8Internal17CppIncludesFilter13prepareSearchERK7QString
                                                                 // in
                                                                 // cppincludesfilter.o
                                                                 //__ZN15ProjectExplorer8Internal17AllProjectsFilter20markFilesAsOutOfDateEv
                                                                 // in
                                                                 // allprojectsfilter.o
                                                                 //__ZN15ProjectExplorer8Internal17AllProjectsFilter13prepareSearchERK7QString
                                                                 // in
                                                                 // allprojectsfilter.o
                                                                 //__ZN15ProjectExplorer8Internal20CurrentProjectFilter20markFilesAsOutOfDateEv
                                                                 // in
                                                                 // currentprojectfilter.o
                                                                 //__ZN15ProjectExplorer8Internal20CurrentProjectFilter13prepareSearchERK7QString
                                                                 // in
                                                                 // currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter16staticMetaObjectE);  // ", referenced from:
                                                   //__ZN8CppTools8Internal17CppIncludesFilter16staticMetaObjectE
                                                   // in moc_cppincludesfilter.o
                                                   //__ZN15ProjectExplorer8Internal17AllProjectsFilter16staticMetaObjectE
                                                   // in moc_allprojectsfilter.o
                                                   //__ZN15ProjectExplorer8Internal20CurrentProjectFilter16staticMetaObjectE
                                                   // in
                                                   // moc_currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilter8IteratorD2Ev);  // ", referenced from:
                                             //__ZN8CppTools8Internal19CppIncludesIteratorC2EN9CPlusPlus8SnapshotERK4QSetI7QStringE
                                             // in cppincludesfilter.o
                                             //__ZN8CppTools8Internal19CppIncludesIteratorD2Ev
                                             // in cppincludesfilter.o
unimpl(
    _ZN4Core14BaseFileFilterC2Ev);  // ", referenced from:
                                    //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                    // in cppincludesfilter.o
                                    //__ZN15ProjectExplorer8Internal17AllProjectsFilterC2Ev
                                    // in allprojectsfilter.o
                                    //__ZN15ProjectExplorer8Internal20CurrentProjectFilterC2Ev
                                    // in currentprojectfilter.o
unimpl(
    _ZN4Core14BaseFileFilterD2Ev);  // ", referenced from:
                                    //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                    // in cppincludesfilter.o
                                    //__ZN15ProjectExplorer8Internal17AllProjectsFilterC2Ev
                                    // in allprojectsfilter.o
                                    //__ZN15ProjectExplorer8Internal20CurrentProjectFilterC2Ev
                                    // in currentprojectfilter.o
                                    //__ZN8CppTools8Internal17CppIncludesFilterD2Ev
                                    // in moc_cppincludesfilter.o
                                    //__ZN15ProjectExplorer8Internal17AllProjectsFilterD2Ev
                                    // in moc_allprojectsfilter.o
                                    //__ZN15ProjectExplorer8Internal20CurrentProjectFilterD2Ev
                                    // in moc_currentprojectfilter.o
unimpl(
    _ZN4Core14ILocatorFilter11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN4Core8Internal13MenuBarFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_menubarfilter.o
                                                                      //__ZN10TextEditor8Internal16LineNumberFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_linenumberfilter.o
                                                                      //__ZN8CppTools8Internal24CppCurrentDocumentFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_cppcurrentdocumentfilter.o
                                                                      //__ZN8CppTools8Internal16CppLocatorFilter11qt_metacallEN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter11qt_metacastEPKc);  // ", referenced from:
                                                 //__ZN4Core8Internal13MenuBarFilter11qt_metacastEPKc
                                                 // in moc_menubarfilter.o
                                                 //__ZN10TextEditor8Internal16LineNumberFilter11qt_metacastEPKc
                                                 // in moc_linenumberfilter.o
                                                 //__ZN8CppTools8Internal24CppCurrentDocumentFilter11qt_metacastEPKc
                                                 // in
                                                 // moc_cppcurrentdocumentfilter.o
                                                 //__ZN8CppTools8Internal16CppLocatorFilter11qt_metacastEPKc
                                                 // in moc_cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter11setPriorityENS0_8PriorityE);  // ", referenced
                                                            // from:
                                                            //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                                            // in
                                                            // linenumberfilter.o
                                                            //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                                            // in
                                                            // cppcurrentdocumentfilter.o
                                                            //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                            // in
                                                            // cppincludesfilter.o
unimpl(
    _ZN4Core14ILocatorFilter12createRegExpERK7QStringN2Qt15CaseSensitivityE);  // ", referenced from:
                                                                               //__ZN8CppTools8Internal24CppCurrentDocumentFilter10matchesForER16QFutureInterfaceIN4Core18LocatorFilterEntryEERK7QString in cppcurrentdocumentfilter.o
                                                                               //__ZN8CppTools8Internal16CppLocatorFilter10matchesForER16QFutureInterfaceIN4Core18LocatorFilterEntryEERK7QString in cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter12restoreStateERK10QByteArray);  // ", referenced
                                                             // from:
                                                             //__ZTVN4Core8Internal13MenuBarFilterE
                                                             // in
                                                             // moc_menubarfilter.o
                                                             //__ZTVN10TextEditor8Internal16LineNumberFilterE
                                                             // in
                                                             // moc_linenumberfilter.o
                                                             //__ZTVN8CppTools16CppClassesFilterE
                                                             // in
                                                             // moc_cppclassesfilter.o
                                                             //__ZTVN8CppTools8Internal24CppCurrentDocumentFilterE
                                                             // in
                                                             // moc_cppcurrentdocumentfilter.o
                                                             //__ZTVN8CppTools8Internal18CppFunctionsFilterE
                                                             // in
                                                             // moc_cppfunctionsfilter.o
                                                             //__ZTVN8CppTools8Internal17CppIncludesFilterE
                                                             // in
                                                             // moc_cppincludesfilter.o
                                                             //__ZTVN8CppTools8Internal16CppLocatorFilterE
                                                             // in
                                                             // moc_cpplocatorfilter.o
                                                             //...
unimpl(
    _ZN4Core14ILocatorFilter13highlightInfoERK23QRegularExpressionMatchNS_18LocatorFilterEntry13HighlightInfo8DataTypeE);  // ", referenced from:
                                                                                                                           //__ZN8CppTools8Internal24CppCurrentDocumentFilter10matchesForER16QFutureInterfaceIN4Core18LocatorFilterEntryEERK7QString in cppcurrentdocumentfilter.o
                                                                                                                           //__ZZN8CppTools8Internal16CppLocatorFilter10matchesForER16QFutureInterfaceIN4Core18LocatorFilterEntryEERK7QStringENK3$_0clERK14QSharedPointerINS_9IndexItemEE in cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter13prepareSearchERK7QString);  // ", referenced from:
                                                          //__ZTVN8CppTools16CppClassesFilterE
                                                          // in
                                                          // moc_cppclassesfilter.o
                                                          //__ZTVN8CppTools8Internal24CppCurrentDocumentFilterE
                                                          // in
                                                          // moc_cppcurrentdocumentfilter.o
                                                          //__ZTVN8CppTools8Internal18CppFunctionsFilterE
                                                          // in
                                                          // moc_cppfunctionsfilter.o
                                                          //__ZTVN8CppTools8Internal16CppLocatorFilterE
                                                          // in
                                                          // moc_cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter14setDisplayNameERK7QString);  // ", referenced
                                                           // from:
                                                           //__ZN4Core8Internal13MenuBarFilterC2Ev
                                                           // in menubarfilter.o
                                                           //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                                           // in
                                                           // linenumberfilter.o
                                                           //__ZN8CppTools16CppClassesFilterC2EPNS_14CppLocatorDataE
                                                           // in
                                                           // cppclassesfilter.o
                                                           //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                                           // in
                                                           // cppcurrentdocumentfilter.o
                                                           //__ZN8CppTools8Internal18CppFunctionsFilterC2EPNS_14CppLocatorDataE
                                                           // in
                                                           // cppfunctionsfilter.o
                                                           //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                           // in
                                                           // cppincludesfilter.o
                                                           //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                                           // in
                                                           // cpplocatorfilter.o
                                                           //...
unimpl(
    _ZN4Core14ILocatorFilter15caseSensitivityERK7QString);  // ", referenced
                                                            // from:
                                                            //__ZN8CppTools8Internal16CppLocatorFilter10matchesForER16QFutureInterfaceIN4Core18LocatorFilterEntryEERK7QString
                                                            // in
                                                            // cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter16openConfigDialogEP7QWidgetRb);  // ", referenced
                                                              // from:
                                                              //__ZTVN4Core8Internal13MenuBarFilterE
                                                              // in
                                                              // moc_menubarfilter.o
                                                              //__ZTVN10TextEditor8Internal16LineNumberFilterE
                                                              // in
                                                              // moc_linenumberfilter.o
                                                              //__ZTVN8CppTools16CppClassesFilterE
                                                              // in
                                                              // moc_cppclassesfilter.o
                                                              //__ZTVN8CppTools8Internal24CppCurrentDocumentFilterE
                                                              // in
                                                              // moc_cppcurrentdocumentfilter.o
                                                              //__ZTVN8CppTools8Internal18CppFunctionsFilterE
                                                              // in
                                                              // moc_cppfunctionsfilter.o
                                                              //__ZTVN8CppTools8Internal17CppIncludesFilterE
                                                              // in
                                                              // moc_cppincludesfilter.o
                                                              //__ZTVN8CppTools8Internal16CppLocatorFilterE
                                                              // in
                                                              // moc_cpplocatorfilter.o
                                                              //...
unimpl(
    _ZN4Core14ILocatorFilter16staticMetaObjectE);  // ", referenced from:
                                                   //__ZN4Core8Internal13MenuBarFilter16staticMetaObjectE
                                                   // in moc_menubarfilter.o
                                                   //__ZN10TextEditor8Internal16LineNumberFilter16staticMetaObjectE
                                                   // in moc_linenumberfilter.o
                                                   //__ZN8CppTools8Internal24CppCurrentDocumentFilter16staticMetaObjectE
                                                   // in
                                                   // moc_cppcurrentdocumentfilter.o
                                                   //__ZN8CppTools8Internal16CppLocatorFilter16staticMetaObjectE
                                                   // in moc_cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilter17setShortcutStringERK7QString);  // ", referenced
                                                              // from:
                                                              //__ZN4Core8Internal13MenuBarFilterC2Ev
                                                              // in
                                                              // menubarfilter.o
                                                              //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                                              // in
                                                              // linenumberfilter.o
                                                              //__ZN8CppTools16CppClassesFilterC2EPNS_14CppLocatorDataE
                                                              // in
                                                              // cppclassesfilter.o
                                                              //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                                              // in
                                                              // cppcurrentdocumentfilter.o
                                                              //__ZN8CppTools8Internal18CppFunctionsFilterC2EPNS_14CppLocatorDataE
                                                              // in
                                                              // cppfunctionsfilter.o
                                                              //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                              // in
                                                              // cppincludesfilter.o
                                                              //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                                              // in
                                                              // cpplocatorfilter.o
                                                              //...
unimpl(
    _ZN4Core14ILocatorFilter20setIncludedByDefaultEb);  // ", referenced from:
                                                        //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                                        // in linenumberfilter.o
                                                        //__ZN8CppTools16CppClassesFilterC2EPNS_14CppLocatorDataE
                                                        // in cppclassesfilter.o
                                                        //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                                        // in
                                                        // cppcurrentdocumentfilter.o
                                                        //__ZN8CppTools8Internal18CppFunctionsFilterC2EPNS_14CppLocatorDataE
                                                        // in
                                                        // cppfunctionsfilter.o
                                                        //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                        // in
                                                        // cppincludesfilter.o
                                                        //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                                        // in cpplocatorfilter.o
                                                        //__ZN15ProjectExplorer8Internal17AllProjectsFilterC2Ev
                                                        // in
                                                        // allprojectsfilter.o
                                                        //...
unimpl(
    _ZN4Core14ILocatorFilter5setIdEN5Utils2IdE);  // ", referenced from:
                                                  //__ZN4Core8Internal13MenuBarFilterC2Ev
                                                  // in menubarfilter.o
                                                  //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                                  // in linenumberfilter.o
                                                  //__ZN8CppTools16CppClassesFilterC2EPNS_14CppLocatorDataE
                                                  // in cppclassesfilter.o
                                                  //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                                  // in
                                                  // cppcurrentdocumentfilter.o
                                                  //__ZN8CppTools8Internal18CppFunctionsFilterC2EPNS_14CppLocatorDataE
                                                  // in cppfunctionsfilter.o
                                                  //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                  // in cppincludesfilter.o
                                                  //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                                  // in cpplocatorfilter.o
                                                  //...
unimpl(
    _ZN4Core14ILocatorFilterC2EP7QObject);  // ", referenced from:
                                            //__ZN4Core8Internal13MenuBarFilterC2Ev
                                            // in menubarfilter.o
                                            //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                            // in linenumberfilter.o
                                            //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                            // in cppcurrentdocumentfilter.o
                                            //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                            // in cpplocatorfilter.o
unimpl(
    _ZN4Core14ILocatorFilterD2Ev);  // ", referenced from:
                                    //__ZN4Core8Internal13MenuBarFilterC2Ev
                                    // in menubarfilter.o
                                    //__ZN10TextEditor8Internal16LineNumberFilterD2Ev
                                    // in texteditorplugin.o
                                    //__ZN10TextEditor8Internal16LineNumberFilterC2EP7QObject
                                    // in linenumberfilter.o
                                    //__ZN8CppTools8Internal24CppCurrentDocumentFilterC2EPNS_15CppModelManagerE
                                    // in cppcurrentdocumentfilter.o
                                    //__ZN8CppTools8Internal16CppLocatorFilterC2EPNS_14CppLocatorDataE
                                    // in cpplocatorfilter.o
                                    //__ZN8CppTools8Internal16CppLocatorFilterD2Ev
                                    // in cpplocatorfilter.o
                                    //__ZN4Core8Internal13MenuBarFilterD2Ev
                                    // in moc_menubarfilter.o
                                    //...
unimpl(
    _ZN4Core14LocatorManager15locatorHasFocusEv);  // ", referenced from:
                                                   //__ZZN4Core8Internal13MenuBarFilterC1EvENK3$_0clEv
                                                   // in menubarfilter.o
unimpl(
    _ZN4Core14LocatorManager24createLocatorInputWidgetEP7QWidget);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN4Core8Internal12EditorWindowC2EP7QWidget
                                                                    // in
                                                                    // editorwindow.o
unimpl(
    _ZN4Core14LocatorManager4showERK7QStringii);  // ", referenced from:
                                                  //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_6clEPNS_16TextEditorWidgetE
                                                  // in
                                                  // texteditoractionhandler.o
unimpl(
    _ZN4Core15DocumentManager11addDocumentEPNS_9IDocumentEb);  // ", referenced
                                                               // from:
                                                               //__ZN15ProjectExplorer15ProjectDocumentC2ERK7QStringRKN5Utils8FilePathEPNS_7ProjectE
                                                               // in project.o
unimpl(
    _ZN4Core15DocumentManager11filePathKeyERK7QStringNS0_11ResolveModeE);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN4Core8Internal20DocumentModelPrivate8addEntryEPNS_13DocumentModel5EntryE
                                                                           // in
                                                                           // documentmodel.o
                                                                           //__ZN4Core8Internal20DocumentModelPrivate11itemChangedEPNS_9IDocumentE
                                                                           // in
                                                                           // documentmodel.o
                                                                           //__ZNK4Core8Internal20DocumentModelPrivate15indexOfFilePathERKN5Utils8FilePathE
                                                                           // in
                                                                           // documentmodel.o
                                                                           //__ZN4Core8Internal20DocumentModelPrivate14removeDocumentEi
                                                                           // in
                                                                           // documentmodel.o
unimpl(
    _ZN4Core15DocumentManager11renamedFileERK7QStringS3_);  // ", referenced
                                                            // from:
                                                            //__ZN15ProjectExplorer8Internal21FolderNavigationModel7setDataERK11QModelIndexRK8QVarianti
                                                            // in
                                                            // foldernavigationwidget.o
unimpl(
    _ZN4Core15DocumentManager16clearRecentFilesEv);  // ", referenced from:
                                                     //__ZN4Core15DocumentManager18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                     // in moc_documentmanager.o
unimpl(
    _ZN4Core15DocumentManager16expectFileChangeERK7QString);  // ", referenced
                                                              // from:
                                                              //__ZN4Core8Internal18ExternalToolRunner3runEv
                                                              // in
                                                              // externaltool.o
unimpl(
    _ZN4Core15DocumentManager17projectsDirectoryEv);  // ", referenced from:
                                                      //__ZNK4Core14IWizardFactory7runPathERK7QString
                                                      // in iwizardfactory.o
                                                      //__ZZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QStringENK3$_6clEv
                                                      // in coreplugin.o
                                                      //__ZN15ProjectExplorer8Internal29FolderNavigationWidgetFactory27updateProjectsDirectoryRootEv
                                                      // in
                                                      // foldernavigationwidget.o
                                                      //__ZN9QtSupport8Internal19ExamplesWelcomePage25copyToAlternativeLocationERK9QFileInfoR11QStringListRKS5_
                                                      // in
                                                      // gettingstartedwelcomepage.o
unimpl(
    _ZN4Core15DocumentManager18unexpectFileChangeERK7QString);  // ", referenced
                                                                // from:
                                                                //__ZN4Core8Internal18ExternalToolRunner8finishedEiN8QProcess10ExitStatusE
                                                                // in
                                                                // externaltool.o
                                                                //__ZN4Core8Internal18ExternalToolRunner5errorEN8QProcess12ProcessErrorE
                                                                // in
                                                                // externaltool.o
unimpl(
    _ZN4Core15DocumentManager20saveModifiedDocumentEPNS_9IDocumentERK7QStringPbS5_S6_P5QListIS2_E);  // ", referenced from:
                                                                                                     //__ZN4Core8Internal18ExternalToolRunner3runEv in externaltool.o
unimpl(
    _ZN4Core15DocumentManager20setProjectsDirectoryERKN5Utils8FilePathE);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer23BaseProjectWizardDialog12slotAcceptedEv
                                                                           // in
                                                                           // baseprojectwizarddialog.o
unimpl(
    _ZN4Core15DocumentManager20useProjectsDirectoryEv);  // ", referenced from:
                                                         //__ZNK4Core14IWizardFactory7runPathERK7QString
                                                         // in iwizardfactory.o
unimpl(
    _ZN4Core15DocumentManager23setUseProjectsDirectoryEb);  // ", referenced
                                                            // from:
                                                            //__ZN15ProjectExplorer23BaseProjectWizardDialog12slotAcceptedEv
                                                            // in
                                                            // baseprojectwizarddialog.o
unimpl(
    _ZN4Core15DocumentManager24saveAllModifiedDocumentsERK7QStringPbS3_S4_P5QListIPNS_9IDocumentEE);  // ", referenced from:
                                                                                                      //__ZN7VcsBase20VcsBasePluginPrivate18promptBeforeCommitEv in vcsbaseplugin.o
unimpl(
    _ZN4Core15DocumentManager26fileDialogInitialDirectoryEv);  // ", referenced
                                                               // from:
                                                               //__ZNK4Core14IWizardFactory7runPathERK7QString
                                                               // in
                                                               // iwizardfactory.o
unimpl(
    _ZN4Core15DocumentManager28getSaveFileNameWithExtensionERK7QStringS3_S3_);  // ", referenced from:
                                                                                //__ZN4Core8Internal22ShortcutSettingsWidget12exportActionEv in shortcutsettings.o
unimpl(
    _ZN4Core15DocumentManager28notifyFilesChangedInternallyERK11QStringList);  // ", referenced from:
                                                                               //__ZN10TextEditor12BaseFileFind9doReplaceERK7QStringRK5QListIN4Core16SearchResultItemEEb in basefilefind.o
unimpl(
    _ZN4Core15DocumentManager29setDefaultLocationForNewFilesERK7QString);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer11ProjectTree14sessionChangedEv
                                                                           // in
                                                                           // projecttree.o
unimpl(
    _ZN4Core15DocumentManager30fileDialogLastVisitedDirectoryEv);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZNK4Core14IWizardFactory7runPathERK7QString
                                                                   // in
                                                                   // iwizardfactory.o
                                                                   //__ZZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QStringENK3$_7clEv
                                                                   // in
                                                                   // coreplugin.o
unimpl(
    _ZN4Core15DocumentManager8instanceEv);  // ", referenced from:
                                            //__ZN4Core10VcsManager21extensionsInitializedEv
                                            // in vcsmanager.o
                                            //__ZN10TextEditor16TextMarkRegistryC2EP7QObject
                                            // in textmark.o
                                            //__ZN8CppTools15CppModelManager12initCppToolsEv
                                            // in cppmodelmanager.o
                                            //__ZN8CppTools15CppModelManagerC2Ev
                                            // in cppmodelmanager.o
                                            //__ZN15ProjectExplorer8Internal29FolderNavigationWidgetFactoryC2Ev
                                            // in foldernavigationwidget.o
unimpl(_ZN4Core15DocumentManagerD0Ev);  // ", referenced from:
                                        //__ZTVN4Core15DocumentManagerE in
                                        // moc_documentmanager.o
unimpl(_ZN4Core15DocumentManagerD1Ev);  // ", referenced from:
                                        //__ZTVN4Core15DocumentManagerE in
                                        // moc_documentmanager.o
unimpl(
    _ZN4Core16BaseTextDocument11qt_metacallEN11QMetaObject4CallEiPPv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN10TextEditor12TextDocument11qt_metacallEN11QMetaObject4CallEiPPv
                                                                        // in
                                                                        // moc_textdocument.o
                                                                        //__ZN10DiffEditor8Internal18DiffEditorDocument11qt_metacallEN11QMetaObject4CallEiPPv
                                                                        // in
                                                                        // moc_diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocument11qt_metacastEPKc);  // ", referenced from:
                                                   //__ZN10TextEditor12TextDocument11qt_metacastEPKc
                                                   // in moc_textdocument.o
                                                   //__ZN10DiffEditor8Internal18DiffEditorDocument11qt_metacastEPKc
                                                   // in
                                                   // moc_diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocument16staticMetaObjectE);  // ", referenced from:
                                                     //__Z12qobject_castIPN4Core16BaseTextDocumentEET_P7QObject
                                                     // in cppeditorwidget.o
                                                     //__Z12qobject_castIPN4Core16BaseTextDocumentEET_P7QObject
                                                     // in vcsbaseeditor.o
                                                     //__ZN10TextEditor12TextDocument16staticMetaObjectE
                                                     // in moc_textdocument.o
                                                     //__ZN10DiffEditor8Internal18DiffEditorDocument16staticMetaObjectE
                                                     // in
                                                     // moc_diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocument4readERK7QStringP11QStringListPS1_);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN10TextEditor12TextDocument8openImplEP7QStringRKS1_S4_b
                                                                    // in
                                                                    // textdocument.o
                                                                    //__ZN10TextEditor12TextDocument8openImplEP7QStringRKS1_S4_b
                                                                    // in
                                                                    // textdocument.o
unimpl(
    _ZN4Core16BaseTextDocument4readERK7QStringPS1_S4_);  // ", referenced from:
                                                         //__ZN10DiffEditor8Internal18DiffEditorDocument4openEP7QStringRKS2_S5_
                                                         // in
                                                         // diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocument8setCodecEPK10QTextCodec);  // ", referenced from:
                                                          //__ZN10TextEditor12TextDocument6reloadEP7QStringP10QTextCodec
                                                          // in textdocument.o
                                                          //__ZN10TextEditor12TextDocument6reloadEP7QStringP10QTextCodec
                                                          // in textdocument.o
                                                          //__ZNK15ProjectExplorer19EditorConfiguration15configureEditorEPN10TextEditor14BaseTextEditorE
                                                          // in
                                                          // editorconfiguration.o
                                                          //__ZN11QmlJSEditor17QmlJSEditorWidget22finalizeInitializationEv
                                                          // in qmljseditor.o
                                                          //__ZN7VcsBase19VcsBaseEditorWidget8setCodecEP10QTextCodec
                                                          // in vcsbaseeditor.o
                                                          //__ZN10DiffEditor8Internal18DiffEditorDocument14selectEncodingEv
                                                          // in
                                                          // diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocumentC2EP7QObject);  // ", referenced from:
                                              //__ZN10TextEditor12TextDocumentC2EN5Utils2IdE
                                              // in textdocument.o
                                              //__ZN10TextEditor12TextDocumentC2EN5Utils2IdE
                                              // in textdocument.o
                                              //__ZN10DiffEditor8Internal18DiffEditorDocumentC2Ev
                                              // in diffeditordocument.o
unimpl(
    _ZN4Core16BaseTextDocumentD2Ev);  // ", referenced from:
                                      //__ZN10TextEditor12TextDocumentC2EN5Utils2IdE
                                      // in textdocument.o
                                      //__ZN10TextEditor12TextDocumentD2Ev in
                                      // textdocument.o
                                      //__ZN10TextEditor12TextDocumentC2EN5Utils2IdE
                                      // in textdocument.o
                                      //__ZN10TextEditor12TextDocumentD2Ev in
                                      // textdocument.o
                                      //__ZN10DiffEditor8Internal18DiffEditorDocumentC2Ev
                                      // in diffeditordocument.o
                                      //__ZN10DiffEditor8Internal18DiffEditorDocumentD2Ev
                                      // in moc_diffeditordocument.o
unimpl(
    _ZN4Core17FileChangeBlockerC1ERK7QString);  // ", referenced from:
                                                //__ZN10TextEditor15RefactoringFile5applyEv
                                                // in refactoringchanges.o
                                                //__ZN15ProjectExplorer8Internal22FolderNavigationWidget17removeCurrentItemEv
                                                // in foldernavigationwidget.o
                                                //__ZN15ProjectExplorer8Internal9FlatModel12dropMimeDataEPK9QMimeDataN2Qt10DropActionEiiRK11QModelIndex
                                                // in projectmodels.o
                                                //__ZN10DiffEditor8Internal26DiffEditorWidgetController5patchEbii
                                                // in
                                                // diffeditorwidgetcontroller.o
unimpl(
    _ZN4Core17FileChangeBlockerD1Ev);  // ", referenced from:
                                       //__ZN10TextEditor15RefactoringFile5applyEv
                                       // in refactoringchanges.o
                                       //__ZN15ProjectExplorer8Internal22FolderNavigationWidget17removeCurrentItemEv
                                       // in foldernavigationwidget.o
                                       //__ZN15ProjectExplorer8Internal9FlatModel12dropMimeDataEPK9QMimeDataN2Qt10DropActionEiiRK11QModelIndex
                                       // in projectmodels.o
                                       //__ZN10DiffEditor8Internal26DiffEditorWidgetController5patchEbii
                                       // in diffeditorwidgetcontroller.o
unimpl(
    _ZN4Core18SearchResultWindow11setTabWidthEi);  // ", referenced from:
                                                   //__ZN10TextEditor8Internal23TextEditorPluginPrivate27updateSearchResultsTabWidthERKNS_11TabSettingsE
                                                   // in texteditorplugin.o
unimpl(
    _ZN4Core18SearchResultWindow14startNewSearchERK7QStringS3_S3_NS0_10SearchModeENS0_16PreserveCaseModeES3_);  // ", referenced from:
                                                                                                                //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE in basefilefind.o
                                                                                                                //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString in cppeditorwidget.o
                                                                                                                //__ZN8CppTools8Internal17CppFindReferences10findUsagesEPN9CPlusPlus6SymbolERKNS2_13LookupContextERK7QStringb in cppfindreferences.o
                                                                                                                //__ZN8CppTools8Internal17CppFindReferences13findMacroUsesERKN9CPlusPlus5MacroERK7QStringb in cppfindreferences.o
                                                                                                                //__ZN8CppTools8Internal17SymbolsFindFilter7findAllERK7QString6QFlagsIN4Core8FindFlagEE in symbolsfindfilter.o
                                                                                                                //__ZN11QmlJSEditor14FindReferences14displayResultsEii in qmljsfindreferences.o
unimpl(
    _ZN4Core18SearchResultWindow17setTextEditorFontERK5QFontRK5QHashINS_17SearchResultColor5StyleES5_E);  // ", referenced from:
                                                                                                          //__ZN10TextEditor8Internal23TextEditorPluginPrivate23updateSearchResultsFontERKNS_12FontSettingsE in texteditorplugin.o
unimpl(
    _ZN4Core18SearchResultWindow8instanceEv);  // ", referenced from:
                                               //__ZN10TextEditor8Internal23TextEditorPluginPrivate23updateSearchResultsFontERKNS_12FontSettingsE
                                               // in texteditorplugin.o
                                               //__ZN10TextEditor8Internal23TextEditorPluginPrivate27updateSearchResultsTabWidthERKNS_11TabSettingsE
                                               // in texteditorplugin.o
                                               //__ZN10TextEditor12BaseFileFind12runNewSearchERK7QString6QFlagsIN4Core8FindFlagEENS5_18SearchResultWindow10SearchModeE
                                               // in basefilefind.o
                                               //__ZN10TextEditor12BaseFileFind9doReplaceERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                               // in basefilefind.o
                                               //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                               // in basefilefind.o
                                               //__ZN9CppEditor8InternalL18findRenameCallbackEPNS0_15CppEditorWidgetERK11QTextCursorRKNSt3__16vectorIN8CppTools5UsageENS6_9allocatorIS9_EEEEbRK7QString
                                               // in cppeditorwidget.o
                                               //__ZN9CppEditor8InternalL22onReplaceUsagesClickedERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                               // in cppeditorwidget.o
                                               //...
unimpl(
    _ZN4Core19ReadOnlyFilesDialog18setShowFailWarningEbRK7QString);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN10TextEditor12BaseFileFind10replaceAllERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                                                     // in
                                                                     // basefilefind.o
                                                                     //__ZN10TextEditor15RefactoringFile5applyEv
                                                                     // in
                                                                     // refactoringchanges.o
unimpl(
    _ZN4Core19ReadOnlyFilesDialog4execEv);  // ", referenced from:
                                            //__ZN10TextEditor12BaseFileFind10replaceAllERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                            // in basefilefind.o
                                            //__ZN10TextEditor15RefactoringFile5applyEv
                                            // in refactoringchanges.o
                                            //__ZTVN4Core19ReadOnlyFilesDialogE
                                            // in moc_readonlyfilesdialog.o
unimpl(
    _ZN4Core19ReadOnlyFilesDialogC1ERK5QListIN5Utils8FilePathEEP7QWidget);  // ", referenced from:
                                                                            //__ZN10TextEditor12BaseFileFind10replaceAllERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                                                            // in
                                                                            // basefilefind.o
unimpl(
    _ZN4Core19ReadOnlyFilesDialogC1ERKN5Utils8FilePathEP7QWidget);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN10TextEditor15RefactoringFile5applyEv
                                                                    // in
                                                                    // refactoringchanges.o
unimpl(_ZN4Core19ReadOnlyFilesDialogD0Ev);  // ", referenced from:
                                            //__ZTVN4Core19ReadOnlyFilesDialogE
                                            // in moc_readonlyfilesdialog.o
unimpl(
    _ZN4Core19ReadOnlyFilesDialogD1Ev);  // ", referenced from:
                                         //__ZN10TextEditor12BaseFileFind10replaceAllERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                         // in basefilefind.o
                                         //__ZN10TextEditor15RefactoringFile5applyEv
                                         // in refactoringchanges.o
                                         //__ZTVN4Core19ReadOnlyFilesDialogE
                                         // in moc_readonlyfilesdialog.o
unimpl(
    _ZN4Core22FindToolBarPlaceHolderC1EP7QWidgetS2_);  // ", referenced from:
                                                       //__ZN8Debugger8Internal9DebugModeC2Ev
                                                       // in debuggerplugin.o
                                                       //__ZN8Debugger8Internal9LogWindowC2EPNS0_14DebuggerEngineE
                                                       // in logwindow.o
                                                       //__ZN8Debugger8Internal15GlobalLogWindowC2Ev
                                                       // in logwindow.o
                                                       //__ZN4Core8Internal10EditorViewC2EPNS0_14SplitterOrViewEP7QWidget
                                                       // in editorview.o
                                                       //__ZN4Core8Internal17OutputPaneManagerC2EP7QWidget
                                                       // in outputpanemanager.o
unimpl(
    _ZN4Core22FindToolBarPlaceHolderD0Ev);  // ", referenced from:
                                            //__ZTVN4Core22FindToolBarPlaceHolderE
                                            // in moc_findplaceholder.o
unimpl(
    _ZN4Core22FindToolBarPlaceHolderD1Ev);  // ", referenced from:
                                            //__ZTVN4Core22FindToolBarPlaceHolderE
                                            // in moc_findplaceholder.o
unimpl(
    _ZN4Core24EditorManagerPlaceHolder9showEventEP10QShowEvent);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZTVN4Core24EditorManagerPlaceHolderE
                                                                  // in
                                                                  // moc_editormanager.o
unimpl(
    _ZN4Core24EditorManagerPlaceHolderC1EP7QWidget);  // ", referenced from:
                                                      //__ZN5Utils25DebuggerMainWindowPrivateC2EPNS_18DebuggerMainWindowE
                                                      // in debuggermainwindow.o
                                                      //__ZN4Core8Internal8EditModeC2Ev
                                                      // in editmode.o
unimpl(
    _ZN4Core24EditorManagerPlaceHolderD0Ev);  // ", referenced from:
                                              //__ZTVN4Core24EditorManagerPlaceHolderE
                                              // in moc_editormanager.o
unimpl(
    _ZN4Core24EditorManagerPlaceHolderD1Ev);  // ", referenced from:
                                              //__ZTVN4Core24EditorManagerPlaceHolderE
                                              // in moc_editormanager.o
unimpl(
    _ZN4Core28HighlightScrollBarController13setScrollAreaEP19QAbstractScrollArea);  // ", referenced from:
                                                                                    //__ZZN10DiffEditor8Internal26SideBySideDiffEditorWidgetC1EP7QWidgetENK3$_1clEv in sidebysidediffeditorwidget.o
unimpl(
    _ZN4Core29textDocumentFlagsForFindFlagsE6QFlagsINS_8FindFlagEE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN10TextEditor8Internal12_GLOBAL__N_114InternalEngine13executeSearchERKNS_18FileFindParametersEPNS_12BaseFileFindE
                                                                      // in
                                                                      // basefilefind.o
                                                                      //__ZN9BinEditor8Internal13BinEditorFind12highlightAllERK7QString6QFlagsIN4Core8FindFlagEE
                                                                      // in
                                                                      // bineditorplugin.o
                                                                      //__ZN9BinEditor8Internal13BinEditorFind15findIncrementalERK7QString6QFlagsIN4Core8FindFlagEE
                                                                      // in
                                                                      // bineditorplugin.o
                                                                      //__ZN9BinEditor8Internal13BinEditorFind8findStepERK7QString6QFlagsIN4Core8FindFlagEE
                                                                      // in
                                                                      // bineditorplugin.o
                                                                      //__ZN9BinEditor8Internal13BinEditorFind4findERK10QByteArrayi6QFlagsIN4Core8FindFlagEEPb
                                                                      // in
                                                                      // bineditorplugin.o
unimpl(
    _ZN4Core4Find10initializeEv);  // ", referenced from:
                                   //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                   // in coreplugin.o
unimpl(
    _ZN4Core4Find14openFindDialogEPNS_11IFindFilterE);  // ", referenced from:
                                                        //__ZN10TextEditor11FindInFiles16findOnFileSystemERK7QString
                                                        // in findinfiles.o
unimpl(
    _ZN4Core4Find15aboutToShutdownEv);  // ", referenced from:
                                        //__ZN4Core8Internal10CorePlugin15aboutToShutdownEv
                                        // in coreplugin.o
unimpl(
    _ZN4Core4Find21extensionsInitializedEv);  // ", referenced from:
                                              //__ZN4Core8Internal10CorePlugin21extensionsInitializedEv
                                              // in coreplugin.o
unimpl(_ZN4Core4Find7destroyEv);  // ", referenced from:
                                  //__ZN4Core8Internal10CorePluginD2Ev in
                                  // coreplugin.o
unimpl(
    _ZN4Core8Internal10MainWindow12saveSettingsEv);  // ", referenced from:
                                                     //__ZN4Core5ICore12saveSettingsENS0_18SaveSettingsReasonE
                                                     // in icore.o
unimpl(
    _ZN4Core8Internal10MainWindow15aboutToShutdownEv);  // ", referenced from:
                                                        //__ZN4Core8Internal10CorePlugin15aboutToShutdownEv
                                                        // in coreplugin.o
unimpl(
    _ZN4Core8Internal10MainWindow16addContextObjectEPNS_8IContextE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN4Core18ModeManagerPrivate10appendModeEPNS_5IModeE
                                                                      // in
                                                                      // modemanager.o
                                                                      //__ZN4Core5ICore16addContextObjectEPNS_8IContextE
                                                                      // in
                                                                      // icore.o
unimpl(
    _ZN4Core8Internal10MainWindow16setOverrideColorERK6QColor);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                                                 // in
                                                                 // coreplugin.o
unimpl(
    _ZN4Core8Internal10MainWindow19addPreCloseListenerERKNSt3__18functionIFbvEEE);  // ", referenced from:
                                                                                    //__ZN4Core5ICore19addPreCloseListenerERKNSt3__18functionIFbvEEE in icore.o
unimpl(
    _ZN4Core8Internal10MainWindow19removeContextObjectEPNS_8IContextE);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN4Core11ModeManager10removeModeEPNS_5IModeE
                                                                         // in
                                                                         // modemanager.o
                                                                         //__ZN4Core5ICore19removeContextObjectEPNS_8IContextE
                                                                         // in
                                                                         // icore.o
unimpl(
    _ZN4Core8Internal10MainWindow21extensionsInitializedEv);  // ", referenced
                                                              // from:
                                                              //__ZN4Core8Internal10CorePlugin21extensionsInitializedEv
                                                              // in coreplugin.o
unimpl(
    _ZN4Core8Internal10MainWindow22appendAboutInformationERK7QString);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN4Core5ICore22appendAboutInformationERK7QString
                                                                        // in
                                                                        // icore.o
unimpl(
    _ZN4Core8Internal10MainWindow24updateAdditionalContextsERKNS_7ContextES4_NS_5ICore15ContextPriorityE);  // ", referenced from:
                                                                                                            //__ZN4Core5ICore24updateAdditionalContextsERKNS_7ContextES3_NS0_15ContextPriorityE in icore.o
                                                                                                            //__ZN4Core5ICore20addAdditionalContextERKNS_7ContextENS0_15ContextPriorityE in icore.o
                                                                                                            //__ZN4Core5ICore23removeAdditionalContextERKNS_7ContextE in icore.o
unimpl(
    _ZN4Core8Internal10MainWindow4initEv);  // ", referenced from:
                                            //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                            // in coreplugin.o
unimpl(_ZN4Core8Internal10MainWindow7restartEv);  // ", referenced from:
                                                  //__ZN4Core5ICore7restartEv in
                                                  // icore.o
unimpl(
    _ZN4Core8Internal10MainWindow9openFilesERK11QStringListNS_5ICore14OpenFilesFlagsERK7QString);  // ", referenced from:
                                                                                                   //__ZN4Core8Internal10CorePlugin13remoteCommandERK11QStringListRK7QStringS4_ in coreplugin.o
                                                                                                   //__ZN4Core5ICore9openFilesERK11QStringListNS0_14OpenFilesFlagsE in icore.o
unimpl(
    _ZN4Core8Internal10MainWindowC1Ev);  // ", referenced from:
                                         //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                         // in coreplugin.o
unimpl(
    _ZN4Core8Internal14AddToVcsDialogC1EP7QWidgetRK7QStringRK11QStringListS6_);  // ", referenced from:
                                                                                 //__ZN4Core10VcsManager11promptToAddERK7QStringRK11QStringList in vcsmanager.o
unimpl(
    _ZN4Core8Internal14AddToVcsDialogD0Ev);  // ", referenced from:
                                             //__ZTVN4Core8Internal14AddToVcsDialogE
                                             // in moc_addtovcsdialog.o
unimpl(
    _ZN4Core8Internal14AddToVcsDialogD1Ev);  // ", referenced from:
                                             //__ZN4Core10VcsManager11promptToAddERK7QStringRK11QStringList
                                             // in vcsmanager.o
                                             //__ZTVN4Core8Internal14AddToVcsDialogE
                                             // in moc_addtovcsdialog.o
unimpl(
    _ZN4Core8Internal16MimeTypeSettings5applyEv);  // ", referenced from:
                                                   //__ZTVN4Core8Internal16MimeTypeSettingsE
                                                   // in moc_mimetypesettings.o
unimpl(
    _ZN4Core8Internal16MimeTypeSettings6finishEv);  // ", referenced from:
                                                    //__ZTVN4Core8Internal16MimeTypeSettingsE
                                                    // in moc_mimetypesettings.o
unimpl(
    _ZN4Core8Internal16MimeTypeSettings6widgetEv);  // ", referenced from:
                                                    //__ZTVN4Core8Internal16MimeTypeSettingsE
                                                    // in moc_mimetypesettings.o
unimpl(
    _ZN4Core8Internal16MimeTypeSettingsD0Ev);  // ", referenced from:
                                               //__ZTVN4Core8Internal16MimeTypeSettingsE
                                               // in moc_mimetypesettings.o
unimpl(
    _ZN4Core8Internal16MimeTypeSettingsD1Ev);  // ", referenced from:
                                               //__ZTVN4Core8Internal16MimeTypeSettingsE
                                               // in moc_mimetypesettings.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate10openEditorEPNS0_10EditorViewERK7QStringN5Utils2IdE6QFlagsINS_13EditorManager14OpenEditorFlagEEPb);  // ", referenced from:
                                                                                                                                                 //__ZN4Core8Internal10EditorView25goBackInNavigationHistoryEv in editorview.o
                                                                                                                                                 //__ZN4Core8Internal10EditorView28goForwardInNavigationHistoryEv in editorview.o
                                                                                                                                                 //__ZN4Core8Internal10EditorView16goToEditLocationERKNS0_12EditLocationE in editorview.o
                                                                                                                                                 //__ZN4Core8Internal14SplitterOrView12restoreStateERK10QByteArray in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate12activateViewEPNS0_10EditorViewE);  // ", referenced from:
                                                                                //__ZN4Core8Internal14SplitterOrView5splitEN2Qt11OrientationEb in editorview.o
                                                                                //__ZN4Core8Internal14SplitterOrView7unsplitEv in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate12openEditorAtEPNS0_10EditorViewERK7QStringiiN5Utils2IdE6QFlagsINS_13EditorManager14OpenEditorFlagEEPb);  // ", referenced from:
                                                                                                                                                     //__ZN4Core8Internal10EditorView16openDroppedFilesERK5QListIN5Utils11DropSupport8FileSpecEE in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate12saveDocumentEPNS_9IDocumentE);  // ", referenced from:
                                                                             //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate13deleteEditorsERK5QListIPNS_7IEditorEE);  // ", referenced from:
                                                                                      //__ZN4Core8Internal14SplitterOrViewD2Ev in editorview.o
                                                                                      //__ZN4Core8Internal14SplitterOrView10unsplitAllEv in editorview.o
                                                                                      //__ZN4Core8Internal14SplitterOrView7unsplitEv in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate13gotoNextSplitEv);  // ", referenced
                                                                // from:
                                                                //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                // in
                                                                // moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate13updateActionsEv);  // ", referenced
                                                                // from:
                                                                //__ZN4Core8Internal10EditorView17splitHorizontallyEv
                                                                // in
                                                                // editorview.o
                                                                //__ZN4Core8Internal10EditorView15splitVerticallyEv
                                                                // in
                                                                // editorview.o
                                                                //__ZN4Core8Internal10EditorView10closeSplitEv
                                                                // in
                                                                // editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate14saveDocumentAsEPNS_9IDocumentE);  // ", referenced from:
                                                                               //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate14setCurrentViewEPNS0_10EditorViewE);  // ", referenced from:
                                                                                  //__ZN4Core8Internal10EditorView12focusInEventEP11QFocusEvent in editorview.o
                                                                                  //__ZN4Core8Internal14SplitterOrView7unsplitEv in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate14splitNewWindowEPNS0_10EditorViewE);  // ", referenced from:
                                                                                  //__ZN4Core8Internal10EditorView14splitNewWindowEv in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate15duplicateEditorEPNS_7IEditorE);  // ", referenced from:
                                                                              //__ZN4Core8Internal14SplitterOrView5splitEN2Qt11OrientationEb in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate15placeholderTextEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN4Core8Internal10EditorViewC2EPNS0_14SplitterOrViewEP7QWidget
                                                                  // in
                                                                  // editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate15removeAllSplitsEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                  // in
                                                                  // moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate16makeFileWritableEPNS_9IDocumentE);  // ", referenced from:
                                                                                 //__ZN4Core13EditorToolBar18makeEditorWritableEv in editortoolbar.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate16setCurrentEditorEPNS_7IEditorEb);  // ", referenced from:
                                                                                //__ZN4Core8Internal14SplitterOrView12restoreStateERK10QByteArray in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate17currentEditorViewEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN4Core8Internal10EditorView10paintEventEP11QPaintEvent
                                                                    // in
                                                                    // editorview.o
                                                                    //__ZN4Core8Internal14SplitterOrView10unsplitAllEv
                                                                    // in
                                                                    // editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate17gotoPreviousSplitEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                    // in
                                                                    // moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate19editorAreaDestroyedEP7QObject);  // ", referenced from:
                                                                              //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate21closeEditorOrDocumentEPNS_7IEditorE);  // ", referenced from:
                                                                                    //__ZN4Core8Internal10EditorView18closeCurrentEditorEv in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate22activateEditorForEntryEPNS0_10EditorViewEPNS_13DocumentModel5EntryE6QFlagsINS_13EditorManager14OpenEditorFlagEE);  // ", referenced from:
                                                                                                                                                                //__ZN4Core8Internal10EditorView22listSelectionActivatedEi in editorview.o
                                                                                                                                                                //__ZN4Core8Internal14SplitterOrView12restoreStateERK10QByteArray in editorview.o
                                                                                                                                                                //__ZN4Core8Internal17OpenEditorsWindow12selectEditorEP15QTreeWidgetItem in openeditorswindow.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate25activateEditorForDocumentEPNS0_10EditorViewEPNS_9IDocumentE6QFlagsINS_13EditorManager14OpenEditorFlagEE);  // ", referenced from:
                                                                                                                                                        //__ZN4Core8Internal10EditorView25goBackInNavigationHistoryEv in editorview.o
                                                                                                                                                        //__ZN4Core8Internal10EditorView28goForwardInNavigationHistoryEv in editorview.o
                                                                                                                                                        //__ZN4Core8Internal10EditorView16goToEditLocationERKNS0_12EditLocationE in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate25handleDocumentStateChangeEv);  // ", referenced from:
                                                                            //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                            // in
                                                                            // moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate28updateWindowTitleForDocumentEPNS_9IDocumentEP7QWidget);  // ", referenced from:
                                                                                                      //__ZN4Core8Internal12EditorWindow17updateWindowTitleEv in editorwindow.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate5splitEN2Qt11OrientationE);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN4Core8Internal20EditorManagerPrivate18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                        // in
                                                                        // moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate8instanceEv);  // ", referenced from:
                                                          //__ZN4Core8Internal10EditorViewC2EPNS0_14SplitterOrViewEP7QWidget
                                                          // in editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate9closeViewEPNS0_10EditorViewE);  // ", referenced from:
                                                                            //__ZN4Core8Internal10EditorView10closeSplitEv
                                                                            // in
                                                                            // editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivate9emptyViewEPNS0_10EditorViewE);  // ", referenced from:
                                                                            //__ZN4Core8Internal14SplitterOrViewD2Ev
                                                                            // in
                                                                            // editorview.o
                                                                            //__ZN4Core8Internal14SplitterOrView17unsplitAll_helperEv
                                                                            // in
                                                                            // editorview.o
                                                                            //__ZN4Core8Internal14SplitterOrView7unsplitEv
                                                                            // in
                                                                            // editorview.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivateD0Ev);  // ", referenced from:
                                                   //__ZTVN4Core8Internal20EditorManagerPrivateE
                                                   // in moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal20EditorManagerPrivateD1Ev);  // ", referenced from:
                                                   //__ZTVN4Core8Internal20EditorManagerPrivateE
                                                   // in moc_editormanager_p.o
unimpl(
    _ZN4Core8Internal21executeSettingsDialogEP7QWidgetN5Utils2IdE);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN4Core5ICore17showOptionsDialogEN5Utils2IdEP7QWidget
                                                                     // in
                                                                     // icore.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate12initInternalEv);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN4Core8Internal22ProgressManagerPrivate4initEv
                                                                 // in
                                                                 // progressmanager.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate21doSetApplicationLabelERK7QString);  // ", referenced from:
                                                                                   //__ZN4Core15ProgressManager19setApplicationLabelERK7QString in progressmanager.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate27setApplicationProgressRangeEii);  // ", referenced from:
                                                                                 //__ZN4Core8Internal22ProgressManagerPrivate25disconnectApplicationTaskEv in progressmanager.o
                                                                                 //__ZN4Core8Internal22ProgressManagerPrivate9doAddTaskERK7QFutureIvERK7QStringN5Utils2IdE6QFlagsINS_15ProgressManager12ProgressFlagEE in progressmanager.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate27setApplicationProgressValueEi);  // ", referenced from:
                                                                                //__ZN4Core8Internal22ProgressManagerPrivate25disconnectApplicationTaskEv in progressmanager.o
                                                                                //__ZN4Core8Internal22ProgressManagerPrivate9doAddTaskERK7QFutureIvERK7QStringN5Utils2IdE6QFlagsINS_15ProgressManager12ProgressFlagEE in progressmanager.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate29setApplicationProgressVisibleEb);  // ", referenced from:
                                                                                  //__ZN4Core8Internal22ProgressManagerPrivate25disconnectApplicationTaskEv in progressmanager.o
                                                                                  //__ZN4Core8Internal22ProgressManagerPrivate9doAddTaskERK7QFutureIvERK7QStringN5Utils2IdE6QFlagsINS_15ProgressManager12ProgressFlagEE in progressmanager.o
unimpl(
    _ZN4Core8Internal22ProgressManagerPrivate7cleanupEv);  // ", referenced
                                                           // from:
                                                           //__ZN4Core8Internal22ProgressManagerPrivateD2Ev
                                                           // in
                                                           // progressmanager.o
unimpl(
    _ZN4Core8Internal6Action12setAttributeENS_7Command16CommandAttributeE);  // ", referenced from:
                                                                             //__ZTVN4Core8Internal6ActionE in moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action14setDescriptionERK7QString);  // ", referenced
                                                           // from:
                                                           //__ZTVN4Core8Internal6ActionE
                                                           // in moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action15removeAttributeENS_7Command16CommandAttributeE);  // ", referenced from:
                                                                                //__ZTVN4Core8Internal6ActionE in moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action15setKeySequencesERK5QListI12QKeySequenceE);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN4Core8Internal6ActionE
                                                                          // in
                                                                          // moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action15setTouchBarIconERK5QIcon);  // ", referenced from:
                                                          //__ZTVN4Core8Internal6ActionE
                                                          // in moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action15setTouchBarTextERK7QString);  // ", referenced
                                                            // from:
                                                            //__ZTVN4Core8Internal6ActionE
                                                            // in
                                                            // moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action17addOverrideActionEP7QActionRKNS_7ContextEb);  // ", referenced from:
                                                                            //__ZN4Core13ActionManager14registerActionEP7QActionN5Utils2IdERKNS_7ContextEb
                                                                            // in
                                                                            // actionmanager.o
unimpl(
    _ZN4Core8Internal6Action17setCurrentContextERKNS_7ContextE);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN4Core8Internal20ActionManagerPrivate17overridableActionEN5Utils2IdE
                                                                  // in
                                                                  // actionmanager.o
                                                                  //__ZN4Core8Internal20ActionManagerPrivate10setContextERKNS_7ContextE
                                                                  // in
                                                                  // actionmanager.o
unimpl(
    _ZN4Core8Internal6Action20removeOverrideActionEP7QAction);  // ", referenced
                                                                // from:
                                                                //__ZN4Core13ActionManager16unregisterActionEP7QActionN5Utils2IdE
                                                                // in
                                                                // actionmanager.o
unimpl(
    _ZN4Core8Internal6Action21setDefaultKeySequenceERK12QKeySequence);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZTVN4Core8Internal6ActionE
                                                                        // in
                                                                        // moc_command_p.o
unimpl(
    _ZN4Core8Internal6Action22setDefaultKeySequencesERK5QListI12QKeySequenceE);  // ", referenced from:
                                                                                 //__ZTVN4Core8Internal6ActionE in moc_command_p.o
unimpl(
    _ZN4Core8Internal6ActionC1EN5Utils2IdE);  // ", referenced from:
                                              //__ZN4Core8Internal20ActionManagerPrivate17overridableActionEN5Utils2IdE
                                              // in actionmanager.o
unimpl(
    _ZN4Core8Internal7Locator10initializeEv);  // ", referenced from:
                                               //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                               // in coreplugin.o
unimpl(
    _ZN4Core8Internal7Locator17delayedInitializeEv);  // ", referenced from:
                                                      //__ZN4Core8Internal10CorePlugin17delayedInitializeEv
                                                      // in coreplugin.o
unimpl(
    _ZN4Core8Internal7Locator21extensionsInitializedEv);  // ", referenced from:
                                                          //__ZN4Core8Internal10CorePlugin21extensionsInitializedEv
                                                          // in coreplugin.o
unimpl(
    _ZN4Core8Internal7LocatorC1Ev);  // ", referenced from:
                                     //__ZN4Core8Internal10CorePlugin10initializeERK11QStringListP7QString
                                     // in coreplugin.o
unimpl(
    _ZN4Core8Internal9NewDialog10showDialogEv);  // ", referenced from:
                                                 //__ZN4Core5ICore17showNewItemDialogERK7QStringRK5QListIPNS_14IWizardFactoryEES3_RK4QMapIS1_8QVariantE
                                                 // in icore.o
unimpl(
    _ZN4Core8Internal9NewDialog13currentDialogEv);  // ", referenced from:
                                                    //__ZN4Core5ICore22isNewItemDialogRunningEv
                                                    // in icore.o
                                                    //__ZN4Core5ICore13newItemDialogEv
                                                    // in icore.o
unimpl(
    _ZN4Core8Internal9NewDialog18setWizardFactoriesE5QListIPNS_14IWizardFactoryEERK7QStringRK4QMapIS6_8QVariantE);  // ", referenced from:
                                                                                                                    //__ZN4Core5ICore17showNewItemDialogERK7QStringRK5QListIPNS_14IWizardFactoryEES3_RK4QMapIS1_8QVariantE in icore.o
unimpl(
    _ZN4Core8Internal9NewDialog5eventEP6QEvent);  // ", referenced from:
                                                  //__ZTVN4Core8Internal9NewDialogE
                                                  // in moc_newdialog.o
unimpl(_ZN4Core8Internal9NewDialog6acceptEv);  // ", referenced from:
                                               //__ZTVN4Core8Internal9NewDialogE
                                               // in moc_newdialog.o
unimpl(_ZN4Core8Internal9NewDialog6rejectEv);  // ", referenced from:
                                               //__ZTVN4Core8Internal9NewDialogE
                                               // in moc_newdialog.o
unimpl(
    _ZN4Core8Internal9NewDialogC1EP7QWidget);  // ", referenced from:
                                               //__ZN4Core5ICore17showNewItemDialogERK7QStringRK5QListIPNS_14IWizardFactoryEES3_RK4QMapIS1_8QVariantE
                                               // in icore.o
unimpl(_ZN4Core8Internal9NewDialogD0Ev);       // ", referenced from:
                                          //__ZTVN4Core8Internal9NewDialogE in
                                          // moc_newdialog.o
unimpl(_ZN4Core8Internal9NewDialogD1Ev);  // ", referenced from:
                                          //__ZTVN4Core8Internal9NewDialogE in
                                          // moc_newdialog.o
unimpl(
    _ZN4Core9FileUtils10removeFileERK7QStringb);  // ", referenced from:
                                                  //__ZN15ProjectExplorer8Internal22FolderNavigationWidget17removeCurrentItemEv
                                                  // in foldernavigationwidget.o
unimpl(
    _ZN4Core9FileUtils12openTerminalERK7QString);  // ", referenced from:
                                                   //__ZZN4Core8Internal10CorePlugin27addToPathChooserContextMenuEPN5Utils11PathChooserEP5QMenuENK4$_21clEv
                                                   // in coreplugin.o
unimpl(
    _ZN4Core9FileUtils12openTerminalERK7QStringRKN5Utils11EnvironmentE);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZZN15ProjectExplorer20BuildDirectoryAspectC1EPKNS_18BuildConfigurationEENK3$_0clEv
                                                                          // in
                                                                          // buildaspects.o
                                                                          //__ZZN15ProjectExplorer17EnvironmentWidgetC1EP7QWidgetNS0_4TypeES2_ENK3$_2clEv
                                                                          // in
                                                                          // environmentwidget.o
                                                                          //__ZZN15ProjectExplorer13DesktopDeviceC1EvENK3$_0clERKN5Utils11EnvironmentERK7QString
                                                                          // in
                                                                          // desktopdevice.o
unimpl(
    _ZN4Core9FileUtils20showInGraphicalShellEP7QWidgetRK7QString);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZZN4Core8Internal10CorePlugin27addToPathChooserContextMenuEPN5Utils11PathChooserEP5QMenuENK4$_20clEv
                                                                    // in
                                                                    // coreplugin.o
unimpl(
    _ZN4Core9FileUtils21msgTerminalHereActionEv);  // ", referenced from:
                                                   //__ZN4Core8Internal10CorePlugin27addToPathChooserContextMenuEPN5Utils11PathChooserEP5QMenu
                                                   // in coreplugin.o
unimpl(
    _ZN4Core9FileUtils23msgGraphicalShellActionEv);  // ", referenced from:
                                                     //__ZN4Core8Internal10CorePlugin27addToPathChooserContextMenuEPN5Utils11PathChooserEP5QMenu
                                                     // in coreplugin.o
unimpl(
    _ZN4QSsh20SshKeyCreationDialogD0Ev);  // ", referenced from:
                                          //__ZTVN4QSsh20SshKeyCreationDialogE
                                          // in moc_sshkeycreationdialog.o
unimpl(
    _ZN4QSsh20SshKeyCreationDialogD1Ev);  // ", referenced from:
                                          //__ZTVN4QSsh20SshKeyCreationDialogE
                                          // in moc_sshkeycreationdialog.o
unimpl(_ZN7ProFileD1Ev);                  // ", referenced from:
                          //__ZN7ProFile5derefEv in profilereader.o
unimpl(_ZN7VcsBase11CleanDialog6acceptEv);  // ", referenced from:
                                            //__ZTVN7VcsBase11CleanDialogE in
                                            // moc_cleandialog.o
unimpl(_ZN7VcsBase11CleanDialogD0Ev);       // ", referenced from:
                                            //__ZTVN7VcsBase11CleanDialogE in
                                            // moc_cleandialog.o
unimpl(_ZN7VcsBase11CleanDialogD1Ev);       // ", referenced from:
                                            //__ZTVN7VcsBase11CleanDialogE in
                                            // moc_cleandialog.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget11setLineWrapEb);  // ", referenced from:
                                                      //__ZN7VcsBase19VcsBaseSubmitEditor11setLineWrapEb
                                                      // in
                                                      // vcsbasesubmiteditor.o
                                                      //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                      // in
                                                      // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget12setFileModelEPNS_15SubmitFileModelE);  // ", referenced from:
                                                                            //__ZN7VcsBase19VcsBaseSubmitEditor12setFileModelEPNS_15SubmitFileModelE
                                                                            // in
                                                                            // vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget15registerActionsEP7QActionS2_S2_S2_);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN7VcsBase19VcsBaseSubmitEditor15registerActionsEP7QActionS2_S2_S2_
                                                                           // in
                                                                           // vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget15setSelectedRowsERK5QListIiE);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN7VcsBase19VcsBaseSubmitEditor12setFileModelEPNS_15SubmitFileModelE
                                                                    // in
                                                                    // vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget16setLineWrapWidthEi);  // ", referenced
                                                           // from:
                                                           //__ZN7VcsBase19VcsBaseSubmitEditor16setLineWrapWidthEi
                                                           // in
                                                           // vcsbasesubmiteditor.o
                                                           //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                           // in
                                                           // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget18setDescriptionTextERK7QString);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN7VcsBase19VcsBaseSubmitEditor14setDescriptionERK7QString
                                                                      // in
                                                                      // vcsbasesubmiteditor.o
                                                                      //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                      // in
                                                                      // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget18updateSubmitActionEv);  // ", referenced
                                                             // from:
                                                             //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                             // in
                                                             // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget20addSubmitFieldWidgetEPNS_17SubmitFieldWidgetE);  // ", referenced from:
                                                                                      //__ZN7VcsBase19VcsBaseSubmitEditor16createUserFieldsERK7QString in vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget22descriptionTextChangedEv);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                 // in
                                                                 // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget23setDescriptionMandatoryEb);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN7VcsBase19VcsBaseSubmitEditor23setDescriptionMandatoryEb
                                                                  // in
                                                                  // vcsbasesubmiteditor.o
                                                                  //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                  // in
                                                                  // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget23setEmptyFileListEnabledEb);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN7VcsBase19VcsBaseSubmitEditor23setEmptyFileListEnabledEb
                                                                  // in
                                                                  // vcsbasesubmiteditor.o
                                                                  //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                  // in
                                                                  // moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget24setFileListSelectionModeEN17QAbstractItemView13SelectionModeE);  // ", referenced from:
                                                                                                      //__ZN7VcsBase19VcsBaseSubmitEditor24setFileListSelectionModeEN17QAbstractItemView13SelectionModeE in vcsbasesubmiteditor.o
                                                                                                      //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidget35addDescriptionEditContextMenuActionEP7QAction);  // ", referenced from:
                                                                                      //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE in vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidgetD0Ev);  // ", referenced from:
                                           //__ZTVN7VcsBase18SubmitEditorWidgetE
                                           // in moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase18SubmitEditorWidgetD1Ev);  // ", referenced from:
                                           //__ZTVN7VcsBase18SubmitEditorWidgetE
                                           // in moc_submiteditorwidget.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialog11createModelEP7QObject);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN7VcsBase8Internal9VcsPlugin13nickNameModelEv
                                                                   // in
                                                                   // vcsplugin.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialog12nickNameListEPK18QStandardItemModel);  // ", referenced from:
                                                                                 //__ZN7VcsBase19VcsBaseSubmitEditor16createUserFieldsERK7QString in vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialog28populateModelFromMailCapFileERK7QStringP18QStandardItemModelPS2_);  // ", referenced from:
                                                                                                              //__ZN7VcsBase8Internal9VcsPlugin21populateNickNameModelEv in vcsplugin.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialogC1EP18QStandardItemModelP7QWidget);  // ", referenced from:
                                                                             //__ZN7VcsBase19VcsBaseSubmitEditor17promptForNickNameEv in vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialogD0Ev);  // ", referenced from:
                                                //__ZTVN7VcsBase8Internal14NickNameDialogE
                                                // in moc_nicknamedialog.o
unimpl(
    _ZN7VcsBase8Internal14NickNameDialogD1Ev);  // ", referenced from:
                                                //__ZTVN7VcsBase8Internal14NickNameDialogE
                                                // in moc_nicknamedialog.o
unimpl(
    _ZN7VcsBase8Internal17CommonOptionsPage5applyEv);  // ", referenced from:
                                                       //__ZTVN7VcsBase8Internal17CommonOptionsPageE
                                                       // in
                                                       // moc_commonsettingspage.o
unimpl(
    _ZN7VcsBase8Internal17CommonOptionsPage6finishEv);  // ", referenced from:
                                                        //__ZTVN7VcsBase8Internal17CommonOptionsPageE
                                                        // in
                                                        // moc_commonsettingspage.o
unimpl(
    _ZN7VcsBase8Internal17CommonOptionsPage6widgetEv);  // ", referenced from:
                                                        //__ZTVN7VcsBase8Internal17CommonOptionsPageE
                                                        // in
                                                        // moc_commonsettingspage.o
unimpl(
    _ZN7VcsBase8Internal17CommonOptionsPageC1Ev);  // ", referenced from:
                                                   //__ZN7VcsBase8Internal16VcsPluginPrivateC2Ev
                                                   // in vcsplugin.o
unimpl(
    _ZN7VcsBase8Internal20CommonSettingsWidgetD0Ev);  // ", referenced from:
                                                      //__ZTVN7VcsBase8Internal20CommonSettingsWidgetE
                                                      // in
                                                      // moc_commonsettingspage.o
unimpl(
    _ZN7VcsBase8Internal20CommonSettingsWidgetD1Ev);  // ", referenced from:
                                                      //__ZTVN7VcsBase8Internal20CommonSettingsWidgetE
                                                      // in
                                                      // moc_commonsettingspage.o
unimpl(
    _ZN8CppTools19SemanticHighlighter21setHighlightingRunnerENSt3__18functionIF7QFutureIN10TextEditor18HighlightingResultEEvEEE);  // ", referenced from:
                                                                                                                                   //__ZN8CppTools30BuiltinEditorDocumentProcessorC2EPN10TextEditor12TextDocumentEb in builtineditordocumentprocessor.o
unimpl(
    _ZN8CppTools19SemanticHighlighter31updateFormatMapFromFontSettingsEv);  // ", referenced from:
                                                                            //__ZN8CppTools30BuiltinEditorDocumentProcessor19semanticRehighlightEv
                                                                            // in
                                                                            // builtineditordocumentprocessor.o
unimpl(
    _ZN8CppTools19SemanticHighlighter3runEv);  // ", referenced from:
                                               //__ZN8CppTools30BuiltinEditorDocumentProcessor21onSemanticInfoUpdatedENS_12SemanticInfoE
                                               // in
                                               // builtineditordocumentprocessor.o
                                               //__ZN8CppTools30BuiltinEditorDocumentProcessor19semanticRehighlightEv
                                               // in
                                               // builtineditordocumentprocessor.o
unimpl(
    _ZN8CppTools19SemanticHighlighterC1EPN10TextEditor12TextDocumentE);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN8CppTools30BuiltinEditorDocumentProcessorC2EPN10TextEditor12TextDocumentEb
                                                                         // in
                                                                         // builtineditordocumentprocessor.o
unimpl(
    _ZN8CppTools19SemanticHighlighterD0Ev);  // ", referenced from:
                                             //__ZTVN8CppTools19SemanticHighlighterE
                                             // in moc_semantichighlighter.o
unimpl(
    _ZN8CppTools19SemanticHighlighterD1Ev);  // ", referenced from:
                                             //__ZTVN8CppTools19SemanticHighlighterE
                                             // in moc_semantichighlighter.o
unimpl(
    _ZN8CppTools28ClangDiagnosticConfigsWidget4syncEv);  // ", referenced from:
                                                         //__ZN8CppTools37ClangDiagnosticConfigsSelectionWidget15onButtonClickedEv
                                                         // in
                                                         // clangdiagnosticconfigsselectionwidget.o
unimpl(
    _ZN8CppTools28ClangDiagnosticConfigsWidgetD0Ev);  // ", referenced from:
                                                      //__ZTVN8CppTools28ClangDiagnosticConfigsWidgetE
                                                      // in
                                                      // moc_clangdiagnosticconfigswidget.o
unimpl(
    _ZN8CppTools28ClangDiagnosticConfigsWidgetD1Ev);  // ", referenced from:
                                                      //__ZTVN8CppTools28ClangDiagnosticConfigsWidgetE
                                                      // in
                                                      // moc_clangdiagnosticconfigswidget.o
unimpl(
    _ZN8CppTools8Internal15CppFileSettings12fromSettingsEP9QSettings);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN8CppTools8Internal17CppFindReferences22onReplaceButtonClickedERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                                                        // in
                                                                        // cppfindreferences.o
                                                                        //__ZNK8CppTools8Internal19CppToolsJsExtension15classToFileNameERK7QStringS4_
                                                                        // in
                                                                        // cpptoolsjsextension.o
                                                                        //__ZN8CppTools8Internal14CppToolsPlugin21extensionsInitializedEv
                                                                        // in
                                                                        // cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal15CppFileSettings15licenseTemplateEv);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN8CppTools21AbstractEditorSupport15licenseTemplateERK7QStringS3_
                                                                 // in
                                                                 // abstracteditorsupport.o
                                                                 //__ZN8CppTools8Internal14CppToolsPlugin15licenseTemplateEv
                                                                 // in
                                                                 // cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal15CppFileSettings21applySuffixesToMimeDBEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN8CppTools8Internal14CppToolsPlugin21extensionsInitializedEv
                                                                       // in
                                                                       // cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal19CppFileSettingsPageC1EPNS0_15CppFileSettingsE);  // ", referenced from:
                                                                            //__ZN8CppTools8Internal21CppToolsPluginPrivateC2Ev
                                                                            // in
                                                                            // cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal24CppCodeModelSettingsPageC1EPNS_20CppCodeModelSettingsE);  // ", referenced from:
                                                                                     //__ZN8CppTools8Internal21CppToolsPluginPrivateC2Ev in cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal24CppCodeStyleSettingsPageC1Ev);  // ", referenced
                                                           // from:
                                                           //__ZN8CppTools8Internal21CppToolsPluginPrivateC2Ev
                                                           // in
                                                           // cpptoolsplugin.o
unimpl(
    _ZN8CppTools8Internal29CppCodeStylePreferencesWidget12setCodeStyleEPNS_23CppCodeStylePreferencesE);  // ", referenced from:
                                                                                                         //__ZNK8CppTools30CppCodeStylePreferencesFactory12createEditorEPN10TextEditor21ICodeStylePreferencesEP7QWidget in cppcodestylepreferencesfactory.o
unimpl(
    _ZN8CppTools8Internal29CppCodeStylePreferencesWidgetC1EP7QWidget);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZNK8CppTools30CppCodeStylePreferencesFactory12createEditorEPN10TextEditor21ICodeStylePreferencesEP7QWidget
                                                                        // in
                                                                        // cppcodestylepreferencesfactory.o
unimpl(
    _ZN8CppTools8Internal29CppCodeStylePreferencesWidgetD0Ev);  // ", referenced
                                                                // from:
                                                                //__ZTVN8CppTools8Internal29CppCodeStylePreferencesWidgetE
                                                                // in
                                                                // moc_cppcodestylesettingspage.o
unimpl(
    _ZN8CppTools8Internal29CppCodeStylePreferencesWidgetD1Ev);  // ", referenced
                                                                // from:
                                                                //__ZTVN8CppTools8Internal29CppCodeStylePreferencesWidgetE
                                                                // in
                                                                // moc_cppcodestylesettingspage.o
unimpl(
    _ZN8Debugger8Internal15createGdbEngineEv);  // ", referenced from:
                                                //__ZN8Debugger15DebuggerRunTool5startEv
                                                // in debuggerruncontrol.o
unimpl(
    _ZN8Debugger8Internal15createPdbEngineEv);  // ", referenced from:
                                                //__ZN8Debugger15DebuggerRunToolC2EPN15ProjectExplorer10RunControlENS0_13AllowTerminalE
                                                // in debuggerruncontrol.o
unimpl(
    _ZN8Debugger8Internal15createQmlEngineEv);  // ", referenced from:
                                                //__ZN8Debugger15DebuggerRunTool5startEv
                                                // in debuggerruncontrol.o
unimpl(
    _ZN8Debugger8Internal16createUvscEngineEv);  // ", referenced from:
                                                 //__ZN8Debugger15DebuggerRunTool5startEv
                                                 // in debuggerruncontrol.o
unimpl(
    _ZN8Debugger8Internal17SymbolPathsDialog20useCommonSymbolPathsERbS2_R7QString);  // ", referenced from:
                                                                                     //__ZN8Debugger8Internal23CdbSymbolPathListEditor16setupSymbolPathsEv in cdbsymbolpathlisteditor.o
unimpl(
    _ZN8Debugger8Internal17SymbolPathsDialogD0Ev);  // ", referenced from:
                                                    //__ZTVN8Debugger8Internal17SymbolPathsDialogE
                                                    // in
                                                    // moc_symbolpathsdialog.o
unimpl(
    _ZN8Debugger8Internal17SymbolPathsDialogD1Ev);  // ", referenced from:
                                                    //__ZTVN8Debugger8Internal17SymbolPathsDialogE
                                                    // in
                                                    // moc_symbolpathsdialog.o
unimpl(
    _ZN8Debugger8Internal17addCdbOptionPagesEP5QListIPN4Core12IOptionsPageEE);  // ", referenced from:
                                                                                //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList in debuggerplugin.o
unimpl(
    _ZN8Debugger8Internal17addGdbOptionPagesEP5QListIPN4Core12IOptionsPageEE);  // ", referenced from:
                                                                                //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList in debuggerplugin.o
unimpl(
    _ZN8Debugger8Internal7Console9printItemENS0_11ConsoleItem8ItemTypeERK7QString);  // ", referenced from:
                                                                                     //__ZN8Debugger15DebuggerRunTool11showMessageERK7QStringii in debuggerruncontrol.o
falseimpl(
    _ZN8Debugger8Internal7ConsoleC1Ev);  // ", referenced from:
                                         //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                         // in debuggerplugin.o
falseimpl(
    _ZN8Debugger8Internal7ConsoleD1Ev);  // ", referenced from:
                                         //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                         // in debuggerplugin.o
                                         //__ZN8Debugger8Internal21DebuggerPluginPrivateD2Ev
                                         // in debuggerplugin.o
unimpl(
    _ZN8Debugger8Internal8CoreInfo26readExecutableNameFromCoreERKN15ProjectExplorer8RunnableERK7QString);  // ", referenced from:
                                                                                                           //__ZN8Debugger8Internal16AttachCoreDialog15coreFileChangedERK7QString in loadcoredialog.o
unimpl(
    _ZN8Debugger8Internal9CdbEngine20extensionLibraryNameEb);  // ", referenced
                                                               // from:
                                                               //__ZN8Debugger8InternalL13cdbRemoteHelpEv
                                                               // in
                                                               // debuggerdialogs.o
unimpl(
    _ZN9CppEditor8Internal21CppPreProcessorDialog4execEv);  // ", referenced
                                                            // from:
                                                            //__ZN9CppEditor8Internal15CppEditorWidget22showPreProcessorWidgetEv
                                                            // in
                                                            // cppeditorwidget.o
                                                            //__ZTVN9CppEditor8Internal21CppPreProcessorDialogE
                                                            // in
                                                            // moc_cpppreprocessordialog.o
unimpl(
    _ZN9CppEditor8Internal21CppPreProcessorDialogC1ERK7QStringP7QWidget);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN9CppEditor8Internal15CppEditorWidget22showPreProcessorWidgetEv
                                                                           // in
                                                                           // cppeditorwidget.o
unimpl(
    _ZN9CppEditor8Internal21CppPreProcessorDialogD0Ev);  // ", referenced from:
                                                         //__ZTVN9CppEditor8Internal21CppPreProcessorDialogE
                                                         // in
                                                         // moc_cpppreprocessordialog.o
unimpl(
    _ZN9CppEditor8Internal21CppPreProcessorDialogD1Ev);  // ", referenced from:
                                                         //__ZN9CppEditor8Internal15CppEditorWidget22showPreProcessorWidgetEv
                                                         // in cppeditorwidget.o
                                                         //__ZTVN9CppEditor8Internal21CppPreProcessorDialogE
                                                         // in
                                                         // moc_cpppreprocessordialog.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidget12loadSettingsEPNS_19CppQuickFixSettingsE);  // ", referenced from:
                                                                                                  //__ZN9CppEditor8Internal23CppQuickFixSettingsPage6widgetEv in cppquickfixsettingspage.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidget12saveSettingsEPNS_19CppQuickFixSettingsE);  // ", referenced from:
                                                                                                  //__ZN9CppEditor8Internal23CppQuickFixSettingsPage5applyEv in cppquickfixsettingspage.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidget24currentCustomItemChangedEP15QListWidgetItemS3_);  // ", referenced from:
                                                                                                         //__ZN9CppEditor8Internal25CppQuickFixSettingsWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_cppquickfixsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidgetC1EP7QWidget);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN9CppEditor8Internal23CppQuickFixSettingsPage6widgetEv
                                                                     // in
                                                                     // cppquickfixsettingspage.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidgetD0Ev);  // ", referenced
                                                             // from:
                                                             //__ZTVN9CppEditor8Internal25CppQuickFixSettingsWidgetE
                                                             // in
                                                             // moc_cppquickfixsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal25CppQuickFixSettingsWidgetD1Ev);  // ", referenced
                                                             // from:
                                                             //__ZTVN9CppEditor8Internal25CppQuickFixSettingsWidgetE
                                                             // in
                                                             // moc_cppquickfixsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal27CppCodeModelInspectorDialog5eventEP6QEvent);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN9CppEditor8Internal27CppCodeModelInspectorDialogE
                                                                          // in
                                                                          // moc_cppcodemodelinspectordialog.o
unimpl(
    _ZN9CppEditor8Internal27CppCodeModelInspectorDialogC1EP7QWidget);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN9CppEditor8Internal22CppEditorPluginPrivate19inspectCppCodeModelEv
                                                                       // in
                                                                       // cppeditorplugin.o
unimpl(
    _ZN9CppEditor8Internal27CppCodeModelInspectorDialogD0Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN9CppEditor8Internal27CppCodeModelInspectorDialogE
                                                               // in
                                                               // moc_cppcodemodelinspectordialog.o
unimpl(
    _ZN9CppEditor8Internal27CppCodeModelInspectorDialogD1Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN9CppEditor8Internal27CppCodeModelInspectorDialogE
                                                               // in
                                                               // moc_cppcodemodelinspectordialog.o
unimpl(
    _ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidget18currentItemChangedEv);  // ", referenced from:
                                                                                      //__ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidget19buttonCustomClickedEv);  // ", referenced from:
                                                                                       //__ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetC1EPN15ProjectExplorer7ProjectEP7QWidget);  // ", referenced from:
                                                                                                        //__ZZN9CppEditor8Internal15CppEditorPlugin10initializeERK11QStringListP7QStringENK3$_0clEPN15ProjectExplorer7ProjectE in cppeditorplugin.o
unimpl(
    _ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetD0Ev);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetE
                                                                    // in
                                                                    // moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetD1Ev);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetE
                                                                    // in
                                                                    // moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZN9QtSupport13BaseQtVersion19createMacroExpanderERKNSt3__18functionIFPKS0_vEEE);  // ", referenced from:
                                                                                       //__ZN9QtSupport18QtMacroSubProviderC2EPN15ProjectExplorer3KitE in qtkitinformation.o
unimpl(
    _ZN9QtSupport13BaseQtVersion23isQmlDebuggingSupportedEPKN15ProjectExplorer3KitEP7QString);  // ", referenced from:
                                                                                                //__ZZN9QtSupport18QmlDebuggingAspect11addToLayoutERN5Utils13LayoutBuilderEENK3$_0clEv in qtbuildaspects.o
unimpl(
    _ZN9QtSupport13BaseQtVersion26isQtQuickCompilerSupportedEPKN15ProjectExplorer3KitEP7QString);  // ", referenced from:
                                                                                                   //__ZZN9QtSupport21QtQuickCompilerAspect11addToLayoutERN5Utils13LayoutBuilderEENK3$_1clEv in qtbuildaspects.o
unimpl(
    _ZN9QtSupport15QtVersionNumberC1Eiii);  // ", referenced from:
                                            //__ZN9QtSupport10CppKitInfoC2EPN15ProjectExplorer3KitE
                                            // in qtcppkitinfo.o
unimpl(
    _ZN9QtSupport16QtVersionFactory10canRestoreERK7QString);  // ", referenced
                                                              // from:
                                                              //__ZN9QtSupportL17restoreQtVersionsEv
                                                              // in
                                                              // qtversionmanager.o
                                                              //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                              // in
                                                              // qtversionmanager.o
unimpl(
    _ZN9QtSupport16QtVersionFactory21allQtVersionFactoriesEv);  // ", referenced
                                                                // from:
                                                                //__ZN9QtSupportL17restoreQtVersionsEv
                                                                // in
                                                                // qtversionmanager.o
                                                                //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                                // in
                                                                // qtversionmanager.o
unimpl(
    _ZN9QtSupport16QtVersionFactory28createQtVersionFromQMakePathERKN5Utils8FilePathEbRK7QStringPS5_);  // ", referenced from:
                                                                                                        //__ZNK9QtSupport17QtProjectImporter21findOrCreateQtVersionERKN5Utils8FilePathE in qtprojectimporter.o
                                                                                                        //__ZN9QtSupportL12findSystemQtEv in qtversionmanager.o
unimpl(
    _ZN9QtSupport16QtVersionFactory7restoreERK7QStringRK4QMapIS1_8QVariantE);  // ", referenced from:
                                                                               //__ZN9QtSupportL17restoreQtVersionsEv in qtversionmanager.o
                                                                               //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb in qtversionmanager.o
unimpl(
    _ZN9QtSupport16QtVersionFactoryD2Ev);  // ", referenced from:
                                           //__ZN9QtSupport8Internal29EmbeddedLinuxQtVersionFactoryD2Ev
                                           // in qtsupportplugin.o
                                           //__ZN9QtSupport8Internal23DesktopQtVersionFactoryD2Ev
                                           // in qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal13QtOptionsPage10linkWithQtEv);  // ", referenced
                                                           // from:
                                                           //__ZZN9QtSupport8InternalL22askAboutQtInstallationEvENK3$_4clEv
                                                           // in
                                                           // qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal13QtOptionsPage13canLinkWithQtEv);  // ", referenced
                                                              // from:
                                                              //__ZN9QtSupport8InternalL22askAboutQtInstallationEv
                                                              // in
                                                              // qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal13QtOptionsPage14isLinkedWithQtEv);  // ", referenced
                                                               // from:
                                                               //__ZN9QtSupport8InternalL22askAboutQtInstallationEv
                                                               // in
                                                               // qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal13QtOptionsPageC1Ev);  // ", referenced from:
                                                 //__ZN9QtSupport8Internal22QtSupportPluginPrivateC2Ev
                                                 // in qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal15ExampleSetModel16selectExampleSetEi);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN9QtSupport8Internal18ExamplesPageWidgetC2Eb
                                                                   // in
                                                                   // gettingstartedwelcomepage.o
unimpl(
    _ZN9QtSupport8Internal17ExamplesListModelC1EP7QObject);  // ", referenced
                                                             // from:
                                                             //__ZN9QtSupport8Internal18ExamplesPageWidgetC2Eb
                                                             // in
                                                             // gettingstartedwelcomepage.o
unimpl(
    _ZN9QtSupport8Internal19CodeGenSettingsPageC1Ev);  // ", referenced from:
                                                       //__ZN9QtSupport8Internal22QtSupportPluginPrivateC2Ev
                                                       // in qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal23DesktopQtVersionFactoryC1Ev);  // ", referenced
                                                           // from:
                                                           //__ZN9QtSupport8Internal22QtSupportPluginPrivateC2Ev
                                                           // in
                                                           // qtsupportplugin.o
unimpl(
    _ZN9QtSupport8Internal23ExamplesListModelFilterC1EPNS0_17ExamplesListModelEbP7QObject);  // ", referenced from:
                                                                                             //__ZN9QtSupport8Internal18ExamplesPageWidgetC2Eb in gettingstartedwelcomepage.o
unimpl(
    _ZN9QtSupport8Internal29EmbeddedLinuxQtVersionFactoryC1Ev);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN9QtSupport8Internal22QtSupportPluginPrivateC2Ev
                                                                 // in
                                                                 // qtsupportplugin.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo10scopeChainERK5QListIPN5QmlJS3AST4NodeEE);  // ", referenced from:
                                                                               //__ZN11QmlJSEditorL25findCppComponentToInspectERKN10QmlJSTools12SemanticInfoEj in qmljseditor.o
                                                                               //__ZN11QmlJSEditor17QmlJSEditorWidget10findLinkAtERK11QTextCursorONSt3__18functionIFvRKN5Utils4LinkEEEEbb in qmljseditor.o
                                                                               //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv in qmljseditor.o
                                                                               //__ZN11QmlJSEditor17QmlJSHoverHandler13identifyMatchEPN10TextEditor16TextEditorWidgetEiNSt3__18functionIFviEEE in qmljshoverhandler.o
                                                                               //__ZNK11QmlJSEditor8Internal14QmlOutlineItem4dataEi in qmloutlinemodel.o
                                                                               //__ZN11QmlJSEditor8Internal30QmlJSCompletionAssistProcessor7performEPKN10TextEditor15AssistInterfaceE in qmljscompletionassist.o
                                                                               //__ZN11QmlJSEditor12_GLOBAL__N_114CollectionTaskC2E16QFutureInterfaceIN10TextEditor18HighlightingResultEERKN10QmlJSTools12SemanticInfoE in qmljssemantichighlighter.o
                                                                               //...
unimpl(
    _ZNK10QmlJSTools12SemanticInfo27declaringMemberNoPropertiesEi);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget17updateContextPaneEv
                                                                     // in
                                                                     // qmljseditor.o
                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget19semanticInfoUpdatedERKN10QmlJSTools12SemanticInfoE
                                                                     // in
                                                                     // qmljseditor.o
                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv
                                                                     // in
                                                                     // qmljseditor.o
                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget16contextMenuEventEP17QContextMenuEvent
                                                                     // in
                                                                     // qmljseditor.o
                                                                     //__ZN11QmlJSEditor17QmlJSEditorWidget10wheelEventEP11QWheelEvent
                                                                     // in
                                                                     // qmljseditor.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo7astPathEi);  // ", referenced from:
                                                //__ZN11QmlJSEditor17QmlJSHoverHandler13identifyMatchEPN10TextEditor16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                // in qmljshoverhandler.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo7isValidEv);  // ", referenced from:
                                                //__ZN11QmlJSEditor17QmlJSEditorWidget17updateContextPaneEv
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditor17QmlJSEditorWidget19setSelectedElementsEv
                                                // in qmljseditor.o
                                                //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditor17QmlJSEditorWidget10findLinkAtERK11QTextCursorONSt3__18functionIFvRKN5Utils4LinkEEEEbb
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv
                                                // in qmljseditor.o
                                                //__ZNK11QmlJSEditor17QmlJSEditorWidget19foldReplacementTextERK10QTextBlock
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditor17QmlJSHoverHandler13identifyMatchEPN10TextEditor16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                // in qmljshoverhandler.o
                                                //...
unimpl(
    _ZNK10QmlJSTools12SemanticInfo7rangeAtEi);  // ", referenced from:
                                                //__ZNK11QmlJSEditor17QmlJSEditorWidget19foldReplacementTextERK10QTextBlock
                                                // in qmljseditor.o
                                                //__ZN11QmlJSEditor12_GLOBAL__N_129matchSplitInitializerQuickFixERK14QSharedPointerIKNS_8Internal28QmlJSQuickFixAssistInterfaceEER5QListIS1_IN10TextEditor17QuickFixOperationEEE
                                                // in qmljsquickfixes.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo8revisionEv);  // ", referenced from:
                                                 //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate21acceptNewSemanticInfoERKN10QmlJSTools12SemanticInfoE
                                                 // in qmljseditordocument.o
                                                 //__ZNK11QmlJSEditor19QmlJSEditorDocument22isSemanticInfoOutdatedEv
                                                 // in qmljseditordocument.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo9astNodeAtEi);  // ", referenced from:
                                                  //__ZN11QmlJSEditorL25findCppComponentToInspectERKN10QmlJSTools12SemanticInfoEj
                                                  // in qmljseditor.o
                                                  //__ZN11QmlJSEditor17QmlJSEditorWidget10findLinkAtERK11QTextCursorONSt3__18functionIFvRKN5Utils4LinkEEEEbb
                                                  // in qmljseditor.o
unimpl(
    _ZNK10QmlJSTools12SemanticInfo9rangePathEi);  // ", referenced from:
                                                  //__ZN11QmlJSEditorL25findCppComponentToInspectERKN10QmlJSTools12SemanticInfoEj
                                                  // in qmljseditor.o
                                                  //__ZN11QmlJSEditor17QmlJSEditorWidget10findLinkAtERK11QTextCursorONSt3__18functionIFvRKN5Utils4LinkEEEEbb
                                                  // in qmljseditor.o
                                                  //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv
                                                  // in qmljseditor.o
                                                  //__ZN11QmlJSEditor17QmlJSHoverHandler13identifyMatchEPN10TextEditor16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                  // in qmljshoverhandler.o
                                                  //__ZN11QmlJSEditor35matchComponentFromObjectDefQuickFixERK14QSharedPointerIKNS_8Internal28QmlJSQuickFixAssistInterfaceEER5QListIS0_IN10TextEditor17QuickFixOperationEEE
                                                  // in
                                                  // qmljscomponentfromobjectdef.o
                                                  //__ZNK11QmlJSEditor8Internal14QmlOutlineItem4dataEi
                                                  // in qmloutlinemodel.o
                                                  //__ZN11QmlJSEditor8Internal30QmlJSCompletionAssistProcessor7performEPKN10TextEditor15AssistInterfaceE
                                                  // in qmljscompletionassist.o
                                                  //...
unimpl(
    _ZNK10QmlJSTools20QmlJSRefactoringFile10isCursorOnEN5QmlJS14SourceLocationE);  // ", referenced from:
                                                                                   //__ZN11QmlJSEditor12_GLOBAL__N_149matchAddAnalysisMessageSuppressionCommentQuickFixERK14QSharedPointerIKNS_8Internal28QmlJSQuickFixAssistInterfaceEER5QListIS1_IN10TextEditor17QuickFixOperationEEE in qmljsquickfixes.o
unimpl(
    _ZNK10QmlJSTools20QmlJSRefactoringFile10isCursorOnEPN5QmlJS3AST13UiQualifiedIdE);  // ", referenced from:
                                                                                       //__ZN11QmlJSEditor35matchComponentFromObjectDefQuickFixERK14QSharedPointerIKNS_8Internal28QmlJSQuickFixAssistInterfaceEER5QListIS0_IN10TextEditor17QuickFixOperationEEE in qmljscomponentfromobjectdef.o
                                                                                       //__ZN11QmlJSEditor25matchWrapInLoaderQuickFixERK14QSharedPointerIKNS_8Internal28QmlJSQuickFixAssistInterfaceEER5QListIS0_IN10TextEditor17QuickFixOperationEEE in qmljswrapinloader.o
unimpl(
    _ZNK10QmlJSTools20QmlJSRefactoringFile13qmljsDocumentEv);  // ", referenced
                                                               // from:
                                                               //__ZN11QmlJSEditor12_GLOBAL__N_19Operation14performChangesE14QSharedPointerIN10QmlJSTools20QmlJSRefactoringFileEERKNS3_23QmlJSRefactoringChangesE
                                                               // in
                                                               // qmljscomponentfromobjectdef.o
unimpl(
    _ZNK10QmlJSTools20QmlJSRefactoringFile7startOfERKN5QmlJS14SourceLocationE);  // ", referenced from:
                                                                                 //__ZN11QmlJSEditor12_GLOBAL__N_19Operation14performChangesE14QSharedPointerIN10QmlJSTools20QmlJSRefactoringFileEERKNS3_23QmlJSRefactoringChangesE in qmljscomponentfromobjectdef.o
                                                                                 //__ZN11QmlJSEditor12_GLOBAL__N_125SplitInitializerOperation14performChangesE14QSharedPointerIN10QmlJSTools20QmlJSRefactoringFileEERKNS3_23QmlJSRefactoringChangesE in qmljsquickfixes.o
unimpl(
    _ZNK10QmlJSTools23QmlJSRefactoringChanges4fileERK7QString);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN11QmlJSEditor29performComponentFromObjectDefERK7QStringPN5QmlJS3AST18UiObjectDefinitionE
                                                                 // in
                                                                 // qmljscomponentfromobjectdef.o
                                                                 //__ZN11QmlJSEditor8Internal15QmlOutlineModel13reparentNodesEPNS0_14QmlOutlineItemEi5QListIS3_E
                                                                 // in
                                                                 // qmloutlinemodel.o
                                                                 //__ZN11QmlJSEditor22QmlJSQuickFixOperation7performEv
                                                                 // in
                                                                 // qmljsquickfix.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor10textCursorEv);  // ", referenced from:
                                                      //__ZN8Debugger8Internal14DebuggerEngine31handleExecRunToSelectedFunctionEv
                                                      // in debuggerengine.o
                                                      //__ZN8Debugger8Internal14DebuggerEngine22handleAddToWatchWindowEv
                                                      // in debuggerengine.o
                                                      //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv
                                                      // in sourceagent.o
                                                      //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                                      // in textdocument.o
                                                      //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                                      // in textdocument.o
                                                      //__ZN7VcsBase13VcsBaseEditor25lineNumberOfCurrentEditorERK7QString
                                                      // in vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor11columnCountEv);  // ", referenced from:
                                                       //__ZZN10TextEditor8Internal16TextEditorPlugin21extensionsInitializedEvENK3$_9clEv
                                                       // in texteditorplugin.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor11contextHelpERKNSt3__18functionIFvRKN4Core8HelpItemEEEE);  // ", referenced from:
                                                                                                //__ZTVN10TextEditor14BaseTextEditorE in moc_texteditor.o
                                                                                                //__ZTVN9CppEditor8Internal9CppEditorE in moc_cppeditor.o
                                                                                                //__ZTVN11QmlJSEditor11QmlJSEditorE in moc_qmljseditor.o
                                                                                                //__ZTVN7VcsBase13VcsBaseEditorE in moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor11currentLineEv);  // ", referenced from:
                                                       //__ZTVN10TextEditor14BaseTextEditorE
                                                       // in moc_texteditor.o
                                                       //__ZTVN9CppEditor8Internal9CppEditorE
                                                       // in moc_cppeditor.o
                                                       //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                       // in moc_qmljseditor.o
                                                       //__ZTVN7VcsBase13VcsBaseEditorE
                                                       // in moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor12editorWidgetEv);  // ", referenced from:
                                                        //__ZN8Debugger8Internal14DebuggerEngine22handleAddToWatchWindowEv
                                                        // in debuggerengine.o
                                                        //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate21updateVisibleToolTipsEv
                                                        // in
                                                        // debuggertooltipmanager.o
                                                        //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate16slotEditorOpenedEPN4Core7IEditorE
                                                        // in
                                                        // debuggertooltipmanager.o
                                                        //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate16leavingDebugModeEv
                                                        // in
                                                        // debuggertooltipmanager.o
                                                        //__ZN8Debugger8Internal21DebuggerToolTipWidget10leaveEventEP6QEvent
                                                        // in
                                                        // debuggertooltipmanager.o
                                                        //__ZN8Debugger8Internal11SourceAgent10setContentERK7QStringS4_
                                                        // in sourceagent.o
                                                        //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                                        // in textdocument.o
                                                        //...
unimpl(
    _ZNK10TextEditor14BaseTextEditor12selectedTextEv);  // ", referenced from:
                                                        //__ZTVN10TextEditor14BaseTextEditorE
                                                        // in moc_texteditor.o
                                                        //__ZTVN9CppEditor8Internal9CppEditorE
                                                        // in moc_cppeditor.o
                                                        //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                        // in moc_qmljseditor.o
                                                        //__ZTVN7VcsBase13VcsBaseEditorE
                                                        // in
                                                        // moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor12textDocumentEv);  // ", referenced from:
                                                        //__ZN8Debugger8Internal12LocationMark10dragToLineEi
                                                        // in debuggerengine.o
                                                        //__ZN8Debugger8Internal14DebuggerEngine19handleExecRunToLineEv
                                                        // in debuggerengine.o
                                                        //__ZN8Debugger8Internal14DebuggerEngine20handleExecJumpToLineEv
                                                        // in debuggerengine.o
                                                        //__ZN8Debugger8Internal21DebuggerPluginPrivate22toggleBreakpointHelperEv
                                                        // in debuggerplugin.o
                                                        //__ZN8Debugger8Internal14openTextEditorERK7QStringS3_
                                                        // in debuggerplugin.o
                                                        //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate21updateVisibleToolTipsEv
                                                        // in
                                                        // debuggertooltipmanager.o
                                                        //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv
                                                        // in sourceagent.o
                                                        //...
unimpl(
    _ZNK10TextEditor14BaseTextEditor13currentColumnEv);  // ", referenced from:
                                                         //__ZTVN10TextEditor14BaseTextEditorE
                                                         // in moc_texteditor.o
                                                         //__ZTVN9CppEditor8Internal9CppEditorE
                                                         // in moc_cppeditor.o
                                                         //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                         // in moc_qmljseditor.o
                                                         //__ZTVN7VcsBase13VcsBaseEditorE
                                                         // in
                                                         // moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor15convertPositionEiPiS1_);  // ", referenced
                                                                // from:
                                                                //__ZTVN10TextEditor14BaseTextEditorE
                                                                // in
                                                                // moc_texteditor.o
                                                                //__ZTVN9CppEditor8Internal9CppEditorE
                                                                // in
                                                                // moc_cppeditor.o
                                                                //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                                // in
                                                                // moc_qmljseditor.o
                                                                //__ZTVN7VcsBase13VcsBaseEditorE
                                                                // in
                                                                // moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor8documentEv);  // ", referenced from:
                                                   //__ZTVN10TextEditor14BaseTextEditorE
                                                   // in moc_texteditor.o
                                                   //__ZTVN9CppEditor8Internal9CppEditorE
                                                   // in moc_cppeditor.o
                                                   //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                   // in moc_qmljseditor.o
                                                   //__ZTVN7VcsBase13VcsBaseEditorE
                                                   // in moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor8positionENS_21TextPositionOperationEi);  // ", referenced from:
                                                                              //__ZTVN10TextEditor14BaseTextEditorE in moc_texteditor.o
                                                                              //__ZTVN9CppEditor8Internal9CppEditorE in moc_cppeditor.o
                                                                              //__ZTVN11QmlJSEditor11QmlJSEditorE in moc_qmljseditor.o
                                                                              //__ZTVN7VcsBase13VcsBaseEditorE in moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor8rowCountEv);  // ", referenced from:
                                                   //__ZZN10TextEditor8Internal16TextEditorPlugin21extensionsInitializedEvENK3$_8clEv
                                                   // in texteditorplugin.o
unimpl(
    _ZNK10TextEditor14BaseTextEditor9saveStateEv);  // ", referenced from:
                                                    //__ZTVN10TextEditor14BaseTextEditorE
                                                    // in moc_texteditor.o
                                                    //__ZTVN9CppEditor8Internal9CppEditorE
                                                    // in moc_cppeditor.o
                                                    //__ZTVN11QmlJSEditor11QmlJSEditorE
                                                    // in moc_qmljseditor.o
                                                    //__ZTVN7VcsBase13VcsBaseEditorE
                                                    // in moc_vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget10cursorRectEi);  // ", referenced from:
                                                        //__ZN10TextEditor20CodeAssistantPrivate15displayProposalEPNS_15IAssistProposalENS_12AssistReasonE
                                                        // in codeassistant.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget10lineNumberEi);  // ", referenced from:
                                                        //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                        // in
                                                        // plaintexteditorfactory.o
                                                        //__ZNK7VcsBase19VcsBaseEditorWidget10lineNumberEi
                                                        // in vcsbaseeditor.o
                                                        //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                        // in diffeditor.o
                                                        //__ZTVN10TextEditor16TextEditorWidgetE
                                                        // in moc_texteditor.o
                                                        //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                        // in
                                                        // moc_snippeteditor.o
                                                        //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                        // in
                                                        // moc_cppeditorwidget.o
                                                        //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                        // in moc_qmljseditor.o
                                                        //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget10paintBlockEP8QPainterRK10QTextBlockRK7QPointFRK7QVectorIN11QTextLayout11FormatRangeEERK5QRect);  // ", referenced from:
                                                                                                                                         //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                                                                         //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                                                                         //__ZNK10DiffEditor8Internal26SelectableTextEditorWidget10paintBlockEP8QPainterRK10QTextBlockRK7QPointFRK7QVectorIN11QTextLayout11FormatRangeEERK5QRect in selectabletexteditorwidget.o
                                                                                                                                         //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                                                                         //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                                                                         //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                                                                         //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                                                                         //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget11characterAtEi);  // ", referenced from:
                                                         //__ZN8Debugger8Internal15cppExpressionAtEPN10TextEditor16TextEditorWidgetEiPiS4_P7QStringS4_S4_
                                                         // in sourceutils.o
                                                         //__ZNK10TextEditor23TextDocumentManipulator11characterAtEi
                                                         // in
                                                         // textdocumentmanipulator.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget12textDocumentEv);  // ", referenced from:
                                                          //__ZN8Debugger8Internal21DebuggerPluginPrivate11requestMarkEPN10TextEditor16TextEditorWidgetEiNS2_19TextMarkRequestKindE
                                                          // in debuggerplugin.o
                                                          //__ZN8Debugger8Internal21DebuggerPluginPrivate18requestContextMenuEPN10TextEditor16TextEditorWidgetEiP5QMenu
                                                          // in debuggerplugin.o
                                                          //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate28slotTooltipOverrideRequestedEPN10TextEditor16TextEditorWidgetERK6QPointiPb
                                                          // in
                                                          // debuggertooltipmanager.o
                                                          //__ZN8Debugger8Internal15cppExpressionAtEPN10TextEditor16TextEditorWidgetEiPiS4_P7QStringS4_S4_
                                                          // in sourceutils.o
                                                          //__ZN10TextEditor21PlainTextEditorWidget22finalizeInitializationEv
                                                          // in
                                                          // plaintexteditorfactory.o
                                                          //__ZN10TextEditor15RefactoringFileC2EPNS_16TextEditorWidgetE
                                                          // in
                                                          // refactoringchanges.o
                                                          //__ZN10TextEditor15RefactoringFile16indentOrReindentEMNS_22RefactoringChangesDataEKFvRK11QTextCursorRK7QStringPKNS_12TextDocumentEERK7QVectorI5QPairIS2_S2_EE
                                                          // in
                                                          // refactoringchanges.o
                                                          //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget14extraAreaWidthEPi);  // ", referenced
                                                             // from:
                                                             //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                             // in
                                                             // plaintexteditorfactory.o
                                                             //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                             // in diffeditor.o
                                                             //__ZNK10DiffEditor8Internal20SideDiffEditorWidget14extraAreaWidthEPi
                                                             // in
                                                             // sidebysidediffeditorwidget.o
                                                             //__ZTVN10TextEditor16TextEditorWidgetE
                                                             // in
                                                             // moc_texteditor.o
                                                             //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                             // in
                                                             // moc_cppeditorwidget.o
                                                             //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                             // in
                                                             // moc_qmljseditor.o
                                                             //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                             // in
                                                             // moc_vcsbaseeditor.o
                                                             //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget15convertPositionEiPiS1_);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN8Debugger8Internal29DebuggerToolTipManagerPrivate28slotTooltipOverrideRequestedEPN10TextEditor16TextEditorWidgetERK6QPointiPb
                                                                  // in
                                                                  // debuggertooltipmanager.o
                                                                  //__ZN8CppTools16CppEditorOutline10modelIndexEv
                                                                  // in
                                                                  // cppeditoroutline.o
                                                                  //__ZN8CppTools19CppElementEvaluator7executeEMS0_F7QFutureI14QSharedPointerINS_10CppElementEEERKN9CPlusPlus8SnapshotERKNS6_10LookupItemERKNS6_13LookupContextEE
                                                                  // in
                                                                  // cppelementevaluator.o
                                                                  //__ZN7VcsBase19VcsBaseEditorWidget15slotJumpToEntryEi
                                                                  // in
                                                                  // vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget15displaySettingsEv);  // ", referenced
                                                             // from:
                                                             //__ZN10TextEditor8Internal30TextEditorActionHandlerPrivate13updateActionsEv
                                                             // in
                                                             // texteditoractionhandler.o
                                                             //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_43clEPNS_16TextEditorWidgetEb
                                                             // in
                                                             // texteditoractionhandler.o
                                                             //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK4$_45clEPNS_16TextEditorWidgetEb
                                                             // in
                                                             // texteditoractionhandler.o
                                                             //__ZN10TextEditor15CodeStyleEditorC2EPNS_28ICodeStylePreferencesFactoryEPNS_21ICodeStylePreferencesEP7QWidget
                                                             // in
                                                             // codestyleeditor.o
                                                             //__ZN10DiffEditor8Internal23DescriptionEditorWidgetC2EP7QWidget
                                                             // in diffeditor.o
                                                             //__ZN10DiffEditor8Internal23DescriptionEditorWidget18setDisplaySettingsERKN10TextEditor15DisplaySettingsE
                                                             // in diffeditor.o
                                                             //__ZN10DiffEditor8Internal20SideDiffEditorWidgetC2EP7QWidget
                                                             // in
                                                             // sidebysidediffeditorwidget.o
                                                             //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget15extraSelectionsEN5Utils2IdE);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN9CppEditor8Internal15CppEditorWidget38finalizeInitializationAfterDuplicationEPN10TextEditor16TextEditorWidgetE
                                                                       // in
                                                                       // cppeditorwidget.o
                                                                       //__ZNK9CppEditor8Internal23CppUseSelectionsUpdater20currentUseSelectionsEv
                                                                       // in
                                                                       // cppuseselectionsupdater.o
                                                                       //__ZN8CppTools19CppElementEvaluator22checkDiagnosticMessageEi
                                                                       // in
                                                                       // cppelementevaluator.o
                                                                       //__ZN11QmlJSEditor17QmlJSHoverHandler22matchDiagnosticMessageEPNS_17QmlJSEditorWidgetEi
                                                                       // in
                                                                       // qmljshoverhandler.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget15refactorMarkersEv);  // ", referenced
                                                             // from:
                                                             //__ZN9CppEditor8Internal15CppEditorWidget21onCodeWarningsUpdatedEj5QListIN9QTextEdit14ExtraSelectionEERKS2_IN10TextEditor14RefactorMarkerEE
                                                             // in
                                                             // cppeditorwidget.o
                                                             //__ZN9CppEditor8Internal19FunctionDeclDefLink10hideMarkerEPNS0_15CppEditorWidgetE
                                                             // in
                                                             // cppfunctiondecldeflink.o
                                                             //__ZN9CppEditor8Internal19FunctionDeclDefLink10showMarkerEPNS0_15CppEditorWidgetE
                                                             // in
                                                             // cppfunctiondecldeflink.o
                                                             //__ZN11QmlJSEditor17QmlJSEditorWidget17updateContextPaneEv
                                                             // in qmljseditor.o
                                                             //__ZN11QmlJSEditor17QmlJSEditorWidget15showContextPaneEv
                                                             // in qmljseditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget15toolTipPositionERK11QTextCursor);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN8Debugger8Internal21DebuggerToolTipHolder12positionShowEPKN10TextEditor16TextEditorWidgetE
                                                                           // in
                                                                           // debuggertooltipmanager.o
                                                                           //__ZN9CppEditor8Internal19FunctionDeclDefLink5applyEPNS0_15CppEditorWidgetEb
                                                                           // in
                                                                           // cppfunctiondecldeflink.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget16behaviorSettingsEv);  // ", referenced
                                                              // from:
                                                              //__ZN9CppEditor8Internal15CppEditorWidget13selectBlockUpEv
                                                              // in
                                                              // cppeditorwidget.o
                                                              //__ZN9CppEditor8Internal15CppEditorWidget15selectBlockDownEv
                                                              // in
                                                              // cppeditorwidget.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget16lineNumberDigitsEv);  // ", referenced
                                                              // from:
                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                              // in
                                                              // plaintexteditorfactory.o
                                                              //__ZNK7VcsBase19VcsBaseEditorWidget16lineNumberDigitsEv
                                                              // in
                                                              // vcsbaseeditor.o
                                                              //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                              // in diffeditor.o
                                                              //__ZTVN10TextEditor16TextEditorWidgetE
                                                              // in
                                                              // moc_texteditor.o
                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                              // in
                                                              // moc_snippeteditor.o
                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                              // in
                                                              // moc_cppeditorwidget.o
                                                              //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                              // in
                                                              // moc_qmljseditor.o
                                                              //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget16selectionVisibleEi);  // ", referenced
                                                              // from:
                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                              // in
                                                              // plaintexteditorfactory.o
                                                              //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                              // in diffeditor.o
                                                              //__ZTVN10TextEditor16TextEditorWidgetE
                                                              // in
                                                              // moc_texteditor.o
                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                              // in
                                                              // moc_snippeteditor.o
                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                              // in
                                                              // moc_cppeditorwidget.o
                                                              //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                              // in
                                                              // moc_qmljseditor.o
                                                              //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                              // in
                                                              // moc_vcsbaseeditor.o
                                                              //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget17hasBlockSelectionEv);  // ", referenced
                                                               // from:
                                                               //__ZN10TextEditor20CodeAssistantPrivate15requestProposalENS_12AssistReasonENS_10AssistKindEPNS_15IAssistProviderE
                                                               // in
                                                               // codeassistant.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget18languageSettingsIdEv);  // ", referenced
                                                                // from:
                                                                //__ZNK15ProjectExplorer19EditorConfiguration15configureEditorEPN10TextEditor14BaseTextEditorE
                                                                // in
                                                                // editorconfiguration.o
                                                                //__ZNK15ProjectExplorer19EditorConfiguration17deconfigureEditorEPN10TextEditor14BaseTextEditorE
                                                                // in
                                                                // editorconfiguration.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget18replacementVisibleEi);  // ", referenced
                                                                // from:
                                                                //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                // in
                                                                // plaintexteditorfactory.o
                                                                //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                // in
                                                                // diffeditor.o
                                                                //__ZTVN10TextEditor16TextEditorWidgetE
                                                                // in
                                                                // moc_texteditor.o
                                                                //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                // in
                                                                // moc_snippeteditor.o
                                                                //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                // in
                                                                // moc_cppeditorwidget.o
                                                                //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                // in
                                                                // moc_qmljseditor.o
                                                                //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                                // in
                                                                // moc_vcsbaseeditor.o
                                                                //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget19foldReplacementTextERK10QTextBlock);  // ", referenced from:
                                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                              //__ZNK11QmlJSEditor17QmlJSEditorWidget19foldReplacementTextERK10QTextBlock in qmljseditor.o
                                                                              //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                              //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                              //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                              //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget19replacementPenColorEi);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                 // in
                                                                 // plaintexteditorfactory.o
                                                                 //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                 // in
                                                                 // diffeditor.o
                                                                 //__ZTVN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // moc_texteditor.o
                                                                 //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                 // in
                                                                 // moc_snippeteditor.o
                                                                 //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                 // in
                                                                 // moc_cppeditorwidget.o
                                                                 //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                 // in
                                                                 // moc_qmljseditor.o
                                                                 //__ZTVN7VcsBase19VcsBaseEditorWidgetE
                                                                 // in
                                                                 // moc_vcsbaseeditor.o
                                                                 //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget21canInsertFromMimeDataEPK9QMimeData);  // ", referenced from:
                                                                              //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                              //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                              //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                              //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                              //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                              //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                              //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                              //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget21createAssistInterfaceENS_10AssistKindENS_12AssistReasonE);  // ", referenced from:
                                                                                                    //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                                    //__ZNK9CppEditor8Internal15CppEditorWidget21createAssistInterfaceEN10TextEditor10AssistKindENS2_12AssistReasonE in cppeditorwidget.o
                                                                                                    //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                                    //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE in sidebysidediffeditorwidget.o
                                                                                                    //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                                    //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                                    //__ZTVN7VcsBase19VcsBaseEditorWidgetE in moc_vcsbaseeditor.o
                                                                                                    //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget21extraSelectionTooltipEi);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN10TextEditor16BaseHoverHandler13identifyMatchEPNS_16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                                   // in
                                                                   // basehoverhandler.o
                                                                   //__ZN10TextEditor24ColorPreviewHoverHandler13identifyMatchEPNS_16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                                   // in
                                                                   // colorpreviewhoverhandler.o
                                                                   //__ZN9CppEditor8Internal27ResourcePreviewHoverHandler13identifyMatchEPN10TextEditor16TextEditorWidgetEiNSt3__18functionIFviEEE
                                                                   // in
                                                                   // resourcepreviewhoverhandler.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget22lastVisibleBlockNumberEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN7VcsBase13VcsBaseEditor25lineNumberOfCurrentEditorERK7QString
                                                                    // in
                                                                    // vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget22plainTextFromSelectionERK11QTextCursor);  // ", referenced from:
                                                                                  //__ZTVN10TextEditor21PlainTextEditorWidgetE in plaintexteditorfactory.o
                                                                                  //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE in diffeditor.o
                                                                                  //__ZTVN10TextEditor16TextEditorWidgetE in moc_texteditor.o
                                                                                  //__ZTVN10TextEditor19SnippetEditorWidgetE in moc_snippeteditor.o
                                                                                  //__ZTVN9CppEditor8Internal15CppEditorWidgetE in moc_cppeditorwidget.o
                                                                                  //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE in moc_qmljseditor.o
                                                                                  //__ZTVN7VcsBase19VcsBaseEditorWidgetE in moc_vcsbaseeditor.o
                                                                                  //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget23firstVisibleBlockNumberEv);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN7VcsBase13VcsBaseEditor25lineNumberOfCurrentEditorERK7QString
                                                                     // in
                                                                     // vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget24centerVisibleBlockNumberEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN7VcsBase13VcsBaseEditor25lineNumberOfCurrentEditorERK7QString
                                                                      // in
                                                                      // vcsbaseeditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget26alwaysOpenLinksInNextSplitEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN9CppEditor8Internal15CppEditorWidget27switchDeclarationDefinitionEb
                                                                        // in
                                                                        // cppeditorwidget.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget27createMimeDataFromSelectionEv);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZTVN10TextEditor21PlainTextEditorWidgetE
                                                                         // in
                                                                         // plaintexteditorfactory.o
                                                                         //__ZTVN10DiffEditor8Internal23DescriptionEditorWidgetE
                                                                         // in
                                                                         // diffeditor.o
                                                                         //__ZTVN10DiffEditor8Internal20SideDiffEditorWidgetE
                                                                         // in
                                                                         // sidebysidediffeditorwidget.o
                                                                         //__ZTVN10TextEditor16TextEditorWidgetE
                                                                         // in
                                                                         // moc_texteditor.o
                                                                         //__ZTVN10TextEditor19SnippetEditorWidgetE
                                                                         // in
                                                                         // moc_snippeteditor.o
                                                                         //__ZTVN9CppEditor8Internal15CppEditorWidgetE
                                                                         // in
                                                                         // moc_cppeditorwidget.o
                                                                         //__ZTVN11QmlJSEditor17QmlJSEditorWidgetE
                                                                         // in
                                                                         // moc_qmljseditor.o
                                                                         //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget28highlightScrollBarControllerEv);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZZN10DiffEditor8Internal26SideBySideDiffEditorWidgetC1EP7QWidgetENK3$_1clEv
                                                                          // in
                                                                          // sidebysidediffeditorwidget.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget32verticalBlockSelectionLastColumnEv);  // ", referenced from:
                                                                              //__ZN10TextEditor16TextEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_texteditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget33verticalBlockSelectionFirstColumnEv);  // ", referenced from:
                                                                               //__ZN10TextEditor16TextEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv in moc_texteditor.o
unimpl(
    _ZNK10TextEditor16TextEditorWidget6textAtEii);  // ", referenced from:
                                                    //__ZN10TextEditor20CodeAssistantPrivate6invokeENS_10AssistKindEPNS_15IAssistProviderE
                                                    // in codeassistant.o
                                                    //__ZN10TextEditor20CodeAssistantPrivate15displayProposalEPNS_15IAssistProposalENS_12AssistReasonE
                                                    // in codeassistant.o
                                                    //__ZN10TextEditor20CodeAssistantPrivate21handlePrefixExpansionERK7QString
                                                    // in codeassistant.o
                                                    //__ZN10TextEditor20CodeAssistantPrivate12notifyChangeEv
                                                    // in codeassistant.o
                                                    //__ZZN10TextEditor20CodeAssistantPrivate26identifyActivationSequenceEvENK3$_2clEPNS_24CompletionAssistProviderE
                                                    // in codeassistant.o
                                                    //__ZNK10TextEditor23TextDocumentManipulator6textAtEii
                                                    // in
                                                    // textdocumentmanipulator.o
                                                    //__ZNK10TextEditor23TextDocumentManipulator17textIsDifferentAtEiiRK7QString
                                                    // in
                                                    // textdocumentmanipulator.o
                                                    //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget8positionENS_21TextPositionOperationEi);  // ", referenced from:
                                                                                //__ZN10TextEditor20CodeAssistantPrivate6invokeENS_10AssistKindEPNS_15IAssistProviderE in codeassistant.o
                                                                                //__ZN10TextEditor20CodeAssistantPrivate15displayProposalEPNS_15IAssistProposalENS_12AssistReasonE in codeassistant.o
                                                                                //__ZN10TextEditor20CodeAssistantPrivate21handlePrefixExpansionERK7QString in codeassistant.o
                                                                                //__ZN10TextEditor20CodeAssistantPrivate12notifyChangeEv in codeassistant.o
                                                                                //__ZZN10TextEditor20CodeAssistantPrivate26identifyActivationSequenceEvENK3$_2clEPNS_24CompletionAssistProviderE in codeassistant.o
                                                                                //__ZNK10TextEditor23TextDocumentManipulator15currentPositionEv in textdocumentmanipulator.o
                                                                                //__ZNK10TextEditor23TextDocumentManipulator10positionAtENS_21TextPositionOperationE in textdocumentmanipulator.o
                                                                                //...
unimpl(
    _ZNK10TextEditor16TextEditorWidget9saveStateEv);  // ", referenced from:
                                                      //__ZN10DiffEditor8Internal20SideDiffEditorWidget9saveStateEv
                                                      // in
                                                      // sidebysidediffeditorwidget.o
                                                      //__ZN10DiffEditor8Internal23UnifiedDiffEditorWidget9saveStateEv
                                                      // in
                                                      // unifieddiffeditorwidget.o
unimpl(
    _ZNK10TextEditor19DisplaySettingsPage14marginSettingsEv);  // ", referenced
                                                               // from:
                                                               //__ZN10TextEditor18TextEditorSettings14marginSettingsEv
                                                               // in
                                                               // texteditorsettings.o
unimpl(
    _ZNK10TextEditor19DisplaySettingsPage15displaySettingsEv);  // ", referenced
                                                                // from:
                                                                //__ZN10TextEditor18TextEditorSettings15displaySettingsEv
                                                                // in
                                                                // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage13codeStylePoolEv);  // ", referenced
                                                               // from:
                                                               //__ZN10TextEditor18TextEditorSettings13codeStylePoolEv
                                                               // in
                                                               // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage14typingSettingsEv);  // ", referenced
                                                                // from:
                                                                //__ZN10TextEditor18TextEditorSettings14typingSettingsEv
                                                                // in
                                                                // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage15storageSettingsEv);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN10TextEditor18TextEditorSettings15storageSettingsEv
                                                                 // in
                                                                 // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage16behaviorSettingsEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZZN10TextEditor18TextEditorSettingsC1EvENK3$_1clEv
                                                                  // in
                                                                  // texteditorsettings.o
                                                                  //__ZN10TextEditor18TextEditorSettings16behaviorSettingsEv
                                                                  // in
                                                                  // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage21extraEncodingSettingsEv);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZN10TextEditor18TextEditorSettings21extraEncodingSettingsEv
                                                                       // in
                                                                       // texteditorsettings.o
unimpl(
    _ZNK10TextEditor20BehaviorSettingsPage9codeStyleEv);  // ", referenced from:
                                                          //__ZN10TextEditor18TextEditorSettings9codeStyleEv
                                                          // in
                                                          // texteditorsettings.o
unimpl(
    _ZNK10TextEditor23HighlighterSettingsPage19highlighterSettingsEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN10TextEditor18TextEditorSettings19highlighterSettingsEv
                                                                        // in
                                                                        // texteditorsettings.o
unimpl(
    _ZNK13LanguageUtils12FakeMetaEnum3keyEi);  // ", referenced from:
                                               //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                               // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils12FakeMetaEnum4keysEv);  // ", referenced from:
                                                //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                // in qmljseditor.o
                                                //__ZNK5QmlJS12QmlEnumValue4keysEv
                                                // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils12FakeMetaEnum4nameEv);  // ", referenced from:
                                                //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                // in qmljseditor.o
                                                //__ZN5QmlJS17CppComponentValueC2E14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEERK7QStringS8_RKNS2_16ComponentVersionESB_iPNS_10ValueOwnerES8_
                                                // in qmljsinterpreter.o
                                                //__ZNK5QmlJS12QmlEnumValue4nameEv
                                                // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils12FakeMetaEnum8keyCountEv);  // ", referenced from:
                                                    //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                    // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod10methodNameEv);  // ", referenced from:
                                                         //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZN5QmlJS21TypeDescriptionReader18readSignalOrMethodEPNS_3AST18UiObjectDefinitionEb14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                         // in
                                                         // qmljstypedescriptionreader.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod10methodTypeEv);  // ", referenced from:
                                                         //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                         // in
                                                         // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod14parameterNamesEv);  // ", referenced
                                                             // from:
                                                             //__ZNK11QmlJSEditor18CodeModelInspector27stringifyFunctionParametersEPKN5QmlJS5ValueE
                                                             // in qmljseditor.o
                                                             //__ZNK5QmlJS12MetaFunction18namedArgumentCountEv
                                                             // in
                                                             // qmljsinterpreter.o
                                                             //__ZNK5QmlJS12MetaFunction12argumentNameEi
                                                             // in
                                                             // qmljsinterpreter.o
                                                             //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                             // in
                                                             // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod14parameterTypesEv);  // ", referenced
                                                             // from:
                                                             //__ZNK11QmlJSEditor18CodeModelInspector27stringifyFunctionParametersEPKN5QmlJS5ValueE
                                                             // in qmljseditor.o
                                                             //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                             // in
                                                             // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod6accessEv);  // ", referenced from:
                                                    //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                    // in qmljsinterpreter.o
                                                    //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                    // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaMethod8revisionEv);  // ", referenced from:
                                                      //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                      // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject10enumeratorEi);  // ", referenced from:
                                                         //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                         // in qmljseditor.o
                                                         //__ZN5QmlJS17CppComponentValueC2E14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEERK7QStringS8_RKNS2_16ComponentVersionESB_iPNS_10ValueOwnerES8_
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS17CppComponentValue7getEnumERK7QStringPPKS0_
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS12QmlEnumValue4nameEv
                                                         // in
                                                         // qmljsinterpreter.o
                                                         //__ZNK5QmlJS12QmlEnumValue4keysEv
                                                         // in
                                                         // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject11fingerprintEv);  // ", referenced from:
                                                          //__ZNK5QmlJS11LibraryInfo20calculateFingerprintEv
                                                          // in qmljsdocument.o
                                                          //__ZN5QmlJS13rescanExportsERK7QStringRNS_20FindExportedCppTypesER5QHashIS0_NS_21ModelManagerInterface7CppDataEE
                                                          // in
                                                          // qmljsmodelmanagerinterface.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject11methodCountEv);  // ", referenced from:
                                                          //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                          // in
                                                          // qmljsinterpreter.o
                                                          //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                          // in
                                                          // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject13propertyCountEv);  // ", referenced
                                                            // from:
                                                            //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                            // in
                                                            // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject13propertyIndexERK7QString);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZNK5QmlJS17CppComponentValue10isWritableERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
                                                                     //__ZNK5QmlJS17CppComponentValue14isListPropertyERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
                                                                     //__ZNK5QmlJS17CppComponentValue9isPointerERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
                                                                     //__ZNK5QmlJS17CppComponentValue12propertyTypeERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
                                                                     //__ZNK5QmlJS17CppComponentValue16hasLocalPropertyERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
                                                                     //__ZNK5QmlJS17CppComponentValue11hasPropertyERK7QString
                                                                     // in
                                                                     // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject14superclassNameEv);  // ", referenced
                                                             // from:
                                                             //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                             // in qmljseditor.o
                                                             //__ZN5QmlJS11CppQmlTypes4loadI5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRK7QStringRKT_SB_
                                                             // in
                                                             // qmljsinterpreter.o
                                                             //__ZN5QmlJS11CppQmlTypes4loadI5QHashI7QString14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRKS3_RKT_SB_
                                                             // in
                                                             // qmljsinterpreter.o
                                                             //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                             // in
                                                             // qmljsinterpreter.o
                                                             //__ZN5QmlJSL22workaroundQEasingCurveERNS_11CppQmlTypesE
                                                             // in qmljslink.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject15enumeratorCountEv);  // ", referenced
                                                              // from:
                                                              //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                              // in
                                                              // qmljseditor.o
                                                              //__ZN5QmlJS17CppComponentValueC2E14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEERK7QStringS8_RKNS2_16ComponentVersionESB_iPNS_10ValueOwnerES8_
                                                              // in
                                                              // qmljsinterpreter.o
                                                              //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                              // in
                                                              // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject15enumeratorIndexERK7QString);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZNK5QmlJS17CppComponentValue7getEnumERK7QStringPPKS0_
                                                                       // in
                                                                       // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject16attachedTypeNameEv);  // ", referenced
                                                               // from:
                                                               //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                               // in
                                                               // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject16enumeratorOffsetEv);  // ", referenced
                                                               // from:
                                                               //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                               // in
                                                               // qmljseditor.o
                                                               //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                               // in
                                                               // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject19defaultPropertyNameEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZNK5QmlJS17CppComponentValue19defaultPropertyNameEv
                                                                  // in
                                                                  // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject6methodEi);  // ", referenced from:
                                                    //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                    // in qmljsinterpreter.o
                                                    //__ZNK5QmlJS17CppComponentValue11signalScopeERK7QString
                                                    // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject7exportsEv);  // ", referenced from:
                                                     //__ZN5QmlJS8Snapshot17insertLibraryInfoERK7QStringRKNS_11LibraryInfoE
                                                     // in qmljsdocument.o
                                                     //__ZN5QmlJS11CppQmlTypes4loadI5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRK7QStringRKT_SB_
                                                     // in qmljsinterpreter.o
                                                     //__ZN5QmlJS11CppQmlTypes4loadI5QHashI7QString14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRKS3_RKT_SB_
                                                     // in qmljsinterpreter.o
                                                     //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                     // in qmljsinterpreter.o
                                                     //__ZL23getHighestExportVersionRK5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEERK7QStringSA_PbPNS1_16ComponentVersionE
                                                     // in qmljsplugindumper.o
                                                     //__ZN5QmlJS21TypeDescriptionReader23readMetaObjectRevisionsEPNS_3AST15UiScriptBindingE14QSharedPointerIN13LanguageUtils14FakeMetaObjectEE
                                                     // in
                                                     // qmljstypedescriptionreader.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject8propertyEi);  // ", referenced from:
                                                      //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                      // in qmljsinterpreter.o
                                                      //__ZNK5QmlJS17CppComponentValue10isWritableERK7QString
                                                      // in qmljsinterpreter.o
                                                      //__ZNK5QmlJS17CppComponentValue14isListPropertyERK7QString
                                                      // in qmljsinterpreter.o
                                                      //__ZNK5QmlJS17CppComponentValue9isPointerERK7QString
                                                      // in qmljsinterpreter.o
                                                      //__ZNK5QmlJS17CppComponentValue12propertyTypeERK7QString
                                                      // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils14FakeMetaObject9classNameEv);  // ", referenced from:
                                                       //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv
                                                       // in qmljseditor.o
                                                       //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                       // in qmljseditor.o
                                                       //__ZN11QmlJSEditor18CodeModelInspector15processPropertyERK7QStringPKN5QmlJS5ValueERKNS4_12PropertyInfoE
                                                       // in qmljseditor.o
                                                       //__ZN12_GLOBAL__N_122buildContextPropertiesERK14QSharedPointerIN9CPlusPlus8DocumentEERNS1_16TypeOfExpressionERK5QListINS_15ContextPropertyEEP5QHashIPNS1_5ClassES0_IN13LanguageUtils14FakeMetaObjectEEEPSD_I7QStringSL_E
                                                       // in
                                                       // qmljsfindexportedcpptypes.o
                                                       //__ZN12_GLOBAL__N_119buildFakeMetaObjectEPN9CPlusPlus5ClassEP5QHashIS2_14QSharedPointerIN13LanguageUtils14FakeMetaObjectEEERNS0_16TypeOfExpressionE
                                                       // in
                                                       // qmljsfindexportedcpptypes.o
                                                       //__ZN5QmlJS11CppQmlTypes4loadI5QListI14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRK7QStringRKT_SB_
                                                       // in qmljsinterpreter.o
                                                       //__ZN5QmlJS11CppQmlTypes4loadI5QHashI7QString14QSharedPointerIKN13LanguageUtils14FakeMetaObjectEEEEEvRKS3_RKT_SB_
                                                       // in qmljsinterpreter.o
                                                       //...
unimpl(
    _ZNK13LanguageUtils16ComponentVersion7isValidEv);  // ", referenced from:
                                                       //__ZZN12QmlDirParser5parseERK7QStringENK3$_7clEPS1_i6QFlagsINS_6Import4FlagEE
                                                       // in qmldirparser.o
                                                       //__ZN5QmlJS4Bind5visitEPNS_3AST8UiImportE
                                                       // in qmljsbind.o
                                                       //__ZN5QmlJS11CppQmlTypes22createObjectsForImportERK7QStringN13LanguageUtils16ComponentVersionE
                                                       // in qmljsinterpreter.o
                                                       //__ZN5QmlJS11LinkPrivate13importNonFileERK14QSharedPointerIKNS_8DocumentEERKNS_10ImportInfoE
                                                       // in qmljslink.o
                                                       //__ZN5QmlJS11LinkPrivate13importLibraryERK14QSharedPointerIKNS_8DocumentEERK7QStringPNS_6ImportEPNS_11ObjectValueES9_b
                                                       // in qmljslink.o
                                                       //__ZN5QmlJSL17findBestModuleApiERK5QListINS_13ModuleApiInfoEERKN13LanguageUtils16ComponentVersionE
                                                       // in qmljslink.o
                                                       //__ZN5QmlJS11LinkPrivate20loadQmldirComponentsEPNS_11ObjectValueEN13LanguageUtils16ComponentVersionERKNS_11LibraryInfoERK7QString
                                                       // in qmljslink.o
                                                       //...
unimpl(
    _ZNK13LanguageUtils16ComponentVersion8toStringEv);  // ", referenced from:
                                                        //__ZN11QmlJSEditorL19inspectCppComponentEPKN5QmlJS17CppComponentValueE
                                                        // in qmljseditor.o
                                                        //__ZN5QmlJS11CppQmlTypes13qualifiedNameERK7QStringS3_N13LanguageUtils16ComponentVersionE
                                                        // in qmljsinterpreter.o
                                                        //__ZNK5QmlJS7Imports4dumpEv
                                                        // in qmljsinterpreter.o
                                                        //__ZN5QmlJS11LinkPrivate13importNonFileERK14QSharedPointerIKNS_8DocumentEERKNS_10ImportInfoE
                                                        // in qmljslink.o
                                                        //__ZN5QmlJS11LinkPrivate13importLibraryERK14QSharedPointerIKNS_8DocumentEERK7QStringPNS_6ImportEPNS_11ObjectValueES9_b
                                                        // in qmljslink.o
                                                        //__ZN5QmlJSL10modulePathERKNS_10ImportInfoERK11QStringList
                                                        // in
                                                        // qmljsmodelmanagerinterface.o
unimpl(
    _ZNK13LanguageUtils16ComponentVersion9addToHashER18QCryptographicHash);  // ", referenced from:
                                                                             //__ZNK5QmlJS13ModuleApiInfo9addToHashER18QCryptographicHash in qmljsdocument.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty10isWritableEv);  // ", referenced
                                                           // from:
                                                           //__ZNK5QmlJS17CppComponentValue10isWritableERK7QString
                                                           // in
                                                           // qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty4nameEv);  // ", referenced from:
                                                    //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                    // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty6isListEv);  // ", referenced from:
                                                      //__ZNK5QmlJS17CppComponentValue14isListPropertyERK7QString
                                                      // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty8revisionEv);  // ", referenced from:
                                                        //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                        // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty8typeNameEv);  // ", referenced from:
                                                        //__ZNK5QmlJS17CppComponentValue14processMembersEPNS_15MemberProcessorE
                                                        // in qmljsinterpreter.o
                                                        //__ZNK5QmlJS17CppComponentValue12propertyTypeERK7QString
                                                        // in qmljsinterpreter.o
unimpl(
    _ZNK13LanguageUtils16FakeMetaProperty9isPointerEv);  // ", referenced from:
                                                         //__ZNK5QmlJS17CppComponentValue9isPointerERK7QString
                                                         // in
                                                         // qmljsinterpreter.o
unimpl(
    _ZNK15ProjectExplorer10JsonWizard11stringValueERK7QString);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZN9QtSupport8Internal21TranslationWizardPage14updateLineEditEv
                                                                 // in
                                                                 // translationwizardpage.o
unimpl(
    _ZNK15ProjectExplorer15KitAspectWidget16kitInformationIdEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN15ProjectExplorer8Internal22KitManagerConfigWidget16updateVisibilityEv
                                                                  // in
                                                                  // kitmanagerconfigwidget.o
                                                                  //__ZN15ProjectExplorer8Internal13KitAreaWidget9updateKitEPNS_3KitE
                                                                  // in
                                                                  // miniprojecttargetselector.o
unimpl(
    _ZNK15ProjectExplorer8Internal17ProjectWizardPage11currentNodeEv);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN15ProjectExplorer8Internal26ProjectFileWizardExtension14processProjectERK5QListIN4Core13GeneratedFileEEPbP7QString
                                                                        // in
                                                                        // projectfilewizardextension.o
                                                                        //__ZNK15ProjectExplorer8Internal26ProjectFileWizardExtension14applyCodeStyleEPN4Core13GeneratedFileE
                                                                        // in
                                                                        // projectfilewizardextension.o
                                                                        //__ZZN15ProjectExplorer8Internal26ProjectFileWizardExtension23firstExtensionPageShownERK5QListIN4Core13GeneratedFileEERK4QMapI7QString8QVariantEENK3$_0clEv
                                                                        // in
                                                                        // projectfilewizardextension.o
unimpl(
    _ZNK15ProjectExplorer8Internal19SimpleProjectWizard13generateFilesEPK7QWizardP7QString);  // ", referenced from:
                                                                                              //__ZTVN15ProjectExplorer8Internal19SimpleProjectWizardE in moc_simpleprojectwizard.o
unimpl(
    _ZNK15ProjectExplorer8Internal19SimpleProjectWizard17postGenerateFilesEPK7QWizardRK5QListIN4Core13GeneratedFileEEP7QString);  // ", referenced from:
                                                                                                                                  //__ZTVN15ProjectExplorer8Internal19SimpleProjectWizardE in moc_simpleprojectwizard.o
unimpl(
    _ZNK15ProjectExplorer8Internal19SimpleProjectWizard6createEP7QWidgetRKN4Core22WizardDialogParametersE);  // ", referenced from:
                                                                                                             //__ZTVN15ProjectExplorer8Internal19SimpleProjectWizardE in moc_simpleprojectwizard.o
unimpl(
    _ZNK15ProjectExplorer8Internal22SessionNameInputDialog19isSwitchToRequestedEv);  // ", referenced from:
                                                                                     //__ZN15ProjectExplorer8Internal12SessionModel25runSessionNameInputDialogEPNS0_22SessionNameInputDialogENSt3__18functionIFvRK7QStringEEE in sessionmodel.o
unimpl(
    _ZNK15ProjectExplorer8Internal22SessionNameInputDialog5valueEv);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN15ProjectExplorer8Internal12SessionModel25runSessionNameInputDialogEPNS0_22SessionNameInputDialogENSt3__18functionIFvRK7QStringEEE
                                                                      // in
                                                                      // sessionmodel.o
unimpl(
    _ZNK15ProjectExplorer8Internal24CustomParserConfigDialog8settingsEv);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE_clEv
                                                                           // in
                                                                           // customparserssettingspage.o
                                                                           //__ZZN15ProjectExplorer8Internal27CustomParsersSettingsWidgetC1EvENKUlvE1_clEv
                                                                           // in
                                                                           // customparserssettingspage.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect16addToEnvironmentEPKNS_3KitERN5Utils11EnvironmentE);  // ", referenced from:
                                                                                          //__ZTVN8Debugger17DebuggerKitAspectE in moc_debuggerkitinformation.o
                                                                                          //__ZTVN15ProjectExplorer16SysRootKitAspectE in moc_kitinformation.o
                                                                                          //__ZTVN15ProjectExplorer19DeviceTypeKitAspectE in moc_kitinformation.o
                                                                                          //__ZTVN15ProjectExplorer15DeviceKitAspectE in moc_kitinformation.o
                                                                                          //__ZTVN15ProjectExplorer9KitAspectE in moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect17availableFeaturesEPKNS_3KitE);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN8Debugger17DebuggerKitAspectE
                                                                     // in
                                                                     // moc_debuggerkitinformation.o
                                                                     //__ZTVN15ProjectExplorer16SysRootKitAspectE
                                                                     // in
                                                                     // moc_kitinformation.o
                                                                     //__ZTVN15ProjectExplorer15DeviceKitAspectE
                                                                     // in
                                                                     // moc_kitinformation.o
                                                                     //__ZTVN15ProjectExplorer20EnvironmentKitAspectE
                                                                     // in
                                                                     // moc_kitinformation.o
                                                                     //__ZTVN15ProjectExplorer9KitAspectE
                                                                     // in
                                                                     // moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect18addToMacroExpanderEPNS_3KitEPN5Utils13MacroExpanderE);  // ", referenced from:
                                                                                             //__ZTVN15ProjectExplorer19DeviceTypeKitAspectE in moc_kitinformation.o
                                                                                             //__ZTVN15ProjectExplorer20EnvironmentKitAspectE in moc_kitinformation.o
                                                                                             //__ZTVN15ProjectExplorer9KitAspectE in moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect18displayNamePostfixEPKNS_3KitE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN8Debugger17DebuggerKitAspectE
                                                                      // in
                                                                      // moc_debuggerkitinformation.o
                                                                      //__ZTVN15ProjectExplorer16SysRootKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer19DeviceTypeKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer20EnvironmentKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer9KitAspectE
                                                                      // in
                                                                      // moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect18supportedPlatformsEPKNS_3KitE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN8Debugger17DebuggerKitAspectE
                                                                      // in
                                                                      // moc_debuggerkitinformation.o
                                                                      //__ZTVN15ProjectExplorer16SysRootKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer18ToolChainKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer15DeviceKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer20EnvironmentKitAspectE
                                                                      // in
                                                                      // moc_kitinformation.o
                                                                      //__ZTVN15ProjectExplorer9KitAspectE
                                                                      // in
                                                                      // moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect19createOutputParsersEPKNS_3KitE);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN8Debugger17DebuggerKitAspectE
                                                                       // in
                                                                       // moc_debuggerkitinformation.o
                                                                       //__ZTVN15ProjectExplorer16SysRootKitAspectE
                                                                       // in
                                                                       // moc_kitinformation.o
                                                                       //__ZTVN15ProjectExplorer19DeviceTypeKitAspectE
                                                                       // in
                                                                       // moc_kitinformation.o
                                                                       //__ZTVN15ProjectExplorer15DeviceKitAspectE
                                                                       // in
                                                                       // moc_kitinformation.o
                                                                       //__ZTVN15ProjectExplorer20EnvironmentKitAspectE
                                                                       // in
                                                                       // moc_kitinformation.o
                                                                       //__ZTVN15ProjectExplorer9KitAspectE
                                                                       // in
                                                                       // moc_kitmanager.o
unimpl(
    _ZNK15ProjectExplorer9KitAspect6weightEPKNS_3KitE);  // ", referenced from:
                                                         //__ZTVN8Debugger17DebuggerKitAspectE
                                                         // in
                                                         // moc_debuggerkitinformation.o
                                                         //__ZTVN15ProjectExplorer16SysRootKitAspectE
                                                         // in
                                                         // moc_kitinformation.o
                                                         //__ZTVN15ProjectExplorer18ToolChainKitAspectE
                                                         // in
                                                         // moc_kitinformation.o
                                                         //__ZTVN15ProjectExplorer19DeviceTypeKitAspectE
                                                         // in
                                                         // moc_kitinformation.o
                                                         //__ZTVN15ProjectExplorer15DeviceKitAspectE
                                                         // in
                                                         // moc_kitinformation.o
                                                         //__ZTVN15ProjectExplorer20EnvironmentKitAspectE
                                                         // in
                                                         // moc_kitinformation.o
                                                         //__ZTVN15ProjectExplorer9KitAspectE
                                                         // in moc_kitmanager.o
                                                         //...
unimpl(
    _ZNK19KSyntaxHighlighting10Definition4nameEv);  // ", referenced from:
                                                    //__ZN10TextEditor11Highlighter29rememberDefinitionForDocumentERKN19KSyntaxHighlighting10DefinitionEPKNS_12TextDocumentE
                                                    // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting10Definition7isValidEv);  // ", referenced from:
                                                       //__ZN10TextEditor11Highlighter22definitionsForFileNameERKN5Utils8FilePathE
                                                       // in highlighter.o
                                                       //__ZN10TextEditor11Highlighter22definitionsForMimeTypeERK7QString
                                                       // in highlighter.o
                                                       //__ZN10TextEditor11Highlighter29rememberDefinitionForDocumentERKN19KSyntaxHighlighting10DefinitionEPKNS_12TextDocumentE
                                                       // in highlighter.o
                                                       //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                                       // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting10DefinitioneqERKS0_);  // ", referenced from:
                                                     //__ZNK5QListIN19KSyntaxHighlighting10DefinitionEE13contains_implERKS1_N9QListData24NotArrayCompatibleLayoutE
                                                     // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting10Repository17definitionForNameERK7QString);  // ",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN10TextEditor11Highlighter17definitionForNameERK7QString
                                                                           // in
                                                                           // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting10Repository22definitionsForFileNameERK7QString);  // ", referenced from:
                                                                                //__ZN10TextEditor11Highlighter22definitionsForFileNameERKN5Utils8FilePathE in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting10Repository22definitionsForMimeTypeERK7QString);  // ", referenced from:
                                                                                //__ZN10TextEditor11Highlighter22definitionsForMimeTypeERK7QString in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting13FoldingRegion4typeEv);  // ", referenced from:
                                                       //__ZN10TextEditor11Highlighter12applyFoldingEiiN19KSyntaxHighlighting13FoldingRegionE
                                                       // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting13FoldingRegion7isValidEv);  // ", referenced from:
                                                          //__ZN10TextEditor11Highlighter12applyFoldingEiiN19KSyntaxHighlighting13FoldingRegionE
                                                          // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting19AbstractHighlighter10definitionEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                                                    // in
                                                                    // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting5StateneERKS0_);  // ", referenced from:
                                               //__ZN10TextEditor11Highlighter14highlightBlockERK7QString
                                               // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format11isUnderlineERKNS_5ThemeE);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                                  // in
                                                                  // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format12hasTextColorERKNS_5ThemeE);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                                   // in
                                                                   // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format15isStrikeThroughERKNS_5ThemeE);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                                      // in
                                                                      // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format18hasBackgroundColorERKNS_5ThemeE);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                                         // in
                                                                         // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format6isBoldERKNS_5ThemeE);  // ", referenced
                                                            // from:
                                                            //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                            // in highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format8isItalicERKNS_5ThemeE);  // ", referenced
                                                              // from:
                                                              //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                              // in
                                                              // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format9textColorERKNS_5ThemeE);  // ", referenced
                                                               // from:
                                                               //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                               // in
                                                               // highlighter.o
unimpl(
    _ZNK19KSyntaxHighlighting6Format9textStyleEv);  // ", referenced from:
                                                    //__ZN10TextEditor11Highlighter11applyFormatEiiRKN19KSyntaxHighlighting6FormatE
                                                    // in highlighter.o
unimpl(
    _ZNK4Core11IFindFilter15defaultShortcutEv);  // ", referenced from:
                                                 //__ZTVN10TextEditor11FindInFilesE
                                                 // in moc_findinfiles.o
                                                 //__ZTVN10TextEditor12BaseFileFindE
                                                 // in moc_basefilefind.o
                                                 //__ZTVN10TextEditor8Internal17FindInCurrentFileE
                                                 // in moc_findincurrentfile.o
                                                 //__ZTVN10TextEditor8Internal15FindInOpenFilesE
                                                 // in moc_findinopenfiles.o
                                                 //__ZTVN8CppTools8Internal17SymbolsFindFilterE
                                                 // in moc_symbolsfindfilter.o
                                                 //__ZTVN15ProjectExplorer8Internal15AllProjectsFindE
                                                 // in moc_allprojectsfind.o
                                                 //__ZTVN15ProjectExplorer8Internal18CurrentProjectFindE
                                                 // in moc_currentprojectfind.o
                                                 //...
unimpl(
    _ZNK4Core11IFindFilter18supportedFindFlagsEv);  // ", referenced from:
                                                    //__ZTVN10TextEditor11FindInFilesE
                                                    // in moc_findinfiles.o
                                                    //__ZTVN10TextEditor12BaseFileFindE
                                                    // in moc_basefilefind.o
                                                    //__ZTVN10TextEditor8Internal17FindInCurrentFileE
                                                    // in
                                                    // moc_findincurrentfile.o
                                                    //__ZTVN10TextEditor8Internal15FindInOpenFilesE
                                                    // in moc_findinopenfiles.o
                                                    //__ZTVN8CppTools8Internal17SymbolsFindFilterE
                                                    // in
                                                    // moc_symbolsfindfilter.o
                                                    //__ZTVN15ProjectExplorer8Internal15AllProjectsFindE
                                                    // in moc_allprojectsfind.o
                                                    //__ZTVN15ProjectExplorer8Internal18CurrentProjectFindE
                                                    // in
                                                    // moc_currentprojectfind.o
                                                    //...
unimpl(
    _ZNK4Core12ItemViewFind10metaObjectEv);  // ", referenced from:
                                             //__ZTVN9CppEditor8Internal13IncludeFinderE
                                             // in cppincludehierarchy.o
unimpl(
    _ZNK4Core12ItemViewFind15supportsReplaceEv);  // ", referenced from:
                                                  //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                  // in cppincludehierarchy.o
unimpl(
    _ZNK4Core12ItemViewFind17currentFindStringEv);  // ", referenced from:
                                                    //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                    // in cppincludehierarchy.o
unimpl(
    _ZNK4Core12ItemViewFind18supportedFindFlagsEv);  // ", referenced from:
                                                     //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                     // in cppincludehierarchy.o
unimpl(
    _ZNK4Core12ItemViewFind19completedFindStringEv);  // ", referenced from:
                                                      //__ZTVN9CppEditor8Internal13IncludeFinderE
                                                      // in
                                                      // cppincludehierarchy.o
unimpl(
    _ZNK4Core12SearchResult23additionalReplaceWidgetEv);  // ", referenced from:
                                                          //__ZN8CppTools8Internal17CppFindReferences22onReplaceButtonClickedERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                                          // in
                                                          // cppfindreferences.o
                                                          //__ZL14searchFinishedPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEE
                                                          // in
                                                          // cppfindreferences.o
unimpl(
    _ZNK4Core12SearchResult8userDataEv);  // ", referenced from:
                                          //__ZN10TextEditor12BaseFileFind9runSearchEPN4Core12SearchResultE
                                          // in basefilefind.o
                                          //__ZN10TextEditor12BaseFileFind10openEditorEPN4Core12SearchResultERKNS1_16SearchResultItemE
                                          // in basefilefind.o
                                          //__ZN10TextEditor12BaseFileFind23getAdditionalParametersEPN4Core12SearchResultE
                                          // in basefilefind.o
                                          //__ZN8CppTools8Internal17CppFindReferences22onReplaceButtonClickedERK7QStringRK5QListIN4Core16SearchResultItemEEb
                                          // in cppfindreferences.o
                                          //__ZN8CppTools8Internal17CppFindReferences11searchAgainEv
                                          // in cppfindreferences.o
                                          //__ZL14searchFinishedPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEE
                                          // in cppfindreferences.o
                                          //__ZL14displayResultsPN4Core12SearchResultEP14QFutureWatcherIN9CPlusPlus5UsageEEii
                                          // in cppfindreferences.o
                                          //...
unimpl(
    _ZNK4Core14BaseFileFilter6acceptENS_18LocatorFilterEntryEP7QStringPiS4_);  // ", referenced from:
                                                                               //__ZTVN8CppTools8Internal17CppIncludesFilterE in moc_cppincludesfilter.o
                                                                               //__ZTVN15ProjectExplorer8Internal17AllProjectsFilterE in moc_allprojectsfilter.o
                                                                               //__ZTVN15ProjectExplorer8Internal20CurrentProjectFilterE in moc_currentprojectfilter.o
unimpl(
    _ZNK4Core14ILocatorFilter14shortcutStringEv);  // ", referenced from:
                                                   //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_6clEPNS_16TextEditorWidgetE
                                                   // in
                                                   // texteditoractionhandler.o
unimpl(
    _ZNK4Core14ILocatorFilter9saveStateEv);  // ", referenced from:
                                             //__ZTVN4Core8Internal13MenuBarFilterE
                                             // in moc_menubarfilter.o
                                             //__ZTVN10TextEditor8Internal16LineNumberFilterE
                                             // in moc_linenumberfilter.o
                                             //__ZTVN8CppTools16CppClassesFilterE
                                             // in moc_cppclassesfilter.o
                                             //__ZTVN8CppTools8Internal24CppCurrentDocumentFilterE
                                             // in
                                             // moc_cppcurrentdocumentfilter.o
                                             //__ZTVN8CppTools8Internal18CppFunctionsFilterE
                                             // in moc_cppfunctionsfilter.o
                                             //__ZTVN8CppTools8Internal17CppIncludesFilterE
                                             // in moc_cppincludesfilter.o
                                             //__ZTVN8CppTools8Internal16CppLocatorFilterE
                                             // in moc_cpplocatorfilter.o
                                             //...
unimpl(
    _ZNK4Core16BaseTextDocument15supportsUtf8BomEv);  // ", referenced from:
                                                      //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                                      // in textdocument.o
                                                      //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                                      // in textdocument.o
unimpl(
    _ZNK4Core16BaseTextDocument16hasDecodingErrorEv);  // ", referenced from:
                                                       //__ZN4Core13CodecSelectorC2EP7QWidgetPNS_16BaseTextDocumentE
                                                       // in codecselector.o
                                                       //__ZN10DiffEditor8Internal26DiffEditorWidgetController22updateCannotDecodeInfoEv
                                                       // in
                                                       // diffeditorwidgetcontroller.o
unimpl(
    _ZNK4Core16BaseTextDocument19decodingErrorSampleEv);  // ", referenced from:
                                                          //__ZN4Core13CodecSelectorC2EP7QWidgetPNS_16BaseTextDocumentE
                                                          // in codecselector.o
unimpl(
    _ZNK4Core16BaseTextDocument5codecEv);  // ", referenced from:
                                           //__ZN10TextEditor12TextDocument27openedTextDocumentEncodingsEv
                                           // in textdocument.o
                                           //__ZN4Core13CodecSelectorC2EP7QWidgetPNS_16BaseTextDocumentE
                                           // in codecselector.o
                                           //__ZN10TextEditor12TextDocument27openedTextDocumentEncodingsEv
                                           // in textdocument.o
                                           //__ZNK7VcsBase19VcsBaseEditorWidget5codecEv
                                           // in vcsbaseeditor.o
                                           //__ZNK7VcsBase19VcsBaseEditorWidget9diffChunkE11QTextCursor
                                           // in vcsbaseeditor.o
                                           //__ZN7VcsBaseL13findFileCodecERK7QString
                                           // in vcsbaseeditor.o
                                           //__ZN10DiffEditor8Internal26DiffEditorWidgetController22updateCannotDecodeInfoEv
                                           // in diffeditorwidgetcontroller.o
                                           //...
unimpl(
    _ZNK4Core16BaseTextDocument5writeERK7QStringRKN5Utils14TextFileFormatES3_PS1_);  // ", referenced from:
                                                                                     //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b in textdocument.o
                                                                                     //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b in textdocument.o
                                                                                     //__ZN10DiffEditor8Internal18DiffEditorDocument4saveEP7QStringRKS2_b in diffeditordocument.o
unimpl(
    _ZNK4Core16BaseTextDocument6formatEv);  // ", referenced from:
                                            //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                            // in textdocument.o
                                            //__ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b
                                            // in textdocument.o
                                            //__ZN10DiffEditor8Internal18DiffEditorDocument4saveEP7QStringRKS2_b
                                            // in diffeditordocument.o
                                            //__ZNK10DiffEditor8Internal25DiffCurrentFileController15reloadInputListEv
                                            // in diffeditorplugin.o
                                            //__ZNK10DiffEditor8Internal23DiffOpenFilesController15reloadInputListEv
                                            // in diffeditorplugin.o
                                            //__ZNK10DiffEditor8Internal27DiffModifiedFilesController15reloadInputListEv
                                            // in diffeditorplugin.o
unimpl(
    _ZNK4Core7Command32augmentActionWithShortcutToolTipEP7QAction);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZN5Utils11Perspective25registerNextPrevShortcutsEP7QActionS2_
                                                                     // in
                                                                     // debuggermainwindow.o
unimpl(
    _ZNK4Core8Internal10MainWindow13contextObjectEP7QWidget);  // ", referenced
                                                               // from:
                                                               //__ZN4Core5ICore13contextObjectEP7QWidget
                                                               // in icore.o
unimpl(
    _ZNK4Core8Internal10MainWindow20currentContextObjectEv);  // ", referenced
                                                              // from:
                                                              //__ZN4Core5ICore20currentContextObjectEv
                                                              // in icore.o
unimpl(
    _ZNK4Core8Internal10MainWindow26additionalAboutInformationEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN4Core5ICore26additionalAboutInformationEv
                                                                    // in
                                                                    // icore.o
unimpl(_ZNK4Core8Internal10MainWindow7infoBarEv);  // ", referenced from:
                                                   //__ZN4Core5ICore7infoBarEv
                                                   // in icore.o
unimpl(
    _ZNK4Core8Internal10MainWindow9statusBarEv);  // ", referenced from:
                                                  //__ZN4Core5ICore9statusBarEv
                                                  // in icore.o
unimpl(
    _ZNK4Core8Internal6Action11descriptionEv);  // ", referenced from:
                                                //__ZTVN4Core8Internal6ActionE
                                                // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action11keySequenceEv);  // ", referenced from:
                                                //__ZTVN4Core8Internal6ActionE
                                                // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12hasAttributeENS_7Command16CommandAttributeE);  // ", referenced from:
                                                                              //__ZTVN4Core8Internal6ActionE in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12isScriptableERKNS_7ContextE);  // ", referenced
                                                              // from:
                                                              //__ZTVN4Core8Internal6ActionE
                                                              // in
                                                              // moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12isScriptableEv);  // ", referenced from:
                                                 //__ZTVN4Core8Internal6ActionE
                                                 // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12keySequencesEv);  // ", referenced from:
                                                 //__ZTVN4Core8Internal6ActionE
                                                 // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12touchBarIconEv);  // ", referenced from:
                                                 //__ZTVN4Core8Internal6ActionE
                                                 // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action12touchBarTextEv);  // ", referenced from:
                                                 //__ZTVN4Core8Internal6ActionE
                                                 // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action14touchBarActionEv);  // ", referenced from:
                                                   //__ZTVN4Core8Internal6ActionE
                                                   // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action19defaultKeySequencesEv);  // ", referenced from:
                                                        //__ZTVN4Core8Internal6ActionE
                                                        // in moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action26stringWithAppendedShortcutERK7QString);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZTVN4Core8Internal6ActionE
                                                                        // in
                                                                        // moc_command_p.o
unimpl(_ZNK4Core8Internal6Action2idEv);       // ", referenced from:
                                              //__ZTVN4Core8Internal6ActionE in
                                              // moc_command_p.o
unimpl(_ZNK4Core8Internal6Action6actionEv);   // ", referenced from:
                                              //__ZTVN4Core8Internal6ActionE in
                                              // moc_command_p.o
unimpl(_ZNK4Core8Internal6Action7contextEv);  // ", referenced from:
                                              //__ZTVN4Core8Internal6ActionE in
                                              // moc_command_p.o
unimpl(
    _ZNK4Core8Internal6Action7isEmptyEv);  // ", referenced from:
                                           //__ZN4Core13ActionManager16unregisterActionEP7QActionN5Utils2IdE
                                           // in actionmanager.o
unimpl(_ZNK4Core8Internal6Action8isActiveEv);  // ", referenced from:
                                               //__ZTVN4Core8Internal6ActionE in
                                               // moc_command_p.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget10commitNameEv);  // ", referenced from:
                                                      //__ZTVN7VcsBase18SubmitEditorWidgetE
                                                      // in
                                                      // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget12checkedFilesEv);  // ", referenced from:
                                                        //__ZNK7VcsBase19VcsBaseSubmitEditor12checkedFilesEv
                                                        // in
                                                        // vcsbasesubmiteditor.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget12selectedRowsEv);  // ", referenced from:
                                                        //__ZN7VcsBase19VcsBaseSubmitEditor12setFileModelEPNS_15SubmitFileModelE
                                                        // in
                                                        // vcsbasesubmiteditor.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget13lineWrapWidthEv);  // ", referenced from:
                                                         //__ZNK7VcsBase19VcsBaseSubmitEditor13lineWrapWidthEv
                                                         // in
                                                         // vcsbasesubmiteditor.o
                                                         //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                         // in
                                                         // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget15descriptionEditEv);  // ", referenced
                                                           // from:
                                                           //__ZN7VcsBase26VcsBaseSubmitEditorPrivateC2EPNS_18SubmitEditorWidgetEPNS_19VcsBaseSubmitEditorE
                                                           // in
                                                           // vcsbasesubmiteditor.o
                                                           //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE
                                                           // in
                                                           // vcsbasesubmiteditor.o
                                                           //__ZN7VcsBase19VcsBaseSubmitEditor18slotInsertNickNameEv
                                                           // in
                                                           // vcsbasesubmiteditor.o
                                                           //__ZN7VcsBase19VcsBaseSubmitEditor12setFileModelEPNS_15SubmitFileModelE
                                                           // in
                                                           // vcsbasesubmiteditor.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget15descriptionTextEv);  // ", referenced
                                                           // from:
                                                           //__ZNK7VcsBase19VcsBaseSubmitEditor11descriptionEv
                                                           // in
                                                           // vcsbasesubmiteditor.o
                                                           //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                           // in
                                                           // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget18cleanupDescriptionERK7QString);  // ",
                                                                       // referenced
                                                                       // from:
                                                                       //__ZTVN7VcsBase18SubmitEditorWidgetE
                                                                       // in
                                                                       // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget18submitFieldWidgetsEv);  // ", referenced
                                                              // from:
                                                              //__ZN7VcsBase19VcsBaseSubmitEditor20slotSetFieldNickNameEi
                                                              // in
                                                              // vcsbasesubmiteditor.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget21fileListSelectionModeEv);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZNK7VcsBase19VcsBaseSubmitEditor21fileListSelectionModeEv
                                                                 // in
                                                                 // vcsbasesubmiteditor.o
                                                                 //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                 // in
                                                                 // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget22isDescriptionMandatoryEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZNK7VcsBase19VcsBaseSubmitEditor22isDescriptionMandatoryEv
                                                                  // in
                                                                  // vcsbasesubmiteditor.o
                                                                  //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                  // in
                                                                  // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget22isEmptyFileListEnabledEv);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZNK7VcsBase19VcsBaseSubmitEditor22isEmptyFileListEnabledEv
                                                                  // in
                                                                  // vcsbasesubmiteditor.o
                                                                  //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                                  // in
                                                                  // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget8lineWrapEv);  // ", referenced from:
                                                   //__ZNK7VcsBase19VcsBaseSubmitEditor8lineWrapEv
                                                   // in vcsbasesubmiteditor.o
                                                   //__ZN7VcsBase18SubmitEditorWidget18qt_static_metacallEP7QObjectN11QMetaObject4CallEiPPv
                                                   // in
                                                   // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget9canSubmitEP7QString);  // ", referenced
                                                            // from:
                                                            //__ZTVN7VcsBase18SubmitEditorWidgetE
                                                            // in
                                                            // moc_submiteditorwidget.o
unimpl(
    _ZNK7VcsBase18SubmitEditorWidget9fileModelEv);  // ", referenced from:
                                                    //__ZN7VcsBase19VcsBaseSubmitEditor12setFileModelEPNS_15SubmitFileModelE
                                                    // in vcsbasesubmiteditor.o
                                                    //__ZNK7VcsBase19VcsBaseSubmitEditor9fileModelEv
                                                    // in vcsbasesubmiteditor.o
unimpl(
    _ZNK7VcsBase8Internal14NickNameDialog8nickNameEv);  // ", referenced from:
                                                        //__ZN7VcsBase19VcsBaseSubmitEditor17promptForNickNameEv
                                                        // in
                                                        // vcsbasesubmiteditor.o
unimpl(
    _ZNK8CppTools28ClangDiagnosticConfigsWidget13currentConfigEv);  // ",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZN8CppTools37ClangDiagnosticConfigsSelectionWidget15onButtonClickedEv
                                                                    // in
                                                                    // clangdiagnosticconfigsselectionwidget.o
unimpl(
    _ZNK8CppTools28ClangDiagnosticConfigsWidget7configsEv);  // ", referenced
                                                             // from:
                                                             //__ZN8CppTools37ClangDiagnosticConfigsSelectionWidget15onButtonClickedEv
                                                             // in
                                                             // clangdiagnosticconfigsselectionwidget.o
unimpl(
    _ZNK9CppEditor8Internal21CppPreProcessorDialog27extraPreprocessorDirectivesEv);  // ", referenced from:
                                                                                     //__ZN9CppEditor8Internal15CppEditorWidget22showPreProcessorWidgetEv in cppeditorwidget.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion10hasQmlDumpEv);  // ", referenced from:
                                                   //__ZN9QtSupport11QmlDumpTool18pathAndEnvironmentEPKN15ProjectExplorer3KitEbP7QStringPN5Utils11EnvironmentE
                                                   // in qmldumptool.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion10uicCommandEv);  // ", referenced from:
                                                   //__ZNK9QtSupport12UicGenerator7commandEv
                                                   // in uicgenerator.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion11displayNameEv);  // ", referenced from:
                                                    //__ZZNK9QtSupport17QtProjectImporter18createTemporaryKitERKNS0_13QtVersionDataERKNSt3__18functionIFvPN15ProjectExplorer3KitEEEEENK3$_2clES8_
                                                    // in qtprojectimporter.o
                                                    //__ZNK9QtSupport11QtKitAspect18displayNamePostfixEPKN15ProjectExplorer3KitE
                                                    // in qtkitinformation.o
                                                    //__ZNK9QtSupport11QtKitAspect12toUserOutputEPKN15ProjectExplorer3KitE
                                                    // in qtkitinformation.o
                                                    //__ZN9QtSupport8Internal17QtKitAspectWidget11itemNameForEPKNS_13BaseQtVersionE
                                                    // in qtkitinformation.o
                                                    //__ZZNK9QtSupport11QtKitAspect18addToMacroExpanderEPN15ProjectExplorer3KitEPN5Utils13MacroExpanderEENK3$_6clEv
                                                    // in qtkitinformation.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion11hostBinPathEv);  // ", referenced from:
                                                    //__ZZN9QtSupport8Internal15QtSupportPlugin21extensionsInitializedEvENK3$_0clEv
                                                    // in qtsupportplugin.o
                                                    //__ZZN9QtSupport8Internal15QtSupportPlugin21extensionsInitializedEvENK3$_2clEv
                                                    // in qtsupportplugin.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion12qmakeCommandEv);  // ", referenced from:
                                                     //__ZNK9QtSupport17QtProjectImporter21findOrCreateQtVersionERKN5Utils8FilePathE
                                                     // in qtprojectimporter.o
                                                     //__ZZNK9QtSupport11QtKitAspect18addToMacroExpanderEPN15ProjectExplorer3KitEPN5Utils13MacroExpanderEENK3$_7clEv
                                                     // in qtkitinformation.o
                                                     //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                     // in qtversionmanager.o
                                                     //__ZZN9QtSupportL12findSystemQtEvENK3$_5clEPKNS_13BaseQtVersionE
                                                     // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion14isAutodetectedEv);  // ", referenced from:
                                                       //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                       // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion14qscxmlcCommandEv);  // ", referenced from:
                                                       //__ZNK9QtSupport16QScxmlcGenerator7commandEv
                                                       // in qscxmlcgenerator.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion19autodetectionSourceEv);  // ", referenced
                                                            // from:
                                                            //__ZN9QtSupport11QtKitAspect5setupEPN15ProjectExplorer3KitE
                                                            // in
                                                            // qtkitinformation.o
                                                            //__ZZN9QtSupport11QtKitAspect11qtVersionIdEPKN15ProjectExplorer3KitEENK3$_8clEPKNS_13BaseQtVersionE
                                                            // in
                                                            // qtkitinformation.o
                                                            //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                            // in
                                                            // qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion19qtPackageSourcePathEv);  // ", referenced
                                                            // from:
                                                            //__ZN8Debugger15DebuggerRunToolC2EPN15ProjectExplorer10RunControlENS0_13AllowTerminalE
                                                            // in
                                                            // debuggerruncontrol.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion21unexpandedDisplayNameEv);  // ", referenced
                                                              // from:
                                                              //__ZN9QtSupport16QtVersionManager19updateFromInstallerEb
                                                              // in
                                                              // qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion4typeEv);  // ", referenced from:
                                            //__ZN9QtSupportL14saveQtVersionsEv
                                            // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion6mkspecEv);  // ", referenced from:
                                              //__ZN9QtSupport11QtKitAspect3fixEPN15ProjectExplorer3KitE
                                              // in qtkitinformation.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion6qtAbisEv);  // ", referenced from:
                                              //__ZNK9QtSupport11QtKitAspect6weightEPKN15ProjectExplorer3KitE
                                              // in qtkitinformation.o
                                              //__ZZN9QtSupport11QtKitAspect5setupEPN15ProjectExplorer3KitEENK3$_0clEPKNS_13BaseQtVersionE
                                              // in qtkitinformation.o
                                              //__ZZN9QtSupport11QtKitAspect5setupEPN15ProjectExplorer3KitEENK3$_1clEPKNS_13BaseQtVersionE
                                              // in qtkitinformation.o
                                              //__ZZN9QtSupport11QtKitAspect3fixEPN15ProjectExplorer3KitEENK3$_2clEPKNS1_9ToolChainE
                                              // in qtkitinformation.o
                                              //__ZZN9QtSupport11QtKitAspect3fixEPN15ProjectExplorer3KitEENK3$_3clEPKNS1_9ToolChainES7_
                                              // in qtkitinformation.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion7binPathEv);  // ", referenced from:
                                               //__ZZN9QtSupport8Internal15QtSupportPlugin21extensionsInitializedEvENK3$_1clEv
                                               // in qtsupportplugin.o
                                               //__ZZN9QtSupport8Internal15QtSupportPlugin21extensionsInitializedEvENK3$_3clEv
                                               // in qtsupportplugin.o
                                               //__ZN9QtSupport11QmlDumpTool14toolForVersionEPKNS_13BaseQtVersionEb
                                               // in qmldumptool.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion8docsPathEv);  // ", referenced from:
                                                //__ZN9QtSupportL18documentationFilesEPNS_13BaseQtVersionE
                                                // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion8featuresEv);  // ", referenced from:
                                                //__ZNK9QtSupport11QtKitAspect17availableFeaturesEPKN15ProjectExplorer3KitE
                                                // in qtkitinformation.o
                                                //__ZZN9QtSupport11QtKitAspect18qtVersionPredicateERK4QSetIN5Utils2IdEERKNS_15QtVersionNumberES9_ENK4$_10clEPKN15ProjectExplorer3KitE
                                                // in qtkitinformation.o
unimpl(
    _ZNK9QtSupport13BaseQtVersion8uniqueIdEv);  // ", referenced from:
                                                //__ZNK9QtSupport17QtProjectImporter21findOrCreateQtVersionERKN5Utils8FilePathE
                                                // in qtprojectimporter.o
                                                //__ZZNK9QtSupport17QtProjectImporter18createTemporaryKitERKNS0_13QtVersionDataERKNSt3__18functionIFvPN15ProjectExplorer3KitEEEEENK3$_2clES8_
                                                // in qtprojectimporter.o
                                                //__ZN9QtSupport11QtKitAspect5setupEPN15ProjectExplorer3KitE
                                                // in qtkitinformation.o
                                                //__ZN9QtSupport11QtKitAspect11qtVersionIdEPKN15ProjectExplorer3KitE
                                                // in qtkitinformation.o
                                                //__ZN9QtSupport11QtKitAspect12setQtVersionEPN15ProjectExplorer3KitEPKNS_13BaseQtVersionE
                                                // in qtkitinformation.o
                                                //__ZN9QtSupport8Internal17QtKitAspectWidgetC2EPN15ProjectExplorer3KitEPKNS2_9KitAspectE
                                                // in qtkitinformation.o
                                                //__ZN9QtSupport22qtVersionNumberCompareEPNS_13BaseQtVersionES1_
                                                // in qtversionmanager.o
                                                //...
unimpl(
    _ZNK9QtSupport13BaseQtVersion9qtVersionEv);  // ", referenced from:
                                                 //__ZN9QtSupport10CppKitInfoC2EPN15ProjectExplorer3KitE
                                                 // in qtcppkitinfo.o
                                                 //__ZZN9QtSupport11QtKitAspect18qtVersionPredicateERK4QSetIN5Utils2IdEERKNS_15QtVersionNumberES9_ENK4$_10clEPKN15ProjectExplorer3KitE
                                                 // in qtkitinformation.o
                                                 //__ZN9QtSupport22qtVersionNumberCompareEPNS_13BaseQtVersionES1_
                                                 // in qtversionmanager.o
                                                 //__ZN9QtSupportL18documentationFilesERK5QListIPNS_13BaseQtVersionEEb
                                                 // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport15QtVersionNumbereqERKS0_);  // ", referenced from:
                                               //__ZN9QtSupport22qtVersionNumberCompareEPNS_13BaseQtVersionES1_
                                               // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport15QtVersionNumbergtERKS0_);  // ", referenced from:
                                               //__ZZN9QtSupport11QtKitAspect18qtVersionPredicateERK4QSetIN5Utils2IdEERKNS_15QtVersionNumberES9_ENK4$_10clEPKN15ProjectExplorer3KitE
                                               // in qtkitinformation.o
                                               //__ZN9QtSupport22qtVersionNumberCompareEPNS_13BaseQtVersionES1_
                                               // in qtversionmanager.o
unimpl(
    _ZNK9QtSupport15QtVersionNumberltERKS0_);  // ", referenced from:
                                               //__ZN9QtSupport10CppKitInfoC2EPN15ProjectExplorer3KitE
                                               // in qtcppkitinfo.o
                                               //__ZZN9QtSupport11QtKitAspect18qtVersionPredicateERK4QSetIN5Utils2IdEERKNS_15QtVersionNumberES9_ENK4$_10clEPKN15ProjectExplorer3KitE
                                               // in qtkitinformation.o
unimpl(
    _ZNK9QtSupport8Internal17ExamplesListModel31fetchPixmapAndUpdatePixmapCacheERK7QString);  // ", referenced from:
                                                                                              //__ZTVN9QtSupport8Internal17ExamplesListModelE in moc_exampleslistmodel.o
unimpl(
    _ZNK9QtSupport8Internal17ExamplesListModel4dataERK11QModelIndexi);  // ",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZTVN9QtSupport8Internal17ExamplesListModelE
                                                                        // in
                                                                        // moc_exampleslistmodel.o
unimpl(
    _ZTIN10TextEditor17TextEditorFactoryE);  // ", referenced from:
                                             //__ZTIN10TextEditor22PlainTextEditorFactoryE
                                             // in plaintexteditorfactory.o
                                             //__ZTIN9CppEditor8Internal16CppEditorFactoryE
                                             // in cppeditorplugin.o
                                             //__ZTIN11QmlJSEditor18QmlJSEditorFactoryE
                                             // in qmljseditor.o
                                             //__ZTIN7VcsBase16VcsEditorFactoryE
                                             // in basevcseditorfactory.o
unimpl(
    _ZTIN15ProjectExplorer21JsonWizardPageFactoryE);  // ", referenced from:
                                                      //__ZTIN9QtSupport8Internal28TranslationWizardPageFactoryE
                                                      // in
                                                      // translationwizardpage.o
                                                      //__ZTIN7VcsBase8Internal27VcsConfigurationPageFactoryE
                                                      // in
                                                      // vcsconfigurationpage.o
                                                      //__ZTIN7VcsBase8Internal21VcsCommandPageFactoryE
                                                      // in vcscommandpage.o
unimpl(
    _ZTIN19KSyntaxHighlighting19AbstractHighlighterE);  // ", referenced from:
                                                        //__ZTIN10TextEditor11HighlighterE
                                                        // in moc_highlighter.o
unimpl(
    _ZTIN4Core11IFindFilterE);  // ", referenced from:
                                //__ZTIN10TextEditor12BaseFileFindE in
                                // moc_basefilefind.o
                                //__ZTIN8CppTools8Internal17SymbolsFindFilterE
                                // in moc_symbolsfindfilter.o
unimpl(_ZTIN4Core12IFindSupportE);  // ", referenced from:
                                    //__ZTIN9BinEditor8Internal13BinEditorFindE
                                    // in bineditorplugin.o
unimpl(_ZTIN4Core12ItemViewFindE);  // ", referenced from:
                                    //__ZTIN9CppEditor8Internal13IncludeFinderE
                                    // in cppincludehierarchy.o
unimpl(_ZTIN4Core12ShellCommandE);  // ", referenced from:
                                    //__ZTIN7VcsBase10VcsCommandE in
                                    // moc_vcscommand.o
unimpl(
    _ZTIN4Core14BaseFileFilter8IteratorE);  // ", referenced from:
                                            //__ZTIN8CppTools8Internal19CppIncludesIteratorE
                                            // in cppincludesfilter.o
unimpl(
    _ZTIN4Core14BaseFileFilterE);  // ", referenced from:
                                   //__ZTIN8CppTools8Internal17CppIncludesFilterE
                                   // in moc_cppincludesfilter.o
                                   //__ZTIN15ProjectExplorer8Internal17AllProjectsFilterE
                                   // in moc_allprojectsfilter.o
                                   //__ZTIN15ProjectExplorer8Internal20CurrentProjectFilterE
                                   // in moc_currentprojectfilter.o
unimpl(
    _ZTIN4Core14ILocatorFilterE);  // ", referenced from:
                                   //__ZTIN4Core8Internal13MenuBarFilterE in
                                   // moc_menubarfilter.o
                                   //__ZTIN10TextEditor8Internal16LineNumberFilterE
                                   // in moc_linenumberfilter.o
                                   //__ZTIN8CppTools8Internal24CppCurrentDocumentFilterE
                                   // in moc_cppcurrentdocumentfilter.o
                                   //__ZTIN8CppTools8Internal16CppLocatorFilterE
                                   // in moc_cpplocatorfilter.o
unimpl(
    _ZTIN4Core16BaseTextDocumentE);  // ", referenced from:
                                     //__ZTIN10TextEditor12TextDocumentE in
                                     // moc_textdocument.o
                                     //__ZTIN10DiffEditor8Internal18DiffEditorDocumentE
                                     // in moc_diffeditordocument.o
unimpl(
    _ZTVN15ProjectExplorer21JsonWizardPageFactoryE);  // ", referenced from:
                                                      //__ZN15ProjectExplorer21JsonWizardPageFactoryC2Ev
                                                      // in
                                                      // translationwizardpage.o
                                                      //__ZN15ProjectExplorer21JsonWizardPageFactoryC2Ev
                                                      // in
                                                      // vcsconfigurationpage.o
                                                      //__ZN15ProjectExplorer21JsonWizardPageFactoryC2Ev
                                                      // in vcscommandpage.o
// NOTE: a missing vtable usually means the first non-inline virtual member
// function has no definition.
unimpl(_ZTVN4Core12IFindSupportE);  // ", referenced from:
                                    //__ZN4Core12IFindSupportC2Ev in
                                    // bineditorplugin.o
// NOTE: a missing vtable usually means the first non-inline virtual member
// function has no definition.
unimpl(
    _ZTVN4Core12ShellCommandE);  // ", referenced from:
                                 //__ZN4Core12ShellCommandD2Ev in
                                 // vcsbaseplugin.o
                                 //__ZN4Core12ShellCommandD2Ev in vcscommand.o
                                 //__ZN4Core12ShellCommandD2Ev in
                                 // vcsbaseclient.o
                                 //__ZN4Core12ShellCommandD2Ev in
                                 // moc_vcscommand.o
// NOTE: a missing vtable usually means the first non-inline virtual member
// function has no definition.
unimpl(
    _ZTVN4Core14BaseFileFilter8IteratorE);  // ", referenced from:
                                            //__ZN4Core14BaseFileFilter8IteratorC2Ev
                                            // in cppincludesfilter.o
// NOTE: a missing vtable usually means the first non-inline virtual member
// function has no definition.
unimpl(
    _ZTVN8CppTools8Internal24CppCodeStyleSettingsPageE);  // ", referenced from:
                                                          //__ZN8CppTools8Internal24CppCodeStyleSettingsPageD2Ev
                                                          // in cpptoolsplugin.o
// NOTE: a missing vtable usually means the first non-inline virtual member
// function has no definition.
unimpl(
    _ZThn16_N10TextEditor16TextEditorWidgetD0Ev);  // ", referenced from:
                                                   //__ZTVN10TextEditor16TextEditorWidgetE
                                                   // in moc_texteditor.o
unimpl(
    _ZThn16_N10TextEditor16TextEditorWidgetD1Ev);  // ", referenced from:
                                                   //__ZTVN10TextEditor16TextEditorWidgetE
                                                   // in moc_texteditor.o
unimpl(
    _ZThn16_N10TextEditor17TabSettingsWidgetD0Ev);  // ", referenced from:
                                                    //__ZTVN10TextEditor17TabSettingsWidgetE
                                                    // in
                                                    // moc_tabsettingswidget.o
unimpl(
    _ZThn16_N10TextEditor17TabSettingsWidgetD1Ev);  // ", referenced from:
                                                    //__ZTVN10TextEditor17TabSettingsWidgetE
                                                    // in
                                                    // moc_tabsettingswidget.o
unimpl(
    _ZThn16_N10TextEditor22BehaviorSettingsWidgetD0Ev);  // ", referenced from:
                                                         //__ZTVN10TextEditor22BehaviorSettingsWidgetE
                                                         // in
                                                         // moc_behaviorsettingswidget.o
unimpl(
    _ZThn16_N10TextEditor22BehaviorSettingsWidgetD1Ev);  // ", referenced from:
                                                         //__ZTVN10TextEditor22BehaviorSettingsWidgetE
                                                         // in
                                                         // moc_behaviorsettingswidget.o
unimpl(
    _ZThn16_N10TextEditor23CodeStyleSelectorWidgetD0Ev);  // ", referenced from:
                                                          //__ZTVN10TextEditor23CodeStyleSelectorWidgetE
                                                          // in
                                                          // moc_codestyleselectorwidget.o
unimpl(
    _ZThn16_N10TextEditor23CodeStyleSelectorWidgetD1Ev);  // ", referenced from:
                                                          //__ZTVN10TextEditor23CodeStyleSelectorWidgetE
                                                          // in
                                                          // moc_codestyleselectorwidget.o
unimpl(
    _ZThn16_N10TextEditor8Internal15ColorSchemeEditD0Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN10TextEditor8Internal15ColorSchemeEditE
                                                           // in
                                                           // moc_colorschemeedit.o
unimpl(
    _ZThn16_N10TextEditor8Internal15ColorSchemeEditD1Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN10TextEditor8Internal15ColorSchemeEditE
                                                           // in
                                                           // moc_colorschemeedit.o
unimpl(
    _ZThn16_N11QmlJSEditor8Internal19ComponentNameDialogD0Ev);  // ", referenced
                                                                // from:
                                                                //__ZTVN11QmlJSEditor8Internal19ComponentNameDialogE
                                                                // in
                                                                // moc_qmljscomponentnamedialog.o
unimpl(
    _ZThn16_N11QmlJSEditor8Internal19ComponentNameDialogD1Ev);  // ", referenced
                                                                // from:
                                                                //__ZTVN11QmlJSEditor8Internal19ComponentNameDialogE
                                                                // in
                                                                // moc_qmljscomponentnamedialog.o
unimpl(
    _ZThn16_N15ExtensionSystem15PluginErrorViewD0Ev);  // ", referenced from:
                                                       //__ZTVN15ExtensionSystem15PluginErrorViewE
                                                       // in
                                                       // moc_pluginerrorview.o
unimpl(
    _ZThn16_N15ExtensionSystem15PluginErrorViewD1Ev);  // ", referenced from:
                                                       //__ZTVN15ExtensionSystem15PluginErrorViewE
                                                       // in
                                                       // moc_pluginerrorview.o
unimpl(
    _ZThn16_N15ExtensionSystem17PluginDetailsViewD0Ev);  // ", referenced from:
                                                         //__ZTVN15ExtensionSystem17PluginDetailsViewE
                                                         // in
                                                         // moc_plugindetailsview.o
unimpl(
    _ZThn16_N15ExtensionSystem17PluginDetailsViewD1Ev);  // ", referenced from:
                                                         //__ZTVN15ExtensionSystem17PluginDetailsViewE
                                                         // in
                                                         // moc_plugindetailsview.o
unimpl(
    _ZThn16_N15ExtensionSystem19PluginErrorOverviewD0Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN15ExtensionSystem19PluginErrorOverviewE
                                                           // in
                                                           // moc_pluginerroroverview.o
unimpl(
    _ZThn16_N15ExtensionSystem19PluginErrorOverviewD1Ev);  // ", referenced
                                                           // from:
                                                           //__ZTVN15ExtensionSystem19PluginErrorOverviewE
                                                           // in
                                                           // moc_pluginerroroverview.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal16DeviceTestDialogD0Ev);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN15ProjectExplorer8Internal16DeviceTestDialogE
                                                                 // in
                                                                 // moc_devicetestdialog.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal16DeviceTestDialogD1Ev);  // ",
                                                                 // referenced
                                                                 // from:
                                                                 //__ZTVN15ProjectExplorer8Internal16DeviceTestDialogE
                                                                 // in
                                                                 // moc_devicetestdialog.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal17ProjectWizardPageD0Ev);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZTVN15ProjectExplorer8Internal17ProjectWizardPageE
                                                                  // in
                                                                  // moc_projectwizardpage.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal17ProjectWizardPageD1Ev);  // ",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZTVN15ProjectExplorer8Internal17ProjectWizardPageE
                                                                  // in
                                                                  // moc_projectwizardpage.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal20DeviceSettingsWidgetD0Ev);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN15ProjectExplorer8Internal20DeviceSettingsWidgetE
                                                                     // in
                                                                     // moc_devicesettingswidget.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal20DeviceSettingsWidgetD1Ev);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN15ProjectExplorer8Internal20DeviceSettingsWidgetE
                                                                     // in
                                                                     // moc_devicesettingswidget.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal24CustomParserConfigDialogD0Ev);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZTVN15ProjectExplorer8Internal24CustomParserConfigDialogE
                                                                         // in
                                                                         // moc_customparserconfigdialog.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal24CustomParserConfigDialogD1Ev);  // ",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZTVN15ProjectExplorer8Internal24CustomParserConfigDialogE
                                                                         // in
                                                                         // moc_customparserconfigdialog.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal28DeviceFactorySelectionDialogD0Ev);  // ", referenced from:
                                                                             //__ZTVN15ProjectExplorer8Internal28DeviceFactorySelectionDialogE in moc_devicefactoryselectiondialog.o
unimpl(
    _ZThn16_N15ProjectExplorer8Internal28DeviceFactorySelectionDialogD1Ev);  // ", referenced from:
                                                                             //__ZTVN15ProjectExplorer8Internal28DeviceFactorySelectionDialogE in moc_devicefactoryselectiondialog.o
unimpl(_ZThn16_N20FilePropertiesDialogD0Ev);  // ", referenced from:
                                              //__ZTV20FilePropertiesDialog in
                                              // moc_filepropertiesdialog.o
unimpl(_ZThn16_N20FilePropertiesDialogD1Ev);  // ", referenced from:
                                              //__ZTV20FilePropertiesDialog in
                                              // moc_filepropertiesdialog.o
unimpl(
    _ZThn16_N4Core19ReadOnlyFilesDialogD0Ev);  // ", referenced from:
                                               //__ZTVN4Core19ReadOnlyFilesDialogE
                                               // in moc_readonlyfilesdialog.o
unimpl(
    _ZThn16_N4Core19ReadOnlyFilesDialogD1Ev);  // ", referenced from:
                                               //__ZTVN4Core19ReadOnlyFilesDialogE
                                               // in moc_readonlyfilesdialog.o
unimpl(
    _ZThn16_N4Core22FindToolBarPlaceHolderD0Ev);  // ", referenced from:
                                                  //__ZTVN4Core22FindToolBarPlaceHolderE
                                                  // in moc_findplaceholder.o
unimpl(
    _ZThn16_N4Core22FindToolBarPlaceHolderD1Ev);  // ", referenced from:
                                                  //__ZTVN4Core22FindToolBarPlaceHolderE
                                                  // in moc_findplaceholder.o
unimpl(
    _ZThn16_N4Core24EditorManagerPlaceHolderD0Ev);  // ", referenced from:
                                                    //__ZTVN4Core24EditorManagerPlaceHolderE
                                                    // in moc_editormanager.o
unimpl(
    _ZThn16_N4Core24EditorManagerPlaceHolderD1Ev);  // ", referenced from:
                                                    //__ZTVN4Core24EditorManagerPlaceHolderE
                                                    // in moc_editormanager.o
unimpl(
    _ZThn16_N4Core8Internal14AddToVcsDialogD0Ev);  // ", referenced from:
                                                   //__ZTVN4Core8Internal14AddToVcsDialogE
                                                   // in moc_addtovcsdialog.o
unimpl(
    _ZThn16_N4Core8Internal14AddToVcsDialogD1Ev);  // ", referenced from:
                                                   //__ZTVN4Core8Internal14AddToVcsDialogE
                                                   // in moc_addtovcsdialog.o
unimpl(
    _ZThn16_N4Core8Internal9NewDialogD0Ev);  // ", referenced from:
                                             //__ZTVN4Core8Internal9NewDialogE
                                             // in moc_newdialog.o
unimpl(
    _ZThn16_N4Core8Internal9NewDialogD1Ev);  // ", referenced from:
                                             //__ZTVN4Core8Internal9NewDialogE
                                             // in moc_newdialog.o
unimpl(
    _ZThn16_N4QSsh20SshKeyCreationDialogD0Ev);  // ", referenced from:
                                                //__ZTVN4QSsh20SshKeyCreationDialogE
                                                // in moc_sshkeycreationdialog.o
unimpl(
    _ZThn16_N4QSsh20SshKeyCreationDialogD1Ev);  // ", referenced from:
                                                //__ZTVN4QSsh20SshKeyCreationDialogE
                                                // in moc_sshkeycreationdialog.o
unimpl(_ZThn16_N7VcsBase11CleanDialogD0Ev);  // ", referenced from:
                                             //__ZTVN7VcsBase11CleanDialogE in
                                             // moc_cleandialog.o
unimpl(_ZThn16_N7VcsBase11CleanDialogD1Ev);  // ", referenced from:
                                             //__ZTVN7VcsBase11CleanDialogE in
                                             // moc_cleandialog.o
unimpl(
    _ZThn16_N7VcsBase18SubmitEditorWidgetD0Ev);  // ", referenced from:
                                                 //__ZTVN7VcsBase18SubmitEditorWidgetE
                                                 // in moc_submiteditorwidget.o
unimpl(
    _ZThn16_N7VcsBase18SubmitEditorWidgetD1Ev);  // ", referenced from:
                                                 //__ZTVN7VcsBase18SubmitEditorWidgetE
                                                 // in moc_submiteditorwidget.o
unimpl(
    _ZThn16_N7VcsBase8Internal14NickNameDialogD0Ev);  // ", referenced from:
                                                      //__ZTVN7VcsBase8Internal14NickNameDialogE
                                                      // in moc_nicknamedialog.o
unimpl(
    _ZThn16_N7VcsBase8Internal14NickNameDialogD1Ev);  // ", referenced from:
                                                      //__ZTVN7VcsBase8Internal14NickNameDialogE
                                                      // in moc_nicknamedialog.o
unimpl(
    _ZThn16_N7VcsBase8Internal20CommonSettingsWidgetD0Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN7VcsBase8Internal20CommonSettingsWidgetE
                                                            // in
                                                            // moc_commonsettingspage.o
unimpl(
    _ZThn16_N7VcsBase8Internal20CommonSettingsWidgetD1Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN7VcsBase8Internal20CommonSettingsWidgetE
                                                            // in
                                                            // moc_commonsettingspage.o
unimpl(
    _ZThn16_N8CppTools28ClangDiagnosticConfigsWidgetD0Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN8CppTools28ClangDiagnosticConfigsWidgetE
                                                            // in
                                                            // moc_clangdiagnosticconfigswidget.o
unimpl(
    _ZThn16_N8CppTools28ClangDiagnosticConfigsWidgetD1Ev);  // ", referenced
                                                            // from:
                                                            //__ZTVN8CppTools28ClangDiagnosticConfigsWidgetE
                                                            // in
                                                            // moc_clangdiagnosticconfigswidget.o
unimpl(
    _ZThn16_N8CppTools8Internal29CppCodeStylePreferencesWidgetD0Ev);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN8CppTools8Internal29CppCodeStylePreferencesWidgetE
                                                                      // in
                                                                      // moc_cppcodestylesettingspage.o
unimpl(
    _ZThn16_N8CppTools8Internal29CppCodeStylePreferencesWidgetD1Ev);  // ",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN8CppTools8Internal29CppCodeStylePreferencesWidgetE
                                                                      // in
                                                                      // moc_cppcodestylesettingspage.o
unimpl(
    _ZThn16_N8Debugger8Internal17SymbolPathsDialogD0Ev);  // ", referenced from:
                                                          //__ZTVN8Debugger8Internal17SymbolPathsDialogE
                                                          // in
                                                          // moc_symbolpathsdialog.o
unimpl(
    _ZThn16_N8Debugger8Internal17SymbolPathsDialogD1Ev);  // ", referenced from:
                                                          //__ZTVN8Debugger8Internal17SymbolPathsDialogE
                                                          // in
                                                          // moc_symbolpathsdialog.o
unimpl(
    _ZThn16_N9CppEditor8Internal21CppPreProcessorDialogD0Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN9CppEditor8Internal21CppPreProcessorDialogE
                                                               // in
                                                               // moc_cpppreprocessordialog.o
unimpl(
    _ZThn16_N9CppEditor8Internal21CppPreProcessorDialogD1Ev);  // ", referenced
                                                               // from:
                                                               //__ZTVN9CppEditor8Internal21CppPreProcessorDialogE
                                                               // in
                                                               // moc_cpppreprocessordialog.o
unimpl(
    _ZThn16_N9CppEditor8Internal25CppQuickFixSettingsWidgetD0Ev);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZTVN9CppEditor8Internal25CppQuickFixSettingsWidgetE
                                                                   // in
                                                                   // moc_cppquickfixsettingswidget.o
unimpl(
    _ZThn16_N9CppEditor8Internal25CppQuickFixSettingsWidgetD1Ev);  // ",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZTVN9CppEditor8Internal25CppQuickFixSettingsWidgetE
                                                                   // in
                                                                   // moc_cppquickfixsettingswidget.o
unimpl(
    _ZThn16_N9CppEditor8Internal27CppCodeModelInspectorDialogD0Ev);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN9CppEditor8Internal27CppCodeModelInspectorDialogE
                                                                     // in
                                                                     // moc_cppcodemodelinspectordialog.o
unimpl(
    _ZThn16_N9CppEditor8Internal27CppCodeModelInspectorDialogD1Ev);  // ",
                                                                     // referenced
                                                                     // from:
                                                                     //__ZTVN9CppEditor8Internal27CppCodeModelInspectorDialogE
                                                                     // in
                                                                     // moc_cppcodemodelinspectordialog.o
unimpl(
    _ZThn16_N9CppEditor8Internal32CppQuickFixProjectSettingsWidgetD0Ev);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetE
                                                                          // in
                                                                          // moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZThn16_N9CppEditor8Internal32CppQuickFixProjectSettingsWidgetD1Ev);  // ",
                                                                          // referenced
                                                                          // from:
                                                                          //__ZTVN9CppEditor8Internal32CppQuickFixProjectSettingsWidgetE
                                                                          // in
                                                                          // moc_cppquickfixprojectsettingswidget.o
unimpl(
    _ZN10TextEditor8Internal16TextEditorPlugin16lineNumberFilterEv);  //",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZZN10TextEditor8Internal30TextEditorActionHandlerPrivate13createActionsEvENK3$_6clEPNS_16TextEditorWidgetE
                                                                      // in
                                                                      // texteditoractionhandler.o
unimpl(
    _ZN10TextEditor8Internal16TextEditorPlugin8instanceEv);  //", referenced
                                                             // from:
                                                             //__ZN10TextEditor16TextMarkRegistry8instanceEv
                                                             // in textmark.o
unimpl(
    _ZN4Core8Internal10CorePlugin8instanceEv);  //", referenced from:
                                                //__ZN4Core11HelpManagerL13checkInstanceEv
                                                // in helpmanager.o
                                                //__ZN4Core8Internal16CheckArchivePage13checkContentsER16QFutureInterfaceINS1_12ArchiveIssueEE
                                                // in plugininstallwizard.o
unimpl(
    _ZN7VcsBase8Internal9VcsPlugin13nickNameModelEv);  //", referenced from:
                                                       //__ZN7VcsBase19VcsBaseSubmitEditor16createUserFieldsERK7QString
                                                       // in
                                                       // vcsbasesubmiteditor.o
                                                       //__ZN7VcsBase19VcsBaseSubmitEditor17promptForNickNameEv
                                                       // in
                                                       // vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase8Internal9VcsPlugin15settingsChangedERKNS0_17CommonVcsSettingsE);  //", referenced from:
                                                                                  //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE in vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase8Internal9VcsPlugin16staticMetaObjectE);  //", referenced from:
                                                         //__ZN7QObject7connectIMN7VcsBase8Internal9VcsPluginEFvPNS1_19VcsBaseSubmitEditorEPbEMNS1_20VcsBasePluginPrivateEFvS5_S6_EEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESG_PKNSF_IT0_E6ObjectESL_N2Qt14ConnectionTypeE
                                                         // in vcsbaseplugin.o
                                                         //__ZN7QObject7connectIMN7VcsBase8Internal9VcsPluginEFvRKNS2_17CommonVcsSettingsEEMNS1_19VcsBaseSubmitEditorEFvS6_EEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESG_PKNSF_IT0_E6ObjectESL_N2Qt14ConnectionTypeE
                                                         // in
                                                         // vcsbasesubmiteditor.o
unimpl(
    _ZN7VcsBase8Internal9VcsPlugin24submitEditorAboutToCloseEPNS_19VcsBaseSubmitEditorEPb);  //", referenced from:
                                                                                             //__ZN7VcsBase20VcsBasePluginPrivateC2ERKN4Core7ContextE in vcsbaseplugin.o
unimpl(
    _ZN7VcsBase8Internal9VcsPlugin8instanceEv);  //", referenced from:
                                                 //__ZN7VcsBase20VcsBasePluginPrivateC2ERKN4Core7ContextE
                                                 // in vcsbaseplugin.o
                                                 //__ZN7VcsBase9sshPromptEv
                                                 // in vcsbaseplugin.o
                                                 //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE
                                                 // in vcsbasesubmiteditor.o
                                                 //__ZN7VcsBase19VcsBaseSubmitEditor16createUserFieldsERK7QString
                                                 // in vcsbasesubmiteditor.o
                                                 //__ZN7VcsBase19VcsBaseSubmitEditor17promptForNickNameEv
                                                 // in vcsbasesubmiteditor.o
                                                 //__ZN7VcsBaseL24submitMessageCheckScriptEv
                                                 // in vcsbasesubmiteditor.o
unimpl(
    _ZN8CppTools27correspondingHeaderOrSourceERK7QStringPbNS_10CacheUsageE);  //", referenced from:
                                                                              //__ZN9CppEditor8Internal22InsertVirtualMethodsOpC2ERKNS0_20CppQuickFixInterfaceEPNS0_26InsertVirtualMethodsDialogE in cppinsertvirtualmethods.o
                                                                              //__ZN9CppEditor8Internal17InsertDefFromDecl5matchERKNS0_20CppQuickFixInterfaceER5QListI14QSharedPointerIN10TextEditor17QuickFixOperationEEE in cppquickfixes.o
                                                                              //__ZN9CppEditor8Internal18MoveFuncDefOutside5matchERKNS0_20CppQuickFixInterfaceER5QListI14QSharedPointerIN10TextEditor17QuickFixOperationEEE in cppquickfixes.o
                                                                              //__ZN9CppEditor8Internal21MoveAllFuncDefOutside5matchERKNS0_20CppQuickFixInterfaceER5QListI14QSharedPointerIN10TextEditor17QuickFixOperationEEE in cppquickfixes.o
                                                                              //__ZN9CppEditor8Internal17MoveFuncDefToDecl5matchERKNS0_20CppQuickFixInterfaceER5QListI14QSharedPointerIN10TextEditor17QuickFixOperationEEE in cppquickfixes.o
                                                                              //__ZN9CppEditor8Internal12_GLOBAL__N_129GetterSetterRefactoringHelperC2EPNS_20CppQuickFixOperationERK7QStringPN9CPlusPlus5ClassE in cppquickfixes.o
                                                                              //__ZN9CppEditor8Internal12_GLOBAL__N_127ExtractLiteralAsParameterOp15findDeclarationERKN8CppTools21CppRefactoringChangesEPN9CPlusPlus21FunctionDefinitionASTE in cppquickfixes.o
                                                                              //...
unimpl(
    _ZN8CppTools8Internal14CppToolsPlugin13usePragmaOnceEv);  //", referenced
                                                              // from:
                                                              //__ZN8CppTools21AbstractEditorSupport13usePragmaOnceEv
                                                              // in
                                                              // abstracteditorsupport.o
unimpl(
    _ZN8CppTools8Internal14CppToolsPlugin17codeModelSettingsEv);  //",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN8CppTools30BuiltinEditorDocumentProcessorC2EPN10TextEditor12TextDocumentEb
                                                                  // in
                                                                  // builtineditordocumentprocessor.o
                                                                  //__ZN8CppTools17codeModelSettingsEv
                                                                  // in
                                                                  // cpptoolsreuse.o
unimpl(
    _ZN8CppTools8Internal14CppToolsPlugin8instanceEv);  //", referenced from:
                                                        //__ZN8CppTools30BuiltinEditorDocumentProcessorC2EPN10TextEditor12TextDocumentEb
                                                        // in
                                                        // builtineditordocumentprocessor.o
                                                        //__ZN8CppTools17codeModelSettingsEv
                                                        // in cpptoolsreuse.o
unimpl(
    _ZN9CppEditor8Internal15CppEditorPlugin16staticMetaObjectE);  //",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZN7QObject7connectIMN9CppEditor8Internal15CppEditorPluginEFvbEMN8CppTools16CppEditorOutlineEFvbEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESE_PKNSD_IT0_E6ObjectESJ_N2Qt14ConnectionTypeE
                                                                  // in
                                                                  // cppeditorwidget.o
                                                                  //__ZN7QObject7connectIMN9CppEditor8Internal15CppEditorPluginEFvvEMNS2_25CppIncludeHierarchyWidgetEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESD_PKNSC_IT0_E6ObjectESI_N2Qt14ConnectionTypeE
                                                                  // in
                                                                  // cppincludehierarchy.o
                                                                  //__ZN7QObject7connectIMN9CppEditor8Internal15CppEditorPluginEFvvEMNS2_22CppTypeHierarchyWidgetEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESD_PKNSC_IT0_E6ObjectESI_N2Qt14ConnectionTypeE
                                                                  // in
                                                                  // cpptypehierarchy.o
unimpl(
    _ZN9CppEditor8Internal15CppEditorPlugin21outlineSortingChangedEb);  //",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN9CppEditor8Internal15CppEditorWidget22finalizeInitializationEv
                                                                        // in
                                                                        // cppeditorwidget.o
unimpl(
    _ZN9CppEditor8Internal15CppEditorPlugin22typeHierarchyRequestedEv);  //",
                                                                         // referenced
                                                                         // from:
                                                                         //__ZN9CppEditor8Internal22CppTypeHierarchyWidgetC2Ev
                                                                         // in
                                                                         // cpptypehierarchy.o
unimpl(
    _ZN9CppEditor8Internal15CppEditorPlugin25includeHierarchyRequestedEv);  //",
                                                                            // referenced
                                                                            // from:
                                                                            //__ZN9CppEditor8Internal25CppIncludeHierarchyWidgetC2Ev
                                                                            // in
                                                                            // cppincludehierarchy.o
unimpl(
    _ZN9CppEditor8Internal15CppEditorPlugin8instanceEv);  //", referenced from:
                                                          //__ZNK9CppEditor8Internal17CppEditorDocument22quickFixAssistProviderEv
                                                          // in
                                                          // cppeditordocument.o
                                                          //__ZN9CppEditor8Internal15CppEditorWidget22finalizeInitializationEv
                                                          // in
                                                          // cppeditorwidget.o
                                                          //__ZN9CppEditor8InternalL21addRefactoringActionsEP5QMenuPN10TextEditor15AssistInterfaceE
                                                          // in
                                                          // cppeditorwidget.o
                                                          //__ZN9CppEditor8Internal25CppIncludeHierarchyWidgetC2Ev
                                                          // in
                                                          // cppincludehierarchy.o
                                                          //__ZN9CppEditor8Internal22CppTypeHierarchyWidgetC2Ev
                                                          // in
                                                          // cpptypehierarchy.o
unimpl(
    _ZNK7VcsBase8Internal9VcsPlugin8settingsEv);  //", referenced from:
                                                  //__ZN7VcsBase9sshPromptEv
                                                  // in vcsbaseplugin.o
                                                  //__ZN7VcsBase19VcsBaseSubmitEditor13setParametersERKNS_29VcsBaseSubmitEditorParametersE
                                                  // in vcsbasesubmiteditor.o
                                                  //__ZN7VcsBaseL24submitMessageCheckScriptEv
                                                  // in vcsbasesubmiteditor.o
unimpl(
    _ZNK9CppEditor8Internal15CppEditorPlugin16quickFixProviderEv);  //",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZNK9CppEditor8Internal17CppEditorDocument22quickFixAssistProviderEv
                                                                    // in
                                                                    // cppeditordocument.o
                                                                    //__ZN9CppEditor8InternalL21addRefactoringActionsEP5QMenuPN10TextEditor15AssistInterfaceE
                                                                    // in
                                                                    // cppeditorwidget.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin15fileListChangedEv);  //",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN8CppTools8Internal17CppIncludesFilterC2Ev
                                                                      // in
                                                                      // cppincludesfilter.o
                                                                      //__ZN15ProjectExplorer8Internal17AllProjectsFilterC2Ev
                                                                      // in
                                                                      // allprojectsfilter.o
                                                                      //__ZN15ProjectExplorer8Internal15AllProjectsFindC2Ev
                                                                      // in
                                                                      // allprojectsfind.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin15settingsChangedEv);  //",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                                                      // in
                                                                      // debuggerplugin.o
                                                                      //__ZN15ProjectExplorer14TerminalAspectC2Ev
                                                                      // in
                                                                      // runconfigurationaspects.o
                                                                      //__ZN15ProjectExplorer8MakeStep18createConfigWidgetEv
                                                                      // in
                                                                      // makestep.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin16staticMetaObjectE);  //",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMN8Debugger8Internal21DebuggerPluginPrivateEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESE_PKNSD_IT0_E6ObjectESJ_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // debuggerplugin.o
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMN8CppTools8Internal17CppIncludesFilterEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESE_PKNSD_IT0_E6ObjectESJ_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // cppincludesfilter.o
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMNS1_8Internal17AllProjectsFilterEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESD_PKNSC_IT0_E6ObjectESI_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // allprojectsfilter.o
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMNS1_8Internal15AllProjectsFindEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESD_PKNSC_IT0_E6ObjectESI_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // allprojectsfind.o
                                                                      //__ZN15ProjectExplorer21ProjectExplorerPlugin2trEPKcS2_i
                                                                      // in
                                                                      // foldernavigationwidget.o
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMNS1_14TerminalAspectEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESC_PKNSB_IT0_E6ObjectESH_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // runconfigurationaspects.o
                                                                      //__ZN7QObject7connectIMN15ProjectExplorer21ProjectExplorerPluginEFvvEMNS1_8Internal12_GLOBAL__N_115SelectionWidgetEFvvEEEN11QMetaObject10ConnectionEPKN9QtPrivate15FunctionPointerIT_E6ObjectESE_PKNSD_IT0_E6ObjectESJ_N2Qt14ConnectionTypeE
                                                                      // in
                                                                      // customparser.o
                                                                      //...
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin17runActionsUpdatedEv);  //",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList
                                                                        // in
                                                                        // debuggerplugin.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin20customParsersChangedEv);  //",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN15ProjectExplorer8Internal12_GLOBAL__N_115SelectionWidgetC2EP7QWidget
                                                                           // in
                                                                           // customparser.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin21recentProjectsChangedEv);  //",
                                                                            // referenced
                                                                            // from:
                                                                            //__ZN15ProjectExplorer8Internal12ProjectModelC2EP7QObject
                                                                            // in
                                                                            // projectwelcomepage.o
unimpl(
    _ZN15ProjectExplorer21ProjectExplorerPlugin22finishedInitializationEv);  //", referenced from:
                                                                             //__ZN8Debugger8Internal21DebuggerPluginPrivateC2ERK11QStringList in debuggerplugin.o

unimpl(
    _ZN10TextEditor12TextDocument10autoIndentERK11QTextCursor5QChari);  //",
                                                                        // referenced
                                                                        // from:
                                                                        //__ZN10TextEditor23TextDocumentManipulator10autoIndentEii
                                                                        // in
                                                                        // textdocumentmanipulator.o
                                                                        //__ZN9CppEditor8Internal15trySplitCommentEPN10TextEditor16TextEditorWidgetERKN9CPlusPlus8SnapshotE
                                                                        // in
                                                                        // cppdocumentationcommenthelper.o
                                                                        //__ZNK9CppEditor8Internal15CppEditorWidget21handleStringSplittingEP9QKeyEvent
                                                                        // in
                                                                        // cppeditorwidget.o
unimpl(
    _ZN10TextEditor12TextDocument10removeMarkEPNS_8TextMarkE);  //", referenced
                                                                // from:
                                                                //__ZN8Debugger8Internal17DisassemblerAgent13resetLocationEv
                                                                // in
                                                                // disassembleragent.o
                                                                //__ZN8Debugger8Internal17DisassemblerAgent20updateLocationMarkerEv
                                                                // in
                                                                // disassembleragent.o
                                                                //__ZN8Debugger8Internal17DisassemblerAgent22removeBreakpointMarkerERK8QPointerINS0_14BreakpointItemEE
                                                                // in
                                                                // disassembleragent.o
                                                                //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv
                                                                // in
                                                                // sourceagent.o
                                                                //__ZN10TextEditor8TextMarkD2Ev
                                                                // in textmark.o
                                                                //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate20cleanDiagnosticMarksEv
                                                                // in
                                                                // qmljseditordocument.o
                                                                //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate18cleanSemanticMarksEv
                                                                // in
                                                                // qmljseditordocument.o
                                                                //...
unimpl(
    _ZN10TextEditor12TextDocument10updateMarkEPNS_8TextMarkE);  //", referenced
                                                                // from:
                                                                //__ZN10TextEditor8TextMark12updateMarkerEv
                                                                // in textmark.o
                                                                //__ZN10TextEditor8TextMark11setPriorityENS0_8PriorityE
                                                                // in textmark.o
                                                                //__ZN10TextEditor8TextMark10setVisibleEb
                                                                // in textmark.o
unimpl(
    _ZN10TextEditor12TextDocument11setContentsERK10QByteArray);  //", referenced
                                                                 // from:
                                                                 //__ZTVN10TextEditor12TextDocumentE
                                                                 // in
                                                                 // moc_textdocument.o
                                                                 //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                                 // in
                                                                 // moc_cppeditordocument.o
                                                                 //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                                 // in
                                                                 // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument11setFilePathERKN5Utils8FilePathE);  //",
                                                                      // referenced
                                                                      // from:
                                                                      //__ZTVN10TextEditor12TextDocumentE
                                                                      // in
                                                                      // moc_textdocument.o
                                                                      //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                                      // in
                                                                      // moc_cppeditordocument.o
                                                                      //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                                      // in
                                                                      // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument11setIndenterEPNS_8IndenterE);  //", referenced
                                                                 // from:
                                                                 //__ZN9CppEditor8Internal9CppEditor14decorateEditorEPN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // cppeditor.o
                                                                 //__ZN9CppEditor8Internal17CppEditorDocumentC2Ev
                                                                 // in
                                                                 // cppeditordocument.o
                                                                 //__ZN11QmlJSEditor18QmlJSEditorFactory14decorateEditorEPN10TextEditor16TextEditorWidgetE
                                                                 // in
                                                                 // qmljseditor.o
                                                                 //__ZN11QmlJSEditor19QmlJSEditorDocumentC2EN5Utils2IdE
                                                                 // in
                                                                 // qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument12setPlainTextERK7QString);  //", referenced
                                                              // from:
                                                              //__ZN8Debugger8Internal17DisassemblerAgent21setContentsToDocumentERKNS0_17DisassemblerLinesE
                                                              // in
                                                              // disassembleragent.o
                                                              //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv
                                                              // in
                                                              // qmljseditor.o
                                                              //__ZN7VcsBase19VcsBaseEditorWidget21reportCommandFinishedEbiRK8QVariant
                                                              // in
                                                              // vcsbaseeditor.o
                                                              //__ZN7VcsBase19VcsBaseEditorWidget12setPlainTextERK7QString
                                                              // in
                                                              // vcsbaseeditor.o
unimpl(
    _ZN10TextEditor12TextDocument16checkPermissionsEv);  //", referenced from:
                                                         //__ZTVN10TextEditor12TextDocumentE
                                                         // in
                                                         // moc_textdocument.o
                                                         //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                         // in
                                                         // moc_cppeditordocument.o
                                                         //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                         // in
                                                         // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument17applyFontSettingsEv);  //", referenced from:
                                                          //__ZN9CppEditor8Internal17CppEditorDocument17applyFontSettingsEv
                                                          // in
                                                          // cppeditordocument.o
                                                          //__ZN11QmlJSEditor19QmlJSEditorDocument17applyFontSettingsEv
                                                          // in
                                                          // qmljseditordocument.o
                                                          //__ZTVN10TextEditor12TextDocumentE
                                                          // in
                                                          // moc_textdocument.o
unimpl(
    _ZN10TextEditor12TextDocument18setStorageSettingsERKNS_15StorageSettingsE);  //", referenced from:
                                                                                 //__ZN9CppEditor8Internal17CppEditorDocument4saveEP7QStringRKS2_b in cppeditordocument.o
                                                                                 //__ZNSt3__110__function6__funcIZN9CppEditor8Internal17CppEditorDocument4saveEP7QStringRKS5_bE3$_3NS_9allocatorIS9_EEFvvEEclEv in cppeditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument20setSyntaxHighlighterEPNS_17SyntaxHighlighterE);  //", referenced from:
                                                                                    //__ZN9CppEditor8Internal9CppEditor14decorateEditorEPN10TextEditor16TextEditorWidgetE in cppeditor.o
                                                                                    //__ZN9CppEditor8Internal17CppEditorDocumentC2Ev in cppeditordocument.o
                                                                                    //__ZNK11QmlJSEditor17QmlJSEditorWidget25inspectElementUnderCursorEv in qmljseditor.o
                                                                                    //__ZN11QmlJSEditor18QmlJSEditorFactory14decorateEditorEPN10TextEditor16TextEditorWidgetE in qmljseditor.o
                                                                                    //__ZN11QmlJSEditor19QmlJSEditorDocumentC2EN5Utils2IdE in qmljseditordocument.o
                                                                                    //__ZN7VcsBase19VcsBaseEditorWidget4initEv in vcsbaseeditor.o
                                                                                    //__ZN7VcsBase19VcsBaseEditorWidget22slotActivateAnnotationEv in vcsbaseeditor.o
                                                                                    //...
unimpl(
    _ZN10TextEditor12TextDocument21triggerPendingUpdatesEv);  //", referenced
                                                              // from:
                                                              //__ZN11QmlJSEditor19QmlJSEditorDocument21triggerPendingUpdatesEv
                                                              // in
                                                              // qmljseditordocument.o
                                                              //__ZTVN10TextEditor12TextDocumentE
                                                              // in
                                                              // moc_textdocument.o
                                                              //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                              // in
                                                              // moc_cppeditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument23textDocumentForFilePathERKN5Utils8FilePathE);  //", referenced from:
                                                                                  //__ZN10TextEditor16TextMarkRegistry3addEPNS_8TextMarkE in textmark.o
unimpl(
    _ZN10TextEditor12TextDocument24removeMarkFromMarksCacheEPNS_8TextMarkE);  //", referenced from:
                                                                              //__ZN10TextEditor17TextBlockUserDataD2Ev in textdocumentlayout.o
                                                                              //__ZN10TextEditor18TextDocumentLayout16documentReloadedE5QListIPNS_8TextMarkEEPNS_12TextDocumentE in textdocumentlayout.o
unimpl(
    _ZN10TextEditor12TextDocument25setFallbackSaveAsFileNameERK7QString);  //",
                                                                           // referenced
                                                                           // from:
                                                                           //__ZN8Debugger8Internal14openTextEditorERK7QStringS3_
                                                                           // in
                                                                           // debuggerplugin.o
unimpl(
    _ZN10TextEditor12TextDocument26openedTextDocumentContentsEv);  //",
                                                                   // referenced
                                                                   // from:
                                                                   //__ZN10TextEditor8Internal12_GLOBAL__N_114InternalEngine13executeSearchERKNS_18FileFindParametersEPNS_12BaseFileFindE
                                                                   // in
                                                                   // basefilefind.o
unimpl(
    _ZN10TextEditor12TextDocument27openedTextDocumentEncodingsEv);  //",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZNK10TextEditor8Internal17FindInCurrentFile5filesERK11QStringListS4_RK8QVariant
                                                                    // in
                                                                    // findincurrentfile.o
                                                                    //__ZNK10TextEditor8Internal15FindInOpenFiles5filesERK11QStringListS4_RK8QVariant
                                                                    // in
                                                                    // findinopenfiles.o
                                                                    //__ZNK15ProjectExplorer8Internal15AllProjectsFind16filesForProjectsERK11QStringListS4_RK5QListIPNS_7ProjectEE
                                                                    // in
                                                                    // allprojectsfind.o
unimpl(
    _ZN10TextEditor12TextDocument34createDiffAgainstCurrentFileActionEP7QObjectRKNSt3__18functionIFN5Utils8FilePathEvEEE);  //", referenced from:
                                                                                                                            //__ZN15ProjectExplorer8Internal22FolderNavigationWidget16contextMenuEventEP17QContextMenuEvent in foldernavigationwidget.o
unimpl(
    _ZN10TextEditor12TextDocument4openEP7QStringRKS1_S4_);  //", referenced
                                                            // from:
                                                            //__ZTVN10TextEditor12TextDocumentE
                                                            // in
                                                            // moc_textdocument.o
                                                            //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                            // in
                                                            // moc_cppeditordocument.o
                                                            //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                            // in
                                                            // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument4saveEP7QStringRKS1_b);  //", referenced from:
                                                          //__ZN9CppEditor8Internal17CppEditorDocument4saveEP7QStringRKS2_b
                                                          // in
                                                          // cppeditordocument.o
                                                          //__ZTVN10TextEditor12TextDocumentE
                                                          // in
                                                          // moc_textdocument.o
                                                          //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                          // in
                                                          // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument6reloadEP7QString);  //", referenced from:
                                                      //__ZTVN10TextEditor12TextDocumentE
                                                      // in moc_textdocument.o
                                                      //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                      // in
                                                      // moc_cppeditordocument.o
                                                      //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                      // in
                                                      // moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument6reloadEP7QStringN4Core9IDocument10ReloadFlagENS4_10ChangeTypeE);  //", referenced from:
                                                                                                    //__ZTVN10TextEditor12TextDocumentE in moc_textdocument.o
                                                                                                    //__ZTVN9CppEditor8Internal17CppEditorDocumentE in moc_cppeditordocument.o
                                                                                                    //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE in moc_qmljseditordocument.o
unimpl(
    _ZN10TextEditor12TextDocument6reloadEP7QStringRKS1_);  //", referenced from:
                                                           //__ZN10DiffEditor8Internal26DiffEditorWidgetController5patchEbii
                                                           // in
                                                           // diffeditorwidgetcontroller.o
unimpl(
    _ZN10TextEditor12TextDocument7addMarkEPNS_8TextMarkE);  //", referenced
                                                            // from:
                                                            //__ZN8Debugger8Internal17DisassemblerAgent22updateBreakpointMarkerERK8QPointerINS0_14BreakpointItemEE
                                                            // in
                                                            // disassembleragent.o
                                                            //__ZN8Debugger8Internal17DisassemblerAgent20updateLocationMarkerEv
                                                            // in
                                                            // disassembleragent.o
                                                            //__ZN8Debugger8Internal11SourceAgent20updateLocationMarkerEv
                                                            // in sourceagent.o
                                                            //__ZN10TextEditor16TextMarkRegistry3addEPNS_8TextMarkE
                                                            // in textmark.o
                                                            //__ZN10TextEditor16TextMarkRegistry12editorOpenedEPN4Core7IEditorE
                                                            // in textmark.o
                                                            //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate15createTextMarksERK5QListIN5QmlJS17DiagnosticMessageEE
                                                            // in
                                                            // qmljseditordocument.o
                                                            //__ZN11QmlJSEditor8Internal26QmlJSEditorDocumentPrivate15createTextMarksERKN10QmlJSTools12SemanticInfoE
                                                            // in
                                                            // qmljseditordocument.o
                                                            //...
unimpl(
    _ZN10TextEditor12TextDocument8moveMarkEPNS_8TextMarkEi);  //", referenced
                                                              // from:
                                                              //__ZN10TextEditor8TextMark4moveEi
                                                              // in textmark.o
unimpl(
    _ZN10TextEditor12TextDocumentC1EN5Utils2IdE);  //", referenced from:
                                                   //__ZNSt3__110__function6__funcIZN10TextEditor22PlainTextEditorFactoryC1EvE3$_0NS_9allocatorIS4_EEFPNS2_12TextDocumentEvEEclEv
                                                   // in
                                                   // plaintexteditorfactory.o
                                                   //__ZNSt3__110__function6__funcIZN7VcsBase16VcsEditorFactoryC1EPKNS2_23VcsBaseEditorParametersENS_8functionIFP7QWidgetvEEENS7_IFvRK7QStringSE_EEEE3$_0NS_9allocatorISH_EEFPN10TextEditor12TextDocumentEvEEclEv
                                                   // in basevcseditorfactory.o
unimpl(
    _ZN10TextEditor12TextDocumentC2EN5Utils2IdE);  //", referenced from:
                                                   //__ZN9CppEditor8Internal17CppEditorDocumentC2Ev
                                                   // in cppeditordocument.o
                                                   //__ZN11QmlJSEditor19QmlJSEditorDocumentC2EN5Utils2IdE
                                                   // in qmljseditordocument.o
unimpl(_ZN10TextEditor12TextDocumentD0Ev);  //", referenced from:
                                            //__ZTVN10TextEditor12TextDocumentE
                                            // in moc_textdocument.o
unimpl(_ZN10TextEditor12TextDocumentD1Ev);  //", referenced from:
                                            //__ZTVN10TextEditor12TextDocumentE
                                            // in moc_textdocument.o
unimpl(
    _ZN10TextEditor12TextDocumentD2Ev);  //", referenced from:
                                         //__ZN9CppEditor8Internal17CppEditorDocumentC2Ev
                                         // in cppeditordocument.o
                                         //__ZN11QmlJSEditor19QmlJSEditorDocumentC2EN5Utils2IdE
                                         // in qmljseditordocument.o
                                         //__ZN11QmlJSEditor19QmlJSEditorDocumentD2Ev
                                         // in qmljseditordocument.o
                                         //__ZN11QmlJSEditor19QmlJSEditorDocumentD1Ev
                                         // in qmljseditordocument.o
                                         //__ZN11QmlJSEditor19QmlJSEditorDocumentD0Ev
                                         // in qmljseditordocument.o
                                         //__ZN9CppEditor8Internal17CppEditorDocumentD2Ev
                                         // in moc_cppeditordocument.o
unimpl(
    _ZN10TextEditor19SemanticHighlighter35clearExtraAdditionalFormatsUntilEndEPNS_17SyntaxHighlighterERK7QFutureINS_18HighlightingResultEE);  //", referenced from:
                                                                                                                                              //__ZN8CppTools19SemanticHighlighter21onHighlighterFinishedEv in semantichighlighter.o
                                                                                                                                              //__ZN11QmlJSEditor19SemanticHighlighter8finishedEv in qmljssemantichighlighter.o
unimpl(
    _ZN10TextEditor19SemanticHighlighter38incrementalApplyExtraAdditionalFormatsEPNS_17SyntaxHighlighterERK7QFutureINS_18HighlightingResultEEiiRK5QHashIi15QTextCharFormatERKNSt3__18functionIFK5QListINSD_4pairIS4_10QTextBlockEEERKS4_RKSH_EEE);  //", referenced from:
                                                                                                                                                                                                                                                    //__ZN8CppTools19SemanticHighlighter28onHighlighterResultAvailableEii in semantichighlighter.o
                                                                                                                                                                                                                                                    //__ZN11QmlJSEditor19SemanticHighlighter12applyResultsEii in qmljssemantichighlighter.o
unimpl(
    _ZNK10TextEditor12TextDocument10isModifiedEv);  //", referenced from:
                                                    //__ZTVN10TextEditor12TextDocumentE
                                                    // in moc_textdocument.o
                                                    //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                    // in
                                                    // moc_cppeditordocument.o
                                                    //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                    // in
                                                    // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument11characterAtEi);  //", referenced from:
                                                     //__ZTVN10TextEditor12TextDocumentE
                                                     // in moc_textdocument.o
                                                     //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                     // in
                                                     // moc_cppeditordocument.o
                                                     //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                     // in
                                                     // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument11tabSettingsEv);  //", referenced from:
                                                     //__ZNK9CppEditor8Internal17CppEditorDocument11tabSettingsEv
                                                     // in cppeditordocument.o
                                                     //__ZTVN10TextEditor12TextDocumentE
                                                     // in moc_textdocument.o
                                                     //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                     // in
                                                     // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument12fontSettingsEv);  //", referenced from:
                                                      //__ZNK10TextEditor8TextMark15paintAnnotationER8QPainterP6QRectFddRK7QPointF
                                                      // in textmark.o
                                                      //__ZN9CppEditor8Internal16CppLocalRenaming5startEv
                                                      // in cpplocalrenaming.o
                                                      //__ZN9CppEditor8Internal16CppLocalRenaming4stopEv
                                                      // in cpplocalrenaming.o
                                                      //__ZNK9CppEditor8Internal16CppLocalRenaming14textCharFormatEN10TextEditor9TextStyleE
                                                      // in cpplocalrenaming.o
                                                      //__ZN9CppEditor8Internal23CppUseSelectionsUpdater17toExtraSelectionsERK7QVectorIN8CppTools10CursorInfo5RangeEEN10TextEditor9TextStyleE
                                                      // in
                                                      // cppuseselectionsupdater.o
                                                      //__ZN8CppTools19SemanticHighlighter31updateFormatMapFromFontSettingsEv
                                                      // in
                                                      // semantichighlighter.o
                                                      //__ZN11QmlJSEditor17QmlJSEditorWidget10updateUsesEv
                                                      // in qmljseditor.o
                                                      //...
unimpl(
    _ZNK10TextEditor12TextDocument14isFileReadOnlyEv);  //", referenced from:
                                                        //__ZTVN10TextEditor12TextDocumentE
                                                        // in moc_textdocument.o
                                                        //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                        // in
                                                        // moc_cppeditordocument.o
                                                        //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                        // in
                                                        // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument14shouldAutoSaveEv);  //", referenced from:
                                                        //__ZTVN10TextEditor12TextDocumentE
                                                        // in moc_textdocument.o
                                                        //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                        // in
                                                        // moc_cppeditordocument.o
                                                        //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                        // in
                                                        // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument15isSaveAsAllowedEv);  //", referenced from:
                                                         //__ZTVN10TextEditor12TextDocumentE
                                                         // in
                                                         // moc_textdocument.o
                                                         //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                         // in
                                                         // moc_cppeditordocument.o
                                                         //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                         // in
                                                         // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument15storageSettingsEv);  //", referenced from:
                                                         //__ZN9CppEditor8Internal17CppEditorDocument4saveEP7QStringRKS2_b
                                                         // in
                                                         // cppeditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument17syntaxHighlighterEv);  //", referenced from:
                                                           //__ZN10TextEditor11Highlighter6reloadEv
                                                           // in highlighter.o
                                                           //__ZN9CppEditor8Internal17CppEditorDocument17applyFontSettingsEv
                                                           // in
                                                           // cppeditordocument.o
                                                           //__ZN9QtPrivate18QFunctorSlotObjectIZN9CppEditor8Internal17CppEditorDocument9processorEvE3$_2Li1ENS_4ListIJ14QSharedPointerIN9CPlusPlus8DocumentEEEEEvE4implEiPNS_15QSlotObjectBaseEP7QObjectPPvPb
                                                           // in
                                                           // cppeditordocument.o
                                                           //__ZN8CppTools19SemanticHighlighter28onHighlighterResultAvailableEii
                                                           // in
                                                           // semantichighlighter.o
                                                           //__ZN8CppTools19SemanticHighlighter21onHighlighterFinishedEv
                                                           // in
                                                           // semantichighlighter.o
                                                           //__ZN11QmlJSEditor19SemanticHighlighter12applyResultsEii
                                                           // in
                                                           // qmljssemantichighlighter.o
                                                           //__ZN11QmlJSEditor19SemanticHighlighter8finishedEv
                                                           // in
                                                           // qmljssemantichighlighter.o
                                                           //...
unimpl(
    _ZNK10TextEditor12TextDocument18fallbackSaveAsPathEv);  //", referenced
                                                            // from:
                                                            //__ZTVN10TextEditor12TextDocumentE
                                                            // in
                                                            // moc_textdocument.o
                                                            //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                            // in
                                                            // moc_cppeditordocument.o
                                                            //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                            // in
                                                            // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument22fallbackSaveAsFileNameEv);  //", referenced
                                                                // from:
                                                                //__ZTVN10TextEditor12TextDocumentE
                                                                // in
                                                                // moc_textdocument.o
                                                                //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                                // in
                                                                // moc_cppeditordocument.o
                                                                //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                                // in
                                                                // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument22quickFixAssistProviderEv);  //", referenced
                                                                // from:
                                                                //__ZTVN10TextEditor12TextDocumentE
                                                                // in
                                                                // moc_textdocument.o
unimpl(
    _ZNK10TextEditor12TextDocument24completionAssistProviderEv);  //",
                                                                  // referenced
                                                                  // from:
                                                                  //__ZTVN10TextEditor12TextDocumentE
                                                                  // in
                                                                  // moc_textdocument.o
                                                                  //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                                  // in
                                                                  // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument26functionHintAssistProviderEv);  //",
                                                                    // referenced
                                                                    // from:
                                                                    //__ZTVN10TextEditor12TextDocumentE
                                                                    // in
                                                                    // moc_textdocument.o
                                                                    //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                                    // in
                                                                    // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument5marksEv);  //", referenced from:
                                              //__ZN10TextEditor16TextMarkRegistry15documentRenamedEPN4Core9IDocumentERK7QStringS6_
                                              // in textmark.o
unimpl(
    _ZNK10TextEditor12TextDocument6textAtEii);  //", referenced from:
                                                //__ZTVN10TextEditor12TextDocumentE
                                                // in moc_textdocument.o
                                                //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                // in moc_cppeditordocument.o
                                                //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                // in moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument8contentsEv);  //", referenced from:
                                                 //__ZTVN10TextEditor12TextDocumentE
                                                 // in moc_textdocument.o
                                                 //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                 // in moc_cppeditordocument.o
                                                 //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                 // in moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor12TextDocument8documentEv);  //", referenced from:
                                                 //__ZN8Debugger8Internal18getLocationContextEPN10TextEditor12TextDocumentEi
                                                 // in sourceutils.o
                                                 //__ZN9CppEditor8Internal9CppEditor14decorateEditorEPN10TextEditor16TextEditorWidgetE
                                                 // in cppeditor.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocumentC2Ev
                                                 // in cppeditordocument.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument24invalidateFormatterCacheEv
                                                 // in cppeditordocument.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument16onReloadFinishedEv
                                                 // in cppeditordocument.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument17onFilePathChangedERKN5Utils8FilePathES5_
                                                 // in cppeditordocument.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument32reparseWithPreferredParseContextERK7QString
                                                 // in cppeditordocument.o
                                                 //...
unimpl(
    _ZNK10TextEditor12TextDocument8indenterEv);  //", referenced from:
                                                 //__ZN10TextEditor15CodeStyleEditor13updatePreviewEv
                                                 // in codestyleeditor.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument17onFilePathChangedERKN5Utils8FilePathES5_
                                                 // in cppeditordocument.o
                                                 //__ZNK9CppEditor8Internal17CppEditorDocument11tabSettingsEv
                                                 // in cppeditordocument.o
                                                 //__ZN9CppEditor8Internal17CppEditorDocument4saveEP7QStringRKS2_b
                                                 // in cppeditordocument.o
                                                 //__ZNK8CppTools25CppRefactoringChangesData15indentSelectionERK11QTextCursorRK7QStringPKN10TextEditor12TextDocumentE
                                                 // in cpprefactoringchanges.o
                                                 //__ZNK8CppTools25CppRefactoringChangesData17reindentSelectionERK11QTextCursorRK7QStringPKN10TextEditor12TextDocumentE
                                                 // in cpprefactoringchanges.o
unimpl(
    _ZNK10TextEditor12TextDocument9plainTextEv);  //", referenced from:
                                                  //__ZTVN10TextEditor12TextDocumentE
                                                  // in moc_textdocument.o
                                                  //__ZTVN9CppEditor8Internal17CppEditorDocumentE
                                                  // in moc_cppeditordocument.o
                                                  //__ZTVN11QmlJSEditor19QmlJSEditorDocumentE
                                                  // in
                                                  // moc_qmljseditordocument.o
unimpl(
    _ZNK10TextEditor7Command10executableEv);  //", referenced from:
                                              //__ZN10TextEditorL6formatENS_10FormatTaskE
                                              // in formattexteditor.o
unimpl(
    _ZNK10TextEditor7Command10processingEv);  //", referenced from:
                                              //__ZN10TextEditorL6formatENS_10FormatTaskE
                                              // in formattexteditor.o
unimpl(
    _ZNK10TextEditor7Command11returnsCRLFEv);  //", referenced from:
                                               //__ZN10TextEditorL6formatENS_10FormatTaskE
                                               // in formattexteditor.o
unimpl(
    _ZNK10TextEditor7Command15pipeAddsNewlineEv);  //", referenced from:
                                                   //__ZN10TextEditorL6formatENS_10FormatTaskE
                                                   // in formattexteditor.o
unimpl(
    _ZNK10TextEditor7Command7optionsEv);  //", referenced from:
                                          //__ZN10TextEditorL6formatENS_10FormatTaskE
                                          // in formattexteditor.o
unimpl(
    _ZTVN4Core16BaseTextDocumentE);  //", referenced from:
                                     //__ZN4Core16BaseTextDocumentC2EP7QObject
                                     // in textdocument.o
                                     //__ZN4Core16BaseTextDocumentD2Ev in
                                     // textdocument.o
                                     //__ZN4Core16BaseTextDocumentD1Ev in
                                     // textdocument.o
                                     //__ZN4Core16BaseTextDocumentD0Ev in
                                     // textdocument.o

#endif
