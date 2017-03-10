// scenario.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "scenario.h"
#include "DialogElement.h"
// scenario 对话框

IMPLEMENT_DYNAMIC(scenario, CDialog)

scenario::scenario(CWnd* pParent /*=NULL*/)
: CDialog(scenario::IDD, pParent)
{
	m_AddButtonMenu = NULL;
	m_MenuCamera = NULL;
	m_MenuScreen = NULL;
	m_ArrayDialogElement = NULL;

	m_HWndList = NULL;
	m_CameraCount = 0;
	m_ScreenCount = 0;
	m_HWndCount = 0;
	m_Height = 0;
}

scenario::~scenario()
{
}

void scenario::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//GetDlgItem(IDC_SCROLLBAR_ELEMENT)->ShowWindow(SW_HIDE);
	CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR_ELEMENT);
	//wndScrollBar->SetScrollRange(0,0);
}


BEGIN_MESSAGE_MAP(scenario, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &scenario::OnBnClickedButtonAdd)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON_MOVE_UP, &scenario::OnBnClickedButtonMoveUp)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &scenario::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MOVE_DOWN, &scenario::OnBnClickedButtonMoveDown)
END_MESSAGE_MAP()

void scenario::OnSize( UINT nType, int cx, int cy )
{
	if (!GetDlgItem(IDC_BUTTON_ADD))	return;

	CRect rc;
	GetClientRect( rc );

	CRect MOVE_rc;
	//添加场景调整位置与大小
	GetDlgItem(IDC_BUTTON_ADD)->GetClientRect(MOVE_rc);
	int ADD_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = 10;
	MOVE_rc.bottom = ADD_height+10;
	//GetDlgItem(IDC_BUTTON_ADD)->MoveWindow(MOVE_rc,TRUE);

	//场景列表调整位置与大小
	GetDlgItem(IDC_STATIC_SCENA_LIST)->GetClientRect(MOVE_rc);
	MOVE_rc.left = 10;
	MOVE_rc.top = ADD_height + 10 + 10 ;
	MOVE_rc.bottom = rc.Height() - 10;
	MOVE_rc.right = rc.Width() - 10;
	GetDlgItem(IDC_STATIC_SCENA_LIST)->MoveWindow(MOVE_rc,TRUE);

	int ScenaList_with = MOVE_rc.Width();
	//删除按钮调整位置与大小
	GetDlgItem(IDC_BUTTON_DELETE)->GetClientRect(MOVE_rc);
	int Delete_with = MOVE_rc.Width();
	int Delete_height = MOVE_rc.Height();
	MOVE_rc.left = ScenaList_with - Delete_with + 10;
	MOVE_rc.top = 10;
	MOVE_rc.bottom = Delete_height+10;
	MOVE_rc.right = ScenaList_with+ 10;
	GetDlgItem(IDC_BUTTON_DELETE)->MoveWindow(MOVE_rc,TRUE);

	//下移调整位置与大小
	GetDlgItem(IDC_BUTTON_MOVE_DOWN)->GetClientRect(MOVE_rc);
	int MoveDown_width = MOVE_rc.Width();
	int MoveDown_height = MOVE_rc.Height();
	MOVE_rc.left = ScenaList_with + 10 - Delete_with - 20 - MoveDown_width;
	MOVE_rc.top = 10;
	MOVE_rc.bottom = Delete_height + 10;
	MOVE_rc.right = ScenaList_with + 10 - Delete_with - 20;
	GetDlgItem(IDC_BUTTON_MOVE_DOWN)->MoveWindow(MOVE_rc,TRUE);

	//下移调整位置与大小
	GetDlgItem(IDC_BUTTON_MOVE_UP)->GetClientRect(MOVE_rc);
	int MoveUp_width = MOVE_rc.Width();
	int MoveUp_height = MOVE_rc.Height();
	MOVE_rc.left = ScenaList_with + 10 - Delete_with - 20  - MoveDown_width - 20 - MoveUp_width;
	MOVE_rc.top = 10;
	MOVE_rc.bottom = MoveUp_height + 10;
	MOVE_rc.right = ScenaList_with + 10 - Delete_with - 20 - MoveDown_width - 20;
	GetDlgItem(IDC_BUTTON_MOVE_UP)->MoveWindow(MOVE_rc,TRUE);

	GetDlgItem(IDC_STATIC_SCENA_LIST)->GetClientRect(rc);
	int bottm = rc.bottom;
	if ( m_Height >  rc.Height())
	{
		GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->ShowWindow(SW_SHOW);
		CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
		int Height=  m_Height - rc.Height() ;
		wndScrollBar->SetScrollRange(0,Height);
	}
	else
	{
		GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->ShowWindow(SW_HIDE);
		CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
		wndScrollBar->SetScrollRange(0,0);
	}
	GetClientRect(rc);


	GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->GetClientRect(MOVE_rc);
	int Scroll_bar_width = MOVE_rc.Width();
	MOVE_rc.right = rc.right;
	MOVE_rc.left = rc.right - Scroll_bar_width;
	MOVE_rc.top = rc.bottom - bottm - 12;
	MOVE_rc.bottom =rc.bottom - 10;
	GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->MoveWindow(&MOVE_rc);
}

// scenario 消息处理程序

void scenario::OnBnClickedButtonAdd()
{
	if(!GetDlgItem(IDC_BUTTON_ADD)) return;
	if ( !Render_GetCurScene() )
	{
		CWnd::MessageBox(L"请添加场景后，再添加内容！",L"提示",MB_OK|MB_ICONEXCLAMATION );
		return;
	}
	CRect pt;
	GetDlgItem(IDC_BUTTON_ADD)->GetWindowRect(&pt);
	AddChipMenu(pt,NULL,false);
	// TODO: 在此添加控件通知处理程序代码
}

int scenario::HWndCountW()
{
	int HWndCount = 0;
	HWND			hWnd	= ::GetTopWindow( NULL );
	while( hWnd )
	{
		HWndCount++;
		hWnd	= ::GetWindow( hWnd, GW_HWNDNEXT );
	}
	return HWndCount;
}

BOOL scenario::OnCommand( WPARAM wParam, LPARAM lParam )
{
	int menuID = LOWORD(wParam);
	if( (menuID > (WM_CAMERA-1) ) & ( menuID < WM_CAMERA + m_CameraCount) )

	{
		int iCaremaCount = menuID - WM_CAMERA; 
		HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene() );
		if ( hChip )
		{
			if ( Chip_Open( hChip, L"Camera",Camera_GetDisplayName(iCaremaCount) ) )
			{
				Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
				Chip_SetVisible( hChip, TRUE );
			}
		}
		//添加你自己的处理代码
	}
	else if ( ( menuID > (WM_SCREEN-1) ) & ( menuID < WM_SCREEN + m_ScreenCount ) )
	{
		UINT	iVal = 0;
		if ( WM_SCREEN == menuID )
		{
			iVal = 0xFFFFFFFF;
		}
		IScreen_SCapParams	sCapParams	= {0};
		if ( iVal == 0xFFFFFFFF )
		{
			sCapParams.iScreen	= -1;
		}
		else if ( iVal >= 0 && iVal < 256 )
		{
			sCapParams.iScreen	= iVal;
		}
		HCHIP hChip	= Scene_CreateChip( Render_GetCurScene() );
		if ( hChip )
		{
			if ( Chip_Open( hChip, L"Screen", Screen_AssembleSource( &sCapParams ) ) )
			{
				Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
				//新添加的元件，不要忘了设置显示。
				Chip_SetVisible( hChip, TRUE );
			}
		}
	}
	else if ( ( menuID > (WM_HWND - 1) ) & ( menuID < WM_HWND + m_HWndCount ) )
	{
		UINT	iVal = 0;
		if ( WM_HWND != menuID )
		{
			iVal = menuID - WM_HWND;
		}
		else
		{
			iVal = menuID - WM_HWND ;
		}
		IScreen_SCapParams	sCapParams	= {0};
		if ( int(iVal+1) > m_HWndList->GetSize() )
		{
			return  CDialog::OnCommand(wParam, lParam);  
		}
		sCapParams.hWindow = m_HWndList->GetAt(iVal); 
		HCHIP hChip	= Scene_CreateChip( Render_GetCurScene() );
		if ( hChip )
		{
			if ( Chip_Open( hChip, L"Screen", Screen_AssembleSource( &sCapParams ) ) )
			{
				Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
				//新添加的元件，不要忘了设置显示。
				Chip_SetVisible( hChip, TRUE );
			}
		}
	}
	else if ( menuID == WM_IAMGE )
	{
		CString szFileName = GetImageDir();
		if ( szFileName.IsEmpty() ) return CDialog::OnCommand(wParam, lParam); ;
		HCHIP	hChip	= Scene_CreateChip( Render_GetCurScene() );
		if ( hChip )
		{
			Chip_SetRectPercent( hChip, 0.0f, 0.0f, 1.0f, 1.0f, eKeepAspectRatio );
			Chip_SetVisible( hChip, TRUE );
			if ( Chip_Open( hChip, L"Picture", szFileName ) )
			{

			}
		}
	}

	return CDialog::OnCommand(wParam, lParam);  
}

BOOL scenario::OnRenderNotify( IRender_ENotify eNotify, WPARAM wParam, LPARAM lParam )
{
	int iValue = (int)lParam;
	HSCENE hScene = (HSCENE)wParam;
	SHORT		shLVal	= (SHORT)( iValue & 0xFFFF );
	SHORT		shHVal	= (SHORT)( iValue >> 16 );

	switch( eNotify )
	{
	case eNotify_ChipAdding:
		break;
	case eNotify_ChipAdded:
		if ( shLVal >= 0 )
		{
				if ( m_ArrayDialogElement == NULL )
				{
					m_ArrayDialogElement = new CArrayDialogElement;
				}
				HCHIP Chip = Scene_GetChip( hScene, shLVal );
				CDialogElement * dialogElement = new CDialogElement(this->GetDlgItem(IDC_STATIC_SCENA_LIST));
				dialogElement->Create(IDD_ELEMENT,this->GetDlgItem(IDC_STATIC_SCENA_LIST));
				dialogElement->m_HChip = Chip;
				dialogElement->m_pant = this;
				dialogElement->Init();
				dialogElement->SetElementName( );
				m_ArrayDialogElement->AddDialogElement(dialogElement);
				adjustmentOnComponentsListLayout();
				return TRUE;
			
		}

	case eNotify_ChipDeleting:
		break;
	case eNotify_ChipDeleted:
		if ( shLVal >= 0 )
		{
			m_ArrayDialogElement->DeleteDoalogElment( m_ArrayDialogElement->m_ArrayElement[shLVal] );
			adjustmentOnComponentsListLayout();
			Invalidate();
		}
		return TRUE;
	case eNotify_ChipPosing:
		break;
	case eNotify_ChipPosed:
		/*pChItem	= GetChipItem( pList, iViewLow );
		if ( pChItem ) pChItem->OnPosChanged();*/
		break;
	case eNotify_ChipRotating:
		break;
	case eNotify_ChipRotated:
		break;
	case eNotify_ChipSwitched:
		if ( shLVal >= 0 )
		{
			if ( m_ArrayDialogElement != NULL )
			{
				if( m_ArrayDialogElement->m_ArrayElement.GetSize() > shLVal )
					m_ArrayDialogElement->m_ArrayElement[shLVal]->SetSelected(TRUE);
			}
		}
		/*pList->setCurrentRow( iViewLow );
		pChItem	= ChipItem::GetChipItem( pList, iViewHigh );
		if ( pChItem ) pChItem->OnChipSelected( FALSE );
		pChItem	= ChipItem::GetChipItem( pList, iViewLow );
		if ( pChItem ) pChItem->OnChipSelected( TRUE );*/
		return TRUE;
	case eNotify_ChipIndexChg:
		if ( (shLVal >= 0) && ( shHVal >= 0 ) )
		{
			m_ArrayDialogElement->AdjustSequence(shLVal, shHVal );
			CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
			int iPos = wndScrollBar->GetScrollPos();  
			MoveWindows(-iPos);
		}
		break;
	case eNotify_ChipStatus:
	case eNotify_ChipVisible:
	case eNotify_ChipViewLock:
		/*	if ( iValue >= 0 )
		{
		pChItem	= ChipItem::GetChipItem( pList, iViewLow );
		if ( pChItem ) pChItem->OnStatusChanged();
		}*/
		break;
	case eNotify_ChipSourceSize:
		break;
	}

	return FALSE;
}

void scenario::adjustmentOnComponentsListLayout()
{
	CRect rc;
	GetDlgItem(IDC_STATIC_SCENA_LIST)->GetClientRect(rc);
	CArray< CDialogElement * > * ArrayElement = &(m_ArrayDialogElement->m_ArrayElement);

	CRect MOVE_rc;
	for ( int i = ArrayElement->GetSize(); i > 0; i-- )
	{
		ArrayElement->GetAt(i-1)->GetClientRect(MOVE_rc);
		int Height = MOVE_rc.Height();
		MOVE_rc.left = 2;
		MOVE_rc.top = ArrayElement->GetAt(i-1)->m_cy + 2;
		MOVE_rc.bottom = MOVE_rc.top + Height;
		MOVE_rc.right = rc.Width() - 2;

		ArrayElement->GetAt(i-1)->MoveWindow(MOVE_rc,TRUE);
		ArrayElement->GetAt(i-1)->ShowWindow(SW_SHOW);
	}

	m_Height = MOVE_rc.bottom;

	int bottm = rc.bottom;
	if ( m_Height >  rc.Height())
	{
		GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->ShowWindow(SW_SHOW);
		CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
		int Height=  m_Height - rc.Height() ;
		wndScrollBar->SetScrollRange(0,Height);
	}
	else
	{
		GetDlgItem(IDC_SCROLL_BAR_ELEMENT)->ShowWindow(SW_HIDE);
		CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
		wndScrollBar->SetScrollRange(0,0);
	}
}


BOOL scenario::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR_ELEMENT);
	int iMin = 0, iMax = 0, iPos = wndScrollBar->GetScrollPos();  
	wndScrollBar->GetScrollRange(&iMin, &iMax);  
	if(zDelta>0)//滑轮向上滚动  
	{  
		if (iPos > iMin)  
		{  
			wndScrollBar->SetScrollPos(iPos - 1);  
			m_iEdtPos = iPos - 1;  
			MoveWindows(- iPos + 1);
		}  
	}  
	else//滑轮向下滚动  
	{  
		if (iPos < iMax)  
		{  
			wndScrollBar->SetScrollPos(iPos + 1);  
			m_iEdtPos = iPos + 1; 
			MoveWindows(- iPos - 1);
		}  
	}  

	UpdateData(FALSE);//更新界面上的m_iEdtPos显示  
	return FALSE;
}

void scenario::OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	int iPos = nPos;
	int TempPos = pScrollBar->GetScrollPos();
	int iMin = 0, iMax = 0;
	pScrollBar->GetScrollRange(&iMin, &iMax);
	switch (nSBCode)
	{
	case SB_THUMBTRACK://拖动滑块
		if (iPos < TempPos && iPos >= iMin)
		{
			pScrollBar->SetScrollPos(iPos, TRUE);
			MoveWindows(- iPos);
		}
		else if (iPos > TempPos && iPos <= iMax)
		{
			pScrollBar->SetScrollPos(iPos, TRUE);
			MoveWindows(- iPos);
		}
		m_iEdtPos = pScrollBar->GetScrollPos();


		UpdateData(FALSE);//拖动过程中更新显示
		break;
		//case SB_THUMBPOSITION://拖动完滑块
		//	pScrollBar->SetScrollPos(iPos, FALSE);
		//	
		//	break;
	case SB_LINEUP://点击上边的箭头
		if(TempPos > iMin)
		{
			pScrollBar->SetScrollPos(TempPos-1, TRUE);
			MoveWindows(- TempPos + 1);
		}
		break;
	case SB_LINEDOWN://点击下边的箭头
		if(TempPos < iMax)
		{
			pScrollBar->SetScrollPos(TempPos+1, TRUE);
			MoveWindows(- TempPos + 1);

		}
		break;
	case SB_PAGEUP://点击滚动条上方空白
		if(TempPos > iMin)
		{
			pScrollBar->SetScrollPos(TempPos-1, TRUE);
			MoveWindows(- TempPos + 1);
		}
		break;
	case SB_PAGEDOWN://点击滚动条下方空白
		if(TempPos < iMax)
		{
			pScrollBar->SetScrollPos(TempPos+1, TRUE);
			MoveWindows(- TempPos + 1);
		}
		break;
	case SB_ENDSCROLL://事件响应完
		m_iEdtPos = pScrollBar->GetScrollPos();



		UpdateData(FALSE);
		break;
	default:
		break;
	}

	UpdateData(FALSE);
}

void scenario::MoveWindows( int ipos )
{
	CRect rc;
	GetDlgItem(IDC_STATIC_SCENA_LIST)->GetClientRect(rc);
	CArray< CDialogElement * > * ArrayElement = &(m_ArrayDialogElement->m_ArrayElement);

	for ( int i = ArrayElement->GetSize(); i > 0; i-- )
	{	
		CRect MOVE_rc;
		ArrayElement->GetAt(i-1)->GetClientRect(MOVE_rc);
		int Height = MOVE_rc.Height();
		MOVE_rc.left = 2;
		MOVE_rc.top = ArrayElement->GetAt(i-1)->m_cy + 2 + ipos;
		MOVE_rc.bottom = MOVE_rc.top + Height;
		MOVE_rc.right = rc.Width() - 2;

		ArrayElement->GetAt(i-1)->MoveWindow(MOVE_rc,TRUE);
	}
}

void scenario::OnBnClickedButtonMoveUp()//上移
{
	HSCENE	hScene	= Render_GetCurScene();
	HCHIP	hChip	= Sceen_GetCurChip( hScene );
	if ( hChip )
	{
		Chip_SetIndex( hChip, Chip_GetIndex( hChip, NULL ) + 1 );
	}
	// TODO: 在此添加控件通知处理程序代码
}

void scenario::OnBnClickedButtonDelete()
{
	int		iCur = -1;
	for ( int i = 0; i < m_ArrayDialogElement->m_ArrayElement.GetSize(); i++  )
	{
		if ( m_ArrayDialogElement->m_ArrayElement[i]->m_BisSelected )
		{
			iCur = i;
		}
	}
	if ( iCur >= 0 )
	{

		HCHIP	hChip	= m_ArrayDialogElement->m_ArrayElement[iCur]->m_HChip;
		if ( hChip ) Chip_Destroy( hChip );
	}
	// TODO: 在此添加控件通知处理程序代码
}

void scenario::OnBnClickedButtonMoveDown()
{
	HSCENE	hScene	= Render_GetCurScene();
	HCHIP	hChip	= Sceen_GetCurChip( hScene );
	if ( hChip )
	{
		Chip_SetIndex( hChip, Chip_GetIndex( hChip, NULL ) - 1 );
	}
	// TODO: 在此添加控件通知处理程序代码
}

void scenario::AddChipMenu(CRect rc,CMenu * pMenu  , bool bIsmen)
{
	CRect pt = rc;
	
	BOOL bIsupdate = FALSE;

	int CameraCount = Camera_GetCount();
	int ScreenCount = Screen_GetCount();
	int HWndCount =  HWndCountW();

	//查看摄像头数量是否有增减
	if ( ( m_CameraCount != CameraCount ) || (m_ScreenCount != ScreenCount) || ( m_HWndCount != HWndCount )   )
	{
		m_CameraCount = CameraCount;
		bIsupdate = TRUE;
		if (bIsmen)
		{
			pMenu->DeleteMenu(0,1);
			pMenu->DeleteMenu(0,1);
			pMenu->DeleteMenu(0,1);
		}
		if ( m_MenuCamera != NULL )
		{
			delete m_MenuCamera;
		}

		m_MenuCamera = new CMenu;
		m_MenuCamera->CreatePopupMenu();

		for ( int i = 0; i < m_CameraCount; i ++ )
		{
			m_MenuCamera->AppendMenu(MF_STRING,WM_CAMERA+i,Camera_GetFriendlyName( i ));
		}


		//查看屏幕数量是否有增减
		m_ScreenCount = ScreenCount;
		m_HWndCount = HWndCount;
		bIsupdate = TRUE;

		m_MenuScreen = new CMenu;
		m_MenuScreen->CreatePopupMenu();

		//计算全屏幕的大小
		MONITORINFOEXW	monit;
		CRect rtScreen;
		for ( int i = 0; i < m_ScreenCount; ++i )
		{
			Screen_GetInfo( i, &monit );
			rtScreen	|= CRect( monit.rcMonitor.left, monit.rcMonitor.top, 
				monit.rcMonitor.right, monit.rcMonitor.bottom );
		}

		char heightBuffer[5] = {0};
		char WidthBuffer[5] = {0};
		_itoa_s(rtScreen.Height(),heightBuffer, sizeof( heightBuffer ),10);
		_itoa_s(rtScreen.Width(),WidthBuffer, sizeof( WidthBuffer ), 10);
		CString csScreen = L"整个桌面 ";
		csScreen += L" [";
		csScreen += WidthBuffer;
		csScreen += L"x";
		csScreen += heightBuffer;
		csScreen += L"]";

		m_MenuScreen->AppendMenu(MF_STRING,WM_SCREEN,csScreen);


		//有两个及以上的屏幕，计算单个屏幕的位置与大小
		if ( m_ScreenCount > 1 )
		{
			for ( int i = 0; i < m_ScreenCount; ++i )
			{
				Screen_GetInfo( i, &monit );
				rtScreen	= CRect( monit.rcMonitor.left, monit.rcMonitor.top, 
					monit.rcMonitor.right, monit.rcMonitor.bottom);
				char sheightBuffer[5] = {0};
				char sWidthBuffer[5] = {0};
				char sScreenCount[5] = {0};
				_itoa_s(rtScreen.Height(),sheightBuffer, sizeof( sheightBuffer ), 10);
				_itoa_s(rtScreen.Width(),sWidthBuffer, sizeof( sWidthBuffer ), 10);
				_itoa_s(i,sScreenCount,sizeof( sScreenCount ), 10);
				CString csScreen1 = L"屏幕 ";
				csScreen1 += sScreenCount;
				csScreen1 += L" [";
				csScreen1 += WidthBuffer;
				csScreen1 += L"x";
				csScreen1 += heightBuffer;
				csScreen1 += L"]";

				m_MenuScreen->AppendMenu(MF_STRING,WM_SCREEN+1 + i,csScreen1);
			}
		}

		m_MenuScreen->AppendMenu(MF_SEPARATOR);

		if ( m_HWndList != NULL )
		{
			delete m_HWndList;
		}

		m_HWndList = new CArray<HWND>;
		//窗口
		HWND			hWnd	= ::GetTopWindow( NULL );
		WCHAR			szWindow[MAX_PATH]	= {0};
		DWORD			dwStyle				= 0;
		DWORD			dwStyleEx			= 0;
		BOOL			bAddWindow			= FALSE;
		//QFontMetrics	fm( ui.menuAddScreen->font() );
		INT J = 0;
		while( hWnd )
		{
			bAddWindow	= FALSE;
			dwStyle		= GetWindowLong( hWnd, GWL_STYLE );
			dwStyleEx	= GetWindowLong( hWnd, GWL_EXSTYLE );
			while( !bAddWindow )
			{
				if ( dwStyle & ( WS_ICONIC | WS_CHILD ) ) break;
				if ( ( dwStyle & WS_VISIBLE ) == 0 ) break;
				if ( ::GetWindow( hWnd, GW_OWNER ) ) break;
				if ( ::GetWindowLong( hWnd, GWL_HWNDPARENT ) ) break;

				bAddWindow	= TRUE;
			}

			if ( bAddWindow )
			{
				if ( InternalGetWindowText( hWnd, szWindow, ARRAYSIZE( szWindow ) ) && szWindow[0] )
				{
					m_MenuScreen->AppendMenu(MF_STRING,WM_HWND + J++ ,szWindow);
					m_HWndList->Add( hWnd );
				}
			}
			hWnd	= ::GetWindow( hWnd, GW_HWNDNEXT );
		}

		if ( bIsupdate )
		{
			if ( m_AddButtonMenu != NULL )
			{
				delete m_AddButtonMenu;
			}

			m_AddButtonMenu = new CMenu;
			m_AddButtonMenu->CreatePopupMenu();

			m_AddButtonMenu->AppendMenu(MF_BYPOSITION|MF_POPUP|MF_STRING,(UINT) m_MenuScreen->m_hMenu,L"屏幕/窗口");
			m_AddButtonMenu->AppendMenu(MF_BYPOSITION|MF_POPUP|MF_STRING,(UINT) m_MenuCamera->m_hMenu,L"摄像头");
			m_AddButtonMenu->AppendMenu(MF_STRING,WM_IAMGE,L"图像文件");
		}
	}
	if (bIsmen)
	{
		if ( bIsupdate )
		{
			pMenu->AppendMenu(MF_BYPOSITION|MF_POPUP|MF_STRING,(UINT) m_MenuScreen->m_hMenu,L"屏幕/窗口");
			pMenu->AppendMenu(MF_BYPOSITION|MF_POPUP|MF_STRING,(UINT) m_MenuCamera->m_hMenu,L"摄像头");
			pMenu->AppendMenu(MF_STRING,WM_IAMGE,L"图像文件");
		}
	} 
	else
	{
		m_AddButtonMenu->TrackPopupMenu(TPM_LEFTALIGN,pt.left,pt.bottom,this);  
	}
}

CString scenario::GetImageDir()
{

	//*.jpg  *.jpeg  *.gif *.bmp)
	TCHAR szFilter[] = _T("Iamge(*.bmp)|*.bmp|Iamge(*.jpg)|*.jpg|Iamge(*.png)|*.png|Iamge(*.gif)|*.gif|Iamge(*.jpeg)|*.jpeg||");  
	CFileDialog fileDlg(TRUE, _T("jpg"), NULL, 0, szFilter, this);      

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())   
	{   
		return fileDlg.GetPathName();   
	}   
	return NULL;
}


