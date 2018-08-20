// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WC_REGISTRY_H_
#define _WC_REGISTRY_H_

#include "WCEntity.h"
#include "WCEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(WCEntity* sender, WCEventArgs* args)> Annex;

class WCRegistry final : public WCEntity
{
public:
	WCRegistry();
	WCRegistry(const WCRegistry& nRegistery);
	WCRegistry(WCRegistry&& nRegistery);
	~WCRegistry();

	long GetCount(void) const;

	WCRegistry* operator()(WCEntity* sender, WCEventArgs* args);
	WCRegistry* Run(WCEntity* sender, WCEventArgs* args);
	WCRegistry* Register(Annex rhs);
	WCRegistry* UnRegister(Annex* rhs);
	WCRegistry* operator+=(Annex rhs);
	WCRegistry* operator-=(Annex rhs);

	std::vector<Annex*> Container(void) const;

private:
	volatile long m_count;
	std::vector<Annex*> m_registered;
};

#endif // !_WC_REGISTRY_H_