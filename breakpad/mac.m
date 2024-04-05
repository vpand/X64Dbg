#import <Breakpad.h>

void install_breakpad(const char *dumpdir, const char *prod, const char *vers) {
  // setenv("BREAKPAD_IGNORE_DEBUGGER", "1", 1);
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSDictionary *plist = [[NSBundle mainBundle] infoDictionary];
  NSMutableDictionary *dict = [NSMutableDictionary new];
  [dict addEntriesFromDictionary:plist];
  [dict setObject:@1 forKey:@BREAKPAD_IN_PROCESS];
  [dict setObject:[NSString stringWithUTF8String:dumpdir] forKey:@BREAKPAD_DUMP_DIRECTORY];
  [dict setObject:@"vpand.com/breakpad" forKey:@BREAKPAD_URL];
  [dict setObject:[NSString stringWithUTF8String:prod] forKey:@BREAKPAD_PRODUCT];
  [dict setObject:[NSString stringWithUTF8String:vers] forKey:@BREAKPAD_VERSION];
  [dict setObject:@"vpand.com" forKey:@BREAKPAD_VENDOR];
  if (!BreakpadCreate(dict)) {
    NSLog(@"Failed to create breakpad crash dumper instance : %@", dict);
  }
  [pool release];
}
