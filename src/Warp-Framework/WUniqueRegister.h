// © 2018 NIREX ALL RIGHTS RESERVED

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
	~WUniqueRegister();
	WUniqueRegister* operator()(WEntity* sender, WEventArgs* args);
	WUniqueRegister* Run(WEntity* sender, WEventArgs* args);
	WUniqueRegister* Register(const Annex& intake);
	WUniqueRegister* Unregister(void);

private:
	std::unique_ptr<Annex> m_Register;
};

#endif // !_W_UNIQUE_REGISTER_H_
