//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LISTBOX_H_
#define _W_LISTBOX_H_

#include <vector>

#include "WGFXContainer.h"
#include "WRECTF.h"
#include "IControl.h"
#include "WPoint.h"
#include "WRect.h"
#include "WContainer.h"
#include "WMouse.h"
#include "WLerp.h"
#include "WListBoxItem.h"

class WListBox : public IControl
{
public:
	WListBox(W_INT zIndex = 0);
	WListBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WListBox(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WListBox(WRectF location, W_INT zIndex = 0);
	~WListBox(void);

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
	W_COLOR Background(W_COLOR col);
	W_COLOR BorderBrush(W_COLOR col);

	// Getters
	W_FLOAT BorderThickness(void) const;
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
	
	// Helpers
	void UpdateRect(void);
	bool IsWithin(WMouseArgs* Args) const;
	void SetZIndexNoChange(W_INT zIndex) override;
	W_INT GetWidth(void) const;
	W_INT GetHeight(void) const;

	// Extended Border
	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(bool intake);
	
	// Items
	WListBoxItem* CreateItem(W_COLOR background, W_COLOR foreground, W_COLOR borderbrush, wchar_t* fontFamily = L"Arial", wchar_t* content = L"ListBox Item", W_FLOAT fontSize = 14, WTextAlignment alignment = WTA_Center);
	int ItemCount(void) const;

	int RemoveLast(void);
	int AddItem(WListBoxItem* item);
	WListBoxItem* GetLast(void);
	WListBoxItem* GetAt(int index);


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

	WRECTF lbRec;

	WRegistry* LBMouseDownRegistery;
	WRegistry* LBMouseUpRegistery;
			   
	WRegistry* LBMouseEnterRegistery;
	WRegistry* LBMouseLeaveRegistery;
			   
	WRegistry* LBMouseRollUpRegistery;
	WRegistry* LBMouseRollDownRegistery;

	IControl* m_Parent;

	// Items
	void RenewItems(void);

	std::vector<WListBoxItem*> m_items;
	W_INT m_itemCount = 0;
	W_INT m_yDisplace = 0;
	W_INT m_DisplaceSpeed = 20;
	W_INT m_ListItemHeight = 30;
	bool m_isMouseDown;
};
#endif // !_W_LISTBOX_H_