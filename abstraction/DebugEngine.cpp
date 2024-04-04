///////////////////////////////////YUNYOO.CN//////////////////////////////////////
//                                                                               *
// This file is part of A64Dbg and VMPStudio gui frontend project. *
//                                                                               *
// Copyright(C) 2021 YunYoo Corp., ALL RIGHTS RESERVED. *
//                                                                               *
// Internet: yunyoo.cn *
//                                                                               *
// This code is distributed "as is", part of YUNYOO.CN and without warranty of *
// any kind, expressed or implied, including, but not limited to warranty of *
// fitness for any particular purpose. In no event will YUNYOO.CN be liable to *
// you for any special, incidental, indirect, consequential or any other *
// damages caused by the use, misuse, or the inability to use of this code, *
// including anylost profits or lost savings, even if YUNYOO.CN has been advised
// * of the possibility of such damages. *
//                                                                               *
///////////////////////////////////////*//////////////////////////////////////////

#include <abstraction/DebugEngine.hpp>

namespace dbgapi {

Disassembler::Disassembler(const char *arch) {}

Disassembler::Disassembler(const char *arch, const char *triple) {}

Disassembler::~Disassembler() {}

bool Disassembler::ready() { return false; }

int Disassembler::disassemble(unsigned int mc, unsigned long long addr) {
  return 0;
}

int Disassembler::disassemble(unsigned int mc, std::string &text,
                              unsigned long long addr) {
  return 0;
}

int Disassembler::disassemble(const unsigned char *mc, int size,
                              unsigned long long addr) {
  return 0;
}

int Disassembler::disassemble(const unsigned char *mc, int size,
                              std::string &text, unsigned long long addr) {
  return 0;
}

uint64_t Disassembler::branchTarget(const unsigned char *mc, uint64_t addr,
                                    int *oplen, const void *gprs, bool *isptr) {
  return 0;
}

bool Disassembler::hitCondA64(const uint64_t *gprs, int n, int z, int c, int v,
                              unsigned mc) {
  return false;
}

bool Disassembler::hitCondA32(const uint64_t *gprs, int n, int z, int c, int v,
                              int t, unsigned mc) {
  return false;
}

bool Disassembler::hitCondX64(const uint64_t *gprs, uint64_t flags,
                              unsigned char *mc) {
  return false;
}

std::string Disassembler::demangle(const char *sym) { return ""; }

std::string Disassembler::assemble(const char *asmcode,
                                   unsigned char opcode[20]) {
  return "";
}

const char *Disassembler::parseOpcode(const char *asmcode,
                                      unsigned char opcode[20]) {
  return nullptr;
}

int Disassembler::name(unsigned opc, char str[32]) { return 0; }

int Disassembler::maxopc() { return 0; }

uint64_t Disassembler::dstAddr() { return 0; }

addr_t DbgBreakpoint::address() { return 0; }

bool DbgBreakpoint::isEnabled() { return false; }

bool DbgBreakpoint::isOneShot() { return false; }

bool DbgBreakpoint::isBreakpoint() { return false; }

bool DbgBreakpoint::isWatchpoint() { return false; }

int DbgBreakpoint::bitSize() { return 0; }

std::string DbgBreakpoint::condition() { return ""; }

void DbgBreakpoint::setEnabled(bool enable) {}

void DbgBreakpoint::setOneshot(bool oneshot) {}

void DbgBreakpoint::setCondition(const char *cond) {}

std::string DbgBreakpoint::responseId() { return ""; }

std::string DbgBreakpoint::moduleName() { return ""; }

std::string DbgBreakpoint::functionName() { return ""; }

LLDBEngine::LLDBEngine() {}

LLDBEngine::LLDBEngine(const DbgGuiOperator *guiops) {}

LLDBEngine::~LLDBEngine() {}

void LLDBEngine::start() {}

void LLDBEngine::shutdown() {}

mana::ArchType LLDBEngine::currentArch() { return mana::ARMV5TE; }

void LLDBEngine::command(const char *cmd) {}

bool LLDBEngine::commandResult(const char *cmd, char *buff, int size) {
  return false;
}

char *LLDBEngine::commandResult(const char *cmd) { return nullptr; }

int LLDBEngine::readMemory(addr_t addr, void *buff, int size, bool sync) {
  return 0;
}

int LLDBEngine::writeMemory(addr_t addr, const void *buff, int size) {
  return 0;
}

void LLDBEngine::setBreakpoint(addr_t addr, bool enable, bool oneshot,
                               const char *cond) {}

void LLDBEngine::setWatchpoint(addr_t addr, int bitsize) {}

void LLDBEngine::removeBreakpoint(DbgBreakpoint bp) {}

void LLDBEngine::updateBreakpoint(DbgBreakpoint bp) {}

std::vector<DbgBreakpoint> LLDBEngine::breakpoints() {
  std::vector<DbgBreakpoint> bps;
  return bps;
}

std::vector<DbgModule> LLDBEngine::moduleList() {
  std::vector<DbgModule> modules;
  return modules;
}

std::vector<DbgThread> LLDBEngine::threadList() {
  std::vector<DbgThread> threads;
  return threads;
}

std::vector<DbgFrame> LLDBEngine::frameList() {
  std::vector<DbgFrame> frames;
  return frames;
}

const char *LLDBEngine::moduleMapPath(const char *path) { return nullptr; }

bool LLDBEngine::findModule(addr_t base, DbgModule *module) { return false; }

void LLDBEngine::hypertraceInit(std::function<void(const hypertrace_database_t *db, int bytes)> dbrecv) {}

void LLDBEngine::hypertraceModule(DbgModule *module, bool on) {}

void LLDBEngine::hypertraceStart(hypertrace_type_t type) {}

void LLDBEngine::hypertraceStop(hypertrace_type_t type) {}

bool LLDBEngine::interpADCpp(const char *code, bool compile) { return false; }

void LLDBEngine::decacheDyld(const char *dyldcache, const char *outdir,
                             const char *name) {}

unsigned LLDBEngine::crc(const char *buff, int size) { return 0; }

void LLDBEngine::activeUraniumVM() {}

void LLDBEngine::activeLLDB() {}

unsigned LLDBEngine::uvmdbgPort() { return 0; }

void LLDBEngine::launchFileiOS(const char *ip, const char *app) {}

void LLDBEngine::launchFile(DbgPlatformType pt, const char *channel,
                            const char *file, const char *args) {}

void LLDBEngine::attachProcess(DbgPlatformType pt, int pidval,
                               const char *channel, const char *path) {}

void LLDBEngine::continueInferior() {}

void LLDBEngine::interruptInferior() {}

void LLDBEngine::shutdownInferior() {}

bool LLDBEngine::isDebugging() { return false; }

bool LLDBEngine::isTracing() { return false; }

void LLDBEngine::selectThread(const char *tid) {}

void LLDBEngine::reloadModules() {}

void LLDBEngine::reloadThreads() {}

void LLDBEngine::animateInto(bool into) {}

void LLDBEngine::traceSetLog(const char *log) {}

void LLDBEngine::traceSetCommand(const char *command) {}

void LLDBEngine::traceSetSwitchCond(const char *cond) {}

void LLDBEngine::traceSetLogFile(const char *file) {}

void LLDBEngine::traceSetBreakCond(const char *cond) {}

void LLDBEngine::traceSetBreakCount(int count) {}

void LLDBEngine::traceSetInit(bool into) {}

void LLDBEngine::traceSetRecordInit() {}

void LLDBEngine::traceStop(bool force) {}

void LLDBEngine::executeStepIn() {}

void LLDBEngine::executeStepOver() {}

void LLDBEngine::executeStepOut() {}

bool LLDBEngine::executeRunToBBE() { return false; }

UraniumEngine::UraniumEngine(const DbgGuiOperator *guiops) {}

UraniumEngine::~UraniumEngine() {}

std::string tburl_request(const char *ip, const char *command,
                          const char *body) {
  return "";
}

std::string tburl_request(const char *ip, const char *command,
                          const char *param, const char *body) {
  return "";
}

bool tbget_file_ex(const char *ip, const char *path, const char *savepath) {
  return false;
}

bool is_android_64(const char *adb, int pid, const char *exe) { return false; }

void adb_pull(const char *adb, const char *rfile, const char *locfile) {}

std::string adb_push(const char *adb, const char *file) { return ""; }

std::string adb_shell(const char *adb, const char *cmd, bool root) {
  return "";
}

namespace mana {

analyze_progress_t analyze_progress = [](const char *prefix, int cur, int max,
                                         int &tmp) {};

analyze_log_t analyze_log = printf;

Binary::Binary() {}

Binary::~Binary() {}

bool Binary::isCode(addr_t addr) { return false; }

bool Binary::isTextCode(addr_t addr) { return false; }

const Function *Binary::addrFunc(addr_t addr) const { return nullptr; }

const Section *Binary::addrSect(addr_t addr) const { return nullptr; }

const Section *Binary::nameSect(const char *name) const { return nullptr; }

const char *Binary::addrBuff(addr_t addr) const { return nullptr; }

bool Binary::valid() const { return false; }

bool Binary::load(const char *dbpath) { return false; }

bool Binary::save(const char *dbpath, bool compress) { return false; }

void Binary::dump() {}

const char *Binary::triple(bool thumb) const { return ""; }

const char *Binary::arch(bool thumb) const { return ""; }

FileType Binary::fileType() const { return UnsupportFile; }

const char *Binary::fileTypeString() const { return "UnsupportFile"; }

ArchType Binary::archType() const { return ARMV5TE; }

const char *Binary::archTypeString() const { return "UNIMPL"; }

Sections &Binary::sections() {
  static Sections sects;
  return sects;
}

SectionBuffs &Binary::sectBuffers() {
  static SectionBuffs buffs;
  return buffs;
}

Functions &Binary::functions() {
  static Functions funs;
  return funs;
}

Function &Binary::insertFunc(addr_t addr) {
  static Function fun;
  return fun;
}

std::vector<const char *> Binary::importLibs() const {
  std::vector<const char *> results;
  return results;
}

std::vector<const char *> Binary::importMachOLibs() const {
  std::vector<const char *> results;
  return results;
}

std::vector<const char *> Binary::importELFLibs() const {
  std::vector<const char *> results;
  return results;
}

std::vector<const char *> Binary::importPELibs() const {
  std::vector<const char *> results;
  return results;
}

void Binary::readObj(std::string &outs) const {}

addr_t Binary::imageBase() const { return 0; }

const char *Binary::filePath() const { return ""; }

const char *Binary::fileBuffer(size_t &size) const { return ""; }

void Binary::analyzeFunc(Disassembler *diser, const char *opcodes,
                         Function &func) {}

bool Binary::analyze(const void *llvmbin) { return false; }

ImportInfos ELFBinary::parseImports() { return ImportInfos(); }

void KamiBinary::initLLVM(const char *opcodes, int opcsize) {}

Binary *New(const char *path, const char *triple, bool analyze) {
  return nullptr;
}

void Delete(Binary *bin) {}

void compressDBFile(const char *dbpath) {}

ManaFile *uncompressDBFile(const char *dbpath) { return nullptr; }

bool compressBuffer(const char *buff, int size, std::string *out) { return false; }

bool uncompressBuffer(const char *buff, int size, int realsize, std::string *out) { return false; }

}// namespace mana

UraniumVMServer::UraniumVMServer() {}

UraniumVMServer::~UraniumVMServer() {}

void UraniumVMServer::start(
    std::function<void()> income,
    std::function<void(UVMDBG_CommandType, const char *, int, uint64_t)>
        protocol) {}

void UraniumVMServer::stop() {}

int UraniumVMServer::send(UVMDBG_CommandType type, const char *buf,
                          size_t bufsz, uint64_t extra) {
  return 0;
}

void UraniumVMServer::disconnect() {}

const char *UraniumVMServer::local_ip() { return nullptr; }

#if __APPLE__
UVMServer::UVMServer() {}

UVMServer::~UVMServer() {}

void UVMServer::start() {}

void UVMServer::stop() {}
#endif

UVMClient::UVMClient() {}

UVMClient::~UVMClient() {}

void UVMClient::connect(
    const char *remoteip,
    std::function<void(UVMSVR_CommandType, const char *, int, uint64_t)>
        protocol) {}

void UVMClient::close() {}

int UVMClient::send(UVMSVR_CommandType type, const char *buf, size_t bufsz,
                    uint64_t extra) {
  return 0;
}

bool UVMClient::valid() { return false; }

void UVMClient::cloudPort(std::function<void(int)> callback) {}

int retdec_main(const char *input, const char *output, addr_t start, addr_t end,
                addr2name_cb_t addr2name) {
  return -1;
}

int urdyndec_main(urdec_params_t *params, addr2name_cb_t addr2name) {
  return -1;
}

int sampledb_main(sample_params_t *params) {
  return -1;
}

}  // namespace dbgapi
