//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GDI_PAINT_ARGS_H_
#define _W_GDI_PAINT_ARGS_H_

#include "WWin.h"
#include "WEventArgs.h"

class WGDIPaintArgs : public WEventArgs
{
public:
	WGDIPaintArgs(PAINTSTRUCT* ps, HWND* hWnd)
		: m_ps(ps)
		, m_hWnd(hWnd)
	{
	}

	~WGDIPaintArgs()
	{
	}

	PAINTSTRUCT* GetPaintStruct(void) const
	{
		return this->m_ps;
	}

	HWND* GetHandle(void) const
	{
		return this->m_hWnd;
	}

private:
	PAINTSTRUCT* m_ps;
	HWND* m_hWnd;
};

#endif // !_W_GDI_PAINT_ARGS_H_
