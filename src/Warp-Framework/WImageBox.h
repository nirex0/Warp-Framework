// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_IMAGE_BOX_H_
#define _W_IMAGE_BOX_H_

#include "WControl.h"
#include "WLerp.h"

class WImageBox : public WControl
{
public:
	WImageBox(const std::wstring& URL, const W_INT& zIndex = 0);
	WImageBox(const std::wstring& URL, const W_FLOAT& top, const W_FLOAT& left, const W_FLOAT& bottom, const W_FLOAT& right, const W_INT& zIndex = 0);
	WImageBox(const std::wstring& URL, const WPointF& topleft, const WPointF& botright, const W_INT& zIndex = 0);
	WImageBox(const std::wstring& URL, const WRectF& location, const W_INT& zIndex = 0);
	~WImageBox(void);

	void Render(void) override;

	std::wstring URL(void) const;
	std::wstring URL(const std::wstring& intake);

	W_FLOAT Opacity(void) const;
	W_FLOAT Opacity(const W_FLOAT& intake);

private:
	W_FLOAT opacity;
	W_IMAGE* img;
	std::wstring m_URL;
};

#endif // !_W_IMAGE_BOX_H_
