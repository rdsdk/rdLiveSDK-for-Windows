#pragma once


// CSpinBox 对话框

class CSpinBox : public CDialog
{
	DECLARE_DYNAMIC(CSpinBox)

public:
	CSpinBox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSpinBox();

// 对话框数据
	enum { IDD = IDD_DIALOG_Spin_Text };
	int m_MaxSpinNumber;//最大值
	int m_MInSpinNumber;//最小值
	
	void SetCurrentNumber( int CurrentNumber );//设置当前数字
	void SetEndleWindows( int isEndele );//禁用设置
	int m_SPinNumber;//每次点击spin添加的数量
	int m_iRealDataNumber;//真实数据
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	int m_spinintBite;//
	DECLARE_MESSAGE_MAP()
public:
	void Init( int MaxNumber, int MinNumber ,int spinNumber = 0 );
	afx_msg void OnEnUpdateEditTextCount();
	afx_msg void OnDeltaposSpinCount(NMHDR *pNMHDR, LRESULT *pResult);
};
