// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LABEL_H_
#define _W_LABEL_H_

#include "WControl.h"

class WLabel : public WControl
{
public:
	WLabel(W_INT zIndex = 0);
	WLabel(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WLabel(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WLabel(WRectF location, W_INT zIndex = 0);
	~WLabel(void);

	W_COLOR Foreground(W_COLOR col);
	W_COLOR Foreground(void) const;

	void Render(void) override;

	void MouseEnter(WMouseArgs* Args) override;
	void MouseLeave(WMouseArgs* Args) override;

	std::wstring FontFamily(void) const;
	std::wstring Content(void) const;
	W_FLOAT	FontSize(void) const;

	std::wstring FontFamily(std::wstring intake);
	std::wstring Content(std::wstring content);
	W_FLOAT	FontSize(W_FLOAT intake);

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