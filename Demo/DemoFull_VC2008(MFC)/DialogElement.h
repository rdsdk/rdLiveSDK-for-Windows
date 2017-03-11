#pragma once
#include "resource.h"
#include "afxwin.h"

// CDialogElement 对话框

class CDialogElement : public CDialog
{
	DECLARE_DYNAMIC(CDialogElement)

public:
	CDialogElement(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogElement();

	ULONG_PTR m_gdiplusToken;
	
// 对话框数据
	enum { IDD = IDD_ELEMENT };
	void Init();
	HCHIP m_HChip;
	IScreen_SCapParams		m_sScrCapParams;
	IPinInput_SStatusInfo	m_sChipStatus;
	IPinInput_EClass		m_eClassType;
	CString			m_szSource;
	BOOL  m_BisSelected;//是否选中
	int m_cy;//纵坐标
	CBrush	m_Bursh;
	CDialog * m_pant;//主界面
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	//BOOL LoadImageFromResource(CImage *pImage, UINT nResID,LPCTSTR lpTyp);
	DECLARE_MESSAGE_MAP()
public:
	void DrawImage(  UINT ImageID );
	void SetElementName();//设置元件名
	BOOL GetSelected();
	void SetSelected( BOOL bIsSelected );
	virtual BOOL PreTranslateMessage(MSG* pMsg);//win自定义消息处理
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);

protected:
	BOOL m_BIsShow;//true 为显， false 为隐藏
	BOOL m_BIsLockAspect;//true 为不锁定的比例
	BOOL m_BIsPosition;//true 为不锁定位置
	BOOL m_BIsSize;//true 为可以拖拽
	BOOL m_BIsAngle;//true 为可旋转
public:
	afx_msg void OnBnClickedCheckShowHide();//元件显隐
	afx_msg void OnBnClickedCheck5();//比例锁定
	afx_msg void OnBnClickedCheck6();//锁定图像位置
	afx_msg void OnBnClickedCheck7();//锁定鼠标拖拽
	afx_msg void OnBnClickedCheck8();//锁定旋转
	afx_msg void OnBnClickedButton1();//图像在正中
	afx_msg void OnBnClickedButton2();//图像平铺
	CStatic m_Image;
	CButton m_SH_Button;
	CButton m_WH_Btton;
	CButton m_POS_Button;
	CButton m_siz_Button;
	CButton m_rotating_Button;
};
