// CDialogHistory.cpp : implementation file
//

#include "pch.h"
#include "UAS_AplikasiPengiriman.h"
#include "afxdialogex.h"
#include "CDialogHistory.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// CDialogHistory dialog

IMPLEMENT_DYNAMIC(CDialogHistory, CDialogEx)

CDialogHistory::CDialogHistory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HISTORY, pParent)
{

}

CDialogHistory::~CDialogHistory()
{
}

void CDialogHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RESI, m_editResi);
	DDX_Control(pDX, IDC_EDIT_OUTPUT, m_editOut);
}


BEGIN_MESSAGE_MAP(CDialogHistory, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CDialogHistory::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CDialogHistory::OnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDialogHistory::OnClickedButtonSave)
END_MESSAGE_MAP()


// CDialogHistory message handlers

void CDialogHistory::OnBnClickedButtonBack()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDOK);
}

void CDialogHistory::CariRiwayat(const CString& kodeResi)
{
	std::ifstream file("RiwayatPengiriman.txt");
	std::string line;
	CString hasil = _T("Data tidak ditemukan.");

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(ss, token, '|')) {
			tokens.push_back(token);
		}

		if (tokens.size() >= 6 && CString(tokens[0].c_str()).CompareNoCase(kodeResi) == 0) {
			hasil.Format(_T("Kode: %s\r\nAsal: %s\r\nTujuan: %s\r\nTanggal: %s\r\nStatus: %s\r\nPosisi: %s"),
				CString(tokens[0].c_str()),
				CString(tokens[1].c_str()),
				CString(tokens[2].c_str()),
				CString(tokens[3].c_str()),
				CString(tokens[4].c_str()),
				CString(tokens[5].c_str()));
			break;
		}
	}

	m_editOut.SetWindowText(hasil);
}

void CDialogHistory::OnClickedButtonSearch()
{
	// TODO: Add your control notification handler code here
	CString kodeResi;
	m_editResi.GetWindowText(kodeResi);

	kodeResi.Trim();

	if (kodeResi.IsEmpty()) {
		MessageBox(_T("Kode resi tidak boleh kosong."), _T("Error"), MB_ICONERROR);
		return;
	}

	if (kodeResi.GetLength() != 10) {
		MessageBox(_T("Kode resi harus terdiri dari 10 karakter."), _T("Format Salah"), MB_ICONERROR);
		return;
	}

	CariRiwayat(kodeResi);
}

void CDialogHistory::OnClickedButtonSave()
{
	CString hasil, kodeResi;
	m_editOut.GetWindowText(hasil);
	m_editResi.GetWindowText(kodeResi);

	hasil.Trim();
	kodeResi.Trim();

	if (kodeResi.IsEmpty()) {
		MessageBox(_T("Kode resi tidak boleh kosong."), _T("Error"), MB_ICONERROR);
		return;
	}

	if (hasil.IsEmpty()) {
		MessageBox(_T("Tidak ada data untuk disimpan."), _T("Peringatan"), MB_ICONWARNING);
		return;
	}

	if (kodeResi.FindOneOf(_T("\\/:*?\"<>|")) != -1) {
		MessageBox(_T("Kode resi mengandung karakter yang tidak diperbolehkan dalam nama file."), _T("Error"), MB_ICONERROR);
		return;
	}

	CString fileName;
	fileName.Format(_T("%s.txt"), kodeResi);

	CStdioFile file;
	if (file.Open(fileName, CFile::modeCreate | CFile::modeWrite | CFile::typeText)) {
		file.WriteString(hasil);
		file.Close();
		CString msg;
		msg.Format(_T("Data berhasil disimpan ke file %s"), fileName);
		MessageBox(msg, _T("Berhasil"), MB_ICONINFORMATION);
	}
	else {
		MessageBox(_T("Gagal menyimpan file."), _T("Error"), MB_ICONERROR);
	}
}
