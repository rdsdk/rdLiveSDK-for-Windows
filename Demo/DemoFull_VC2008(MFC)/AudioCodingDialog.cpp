// AudioCodingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RDLiveSdkDemo.h"
#include "AudioCodingDialog.h"
#include "RDLiveSdkDemoDlg.h"

// AudioCodingDialog 对话框

IMPLEMENT_DYNAMIC(AudioCodingDialog, CDialog)

AudioCodingDialog::AudioCodingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AudioCodingDialog::IDD, pParent)
{

}

AudioCodingDialog::~AudioCodingDialog()
{
}

void AudioCodingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AudioCodingDialog, CDialog)
END_MESSAGE_MAP()


// AudioCodingDialog 消息处理程序



void AudioCodingDialog::Init()
{
	
	CRect rc;
	CRect MOVE_rc;
	int width = 0;
	int height = 0;
	m_RateBitSpinButton = new CSpinBox(this);
	m_RateBitSpinButton->Create(IDD_DIALOG_Spin_Text,this);
	m_RateBitSpinButton->Init(256,16,16);
	
	GetDlgItem(IDC_STATIC_Rate_BIt)->GetClientRect(rc);
	m_RateBitSpinButton->GetClientRect(MOVE_rc);
	width = MOVE_rc.Width();
	height = MOVE_rc.Height();
	MOVE_rc.left = rc.right + 20;
	MOVE_rc.right  = MOVE_rc.left + width;
	MOVE_rc.top = 5;
	MOVE_rc.bottom = MOVE_rc.top + height;
	CString ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Bitrate"));
	int iBitrate = _wtoi(ComboBoxValue);
	if ( iBitrate < 16 )
		iBitrate = 16;

	m_RateBitSpinButton->SetCurrentNumber(iBitrate);
	m_RateBitSpinButton->ShowWindow(SW_SHOW);
	m_RateBitSpinButton->MoveWindow(MOVE_rc);


	CComPtr<MSXML2::IXMLDOMElement> spRootEle;
	( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
	CComPtr<MSXML2::IXMLDOMNodeList> sFilmList;
	sFilmList = spRootEle->selectNodes(OLESTR("/Option/Encoder/Audio/*"));

	long nLen;
	sFilmList->get_length(&nLen); //子节点数
	for ( long i  = 0;  i != nLen; i++ )
	{
		CComPtr<MSXML2::IXMLDOMNode> spNode;
		sFilmList->get_item(i, &spNode);
		CComPtr<MSXML2::IXMLDOMNamedNodeMap> spNameNodeMap;
		spNode->get_attributes(&spNameNodeMap);
		long NodeLen = 0;
		spNameNodeMap->get_length(&NodeLen);
		if ( NodeLen > 0 )
		{
			CString szCStr,szCSamp,szCBit, szCSampAudio;
			for ( long j = 0; j != NodeLen; j++ )
			{
				CComPtr<MSXML2::IXMLDOMNode> spNodeAttrib; //注意属性也是一个IXMLDOMNode
				spNameNodeMap->get_item(j, &spNodeAttrib);
				CComBSTR bsNodeName;
				spNodeAttrib->get_nodeName(&bsNodeName); //节点名
				CString name = COLE2CT(bsNodeName);
				CComVariant varVal;
				spNodeAttrib->get_nodeValue(&varVal); //节点值
				CString val = COLE2CT(varVal.bstrVal);

				if ( L"Samp" == name )
					szCSamp += val;
				else if ( L"Bit" == name )
					szCBit += val;
				else if ( L"Str" == name )
					szCStr += val;
			}
			if( szCSamp.IsEmpty() )
				continue;
			szCSampAudio += szCSamp;
			szCSampAudio += L" ";
			szCSampAudio += szCBit;
			szCSampAudio += L" ";
			szCSampAudio += szCStr;
			CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_COMBO_Audio_Sampling_rate);
			comboBox->AddString(szCSampAudio);
			comboBox->SetItemData(comboBox->GetCount() - 1,DWORD_PTR( ( _wtoi(szCBit) << 16 ) | _wtoi(szCSamp) ) );
		}
	}

	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_COMBO_Audio_Sampling_rate);
	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Audio/@Enc"));
	int iValue = _wtoi(ComboBoxValue);
	if ( iValue > comboBox->GetCount() )
		iValue = 0;

	DWORD dwValue = (DWORD)comboBox->GetItemData(iValue);
	EAudioInSamples	eSamples	= Aud_Inp_Samp_22050;
	WORD			wBits		= 16;
	eSamples	= EAudioInSamples( dwValue & 0xFFFF );
	wBits		= dwValue >> 16;
	comboBox->SetCurSel(iValue);

	ComboBoxValue = Getattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Bitrate"));
	int iChannel = _wtoi(ComboBoxValue);
	if ( iChannel <= 0 )
		iChannel = 2;

	if ( iChannel > 1 )
	{
		((CButton *)GetDlgItem(IDC_RADIO_channel_state))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_channel_single))->SetCheck(TRUE);
	} 
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO_channel_state))->SetCheck(TRUE);
		((CButton *)GetDlgItem(IDC_RADIO_channel_single))->SetCheck(FALSE);
	}
	

	Encoder_SetAudioParams( iChannel,
		eSamples,
		wBits,
		Aud_Enc_AAC,
		iBitrate );
}

void AudioCodingDialog::SaveAuido()
{
	//Enc
	CComboBox * comboBox =  (CComboBox*)GetDlgItem(IDC_COMBO_Audio_Sampling_rate);
	CString str;
	str.Format(L"%d",comboBox->GetCurSel());
	Settattrib(OLESTR("/Option/Encoder/Audio/@Enc"),str  );
	//Channel
	{
		CString str;
		//comboBox =  (CComboBox*)GetDlgItem(IDC_RATE_MODEL_COMBOX_RATE_MODEL);
		str.Format(L"%d",((CButton *)GetDlgItem(IDC_RADIO_channel_state))->GetCheck()? 2 : 1 );
		if( ! Settattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Channel") ,str  ) )
		{ 
			if( !Creatattrib(OLESTR("/Option/Encoder/Audio/AudioParam"),OLESTR("Channel"),str) )
			{
				CComPtr<MSXML2::IXMLDOMElement> spRootEle;
				( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
				CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNode= NULL; 
				pXMLNodeNode = spRootEle->selectSingleNode(OLESTR("/Option/Encoder/Audio"));
				if ( pXMLNodeNode != NULL )
				{
					CComPtr<MSXML2::IXMLDOMNode> pXMLNodeNodeChip= NULL; 
					pXMLNodeNodeChip = pXMLNodeNode->appendChild(( CDemoRdLiveDlg::Instance().m_sOptionDoc )->createElement(_T("AudioParam")));
					Creatattrib(OLESTR("/Option/Encoder/Audio/AudioParam"),OLESTR("Channel"),str);
				}
			}
		}
	}

	EAudioInSamples	eSamples	= Aud_Inp_Samp_22050;
	WORD			wBits		= 16;
	EAudioEncoder	eAudEncoder	= Aud_Enc_AAC;
	int iValue = comboBox->GetCurSel();
	if ( iValue > comboBox->GetCount() )
		iValue = 0;
	if ( iValue >= 0 )
	{
		DWORD		dwValue		= (DWORD)comboBox->GetItemData(iValue);;
		eSamples	= EAudioInSamples( dwValue & 0xFFFF );
		wBits		= dwValue >> 16;
	}

	//Sample
	{
		CString str;
		str.Format(L"%d",eSamples );
		if( ! Settattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Sample"),str  ) )
		{ 
			Creatattrib(OLESTR("/Option/Encoder/Audio/AudioParam"),OLESTR("Sample"),str);
		}
	}
	//Bits
	{
		CString str;
		str.Format(L"%d",wBits );
		if( ! Settattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Bits"),str  ) )
		{ 
			Creatattrib(OLESTR("/Option/Encoder/Audio/AudioParam"),OLESTR("Bits"),str);
		}
	}
	int iBitrate = m_RateBitSpinButton->m_iRealDataNumber;
	//Bitrate
	{
		CString str;
		str.Format(L"%d",iBitrate );
		if( ! Settattrib(OLESTR("/Option/Encoder/Audio/AudioParam/@Bitrate"),str  ) )
		{ 
			Creatattrib(OLESTR("/Option/Encoder/Audio/AudioParam"),OLESTR("Bitrate"),str);
		}
	}
	
	Encoder_SetAudioParams( ((CButton *)GetDlgItem(IDC_RADIO_channel_state))->GetCheck()? 1 : 2,
		eSamples,
		wBits,
		eAudEncoder,
		iBitrate );

}
