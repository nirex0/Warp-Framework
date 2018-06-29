//© 2018 NIREX ALL RIGHTS RESERVED

#include "WFixedCanvas.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WFixedCanvas::WFixedCanvas(W_INT zIndex)
	: m_zIndex(zIndex)
{
	fcRec.Top((W_FLOAT)WGraphicsContainer::Graphics()->GetClientArea().top);
	fcRec.Left((W_FLOAT)WGraphicsContainer::Graphics()->GetClientArea().left);
	
	fcRec.Bottom((W_FLOAT)WGraphicsContainer::Graphics()->GetClientArea().bottom);
	fcRec.Right((W_FLOAT)WGraphicsContainer::Graphics()->GetClientArea().right);

	FCMouseDownRegistery = new WRegistry();
	FCMouseUpRegistery = new WRegistry();
	FCMouseEnterRegistery = new WRegistry();
	FCMouseLeaveRegistery = new WRegistry();
	FCMouseRollUpRegistery = new WRegistry();
	FCMouseRollDownRegistery = new WRegistry();

	m_isEnabled = true;
	m_isVisible = true;
}

WFixedCanvas::~WFixedCanvas()
{
	delete FCMouseDownRegistery;
	delete FCMouseUpRegistery;
	delete FCMouseEnterRegistery;
	delete FCMouseLeaveRegistery;
	delete FCMouseRollUpRegistery;
	delete FCMouseRollDownRegistery;

	WControlHandler::Remove(this);
}

WRectF WFixedCanvas::Location(void) const
{
	return WRectF(m_top, m_left, m_bottom, m_right);
}

void WFixedCanvas::Render(void)
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

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

WRegistry* WFixedCanvas::MouseDownRegistery(void)
{
	return FCMouseDownRegistery;
}

WRegistry* WFixedCanvas::MouseUpRegistery(void)
{
	return FCMouseUpRegistery;
}

WRegistry* WFixedCanvas::MouseEnterRegistery(void)
{
	return FCMouseEnterRegistery;
}

WRegistry* WFixedCanvas::MouseLeaveRegistery(void)
{
	return FCMouseLeaveRegistery;
}

WRegistry* WFixedCanvas::MouseRollUpRegistery(void)
{
	return FCMouseRollUpRegistery;
}

WRegistry* WFixedCanvas::MouseRollDownRegistery(void)
{
	return FCMouseRollDownRegistery;
}

WRegistry* WFixedCanvas::MouseDownRegistery(WRegistry* intake)
{
	FCMouseDownRegistery = intake;
	return FCMouseDownRegistery;
}

WRegistry* WFixedCanvas::MouseUpRegistery(WRegistry* intake)
{
	FCMouseUpRegistery = intake;
	return FCMouseUpRegistery;
}

WRegistry* WFixedCanvas::MouseEnterRegistery(WRegistry* intake)
{
	FCMouseEnterRegistery = intake;
	return FCMouseEnterRegistery;
}

WRegistry* WFixedCanvas::MouseLeaveRegistery(WRegistry* intake)
{
	FCMouseLeaveRegistery = intake;
	return FCMouseLeaveRegistery;
}

WRegistry* WFixedCanvas::MouseRollUpRegistery(WRegistry* intake)
{
	FCMouseRollUpRegistery = intake;
	return FCMouseRollUpRegistery;
}

WRegistry* WFixedCanvas::MouseRollDownRegistery(WRegistry* intake)
{
	FCMouseRollDownRegistery = intake;
	return FCMouseRollDownRegistery;
}

W_INT WFixedCanvas::ZIndex(void) const
{
	return m_zIndex;
}

bool WFixedCanvas::IsEnabled(void) const
{
	return m_isEnabled;
}

bool WFixedCanvas::IsVisible(void) const
{
	return m_isVisible;
}

W_INT WFixedCanvas::ZIndex(W_INT input)
{
	WControlHandler::Remove(this);
	m_zIndex = input;
	WControlHandler::Add(this);
	return m_zIndex;
}

bool WFixedCanvas::IsEnabled(bool input)
{
	m_isEnabled = input;
	return m_isEnabled;
}

bool WFixedCanvas::IsVisible(bool input)
{
	m_isVisible = input;
	return m_isVisible;
}

void WFixedCanvas::MouseDown(WMouseArgs* Args)
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
		FCMouseDownRegistery->Run(this, Args);
	}
}

void WFixedCanvas::MouseUp(WMouseArgs* Args)
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
		FCMouseUpRegistery->Run(this, Args);
	}
}

void WFixedCanvas::MouseEnter(WMouseArgs* Args)
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
		FCMouseEnterRegistery->Run(this, Args);
	}
}

void WFixedCanvas::MouseLeave(WMouseArgs* Args)
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
		FCMouseLeaveRegistery->Run(this, Args);
	}
}

void WFixedCanvas::MouseRollUp(WMouseArgs* Args)
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
		FCMouseRollUpRegistery->Run(this, Args);
	}
}

void WFixedCanvas::MouseRollDown(WMouseArgs* Args)
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
		FCMouseRollDownRegistery->Run(this, Args);
	}
}

IControl* WFixedCanvas::Parent(IControl* intake)
{
	m_Parent = intake;
	return m_Parent;
}

IControl* WFixedCanvas::Parent(void) const
{
	return m_Parent;
}

bool WFixedCanvas::IsWithin(WMouseArgs* Args) const
{
	return Location().IsColliding(Args->Point());
}

void WFixedCanvas::SetZIndexNoChange(W_INT zIndex)
{
	m_zIndex = zIndex;
}

W_INT WFixedCanvas::GetWidth(void) const
{
	return (W_INT)(fcRec.Right() - fcRec.Left());
}

W_INT WFixedCanvas::GetHeight(void) const
{
	return (W_INT)(fcRec.Bottom() - fcRec.Top());
}
