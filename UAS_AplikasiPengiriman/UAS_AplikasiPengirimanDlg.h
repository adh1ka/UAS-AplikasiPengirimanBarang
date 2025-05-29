
// UAS_AplikasiPengirimanDlg.h : header file
//

#pragma once


// CUASAplikasiPengirimanDlg dialog
class CUASAplikasiPengirimanDlg : public CDialogEx
{
// Construction
public:
	CUASAplikasiPengirimanDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UAS_APLIKASIPENGIRIMAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStats();
	afx_msg void OnBnClickedButtonEstimasi();
	afx_msg void OnBnClickedButtonHistory();
	afx_msg void OnBnClickedCancel();
};
