// © 2018 NIREX ALL RIGHTS RESERVED

#include "WLabel.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WLabel::WLabel(W_INT zIndex)
	: WControl(zIndex)
{
	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.007f, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.007f, 1);

	HoverColorFore->TickRegistry()->Register(std::bind(&WLabel::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WLabel::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));

	foreColor = WContainer::Theme().ColorText();
	m_family = L"Arial";
}

WLabel::WLabel(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(zIndex)
{
	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.007f, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.007f, 1);

	HoverColorFore->TickRegistry()->Register(std::bind(&WLabel::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WLabel::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));

	foreColor = WContainer::Theme().ColorText();
	m_family = L"Arial";
}

WLabel::WLabel(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(zIndex)
{
	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.007f, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.007f, 1);

	HoverColorFore->TickRegistry()->Register(std::bind(&WLabel::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WLabel::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));

	foreColor = WContainer::Theme().ColorText();
	m_family = L"Arial";
}

WLabel::WLabel(WRectF location, W_INT zIndex)
	: WControl(zIndex)
{
	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.007f, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.007f, 1);

	HoverColorFore->TickRegistry()->Register(std::bind(&WLabel::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WLabel::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WLabel::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));

	foreColor = WContainer::Theme().ColorText();
	m_family = L"Arial";
}

WLabel::~WLabel()
{
	delete HoverColorFore;
	delete UnHoverColorFore;
}

W_COLOR WLabel::Foreground(W_COLOR col)
{
	foreColor = col;
	return col;
}

W_COLOR WLabel::Foreground(void) const
{
	return foreColor;
}

void WLabel::Render(void)
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
	WGraphicsContainer::Graphics()->WriteText(ctRec, m_Content, m_conLen, m_family, m_fsize, foreColor);

// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WLabel::MouseEnter(WMouseArgs* Args)
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
		UnHoverColorFore->Lock();
		HoverColorFore->Perform();
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WLabel::MouseLeave(WMouseArgs* Args)
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
		UnHoverColorFore->Unlock();
		HoverColorFore->Lock();
		UnHoverColorFore->Perform();
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

wchar_t* WLabel::FontFamily(void) const
{
	return m_family;
}

wchar_t* WLabel::Content(UINT32 & outLen) const
{
	outLen = m_conLen;
	return m_Content;
}

W_FLOAT WLabel::FontSize(void) const
{
	return m_fsize;
}

wchar_t* WLabel::FontFamily(wchar_t* intake)
{
	m_family = intake;
	return m_family;
}

wchar_t* WLabel::Content(wchar_t* content)
{
	m_conLen = lstrlenW(content);
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < m_conLen; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

wchar_t* WLabel::Content(wchar_t* content, UINT32 Length)
{
	m_conLen = Length;
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < Length; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

W_FLOAT WLabel::FontSize(W_FLOAT intake)
{
	m_fsize = intake;
	return m_fsize;
}

void WLabel::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WLabel::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
	UnHoverColorFore->Unlock();
}

void WLabel::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WLabel::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
	HoverColorFore->Unlock();
}
