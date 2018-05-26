#include "WButton.h"
#include "WControlHandler.h"

WButton::WButton(W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
														   
	btnRec.Top(m_top);
	btnRec.Left(m_left);

	btnRec.Bottom(m_bottom);
	btnRec.Right(m_right);

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	ExBordLerpExtend = new WLerp(500, 100, 0.07, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WButton::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WButton::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WButton::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WButton::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WPointF topleft, WPointF botright, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WRectF location, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::~WButton(void)
{
	delete BtnMouseDownRegistery;
	delete BtnMouseUpRegistery;
	delete BtnMouseEnterRegistery;
	delete BtnMouseLeaveRegistery;
}

WRectF WButton::Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::Location(WPointF topleft, WPointF botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::Location(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::RelLocation(WPointF topleft, WPointF heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::RelLocation(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = m_top + location.Bottom();
	m_right = m_left + location.Right();;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WButton::Location(void) const
{
	return WRectF(m_top, m_left, m_bottom, m_right);
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

	// Top Bar
	WRECTF TopBar = btnRec;
	TopBar.Top(btnRec.Top() - 8);
	TopBar.Left(btnRec.Left() - 8);
	TopBar.Bottom(btnRec.Top() - 6);
	TopBar.Right(btnRec.Left() + GetWidth() / ExBordRatio + 15);

	WGraphicsContainer::Graphics()->DrawRect(TopBar, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRectSolid(TopBar, bordColor);

	// Left Bar
	WRECTF LeftBar = btnRec;
	LeftBar.Top(btnRec.Top() - 8);
	LeftBar.Left(btnRec.Left() - 8);
	LeftBar.Bottom(btnRec.Top() + GetHeight() / ExBordRatio + 15);
	LeftBar.Right(btnRec.Left() - 6);

	WGraphicsContainer::Graphics()->DrawRect(LeftBar, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRectSolid(LeftBar, bordColor);

	// Bottom Bar
	WRECTF BottomBar = btnRec;

	BottomBar.Top(btnRec.Bottom() + 6);
	BottomBar.Left(btnRec.Right() - GetWidth() / ExBordRatio - 15);
	BottomBar.Bottom(btnRec.Bottom() + 8);
	BottomBar.Right(btnRec.Right() + 8);

	WGraphicsContainer::Graphics()->DrawRect(BottomBar, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRectSolid(BottomBar, bordColor);

	// Right Bar
	WRECTF RightBar = btnRec;
	RightBar.Top(btnRec.Bottom() - GetHeight() / ExBordRatio - 15);
	RightBar.Left(btnRec.Right() + 6);
	RightBar.Bottom(btnRec.Bottom() + 8);
	RightBar.Right(btnRec.Right() + 8);

	WGraphicsContainer::Graphics()->DrawRect(RightBar, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRectSolid(RightBar, bordColor);

	WGraphicsContainer::Graphics()->DrawRect(btnRec, m_thickness, bordColor);
	WGraphicsContainer::Graphics()->FillRectSolid(btnRec, backColor);
	WGraphicsContainer::Graphics()->WriteText(btnRec, m_Content, m_conLen, m_family, m_fsize, foreColor);
}

WPointF WButton::Displace(W_FLOAT X, W_FLOAT Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WPointF(X, Y);
}

WPointF WButton::Displace(WPointF XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WPointF(XY.X(), XY.Y());
}

WRegistry* WButton::MouseDownRegistery(void)
{
	return BtnMouseDownRegistery;
}

WRegistry* WButton::MouseUpRegistery(void)
{
	return BtnMouseUpRegistery;
}

WRegistry* WButton::MouseEnterRegistery(void)
{
	return BtnMouseEnterRegistery;
}

WRegistry* WButton::MouseLeaveRegistery(void)
{
	return BtnMouseLeaveRegistery;
}

WRegistry* WButton::MouseRollUpRegistery(void)
{
	return BtnMouseRollUpRegistery;
}

WRegistry* WButton::MouseRollDownRegistery(void)
{
	return BtnMouseRollDownRegistery;
}

WRegistry* WButton::MouseDownRegistery(WRegistry* intake)
{
	BtnMouseDownRegistery = intake;
	return BtnMouseDownRegistery;
}

WRegistry* WButton::MouseUpRegistery(WRegistry* intake)
{
	BtnMouseUpRegistery = intake;
	return BtnMouseUpRegistery;
}

WRegistry* WButton::MouseEnterRegistery(WRegistry* intake)
{
	BtnMouseEnterRegistery = intake;
	return BtnMouseEnterRegistery;
}

WRegistry* WButton::MouseLeaveRegistery(WRegistry* intake)
{
	BtnMouseLeaveRegistery = intake;
	return BtnMouseLeaveRegistery;
}

WRegistry* WButton::MouseRollUpRegistery(WRegistry* intake)
{
	BtnMouseRollUpRegistery = intake;
	return BtnMouseRollUpRegistery;
}

WRegistry* WButton::MouseRollDownRegistery(WRegistry* intake)
{
	BtnMouseRollDownRegistery = intake;
	return BtnMouseRollDownRegistery;
}

W_INT WButton::ZIndex(void) const
{
	return m_zIndex;
}

bool WButton::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WButton::IsVisible(void) const
{
	return m_isVisible;
}

W_INT WButton::ZIndex(W_INT input)
{
	WControlHandler::Remove(this);
	m_zIndex = input;
	WControlHandler::Add(this);
	return m_zIndex;
}

bool WButton::IsEnabled(bool input)
{
	m_isEnabled = input;
	return m_isEnabled;
}

bool WButton::IsVisible(bool input)
{
	m_isVisible = input;
	return m_isVisible;
}

void WButton::MouseDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::MouseDown)
	{
		BtnMouseDownRegistery->Run(this, Args);
	}
}

void WButton::MouseUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::MouseUp)
	{
		BtnMouseUpRegistery->Run(this, Args);
	}
}

void WButton::MouseEnter(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WPointF p;
	p.X(WContainer::HCX());
	p.Y(WContainer::HCY());

	if (IsWithin(Args) && Args->State() == KeyState::NoClick && !Location().IsColliding(p))
	{
		if (IsShrinked && !IsExtending)
		{
			ExBordLerpShrink->Lock();
			IsExtending = true;
			ExBordLerpExtend->Perform();
		}
		BtnMouseEnterRegistery->Run(this, Args);
	}
}

void WButton::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WPointF p;
	p.X(WContainer::HCX());
	p.Y(WContainer::HCY());
	
	if (!IsWithin(Args) && Args->State() == KeyState::NoClick && Location().IsColliding(p))
	{
		if (!IsShrinking)
		{
			ExBordLerpExtend->Lock();
			ExBordLerpShrink->Unlock();
			IsShrinking = true;
			ExBordLerpShrink->Perform();
		}
		BtnMouseLeaveRegistery->Run(this, Args);
	}
}

void WButton::MouseRollUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
		BtnMouseRollUpRegistery->Run(this, Args);
	}
}

void WButton::MouseRollDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
		BtnMouseRollDownRegistery->Run(this, Args);
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

wchar_t * WButton::FontFamily(wchar_t* intake)
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

void WButton::UpdateRect(void)
{
	btnRec.Top(m_top);
	btnRec.Left(m_left);
	btnRec.Bottom(m_bottom);
	btnRec.Right(m_right);
}

bool WButton::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WButton::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}

W_INT WButton::GetWidth(void) const
{
	return btnRec.Right() - btnRec.Left();
}

W_INT WButton::GetHeight(void) const
{
	return btnRec.Bottom() - btnRec.Top();
}

void WButton::Extend(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
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
