//© 2018 NIREX ALL RIGHTS RESERVED

#include "WFixedCanvas.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WFixedCanvas::WFixedCanvas(W_INT zIndex)
	: WControl(zIndex)
{
}

WFixedCanvas::~WFixedCanvas()
{
}

void WFixedCanvas::Render(void)
{
	if (!m_isVisible)
		return;

	if (m_Parent)
	{
		if (!m_Parent->IsEnabled())
			return;
		if (!m_Parent->IsVisible())
			return;
	}
}