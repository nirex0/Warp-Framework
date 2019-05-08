// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LISTBOX_H_
#define _W_LISTBOX_H_

#include <vector>

#include "WControl.h"
#include "WLerp.h"
#include "WListBoxItem.h"

class WListBox : public WControl
{
public:
	WListBox(const W_INT& zIndex = 0);
	WListBox(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WListBox(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WListBox(const WRectF& location, const W_INT& zIndex = 0);
	~WListBox(void);

	W_FLOAT BorderThickness(const W_FLOAT& f);
	W_COLOR Background(const W_COLOR& col);
	W_COLOR BorderBrush(const W_COLOR& col);

	W_FLOAT BorderThickness(void) const;
	W_COLOR Background(void) const;
	W_COLOR BorderBrush(void) const;

	void Render(void) override;

	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;
	void MouseRollUp(WMouseArgs* Args) override;
	void MouseRollDown(WMouseArgs* Args) override;

	bool UseExtendedBorder(void) const;
	bool UseExtendedBorder(const bool& intake);

	WListBoxItem* CreateItem(const W_COLOR& background, const W_COLOR& foreground, const W_COLOR& borderbrush, wchar_t* fontFamily = L"Arial", wchar_t* content = L"ListBox Item", const W_FLOAT& fontSize = 14, const WTextAlignment& alignment = WTA_Center);
	WListBoxItem* CreateItem(wchar_t* content = L"ListBox Item", wchar_t* fontFamily = L"Arial", W_FLOAT fontSize = 14, WTextAlignment alignment = WTA_Center);
	int ItemCount(void) const;

	int RemoveLast(void);
	WListBoxItem* GetLast(void);
	WListBoxItem* GetAt(const int& index);

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