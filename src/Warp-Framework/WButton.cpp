// © 2018 NIREX ALL RIGHTS RESERVED

#include "WButton.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WButton::WButton(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WButton::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WButton::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WButton::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WButton::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));
	
	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WButton::WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WButton::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WButton::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WButton::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WButton::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WButton::WButton(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WButton::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WButton::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WButton::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WButton::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WButton::WButton(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WButton::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WButton::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WButton::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WButton::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WButton::~WButton(void)
{	
	delete ExBordLerpExtend;
	delete ExBordLerpShrink;
}

W_FLOAT WButton::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WButton::Foreground(W_COLOR col)
{
	foreColor = col;
	return col;
}

W_COLOR WButton::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WButton::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WButton::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WButton::Foreground(void) const
{
	return foreColor;
}

W_COLOR WButton::Background(void) const
{
	return backColor;
}

W_COLOR WButton::BorderBrush(void) const
{
	return bordColor;
}

void WButton::Render(void)
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
	if (m_UseExtendedBorder)
	{
// Top Bar
		WRECTF TopBar = ctRec;
		TopBar.Top(ctRec.Top() - 5);
		TopBar.Left(ctRec.Left() - 5);
		TopBar.Bottom(ctRec.Top() - 4);
		TopBar.Right(ctRec.Left() + GetWidth() / ExBordRatio + 10);

		WGraphicsContainer::Graphics()->DrawRoundRect(TopBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(TopBar, 1, bordColor);

// Left Bar
		WRECTF LeftBar = ctRec;
		LeftBar.Top(ctRec.Top() - 5);
		LeftBar.Left(ctRec.Left() - 5);
		LeftBar.Bottom(ctRec.Top() + GetHeight() / ExBordRatio + 10);
		LeftBar.Right(ctRec.Left() - 4);

		WGraphicsContainer::Graphics()->DrawRoundRect(LeftBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(LeftBar, 1, bordColor);

// Bottom Bar
		WRECTF BottomBar = ctRec;

		BottomBar.Top(ctRec.Bottom() + 4);
		BottomBar.Left(ctRec.Right() - GetWidth() / ExBordRatio - 10);
		BottomBar.Bottom(ctRec.Bottom() + 5);
		BottomBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(BottomBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(BottomBar, 1, bordColor);

// Right Bar
		WRECTF RightBar = ctRec;
		RightBar.Top(ctRec.Bottom() - GetHeight() / ExBordRatio - 10);
		RightBar.Left(ctRec.Right() + 4);
		RightBar.Bottom(ctRec.Bottom() + 5);
		RightBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(RightBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(RightBar, 1, bordColor);
	}

	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 1, backColor);
	WGraphicsContainer::Graphics()->WriteText(ctRec, m_Content, m_conLen, m_family, m_fsize, foreColor);

// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WButton::MouseEnter(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && !Location().IsColliding(p) && parentalControl)
	{
		if (IsShrinked && !IsExtending)
		{
			ExBordLerpShrink->Lock();
			IsExtending = true;
			ExBordLerpExtend->Perform();
		}
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WButton::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (!IsWithin(Args) && Args->State() == KeyState::NoClick && Location().IsColliding(p) && parentalControl)
	{
		if (!IsShrinking)
		{
			ExBordLerpExtend->Lock();
			ExBordLerpShrink->Unlock();
			IsShrinking = true;
			ExBordLerpShrink->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

wchar_t* WButton::FontFamily(void) const
{
	return m_family;
}

wchar_t* WButton::Content(UINT32& outLen) const
{
	outLen = m_conLen;
	return m_Content;
}

W_FLOAT WButton::FontSize(void) const
{
	return m_fsize;
}

wchar_t* WButton::FontFamily(wchar_t* intake)
{
	m_family = intake;
	return m_family;
}

wchar_t* WButton::Content(wchar_t* content)
{
	m_conLen = lstrlenW(content);
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < m_conLen; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

wchar_t* WButton::Content(wchar_t* content, UINT32 Length)
{
	m_conLen = Length;
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < Length; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

W_FLOAT WButton::FontSize(W_FLOAT intake)
{
	m_fsize = intake;
	return m_fsize;
}

bool WButton::UseExtendedBorder(void) const
{
	return m_UseExtendedBorder;
}

bool WButton::UseExtendedBorder(bool intake)
{
	m_UseExtendedBorder = intake;
	return m_UseExtendedBorder;
}

void WButton::Extend(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
	ExBordLerpShrink->From(Largs->ValueExact());
}

void WButton::Shrink(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WButton::ExtendDone(WEntity* sender, WEventArgs* args)
{
	ExBordLerpShrink->Unlock();
	IsExtending = false;
	IsExtended = true;
	IsShrinked = false;
}

void WButton::ShrinkDone(WEntity* sender, WEventArgs* args)
{
	ExBordLerpExtend->Unlock();
	IsShrinking = false;
	IsExtended = false;
	IsShrinked = true;
}