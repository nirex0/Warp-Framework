//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_BUTTON_H_
#define _W_BUTTON_H_

#include "WGFXContainer.h"

#include "WRECTF.h"
#include "IControl.h"
#include "WCoordinates.h"
#include "WThickness.h"
#include "WBoundary.h"
#include "WContainer.h"

#include "WMouse.h"

class WButton : public IControl
{
public:
	WButton(int zIndex);
	WButton(float top, float left, float bottom, float right, int zIndex);
	WButton(WCoordinates topleft, WCoordinates botright, int zIndex);
	WButton(WThickness location, int zIndex);
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
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

	// Getters
	float BorderThickness(void) const;
	float BorderRadius(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	// Functions
	void Render(void) override;
	void UpdateRect(void);

	WCoordinates Displace(float X, float Y) override;
	WCoordinates Displace(WCoordinates XY) override;

	// Getters
	WRegistry* MouseDownRegistery(void) override;
	WRegistry* MouseUpRegistery(void) override;
	WRegistry* MouseEnterRegistery(void) override;
	WRegistry* MouseLeaveRegistery(void) override;
	WRegistry* MouseRollUpRegistery(void) override;
	WRegistry* MouseRollDownRegistery(void) override;

	// Setters
	WRegistry* MouseDownRegistery(WRegistry* intake) override;
	WRegistry* MouseUpRegistery(WRegistry* intake) override;
	WRegistry* MouseEnterRegistery(WRegistry* intake) override;
	WRegistry* MouseLeaveRegistery(WRegistry* intake) override;
	WRegistry* MouseRollUpRegistery(WRegistry* intake) override;
	WRegistry* MouseRollDownRegistery(WRegistry* intake) override;

	// Getters
	int ZIndex(void) const;
	bool IsEnabled(void) const override;
	bool IsVisible(void) const override;
	bool AutoRender(void) const override;

	// Setters
	int ZIndex(int input);
	bool IsEnabled(bool input) override;
	bool IsVisible(bool input) override;
	bool AutoRender(bool input) override;

	// Events
	void MouseDown(WMouseArgs* Args) override;
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;
	void MouseRollUp(WMouseArgs* Args) override;
	void MouseRollDown(WMouseArgs* Args) override;

	// Getters
	wchar_t*				FontFamily(void) const;
	wchar_t*				Content(UINT32& outLen) const;
	float					FontSize(void) const;

	// Setters
	wchar_t*				FontFamily(wchar_t* intake);
	wchar_t*				Content(wchar_t* content);
	wchar_t*				Content(wchar_t* content, UINT32 Length);
	float					FontSize(float intake);

	// Helpers
	bool IsWithin(WMouseArgs* Args) const;
	void SetZIndexNoChange(int zIndex);

private:
	int m_zIndex;

	wchar_t* m_Content;
	wchar_t* m_family;
	float m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	bool m_isEnabled;
	bool m_isVisible;
	bool m_autoRender;

	float m_top;
	float m_left;
	float m_bottom;
	float m_right;
	
	float m_thickness;
	float m_borderRad;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

	WRECTF btnRec;

	WRegistry* BtnMouseDownRegistery;
	WRegistry* BtnMouseUpRegistery;

	WRegistry* BtnMouseEnterRegistery;
	WRegistry* BtnMouseLeaveRegistery;

	WRegistry* BtnMouseRollUpRegistery;
	WRegistry* BtnMouseRollDownRegistery;


};

#endif // !_W_BUTTON_H_
