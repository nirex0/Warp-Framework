//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_UNIQUE_REGISTER_H_
#define _W_UNIQUE_REGISTER_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <memory>
#include <functional>

typedef std::function<void __stdcall (WEntity* sender, WEventArgs* args)> Annex;


class WUniqueRegister final : public WEntity
{
public:	
	~WUniqueRegister()
	{
		m_Register.release();
	}

	WUniqueRegister* Register(const Annex& intake)
	{
		m_Register = std::make_unique<Annex>(*(new Annex));
		return this;
	}

	WUniqueRegister* Unregister(void)
	{
		m_Register.release();
		return this;
	}

	WUniqueRegister* operator()(WEntity* sender, WEventArgs* args)
	{
		(*m_Register)(sender, args);
		return this;
	}

	WUniqueRegister* Run(WEntity* sender, WEventArgs* args)
	{
		(*m_Register)(sender, args);
		return this;
	}

private:
	std::unique_ptr<Annex> m_Register;
};

#endif // _W_UNIQUE_REGISTER_H_