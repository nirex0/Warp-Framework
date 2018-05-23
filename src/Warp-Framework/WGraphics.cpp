//© 2018 NIREX ALL RIGHTS RESERVED

#include "WGraphics.h"
#include "WContainer.h"
#include "WDXContainer.h"
#include "WSafeRelease.h"
#include "WCODEC.h"

WGraphics::WGraphics(void)
	: m_pD2D1Factory(NULL)
	, m_pD2D1RenderTarget(NULL)
	, m_pSolidColorBrush(NULL)
	, m_pLinearGradientBrush(NULL)
	, m_pRadialGradientBrush(NULL)
	, m_pIDWriteFactory(NULL)
	, m_pIDWriteTextFormat(NULL)
{
	m_FontFamilyName = L"Arial";
	m_FontSize = 14.0F;
}

WGraphics::~WGraphics(void)
{
	SafeRelease(&m_pD2D1Factory);
	SafeRelease(&m_pD2D1RenderTarget);
	SafeRelease(&m_pSolidColorBrush);
	SafeRelease(&m_pLinearGradientBrush);
	SafeRelease(&m_pRadialGradientBrush);
	SafeRelease(&m_pIDWriteFactory);
	SafeRelease(&m_pIDWriteTextFormat);
}

HRESULT WGraphics::CreateDeviceResources()
{
	POINTF tmpPt0;
	tmpPt0.x = 0;
	tmpPt0.y = 0;

	POINTF tmpPt1;
	tmpPt1.x = WContainer::Width();
	tmpPt1.y = WContainer::Height();

	WContainer::hResult(CreateFactory());
	WContainer::hResult(CreateRenderTarget());
	WContainer::hResult(CreateSolidColorBrush(W_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF }));
	WContainer::hResult(CreateLinearColorBrush(W_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF }, W_COLOR{ 0xFF, 0x00, 0x00, 0x00 }, tmpPt0, tmpPt1));
	WContainer::hResult(CreateWriteFactory());
	WContainer::hResult(CreateFormat());
	return WContainer::hResult();
}

HRESULT WGraphics::UpdateDeviceResources()
{
	POINTF tmpPt0;
	tmpPt0.x = 0;
	tmpPt0.y = 0;

	POINTF tmpPt1;
	tmpPt1.x = WContainer::Width();
	tmpPt1.y = WContainer::Height();

	WContainer::hResult(UpdateFactory());
	WContainer::hResult(UpdateRenderTarget());
	WContainer::hResult(UpdateSolidColorBrush(W_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF }));
	WContainer::hResult(UpdateLinearColorBrush(W_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF }, W_COLOR{ 0xFF, 0x00, 0x00, 0x00 }, tmpPt0, tmpPt1));
	WContainer::hResult(UpdateWriteFactory());
	WContainer::hResult(UpdateFormat());
	return WContainer::hResult();
}

HRESULT WGraphics::CreateFactory(void)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsFactoryCreated)
	{
		m_bIsFactoryCreated = 1;
		WContainer::hResult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2D1Factory));
		WDXContainer::Factory(m_pD2D1Factory);
		return WContainer::hResult();
	}
	return WContainer::hResult(UpdateFactory());
}

HRESULT WGraphics::UpdateFactory(void)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pD2D1Factory);
	if (!m_pD2D1Factory)
	{
		WContainer::hResult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2D1Factory));
		WDXContainer::Factory(m_pD2D1Factory);
	}
	return WContainer::hResult();
}


HRESULT WGraphics::CreateRenderTarget(void)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsRenderTargetCreated)
	{
		m_bIsRenderTargetCreated = 1;
		UpdateClientRect();

		WContainer::hResult(m_pD2D1Factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_ScreenRect.right - m_ScreenRect.left,
					m_ScreenRect.bottom - m_ScreenRect.top)),
			&m_pD2D1RenderTarget
		));
		WDXContainer::RenderTarget(m_pD2D1RenderTarget);
		return WContainer::hResult();
	}
	return UpdateRenderTarget();
}

HRESULT WGraphics::UpdateRenderTarget(void)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pD2D1RenderTarget);
	if (!m_pD2D1RenderTarget)
	{
		UpdateClientRect();

		WContainer::hResult(m_pD2D1Factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_ScreenRect.right - m_ScreenRect.left,
					m_ScreenRect.bottom - m_ScreenRect.top)),
			&m_pD2D1RenderTarget
		));
		WDXContainer::RenderTarget(m_pD2D1RenderTarget);
		return WContainer::hResult();
	}
	return WContainer::hResult();
}

HRESULT WGraphics::ResizeRenderTarget(W_UINT width, W_UINT height)
{
	WContainer::hResult(E_ABORT);
	if (m_pD2D1RenderTarget)
	{
		UpdateClientRect();
		return WContainer::hResult(m_pD2D1RenderTarget->Resize(D2D1::SizeU(width, height)));
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::CreateSolidColorBrush(const W_COLOR& color)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsSolidColorBrushCreated)
	{
		m_bIsSolidColorBrushCreated = 1;
		return WContainer::hResult(m_pD2D1RenderTarget->CreateSolidColorBrush(
			color,
			&m_pSolidColorBrush));
	}
	return UpdateSolidColorBrush(color);
}

HRESULT WGraphics::UpdateSolidColorBrush(const W_COLOR& color)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pSolidColorBrush);
	if (!m_pSolidColorBrush)
	{
		return WContainer::hResult(m_pD2D1RenderTarget->CreateSolidColorBrush(
			color,
			&m_pSolidColorBrush));
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateLinearColorBrush(const W_COLOR& color0, const W_COLOR& color1,const POINTF& pos0, const POINTF& pos1)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsLinearGradientBrushCreated)
	{
		m_bIsLinearGradientBrushCreated = 1;

		ID2D1GradientStopCollection *pGradientStops = NULL;
		D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES lbProps;
		lbProps.startPoint.x = pos0.x;
		lbProps.startPoint.y = pos0.y;

		lbProps.endPoint.x = pos1.x;
		lbProps.endPoint.y = pos1.y;

		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = color0;
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = color1;
		gradientStops[1].position = 1.0f;

		WContainer::hResult(m_pD2D1RenderTarget->CreateGradientStopCollection(gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradientStops));
		WContainer::hResult(m_pD2D1RenderTarget->CreateLinearGradientBrush(lbProps, pGradientStops, &m_pLinearGradientBrush));

		SafeRelease(&pGradientStops);

		return WContainer::hResult();
	}
	return UpdateLinearColorBrush(color0, color1, pos0, pos1);
}

HRESULT WGraphics::UpdateLinearColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& pos0, const POINTF& pos1)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pLinearGradientBrush);
	if (!m_pLinearGradientBrush)
	{
		ID2D1GradientStopCollection *pGradientStops = NULL;
		D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES lbProps;
		lbProps.startPoint.x = pos0.x;
		lbProps.startPoint.y = pos0.y;

		lbProps.endPoint.x = pos1.x;
		lbProps.endPoint.y = pos1.y;

		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = color0;
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = color1;
		gradientStops[1].position = 1.0f;

		WContainer::hResult(m_pD2D1RenderTarget->CreateGradientStopCollection(gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradientStops));
		WContainer::hResult(m_pD2D1RenderTarget->CreateLinearGradientBrush(lbProps, pGradientStops, &m_pLinearGradientBrush));

		SafeRelease(&pGradientStops);
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateRadialColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& center, const POINTF& offset, FLOAT radX, FLOAT radY)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsRadialGradientBrushCreated)
	{
		m_bIsRadialGradientBrushCreated = 1;

		ID2D1GradientStopCollection *pGradientStops = NULL;
		D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES rbProps;
		rbProps.center.x = center.x;
		rbProps.center.y = center.y;
		rbProps.radiusX = radX;
		rbProps.radiusY = radY;
		rbProps.gradientOriginOffset.x = offset.x;
		rbProps.gradientOriginOffset.y = offset.y;

		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = color0;
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = color1;
		gradientStops[1].position = 1.0f;


		WContainer::hResult(m_pD2D1RenderTarget->CreateGradientStopCollection(gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradientStops));
		WContainer::hResult(m_pD2D1RenderTarget->CreateRadialGradientBrush(rbProps, pGradientStops, &m_pRadialGradientBrush));

		SafeRelease(&pGradientStops);

		return WContainer::hResult();
	}
	return UpdateRadialColorBrush(color0, color1, center, offset, radX, radY);
}

HRESULT WGraphics::UpdateRadialColorBrush(const W_COLOR & color0, const W_COLOR & color1, const POINTF & center, const POINTF & offset, FLOAT radX, FLOAT radY)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pRadialGradientBrush);
	if (!m_pRadialGradientBrush)
	{
		ID2D1GradientStopCollection *pGradientStops = NULL;
		D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES rbProps;
		rbProps.center.x = center.x;
		rbProps.center.y = center.y;
		rbProps.radiusX = radX;
		rbProps.radiusY = radY;
		rbProps.gradientOriginOffset.x = offset.x;
		rbProps.gradientOriginOffset.y = offset.y;

		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = color0;
		gradientStops[0].position = 0.0f;
		gradientStops[1].color = color1;
		gradientStops[1].position = 1.0f;


		WContainer::hResult(m_pD2D1RenderTarget->CreateGradientStopCollection(gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradientStops));
		WContainer::hResult(m_pD2D1RenderTarget->CreateRadialGradientBrush(rbProps, pGradientStops, &m_pRadialGradientBrush));

		SafeRelease(&pGradientStops);
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateWriteFactory(void)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsDWriteFactoryCreated)
	{
		m_bIsDWriteFactoryCreated = 1;

		WContainer::hResult(DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_pIDWriteFactory)));
		WDXContainer::WriteFactory(m_pIDWriteFactory);
		return WContainer::hResult();
	}
	return WContainer::hResult(UpdateWriteFactory());
}

HRESULT WGraphics::UpdateWriteFactory(void)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pIDWriteFactory);
	if (!m_pIDWriteFactory)
	{
		WContainer::hResult(DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_pIDWriteFactory)));
		WDXContainer::WriteFactory(m_pIDWriteFactory);
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateFormat(void)
{
	WContainer::hResult(E_ABORT);
	if (!m_bIsDWiteTextFormatCreated)
	{
		m_bIsDWiteTextFormatCreated = 1;

		WContainer::hResult(
			m_pIDWriteFactory->CreateTextFormat(
				m_FontFamilyName,
				NULL,
				DWRITE_FONT_WEIGHT_REGULAR,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				m_FontSize,
				L"en-us",
				&m_pIDWriteTextFormat
			));
		WDXContainer::TextFormat(m_pIDWriteTextFormat);
		WContainer::hResult(m_pIDWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER));
		WContainer::hResult(m_pIDWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER));
		return WContainer::hResult();
	}
	return WContainer::hResult(UpdateFormat());

}

HRESULT WGraphics::UpdateFormat(void)
{
	WContainer::hResult(E_ABORT);
	SafeRelease(&m_pIDWriteTextFormat);
	if (!m_pIDWriteTextFormat)
	{
		WContainer::hResult(
			m_pIDWriteFactory->CreateTextFormat(
				m_FontFamilyName,
				NULL,
				DWRITE_FONT_WEIGHT_REGULAR,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				m_FontSize,
				L"en-us",
				&m_pIDWriteTextFormat
			));
		WDXContainer::TextFormat(m_pIDWriteTextFormat);
		WContainer::hResult(m_pIDWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER));
		WContainer::hResult(m_pIDWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER));
	}
	return WContainer::hResult();
}

HRESULT WGraphics::UpdateClientRect(void)
{
	if (GetClientRect(WContainer::Handle(), &m_ScreenRect))
	{
		WDXContainer::ClientArea(m_ScreenRect);
		return WContainer::hResult(S_OK);
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::UpdateClientRect(HWND hWnd)
{
	if (GetClientRect(hWnd, &m_ScreenRect))
	{
		WDXContainer::ClientArea(m_ScreenRect);
		return WContainer::hResult(S_OK);
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::GetBrushColor(W_COLOR& outColor)
{
	outColor = m_pSolidColorBrush->GetColor();
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::SetBrushColor(const W_COLOR& color)
{
	m_pSolidColorBrush->SetColor(color);
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::GetText(wchar_t* OutText, UINT32& OutLength) const
{
	OutText = m_C_TEXT;
	OutLength = m_TEXTLN;
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::SetText(wchar_t* Intake, UINT32 Length)
{
	m_C_TEXT = new wchar_t[Length];
	for (size_t i = 0; i < Length; i++)
	{
		m_C_TEXT[i] = Intake[i];
	}
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::SafeBeginDraw(void)
{
	if (!m_bIsDrawing)
	{
		m_pD2D1RenderTarget->BeginDraw();
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
		return WContainer::hResult(m_pD2D1RenderTarget->EndDraw());
	}
	return WContainer::hResult(E_FAIL);
}

HRESULT WGraphics::SafeFlush(void)
{
	return WContainer::hResult(m_pD2D1RenderTarget->Flush());
}

HRESULT WGraphics::SaveResources(void)
{
	WDXContainer::Factory(m_pD2D1Factory);
	WDXContainer::RenderTarget(m_pD2D1RenderTarget);
	WDXContainer::ClientArea(m_ScreenRect);
	WDXContainer::WriteFactory(m_pIDWriteFactory);
	WDXContainer::TextFormat(m_pIDWriteTextFormat);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::ClearWindow(W_COLOR color)
{
	D2D1_COLOR_F tmpCol(m_pSolidColorBrush->GetColor());

	CreateSolidColorBrush(color);
	m_pD2D1RenderTarget->FillRectangle(D2D1::RectF(m_ScreenRect.left, m_ScreenRect.top, m_ScreenRect.right, m_ScreenRect.bottom), m_pSolidColorBrush);

	m_pSolidColorBrush->SetColor(tmpCol);
	return WContainer::hResult(S_OK);
}

ID2D1Factory* WGraphics::GetFactory(void) const
{
	return m_pD2D1Factory;
}

ID2D1HwndRenderTarget* WGraphics::GetRenderTarget(void) const
{
	return m_pD2D1RenderTarget;
}

ID2D1SolidColorBrush* WGraphics::GetSolidColorBrush(void) const
{
	return m_pSolidColorBrush;
}

ID2D1LinearGradientBrush* WGraphics::GetLinearColorBrush(void) const
{
	return m_pLinearGradientBrush;
}

ID2D1RadialGradientBrush* WGraphics::GetRadialColorBrush(void) const
{
	return m_pRadialGradientBrush;
}

RECT WGraphics::GetClientArea(void) const
{
	return m_ScreenRect;
}

IDWriteFactory* WGraphics::GetWriteFactory(void) const
{
	return m_pIDWriteFactory;
}

IDWriteTextFormat* WGraphics::GetTextFormat(void) const
{
	return m_pIDWriteTextFormat;
}

wchar_t* WGraphics::GetText(void) const
{
	return m_C_TEXT;
}

UINT32 WGraphics::GetTextLength(void) const
{
	return m_TEXTLN;
}

wchar_t* WGraphics::FontFamily(void) const
{
	return m_FontFamilyName;
}

wchar_t* WGraphics::FontFamily(wchar_t* familyName)
{
	m_FontFamilyName = familyName;
	return m_FontFamilyName;
}

FLOAT WGraphics::FontSize(void) const
{
	return m_FontSize;
}

FLOAT WGraphics::FontSize(FLOAT intake)
{
	m_FontSize = intake;
	return m_FontSize;
}

HRESULT WGraphics::DrawRect(WRECTF boundaryRect, FLOAT bord_thickness, W_COLOR bord_color)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	CreateSolidColorBrush(bord_color); 
	m_pD2D1RenderTarget->DrawRectangle(D2D1RECTF, m_pSolidColorBrush, bord_thickness);
	
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRectSolid(WRECTF boundaryRect, W_COLOR back_color)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	CreateSolidColorBrush(back_color);
	m_pD2D1RenderTarget->FillRectangle(D2D1RECTF, m_pSolidColorBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRectLinear(WRECTF boundaryRect, W_COLOR back_color0, W_COLOR back_color1, WLinearGradientDirection direction)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	POINTF topLeft;
	topLeft.x = boundaryRect.Left();
	topLeft.y = boundaryRect.Top();

	POINTF topRight;
	topRight.x = boundaryRect.Right();
	topRight.y = boundaryRect.Top();

	POINTF bottomLeft;
	bottomLeft.x = boundaryRect.Left();
	bottomLeft.y = boundaryRect.Bottom();

	POINTF bottomRight;
	bottomRight.x = boundaryRect.Right();
	bottomRight.y = boundaryRect.Bottom();

	POINTF middleTop;
	middleTop.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleTop.y = boundaryRect.Top();

	POINTF middleLeft;
	middleLeft.x = boundaryRect.Left();
	middleLeft.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;


	POINTF middleBottom;
	middleBottom.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleBottom.y = boundaryRect.Bottom();

	POINTF middleRight;
	middleRight.x = boundaryRect.Right();
	middleRight.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	switch (direction)
	{
	case WLG_Invalid:
		return WContainer::hResult(E_ABORT);
	case WLG_Left_Right:
		CreateLinearColorBrush(back_color0, back_color1, middleLeft, middleRight);
		break;
	case WLG_Right_Left:
		CreateLinearColorBrush(back_color0, back_color1, middleRight, middleLeft);
		break;
	case WLG_Top_Bottom:
		CreateLinearColorBrush(back_color0, back_color1, middleTop, middleBottom);
		break;
	case WLG_Bottom_Top:
		CreateLinearColorBrush(back_color0, back_color1, middleBottom, middleTop);
		break;
	case WLG_TopLeft_BottomRight:
		CreateLinearColorBrush(back_color0, back_color1, topLeft, bottomRight);
		break;
	case WLG_TopRight_BottomLeft:
		CreateLinearColorBrush(back_color0, back_color1, topRight, bottomLeft);
		break;
	case WLG_BottomLeft_TopRight:
		CreateLinearColorBrush(back_color0, back_color1, bottomLeft, topRight);
		break;
	case WLG_BottomRight_TopLeft:
		CreateLinearColorBrush(back_color0, back_color1, bottomRight, topLeft);
		break;
	default:
		return WContainer::hResult(E_ABORT);
		break;
	}

	m_pD2D1RenderTarget->FillRectangle(D2D1RECTF, m_pLinearGradientBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRectRadial(WRECTF boundaryRect, W_COLOR back_color0, W_COLOR back_color1, POINTF offset, FLOAT radX, FLOAT radY, WLRadialGradientDirection direction)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	POINTF CENTER_POINT;
	CENTER_POINT.x = (D2D1RECTF.left + D2D1RECTF.right) / 2;
	CENTER_POINT.y = (D2D1RECTF.top + D2D1RECTF.bottom) / 2;

	POINTF topLeft;
	topLeft.x = boundaryRect.Left();
	topLeft.y = boundaryRect.Top();

	POINTF topRight;
	topRight.x = boundaryRect.Right();
	topRight.y = boundaryRect.Top();

	POINTF bottomLeft;
	bottomLeft.x = boundaryRect.Left();
	bottomLeft.y = boundaryRect.Bottom();

	POINTF bottomRight;
	bottomRight.x = boundaryRect.Right();
	bottomRight.y = boundaryRect.Bottom();

	POINTF middleTop;
	middleTop.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleTop.y = boundaryRect.Top();

	POINTF middleLeft;
	middleLeft.x = boundaryRect.Left();
	middleLeft.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;


	POINTF middleBottom;
	middleBottom.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleBottom.y = boundaryRect.Bottom();

	POINTF middleRight;
	middleRight.x = boundaryRect.Right();
	middleRight.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	switch (direction)
	{
	case WRG_Invalid:
		return WContainer::hResult(E_ABORT);
	case WRG_Center:
		CENTER_POINT.x = (D2D1RECTF.left + D2D1RECTF.right) / 2;
		CENTER_POINT.y = (D2D1RECTF.top + D2D1RECTF.bottom) / 2;
	case WRG_MiddleTop:
		CENTER_POINT = middleTop;
		break;
	case WRG_MiddleLeft:
		CENTER_POINT = middleLeft;
		break;
	case WRG_MiddleBottom:
		CENTER_POINT = middleBottom;
		break;
	case WRG_MiddleRight:
		CENTER_POINT = middleRight;
		break;
	case WRG_TopLeft:
		CENTER_POINT = topLeft;
		break;
	case WRG_TopRight:
		CENTER_POINT = topRight;
		break;
	case WRG_BottomLeft:
		CENTER_POINT = bottomLeft;
		break;
	case WRG_BottomRight:
		CENTER_POINT = bottomRight;
		break;
	default:
		return WContainer::hResult(E_ABORT);
	}

	CreateRadialColorBrush(back_color0, back_color1, CENTER_POINT, offset, radX, radY);
	m_pD2D1RenderTarget->FillRectangle(D2D1RECTF, m_pRadialGradientBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawRoundRect(WRECTF boundaryRect, FLOAT bord_thickness, FLOAT bord_radius, W_COLOR bord_color)
{
	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	m_pSolidColorBrush->SetColor(bord_color);
	//CreateSolidColorBrush(bord_color);
	m_pD2D1RenderTarget->DrawRoundedRectangle(D2D1RECTF, m_pSolidColorBrush, bord_thickness);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRoundRectSolid(WRECTF boundaryRect, FLOAT bord_radius, W_COLOR back_color)
{
	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	CreateSolidColorBrush(back_color); 
	m_pD2D1RenderTarget->FillRoundedRectangle(D2D1RECTF, m_pSolidColorBrush);
	
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRoundRectLinear(WRECTF boundaryRect, FLOAT bord_radius, W_COLOR back_color0, W_COLOR back_color1, WLinearGradientDirection direction)
{
	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	POINTF topLeft;
	topLeft.x = boundaryRect.Left();
	topLeft.y = boundaryRect.Top();

	POINTF topRight;
	topRight.x = boundaryRect.Right();
	topRight.y = boundaryRect.Top();

	POINTF bottomLeft;
	bottomLeft.x = boundaryRect.Left();
	bottomLeft.y = boundaryRect.Bottom();

	POINTF bottomRight;
	bottomRight.x = boundaryRect.Right();
	bottomRight.y = boundaryRect.Bottom();

	POINTF middleTop;
	middleTop.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleTop.y = boundaryRect.Top();

	POINTF middleLeft;
	middleLeft.x = boundaryRect.Left();
	middleLeft.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	POINTF middleBottom;
	middleBottom.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleBottom.y = boundaryRect.Bottom();

	POINTF middleRight;
	middleRight.x = boundaryRect.Right();
	middleRight.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	switch (direction)
	{
	case WLG_Invalid:
		return WContainer::hResult(E_ABORT);
	case WLG_Left_Right:
		CreateLinearColorBrush(back_color0, back_color1, middleLeft, middleRight);
		break;
	case WLG_Right_Left:
		CreateLinearColorBrush(back_color0, back_color1, middleRight, middleLeft);
		break;
	case WLG_Top_Bottom:
		CreateLinearColorBrush(back_color0, back_color1, middleTop, middleBottom);
		break;
	case WLG_Bottom_Top:
		CreateLinearColorBrush(back_color0, back_color1, middleBottom, middleTop);
		break;
	case WLG_TopLeft_BottomRight:
		CreateLinearColorBrush(back_color0, back_color1, topLeft, bottomRight);
		break;
	case WLG_TopRight_BottomLeft:
		CreateLinearColorBrush(back_color0, back_color1, topRight, bottomLeft);
		break;
	case WLG_BottomLeft_TopRight:
		CreateLinearColorBrush(back_color0, back_color1, bottomLeft, topRight);
		break;
	case WLG_BottomRight_TopLeft:
		CreateLinearColorBrush(back_color0, back_color1, bottomRight, topLeft);
		break;
	default:
		return WContainer::hResult(E_ABORT);
		break;
	}

	m_pD2D1RenderTarget->FillRoundedRectangle(D2D1RECTF, m_pLinearGradientBrush);
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRoundRectRadial(WRECTF boundaryRect, FLOAT bord_radius, W_COLOR back_color0, W_COLOR back_color1, POINTF offset, FLOAT radX, FLOAT radY, WLRadialGradientDirection direction)
{
	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	POINTF CENTER_POINT;
	CENTER_POINT.x = (D2D1RECTF.rect.left + D2D1RECTF.rect.right) / 2;
	CENTER_POINT.y = (D2D1RECTF.rect.top + D2D1RECTF.rect.bottom) / 2;

	POINTF topLeft;
	topLeft.x = boundaryRect.Left();
	topLeft.y = boundaryRect.Top();

	POINTF topRight;
	topRight.x = boundaryRect.Right();
	topRight.y = boundaryRect.Top();

	POINTF bottomLeft;
	bottomLeft.x = boundaryRect.Left();
	bottomLeft.y = boundaryRect.Bottom();

	POINTF bottomRight;
	bottomRight.x = boundaryRect.Right();
	bottomRight.y = boundaryRect.Bottom();

	POINTF middleTop;
	middleTop.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleTop.y = boundaryRect.Top();

	POINTF middleLeft;
	middleLeft.x = boundaryRect.Left();
	middleLeft.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	POINTF middleBottom;
	middleBottom.x = (boundaryRect.Right() - boundaryRect.Left()) / 2;
	middleBottom.y = boundaryRect.Bottom();

	POINTF middleRight;
	middleRight.x = boundaryRect.Right();
	middleRight.y = (boundaryRect.Bottom() - boundaryRect.Top()) / 2;

	switch (direction)
	{
	case WRG_Invalid:
		return WContainer::hResult(E_ABORT);
	case WRG_Center:
		CENTER_POINT.x = (D2D1RECTF.rect.left + D2D1RECTF.rect.right) / 2;
		CENTER_POINT.y = (D2D1RECTF.rect.top + D2D1RECTF.rect.bottom) / 2;
	case WRG_MiddleTop:
		CENTER_POINT = middleTop;
		break;
	case WRG_MiddleLeft:
		CENTER_POINT = middleLeft;
		break;
	case WRG_MiddleBottom:
		CENTER_POINT = middleBottom;
		break;
	case WRG_MiddleRight:
		CENTER_POINT = middleRight;
		break;
	case WRG_TopLeft:
		CENTER_POINT = topLeft;
		break;
	case WRG_TopRight:
		CENTER_POINT = topRight;
		break;
	case WRG_BottomLeft:
		CENTER_POINT = bottomLeft;
		break;
	case WRG_BottomRight:
		CENTER_POINT = bottomRight;
		break;
	default:
		return WContainer::hResult(E_ABORT);
	}

	CreateRadialColorBrush(back_color0, back_color1, CENTER_POINT, offset, radX, radY);
	m_pD2D1RenderTarget->FillRoundedRectangle(D2D1RECTF, m_pRadialGradientBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawEllipse(POINTF center, FLOAT radX, FLOAT radY, FLOAT bord_thickness, W_COLOR bord_color)
{
	D2D1_ELLIPSE D2D1ELIPSE;
	D2D1ELIPSE.point.x = center.x;
	D2D1ELIPSE.point.y = center.y;
	D2D1ELIPSE.radiusX = radX;
	D2D1ELIPSE.radiusY = radY;

	CreateSolidColorBrush(bord_color);
	m_pD2D1RenderTarget->DrawEllipse(D2D1ELIPSE, m_pSolidColorBrush, bord_thickness);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillEllipseSolid(POINTF center, FLOAT radX, FLOAT radY, W_COLOR back_color)
{
	D2D1_ELLIPSE D2D1ELIPSE;
	D2D1ELIPSE.point.x = center.x;
	D2D1ELIPSE.point.y = center.y;
	D2D1ELIPSE.radiusX = radX;
	D2D1ELIPSE.radiusY = radY;

	CreateSolidColorBrush(back_color);
	m_pD2D1RenderTarget->FillEllipse(D2D1ELIPSE, m_pSolidColorBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillEllipseRadial(POINTF center, FLOAT radX, FLOAT radY, W_COLOR back_color, W_COLOR back_color0, W_COLOR back_color1)
{
	D2D1_ELLIPSE D2D1ELIPSE;
	D2D1ELIPSE.point.x = center.x;
	D2D1ELIPSE.point.y = center.y;
	D2D1ELIPSE.radiusX = radX;
	D2D1ELIPSE.radiusY = radY;

	POINTF Null_Point;
	Null_Point.x = 0;
	Null_Point.y = 0;

	CreateRadialColorBrush(back_color0, back_color1, center, Null_Point, radX, radY);
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawLine(POINTF begin, POINTF end, W_COLOR color, FLOAT thickness)
{

	D2D1_POINT_2F D2D1POINTBEGIN;
	D2D1POINTBEGIN.x = begin.x;
	D2D1POINTBEGIN.y = begin.y;

	D2D1_POINT_2F D2D1POINTEND;
	D2D1POINTEND.x = end.x;	
	D2D1POINTEND.y = end.y;

	CreateSolidColorBrush(color);
	m_pD2D1RenderTarget->DrawLine(D2D1POINTBEGIN, D2D1POINTEND, m_pSolidColorBrush, thickness);
		
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawPoint(POINTF Coords, W_COLOR color)
{	
	D2D1_POINT_2F D2D1POINTBEGIN;
	D2D1POINTBEGIN.x = Coords.x;
	D2D1POINTBEGIN.y = Coords.y;

	D2D1_POINT_2F D2D1POINTEND;
	D2D1POINTEND.x = Coords.x + 1;
	D2D1POINTEND.y = Coords.y + 1;

	CreateSolidColorBrush(color);
	m_pD2D1RenderTarget->DrawLine(D2D1POINTBEGIN, D2D1POINTEND, m_pSolidColorBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::LoadBMP(LPCWSTR uri, W_IMAGE** ppImage)
{
	IWICImagingFactory*	pIWICFactory = NULL;
	IWICBitmapDecoder *pDecoder = NULL;
	IWICBitmapFrameDecode *pSource = NULL;
	IWICStream *pStream = NULL;
	IWICFormatConverter *pConverter = NULL;
	IWICBitmapScaler *pScaler = NULL;

	WContainer::hResult(CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&pIWICFactory));
	WContainer::hResult(pIWICFactory->CreateDecoderFromFilename(uri, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder));
	WContainer::hResult(pDecoder->GetFrame(0, &pSource));
	WContainer::hResult(pIWICFactory->CreateFormatConverter(&pConverter));
	WContainer::hResult(pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeMedianCut));
	WContainer::hResult(m_pD2D1RenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppImage));

	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);
	SafeRelease(&pIWICFactory);

	return WContainer::hResult();
}

HRESULT WGraphics::DrawBMP(W_IMAGE* pImage, WRECTF boundaryRect, FLOAT opacity)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	m_pD2D1RenderTarget->DrawBitmap(pImage, D2D1RECTF, opacity);
	
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::WriteText(WRECTF boundaryRect, WCHAR* text, UINT32 strLengh, WCHAR* fontfamily, FLOAT fontsize, W_COLOR text_color)
{
	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	FontSize(fontsize);
	FontFamily(fontfamily);
	UpdateFormat();

	CreateSolidColorBrush(text_color);
	m_pD2D1RenderTarget->DrawTextW(text, strLengh, m_pIDWriteTextFormat, D2D1RECTF, m_pSolidColorBrush);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawRect(WRECTF boundaryRect, WRectF borderThickness, W_COLOR bord_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_pSolidColorBrush->GetColor());

	D2D1_POINT_2F TOP_LEFT;
	D2D1_POINT_2F TOP_RIGHT;

	D2D1_POINT_2F BOTTOM_LEFT;
	D2D1_POINT_2F BOTTOM_RIGHT;

	TOP_LEFT.y = boundaryRect.Top(); 
	TOP_LEFT.x = boundaryRect.Left();

	TOP_RIGHT.y = boundaryRect.Top();
	TOP_RIGHT.x = boundaryRect.Right();

	BOTTOM_LEFT.y = boundaryRect.Bottom();
	BOTTOM_LEFT.x = boundaryRect.Left();

	BOTTOM_RIGHT.y = boundaryRect.Bottom();
	BOTTOM_RIGHT.x = boundaryRect.Right();

	CreateSolidColorBrush(bord_color);
	m_pD2D1RenderTarget->DrawLine(TOP_LEFT, TOP_RIGHT, m_pSolidColorBrush, borderThickness.Top());
	m_pD2D1RenderTarget->DrawLine(TOP_LEFT, BOTTOM_LEFT, m_pSolidColorBrush, borderThickness.Left());
	m_pD2D1RenderTarget->DrawLine(BOTTOM_LEFT, BOTTOM_RIGHT, m_pSolidColorBrush, borderThickness.Bottom());
	m_pD2D1RenderTarget->DrawLine(BOTTOM_RIGHT, TOP_RIGHT, m_pSolidColorBrush, borderThickness.Right());

	m_pD2D1RenderTarget->DrawLine(TOP_RIGHT, BOTTOM_LEFT, m_pSolidColorBrush, 1);
	m_pD2D1RenderTarget->DrawLine(TOP_LEFT, BOTTOM_RIGHT, m_pSolidColorBrush, 1);


	m_pSolidColorBrush->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

W_COLOR WGraphics::FromRGBA(INT R, INT G, INT B, FLOAT A) const
{
	return D2D1::ColorF(RGB(R, G, B), A);
}


HRESULT WGraphics::SetTransparency(UINT alpha)
{
	WContainer::BackA((W_BYTE)((alpha * 255) / 100));
	return WContainer::hResult(SetLayeredWindowAttributes(WContainer::Handle(), 0, (alpha * 255) / 100, LWA_ALPHA));
}

void W_MAIN_WINDOW::ResizeWindow(W_INT X, W_INT Y)
{
	RECT wndRect = {};
	GetWindowRect(WContainer::Handle(), &wndRect);

	SetWindowPos(WContainer::Handle(), HWND_TOP
		, wndRect.left	// Position.X
		, wndRect.top	// Position.Y
		, X				// Width
		, Y				// Height 
		, NULL);
}

void W_MAIN_WINDOW::RepositionWindow(W_INT X, W_INT Y)
{
	RECT wndRect = {};
	GetWindowRect(WContainer::Handle(), &wndRect);

	SetWindowPos(WContainer::Handle(), HWND_TOP
		, X, Y							// Position
		, wndRect.right - wndRect.left	// Width
		, wndRect.bottom - wndRect.top	// Height
		, NULL);
}

void W_MAIN_WINDOW::DragMoveWindow(W_INT Yoffset)
{
	POINT globalP;
	GetCursorPos(&globalP);

	RepositionWindow(
		globalP.x- WContainer::HCX(),
		globalP.y - WContainer::HCY());
}