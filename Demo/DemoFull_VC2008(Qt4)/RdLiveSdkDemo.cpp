#include "stdafx.h"
#include "rdlivesdkdemo.h"
#include "chipitem.h"

RDLiveSdkDemo::RDLiveSdkDemo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	m_bPreviewSizeing	= FALSE;
	m_bChipListChanging	= FALSE;
	ZeroMemory( &m_sPerviewLayout, sizeof(m_sPerviewLayout) );
	m_timReszie	= new QTimer( this );
	m_timReszie->setObjectName( "timReszie" );
	m_timReszie->setSingleShot( true );

	ui.setupUi(this);
	m_agpSwictScene		= new QActionGroup( this );
	m_agpBSceneCount	= new QActionGroup( this );
	ui.actBSceneCount0->setData( int(0) );
	m_agpBSceneCount->addAction( ui.actBSceneCount0 );
	ui.actBSceneCount2->setData( int(2) );
	m_agpBSceneCount->addAction( ui.actBSceneCount2 );
	ui.actBSceneCount4->setData( int(4) );
	m_agpBSceneCount->addAction( ui.actBSceneCount4 );
	ui.actBSceneCount6->setData( int(6) );
	m_agpBSceneCount->addAction( ui.actBSceneCount6 );
	ui.actBSceneCount8->setData( int(8) );
	m_agpBSceneCount->addAction( ui.actBSceneCount8 );
	m_agpBSceneCount->setExclusive( true );
	m_agpBScenePos		= new QActionGroup( this );
	ui.actBSceneUp->setData( int(0) );
	m_agpBScenePos->addAction( ui.actBSceneUp );
	ui.actBSceneDown->setData( int(1) );
	m_agpBScenePos->addAction( ui.actBSceneDown );
	ui.actBSceneLeft->setData( int(2) );
	m_agpBScenePos->addAction( ui.actBSceneLeft );
	ui.actBSceneRight->setData( int(3) );
	m_agpBScenePos->addAction( ui.actBSceneRight );
	m_agpBScenePos->setExclusive( true );

	ui.widVolumeSpk->SetRange( 0.0, 1.0 );
	CRangeSlider::SStyle	sSty	= ui.widVolumeSpk->GetStyle();
	sSty.bHitMinSpace	= false;
	sSty.bHitMinLine	= false;
	sSty.bHitAreaBar	= false;
	sSty.bHitValue		= false;
	sSty.sMinText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sMaxText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sAreaText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sValueText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sValueTextSub.eAlign	= CRangeSlider::eAlignNone;
	ui.widVolumeSpk->SetStyle( sSty );
	ui.widVolumeMic->SetRange( 0.0, 1.0 );
	ui.widVolumeMic->SetStyle( sSty );

	ui.widEncoderSetting->SetDocOption( &m_docOption );


	m_pLabVideoSize	= new QLabel( this );
	m_pLabFScale	= new QLabel( this );
	m_pLabTimeFps	= new QLabel( this );
	statusBar()->addWidget( m_pLabVideoSize );
	statusBar()->addWidget( m_pLabFScale );
	statusBar()->addWidget( m_pLabTimeFps );

	qRegisterMetaType<int>("IRender_ENotify");
	qRegisterMetaType<void*>("HSCENE");
	connect( this, SIGNAL(signalRenderNotifyCB( IRender_ENotify, HSCENE, int )), this, SLOT(on_RenderNotifyCB( IRender_ENotify, HSCENE, int )) );
	qRegisterMetaType<int>("IEncoder_ENotify");
	connect( this, SIGNAL(signalEncoderNotifyCB( IEncoder_ENotify, ulong, ulong )), this, SLOT(on_EncoderNotifyCB( IEncoder_ENotify, ulong, ulong )) );


	if ( !RDLive_Init( L"17RD", L"RDLiveSdkDemo",
		RenderNotifyCB, EncoderNotifyCB, this ) )
	{
		QMessageBox::about( this, "RDLiveSDK", "Init Fail!" );
		close();
	}

	if ( !RDLive_ResetAccredit( "d3200cc987431827", 
		"77a9eeea008524e8bdf10e18409cbdb3sULczML4CjomZFtst04v/HLUrHqWT72Mmkz7WhUEmpjXMH7/UWz5oGMwUGQPbYX+MKSpM01lSGQ/qNzCkFFyKXSwxrKIViR4iZ7ZxOuB6n80wDeCV7jHJSEN1+DqlCLm3dJWQF3CFLMOj2YJxwI/YDY9h3SjCsWFz9j/71RCHH0FWpr13vMRM6a1uRCnke2Tyly/V4S4E7BE1tR6WDcxNQTeX9w399l/EpNb8LvBNNUz6shNmM627BGBfTbPG2vj+grPaxv1rFcVRqNkT45Jrjvjp3PV8L6Py7fCUvK5PJ0Pb/olb9q/M2Yom+AZkSlE0FDcSKb0MG+QCE9f1MYacjFoU31o7cZb5ZQZ++7lMqXMDvTi9LyTYR+0lDKKwFC8EJ43/upbIuhawyXQ2w4u7Zvv9IUXqhamlTUirPmuV4lSVypdzCT+gPdEjq9krLLjRajAMutBwefKiHdrp/h65BxTErT94rH7OAU6bCmbX/o=" ) )
	{
	}


	LoadProfile();


}

RDLiveSdkDemo::~RDLiveSdkDemo()
{

}

void WINAPI RDLiveSdkDemo::RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, INT iValue, LPVOID pCbParam )
{
	RDLiveSdkDemo*	pThis	= (RDLiveSdkDemo*)pCbParam;
	emit pThis->signalRenderNotifyCB( eNotify, hScene, iValue );
}
void WINAPI RDLiveSdkDemo::EncoderNotifyCB( IEncoder_ENotify eNotify, DWORD dwValue, DWORD_PTR ptrValue, LPVOID pCbParam )
{
	RDLiveSdkDemo*	pThis	= (RDLiveSdkDemo*)pCbParam;
	emit pThis->signalEncoderNotifyCB( eNotify, dwValue, ptrValue );
}

BOOL RDLiveSdkDemo::LoadProfile()
{
	BOOL		bReplaceUserOpt	= FALSE;	//是否需要替换掉用用户的配置文件
	//取得配置文件的路径。使用了 RDLive_DefaultDir() 得到指定的文件夹。
	//默认配置文件的路径，即程序的初始配置，当用户配置文件不存在时，或者默认配置的版本有更新时，将替换掉用户配置文件。
	QString		szOptDefault	= QFU( (PWORD)RDLive_DefaultDir( RDir_Application ) ) + "Option.xml";
	//用户配置文件的路径，当用户配置文件存在，且版本与默认配置文件一致，就使用用户配置文件。
	QString		szOptUser		= QFU( (PWORD)RDLive_DefaultDir( RDir_Profile ) ) + "Option.xml";
	//把 Windows 格式的路径转换为 Qt 的路径字符串，实际上只是把 \ 替换成了 /。
	szOptDefault	= QDir::fromNativeSeparators( szOptDefault );
	szOptUser	= QDir::fromNativeSeparators( szOptUser );

	QFile		fileUser( szOptUser );
	if ( !fileUser.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		bReplaceUserOpt	= TRUE;		//文件打开失败
	}
	else
	{
		if ( !m_docOption.setContent( &fileUser ) )
		{
			bReplaceUserOpt	= TRUE;		//解析 XML 格式失败
		}
		else
		{
			QDomElement		eleUser	= m_docOption.documentElement();
			if ( eleUser.tagName() != "Option" )
			{
				bReplaceUserOpt	= TRUE;		//XML 内容错误
			}
			else
			{
				INT				iEdition	= eleUser.attribute( "Edition" ).toInt();
				QFile			fileDefault( szOptDefault );
				if ( fileDefault.open( QIODevice::ReadOnly | QIODevice::Text ) )
				{
					QDomDocument	docDefault;
					if ( docDefault.setContent( &fileDefault ) )
					{
						QDomElement		eleDefault	= docDefault.documentElement();
						if ( eleDefault.tagName() == "Option" && 
							eleUser.attribute( "Edition" ).toInt() != eleDefault.attribute( "Edition" ).toInt() )
						{
							bReplaceUserOpt	= TRUE;		//默认配置文件的版本更新
						}
					}
					fileDefault.close();
				}
			}
		}
		fileUser.close();
	}

	if ( bReplaceUserOpt )
	{
		QFile::remove( szOptUser );
		if ( !QFile::copy( szOptDefault, szOptUser ) )
		{
			return FALSE;		//文件复制失败
		}
		if ( !fileUser.open( QIODevice::ReadOnly | QIODevice::Text ) )
		{
			return FALSE;		//文件打开失败
		}
		if ( !m_docOption.setContent( &fileUser ) )
		{
			return FALSE;		//解析 XML 格式失败
		}
		QDomElement		eleUser	= m_docOption.documentElement();
		if ( eleUser.tagName() != "Option" )
		{
			return FALSE;		//XML 内容错误
		}
	}
	return SettingToUiAndSdk();
}

BOOL RDLiveSdkDemo::SaveProfile()
{
	QDomElement		eleUser	= m_docOption.documentElement();
	if ( eleUser.tagName() != "Option" )
	{
		return FALSE;		//XML 内容错误
	}
	eleUser.setAttribute( "Update", QDate::currentDate().toString( "yyyyMMdd" ) );
	//在保存配置文件之前，把当前的编码设置从界面保存到XML对象
	ui.widEncoderSetting->UpdateEncoderConfig();
	
	//保存配置文件
	QString		szOptUser		= QFU( (PWORD)RDLive_DefaultDir( RDir_Profile ) ) + "Option.xml";
	szOptUser	= QDir::fromNativeSeparators( szOptUser );
	QFile		fileUser( szOptUser );
	if ( !fileUser.open( QIODevice::WriteOnly | QIODevice::Text ) )
	{
		return FALSE;		//文件打开失败
	}
	QTextStream	steXml( &fileUser );
	steXml.setCodec( "UTF-8" );
	m_docOption.save( steXml, 4, QDomNode::EncodingFromTextStream );
	fileUser.close();
	return TRUE;
}

BOOL RDLiveSdkDemo::LoadScenes()
{
	//取得配置文件的路径。使用了 RDLive_DefaultDir() 得到指定的文件夹。
	QString		szOptScenes		= QFU( (PWORD)RDLive_DefaultDir( RDir_Profile ) ) + "Scenes.xml";
	szOptScenes	= QDir::fromNativeSeparators( szOptScenes );

	QDomDocument	docScenes;
	QFile			fileScenes( szOptScenes );
	if ( !fileScenes.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		return FALSE;
	}
	if ( !docScenes.setContent( &fileScenes ) )
	{
		return FALSE;		//解析 XML 格式失败
	}
	fileScenes.close();

	QDomElement		eleSceneAll	= docScenes.documentElement();
	if ( eleSceneAll.tagName() != "Scenes" )
	{
		return FALSE;		//XML 内容错误
	}

	QDomNode		nodeScene	= eleSceneAll.firstChild();
	int				iSelScene	= eleSceneAll.attribute( "Current", "-1" ).toInt();
	while( !nodeScene.isNull() )
	{
		if ( !nodeScene.isElement() )
		{
			nodeScene	= nodeScene.nextSibling();
			continue;
		}
		QDomElement		eleScene	= nodeScene.toElement();
		if ( eleScene.tagName() != "Scene" )
		{
			nodeScene	= nodeScene.nextSibling();
			continue;
		}
		HSCENE	hScene	= Render_CreateScene();
        Scene_SetName( hScene, (LPCWSTR)eleScene.attribute( "Name" ).utf16() );
		if ( iSelScene == Render_GetSceneCount() - 1 )
		{
			Render_SetCurScene( hScene );
		}
		QDomNode	nodeChip	= eleScene.firstChild();
		while( !nodeChip.isNull() )
		{
			if ( !nodeChip.isElement() )
			{
				nodeChip	= nodeChip.nextSibling();
				continue;
			}
			QDomElement		eleChip		= nodeChip.toElement();
			if ( eleChip.tagName() != "Chip" )
			{
				nodeChip	= nodeChip.nextSibling();
				continue;
			}
			int					iSelChip	= eleScene.attribute( "Current", "-1" ).toInt();
			IPinInput_EClass	eClass		= (IPinInput_EClass)eleChip.attribute( "Type" ).toInt();
			HCHIP				hChip		= NULL;
			switch( eClass )
			{
			case ePinInput_Picture:
			case ePinInput_Camera:
			case ePinInput_Screen:
				hChip	= Scene_CreateChip( hScene, eClass, (LPCWSTR)eleChip.attribute( "Source" ).utf16(),
								eleChip.attribute( "CannotReuse" ).toInt() ? TRUE : FALSE );
				break;
			case ePinInput_Flash:
			case ePinInput_Movie:
				hChip	= Scene_CreateChip( hScene, eClass, (LPCWSTR)eleChip.attribute( "Source" ).utf16(),
								eleChip.attribute( "CannotReuse" ).toInt() ? TRUE : FALSE, 
								eleChip.attribute( "Playing" ).toInt() ? TRUE : FALSE );
				break;
			case ePinInput_Game:
				hChip	= Scene_CreateChip( hScene, eClass, (LPCWSTR)eleChip.attribute( "Source" ).utf16(),
								eleChip.attribute( "CannotReuse" ).toInt() ? TRUE : FALSE );
				break;
			case ePinInput_Text:
				hChip	= Scene_CreateChip( hScene, eClass, (LPCWSTR)eleChip.attribute( "Source" ).utf16(),
								eleChip.attribute( "CannotReuse" ).toInt() ? TRUE : FALSE );
				break;
			}
			if ( hChip == NULL )
			{
				nodeChip	= nodeChip.nextSibling();
				continue;
			}

			QDomElement		eleRect		= eleChip.firstChildElement( "Rect" );
			if ( !eleRect.isNull() )
			{
				Chip_SetRectPercent( hChip, eleRect.attribute( "X" ).toFloat(), eleRect.attribute( "Y" ).toFloat(),
					eleRect.attribute( "W" ).toFloat(), eleRect.attribute( "H" ).toFloat(), eIgnoreAspectRatio );
			}
			QDomElement		eleClip		= eleChip.firstChildElement( "Clip" );
			if ( !eleClip.isNull() )
			{
				Chip_SetClipPercent( hChip, eleClip.attribute( "L" ).toFloat(), eleClip.attribute( "T" ).toFloat(),
					eleClip.attribute( "R" ).toFloat(), eleClip.attribute( "B" ).toFloat() );
			}

			QDomElement	eleColor	= eleChip.firstChildElement( "Color" );
			if ( !eleColor.isNull() )
			{
				Chip_SetShaderParam( hChip, eShader_Hue, eleColor.attribute( "Hue" ).toFloat() );
				Chip_SetShaderParam( hChip, eShader_UseFixedHue, eleColor.attribute( "HueFixed" ).toFloat() );
				Chip_SetShaderParam( hChip, eShader_Saturation, eleColor.attribute( "Saturation" ).toFloat() );
				Chip_SetShaderParam( hChip, eShader_Lighteness, eleColor.attribute( "Ligtheness" ).toFloat() );
				Chip_SetShaderParam( hChip, eShader_Contrast, eleColor.attribute( "Contrast" ).toFloat() );
				Chip_SetShaderParam( hChip, eShader_Transparency, eleColor.attribute( "Transparency" ).toFloat() );
			}

			Chip_SetViewLock( hChip, eLock_AspectRatio, eleChip.attribute( "LockAR" ).toInt() ? TRUE : FALSE );
			Chip_SetViewLock( hChip, eLock_Position, eleChip.attribute( "LockPos" ).toInt() ? TRUE : FALSE );
			Chip_SetViewLock( hChip, eLock_Size, eleChip.attribute( "LockSize" ).toInt() ? TRUE : FALSE ); 
			Chip_SetViewLock( hChip, eLock_Angle, eleChip.attribute( "LockAngle" ).toInt() ? TRUE : FALSE ); 

			Chip_SetVisible( hChip, eleChip.attribute( "Visible" ).toInt() ? TRUE : FALSE );
			Chip_SetVolume( hChip, eleChip.attribute( "Volume" ).toFloat() );
			Chip_SetMute( hChip, eleChip.attribute( "Mutex" ).toInt() ? TRUE : FALSE );
			Chip_SetLoop( hChip, eleChip.attribute( "LoopPlay" ).toInt() ? TRUE : FALSE );
			if ( eleChip.attribute( "RangePlay" ).toInt() )
			{
				Chip_SetRange( hChip, INT64( eleChip.attribute( "RangeStart" ).toFloat() * 1000.0 ),
					INT64( eleChip.attribute( "RangeEnd" ).toFloat() * 1000.0 ), FALSE );
			}

			if ( iSelChip == Scene_GetChipCount( hScene ) - 1 )
			{
				Chip_SetCurent( hChip );
			}
			nodeChip	= nodeChip.nextSibling();
		}
		nodeScene	= nodeScene.nextSibling();
	}

	return TRUE;
}

BOOL RDLiveSdkDemo::SaveScenes()
{
	QString		szOptScenes		= QFU( (PWORD)RDLive_DefaultDir( RDir_Profile ) ) + "Scenes.xml";
	szOptScenes	= QDir::fromNativeSeparators( szOptScenes );

	QDomDocument	docScenes;

	QDomProcessingInstruction	domProc	= docScenes.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	docScenes.appendChild( domProc );
	QDomElement		eleSceneAll	= docScenes.createElement( "Scenes" );
	docScenes.appendChild( eleSceneAll );

	for ( int iScene = 0; iScene < Render_GetSceneCount(); ++iScene )
	{
		HSCENE		hScene		= Render_GetScene( iScene );
		QDomElement	eleScene	= docScenes.createElement( "Scene" );
		eleScene.setAttribute( "Name", QFU( Scene_GetName( hScene ) ) );
		for ( int iChip = 0; iChip < Scene_GetChipCount( hScene ); ++iChip )
		{
			HCHIP		hChip	= Scene_GetChip( hScene, iChip );
			QDomElement	eleChip	= docScenes.createElement( "Chip" );
			IPinInput_SStatusInfo	sStatus;
			Chip_GetStatusInfo( hChip, &sStatus );

			eleChip.setAttribute( "Type", Chip_GetClassType( hChip ) );
			eleChip.setAttribute( "Source", QFU( Chip_GetSourceName( hChip ) ) );
			eleChip.setAttribute( "CannotReuse", sStatus.bCannotReuse ? 1 : 0 );
			eleChip.setAttribute( "Visible", Chip_IsVisible( hChip ) );
			eleChip.setAttribute( "Volume", sStatus.fVolume );
			eleChip.setAttribute( "Mutex", sStatus.bIsMute );
			if ( sStatus.eStatus == ePin_Played || sStatus.eStatus == ePin_Loading )
				eleChip.setAttribute( "Playing", 1 );
			else
				eleChip.setAttribute( "Playing", 0 );
			eleChip.setAttribute( "LoopPlay", sStatus.bIsLoop );
			eleChip.setAttribute( "RangePlay", sStatus.bIsRange ? 1 : 0 );
			eleChip.setAttribute( "RangeStart", sStatus.fSecondStart );
			eleChip.setAttribute( "RangeEnd", sStatus.fSecondEnd );

			eleChip.setAttribute( "LockAR", Chip_GetViewLock( hChip, eLock_AspectRatio )  );
			eleChip.setAttribute( "LockPos", Chip_GetViewLock( hChip, eLock_Position )  );
			eleChip.setAttribute( "LockSize", Chip_GetViewLock( hChip, eLock_Size )  );
			eleChip.setAttribute( "LockAngle", Chip_GetViewLock( hChip, eLock_Angle )  );

			QDomElement	eleRect	= docScenes.createElement( "Rect" );
			FLOAT	fX, fY, fW, fH;
			BOOL	bKeepAspectRatio;
			Chip_GetRectPercent( hChip, &fX, &fY, &fW, &fH, FALSE );
			eleRect.setAttribute( "X", fX );
			eleRect.setAttribute( "Y", fY );
			eleRect.setAttribute( "W", fW );
			eleRect.setAttribute( "H", fH );
			eleChip.appendChild( eleRect );

			QDomElement	eleClip	= docScenes.createElement( "Clip" );
			FLOAT	fL, fT, fR, fB;
			Chip_GetClipPercent( hChip, &fL, &fT, &fR, &fB );
			eleClip.setAttribute( "L", fL );
			eleClip.setAttribute( "T", fT );
			eleClip.setAttribute( "R", fR );
			eleClip.setAttribute( "B", fB );
			eleChip.appendChild( eleClip );

			QDomElement	eleColor	= docScenes.createElement( "Color" );
			eleColor.setAttribute( "Hue", Chip_GetShaderParam( hChip, eShader_Hue ) );
			eleColor.setAttribute( "HueFixed", Chip_GetShaderParam( hChip, eShader_UseFixedHue ) );
			eleColor.setAttribute( "Saturation", Chip_GetShaderParam( hChip, eShader_Saturation ) );
			eleColor.setAttribute( "Ligtheness", Chip_GetShaderParam( hChip, eShader_Lighteness ) );
			eleColor.setAttribute( "Contrast", Chip_GetShaderParam( hChip, eShader_Contrast ) );
			eleColor.setAttribute( "Transparency", Chip_GetShaderParam( hChip, eShader_Transparency ) );
			eleChip.appendChild( eleColor );

			eleScene.appendChild( eleChip );
		}
		int	iCurrent	= Chip_GetIndex( Sceen_GetCurChip( hScene ), NULL );
		eleScene.setAttribute( "Current", iCurrent );
		eleSceneAll.appendChild( eleScene );
	}
	eleSceneAll.setAttribute( "Current", Render_GetSceneIndex( Render_GetCurScene() ) );

	QFile			fileScenes( szOptScenes );
	if ( !fileScenes.open( QIODevice::WriteOnly | QIODevice::Text ) )
	{
		return FALSE;		//文件打开失败
	}
	QTextStream	steXml( &fileScenes );
	steXml.setCodec( "UTF-8" );
	docScenes.save( steXml, 4, QDomNode::EncodingFromTextStream );
	fileScenes.close();
	return TRUE;
}

BOOL RDLiveSdkDemo::SettingToUiAndSdk()
{
	SetImageSettingToMenu();
	SetPreviewLayoutToMenu();
	ui.widEncoderSetting->SetEncoderSetting();
	SetAudioCaptureSetting();
	QDomElement		eleFun	= FindXmlElement( "Function" );
	if ( eleFun.attribute( "GameRec" ).toInt() ) ui.actGameRec->setChecked( true );
	if ( eleFun.attribute( "CursorCapture" ).toInt() ) ui.actCapCursor->setChecked( true );
	if ( eleFun.attribute( "AutoAero" ).toInt() ) ui.actAutoAero->setChecked( true );
	return TRUE;
}

void RDLiveSdkDemo::SetAudioCaptureSetting()
{
	int			iCount		= Audio_GetDevCount( eAudCap_Speaker );
	if ( iCount > 0 )
	{
		QDomElement	eleSpeaker	= FindXmlElement( "AuidoCapture/Speaker" );
		if ( !eleSpeaker.isNull() )
		{
            Audio_SetCurrent( eAudCap_Speaker, (LPCWSTR)eleSpeaker.attribute( "DevId" ).utf16() );
			Audio_Enable( eAudCap_Speaker, eleSpeaker.attribute( "Mutex" ).toInt() ? FALSE : TRUE );
			Audio_SetVolume( eAudCap_Speaker, eleSpeaker.attribute( "Volume" ).toFloat() );
		}
		else
		{
			Audio_Enable( eAudCap_Speaker, TRUE );
			Audio_SetVolume( eAudCap_Speaker, 1.0f );
		}
		ui.widVolumeSpk->SetArea( 0.0, Audio_GetVolume( eAudCap_Speaker ) );
		ui.chkSpeaker->setChecked( !Audio_IsEnabled( eAudCap_Speaker ) );
	}
	else
	{
		ui.chkSpeaker->setChecked( true );
	}
	ui.widVolumeOperSpk->setEnabled( iCount > 0 );

	iCount		= Audio_GetDevCount( eAudCap_Microphone );
	if ( iCount > 0 )
	{
		QDomElement	eleMicro	= FindXmlElement( "AuidoCapture/Microphone" );
		if ( !eleMicro.isNull() )
		{
            Audio_SetCurrent( eAudCap_Microphone, (LPCWSTR)eleMicro.attribute( "DevId" ).utf16() );
			Audio_Enable( eAudCap_Microphone, eleMicro.attribute( "Mutex" ).toInt() ? FALSE : TRUE );
			Audio_SetVolume( eAudCap_Microphone, eleMicro.attribute( "Volume" ).toFloat() );
		}
		else
		{
			Audio_Enable( eAudCap_Microphone, TRUE );
			Audio_SetVolume( eAudCap_Microphone, 1.0f );
		}
		ui.widVolumeMic->SetArea( 0.0, Audio_GetVolume( eAudCap_Microphone ) );
		ui.chkMicrophone->setChecked( !Audio_IsEnabled( eAudCap_Microphone ) );
	}
	else
	{
		ui.chkMicrophone->setChecked( true );
	}
	ui.widVolumeOperMic->setEnabled( iCount > 0 );
}

void RDLiveSdkDemo::UpdateVideoSizeLabel()
{
	QDomElement		eleRR	= FindXmlElement( "Base/ResolutionRatio" );
	QDomElement		eleFR	= FindXmlElement( "Base/FrameRatio" );
	if ( !eleRR.isNull() && !eleFR.isNull() )
	{
		bool	bSwapVH	= eleRR.attribute( "SwapVH" ).toInt() ? true : false;
		int		iWidth	= eleRR.attribute( "Width" ).toInt();
		int		iHeight	= eleRR.attribute( "Height" ).toInt();
		float	fps		= eleFR.attribute( "Fps" ).toFloat();
		if ( bSwapVH )
			m_pLabVideoSize->setText( QFU(L" 视频：%1x%2 %3f/s ").arg(iHeight).arg(iWidth).arg(fps) );
		else
			m_pLabVideoSize->setText( QFU(L" 视频：%1x%2 %3f/s ").arg(iWidth).arg(iHeight).arg(fps) );
	}
}

void RDLiveSdkDemo::on_timReszie_timeout()
{
	static bool bFirstResize	= true;
	if ( bFirstResize )
	{
		bFirstResize	= false;
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eScreenCenter );		
		LoadScenes();
	}
	else
	{
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eNotChangePos );
	}
}

void RDLiveSdkDemo::on_chkStart_toggled ( bool checked )
{
	if ( checked )	//开始
	{
		ui.chkStart->setEnabled( false );
		if ( !ui.widEncoderSetting->UpdateEncoderConfig( true ) ||
			!Encoder_Start() )
		{
			ui.chkStart->setChecked( false );
			ui.chkStart->setEnabled( true );
		}
	}
	else
	{
		ui.chkStart->setEnabled( false );
		Encoder_End();
	}
}

void RDLiveSdkDemo::on_butAddChip_clicked()
{
	QPoint	pos	= ui.butAddChip->mapToGlobal( QPoint( 0, ui.butAddChip->height() ) );
	ui.menuChipInput->popup( pos );
}

void RDLiveSdkDemo::on_butCloseChip_clicked()
{
	int		iCur	= ui.listWidChips->currentRow();
	if ( iCur >= 0 )
	{
		HCHIP	hChip	= ChipItem::GetChipHandle( ui.listWidChips, iCur );
		if ( hChip ) Chip_Destroy( hChip );
	}
}

void RDLiveSdkDemo::on_butUpChip_clicked()
{
	HSCENE	hScene	= Render_GetCurScene();
	HCHIP	hChip	= Sceen_GetCurChip( hScene );
	if ( hChip )
	{
		Chip_SetIndex( hChip, Chip_GetIndex( hChip, NULL ) + 1 );
	}
}

void RDLiveSdkDemo::on_butDownChip_clicked()
{
	HSCENE	hScene	= Render_GetCurScene();
	HCHIP	hChip	= Sceen_GetCurChip( hScene );
	if ( hChip )
	{
		if ( hChip ) Chip_SetIndex( hChip, Chip_GetIndex( hChip, NULL ) - 1 );
	}
}

void RDLiveSdkDemo::on_listWidChips_currentItemChanged( QListWidgetItem * current, QListWidgetItem * previous )
{
	if ( !m_bChipListChanging && current )
	{
		ChipItem*	pChip	= (ChipItem*)ui.listWidChips->itemWidget( current );
		if ( pChip ) Chip_SetCurent( pChip->GetHChip() );
	}
}


void RDLiveSdkDemo::on_butAudioPopSpk_clicked()
{
	QActionGroup	agpMenu( this );
	QMenu		menuDev;
	INT			iCount	= Audio_GetDevCount( eAudCap_Speaker );
	LPCWSTR		pCurDev	= Audio_GetCurrent( eAudCap_Speaker );
	agpMenu.setExclusive( true );
	for ( int i = 0; i < iCount; ++i )
	{
		QAction*	pAct	= menuDev.addAction( QFU( Audio_GetDevName( eAudCap_Speaker, i ) ) );
		pAct->setData( QFU( Audio_GetDevId( eAudCap_Speaker, i ) ) );
		pAct->setCheckable( true );
		if ( pCurDev && wcscmp( pCurDev, Audio_GetDevId( eAudCap_Speaker, i ) ) == 0 )
		{
			pAct->setChecked( true );
		}
		agpMenu.addAction( pAct );
	}
	QAction*	pSel	= menuDev.exec( ui.butAudioPopSpk->mapToGlobal( QPoint( 0, ui.butAudioPopSpk->height() ) ) );
	if ( pSel )
	{
        if ( Audio_SetCurrent( eAudCap_Speaker, (LPCWSTR)pSel->data().toString().utf16() ) )
		{
			QDomElement	eleSpeaker	= FindXmlElement( "AuidoCapture/Speaker", TRUE );
			eleSpeaker.setAttribute( "DevId", pSel->data().toString() );
		}
	}
}

void RDLiveSdkDemo::on_butAudioPopMic_clicked()
{
	QActionGroup	agpMenu( this );
	QMenu		menuDev;
	INT			iCount	= Audio_GetDevCount( eAudCap_Microphone );
	LPCWSTR		pCurDev	= Audio_GetCurrent( eAudCap_Microphone );
	agpMenu.setExclusive( true );
	for ( int i = 0; i < iCount; ++i )
	{
		QAction*	pAct	= menuDev.addAction( QFU( Audio_GetDevName( eAudCap_Microphone, i ) ) );
		pAct->setData( QFU( Audio_GetDevId( eAudCap_Microphone, i ) ) );
		pAct->setCheckable( true );
		if ( pCurDev && wcscmp( pCurDev, Audio_GetDevId( eAudCap_Microphone, i ) ) == 0 )
		{
			pAct->setChecked( true );
		}
		agpMenu.addAction( pAct );
	}
	QAction*	pSel	= menuDev.exec( ui.butAudioPopMic->mapToGlobal( QPoint( 0, ui.butAudioPopMic->height() ) ) );
	if ( pSel )
	{
        if ( Audio_SetCurrent( eAudCap_Microphone, (LPCWSTR)pSel->data().toString().utf16() ) )
		{
			QDomElement	eleMicro	= FindXmlElement( "AuidoCapture/Microphone", TRUE );
			eleMicro.setAttribute( "DevId", pSel->data().toString() );
		}
	}
}

void RDLiveSdkDemo::on_chkSpeaker_clicked( bool checked )
{
	if ( Audio_Enable( eAudCap_Speaker, !checked ) )
	{
		QDomElement	eleSpeaker	= FindXmlElement( "AuidoCapture/Speaker", TRUE );
		eleSpeaker.setAttribute( "Mutex", checked ? 1 : 0 );
	}
}

void RDLiveSdkDemo::on_chkMicrophone_clicked( bool checked )
{
	if ( Audio_Enable( eAudCap_Microphone, !checked ) )
	{
		QDomElement	eleMicro	= FindXmlElement( "AuidoCapture/Microphone", TRUE );
		eleMicro.setAttribute( "Mutex", checked ? 1 : 0 );
	}
}

void RDLiveSdkDemo::on_widVolumeSpk_sliderRange( double fLeft, double fRight )
{
	if ( Audio_SetVolume( eAudCap_Speaker, fRight ) )
	{
		QDomElement	eleSpeaker	= FindXmlElement( "AuidoCapture/Speaker", TRUE );
		eleSpeaker.setAttribute( "Volume", fRight );
	}
}

void RDLiveSdkDemo::on_widVolumeMic_sliderRange( double fLeft, double fRight )
{
	if ( Audio_SetVolume( eAudCap_Microphone, fRight ) )
	{
		QDomElement	eleMicro	= FindXmlElement( "AuidoCapture/Microphone", TRUE );
		eleMicro.setAttribute( "Volume", fRight );
	}
}

void RDLiveSdkDemo::resizeEvent( QResizeEvent * event )
{
	if ( !m_bPreviewSizeing )
		m_timReszie->start( 100 );
}

void RDLiveSdkDemo::closeEvent( QCloseEvent * event )
{
	SaveProfile();
	SaveScenes();
	RDLive_Uninit();
}

QDomElement RDLiveSdkDemo::FindXmlElement( const QString& szPath, BOOL bCreateIfNull )
{
	QStringList		lstNode		= szPath.split( '/' );
	
	QDomElement		eleFind		= m_docOption.documentElement();  //返回根元素
	for ( int i = 0; i < lstNode.count(); ++i )
	{
		QDomElement	eleParent	= eleFind;
		eleFind		= eleParent.firstChildElement( lstNode[i] );
		if ( eleFind.isNull() )
		{
			if ( bCreateIfNull )
			{
				eleFind	= m_docOption.createElement( lstNode[i]);
				eleParent.appendChild( eleFind );
			}
			else
			{
				break;
			}
		}
	}
	return eleFind;
}


void RDLiveSdkDemo::on_RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, int iValue )
{
	switch( eNotify )
	{
	case eNotify_None:
		break;
	case eNotify_SceneAdding:
		on_actAddScene_triggered( false );
		break;
	case eNotify_SceneAdded:
		if ( iValue )
		{
			UpdatePreviewConfig( IGlRender_SPreviewLayout::eDoNotExceedDesktop );
		}
		break;
	case eNotify_SceneDeleting:
		break;
	case eNotify_SceneDeleted:
		if ( iValue )
		{
			UpdatePreviewConfig( IGlRender_SPreviewLayout::eDoNotExceedDesktop );
		}
		break;
	case eNotify_SceneSwitched:		//切换了当前选中的场景
		m_bChipListChanging	= TRUE;
		//检查当前是否有选中项，有的话，就要把选中项中附加的控制窗口移出，注意是移出，不是移除。
		//如果不移出，那么在删除该项的时候，附加的控制窗口也会被删除。
		if ( ui.listWidChips->currentItem() )
		{
			ChipItem*	pChip	= (ChipItem*)ui.listWidChips->itemWidget( ui.listWidChips->currentItem() );
			if ( pChip ) pChip->OnChipSelected( FALSE );
		}
		//先删除元件列表中的所有元件
		while( ui.listWidChips->count() )
		{
			delete ui.listWidChips->takeItem( 0 );
		}
		if ( hScene )
		{
			QString	szName	= QFU( Scene_GetName( hScene ) );
			if ( szName.isEmpty() )
			{
				szName	= QFU( L"场景 %1" ).arg( Render_GetSceneIndex( hScene ) + 1 );
			}
			ui.tabSector->setTabText( 0, szName );
			ui.menuChipInput->setEnabled( true );
			ui.butAddChip->setEnabled( true );
			//再逐个添加到元件列表
			for ( int i = 0; i < Scene_GetChipCount( hScene ); ++i )
			{
				new ChipItem( Scene_GetChip( hScene, i ), ui.listWidChips );
			}
		}
		else
		{
			ui.tabSector->setTabText( 0, QFU( L"无") );
			ui.menuChipInput->setEnabled( false );
			ui.butAddChip->setEnabled( false );
		}
		SetChipListButStatus();
		m_bChipListChanging	= FALSE;
		break;
	case eNotify_SceneNamed:
		if ( hScene == Render_GetCurScene() )
		{
			QString	szName	= QFU( Scene_GetName( hScene ) );
			if ( szName.isEmpty() )
			{
				szName	= QFU( L"场景 %1" ).arg( Render_GetSceneIndex( hScene ) + 1 );
			}
			ui.tabSector->setTabText( 0, szName );
		}
		break;
	case eNotify_SceneScroll:
		break;
	case eNotify_RBDownCScene:
		break;
	case eNotify_RBDownBScene:
		break;
	case eNotify_RBUpCScene:
		break;
	case eNotify_RBUpBScene:
		break;
	}
	if ( hScene == Render_GetCurScene() )
	{
		m_bChipListChanging	= TRUE;
		if ( ChipItem::OnRenderNotify( ui.listWidChips, eNotify, hScene, iValue ) )
		{
			SetChipListButStatus();
		}
		m_bChipListChanging	= FALSE;
	}
}

void RDLiveSdkDemo::on_EncoderNotifyCB( IEncoder_ENotify eNotify, ulong dwValue, ulong ptrValue )
{
	switch( eNotify )
	{
	case eEncNotifySuccess:
		break;
	case eEncNotifyStarted:
		ui.chkStart->setEnabled( true );
		break;
	case eEncNotifyStoped:
		ui.chkStart->setChecked( false );
		ui.chkStart->setEnabled( true );
		if ( dwValue )
		{
			QMessageBox::critical( this, QFU( L"直播/录制" ), 
				QFU( L"直播/录制出错，现已停止。\n错误代码：%1" ).arg( dwValue ) );
		}
		break;
	case eEncNotifyEncodeError:
		break;
	case eEncNotifyEncodeFps:
		if ( ptrValue )
		{
			PSEncStatusEncodeFps	pFps	= (PSEncStatusEncodeFps)ptrValue;
			QString	szTime	= QFU( L"时长：%1:%2:%3  编码帧率：%4" )
				.arg( int( pFps->iRecordTime / 1000 / 60 / 60 ), 2, 10, QChar('0') )
				.arg( int( pFps->iRecordTime / 1000 / 60 ) % 60, 2, 10, QChar('0') )
				.arg( int( pFps->iRecordTime / 1000 ) % 60, 2, 10, QChar('0') )
				.arg( pFps->fCurEncodeFps, 0, 'f', 2 );
			szTime	+= QString( "(%1)" ).arg( pFps->iInpFrameNum );
			m_pLabTimeFps->setText( szTime );
		}
		break;
	case eEncNotifyWriteFileFail:
		break;
	case eEncNotifyDisconnected:
		break;
	case eEncNotifyReConnectStart:
		break;
	case eEncNotifyReConnectDone:
		break;
	case eEncNotifyReConnectFail:
		break;
	case eEncNotifyUploadBitrate:
		break;
	case eEncNotifyDiscardPacks:
		break;
	case eEncNotifyDiscardFrame:
		break;
	case eEncNotifyResetBitrate:
		break;
	case eEncNotifyResetPreset:
		break;
	case eEncNotify_AcceditDone:
		ui.widEncoderSetting->OnAcceditDone( dwValue ? TRUE : FALSE, QFU( (PWORD)ptrValue ) );
		break;
	case eEncNotify_GetCloudFail:
		QMessageBox::critical( this, QFU( L"直播/录制" ), 
			QFU( L"取得云直播地址失败。\n：%1" ).arg( QFU( PWORD(ptrValue) ) ) );
		break;
	}
}

void RDLiveSdkDemo::SetChipListButStatus()
{
	INT		iIndex	= ui.listWidChips->currentRow();
	ui.butCloseChip->setEnabled( iIndex >= 0 );
	ui.butUpChip->setEnabled( iIndex > 0 );
	ui.butDownChip->setEnabled( iIndex >= 0 && iIndex < ui.listWidChips->count() - 1);
}





