#ifndef RDLIVESDKDEMO_H
#define RDLIVESDKDEMO_H

#include <QtGui/QMainWindow>
#include "ui_rdlivesdkdemo.h"

class RDLiveSdkDemo : public QMainWindow
{
	Q_OBJECT

public:
	RDLiveSdkDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~RDLiveSdkDemo();

private:
	Ui::RDLiveSdkDemoClass ui;

	QDomDocument	m_docOption;
	QLabel*			m_pLabVideoSize;
	QLabel*			m_pLabFScale;
	QLabel*			m_pLabTimeFps;
	BOOL			m_bPreviewSizeing;		//标记，当前的窗口缩放是程序自己调用的，而不是用户操作，因此不需要在事件响应中进行任何处理。
	QTimer*			m_timReszie;
	BOOL			m_bChipListChanging;	//标记，当前的元件列表的修改是程序自己调用的，而不是用户操作，因此不需要在事件响应中进行任何处理。
	BOOL			m_bSceneActionSingle;	//场景切换的动画效果只能单选

	//加载配置文件
	BOOL LoadProfile();
	//把界面上的设置更新到配置文件和SDK并保存
	BOOL SaveProfile();
	//把配置文件的内容设置到界面和SDK
	BOOL SettingToUiAndSdk();

	//截入场景配置文件
	BOOL LoadScenes();
	BOOL SaveScenes();

	QDomElement FindXmlElement( const QString& szPath, BOOL bCreateIfNull = FALSE );

	void UpdateVideoSizeLabel();
	static void WINAPI RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, INT iValue, LPVOID pCbParam );
	static void WINAPI EncoderNotifyCB( IEncoder_ENotify eNotify, DWORD dwValue, DWORD_PTR ptrValue, LPVOID pCbParam );
	void SetChipListButStatus();

	void	resizeEvent( QResizeEvent * event );
	void	closeEvent( QCloseEvent * event );

	IGlRender_SPreviewLayout m_sPerviewLayout;	//预览布局
	QActionGroup*	m_agpSwictScene;	//菜单单选：场景切换菜单项
	QActionGroup*	m_agpBSceneCount;	//菜单单选：后台场景显示数量
	QActionGroup*	m_agpBScenePos;		//菜单单选：后台场景显示在当前的场景的上下左右哪个位置
	//把配置文件中的设置更新到界面和 SDK
	void SetImageSettingToMenu();
	void SetPreviewLayoutToMenu( BOOL bRestore = FALSE );
	void SetAudioCaptureSetting();
	//把对预览的界面设置，更新到 SDK 以及 XML 对象，然后根据返回值重设窗口
	void UpdatePreviewConfig( IGlRender_SPreviewLayout::EReposWnd eMode );
	//
signals:
	void	signalRenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, int iValue );
	void	signalEncoderNotifyCB( IEncoder_ENotify eNotify, ulong dwValue, ulong ptrValue );
public slots:
	void on_timReszie_timeout();
	void on_RenderNotifyCB( IRender_ENotify eNotify, HSCENE hScene, int iValue );
	void on_EncoderNotifyCB( IEncoder_ENotify eNotify, ulong dwValue, ulong ptrValue );
	//开始
	void on_chkStart_toggled ( bool checked );
	//元件操作
	void on_butAddChip_clicked();
	void on_butCloseChip_clicked();
	void on_butUpChip_clicked();
	void on_butDownChip_clicked();
	void on_listWidChips_currentItemChanged ( QListWidgetItem * current, QListWidgetItem * previous );

	//录音控制
	void on_butAudioPopSpk_clicked();
	void on_butAudioPopMic_clicked();
	void on_chkSpeaker_clicked( bool checked );
	void on_chkMicrophone_clicked( bool checked );
	void on_widVolumeSpk_sliderRange( double fLeft, double fRight );
	void on_widVolumeMic_sliderRange( double fLeft, double fRight );
	
	//图像菜单
	void on_agpImageSize_triggered ( QAction * action );
	void on_menuFpses_triggered ( QAction * action );
	void on_menuPreviewScale_triggered ( QAction * action );
	void on_actSwapVH_triggered( bool checked );
	void on_actPreviewOpenGL_triggered( bool checked );

	//场景布局菜单
	void on_menuScene_aboutToShow();
	void on_menuSwitchScene_triggered ( QAction * action );
	void on_menuDeleteScene_triggered ( QAction * action );
	void on_menuRenameScene_triggered ( QAction * action );
	void on_actAddScene_triggered( bool checked );
	void on_actClearCurScene_triggered( bool checked );
	void on_menuPreviewLayout_triggered( QAction * action );
	
	//场景内容菜单
	void on_menuAddScreen_aboutToShow();
	void on_menuAddCamera_aboutToShow();
	void on_menuAddGame_aboutToShow();
	void on_menuAddScreen_triggered ( QAction * action );
	void on_menuAddCamera_triggered ( QAction * action );
	void on_menuAddGame_triggered ( QAction * action );
	void on_actAddPicture_triggered( bool checked );
	void on_actAddMovie_triggered( bool checked );
	void on_actAddOnline_triggered( bool checked );
	void on_actAddText_triggered( bool checked );
	
	//
	void on_actGameRec_toggled( bool checked );
	void on_actCapCursor_toggled( bool checked );
	void on_actAutoAero_toggled( bool checked );


	void on_butCutTo_clicked();
};

#endif // RDLIVESDKDEMO_H
