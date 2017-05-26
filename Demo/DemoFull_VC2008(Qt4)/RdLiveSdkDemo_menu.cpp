#include "stdafx.h"
#include "rdlivesdkdemo.h"

void RDLiveSdkDemo::SetImageSettingToMenu()
{
	QDomElement		eleRoot	= m_docOption.documentElement();  //返回根元素
	QDomElement		eleBase	= eleRoot.firstChildElement( "Base" );
	//创建菜单项，菜单内容从配置文件中得到。
	if ( !eleBase.isNull() )
	{
		//创建分辨率列表的菜单项
		QDomElement		eleResRatio	= eleBase.firstChildElement( "ResolutionRatio" );
		QDomNode		nodeGroup	= eleResRatio.firstChild();
		QActionGroup*	agrpGroup	= new QActionGroup( this );	//分辨率分类
		QActionGroup*	agrpSize	= new QActionGroup( this );	//所有的分辨率
		agrpGroup->setExclusive( true );
		agrpSize->setExclusive( true );
		int			iWidth		= eleResRatio.attribute( "Width", "1280" ).toInt();
		int			iHeight		= eleResRatio.attribute( "Height", "720" ).toInt();
		bool		bRotate90	= eleResRatio.attribute( "SwapVH", "0" ).toInt() ? true : false;
		QString		szGroup		= eleResRatio.attribute( "Group", "User" );
		if ( iWidth < 8 || iWidth > 8192 )	iWidth	= 1280;
		if ( iHeight < 8 || iHeight > 8192 )	iHeight	= 720;
		//设置渲染的分辨率
		Render_SetSize( iWidth, iHeight );
		while( !nodeGroup.isNull() )
		{
			if ( nodeGroup.isElement() )
			{
				QDomElement		eleGroup	= nodeGroup.toElement();
				QMenu*			menuGroup	= new QMenu( eleGroup.attribute( "Str" ) );
				QDomNode		nodeSize	= nodeGroup.firstChild();

				menuGroup->menuAction()->setData( eleGroup.tagName() );
				menuGroup->menuAction()->setCheckable( true );
				agrpGroup->addAction( menuGroup->menuAction() );
				ui.menuImage->insertMenu( ui.actSwapVH, menuGroup );

				if ( szGroup == eleGroup.tagName() )	menuGroup->menuAction()->setChecked( true );
				while( !nodeSize.isNull() )
				{
					QDomElement	eleSize	= nodeSize.toElement();
					if ( eleSize.tagName() == "Separator" )
					{
						menuGroup->addSeparator();
					}
					else if ( eleSize.tagName() == "Size" )
					{
						QAction*	actSize	= menuGroup->addAction( eleSize.attribute( "Str" ) );
						actSize->setData( QSize( eleSize.attribute( "Width" ).toInt(), eleSize.attribute( "Height" ).toInt() ) );
						actSize->setCheckable( true );
						agrpSize->addAction( actSize );

						if ( szGroup == eleGroup.tagName() &&
							iWidth == eleSize.attribute( "Width" ).toInt() &&
							iHeight == eleSize.attribute( "Height" ).toInt() )
						{
							actSize->setChecked( true );
						}
					}
					nodeSize	= nodeSize.nextSibling();
				}
			}
			nodeGroup	= nodeGroup.nextSibling();
		}
		connect( agrpSize, SIGNAL(triggered(QAction*)), this, SLOT(on_agpImageSize_triggered(QAction*)) );
		if ( bRotate90 ) ui.actSwapVH->setChecked( true );


		//添加帧率列表
		QDomElement		eleFRatio	= eleBase.firstChildElement( "FrameRatio" );
		QDomNode		nodeFps		= eleFRatio.firstChild();
		QActionGroup*	agrpFRatio	= new QActionGroup( this );

		float			fps			= eleFRatio.attribute( "Fps", "30" ).toFloat();
		if ( fps < 1.0f || fps > 120.0f )	fps	= 30.0f;
		Render_SetFps( fps );
		agrpFRatio->setExclusive( true );
		while( !nodeFps.isNull() )
		{
			QDomElement	eleFps		= nodeFps.toElement();
			if ( eleFps.tagName() == "Separator" )
			{
				ui.menuFpses->addSeparator();
			}
			else if ( eleFps.tagName() == "Fps" )
			{
				QAction*	actFps		= ui.menuFpses->addAction( eleFps.attribute( "Str" ) );
				actFps->setData( eleFps.attribute( "val" ).toFloat() );
				actFps->setCheckable( true );
				agrpFRatio->addAction( actFps );
				if ( fps == eleFps.attribute( "val" ).toFloat() ) actFps->setChecked( true );
			}
			nodeFps		= nodeFps.nextSibling();
		}

		UpdateVideoSizeLabel();
		//预览缩放比例列表
		QDomElement		elePreview	= eleBase.firstChildElement( "PreviewScale" );
		QDomNode		nodeScale	= elePreview.firstChild();
		QActionGroup*	agrpPreview	= new QActionGroup( this );
		bool			bHardware	= elePreview.attribute( "Hardware", "1" ).toInt() ? true : false;
		float			fScale		= elePreview.attribute( "Scale" ).toFloat();
		if ( fScale < 0.1f || fScale > 1.0f ) fScale = 0.5f;
		while( !nodeScale.isNull() )
		{
			QDomElement	eleScale	= nodeScale.toElement();
			if ( eleScale.tagName() == "Separator" )
			{
				ui.menuPreviewScale->addSeparator();
			}
			else if ( eleScale.tagName() == "Scale" )
			{
				QAction*	actScale	= ui.menuPreviewScale->addAction( eleScale.attribute( "Str" ) );
				actScale->setData( eleScale.attribute( "val" ).toFloat() );
				agrpPreview->addAction( actScale );
				if ( fScale == eleScale.attribute( "val" ).toFloat() ) actScale->setChecked( true );
			}
			nodeScale	= nodeScale.nextSibling();
		}
		if ( bHardware ) ui.actPreviewOpenGL->setChecked( true );
	}
}

void RDLiveSdkDemo::on_agpImageSize_triggered ( QAction * action )
{
	QMenu*	pMenu	= (QMenu*)action->parent();
	pMenu->menuAction()->setChecked( true );
	QDomElement		eleNode	= FindXmlElement( "Base/ResolutionRatio", TRUE );
	if ( !eleNode.isNull() )
	{
		QSize	siVideo	= action->data().toSize();
		eleNode.setAttribute( "Group", pMenu->menuAction()->data().toString() );
		eleNode.setAttribute( "Width", siVideo.width() );
		eleNode.setAttribute( "Height", siVideo.height() );
		bool	bRotate90	= eleNode.attribute( "SwapVH", "0" ).toInt() ? true : false;
		if ( bRotate90 )
		{
			Render_SetSize( siVideo.height(), siVideo.width() );
		}
		else
		{
			Render_SetSize( siVideo.width(), siVideo.height() );
		}
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eScreenCenter );
		UpdateVideoSizeLabel();
	}
}

void RDLiveSdkDemo::on_menuFpses_triggered ( QAction * action )
{
	QDomElement		eleNode	= FindXmlElement( "Base/FrameRatio", TRUE );
	if ( !eleNode.isNull() )
	{
		eleNode.setAttribute( "Fps", action->data().toFloat() );
		Render_SetFps( action->data().toFloat() );
		UpdateVideoSizeLabel();
	}
}

void RDLiveSdkDemo::on_menuPreviewScale_triggered ( QAction * action )
{
	QDomElement		eleNode	= FindXmlElement( "Base/PreviewScale", TRUE );
	if ( !eleNode.isNull() )
	{
		eleNode.setAttribute( "Scale", action->data().toFloat() );
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eScreenCenter );
	}
}

void RDLiveSdkDemo::on_actSwapVH_triggered( bool checked )
{
	QDomElement		eleNode	= FindXmlElement( "Base/ResolutionRatio", TRUE );
	if ( !eleNode.isNull() )
	{
		eleNode.setAttribute( "SwapVH", checked ? "1" : "0" );
		int	iWidth	= eleNode.attribute( "Width" ).toInt();
		int	iHeight	= eleNode.attribute( "Height" ).toInt();
		if ( checked )
			Render_SetSize( iHeight, iWidth );
		else
			Render_SetSize( iWidth, iHeight );
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eScreenCenter );
		UpdateVideoSizeLabel();
	}
}

void RDLiveSdkDemo::on_actPreviewOpenGL_triggered( bool checked )
{
	QDomElement		eleNode	= FindXmlElement( "Base/PreviewScale", TRUE );
	if ( !eleNode.isNull() )
	{
		eleNode.setAttribute( "Hardware", checked ? "1" : "0" );
		UpdatePreviewConfig( IGlRender_SPreviewLayout::eNotChangePos );
	}
}

////////////////////////////////////////////////////////////////////////

void RDLiveSdkDemo::on_menuScene_aboutToShow()
{
	HSCENE		hCurScene	= Render_GetCurScene();
	QAction*	actScene	= NULL;
	ui.menuSwitchScene->clear();
	ui.menuDeleteScene->clear();
	ui.menuRenameScene->clear();
	for ( int i = 0; i < Render_GetSceneCount(); ++i )
	{
		HSCENE	hScene	= Render_GetScene( i );
		QString	szName	= QFU( Scene_GetName( hScene ) );
		if ( szName.isEmpty() )
		{
			szName	= QFU( L"场景 %1" ).arg( i + 1 );
		}
		actScene	= ui.menuSwitchScene->addAction( szName );
		actScene->setData( i );
		actScene->setActionGroup( m_agpSwictScene );
		actScene->setCheckable( true );
		if ( hCurScene == hScene ) actScene->setChecked( true );
		actScene	= ui.menuDeleteScene->addAction( szName );
		actScene->setData( i );
		if ( hCurScene == hScene ) ui.menuDeleteScene->setDefaultAction( actScene );
		actScene	= ui.menuRenameScene->addAction( szName );
		actScene->setData( i );
		if ( hCurScene == hScene ) ui.menuRenameScene->setDefaultAction( actScene );
	}
	ui.menuDeleteScene->addSeparator();
	actScene	= ui.menuDeleteScene->addAction( QFU( L"删除所有空场景" ) );
	actScene->setData( -1 );

}

void RDLiveSdkDemo::SetPreviewLayoutToMenu( BOOL bRestore )
{
	if ( bRestore )
	{
		Render_SetPreviewLayout( NULL );
		m_sPerviewLayout	= *Render_GetPreviewLayout();
	}
	else
	{
		m_sPerviewLayout	= *Render_GetPreviewLayout();
		QDomElement		elePreview	= FindXmlElement( "PreviewLayout" );
		if ( !elePreview.isNull() )
		{
			QDomNode		nodeText	= elePreview.firstChild();
			if ( !nodeText.isNull() && nodeText.isText() )
			{
				QByteArray		hexLayout	= QByteArray::fromHex( nodeText.nodeValue().trimmed().toUtf8() );
				if ( hexLayout.length() == sizeof( m_sPerviewLayout ) )
				{
					memcpy( &m_sPerviewLayout, hexLayout.data(), sizeof( m_sPerviewLayout ) );
				}
			}
		}
	}
	if ( 0 == m_sPerviewLayout.iBSceneCount )
		ui.actBSceneCount0->setChecked( true );
	else if ( 2 == m_sPerviewLayout.iBSceneCount )
		ui.actBSceneCount2->setChecked( true );
	else if ( 4 == m_sPerviewLayout.iBSceneCount )
		ui.actBSceneCount4->setChecked( true );
	else if ( 6 == m_sPerviewLayout.iBSceneCount )
		ui.actBSceneCount6->setChecked( true );
	else if ( 8 == m_sPerviewLayout.iBSceneCount )
		ui.actBSceneCount8->setChecked( true );

	if ( m_sPerviewLayout.bAddSceneBut )
		ui.actShowAddScene->setChecked( true );
	if ( m_sPerviewLayout.bSceneName )
		ui.actShowSceneName->setChecked( true );
	if ( m_sPerviewLayout.iScrollBarSize )
		ui.actShowScrollBar->setChecked( true );
	if ( m_sPerviewLayout.bCurLikeBScene )
		ui.actShowCurrOnBack->setChecked( true );
	if ( m_sPerviewLayout.fEnterScale > 1.0 )
		ui.actBSceneScale->setChecked( true );
}

void RDLiveSdkDemo::on_menuSwitchScene_triggered ( QAction * action )
{
	int	iScene	= action->data().toInt();
	Render_SetCurScene( Render_GetScene( iScene ) );
}

void RDLiveSdkDemo::on_menuDeleteScene_triggered ( QAction * action )
{
	int	iScene	= action->data().toInt();
	if ( iScene >= 0 )
	{
		Render_DestroyScene( Render_GetScene( iScene ) );
	}
	else
	{
		for ( iScene = 0; iScene < Render_GetSceneCount(); ++iScene )
		{
			HSCENE	hScene	= Render_GetScene( iScene );
			if ( Scene_GetChipCount( hScene ) == 0 )
			{
				Render_DestroyScene( hScene );
				--iScene;
			}
		}
	}
}

void RDLiveSdkDemo::on_menuRenameScene_triggered ( QAction * action )
{
	bool	bOk	= false;
	int		iScene	= action->data().toInt();
	HSCENE	hScene	= Render_GetScene( iScene );
	QString	szName	= QFU( Scene_GetName( hScene ) );
	if ( szName.isEmpty() )
	{
		szName	= QFU( L"场景 %1" ).arg( Render_GetSceneIndex( hScene ) + 1 );
	}
	szName	= QInputDialog::getText( this, QFU( L"场景重命名" ), QFU( L"新的名称：" ),
		QLineEdit::Normal, szName, &bOk );
	if ( bOk )
	{
        Scene_SetName( hScene, (LPCWSTR)szName.utf16() );
	}
}

void RDLiveSdkDemo::on_actAddScene_triggered( bool checked )
{
	bool	bOk		= false;
	QString	szName	= QInputDialog::getText( this, QFU( L"添加场景" ), QFU( L"场景名称：" ),
		QLineEdit::Normal, QString(), &bOk );
	if ( bOk )
	{
		HSCENE		hScene	= Render_CreateScene();
        Scene_SetName( hScene, (LPCWSTR)szName.utf16() );
	}
}

void RDLiveSdkDemo::on_actClearCurScene_triggered( bool checked )
{
	HSCENE		hScene	= Render_GetCurScene();
	while( hScene && Scene_GetChipCount( hScene ) )
	{
		HCHIP	hChip	= Scene_GetChip( hScene, 0 );
		Chip_Destroy( hChip );
	}
}

void RDLiveSdkDemo::on_menuPreviewLayout_triggered( QAction * action )
{
	if ( action == ui.actRestorePreview )
	{
		SetPreviewLayoutToMenu( TRUE );
	}
	UpdatePreviewConfig( IGlRender_SPreviewLayout::eDoNotExceedDesktop );
}



void RDLiveSdkDemo::UpdatePreviewConfig( IGlRender_SPreviewLayout::EReposWnd eMode )
{
	QDomElement		eleNode	= FindXmlElement( "Base/PreviewScale", TRUE );
	if ( eleNode.isNull() ) return;
	float			fScale		= eleNode.attribute( "Scale" ).toFloat();
	BOOL			bHardware	= eleNode.attribute( "Hardware", "1" ).toInt() ? TRUE : FALSE;

	if ( eMode == IGlRender_SPreviewLayout:: eNotChangePos )
	{
		m_sPerviewLayout.fScale	= 0.0f;
	}
	else
	{
		m_sPerviewLayout.fScale	= fScale;
	}
	m_sPerviewLayout.hMainWnd	= winId();
	m_sPerviewLayout.siMinimumLimit.cx	= ui.widPreview->minimumWidth();
	m_sPerviewLayout.siMinimumLimit.cy	= ui.widPreview->minimumHeight();
	
	if ( bHardware )
	{
		if ( !m_sPerviewLayout.hMainWnd )		//如果之前不是使用的OpenGL窗口预览，现在就需要设置为使用窗口预览
		{
		}
		m_sPerviewLayout.rtPreview.left	= 0;
		m_sPerviewLayout.rtPreview.right	= ui.widPreview->width();
		m_sPerviewLayout.rtPreview.top	= 0;
		m_sPerviewLayout.rtPreview.bottom= ui.widPreview->height();
		m_sPerviewLayout.hPreviewWnd	= ui.widPreview->winId();
		m_sPerviewLayout.pCbFunction	= NULL;
		m_sPerviewLayout.pCbParam	= NULL;

		ui.widPreview->SetUsePreiveImage( FALSE );
	}
	else
	{
		if ( m_sPerviewLayout.hMainWnd )
		{
		}
		m_sPerviewLayout.rtPreview.left	= ui.widPreview->geometry().left();
		m_sPerviewLayout.rtPreview.right	= ui.widPreview->geometry().right() + 1;
		m_sPerviewLayout.rtPreview.top	= ui.widPreview->geometry().top();
		m_sPerviewLayout.rtPreview.bottom= ui.widPreview->geometry().bottom() + 1;
		m_sPerviewLayout.hPreviewWnd	= 0;
		m_sPerviewLayout.pCbFunction	= ui.widPreview->OnPreviewBufferCB;
		m_sPerviewLayout.pCbParam		= ui.widPreview;

		ui.widPreview->SetUsePreiveImage( TRUE );
	}
	m_sPerviewLayout.eReposWindow	= eMode;
	m_sPerviewLayout.bOnlyWorkArea	= TRUE;
	//根据菜单项设置预览布局
	QAction*	pAction		= m_agpBSceneCount->checkedAction();
	m_sPerviewLayout.iBSceneCount	= pAction ? pAction->data().toInt() : 0;
	m_sPerviewLayout.bAddSceneBut	= ui.actShowAddScene->isChecked() ? TRUE : FALSE;
	m_sPerviewLayout.bSceneName		= ui.actShowSceneName->isChecked() ? TRUE : FALSE;
	m_sPerviewLayout.bCurLikeBScene	= ui.actShowCurrOnBack->isChecked() ? TRUE : FALSE;
	m_sPerviewLayout.iScrollBarSize	= ui.actShowScrollBar->isChecked() ? 12 : 0;
	//sLayout.bBSceneHolder	= FALSE;
	//sLayout.bScrollHolder	= FALSE;

	if ( Render_SetPreviewLayout( &m_sPerviewLayout ) )
	{
		if ( eMode != IGlRender_SPreviewLayout:: eNotChangePos )
		{
			m_bPreviewSizeing	= TRUE;
			setGeometry( m_sPerviewLayout.rtMainClient.left, m_sPerviewLayout.rtMainClient.top,
				m_sPerviewLayout.rtMainClient.right - m_sPerviewLayout.rtMainClient.left,
				m_sPerviewLayout.rtMainClient.bottom - m_sPerviewLayout.rtMainClient.top );
			m_bPreviewSizeing	= FALSE;
		}
	}
	m_pLabFScale->setText( QFU(L" 预览：%1% ").arg( int( m_sPerviewLayout.fScale * 100.0f + 0.5f ) ) );
	//把当前的预览布局写入 XML 对象
	QDomElement		elePreview	= FindXmlElement( "PreviewLayout", TRUE );
	QByteArray		hexLayout( (char*)&m_sPerviewLayout, sizeof( m_sPerviewLayout ) );
	QDomNode		nodeText	= elePreview.firstChild();
	if ( nodeText.isNull() || !nodeText.isText() )
	{
		QDomText	domText	= m_docOption.createTextNode( hexLayout.toHex() );
		elePreview.appendChild( domText );
	}
	else
	{
		nodeText.setNodeValue( hexLayout.toHex() );
	}
}

//////////////////////////////////////////////////////////////////
void RDLiveSdkDemo::on_menuAddScreen_aboutToShow()
{
	int				iScreenCount	= Screen_GetCount();
	MONITORINFOEXW	monit;
	QRect			rtScreen;
	QString			szItem;
	for ( int i = 0; i < iScreenCount; ++i )
	{
		Screen_GetInfo( i, &monit );
		rtScreen	|= QRect( monit.rcMonitor.left, monit.rcMonitor.top, 
			monit.rcMonitor.right - monit.rcMonitor.left, monit.rcMonitor.bottom - monit.rcMonitor.top );
	}

	ui.menuAddScreen->clear();
	szItem	= QFU( L"整个桌面 [%1x%2]" ).arg( rtScreen.width() ).arg( rtScreen.height() );
	QAction*	actDesktop	= ui.menuAddScreen->addAction( szItem );
	actDesktop->setData( UINT(-1) );
	if ( iScreenCount > 1 )
	{
		for ( int i = 0; i < iScreenCount; ++i )
		{
			Screen_GetInfo( i, &monit );
			rtScreen	= QRect( monit.rcMonitor.left, monit.rcMonitor.top, 
				monit.rcMonitor.right - monit.rcMonitor.left, monit.rcMonitor.bottom - monit.rcMonitor.top );
			szItem	= QFU( L"屏幕 %1 [%2x%3]" ).arg(i).arg( rtScreen.width() ).arg( rtScreen.height() );
			QAction*	actScreen	= ui.menuAddScreen->addAction( szItem );
			actScreen->setData( UINT(i) );
		}
	}
	ui.menuAddScreen->addSeparator();

	HWND			hWnd	= GetTopWindow( NULL );
	WCHAR			szWindow[MAX_PATH]	= {0};
	DWORD			dwStyle				= 0;
	DWORD			dwStyleEx			= 0;
	BOOL			bAddWindow			= FALSE;
	QFontMetrics	fm( ui.menuAddScreen->font() );
	HWND			hMenuWnd			= ui.menuChipInput->winId();
	HWND			hMyWnd				= winId();
	while( hWnd )
	{
		bAddWindow	= FALSE;
		dwStyle		= GetWindowLong( hWnd, GWL_STYLE );
		dwStyleEx	= GetWindowLong( hWnd, GWL_EXSTYLE );
		while( !bAddWindow )
		{
			if ( hMenuWnd == hWnd || hMyWnd == hWnd ) break;
			if ( dwStyle & ( WS_ICONIC | WS_CHILD ) ) break;
			if ( ( dwStyle & WS_VISIBLE ) == 0 ) break;
			if ( GetWindow( hWnd, GW_OWNER ) ) break;
			if ( GetWindowLong( hWnd, GWL_HWNDPARENT ) ) break;
			bAddWindow	= TRUE;
		}

		if ( bAddWindow )
		{
			if ( InternalGetWindowText( hWnd, szWindow, ARRAYSIZE( szWindow ) ) && szWindow[0] )
			{
				szItem	= fm.elidedText( QFU( szWindow ), Qt::ElideRight, 200 );
				QAction*	actWindow	= ui.menuAddScreen->addAction( szItem );
				actWindow->setData( UINT(hWnd) );
			}
		}
		hWnd	= GetWindow( hWnd, GW_HWNDNEXT );
	}
}

void RDLiveSdkDemo::on_menuAddCamera_aboutToShow()
{
	ui.menuAddCamera->clear();
	int		iCameraCount	= Camera_GetCount();
	if ( iCameraCount )
	{
		ui.menuAddCamera->setVisible( true );
		for ( int i = 0; i < iCameraCount; ++i )
		{
			QAction*	actCamera	= ui.menuAddCamera->addAction( QFU( Camera_GetFriendlyName( i ) ) );
			actCamera->setData( QFU( Camera_GetInternalName( i ) ) );
		}
	}
	else
	{
		ui.menuAddCamera->setVisible( false );
	}
}

void RDLiveSdkDemo::on_menuAddGame_aboutToShow()
{
	ui.menuAddGame->clear();
	int		iGameCount	= Game_GetCount();
	if ( iGameCount )
	{
		IGame_SGameInfo	gameInfo	= {0};
		for ( int i = 0; i < iGameCount; ++i )
		{
			Game_GetInfoByInd( i, &gameInfo );
			QAction*	actGame	= ui.menuAddGame->addAction( QFU( gameInfo.szGameName ) );
			actGame->setData( int( gameInfo.dwProcessId ) );
		}
	}
}

void RDLiveSdkDemo::on_menuAddScreen_triggered ( QAction * action )
{
	IScreen_SCapParams	sCapParams	= {0};
	HCHIP	hChip	= 0;
	UINT	iVal	= action->data().toUInt();
	if ( iVal == 0xFFFFFFFF )
	{
		sCapParams.iScreen	= -1;
	}
	else if ( iVal >= 0 && iVal < 256 )
	{
		sCapParams.iScreen	= iVal;
	}
	else
	{
		sCapParams.hWindow	= HWND(iVal);
	}
	hChip	= Scene_CreateChip( Render_GetCurScene(), 
		ePinInput_Screen,
		Screen_AssembleSource( &sCapParams ) );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		//新添加的元件，不要忘了设置显示。
		Chip_SetVisible( hChip, TRUE );
	}
}

void RDLiveSdkDemo::on_menuAddCamera_triggered ( QAction * action )
{
	HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene(), 
		ePinInput_Camera,
		(LPCWSTR)action->data().toString().utf16() );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}
}

void RDLiveSdkDemo::on_menuAddGame_triggered ( QAction * action )
{
	QString		str	= action->data().toString();
	HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene(), 
		ePinInput_Game,
		(LPCWSTR)action->data().toString().utf16() );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}
}

void RDLiveSdkDemo::on_actAddPicture_triggered( bool checked )
{
	QString	szFilter	= "Images (*.png *.jpg *.jpeg *.gif *.bmp)";
	QString szFileName	= QFileDialog::getOpenFileName( this, "Open File", QString(), szFilter );
	if ( szFileName.isEmpty() ) return;

	HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene(), 
		ePinInput_Picture,
		(LPCWSTR)szFileName.utf16() );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}

	//QString	szFilter	= "Media Files (*.png *.jpg *.jpeg *.gif *.bmp )"
	//	";;Images (*.png *.jpg *.jpeg *.gif *.bmp)"
	//	";;Movies (*.mp4 *.flv *.mkv *.mpg *.mpeg *.avi *.3gp *.ts *.wmv *.asf)";
}


void RDLiveSdkDemo::on_actAddMovie_triggered( bool checked )
{
	QString	szFilter	= "Video Files (*.swf *.mp4 *.m4v *.flv *.f4v *.3gpp)";
	QString szFileName	= QFileDialog::getOpenFileName( this, "Open File", QString(), szFilter );
	if ( szFileName.isEmpty() ) return;

	HCHIP	hChip	= 0;
	if ( szFileName.lastIndexOf( ".swf", -1, Qt::CaseInsensitive ) == szFileName.length() - 4 )
	{
		hChip	= Scene_CreateChip( Render_GetCurScene(), ePinInput_Flash,
			(LPCWSTR)szFileName.utf16(), FALSE, TRUE );
	}
	else
	{
		hChip	= Scene_CreateChip( Render_GetCurScene(), ePinInput_Movie,
			(LPCWSTR)szFileName.utf16(), FALSE, TRUE );
	}
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}
}

void RDLiveSdkDemo::on_actAddOnline_triggered( bool checked )
{
	bool	bOk		= false;
	QString	szUrl	= QInputDialog::getText( this, QFU( L"添加在线视频" ), QFU( L"URL：" ),
		QLineEdit::Normal, QString(), &bOk );

	if ( !bOk ) return;
	if ( szUrl.isEmpty() ) return;

	HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene(), ePinInput_Movie,
		(LPCWSTR)szUrl.utf16(), FALSE, TRUE );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}

}

void RDLiveSdkDemo::on_actAddText_triggered( bool checked )
{
	QString	szText	= QFU( L"黑体|I|0|0,Hello" );
	HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene(), ePinInput_Text,
		(LPCWSTR)szText.utf16() );
	if ( hChip )
	{
		Chip_SetRectPercent( hChip, 0.1f, 0.4f, 0.8f, 0.2f, eKeepAspectRatio );
		Chip_SetVisible( hChip, TRUE );
	}
}

void RDLiveSdkDemo::on_actGameRec_toggled( bool checked )
{
	if ( checked )
		Game_InitRecord( FALSE );
	else
		Game_UninitRecord();
	QDomElement		eleFun	= FindXmlElement( "Function" );
	eleFun.setAttribute( "GameRec", checked ? 1 : 0 );
}

void RDLiveSdkDemo::on_actCapCursor_toggled( bool checked )
{
	QDomElement		eleFun	= FindXmlElement( "Function" );
	eleFun.setAttribute( "CursorCapture", checked ? 1 : 0 );
	Cursor_EnableCapture( checked );
}

void RDLiveSdkDemo::on_actAutoAero_toggled( bool checked )
{
	QDomElement		eleFun	= FindXmlElement( "Function" );
	eleFun.setAttribute( "AutoAero", checked ? 1 : 0 );
	Screen_SetAutoEnableAero( checked );
}

void RDLiveSdkDemo::on_butCutTo_clicked()
{
	QString	szFile	= QApplication::applicationDirPath() + "/Effects.xml";
	QFile	file( szFile );
	if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )	return;
	QDomDocument	doc;
	if ( !doc.setContent( &file ) )	return;
	QDomElement		eleRoot	= doc.documentElement();
	if ( eleRoot.tagName() != "Effects" )	return;

	QDomElement		eleActs	= eleRoot.firstChildElement( "Actions" );
	if ( eleActs.isNull() ) return;
	QDomElement		eleAct	= eleActs.firstChildElement( "Action" );
	if ( eleAct.isNull() ) return;

	QStringList		szList	= QFU( Scene_GetCurrentActions( Render_GetCurScene() ) ).split( "|", QString::SkipEmptyParts );
	QActionGroup	grpAction( this );
	QMenu			menu;
	QAction*		actSingle	= menu.addAction( QFU(L"单选") );
	menu.addSeparator();
	actSingle->setCheckable( true );
	actSingle->setChecked( m_bSceneActionSingle );
	grpAction.setExclusive( m_bSceneActionSingle );

	while( !eleAct.isNull() )
	{
		QAction*	act	= menu.addAction( eleAct.attribute( "name" ) );
		grpAction.addAction( act );
		act->setData( eleAct.attribute( "file" ) );
		act->setCheckable( true );
		for ( int i = 0; i < szList.count(); ++i )
		{
			if ( szList[i] == eleAct.attribute( "file" ) )
			{
				act->setChecked( true );
				break;
			}
		}
		eleAct	= eleAct.nextSiblingElement( "Action" );
	}
	
	QAction*	pSelect	= menu.exec( ui.butCutTo->mapToGlobal( QPoint( 0, ui.butCutTo->height() ) ) );
	if ( pSelect )
	{
		if ( pSelect == actSingle )
		{
			m_bSceneActionSingle	= !m_bSceneActionSingle;
		}
		else
		{
			QString	szActs;
			QList<QAction*>	actList	= grpAction.actions();
			for ( int i = 0; i < actList.count(); ++i )
			{
				if ( actList[i]->isChecked() )
				{
					szActs.append( actList[i]->data().toString() );
					szActs.append( "|" );
				}
			}
			Scene_SetSwitchActions( Render_GetCurScene(), szActs.utf16() );
		}
	}
}