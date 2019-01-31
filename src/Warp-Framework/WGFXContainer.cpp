// © 2019 NIREX ALL RIGHTS RESERVED

#include "WGFXContainer.h"

WGraphics* WGraphicsContainer::Graphics(void)
{
	return WGraphicsContainer::gfx;
}

WGraphics* WGraphicsContainer::Graphics(WGraphics* intake)
{
	WGraphicsContainer::gfx = intake;
	return WGraphicsContainer::gfx;
}

D2D1_RENDER_TARGET_TYPE WGraphicsContainer::RenderMethod(void)
{
	return WGraphicsContainer::main_rttype;
}

D2D1_RENDER_TARGET_TYPE WGraphicsContainer::RenderMethod(D2D1_RENDER_TARGET_TYPE intake)
{
	WGraphicsContainer::main_rttype = intake; 
	return WGraphicsContainer::main_rttype;
}