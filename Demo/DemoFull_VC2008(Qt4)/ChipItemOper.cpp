#include "StdAfx.h"
#include "chipitemoper.h"

ChipItemOper::ChipItemOper(QWidget *parent)
	: QWidget(parent)
{
	m_hChip	= NULL;
	m_pPlayTimer	= new QTimer( this );
	m_pPlayTimer->setObjectName( "timPlayProgress" );
	ui.setupUi(this);
	CRangeSlider::SStyle	sSty	= ui.widClipLR->GetStyle();
	sSty.bHitValue	= false;
	sSty.bDrawValueBar	= false;
	sSty.iPrecision	= 0;
	ui.widClipLR->SetStyle( sSty );
	ui.widClipTB->SetStyle( sSty );

	sSty	= ui.widPlayProgress->GetStyle();
	sSty.eFormat	= CRangeSlider::eTextHMSAuto;
	sSty.bTextAlignBar	= true;
	sSty.sValueText.eAlign	= CRangeSlider::eAlignFar;
	sSty.sValueTextSub.eAlign	= CRangeSlider::eAlignFar;
	sSty.iPrecision	= 0;
	ui.widPlayProgress->SetStyle( sSty );
	ui.widPlayProgress->SetDispMode( CRangeSlider::eDispValue );

	sSty	= ui.widPlayVolume->GetStyle();
	//sSty.sMinText.eAlign	= CRangeSlider::eAlignNone;
	//sSty.sMaxText.eAlign	= CRangeSlider::eAlignNone;
	//sSty.sAreaText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sValueText.eAlign	= CRangeSlider::eAlignNone;
	sSty.sValueTextSub.eAlign	= CRangeSlider::eAlignNone;
	ui.widPlayVolume->SetStyle( sSty );
	ui.widPlayVolume->SetDispMode( CRangeSlider::eDispValue );

	m_bTextChanging	= FALSE;
}

ChipItemOper::~ChipItemOper()
{

}

void ChipItemOper::OnChipSelected( HCHIP hChip, const IPinInput_SStatusInfo& sChipStatus )
{
	m_hChip	= hChip;
	if ( hChip )
	{
		IPinInput_SCharacteristics	sChipCharact	= {0};
		Chip_GetCharacteristics( m_hChip, &sChipCharact );
		ui.widPlayProgress->SetDispMode( CRangeSlider::eDispValue );
		ui.stkPlayControl->setCurrentIndex( 0 );

		ui.chkFixedHue->setChecked( Chip_GetBaseShaderParam( m_hChip, eShader_UseFixedHue ) != 0.0f ? true : false );
		ui.hsHue->setValue( Chip_GetBaseShaderParam( m_hChip, eShader_Hue ) * ui.hsHue->maximum() );
		ui.hsSaturation->setValue( Chip_GetBaseShaderParam( m_hChip, eShader_Saturation ) * ui.hsSaturation->maximum() );
		ui.hsLighteness->setValue( Chip_GetBaseShaderParam( m_hChip, eShader_Lighteness ) * ui.hsLighteness->maximum() );
		ui.hsContrast->setValue( Chip_GetBaseShaderParam( m_hChip, eShader_Contrast ) * ui.hsContrast->maximum() );
		ui.hsTransparency->setValue( Chip_GetBaseShaderParam( m_hChip, eShader_Transparency ) * ui.hsTransparency->maximum() );

		switch( Chip_GetClassType( m_hChip ) )
		{
		case ePinInput_Unknow:
			break;
		case ePinInput_Picture:
			ui.stkChipPlayType->setCurrentIndex( 0 );
			ui.tabWidget->setTabEnabled( 0, sChipCharact.bExistMovie );
			break;
		case ePinInput_Camera:
		case ePinInput_Screen:
			ui.stkChipPlayType->setCurrentIndex( 0 );
			ui.tabWidget->setTabEnabled( 0, sChipCharact.bExistMovie );
			break;
		case ePinInput_Flash:
		case ePinInput_Movie:
			ui.stkChipPlayType->setCurrentIndex( 0 );
			ui.tabWidget->setTabEnabled( 0, sChipCharact.bExistMovie );
			break;
		case ePinInput_Game:
			ui.stkChipPlayType->setCurrentIndex( 0 );
			ui.tabWidget->setTabEnabled( 0, sChipCharact.bExistMovie );
			break;
		case ePinInput_Text:
			m_bTextChanging	= TRUE;
			ui.stkChipPlayType->setCurrentIndex( 1 );
			ui.tabWidget->setTabEnabled( 0, true );
			if ( LPCWSTR pSource = Chip_GetSourceName( m_hChip ) )
			{
				LPCWSTR	pText	= wcschr( pSource, ',' );
				if ( pText )
				{
					QStringList	szParams	= QString::fromUtf16( pSource, pText - pSource ).split( '|' );
					if ( szParams.count() > 0 )
					{
						int	iSel	= ui.fontComboBox->findText( szParams[0] );
						if ( iSel >= 0 ) ui.fontComboBox->setCurrentIndex( iSel );
					}
					if ( szParams.count() > 1 )
					{
						ui.butTexItalic->setChecked( szParams[1].indexOf( 'I' ) >= 0 );
						ui.butTexBold->setChecked( szParams[1].indexOf( 'B' ) >= 0 );
						ui.butTexSizeByWidth->setChecked( szParams[1].indexOf( 'W' ) >= 0 );
					}
					if ( szParams.count() > 2 )
					{
						m_coTextColor.setRgb( szParams[2].toUInt() );
						QString	szStyle	= QString( "background-color: rgb(%1, %2, %3);" )
							.arg( m_coTextColor.red() ).arg( m_coTextColor.green() ).arg( m_coTextColor.blue() );
						ui.butTexColor->setStyleSheet( szStyle );
					}
					if ( szParams.count() > 3 )
					{
						ui.dspScrollCharPerSecond->setValue( szParams[3].toFloat() );
					}
					ui.texInput->setText( QFU( pText + 1 ) );
				}
			}
			m_bTextChanging	= FALSE;
			break;
		}

		OnStatusChanged( sChipStatus );
		OnPosChanged();
		OnRotateChanged();
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
	ui.widClipLR->SetArea( fLeft * iWidth, iWidth - fRight * iWidth );
	ui.widClipTB->SetRange( 0.0, iHeight );
	ui.widClipTB->SetArea( fTop * iHeight, iHeight - fBottom * iHeight );
}

void ChipItemOper::OnRotateChanged()
{
	FLOAT	fX, fY, fZ;
	Chip_GetRotate( m_hChip, &fX, &fY, &fZ );
	ui.dspRotateX->setValue( fX );
	ui.dspRotateY->setValue( fY );
	ui.dspRotateZ->setValue( fZ );
}

void ChipItemOper::OnStatusChanged( const IPinInput_SStatusInfo& sChipStatus )
{
	struct	SControlEnabled
	{
		bool	bPlayProgress;
		bool	bPlayVolume;
		bool	bButPlay;
		bool	bButPause;
		bool	bButStop;
		bool	bChkMute;
	}enableList	= {0};

	IPinInput_SCharacteristics	sChipCharact	= {0};
	Chip_GetCharacteristics( m_hChip, &sChipCharact );
	if ( sChipStatus.eStatus >= ePin_Closed && sChipStatus.eStatus < ePin_Closing )
	{
		if ( ui.stkPlayControl->currentIndex() == 0 )
		{
			//设置播放进度的时间
			ui.widPlayProgress->SetRange( 0.0f, sChipStatus.fSecondCount );
			if ( sChipStatus.bIsRange )
			{
				ui.widPlayProgress->SetArea( sChipStatus.fSecondStart, sChipStatus.fSecondEnd );
				ui.labPalyRange->setText( QFU(L"选区") );
			}
			else
			{
				ui.widPlayProgress->SetArea( 0.0f, sChipStatus.fSecondCount );
				ui.labPalyRange->setText( QFU(L"全部") );
			}
		}
		ui.chkLoopPlay->setChecked( sChipStatus.bIsLoop );
		ui.chkMute->setChecked( sChipStatus.bIsMute );
		ui.widPlayVolume->SetValue( sChipStatus.fVolume );
	}
	if ( sChipStatus.eStatus == ePin_Played )
	{
		m_pPlayTimer->setSingleShot( false );
		m_pPlayTimer->setInterval( 20 );
		m_pPlayTimer->start();
	}
	else
	{
		m_pPlayTimer->stop();
	}
	switch( sChipStatus.eStatus )
	{
	case ePin_None:		//没有设置源
		break;
	case ePin_Error:		//源错误
	case ePin_Closed:	//已经关闭
		enableList.bButPlay	= true;
		break;
	case ePin_Opened:	//源打开完成
		enableList.bButPlay			= sChipCharact.bTunableStop || sChipCharact.bTunablePause;
		enableList.bPlayProgress	= sChipCharact.bTunableSeek;
		enableList.bPlayVolume		= sChipCharact.bTunableVolume;
		enableList.bChkMute			= sChipCharact.bTunableMute;
		break;
	case ePin_Stoped:	//源已经停止
		enableList.bButPlay			= sChipCharact.bTunableStop || sChipCharact.bTunablePause;
		break;
	case ePin_Paused:	//已经暂停
		enableList.bButPlay			= sChipCharact.bTunableStop || sChipCharact.bTunablePause;
		enableList.bButStop			= sChipCharact.bTunableStop;
		enableList.bPlayProgress	= sChipCharact.bTunableSeek;
		enableList.bPlayVolume		= sChipCharact.bTunableVolume;
		enableList.bChkMute			= sChipCharact.bTunableMute;
		break;
	case ePin_Played:	//正在播放
		enableList.bButPause		= sChipCharact.bTunablePause;
		enableList.bButStop			= sChipCharact.bTunableStop;
		enableList.bPlayProgress	= sChipCharact.bTunableSeek;
		enableList.bPlayVolume		= sChipCharact.bTunableVolume;
		enableList.bChkMute			= sChipCharact.bTunableMute;
		break;

	case ePin_Closing:	//正在关闭
		break;
	case ePin_Opening:	//正在打开
		break;
	case ePin_Stoping:	//正在停止
		break;
	case ePin_Pausing:	//正在暂停
		break;
	case ePin_Loading:	//正在载入
		return;
		break;
	}
	ui.widPlayProgress->setEnabled( enableList.bPlayProgress );
	ui.widPlayVolume->setEnabled( enableList.bPlayVolume );
	ui.butPlay->setEnabled( enableList.bButPlay );
	ui.butPause->setEnabled( enableList.bButPause );
	ui.butStop->setEnabled( enableList.bButStop );
	ui.chkMute->setEnabled( enableList.bChkMute );
	ui.labPalyRangeTit->setEnabled( enableList.bPlayProgress );
	ui.labPalyRange->setEnabled( enableList.bPlayProgress );
	ui.butSetPlayRange->setEnabled( enableList.bPlayProgress );
	ui.chkLoopPlay->setEnabled( sChipStatus.iFrameCount > 0 );
}

void ChipItemOper::on_widClipLR_areaChanged( double fMin, double fMax )
{
	SetAspectRatioClip( 0, 0 );
}

void ChipItemOper::on_widClipTB_areaChanged( double fMin, double fMax )
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
		ui.widClipLR->SetArea( ( iWidth - siChip.width() ) * 0.5, iWidth - ( iWidth - siChip.width() ) * 0.5 );
		ui.widClipTB->SetRange( 0.0, iHeight );
		ui.widClipTB->SetArea( ( iHeight - siChip.height() ) * 0.5, iHeight - ( iHeight - siChip.height() ) * 0.5 );
	}
	Chip_SetClipPercent( m_hChip, 
		ui.widClipLR->GetAreaMin() / iWidth,
		ui.widClipTB->GetAreaMin() / iHeight, 
		( iWidth - ui.widClipLR->GetAreaMax() ) / iWidth,
		( iHeight - ui.widClipTB->GetAreaMax() ) /iHeight ); 
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

void ChipItemOper::on_hsRotateX_valueChanged( int value )
{
	if ( int( ui.dspRotateX->value() ) != value )
	{
		ui.dspRotateX->setValue( value );
	}
}

void ChipItemOper::on_hsRotateY_valueChanged( int value )
{
	if ( int( ui.dspRotateY->value() ) != value )
	{
		ui.dspRotateY->setValue( value );
	}
}

void ChipItemOper::on_hsRotateZ_valueChanged( int value )
{
	if ( int( ui.dspRotateZ->value() ) != value )
	{
		ui.dspRotateZ->setValue( value );
	}
}

void ChipItemOper::on_dspRotateX_valueChanged ( double d )
{
	ui.hsRotateX->setValue( int( d ) );
	Chip_SetRotate( m_hChip, ui.dspRotateX->value(), ui.dspRotateY->value(), ui.dspRotateZ->value() );
}

void ChipItemOper::on_dspRotateY_valueChanged ( double d )
{
	ui.hsRotateY->setValue( int( d ) );
	Chip_SetRotate( m_hChip, ui.dspRotateX->value(), ui.dspRotateY->value(), ui.dspRotateZ->value() );
}

void ChipItemOper::on_dspRotateZ_valueChanged ( double d )
{
	ui.hsRotateZ->setValue( int( d ) );
	Chip_SetRotate( m_hChip, ui.dspRotateX->value(), ui.dspRotateY->value(), ui.dspRotateZ->value() );
}

void ChipItemOper::on_butPlay_clicked()
{
	Chip_Play( m_hChip );
}

void ChipItemOper::on_butPause_clicked()
{
	Chip_Pause( m_hChip );
}

void ChipItemOper::on_butStop_clicked()
{
	Chip_Stop( m_hChip );
}

void ChipItemOper::on_chkMute_clicked( bool checked )
{
	Chip_SetMute( m_hChip, checked );
}

void ChipItemOper::on_butSetPlayRange_clicked()
{
	ui.widPlayProgress->SetDispMode( CRangeSlider::eDispArea );
	ui.stkPlayControl->setCurrentIndex( 1 );
	on_widPlayProgress_areaChanged( ui.widPlayProgress->GetAreaMin(), ui.widPlayProgress->GetAreaMax() );
}

void ChipItemOper::on_butUsePlayRange_clicked()
{
	//以毫秒为单位设置播放的时间范围。
	Chip_SetRange( m_hChip, INT64( ui.widPlayProgress->GetAreaMin() * 1000.0 ),
		INT64( ui.widPlayProgress->GetAreaMax() * 1000.0 ), FALSE );

	ui.widPlayProgress->SetDispMode( CRangeSlider::eDispValue );
	ui.stkPlayControl->setCurrentIndex( 0 );
	IPinInput_SStatusInfo sChipStatus;
	if ( Chip_GetStatusInfo( m_hChip, &sChipStatus ) )
	{
		if ( sChipStatus.bIsRange )
		{
			ui.labPalyRange->setText( QFU(L"选区") );
		}
		else
		{
			ui.labPalyRange->setText( QFU(L"全部") );
		}
	}
}

void ChipItemOper::on_timPlayProgress_timeout()
{
	IPinInput_SStatusInfo sChipStatus;
	if ( Chip_GetStatusInfo( m_hChip, &sChipStatus ) )
	{
		double	maxSec	= 0.0;
		ui.widPlayProgress->GetRange( NULL, &maxSec );
		if ( sChipStatus.fSecondPlay > maxSec )
		{
			ui.widPlayProgress->SetRange( 0, sChipStatus.fSecondPlay );
			ui.widPlayProgress->SetArea( 0, sChipStatus.fSecondPlay );
		}
		ui.widPlayProgress->SetValue( sChipStatus.fSecondPlay );
	}
}


void ChipItemOper::on_chkLoopPlay_clicked( bool checked )
{
	Chip_SetLoop( m_hChip, checked );
}

QTime ChipItemOper::SecondToTime( double dSecond )
{
	int	iHour	= int( dSecond / 60.0 / 60.0 );
	dSecond	-= iHour * 60.0 * 60.0;
	int	iMinute	= int( dSecond / 60.0 );
	dSecond	-= iMinute * 60.0;
	int	iSecond	= int( dSecond );
	dSecond	-= iSecond;
	return QTime( iHour, iMinute, iSecond, int( dSecond * 1000.0 ) );
}

void ChipItemOper::on_widPlayProgress_areaChanged( double fMin, double fMax )
{
	QTime	timRangeMin	= SecondToTime( fMin );
	QTime	timRangeMax	= SecondToTime( fMax );
	ui.widPlayProgress->GetRange( &fMin, &fMax );
	QTime	timMin	= SecondToTime( fMin );
	QTime	timMax	= SecondToTime( fMax );

	ui.tiePlayStart->setTimeRange( timMin, timRangeMax );
	ui.tiePlayStart->setTime( timRangeMin );
	ui.tiePlayEnd->setTimeRange( timRangeMin, timMax );
	ui.tiePlayEnd->setTime( timRangeMax );
}

void ChipItemOper::on_tiePlayStart_timeChanged ( const QTime & time )
{
	double	fMSecond	= time.hour() * 60.0 * 60.0;
	fMSecond	+= time.minute() * 60.0;
	fMSecond	+= time.second();
	fMSecond	+= time.msec() / 1000.0;

	ui.widPlayProgress->SetArea( fMSecond, ui.widPlayProgress->GetAreaMax() );
}

void ChipItemOper::on_tiePlayEnd_timeChanged ( const QTime & time )
{
	double	fMSecond	= time.hour() * 60.0 * 60.0;
	fMSecond	+= time.minute() * 60.0;
	fMSecond	+= time.second();
	fMSecond	+= time.msec() / 1000.0;

	ui.widPlayProgress->SetArea( ui.widPlayProgress->GetAreaMin(), fMSecond );
}

void ChipItemOper::on_widPlayProgress_valueChanged( double fValue )
{
	//设置播放时间，单位是毫秒数。
	Chip_Seek( m_hChip, INT64( fValue * 1000 ), FALSE );
}

void ChipItemOper::on_widPlayVolume_valueChanged( double fValue )
{
	Chip_SetVolume( m_hChip, fValue );
}

void ChipItemOper::on_hsHue_valueChanged( int value )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_Hue, float( value ) / ui.hsHue->maximum() );
}
void ChipItemOper::on_hsSaturation_valueChanged( int value )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_Saturation, float( value ) / ui.hsSaturation->maximum() );
}
void ChipItemOper::on_hsLighteness_valueChanged( int value )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_Lighteness, float( value ) / ui.hsLighteness->maximum() );
}
void ChipItemOper::on_hsContrast_valueChanged( int value )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_Contrast, float( value ) / ui.hsContrast->maximum() );
}
void ChipItemOper::on_hsTransparency_valueChanged( int value )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_Transparency, float( value ) / ui.hsTransparency->maximum() );
}
void ChipItemOper::on_chkFixedHue_clicked( bool checked )
{
	Chip_SetBaseShaderParam( m_hChip, eShader_UseFixedHue, float( checked ) );
}
void ChipItemOper::on_texInput_textChanged()
{
	if ( m_bTextChanging ) return;
	QString	szFlag;
	if ( ui.butTexItalic->isChecked() )	szFlag.append( "I" );
	if ( ui.butTexBold->isChecked() )		szFlag.append( "B" );
	if ( ui.butTexSizeByWidth->isChecked() )	szFlag.append( "W" );

	QString	szText	= QString("%1|%2|%3|%4,%5").arg( ui.fontComboBox->currentText() )
		.arg( szFlag ).arg( m_coTextColor.rgb() ).arg( ui.dspScrollCharPerSecond->value(), 0, 'f', 1 )
		.arg( ui.texInput->toPlainText() );
	
	Chip_Open( m_hChip, (LPCWSTR)szText.utf16(), FALSE, TRUE );

}

void ChipItemOper::on_fontComboBox_currentFontChanged ( const QFont & font )
{
	on_texInput_textChanged();
}

void ChipItemOper::on_butTexItalic_clicked( bool checked )
{
	on_texInput_textChanged();
}

void ChipItemOper::on_butTexBold_clicked( bool checked )
{
	on_texInput_textChanged();
}

void ChipItemOper::on_butTexSizeByWidth_clicked( bool checked )
{
	on_texInput_textChanged();
}

void ChipItemOper::on_dspScrollCharPerSecond_valueChanged ( double d )
{
	on_texInput_textChanged();
}

void ChipItemOper::on_butTexColor_clicked()
{
	QColor	coSel	= QColorDialog::getColor( m_coTextColor, this, QFU(L"选择文字颜色") );
	if ( coSel.isValid() )
	{
		m_coTextColor	= coSel;
		QString	szStyle	= QString( "background-color: rgb(%1, %2, %3);" )
			.arg( m_coTextColor.red() ).arg( m_coTextColor.green() ).arg( m_coTextColor.blue() );
		ui.butTexColor->setStyleSheet( szStyle );
		on_texInput_textChanged();
	}
}