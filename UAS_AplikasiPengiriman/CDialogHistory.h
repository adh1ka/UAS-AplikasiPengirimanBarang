#pragma once
#include "afxdialogex.h"


// CDialogHistory dialog

class CDialogHistory : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogHistory)

public:
	CDialogHistory(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogHistory();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBack();
	CEdit m_editResi;
	CEdit m_editOut;
	void CariRiwayat(const CString& kodeResi);
	afx_msg void OnClickedButtonSearch();
	afx_msg void OnClickedButtonSave();
};
