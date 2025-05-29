#pragma once
#include "afxdialogex.h"
#include "ChartCtrl.h"
#include "pch.h"

// CDialogStats dialog

class CDialogStats : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogStats)

public:
	CDialogStats(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogStats();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STATS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBack();
};
