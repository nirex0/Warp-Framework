// © 2019 NIREX ALL RIGHTS RESERVED

#include "WControlHandler.h"

void WControlHandler::Add(IControl* intake)
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

void WControlHandler::Remove(IControl* intake)
{
	stcz.erase(intake->ZIndex());
	mtcp.erase(intake->ZIndex());
}

void WControlHandler::KeyDown(WKeyboardArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->KeyDown(args);
	}
}

void WControlHandler::KeyUp(WKeyboardArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->KeyUp(args);
	}
}

void WControlHandler::KeyChar(WKeyboardArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->KeyChar(args);
	}
}

void WControlHandler::MouseDown(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseDown(args);
	}
}

void WControlHandler::MouseUp(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseUp(args);
	}
}

void WControlHandler::MouseEnter(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseEnter(args);
	}
}

void WControlHandler::MouseLeave(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseLeave(args);
	}
}

void WControlHandler::MouseRollUp(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseRollUp(args);
	}
}

void WControlHandler::MouseRollDown(WMouseArgs* args)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->MouseRollDown(args);
	}
}

void WControlHandler::MouseMove(WMouseArgs* args)
{
	WControlHandler::MouseLeave(args);
	WControlHandler::MouseEnter(args);
}

void WControlHandler::Update(void)
{
	for (const auto &p : mtcp)
	{
		mtcp.at(p.first)->UpdateRect();
	}
}

void WControlHandler::Render(void)
{
	for (const auto &p : mtcp)
	{	
		if(mtcp.at(p.first)->IsVisible())
			mtcp.at(p.first)->Render();
	}
}