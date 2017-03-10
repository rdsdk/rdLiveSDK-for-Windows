#pragma once

#include "ArrayDialogElement.h"
// scenario 对话框

class scenario : public CDialog
{
	DECLARE_DYNAMIC(scenario)

public:
	scenario(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~scenario();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };
	BOOL OnRenderNotify( IRender_ENotify eNotify, WPARAM wParam, LPARAM lParam );//元件有变化
	CArrayDialogElement * m_ArrayDialogElement;//元件数组

	int m_iEdtPos;
	void MoveWindows( int ipos );
	int m_Height;//真实高度元件列表
	CMenu * m_AddButtonMenu;//添加场景菜单
	void AddChipMenu(CRect rc  ,CMenu * pMenu  , bool bIsmen);

	CMenu * m_MenuScreen;//屏幕/窗口 菜单
	int m_ScreenCount;//屏幕 数量
	int m_HWndCount;//窗口 数量
	CMenu * m_MenuCamera;//摄像头菜单
	int m_CameraCount;//摄像头 数量

	int m_iScreenCount;//窗口的数量
	int m_iCameraCount;//摄像头的数量

	CArray <HWND> * m_HWndList;//窗口句柄
	CString GetImageDir();//选择图片路径
protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
	
public:
	void adjustmentOnComponentsListLayout();//元件列表布局调整
	BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	int HWndCountW();

	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);//滑块的动作或者按钮
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);//滑轮的动作
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMoveUp();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonMoveDown();
};
