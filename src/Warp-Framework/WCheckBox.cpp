// © 2019 NIREX ALL RIGHTS RESERVED

#include "WCheckBox.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WCheckBox::WCheckBox(const W_INT& zIndex)
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

	HoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isChecked = false;
}

WCheckBox::WCheckBox(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex)
	: WControl(top, left, bottom, right, zIndex)
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

	HoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isChecked = false;
}

WCheckBox::WCheckBox(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex)
	: WControl(topleft, botright, zIndex)
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

	HoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isChecked = false;
}

WCheckBox::WCheckBox(const WRectF& location, const W_INT& zIndex)
	: WControl(location, zIndex)
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

	HoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));

	HoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
	HoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
	UnHoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isChecked = false;
}

WCheckBox::~WCheckBox(void)
{
	delete HoverColorBord;
	delete UnHoverColorBord;

	delete HoverColorFore;
	delete UnHoverColorFore;

	delete HoverColorBack;
	delete UnHoverColorBack;
}

W_FLOAT WCheckBox::BorderThickness(const W_FLOAT& f)
{
	m_thickness = f;
	return f;
}

W_COLOR WCheckBox::Foreground(const W_COLOR& col)
{
	foreColor = col;
	return col;
}

W_COLOR WCheckBox::Background(const W_COLOR& col)
{
	backColor = col;
	return col;
}

W_COLOR WCheckBox::BorderBrush(const W_COLOR& col)
{
	bordColor = col;
	return col;
}

W_FLOAT WCheckBox::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WCheckBox::Foreground(void) const
{
	return foreColor;
}

W_COLOR WCheckBox::Background(void) const
{
	return backColor;
}

W_COLOR WCheckBox::BorderBrush(void) const
{
	return bordColor;
}

void WCheckBox::Render(void)
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

	if (m_DrawBorders)
	{
		WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	}

	WRectF checkrec = ctRec;
	checkrec.Right(ctRec.Left() + (checkrec.Bottom() - checkrec.Top()));

	WGraphicsContainer::Graphics()->DrawRoundRect(checkrec, m_thickness, 2, foreColor);

	WRectF checkrecFill;
	checkrecFill.Top(checkrec.Top() + 5);
	checkrecFill.Left(checkrec.Left() + 5);
	checkrecFill.Bottom(checkrec.Bottom() - 5);
	checkrecFill.Right(checkrec.Right() - 5);

	if (m_isChecked)
	{
		WGraphicsContainer::Graphics()->FillRoundRectSolid(checkrecFill, 1, foreColor);
	}

	W_INT toffset = 5;
	WRectF textrec;
	textrec.Top(ctRec.Top() + toffset);
	textrec.Left(ctRec.Left() + (checkrec.Right() - ctRec.Left()) + toffset);
	textrec.Bottom(ctRec.Bottom() - toffset);
	textrec.Right(ctRec.Right() - toffset);
	WGraphicsContainer::Graphics()->WriteText(textrec, (wchar_t*)m_Content.c_str(), (UINT32)m_Content.length(), (wchar_t*)m_family.c_str(), m_fsize, foreColor, WTA_Center, ctRec);

	WGraphicsContainer::Graphics()->SafeFlush();

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WCheckBox::MouseUp(WMouseArgs* Args)
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
	if (IsWithin(Args) && Args->State() == KeyState::MouseUp && parentalControl)
	{
		m_isChecked = !m_isChecked;
	}
	m_isClicked = 0;
}

void WCheckBox::MouseEnter(WMouseArgs* Args)
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
			HoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::HoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::HoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::HoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			HoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::HoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			HoverColorBack->Perform();
		}
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WCheckBox::MouseLeave(WMouseArgs* Args)
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
			UnHoverColorBord->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBord->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBorderDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorFore->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorFore->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverForegroundDone, this, std::placeholders::_1, std::placeholders::_2));
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
			UnHoverColorBack->TickRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundTick, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->DoneRegistry()->Register(std::bind(&WCheckBox::UnHoverBackgroundDone, this, std::placeholders::_1, std::placeholders::_2));
			UnHoverColorBack->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

bool WCheckBox::Checked(void) const
{
	return m_isChecked;
}

bool WCheckBox::ShowBorder(void) const
{
	return m_DrawBorders;
}

std::wstring WCheckBox::FontFamily(void) const
{
	return m_family;
}

std::wstring WCheckBox::Content(void) const
{
	return m_Content;
}

W_FLOAT WCheckBox::FontSize(void) const
{
	return m_fsize;
}

bool WCheckBox::Checked(const bool& intake)
{
	m_isChecked = intake;
	return m_isChecked;
}

bool WCheckBox::ShowBorder(const bool& intake)
{
	m_DrawBorders = intake;
	return m_DrawBorders;
}

std::wstring WCheckBox::FontFamily(const std::wstring& intake)
{
	m_family = intake;
	return m_family;
}

std::wstring WCheckBox::Content(const std::wstring& content)
{
	m_Content = content;
	return m_Content;
}

W_FLOAT WCheckBox::FontSize(const W_FLOAT& intake)
{
	m_fsize = intake;
	return m_fsize;
}

void WCheckBox::ToggleBorder(void)
{
	m_DrawBorders = !m_DrawBorders;
}

void WCheckBox::ToggleValue(void)
{
	m_isChecked = !m_isChecked;
}

void WCheckBox::HoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WCheckBox::HoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WCheckBox::UnHoverBorderTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WCheckBox::UnHoverBorderDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	bordColor = Cargs->Value();
}

void WCheckBox::HoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WCheckBox::HoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WCheckBox::UnHoverForegroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WCheckBox::UnHoverForegroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	foreColor = Cargs->Value();
}

void WCheckBox::HoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WCheckBox::HoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WCheckBox::UnHoverBackgroundTick(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}

void WCheckBox::UnHoverBackgroundDone(WEntity* sender, WEventArgs* args)
{
	WColorTransformArgs* Cargs = (WColorTransformArgs*)args;
	backColor = Cargs->Value();
}