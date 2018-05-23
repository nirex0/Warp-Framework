#include "WButton.h"
#include "WControlHandler.h"

WButton::WButton(W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
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

	m_isEnabled = true;
	m_isVisible = true;
	m_autoRender = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
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

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;
	m_autoRender = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WPointF topleft, WPointF botright, W_INT zIndex)
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

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;
	m_autoRender = true;

	m_family = L"Arial";

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WRectF location, W_INT zIndex)
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

	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;
	m_autoRender = true;

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

W_FLOAT WButton::BorderRadius(W_FLOAT f)
{
	m_borderRad = f;
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

W_FLOAT WButton::BorderRadius(void) const
{
	return m_borderRad;
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

	WGraphicsContainer::Graphics()->DrawRoundRect(btnRec, m_thickness, m_borderRad, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(btnRec, m_borderRad, backColor);
	WGraphicsContainer::Graphics()->WriteText(btnRec, m_Content, m_conLen, m_family, m_fsize, foreColor);
}

void WButton::UpdateRect(void)
{
	btnRec.Top(m_top);
	btnRec.Left(m_left);
	btnRec.Bottom(m_bottom);
	btnRec.Right(m_right);
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

bool WButton::AutoRender(void) const
{
	return m_autoRender;
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

bool WButton::AutoRender(bool input)
{
	m_autoRender = input;
	return m_autoRender;
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

	if (IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
		BtnMouseEnterRegistery->Run(this, Args);
	}
}

void WButton::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;
	
	if (!IsWithin(Args) && Args->State() == KeyState::NoClick)
	{
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

bool WButton::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WButton::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}
