//© 2018 NIREX ALL RIGHTS RESERVED

#include "WListBox.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"
#include<math.h>

WListBox::WListBox(W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	lbRec.Top(m_top);
	lbRec.Left(m_left);

	lbRec.Bottom(m_bottom);
	lbRec.Right(m_right);

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);
	
	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));
	
	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isEnabled = true;
	m_isVisible = true;
	
	WControlHandler::Add(this);
	UpdateRect();
	m_UseExtendedBorder = true;
}

WListBox::WListBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
	m_UseExtendedBorder = true;
}

WListBox::WListBox(WPointF topleft, WPointF botright, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));
	
	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
	m_UseExtendedBorder = true;
}

WListBox::WListBox(WRectF location, W_INT zIndex)
	: m_thickness(1.0F)
	, m_zIndex(zIndex)
	, ExBordRatio(5)
{
	foreColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);
	backColor = D2D1::ColorF(1.0F, 0.0F, 0.0F, 0.0F);
	bordColor = D2D1::ColorF(1.0F, 1.0F, 1.0F, 1.0F);

	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	LBMouseDownRegistery = new WRegistry();
	LBMouseUpRegistery = new WRegistry();
	LBMouseEnterRegistery = new WRegistry();
	LBMouseLeaveRegistery = new WRegistry();
	LBMouseRollUpRegistery = new WRegistry();
	LBMouseRollDownRegistery = new WRegistry();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_isEnabled = true;
	m_isVisible = true;

	WControlHandler::Add(this);
	UpdateRect();
	m_UseExtendedBorder = true;
}

WListBox::~WListBox()
{
	delete LBMouseDownRegistery;
	delete LBMouseUpRegistery;
	delete LBMouseEnterRegistery;
	delete LBMouseLeaveRegistery;
	delete LBMouseRollUpRegistery; 
	delete LBMouseRollDownRegistery;

	delete ExBordLerpExtend;
	delete ExBordLerpShrink;

	WControlHandler::Remove(this);
}

WRectF WListBox::Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right)
{
	m_top = top;
	m_left = left;

	m_bottom = bottom;
	m_right = right;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::Location(WPointF topleft, WPointF botright)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = botright.X();
	m_right = botright.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::Location(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = location.Bottom();
	m_right = location.Right();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width)
{
	m_top = top;
	m_left = left;

	m_bottom = top + height;
	m_right = left + width;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::RelLocation(WPointF topleft, WPointF heightwidth)
{
	m_top = topleft.X();
	m_left = topleft.Y();

	m_bottom = m_top + heightwidth.X();
	m_right = m_left + heightwidth.Y();

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::RelLocation(WRectF location)
{
	m_top = location.Top();
	m_left = location.Left();

	m_bottom = m_top + location.Bottom();
	m_right = m_left + location.Right();;

	UpdateRect();
	return WRectF(m_top, m_left, m_bottom, m_right);
}

WRectF WListBox::Location(void) const
{
	return WRectF(m_top, m_left, m_bottom, m_right);
}

W_FLOAT WListBox::BorderThickness(W_FLOAT f)
{
	m_thickness = f;
	return f;
}

W_COLOR WListBox::Background(W_COLOR col)
{
	backColor = col;
	return col;
}

W_COLOR WListBox::BorderBrush(W_COLOR col)
{
	bordColor = col;
	return col;
}

W_FLOAT WListBox::BorderThickness(void) const
{
	return m_thickness;
}

W_COLOR WListBox::Background(void) const
{
	return backColor;
}

W_COLOR WListBox::BorderBrush(void) const
{
	return bordColor;
}

void WListBox::Render(void)
{
	if (!m_isVisible)
		return;

	ID2D1Layer* maskLayer;
	D2D_RECT_F ParentRect;
	if (m_Parent)
	{
		ParentRect.top = m_Parent->Location().Top();
		ParentRect.left = m_Parent->Location().Left();
		ParentRect.bottom = m_Parent->Location().Bottom();
		ParentRect.right = m_Parent->Location().Right();
	}
	else
	{
		ParentRect.top = 0.0F;
		ParentRect.left = 0.0F;
		ParentRect.bottom = (W_FLOAT)INFINITE;
		ParentRect.right = (W_FLOAT)INFINITE;
	}

	// Mask
	ID2D1PathGeometry* MaskGeo;
	WGraphicsContainer::Graphics()->GetFactory()->CreatePathGeometry(&MaskGeo);

	// Geometry Sink
	ID2D1GeometrySink* pSink = NULL;
	MaskGeo->Open(&pSink);
	pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
	pSink->BeginFigure(D2D1::Point2F(ParentRect.left, ParentRect.top), D2D1_FIGURE_BEGIN_FILLED);
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.top));
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.bottom));
	pSink->AddLine(D2D1::Point2F(ParentRect.left, ParentRect.bottom));
	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
	pSink->Close();

	// Begin Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->CreateLayer(NULL, &maskLayer);
	WGraphicsContainer::Graphics()->GetRenderTarget()->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(), MaskGeo), maskLayer);

	// Render Statements Go Here
	if (m_UseExtendedBorder)
	{
		// Top Bar
		WRECTF TopBar = lbRec;
		TopBar.Top(lbRec.Top() - 5);
		TopBar.Left(lbRec.Left() - 5);
		TopBar.Bottom(lbRec.Top() - 4);
		TopBar.Right(lbRec.Left() + GetWidth() / ExBordRatio + 10);

		WGraphicsContainer::Graphics()->DrawRoundRect(TopBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(TopBar, 1, bordColor);

		// Left Bar
		WRECTF LeftBar = lbRec;
		LeftBar.Top(lbRec.Top() - 5);
		LeftBar.Left(lbRec.Left() - 5);
		LeftBar.Bottom(lbRec.Top() + GetHeight() / ExBordRatio + 10);
		LeftBar.Right(lbRec.Left() - 4);

		WGraphicsContainer::Graphics()->DrawRoundRect(LeftBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(LeftBar, 1, bordColor);

		// Bottom Bar
		WRECTF BottomBar = lbRec;

		BottomBar.Top(lbRec.Bottom() + 4);
		BottomBar.Left(lbRec.Right() - GetWidth() / ExBordRatio - 10);
		BottomBar.Bottom(lbRec.Bottom() + 5);
		BottomBar.Right(lbRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(BottomBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(BottomBar, 1, bordColor);

		// Right Bar
		WRECTF RightBar = lbRec;
		RightBar.Top(lbRec.Bottom() - GetHeight() / ExBordRatio - 10);
		RightBar.Left(lbRec.Right() + 4);
		RightBar.Bottom(lbRec.Bottom() + 5);
		RightBar.Right(lbRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(RightBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(RightBar, 1, bordColor);
	}

	WGraphicsContainer::Graphics()->DrawRoundRect(lbRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(lbRec, 1, backColor);

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

WPointF WListBox::Displace(W_FLOAT X, W_FLOAT Y)
{
	m_top += Y;
	m_bottom += Y;

	m_left += X;
	m_right += X;

	UpdateRect();
	return WPointF(X, Y);
}

WPointF WListBox::Displace(WPointF XY)
{
	m_top += XY.Y();
	m_bottom += XY.Y();

	m_left += XY.X();
	m_right += XY.X();

	UpdateRect();
	return WPointF(XY.X(), XY.Y());
}

WRegistry* WListBox::MouseDownRegistery(void)
{
	return LBMouseDownRegistery;
}

WRegistry* WListBox::MouseUpRegistery(void)
{
	return LBMouseUpRegistery;
}

WRegistry* WListBox::MouseEnterRegistery(void)
{
	return LBMouseEnterRegistery;
}

WRegistry* WListBox::MouseLeaveRegistery(void)
{
	return LBMouseLeaveRegistery;
}

WRegistry* WListBox::MouseRollUpRegistery(void)
{
	return LBMouseRollUpRegistery;
}

WRegistry* WListBox::MouseRollDownRegistery(void)
{
	return LBMouseRollDownRegistery;
}

WRegistry* WListBox::MouseDownRegistery(WRegistry* intake)
{
	LBMouseDownRegistery = intake;
	return LBMouseDownRegistery;
}

WRegistry* WListBox::MouseUpRegistery(WRegistry* intake)
{
	LBMouseUpRegistery = intake;
	return LBMouseUpRegistery;
}

WRegistry* WListBox::MouseEnterRegistery(WRegistry* intake)
{
	LBMouseEnterRegistery = intake;
	return LBMouseEnterRegistery;
}

WRegistry* WListBox::MouseLeaveRegistery(WRegistry* intake)
{
	LBMouseLeaveRegistery = intake;
	return LBMouseLeaveRegistery;
}

WRegistry* WListBox::MouseRollUpRegistery(WRegistry* intake)
{
	LBMouseRollUpRegistery = intake;
	return LBMouseRollUpRegistery;
}

WRegistry* WListBox::MouseRollDownRegistery(WRegistry* intake)
{
	LBMouseRollDownRegistery = intake;
	return LBMouseRollDownRegistery;
}

W_INT WListBox::ZIndex(void) const
{
	return m_zIndex;
}

bool WListBox::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WListBox::IsVisible(void) const
{
	return m_isVisible;
}


W_INT WListBox::ZIndex(W_INT input)
{
	WControlHandler::Remove(this);
	m_zIndex = input;
	WControlHandler::Add(this);
	return m_zIndex;
}

bool WListBox::IsEnabled(bool input)
{
	m_isEnabled = input;
	return m_isEnabled;
}

bool WListBox::IsVisible(bool input)
{
	m_isVisible = input;
	return m_isVisible;
}

void WListBox::MouseDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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
		m_isMouseDown = true;
		LBMouseDownRegistery->Run(this, Args);
	}
}

void WListBox::MouseUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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
		m_isMouseDown = false;
		LBMouseUpRegistery->Run(this, Args);
	}
}

void WListBox::MouseEnter(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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

		if (IsShrinked && !IsExtending)
		{
			ExBordLerpShrink->Lock();
			IsExtending = true;
			ExBordLerpExtend->Perform();
		}
		LBMouseEnterRegistery->Run(this, Args);
	}
}

void WListBox::MouseLeave(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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
		if (!IsShrinking)
		{
			ExBordLerpExtend->Lock();
			ExBordLerpShrink->Unlock();
			IsShrinking = true;
			ExBordLerpShrink->Perform();
		}
		LBMouseLeaveRegistery->Run(this, Args);
	}
}

void WListBox::MouseRollUp(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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
		if((m_yDisplace > -((m_ListItemHeight + 5) * (m_itemCount - 1))))
		{
			m_yDisplace -= m_DisplaceSpeed;
		}
		RenewItems();
		LBMouseRollUpRegistery->Run(this, Args);
	}
}

void WListBox::MouseRollDown(WMouseArgs* Args)
{
	if (!m_isEnabled)
		return;
	if (!m_isVisible)
		return;

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
		if (m_yDisplace < 0)
		{
			m_yDisplace += m_DisplaceSpeed;
		}
		RenewItems();
		LBMouseRollDownRegistery->Run(this, Args);
	}
}

IControl* WListBox::Parent(IControl* intake)
{
	m_Parent = intake;
	return m_Parent;
}

IControl* WListBox::Parent(void) const
{
	return m_Parent;
}

void WListBox::UpdateRect(void)
{
	lbRec.Top(m_top);
	lbRec.Left(m_left);
	lbRec.Bottom(m_bottom);
	lbRec.Right(m_right);
}

bool WListBox::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WListBox::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}

W_INT WListBox::GetWidth(void) const
{
	return (W_INT)(lbRec.Right() - lbRec.Left());
}

W_INT WListBox::GetHeight(void) const
{
	return (W_INT)(lbRec.Bottom() - lbRec.Top());
}

bool WListBox::UseExtendedBorder(void) const
{
	return m_UseExtendedBorder;
}

bool WListBox::UseExtendedBorder(bool intake)
{
	m_UseExtendedBorder = intake;
	return m_UseExtendedBorder;
}

WListBoxItem* WListBox::CreateItem(W_COLOR background, W_COLOR foreground, W_COLOR borderbrush, wchar_t* fontFamily, wchar_t* content, W_FLOAT fontSize, WTextAlignment alignment)
{
	m_itemCount++;

	// Create a New Item
	WListBoxItem* NewListBoxItem = new WListBoxItem();

	NewListBoxItem->Background(background);
	NewListBoxItem->Foreground(foreground);
	NewListBoxItem->BorderBrush(borderbrush);
	NewListBoxItem->FontFamily(fontFamily);
	NewListBoxItem->Content(content);
	NewListBoxItem->FontSize(fontSize);
	NewListBoxItem->Alignment(alignment);

	// Set the parent of the new Item
	NewListBoxItem->Parent(this);

	// Set the location of the new Item
	NewListBoxItem->Location
	(
		this->Location().Top() + ((m_itemCount - 1) * m_ListItemHeight) + (m_itemCount * 5) + m_yDisplace,	// Top
		this->Location().Left() + 5,																		// Left
		this->Location().Top() + ((m_ListItemHeight + 5)  * m_itemCount) + m_yDisplace,						// Bottom
		this->Location().Right() - 5																		// Right
	);

	// Push the new item
	m_items.push_back(NewListBoxItem);
	return NewListBoxItem;
}

int WListBox::RemoveLast(void)
{
	WListBoxItem* LastItem = m_items[m_itemCount];
	m_items.pop_back();
	m_itemCount--;
	delete LastItem;
	return m_itemCount;
}

int WListBox::AddItem(WListBoxItem* item)
{
	m_itemCount++;

	// Set the parent of the new Item
	item->Parent(this);

	// Set the location of the new Item
	item->Location
	(
		this->Location().Top() + ((m_itemCount - 1) * m_ListItemHeight) + (m_itemCount * 5) + m_yDisplace,	// Top
		this->Location().Left() + 5,																		// Left
		this->Location().Top() + ((m_ListItemHeight + 5)  * m_itemCount) + m_yDisplace,						// Bottom
		this->Location().Right() - 5																		// Right
	);

	// Push the new item
	m_items.push_back(item);
	return m_itemCount;
}

WListBoxItem* WListBox::GetLast(void)
{
	WListBoxItem* LastItem = m_items[m_itemCount];
	m_items.pop_back();
	m_itemCount--;
	return LastItem;
}

int WListBox::ItemCount(void) const
{
	return m_itemCount;
}

WListBoxItem* WListBox::GetAt(int index)
{
	if (index >= m_itemCount || index < 0)
	{
		return nullptr;
	}
	return m_items[index];
}

void WListBox::Extend(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WListBox::Shrink(WEntity* sender, WEventArgs* args)
{
	WLerpArgs* Largs = (WLerpArgs*)args;
	ExBordRatio = Largs->ValueExact() / 100;
}

void WListBox::ExtendDone(WEntity* sender, WEventArgs* args)
{
	ExBordLerpShrink->Unlock();
	IsExtending = false;
	IsExtended = true;
	IsShrinked = false;
}

void WListBox::ShrinkDone(WEntity* sender, WEventArgs* args)
{
	ExBordLerpExtend->Unlock();
	IsShrinking = false;
	IsExtended = false;
	IsShrinked = true;
}

void WListBox::RenewItems()
{
	for (size_t i = 1; i < m_itemCount + 1; i++)
	{
		m_items[i - 1]->Location
		(
			this->Location().Top() + ((i - 1) * m_ListItemHeight) + (i * 5) + m_yDisplace,	// Top
			this->Location().Left() + 5,													// Left
			this->Location().Top() + ((m_ListItemHeight + 5) * i) + m_yDisplace,			// Bottom
			this->Location().Right() - 5													// Right
		);
	}
}