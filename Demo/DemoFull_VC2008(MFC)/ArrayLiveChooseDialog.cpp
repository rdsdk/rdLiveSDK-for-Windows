#include "StdAfx.h"
#include "ArrayLiveChooseDialog.h"

ArrayLiveChooseDialog::ArrayLiveChooseDialog(void)
{
}

ArrayLiveChooseDialog::~ArrayLiveChooseDialog(void)
{
}

void ArrayLiveChooseDialog::AddDialogElement( CLiveChooseDialog * dialogElement )
{
	if ( dialogElement == NULL )
	{
		return;
	}
	int ElementCount = m_ArrayElement.GetSize();

	for ( int i = 0; i <  ElementCount; i++)
	{
		m_ArrayElement.GetAt(i)->m_cy +=  25;
	}

	dialogElement->m_cy = 0;
	m_ArrayElement.Add(dialogElement);
}

void ArrayLiveChooseDialog::DeleteDoalogElment( CLiveChooseDialog * dialogElement )
{
	if ( (m_ArrayElement.GetSize() < 1) || ( dialogElement == NULL )  )
	{
		return;
	}
	int ElementCount = m_ArrayElement.GetSize();

	int iCount = -1;
	for ( int i = 0; i < ElementCount; i++ )
	{
		if ( m_ArrayElement.GetAt(i)->m_StrDisName == dialogElement->m_StrDisName )
		{
			iCount = i;
			break;
		} 
		else
		{
			m_ArrayElement.GetAt(i)->m_cy -= 25;
		}
	}
	m_ArrayElement.RemoveAt(iCount);
	dialogElement->SetParent(NULL);
	dialogElement->ShowWindow(HIDE_WINDOW);
	dialogElement->DestroyWindow();
	delete dialogElement;
}

void ArrayLiveChooseDialog::AdjustSequence( int shLVal , int shHVal )
{
	CLiveChooseDialog * DialongElementold = m_ArrayElement[shLVal];
	CLiveChooseDialog * DialongElementNew = m_ArrayElement[shHVal];
	int iCy = DialongElementold->m_cy;

	DialongElementold->m_cy = DialongElementNew->m_cy;
	DialongElementNew->m_cy = iCy;

	m_ArrayElement[shLVal] = DialongElementNew;
	m_ArrayElement[shHVal] = DialongElementold;
}
