// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_DX_CONTAINER_H_
#define _W_DX_CONTAINER_H_

#include "WDX.h"

#ifdef _WDX_
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
	static ID2D1Factory* DX_Factory;
	static ID2D1HwndRenderTarget* DX_RT;
	static RECT DX_cRect;
	static IDWriteFactory* DX_WFactory;
	static IDWriteTextFormat* DX_TextFormat;
};

#endif // _WDX_
#endif // !_W_DX_CONTAINER_H_
