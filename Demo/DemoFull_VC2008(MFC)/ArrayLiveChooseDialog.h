#pragma once
#include "LiveChooseDialog.h"
class ArrayLiveChooseDialog
{
public:
	ArrayLiveChooseDialog(void);
	~ArrayLiveChooseDialog(void);


	CArray< CLiveChooseDialog * > m_ArrayElement;

	void AddDialogElement( CLiveChooseDialog * dialogElement );
	void DeleteDoalogElment( CLiveChooseDialog * dialogElement );
	void AdjustSequence( int shLVal , int shHVal);
};
