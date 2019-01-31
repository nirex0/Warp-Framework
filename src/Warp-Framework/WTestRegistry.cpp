// © 2019 NIREX ALL RIGHTS RESERVED

#include "WTestRegistry.h"

WTestRegistry::WTestRegistry()
	: m_count(0)
{
}

WTestRegistry::WTestRegistry(const WTestRegistry& nRegistery)
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

WTestRegistry::WTestRegistry(WTestRegistry&& nRegistery)
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

WTestRegistry::~WTestRegistry()
{
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		delete m_registered[i];
	}
}

long WTestRegistry::GetCount(void) const
{
	return m_count;
}

WTestRegistry* WTestRegistry::operator()()
{
	WTest current;
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] != nullptr)
		{
			current = *m_registered[i];
			WAssertion(current() == true);
		}
	}
	return this;
}

WTestRegistry* WTestRegistry::TestEqual()
{
	WTest current;
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] != nullptr)
		{
			current = *m_registered[i];
			WAssertion(current() == true);
		}
	}
	return this;
}

WTestRegistry* WTestRegistry::TestNotEqual()
{
	WTest current;
	for (size_t i = 0; i < m_registered.size(); i++)
	{
		if (m_registered[i] != nullptr)
		{
			current = *m_registered[i];
			WAssertion(current() != true);
		}
	}
	return this;
}

WTestRegistry* WTestRegistry::Register(WTest rhs)
{
	m_registered.push_back(new WTest(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WTestRegistry* WTestRegistry::UnRegister(WTest* rhs)
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

WTestRegistry* WTestRegistry::operator+=(WTest rhs)
{
	m_registered.push_back(new WTest(rhs));
	_InterlockedIncrement(&m_count);
	return this;
}

WTestRegistry* WTestRegistry::operator-=(WTest rhs)
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
