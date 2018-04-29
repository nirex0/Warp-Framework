//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_BUTTON_H_
#define _W_BUTTON_H_

#include "WGFXContainer.h"

#include "IControl.h"
#include "WCoordinates.h"
#include "WThickness.h"
#include "WBoundary.h"
#include "WContainer.h"

#include "WMouse.h"

class WButton : public IControl
{
public:
	WButton();
	WButton(float top, float left, float bottom, float right);
	WButton(WCoordinates topleft, WCoordinates botright);
	WButton(WThickness location);
	~WButton(void);

	// Setters
	WThickness Location(float top, float left, float bottom, float right) override;
	WThickness Location(WCoordinates topleft, WCoordinates botright) override;
	WThickness Location(WThickness location);

	WThickness RelLocation(float top, float left, float height, float width) override;
	WThickness RelLocation(WCoordinates topleft, WCoordinates heightwidth) override;
	WThickness RelLocation(WThickness location) override;

	// Getters
	WThickness Location(void) const override;
	
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

	WCoordinates Displace(float X, float Y) override;
	WCoordinates Displace(WCoordinates XY) override;

	// Getters
	WRegistry* ClickRegistery(void) override;
	WRegistry* MouseDownRegistery(void) override;
	WRegistry* MouseUpRegistery(void) override;
	WRegistry* MouseEnterRegistery(void) override;
	WRegistry* MouseLeaveRegistery(void) override;

	// Setters
	WRegistry* ClickRegistery(WRegistry* intake) override;
	WRegistry* MouseDownRegistery(WRegistry* intake) override;
	WRegistry* MouseUpRegistery(WRegistry* intake) override;
	WRegistry* MouseEnterRegistery(WRegistry* intake) override;
	WRegistry* MouseLeaveRegistery(WRegistry* intake) override;

	// Getters
	bool IsEnabled(void) const override;
	bool IsVisible(void) const override;

	// Setters
	bool IsEnabled(bool input) override;
	bool IsVisible(bool input) override;

	// Events
	void Click(WMouseArgs* Args) override;
	void MouseDown(WMouseArgs* Args) override;
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	// Getters
	wchar_t*				FontFamily(void) const;
	wchar_t*				Content(UINT32& outLen) const;
	float					FontSize(void) const;

	// Setters
	wchar_t*				FontFamily(wchar_t* intake);
	wchar_t*				Content(wchar_t* familyName, UINT32 Length);
	float					FontSize(float intake);

private:
	wchar_t* m_Content;
	wchar_t* m_family;
	float m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	bool m_isEnabled;
	bool m_isVisible;

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

	WRegistry* BtnClickRegistery;
	WRegistry* BtnMouseDownRegistery;
	WRegistry* BtnMouseUpRegistery;

	WRegistry* BtnMouseEnterRegistery;
	WRegistry* BtnMouseLeaveRegistery;

};

#endif // !_W_BUTTON_H_
