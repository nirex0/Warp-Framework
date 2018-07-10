// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CHECKBOX_H_
#define _W_CHECKBOX_H_

#include "WControl.h"

class WCheckBox : public WControl
{
public:
	WCheckBox(W_INT zIndex = 0);
	WCheckBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WCheckBox(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WCheckBox(WRectF location, W_INT zIndex = 0);
	~WCheckBox(void);

// Setters
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

// Getters
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

// Functions
	void Render(void) override;

// Events
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

// Getters
	bool Checked(void) const;
	bool ShowBorder(void) const;
	wchar_t* FontFamily(void) const;
	wchar_t* Content(UINT32& outLen) const;
	W_FLOAT	FontSize(void) const;


// Setters
	bool Checked(bool intake);
	bool ShowBorder(bool intake);
	wchar_t* FontFamily(wchar_t* intake);
	wchar_t* Content(wchar_t* content);
	wchar_t* Content(wchar_t* content, UINT32 Length);
	W_FLOAT	FontSize(W_FLOAT intake);

// Checkbox
	void ToggleBorder(void);
	void ToggleValue(void);

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

	bool m_DrawBorders;
	bool m_isChecked;

	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	
};

#endif // !_W_CHECKBOX_H_
