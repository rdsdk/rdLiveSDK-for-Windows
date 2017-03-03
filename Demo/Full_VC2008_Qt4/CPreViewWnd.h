#ifndef CPREVIEWWND_H
#define CPREVIEWWND_H

#include <QWidget>

class CPreviewWnd : public QWidget
{
	Q_OBJECT

public:
	CPreviewWnd(QWidget *parent);
	~CPreviewWnd();
	void SetUsePreiveImage( BOOL bUse );
	static	VOID WINAPI OnPreviewBufferCB( INT iWidth, INT iHeight, LPBYTE pImageBuffer, LPVOID pCbParam );
private:
	BOOL	m_bUsePreiveImg;
	HCURSOR	m_hCursor;
	QImage	m_imgPreview;
	QMutex	m_mutex;
	UINT MsgFromButton( Qt::MouseButton but, BOOL bPress );
	WPARAM WParamFromBottons( Qt::MouseButtons buts );
	void paintEvent( QPaintEvent * event );
	void mouseMoveEvent( QMouseEvent * event );
	void mousePressEvent( QMouseEvent * event );
	void mouseReleaseEvent( QMouseEvent * event );
	void wheelEvent( QWheelEvent * event );
signals:
	void previewBuffer( int, int, void* );
public slots:
	//void onGameListChanged( quint32 dwPID, qint32 iInterface );};
};
#endif // CPREVIEWWND_H
