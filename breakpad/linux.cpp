#include <client/linux/handler/exception_handler.h>

extern "C" void install_breakpad(const char *dumpdir, const char *prod, const char *vers) {
  google_breakpad::MinidumpDescriptor descriptor(dumpdir);
  new google_breakpad::ExceptionHandler(descriptor, NULL, NULL, NULL, true, -1);
}
