// NameDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "NameDialog.h"


// CNameDialog 对话框

IMPLEMENT_DYNAMIC(CNameDialog, CDialog)

CNameDialog::CNameDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNameDialog::IDD, pParent)
{
	m_szName = NULL;
	m_bIsConfirm = FALSE;
}

CNameDialog::~CNameDialog()
{
}

void CNameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNameDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CNameDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CNameDialog 消息处理程序

void CNameDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if ( m_szName != NULL )
	{
		m_bIsConfirm = TRUE;
		CString str;
		GetDlgItem(IDC_Name)->GetWindowText(str);
		m_szName = str;
	}
	OnOK();
}
