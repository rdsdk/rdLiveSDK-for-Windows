#pragma once
#include "VideoDialog.h"
#include "odingOutDialog.h"
#include "AudioCodingDialog.h"
// CRollingDialog 对话框

class CRollingDialog : public CDialog
{
	DECLARE_DYNAMIC(CRollingDialog)

public:
	CRollingDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRollingDialog();
	int iDisplayingSerialNumber;//显示序号
	VideoDialog * m_VideoDialog;//视频编码设置
	int m_VideoDialog_width;//视频编码宽
	int m_VideoDialog_height;//视频编码高

	CodingOutDialog * m_codingOutDialog;//编码输出
	int m_codingOutDialog_width;//编码输出宽
	int m_codingOutDialog_height;//编码输出高

	AudioCodingDialog * m_AudioCOdingDialog;//音频编码
	int m_AudioCOdingDialog_width;//音频编码宽
	int m_AudioCOdingDialog_height;//音频编码高
	void AdjustSize();
// 对话框数据
	enum { IDD = IDD_DIALOG4 };
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_iEdtPos;
	void MoveWindows( int ipos );
	void Init();
	BOOL saveEncod( BOOL bPopMsg  = FALSE );//保存编码
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);//滑块的动作或者按钮
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);//滑轮的动作
	afx_msg void OnNMThemeChangedScrollBar(NMHDR *pNMHDR, LRESULT *pResult);
};
