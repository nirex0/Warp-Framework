//© 2018 NIREX ALL RIGHTS RESERVED

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
	static void Add(IControl* intake)
	{
		for (const W_INT &p : stcz)
		{
			if (intake->ZIndex() == p)
			{
				intake->SetZIndexNoChange(p + 1);
			}
		}
		stcz.emplace(intake->ZIndex());
		mtcp.emplace(std::make_pair(intake->ZIndex(), intake));
	}
	static void Remove(IControl* intake)
	{
		stcz.erase(intake->ZIndex());
		mtcp.erase(intake->ZIndex());
	}
	static void MouseDown(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseDown(args);
		}
	}
	static void MouseUp(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseUp(args);
		}
	}
	static void MouseEnter(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseEnter(args);
		}
	}
	static void MouseLeave(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseLeave(args);
		}
			
	}
	static void MouseRollUp(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseRollUp(args);
		}
	}
	static void MouseRollDown(WMouseArgs* args)
	{
		for (const auto &p : mtcp)
		{
			mtcp.at(p.first)->MouseRollDown(args);
		}
	}
	static void MouseMove(WMouseArgs* args)
	{
		WControlHandler::MouseLeave(args);
		WControlHandler::MouseEnter(args);
	}
	static void Render(void)
	{
		for (const auto &p : mtcp)
		{
			if (mtcp.at(p.first)->AutoRender())
			{
				mtcp.at(p.first)->Render();
			}
		}
	}
private:
	static std::map<W_INT, IControl*> WControlHandler::mtcp;
	static std::set<W_INT> WControlHandler::stcz;
};

#endif // !_W_CONTROL_HANDLER_H_
