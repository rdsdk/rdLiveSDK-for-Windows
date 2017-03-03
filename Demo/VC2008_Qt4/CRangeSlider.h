#ifndef RANGESLIDER_H
#define RANGESLIDER_H

#include <QWidget>

class CRangeSlider : public QWidget
{
	Q_OBJECT

public:
	CRangeSlider(QWidget *parent);
	~CRangeSlider();

	VOID SetRange( double fMin, double fMax );
	VOID GetRange( double* pMin, double* pMax );

	VOID SetSlider( double fSliderMin, double fSliderMax );
	double GetSliderMin() { return m_fSliderMin; }
	double GetSliderMax() { return m_fSliderMax; };
	VOID SetProgress( double fPos, BOOL bEnable );
	double GetProgress() { return m_fPos; }

	VOID SetColors( const QColor& coFrame, const QColor& coBack,
		const QColor& coSlider, const QColor& coLine, 
		const QColor& coProgress, const QColor& coText ); 

	enum	EHit
	{
		eHit_None,
		eHit_Left,
		eHit_Right,
		eHit_LeftLine,
		eHit_RightLine,
		eHit_Slider,
	};

	enum	ETextDraw
	{
		//显示值的内容模式，只能使用其中一个。
		eTex_None		= 0,	//什么都不显示
		eTex_Percent	= 1,	//显示为百分数
		eTex_Number		= 2,	//显示为数字
		//显示值的位置 MASK，使用多个值组合。
		eTex_Left		= 0x10,	//显示左边的值
		eTex_Right		= 0x20,
		eTex_Middle		= 0x40,
		//
		eTex_RightRange	= 0x100,	//右侧的值使用显示为右侧空出的范围，否则直接显示右边的值。
		eTex_MidSlider	= 0x200,	//中间的值跟随滑块移动。
	};

	VOID SetText( DWORD eDrawMask, int iPrecision, int iSpace );
	VOID SetHitMask( DWORD dwHitMask )	{ m_dwHitMask = dwHitMask; }
signals:
	void sliderRange( double fLeft, double fRight );
	void progress( double fProgress );
private:
	virtual void	mouseMoveEvent ( QMouseEvent * event );
	virtual void	mousePressEvent ( QMouseEvent * event );
	virtual void	mouseReleaseEvent ( QMouseEvent * event );
	virtual void	paintEvent ( QPaintEvent * event );
	virtual void	resizeEvent ( QResizeEvent * event );
	void CalcPos( int iWidth );
	void CalcHit( int x, int y );

	double	m_fMax;
	double	m_fMin;
	double	m_fSliderMin;
	double	m_fSliderMax;
	double	m_fPos;
	BOOL	m_bEnablePos;
	QColor	m_coFrame;
	QColor	m_coBack;
	QColor	m_coSlider;
	QColor	m_coLine;
	QColor	m_coProgress;

	int		m_iLeft;
	int		m_iRight;
	int		m_iPos;
	DWORD	m_dwHitMask;
	EHit	m_eHit;
	int		m_iOffset;

	DWORD	m_dwTexDraw;
	int		m_iPrecision;
	int		m_iTexSpace;
	QColor	m_coText;
};

#endif // RANGESLIDER_H
