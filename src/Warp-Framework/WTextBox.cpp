// © 2018 NIREX ALL RIGHTS RESERVED

#include "WTextBox.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WTextBox::WTextBox(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.03F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.03F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WTextBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WTextBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WTextBox::WTextBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.03F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.03F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WTextBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WTextBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WTextBox::WTextBox(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.03F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.03F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WTextBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WTextBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.07F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.07F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.07F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.07F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.07F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.07F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WTextBox::WTextBox(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.03F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.03F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WTextBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WTextBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord = new WColorTransform(WContainer::Theme().ColorBorder(), WContainer::Theme().ColorBorderGlow(), 0.005F, 1);
	UnHoverColorBord = new WColorTransform(WContainer::Theme().ColorBorderGlow(), WContainer::Theme().ColorBorder(), 0.005F, 1);

	HoverColorFore = new WColorTransform(WContainer::Theme().ColorText(), WContainer::Theme().ColorTextGlow(), 0.005F, 1);
	UnHoverColorFore = new WColorTransform(WContainer::Theme().ColorTextGlow(), WContainer::Theme().ColorText(), 0.005F, 1);

	HoverColorBack = new WColorTransform(WContainer::Theme().ColorBack(), WContainer::Theme().ColorBackGlow(), 0.005F, 1);
	UnHoverColorBack = new WColorTransform(WContainer::Theme().ColorBackGlow(), WContainer::Theme().ColorBack(), 0.005F, 1);

	HoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_family = L"Arial";
	m_UseExtendedBorder = true;
}

WTextBox::~WTextBox(void)
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

W_FLOAT WTextBox::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WTextBox::Foreground(W_COLOR col)
{
	foreColor = col;
	return col;
}

W_COLOR WTextBox::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WTextBox::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WTextBox::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WTextBox::Foreground(void) const
{
	return foreColor;
}

W_COLOR WTextBox::Background(void) const
{
	return backColor;
}

W_COLOR WTextBox::BorderBrush(void) const
{
	return bordColor;
}

void WTextBox::Render(void)
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
	// Extended Border
	if (m_UseExtendedBorder)
	{
		// Top Bar
		WRECTF TopBar = ctRec;
		TopBar.Top(ctRec.Top() - 5);
		TopBar.Left(ctRec.Left() - 5);
		TopBar.Bottom(ctRec.Top() - 4);
		TopBar.Right(ctRec.Left() + GetWidth() / ExBordRatio + 10);

		WGraphicsContainer::Graphics()->DrawRect(TopBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(TopBar, bordColor);

		// Left Bar
		WRECTF LeftBar = ctRec;
		LeftBar.Top(ctRec.Top() - 5);
		LeftBar.Left(ctRec.Left() - 5);
		LeftBar.Bottom(ctRec.Top() + GetHeight() / ExBordRatio + 10);
		LeftBar.Right(ctRec.Left() - 4);

		WGraphicsContainer::Graphics()->DrawRect(LeftBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(LeftBar, bordColor);

		// Bottom Bar
		WRECTF BottomBar = ctRec;

		BottomBar.Top(ctRec.Bottom() + 4);
		BottomBar.Left(ctRec.Right() - GetWidth() / ExBordRatio - 10);
		BottomBar.Bottom(ctRec.Bottom() + 5);
		BottomBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRect(BottomBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(BottomBar, bordColor);

		// Right Bar
		WRECTF RightBar = ctRec;
		RightBar.Top(ctRec.Bottom() - GetHeight() / ExBordRatio - 10);
		RightBar.Left(ctRec.Right() + 4);
		RightBar.Bottom(ctRec.Bottom() + 5);
		RightBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRect(RightBar, 2, bordColor);
		WGraphicsContainer::Graphics()->FillRectSolid(RightBar, bordColor);
	}

	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 1, backColor);
	WGraphicsContainer::Graphics()->WriteText(ctRec, m_Content, m_conLen, m_family, m_fsize, foreColor, WTA_LeftToRight);

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WTextBox::KeyDown(WKeyboardArgs* Args)
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
		if (m_Parent->IsActive())
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (m_isActive && parentalControl)
	{
		UINT32 len;
		std::wstring ctn = Content(len);
		std::wstring nctn = L"";
		for (size_t i = 0; i < len; i++)
		{
			nctn += ctn[i];
		}
		if (Args->GetKey() == 8)
		{
			len--;
		}
		else
		{
			len++;
		}

		nctn += (wchar_t)Args->GetKey();
		
		wchar_t* fullctn = (wchar_t*)nctn.c_str();

		Content(fullctn, len);

		WCTKeyDownRegistery->Run(this, Args);
	}
}

void WTextBox::MouseDown(WMouseArgs* Args)
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
	if (IsWithin(Args) && Args->State() == KeyState::MouseDown  && parentalControl)
	{
		m_isActive = 1;
		m_isClicked = 1;
		WCTMouseDownRegistery->Run(this, Args);
	}
	else if (!IsWithin(Args))
	{
		m_isActive = 0;
	}
}

void WTextBox::MouseEnter(WMouseArgs* Args)
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
			HoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			ExBordLerpExtend->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpExtend->Perform();
		}

		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WTextBox::MouseLeave(WMouseArgs* Args)
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
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WTextBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			ExBordLerpShrink->TickRegistry()->Register(std::bind(&WTextBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WTextBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
			ExBordLerpShrink->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

wchar_t* WTextBox::FontFamily(void) const
{
	return m_family;
}

wchar_t* WTextBox::Content(UINT32& outLen) const
{
	outLen = m_conLen;
	return m_Content;
}

W_FLOAT WTextBox::FontSize(void) const
{
	return m_fsize;
}

wchar_t* WTextBox::FontFamily(wchar_t* intake)
{
	m_family = intake;
	return m_family;
}

wchar_t* WTextBox::Content(wchar_t* content)
{
	m_conLen = lstrlenW(content);
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < m_conLen; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

wchar_t* WTextBox::Content(wchar_t* content, UINT32 Length)
{
	m_conLen = Length;
	m_Content = new wchar_t[m_conLen];
	for (size_t i = 0; i < Length; i++)
	{
		m_Content[i] = content[i];
	}
	return m_Content;
}

W_FLOAT WTextBox::FontSize(W_FLOAT intake)
{
	m_fsize = intake;
	return m_fsize;
}

bool WTextBox::UseExtendedBorder(void) const
{
	return m_UseExtendedBorder;
}

bool WTextBox::UseExtendedBorder(bool intake)
{
	m_UseExtendedBorder = intake;
	return m_UseExtendedBorder;
}

void WTextBox::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WTextBox::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WTextBox::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WTextBox::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WTextBox::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WTextBox::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WTextBox::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WTextBox::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WTextBox::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WTextBox::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WTextBox::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WTextBox::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WTextBox::Extend(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WTextBox::Shrink(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WTextBox::ExtendDone(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WTextBox::ShrinkDone(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}