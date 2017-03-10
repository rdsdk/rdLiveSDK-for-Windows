#pragma once
#include "afxwin.h"


// CRtmpDialog 对话框

class CRtmpDialog : public CDialog
{
	DECLARE_DYNAMIC(CRtmpDialog)

public:
	CRtmpDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRtmpDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };
	void setmodel( int index );
	struct	SLiveUrl
	{
		int		iType;
		CString	szDispName;
		CString	szUrlOrId;
		CString	szPw;
		bool	bAutoLogin;
	};
	bool m_bIsConfirm;
	SLiveUrl	m_sLiveUrl;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//RTMP
	CStatic m_Rtmp_static;
	CEdit m_Rtmp_edit;
	CStatic m_Rtmp_exampl_static;
	//UID
	CStatic m_UID_text;
	CEdit m_UID_Edit;
	CStatic m_UID_prompt;
	//用户
	CStatic m_UserName;
	CEdit m_UserName_Edit;
	CStatic m_PW_Static;
	CEdit m_PW_Edit;
	CButton m_Check_Login;
	//直播类型
	CComboBox m_ComboBox;
	afx_msg void OnCbnSelendokCombo1();
	afx_msg void OnBnClickedOk();
	
};
