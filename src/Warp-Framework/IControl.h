//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _I_CONTROL_H_
#define _I_CONTROL_H_

#include "WPoint.h"
#include "WRect.h"
#include "WRegistry.h"
#include "WMouseArgs.h"

class IControl : public WEntity
{
public:
	virtual WRectF Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right) = 0;
	virtual WRectF Location(WPointF topleft, WPointF botright) = 0;
	virtual WRectF Location(WRectF location) = 0;
			
	virtual WRectF RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width) = 0;
	virtual WRectF RelLocation(WPointF topleft, WPointF heightwidth) = 0;
	virtual WRectF RelLocation(WRectF location) = 0;

	// Getters
	virtual WRectF Location(void) const = 0;

	// Location Setters
	virtual WPointF Displace(W_FLOAT X, W_FLOAT Y) = 0;
	virtual WPointF Displace(WPointF XY) = 0;

	// Getters
	virtual WRegistry* MouseDownRegistery(void) = 0;
	virtual WRegistry* MouseUpRegistery(void) = 0;
	virtual WRegistry* MouseEnterRegistery(void) = 0;
	virtual WRegistry* MouseLeaveRegistery(void) = 0;
	virtual WRegistry* MouseRollUpRegistery(void) = 0;
	virtual WRegistry* MouseRollDownRegistery(void) = 0;

	// Setters
	virtual WRegistry* MouseDownRegistery(WRegistry* intake) = 0;
	virtual WRegistry* MouseUpRegistery(WRegistry* intake) = 0;
	virtual WRegistry* MouseEnterRegistery(WRegistry* intake) = 0;
	virtual WRegistry* MouseLeaveRegistery(WRegistry* intake) = 0;
	virtual WRegistry* MouseRollUpRegistery(WRegistry* intake) = 0;
	virtual WRegistry* MouseRollDownRegistery(WRegistry* intake) = 0;

	// Getters
	virtual W_INT ZIndex(void) const = 0;
	virtual bool IsEnabled(void) const = 0;
	virtual bool IsVisible(void) const = 0;
	virtual bool AutoRender(void) const = 0;

	// Setters
	virtual W_INT ZIndex(W_INT input) = 0;
	virtual bool IsEnabled(bool input) = 0;
	virtual bool IsVisible(bool input) = 0;
	virtual bool AutoRender(bool input) = 0;

	// Events
	virtual void MouseDown(WMouseArgs* Args) = 0;
	virtual void MouseUp(WMouseArgs* Args) = 0;
	virtual void MouseEnter(WMouseArgs* Args) = 0;
	virtual void MouseLeave(WMouseArgs* Args) = 0;
	virtual void MouseRollUp(WMouseArgs* Args) = 0;
	virtual void MouseRollDown(WMouseArgs* Args) = 0;

	// Helpers
	virtual bool IsWithin(WMouseArgs* Args) const = 0;
	virtual void SetZIndexNoChange(W_INT zIndex) = 0;

	// Visual
	virtual void Render(void) = 0;
};

#endif // !_I_CONTROL_H_
