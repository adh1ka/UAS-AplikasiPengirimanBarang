#include "ChartCtrl.h"
#include <afxgraphics.h>
#include "pch.h"

IMPLEMENT_DYNAMIC(CChartCtrl, CStatic)

CChartCtrl::CChartCtrl()
{
}

CChartCtrl::~CChartCtrl()
{
}

BEGIN_MESSAGE_MAP(CChartCtrl, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()

void CChartCtrl::SetData(const std::vector<CString>& labels, const std::vector<int>& values)
{
    m_labels = labels;
    m_values = values;
    Invalidate(); // trigger redraw
}

void CChartCtrl::SetTitle(const CString& title)
{
    m_title = title;
    Invalidate();
}

void CChartCtrl::Clear()
{
    m_labels.clear();
    m_values.clear();
    Invalidate();
}

void CChartCtrl::OnPaint()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(&rect);

    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap bmp;
    bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
    CBitmap* pOldBmp = memDC.SelectObject(&bmp);
    memDC.FillSolidRect(&rect, RGB(255, 255, 255)); // white background

    // Draw title
    if (!m_title.IsEmpty())
    {
        CFont titleFont;
        titleFont.CreatePointFont(180, _T("Segoe UI"));
        CFont* pOldFont = memDC.SelectObject(&titleFont);
        memDC.SetTextColor(RGB(0, 0, 0));
        memDC.DrawText(m_title, &rect, DT_CENTER | DT_TOP);
        memDC.SelectObject(pOldFont);
    }

    if (m_values.empty()) {
        dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
        return;
    }

    int chartTop = 40;
    int chartBottom = rect.Height() - 40;
    int chartLeft = 40;
    int chartRight = rect.Width() - 40;

    int maxValue = *max_element(m_values.begin(), m_values.end());
    int barWidth = (chartRight - chartLeft) / max(1, (int)m_values.size());

    for (size_t i = 0; i < m_values.size(); ++i)
    {
        int barHeight = (double)m_values[i] / maxValue * (chartBottom - chartTop);
        int x1 = chartLeft + i * barWidth;
        int y1 = chartBottom - barHeight;
        int x2 = x1 + barWidth - 10;

        CBrush brush(RGB(100, 149, 237)); // cornflower blue
        memDC.FillRect(CRect(x1, y1, x2, chartBottom), &brush);

        // label
        memDC.SetTextColor(RGB(0, 0, 0));
        memDC.DrawText(m_labels[i], CRect(x1, chartBottom, x2, chartBottom + 20), DT_CENTER | DT_TOP | DT_SINGLELINE);
    }

    dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    memDC.SelectObject(pOldBmp);
}
