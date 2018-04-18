#ifndef _W_BUTTON_H_
#define _W_BUTTON_H_

#include "WGFXContainer.h"

#include "WCoordinates.h"
#include "WThickness.h"

class WButton
{
public:
	WButton();
	WButton(float top, float left, float bottom, float right);
	WButton(WCoordinates topleft, WCoordinates botright);
	WButton(WThickness location);

	// Setters
	WThickness Location(float top, float left, float bottom, float right);
	WThickness Location(WCoordinates topleft, WCoordinates botright);
	WThickness Location(WThickness location);

	WThickness RelLocation(float top, float left, float height, float width);
	WThickness RelLocation(WCoordinates topleft, WCoordinates heightwidth);
	WThickness RelLocation(WThickness location);

	// Getters
	WThickness Location(void) const;

	// Setters
	float BorderThickness(float f);
	float BorderRadius(float f);
	WColor Foreground(WColor col);
	WColor Background(WColor col);
	WColor BorderBrush(WColor col);

	// Getters
	float BorderThickness(void) const;
	float BorderRadius(void) const;
	WColor Foreground(void) const;
	WColor Background(void) const;
	WColor BorderBrush(void) const;

	// Functions
	void Render();
	void UpdateRect(void);

	WCoordinates Displace(float X, float Y);
	WCoordinates Displace(WCoordinates XY);

private:
	float m_top;
	float m_left;
	float m_bottom;
	float m_right;
	
	float m_thickness;
	float m_borderRad;

	WColor foreColor;
	WColor backColor;
	WColor bordColor;

	RECT btnRec;
};

#endif // !_W_BUTTON_H_
