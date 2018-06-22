//© 2018 NIREX ALL RIGHTS RESERVED

#include "WListBoxItem.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"
#include<math.h>

WListBoxItem::WListBoxItem(W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	lbiRec.Top(m_top);
	lbiRec.Left(m_left);

	lbiRec.Bottom(m_bottom);
	lbiRec.Right(m_right);

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";
	m_alighment = WTA_Center;

	WControlHandler::Add(this);
	UpdateRect();
}

WListBoxItem::WListBoxItem(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";
	m_alighment = WTA_Center;

	WControlHandler::Add(this);
	UpdateRect();
}

WListBoxItem::WListBoxItem(WPointF topleft, WPointF botright, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();
	
	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";
	m_alighment = WTA_Center;

	WControlHandler::Add(this);
	UpdateRect();
}

WListBoxItem::WListBoxItem(WRectF location, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";
	m_alighment = WTA_Center;

	WControlHandler::Add(this);
	UpdateRect();
}

WListBoxItem::~WListBoxItem()
{
	delete LBMouseDownRegistery;
	delete LBMouseUpRegistery;
	delete LBMouseEnterRegistery;
	delete LBMouseLeaveRegistery;
	delete LBMouseRollUpRegistery;
	delete LBMouseRollDownRegistery;
}


WRectF WListBoxItem::Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::Location(WPointF topleft, WPointF botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::Location(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::RelLocation(WPointF topleft, WPointF heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::RelLocation(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = m_top + location.Bottom();
	m_right = m_left + location.Right();;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBoxItem::Location(void) const
{
	return WRectF(m_top, m_left, m_bottom, m_right);
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
	WGraphicsContainer::Graphics()->DrawRoundRect(lbiRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(lbiRec, 1, backColor);
	WGraphicsContainer::Graphics()->WriteText(lbiRec, m_Content, m_conLen, m_family, m_fsize, foreColor);

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

WPointF WListBoxItem::Displace(W_FLOAT X, W_FLOAT Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WPointF(X, Y);
}

WPointF WListBoxItem::Displace(WPointF XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WPointF(XY.X(), XY.Y());
}

WRegistry* WListBoxItem::MouseDownRegistery(void)
{
	return LBMouseDownRegistery;
}

WRegistry* WListBoxItem::MouseUpRegistery(void)
{
	return LBMouseUpRegistery;
}

WRegistry* WListBoxItem::MouseEnterRegistery(void)
{
	return LBMouseEnterRegistery;
}

WRegistry* WListBoxItem::MouseLeaveRegistery(void)
{
	return LBMouseLeaveRegistery;
}

WRegistry* WListBoxItem::MouseRollUpRegistery(void)
{
	return LBMouseRollUpRegistery;
}

WRegistry* WListBoxItem::MouseRollDownRegistery(void)
{
	return LBMouseRollDownRegistery;
}

WRegistry* WListBoxItem::MouseDownRegistery(WRegistry* intake)
{
	LBMouseDownRegistery = intake;
	return LBMouseDownRegistery;
}

WRegistry* WListBoxItem::MouseUpRegistery(WRegistry* intake)
{
	LBMouseUpRegistery = intake;
	return LBMouseUpRegistery;
}

WRegistry* WListBoxItem::MouseEnterRegistery(WRegistry* intake)
{
	LBMouseEnterRegistery = intake;
	return LBMouseEnterRegistery;
}

WRegistry* WListBoxItem::MouseLeaveRegistery(WRegistry* intake)
{
	LBMouseLeaveRegistery = intake;
	return LBMouseLeaveRegistery;
}

WRegistry* WListBoxItem::MouseRollUpRegistery(WRegistry* intake)
{
	LBMouseRollUpRegistery = intake;
	return LBMouseRollUpRegistery;
}

WRegistry* WListBoxItem::MouseRollDownRegistery(WRegistry* intake)
{
	LBMouseRollDownRegistery = intake;
	return LBMouseRollDownRegistery;
}

W_INT WListBoxItem::ZIndex(void) const
{
	return m_zIndex;
}

bool WListBoxItem::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WListBoxItem::IsVisible(void) const
{
	return m_isVisible;
}


W_INT WListBoxItem::ZIndex(W_INT input)
{
	WControlHandler::Remove(this);
	m_zIndex = input;
	WControlHandler::Add(this);
	return m_zIndex;
}

bool WListBoxItem::IsEnabled(bool input)
{
	m_isEnabled = input;
	return m_isEnabled;
}

bool WListBoxItem::IsVisible(bool input)
{
	m_isVisible = input;
	return m_isVisible;
}

void WListBoxItem::MouseDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::MouseDown)
	{
		LBMouseDownRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::MouseUp)
	{
		LBMouseUpRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseEnter(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	if (IsWithin(Args) && Args->State() == KeyState::NoClick && !Location().IsColliding(p))
	{
		LBMouseEnterRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	if (!IsWithin(Args) && Args->State() == KeyState::NoClick && Location().IsColliding(p))
	{
		LBMouseLeaveRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseRollUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
		LBMouseRollUpRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseRollDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
		LBMouseRollDownRegistery->Run(this, Args);
	}
}

IControl* WListBoxItem::Parent(IControl* intake)
{
	m_Parent = intake;
	return m_Parent;
}

IControl* WListBoxItem::Parent(void) const
{
	return m_Parent;
}

wchar_t* WListBoxItem::FontFamily(void) const
{
	return m_family;
}

wchar_t* WListBoxItem::Content(UINT32 & outLen) const
{
	outLen = m_conLen;
	return m_Content;
}

W_FLOAT WListBoxItem::FontSize(void) const
{
	return m_fsize;
}

wchar_t* WListBoxItem::FontFamily(wchar_t * intake)
{
	m_family = intake;
	return m_family;
}

wchar_t* WListBoxItem::Content(wchar_t * content)
{
	m_conLen = lstrlenW(content);
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < m_conLen; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

wchar_t* WListBoxItem::Content(wchar_t * content, UINT32 Length)
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

void WListBoxItem::UpdateRect(void)
{
	lbiRec.Top(m_top);
	lbiRec.Left(m_left);
	lbiRec.Bottom(m_bottom);
	lbiRec.Right(m_right);
}

bool WListBoxItem::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WListBoxItem::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}

W_INT WListBoxItem::GetWidth(void) const
{
	return (W_INT)(lbiRec.Right() - lbiRec.Left());
}

W_INT WListBoxItem::GetHeight(void) const
{
	return (W_INT)(lbiRec.Bottom() - lbiRec.Top());
}