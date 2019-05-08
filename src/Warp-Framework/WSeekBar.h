// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_SEEK_BAR_H_
#define _W_SEEK_BAR_H_

#include "WControl.h"
#include "WLerp.h"

class WSeekBar : public WControl
{
public:
	WSeekBar(const W_INT& zIndex = 0);
	WSeekBar(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WSeekBar(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WSeekBar(const WRectF& location, const W_INT& zIndex = 0);
	~WSeekBar(void);

	W_FLOAT BorderThickness(const W_FLOAT& f);
	W_COLOR Foreground(const W_COLOR& col);
	W_COLOR Background(const W_COLOR& col);
	W_COLOR BorderBrush(const W_COLOR& col);

	W_FLOAT BorderThickness(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	void Render(void) override;

	virtual WRegistry* ValueChangeRegistery(void);

	virtual WRegistry* ValueChangeRegistery(WRegistry* intake);

	void MouseDown(WMouseArgs* Args) override;
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;
	void ValueChange(W_FLOAT value);

	W_FLOAT	Value(void) const;
	bool IsVertical(void) const;

	W_FLOAT	Value(const W_FLOAT& intake);
	bool IsVertical(const bool& intake);

protected:
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
	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	bool m_isVertical;
	bool m_shouldSeek;

	// Seek Bar
	WRegistry* WSCValueChangeRegistery;
};

#endif // !_W_SEEK_BAR_H_