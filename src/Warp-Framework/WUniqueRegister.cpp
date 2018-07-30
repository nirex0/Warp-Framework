// © 2018 NIREX ALL RIGHTS RESERVED

#include "WUniqueRegister.h"

WUniqueRegister::~WUniqueRegister(void)
{
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

WUniqueRegister* WUniqueRegister::Register(Annex intake)
{
	m_Register = &intake;
	return this;
}

WUniqueRegister* WUniqueRegister::Unregister(void)
{
	m_Register = nullptr;
	return this;
}