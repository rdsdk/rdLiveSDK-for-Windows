// LiveChooseDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "LiveChooseDialog.h"
#include "LiveDialog.h"

// CLiveChooseDialog 对话框

IMPLEMENT_DYNAMIC(CLiveChooseDialog, CDialog)

CLiveChooseDialog::CLiveChooseDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLiveChooseDialog::IDD, pParent)
{	
	m_BisSelected =FALSE;
	m_Bursh.CreateSolidBrush(RGB( 255, 255, 0 ));
}

CLiveChooseDialog::~CLiveChooseDialog()
{
}

void CLiveChooseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_LIVE_TEXT, m_Stat_Live_Text);
	DDX_Control(pDX, IDC_CHECK_live_choose, m_Check_Live_Choose);
}


BEGIN_MESSAGE_MAP(CLiveChooseDialog, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

void CLiveChooseDialog::Init( CString StrDisName , bool Checke )
{
	m_Stat_Live_Text.SetWindowText(StrDisName);
	m_StrDisName = StrDisName;
	m_Check_Live_Choose.SetCheck(Checke);
}

BOOL CLiveChooseDialog::PreTranslateMessage( MSG* pMsg )
{
	if ( pMsg->message == WM_LBUTTONDOWN )
	{
		SetSelected(TRUE);
		Invalidate();
		return FALSE;
	}
	return FALSE;
}

HBRUSH CLiveChooseDialog::OnCtlColor( CDC *pDC,CWnd *pWnd,UINT nCtlColor )
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
			if ( pWnd->m_hWnd == GetDlgItem( IDC_STATIC_LIVE_TEXT )->m_hWnd )
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
			if ( pWnd->m_hWnd == GetDlgItem( IDC_STATIC_LIVE_TEXT )->m_hWnd )
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

void CLiveChooseDialog::SetSelected( BOOL bIsSelected )
{
	if ( bIsSelected )
	{
		int ElementCount = ((CLiveDialog*)m_pant)->m_ArrayDialogElement->m_ArrayElement.GetSize();
		for( int i = 0; i < ElementCount; i++ )
		{
			if ( ((CLiveDialog*)m_pant)->m_ArrayDialogElement->m_ArrayElement[i]->GetSelected() )
			{
				((CLiveDialog*)m_pant)->m_ArrayDialogElement->m_ArrayElement[i]->SetSelected(FALSE);
			}
		}
		//Chip_SetCurent(m_HChip);
		m_BisSelected = TRUE; 
	} 
	else
	{
		m_BisSelected = FALSE; 
	}
	Invalidate();
}

BOOL CLiveChooseDialog::GetSelected()
{
	return m_BisSelected;
}


// CLiveChooseDialog 消息处理程序
