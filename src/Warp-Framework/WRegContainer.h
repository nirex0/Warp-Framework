// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_REG_CONTAINER_H_
#define _W_REG_CONTAINER_H_

#include "WRegistry.h"
#include "WUniqueRegister.h"

//-->DOC_CLASS
// A Container class that allows access to a set of global static registry pointers throughout the framework
class WRegContainer final
{
public:
	static void KeyboardKeyDown(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardKeyDown(void);

	static void KeyboardKeyUp(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardKeyUp(void);

	static void KeyboardOnChar(WUniqueRegister* const kbdReg);
	static WUniqueRegister* KeyboardOnChar(void);

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

	static void OnGDIPaint(WUniqueRegister* const gdiReg);
	static WUniqueRegister* OnGDIPaint(void);

private:
	//-->DOC_MEMBER
	//Keyboard Key down Registry pointer
	static WUniqueRegister* KBD_KeyDownReg;

	//-->DOC_MEMBER
	//Keyboard Key up Registry pointer
	static WUniqueRegister* KBD_KeyUpReg;

	//-->DOC_MEMBER
	//Keyboard On Char Registry pointer (For Typing)
	static WUniqueRegister* KBD_OnCharReg;

	//-->DOC_MEMBER
	//Mouse On Click down Registry pointer
	static WRegistry* MOS_MouseDown;

	//-->DOC_MEMBER
	//Mouse On Click up Registry pointer
	static WRegistry* MOS_MouseUp;

	//-->DOC_MEMBER
	//Mouse On Mouse movement Registry pointer
	static WRegistry* MOS_MouseMove;

	//-->DOC_MEMBER
	//Mouse On Mouse roll up Registry pointer
	static WRegistry* MOS_MouseRollUp;

	//-->DOC_MEMBER
	//Mouse On Mouse roll down Registry pointer
	static WRegistry* MOS_MouseRollDown;

	//-->DOC_MEMBER
	//Windows on GDI Paint message Registry pointer
	static WUniqueRegister* WND_OnGDIPaint;
};

#endif // !_W_CONTAINER_H_
