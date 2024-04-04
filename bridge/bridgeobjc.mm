#import <Foundation/Foundation.h>
#import <string>

std::string app_executable(const char *app) {
  std::string exe(app);
  @autoreleasepool {
    NSString *plistpath = [NSString stringWithFormat:@"%s/Contents/Info.plist", app];
    NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:plistpath];
    if (!dict) {
      return exe;
    }
    NSString *exename = [dict objectForKey:@"CFBundleExecutable"];
    if (!exename) {
      return exe;
    }
    exe += "/Contents/MacOS/";
    exe += exename.UTF8String;
  }
  return exe;
}
