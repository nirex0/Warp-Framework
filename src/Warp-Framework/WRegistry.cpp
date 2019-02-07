// © 2019 NIREX ALL RIGHTS RESERVED

#include "WRegistry.h"

WRegistry::WRegistry(void)
	: m_count(0)
{
}

WRegistry::WRegistry(const WRegistry& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{
		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WRegistry::WRegistry(WRegistry&& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{
		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WRegistry::~WRegistry(void) {}

long WRegistry::GetCount(void) const
{
	return m_count;
}

WRegistry* WRegistry::operator()(WEntity* sender, WEventArgs* args)
{
	Annex current;
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] != nullptr)
		{
			current = *m_registered[i];
			current(sender, args);
		}
	}
	return this;
}

WRegistry* WRegistry::Run(WEntity* sender, WEventArgs* args)
{
	Annex current;
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] != nullptr)
		{
			current = *m_registered[i];
			current(sender, args);
		}
	}
	return this;
}

WRegistry* WRegistry::Register(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WRegistry* WRegistry::UnRegister(Annex rhs)
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] == &rhs)
		{
			m_registered[i] = nullptr;
			_InterlockedDecrement(&m_count);
		}
	}
	return this;
}

WRegistry* WRegistry::operator+=(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WRegistry* WRegistry::operator-=(Annex rhs)
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] == &rhs)
		{
			m_registered[i] = nullptr;
			_InterlockedDecrement(&m_count);
		}
	}
	return this;
}

std::vector<Annex*> WRegistry::Container(void) const
{
	return m_registered;
}
