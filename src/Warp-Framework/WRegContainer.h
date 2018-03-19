//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_REG_CONTAINER_H_
#define _W_REG_CONTAINER_H_

#include "WUniqueRegister.h"

class WRegContainer
{
public:
	// Keyboard
	static void KeyboardKeyDown(WUniqueRegister* const kbdReg) { WRegContainer::KBD_KeyDownReg = kbdReg; }
	static WUniqueRegister* KeyboardKeyDown(void) { return WRegContainer::KBD_KeyDownReg; }

	static void KeyboardKeyUp(WUniqueRegister* const kbdReg) { WRegContainer::KBD_KeyUpReg = kbdReg; }
	static WUniqueRegister* KeyboardKeyUp(void) { return WRegContainer::KBD_KeyUpReg; }

	static void KeyboardOnChar(WUniqueRegister* const kbdReg) { WRegContainer::KBD_OnCharReg = kbdReg; }
	static WUniqueRegister* KeyboardOnChar(void) { return WRegContainer::KBD_OnCharReg; }

	// MOUSE
	static void MouseDown(WUniqueRegister* const mouseReg) { WRegContainer::MOS_MouseDown = mouseReg; }
	static WUniqueRegister* MouseDown(void) { return WRegContainer::MOS_MouseDown; }

	static void MouseUp(WUniqueRegister* const mouseReg) { WRegContainer::MOS_MouseUp = mouseReg; }
	static WUniqueRegister* MouseUp(void) { return WRegContainer::MOS_MouseUp; }

	static void MouseMove(WUniqueRegister* const mouseReg) { WRegContainer::MOS_MouseMove = mouseReg; }
	static WUniqueRegister* MouseMove(void) { return WRegContainer::MOS_MouseMove; }

	static void MouseRollUp(WUniqueRegister* const mouseReg) { WRegContainer::MOS_MouseRollUp = mouseReg; }
	static WUniqueRegister* MouseRollUp(void) { return WRegContainer::MOS_MouseRollUp; }

	static void MouseRollDown(WUniqueRegister* const mouseReg) { WRegContainer::MOS_MouseRollDown = mouseReg; }
	static WUniqueRegister* MouseRollDown(void) { return WRegContainer::MOS_MouseRollDown; }

	// MAIN WINDOW
	static void OnGDIPaint(WUniqueRegister* const gdiReg) { WRegContainer::WND_OnGDIPaint = gdiReg; }
	static WUniqueRegister* OnGDIPaint(void) { return WRegContainer::WND_OnGDIPaint; }

private:
	static WUniqueRegister* WRegContainer::KBD_KeyDownReg;
	static WUniqueRegister* WRegContainer::KBD_KeyUpReg;
	static WUniqueRegister* WRegContainer::KBD_OnCharReg;

	static WUniqueRegister* WRegContainer::MOS_MouseDown;
	static WUniqueRegister* WRegContainer::MOS_MouseUp;
	static WUniqueRegister* WRegContainer::MOS_MouseMove;
	static WUniqueRegister* WRegContainer::MOS_MouseRollUp;
	static WUniqueRegister* WRegContainer::MOS_MouseRollDown;

	static WUniqueRegister* WRegContainer::WND_OnGDIPaint;
};

#endif // !_W_CONTAINER_H_