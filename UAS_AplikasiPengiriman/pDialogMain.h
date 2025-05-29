#pragma once
#include "afxdialogex.h"


// pDialogMain dialog

class pDialogMain : public CDialogEx
{
	DECLARE_DYNAMIC(pDialogMain)

public:
	pDialogMain(CWnd* pParent = nullptr);   // standard constructor
	virtual ~pDialogMain();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UAS_APLIKASIPENGIRIMAN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
