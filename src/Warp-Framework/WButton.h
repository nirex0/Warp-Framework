// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_BUTTON_H_
#define _W_BUTTON_H_

#include "WControl.h"
#include "WLerp.h"

class WButton : public WControl
{
public:
	WButton(W_INT zIndex = 0);
	WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WButton(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WButton(WRectF location, W_INT zIndex = 0);
	~WButton(void);

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

// Events
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

// Getters
	wchar_t*				FontFamily(void) const;
	wchar_t*				Content(UINT32& outLen) const;
	W_FLOAT					FontSize(void) const;

// Setters
	wchar_t*				FontFamily(wchar_t* intake);
	wchar_t*				Content(wchar_t* content);
	wchar_t*				Content(wchar_t* content, UINT32 Length);
	W_FLOAT					FontSize(W_FLOAT intake);

// Extended Border
	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(bool intake);
	
protected:
// Extended Border
	void Extend(WEntity* sender, WEventArgs* args);
	void Shrink(WEntity* sender, WEventArgs* args);

	void ExtendDone(WEntity* sender, WEventArgs* args);
	void ShrinkDone(WEntity* sender, WEventArgs* args);

	bool IsExtended = false;
	bool IsShrinked = true;

	bool IsExtending = false;
	bool IsShrinking = false;

	WLerp* ExBordLerpExtend;
	WLerp* ExBordLerpShrink;

	W_FLOAT ExBordRatio;

	bool m_UseExtendedBorder;

// Normal
	wchar_t* m_Content;
	wchar_t* m_family;
	W_FLOAT m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;
};

#endif // !_W_BUTTON_H_
