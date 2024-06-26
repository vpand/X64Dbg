#ifndef TRACEFILESEARCH_H
#define TRACEFILESEARCH_H

#include "UVMGlobal.h"
#include "VMPBridge.h"

class TraceFileReader;

int TraceFileSearchConstantRange(TraceFileReader* file, duint start, duint end);
int TraceFileSearchMemReference(TraceFileReader* file, duint address);
#endif  // TRACEFILESEARCH_H
