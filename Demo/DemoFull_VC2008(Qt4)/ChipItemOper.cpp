#include "StdAfx.h"
#include "chipitemoper.h"

ChipItemOper::ChipItemOper(QWidget *parent)
	: QWidget(parent)
{
	m_hChip	= NULL;
	ui.setupUi(this);
	ui.widClipLR->SetText( CRangeSlider::eTex_Number | CRangeSlider::eTex_Middle | CRangeSlider::eTex_MidSlider, 0, 2 );
	ui.widClipTB->SetText( CRangeSlider::eTex_Number | CRangeSlider::eTex_Middle | CRangeSlider::eTex_MidSlider, 0, 2 );
}

ChipItemOper::~ChipItemOper()
{

}

void ChipItemOper::OnChipSelected( HCHIP hChip )
{
	m_hChip	= hChip;
	if ( hChip )
	{
		OnPosChanged();
	}
	setEnabled( hChip ? true : false );
}

void ChipItemOper::OnPosChanged()
{
	INT		iWidth,	iHeight;
	FLOAT	fLeft, fTop, fRight, fBottom;
	Chip_GetRect( m_hChip, NULL, NULL, &iWidth, &iHeight, TRUE );
	Chip_GetClipPercent( m_hChip, &fLeft, &fTop, &fRight, &fBottom ); 

	ui.widClipLR->SetRange( 0.0, iWidth );
	ui.widClipLR->SetSlider( fLeft * iWidth, iWidth - fRight * iWidth );
	ui.widClipTB->SetRange( 0.0, iHeight );
	ui.widClipTB->SetSlider( fTop * iHeight, iHeight - fBottom * iHeight );
}

void ChipItemOper::on_widClipLR_sliderRange( double fLeft, double fRight )
{
	SetAspectRatioClip( 0, 0 );
}

void ChipItemOper::on_widClipTB_sliderRange( double fLeft, double fRight )
{
	SetAspectRatioClip( 0, 0 );
}

void ChipItemOper::SetAspectRatioClip( int w, int h )
{
	INT		iWidth,	iHeight;
	Chip_GetRect( m_hChip, NULL, NULL, &iWidth, &iHeight, TRUE );
	if ( w > 0 && h > 0 )
	{
		QSize	siChip( w, h );
		siChip.scale( iWidth, iHeight, Qt::KeepAspectRatio );

		ui.widClipLR->SetRange( 0.0, iWidth );
		ui.widClipLR->SetSlider( ( iWidth - siChip.width() ) * 0.5, iWidth - ( iWidth - siChip.width() ) * 0.5 );
		ui.widClipTB->SetRange( 0.0, iHeight );
		ui.widClipTB->SetSlider( ( iHeight - siChip.height() ) * 0.5, iHeight - ( iHeight - siChip.height() ) * 0.5 );
	}
	Chip_SetClipPercent( m_hChip, 
		ui.widClipLR->GetSliderMin() / iWidth,
		ui.widClipTB->GetSliderMin() / iHeight, 
		( iWidth - ui.widClipLR->GetSliderMax() ) / iWidth,
		( iHeight - ui.widClipTB->GetSliderMax() ) /iHeight ); 
}

void ChipItemOper::on_butClip16_9_clicked()
{
	SetAspectRatioClip( 16, 9 );
}

void ChipItemOper::on_butClip9_16_clicked()
{
	SetAspectRatioClip( 9, 16 );
}

void ChipItemOper::on_butClip4_3_clicked()
{
	SetAspectRatioClip( 4, 3 );
}

void ChipItemOper::on_butClip3_4_clicked()
{
	SetAspectRatioClip( 3, 4 );
}

void ChipItemOper::on_butRestore_clicked()
{
	INT		iWidth,	iHeight;
	Chip_GetRect( m_hChip, NULL, NULL, &iWidth, &iHeight, TRUE );
	SetAspectRatioClip( iWidth, iHeight );
}
