#include "StdAfx.h"
#include "DlgEncoderSetting.h"
#include "DlgAddLive.h"

DlgEncoderSetting::DlgEncoderSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_pDocOption	= NULL;
	QStandardItemModel	*model	= new QStandardItemModel();
	ui.listViewLiveUrls->setModel( model );
}

DlgEncoderSetting::~DlgEncoderSetting()
{

}

void DlgEncoderSetting::SetDocOption( QDomDocument* pDoc )
{
	m_pDocOption	= pDoc;
}

QDomElement DlgEncoderSetting::FindXmlElement( const QString& szPath, BOOL bCreateIfNull )
{
	if ( m_pDocOption == NULL ) return QDomElement();
	QStringList		lstNode		= szPath.split( '/' );
	QDomElement		eleFind		= m_pDocOption->documentElement();  //返回根元素
	for ( int i = 0; i < lstNode.count(); ++i )
	{
		QDomElement	eleParent	= eleFind;
		eleFind		= eleParent.firstChildElement( lstNode[i] );
		if ( eleFind.isNull() )
		{
			if ( bCreateIfNull )
			{
				eleFind	= m_pDocOption->createElement( lstNode[i]);
				eleParent.appendChild( eleFind );
			}
			else
			{
				break;
			}
		}
	}
	return eleFind;
}

void DlgEncoderSetting::SetEncoderSetting()
{
	//视频
	QDomElement		eleVideo	= FindXmlElement( "Encoder/Video" );
	EVideoEncoder	eVidEncoder	= VE_X264;
	if ( !eleVideo.isNull() )
	{
		for ( int i = 0; i < 4; ++i )
		{
			QDomElement		eleEnc	= eleVideo.firstChildElement( video_encoder_names[i] );
			if ( !eleEnc.isNull() )
			{
				Encoder_SetProfile( EVideoEncoder(i), (EVideoProfile)eleEnc.attribute( "Profile", "0" ).toInt() );
				Encoder_SetPreset( EVideoEncoder(i), (EVideoPreset)eleEnc.attribute( "Perset", "0" ).toInt() ); 
			}
		}
		eVidEncoder	= (EVideoEncoder)eleVideo.attribute( "Enc", "0" ).toInt();
		if ( !Encoder_SetCurrent( eVidEncoder ) )	eVidEncoder	= Encoder_GetCurrent();

		QDomElement		eleBitrate	= eleVideo.firstChildElement( "Bitrate" );
		if ( !eleBitrate.isNull() )
		{
			Encoder_SetBitrate( (EVideoRateMode)eleBitrate.attribute( "RMode", "0" ).toInt(),
				eleBitrate.attribute( "Bitrate", "1000" ).toInt(),
				eleBitrate.attribute( "Max", "1000" ).toInt(),
				eleBitrate.attribute( "Vbv", "1000" ).toInt() );
		}
		QDomElement		eleFrameParam	= eleVideo.firstChildElement( "FrameParams" );
		if ( !eleFrameParam.isNull() )
		{
			Encoder_SetFrameParams( eleFrameParam.attribute( "Gop", "0" ).toInt(),
				eleFrameParam.attribute( "GopMin", "0" ).toInt(),
				eleFrameParam.attribute( "Ref", "0" ).toInt(),
				eleFrameParam.attribute( "BFrame", "0" ).toInt() );
		}
	}
	if ( Encoder_IsUsable( VE_X264, NULL, NULL, NULL ) )	ui.combVideoEncoder->addItem( video_encoder_names[VE_X264], int(VE_X264) );
	if ( Encoder_IsUsable( VE_CUDA, NULL, NULL, NULL ) )	ui.combVideoEncoder->addItem( video_encoder_names[VE_CUDA], int(VE_CUDA) );
	if ( Encoder_IsUsable( VE_NVENC, NULL, NULL, NULL ) )	ui.combVideoEncoder->addItem( video_encoder_names[VE_NVENC], int(VE_NVENC) );
	if ( Encoder_IsUsable( VE_INTEL, NULL, NULL, NULL ) )	ui.combVideoEncoder->addItem( video_encoder_names[VE_INTEL], int(VE_INTEL) );
	ui.combVideoEncoder->setCurrentIndex( ui.combVideoEncoder->findData( int(eVidEncoder) ) );
	EVideoRateMode	eRateMode;
	INT				iBitrate, iBitrateMax, iVbvSize;
	if ( Encoder_GetBitrate( &eRateMode, &iBitrate, &iBitrateMax, &iVbvSize ) )
	{
		ui.spinVideoBitrate->setValue( iBitrate );
		ui.combVideoVBVMode->setCurrentIndex( eRateMode );
		ui.spinVBVBitrateMax->setValue( iBitrateMax );
		ui.spinVBVBufSize->setValue( iVbvSize );
	}
	INT				iGop, iGopMin, iRefFrames, iBFrames;
	if ( Encoder_GetFrameParams( &iGop, &iGopMin, &iRefFrames, &iBFrames ) )
	{
		ui.spinVideoIDR->setValue( iGop );
		ui.spinVideoIMin->setValue( iGopMin );
		ui.spinVideoRef->setValue( iRefFrames );
		ui.spinVideoBFrame->setValue( iBFrames );
	}
	//音频
	QDomElement		eleAudio	= FindXmlElement( "Encoder/Audio" );
	EAudioEncoder	eAudEncoder	= Aud_Enc_AAC;
	EAudioInSamples	eSamples	= Aud_Inp_Samp_22050;
	WORD			wBits		= 16;
	if ( !eleAudio.isNull() )
	{
		eAudEncoder	= (EAudioEncoder)eleAudio.attribute( "Enc", "0" ).toInt();
		QDomNode		nodeSamp	= eleAudio.firstChild();
		while( !nodeSamp.isNull() )
		{
			QDomElement	eleSamp	= nodeSamp.toElement();
			if ( eleSamp.tagName() == "Samp" )
			{
				ui.combAudioSamples->addItem( eleSamp.attribute( "Str" ), 
					int( ( eleSamp.attribute( "Bit" ).toInt() << 16 ) | eleSamp.attribute( "Samp" ).toInt() ) );
			}
			nodeSamp	= nodeSamp.nextSibling();
		}

		QDomElement		eleAudParam	= eleAudio.firstChildElement( "AudioParam" );
		if ( !eleAudParam.isNull() )
		{
			Encoder_SetAudioParams( eleAudParam.attribute( "Channel", "2" ).toInt(),
				(EAudioInSamples)eleAudParam.attribute( "Sample", "22050" ).toInt(),
				eleAudParam.attribute( "Bits", "16" ).toInt(),
				eAudEncoder,
				eleAudParam.attribute( "Bitrate", "0" ).toInt() );
		}
	}

	WORD			wChannels;
	if ( Encoder_GetAudioParam( &wChannels, &eSamples, &wBits, &eAudEncoder, &iBitrate ) )
	{
		ui.spinAudioBitrate->setValue( iBitrate );
		if ( wChannels == 1 )
		{
			ui.radSingleChannel->setChecked( true );
		}
		else
		{
			ui.radDoubleChannel->setChecked( true );
		}
		ui.combAudioSamples->setCurrentIndex( ui.combAudioSamples->findData( int( ( wBits<<16 ) | eSamples ) ) );
	}
	//输出
	QDomElement		eleSave	= FindXmlElement( "Encoder/Save" );
	ui.editVideoTitle->setText( eleSave.attribute( "Title" ) );
	ui.gboxSaveToFile->setChecked( eleSave.attribute( "File", 0 ).toInt() ? true : false );
	ui.gboxLiveToNet->setChecked( eleSave.attribute( "Live", 0 ).toInt() ? true : false );
	ui.chkAdaptiveNetwork->setChecked( eleSave.attribute( "AdaptiveNetwork", 0 ).toInt() ? true : false );
	//文件
	QDomElement		eleFile	= FindXmlElement( "Encoder/Save/File" );
	if ( !eleSave.isNull() )
	{
		ui.editVideoDir->setText( eleFile.attribute( "Dir" ) );
		ui.combVideoFileFormat->setCurrentIndex( eleFile.attribute( "Fmt", 0 ).toInt() );
		ui.spinVideoSplitSize->setValue( eleFile.attribute( "Split", 0 ).toInt() );
	}
	CheckMovieSaveDir();
	//直播
	QDomNode		nodeLive	= FindXmlElement( "Encoder/Save", TRUE ).firstChild();
	QStandardItemModel	*pModel	= (QStandardItemModel*)ui.listViewLiveUrls->model();
	while( !nodeLive.isNull() )
	{
		QDomElement	eleLive		= nodeLive.toElement();
		if ( !nodeLive.isElement() || eleLive.isNull() || eleLive.tagName() != "Live" )
		{
			nodeLive	= nodeLive.nextSibling();
			continue;
		}
		QStandardItem		*pItem	= new QStandardItem( eleLive.attribute("DispName") );
		pItem->setCheckable( true );
		pItem->setCheckState( eleLive.attribute("Checked").toInt() ? Qt::Checked : Qt::Unchecked );
		pItem->setData( eleLive.attribute("Date").toUInt() );
		pModel->appendRow( pItem );
		nodeLive	= nodeLive.nextSibling();
	}
}

bool DlgEncoderSetting::UpdateEncoderConfig( BOOL bPopMsg )
{
	DWORD	dwError	= 0;
	//视频
	QDomElement		eleBitrate	= FindXmlElement( "Encoder/Video/Bitrate", TRUE );
	eleBitrate.setAttribute( "RMode", ui.combVideoVBVMode->currentIndex() );
	eleBitrate.setAttribute( "Bitrate", ui.spinVideoBitrate->value() );
	eleBitrate.setAttribute( "Max", ui.spinVBVBitrateMax->value() );
	eleBitrate.setAttribute( "Vbv", ui.spinVBVBufSize->value() );

	Encoder_SetBitrate( (EVideoRateMode)ui.combVideoVBVMode->currentIndex(),
		ui.spinVideoBitrate->value(),
		ui.spinVBVBitrateMax->value(),
		ui.spinVBVBufSize->value() );

	QDomElement		eleFrameParam	= FindXmlElement( "Encoder/Video/FrameParams", TRUE );
	eleFrameParam.setAttribute( "Gop", ui.spinVideoIDR->value() );
	eleFrameParam.setAttribute( "GopMin", ui.spinVideoIMin->value() );
	eleFrameParam.setAttribute( "Ref", ui.spinVideoRef->value() );
	eleFrameParam.setAttribute( "BFrame", ui.spinVideoBFrame->value() );
	
	Encoder_SetFrameParams( ui.spinVideoIDR->value(),
		ui.spinVideoIMin->value(),
		ui.spinVideoRef->value(),
		ui.spinVideoBFrame->value() );

	//音频
	EAudioInSamples	eSamples	= Aud_Inp_Samp_22050;
	WORD			wBits		= 16;
	EAudioEncoder	eAudEncoder	= Aud_Enc_AAC;
	QDomElement		eleAudio	= FindXmlElement( "Encoder/Audio", TRUE );
	eleAudio.setAttribute( "Enc", int( eAudEncoder ) );
	if ( ui.combAudioSamples->currentIndex() >= 0 )
	{
		DWORD		dwValue		= ui.combAudioSamples->itemData( ui.combAudioSamples->currentIndex() ).toInt();
		eSamples	= EAudioInSamples( dwValue & 0xFFFF );
		wBits		= dwValue >> 16;
	}
	QDomElement		eleAudParam	= FindXmlElement( "Encoder/Audio/AudioParam", TRUE );
	eleAudParam.setAttribute( "Channel", ui.radSingleChannel->isChecked() ? 1 : 2 );
	eleAudParam.setAttribute( "Sample", int( eSamples ) );
	eleAudParam.setAttribute( "Bits", int( wBits ) );
	eleAudParam.setAttribute( "Bitrate", ui.spinAudioBitrate->value() );

	Encoder_SetAudioParams( ui.radSingleChannel->isChecked() ? 1 : 2,
		eSamples,
		wBits,
		eAudEncoder,
		ui.spinAudioBitrate->value() );

	//输出
	SEncoderSaveFile	sSave;
	ZeroMemory( &sSave, sizeof( sSave ) );
	QString				szTitle	= ui.editVideoTitle->text();
	if ( bPopMsg && szTitle.isEmpty() )
	{
		QMessageBox::warning( window(), QFU(L"编码输出"),
			QFU(L"标题不能为空！\n请输入标题。") );
		return false;
	}
    sSave.szTitle		= (LPCWSTR)szTitle.utf16();
	QDomElement		eleSave	= FindXmlElement( "Encoder/Save", TRUE );
	eleSave.setAttribute( "Title", szTitle );
	eleSave.setAttribute( "File", ui.gboxSaveToFile->isChecked() ? 1 : 0 );
	eleSave.setAttribute( "Live", ui.gboxLiveToNet->isChecked() ? 1 : 0 );
	eleSave.setAttribute( "AdaptiveNetwork", ui.chkAdaptiveNetwork->isChecked() ? 1 : 0 );
	//输出-文件
	QDomElement		eleFile	= FindXmlElement( "Encoder/Save/File", TRUE );
	Encoder_RemoveSaveFile( -1 );	//删除所有的保存文件设置
	LPCSTR				szExtNames[]	= { ".flv", ".mp4", ".avi" };
	QString				szFilePath;

	sSave.eContainer	= (EFileContainer)ui.combVideoFileFormat->currentIndex();
	if ( !CheckMovieSaveDir( bPopMsg ) )
	{
		return false;
	}
	szFilePath			= CombinationFilePath( ui.editVideoDir->text(), ui.editVideoTitle->text(), szExtNames[ sSave.eContainer ] );
    sSave.szSavePath	= (LPCWSTR)szFilePath.utf16();
	sSave.iSplitSize	= INT64( ui.spinVideoSplitSize->value() ) * 1024 * 1024;

	eleFile.setAttribute( "Dir", ui.editVideoDir->text() );
	eleFile.setAttribute( "Fmt", int( sSave.eContainer ) );
	eleFile.setAttribute( "Split", ui.spinVideoSplitSize->value() );

	if ( ui.gboxSaveToFile->isChecked() )
	{
		if ( -1 == Encoder_AddSaveFile( &sSave ) )
		{
			dwError	= GetLastError();
		}
	}
	//输出-直播
	sSave.dwDelaySecond		= 0;
	sSave.bAdaptiveNetwork	= ui.chkAdaptiveNetwork->isChecked();
	QDomNode		nodeLive	= FindXmlElement( "Encoder/Save", TRUE ).firstChild();
	QStandardItemModel	*pModel	= (QStandardItemModel*)ui.listViewLiveUrls->model();
	while( !nodeLive.isNull() )
	{
		QDomElement	eleLive		= nodeLive.toElement();
		if ( !nodeLive.isElement() || eleLive.isNull() || eleLive.tagName() != "Live" )
		{
			nodeLive	= nodeLive.nextSibling();
			continue;
		}

		for ( int i = 0; i < pModel->rowCount(); ++i )
		{
			if ( eleLive.attribute( "Date" ).toUInt() == pModel->item(i)->data().toUInt() )
			{
				if ( pModel->item(i)->checkState() == Qt::Checked )
				{
					eleLive.setAttribute( "Checked", 1 );
					if ( ui.gboxLiveToNet->isChecked() )
					{
						switch( eleLive.attribute( "Type" ).toInt() )
						{
						case 0:
							sSave.eContainer	= Mix_RTMP;
                            sSave.szSavePath	= (LPCWSTR)eleLive.attribute( "UrlOrId" ).utf16();
							break;
						case 1:
							sSave.eContainer	= Mix_RdCloud;
                            sSave.szSavePath	= (LPCWSTR)eleLive.attribute( "UrlOrId" ).utf16();
							break;
						case 2:
							sSave.eContainer	= Mix_RdCloud;
                            sSave.szSavePath	= (LPCWSTR)eleLive.attribute( "UrlOrId" ).utf16();
							break;
						}
						if ( -1 == Encoder_AddSaveFile( &sSave ) )
						{
							dwError	= GetLastError();
						}
					}
				}
				else
				{
					eleLive.setAttribute( "Checked", 0 );
				}
				break;
			}
		}
		nodeLive	= nodeLive.nextSibling();
	}

	return true;
}

QString DlgEncoderSetting::CombinationFilePath( const QString& szDir, const QString& szPrefix, const QString& szExtension )
{
	QString	szFilePath	= szDir;
	SYSTEMTIME	stTime;
	if ( !szFilePath.endsWith( "\\" ) ) szFilePath += "\\";

	GetLocalTime( &stTime );
	QString	szPre	= szPrefix;

	szPre.replace( QChar('\\'), QChar('-') );
	szPre.replace( QChar('/'), QChar('-') );
	szPre.replace( QChar(':'), QChar('-') );
	szPre.replace( QChar('*'), QChar('-') );
	szPre.replace( QChar('?'), QChar('-') );
	szPre.replace( QChar('\"'), QChar('\'') );
	szPre.replace( QChar('<'), QChar('(') );
	szPre.replace( QChar('>'), QChar(')') );
	szPre.replace( QChar('|'), QChar('!') );

	szFilePath	+= QString( "%1-%2-%3\\" ).arg( stTime.wYear, 2, 10, QChar('0') )
		.arg( stTime.wMonth, 2, 10, QChar('0') ).arg( stTime.wDay, 2, 10, QChar('0') );
	szFilePath	+= QString( "%1(%2%3%4)%5" ).arg( szPre )
		.arg( stTime.wHour, 2, 10, QChar('0') ).arg( stTime.wMinute, 2, 10, QChar('0') )
		.arg( stTime.wSecond, 2, 10, QChar('0') ).arg( szExtension );


	//if ( !szPre.isEmpty() )
	//	szFilePath	+= QString( "[%1]" ).arg( szPre );

	//GetLocalTime( &stTime );
	//szFilePath	+= QString( "%1-%2-%3(%4%5%6)%7" ).arg( stTime.wYear, 2, 10, QChar('0') )
	//	.arg( stTime.wMonth, 2, 10, QChar('0') ).arg( stTime.wDay, 2, 10, QChar('0') )
	//	.arg( stTime.wHour, 2, 10, QChar('0') ).arg( stTime.wMinute, 2, 10, QChar('0') )
	//	.arg( stTime.wSecond, 2, 10, QChar('0') ).arg( szExtension );
	return szFilePath;
}

bool DlgEncoderSetting::CheckMovieSaveDir( BOOL bPopMsg )
{
	bool	bUseDefault	= false;
	if ( ui.editVideoDir->text().isEmpty() )
	{
		bUseDefault	= true;
	}
	else
	{
		QDir	dir( ui.editVideoDir->text() );
		if ( !dir.exists() && !dir.mkpath( ui.editVideoDir->text() ) )
		{
			if ( bPopMsg )
			{
				if ( QMessageBox::Ok == QMessageBox::question( window(), QFU(L"视频文件夹"),
					QFU(L"指定的视频文件夹不存在，并且创建失败，是否使用默认的视频文件夹？"), 
					QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok ) )
				{
					bUseDefault	= true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				bUseDefault	= true;
			}
		}
	}
	if ( bUseDefault )
	{
		ui.editVideoDir->setText( QFU( RDLive_DefaultDir( RDir_Videos ) ) );
	}
	return true;
}

void DlgEncoderSetting::on_combVideoEncoder_currentIndexChanged ( int index )
{
	if ( index >= 0 )
	{
		EVideoEncoder	eEncoder	= (EVideoEncoder)ui.combVideoEncoder->itemData( index ).toInt();
		DWORD dwSupportProfileMask, dwSupportPresetMask, dwSupportColorSpaceMask;
		if ( Encoder_IsUsable( eEncoder, &dwSupportProfileMask, &dwSupportPresetMask, &dwSupportColorSpaceMask ) )
		{
			Encoder_SetCurrent( eEncoder );
			QDomElement		eleVideo	= FindXmlElement( "Encoder/Video", TRUE );
			eleVideo.setAttribute( "Enc", int( eEncoder ) );

			EVideoPreset	ePreset	= Encoder_GetPreset( eEncoder );
			ui.combVideoPerset->clear();
			switch( eEncoder )
			{
			case VE_X264:
				for ( int i = 0; i <= VP_x264_Placebo; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						ui.combVideoPerset->addItem( video_preset_x264_names[i], i );
					}
				}
				break;
			case VE_CUDA:
				for ( int i = 0; i <= VP_Cuda_FlipCam; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						ui.combVideoPerset->addItem( video_preset_cuda_names[i], i );
					}
				}
				break;
			case VE_NVENC:
				for ( int i = 0; i <= VP_Nvenc_LosslessHP; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						ui.combVideoPerset->addItem( video_preset_nvenc_names[i], i );
					}
				}
				break;
			case VE_INTEL:
				for ( int i = 0; i <= VP_Intel_Quality; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						ui.combVideoPerset->addItem( video_preset_intel_names[i], i );
					}
				}
				break;
			}
			ui.combVideoPerset->setCurrentIndex( ui.combVideoPerset->findData( (int)ePreset ) );
		}
		else
		{
			Encoder_SetCurrent( VE_X264 );
		}
	}
}

void DlgEncoderSetting::on_combVideoPerset_currentIndexChanged ( int index )
{
	if ( index >= 0 )
	{
		EVideoEncoder	eEncoder	= Encoder_GetCurrent();
		EVideoPreset	ePreset		= (EVideoPreset)ui.combVideoPerset->itemData( index ).toInt();
		Encoder_SetPreset( Encoder_GetCurrent(), ePreset );

		QDomElement		eleEnc	= FindXmlElement( QString( "Encoder/Video/" ) + video_encoder_names[eEncoder], TRUE );
		if ( !eleEnc.isNull() )
		{
			eleEnc.setAttribute( "Perset", ePreset );
		}
	}
}

void DlgEncoderSetting::on_spinVideoBitrate_valueChanged ( int i )
{
	ui.spinVBVBitrateMax->setRange( i, i * 2 );
	ui.spinVBVBitrateMax->setValue( i * 1.5 );
}

void DlgEncoderSetting::on_spinVBVBitrateMax_valueChanged ( int i )
{
	ui.spinVBVBufSize->setRange( i, i * 2 );
	ui.spinVBVBufSize->setValue( i );
}

void DlgEncoderSetting::on_combVideoVBVMode_currentIndexChanged ( int index )
{
	if ( index >= 0 )
	{
		EVideoRateMode	eRateMode	= (EVideoRateMode)index;
		if ( eRateMode == VR_VariableBitrate || eRateMode == VR_ConstantQP )
		{
			ui.spinVBVBitrateMax->setEnabled( true );
			ui.spinVBVBufSize->setEnabled( true );
		}
		else
		{
			ui.spinVBVBitrateMax->setEnabled( false );
			ui.spinVBVBufSize->setEnabled( false );
		}
	}
}

void DlgEncoderSetting::on_butBrowVideoDir_clicked()
{
	QString	szDir	= QFileDialog::getExistingDirectory( this,
		QFU( L"选择视频文件夹" ), 
		ui.editVideoDir->text(), QFileDialog::ShowDirsOnly );
	if ( !szDir.isEmpty() )
	{
		ui.editVideoDir->setText( szDir );
	}
}

void DlgEncoderSetting::on_butViewVideoDir_clicked()
{
	if ( CheckMovieSaveDir( TRUE ) )
	{
        ShellExecute( winId(), L"explore", (LPCWSTR)ui.editVideoDir->text().utf16(), NULL, NULL, SW_SHOW );
	}
}

void DlgEncoderSetting::on_butAddLiveUrl_clicked()
{
	DlgAddLive	dlg;

	if ( dlg.exec() == QDialog::Accepted )
	{
		QStandardItemModel	*pModel	= (QStandardItemModel*)ui.listViewLiveUrls->model();
		//检查是否已经有相同的项目
		for ( int i = 0; i < pModel->rowCount(); ++i )
		{
			if ( pModel->item(i)->text().compare( dlg.m_sLiveUrl.szDispName, Qt::CaseInsensitive ) == 0 )
			{
				QMessageBox::critical( window(), QFU( L"添加直播目标" ), QFU( L"已经存在相同的项目" ) );
				return;
			}
		}

		//计算一个值作为item的附加值，以便能与xml中的记录一一对应。
		UINT		uTick	= 0;
		SYSTEMTIME	sSysTime;		//使用 UTC (1970-1-1) 至今经过的秒数（常说的时间戳）来作为附加值。
		FILETIME	sFileTime;		//相信在界面上，应该不会有1秒添加多项的情况，没有人操作有这么快。
		GetSystemTime( &sSysTime );
		SystemTimeToFileTime( &sSysTime, &sFileTime );	//UTC时间转为文件时间，文件时间是自 1601年1月1日 以来的 100ns 数。
		//文件时间除以 10000 得到毫秒数，再除以1000 到得秒数，减去 11644473600（1601-1-1到1970-1-1经过的秒数）得到UTC时间的秒数
		uTick		= ( ( INT64( sFileTime.dwHighDateTime ) << 32 ) | sFileTime.dwLowDateTime ) / 10000000 - 11644473600;
		QStandardItem		*pItem	= new QStandardItem( dlg.m_sLiveUrl.szDispName );
		pItem->setCheckable( true );
		pItem->setCheckState( Qt::Checked );
		pItem->setData( uTick );
		pModel->appendRow( pItem );

		QDomElement		eleSave	= FindXmlElement( "Encoder/Save", TRUE );
		QDomElement		eleLive	= m_pDocOption->createElement( "Live" );
		eleSave.appendChild( eleLive );
		eleLive.setAttribute( "Type", dlg.m_sLiveUrl.iType );
		eleLive.setAttribute( "UrlOrId", dlg.m_sLiveUrl.szUrlOrId );
		eleLive.setAttribute( "PW", dlg.m_sLiveUrl.szPw );
		eleLive.setAttribute( "AutoLogin", dlg.m_sLiveUrl.bAutoLogin ? 1 : 0 );
		eleLive.setAttribute( "DispName", dlg.m_sLiveUrl.szDispName );
		eleLive.setAttribute( "Checked", 1 );
		eleLive.setAttribute( "Date", uTick );
		
	}
}

void DlgEncoderSetting::on_butDelLiveUrl_clicked()
{
	QModelIndex			selInd	= ui.listViewLiveUrls->currentIndex();
	if ( selInd.row() >= 0 )
	{
		QStandardItemModel	*pModel	= (QStandardItemModel*)ui.listViewLiveUrls->model();
		QStandardItem		*pItem	= pModel->itemFromIndex( selInd );
		if ( pItem )
		{
			QDomElement		eleSave		= FindXmlElement( "Encoder/Save" );
			QDomNode		nodeLive	= eleSave.firstChild();
			while( !nodeLive.isNull() )
			{
				QDomElement	eleLive		= nodeLive.toElement();
				if ( !nodeLive.isElement() || eleLive.isNull() || eleLive.tagName() != "Live" )
				{
					nodeLive	= nodeLive.nextSibling();
					continue;
				}
				if ( eleLive.attribute( "Date" ).toUInt() == pItem->data().toUInt() )
				{
					eleSave.removeChild( eleLive );
					break;
				}
				nodeLive	= nodeLive.nextSibling();
			}
			pModel->removeRow( selInd.row() );
		}
	}
}

void DlgEncoderSetting::OnAcceditDone( BOOL bSuccess, const QString& szErrStr  )
{
	if ( bSuccess )
	{
		FLOAT	fLocalDays	= RDLive_GetAccreditDays( eAccreditLocalSave );
		FLOAT	fRtmpDays	= RDLive_GetAccreditDays( eAccreditRtmpLive );
		FLOAT	fCloudDays	= RDLive_GetAccreditDays( eAccreditCloudLive );

		QString	szTilte	= QFU( L"授权剩余 %1 天" ).arg( fLocalDays, 0, 'f', 1 );
		ui.labAcceditLocalDays->setText( szTilte );

		szTilte	= QFU( L"RTMP 授权剩余 RTMP %1 天\nCloud 授权剩余 %2 天" ).arg( fRtmpDays, 0, 'f', 1 ).arg( fCloudDays, 0, 'f', 1 );
		ui.labAcceditLiveDays->setText( szTilte );

		ui.gboxSaveToFile->setEnabled( true );
		ui.gboxLiveToNet->setEnabled( true );
	}
	else
	{
		ui.labAcceditLocalDays->setText( QFU( L"授权失败：%1").arg( szErrStr ) );
		ui.labAcceditLiveDays->setText( QFU( L"授权失败：%1").arg( szErrStr ) );
		ui.gboxSaveToFile->setEnabled( false );
		ui.gboxLiveToNet->setEnabled( false );
		ui.gboxSaveToFile->setChecked( false );
		ui.gboxLiveToNet->setChecked( false );
	}
}
