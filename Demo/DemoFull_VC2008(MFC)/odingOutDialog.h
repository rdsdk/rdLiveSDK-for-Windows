#pragma once
#include "afxwin.h"
#include "SpinBox.h"
#include "LiveDialog.h"
// CodingOutDialog 对话框

class CodingOutDialog : public CDialog
{
	DECLARE_DYNAMIC(CodingOutDialog)

public:
	CodingOutDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CodingOutDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };
	void Init();
	bool SvaePife(BOOL bPopMsg = FALSE );
	void OnAcceditDone( BOOL bSuccess, LPWSTR szErrStr  );
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CLiveDialog * m_LiveDialog;
	DECLARE_MESSAGE_MAP()
	CComPtr<MSXML2::IXMLDOMNode> Createnode( LPWSTR nodename );
	
public:
	bool CheckMovieSaveDir( BOOL bPopMsg = FALSE );//检查文件夹是否存在
	CButton m_FIle_Button;

	CButton m_Live_Network;
	//文件
	CButton m_FIle_B_Button;
	CButton m_FILE_V_Button;
	CEdit m_Edit_File;
	CSpinBox * m_spinBox;
	//CEdit m_Edit_suffix;
	CComboBox m_combo_format;
	//直播
	CButton m_Live_NetworkSpeed;
	CButton m_ADD_Live_Button;
	CButton m_Delete_Button;
	//虚拟摄像头输出
	CButton m_Virtual_Check;
	afx_msg void OnBnClickedCheckFile();
	afx_msg void OnBnClickedCheckLivenetwork();

	CEdit m_Edit_Title;
	afx_msg void OnBnClickedButtonFileB();
	afx_msg void OnBnClickedButtonFileV();
	afx_msg void OnBnClickedButtonAddLive();
	afx_msg void OnBnClickedButtonDelete();
	CStatic m_accredit_File;
	CStatic m_accredit_Rtmp;
	CStatic m_accredit_cloud;
};
