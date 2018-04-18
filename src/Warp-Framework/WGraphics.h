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

	HRESULT UpdateClientRect(void);
	HRESULT UpdateClientRect(HWND hWnd);

	HRESULT GetBrushColor(WColor& outColor);
	HRESULT SetBrushColor(const WColor& color);

	HRESULT SafeBeginDraw(void);
	HRESULT SafeEndDraw(void);
	HRESULT SafeFlush(void);

	HRESULT SaveResources(void);
	HRESULT ClearWindow(WColor color);

	ID2D1Factory*			GetFactory(void) const;
	ID2D1HwndRenderTarget*	GetRenderTarget(void) const;
	ID2D1SolidColorBrush*	GetColorBrush(void) const;
	RECT					GetClientArea(void) const;

private:
	ID2D1Factory*			m_DX_FAC;
	ID2D1HwndRenderTarget*	m_DX_HRT;
	ID2D1SolidColorBrush*	m_DX_SCB;
	RECT					m_DX_REC;

	BOOL m_bIsFacCreated = 0;
	BOOL m_bIsHRTCreated = 0;
	BOOL m_bIsSCBCreated = 0;

	BOOL m_bIsDrawing = 0;

};

#endif // !_W_GRAPHICS_H_