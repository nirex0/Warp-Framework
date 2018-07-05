// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LISTBOX_H_
#define _W_LISTBOX_H_

#include <vector>

#include "WControl.h"
#include "WLerp.h"
#include "WListBoxItem.h"

class WListBox : public WControl
{
public:
	WListBox(W_INT zIndex = 0);
	WListBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WListBox(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WListBox(WRectF location, W_INT zIndex = 0);
	~WListBox(void);
	
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

// Events
	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;
	void MouseRollUp(WMouseArgs* Args) override;
	void MouseRollDown(WMouseArgs* Args) override;

// Extended Border
	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(bool intake);
	
// Items
	WListBoxItem* CreateItem(W_COLOR background, W_COLOR foreground, W_COLOR borderbrush, wchar_t* fontFamily = L"Arial", wchar_t* content = L"ListBox Item", W_FLOAT fontSize = 14, WTextAlignment alignment = WTA_Center);
	WListBoxItem* CreateItem(wchar_t* fontFamily = L"Arial", wchar_t* content = L"ListBox Item", W_FLOAT fontSize = 14, WTextAlignment alignment = WTA_Center);
	int ItemCount(void) const;

	int RemoveLast(void);
	int AddItem(WListBoxItem* item);
	WListBoxItem* GetLast(void);
	WListBoxItem* GetAt(int index);

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

// Extended Border
	void Extend(WEntity* sender, WEventArgs* args);
	void Shrink(WEntity* sender, WEventArgs* args);

	void ExtendDone(WEntity* sender, WEventArgs* args);
	void ShrinkDone(WEntity* sender, WEventArgs* args);

	WLerp* ExBordLerpExtend;
	WLerp* ExBordLerpShrink;

	W_FLOAT ExBordRatio;

	bool m_UseExtendedBorder;

// Normal
	W_FLOAT m_thickness;

	W_COLOR foreColor;
	W_COLOR backColor;
	W_COLOR bordColor;

// Items
	void RenewItems(void);

	std::vector<WListBoxItem*> m_items;
	W_INT m_itemCount = 0;
	W_INT m_yDisplace = 0;
	W_INT m_DisplaceSpeed = 20;
	W_INT m_ListItemHeight = 30;
};
#endif // !_W_LISTBOX_H_