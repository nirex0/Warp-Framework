//© 2018 NIREX ALL RIGHTS RESERVED

#include "WControl.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WControl::WControl(W_INT zIndex)
	: m_zIndex(zIndex)
{
	ctRec.Top(m_top);
	ctRec.Left(m_left);

	ctRec.Bottom(m_bottom);
	ctRec.Right(m_right);

	WCTMouseDownRegistery = new WRegistry();
	WCTMouseUpRegistery = new WRegistry();
	WCTMouseEnterRegistery = new WRegistry();
	WCTMouseLeaveRegistery = new WRegistry();
	WCTMouseRollUpRegistery = new WRegistry();
	WCTMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WControl::WControl(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex) 
	: m_zIndex(zIndex)

{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	WCTMouseDownRegistery = new WRegistry();
	WCTMouseUpRegistery = new WRegistry();
	WCTMouseEnterRegistery = new WRegistry();
	WCTMouseLeaveRegistery = new WRegistry();
	WCTMouseRollUpRegistery = new WRegistry();
	WCTMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WControl::WControl(WPointF topleft, WPointF botright, W_INT zIndex) 
	: m_zIndex(zIndex)

{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	WCTMouseDownRegistery = new WRegistry();
	WCTMouseUpRegistery = new WRegistry();
	WCTMouseEnterRegistery = new WRegistry();
	WCTMouseLeaveRegistery = new WRegistry();
	WCTMouseRollUpRegistery = new WRegistry();
	WCTMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WControl::WControl(WRectF location, W_INT zIndex) 
	: m_zIndex(zIndex)

{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	WCTMouseDownRegistery = new WRegistry();
	WCTMouseUpRegistery = new WRegistry();
	WCTMouseEnterRegistery = new WRegistry();
	WCTMouseLeaveRegistery = new WRegistry();
	WCTMouseRollUpRegistery = new WRegistry();
	WCTMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
}

WControl::~WControl()
{
	delete WCTMouseDownRegistery;
	delete WCTMouseUpRegistery;
	delete WCTMouseEnterRegistery;
	delete WCTMouseLeaveRegistery;
	delete WCTMouseRollUpRegistery;
	delete WCTMouseRollDownRegistery;

	WControlHandler::Remove(this);

}

WRectF WControl::Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::Location(WPointF topleft, WPointF botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::Location(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(WPointF topleft, WPointF heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = m_top + location.Bottom();
	m_right = m_left + location.Right();;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::Location(void) const
{
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WPointF WControl::Displace(W_FLOAT X, W_FLOAT Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WPointF(X, Y);
}

WPointF WControl::Displace(WPointF XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WPointF(XY.X(), XY.Y());
}

WRegistry* WControl::MouseDownRegistery(void)
{
	return WCTMouseDownRegistery;
}

WRegistry* WControl::MouseUpRegistery(void)
{
	return WCTMouseUpRegistery;
}

WRegistry* WControl::MouseEnterRegistery(void)
{
	return WCTMouseEnterRegistery;
}

WRegistry* WControl::MouseLeaveRegistery(void)
{
	return WCTMouseLeaveRegistery;
}

WRegistry* WControl::MouseRollUpRegistery(void)
{
	return WCTMouseRollUpRegistery;
}

WRegistry* WControl::MouseRollDownRegistery(void)
{
	return WCTMouseRollDownRegistery;
}

WRegistry* WControl::MouseDownRegistery(WRegistry* intake)
{
	WCTMouseDownRegistery = intake;
	return WCTMouseDownRegistery;
}

WRegistry* WControl::MouseUpRegistery(WRegistry* intake)
{
	WCTMouseUpRegistery = intake;
	return WCTMouseUpRegistery;
}

WRegistry* WControl::MouseEnterRegistery(WRegistry* intake)
{
	WCTMouseEnterRegistery = intake;
	return WCTMouseEnterRegistery;
}

WRegistry* WControl::MouseLeaveRegistery(WRegistry* intake)
{
	WCTMouseLeaveRegistery = intake;
	return WCTMouseLeaveRegistery;
}

WRegistry* WControl::MouseRollUpRegistery(WRegistry* intake)
{
	WCTMouseRollUpRegistery = intake;
	return WCTMouseRollUpRegistery;
}

WRegistry* WControl::MouseRollDownRegistery(WRegistry* intake)
{
	WCTMouseRollDownRegistery = intake;
	return WCTMouseRollDownRegistery;
}

W_INT WControl::ZIndex(void) const
{
	return m_zIndex;
}

bool WControl::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WControl::IsVisible(void) const
{
	return m_isVisible;
}

W_INT WControl::ZIndex(W_INT input)
{
	WControlHandler::Remove(this);
	m_zIndex = input;
	WControlHandler::Add(this);
	return m_zIndex;
}

bool WControl::IsEnabled(bool input)
{
	m_isEnabled = input;
	return m_isEnabled;
}

bool WControl::IsVisible(bool input)
{
	m_isVisible = input;
	return m_isVisible;
}

void WControl::MouseDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::MouseDown  && parentalControl)
	{
		WCTMouseDownRegistery->Run(this, Args);
	}
}

void WControl::MouseUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::MouseUp  && parentalControl)
	{
		WCTMouseUpRegistery->Run(this, Args);
	}
}

void WControl::MouseEnter(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && !Location().IsColliding(p) && parentalControl)
	{
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WControl::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	WPointF p;
	p.X((W_FLOAT)WContainer::HCX());
	p.Y((W_FLOAT)WContainer::HCY());

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (!IsWithin(Args) && Args->State() == KeyState::NoClick && Location().IsColliding(p) && parentalControl)
	{
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

void WControl::MouseRollUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && parentalControl)
	{
		WCTMouseRollUpRegistery->Run(this, Args);
	}
}

void WControl::MouseRollDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}

	bool parentalControl = 1;

	if (m_Parent)
	{
		if (m_Parent->IsWithin(Args))
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (IsWithin(Args) && Args->State() == KeyState::NoClick && parentalControl)
	{
		WCTMouseRollDownRegistery->Run(this, Args);
	}
}


IControl* WControl::Parent(IControl* intake)
{
	m_Parent = intake;
	return m_Parent;
}

IControl* WControl::Parent(void) const
{
	return m_Parent;
}

void WControl::UpdateRect(void)
{
	ctRec.Top(m_top);
	ctRec.Left(m_left);
	ctRec.Bottom(m_bottom);
	ctRec.Right(m_right);
}

bool WControl::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WControl::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}

W_INT WControl::GetWidth(void) const
{
	return (W_INT)(ctRec.Right() - ctRec.Left());
}

W_INT WControl::GetHeight(void) const
{
	return (W_INT)(ctRec.Bottom() - ctRec.Top());
}
