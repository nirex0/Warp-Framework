// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_REG_CONTAINER_H_
#define _W_REG_CONTAINER_H_

#include "WRegistry.h"
#include "WUniqueRegister.h"

class WRegContainer
{
public:
// Keyboard
	static void KeyboardKeyDown(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardKeyDown(void);

	static void KeyboardKeyUp(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardKeyUp(void);

	static void KeyboardOnChar(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardOnChar(void);

// MOUSE
	static void MouseDown(WRegistry* const mouseReg);
	static WRegistry* MouseDown(void);

	static void MouseUp(WRegistry* const mouseReg);
	static WRegistry* MouseUp(void);

	static void MouseMove(WRegistry* const mouseReg);
	static WRegistry* MouseMove(void);

	static void MouseRollUp(WRegistry* const mouseReg);
	static WRegistry* MouseRollUp(void);

	static void MouseRollDown(WRegistry* const mouseReg);
	static WRegistry* MouseRollDown(void);

// MAIN WINDOW
	static void OnGDIPaint(WUniqueRegister* const gdiReg);
	static WUniqueRegister* OnGDIPaint(void);

private:
	static WUniqueRegister* WRegContainer::KBD_KeyDownReg;
	static WUniqueRegister* WRegContainer::KBD_KeyUpReg;
	static WUniqueRegister* WRegContainer::KBD_OnCharReg;

	static WRegistry* WRegContainer::MOS_MouseDown;
	static WRegistry* WRegContainer::MOS_MouseUp;
	static WRegistry* WRegContainer::MOS_MouseMove;
	static WRegistry* WRegContainer::MOS_MouseRollUp;
	static WRegistry* WRegContainer::MOS_MouseRollDown;

	static WUniqueRegister* WRegContainer::WND_OnGDIPaint;
};

#endif // !_W_CONTAINER_H_
