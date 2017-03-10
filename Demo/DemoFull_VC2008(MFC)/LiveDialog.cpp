// LiveDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "LiveDialog.h"

// CLiveDialog 对话框

IMPLEMENT_DYNAMIC(CLiveDialog, CDialog)

CLiveDialog::CLiveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLiveDialog::IDD, pParent)
{
	m_ArrayDialogElement = new ArrayLiveChooseDialog;
}

CLiveDialog::~CLiveDialog()
{
}

void CLiveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLL_BAR, m_ScrollBar_Bar);
}


BEGIN_MESSAGE_MAP(CLiveDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

void CLiveDialog::OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
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

void CLiveDialog::adjustmentOnComponentsListLayout()
{
	CRect rc;
	GetClientRect(rc);
	CArray< CLiveChooseDialog * > * ArrayElement = &(m_ArrayDialogElement->m_ArrayElement);

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
		m_ScrollBar_Bar.ShowWindow(SW_SHOW);
		int Height=  m_Height - rc.Height() ;
		m_ScrollBar_Bar.SetScrollRange(0,Height);
	}
	else
	{
		m_ScrollBar_Bar.ShowWindow(SW_HIDE);
		m_ScrollBar_Bar.SetScrollRange(0,0);
	}
}

BOOL CLiveDialog::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	int iMin = 0, iMax = 0, iPos = m_ScrollBar_Bar.GetScrollPos();  
	m_ScrollBar_Bar.GetScrollRange(&iMin, &iMax);  
	if(zDelta>0)//滑轮向上滚动  
	{  
		if (iPos > iMin)  
		{  
			m_ScrollBar_Bar.SetScrollPos(iPos - 1);  
			m_iEdtPos = iPos - 1;  
			MoveWindows(- iPos + 1);
		}  
	}  
	else//滑轮向下滚动  
	{  
		if (iPos < iMax)  
		{  
			m_ScrollBar_Bar.SetScrollPos(iPos + 1);  
			m_iEdtPos = iPos + 1; 
			MoveWindows(- iPos - 1);
		}  
	}  

	UpdateData(FALSE);//更新界面上的m_iEdtPos显示  
	return FALSE;
}

void CLiveDialog::MoveWindows( int ipos )
{	
	CRect rc;
	GetDlgItem(IDC_STATIC_SCENA_LIST)->GetClientRect(rc);
	CArray< CLiveChooseDialog * > * ArrayElement = &(m_ArrayDialogElement->m_ArrayElement);

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

void CLiveDialog::OnSize( UINT nType, int cx, int cy )
{
	
}

void CLiveDialog::AddLiveChooseDialog( CString StrDisName , bool Checke )
{
	CLiveChooseDialog * dialogElement = new CLiveChooseDialog(this);
	dialogElement->Create(IDD_DIALOG_Live,this);
	dialogElement->m_pant = this;
	dialogElement->Init(StrDisName,Checke);
	m_ArrayDialogElement->AddDialogElement(dialogElement);
	adjustmentOnComponentsListLayout();
}


// CLiveDialog 消息处理程序
