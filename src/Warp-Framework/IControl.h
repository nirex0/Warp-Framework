// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _I_CONTROL_H_
#define _I_CONTROL_H_

#include "WPoint.h"
#include "WRect.h"
#include "WRegistry.h"
#include "WMouseArgs.h"
#include "WKeyboardArgs.h"

class IControl : public WEntity
{
public:
	// Events
	virtual void KeyDown(WKeyboardArgs* Args) = 0;
	virtual void KeyUp(WKeyboardArgs* Args) = 0;
	virtual void KeyChar(WKeyboardArgs* Args) = 0;
	virtual void MouseDown(WMouseArgs* Args) = 0;
	virtual void MouseUp(WMouseArgs* Args) = 0;
	virtual void MouseEnter(WMouseArgs* Args) = 0;
	virtual void MouseLeave(WMouseArgs* Args) = 0;
	virtual void MouseRollUp(WMouseArgs* Args) = 0;
	virtual void MouseRollDown(WMouseArgs* Args) = 0;

	// Location
	virtual WRectF Location(void) const = 0;
	virtual bool IsWithin(WMouseArgs* Args) const = 0;

	// ZIndex
	virtual W_INT ZIndex(void) const = 0;
	virtual W_INT ZIndex(W_INT input) = 0;
	virtual void SetZIndexNoChange(W_INT zIndex) = 0;

	// Getters
	virtual bool IsActive(void) const = 0;
	virtual bool IsVisible(void) const = 0;
	virtual bool IsVisible(bool input) = 0;

	// Setters
	virtual bool IsActive(bool input) = 0;
	virtual bool IsEnabled(void) const = 0;
	virtual bool IsEnabled(bool input) = 0;

	// Visual
	virtual void UpdateRect(void) = 0;
	virtual void Render(void) = 0;
};

#endif // !_I_CONTROL_H_
