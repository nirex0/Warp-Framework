// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_GDI_PAINT_ARGS_H_
#define _W_GDI_PAINT_ARGS_H_

#include "WWin.h"
#include "WEventArgs.h"

class WGDIPaintArgs : public WEventArgs
{
public:
	WGDIPaintArgs(PAINTSTRUCT* ps, HWND* hWnd);
	~WGDIPaintArgs() = default;

	PAINTSTRUCT* GetPaintStruct(void) const;
	HWND* GetHandle(void) const;

private:
	PAINTSTRUCT* m_ps;
	HWND* m_hWnd;
};

#endif // !_W_GDI_PAINT_ARGS_H_
