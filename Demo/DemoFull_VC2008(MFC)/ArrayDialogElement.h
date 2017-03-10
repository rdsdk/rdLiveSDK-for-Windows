#pragma once
#include "afxtempl.h"
#include "DialogElement.h"

class CArrayDialogElement 
{
public:
	CArrayDialogElement(void);
	~CArrayDialogElement(void);

	CArray< CDialogElement * > m_ArrayElement;

	void AddDialogElement( CDialogElement * dialogElement );
	void DeleteDoalogElment( CDialogElement * dialogElement );
	void AdjustSequence( int shLVal , int shHVal);
};
