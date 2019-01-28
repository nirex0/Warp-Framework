// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_DX_CONTAINER_H_
#define _W_DX_CONTAINER_H_

#include "WDX.h"

#ifdef _WDX_

//-->DOC_CLASS
// A Container class that allows access to a set of global static DirectX and DirectWrite variables throughout the framework
class WDXContainer final
{
public:
	static void Factory(ID2D1Factory* factory);
	static const ID2D1Factory* Factory(void);

	static void RenderTarget(ID2D1HwndRenderTarget* rt);
	static const ID2D1HwndRenderTarget* RenderTarget(void);

	static void ClientArea(RECT rect);
	static const RECT ClientArea(void);

	static void WriteFactory(IDWriteFactory* factory);
	static const IDWriteFactory* WriteFactory(void);

	static void TextFormat(IDWriteTextFormat* tf);
	static const IDWriteTextFormat* TextFormat(void);

private:
	//-->DOC_MEMBER
	//Pointer to the main Direct2D Factory
	static ID2D1Factory* DX_Factory;

	//-->DOC_MEMBER
	//Pointer to the main Direct2D Render Target
	static ID2D1HwndRenderTarget* DX_RT;

	//-->DOC_MEMBER
	//Window Rect
	static RECT DX_cRect;

	//-->DOC_MEMBER
	//Pointer to the main DirectWrite Factory
	static IDWriteFactory* DX_WFactory;

	//-->DOC_MEMBER
	//Pointer to the main DirectWrite TextFormat
	static IDWriteTextFormat* DX_TextFormat;
};

#endif // _WDX_
#endif // !_W_DX_CONTAINER_H_
