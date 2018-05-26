//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_REGISTRY_H_
#define _W_REGISTRY_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(WEntity* sender, WEventArgs* args)> Annex;

class WRegistry final : public WEntity
{
public:
	WRegistry() 
		: m_count(0)
	{
	}
	
	WRegistry(const WRegistry& nRegistery)
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
	
	WRegistry(WRegistry&& nRegistery)
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
	
	~WRegistry()
	{
		for (size_t i = 0; i < m_registered.size(); i++)
		{
			delete m_registered[i];
		}
	}
	
	long GetCount(void) const
	{
		return m_count;
	}

	WRegistry* operator()(WEntity* sender, WEventArgs* args)
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

	WRegistry* Run(WEntity* sender, WEventArgs* args)
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

	WRegistry* Register(Annex rhs)
	{
		m_registered.push_back(new Annex(rhs));
		_InterlockedIncrement(&m_count);
		return this;
	}

	WRegistry* UnRegister(Annex* rhs)
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

	WRegistry* operator+=(Annex rhs)
	{
		m_registered.push_back(new Annex(rhs));
		_InterlockedIncrement(&m_count);
		return this;
	}

	WRegistry* operator-=(Annex rhs)
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

private:
	volatile long m_count;
	std::vector<Annex*> m_registered;
};

#endif // !_W_REGISTRY_H_
