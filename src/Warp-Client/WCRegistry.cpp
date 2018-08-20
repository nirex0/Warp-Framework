// © 2018 NIREX ALL RIGHTS RESERVED

#include "WCRegistry.h"

WCRegistry::WCRegistry()
	: m_count(0)
{
}

WCRegistry::WCRegistry(const WCRegistry& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{
		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WCRegistry::WCRegistry(WCRegistry&& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{
		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WCRegistry::~WCRegistry() {}

long WCRegistry::GetCount(void) const
{
	return m_count;
}

WCRegistry* WCRegistry::operator()(WCEntity* sender, WCEventArgs* args)
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

WCRegistry* WCRegistry::Run(WCEntity* sender, WCEventArgs* args)
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

WCRegistry* WCRegistry::Register(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WCRegistry* WCRegistry::UnRegister(Annex* rhs)
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] == rhs)
		{
			m_registered[i] = nullptr;
			_InterlockedDecrement(&m_count);
		}
	}
	return this;
}

WCRegistry* WCRegistry::operator+=(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WCRegistry* WCRegistry::operator-=(Annex rhs)
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

std::vector<Annex*> WCRegistry::Container(void) const
{
	return m_registered;
}
