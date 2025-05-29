// CDialogEstimasi.cpp : implementation file
//

#include "pch.h"
#include "UAS_AplikasiPengiriman.h"
#include "afxdialogex.h"
#include "CDialogEstimasi.h"
#include <fstream>
#include <sstream>
#include <string>
#include <map>


// CDialogEstimasi dialog

IMPLEMENT_DYNAMIC(CDialogEstimasi, CDialogEx)

CDialogEstimasi::CDialogEstimasi(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ESTIMASI, pParent)
{

}

CDialogEstimasi::~CDialogEstimasi()
{
}

BOOL CDialogEstimasi::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CStringArray kotaArray;
    kotaArray.Add(_T("Jakarta"));
    kotaArray.Add(_T("Bandung"));
    kotaArray.Add(_T("Surabaya"));
    kotaArray.Add(_T("Yogyakarta"));
    kotaArray.Add(_T("Malang"));


    for (int i = 0; i < kotaArray.GetSize(); ++i) {
        m_comboAsal.AddString(kotaArray[i]);
        m_comboTujuan.AddString(kotaArray[i]);
    }

    LoadEstimasiFromFile(_T("EstimasiKota.txt"));

    return TRUE;
}

void CDialogEstimasi::LoadEstimasiFromFile(CString fileName)
{
    std::ifstream file(CT2A(fileName, CP_UTF8)); // aman untuk UNICODE
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string kota1, kota2, hariStr;

        std::getline(ss, kota1, ',');
        std::getline(ss, kota2, ',');
        std::getline(ss, hariStr, ',');

        // Ubah ke CString
        CString csKota1(kota1.c_str()), csKota2(kota2.c_str());
        CString key;
        if (csKota1 < csKota2)
            key.Format(_T("%s-%s"), csKota1, csKota2);
        else
            key.Format(_T("%s-%s"), csKota2, csKota1);

        estimasiMap[key] = atoi(hariStr.c_str());
    }

   ///* std::ifstream file(CT2A(fileName));
   // std::string line;

   // while (std::getline(file, line)) {
   //     std::istringstream ss(line);
   //     std::string kota1, kota2, hariStr;

   //     std::getline(ss, kota1, ',');
   //     std::getline(ss, kota2, ',');
   //     std::getline(ss, hariStr, ',');

   //     CString key;
   //     CString csKota1(kota1.c_str()), csKota2(kota2.c_str());
   //     if (csKota1 < csKota2)
   //         key.Format(_T("%s-%s"), csKota1, csKota2);
   //     else
   //         key.Format(_T("%s-%s"), csKota2, csKota1);

   //     estimasiMap[key] = atoi(hariStr.c_str());
   // }
   // */
}

void CDialogEstimasi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_ASAL, m_comboAsal);
	DDX_Control(pDX, IDC_COMBO_TUJUAN, m_comboTujuan);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, m_staticOut);
}


BEGIN_MESSAGE_MAP(CDialogEstimasi, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_HITUNG, &CDialogEstimasi::OnBnClickedButtonHitung)
    ON_BN_CLICKED(IDC_BUTTON_BACK, &CDialogEstimasi::OnBnClickedButtonBack)
END_MESSAGE_MAP()


// CDialogEstimasi message handlers

//void CDialogEstimasi::OnBnClickedButton2()
//{
//	// TODO: Add your control notification handler code here
//}

void CDialogEstimasi::OnBnClickedButtonHitung()
{
    // TODO: Add your control notification handler code here
    CString asal, tujuan;
    m_comboAsal.GetWindowText(asal);
    m_comboTujuan.GetWindowText(tujuan);

    if (asal.IsEmpty() || tujuan.IsEmpty()) {
        m_staticOut.SetWindowText(_T("Pilih kota asal dan tujuan."));
        return;
    }

    if (asal == tujuan) {
        m_staticOut.SetWindowText(_T("Kota asal dan tujuan tidak boleh sama."));
        return;
    }

    CString key;
    if (asal < tujuan)
        key.Format(_T("%s-%s"), asal, tujuan);
    else
        key.Format(_T("%s-%s"), tujuan, asal);

    auto it = estimasiMap.find(key);
    if (it != estimasiMap.end()) {
        CString hasil;
        hasil.Format(_T("Estimasi Dari %s ke %s adalah %d hari"), asal, tujuan, it->second);
        m_staticOut.SetWindowText(hasil);
    }
    else {
        m_staticOut.SetWindowText(_T("Estimasi untuk rute ini belum tersedia."));
    }
}

void CDialogEstimasi::OnBnClickedButtonBack()
{
    // TODO: Add your control notification handler code here
    EndDialog(IDOK);
}
