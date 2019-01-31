// © 2019 NIREX ALL RIGHTS RESERVED

#include "WGDIPaintEventArgs.h"

WGDIPaintArgs::WGDIPaintArgs(PAINTSTRUCT* ps, HWND* hWnd)
	: m_ps(ps)
	, m_hWnd(hWnd)
{
}

PAINTSTRUCT* WGDIPaintArgs::GetPaintStruct(void) const
{
	return this->m_ps;
}

HWND* WGDIPaintArgs::GetHandle(void) const
{
	return this->m_hWnd;
}