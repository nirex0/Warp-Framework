//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GRAPHICS_H_
#define _W_GRAPHICS_H_

#include "WDX.h"
#include "WEntity.h"
#include "WColor.h"
#include "WDefines.h"

class WGraphics : public WEntity
{
public:
	WGraphics(void);
	~WGraphics(void);

	HRESULT CreateFactory(void);
	HRESULT UpdateFactory(void);

	HRESULT CreateRenderTarget(void);
	HRESULT UpdateRenderTarget(void);
	HRESULT ResizeRenderTarget(W_UINT width, W_UINT height);

	HRESULT CreateSolidColorBrush(const WColor& color);
	HRESULT UpdateSolidColorBrush(const WColor& color);

	HRESULT CreateDeviceResources(void);
	HRESULT UpdateDeviceResources(void);

	HRESULT CreateWriteFactory(void);
	HRESULT UpdateWriteFactory(void);

	HRESULT CreateFormat(void);
	HRESULT UpdateFormat(void);

	HRESULT UpdateClientRect(void);
	HRESULT UpdateClientRect(HWND hWnd);

	HRESULT GetBrushColor(WColor& outColor);
	HRESULT SetBrushColor(const WColor& color);

	HRESULT GetText(wchar_t* OutText, UINT32& OutLength) const;
	HRESULT SetText(wchar_t* Intake, UINT32 Length);

	HRESULT SafeBeginDraw(void);
	HRESULT SafeEndDraw(void);
	HRESULT SafeFlush(void);

	HRESULT SaveResources(void);
	HRESULT ClearWindow(WColor color);

	ID2D1Factory*			GetFactory(void) const;
	ID2D1HwndRenderTarget*	GetRenderTarget(void) const;
	ID2D1SolidColorBrush*	GetColorBrush(void) const;
	RECT					GetClientArea(void) const;
	IDWriteFactory*			GetWriteFactory(void) const;
	IDWriteTextFormat*		GetTextFormat(void) const;
	wchar_t*				GetText(void) const;
	UINT32					GetTextLength(void) const;

	wchar_t*				FontFamily(void) const;
	wchar_t*				FontFamily(wchar_t* familyName);

	float					FontSize(void) const;
	float					FontSize(float intake);

private:
	ID2D1Factory*			m_DX_FAC;
	ID2D1HwndRenderTarget*	m_DX_HRT;
	ID2D1SolidColorBrush*	m_DX_SCB;
	RECT					m_DX_REC;
	IDWriteFactory*			m_DW_FAC;
	IDWriteTextFormat*		m_DW_TXF;
	wchar_t*				m_C_TEXT;
	UINT32					m_TEXTLN;
	wchar_t*				m_FontFamilyName;
	float					m_FontSize = 14.0F;

	BOOL m_bIsFacCreated = 0;
	BOOL m_bIsHRTCreated = 0;
	BOOL m_bIsSCBCreated = 0;
	BOOL m_bIsDWFCreated = 0;
	BOOL m_bIsDWTXreated = 0;

	BOOL m_bIsDrawing = 0;

};

namespace W_MAIN_WINDOW
{
	void ResizeWindow(int X, int Y);
	void RepositionWindow(int X, int Y);
	void DragMoveWindow(int yOffset = 25);
}

#endif // !_W_GRAPHICS_H_