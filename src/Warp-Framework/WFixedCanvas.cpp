// © 2019 NIREX ALL RIGHTS RESERVED

#include "WFixedCanvas.h"
#include "WControlHandler.h"
#include "WSafeRelease.h"

WFixedCanvas::WFixedCanvas(const W_INT& zIndex)
	: WControl(zIndex)
{
	this->m_top = 0;
	this->m_bottom = WContainer::Height();

	this->m_left = 0;
	this->m_right = WContainer::Width();
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