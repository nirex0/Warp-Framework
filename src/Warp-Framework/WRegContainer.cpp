// © 2018 NIREX ALL RIGHTS RESERVED

#include "WRegContainer.h"

void WRegContainer::KeyboardKeyDown(WUniqueRegister* const kbdReg)
{
	WRegContainer::KBD_KeyDownReg = kbdReg;
}

WUniqueRegister* WRegContainer::KeyboardKeyDown(void)
{
	return WRegContainer::KBD_KeyDownReg;
}

void WRegContainer::KeyboardKeyUp(WUniqueRegister* const kbdReg)
{
	WRegContainer::KBD_KeyUpReg = kbdReg;
}

WUniqueRegister* WRegContainer::KeyboardKeyUp(void)
{
	return WRegContainer::KBD_KeyUpReg;
}

void WRegContainer::KeyboardOnChar(WUniqueRegister* const kbdReg)
{
	WRegContainer::KBD_OnCharReg = kbdReg;
}

WUniqueRegister* WRegContainer::KeyboardOnChar(void)
{
	return WRegContainer::KBD_OnCharReg;
}

void WRegContainer::MouseDown(WRegistry* const mouseReg)
{
	WRegContainer::MOS_MouseDown = mouseReg;
}

WRegistry* WRegContainer::MouseDown(void)
{
	return WRegContainer::MOS_MouseDown;
}

void WRegContainer::MouseUp(WRegistry* const mouseReg)
{
	WRegContainer::MOS_MouseUp = mouseReg;
}

WRegistry* WRegContainer::MouseUp(void)
{
	return WRegContainer::MOS_MouseUp;
}

void WRegContainer::MouseMove(WRegistry* const mouseReg)
{
	WRegContainer::MOS_MouseMove = mouseReg;
}

WRegistry* WRegContainer::MouseMove(void)
{
	return WRegContainer::MOS_MouseMove;
}

void WRegContainer::MouseRollUp(WRegistry* const mouseReg)
{
	WRegContainer::MOS_MouseRollUp = mouseReg;
}

WRegistry* WRegContainer::MouseRollUp(void)
{
	return WRegContainer::MOS_MouseRollUp;
}

void WRegContainer::MouseRollDown(WRegistry* const mouseReg)
{
	WRegContainer::MOS_MouseRollDown = mouseReg;
}

WRegistry* WRegContainer::MouseRollDown(void)
{
	return WRegContainer::MOS_MouseRollDown;
}

void WRegContainer::OnGDIPaint(WUniqueRegister* const gdiReg)
{
	WRegContainer::WND_OnGDIPaint = gdiReg;
}

WUniqueRegister* WRegContainer::OnGDIPaint(void)
{
	return WRegContainer::WND_OnGDIPaint;
}
