#include "WButton.h"
#include "WControlHandler.h"

WButton::WButton()
	: m_thickness(1.0F)
	, foreColor(WColor(255, 255, 255, 255))
	, backColor(WColor(255, 0, 0, 0))
	, bordColor(WColor(255, 255, 255, 255))
{
	btnRec.top = (long)m_top;
	btnRec.left = (long)m_left;

	btnRec.bottom = (long)m_bottom;
	btnRec.right = (long)m_right;

	BtnClickRegistery = new WRegistry();
	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(float top, float left, float bottom, float right)
	: m_thickness(1.0F)
	, foreColor(WColor(255, 255, 255, 255))
	, backColor(WColor(255, 0, 0, 0))
	, bordColor(WColor(255, 255, 255, 255))
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	BtnClickRegistery = new WRegistry();
	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WCoordinates topleft, WCoordinates botright)
	: m_thickness(1.0F)
	, foreColor(WColor(255, 255, 255, 255))
	, backColor(WColor(255, 0, 0, 0))
	, bordColor(WColor(255, 255, 255, 255))
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	BtnClickRegistery = new WRegistry();
	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::WButton(WThickness location)
	: m_thickness(1.0F)
	, foreColor(WColor(255, 255, 255, 255))
	, backColor(WColor(255, 0, 0, 0))
	, bordColor(WColor(255, 255, 255, 255))
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	BtnClickRegistery = new WRegistry();
	BtnMouseDownRegistery = new WRegistry();
	BtnMouseUpRegistery = new WRegistry();
	BtnMouseEnterRegistery = new WRegistry();
	BtnMouseLeaveRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WButton::~WButton(void)
{
	delete BtnClickRegistery;
	delete BtnMouseDownRegistery;
	delete BtnMouseUpRegistery;
	delete BtnMouseEnterRegistery;
	delete BtnMouseLeaveRegistery;
}

WThickness WButton::Location(float top, float left, float bottom, float right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::Location(WCoordinates topleft, WCoordinates botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::Location(WThickness location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::RelLocation(float top, float left, float height, float width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::RelLocation(WCoordinates topleft, WCoordinates heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::RelLocation(WThickness location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = m_top + location.Bottom();
	m_right = m_left + location.Right();;

	UpdateRect();
	return WThickness(m_top, m_left, m_bottom, m_right);
}

WThickness WButton::Location(void) const
{
	return WThickness(m_top, m_left, m_bottom, m_right);
}

float WButton::BorderThickness(float f)
{
	m_thickness = f;
	return f;
}

float WButton::BorderRadius(float f)
{
	m_borderRad = f;
	return f;
}

WColor WButton::Foreground(WColor col)
{
	foreColor = col;
	return col;
}

WColor WButton::Background(WColor col)
{
	backColor = col;
	return col;
}

WColor WButton::BorderBrush(WColor col)
{
	bordColor = col;
	return col;
}

float WButton::BorderThickness(void) const
{
	return m_thickness;
}

float WButton::BorderRadius(void) const
{
	return m_borderRad;
}

WColor WButton::Foreground(void) const
{
	return foreColor;
}

WColor WButton::Background(void) const
{
	return backColor;
}

WColor WButton::BorderBrush(void) const
{
	return bordColor;
}

void WButton::Render()
{
	if (!m_isVisible)
		return;

	D2D1_COLOR_F textC;
	textC.a = (float)(foreColor.A()) / 255;
	textC.r = (float)(foreColor.R()) / 255;
	textC.g = (float)(foreColor.G()) / 255;
	textC.b = (float)(foreColor.B()) / 255;

	D2D1_COLOR_F backC;
	backC.a = (float)(backColor.A()) / 255;
	backC.r = (float)(backColor.R()) / 255;
	backC.g = (float)(backColor.G()) / 255;
	backC.b = (float)(backColor.B()) / 255;

	D2D1_COLOR_F bordC;
	bordC.a = (float)(bordColor.A()) / 255;
	bordC.r = (float)(bordColor.R()) / 255;
	bordC.g = (float)(bordColor.G()) / 255;
	bordC.b = (float)(bordColor.B()) / 255;

	D2D1_COLOR_F tmpCol(WGraphicsContainer::Graphics()->GetColorBrush()->GetColor());
	WGraphicsContainer::Graphics()->GetColorBrush()->SetColor(bordC);
	WGraphicsContainer::Graphics()->GetRenderTarget()->DrawRoundedRectangle
	(
		D2D1::RoundedRect(D2D1::RectF((float)btnRec.left, (float)btnRec.top, (float)btnRec.right, (float)btnRec.bottom), m_borderRad, m_borderRad),
		WGraphicsContainer::Graphics()->GetColorBrush(),
		m_thickness
	);

	WGraphicsContainer::Graphics()->GetColorBrush()->SetColor(backC);
	WGraphicsContainer::Graphics()->GetRenderTarget()->FillRoundedRectangle
	(
		D2D1::RoundedRect(D2D1::RectF((float)btnRec.left, (float)btnRec.top, (float)btnRec.right, (float)btnRec.bottom), m_borderRad, m_borderRad),
		WGraphicsContainer::Graphics()->GetColorBrush()

	);
	WGraphicsContainer::Graphics()->GetColorBrush()->SetColor(tmpCol);
}

WCoordinates WButton::Displace(float X, float Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WCoordinates(X, Y);
}

WCoordinates WButton::Displace(WCoordinates XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WCoordinates(XY.X(), XY.Y());
}

WRegistry* WButton::ClickRegistery(void)
{
	return BtnClickRegistery;
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

WRegistry* WButton::ClickRegistery(WRegistry* intake)
{
	BtnClickRegistery = intake;
	return BtnClickRegistery;
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

bool WButton::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WButton::IsVisible(void) const
{
	return m_isVisible;
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

void WButton::Click(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WBoundary bounds;

	bounds.Top(this->Location().Top());
	bounds.Left(this->Location().Left());
	bounds.Bottom(this->Location().Bottom());
	bounds.Right(this->Location().Right());

	if (bounds.IsColliding(*(Args->Point())))
	{
		BtnClickRegistery->Run(this, Args);
	}

}

void WButton::MouseDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	WBoundary bounds;

	bounds.Top(this->Location().Top());
	bounds.Left(this->Location().Left());
	bounds.Bottom(this->Location().Bottom());
	bounds.Right(this->Location().Right());
	
	if (bounds.IsColliding(*(Args->Point())) && Args->State() == KeyState::MouseDown)
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

	WBoundary bounds;

	bounds.Top(this->Location().Top());
	bounds.Left(this->Location().Left());
	bounds.Bottom(this->Location().Bottom());
	bounds.Right(this->Location().Right());

	if (bounds.IsColliding(*(Args->Point())) && Args->State() == KeyState::MouseUp)
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

	WBoundary bounds;

	bounds.Top(this->Location().Top());
	bounds.Left(this->Location().Left());
	bounds.Bottom(this->Location().Bottom());
	bounds.Right(this->Location().Right());

	if (bounds.IsColliding(*(Args->Point())) && Args->State() == KeyState::NoClick)
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

	WBoundary bounds;

	bounds.Top(this->Location().Top());
	bounds.Left(this->Location().Left());
	bounds.Bottom(this->Location().Bottom());
	bounds.Right(this->Location().Right());

	if (!bounds.IsColliding(*(Args->Point())) && Args->State() == KeyState::NoClick)
	{
		BtnMouseLeaveRegistery->Run(this, Args);
	}
}


void WButton::UpdateRect(void)
{
	btnRec.top = (long)m_top;
	btnRec.left = (long)m_left;
	btnRec.bottom = (long)m_bottom;
	btnRec.right = (long)m_right;
}


