// © 2019 NIREX ALL RIGHTS RESERVED

#include "WLogicalBound.h"

WLogicalBound::WLogicalBound()
{
}

WLogicalBound::~WLogicalBound()
{
}

bool WLogicalBound::Binding(void) const
{
	return m_binding;
}

bool WLogicalBound::Binding(bool intake)
{
	m_binding = intake;
	return m_binding;
}

WBinding* WLogicalBound::Function(void) const
{
	return m_annex;
}

WBinding* WLogicalBound::Function(WBinding intake)
{
	m_annex = &intake;
	return m_annex;
}

void WLogicalBound::operator=(WBinding rhs)
{
	m_annex = &rhs;
}

void WLogicalBound::operator()(void)
{
	WBinding current;
	if (m_annex)
	{
		current = *m_annex;
		current(m_binding);
	}
}

void WLogicalBound::Run(void)
{
	WBinding current;
	if (m_annex)
	{
		current = *m_annex;
		current(m_binding);
	}
}
