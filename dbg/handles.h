#ifndef HANDLES_H
#define HANDLES_H

#include "_dbgfunctions.h"
#include "_global.h"

bool HandlesEnum(duint pid, std::vector<HANDLEINFO>& handlesList);
bool HandlesGetName(HANDLE hProcess, HANDLE remoteHandle, String& name,
                    String& typeName);
bool HandlesEnumWindows(std::vector<WINDOW_INFO>& windowsList);
bool HandlesEnumHeaps(std::vector<HEAPINFO>& heapList);

#endif  // HANDLES_H