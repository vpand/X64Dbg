#pragma once

#include "_dbgfunctions.h"
#include "_global.h"

bool TcpEnumConnections(duint pid, std::vector<TCPCONNECTIONINFO>& connections);
