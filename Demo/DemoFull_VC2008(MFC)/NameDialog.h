#pragma once


// CNameDialog 对话框

class CNameDialog : public CDialog
{
	DECLARE_DYNAMIC(CNameDialog)

public:
	CNameDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNameDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bIsConfirm;
	LPCWSTR m_szName;
	afx_msg void OnBnClickedOk();
};
