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

	VOID OnChipSelected( HCHIP hChip );
	VOID OnPosChanged();
	HCHIP GetHChip() { return m_hChip; }
private:
	Ui::ChipItemOper ui;
	HCHIP			m_hChip;
	VOID SetAspectRatioClip( int w, int h );
public slots:
	void on_widClipLR_sliderRange( double fLeft, double fRight );
	void on_widClipTB_sliderRange( double fLeft, double fRight );

	void on_butClip16_9_clicked();
	void on_butClip9_16_clicked();
	void on_butClip4_3_clicked();
	void on_butClip3_4_clicked();
	void on_butRestore_clicked();
};

#endif // CHIPITEMOPER_H
