#pragma once
#include "SpinBox.h"

// AudioCodingDialog 对话框

class AudioCodingDialog : public CDialog
{
	DECLARE_DYNAMIC(AudioCodingDialog)

public:
	AudioCodingDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AudioCodingDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };
	void Init();//初始化
	void SaveAuido();//音频编码保存
	CSpinBox * m_RateBitSpinButton;//音频码率
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnBnClickedRadiochannelstate();
	afx_msg void OnBnClickedRadiochannelsingle();
};
