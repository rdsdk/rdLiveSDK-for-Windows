#include "StdAfx.h"
#include "CRangeSlider.h"

CRangeSlider::CRangeSlider(QWidget *parent)
	: QWidget(parent)
{
	m_fMax		= 1.0;
	m_fMin		= 0.0;
	m_fSliderMin		= 0.0;
	m_fSliderMax	= 1.0;
	m_fPos		= 0.0;
	m_bEnablePos	= FALSE;
	m_coFrame.setRgb( 96,96,96 );
	m_coBack.setRgb( 160,160,160 );
	m_coSlider.setRgb( 0,36,200 );
	m_coLine.setRgb( 0,0,0 );
	m_coProgress.setRgb( 0,200,32 );

	m_iLeft		= 0;
	m_iRight	= 0;
	m_iPos		= 0;
	m_dwHitMask	= 0xFFFFFFFF;

	m_eHit		= eHit_None;
	m_iOffset	= 0;

	m_dwTexDraw		= eTex_Percent | eTex_Left | eTex_Right | eTex_Middle;
	m_iPrecision	= 2;
	m_iTexSpace		= 2;
	m_coText.setRgb( 255, 255, 255 );

	setMouseTracking( true );
}

CRangeSlider::~CRangeSlider()
{

}

VOID CRangeSlider::SetRange( double fMin, double fMax )
{
	if ( fMin < fMax )
	{
		m_fMin	= fMin;
		m_fMax	= fMax;
		m_fSliderMin	= max( m_fMin, m_fSliderMin );
		m_fSliderMin	= min( m_fMax, m_fSliderMin );
		m_fSliderMax	= min( m_fMax, m_fSliderMax );
		m_fSliderMax	= max( m_fMin, m_fSliderMax );
		CalcPos( width() );
		update();
	}
}

VOID CRangeSlider::GetRange( double* pMin, double* pMax )
{
	if ( pMin ) *pMin	= m_fMin;
	if ( pMax ) *pMax	= m_fMax;
}

VOID CRangeSlider::SetSlider( double fSliderMin, double fSliderMax )
{
	m_fSliderMin	= max( m_fMin, fSliderMin );
	m_fSliderMax	= min( m_fMax, fSliderMax );
	if ( m_fSliderMin > m_fSliderMax )
	{
		m_fSliderMin	= ( m_fSliderMax + m_fSliderMin ) * 0.5;
		m_fSliderMax	= m_fSliderMin;
	}
	CalcPos( width() );
	update();
}

VOID CRangeSlider::SetProgress( double fPos, BOOL bEnable )
{
	m_fPos		= max( m_fPos, m_fSliderMin );
	m_fPos		= min( m_fPos, m_fSliderMax );
	m_bEnablePos	= bEnable ? TRUE : FALSE;
	CalcPos( width() );
	update();
}

VOID CRangeSlider::SetColors( const QColor& coFrame, const QColor& coBack,
		const QColor& coSlider, const QColor& coLine, 
		const QColor& coProgress, const QColor& coText )
{
	m_coFrame	= coFrame;
	m_coBack	= coBack;
	m_coSlider	= coSlider;
	m_coLine	= coLine;
	m_coProgress	= coProgress;
	m_coText		= coText;
	update();
}

VOID CRangeSlider::SetText( DWORD eDrawMask, int iPrecision, int iSpace )
{
	m_dwTexDraw		= eDrawMask;
	m_iPrecision	= iPrecision;
	m_iTexSpace		= iSpace;
	update();
}

void CRangeSlider::resizeEvent ( QResizeEvent * event )
{
	CalcPos( event->size().width() );
}

void CRangeSlider::CalcPos( int iWidth )
{
	m_iLeft		= INT( ( iWidth - 3 ) * ( m_fSliderMin - m_fMin ) / ( m_fMax - m_fMin ) ) + 1;
	m_iRight	= INT( ( iWidth - 3 ) * ( m_fSliderMax - m_fMin ) / ( m_fMax - m_fMin ) ) + 1;
}

void CRangeSlider::CalcHit( int x, int y )
{
	if ( y < 1 || y > height() - 2 )
	{
		setCursor( QCursor( Qt::ArrowCursor ) );
		m_eHit	= eHit_None;
		return;
	}
	if ( x >= m_iLeft - 1 && x <= m_iLeft + 1 && m_iRight > 1
		&& ( m_dwHitMask & ( 1 << eHit_LeftLine ) ) )
	{
		setCursor( QCursor( Qt::SizeHorCursor ) );
		m_eHit	= eHit_LeftLine;
	}
	else if ( x >= m_iRight - 1 && x <= m_iRight + 1 && m_iLeft < width() - 2 
		&& ( m_dwHitMask & ( 1 << eHit_RightLine ) ) )
	{
		setCursor( QCursor( Qt::SizeHorCursor ) );
		m_eHit	= eHit_RightLine;
	}
	else if ( x > m_iLeft && x < m_iRight )
	{
		if ( m_dwHitMask & ( 1 << eHit_Slider ) )
		{
			setCursor( QCursor( Qt::SizeAllCursor ) );
			m_eHit	= eHit_Slider;
		}
		else if ( ( m_dwHitMask & ( 1 << eHit_Left ) ) && !( m_dwHitMask & ( 1 << eHit_Right ) ) )
		{
			setCursor( QCursor( Qt::ArrowCursor ) );
			m_eHit	= eHit_Left;
		}
		else if ( !( m_dwHitMask & ( 1 << eHit_Left ) ) && ( m_dwHitMask & ( 1 << eHit_Right ) ) )
		{
			setCursor( QCursor( Qt::ArrowCursor ) );
			m_eHit	= eHit_Right;
		}
	}
	else if ( x < m_iLeft && x > 0 && ( m_dwHitMask & ( 1 << eHit_Left ) ) )
	{
		setCursor( QCursor( Qt::ArrowCursor ) );
		m_eHit	= eHit_Left;
	}
	else if ( x > m_iRight && x < width() - 1 && ( m_dwHitMask & ( 1 << eHit_Right ) ) )
	{
		setCursor( QCursor( Qt::ArrowCursor ) );
		m_eHit	= eHit_Right;
	}
	else
	{
		setCursor( QCursor( Qt::ArrowCursor ) );
		m_eHit	= eHit_None;
	}
}

void CRangeSlider::mouseMoveEvent ( QMouseEvent * event )
{
	if ( event->buttons() == Qt::LeftButton )
	{
		switch( m_eHit )
		{
		case eHit_None:
			break;
		case eHit_LeftLine:
			m_iLeft	= event->pos().x() + m_iOffset;
			if ( m_iLeft > m_iRight ) m_iLeft = m_iRight;
			if ( m_iLeft < 1 ) m_iLeft = 1;
			m_fSliderMin	= ( m_iLeft - 1 ) * ( m_fMax - m_fMin ) / ( width() - 3 ) + m_fMin;
			update();
			emit sliderRange( m_fSliderMin, m_fSliderMax );
			break;
		case eHit_RightLine:
			m_iRight	= event->pos().x() + m_iOffset;
			if ( m_iRight < m_iLeft ) m_iRight = m_iLeft;
			if ( m_iRight > width() - 2 ) m_iRight = width() - 2;
			m_fSliderMax	= ( m_iRight - 1 ) * ( m_fMax - m_fMin ) / ( width() - 3 ) + m_fMin;
			update();
			emit sliderRange( m_fSliderMin, m_fSliderMax );
			break;
		case eHit_Slider:
			{
				int	iWidth	= m_iRight - m_iLeft;
				int	iLeft	= event->pos().x() + m_iOffset;
				if ( iLeft < 1 ) iLeft = 1;
				if ( iLeft + iWidth > width() - 2 ) iLeft = width() - 2 - iWidth;
				m_iLeft		= iLeft;
				m_iRight	= iLeft + iWidth;
				float	fWidth	= m_fSliderMax - m_fSliderMin;
				m_fSliderMin		= ( m_iLeft - 1 ) * ( m_fMax - m_fMin ) / ( width() - 3 ) + m_fMin;
				m_fSliderMax	= m_fSliderMin + fWidth;
			}
			update();
			emit sliderRange( m_fSliderMin, m_fSliderMax );
			break;	
		}
	}
	else
	{
		CalcHit( event->pos().x(), event->pos().y() );
	}
}

void CRangeSlider::mousePressEvent ( QMouseEvent * event )
{
	if ( event->button() == Qt::LeftButton )
	{
		switch( m_eHit )
		{
		case eHit_None:
			break;
		case eHit_Left:
			m_iLeft	= event->pos().x();
			m_fSliderMin	= ( m_iLeft - 1 ) * ( m_fMax - m_fMin ) / ( width() - 3 ) + m_fMin;
			CalcHit( event->pos().x(), event->pos().y() );
			update();
			emit sliderRange( m_fSliderMin, m_fSliderMax );
			break;
		case eHit_Right:
			m_iRight	= event->pos().x();
			m_fSliderMax	= ( m_iRight - 1 ) * ( m_fMax - m_fMin ) / ( width() - 3 ) + m_fMin;
			CalcHit( event->pos().x(), event->pos().y() );
			update();
			emit sliderRange( m_fSliderMin, m_fSliderMax );
			break;
		case eHit_LeftLine:
			m_iOffset	= m_iLeft - event->pos().x();
			break;
		case eHit_RightLine:
			m_iOffset	= m_iRight - event->pos().x();
			break;
		case eHit_Slider:
			m_iOffset	= m_iLeft - event->pos().x();
			break;
		
		}
	}
}

void CRangeSlider::mouseReleaseEvent ( QMouseEvent * event )
{
}

void CRangeSlider::paintEvent ( QPaintEvent * event )
{
	QPainter	pnt( this );
	QRect		rtDraw	= rect();
	QPoint		poSlider;

	rtDraw.setWidth( rtDraw.width() - 1 );
	rtDraw.setHeight( rtDraw.height() - 1 );
	pnt.setPen( m_coFrame );
	pnt.fillRect( rtDraw, m_coBack );
	pnt.drawRect( rtDraw );

	rtDraw.setTop( 1 );
	rtDraw.moveLeft( m_iLeft );
	rtDraw.setWidth( m_iRight - m_iLeft + 1 );
	pnt.fillRect( rtDraw, m_coSlider );
	poSlider	= rtDraw.center();

	pnt.setPen( m_coLine );
	if ( m_dwHitMask & ( 1 << eHit_LeftLine ) )
		pnt.drawLine( m_iLeft, rtDraw.top(), m_iLeft, rtDraw.bottom() );
	if ( m_dwHitMask & ( 1 << eHit_RightLine ) ) 
		pnt.drawLine( m_iRight, rtDraw.top(), m_iRight, rtDraw.bottom() );

	if ( m_bEnablePos )
	{
	}

	if ( m_dwTexDraw & 0xF )
	{
		QString	szLeft, szRight, szMiddle;
		if ( (m_dwTexDraw & 0xF) == eTex_Percent )
		{
			double	dVal	= ( m_fSliderMin - m_fMin ) / ( m_fMax - m_fMin ) * 100.0;
			szLeft	= QString( "%1%" ).arg( dVal, 0, 'f', m_iPrecision );
			if ( m_dwTexDraw & eTex_RightRange )
				dVal	= ( m_fMax - m_fSliderMax - m_fMin ) / ( m_fMax - m_fMin ) * 100;
			else
				dVal	= ( m_fSliderMax - m_fMin ) / ( m_fMax - m_fMin ) * 100;
			szRight	= QString( "%1%" ).arg( dVal, 0, 'f', m_iPrecision );
			dVal	= ( m_fSliderMax - m_fSliderMin ) / ( m_fMax - m_fMin ) * 100;
			szMiddle	= QString( "%1%" ).arg( dVal, 0, 'f', m_iPrecision );
		}
		else if ( (m_dwTexDraw & 0xF) == eTex_Number )
		{
			szLeft	= QString( "%1" ).arg( m_fSliderMin, 0, 'f', m_iPrecision );
			if ( m_dwTexDraw & eTex_RightRange )
				szRight	= QString( "%1" ).arg( m_fMax - m_fSliderMax, 0, 'f', m_iPrecision );
			else
				szRight	= QString( "%1" ).arg( m_fSliderMax, 0, 'f', m_iPrecision );
			szMiddle	= QString( "%1" ).arg( m_fSliderMax - m_fSliderMin, 0, 'f', m_iPrecision );
		}

		rtDraw	= rect();
		rtDraw.setLeft(	m_iTexSpace + 1 );
		rtDraw.setRight( width() - 2 - m_iTexSpace );
		pnt.setPen( m_coText );
		if ( m_dwTexDraw & eTex_Left )
			pnt.drawText( rtDraw, Qt::AlignLeft | Qt::AlignVCenter, szLeft );
		if ( m_dwTexDraw & eTex_Right )
			pnt.drawText( rtDraw, Qt::AlignRight | Qt::AlignVCenter, szRight );
		if ( m_dwTexDraw & eTex_Middle )
		{
			if ( m_dwTexDraw & eTex_MidSlider )
			{
				rtDraw.moveCenter( poSlider );
			}
			pnt.drawText( rtDraw, Qt::AlignCenter | Qt::AlignVCenter, szMiddle );
		}
	}
}
