#pragma once
#include "resource.h"
#include "afxwin.h"


// CLiveChooseDialog 对话框

class CLiveChooseDialog : public CDialog
{
	DECLARE_DYNAMIC(CLiveChooseDialog)

public:
	CLiveChooseDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLiveChooseDialog();
	CBrush	m_Bursh;
	int m_cy;//纵坐标
	BOOL  m_BisSelected;//是否选中
	// 对话框数据
	enum { IDD = IDD_DIALOG_Live };
	CString m_StrDisName;
	void Init( CString StrDisName , bool Checke = FALSE );
	CDialog * m_pant;//主界面
	void SetSelected( BOOL bIsSelected );
	BOOL  GetSelected();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);//win自定义消息处理
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);
	CStatic m_Stat_Live_Text;
	CButton m_Check_Live_Choose;
};
