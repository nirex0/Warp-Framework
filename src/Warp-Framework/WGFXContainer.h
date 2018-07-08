// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GFX_CONTAINER_H_
#define _W_GFX_CONTAINER_H_

#include "WGraphics.h"

class WGraphicsContainer
{
public:
	static WGraphics* Graphics(void);
	static WGraphics* Graphics(WGraphics* intake);

	static D2D1_RENDER_TARGET_TYPE RenderMethod(void);
	static D2D1_RENDER_TARGET_TYPE RenderMethod(D2D1_RENDER_TARGET_TYPE intake);

private:
	static WGraphics* WGraphicsContainer::gfx;
	static WGraphicsContainer::D2D1_RENDER_TARGET_TYPE main_rttype;
};


#endif // !_W_GFX_CONTAINER_H_
