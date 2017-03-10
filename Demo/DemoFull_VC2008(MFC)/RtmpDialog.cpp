// RtmpDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "RtmpDialog.h"


// CRtmpDialog 对话框

IMPLEMENT_DYNAMIC(CRtmpDialog, CDialog)

CRtmpDialog::CRtmpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CRtmpDialog::IDD, pParent)
{
	m_bIsConfirm = false;
}

CRtmpDialog::~CRtmpDialog()
{
}

void CRtmpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_RTMP, m_Rtmp_static);
	DDX_Control(pDX, IDC_EDIT_RTMP, m_Rtmp_edit);
	DDX_Control(pDX, IDC_STATIC_RTMP_example, m_Rtmp_exampl_static);
	DDX_Control(pDX, IDC_STATIC_UID_TEXT, m_UID_text);
	DDX_Control(pDX, IDC_EDIT_UID_Edit, m_UID_Edit);
	DDX_Control(pDX, IDC_STATIC_UID_prompt, m_UID_prompt);
	DDX_Control(pDX, IDC_STATIC_UserName, m_UserName);
	DDX_Control(pDX, IDC_EDIT_UserName, m_UserName_Edit);
	DDX_Control(pDX, IDC_STATIC_PW, m_PW_Static);
	DDX_Control(pDX, IDC_EDIT_PW, m_PW_Edit);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);

	m_ComboBox.AddString(L"RTMP 直播");
	m_ComboBox.AddString(L"RDLiveSDK 云直播");
	m_ComboBox.AddString(L"锐动直播 （云直播）");
	DDX_Control(pDX, IDC_CHECK_Login, m_Check_Login);
	m_ComboBox.SetCurSel(0);
	setmodel(0);
}


BEGIN_MESSAGE_MAP(CRtmpDialog, CDialog)
	ON_CBN_SELENDOK(IDC_COMBO1, &CRtmpDialog::OnCbnSelendokCombo1)
	ON_BN_CLICKED(IDOK, &CRtmpDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CRtmpDialog 消息处理程序

void CRtmpDialog::OnCbnSelendokCombo1()
{
	setmodel(m_ComboBox.GetCurSel());
	// TODO: 在此添加控件通知处理程序代码
}

void CRtmpDialog::setmodel( int index )
{
	switch( index )
	{
	case 0:
		m_Rtmp_static.ShowWindow(SW_SHOW);
		m_Rtmp_edit.ShowWindow(SW_SHOW);
		m_Rtmp_exampl_static.ShowWindow(SW_SHOW);

		m_UID_text.ShowWindow(SW_HIDE);
		m_UID_Edit.ShowWindow(SW_HIDE);
		m_UID_prompt.ShowWindow(SW_HIDE);

		m_UserName.ShowWindow(SW_HIDE);
		m_UserName_Edit.ShowWindow(SW_HIDE);
		m_PW_Static.ShowWindow(SW_HIDE);
		m_PW_Edit.ShowWindow(SW_HIDE);
		m_Check_Login.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_Rtmp_static.ShowWindow(SW_HIDE);
		m_Rtmp_edit.ShowWindow(SW_HIDE);
		m_Rtmp_exampl_static.ShowWindow(SW_HIDE);

		m_UID_text.ShowWindow(SW_SHOW);
		m_UID_Edit.ShowWindow(SW_SHOW);
		m_UID_prompt.ShowWindow(SW_SHOW);

		m_UserName.ShowWindow(SW_HIDE);
		m_UserName_Edit.ShowWindow(SW_HIDE);
		m_PW_Static.ShowWindow(SW_HIDE);
		m_PW_Edit.ShowWindow(SW_HIDE);
		m_Check_Login.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_Rtmp_static.ShowWindow(SW_HIDE);
		m_Rtmp_edit.ShowWindow(SW_HIDE);
		m_Rtmp_exampl_static.ShowWindow(SW_HIDE);

		m_UID_text.ShowWindow(SW_HIDE);
		m_UID_Edit.ShowWindow(SW_HIDE);
		m_UID_prompt.ShowWindow(SW_HIDE);

		m_UserName.ShowWindow(SW_SHOW);
		m_UserName_Edit.ShowWindow(SW_SHOW);
		m_PW_Static.ShowWindow(SW_SHOW);
		m_PW_Edit.ShowWindow(SW_SHOW);
		m_Check_Login.ShowWindow(SW_SHOW);
		break;
	}
}

void CRtmpDialog::OnBnClickedOk()
{
	m_sLiveUrl.iType	= m_ComboBox.GetCurSel();
	switch( m_sLiveUrl.iType )
	{
	case 0:
		m_sLiveUrl.szDispName	= L"RTMP：";
		m_Rtmp_edit.GetWindowText(m_sLiveUrl.szUrlOrId);
		if ( m_sLiveUrl.szUrlOrId.IsEmpty() )
		{
			return;
		}
		break;
	case 1:
		m_sLiveUrl.szDispName	= L"RdCloud：";
		m_UID_Edit.GetWindowText(m_sLiveUrl.szUrlOrId);
		if ( m_sLiveUrl.szUrlOrId.IsEmpty() )
		{
			return;
		}
		break;
	case 2:
		m_sLiveUrl.szDispName	= L"锐动直播：";
		m_UserName_Edit.GetWindowText(m_sLiveUrl.szUrlOrId);
		m_PW_Static.GetWindowText(m_sLiveUrl.szPw);
		m_sLiveUrl.bAutoLogin	= m_Check_Login.GetCheck() ? true : false;
		if ( m_sLiveUrl.szUrlOrId.IsEmpty() || m_sLiveUrl.szPw.IsEmpty() )
		{
			return;
		}
		break;
	}
	m_sLiveUrl.szDispName += m_sLiveUrl.szUrlOrId ;
	m_bIsConfirm = TRUE;
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
