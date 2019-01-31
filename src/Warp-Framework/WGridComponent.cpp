// © 2019 NIREX ALL RIGHTS RESERVED

#include "WGridComponent.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WGridComponent::WGridComponent(W_INT zIndex)
	: WControl(zIndex)
	, m_thickness(1.0F)
	, m_sqSize(10.0F)
{
	m_color = WContainer::Theme().ColorBorder();
}

WGridComponent::WGridComponent(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_thickness(1.0F)
	, m_sqSize(10.0F)
{
	m_color = WContainer::Theme().ColorBorder();
}

WGridComponent::WGridComponent(WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_thickness(1.0F)
	, m_sqSize(10.0F)
{
	m_color = WContainer::Theme().ColorBorder();
}

WGridComponent::WGridComponent(WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_thickness(1.0F)
	, m_sqSize(10.0F)
{
	m_color = WContainer::Theme().ColorBorder();
}

W_FLOAT WGridComponent::SquareSize(W_FLOAT f)
{
	if (f <= 10)
	{
		m_sqSize = 10;
		return 10;
	}

	m_sqSize = f;
	return m_sqSize;
}

W_FLOAT WGridComponent::LineThickness(W_FLOAT f)
{
	m_thickness = f;
	return m_thickness;
}

W_COLOR WGridComponent::Color(W_COLOR col)
{
	m_color = col;
	return m_color;
}

W_FLOAT WGridComponent::SquareSize(void) const
{
	return m_sqSize;
}

W_FLOAT WGridComponent::LineThickness(void) const
{
	return m_thickness;
}

W_COLOR WGridComponent::Color(void) const
{
	return m_color;
}

void WGridComponent::Render(void)
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

	WRectF parent;
	parent.Top(ParentRect.top);
	parent.Left(ParentRect.left);
	parent.Bottom(ParentRect.bottom);
	parent.Right(ParentRect.right);

	WRectF ct;
	ct.Top(ctRec.Top());
	ct.Left(ctRec.Left());
	ct.Bottom(ctRec.Bottom());
	ct.Right(ctRec.Right());

	if (!parent.IsColliding(ct))
	{
		return;
	}

	// Mask
	ID2D1PathGeometry* MaskGeo;
	WGraphicsContainer::Graphics()->GetFactory()->CreatePathGeometry(&MaskGeo);

	// Geometry Sink
	ID2D1GeometrySink* pSink = nullptr;
	MaskGeo->Open(&pSink);
	pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
	pSink->BeginFigure(D2D1::Point2F(ParentRect.left, ParentRect.top), D2D1_FIGURE_BEGIN_FILLED);
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.top));
	pSink->AddLine(D2D1::Point2F(ParentRect.right, ParentRect.bottom));
	pSink->AddLine(D2D1::Point2F(ParentRect.left, ParentRect.bottom));
	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
	pSink->Close();

	// Begin Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->CreateLayer(nullptr, &maskLayer);
	WGraphicsContainer::Graphics()->GetRenderTarget()->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(), MaskGeo), maskLayer);

	// Render Statements Go Here
	// VERTICAL
	int curWidthLoc = (W_INT)ctRec.Left();
	while (curWidthLoc < ctRec.Right())
	{
		POINTF begin;
		begin.x = (W_FLOAT)curWidthLoc;
		begin.y = (W_FLOAT)ctRec.Top();

		POINTF end;
		end.x = (W_FLOAT)curWidthLoc;
		end.y = (W_FLOAT)ctRec.Bottom();

		WGraphicsContainer::Graphics()->DrawLine(begin, end, m_color, m_thickness);
		WGraphicsContainer::Graphics()->SafeFlush();
		curWidthLoc += (W_INT)m_sqSize;
	}

	// HORIZONTAL
	int curHeightLoc = (W_INT)ctRec.Top();
	while (curHeightLoc < ctRec.Bottom())
	{
		POINTF begin;
		begin.x = (W_FLOAT)ctRec.Left();
		begin.y = (W_FLOAT)curHeightLoc;

		POINTF end;
		end.x = (W_FLOAT)ctRec.Right();
		end.y = (W_FLOAT)curHeightLoc;

		WGraphicsContainer::Graphics()->DrawLine(begin, end, m_color, m_thickness);
		WGraphicsContainer::Graphics()->SafeFlush();
		curHeightLoc += (W_INT)m_sqSize;
	}

	// SQUARE
	//WGraphicsContainer::Graphics()->DrawRect(ctRec, m_thickness + 2, m_color, ctRec);
	WGraphicsContainer::Graphics()->SafeFlush();


	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}
