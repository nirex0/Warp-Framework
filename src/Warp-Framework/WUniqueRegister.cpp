// © 2018 NIREX ALL RIGHTS RESERVED

#include "WUniqueRegister.h"

WUniqueRegister::~WUniqueRegister()
{
	m_Register.release();
}

WUniqueRegister* WUniqueRegister::operator()(WEntity* sender, WEventArgs* args)
{
	if (m_Register != nullptr)
	{
		(*m_Register)(sender, args);
	}
	return this;
}
WUniqueRegister* WUniqueRegister::Run(WEntity* sender, WEventArgs* args)
{
	if (m_Register != nullptr)
	{
		(*m_Register)(sender, args);
	}
	return this;
}

WUniqueRegister* WUniqueRegister::Register(const Annex & intake)
{
	m_Register = std::make_unique<Annex>(*(new Annex(intake)));
	return this;
}

WUniqueRegister* WUniqueRegister::Unregister(void)
{
	m_Register.release();
	return this;
}