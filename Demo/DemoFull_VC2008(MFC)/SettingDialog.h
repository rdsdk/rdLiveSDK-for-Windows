#pragma once
#include "RollingDialog.h"

// SettingDialog 对话框

class SettingDialog : public CDialog
{
	DECLARE_DYNAMIC(SettingDialog)

public:
	SettingDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SettingDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_SETUP };
	int m_selectCount;//选择显示的设置
	CRollingDialog * m_RollingDialog;//滚动框
	//VideoDialog * m_videoDialog;//视频编码
	BOOL SaveEncoderSetting(BOOL bPopMsg = FALSE );//音频、视频、输出的编码设置
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonVideoEncode();
	afx_msg void OnBnClickedButtonAdioEncode();
	afx_msg void OnBnClickedButtonEncodeOut();
};
