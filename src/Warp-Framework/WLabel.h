// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LABEL_H_
#define _W_LABEL_H_

#include "WControl.h"

class WLabel : public WControl
{
public:
	WLabel(const W_INT& zIndex = 0);
	WLabel(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WLabel(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WLabel(const WRectF& location, const W_INT& zIndex = 0);
	~WLabel(void);

	W_COLOR Foreground(const W_COLOR& col);
	W_COLOR Foreground(void) const;

	void Render(void) override;

	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	std::wstring FontFamily(void) const;
	std::wstring Content(void) const;
	W_FLOAT	FontSize(void) const;

	std::wstring FontFamily(const std::wstring& intake);
	std::wstring Content(const std::wstring& content);
	W_FLOAT	FontSize(const W_FLOAT& intake);

private:
	// Dynamic Color
	void HoverForegroundTick(WEntity* sender, WEventArgs* args);
	void HoverForegroundDone(WEntity* sender, WEventArgs* args);

	void UnHoverForegroundTick(WEntity* sender, WEventArgs* args);
	void UnHoverForegroundDone(WEntity* sender, WEventArgs* args);

	WColorTransform* HoverColorFore;
	WColorTransform* UnHoverColorFore;

	// Normal
	std::wstring m_Content;
	std::wstring m_family;
	W_FLOAT m_fsize = 14.0F;

	W_COLOR foreColor;
};

#endif // !_W_LABEL_H_