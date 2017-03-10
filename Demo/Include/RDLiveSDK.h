#ifndef	_RDLIVESDK_HEAD_
#define	_RDLIVESDK_HEAD_
#include "windows.h"
#include "IGlRenderDefine.h"
#include "GEncoderParams.h"

#ifdef __cplusplus
extern "C"
{
#endif

BOOL	WINAPI RDLive_Init( LPCWSTR szOrganizationName, LPCWSTR szApplicationName,
						   fnRenderNotifyCB pCbRender, fnEncoderNotifyCB pCbEncoder, LPVOID pCbParam );
VOID	WINAPI RDLive_Uninit();

enum	ERdLiveAccreditType
{
	eAccreditLocalSave,		//授权本地保存
	eAccreditRtmpLive,		//授权RTMP直播
	eAccreditCloudLive,		//授权RD云直播
};
BOOL	WINAPI RDLive_ResetAccredit( LPCSTR szAppKey, LPCSTR szAppSecret );
FLOAT	WINAPI RDLive_GetAccreditDays( ERdLiveAccreditType eAccreditType );

//系统默认文件夹的类型。
enum	ERecDefaultDirs
{
	RDir_Application,		//程序运行的文件夹
	RDir_Profile,			//存放配置文件的默认文件夹。eg: C:\Users\UserName\AppData\Local\17rd\RDLiveSDK 
	RDir_Videos,			//存放视频文件的默认文件夹。eg: C:\Users\UserName\Videos\RDLiveSDK 
	RDir_Audios,			//存放音频文件的默认文件夹。eg: C:\Users\UserName\Music\RDLiveSDK 
	RDir_Images,			//存放图片文件的默认文件夹。eg: C:\Users\UserName\Pictures\RDLiveSDK 

};
LPCWSTR	WINAPI RDLive_DefaultDir( ERecDefaultDirs eDir );

BOOL	WINAPI Render_SetSize( INT iWidth, INT iHeight );
SIZE	WINAPI Render_GetSize();
BOOL	WINAPI Render_SetFps( FLOAT fps );
FLOAT	WINAPI Render_GetFps();

INT		WINAPI Render_GetClassCount();
IGlRender_SClassInfo		WINAPI Render_GetClassInfo( INT iIndex );


//功能：重设预览画面显示布局和百分比，并计算出需要的主窗口等的大小。
//参数：pLayout		[in,out]	SPreviewLayout 结构的指针，请务必详细阅读 SPreviewLayout 结构中的注释。
//返回：TRUE 表示成功，FALSE 表示失败，可以使用 RDLive_LastError 取得错误代码。
BOOL	WINAPI Render_SetPreviewLayout( IGlRender_SPreviewLayout* pLayout );
const IGlRender_SPreviewLayout* WINAPI Render_GetPreviewLayout();
//当不使用OpenGL加速，而通过回调获得预览图像时，需要在鼠标在预览的显示区域进行操作的时候，
//由上层调用者把鼠标消息发送到预览。
//目前只处理以下消息，x 和 y 参数都是以预览图像绘制区域左上角为原点的鼠标坐标。
//WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_LBUTTONUP, WM_RBUTTONDOWN, WM_RBUTTONUP
//返回值是当前应该显示的鼠标指针形状的句柄
HCURSOR WINAPI Render_SendPreviewMouseMessage( UINT uMsg, WPARAM wParam, int iX, int iY );

INT		WINAPI Render_GetSceneCount();
HSCENE	WINAPI Render_GetScene( INT iIndex );
HSCENE	WINAPI Render_CreateScene();
BOOL	WINAPI Render_DestroyScene( HSCENE hScene );
BOOL	WINAPI Render_SetCurScene( HSCENE hScene );
HSCENE	WINAPI Render_GetCurScene();
INT		WINAPI Render_GetSceneIndex( HSCENE hScene );
BOOL	WINAPI Render_SetBSceneScroll( INT iValue );
INT		WINAPI Render_GetBSceneScroll();

INT		WINAPI Scene_GetChipCount( HSCENE hScene );
HCHIP	WINAPI Scene_GetChip( HSCENE hScene, INT iIndex );

HCHIP	WINAPI Scene_CreateChip( HSCENE hScene );
HCHIP	WINAPI Sceen_GetCurChip( HSCENE hScene );
LPCWSTR WINAPI Scene_GetName( HSCENE hScene );
BOOL	WINAPI Scene_SetName( HSCENE hScene, LPCWSTR szName );
///////////////////////////////////
INT		WINAPI Chip_GetIndex( HCHIP hChip, HSCENE* pScene );
BOOL	WINAPI Chip_SetIndex( HCHIP hChip, INT iIndex );
BOOL	WINAPI Chip_Destroy( HCHIP hChip );
BOOL	WINAPI Chip_SetCurent( HCHIP hChip );
//////////////////////////////////////////////////////

BOOL	WINAPI Chip_Open( HCHIP hChip, LPCWSTR szTypeName, LPCWSTR szResource, BOOL bCannotReuse = FALSE, DWORD_PTR ptrParam = NULL );
BOOL	WINAPI Chip_Close( HCHIP hChip );
BOOL	WINAPI Chip_SetRect( HCHIP hChip, INT iX, INT iY, INT iWidth, INT iHeight, IChip_EBorderFitMode eFitMode );
BOOL	WINAPI Chip_GetRect( HCHIP hChip, PINT pX, PINT pY, PINT pWidth, PINT pHeight, BOOL bRealDisplay );
BOOL	WINAPI Chip_SetRectPercent( HCHIP hChip, FLOAT fX, FLOAT fY, FLOAT fWidth, FLOAT fHeight, IChip_EBorderFitMode eFitMode );
BOOL	WINAPI Chip_GetRectPercent( HCHIP hChip, PFLOAT pX, PFLOAT pY, PFLOAT pWidth, PFLOAT pHeight, BOOL bRealDisplay );
BOOL	WINAPI Chip_SetClipPercent( HCHIP hChip, FLOAT fLeft, FLOAT fTop, FLOAT fRight, FLOAT fBottom );
BOOL	WINAPI Chip_GetClipPercent( HCHIP hChip, PFLOAT pLeft, PFLOAT pTop, PFLOAT pRight, PFLOAT pBottom );

BOOL	WINAPI Chip_SetViewLock( HCHIP hChip, IChip_ELockType eLockType, BOOL bLock );
BOOL	WINAPI Chip_GetViewLock( HCHIP hChip, IChip_ELockType eLockType );
BOOL	WINAPI Chip_SetVolume( HCHIP hChip, FLOAT fVolume, BOOL bMute );
FLOAT	WINAPI Chip_GetVolume( HCHIP hChip, PBOOL pMute );
BOOL	WINAPI Chip_SetVisible( HCHIP hChip, BOOL bVisible );
BOOL	WINAPI Chip_IsVisible( HCHIP hChip );

IPinInput_EChipStatus		WINAPI Chip_GetStatus( HCHIP hChip );
BOOL	WINAPI Chip_GetStatusInfo( HCHIP hChip, IPinInput_SStatusInfo* pStatus );
BOOL	WINAPI Chip_GetCharacteristics( HCHIP hChip, IPinInput_SCharacteristics* pCharacter );
LPCWSTR	WINAPI Chip_GetClassName( HCHIP hChip );
LPCWSTR	WINAPI Chip_GetSourceName( HCHIP hChip );

////////////////////////////////////////////////////////////////
INT		WINAPI Camera_GetCount();
LPCWSTR	WINAPI Camera_GetFriendlyName( INT iIndex );
LPCWSTR	WINAPI Camera_GetDisplayName( INT iIndex );
INT		WINAPI Camera_GetIndex( LPCWSTR szDisplayName );

INT		WINAPI Screen_GetCount();
BOOL	WINAPI Screen_GetInfo( INT iIndex, MONITORINFOEXW* pMonitorInfo );
LPCWSTR	WINAPI Screen_AssembleSource( IScreen_SCapParams* pParams );
BOOL	WINAPI Screen_AnalysisSource( LPCWSTR szSource, IScreen_SCapParams* pParams  );

//音频捕获设备的类型
enum	EAudioCaptureDev
{
	eAudCap_Speaker		= 1,	//输出设备，如扬声器等发出的声音
	eAudCap_Microphone	= 2,	//输出设备，如果麦克风等
};
INT		WINAPI Audio_GetDevCount( EAudioCaptureDev eDev );
LPCWSTR	WINAPI Audio_GetDevName( EAudioCaptureDev eDev, UINT iIndex );
LPCWSTR WINAPI Audio_GetDevId( EAudioCaptureDev eDev, UINT iIndex );
LPCWSTR	WINAPI Audio_GetCurrent( EAudioCaptureDev eDev );
BOOL	WINAPI Audio_SetCurrent( EAudioCaptureDev eDev, LPCWSTR szDevId );
BOOL	WINAPI Audio_IsEnabled( EAudioCaptureDev eDev );
BOOL	WINAPI Audio_Enable( EAudioCaptureDev eDev, BOOL bIsEnable );
FLOAT	WINAPI Audio_GetVolume( EAudioCaptureDev eDev );
BOOL	WINAPI Audio_SetVolume( EAudioCaptureDev eDev, FLOAT fVolume );

////////////////////////////////////////////////////////////////
BOOL	WINAPI Encoder_IsUsable( EVideoEncoder eEncoder,
								LPDWORD pSupportProfileMask, 
								LPDWORD pSupportPresetMask, 
								LPDWORD pSupportColorSpaceMask );
BOOL	WINAPI Encoder_SetCurrent( EVideoEncoder eEncoder );
EVideoEncoder	WINAPI Encoder_GetCurrent();
BOOL	WINAPI Encoder_SetProfile( EVideoEncoder eEncoder, EVideoProfile eProfile );
EVideoProfile	WINAPI Encoder_GetProfile( EVideoEncoder eEncoder );
BOOL	WINAPI Encoder_SetPreset( EVideoEncoder eEncoder, EVideoPreset ePreset );
EVideoPreset	WINAPI Encoder_GetPreset( EVideoEncoder eEncoder );

BOOL	WINAPI Encoder_SetBitrate( EVideoRateMode eMode, INT iBitrate, INT iBitrateMax, INT iVbvSize );
BOOL	WINAPI Encoder_GetBitrate( EVideoRateMode* pMode, INT* pBitrate, INT* pBitrateMax, INT* pVbvSize );
BOOL	WINAPI Encoder_SetFrameParams( INT iGop, INT iGopMin, INT iRefFrames, INT iBFrames );
BOOL	WINAPI Encoder_GetFrameParams( INT* pGop, INT* pGopMin, INT* pRefFrames, INT* pBFrames );
BOOL	WINAPI Encoder_SetAudioParams( WORD nChannels, EAudioInSamples eSample, WORD wBits, EAudioEncoder eEncoder, INT iEncBitsRate );
BOOL	WINAPI Encoder_GetAudioParam( WORD* pChannels, EAudioInSamples* pSample, WORD* pBits, EAudioEncoder* pEncoder, INT* pEncBitsRate );

INT		WINAPI Encoder_AddSaveFile( SEncoderSaveFile* pSaveFile );
INT		WINAPI Encoder_GetSaveFileCount();
BOOL	WINAPI Encoder_GetSaveFileInfo( INT iIndex, SEncoderSaveFile* pSaveFile );
BOOL	WINAPI Encoder_RemoveSaveFile( INT iIndex );

BOOL	WINAPI Encoder_Start();
BOOL	WINAPI Encoder_End();

#ifdef __cplusplus
}
#endif

#endif