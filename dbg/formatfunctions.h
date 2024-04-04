#pragma once

#include <functional>

//#include "_global.h"
#include "stringutils.h"
#if 0
#include "_plugins.h"
#else
typedef enum {
  FORMAT_ERROR,          // generic failure (no message)
  FORMAT_SUCCESS,        // success
  FORMAT_ERROR_MESSAGE,  // formatting failed but an error was put in the buffer
                         // (there are always at least 511 characters available).
  FORMAT_BUFFER_TOO_SMALL  // buffer too small (x64dbg will retry until the
                           // buffer is big enough)
} FORMATRESULT;
#endif

class FormatFunctions {
 public:
  using CBFORMATFUNCTION =
      std::function<FORMATRESULT(char* dest, size_t destCount, int argc,
                                 char* argv[], duint value, void* userdata)>;

  static void Init();
  static bool Register(const String& type, const CBFORMATFUNCTION& cbFunction,
                       void* userdata = nullptr);
  static bool RegisterAlias(const String& type, const String& alias);
  static bool Unregister(const String& type);
  static bool Call(std::vector<char>& dest, const String& type,
                   std::vector<String>& argv, duint value);

 private:
  struct Function {
    String type;
    CBFORMATFUNCTION cbFunction;
    void* userdata = nullptr;
    std::vector<String> aliases;
  };

  static bool isValidName(const String& name);

  static std::unordered_map<String, Function> mFunctions;
};
