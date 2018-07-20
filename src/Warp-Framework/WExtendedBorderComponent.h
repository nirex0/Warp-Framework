// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_EXTENDED_BORDER_COMPONENT_H_
#define _W_EXTENDED_BORDER_COMPONENT_H_

#include "WControl.h"
#include "WLerp.h"

class WExtendedBorderComponent : public WControl
{
public:
	WExtendedBorderComponent(W_INT zIndex = 0);
	WExtendedBorderComponent(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WExtendedBorderComponent(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WExtendedBorderComponent(WRectF location, W_INT zIndex = 0);
	~WExtendedBorderComponent(void);

	W_FLOAT BorderThickness(W_FLOAT f);
	W_COLOR Color(W_COLOR col);

	W_FLOAT BorderThickness(void) const;
	W_COLOR Color(void) const;

	void Render(void) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

protected:
	// Dynamic Color
	void HoverBorderTick(WEntity* sender, WEventArgs* args);
	void HoverBorderDone(WEntity* sender, WEventArgs* args);

	void UnHoverBorderTick(WEntity* sender, WEventArgs* args);
	void UnHoverBorderDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorBord;
	WColorTransform* UnHoverColorBord;

	// Extended Border
	void Extend(WEntity* sender, WEventArgs* args);
	void Shrink(WEntity* sender, WEventArgs* args);

	void ExtendDone(WEntity* sender, WEventArgs* args);
	void ShrinkDone(WEntity* sender, WEventArgs* args);

	WLerp* ExBordLerpExtend;
	WLerp* ExBordLerpShrink;

	W_FLOAT ExBordRatio;

	// Normal
	W_FLOAT m_thickness;
	W_COLOR bordColor;
};

#endif // !_W_BUTTON_H_
