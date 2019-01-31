// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_PROGRESS_BAR_H_
#define _W_PROGRESS_BAR_H_

#include "WControl.h"
#include "WLerp.h"

class WProgressBar : public WControl
{
public:
	WProgressBar(W_INT zIndex = 0);
	WProgressBar(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WProgressBar(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WProgressBar(WRectF location, W_INT zIndex = 0);
	~WProgressBar(void);

	W_FLOAT BorderThickness(W_FLOAT f);
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

	W_FLOAT BorderThickness(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	void Render(void) override;
	void ChangeValue(W_FLOAT intake);

	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	W_FLOAT	Value(void) const;
	W_FLOAT	MaxValue(void) const;

	W_FLOAT Value(W_FLOAT intake);
	W_FLOAT MaxValue(W_FLOAT intake);

protected:
	void ChangeTick(WEntity* sender, WEventArgs* args);
	void ChangeDone(WEntity* sender, WEventArgs* args);
	WLerp* ChangeLerp;

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

	W_FLOAT m_value;
	W_FLOAT m_maxValue;
	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;
};

#endif // !_W_PROGRESS_BAR_H_
