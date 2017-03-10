#include "StdAfx.h"
#include "ArrayDialogElement.h"

CArrayDialogElement::CArrayDialogElement(void)
{
}

CArrayDialogElement::~CArrayDialogElement(void)
{
}

void CArrayDialogElement::AddDialogElement( CDialogElement * dialogElement )
{
	if ( dialogElement == NULL )
	{
		return;
	}
	int ElementCount = m_ArrayElement.GetSize();
	
	for ( int i = 0; i <  ElementCount; i++)
	{
		m_ArrayElement.GetAt(i)->m_cy +=  70;
	}

	dialogElement->m_cy = 0;
	m_ArrayElement.Add(dialogElement);
}

void CArrayDialogElement::DeleteDoalogElment( CDialogElement * dialogElement )
{
	if ( (m_ArrayElement.GetSize() < 1) || ( dialogElement == NULL )  )
	{
		return;
	}
	int ElementCount = m_ArrayElement.GetSize();

	int iCount = -1;
	for ( int i = 0; i < ElementCount; i++ )
	{
		if ( m_ArrayElement.GetAt(i)->m_HChip == dialogElement->m_HChip )
		{
			iCount = i;
			break;
		} 
		else
		{
			m_ArrayElement.GetAt(i)->m_cy -= 70;
		}
	}
	m_ArrayElement.RemoveAt(iCount);
	dialogElement->SetParent(NULL);
	dialogElement->ShowWindow(HIDE_WINDOW);
	dialogElement->DestroyWindow();
	delete dialogElement;
}

void CArrayDialogElement::AdjustSequence( int shLVal , int shHVal)
{
	CDialogElement * DialongElementold = m_ArrayElement[shLVal];
	CDialogElement * DialongElementNew = m_ArrayElement[shHVal];
	int iCy = DialongElementold->m_cy;

	DialongElementold->m_cy = DialongElementNew->m_cy;
	DialongElementNew->m_cy = iCy;

	m_ArrayElement[shLVal] = DialongElementNew;
	m_ArrayElement[shHVal] = DialongElementold;
}
