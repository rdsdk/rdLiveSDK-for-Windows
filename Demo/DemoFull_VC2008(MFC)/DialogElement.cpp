// DialogElement.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "DialogElement.h"
#include "scenario.h"

// CDialogElement 对话框

IMPLEMENT_DYNAMIC(CDialogElement, CDialog)

CDialogElement::CDialogElement(CWnd* pParent /*=NULL*/)
: CDialog(CDialogElement::IDD, pParent)
{
	m_eClassType	= ePinInput_Unknow;
	m_BisSelected = FALSE;
	m_Bursh.CreateSolidBrush(RGB( 255, 255, 0 ));
	ZeroMemory( &m_sScrCapParams, sizeof( m_sScrCapParams ) );
	ZeroMemory( &m_sChipStatus, sizeof( m_sChipStatus ) );
	m_HChip = 0;
	m_BIsShow = FALSE;
	m_BIsLockAspect = FALSE;
	m_BIsPosition = FALSE;
	m_BIsAngle =FALSE;
	m_BIsSize =FALSE;
	GdiplusStartupInput gdiplusinput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusinput, NULL);

}

CDialogElement::~CDialogElement()
{
	 Gdiplus::GdiplusShutdown(m_gdiplusToken);  
}

void CDialogElement::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_EXHIBITION_IMAGE, m_Image);
	DDX_Control(pDX, IDC_CHECK_SHOW_HIDE, m_SH_Button);
	DDX_Control(pDX, IDC_CHECK5, m_WH_Btton);
	DDX_Control(pDX, IDC_CHECK6, m_POS_Button);
	DDX_Control(pDX, IDC_CHECK7, m_siz_Button);
	DDX_Control(pDX, IDC_CHECK8, m_rotating_Button);
}


BEGIN_MESSAGE_MAP(CDialogElement, CDialog)
	ON_WM_SIZE()
	//ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_SHOW_HIDE, &CDialogElement::OnBnClickedCheckShowHide)
	ON_BN_CLICKED(IDC_CHECK5, &CDialogElement::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CDialogElement::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CDialogElement::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CDialogElement::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogElement::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogElement::OnBnClickedButton2)
END_MESSAGE_MAP()

void CDialogElement::OnSize( UINT nType, int cx, int cy )
{
	if ( !GetDlgItem(IDC_STATIC_EXHIBITION) ) return;
	CRect rc;
	GetClientRect( rc );

	CRect MOVE_rc;

	//图片
	GetDlgItem(IDC_STATIC_EXHIBITION)->GetClientRect(MOVE_rc);
	int Exhibition_width = MOVE_rc.Width();
	int Exhibition_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = (rc.Height() - Exhibition_height)/2;
	MOVE_rc.bottom = MOVE_rc.top + Exhibition_height + 5;
	MOVE_rc.right = Exhibition_width + MOVE_rc.left + 10;
	GetDlgItem(IDC_STATIC_EXHIBITION)->MoveWindow(MOVE_rc,TRUE);

	//框
	GetDlgItem(IDC_STATIC_ELEMENT )->GetClientRect(MOVE_rc);
	int Element_width = MOVE_rc.Width();
	int Element_height= MOVE_rc.Height();
	MOVE_rc.left = Exhibition_width + 20 + 5;
	MOVE_rc.top = (rc.Height() - Element_height)/2;
	MOVE_rc.bottom = MOVE_rc.top + Element_height;
	MOVE_rc.right = rc.Width() - 10;
	GetDlgItem(IDC_STATIC_ELEMENT)->MoveWindow(MOVE_rc,TRUE);

}

BOOL CDialogElement::PreTranslateMessage( MSG* pMsg )
{
	if ( pMsg->message == WM_LBUTTONDOWN )
	{
		SetSelected(TRUE);
		Invalidate();
		return FALSE;
	}
	return FALSE;
}

HBRUSH CDialogElement::OnCtlColor( CDC *pDC,CWnd *pWnd,UINT nCtlColor )
{
	if ( m_BisSelected )
	{
		if ( nCtlColor == CTLCOLOR_DLG )
		{
			m_Bursh.DeleteObject();
			m_Bursh.CreateSolidBrush( RGB(170,170,170));

		}
		else if ( nCtlColor == CTLCOLOR_STATIC )
		{
			if ( pWnd->m_hWnd == GetDlgItem( IDC_S_ELEMENT_NAME )->m_hWnd )
			{
				m_Bursh.DeleteObject();
				m_Bursh.CreateSolidBrush( RGB(255,255,255));

			}
		}
		else
		{
			m_Bursh.DeleteObject();
			m_Bursh.CreateSolidBrush( RGB(255,255,255));

		}
	} 
	else
	{
		if ( nCtlColor == CTLCOLOR_DLG )
		{
			m_Bursh.DeleteObject();
			m_Bursh.CreateSolidBrush( RGB(250,250,250));

		}
		else if ( nCtlColor == CTLCOLOR_STATIC )
		{
			if ( pWnd->m_hWnd == GetDlgItem( IDC_S_ELEMENT_NAME )->m_hWnd )
			{
				m_Bursh.DeleteObject();
				m_Bursh.CreateSolidBrush( RGB(255,255,255));

			}
		}
		else
		{
			m_Bursh.DeleteObject();
			m_Bursh.CreateSolidBrush( RGB(255,255,255));

		}
	}

	return (HBRUSH)m_Bursh.m_hObject;
}

void CDialogElement::SetSelected( BOOL bIsSelected )
{
	if ( bIsSelected )
	{
		int ElementCount = ((scenario*)m_pant)->m_ArrayDialogElement->m_ArrayElement.GetSize();
		for( int i = 0; i < ElementCount; i++ )
		{
			if ( ((scenario*)m_pant)->m_ArrayDialogElement->m_ArrayElement[i]->GetSelected() )
			{
				((scenario*)m_pant)->m_ArrayDialogElement->m_ArrayElement[i]->SetSelected(FALSE);
			}
		}
		Chip_SetCurent(m_HChip);
		m_BisSelected = TRUE; 
	} 
	else
	{
		m_BisSelected = FALSE; 
	}
	Invalidate();
}

BOOL CDialogElement::GetSelected()
{
	return m_BisSelected;
}

void CDialogElement::SetElementName( )
{
	int ImageID = -1;
	CString szName;
	m_eClassType	=  Chip_GetClassType( m_HChip );
	m_szSource	=  Chip_GetSourceName( m_HChip );
	//QFontMetrics	fm( ui.labSourceName->font() );
	if ( m_eClassType == ePinInput_Unknow )
	{
		szName	= "Unknow";
		ImageID = 0;
	}
	else if ( m_eClassType == ePinInput_Picture )
	{
		szName	= m_szSource;
		ImageID = 1;
		//szName	= fm.elidedText( szName, Qt::ElideLeft, ui.labSourceName->width() );
	}
	else if ( m_eClassType == ePinInput_Camera )
	{
		int	iCamera	= Camera_GetIndex( m_szSource );
		if ( iCamera >= 0 ) 
			szName	= Camera_GetFriendlyName( iCamera );
		ImageID = 2;
		/*szName	= fm.elidedText( szName, Qt::ElideRight, ui.labSourceName->width() );*/
	}
	else if ( m_eClassType == ePinInput_Screen )
	{
		if ( Screen_AnalysisSource( m_szSource, &m_sScrCapParams ) )
		{
			if ( m_sScrCapParams.szWindow[0] )
			{
				szName	= L"窗口：" ;
				szName	+= m_sScrCapParams.szWindow; 
				ImageID = 3;
			}
			else if ( m_sScrCapParams.hWindow )
			{
				szName	= L"窗口：" ;
				WCHAR	szWindow[MAX_PATH]	= {0};
				if ( 0 == InternalGetWindowText( m_sScrCapParams.hWindow, szWindow, ARRAYSIZE( szWindow ) ) || 0 == szWindow[0] )
				{
					wsprintf( szWindow, L"0x08X", m_sScrCapParams.hWindow );
					szName	+= szWindow;
				}
				szName	+= szWindow;
				ImageID = 3;
			}
			else if ( m_sScrCapParams.iScreen < 0 )
			{
				if ( m_sScrCapParams.bUseInitRect )
				{
					char heightBuffer[10] = {0};
					char WidthBuffer[10] = {0};
					_itoa_s(m_sScrCapParams.rtInit.bottom,heightBuffer,sizeof(heightBuffer),10);
					_itoa_s(m_sScrCapParams.rtInit.right,WidthBuffer,sizeof(WidthBuffer),10);
					szName	= L"桌面 [" ;
					szName += WidthBuffer;
					szName += L"x";
					szName += heightBuffer;
					szName += L"]";
					ImageID = 4;
				}
				else
				{
					MONITORINFOEXW	monit;
					CRect			rtScreen;
					for ( int i = 0; i < Screen_GetCount(); ++i )
					{
						Screen_GetInfo( i, &monit );
						rtScreen	|= CRect( monit.rcMonitor.left, monit.rcMonitor.top, 
							monit.rcMonitor.right - monit.rcMonitor.left, monit.rcMonitor.bottom - monit.rcMonitor.top );
					}
					char heightBuffer[10] = {0};
					char WidthBuffer[10] = {0};
					_itoa_s(rtScreen.bottom,heightBuffer,sizeof(heightBuffer),10);
					_itoa_s(rtScreen.right,WidthBuffer,sizeof(WidthBuffer), 10);
					szName	= L"整个桌面 [" ;
					szName += WidthBuffer;
					szName += L"x";
					szName += heightBuffer;
					szName += L"]";
					ImageID = 4;
				}
			}
			else
			{
				if ( m_sScrCapParams.bUseInitRect )
				{
					char srightBuffer[10] = {0};
					char sleftBuffer[10] = {0};
					char stopBuffer[10] = {0};
					char sbottomBuffer[10] = {0};
					char sScreenCount[5] = {0};
					_itoa_s(m_sScrCapParams.rtInit.left,srightBuffer,sizeof(srightBuffer),10);
					_itoa_s( m_sScrCapParams.rtInit.right ,sleftBuffer,sizeof( sleftBuffer ),10);
					_itoa_s(m_sScrCapParams.rtInit.top,stopBuffer,sizeof(stopBuffer),10);
					_itoa_s( m_sScrCapParams.rtInit.bottom ,sbottomBuffer,sizeof( sbottomBuffer ),10);
					_itoa_s(m_sScrCapParams.iScreen,sScreenCount,sizeof(sScreenCount),10);
					szName = L"屏幕 ";
					szName += sScreenCount;
					szName += L" (";
					szName += sleftBuffer;
					szName += L",";
					szName += stopBuffer;
					szName += L")-(";
					szName += srightBuffer;
					szName += L",";
					szName += sbottomBuffer;
					szName += L")";
					ImageID = 4;
				}
				else
				{
					MONITORINFOEXW	monit;
					CRect			rtScreen;
					Screen_GetInfo( m_sScrCapParams.iScreen, &monit );
					rtScreen	= CRect( monit.rcMonitor.left, monit.rcMonitor.top, 
						monit.rcMonitor.right - monit.rcMonitor.left, monit.rcMonitor.bottom - monit.rcMonitor.top );

					char sXBuffer[5] = {0};
					char sYBuffer[5] = {0};
					char sbottomBuffer[5] = {0};
					char srightBuffer[5] = {0};
					char sScreenCount[5] = {0};
					_itoa_s(rtScreen.left,sXBuffer,sizeof(sXBuffer),10);
					_itoa_s( rtScreen.top ,sYBuffer,sizeof( sYBuffer), 10);
					_itoa_s(rtScreen.right + 1 ,srightBuffer,sizeof(srightBuffer),10);
					_itoa_s( rtScreen.bottom + 1 ,sbottomBuffer,sizeof(sbottomBuffer),10);
					_itoa_s(m_sScrCapParams.iScreen,sScreenCount,sizeof(sScreenCount),10);
					szName = L"屏幕 ";
					szName += sScreenCount;
					szName += L" (";
					szName += sXBuffer;
					szName += L",";
					szName += sYBuffer;
					szName += L")-(";
					szName += srightBuffer;
					szName += L",";
					szName += sbottomBuffer;
					szName += L")";
					ImageID = 4;
				}
			}
		}
	}
	//图标显示
	switch( ImageID )
	{
	case 0:
		DrawImage(IDB_inpMovie);
		break;
	case 1:
		DrawImage(IDB_inpPicture);
		break;
	case 2:
		DrawImage(ID_inpCarmera);
		break;
	case 3:
		DrawImage(IDB_inpWindows);
		break;
	case 4:
		DrawImage(IDB_inpDesktop);
		break;
	}
	GetDlgItem(IDC_S_ELEMENT_NAME)->SetWindowText(szName);
}

// CDialogElement 消息处理程序

void CDialogElement::OnBnClickedCheckShowHide()
{	

	if ( m_BIsShow )
		m_BIsShow = FALSE;
	else
		m_BIsShow = TRUE;

	Chip_SetVisible( m_HChip, m_BIsShow ? FALSE : TRUE );
	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedCheck5()
{

	if ( m_BIsLockAspect )
		m_BIsLockAspect = FALSE;
	else
		m_BIsLockAspect = TRUE;

	Chip_SetViewLock( m_HChip, eLock_AspectRatio, m_BIsLockAspect ? TRUE : FALSE );
	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedCheck6()
{

	if ( m_BIsPosition )
		m_BIsPosition = FALSE;
	else
		m_BIsPosition = TRUE;


	Chip_SetViewLock( m_HChip, eLock_Position, m_BIsPosition ? TRUE : FALSE );
	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedCheck7()
{
	if ( m_BIsSize )
		m_BIsSize = FALSE;
	else
		m_BIsSize = TRUE;

	Chip_SetViewLock( m_HChip, eLock_Size, m_BIsSize ? TRUE : FALSE );
	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedCheck8()
{

	if ( m_BIsAngle )
		m_BIsAngle = FALSE;
	else
		m_BIsAngle = TRUE;

	Chip_SetViewLock( m_HChip, eLock_Angle, m_BIsAngle ? TRUE : FALSE );

	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedButton1()
{
	FLOAT fWidth, fHeight;
	Chip_GetRectPercent( m_HChip, NULL, NULL, &fWidth, &fHeight, FALSE );
	IChip_EBorderFitMode	eFitMode	= Chip_GetViewLock( m_HChip, eLock_AspectRatio ) ? eKeepAspectRatio : eIgnoreAspectRatio;
	Chip_SetRectPercent( m_HChip, ( 1.0f - fWidth ) * 0.5f, ( 1.0f - fHeight ) * 0.5f, fWidth, fHeight, eFitMode );
	// TODO: 在此添加控件通知处理程序代码
}

void CDialogElement::OnBnClickedButton2()
{
	IChip_EBorderFitMode	eFitMode	= eIgnoreAspectRatio;
	FLOAT fX, fY, fWidth, fHeight;
	Chip_GetRectPercent( m_HChip, &fX, &fY, &fWidth, &fHeight, FALSE );
	if ( Chip_GetViewLock( m_HChip, eLock_AspectRatio ) )
	{
		if ( ( fX == 0.0f && fWidth == 1.0f && fY >= 0.0f && fHeight <= 1.0f ) ||
			( fX >= 0.0f && fWidth <= 1.0f && fY == 0.0f && fHeight == 1.0f ) )
		{
			eFitMode	= eKeepAspectRatioByExpanding;
		}
		else
		{
			eFitMode	= eKeepAspectRatio;
		}
	}
	Chip_SetRectPercent( m_HChip, 0.0f, 0.0f, 1.0f, 1.0f, eFitMode );
	// TODO: 在此添加控件通知处理程序代码
}

BOOL LoadImageFromResource(CImage *pImage, UINT nResID,LPCTSTR lpTyp)
{
	if ( pImage == NULL) 
		return false;
	pImage->Destroy();
	// 查找资源
	HRSRC hRsrc = ::FindResource(GetModuleHandle(NULL), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL) 
		return false;
	// 加载资源
	HGLOBAL hImgData = ::LoadResource(GetModuleHandle(NULL), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}
	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);
	// 解除内存中的指定资源
	::GlobalUnlock(hNew);
	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if ( ht != S_OK )
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		pImage->Load(pStream);
		GlobalFree(hNew);
	}
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

void MyLoadImage(DWORD resID, Image** pImg)
{
	HRSRC hRsrc = ::FindResource (AfxGetResourceHandle(),MAKEINTRESOURCE(resID), L"PNG"); // type
	if (!hRsrc)
		return;
	// load resource into memory
	DWORD len = SizeofResource(AfxGetResourceHandle(), hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(AfxGetResourceHandle(), hRsrc);
	if (!lpRsrc)
		return;

	// Allocate global memory on which to create stream
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem,lpRsrc,len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem,FALSE,&pstm);

	//通过FromStream返回各Image*，然后在Graphic的DrawImage地方调用
	*pImg = Gdiplus::Image::FromStream(pstm);

	/*CClientDC dc(this);
	Graphics graphics(dc.m_hDC);
	graphics.DrawImage(pImg, 0, 0);*/
	// free/release stuff
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);


}
void CDialogElement::DrawImage( UINT ImageID )
{
	CWnd* pic = GetDlgItem(IDC_STATIC_EXHIBITION_IMAGE);    // 用此句，得到图片控件的CWnd，图片将被绘制在控件上，IDC_PIC_VIEW为picture control的控件ID  
	Graphics graphics(pic->GetDC()->m_hDC);  
	//Image pImg(L"D:\\88084e2a3e93ee825d215e404df737d1.jpg");         //加载图片
	//Image *pImg;         //加载图片  
	//MyLoadImage(ImageID, &pImg);
	CRect rect;  
	Gdiplus::SolidBrush solidBrush(Gdiplus::Color::Red); 
	Gdiplus::FontFamily fontFamily(L"宋体");
	Gdiplus::Font	    font(&fontFamily, 16, FontStyleRegular, UnitPoint);

	graphics.DrawString(L"GDI+程序示意",30, &font, Gdiplus::PointF(0, 0), &solidBrush);
	//graphics.ReleaseHDC(pic->GetDC()->m_hDC);
	//graphics.DrawImage(&pImg, 0, 0,rect.Width(),rect.Height());  

	// GdiplusShutdown(m_gdiplusToken);
}

void CDialogElement::Init()
{
	if ( m_HChip )
	{
		if( !Chip_IsVisible( m_HChip ) )
		{
			m_SH_Button.SetCheck(TRUE);
			m_BIsShow = TRUE;
			
		}
		if (Chip_GetViewLock( m_HChip ,eLock_AspectRatio))
		{
			m_WH_Btton.SetCheck(TRUE);
			m_BIsLockAspect = TRUE;
		}
		if(Chip_GetViewLock( m_HChip, eLock_Position))
		{
			m_POS_Button.SetCheck(TRUE);
			m_BIsPosition = TRUE;
		}
		if(Chip_GetViewLock( m_HChip, eLock_Angle))
		{
			m_rotating_Button.SetCheck(TRUE);
			m_BIsAngle = TRUE;
		}
		if( Chip_GetViewLock( m_HChip,eLock_Size) )
		{
			m_siz_Button.SetCheck(TRUE);
			m_BIsSize = TRUE;
		}
	}
}
