// SimpleDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//场景编辑的回调
VOID WINAPI RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, INT iValue, LPVOID pCbParam )
{
}
//视频编码存储上传的回调，作为类成员函数时，声明时应该加上 static 标识，否则不能作为回调函数使用。
VOID WINAPI EncoderNotifyCB( IEncoder_ENotify eNotify, DWORD dwValue, DWORD_PTR ptrValue, LPVOID pCbParam )
{
	if ( eNotify == eEncNotify_AcceditDone )
	{
		if ( dwValue )
		{
			printf( "Accedit Success.\nLocal Save=%f days\nRtmp Live=%f days\nCloud Live=%f days\n",
				RDLive_GetAccreditDays(eAccreditLocalSave),
				RDLive_GetAccreditDays(eAccreditRtmpLive),
				RDLive_GetAccreditDays(eAccreditCloudLive) );
		}
		else
		{
			printf( "Accedit Fail!\n" );
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//初始化 SDK。公司名和产品名参数主要是为了生成保存各种文件的默认路径。
	if ( !RDLive_Init( L"17RD", L"RDLiveSdkDemo",
				RenderNotifyCB, EncoderNotifyCB, 0 ) )
	{
		//失败处理
		printf( "Init Fail, Error=%1\n", GetLastError() );
	}
	//验证 SDK 的授权信息。调用此接口时，如果已经联网，那么会从本公司网站异步获得最新的授权信息。
	//注意，因为从网站获得最新授权信息是异步的，所以在更新成功后，会通过回调函数通知。
	if ( !RDLive_ResetAccredit( "d3200cc987431827", 
		"77a9eeea008524e8bdf10e18409cbdb3sULczML4CjomZFtst04v/HLUrHqWT72Mmkz7WhUEmpjXMH7/UWz5oGMwUGQPbYX+MKSpM01lSGQ/qNzCkFFyKXSwxrKIViR4iZ7ZxOuB6n80wDeCV7jHJSEN1+DqlCLm3dJWQF3CFLMOj2YJxwI/YDY9h3SjCsWFz9j/71RCHH0FWpr13vMRM6a1uRCnke2Tyly/V4S4E7BE1tR6WDcxNQTeX9w399l/EpNb8LvBNNUz6shNmM627BGBfTbPG2vj+grPaxv1rFcVRqNkT45Jrjvjp3PV8L6Py7fCUvK5PJ0Pb/olb9q/M2Yom+AZkSlE0FDcSKb0MG+QCE9f1MYacjFoU31o7cZb5ZQZ++7lMqXMDvTi9LyTYR+0lDKKwFC8EJ43/upbIuhawyXQ2w4u7Zvv9IUXqhamlTUirPmuV4lSVypdzCT+gPdEjq9krLLjRajAMutBwefKiHdrp/h65BxTErT94rH7OAU6bCmbX/o=" ) )
	{
		//失败处理
		printf( "ResetAccredit Fail, Error=%1\n", GetLastError() );
	}

	//设置想要录制、直播的视频分辨率
	if ( FALSE == Render_SetSize( 1280, 720 ) )
	{
		//失败处理
	}
	//设置想要录制、直播的视频帧率 
	if ( FALSE == Render_SetFps( 25.0f ) )
	{
		//失败处理
	}

	//创建一个场景。得到场景句柄，之后对该场景的操作，都通过句柄来完成。
	HSCENE hScene = Render_CreateScene();
	//创建一个元件。得到元件句柄。之后对该元件的操作，都通过句柄来完成。
	HCHIP hChip = Scene_CreateChip( hScene );

	//为元件设置图像来源。这里设置为录制第一个屏幕。
	if ( FALSE == Chip_Open( hChip, L"Screen", L"0", FALSE, NULL ) )
	{
		//错误处理 
		printf( "Open Chip Fail, Error=%d\n", GetLastError() );
	} 
	//设置元件显示。新创建的元件默认是隐藏的，不会绘制，因此要设置为显示。
	Chip_SetVisible( hChip, TRUE );

	//检查摄像头的数量，如果有摄像头，就把第一个摄像头的画面放在整个画面的右下角
	int		iCameraCount	= Camera_GetCount();
	if ( iCameraCount )
	{
		HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene() );
		if ( hChip )
		{
			//打开第一个摄像头
			if ( Chip_Open( hChip, L"Camera", Camera_GetDisplayName( 0 ) ) )
			{
			}
			//之前设置的视频分辨率为 1280x720，这里设置一个 320x240 的摄像头画面到右下方。
			Chip_SetRect( hChip, 900, 450, 320, 240, eKeepAspectRatio );
			Chip_SetVisible( hChip, TRUE );
		}
	}

	//设置视频编码器为 x264。
	Encoder_SetCurrent( VE_X264 );
	//设置 x264 编码器的 Perset 为 Medium。
	Encoder_SetPreset( VE_X264, VP_x264_Medium );
	//设置码率为 1000Kbps，模式为“平均码率”。 
	Encoder_SetBitrate( VR_AverageBitrate, 1000, 0, 0 ); 
	//设置录音的参数为 2 声道，22050hz 16bit 采样率，AAC 编码，码率 96Kbps。 
	Encoder_SetAudioParams( 2, Aud_Inp_Samp_22050, 16, Aud_Enc_AAC, 96 );
	//设置保存文件和直播信息的相关结构。
	SEncoderSaveFile sFile;
	ZeroMemory( &sFile, sizeof( sFile ) );
	sFile.eContainer = Mix_FLV;    //设置文件格式为 FLV
	sFile.szSavePath = L"D:\\Movie\\abc.flv";    //设置文件保存路径
	//添加到视频输出列表。
	if ( -1 == Encoder_AddSaveFile( &sFile ) )
	{
		//失败可能是由于没有获得授权，或者路径格式不正确
		printf( "AddSaveFile Fail, Error=%d\n", GetLastError() );
	} 
	//再设置一个输出，为 RTMP 直播。
	//sFile.eContainer = Mix_RTMP;    //设置类型为 RTMP 直播
	//sFile.szSavePath = L"rtmp://192.168.0.1/live/abc";    //设置直播的 URL
	//if ( -1 == Encoder_AddSaveFile( &sFile ) )
	//{
	//	//失败可能是由于没有获得授权，或者URL格式不正确
	//	printf( "AddSaveFile Fail, Error=%d\n", GetLastError() );
	//} 
	//开始录制和直播。
	if ( FALSE == Encoder_Start() )
	{
		//通常是由于没有设置任何输出才导致返回失败。因为打开文件和连接网络的操作等等都是异步的，如果失败会通过回调函数进行通知。
		printf( "Start Fail, Error=%d\n", GetLastError() );
	}

	printf( "Recording, Press Enter key Exit!\n" );
	getchar();
	//调用停止编码
	Encoder_End();
	//调用反初始化
	RDLive_Uninit();
	return 0;
}

