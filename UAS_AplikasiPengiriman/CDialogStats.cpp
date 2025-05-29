// CDialogStats.cpp : implementation file
//

#include "pch.h"
#include "UAS_AplikasiPengiriman.h"
#include "afxdialogex.h"
#include "CDialogStats.h"
#include "ChartCtrl.h"

// CDialogStats dialog

IMPLEMENT_DYNAMIC(CDialogStats, CDialogEx)

CDialogStats::CDialogStats(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STATS, pParent)
{

}

CDialogStats::~CDialogStats()
{
}

void CDialogStats::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogStats, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CDialogStats::OnBnClickedButtonBack)
END_MESSAGE_MAP()


// CDialogStats message handlers

void CDialogStats::OnBnClickedButtonBack()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDOK);
}
