// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSRegistry.h"

WSRegistry::WSRegistry()
	: m_count(0)
{
}

WSRegistry::WSRegistry(const WSRegistry& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		delete m_registered[i];
	}
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{
		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WSRegistry::WSRegistry(WSRegistry&& nRegistery)
	: m_count(0)
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		delete m_registered[i];
	}
	for (size_t i = 0; i < nRegistery.m_registered.size(); i++)
	{

		this->Register(*nRegistery.m_registered[i]);
		_InterlockedIncrement(&m_count);
	}
}

WSRegistry::~WSRegistry()
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		delete m_registered[i];
	}
}

long WSRegistry::GetCount(void) const
{
	return m_count;
}

WSRegistry* WSRegistry::operator()(WSEntity* sender, WSEventArgs* args)
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

WSRegistry* WSRegistry::Run(WSEntity* sender, WSEventArgs* args)
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

WSRegistry* WSRegistry::Register(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WSRegistry* WSRegistry::UnRegister(Annex* rhs)
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

WSRegistry* WSRegistry::operator+=(Annex rhs)
{
	m_registered.push_back(new Annex(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WSRegistry* WSRegistry::operator-=(Annex rhs)
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
