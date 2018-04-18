//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GFX_CONTAINER_H_
#define _W_GFX_CONTAINER_H_

#include "WGraphics.h"

class WGraphicsContainer
{
public:
	static WGraphics* Graphics(void) { return WGraphicsContainer::gfx; }
	static WGraphics* Graphics(WGraphics* intake) { WGraphicsContainer::gfx = intake; return WGraphicsContainer::gfx; }

private:
	static WGraphics* WGraphicsContainer::gfx;
};


#endif // !_W_GFX_CONTAINER_H_