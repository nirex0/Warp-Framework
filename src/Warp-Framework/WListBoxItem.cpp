//© 2018 NIREX ALL RIGHTS RESERVED

#include "WListBoxItem.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WListBoxItem::WListBoxItem(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::~WListBoxItem()
{
}

W_FLOAT WListBoxItem::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WListBoxItem::Foreground(W_COLOR col)
{
	foreColor = col;
	return foreColor;
}

W_COLOR WListBoxItem::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WListBoxItem::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WListBoxItem::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WListBoxItem::Foreground(void) const
{
	return foreColor;
}

W_COLOR WListBoxItem::Background(void) const
{
	return backColor;
}

W_COLOR WListBoxItem::BorderBrush(void) const
{
	return bordColor;
}

void WListBoxItem::Render(void)
{
	if (!m_isVisible)
		return;

	ID2D1Layer* maskLayer;
	D2D_RECT_F ParentRect;
	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;

		ParentRect.top = m_Parent->Location().Top();
		ParentRect.left = m_Parent->Location().Left();
		ParentRect.bottom = m_Parent->Location().Bottom();
		ParentRect.right = m_Parent->Location().Right();
	}
	else
	{
		ParentRect.top = 0.0F;
		ParentRect.left = 0.0F;
		ParentRect.bottom = (W_FLOAT)INFINITE;
		ParentRect.right = (W_FLOAT)INFINITE;
	}

	// Mask
	ID2D1PathGeometry* MaskGeo;
	WGraphicsContainer::Graphics()->GetFactory()->CreatePathGeometry(&MaskGeo);

	// Geometry Sink
	ID2D1GeometrySink* pSink = NULL;
	MaskGeo->Open(&pSink);
	pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
	pSink->BeginFigure(D2D1::Point2F(ParentRect.left, ParentRect.top), D2D1_FIGURE_BEGIN_FILLED);
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.top));
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.bottom));
	pSink->AddLine(D2D1::Point2F(ParentRect.left, ParentRect.bottom));
	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
	pSink->Close();

	// Begin Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->CreateLayer(NULL, &maskLayer);
	WGraphicsContainer::Graphics()->GetRenderTarget()->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(), MaskGeo), maskLayer);

	// Render Statements Go Here
	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 1, backColor);
	WGraphicsContainer::Graphics()->WriteText(ctRec, m_Content, m_conLen, m_family, m_fsize, foreColor);

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

wchar_t* WListBoxItem::FontFamily(void) const
{
	return m_family;
}

wchar_t* WListBoxItem::Content(UINT32& outLen) const
{
	outLen = m_conLen;
	return m_Content;
}

W_FLOAT WListBoxItem::FontSize(void) const
{
	return m_fsize;
}

wchar_t* WListBoxItem::FontFamily(wchar_t* intake)
{
	m_family = intake;
	return m_family;
}

wchar_t* WListBoxItem::Content(wchar_t* content)
{
	m_conLen = lstrlenW(content);
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < m_conLen; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

wchar_t* WListBoxItem::Content(wchar_t* content, UINT32 Length)
{
	m_conLen = Length;
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < Length; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

W_FLOAT WListBoxItem::FontSize(W_FLOAT intake)
{
	m_fsize = intake;
	return m_fsize;
}

WTextAlignment WListBoxItem::Alignment(void) const
{
	return m_alighment;
}

WTextAlignment WListBoxItem::Alignment(WTextAlignment intake)
{
	m_alighment = intake;
	return m_alighment;
}
