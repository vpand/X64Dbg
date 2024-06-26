#ifndef _SCRIPTAPI_GUI_H
#define _SCRIPTAPI_GUI_H

#include "_scriptapi.h"

namespace Script {
namespace Gui {
namespace Disassembly {
SCRIPT_EXPORT bool SelectionGet(duint* start, duint* end);
SCRIPT_EXPORT bool SelectionSet(duint start, duint end);
SCRIPT_EXPORT duint SelectionGetStart();
SCRIPT_EXPORT duint SelectionGetEnd();
};  // namespace Disassembly

namespace Dump {
SCRIPT_EXPORT bool SelectionGet(duint* start, duint* end);
SCRIPT_EXPORT bool SelectionSet(duint start, duint end);
SCRIPT_EXPORT duint SelectionGetStart();
SCRIPT_EXPORT duint SelectionGetEnd();
};  // namespace Dump

namespace Stack {
SCRIPT_EXPORT bool SelectionGet(duint* start, duint* end);
SCRIPT_EXPORT bool SelectionSet(duint start, duint end);
SCRIPT_EXPORT duint SelectionGetStart();
SCRIPT_EXPORT duint SelectionGetEnd();
};  // namespace Stack

namespace Graph {
SCRIPT_EXPORT duint SelectionGetStart();
};  // namespace Graph

namespace MemMap {
SCRIPT_EXPORT duint SelectionGetStart();
};  // namespace MemMap

namespace SymMod {
SCRIPT_EXPORT duint SelectionGetStart();
};  // namespace SymMod
};  // namespace Gui

namespace Gui {
enum Window {
  DisassemblyWindow,
  DumpWindow,
  StackWindow,
  GraphWindow,
  MemMapWindow,
  SymModWindow
};

SCRIPT_EXPORT bool SelectionGet(Window window, duint* start, duint* end);
SCRIPT_EXPORT bool SelectionSet(Window window, duint start, duint end);
SCRIPT_EXPORT duint SelectionGetStart(Window window);
SCRIPT_EXPORT duint SelectionGetEnd(Window window);
SCRIPT_EXPORT void Message(const char* message);
SCRIPT_EXPORT bool MessageYesNo(const char* message);
SCRIPT_EXPORT bool InputLine(const char* title,
                             char* text);  // text[GUI_MAX_LINE_SIZE]
SCRIPT_EXPORT bool InputValue(const char* title, duint* value);
SCRIPT_EXPORT void Refresh();
SCRIPT_EXPORT void AddQWidgetTab(void* qWidget);
SCRIPT_EXPORT void ShowQWidgetTab(void* qWidget);
SCRIPT_EXPORT void CloseQWidgetTab(void* qWidget);

};  // namespace Gui
};  // namespace Script

#endif  //_SCRIPTAPI_GUI_H