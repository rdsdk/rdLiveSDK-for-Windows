#ifndef CHIPITEMOPER_H
#define CHIPITEMOPER_H

#include <QWidget>
#include "ui_chipitemoper.h"

class ChipItemOper : public QWidget
{
	Q_OBJECT

public:
	ChipItemOper(QWidget *parent = 0);
	~ChipItemOper();

	void OnChipSelected( HCHIP hChip, const IPinInput_SStatusInfo& sChipStatus );
	void OnPosChanged();
	void OnRotateChanged();
	void OnStatusChanged( const IPinInput_SStatusInfo& sChipStatus );
	HCHIP GetHChip() { return m_hChip; }
private:
	Ui::ChipItemOper ui;
	HCHIP			m_hChip;
	QTimer*			m_pPlayTimer;
	QColor			m_coTextColor;
	BOOL			m_bTextChanging;
	void SetAspectRatioClip( int w, int h );
	QTime SecondToTime( double dSecond );
public slots:
	void on_widClipLR_areaChanged( double fMin, double fMax );
	void on_widClipTB_areaChanged( double fMin, double fMax );
	void on_widPlayProgress_areaChanged( double fMin, double fMax );
	void on_widPlayProgress_valueChanged( double fValue );
	void on_tiePlayStart_timeChanged ( const QTime & time );
	void on_tiePlayEnd_timeChanged ( const QTime & time );
	void on_widPlayVolume_valueChanged( double fValue );

	void on_butClip16_9_clicked();
	void on_butClip9_16_clicked();
	void on_butClip4_3_clicked();
	void on_butClip3_4_clicked();
	void on_butRestore_clicked();
	void on_hsRotateX_valueChanged( int value );
	void on_hsRotateY_valueChanged( int value );
	void on_hsRotateZ_valueChanged( int value );
	void on_dspRotateX_valueChanged ( double d );
	void on_dspRotateY_valueChanged ( double d );
	void on_dspRotateZ_valueChanged ( double d );

	void on_butPlay_clicked();
	void on_butPause_clicked();
	void on_butStop_clicked();
	void on_chkMute_clicked( bool checked );
	void on_butSetPlayRange_clicked();
	void on_butUsePlayRange_clicked();
	void on_chkLoopPlay_clicked( bool checked );

	void on_timPlayProgress_timeout();

	void on_hsHue_valueChanged( int value );
	void on_hsSaturation_valueChanged( int value );
	void on_hsLighteness_valueChanged( int value );
	void on_hsContrast_valueChanged( int value );
	void on_hsTransparency_valueChanged( int value );
	void on_chkFixedHue_clicked( bool checked );
	void on_texInput_textChanged();
	void on_fontComboBox_currentFontChanged ( const QFont & font );
	void on_butTexItalic_clicked( bool checked );
	void on_butTexBold_clicked( bool checked );
	void on_butTexSizeByWidth_clicked( bool checked );
	void on_dspScrollCharPerSecond_valueChanged ( double d );
	void on_butTexColor_clicked();
};

#endif // CHIPITEMOPER_H
