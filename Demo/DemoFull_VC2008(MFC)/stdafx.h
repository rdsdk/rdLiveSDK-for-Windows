
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


#include "..\Include\RDLiveSDK.h"
#pragma comment ( lib, "..\\Lib\\RDLiveSDK.lib" )

#import "msxml3.dll" 

using namespace MSXML2;


#define WM_MYNotify	(WM_USER+10)//后台提示

#define WM_CAMERA	(WM_USER+200)
	
#define WM_SCREEN	(WM_USER+250)
#define WM_HWND		(WM_USER + 270 )
#define WM_WH_16_9  (WM_USER + 500) //16:9分辨率
#define WM_WH_4_3  (WM_USER + 550) //16:9分辨率
#define WM_WH_CIF  (WM_USER + 600)//CIF分辨率
#define WM_WH_USER  (WM_USER + 650)//自定义分辨率

#define  WM_WH_FPS (WM_USER + 700)//帧率
#define  WM_WH_WH (WM_USER + 710)//缩放比例

#define WM_SECNE_Switch (WM_USER + 750)

#define WM_SECNE_Dletel (WM_USER + 850)

#define WM_SECNE_Rename  (WM_USER + 951)

#define WM_SECNE_Layout  (WM_USER + 1051)

#define WM_SECNE_location (WM_USER + 1151)

#define WM_AUDIO_Speaker ( WM_USER + 1251 )//扬声器
#define WM_AUDIO_MIC ( WM_USER + 1301 )//MIC

#define WM_IAMGE ( WM_USER + 1351 ) //图片添加

#define WM_Encoder_ENotify ( WM_USER + 1352 )

//#define  
//按钮的状态  
enum  
{  
	CTRL_NOFOCUS = 0x01,            //普通  
	CTRL_FOCUS,                     //mousemove  
	CTRL_SELECTED,                  //buttondown  
	CTRL_DISABLE,                   //无效  
};  

//图片形式  
enum  
{  
	BTN_IMG_1 = 1,                  //  
	BTN_IMG_3 = 3,                  //3分图（1个图片内有3小图，下同）  
	BTN_IMG_4 = 4,                  //4分图  
};  

//按钮类型  
enum  
{  
	BTN_TYPE_NORMAL = 0x10,         //普通BTN  
	BTN_TYPE_MENU,                  //菜单类型的BTN  
	BTN_TYPE_STATIC,                //静态类型的BTN  
};  

#include <gdiplus.h>                //

using namespace Gdiplus;            //使用GDI+的命名空间, 若不用的话每次使用Gdiplus时均加上命名空间亦可
#pragma comment(lib, "gdiplus.lib") //在工程属性中添加亦可


CString Getattrib( LPWSTR szattrib , bool bIsInterface = TRUE  );//读取属性

BOOL Settattrib( LPWSTR szattrib, CString szValue, bool bIsInterface = TRUE   );//设置属性

BOOL Creatattrib( LPWSTR szNode, LPWSTR szattrib,CString szValue, bool bIsInterface  = TRUE  );//创建属性

