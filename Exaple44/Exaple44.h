// Exaple44.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExaple44App:
// See Exaple44.cpp for the implementation of this class
//

class CExaple44App : public CWinApp
{
public:
	CExaple44App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
public:
	CString GetTiming(void);
};

extern CExaple44App theApp;