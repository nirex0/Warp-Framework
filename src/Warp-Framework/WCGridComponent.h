// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_C_GRID_COMPONENT_H_
#define _W_C_GRID_COMPONENT_H_

#include "WControl.h"
#include "WLerp.h"

class WCGridComponent : public WControl
{
public:
	WCGridComponent(W_INT zIndex = 0);
	WCGridComponent(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WCGridComponent(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WCGridComponent(WRectF location, W_INT zIndex = 0);
	~WCGridComponent(void) = default;

	W_FLOAT SquareSize(W_FLOAT f);
	W_FLOAT LineThickness(W_FLOAT f);
	W_COLOR Color(W_COLOR col);

	W_FLOAT SquareSize(void) const;
	W_FLOAT LineThickness(void) const;
	W_COLOR Color(void) const;

	void Render(void) override;

protected:
	W_FLOAT m_sqSize;
	W_FLOAT m_thickness;
	W_COLOR m_color;
};

#endif // !_W_C_GRID_COMPONENT_H_
