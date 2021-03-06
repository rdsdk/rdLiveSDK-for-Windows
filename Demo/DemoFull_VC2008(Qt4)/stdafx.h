﻿#ifndef WINVER                  // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0500           // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT            // 指定要求的最低平台是 Windows Vista。
#define _WIN32_WINNT 0x0500     // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif


#include <Windows.h>
#include <QtGui>
#include <QDomDocument>

#include "..\Include\RDLiveSDK.h"
//如果使用 VC 的编译器就用 #pragma 来告诉编译器需要的 lib 文件。
#ifdef  _MSC_VER
#pragma comment ( lib, "..\\Lib\\RDLiveSDK.lib" )
#pragma comment ( lib, "shell32.lib" )
#pragma comment ( lib, "user32.lib" )
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE(x) ( sizeof(x) / sizeof(x[0]) )
#endif

#define QFU(str) (QString::fromUtf16((const ushort*)(str)))
