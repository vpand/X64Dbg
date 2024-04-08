#ifndef __FAKE_WINDOWS_H__
#define __FAKE_WINDOWS_H__

#define _WIN64 1

#if __APPLE__ || __linux__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define __declspec(...)
#define DECLSPEC_ALIGN(n) __attribute__((aligned(n)))
#define __debugbreak abort

struct MEMORY_BASIC_INFORMATION {
  long BaseAddress;
  long RegionSize;
  long Type;
  long Protect;
  long AllocationProtect;
};
struct FILETIME {
  long dwLowDateTime;
  long dwHighDateTime;
};
#if __APPLE__
struct MSG {};
#else
struct tagMSG;
typedef tagMSG MSG;
#endif
struct RECT {
  int left, right;
  int top, bottom;
};
struct CRITICAL_SECTION {};
#define GUID_DEFINED // make Qt happy
typedef struct _GUID {
  unsigned long   Data1;
  unsigned short  Data2;
  unsigned short  Data3;
  unsigned char   Data4[8];
} GUID, *REFGUID, *LPGUID;
struct SHFILEINFO {
  void *hIcon;
};
struct SYSTEMTIME {
  int wDay;
  int wMonth;
  int wYear;
};
union LARGE_INTEGER {
  struct {
    unsigned int LowPart;
    unsigned int HighPart;
  };
  unsigned long long QuadPart;
};

typedef unsigned long long ULONGLONG;
typedef unsigned long ULONG64;
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned char BOOL;
typedef ULONGLONG ULONG_PTR;
typedef long long LONGLONG;
typedef void *HANDLE;
#if __APPLE__
typedef void *HWND;
#else
struct HWND__;
typedef HWND__ *HWND;
#endif
typedef size_t SIZE_T;
typedef const char *PCTSTR;
typedef const wchar_t *LPCTSTR;
typedef int INT;
typedef void *PVOID;
typedef void *LPVOID;
typedef void *HMODULE;
typedef int NTSTATUS;
#if __APPLE__
typedef void *HICON;
#else
struct HICON__;
typedef HICON__ *HICON;
#endif
typedef long LPARAM;
typedef int WPARAM;

#define MAX_PATH 1024
#define OutputDebugStringA puts
#define MessageBeep(...)
#define GetLastError() 0
#define strcpy_s strcpy
#define sprintf_s sprintf
#define sscanf_s sscanf
#define strncpy_s strncpy
#define _wfopen_helper(...) nullptr
#define _strcmpi strcmp
#define _aligned_malloc(size, align) malloc(size)
#define _aligned_free free
#define LoadLibrary(...) nullptr
#define FreeLibrary(...)
#define GetProcAddress(...) nullptr
#define Sleep(ms) sleep(ms / 1000)
#define SetWindowPos(...)
#define PlaySoundA(...)
#define IsWindowsVistaOrGreater() 0
#define IsWindowUnicode(...) 0
#define GetDesktopWindow() 0
#define GetClassLongPtrW(...) 0
#define GetClassLongPtrA(...) 0
#define DestroyIcon(...)
#define GetModuleHandleW(...) 0
#define LoadIcon(...) 0
#define GetTickCount() 0
#define SendMessageW(...)
#define SHGetFileInfoW(...) 0
#define FileTimeToLocalFileTime(...)
#define FileTimeToSystemTime(...)
#define SetFilePointerEx(...) 0
#define FindWindowW(...) 0
#define GetWindowThreadProcessId(...) 0
#define IsWindow(...) 0
#define GetSystemTimes(...)
#define MAKEFOURCC(...) 0
#define FIELD_OFFSET(...) 0
#define CreateFileW(...) 0
#define ReadFile(...) 0
#define GetFileSizeEx(...) 0
#define CloseHandle(...)

#define _countof(arr) (sizeof(arr) / sizeof((arr)[0]))

#define MEM_IMAGE 0
#define MEM_MAPPED 1
#define MEM_PRIVATE 2

#define HWND_TOPMOST 0
#define HWND_NOTOPMOST 0
#define SWP_NOMOVE 0
#define SWP_NOSIZE 0
#define SWP_NOACTIVATE 0
#define INVALID_HANDLE_VALUE (HANDLE) - 1
#define TRUE 1
#define FALSE 0
#define WM_SETICON 0
#define ICON_BIG 0
#define WM_SETICON 0
#define ICON_BIG 0
#define SHGFI_ICON 0
#define _TRUNCATE 128
#define WINAPI

#else
#include <Windows.h>
#include <stdlib.h>
#undef min
#undef max
#define strtoul strtoull
#endif

#endif  // end of __FAKE_WINDOWS_H__
