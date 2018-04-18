//© 2018 NIREX ALL RIGHTS RESERVED

#include "WGraphics.h"
#include "WContainer.h"
#include "WDXContainer.h"
#include "WSafeRelease.h"

WGraphics::WGraphics(void)
	: m_DX_FAC(NULL)
	, m_DX_HRT(NULL)
	, m_DX_SCB(NULL)
{
}

WGraphics::~WGraphics(void)
{
	SafeRelease(&m_DX_FAC);
	SafeRelease(&m_DX_HRT);
	SafeRelease(&m_DX_SCB);
}

HRESULT WGraphics::CreateFactory(void)
{
	WContainer::hResult(S_OK);
	if (!m_bIsFacCreated)
	{
		m_bIsFacCreated = 1;
		return WContainer::hResult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_DX_FAC));
		WDXContainer::Factory(m_DX_FAC);
	}
	return WContainer::hResult(UpdateFactory());
}

HRESULT WGraphics::UpdateFactory(void)
{
	WContainer::hResult(S_OK);
	if (!m_DX_FAC)
	{
		WContainer::hResult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_DX_FAC));
		WDXContainer::Factory(m_DX_FAC);
	}
	return WContainer::hResult();
}


HRESULT WGraphics::CreateRenderTarget(void)
{
	WContainer::hResult(S_OK);
	if (!m_bIsHRTCreated)
	{
		m_bIsHRTCreated = 1;
		UpdateClientRect();

		return WContainer::hResult(m_DX_FAC->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_DX_REC.right - m_DX_REC.left,
					m_DX_REC.bottom - m_DX_REC.top)),
			&m_DX_HRT
		));
		WDXContainer::RenderTarget(m_DX_HRT);
	}
	return UpdateRenderTarget();
}

HRESULT WGraphics::UpdateRenderTarget(void)
{
	WContainer::hResult(S_OK);
	if (!m_DX_HRT)
	{
		UpdateClientRect();

		return WContainer::hResult(m_DX_FAC->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_DX_REC.right - m_DX_REC.left,
					m_DX_REC.bottom - m_DX_REC.top)),
			&m_DX_HRT
		));
		WDXContainer::RenderTarget(m_DX_HRT);
	}
	return WContainer::hResult();
}

HRESULT WGraphics::ResizeRenderTarget(W_UINT width, W_UINT height)
{
	WContainer::hResult(S_OK);
	if (m_DX_HRT)
	{
		UpdateClientRect();
		return WContainer::hResult(m_DX_HRT->Resize(D2D1::SizeU(width, height)));
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::CreateSolidColorBrush(const WColor& color)
{
	WContainer::hResult(S_OK);
	if (!m_bIsSCBCreated)
	{
		m_bIsSCBCreated = 1;
		return WContainer::hResult(m_DX_HRT->CreateSolidColorBrush(
			D2D1::ColorF(color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255),
			&m_DX_SCB));
	}
	return UpdateSolidColorBrush(color);
}

HRESULT WGraphics::UpdateSolidColorBrush(const WColor& color)
{
	WContainer::hResult(S_OK);
	if (!m_DX_HRT)
	{
		return 	WContainer::hResult(m_DX_HRT->CreateSolidColorBrush(
			D2D1::ColorF(color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255),
			&m_DX_SCB));
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateDeviceResources()
{
	WContainer::hResult(CreateFactory());
	WContainer::hResult(CreateRenderTarget());
	WContainer::hResult(CreateSolidColorBrush(WColor{ 0xFF, 0xFF, 0xFF, 0xFF }));
	return WContainer::hResult();
}

HRESULT WGraphics::UpdateDeviceResources()
{

	WContainer::hResult(UpdateFactory());
	WContainer::hResult(UpdateRenderTarget());
	WContainer::hResult(UpdateSolidColorBrush(WColor{ 0xFF, 0xFF, 0xFF, 0xFF }));
	return WContainer::hResult();
}

HRESULT WGraphics::UpdateClientRect(void)
{
	if (GetClientRect(WContainer::Handle(), &m_DX_REC))
	{
		WDXContainer::ClientArea(m_DX_REC);
		return WContainer::hResult(S_OK);
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::UpdateClientRect(HWND hWnd)
{
	if (GetClientRect(hWnd, &m_DX_REC))
	{
		WDXContainer::ClientArea(m_DX_REC);
		return WContainer::hResult(S_OK);
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::GetBrushColor(WColor& outColor)
{
	auto col = m_DX_SCB->GetColor();
	outColor.R((float)col.r * 255);
	outColor.G((float)col.g * 255);
	outColor.B((float)col.b * 255);
	outColor.A((float)col.a * 255);
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::SetBrushColor(const WColor& color)
{
	m_DX_SCB->SetColor(D2D1::ColorF(color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255));
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::SafeBeginDraw(void)
{
	if (!m_bIsDrawing)
	{
		m_DX_HRT->BeginDraw();
		m_bIsDrawing = 1;
		return WContainer::hResult(S_OK);
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::SafeEndDraw(void)
{
	if (m_bIsDrawing)
	{
		m_bIsDrawing = 0;
		return WContainer::hResult(m_DX_HRT->EndDraw());
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::SafeFlush(void)
{
	return WContainer::hResult(m_DX_HRT->Flush());
}

HRESULT WGraphics::SaveResources(void)
{
	WDXContainer::Factory(m_DX_FAC);
	WDXContainer::RenderTarget(m_DX_HRT);
	WDXContainer::ClientArea(m_DX_REC);
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::ClearWindow(WColor color)
{
	D2D1_COLOR_F tmpCol(m_DX_SCB->GetColor());

	D2D1_COLOR_F bgCol;
	bgCol.a = (float)(color.A()) / 255;
	bgCol.r = (float)(color.R()) / 255;
	bgCol.g = (float)(color.G()) / 255;
	bgCol.b = (float)(color.B()) / 255;

	m_DX_SCB->SetColor(bgCol);

	m_DX_HRT->FillRectangle(D2D1::RectF(m_DX_REC.left, m_DX_REC.top, m_DX_REC.right, m_DX_REC.bottom), m_DX_SCB);

	m_DX_SCB->SetColor(tmpCol);
	return WContainer::hResult(S_OK);
}

ID2D1Factory* WGraphics::GetFactory(void) const
{
	return m_DX_FAC;
}

ID2D1HwndRenderTarget* WGraphics::GetRenderTarget(void) const
{
	return m_DX_HRT;
}

ID2D1SolidColorBrush* WGraphics::GetColorBrush(void) const
{
	return m_DX_SCB;
}

RECT WGraphics::GetClientArea(void) const
{
	return m_DX_REC;
}
