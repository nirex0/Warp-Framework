// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_FIXEDCANVAS_H_
#define _W_FIXEDCANVAS_H_

#include "WControl.h"

class WFixedCanvas : public WControl
{
public:
	WFixedCanvas(W_INT zIndex = 0);
	~WFixedCanvas(void);

	void Render(void) override;
};

#endif // !_W_FIXEDCANVAS_H_
