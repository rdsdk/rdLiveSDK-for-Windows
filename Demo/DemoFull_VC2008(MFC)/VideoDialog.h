#pragma once
#include "SpinBox.h"

// VideoDialog 对话框

class VideoDialog : public CDialog
{
	DECLARE_DYNAMIC(VideoDialog)

public:
	VideoDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~VideoDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_Video };
	afx_msg void OnSize(UINT nType, int cx, int cy);

	//bool m_bIsFist;//只运行第一次
	CSpinBox * AddSpinButton( int MaxNumber, int MinNumber, int top, UINT uID, int spinNumber  );//添加spinButton
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void SetQualityComboBox( int index );//设置质量参考的下拉列表
	DECLARE_MESSAGE_MAP()
public:
	void Init();//初始化
	void SaveProfile();//保存配置信息
	//码率处理
	int m_spinintBite;
	afx_msg void OnDeltaposBitrateSpinBite(NMHDR *pNMHDR, LRESULT *pResult);
	//视频编码器处理
	int m_iEncoderIndex;
	afx_msg void OnCbnSelendokEncoderComboxEncode();
	afx_msg void OnCbnDropdownEncoderComboxEncode();
	//码率模式
	afx_msg void OnCbnSelendokRateModelComboxRateModel();
	//视频质量
	afx_msg void OnCbnSelendokQuelityReferenceComboxQuality();

private:
	CSpinBox * m_BitRateSpinButton;//码率
	CSpinBox * m_MaximumSpinButton;//最大码率
	CSpinBox * m_VBVSpinButton;//VBV码率
	CSpinBox * m_IDRSpinButton;//IDR 间隔
	CSpinBox * m_I_Fps_SpinButton;//I 帧间隔
	CSpinBox * m_Ref_Quote_SpinButton;//Ref 引用
	CSpinBox * m_B_Fps_SpinButton;//B帧间隔
};
