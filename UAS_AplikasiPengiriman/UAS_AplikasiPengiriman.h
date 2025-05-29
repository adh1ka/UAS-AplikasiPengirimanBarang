
// UAS_AplikasiPengiriman.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CUASAplikasiPengirimanApp:
// See UAS_AplikasiPengiriman.cpp for the implementation of this class
//

class CUASAplikasiPengirimanApp : public CWinApp
{
public:
	CUASAplikasiPengirimanApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CUASAplikasiPengirimanApp theApp;
