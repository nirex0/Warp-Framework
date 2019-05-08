// © 2019 NIREX ALL RIGHTS RESERVED

#include "WControl.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WControl::WControl(const W_INT& zIndex)
	: m_zIndex(zIndex)
	, m_xoffset(0)
	, m_yoffset(0)
{
	ctRec.Top(m_top);
	ctRec.Left(m_left);

	ctRec.Bottom(m_bottom);
	ctRec.Right(m_right);

	WCTKeyDownRegistery = new WRegistry();
	WCTKeyUpRegistery = new WRegistry();
	WCTKeyCharRegistery = new WRegistry();
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

WControl::WControl(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex)
	: m_zIndex(zIndex)
	, m_xoffset(0)
	, m_yoffset(0)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	WCTKeyDownRegistery = new WRegistry();
	WCTKeyUpRegistery = new WRegistry();
	WCTKeyCharRegistery = new WRegistry();
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

WControl::WControl(const WPointF& topleft, const WPointF& botright, const W_INT& zIndex)
	: m_zIndex(zIndex)
	, m_xoffset(0)
	, m_yoffset(0)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	WCTKeyDownRegistery = new WRegistry();
	WCTKeyUpRegistery = new WRegistry();
	WCTKeyCharRegistery = new WRegistry();
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

WControl::WControl(const WRectF& location, const W_INT& zIndex)
	: m_zIndex(zIndex)
	, m_xoffset(0)
	, m_yoffset(0)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	WCTKeyDownRegistery = new WRegistry();
	WCTKeyUpRegistery = new WRegistry();
	WCTKeyCharRegistery = new WRegistry();
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
	delete WCTKeyDownRegistery;
	delete WCTKeyUpRegistery;
	delete WCTKeyCharRegistery;
	delete WCTMouseDownRegistery;
	delete WCTMouseUpRegistery;
	delete WCTMouseEnterRegistery;
	delete WCTMouseLeaveRegistery;
	delete WCTMouseRollUpRegistery;
	delete WCTMouseRollDownRegistery;

	WControlHandler::Remove(this);
}

WRectF WControl::Location(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::Location(const WPointF& topleft, const WPointF& botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::Location(const WRectF& location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& height, const W_FLOAT& width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(const WPointF& topleft, const WPointF& heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WControl::RelLocation(const WRectF& location)
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
	W_FLOAT gxOffset = 0;
	W_FLOAT gyOffset = 0;
	if (m_Parent)
	{
		gxOffset = m_Parent->XOffset();
		gyOffset = m_Parent->YOffset();
	}

	return WRectF(m_top + gyOffset,
		m_left + gxOffset,
		m_bottom + gyOffset,
		m_right + gxOffset);
}

WPointF WControl::Displace(const W_FLOAT& X, const W_FLOAT& Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WPointF(X, Y);
}

WPointF WControl::Displace(const WPointF& XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WPointF(XY.X(), XY.Y());
}

WRegistry* WControl::KeyDownRegistery(void)
{
	return WCTKeyDownRegistery;
}

WRegistry* WControl::KeyUpRegistery(void)
{
	return WCTKeyUpRegistery;
}

WRegistry* WControl::KeyCharRegistery(void)
{
	return WCTKeyCharRegistery;
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

WRegistry* WControl::KeyDownRegistery(WRegistry* intake)
{
	WCTKeyDownRegistery = intake;
	return WCTKeyDownRegistery;
}

WRegistry* WControl::KeyUpRegistery(WRegistry* intake)
{
	WCTKeyUpRegistery = intake;
	return WCTKeyUpRegistery;
}

WRegistry* WControl::KeyCharRegistery(WRegistry* intake)
{
	WCTKeyCharRegistery = intake;
	return WCTKeyCharRegistery;
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

bool WControl::IsActive(void) const
{
	return m_isActive;
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

bool WControl::IsActive(bool input)
{
	m_isActive = input;
	return m_isActive;
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

void WControl::KeyDown(WKeyboardArgs* Args)
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
		if (m_Parent->IsActive())
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (m_isActive && parentalControl)
	{
		WCTKeyDownRegistery->Run(this, Args);
	}
}

void WControl::KeyUp(WKeyboardArgs* Args)
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
		if (m_Parent->IsActive())
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (m_isActive && parentalControl)
	{
		WCTKeyUpRegistery->Run(this, Args);
	}
}

void WControl::KeyChar(WKeyboardArgs* Args)
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
		if (m_Parent->IsActive())
		{
			parentalControl = 1;
		}
		else
		{
			parentalControl = 0;
		}
	}
	if (m_isActive && parentalControl)
	{
		WCTKeyCharRegistery->Run(this, Args);
	}
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
		m_isActive = 1;
		m_isClicked = 1;
		WCTMouseDownRegistery->Run(this, Args);
	}
	else if (!IsWithin(Args))
	{
		m_isActive = 0;
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
	m_isClicked = 0;
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

WControl* WControl::Parent(WControl* intake)
{
	m_Parent = intake;
	return m_Parent;
}

WControl* WControl::Parent(void) const
{
	return m_Parent;
}

W_FLOAT WControl::XOffset(void) const
{
	return m_xoffset;
}

W_FLOAT WControl::XOffset(const W_FLOAT& intake)
{
	m_xoffset = intake;
	return m_xoffset;
}

W_FLOAT WControl::YOffset(void) const
{
	return m_yoffset;
}

W_FLOAT WControl::YOffset(const W_FLOAT& intake)
{
	m_yoffset = intake;
	return m_yoffset;
}

void WControl::UpdateRect(void)
{
	W_FLOAT gxOffset = 0;
	W_FLOAT gyOffset = 0;
	if (m_Parent)
	{
		gxOffset = m_Parent->XOffset();
		gyOffset = m_Parent->YOffset();
	}

	ctRec.Top(m_top + gyOffset);
	ctRec.Left(m_left + gxOffset);
	ctRec.Bottom(m_bottom + gyOffset);
	ctRec.Right(m_right + gxOffset);
}

bool WControl::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WControl::SetZIndexNoChange(const W_INT& zIndex)
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
