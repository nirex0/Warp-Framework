#include "WButton.h"

WButton::WButton()
	: m_thickness(1.0F)
	, foreColor(WColor(255, 255, 255, 255))
	, backColor(WColor(255, 0, 0, 0))
	, bordColor(WColor(255, 255, 255, 255))
{
	btnRec.top = m_top;
	btnRec.left = m_left;

	btnRec.bottom = m_bottom;
	btnRec.right = m_right;

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

	UpdateRect();
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
		D2D1::RoundedRect(D2D1::RectF(btnRec.left, btnRec.top, btnRec.right, btnRec.bottom), 15, 15),
		WGraphicsContainer::Graphics()->GetColorBrush(),
		m_thickness
	);

	WGraphicsContainer::Graphics()->GetColorBrush()->SetColor(backC);
	WGraphicsContainer::Graphics()->GetRenderTarget()->FillRoundedRectangle
	(
		D2D1::RoundedRect(D2D1::RectF(btnRec.left, btnRec.top, btnRec.right, btnRec.bottom), 15, 15),
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


void WButton::UpdateRect(void)
{
	btnRec.top = m_top;
	btnRec.left = m_left;
	btnRec.bottom = m_bottom;
	btnRec.right = m_right;
}
