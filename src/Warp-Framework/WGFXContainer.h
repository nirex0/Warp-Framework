// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GFX_CONTAINER_H_
#define _W_GFX_CONTAINER_H_

#include "WGraphics.h"

//-->DOC_CLASS
// A Container class that allows access to a set of global static graphics related variables throughout the framework
class WGraphicsContainer final
{
public:
	static WGraphics* Graphics(void);
	static WGraphics* Graphics(WGraphics* intake);

	static D2D1_RENDER_TARGET_TYPE RenderMethod(void);
	static D2D1_RENDER_TARGET_TYPE RenderMethod(D2D1_RENDER_TARGET_TYPE intake);

private:
	//-->DOC_MEMBER
	//Pointer to the main WGraphics object
	static WGraphics* gfx;

	//-->DOC_MEMBER
	//Pointer to the main Direct2D Render Target type
	//This can be Hardware (GPU) or Software (CPU)
	static D2D1_RENDER_TARGET_TYPE main_rttype;
};


#endif // !_W_GFX_CONTAINER_H_
