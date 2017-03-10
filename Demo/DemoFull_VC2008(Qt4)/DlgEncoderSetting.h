#ifndef DLGENCODERSETTING_H
#define DLGENCODERSETTING_H

#include <QWidget>
#include "ui_dlgencodersetting.h"

class DlgEncoderSetting : public QWidget
{
	Q_OBJECT

public:
	DlgEncoderSetting(QWidget *parent = 0);
	~DlgEncoderSetting();

	void SetDocOption( QDomDocument* pDoc );
	QDomElement FindXmlElement( const QString& szPath, BOOL bCreateIfNull = FALSE );

	void SetEncoderSetting();
	bool UpdateEncoderConfig( BOOL bPopMsg = FALSE );	//把界面上对编码器的设置更新到SDK和XML配置对象
	QString CombinationFilePath( const QString& szDir, const QString& szPrefix, const QString& szExtension );
	bool CheckMovieSaveDir( BOOL bPopMsg = FALSE );
	void OnAcceditDone( BOOL bSuccess, const QString& szErrStr );
private:
	Ui::DlgEncoderSetting ui;
	QDomDocument*	m_pDocOption;

public slots:
	//编码设置
	void on_combVideoEncoder_currentIndexChanged ( int index );
	void on_combVideoPerset_currentIndexChanged ( int index );
	void on_spinVideoBitrate_valueChanged ( int i );
	void on_spinVBVBitrateMax_valueChanged ( int i );
	void on_combVideoVBVMode_currentIndexChanged ( int index );

	void on_butBrowVideoDir_clicked();
	void on_butViewVideoDir_clicked();

	void on_butAddLiveUrl_clicked();
	void on_butDelLiveUrl_clicked();

};

#endif // DLGENCODERSETTING_H
