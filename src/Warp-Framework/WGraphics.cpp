//© 2018 NIREX ALL RIGHTS RESERVED

#include "WGraphics.h"
#include "WContainer.h"
#include "WDXContainer.h"
#include "WSafeRelease.h"

WGraphics::WGraphics(void)
	: m_DX_FAC(NULL)
	, m_DX_HRT(NULL)
	, m_DX_SCB(NULL)
	, m_DW_FAC(NULL)
	, m_DW_TXF(NULL)
{
	m_FontFamilyName = L"Arial";
	m_FontSize = 14.0F;
}

WGraphics::~WGraphics(void)
{
	SafeRelease(&m_DX_FAC);
	SafeRelease(&m_DX_HRT);
	SafeRelease(&m_DX_SCB);
	SafeRelease(&m_DW_FAC);
	SafeRelease(&m_DW_TXF);
}

HRESULT WGraphics::CreateFactory(void)
{
	WContainer::hResult(S_OK);
	if (!m_bIsFacCreated)
	{
		m_bIsFacCreated = 1;
		WContainer::hResult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_DX_FAC));
		WDXContainer::Factory(m_DX_FAC);
		return WContainer::hResult();
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

		WContainer::hResult(m_DX_FAC->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_DX_REC.right - m_DX_REC.left,
					m_DX_REC.bottom - m_DX_REC.top)),
			&m_DX_HRT
		));
		WDXContainer::RenderTarget(m_DX_HRT);
		return WContainer::hResult();
	}
	return UpdateRenderTarget();
}

HRESULT WGraphics::UpdateRenderTarget(void)
{
	WContainer::hResult(S_OK);
	if (!m_DX_HRT)
	{
		UpdateClientRect();

		WContainer::hResult(m_DX_FAC->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT),
			D2D1::HwndRenderTargetProperties(
				WContainer::Handle(),
				D2D1::SizeU(
					m_DX_REC.right - m_DX_REC.left,
					m_DX_REC.bottom - m_DX_REC.top)),
			&m_DX_HRT
		));
		WDXContainer::RenderTarget(m_DX_HRT);
		return WContainer::hResult();
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
		return WContainer::hResult(m_DX_HRT->CreateSolidColorBrush(
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
	WContainer::hResult(CreateWriteFactory());
	WContainer::hResult(CreateFormat());
	return WContainer::hResult();
}

HRESULT WGraphics::UpdateDeviceResources()
{

	WContainer::hResult(UpdateFactory());
	WContainer::hResult(UpdateRenderTarget());
	WContainer::hResult(UpdateSolidColorBrush(WColor{ 0xFF, 0xFF, 0xFF, 0xFF }));
	WContainer::hResult(UpdateWriteFactory());
	WContainer::hResult(UpdateFormat());
	return WContainer::hResult();
}

HRESULT WGraphics::CreateWriteFactory(void)
{
	WContainer::hResult(S_OK);
	if (!m_bIsDWFCreated)
	{
		m_bIsDWFCreated = 1;

		WContainer::hResult(DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_DW_FAC)));
		WDXContainer::WriteFactory(m_DW_FAC);
		return WContainer::hResult();
	}
	return WContainer::hResult(UpdateWriteFactory());
}

HRESULT WGraphics::UpdateWriteFactory(void)
{
	WContainer::hResult(S_OK);
	if (!m_DW_FAC)
	{
		WContainer::hResult(DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_DW_FAC)));
		WDXContainer::WriteFactory(m_DW_FAC);
	}
	return WContainer::hResult();
}

HRESULT WGraphics::CreateFormat(void)
{
	WContainer::hResult(S_OK);
	if (!m_bIsDWTXreated)
	{
		m_bIsDWTXreated = 1;

		WContainer::hResult(
			m_DW_FAC->CreateTextFormat(
				m_FontFamilyName,
				NULL,
				DWRITE_FONT_WEIGHT_REGULAR,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				m_FontSize,
				L"en-us",
				&m_DW_TXF
			));
		WDXContainer::TextFormat(m_DW_TXF);
		WContainer::hResult(m_DW_TXF->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER));
		WContainer::hResult(m_DW_TXF->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER));
		return WContainer::hResult();
	}
	return WContainer::hResult(UpdateFormat());

}

HRESULT WGraphics::UpdateFormat(void)
{
	WContainer::hResult(S_OK);
	SafeRelease(&m_DW_TXF);
	if (!m_DW_TXF)
	{
		WContainer::hResult(
			m_DW_FAC->CreateTextFormat(
				m_FontFamilyName,
				NULL,
				DWRITE_FONT_WEIGHT_REGULAR,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				m_FontSize,
				L"en-us",
				&m_DW_TXF
			));
		WDXContainer::TextFormat(m_DW_TXF);
		WContainer::hResult(m_DW_TXF->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER));
		WContainer::hResult(m_DW_TXF->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER));
	}
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
	WDXContainer::WriteFactory(m_DW_FAC);
	WDXContainer::TextFormat(m_DW_TXF);

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

IDWriteFactory* WGraphics::GetWriteFactory(void) const
{
	return m_DW_FAC;
}

IDWriteTextFormat* WGraphics::GetTextFormat(void) const
{
	return m_DW_TXF;
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

float WGraphics::FontSize(void) const
{
	return m_FontSize;
}

float WGraphics::FontSize(float intake)
{
	m_FontSize = intake;
	return m_FontSize;
}

HRESULT WGraphics::DrawRect(WRECTF boundaryRect, float bord_thickness, WColor bord_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(bord_color.A()) / 255;
	D2D1COLOR.r = (float)(bord_color.R()) / 255;
	D2D1COLOR.g = (float)(bord_color.G()) / 255;
	D2D1COLOR.b = (float)(bord_color.B()) / 255;

	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawRectangle(D2D1RECTF, m_DX_SCB, bord_thickness);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRect(WRECTF boundaryRect, WColor back_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(back_color.A()) / 255;
	D2D1COLOR.r = (float)(back_color.R()) / 255;
	D2D1COLOR.g = (float)(back_color.G()) / 255;
	D2D1COLOR.b = (float)(back_color.B()) / 255;

	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->FillRectangle(D2D1RECTF, m_DX_SCB);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawRoundRect(WRECTF boundaryRect, float bord_thickness, float bord_radius, WColor bord_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(bord_color.A()) / 255;
	D2D1COLOR.r = (float)(bord_color.R()) / 255;
	D2D1COLOR.g = (float)(bord_color.G()) / 255;
	D2D1COLOR.b = (float)(bord_color.B()) / 255;

	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawRoundedRectangle(D2D1RECTF, m_DX_SCB, bord_thickness);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillRoundRect(WRECTF boundaryRect, float bord_radius, WColor back_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(back_color.A()) / 255;
	D2D1COLOR.r = (float)(back_color.R()) / 255;
	D2D1COLOR.g = (float)(back_color.G()) / 255;
	D2D1COLOR.b = (float)(back_color.B()) / 255;

	D2D1_ROUNDED_RECT D2D1RECTF;
	D2D1RECTF.rect.top = boundaryRect.Top();
	D2D1RECTF.rect.left = boundaryRect.Left();
	D2D1RECTF.rect.bottom = boundaryRect.Bottom();
	D2D1RECTF.rect.right = boundaryRect.Right();
	D2D1RECTF.radiusX = bord_radius;
	D2D1RECTF.radiusY = bord_radius;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->FillRoundedRectangle(D2D1RECTF, m_DX_SCB);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawEllipse(POINTF center, float radX, float radY, float bord_thickness, WColor bord_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(bord_color.A()) / 255;
	D2D1COLOR.r = (float)(bord_color.R()) / 255;
	D2D1COLOR.g = (float)(bord_color.G()) / 255;
	D2D1COLOR.b = (float)(bord_color.B()) / 255;

	D2D1_ELLIPSE D2D1ELIPSE;
	D2D1ELIPSE.point.x = center.x;
	D2D1ELIPSE.point.y = center.y;
	D2D1ELIPSE.radiusX = radX;
	D2D1ELIPSE.radiusY = radY;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawEllipse(D2D1ELIPSE, m_DX_SCB, bord_thickness);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::FillEllipse(POINTF center, float radX, float radY, WColor back_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(back_color.A()) / 255;
	D2D1COLOR.r = (float)(back_color.R()) / 255;
	D2D1COLOR.g = (float)(back_color.G()) / 255;
	D2D1COLOR.b = (float)(back_color.B()) / 255;

	D2D1_ELLIPSE D2D1ELIPSE;
	D2D1ELIPSE.point.x = center.x;
	D2D1ELIPSE.point.y = center.y;
	D2D1ELIPSE.radiusX = radX;
	D2D1ELIPSE.radiusY = radY;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->FillEllipse(D2D1ELIPSE, m_DX_SCB);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawLine(POINTF begin, POINTF end, WColor color, float thickness)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(color.A()) / 255;
	D2D1COLOR.r = (float)(color.R()) / 255;
	D2D1COLOR.g = (float)(color.G()) / 255;
	D2D1COLOR.b = (float)(color.B()) / 255;

	D2D1_POINT_2F D2D1POINTBEGIN;
	D2D1POINTBEGIN.x = begin.x;
	D2D1POINTBEGIN.y = begin.y;

	D2D1_POINT_2F D2D1POINTEND;
	D2D1POINTEND.x = end.x;	
	D2D1POINTEND.y = end.y;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawLine(D2D1POINTBEGIN, D2D1POINTEND, m_DX_SCB, thickness);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);
		
	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawPoint(POINTF Coords, WColor color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(color.A()) / 255;
	D2D1COLOR.r = (float)(color.R()) / 255;
	D2D1COLOR.g = (float)(color.G()) / 255;
	D2D1COLOR.b = (float)(color.B()) / 255;
	
	D2D1_POINT_2F D2D1POINTBEGIN;
	D2D1POINTBEGIN.x = Coords.x;
	D2D1POINTBEGIN.y = Coords.y;

	D2D1_POINT_2F D2D1POINTEND;
	D2D1POINTEND.x = Coords.x + 1;
	D2D1POINTEND.y = Coords.y + 1;

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawLine(D2D1POINTBEGIN, D2D1POINTEND, m_DX_SCB);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::WriteText(WRECTF boundaryRect, WCHAR* text, UINT32 strLengh, WCHAR* fontfamily, float fontsize, WColor text_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(text_color.A()) / 255;
	D2D1COLOR.r = (float)(text_color.R()) / 255;
	D2D1COLOR.g = (float)(text_color.G()) / 255;
	D2D1COLOR.b = (float)(text_color.B()) / 255;

	D2D_RECT_F D2D1RECTF;
	D2D1RECTF.top = boundaryRect.Top();
	D2D1RECTF.left = boundaryRect.Left();
	D2D1RECTF.bottom = boundaryRect.Bottom();
	D2D1RECTF.right = boundaryRect.Right();

	FontSize(fontsize);
	FontFamily(fontfamily);
	UpdateFormat();

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawTextW(text, strLengh, m_DW_TXF, D2D1RECTF, m_DX_SCB);
	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

HRESULT WGraphics::DrawRect(WRECTF boundaryRect, WThickness borderThickness, WColor bord_color)
{
	D2D1_COLOR_F D2D1TMPCOLOR(m_DX_SCB->GetColor());

	D2D1_COLOR_F D2D1COLOR;
	D2D1COLOR.a = (float)(bord_color.A()) / 255;
	D2D1COLOR.r = (float)(bord_color.R()) / 255;
	D2D1COLOR.g = (float)(bord_color.G()) / 255;
	D2D1COLOR.b = (float)(bord_color.B()) / 255;

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

	m_DX_SCB->SetColor(D2D1COLOR);
	m_DX_HRT->DrawLine(TOP_LEFT, TOP_RIGHT, m_DX_SCB, borderThickness.Top());
	m_DX_HRT->DrawLine(TOP_LEFT, BOTTOM_LEFT, m_DX_SCB, borderThickness.Left());
	m_DX_HRT->DrawLine(BOTTOM_LEFT, BOTTOM_RIGHT, m_DX_SCB, borderThickness.Bottom());
	m_DX_HRT->DrawLine(BOTTOM_RIGHT, TOP_RIGHT, m_DX_SCB, borderThickness.Right());

	m_DX_HRT->DrawLine(TOP_RIGHT, BOTTOM_LEFT, m_DX_SCB, 1);
	m_DX_HRT->DrawLine(TOP_LEFT, BOTTOM_RIGHT, m_DX_SCB, 1);

	m_DX_SCB->SetColor(D2D1TMPCOLOR);

	return WContainer::hResult(S_OK);
}

void W_MAIN_WINDOW::ResizeWindow(int X, int Y)
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

void W_MAIN_WINDOW::RepositionWindow(int X, int Y)
{
	RECT wndRect = {};
	GetWindowRect(WContainer::Handle(), &wndRect);

	SetWindowPos(WContainer::Handle(), HWND_TOP
		, X, Y							// Position
		, wndRect.right - wndRect.left	// Width
		, wndRect.bottom - wndRect.top	// Height
		, NULL);
}

void W_MAIN_WINDOW::DragMoveWindow(int Yoffset)
{
	POINT localP;
	GetCursorPos(&localP);
	ScreenToClient(WContainer::Handle(), &localP);
	
	RECT wndRect = {};
	GetWindowRect(WContainer::Handle(), &wndRect);

	int newXpos = wndRect.left + localP.x - ((wndRect.right - wndRect.left) / 2);
	int newYpos = wndRect.top + localP.y - Yoffset;

	RepositionWindow(newXpos, newYpos);
}
