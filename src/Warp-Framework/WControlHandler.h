//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTROL_HANDLER_H_
#define _W_CONTROL_HANDLER_H_


#include "IControl.h"
#include "WButton.h"
#include "WContainer.h"
#include <vector>

class WControlHandler
{
public:
	static void Add(IControl* intake)
	{
		vtcp.push_back(intake);
	}
	static void MouseDown(WMouseArgs* args)
	{
		for (size_t i = 0; i < vtcp.size(); i++)
		{
			vtcp[i]->MouseDown(args);
		}
	}
	static void MouseUp(WMouseArgs* args)
	{
		for (size_t i = 0; i < vtcp.size(); i++)
		{
			vtcp[i]->MouseUp(args);
		}
	}
	static void MouseEnter(WMouseArgs* args)
	{
		for (size_t i = 0; i < vtcp.size(); i++)
		{
			vtcp[i]->MouseEnter(args);
		}
	}
	static void MouseLeave(WMouseArgs* args)
	{
		for (size_t i = 0; i < vtcp.size(); i++)
		{
			vtcp[i]->MouseLeave(args);
		}
	}
	static void MouseMove(WMouseArgs* args)
	{
		WControlHandler::MouseLeave(args);
		WControlHandler::MouseEnter(args);
	}

private:
	static std::vector<IControl*> WControlHandler::vtcp;
};

#endif // !_W_CONTROL_HANDLER_H_
