#include "BridgeResult.h"

#include <QCoreApplication>

#include "Bridge.h"

BridgeResult::BridgeResult(Type type) : mType(type) {
  Bridge* bridge = Bridge::getBridge();
  // EnterCriticalSection(&bridge->csBridge);
#ifdef DEBUG
  OutputDebugStringA(QString()
                         .sprintf("[x64dbg] [%u] BridgeResult(%d)\n",
                                  GetCurrentThreadId(), type)
                         .toUtf8()
                         .constData());
#endif  // DEBUG
  // ResetEvent(bridge->resultEvents[type]);
}

BridgeResult::~BridgeResult() {
#ifdef DEBUG
  OutputDebugStringA(QString()
                         .sprintf("[x64dbg] [%u] ~BridgeResult(%d)\n",
                                  GetCurrentThreadId(), mType)
                         .toUtf8()
                         .constData());
#endif  // DEBUG
  // LeaveCriticalSection(&Bridge::getBridge()->csBridge);
}

dsint BridgeResult::Wait() {
#ifdef DEBUG
  OutputDebugStringA(QString()
                         .sprintf("[x64dbg] [%u] BridgeResult::Wait(%d)\n",
                                  GetCurrentThreadId(), mType)
                         .toUtf8()
                         .constData());
#endif  // DEBUG
  Bridge* bridge = Bridge::getBridge();
  HANDLE hResultEvent = bridge->resultEvents[mType];
#ifdef DEBUG
  OutputDebugStringA(QString()
                         .sprintf("[x64dbg] [%u] BridgeResult::~Wait(%d)\n",
                                  GetCurrentThreadId(), mType)
                         .toUtf8()
                         .constData());
#endif  // DEBUG
  return bridge->bridgeResults[mType];
}
