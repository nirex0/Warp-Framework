// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SEEK_BAR_H_
#define _W_SEEK_BAR_H_

#include "WControl.h"
#include "WLerp.h"

class WSeekBar : public WControl
{
public:
	WSeekBar(W_INT zIndex = 0);
	WSeekBar(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WSeekBar(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WSeekBar(WRectF location, W_INT zIndex = 0);
	~WSeekBar(void);

// Setters
	W_FLOAT BorderThickness(W_FLOAT f);
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

// Getters
	W_FLOAT BorderThickness(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

// Functions
	void Render(void) override;
	void ChangeValue(W_FLOAT intake);

// Events
	void MouseDown(WMouseArgs* Args) override;
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

// Getters
	W_FLOAT	Value(void) const;
	W_FLOAT	MaxValue(void) const;

// Setters
	W_FLOAT MaxValue(W_FLOAT intake);

protected:
// Dynamic Value
	void ChangeTick(WEntity* sender, WEventArgs* args);
	void ChangeDone(WEntity* sender, WEventArgs* args);
	WLerp* ChangeLerp;

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
	W_FLOAT m_value;
	W_FLOAT m_offset;
	W_FLOAT m_maxValue;
	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	bool m_shouldSeek = 0;
};

#endif // !_W_SEEK_BAR_H_