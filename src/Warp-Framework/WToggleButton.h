// � 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_TOGGLE_BUTTON_H_
#define _W_TOGGLE_BUTTON_H_

#include "WControl.h"
#include "WLerp.h"

class WToggleButton : public WControl
{
public:
	WToggleButton(const W_INT& zIndex = 0);
	WToggleButton(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WToggleButton(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WToggleButton(const WRectF& location, const W_INT& zIndex = 0);
	~WToggleButton(void);

	W_FLOAT BorderThickness(const W_FLOAT& f);
	W_COLOR Foreground(const W_COLOR& col);
	W_COLOR Background(const W_COLOR& col);
	W_COLOR BorderBrush(const W_COLOR& col);
	
	W_FLOAT BorderThickness(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	void Render(void) override;

	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	bool Value(void) const;
	bool Value(const bool& intake);

protected:
	// Dynamic Movement
	WRectF m_transitLocation;
	bool m_isTransitioning;

	void ToLeftTick(WEntity* sender, WEventArgs* args);
	void ToRightTick(WEntity* sender, WEventArgs* args);

	void ToLeftDone(WEntity* sender, WEventArgs* args);
	void ToRightDone(WEntity* sender, WEventArgs* args);

	WLerp* LerpToLeft;
	WLerp* LerpToRight;

	// Dynamic Color
	void HoverBorderTick(WEntity* sender, WEventArgs* args);
	void HoverBorderDone(WEntity* sender, WEventArgs* args);

	void UnHoverBorderTick(WEntity* sender, WEventArgs* args);
	void UnHoverBorderDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorBord;
	WColorTransform* UnHoverColorBord;

	void HoverForegroundTick(WEntity* sender, WEventArgs* args);
	void HoverForegroundDone(WEntity* sender, WEventArgs* args);

	void UnHoverForegroundTick(WEntity* sender, WEventArgs* args);
	void UnHoverForegroundDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorFore;
	WColorTransform* UnHoverColorFore;

	void HoverBackgroundTick(WEntity* sender, WEventArgs* args);
	void HoverBackgroundDone(WEntity* sender, WEventArgs* args);

	void UnHoverBackgroundTick(WEntity* sender, WEventArgs* args);
	void UnHoverBackgroundDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorBack;
	WColorTransform* UnHoverColorBack;
	
	// Normal
	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	// Toggle
	bool m_bIsOn;
};

#endif // !_W_TOGGLE_BUTTON_H_
