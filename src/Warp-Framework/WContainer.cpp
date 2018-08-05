// © 2018 NIREX ALL RIGHTS RESERVED

#include "WContainer.h"

const HRESULT WContainer::hResult(HRESULT intake)
{
	WContainer::HR = intake; return WContainer::HR;
}

const HRESULT WContainer::hResult(void)
{
	return WContainer::HR;
}

const HWND WContainer::Handle(HWND intake)
{
	WContainer::hWnd = intake;
	return WContainer::hWnd;
}

const HWND WContainer::Handle(void)
{
	return WContainer::hWnd;
}

const UINT WContainer::Message(UINT intake)
{
	WContainer::msg = intake; 
	return WContainer::msg;
}

const UINT WContainer::Message(void)
{
	return WContainer::msg;
}

const WPARAM WContainer::WParam(WPARAM intake)
{
	WContainer::wParam = intake;
	return WContainer::wParam;
}

const WPARAM WContainer::WParam(void)
{
	return WContainer::wParam;
}

const LPARAM WContainer::LParam(LPARAM intake)
{
	WContainer::lParam = intake; 
	return WContainer::lParam;
}

const LPARAM WContainer::LParam(void)
{
	return WContainer::lParam;
}

const WEntry WContainer::Framework(WEntry intake)
{
	WContainer::WFramework = intake; 
	return WContainer::WFramework;
}

const WEntry WContainer::Framework(void)
{
	return WContainer::WFramework;
}

const DELTATIME WContainer::DeltaSeconds(DELTATIME intake)
{
	WContainer::DeltaTime = intake;
	return WContainer::DeltaTime;
}

const DELTATIME WContainer::DeltaSeconds(void)
{
	return WContainer::DeltaTime;
}

const W_INT WContainer::BackA(W_INT intake)
{
	WContainer::BGA = intake;
	return WContainer::BGA;
}

const W_INT WContainer::BackA(void)
{
	return WContainer::BGA;
}

const W_INT WContainer::BackR(W_INT intake)
{
	WContainer::BGR = intake;
	return WContainer::BGR;
}

const W_INT WContainer::BackR(void)
{
	return WContainer::BGR;
}

const W_INT WContainer::BackG(W_INT intake)
{
	WContainer::BGG = intake; 
	return WContainer::BGG;
}

const W_INT WContainer::BackG(void)
{
	return WContainer::BGG;
}

const W_INT WContainer::BackB(W_INT intake)
{
	WContainer::BGB = intake; 
	return WContainer::BGB;
}

const W_INT WContainer::BackB(void)
{
	return WContainer::BGB;
}

const W_INT WContainer::Width(W_INT intake)
{
	WContainer::W_WIDTH = intake;
	return WContainer::W_WIDTH;
}

const W_INT WContainer::Width(void)
{
	return WContainer::W_WIDTH;
}

const W_INT WContainer::Height(W_INT intake)
{
	WContainer::W_HEIGHT = intake;
	return WContainer::W_HEIGHT;
}

const W_INT WContainer::Height(void)
{
	return WContainer::W_HEIGHT;
}

WMouse* WContainer::Mouse(WMouse* intake)
{
	WContainer::mouse = intake; 
	return WContainer::mouse;
}

WMouse* WContainer::Mouse(void)
{
	return WContainer::mouse;
}

WKeyboard* WContainer::Keyboard(WKeyboard* intake)
{
	WContainer::keyboard = intake;
	return WContainer::keyboard;
}

WKeyboard* WContainer::Keyboard(void)
{
	return WContainer::keyboard;
}

W_INT WContainer::HCX(W_INT intake)
{
	WContainer::helperCoordX = intake; 
	return WContainer::helperCoordX;
}

W_INT WContainer::HCX(void)
{
	return WContainer::helperCoordX;
}

W_INT WContainer::HCY(W_INT intake)
{
	WContainer::helperCoordY = intake; 
	return WContainer::helperCoordY;
}

W_INT WContainer::HCY(void)
{
	return WContainer::helperCoordY;
}

BOOL WContainer::DragMove(BOOL intake)
{
	WContainer::bDragMove = intake; 
	return WContainer::bDragMove;
}

BOOL WContainer::DragMove(void)
{
	return WContainer::bDragMove;
}

WTheme WContainer::Theme(WTheme intake)
{
	wTheme = intake; 
	return wTheme;
}

WTheme WContainer::Theme(void)
{
	return wTheme;
}
