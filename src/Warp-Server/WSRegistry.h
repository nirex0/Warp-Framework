// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_REGISTRY_H_
#define _WS_REGISTRY_H_

#include "WSEntity.h"
#include "WSEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(WSEntity* sender, WSEventArgs* args)> Annex;

class WSRegistry final : public WSEntity
{
public:
	WSRegistry();
	WSRegistry(const WSRegistry& nRegistery);
	WSRegistry(WSRegistry&& nRegistery);
	~WSRegistry();

	long GetCount(void) const;

	WSRegistry* operator()(WSEntity* sender, WSEventArgs* args);
	WSRegistry* Run(WSEntity* sender, WSEventArgs* args);
	WSRegistry* Register(Annex rhs);
	WSRegistry* UnRegister(Annex* rhs);
	WSRegistry* operator+=(Annex rhs);
	WSRegistry* operator-=(Annex rhs);

private:
	volatile long m_count;
	std::vector<Annex*> m_registered;
};

#endif // !_WS_REGISTRY_H_