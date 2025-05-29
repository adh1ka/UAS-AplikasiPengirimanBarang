#pragma once
#include "afxdialogex.h"
#include <map>

// CDialogEstimasi dialog


class CDialogEstimasi : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogEstimasi)

public:
	CDialogEstimasi(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogEstimasi();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ESTIMASI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void LoadEstimasiFromFile(CString fileName);
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();

public:
	CComboBox m_comboAsal;
	CComboBox m_comboTujuan;
	CStatic m_staticOut;
	afx_msg void OnBnClickedButtonHitung();
	std::map<CString, int> estimasiMap;
	afx_msg void OnBnClickedButtonBack();
};
