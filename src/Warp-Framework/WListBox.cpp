// © 2018 NIREX ALL RIGHTS RESERVED

#include "WListBox.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WListBox::WListBox(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);
	
	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));
	
	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WListBox::WListBox(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WListBox::WListBox(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WListBox::WListBox(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, ExBordRatio(5)
{
	foreColor = WContainer::Theme().ColorText();
	backColor = WContainer::Theme().ColorBack();
	bordColor = WContainer::Theme().ColorBorder();

	ExBordLerpExtend = new WLerp(500, 100, 0.07F, 1);
	ExBordLerpShrink = new WLerp(100, 500, 0.07F, 1);

	ExBordLerpExtend->TickRegistry()->Register(std::bind(&WListBox::Extend, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->TickRegistry()->Register(std::bind(&WListBox::Shrink, this, std::placeholders::_1, std::placeholders::_2));

	ExBordLerpExtend->DoneRegistry()->Register(std::bind(&WListBox::ExtendDone, this, std::placeholders::_1, std::placeholders::_2));
	ExBordLerpShrink->DoneRegistry()->Register(std::bind(&WListBox::ShrinkDone, this, std::placeholders::_1, std::placeholders::_2));

	m_UseExtendedBorder = true;
}

WListBox::~WListBox()
{
	delete ExBordLerpExtend;
	delete ExBordLerpShrink;
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
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;

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
		WRECTF TopBar = ctRec;
		TopBar.Top(ctRec.Top() - 5);
		TopBar.Left(ctRec.Left() - 5);
		TopBar.Bottom(ctRec.Top() - 4);
		TopBar.Right(ctRec.Left() + GetWidth() / ExBordRatio + 10);

		WGraphicsContainer::Graphics()->DrawRoundRect(TopBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(TopBar, 1, bordColor);

// Left Bar
		WRECTF LeftBar = ctRec;
		LeftBar.Top(ctRec.Top() - 5);
		LeftBar.Left(ctRec.Left() - 5);
		LeftBar.Bottom(ctRec.Top() + GetHeight() / ExBordRatio + 10);
		LeftBar.Right(ctRec.Left() - 4);

		WGraphicsContainer::Graphics()->DrawRoundRect(LeftBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(LeftBar, 1, bordColor);

// Bottom Bar
		WRECTF BottomBar = ctRec;

		BottomBar.Top(ctRec.Bottom() + 4);
		BottomBar.Left(ctRec.Right() - GetWidth() / ExBordRatio - 10);
		BottomBar.Bottom(ctRec.Bottom() + 5);
		BottomBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(BottomBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(BottomBar, 1, bordColor);

// Right Bar
		WRECTF RightBar = ctRec;
		RightBar.Top(ctRec.Bottom() - GetHeight() / ExBordRatio - 10);
		RightBar.Left(ctRec.Right() + 4);
		RightBar.Bottom(ctRec.Bottom() + 5);
		RightBar.Right(ctRec.Right() + 5);

		WGraphicsContainer::Graphics()->DrawRoundRect(RightBar, 2, 1, bordColor);
		WGraphicsContainer::Graphics()->FillRoundRectSolid(RightBar, 1, bordColor);
	}

	WGraphicsContainer::Graphics()->DrawRoundRect(ctRec, m_thickness, 2, bordColor);
	WGraphicsContainer::Graphics()->FillRoundRectSolid(ctRec, 1, backColor);

// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

void WListBox::MouseEnter(WMouseArgs* Args)
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

		if (IsShrinked && !IsExtending)
		{
			ExBordLerpShrink->Lock();
			IsExtending = true;
			ExBordLerpExtend->Perform();
		}
		WCTMouseEnterRegistery->Run(this, Args);
	}
}

void WListBox::MouseLeave(WMouseArgs* Args)
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
		if (!IsShrinking)
		{
			ExBordLerpExtend->Lock();
			ExBordLerpShrink->Unlock();
			IsShrinking = true;
			ExBordLerpShrink->Perform();
		}
		WCTMouseLeaveRegistery->Run(this, Args);
	}
}

void WListBox::MouseRollUp(WMouseArgs* Args)
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
		if((m_yDisplace > -((m_ListItemHeight + 5) * (m_itemCount - 1))))
		{
			m_yDisplace -= m_DisplaceSpeed;
		}
		RenewItems();
		WCTMouseRollUpRegistery->Run(this, Args);
	}
}

void WListBox::MouseRollDown(WMouseArgs* Args)
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
		if (m_yDisplace < 0)
		{
			m_yDisplace += m_DisplaceSpeed;
		}
		RenewItems();
		WCTMouseRollDownRegistery->Run(this, Args);
	}
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
		this->Location().Top() + ((m_itemCount - 1) * m_ListItemHeight) + (m_itemCount * 5) + m_yDisplace,// Top
		this->Location().Left() + 5,																// Left
		this->Location().Top() + ((m_ListItemHeight + 5)  * m_itemCount) + m_yDisplace,				// Bottom
		this->Location().Right() - 5																// Right
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
		this->Location().Top() + ((m_itemCount - 1) * m_ListItemHeight) + (m_itemCount * 5) + m_yDisplace,// Top
		this->Location().Left() + 5,																// Left
		this->Location().Top() + ((m_ListItemHeight + 5)  * m_itemCount) + m_yDisplace,				// Bottom
		this->Location().Right() - 5																// Right
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
			this->Location().Top() + ((i - 1) * m_ListItemHeight) + (i * 5) + m_yDisplace,// Top
			this->Location().Left() + 5,											// Left
			this->Location().Top() + ((m_ListItemHeight + 5) * i) + m_yDisplace,	// Bottom
			this->Location().Right() - 5											// Right
		);
	}
}