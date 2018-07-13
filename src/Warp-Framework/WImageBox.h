// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_IMAGE_BOX_H_
#define _W_IMAGE_BOX_H_

#include "WControl.h"
#include "WLerp.h"

class WImageBox : public WControl
{
public:
	WImageBox(wchar_t* URL, W_INT zIndex = 0);
	WImageBox(wchar_t* URL, W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WImageBox(wchar_t* URL, WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WImageBox(wchar_t* URL, WRectF location, W_INT zIndex = 0);
	~WImageBox(void);

	void Render(void) override;

	wchar_t* URL(void) const;
	wchar_t* URL(wchar_t* intake);

	W_FLOAT Opacity(void) const;
	W_FLOAT Opacity(W_FLOAT intake);

private:
	W_FLOAT opacity;
	W_IMAGE* img;
	wchar_t* m_URL;
};

#endif // !_W_IMAGE_BOX_H_
