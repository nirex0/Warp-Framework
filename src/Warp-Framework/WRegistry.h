//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_REGISTRY_H_
#define _W_REGISTRY_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void __stdcall (WEntity* sender, WEventArgs* args)> Annex;

class WRegistry final : public WEntity
{
public:
	// Ctor
	WRegistry();
	// CCtor
	WRegistry(const WRegistry& nRegistery);
	// MCtor
	WRegistry(WRegistry&& nRegistery);
	// Dtor
	~WRegistry();

	// Get the count of all the registered functions
	long GetCount(void) const;

	// Run all the registered Annexes
	WRegistry* operator()(WEntity* sender, WEventArgs* args);
	WRegistry* Run(WEntity* sender, WEventArgs* args);

	// Regiser / Unregister an Annex
	WRegistry* Register(Annex* rhs);
	WRegistry* UnRegister(Annex* rhs);

	// Regiser / Unregister an Annex
	WRegistry* operator+=(Annex* rhs);
	WRegistry* operator-=(Annex* rhs);

private:
	volatile long m_count;
	std::vector<Annex*> m_registered;
};

#endif // _W_REGISTRY_H_
