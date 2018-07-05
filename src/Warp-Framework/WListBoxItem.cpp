// © 2018 NIREX ALL RIGHTS RESERVED

#include "WListBoxItem.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WListBoxItem::WListBoxItem(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::WListBoxItem(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_alighment = WTA_Center;
}

WListBoxItem::~WListBoxItem()
{
	delete HoverColorBord;
	delete UnHoverColorBord;

	delete HoverColorFore;
	delete UnHoverColorFore;

	delete HoverColorBack;
	delete UnHoverColorBack;
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

void WListBoxItem::MouseEnter(WMouseArgs* Args)
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
		if (UnHoverColorBord)
		{
			UnHoverColorBord->Stop();
		}
		if (!HoverColorBord->IsRunning())
		{
			delete HoverColorBord;
			HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
			HoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->Perform();
		}

		if (UnHoverColorFore)
		{
			UnHoverColorFore->Stop();
		}
		if (!HoverColorFore->IsRunning())
		{
			delete HoverColorFore;
			HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
			HoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->Perform();
		}

		if (UnHoverColorBack)
		{
			UnHoverColorBack->Stop();
		}
		if (!HoverColorBack->IsRunning())
		{
			delete HoverColorBack;
			HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
			HoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->Perform();
		}

		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WListBoxItem::MouseLeave(WMouseArgs* Args)
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
		if (HoverColorBord)
		{
			HoverColorBord->Stop();
		}
		if (!UnHoverColorBord->IsRunning())
		{
			delete UnHoverColorBord;
			UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->Perform();
		}

		if (HoverColorFore)
		{
			HoverColorFore->Stop();
		}
		if (!UnHoverColorFore->IsRunning())
		{
			delete UnHoverColorFore;
			UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->Perform();
		}

		if (HoverColorBack)
		{
			HoverColorBack->Stop();
		}
		if (!UnHoverColorBack->IsRunning())
		{
			delete UnHoverColorBack;
			UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WListBoxItem::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->Perform();
		}

		WCTMouseLeaveRegistery->Run(this, Args);
	}
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

void WListBoxItem::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WListBoxItem::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WListBoxItem::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WListBoxItem::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WListBoxItem::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WListBoxItem::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WListBoxItem::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WListBoxItem::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WListBoxItem::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WListBoxItem::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WListBoxItem::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WListBoxItem::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}
