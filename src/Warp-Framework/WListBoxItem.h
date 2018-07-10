// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LISTBOXITEM_H_
#define _W_LISTBOXITEM_H_

#include "WControl.h"

class WListBoxItem : public WControl
{
public:
	WListBoxItem(W_INT zIndex = 0);
	WListBoxItem(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WListBoxItem(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WListBoxItem(WRectF location, W_INT zIndex = 0);
	~WListBoxItem(void);

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
	wchar_t* FontFamily(void) const;
	wchar_t* Content(UINT32& outLen) const;
	W_FLOAT	FontSize(void) const;

// Setters
	wchar_t* FontFamily(wchar_t* intake);
	wchar_t* Content(wchar_t* content);
	wchar_t* Content(wchar_t* content, UINT32 Length);
	W_FLOAT	FontSize(W_FLOAT intake);

// Getters
	WTextAlignment Alignment(void) const;

// Setters
	WTextAlignment Alignment(WTextAlignment intake);
	
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
	wchar_t* m_Content;
	wchar_t* m_family;
	W_FLOAT m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	WTextAlignment m_alighment;
};
#endif // !_W_LISTBOX_H_