// © 2018 NIREX ALL RIGHTS RESERVED

#include "WScrollView.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WScrollView::WScrollView(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
		foreColor = WContainer::Theme().ColorText();
		backColor = WContainer::Theme().ColorBack();
		bordColor = WContainer::Theme().ColorBorder();

		ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
		ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

		ExBordLerpExtend->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
		ExBordLerpShrink->TickRegistry()->Register(std::bind(&WScrollView::Shrink, this, std::placeholders::_1, std::placeholders::_2));

		ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
		ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WScrollView::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

		HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
		UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

		HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
		UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

		HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
		UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

		HoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
		HoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
		HoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

		HoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
		HoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
		HoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
		UnHoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

		m_UseExtendedBorder = true;
}

WScrollView::WScrollView(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WScrollView::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WScrollView::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WScrollView::WScrollView(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WScrollView::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WScrollView::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WScrollView::WScrollView(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WScrollView::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WScrollView::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WScrollView::~WScrollView()
{
	delete ExBordLerpExtend;
	delete ExBordLerpShrink;

	delete HoverColorBord;
	delete UnHoverColorBord;

	delete HoverColorFore;
	delete UnHoverColorFore;

	delete HoverColorBack;
	delete UnHoverColorBack;
}

W_FLOAT WScrollView::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WScrollView::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WScrollView::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WScrollView::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WScrollView::Background(void) const
{
	return backColor;
}

W_COLOR WScrollView::BorderBrush(void) const
{
	return bordColor;
}

void WScrollView::Render(void)
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
	if (m_UseExtendedBorder)
	{
		// Top Bar
		WRectF TopBar = ctRec;
		TopBar.Top(ctRec.Top() - 5);
		TopBar.Left(ctRec.Left() - 5);
		TopBar.Bottom(ctRec.Top() - 4);
		TopBar.Right(ctRec.Left() + GetWidth() / ExBordRatio + 10);

		WGraphicsContainer::Graphics()->DrawRect(TopBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(TopBar, bordColor);

		// Left Bar
		WRectF LeftBar = ctRec;
		LeftBar.Top(ctRec.Top() - 5);
		LeftBar.Left(ctRec.Left() - 5);
		LeftBar.Bottom(ctRec.Top() + GetHeight() / ExBordRatio + 10);
		LeftBar.Right(ctRec.Left() - 4);

		WGraphicsContainer::Graphics()->DrawRect(LeftBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(LeftBar, bordColor);

		// Bottom Bar
		WRectF BottomBar = ctRec;

		BottomBar.Top(ctRec.Bottom() + 4);
		BottomBar.Left(ctRec.Right() - GetWidth() / ExBordRatio - 10);
		BottomBar.Bottom(ctRec.Bottom() + 5);
		BottomBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRect(BottomBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(BottomBar, bordColor);

		// Right Bar
		WRectF RightBar = ctRec;
		RightBar.Top(ctRec.Bottom() - GetHeight() / ExBordRatio - 10);
		RightBar.Left(ctRec.Right() + 4);
		RightBar.Bottom(ctRec.Bottom() + 5);
		RightBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRect(RightBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(RightBar, bordColor);
	}

	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 2, backColor);

	WGraphicsContainer::Graphics()->SafeFlush();

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WScrollView::MouseEnter(WMouseArgs * Args)
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
			HoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->Perform();
		}

		if (ExBordLerpShrink)
		{
			ExBordLerpShrink->Stop();
		}
		if (!ExBordLerpExtend->IsRunning())
		{
			delete ExBordLerpExtend;
			ExBordLerpExtend = new WLerp(500, 100, 0.03F, 1);
			ExBordLerpExtend->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpExtend->Perform();
		}

		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WScrollView::MouseLeave(WMouseArgs * Args)
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
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WScrollView::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->Perform();
		}


		if (ExBordLerpExtend)
		{
			ExBordLerpExtend->Stop();
		}
		if (!ExBordLerpShrink->IsRunning())
		{
			delete ExBordLerpShrink;
			ExBordLerpShrink = new WLerp(ExBordRatio * 100, 500, 0.03F, 1);
			ExBordLerpShrink->TickRegistry()->Register(std::bind(&WScrollView::Extend, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WScrollView::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpShrink->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

void WScrollView::MouseRollUp(WMouseArgs * Args)
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
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && parentalControl)
	{
		m_yoffset -= m_DisplaceSpeed;
		WCTMouseRollUpRegistery->Run(this, Args);
	}
}

void WScrollView::MouseRollDown(WMouseArgs * Args)
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
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && parentalControl)
	{
		m_yoffset += m_DisplaceSpeed;
		WCTMouseRollDownRegistery->Run(this, Args);
	}
}

bool WScrollView::UseExtendedBorder(void) const
{
	return m_UseExtendedBorder;
}

bool WScrollView::UseExtendedBorder(bool intake)
{
	m_UseExtendedBorder = intake;
	return m_UseExtendedBorder;
}

void WScrollView::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WScrollView::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WScrollView::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WScrollView::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WScrollView::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WScrollView::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WScrollView::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WScrollView::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WScrollView::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WScrollView::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WScrollView::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WScrollView::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WScrollView::Extend(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WScrollView::Shrink(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WScrollView::ExtendDone(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WScrollView::ShrinkDone(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

