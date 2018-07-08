// © 2018 NIREX ALL RIGHTS RESERVED

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
	WRegistry();
	WRegistry(const WRegistry& nRegistery);
	WRegistry(WRegistry&& nRegistery);
	~WRegistry();
	
	long GetCount(void) const;

	WRegistry* operator()(WEntity* sender, WEventArgs* args);
	WRegistry* Run(WEntity* sender, WEventArgs* args);
	WRegistry* Register(Annex rhs);
	WRegistry* UnRegister(Annex* rhs);
	WRegistry* operator+=(Annex rhs);
	WRegistry* operator-=(Annex rhs);

private:
	volatile long m_count;
	std::vector<Annex*> m_registered;
};

#endif // !_W_REGISTRY_H_
