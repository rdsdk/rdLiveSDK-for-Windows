// SettingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "SettingDialog.h"


// SettingDialog 对话框

IMPLEMENT_DYNAMIC(SettingDialog, CDialog)

SettingDialog::SettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SettingDialog::IDD, pParent)
{
	m_selectCount = 0;
	m_RollingDialog = NULL;
}

SettingDialog::~SettingDialog()
{
}

void SettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SettingDialog, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_Video_ENCODE, &SettingDialog::OnBnClickedButtonVideoEncode)
	ON_BN_CLICKED(IDC_BUTTON_Adio_ENCODE, &SettingDialog::OnBnClickedButtonAdioEncode)
	ON_BN_CLICKED(IDC_BUTTON_ENCODE_OUT,&SettingDialog::OnBnClickedButtonEncodeOut)
END_MESSAGE_MAP()


// SettingDialog 消息处理程序

void SettingDialog::OnBnClickedButtonVideoEncode()
{
	CRect rc;
	GetClientRect( rc );

	CRect MOVE_rc;

	//视频编码
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = 5;
	MOVE_rc.bottom = Exhibition_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->MoveWindow(MOVE_rc,TRUE);
	int Button_Video_Encode_Bottom = MOVE_rc.bottom ;

	//编码输出
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->GetClientRect(MOVE_rc);
	int Exhibition3_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.bottom = rc.bottom - 5;
	MOVE_rc.top = MOVE_rc.bottom - Exhibition3_height;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->MoveWindow(MOVE_rc,TRUE);
	
	

	//音频编码
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition1_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.bottom = rc.bottom - 5 - Exhibition3_height - 5;
	MOVE_rc.top = MOVE_rc.bottom - Exhibition1_height ;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->MoveWindow(MOVE_rc,TRUE);
	int Exhibition3_top = MOVE_rc.top;	
	if ( m_RollingDialog  == NULL )
	{
		m_RollingDialog = new CRollingDialog(this);
		m_RollingDialog->Create(IDD_DIALOG4,this);
		m_RollingDialog->Init();

	}
	if ( m_RollingDialog  != NULL )
	{
		m_RollingDialog->iDisplayingSerialNumber = 0;
	}
	MOVE_rc.left = 10;
	MOVE_rc.top = Button_Video_Encode_Bottom + 10;
	MOVE_rc.bottom = Exhibition3_top - 10;
	MOVE_rc.right = rc.right - 10;
	m_RollingDialog->MoveWindow(&MOVE_rc);
	m_RollingDialog->AdjustSize();
	m_RollingDialog->ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
	m_selectCount = 0;

}

void SettingDialog::OnBnClickedButtonAdioEncode()
{
	CRect rc;
	GetClientRect( rc );

	CRect MOVE_rc;

	//视频编码
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = 5;
	MOVE_rc.bottom = Exhibition_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->MoveWindow(MOVE_rc,TRUE);

	//音频编码
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition1_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = Exhibition_height + 5  + 5;
	MOVE_rc.bottom = Exhibition1_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->MoveWindow(MOVE_rc,TRUE);
	int Button_Video_Encode_Bottom = MOVE_rc.bottom ;

	//编码输出
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->GetClientRect(MOVE_rc);
	int Exhibition2_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.bottom = rc.bottom - 5;
	MOVE_rc.top = MOVE_rc.bottom - Exhibition2_height;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->MoveWindow(MOVE_rc,TRUE);
	int Exhibition3_top = MOVE_rc.top;	


	if ( m_RollingDialog  == NULL )
	{
		m_RollingDialog = new CRollingDialog(this);
		m_RollingDialog->Create(IDD_DIALOG4,this);
		m_RollingDialog->Init();
	}
	if ( m_RollingDialog  != NULL )
	{
		m_RollingDialog->iDisplayingSerialNumber = 1;
	}
	MOVE_rc.left = 10;
	MOVE_rc.top = Button_Video_Encode_Bottom + 10;
	MOVE_rc.bottom = Exhibition3_top - 10;
	MOVE_rc.right = rc.right - 10;
	m_RollingDialog->MoveWindow(&MOVE_rc);
	m_RollingDialog->AdjustSize();
	m_RollingDialog->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码

	/*if ( m_videoDialog  != NULL )
	{
		m_videoDialog->ShowWindow(SW_HIDE);
	}*/
	m_selectCount = 1;


}

void SettingDialog::OnBnClickedButtonEncodeOut()
{
	CRect rc;
	GetClientRect( rc );

	CRect MOVE_rc;

	//视频编码
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = 5;
	MOVE_rc.bottom = Exhibition_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Video_ENCODE)->MoveWindow(MOVE_rc,TRUE);

	//音频编码
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->GetClientRect(MOVE_rc);
	int Exhibition1_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = Exhibition_height + 5  + 5;
	MOVE_rc.bottom = Exhibition1_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_Adio_ENCODE)->MoveWindow(MOVE_rc,TRUE);

	//编码输出
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->GetClientRect(MOVE_rc);
	int Exhibition2_height = MOVE_rc.Height();
	MOVE_rc.left = 10;
	MOVE_rc.top = Exhibition_height + 5  + 5 + Exhibition1_height + 5;
	MOVE_rc.bottom = Exhibition2_height + MOVE_rc.top;
	MOVE_rc.right = rc.right - 10;
	GetDlgItem(IDC_BUTTON_ENCODE_OUT)->MoveWindow(MOVE_rc,TRUE);
	int Button_Video_Encode_Bottom = MOVE_rc.bottom ;

	if ( m_RollingDialog  == NULL )
	{
		m_RollingDialog = new CRollingDialog(this);
		m_RollingDialog->Create(IDD_DIALOG4,this);
		m_RollingDialog->Init();

	}
	if ( m_RollingDialog  != NULL )
	{
		m_RollingDialog->iDisplayingSerialNumber = 2;
	}
	MOVE_rc.left = 10;
	MOVE_rc.top = Button_Video_Encode_Bottom + 10;
	MOVE_rc.bottom = rc.bottom - 10;
	MOVE_rc.right = rc.right - 10;
	m_RollingDialog->MoveWindow(&MOVE_rc);
	m_RollingDialog->AdjustSize();
	m_RollingDialog->ShowWindow(SW_SHOW);
	m_selectCount = 2;

}

void SettingDialog::OnSize( UINT nType, int cx, int cy )
{
	if(!GetDlgItem(IDC_BUTTON_Video_ENCODE)) return;
	switch( m_selectCount )
	{
	case 0:OnBnClickedButtonVideoEncode();break;
	case 1:OnBnClickedButtonAdioEncode();break;
	case 2:OnBnClickedButtonEncodeOut();break;
	}
	CDialog::OnSize(nType,cx,cy);
}

BOOL SettingDialog::SaveEncoderSetting(BOOL bPopMsg )
{
	BOOL Error = false;
	if ( m_RollingDialog != NULL )
	{	
		Error = m_RollingDialog->saveEncod(bPopMsg);
	}
	return Error;
}



