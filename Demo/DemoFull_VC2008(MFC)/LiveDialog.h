#pragma once
#include "afxwin.h"
#include "LiveChooseDialog.h"
#include "ArrayLiveChooseDialog.h"
// CLiveDialog 对话框

class CLiveDialog : public CDialog
{
	DECLARE_DYNAMIC(CLiveDialog)

public:
	CLiveDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLiveDialog();

	ArrayLiveChooseDialog * m_ArrayDialogElement;
// 对话框数据
	int m_Height;
	enum { IDD = IDD_DIALOG4 };
	int m_iEdtPos;
	void AddLiveChooseDialog( CString StrDisName , bool Checke = FALSE );
	void adjustmentOnComponentsListLayout( );
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void MoveWindows( int ipos );
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);//滑块的动作或者按钮
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);//滑轮的动作
	CScrollBar m_ScrollBar_Bar;
};
