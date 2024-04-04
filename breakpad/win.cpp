#include <client/windows/handler/exception_handler.h>
#include <QString>

extern "C" void install_breakpad(const char *dumpdir, const char *prod, const char *vers) {
#ifdef QT_NO_DEBUG
  new google_breakpad::ExceptionHandler(
        QString(dumpdir).toStdWString(), NULL, NULL, NULL,
        google_breakpad::ExceptionHandler::HANDLER_ALL);
#endif
}
