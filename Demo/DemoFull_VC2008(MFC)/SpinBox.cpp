// SpinBox.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "SpinBox.h"


// CSpinBox 对话框

IMPLEMENT_DYNAMIC(CSpinBox, CDialog)

CSpinBox::CSpinBox(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinBox::IDD, pParent)
{
	m_SPinNumber = 1;
	m_MInSpinNumber = 0;
	m_MaxSpinNumber = 100;
}

CSpinBox::~CSpinBox()
{
}

void CSpinBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSpinBox, CDialog)
	ON_EN_UPDATE(IDC_EDIT_Text_COUNT, &CSpinBox::OnEnUpdateEditTextCount)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_COUNT, &CSpinBox::OnDeltaposSpinCount)
END_MESSAGE_MAP()


// CSpinBox 消息处理程序

void CSpinBox::OnEnUpdateEditTextCount()
{
	CString CszCount;
	((CEdit*)GetDlgItem(IDC_EDIT_Text_COUNT))->GetWindowText(CszCount);
	m_iRealDataNumber = _wtoi(CszCount);
	bool bIsModify = false;
	if ( m_iRealDataNumber < m_MInSpinNumber )
	{
		m_iRealDataNumber  = m_MInSpinNumber;
		bIsModify = true;
	}
	if ( m_iRealDataNumber > m_MaxSpinNumber )
	{
		m_iRealDataNumber  = m_MaxSpinNumber;
		bIsModify = true;
	}

	if ( bIsModify )
	{
		CString Duration;
		Duration.Format(L"%d", m_iRealDataNumber);
		((CEdit*)GetDlgItem(IDC_EDIT_Text_COUNT))->SetWindowText(Duration);
	}
	
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CSpinBox::OnDeltaposSpinCount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	if(pNMUpDown->iDelta>0)  
	{  
		m_iRealDataNumber -= m_SPinNumber;
		if ( m_iRealDataNumber < m_MInSpinNumber )
		{
			m_iRealDataNumber  = m_MInSpinNumber;
		}
	}  
	if(pNMUpDown->iDelta<0)  
	{  
		m_iRealDataNumber += m_SPinNumber;
		if ( m_iRealDataNumber > m_MaxSpinNumber )
		{
			m_iRealDataNumber  = m_MaxSpinNumber;
		}
	}  
	CString Duration;
	Duration.Format(L"%d", m_iRealDataNumber);
	((CEdit*)GetDlgItem(IDC_EDIT_Text_COUNT))->SetWindowText(Duration);
}

void CSpinBox::Init( int MaxNumber, int MinNumber ,int spinNumber )
{
	m_MInSpinNumber = MinNumber;
	m_MaxSpinNumber = MaxNumber;
	m_SPinNumber = spinNumber;

	CString Duration;
	Duration.Format(L"%d", MinNumber);
	((CEdit*)GetDlgItem(IDC_EDIT_Text_COUNT))->SetWindowText(Duration);
}

void CSpinBox::SetEndleWindows( int isEndele )
{
	GetDlgItem(IDC_EDIT_Text_COUNT)->EnableWindow( isEndele );
	GetDlgItem(IDC_SPIN_COUNT)->EnableWindow(isEndele);
}	

void CSpinBox::SetCurrentNumber( int CurrentNumber )
{
	if ( (CurrentNumber > m_MInSpinNumber) && (CurrentNumber <= m_MaxSpinNumber) )
	{
		m_iRealDataNumber  = CurrentNumber;
	}
	else
	{
		m_iRealDataNumber = m_MInSpinNumber;
	}

	CString Duration;
	Duration.Format(L"%d", m_iRealDataNumber);
	((CEdit*)GetDlgItem(IDC_EDIT_Text_COUNT))->SetWindowText(Duration);
}
