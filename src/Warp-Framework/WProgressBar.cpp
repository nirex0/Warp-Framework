// © 2018 NIREX ALL RIGHTS RESERVED

#include "WProgressBar.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WProgressBar::WProgressBar(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, m_maxValue(100.0F)
	, m_value(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ChangeLerp = new WLerp(m_value, m_maxValue, 0.01F, 1);
	ChangeLerp->TickRegistry()->Register(std::bind(&WProgressBar::ChangeTick, this, std::placeholders::_1, std::placeholders::_2));
	ChangeLerp->DoneRegistry()->Register(std::bind(&WProgressBar::ChangeDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WProgressBar::WProgressBar(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, m_maxValue(100.0F)
	, m_value(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ChangeLerp = new WLerp(m_value, m_maxValue, 0.01F, 1);
	ChangeLerp->TickRegistry()->Register(std::bind(&WProgressBar::ChangeTick, this, std::placeholders::_1, std::placeholders::_2));
	ChangeLerp->DoneRegistry()->Register(std::bind(&WProgressBar::ChangeDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WProgressBar::WProgressBar(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, m_maxValue(100.0F)
	, m_value(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ChangeLerp = new WLerp(m_value, m_maxValue, 0.01F, 1);
	ChangeLerp->TickRegistry()->Register(std::bind(&WProgressBar::ChangeTick, this, std::placeholders::_1, std::placeholders::_2));
	ChangeLerp->DoneRegistry()->Register(std::bind(&WProgressBar::ChangeDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WProgressBar::WProgressBar(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, m_maxValue(100.0F)
	, m_value(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ChangeLerp = new WLerp(m_value, m_maxValue, 0.01F, 1);
	ChangeLerp->TickRegistry()->Register(std::bind(&WProgressBar::ChangeTick, this, std::placeholders::_1, std::placeholders::_2));
	ChangeLerp->DoneRegistry()->Register(std::bind(&WProgressBar::ChangeDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WProgressBar::~WProgressBar(void)
{
	delete ChangeLerp;

	delete HoverColorBord;
	delete UnHoverColorBord;

	delete HoverColorFore;
	delete UnHoverColorFore;

	delete HoverColorBack;
	delete UnHoverColorBack;
}

W_FLOAT WProgressBar::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WProgressBar::Foreground(W_COLOR col)
{
	foreColor = col;
	return col;
}

W_COLOR WProgressBar::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WProgressBar::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WProgressBar::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WProgressBar::Foreground(void) const
{
	return foreColor;
}

W_COLOR WProgressBar::Background(void) const
{
	return backColor;
}

W_COLOR WProgressBar::BorderBrush(void) const
{
	return bordColor;
}

void WProgressBar::Render(void)
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

	WRectF parent;
	parent.Top(ParentRect.top);
	parent.Left(ParentRect.left);
	parent.Bottom(ParentRect.bottom);
	parent.Right(ParentRect.right);

	WRectF ct;
	ct.Top(ctRec.Top());
	ct.Left(ctRec.Left());
	ct.Bottom(ctRec.Bottom());
	ct.Right(ctRec.Right());

	if (!parent.IsColliding(ct))
	{
		return;
	}

	// Mask
	ID2D1PathGeometry* MaskGeo;
	WGraphicsContainer::Graphics()->GetFactory()->CreatePathGeometry(&MaskGeo);

	// Geometry Sink
	ID2D1GeometrySink* pSink = nullptr;
	MaskGeo->Open(&pSink);
	pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
	pSink->BeginFigure(D2D1::Point2F(ParentRect.left, ParentRect.top), D2D1_FIGURE_BEGIN_FILLED);
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.top));
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.bottom));
	pSink->AddLine(D2D1::Point2F(ParentRect.left, ParentRect.bottom));
	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
	pSink->Close();

	// Begin Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->CreateLayer(nullptr, &maskLayer);
	WGraphicsContainer::Graphics()->GetRenderTarget()->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(), MaskGeo), maskLayer);

	// Render Statements Go Here
	W_FLOAT percentValue = m_maxValue / 100;
	W_FLOAT filledValue = m_value / percentValue;

	W_FLOAT percentValueGeo = (ctRec.Right() - ctRec.Left()) / 100;
	W_FLOAT offset = percentValueGeo * filledValue;

	WRECTF checkrec;
	checkrec.Top(ctRec.Top());
	checkrec.Left(ctRec.Left());
	checkrec.Bottom(ctRec.Bottom());
	checkrec.Right(ctRec.Left() + offset);

	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 2, backColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(checkrec, 2, bordColor);

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WProgressBar::ChangeValue(W_FLOAT intake)
{
	if (intake >= m_maxValue)
		intake = m_maxValue;
	else if (intake <= 0)
		intake = 0;
	
	if (ChangeLerp)
	{
		ChangeLerp->Stop();
	}
	if (!ChangeLerp->IsRunning())
	{
		delete ChangeLerp;
		ChangeLerp = new WLerp(m_value * 10, intake * 10, 0.01F, 1);
		ChangeLerp->TickRegistry()->Register(std::bind(&WProgressBar::ChangeTick, this, std::placeholders::_1, std::placeholders::_2));
		ChangeLerp->DoneRegistry()->Register(std::bind(&WProgressBar::ChangeDone, this, std::placeholders::_1, std::placeholders::_2));
		ChangeLerp->Perform(); 
	}
}

void WProgressBar::MouseEnter(WMouseArgs* Args)
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
			HoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->Perform();
		}
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WProgressBar::MouseLeave(WMouseArgs* Args)
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
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WProgressBar::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

W_FLOAT WProgressBar::Value(void) const
{
	return m_value;
}

W_FLOAT WProgressBar::MaxValue(void) const
{
	return m_maxValue;
}

W_FLOAT WProgressBar::Value(W_FLOAT intake)
{
	if (intake >= m_maxValue)
	{
		m_value = m_maxValue;
		return m_value;
	}
	if (intake <= 0)
	{
		m_value = 0;
		return m_value;
	}
	m_value = intake;
	return m_value;
}

W_FLOAT WProgressBar::MaxValue(W_FLOAT intake)
{
	m_maxValue = intake;
	return m_maxValue;
}

void WProgressBar::ChangeTick(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	m_value = Largs->ValueExact() / 10;
}

void WProgressBar::ChangeDone(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	m_value = Largs->ValueExact() / 10;
}

void WProgressBar::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WProgressBar::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WProgressBar::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WProgressBar::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WProgressBar::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WProgressBar::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WProgressBar::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WProgressBar::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WProgressBar::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WProgressBar::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WProgressBar::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WProgressBar::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}