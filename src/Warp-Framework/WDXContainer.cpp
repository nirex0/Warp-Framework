// © 2018 NIREX ALL RIGHTS RESERVED

#include "WDXContainer.h"

void WDXContainer::Factory(ID2D1Factory* factory)
{
	WDXContainer::DX_Factory = factory;
}

const ID2D1Factory* WDXContainer::Factory(void)
{
	return WDXContainer::DX_Factory;
}

void WDXContainer::RenderTarget(ID2D1HwndRenderTarget* rt)
{
	WDXContainer::DX_RT = rt;
}

const ID2D1HwndRenderTarget* WDXContainer::RenderTarget(void)
{
	return WDXContainer::DX_RT;
}

void WDXContainer::ClientArea(RECT rect)
{
	WDXContainer::DX_cRect = rect;
}

const RECT WDXContainer::ClientArea(void)
{
	return WDXContainer::DX_cRect;
}

void WDXContainer::WriteFactory(IDWriteFactory* factory)
{
	WDXContainer::DX_WFactory = factory;
}

const IDWriteFactory* WDXContainer::WriteFactory(void)
{
	return WDXContainer::DX_WFactory;
}

void WDXContainer::TextFormat(IDWriteTextFormat* tf)
{
	WDXContainer::DX_TextFormat = tf;
}

const IDWriteTextFormat* WDXContainer::TextFormat(void)
{
	return WDXContainer::DX_TextFormat;
}
