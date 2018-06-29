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
#include "WLerp.h"
#include "WColorTransform.h"

class WButton : public IControl
{
public:
	WButton(W_INT zIndex = 0);
	WButton(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WButton(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WButton(WRectF location, W_INT zIndex = 0);
	~WButton(void);

	// Setters
	WRectF Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right);
	WRectF Location(WPointF topleft, WPointF botright);
	WRectF Location(WRectF location);
		 
	WRectF RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width);
	WRectF RelLocation(WPointF topleft, WPointF heightwidth);
	WRectF RelLocation(WRectF location);

	// Getters
	WRectF Location(void) const;
	
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

	WPointF Displace(W_FLOAT X, W_FLOAT Y);
	WPointF Displace(WPointF XY);

	// Getters
	WRegistry* MouseDownRegistery(void);
	WRegistry* MouseUpRegistery(void);
	WRegistry* MouseEnterRegistery(void);
	WRegistry* MouseLeaveRegistery(void);
	WRegistry* MouseRollUpRegistery(void);
	WRegistry* MouseRollDownRegistery(void);

	// Setters
	WRegistry* MouseDownRegistery(WRegistry* intake);
	WRegistry* MouseUpRegistery(WRegistry* intake);
	WRegistry* MouseEnterRegistery(WRegistry* intake);
	WRegistry* MouseLeaveRegistery(WRegistry* intake);
	WRegistry* MouseRollUpRegistery(WRegistry* intake);
	WRegistry* MouseRollDownRegistery(WRegistry* intake);

	// Getters
	W_INT ZIndex(void) const override;
	bool IsEnabled(void) const override;
	bool IsVisible(void) const override;

	// Setters
	W_INT ZIndex(W_INT input) override;
	bool IsEnabled(bool input) override;
	bool IsVisible(bool input) override;

	// Events
	void MouseDown(WMouseArgs* Args) override;
	void MouseUp(WMouseArgs* Args) override;
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;
	void MouseRollUp(WMouseArgs* Args) override;
	void MouseRollDown(WMouseArgs* Args) override;

	// Parent
	IControl* Parent(IControl* intake);
	IControl* Parent(void) const;

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
	void UpdateRect(void);
	bool IsWithin(WMouseArgs* Args) const;
	void SetZIndexNoChange(W_INT zIndex) override;
	W_INT GetWidth(void) const;
	W_INT GetHeight(void) const;

	// Extended Border
	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(bool intake);
	
private:
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
	W_INT m_zIndex;

	wchar_t* m_Content;
	wchar_t* m_family;
	W_FLOAT m_fsize = 14.0F;
	UINT32 m_conLen = 0;

	bool m_isEnabled;
	bool m_isVisible;
	
	W_FLOAT m_top;
	W_FLOAT m_left;
	W_FLOAT m_bottom;
	W_FLOAT m_right;
	
	W_FLOAT m_thickness;

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

	IControl* m_Parent;
};

#endif // !_W_BUTTON_H_
