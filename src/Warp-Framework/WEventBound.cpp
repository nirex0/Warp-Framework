// © 2019 NIREX ALL RIGHTS RESERVED

#include "WEventBound.h"
#include "WContainer.h"

WEventBound::WEventBound(void)
{
}

WEventBound::~WEventBound(void)
{
}

bool WEventBound::Binding(void) const
{
	return m_binding;
}

bool WEventBound::Binding(bool intake)
{
	m_binding = intake;
	return m_binding;
}

Annex* WEventBound::Function(void) const
{
	return m_annex;
}

Annex* WEventBound::Function(Annex intake)
{
	m_annex = &intake;
	return m_annex;
}

void WEventBound::operator=(Annex rhs)
{
	m_annex = &rhs;
}

void WEventBound::operator()(WEntity* sender, WEventArgs* args)
{
	Annex current;
	if (m_annex)
	{
		current = *m_annex;
		current(sender, args);
		m_binding = WContainer::hResult() == S_OK;
	}
}

void WEventBound::Run(WEntity* sender, WEventArgs* args)
{
	Annex current;
	if (m_annex)
	{
		current = *m_annex;
		current(sender, args);
		m_binding = WContainer::hResult() == S_OK;
	}
}
