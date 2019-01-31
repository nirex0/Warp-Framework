// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_GRAPHICS_H_
#define _W_GRAPHICS_H_

#include "WDX.h"
#include "WEntity.h"
#include "WDefines.h"
#include "WRect.h"
#include "WTextAlignment.h"
#include "WGradientDirection.h"

class WGraphics : public WEntity
{
public:
	WGraphics(void);
	~WGraphics(void);

	HRESULT CreateDeviceResources(void);
	HRESULT UpdateDeviceResources(void);

	HRESULT CreateFactory(void);
	HRESULT UpdateFactory(void);

	HRESULT CreateRenderTarget(void);
	HRESULT UpdateRenderTarget(void);
	HRESULT ResizeRenderTarget(W_UINT width, W_UINT height);

	HRESULT CreateSolidColorBrush(const W_COLOR& color);
	HRESULT UpdateSolidColorBrush(const W_COLOR& color);

	HRESULT CreateLinearColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& pos0, const POINTF& pos1);
	HRESULT UpdateLinearColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& pos0, const POINTF& pos1);

	HRESULT CreateRadialColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& center, const POINTF& offset, FLOAT radX, FLOAT radY);
	HRESULT UpdateRadialColorBrush(const W_COLOR& color0, const W_COLOR& color1, const POINTF& center, const POINTF& offset, FLOAT radX, FLOAT radY);

	HRESULT CreateWriteFactory(void);
	HRESULT UpdateWriteFactory(void);

	HRESULT CreateFormat(void);
	HRESULT UpdateFormat(void);

	HRESULT UpdateClientRect(void);
	HRESULT UpdateClientRect(HWND hWnd);

	HRESULT GetBrushColor(W_COLOR& outColor);
	HRESULT SetBrushColor(const W_COLOR& color);

	HRESULT GetText(wchar_t* OutText, UINT32& OutLength) const;
	HRESULT SetText(wchar_t* Intake, UINT32 Length);

	HRESULT SafeBeginDraw(void);
	HRESULT SafeEndDraw(void);
	HRESULT SafeFlush(void);

	HRESULT SaveResources(void);
	HRESULT ClearWindow(W_COLOR color);

	ID2D1Factory* GetFactory(void) const;
	ID2D1HwndRenderTarget* GetRenderTarget(void) const;
	
	ID2D1SolidColorBrush* GetSolidColorBrush(void) const;
	ID2D1LinearGradientBrush* GetLinearColorBrush(void) const;
	ID2D1RadialGradientBrush* GetRadialColorBrush(void) const;

	RECT GetClientArea(void) const;
	IDWriteFactory* GetWriteFactory(void) const;
	IDWriteTextFormat* GetTextFormat(void) const;
	wchar_t* GetText(void) const;
	UINT32 GetTextLength(void) const;

	wchar_t* FontFamily(void) const;
	wchar_t* FontFamily(wchar_t* familyName);

	FLOAT FontSize(void) const;
	FLOAT FontSize(FLOAT intake);

// Primitive Drawing
	HRESULT DrawRect(WRectF boundaryRect, FLOAT bord_thickness, W_COLOR bord_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRectSolid(WRectF boundaryRect, W_COLOR back_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRectLinear(WRectF boundaryRect, W_COLOR back_color0, W_COLOR back_color1, WLinearGradientDirection direction, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRectRadial(WRectF boundaryRect, W_COLOR back_color0, W_COLOR back_color1, POINTF offset, FLOAT radX, FLOAT radY, WLRadialGradientDirection direction, WRectF Mask = {0, 0, 0, 0});

	HRESULT DrawRoundRect(WRectF boundaryRect, FLOAT bord_thickness, FLOAT bord_radius, W_COLOR bord_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRoundRectSolid(WRectF boundaryRect, FLOAT bord_radius, W_COLOR back_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRoundRectLinear(WRectF boundaryRect, FLOAT bord_radius, W_COLOR back_color0, W_COLOR back_color1, WLinearGradientDirection direction, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillRoundRectRadial(WRectF boundaryRect, FLOAT bord_radius, W_COLOR back_color0, W_COLOR back_color1, POINTF offset, FLOAT radX, FLOAT radY, WLRadialGradientDirection direction, WRectF Mask = {0, 0, 0, 0});

	HRESULT DrawEllipse(POINTF center, FLOAT radX, FLOAT radY, FLOAT bord_thickness, W_COLOR bord_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillEllipseSolid(POINTF center, FLOAT radX, FLOAT radY, W_COLOR back_color, WRectF Mask = {0, 0, 0, 0});
	HRESULT FillEllipseRadial(POINTF center, FLOAT radX, FLOAT radY, W_COLOR back_color, W_COLOR back_color0, W_COLOR back_color1, WRectF Mask = {0, 0, 0, 0});

	HRESULT DrawLine(POINTF begin, POINTF end, W_COLOR color, FLOAT thickness, WRectF Mask = {0, 0, 0, 0});
	HRESULT DrawPoint(POINTF Coords, W_COLOR color, WRectF Mask = {0, 0, 0, 0});
	
	HRESULT LoadIMG(LPCWSTR uri, W_IMAGE** ppImage);
	HRESULT DrawIMG(W_IMAGE* pImage, WRectF boundaryRect, FLOAT opacity, WRectF Mask = {0, 0, 0, 0});
	
	HRESULT WriteText(WRectF boundaryRect, WCHAR* text, UINT32 strLengh, WCHAR* fontfamily, FLOAT fontsize, W_COLOR text_color, WTextAlignment alignment = WTA_Center, WRectF Mask = {0, 0, 0, 0});
	
// Primitive Component Drawing
	HRESULT DrawRect(WRectF boundaryRect, WRectF borderThickness, W_COLOR bord_color);

// Helper Functions
	W_COLOR FromRGBA(INT R, INT G, INT B, FLOAT A = 1.0F) const;

// Window Helper Functions
	HRESULT SetTransparency(UINT alpha = 100);

private:
// Direct2D Factory and Render Target
	ID2D1Factory* m_pD2D1Factory;
	ID2D1HwndRenderTarget* m_pD2D1RenderTarget;

// Brush Resources
	ID2D1SolidColorBrush* m_pSolidColorBrush;
	ID2D1LinearGradientBrush* m_pLinearGradientBrush;
	ID2D1RadialGradientBrush* m_pRadialGradientBrush;

// Screen Rect
	RECT m_ScreenRect;
	
// DirectWrite Factory and Text Format
	IDWriteFactory* m_pIDWriteFactory;
	IDWriteTextFormat* m_pIDWriteTextFormat;
	
// DirectWrite Components
	wchar_t* m_C_TEXT;
	UINT32 m_TEXTLN;
	wchar_t* m_FontFamilyName;
	FLOAT m_FontSize = 14.0F;

	BOOL m_bIsFactoryCreated = 0;
	BOOL m_bIsRenderTargetCreated = 0;
	
	BOOL m_bIsSolidColorBrushCreated = 0;
	BOOL m_bIsLinearGradientBrushCreated = 0;
	BOOL m_bIsRadialGradientBrushCreated = 0;
	
	BOOL m_bIsDWriteFactoryCreated = 0;
	BOOL m_bIsDWiteTextFormatCreated = 0;

	BOOL m_bIsDrawing = 0;
};

namespace W_MAIN_WINDOW
{
	void ResizeWindow(W_INT X, W_INT Y);
	void RepositionWindow(W_INT X, W_INT Y);
	void DragMoveWindow(W_INT yOffset = 25);
}

#endif // !_W_GRAPHICS_H_
