//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GFX_CONTAINER_H_
#define _W_GFX_CONTAINER_H_

#include "WGraphics.h"

class WGraphicsContainer
{
public:
	static WGraphics* Graphics(void) { return WGraphicsContainer::gfx; }
	static WGraphics* Graphics(WGraphics* intake) { WGraphicsContainer::gfx = intake; return WGraphicsContainer::gfx; }

	static D2D1_RENDER_TARGET_TYPE RenderMethod(void) { return WGraphicsContainer::main_rttype; }
	static D2D1_RENDER_TARGET_TYPE RenderMethod(D2D1_RENDER_TARGET_TYPE intake) { WGraphicsContainer::main_rttype = intake; return WGraphicsContainer::main_rttype; }

private:
	static WGraphics* WGraphicsContainer::gfx;
	static WGraphicsContainer::D2D1_RENDER_TARGET_TYPE main_rttype;
};


#endif // !_W_GFX_CONTAINER_H_