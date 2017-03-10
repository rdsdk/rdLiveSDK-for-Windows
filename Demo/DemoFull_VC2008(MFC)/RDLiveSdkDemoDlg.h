
// Demo_VC2008(MFC)Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "scenario.h"
#include "SettingDialog.h"
#include "afxwin.h"

// CDemoRdLiveDlg 对话框
class CDemoRdLiveDlg : public CDialog
{
// 构造
public:
	CDemoRdLiveDlg(CWnd* pParent = NULL);	// 标准构造函数
	//管理类为单实例类，通过 Instance() 取得实例
	static CDemoRdLiveDlg& Instance();

	enum { IDD = IDD_DEMO_VC2008MFC_DIALOG };
	//把界面上的设置更新到配置文件和SDK并保存
	BOOL SaveProfile();
	//加载场景配置文件
	BOOL LoadScenes();
	//保存场景配置文件
	BOOL SaveScenes();

	SettingDialog * m_settingDialog;//编码设置界面
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	virtual BOOL PreTranslateMessage(MSG* pMsg);//win自定义消息处理
	BOOL	m_bChipListChanging;	//标记，当前的元件列表的修改是程序自己调用的，而不是用户操作，因此不需要在事件响应中进行任何处理。
	BOOL GetIsLoading();//是否加载成功

	CMenu * CreaMenuAudioCapture( EAudioCaptureDev audioCapTureDev , INT menuId );//创建设备
	void SetAudioCaptureSetting();//设置音频
	void SaveAudioCaptureSetting();//保存音频
	void on_EncoderNotifyCB( IEncoder_ENotify eNotify, ULONG dwValue, ULONG ptrValue );
// 实现
protected:
	CString GetattribValue( LPWSTR szattrib ,CComPtr<MSXML2::IXMLDOMNode>  pChildNode);
	void AppendMenuData( CMenu * pMenu, int NumberData, int Count, LPWSTR Name);
	bool m_bIsLoading;//是否加载成功
	HICON m_hIcon;
	int m_iNumberScenarios;//场景数量
	BOOL m_bAddSceneBut;//添加场景按钮
	BOOL m_bScrollBarSize;//滚动条
	BOOL m_bSceneName;//显示场景名称
	BOOL m_bCurLikeBScene;//后台显示当前场景
	FLOAT m_fEnterScale;//鼠标移入场景放大
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void UpdateVideoSizeLabel();//视频分辨率 帧率 的显示
private:
	
	void ClearStateMenu();//清除菜单状态
	void SetCurrentOptions( CMenu * pMenu, int width ,LPWSTR szList,int MAX, int MIN  );//设置菜单
	//  SerialNumber 0为分辨率  1为 帧率  2为比例
	CMenu * CreaoadMenu( LPWSTR szList,LPWSTR szattrib ,CString * szName, UINT UResolutionRatio , int SerialNumber);//创建对应的菜单
	void LoadMenuinformation();
	//音频设备
	//扬声器
	CMenu * m_MenuSpeaker;
	//MIC
	CMenu * m_MenuMIC;
	//分辨率
	CMenu * m_MenuFilm;//16:9
	CMenu * m_MenuTelevision;//4:3
	CMenu * m_MenuCIF;//CIF
	CMenu * m_MenuUser;//自定义
	CMenu * m_MenuFps;//帧率
	CMenu * m_MenuWH;//比例
	CMenu * m_MenuSwitch;//切换
	CMenu * m_MenuDletel;//删除场景
	CMenu * m_MenuRename;//重命名场景
	CMenu * m_MenuLayout;//预览布局
	CMenu * m_MenuLocation;//显示的位置
	//界面布局调整
	void SetAdjustLayout();
	//加载配置文件
	BOOL LoadProfile();
	
	//把配置文件的内容设置到界面和SDK
	BOOL SettingToUiAndSdk();

	BOOL m_bPreviewSizeing;
	IGlRender_SPreviewLayout m_sPerviewLayout;	//预览布局
	CMenu		m_menuMain;
	scenario *   m_scenario;//场景操作界面

	void DrawPreviewImage( INT iWidth, INT iHeight, LPBYTE pImageBuffer );//不适用OpenGL图像绘制
	CRect m_WIndrc;
public:
	
	static VOID WINAPI onPreviewImageCB( INT iWidth, INT iHeight, LPBYTE pImageBuffer, LPVOID pCbParam );//图像数据回调
	//界面配置
	void SetPreviewLayoutToMenu( BOOL bRestore = FALSE );
	CComPtr<MSXML2::IXMLDOMDocument> m_sScenes;//场景根目录
	CComPtr<MSXML2::IXMLDOMDocument> m_sOptionDoc;//option根目录
	BOOL OnCommand(WPARAM wParam, LPARAM lParam);//菜单项点击处理
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg  void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	void AddScene();
	void UpdatePreviewConfig( IGlRender_SPreviewLayout::EReposWnd eMode );
	static VOID WINAPI RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, INT iValue, LPVOID pCbParam );//场景回调
	static VOID WINAPI EncoderNotifyCB( IEncoder_ENotify eNotify, DWORD dwValue, DWORD_PTR ptrValue, LPVOID pCbParam );//编码回调

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tabctrl;
	afx_msg void onTcnSelchang(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnStnClickedStaticFps();
	afx_msg void OnClose( );
protected:
	CComPtr<MSXML2::IXMLDOMNode> Createnode( LPWSTR nodename );
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonMicequipment();
	CSliderCtrl m_Speaker_Slider;
	CSliderCtrl m_MIC_Slider;
	CButton m_Speaker_Button;
	CButton m_MIC_Button;
	CButton m_Button_LiveCease;
	CButton m_Button_LiveBegin;
	afx_msg void OnBnClickedButtonLivecease();//停止
	afx_msg void OnBnClickedButtonLivebegin();//开始
	afx_msg void OnBnClickedCheckAudioselect();//音频
	afx_msg void OnBnClickedCheck1Micselect();
	afx_msg void OnNMReleasedcaptureSliderAudioVolnm(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderMicVolnm(NMHDR *pNMHDR, LRESULT *pResult);
};
