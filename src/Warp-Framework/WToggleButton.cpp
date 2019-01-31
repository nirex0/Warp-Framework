// © 2019 NIREX ALL RIGHTS RESERVED

#include "WToggleButton.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WToggleButton::WToggleButton(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, m_bIsOn(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	LerpToLeft = new WLerp(0, 0, 0.03F, 1);
	LerpToRight = new WLerp(0, 0, 0.03F, 1);

	LerpToLeft->TickRegistry()->Register(std::bind(&WToggleButton::ToLeftTick, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->TickRegistry()->Register(std::bind(&WToggleButton::ToRightTick, this, std::placeholders::_1, std::placeholders::_2));

	LerpToLeft->DoneRegistry()->Register(std::bind(&WToggleButton::ToLeftDone, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->DoneRegistry()->Register(std::bind(&WToggleButton::ToRightDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WToggleButton::WToggleButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, m_bIsOn(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	LerpToLeft = new WLerp(0, 0, 0.03F, 1);
	LerpToRight = new WLerp(0, 0, 0.03F, 1);

	LerpToLeft->TickRegistry()->Register(std::bind(&WToggleButton::ToLeftTick, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->TickRegistry()->Register(std::bind(&WToggleButton::ToRightTick, this, std::placeholders::_1, std::placeholders::_2));

	LerpToLeft->DoneRegistry()->Register(std::bind(&WToggleButton::ToLeftDone, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->DoneRegistry()->Register(std::bind(&WToggleButton::ToRightDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WToggleButton::WToggleButton(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, m_bIsOn(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	LerpToLeft = new WLerp(0, 0, 0.03F, 1);
	LerpToRight = new WLerp(0, 0, 0.03F, 1);

	LerpToLeft->TickRegistry()->Register(std::bind(&WToggleButton::ToLeftTick, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->TickRegistry()->Register(std::bind(&WToggleButton::ToRightTick, this, std::placeholders::_1, std::placeholders::_2));

	LerpToLeft->DoneRegistry()->Register(std::bind(&WToggleButton::ToLeftDone, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->DoneRegistry()->Register(std::bind(&WToggleButton::ToRightDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WToggleButton::WToggleButton(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, m_bIsOn(0)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	LerpToLeft = new WLerp(0, 0, 0.03F, 1);
	LerpToRight = new WLerp(0, 0, 0.03F, 1);

	LerpToLeft->TickRegistry()->Register(std::bind(&WToggleButton::ToLeftTick, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->TickRegistry()->Register(std::bind(&WToggleButton::ToRightTick, this, std::placeholders::_1, std::placeholders::_2));

	LerpToLeft->DoneRegistry()->Register(std::bind(&WToggleButton::ToLeftDone, this, std::placeholders::_1, std::placeholders::_2));
	LerpToRight->DoneRegistry()->Register(std::bind(&WToggleButton::ToRightDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
}

WToggleButton::~WToggleButton(void)
{
	delete LerpToLeft;
	delete LerpToRight;

	delete HoverColorBord;
	delete UnHoverColorBord;

	delete HoverColorFore;
	delete UnHoverColorFore;

	delete HoverColorBack;
	delete UnHoverColorBack;
}

W_FLOAT WToggleButton::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WToggleButton::Foreground(W_COLOR col)
{
	foreColor = col;
	return col;
}

W_COLOR WToggleButton::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WToggleButton::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WToggleButton::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WToggleButton::Foreground(void) const
{
	return foreColor;
}

W_COLOR WToggleButton::Background(void) const
{
	return backColor;
}

W_COLOR WToggleButton::BorderBrush(void) const
{
	return bordColor;
}

void WToggleButton::Render(void)
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
	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 2, backColor);

	if (m_bIsOn && !m_isTransitioning)
	{
		WRectF indLoc;
		indLoc.Top(ctRec.Top() + 5);
		indLoc.Left(((ctRec.Right() - ctRec.Left()) / 2) + ctRec.Left() + 5);
		indLoc.Right(ctRec.Right() - 5);
		indLoc.Bottom(ctRec.Bottom() - 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(indLoc, m_thickness, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(indLoc, 2, foreColor);
	}
	else if(!m_bIsOn && !m_isTransitioning)
	{
		WRectF indLoc;
		indLoc.Top(ctRec.Top() + 5);
		indLoc.Left(ctRec.Left() + 5);
		indLoc.Right(((ctRec.Right() - ctRec.Left()) / 2) + ctRec.Left() - 5);
		indLoc.Bottom(ctRec.Bottom() - 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(indLoc, m_thickness, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(indLoc, 2, backColor);
	}
	else if (m_isTransitioning && m_bIsOn)
	{
		WRectF indLoc;
		indLoc.Top(ctRec.Top() + 5);
		indLoc.Left(m_transitLocation.Left());
		indLoc.Right(m_transitLocation.Right());
		indLoc.Bottom(ctRec.Bottom() - 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(indLoc, m_thickness, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(indLoc, 2, foreColor);
	}
	else if (m_isTransitioning && !m_bIsOn)
	{
		WRectF indLoc;
		indLoc.Top(ctRec.Top() + 5);
		indLoc.Left(m_transitLocation.Left());
		indLoc.Right(m_transitLocation.Right());
		indLoc.Bottom(ctRec.Bottom() - 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(indLoc, m_thickness, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(indLoc, 2, backColor);
	}

	WGraphicsContainer::Graphics()->SafeFlush();

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WToggleButton::MouseUp(WMouseArgs * Args)
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
	if (IsWithin(Args) && Args->State() == KeyState::MouseUp  && parentalControl)
	{
		m_bIsOn = !m_bIsOn;
		m_isTransitioning = 1;

		if (m_bIsOn)
		{
			if (LerpToRight)
			{
				LerpToRight->Stop();
			}
			if (!LerpToRight->IsRunning())
			{
				delete LerpToLeft;
				LerpToLeft = new WLerp(ctRec.Left(), ((ctRec.Right() - ctRec.Left()) / 2) + ctRec.Left(), 0.03F, 1);
				LerpToLeft->TickRegistry()->Register(std::bind(&WToggleButton::ToLeftTick, this, std::placeholders::_1, std::placeholders::_2));
				LerpToLeft->DoneRegistry()->Register(std::bind(&WToggleButton::ToLeftDone, this, std::placeholders::_1, std::placeholders::_2));
				LerpToLeft->Perform();
			}
		}
		else
		{
			if (LerpToLeft)
			{
				LerpToLeft->Stop();
			}
			if (!LerpToRight->IsRunning())
			{
				delete LerpToRight;
				LerpToRight = new WLerp(((ctRec.Right() - ctRec.Left()) / 2) + ctRec.Left(), ctRec.Left(), 0.03F, 1);
				LerpToRight->TickRegistry()->Register(std::bind(&WToggleButton::ToRightTick, this, std::placeholders::_1, std::placeholders::_2));
				LerpToRight->DoneRegistry()->Register(std::bind(&WToggleButton::ToRightDone, this, std::placeholders::_1, std::placeholders::_2));
				LerpToRight->Perform();
			}
		}

		WCTMouseUpRegistery->Run(this, Args);
	}
	m_isClicked = 0;
}

void WToggleButton::MouseEnter(WMouseArgs* Args)
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
			HoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->Perform();
		}

		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WToggleButton::MouseLeave(WMouseArgs* Args)
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
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WToggleButton::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->Perform();
		}

		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

bool WToggleButton::Value(void) const
{
	return m_bIsOn;
}

bool WToggleButton::Value(bool intake)
{
	m_bIsOn = intake;
	return m_bIsOn;
}

void WToggleButton::ToLeftTick(WEntity* sender, WEventArgs* args)
{
	m_isTransitioning = true;
	WLerpArgs* Largs = (WLerpArgs*)args;

	m_transitLocation.Left(Largs->ValueExact() + 5);
	m_transitLocation.Right(Largs->ValueExact() + ((ctRec.Right() - ctRec.Left()) / 2) - 5);
}

void WToggleButton::ToRightTick(WEntity* sender, WEventArgs* args)
{
	m_isTransitioning = true;
	WLerpArgs*Largs = (WLerpArgs*)args;

	m_transitLocation.Left(Largs->ValueExact() + 5);
	m_transitLocation.Right(Largs->ValueExact() + ((ctRec.Right() - ctRec.Left()) / 2) - 5);
}

void WToggleButton::ToLeftDone(WEntity* sender, WEventArgs* args)
{
	m_isTransitioning = false;
	WLerpArgs* Largs = (WLerpArgs*)args;

	m_transitLocation.Left(Largs->ValueExact() + 5);
	m_transitLocation.Right(Largs->ValueExact() + ((ctRec.Right() - ctRec.Left()) / 2) - 5);
}

void WToggleButton::ToRightDone(WEntity* sender, WEventArgs* args)
{
	m_isTransitioning = false;
	WLerpArgs* Largs = (WLerpArgs*)args;

	m_transitLocation.Left(Largs->ValueExact() + 5);
	m_transitLocation.Right(Largs->ValueExact() + ((ctRec.Right() - ctRec.Left()) / 2) - 5);
}

void WToggleButton::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WToggleButton::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WToggleButton::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WToggleButton::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WToggleButton::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WToggleButton::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WToggleButton::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WToggleButton::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WToggleButton::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WToggleButton::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WToggleButton::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WToggleButton::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}