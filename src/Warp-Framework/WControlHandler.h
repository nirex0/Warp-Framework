// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTROL_HANDLER_H_
#define _W_CONTROL_HANDLER_H_


#include "IControl.h"
#include "WButton.h"
#include "WContainer.h"

#include <map>
#include <set>
#include <utility>

class WControlHandler
{
public:
	static void Add(IControl* intake);
	static void Remove(IControl* intake);
	static void MouseDown(WMouseArgs* args);
	static void MouseUp(WMouseArgs* args);
	static void MouseEnter(WMouseArgs* args);
	static void MouseLeave(WMouseArgs* args);
	static void MouseRollUp(WMouseArgs* args);
	static void MouseRollDown(WMouseArgs* args);
	static void MouseMove(WMouseArgs* args);
	static void Update(void);
	static void Render(void);

private:
	static std::map<W_INT, IControl*> WControlHandler::mtcp;
	static std::set<W_INT> WControlHandler::stcz;
};

#endif // !_W_CONTROL_HANDLER_H_
