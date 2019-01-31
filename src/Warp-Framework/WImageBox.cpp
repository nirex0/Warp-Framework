// © 2019 NIREX ALL RIGHTS RESERVED

#include "WImageBox.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WImageBox::WImageBox(wchar_t* URL, W_INT zIndex)
	: WControl(zIndex)
	, m_URL(URL)
	, opacity(1.0F)
{
	WGraphicsContainer::Graphics()->LoadIMG(URL, &img);
}

WImageBox::WImageBox(wchar_t* URL, W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex)
	: WControl(top, left, bottom, right, zIndex)
	, m_URL(URL)
	, opacity(1.0F)
{
	WGraphicsContainer::Graphics()->LoadIMG(URL, &img);
}

WImageBox::WImageBox(wchar_t* URL, WPointF topleft, WPointF botright, W_INT zIndex)
	: WControl(topleft, botright, zIndex)
	, m_URL(URL)
	, opacity(1.0F)
{
	WGraphicsContainer::Graphics()->LoadIMG(URL, &img);
}

WImageBox::WImageBox(wchar_t* URL, WRectF location, W_INT zIndex)
	: WControl(location, zIndex)
	, m_URL(URL)
	, opacity(1.0F)
{
	WGraphicsContainer::Graphics()->LoadIMG(URL, &img);
}

WImageBox::~WImageBox(void)
{
	delete img;
}

void WImageBox::Render(void)
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
	WGraphicsContainer::Graphics()->DrawIMG(img, ctRec, opacity);

	WGraphicsContainer::Graphics()->SafeFlush();

	// End Mask Render
	WGraphicsContainer::Graphics()->GetRenderTarget()->PopLayer();
	SafeRelease(&maskLayer);
	SafeRelease(&MaskGeo);
	SafeRelease(&pSink);
}

wchar_t* WImageBox::URL(void) const
{
	return m_URL;
}

wchar_t* WImageBox::URL(wchar_t* intake)
{
	m_URL = intake;
	WGraphicsContainer::Graphics()->LoadIMG(intake, &img);
	return m_URL;
}

W_FLOAT WImageBox::Opacity(void) const
{
	return opacity;
}

W_FLOAT WImageBox::Opacity(W_FLOAT intake)
{
	opacity = intake;
	return opacity;
}
