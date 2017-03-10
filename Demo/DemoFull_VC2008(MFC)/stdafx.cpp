
// stdafx.cpp : 只包括标准包含文件的源文件
// Demo_VC2008(MFC).pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
#include "RDLiveSdkDemoDlg.h"


CString Getattrib( LPWSTR szattrib , bool bIsInterface)
{
	CString szName;
	CComPtr<MSXML2::IXMLDOMElement> spRootEle;
	if( bIsInterface )
		( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
	else
		( CDemoRdLiveDlg::Instance().m_sScenes )->get_documentElement(&spRootEle);

	if ( szattrib != NULL )
	{
		CComPtr<MSXML2::IXMLDOMNode> spNode1;
		spNode1 = spRootEle->selectSingleNode(szattrib);
		if ( spNode1 == NULL )
		{
			return szName;
		}
		CComVariant VarVal;
		spNode1->get_nodeValue(&VarVal); //节点值
		szName = CString( COLE2CT(VarVal.bstrVal) );
	}
	return szName;
}

BOOL Settattrib( LPWSTR szattrib, CString szValue , bool bIsInterface )
{
	CComPtr<MSXML2::IXMLDOMElement> spRootEle;
	if( bIsInterface )
		( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
	else
		( CDemoRdLiveDlg::Instance().m_sScenes )->get_documentElement(&spRootEle);
		
	CComPtr<MSXML2::IXMLDOMNode> spNode;
	spNode = spRootEle->selectSingleNode(szattrib);
	if ( spNode != NULL )
	{
		spNode->put_nodeValue(CComVariant(szValue)); //写入value
		return TRUE;
	} 
	return FALSE;
}

BOOL Creatattrib( LPWSTR szNode, LPWSTR szattrib,CString szValue, bool bIsInterface )
{	
	CComPtr<MSXML2::IXMLDOMElement> spRootEle;
	if( bIsInterface )
		( CDemoRdLiveDlg::Instance().m_sOptionDoc )->get_documentElement(&spRootEle); //根节点
	else
		( CDemoRdLiveDlg::Instance().m_sScenes )->get_documentElement(&spRootEle);

	CComPtr<MSXML2::IXMLDOMNode> spNode;
	spNode = spRootEle->selectSingleNode(szNode);
	if ( spNode != NULL )
	{
		CComQIPtr<MSXML2::IXMLDOMElement> spEle = spNode;
		spEle->setAttribute(szattrib, CComVariant(szValue));//给新节点添加属性
		return true;
	}
	return false;
}
