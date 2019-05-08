// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTROL_H_
#define _W_CONTROL_H_

#include "WGFXContainer.h"
#include "WRect.h"
#include "IControl.h"
#include "WPoint.h"
#include "WRect.h"
#include "WContainer.h"
#include "WMouse.h"
#include "WColorTransform.h"

class WControl : public IControl
{
public:
	WControl(const W_INT& zIndex = 0);
	WControl(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WControl(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WControl(const WRectF& location, const W_INT& zIndex = 0);
	virtual ~WControl(void);

	virtual WRectF Location(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right);
	virtual WRectF Location(const WPointF& topleft, const WPointF& botright);
	virtual WRectF Location(const WRectF& location);

	virtual WRectF RelLocation(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& height, const W_FLOAT& width);
	virtual WRectF RelLocation(const WPointF& topleft, const WPointF& heightwidth);
	virtual WRectF RelLocation(const WRectF& location);

	virtual WRectF Location(void) const;

	virtual void Render(void) override = 0;

	virtual WPointF Displace(const W_FLOAT& X, const W_FLOAT& Y);
	virtual WPointF Displace(const WPointF& XY);

	virtual WRegistry* KeyDownRegistery(void);
	virtual WRegistry* KeyUpRegistery(void);
	virtual WRegistry* KeyCharRegistery(void);
	virtual WRegistry* MouseDownRegistery(void);
	virtual WRegistry* MouseUpRegistery(void);
	virtual WRegistry* MouseEnterRegistery(void);
	virtual WRegistry* MouseLeaveRegistery(void);
	virtual WRegistry* MouseRollUpRegistery(void);
	virtual WRegistry* MouseRollDownRegistery(void);

	virtual WRegistry* KeyDownRegistery(WRegistry* intake);
	virtual WRegistry* KeyUpRegistery(WRegistry* intake);
	virtual WRegistry* KeyCharRegistery(WRegistry* intake);
	virtual WRegistry* MouseDownRegistery(WRegistry* intake);
	virtual WRegistry* MouseUpRegistery(WRegistry* intake);
	virtual WRegistry* MouseEnterRegistery(WRegistry* intake);
	virtual WRegistry* MouseLeaveRegistery(WRegistry* intake);
	virtual WRegistry* MouseRollUpRegistery(WRegistry* intake);
	virtual WRegistry* MouseRollDownRegistery(WRegistry* intake);

	virtual W_INT ZIndex(void) const override;
	virtual bool IsActive(void) const override;
	virtual bool IsEnabled(void) const override;
	virtual bool IsVisible(void) const override;

	virtual W_INT ZIndex(const W_INT& input) override;
	virtual bool IsActive(const bool& input) override;
	virtual bool IsEnabled(const bool& input) override;
	virtual bool IsVisible(const bool& input) override;

	virtual void KeyDown(WKeyboardArgs* Args) override;
	virtual void KeyUp(WKeyboardArgs* Args) override;
	virtual void KeyChar(WKeyboardArgs* Args) override;
	virtual void MouseDown(WMouseArgs* Args) override;
	virtual void MouseUp(WMouseArgs* Args) override;
	virtual void MouseEnter(WMouseArgs* Args) override;
	virtual void MouseLeave(WMouseArgs* Args) override;
	virtual void MouseRollUp(WMouseArgs* Args) override;
	virtual void MouseRollDown(WMouseArgs* Args) override;

	virtual WControl* Parent(WControl* intake);
	virtual WControl* Parent(void) const;

	virtual W_FLOAT XOffset(void) const;
	virtual W_FLOAT XOffset(const W_FLOAT& intake);

	virtual W_FLOAT YOffset(void) const;
	virtual W_FLOAT YOffset(const W_FLOAT& intake);

	virtual void UpdateRect(void);
	virtual bool IsWithin(WMouseArgs* Args) const;
	virtual void SetZIndexNoChange(const W_INT& zIndex) override;
	virtual W_INT GetWidth(void) const;
	virtual W_INT GetHeight(void) const;

protected:
	// Normal
	W_INT m_zIndex;
	W_FLOAT m_xoffset;
	W_FLOAT m_yoffset;

	bool m_isActive;
	bool m_isClicked;
	bool m_isEnabled;
	bool m_isVisible;

	W_FLOAT m_top;
	W_FLOAT m_left;
	W_FLOAT m_bottom;
	W_FLOAT m_right;

	WRectF ctRec;

	WRegistry* WCTKeyDownRegistery;
	WRegistry* WCTKeyUpRegistery;
	WRegistry* WCTKeyCharRegistery;

	WRegistry* WCTMouseDownRegistery;
	WRegistry* WCTMouseUpRegistery;

	WRegistry* WCTMouseEnterRegistery;
	WRegistry* WCTMouseLeaveRegistery;

	WRegistry* WCTMouseRollUpRegistery;
	WRegistry* WCTMouseRollDownRegistery;

	WControl* m_Parent;
};

#endif // !_W_CONTROL_H_
