//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_BUTTON_H_
#define _W_BUTTON_H_

#include "WGFXContainer.h"

#include "WRECTF.h"
#include "IControl.h"
#include "WPoint.h"
#include "WRect.h"
#include "WContainer.h"

#include "WMouse.h"

class WButton : public IControl
{
public:
	WButton(W_INT zIndex = 0);
	WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WButton(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WButton(WRectF location, W_INT zIndex = 0);
	~WButton(void);

	// Setters
	WRectF Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right) override;
	WRectF Location(WPointF topleft, WPointF botright) override;
	WRectF Location(WRectF location);
		 
	WRectF RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width) override;
	WRectF RelLocation(WPointF topleft, WPointF heightwidth) override;
	WRectF RelLocation(WRectF location) override;

	// Getters
	WRectF Location(void) const override;
	
	// Setters
	W_FLOAT BorderThickness(W_FLOAT f);
	W_FLOAT BorderRadius(W_FLOAT f);
	W_COLOR Foreground(W_COLOR col);
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

	// Getters
	W_FLOAT BorderThickness(void) const;
	W_FLOAT BorderRadius(void) const;
	W_COLOR Foreground(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	// Functions
	void Render(void) override;
	void UpdateRect(void);

	WPointF Displace(W_FLOAT X, W_FLOAT Y) override;
	WPointF Displace(WPointF XY) override;

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
	W_INT ZIndex(void) const;
	bool IsEnabled(void) const override;
	bool IsVisible(void) const override;
	bool AutoRender(void) const override;

	// Setters
	W_INT ZIndex(W_INT input);
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
	W_FLOAT					FontSize(void) const;

	// Setters
	wchar_t*				FontFamily(wchar_t* intake);
	wchar_t*				Content(wchar_t* content);
	wchar_t*				Content(wchar_t* content, UINT32 Length);
	W_FLOAT					FontSize(W_FLOAT intake);

	// Helpers
	bool IsWithin(WMouseArgs* Args) const;
	void SetZIndexNoChange(W_INT zIndex);

private:
	W_INT m_zIndex;

	wchar_t* m_Content;
	wchar_t* m_family;
	W_FLOAT m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	bool m_isEnabled;
	bool m_isVisible;
	bool m_autoRender;

	W_FLOAT m_top;
	W_FLOAT m_left;
	W_FLOAT m_bottom;
	W_FLOAT m_right;
	
	W_FLOAT m_thickness;
	W_FLOAT m_borderRad;

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
