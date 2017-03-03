#include "StdAfx.h"
#include "DlgAddLive.h"

DlgAddLive::DlgAddLive(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

DlgAddLive::~DlgAddLive()
{

}


void DlgAddLive::on_butOK_clicked()
{
	m_sLiveUrl.iType	= ui.combLiveType->currentIndex();
	switch( m_sLiveUrl.iType )
	{
	case 0:
		m_sLiveUrl.szDispName	= QString::fromUtf16(L"RTMP£º");
		m_sLiveUrl.szUrlOrId	= ui.texRtmpUrl->text();
		if ( m_sLiveUrl.szUrlOrId.isEmpty() )
		{
			return;
		}
		break;
	case 1:
		m_sLiveUrl.szDispName	= QString::fromUtf16(L"RdCloud£º");
		m_sLiveUrl.szUrlOrId	= ui.texSdkUserId->text();
		if ( m_sLiveUrl.szUrlOrId.isEmpty() )
		{
			return;
		}
		break;
	case 2:
		m_sLiveUrl.szDispName	= QString::fromUtf16(L"Èñ¶¯Ö±²¥£º");
		m_sLiveUrl.szUrlOrId	= ui.texRdLiveUserName->text();
		m_sLiveUrl.szPw			= ui.texRdLivePassword->text();
		m_sLiveUrl.bAutoLogin	= ui.chkRdLiveAutoLogin->isChecked();
		if ( m_sLiveUrl.szUrlOrId.isEmpty() || m_sLiveUrl.szPw.isEmpty() )
		{
			return;
		}
		break;
	}
	m_sLiveUrl.szDispName.append( m_sLiveUrl.szUrlOrId );
	accept();
}

void DlgAddLive::on_butCancel_clicked()
{
	reject();
}
