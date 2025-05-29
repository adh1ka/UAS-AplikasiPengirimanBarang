#pragma once

#include <vector>
#include <string>
#include <afxwin.h>
#include <afxext.h>

class CChartCtrl : public CStatic
{
public:
    CChartCtrl();
    virtual ~CChartCtrl();

    void SetData(const std::vector<CString>& labels, const std::vector<int>& values);
    void SetTitle(const CString& title);

protected:
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()

private:
    CString m_title;
    std::vector<CString> m_labels;
    std::vector<int> m_values;
};
