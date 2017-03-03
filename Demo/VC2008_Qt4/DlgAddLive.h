#ifndef DLGADDLIVE_H
#define DLGADDLIVE_H

#include <QDialog>
#include "ui_DlgAddLive.h"

class DlgAddLive : public QDialog
{
	Q_OBJECT

public:
	DlgAddLive(QWidget *parent = 0);
	~DlgAddLive();

	struct	SLiveUrl
	{
		int		iType;
		QString	szDispName;
		QString	szUrlOrId;
		QString	szPw;
		bool	bAutoLogin;
	};
	SLiveUrl	m_sLiveUrl;
private:
	Ui::DlgAddLive ui;
public slots:
	void on_butOK_clicked();
	void on_butCancel_clicked();
};

#endif // DLGADDLIVE_H
