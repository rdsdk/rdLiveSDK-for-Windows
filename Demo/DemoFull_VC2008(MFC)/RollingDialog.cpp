// RollingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "RollingDialog.h"


// CRollingDialog 对话框

IMPLEMENT_DYNAMIC(CRollingDialog, CDialog)

CRollingDialog::CRollingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CRollingDialog::IDD, pParent)
{
	iDisplayingSerialNumber = 0;
	m_VideoDialog_width = 0;
	m_VideoDialog_height =0;
	m_VideoDialog = NULL;

	m_codingOutDialog = NULL;//编码输出
	m_codingOutDialog_width = 0;//编码输出宽
	m_codingOutDialog_height = 0;//编码输出高

	m_AudioCOdingDialog = NULL;//音频编码
	m_AudioCOdingDialog_width = 0;//音频编码宽
	m_AudioCOdingDialog_height = 0;//音频编码高
}

CRollingDialog::~CRollingDialog()
{
}

void CRollingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRollingDialog, CDialog)
	ON_WM_SIZE()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLL_BAR, &CRollingDialog::OnNMThemeChangedScrollBar)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

void CRollingDialog::OnSize( UINT nType, int cx, int cy )
{
	AdjustSize();
	CDialog::OnSize(nType,cx,cy);
}


// CRollingDialog 消息处理程序

void CRollingDialog::OnNMThemeChangedScrollBar(NMHDR *pNMHDR, LRESULT *pResult)
{

	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

BOOL CRollingDialog::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);
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

void CRollingDialog::OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
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

void CRollingDialog::MoveWindows( int ipos )
{
	switch( iDisplayingSerialNumber )
	{
	case 0:
		{
			if ( m_VideoDialog != NULL )
			{
				CRect MOVE_rc;
				m_VideoDialog->GetClientRect(MOVE_rc);
				int width = MOVE_rc.Width();
				int height = MOVE_rc.Height();
				
				m_VideoDialog->MoveWindow(MOVE_rc.left ,MOVE_rc.top + ipos,width,height,TRUE);

			}
			
		}
		break;
	case 1:
		{
			if ( m_AudioCOdingDialog != NULL )
			{
				CRect MOVE_rc;
				m_AudioCOdingDialog->GetClientRect(MOVE_rc);
				int width = MOVE_rc.Width();
				int height = MOVE_rc.Height();
				m_AudioCOdingDialog->MoveWindow(MOVE_rc.left ,MOVE_rc.top + ipos,width,height,TRUE);
			}
		}
		break;
	case 2:
		{
			if ( m_codingOutDialog != NULL )
			{
				CRect MOVE_rc;
				m_codingOutDialog->GetClientRect(MOVE_rc);
				int width = MOVE_rc.Width();
				int height = MOVE_rc.Height();
				m_codingOutDialog->MoveWindow(MOVE_rc.left ,MOVE_rc.top + ipos,width,height,TRUE);
			}
		}
		break;
	}
}

void CRollingDialog::AdjustSize()
{
	if(!GetDlgItem(IDC_SCROLL_BAR)) return;
	CRect rc;
	GetClientRect( rc );
	switch( iDisplayingSerialNumber )
	{
	case 0:
		{
			CRect MOVE_rc;
			
			if ( m_VideoDialog_height >  rc.Height())
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_SCROLL_BAR)->GetClientRect(MOVE_rc);
				int Scroll_bar_width = MOVE_rc.Width();
				MOVE_rc.right = rc.right;
				MOVE_rc.left = rc.right - Scroll_bar_width;
				MOVE_rc.bottom = rc.bottom;
				GetDlgItem(IDC_SCROLL_BAR)->MoveWindow(&MOVE_rc);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);

				wndScrollBar->SetScrollRange(0, m_VideoDialog_height - rc.Height() );
			}
			else
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_HIDE);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);
				wndScrollBar->SetScrollRange(0,0);
			}

			MOVE_rc.left = 0;
			MOVE_rc.top = 0;
			MOVE_rc.bottom = m_VideoDialog_height;
			MOVE_rc.right = m_VideoDialog_width;
			m_VideoDialog->MoveWindow(&MOVE_rc);
			m_VideoDialog->ShowWindow(SW_SHOW);


			if( m_AudioCOdingDialog != NULL )
				m_AudioCOdingDialog->ShowWindow(SW_HIDE);
			if( m_codingOutDialog != NULL )
				m_codingOutDialog->ShowWindow(SW_HIDE);
		}
		break;
	case 1:
		{
			if( m_VideoDialog != NULL )
				m_VideoDialog->ShowWindow(SW_HIDE);
			if( m_codingOutDialog != NULL )
				m_codingOutDialog->ShowWindow(SW_HIDE);

			
			CRect MOVE_rc;
			
			if ( m_AudioCOdingDialog_height >  rc.Height())
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_SCROLL_BAR)->GetClientRect(MOVE_rc);
				int Scroll_bar_width = MOVE_rc.Width();
				MOVE_rc.right = rc.right;
				MOVE_rc.left = rc.right - Scroll_bar_width;
				MOVE_rc.bottom = rc.bottom;
				GetDlgItem(IDC_SCROLL_BAR)->MoveWindow(&MOVE_rc);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);

				wndScrollBar->SetScrollRange(0, m_AudioCOdingDialog_height - rc.Height() );
			}
			else
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_HIDE);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);
				wndScrollBar->SetScrollRange(0,0);
			}

			MOVE_rc.left = 0;
			MOVE_rc.top = 0;
			MOVE_rc.bottom = m_AudioCOdingDialog_height;
			MOVE_rc.right = m_AudioCOdingDialog_width;
			m_AudioCOdingDialog->MoveWindow(&MOVE_rc);
			m_AudioCOdingDialog->ShowWindow(SW_SHOW);
		}
		break;
	case 2:
		{
			if( m_VideoDialog != NULL )
				m_VideoDialog->ShowWindow(SW_HIDE);
			if( m_AudioCOdingDialog != NULL )
				m_AudioCOdingDialog->ShowWindow(SW_HIDE);

			CRect MOVE_rc;
			
			if ( m_codingOutDialog_height >  rc.Height())
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_SCROLL_BAR)->GetClientRect(MOVE_rc);
				int Scroll_bar_width = MOVE_rc.Width();
				MOVE_rc.right = rc.right;
				MOVE_rc.left = rc.right - Scroll_bar_width;
				MOVE_rc.bottom = rc.bottom;
				GetDlgItem(IDC_SCROLL_BAR)->MoveWindow(&MOVE_rc);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);

				wndScrollBar->SetScrollRange(0, m_codingOutDialog_height - rc.Height() );
			}
			else
			{
				GetDlgItem(IDC_SCROLL_BAR)->ShowWindow(SW_HIDE);
				CScrollBar  * wndScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLL_BAR);
				wndScrollBar->SetScrollRange(0,0);
			}

			MOVE_rc.left = 0;
			MOVE_rc.top = 0;
			MOVE_rc.bottom = m_codingOutDialog_height;
			MOVE_rc.right = m_codingOutDialog_width;
			m_codingOutDialog->MoveWindow(&MOVE_rc);
			m_codingOutDialog->ShowWindow(SW_SHOW);
		}
		break;
	}
}

void CRollingDialog::Init()
{
	CRect MOVE_rc;
	if ( m_codingOutDialog == NULL )
	{
		m_codingOutDialog = new CodingOutDialog(this);
		m_codingOutDialog->Create(IDD_DIALOG6,this);
		m_codingOutDialog->GetClientRect(MOVE_rc);
		m_codingOutDialog->Init();
		m_codingOutDialog_height = MOVE_rc.Height();
		m_codingOutDialog_width = MOVE_rc.Width();
	}


	if ( m_AudioCOdingDialog == NULL )
	{
		m_AudioCOdingDialog = new AudioCodingDialog(this);
		m_AudioCOdingDialog->Create(IDD_DIALOG5,this);
		m_AudioCOdingDialog->GetClientRect(MOVE_rc);
		m_AudioCOdingDialog_height = MOVE_rc.Height();
		m_AudioCOdingDialog_width = MOVE_rc.Width();
		m_AudioCOdingDialog->Init();
	}

	if ( m_VideoDialog == NULL )
	{
		m_VideoDialog = new VideoDialog(this);
		m_VideoDialog->Create(IDD_DIALOG_Video,this);
		m_VideoDialog->GetClientRect(MOVE_rc);
		m_VideoDialog->Init();
		m_VideoDialog_height = MOVE_rc.Height();
		m_VideoDialog_width = MOVE_rc.Width();
	}

}

BOOL CRollingDialog::saveEncod( BOOL bPopMsg )
{
	BOOL Error = false;
	if ( m_codingOutDialog != NULL )
	{
		Error = m_codingOutDialog->SvaePife(bPopMsg);
	}

	if ( m_VideoDialog != NULL )
	{
		m_VideoDialog->SaveProfile();
	}

	if ( m_AudioCOdingDialog != NULL )
	{
		m_AudioCOdingDialog->SaveAuido();
	}
	return Error;
}
