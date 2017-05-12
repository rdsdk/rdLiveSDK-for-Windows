#include "StdAfx.h"
#include "chipitem.h"

ChipItemOper*	ChipItem::m_pItemOper	= NULL;
ChipItem::ChipItem( HCHIP hChip, QListWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_eClassType	= Chip_GetClassType( hChip );

	m_eClassType		= ePinInput_Unknow;
	m_listWidChips		= parent;
	m_hChip				= hChip;
	if ( NULL == m_pItemOper )
	{
		m_pItemOper	= new ChipItemOper( parent );
		m_pItemOper->hide();
	}
	m_lwItem			= new QListWidgetItem;

	INT		iIndex	= Chip_GetIndex( m_hChip, NULL );
	iIndex	= m_listWidChips->count() - iIndex;
	//界面上的元件列表显示顺序与实际顺序是相反的，也就是最后添加的显示在最前。
	//所以新添加的元件始终插入显示列表顶端的位置。
	m_siBase	= size();

	m_listWidChips->insertItem( iIndex, m_lwItem );
	m_listWidChips->setItemWidget( m_lwItem, this );
	m_lwItem->setSizeHint( m_siBase );


	if ( Sceen_GetCurChip( Render_GetCurScene() ) == m_hChip )
	{
		m_listWidChips->setCurrentRow( iIndex );
		OnChipSelected();
	}
	OnStatusChanged();
}

ChipItem::~ChipItem()
{
	m_hChip	= 0;
}

BOOL ChipItem::OnRenderNotify( QListWidget* pList, IRender_ENotify eNotify, HSCENE hScene, int iValue )
{
	ChipItem*	pChItem	= NULL;
	SHORT		shLVal	= (SHORT)( iValue & 0xFFFF );
	SHORT		shHVal	= (SHORT)( iValue >> 16 );
	//因为列表的显示顺序和实际顺序相反，所以要先计算出当前删除的项目在显示列表中的位置。
	INT		iViewLow	= pList->count() - shLVal - 1;
	INT		iViewHigh	= pList->count() - shHVal - 1;
	if ( shLVal < 0 || iViewLow >= pList->count() ) iViewLow = -1;
	if ( shHVal < 0 || iViewHigh >= pList->count() ) iViewHigh = -1;

	switch( eNotify )
	{
	case eNotify_ChipAdding:
		break;
	case eNotify_ChipAdded:
		new ChipItem( Scene_GetChip( hScene, shLVal ), pList );
		return TRUE;
	case eNotify_ChipDeleting:
		break;
	case eNotify_ChipDeleted:
		pChItem	= ChipItem::GetChipItem( pList, iViewLow );
		if ( pChItem && pChItem->m_hChip == m_pItemOper->GetHChip() )
		{
			pChItem->OnChipSelected( FALSE );
		}
		delete pList->takeItem( iViewLow );
		//删除 item 会引起列表的选中项改变，这里重设选中项。
		iViewLow = pList->currentRow();
		pChItem	= ChipItem::GetChipItem( pList, iViewLow );
		if ( pChItem ) Chip_SetCurent( pChItem->m_hChip );
		return TRUE;
	case eNotify_ChipPosing:
		break;
	case eNotify_ChipPosed:
		pChItem	= GetChipItem( pList, iViewLow );
		if ( pChItem && pChItem->m_hChip == m_pItemOper->GetHChip() ) m_pItemOper->OnPosChanged();
		break;
	case eNotify_ChipRotating:
		break;
	case eNotify_ChipRotated:
		break;
	case eNotify_ChipSwitched:
		pList->setCurrentRow( iViewLow );
		pChItem	= ChipItem::GetChipItem( pList, iViewHigh );
		if ( pChItem ) pChItem->OnChipSelected( FALSE );
		pChItem	= ChipItem::GetChipItem( pList, iViewLow );
		if ( pChItem ) pChItem->OnChipSelected( TRUE );
		return TRUE;
	case eNotify_ChipIndexChg:
		if ( iViewLow >= 0 && iViewHigh >= 0 )
		{
			ChipItem::MoveChipItem( pList, iViewLow, iViewHigh );
			return TRUE;
		}
		break;
	case eNotify_ChipStatus:
	case eNotify_ChipVisible:
	case eNotify_ChipViewLock:
		if ( iValue >= 0 )
		{
			pChItem	= ChipItem::GetChipItem( pList, iViewLow );
			if ( pChItem ) pChItem->OnStatusChanged();
		}
		break;
	case eNotify_ChipSourceSize:
		break;
	}

	return FALSE;
}

HCHIP ChipItem::GetChipHandle( QListWidget* pList, int iViewIndex )
{
	QListWidgetItem*	pItem	= pList->item( iViewIndex );
	if ( pItem )
	{
		ChipItem*	pChip	= (ChipItem*)pList->itemWidget( pItem );
		return pChip ? pChip->m_hChip : NULL;
	}
	return NULL;
}

ChipItem* ChipItem::GetChipItem( QListWidget* pList, int iViewIndex )
{
	QListWidgetItem*	pItem	= pList->item( iViewIndex );
	if ( pItem )
	{
		ChipItem*	pChip	= (ChipItem*)pList->itemWidget( pItem );
		return pChip;
	}
	return NULL;
}

BOOL ChipItem::MoveChipItem( QListWidget* pList, int iViewFrom, int iViewTo )
{
	QListWidgetItem*	pItem	= pList->item( iViewFrom );
	if ( pItem )
	{
		ChipItem*	pChip	= (ChipItem*)pList->itemWidget( pItem );
		if ( pChip )
		{
			HCHIP	hChip	= pChip->m_hChip;;
			delete pList->takeItem( iViewFrom );
			new ChipItem( hChip, pList );
			return TRUE;
		}
	}
	return FALSE;
}

void ChipItem::OnStatusChanged()
{
	IPinInput_SStatusInfo	sChipStatus;
	if ( !Chip_GetStatusInfo( m_hChip, &sChipStatus ) )
	{
		return;
	}
	DisplaySourceName();
	
	SetLabelIcon( sChipStatus );
	BOOL	bSeted	= FALSE;
	BOOL	bCurr	= ( this == (ChipItem*)m_listWidChips->itemWidget( m_listWidChips->currentItem() ) );

	if ( sChipStatus.eStatus >= ePin_Opened )
	{
		IPinInput_SCharacteristics	sCharact	= {0};
		if ( Chip_GetCharacteristics( m_hChip, &sCharact ) )
		{
			if ( sCharact.bExistImage || sCharact.bExistMovie )
			{
				ui.chkHideChip->setChecked( !Chip_IsVisible( m_hChip ) );
				ui.chkLockAspect->setChecked( Chip_GetViewLock( m_hChip, eLock_AspectRatio ) );
				ui.chkLockAspect->setChecked( Chip_GetViewLock( m_hChip, eLock_AspectRatio ) );
				ui.chkLockPos->setChecked( Chip_GetViewLock( m_hChip, eLock_Position ) );
				ui.chkLockSize->setChecked( Chip_GetViewLock( m_hChip, eLock_Size ) );
				ui.chkLockAngle->setChecked( Chip_GetViewLock( m_hChip, eLock_Angle ) );
				ui.widImgOper->setEnabled( true );
				if ( bCurr && m_pItemOper->isHidden() )
				{
					m_lwItem->setSizeHint( QSize( m_siBase.width(), m_siBase.height() + m_pItemOper->height() ) );
					m_pItemOper->OnChipSelected( m_hChip, sChipStatus );
					m_pItemOper->show();
				}
				bSeted	= TRUE;
			}
		}
	}
	if ( !bSeted )
	{
		ui.chkHideChip->setChecked( true );
		ui.chkLockAspect->setChecked( false );
		ui.chkLockPos->setChecked( false );
		ui.chkLockSize->setChecked( false );
		ui.chkLockAngle->setChecked( false );
		ui.widImgOper->setEnabled( false );
		if ( bCurr )
		{
			m_pItemOper->hide();
			m_lwItem->setSizeHint( m_siBase );
		}
	}
	if ( bCurr )
	{
		m_pItemOper->OnStatusChanged( sChipStatus );
	}
}

void ChipItem::OnChipSelected( BOOL bSelect )
{
	if ( bSelect )
	{
		IPinInput_SStatusInfo	sChipStatus;
		if ( !Chip_GetStatusInfo( m_hChip, &sChipStatus ) )
		{
			return;
		}
		ui.verticalLayout->addWidget( m_pItemOper );
		if ( Chip_GetStatus( m_hChip ) >= ePin_Opened )
		{
			int		iHeight	= m_pItemOper->minimumHeight();
			m_lwItem->setSizeHint( QSize( m_siBase.width(), m_siBase.height() + iHeight ) );
			m_pItemOper->OnChipSelected( m_hChip, sChipStatus );
			m_pItemOper->show();
		}
		else
		{
			m_pItemOper->hide();
			m_lwItem->setSizeHint( m_siBase );
		}
	}
	else
	{
		m_pItemOper->hide();
		m_pItemOper->setParent( m_listWidChips );
		ui.verticalLayout->removeWidget( m_pItemOper );
		m_lwItem->setSizeHint( m_siBase );
	}
}

void ChipItem::OnPosChanged()
{
}

void ChipItem::DisplaySourceName()
{
	m_eClassType	= Chip_GetClassType( m_hChip );
	QString	szName	= QFU( Chip_GetFriendlyName( m_hChip ) );
	QFontMetrics	fm( ui.labSourceName->font() );

	if ( m_eClassType == ePinInput_Picture 
		|| m_eClassType == ePinInput_Flash
		|| m_eClassType == ePinInput_Movie )
	{
		szName	= fm.elidedText( szName, Qt::ElideLeft, ui.labSourceName->width() );
	}
	else if ( m_eClassType == ePinInput_Camera )
	{
		szName	= fm.elidedText( szName, Qt::ElideRight, ui.labSourceName->width() );
	}
	else if ( m_eClassType == ePinInput_Screen )
	{
	}
	else if ( m_eClassType == ePinInput_Game )
	{
	}

	ui.labSourceName->setText( szName );
}

void ChipItem::SetLabelIcon( IPinInput_SStatusInfo& sChipStatus )
{
	static QImage	imgNone( ":/Resources/ItemToolbar/inpNone32.png" );
	static QImage	imgPicture( ":/Resources/ItemToolbar/inpPicture32.png" );
	static QImage	imgCamera( ":/Resources/ItemToolbar/inpCamera32.png" );
	static QImage	imgSceeen( ":/Resources/ItemToolbar/inpDesktop32.png" );
	static QImage	imgWindow( ":/Resources/ItemToolbar/inpWindow32.png" );
	static QImage	imgMovie( ":/Resources/ItemToolbar/inpMovie32.png" );
	static QImage	imgGame( ":/Resources/ItemToolbar/inpGame32.png" );
	static QImage	imgText( ":/Resources/ItemToolbar/inpText32.png" );

	static QImage	imgStaError( ":/Resources/ItemToolbar/inpStatusError.png" );
	static QImage	imgStaStoped( ":/Resources/ItemToolbar/inpStatusStoped.png" );
	static QImage	imgStaPaused( ":/Resources/ItemToolbar/inpStatusPaused.png" );
	static QImage	imgStaPlayed( ":/Resources/ItemToolbar/inpStatusPlayed.png" );
	static QImage	imgStaClosing( ":/Resources/ItemToolbar/inpStatusClosing.png" );
	static QImage	imgStaOpening( ":/Resources/ItemToolbar/inpStatusOpening.png" );
	static QImage	imgStaStoping( ":/Resources/ItemToolbar/inpStatusStoping.png" );
	static QImage	imgStaPausing( ":/Resources/ItemToolbar/inpStatusPausing.png" );
	static QImage	imgStaLoading( ":/Resources/ItemToolbar/inpStatusLoading.png" );

	QImage	imgIcon;
	switch( m_eClassType )
	{
	case ePinInput_Unknow:
		imgIcon	= imgNone;
		break;
	case ePinInput_Picture:
		imgIcon	= imgPicture;
		break;
	case ePinInput_Camera:
		imgIcon	= imgCamera;
		break;
	case ePinInput_Screen:
		{
			IScreen_SCapParams	sParams	= {0};
			Screen_AnalysisSource( Chip_GetSourceName( m_hChip ), &sParams );
			if ( sParams.szWindow[0] || sParams.hWindow )
			{
				imgIcon	= imgWindow;
			}
			else
			{
				imgIcon	= imgSceeen;
			}
		}
		break;
	case ePinInput_Flash:
	case ePinInput_Movie:
		imgIcon	= imgMovie;
		break;
	case ePinInput_Game:
		imgIcon	= imgGame;
		break;
	case ePinInput_Text:
		imgIcon	= imgText;
		break;
	}
	
	QPainter	pnt( &imgIcon );

	switch( sChipStatus.eStatus )
	{
	case ePin_None:		//没有设置源
		break;
	case ePin_Error:		//源错误
		pnt.drawImage( 16, 16, imgStaError );
		break;
	case ePin_Closed:		//已经关闭
	case ePin_Closing:	//正在关闭
		for ( int y = 0; y < imgIcon.height(); ++y )
		{
			LPBYTE	pPix	= imgIcon.scanLine( y );
			for ( int x = 0; x < imgIcon.width(); ++x )
			{
				BYTE	c = ( pPix[0] + pPix[1] + pPix[2] ) / 3;
				pPix[0]	= c;
				pPix[1]	= c;
				pPix[2]	= c;
				pPix	+= 4;
			}
		}
		if ( sChipStatus.eStatus == ePin_Closing ) pnt.drawImage( 16, 16, imgStaClosing );
		break;
	case ePin_Opened:		//源打开完成
		break;
	case ePin_Stoped:		//源已经停止
		pnt.drawImage( 16, 16, imgStaStoped );
		break;
	case ePin_Paused:		//已经暂停
		pnt.drawImage( 16, 16, imgStaPaused );
		break;
	case ePin_Played:		//正在播放
		pnt.drawImage( 16, 16, imgStaPlayed );
		break;
	case ePin_Opening:	//正在打开
		pnt.drawImage( 16, 16, imgStaOpening );
		break;
	case ePin_Stoping:	//正在停止
		pnt.drawImage( 16, 16, imgStaStoping );
		break;
	case ePin_Pausing:	//正在暂停
		pnt.drawImage( 16, 16, imgStaPausing );
		break;
	case ePin_Loading:	//正在载入
		pnt.drawImage( 16, 16, imgStaLoading );
		break;
	}
	ui.labChipIcon->setPixmap( QPixmap::fromImage( imgIcon ) );
}

void ChipItem::on_chkHideChip_clicked( bool checked )
{
	Chip_SetVisible( m_hChip, checked ? FALSE : TRUE );
}

void ChipItem::on_chkLockAspect_clicked( bool checked )
{
	Chip_SetViewLock( m_hChip, eLock_AspectRatio, checked ? TRUE : FALSE );
}
void ChipItem::on_chkLockPos_clicked( bool checked )
{
	Chip_SetViewLock( m_hChip, eLock_Position, checked ? TRUE : FALSE );
}
void ChipItem::on_chkLockSize_clicked( bool checked )
{
	Chip_SetViewLock( m_hChip, eLock_Size, checked ? TRUE : FALSE );
}
void ChipItem::on_chkLockAngle_clicked( bool checked )
{
	Chip_SetViewLock( m_hChip, eLock_Angle, checked ? TRUE : FALSE );
}

void ChipItem::on_butMiddle_clicked( bool checked )
{
	FLOAT fWidth, fHeight;
	Chip_GetRectPercent( m_hChip, NULL, NULL, &fWidth, &fHeight, FALSE );
	IChip_EBorderFitMode	eFitMode	= Chip_GetViewLock( m_hChip, eLock_AspectRatio ) ? eKeepAspectRatio : eIgnoreAspectRatio;
	Chip_SetRectPercent( m_hChip, ( 1.0f - fWidth ) * 0.5f, ( 1.0f - fHeight ) * 0.5f, fWidth, fHeight, eFitMode );
}

void ChipItem::on_butScaleFull_clicked( bool checked )
{
	IChip_EBorderFitMode	eFitMode	= eIgnoreAspectRatio;
	FLOAT fX, fY, fWidth, fHeight;
	Chip_GetRectPercent( m_hChip, &fX, &fY, &fWidth, &fHeight, FALSE );
	if ( Chip_GetViewLock( m_hChip, eLock_AspectRatio ) )
	{
		if ( ( fX == 0.0f && fWidth == 1.0f && fY >= 0.0f && fHeight <= 1.0f ) ||
			( fX >= 0.0f && fWidth <= 1.0f && fY == 0.0f && fHeight == 1.0f ) )
		{
			eFitMode	= eKeepAspectRatioByExpanding;
		}
		else
		{
			eFitMode	= eKeepAspectRatio;
		}
	}
	Chip_SetRectPercent( m_hChip, 0.0f, 0.0f, 1.0f, 1.0f, eFitMode );
}

