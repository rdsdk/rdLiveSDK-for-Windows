// VideoDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "VideoDialog.h"
#include "RDLiveSdkDemoDlg.h"

// VideoDialog 对话框

IMPLEMENT_DYNAMIC(VideoDialog, CDialog)

VideoDialog::VideoDialog(CWnd* pParent /*=NULL*/)
: CDialog(VideoDialog::IDD, pParent)
{
	m_spinintBite;
	m_iEncoderIndex= -1;
}

VideoDialog::~VideoDialog()
{
}

void VideoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(VideoDialog, CDialog)
	ON_WM_SIZE()
	ON_CBN_SELENDOK(IDC_ENCODER_COMBOX_ENCODE, &VideoDialog::OnCbnSelendokEncoderComboxEncode)
	ON_CBN_DROPDOWN(IDC_ENCODER_COMBOX_ENCODE, &VideoDialog::OnCbnDropdownEncoderComboxEncode)
	ON_CBN_SELENDOK(IDC_RATE_MODEL_COMBOX_RATE_MODEL, &VideoDialog::OnCbnSelendokRateModelComboxRateModel)
	ON_CBN_SELENDOK(IDC_QUELITY_REFERENCE_COMBOX_QUALITY, &VideoDialog::OnCbnSelendokQuelityReferenceComboxQuality)
END_MESSAGE_MAP()

void VideoDialog::OnSize( UINT nType, int cx, int cy )
{


}


// VideoDialog 消息处理程序

void VideoDialog::OnDeltaposBitrateSpinBite(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	if(pNMUpDown->iDelta>0)  
	{  
		pNMUpDown->iPos--;  
	}  
	if(pNMUpDown->iDelta<0)  
	{  
		pNMUpDown->iPos++;  
	}  
	m_spinintBite = pNMUpDown->iPos;  
	UpdateData(false);  
}

void VideoDialog::OnCbnSelendokEncoderComboxEncode()
{
	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_ENCODER_COMBOX_ENCODE);
	int iSelectedIndexing = comboBox->GetCurSel();
	SetQualityComboBox(iSelectedIndexing);
	// TODO: 在此添加控件通知处理程序代码
}

void VideoDialog::OnCbnDropdownEncoderComboxEncode()
{
	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_ENCODER_COMBOX_ENCODE);
	comboBox->ResetContent();
	if ( Encoder_IsUsable( VE_X264, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[0]) );
	if ( Encoder_IsUsable( VE_CUDA, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[1]) );
	if ( Encoder_IsUsable( VE_NVENC, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[2]) );
	if ( Encoder_IsUsable( VE_INTEL, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[3]) );
	comboBox->SetCurSel(0);

	// TODO: 在此添加控件通知处理程序代码
}

void VideoDialog::Init()
{
	//编码器
	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_ENCODER_COMBOX_ENCODE);
	comboBox->ResetContent();
	if ( Encoder_IsUsable( VE_X264, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[0]) );
	if ( Encoder_IsUsable( VE_CUDA, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[1]) );
	if ( Encoder_IsUsable( VE_NVENC, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[2]) );
	if ( Encoder_IsUsable( VE_INTEL, NULL, NULL, NULL ) )	comboBox->AddString( CString(video_encoder_names[3]) );
	//m_iEncoderIndex = 0;
	CString ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/@Enc"));

	comboBox->SetCurSel(_wtoi(ComboBoxValue));
	//质量参考
	SetQualityComboBox(comboBox->GetCurSel());
	LPWSTR  Perset = OLESTR("/Option/Encoder/Video/x264/@Perset");
	switch( comboBox->GetCurSel() )
	{
	case 0:
		Perset = OLESTR("/Option/Encoder/Video/x264/@Perset");
		break;
	case 1:
		Perset = OLESTR("/Option/Encoder/Video/nvcuda/@Perset");
		break;
	case 2:
		Perset = OLESTR("/Option/Encoder/Video/nvenc/@Perset");
		break;
	case 3:
		Perset = OLESTR("/Option/Encoder/Video/intel/@Perset");
		break;
	}
	ComboBoxValue = Getattrib(Perset);
	comboBox =  (CComboBox*)GetDlgItem(IDC_QUELITY_REFERENCE_COMBOX_QUALITY);
	comboBox->SetCurSel(_wtoi(ComboBoxValue));
	Encoder_SetPreset( Encoder_GetCurrent(), EVideoPreset(_wtoi(ComboBoxValue)) );
	//码率模式
	comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
	comboBox->AddString(L"ABR(平均码率)");
	comboBox->AddString(L"VBR(可变码率)");
	comboBox->AddString(L"CBR(固定码率)");
	comboBox->AddString(L"CQP(恒定质量)");
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/Bitrate/@RMode"));
	comboBox->SetCurSel(_wtoi(ComboBoxValue));
	EVideoRateMode	eRateMode	= (EVideoRateMode)_wtoi(ComboBoxValue);

	//码率
	m_BitRateSpinButton = AddSpinButton( 10000,200 ,60, IDC_BITRATE_TEXT_BitRate, 200 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Bitrate"));
	int iBitrate = _wtoi(ComboBoxValue);
	if ( iBitrate < 200 )
	{
		iBitrate = 1000;
	}
	m_BitRateSpinButton->SetCurrentNumber(iBitrate);
	//最大码率 IDC_MAXIMUM_RATE_TEXT
	m_MaximumSpinButton = AddSpinButton( 10000,0 ,135, IDC_MAXIMUM_RATE_TEXT, 200 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Max"));
	int iMAXBitrate = _wtoi(ComboBoxValue);
	if ( iMAXBitrate <= 0 )
	{
		iMAXBitrate = 1000;
	}
	m_MaximumSpinButton->SetCurrentNumber(iMAXBitrate);
	//VBV码率  IDC_VBV_RATE_TEXT
	m_VBVSpinButton = AddSpinButton( 10000,0 ,165, IDC_VBV_RATE_TEXT, 200 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Vbv"));
	int iVBVBitrate = _wtoi(ComboBoxValue);
	if ( iVBVBitrate <= 0 )
	{
		iVBVBitrate = 1000;
	}
	m_VBVSpinButton->SetCurrentNumber(iVBVBitrate);

	if ( eRateMode == VR_VariableBitrate || eRateMode == VR_ConstantQP )
	{
		m_MaximumSpinButton->SetEndleWindows( true );
		m_VBVSpinButton->SetEndleWindows( true );
	}
	else
	{
		m_MaximumSpinButton->SetEndleWindows( FALSE );
		m_VBVSpinButton->SetEndleWindows( FALSE );
	}
	//IDR 间隔 IDC_IDR_INTERVAL_TEXT
	m_IDRSpinButton = AddSpinButton( 6000,0 ,230, IDC_IDR_INTERVAL_TEXT, 1 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/FrameParams/@Gop"));
	int iGopBitrate = _wtoi(ComboBoxValue);
	m_IDRSpinButton->SetCurrentNumber(iGopBitrate);
	//IDC_I_FPS_INTERVAL_TEXT I帧间隔
	m_I_Fps_SpinButton = AddSpinButton( 6000,0 ,260, IDC_I_FPS_INTERVAL_TEXT, 1 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/FrameParams/@GopMin"));
	int iI_FPS_Bitrate = _wtoi(ComboBoxValue);
	m_I_Fps_SpinButton->SetCurrentNumber(iI_FPS_Bitrate);
	//IDC_REF_QUOTE_TEXT Ref 引用
	m_Ref_Quote_SpinButton = AddSpinButton( 16,0 ,290, IDC_REF_QUOTE_TEXT, 1 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/FrameParams/@Ref"));
	int iRef_Bitrate = _wtoi(ComboBoxValue);
	m_Ref_Quote_SpinButton->SetCurrentNumber(iRef_Bitrate);
	//IDC_B_FPS_INTERVAL_TEXT B帧间隔
	m_B_Fps_SpinButton = AddSpinButton( 8,0 ,320, IDC_B_FPS_INTERVAL_TEXT, 1 );
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Video/FrameParams/@BFrame"));
	int iB_Fps_Bitrate = _wtoi(ComboBoxValue);
	m_B_Fps_SpinButton->SetCurrentNumber(iB_Fps_Bitrate);

	Encoder_SetBitrate( eRateMode,
		iBitrate,
		iMAXBitrate,
		iVBVBitrate );
	Encoder_SetFrameParams( iGopBitrate,
		iI_FPS_Bitrate,
		iRef_Bitrate,
		iB_Fps_Bitrate );
}

void VideoDialog::SetQualityComboBox( int index )
{
	if ( index >= 0 )
	{
		EVideoEncoder	eEncoder	= (EVideoEncoder)index;
		if ( index == m_iEncoderIndex )
		{
			return;
		}
		else
		{
			m_iEncoderIndex = index;	
		}
		DWORD dwSupportProfileMask, dwSupportPresetMask, dwSupportColorSpaceMask;
		if ( Encoder_IsUsable( eEncoder, &dwSupportProfileMask, &dwSupportPresetMask, &dwSupportColorSpaceMask ) )
		{

			Encoder_SetCurrent( eEncoder );
			{
				CString str;
				str.Format(L"%d",m_iEncoderIndex);
				if( ! Settattrib(OLESTR("/Option/Encoder/Video/@Enc"),str  ) )
				{ 
					Creatattrib(OLESTR("/Option/Encoder/Video"),OLESTR("Enc"),str);
				}
			}
			/*QDomElement		eleVideo	= FindXmlElement( "Encoder/Video", TRUE );
			eleVideo.setAttribute( "Enc", int( eEncoder ) );*/

			EVideoPreset	ePreset	= Encoder_GetPreset( eEncoder );
			CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_QUELITY_REFERENCE_COMBOX_QUALITY);
			comboBox->ResetContent();

			switch( eEncoder )
			{
			case VE_X264:
				for ( int i = 0; i <= VP_x264_Placebo; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						comboBox->AddString( CString(video_preset_x264_names[i]) );
					}
				}

				break;
			case VE_CUDA:
				for ( int i = 0; i <= VP_Cuda_FlipCam; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						comboBox->AddString( CString(video_preset_cuda_names[i]) );
					}
				}
				break;
			case VE_NVENC:
				for ( int i = 0; i <= VP_Nvenc_LosslessHP; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						comboBox->AddString( CString(video_preset_nvenc_names[i]) );
					}
				}
				break;
			case VE_INTEL:
				for ( int i = 0; i <= VP_Intel_Quality; ++i )
				{
					if ( dwSupportPresetMask & ( 1 << i ) )
					{
						comboBox->AddString( CString(video_preset_intel_names[i]) );
					}
				}
				break;
			}
			comboBox->SetCurSel(0);
			Encoder_SetPreset( Encoder_GetCurrent(), EVideoPreset(0) );
		}
	}
}

void VideoDialog::OnCbnSelendokRateModelComboxRateModel()
{
	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
	int index = comboBox->GetCurSel();
	if ( index >= 0 )
	{
		EVideoRateMode	eRateMode	= (EVideoRateMode)index;
		if ( eRateMode == VR_VariableBitrate || eRateMode == VR_ConstantQP )
		{
			m_MaximumSpinButton->SetEndleWindows( true );
			m_VBVSpinButton->SetEndleWindows( true );
		}
		else
		{
			m_MaximumSpinButton->SetEndleWindows( FALSE );
			m_VBVSpinButton->SetEndleWindows( FALSE );
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}

void VideoDialog::OnCbnSelendokQuelityReferenceComboxQuality()
{
	int index = ((CComboBox*)GetDlgItem(IDC_QUELITY_REFERENCE_COMBOX_QUALITY))->GetCurSel();
	if ( index >= 0 )
	{
		EVideoEncoder	eEncoder	= Encoder_GetCurrent();
		EVideoPreset	ePreset		= (EVideoPreset)index;
		Encoder_SetPreset( Encoder_GetCurrent(), ePreset );

		/*QDomElement		eleEnc	= FindXmlElement( QString( "Encoder/Video/" ) + video_encoder_names[eEncoder], TRUE );
		if ( !eleEnc.isNull() )
		{
			eleEnc.setAttribute( "Perset", ePreset );
		}*/
	}
	// TODO: 在此添加控件通知处理程序代码
}

CSpinBox * VideoDialog::AddSpinButton( int MaxNumber, int MinNumber, int top, UINT uID, int spinNumber )
{
	CSpinBox * spinBox = NULL;
	CRect rc;
	CRect MOVE_rc;
	int width = 0;
	int height = 0;
	spinBox = new CSpinBox(this);
	spinBox->Create(IDD_DIALOG_Spin_Text,this);
	spinBox->Init(MaxNumber,MinNumber,spinNumber);
	GetDlgItem(uID)->GetClientRect(rc);
	spinBox->GetClientRect(MOVE_rc);
	width = MOVE_rc.Width();
	height = MOVE_rc.Height();
	MOVE_rc.left = rc.right + 20;
	MOVE_rc.right  = MOVE_rc.left + width;
	MOVE_rc.top = top;
	MOVE_rc.bottom = MOVE_rc.top + height;

	spinBox->ShowWindow(SW_SHOW);
	spinBox->MoveWindow(MOVE_rc);

	return spinBox;
}

void VideoDialog::SaveProfile()
{
	CComboBox * comboBox = NULL;
	// RMode
	{
		CString str;
		comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
		str.Format(L"%d",comboBox->GetCurSel());
		if( ! Settattrib(OLESTR("/Option/Encoder/Video/Bitrate/@RMode") ,str  ) )
		{ 
			if( !Creatattrib(OLESTR("/Option/Encoder/Video/Bitrate"),OLESTR("RMode"),str) )
			{
				CComPtr<MSXML2::IXMLDOMElement> spRootEle;
				( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
				CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNode= NULL; 
				pXMLNodeNode = spRootEle->selectSingleNode(OLESTR("/Option/Encoder/Video"));
				if ( pXMLNodeNode != NULL )
				{
					CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNodeChip= NULL; 
					pXMLNodeNodeChip = pXMLNodeNode->appendChild(( CDemoRdLiveDlg::Instance().m_sOptionDoc )->createElement(_T("Bitrate")));
					Creatattrib(OLESTR("/Option/Encoder/Video/Bitrate"),OLESTR("RMode"),str);
				}
			}
		}
	}
	// Bitrate
	{
		CString str;
		str.Format(L"%d",m_BitRateSpinButton->m_iRealDataNumber);
		if( ! Settattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Bitrate") ,str  ) )
		{ 
			Creatattrib(OLESTR("/Option/Encoder/Video/Bitrate"),OLESTR("Bitrate"),str);
		}
	}
	// Max
	{
		CString str;
		str.Format(L"%d",m_MaximumSpinButton->m_iRealDataNumber);
		if( ! Settattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Max") ,str  ) )
		{ 
			Creatattrib(OLESTR("/Option/Encoder/Video/Bitrate"),OLESTR("Max"),str);
		}
	}
	// Vbv
	{
		CString str;
		str.Format(L"%d",m_VBVSpinButton->m_iRealDataNumber);
			if( ! Settattrib(OLESTR("/Option/Encoder/Video/Bitrate/@Vbv") ,str  ) )
			{ 
				Creatattrib(OLESTR("/Option/Encoder/Video/Bitrate"),OLESTR("Vbv"),str);
			}
	}
	comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
	Encoder_SetBitrate( (EVideoRateMode)comboBox->GetCurSel(),
		m_BitRateSpinButton->m_iRealDataNumber,
		m_MaximumSpinButton->m_iRealDataNumber,
		m_VBVSpinButton->m_iRealDataNumber);

	//与编码帧有关的设置
	// Gop OLESTR("/Option/Encoder/Video/FrameParams/@Gop")
	{
		CString str;
		comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
		str.Format(L"%d",m_IDRSpinButton->m_iRealDataNumber);
			if( ! Settattrib(OLESTR("/Option/Encoder/Video/FrameParams/@Gop") ,str  ) )
			{ 
				if( !Creatattrib(OLESTR("/Option/Encoder/Video/FrameParams"),OLESTR("Gop"),str) )
				{
					CComPtr<MSXML2::IXMLDOMElement> spRootEle;
					( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
					CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNode= NULL; 
					pXMLNodeNode = spRootEle->selectSingleNode(OLESTR("/Option/Encoder/Video"));
					if ( pXMLNodeNode != NULL )
					{
						CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNodeChip= NULL; 
						pXMLNodeNodeChip = pXMLNodeNode->appendChild(( CDemoRdLiveDlg::Instance().m_sOptionDoc )->createElement(_T("FrameParams")));
						Creatattrib(OLESTR("/Option/Encoder/Video/FrameParams"),OLESTR("Gop"),str);
					}
				}
			}
	}
	// GopMin
	{
		CString str;
		str.Format(L"%d",m_I_Fps_SpinButton->m_iRealDataNumber);
			if( ! Settattrib(OLESTR("/Option/Encoder/Video/FrameParams/@GopMin"),str  ) )
			{ 
				Creatattrib(OLESTR("/Option/Encoder/Video/FrameParams"),OLESTR("GopMin"),str);
			}
	}
	//Ref
	{
		CString str;
		str.Format(L"%d",m_Ref_Quote_SpinButton->m_iRealDataNumber);
			if( ! Settattrib(OLESTR("/Option/Encoder/Video/FrameParams/@Ref") ,str  ) )
			{ 
				Creatattrib(OLESTR("/Option/Encoder/Video/FrameParams"),OLESTR("Ref"),str);
			}
	}
	//BFrame
	{
		CString str;
		str.Format(L"%d",m_B_Fps_SpinButton->m_iRealDataNumber);
			if( ! Settattrib(OLESTR("/Option/Encoder/Video/FrameParams/@BFrame") ,str  ) )
			{ 
				Creatattrib(OLESTR("/Option/Encoder/Video/FrameParams"),OLESTR("BFrame"),str);
			}
	}

	Encoder_SetFrameParams( m_IDRSpinButton->m_iRealDataNumber,
		m_I_Fps_SpinButton->m_iRealDataNumber,
		m_Ref_Quote_SpinButton->m_iRealDataNumber,
		m_B_Fps_SpinButton->m_iRealDataNumber);
}
