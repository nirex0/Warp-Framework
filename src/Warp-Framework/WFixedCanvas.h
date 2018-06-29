//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_FIXEDCANVAS_H_
#define _W_FIXEDCANVAS_H_

#include "WGFXContainer.h"
#include "WRECTF.h"
#include "IControl.h"
#include "WPoint.h"
#include "WRect.h"
#include "WContainer.h"
#include "WMouse.h"
#include "WLerp.h"
#include "WColorTransform.h"

class WFixedCanvas : public IControl
{
public:
	WFixedCanvas(W_INT zIndex = 0);
	~WFixedCanvas(void);

	// Getters
	WRectF Location(void) const override;

	// Functions
	void Render(void) override;

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
	bool IsWithin(WMouseArgs* Args) const;
	void SetZIndexNoChange(W_INT zIndex);
	W_INT GetWidth(void) const;
	W_INT GetHeight(void) const;

private:
	// Normal
	W_INT m_zIndex;

	bool m_isEnabled;
	bool m_isVisible;

	W_FLOAT m_top;
	W_FLOAT m_left;
	W_FLOAT m_bottom;
	W_FLOAT m_right;

	WRECTF fcRec;

	WRegistry* FCMouseDownRegistery;
	WRegistry* FCMouseUpRegistery;
			   
	WRegistry* FCMouseEnterRegistery;
	WRegistry* FCMouseLeaveRegistery;
			   
	WRegistry* FCMouseRollUpRegistery;
	WRegistry* FCMouseRollDownRegistery;

	IControl* m_Parent;
};

#endif // !_W_FIXEDCANVAS_H_
