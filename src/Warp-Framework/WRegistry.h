// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_REGISTRY_H_
#define _W_REGISTRY_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(WEntity* sender, WEventArgs* args)> Annex;

//-->DOC_CLASS
// A class for event registry and handling
class WRegistry final : public WEntity
{
public:
	WRegistry(void);
	WRegistry(const WRegistry& nRegistery);
	WRegistry(WRegistry&& nRegistery);
	~WRegistry(void);
	
	long GetCount(void) const;

	//-->DOC_FUNC
	// Raise event functor
	WRegistry* operator()(WEntity* sender, WEventArgs* args);

	//-->DOC_FUNC
	// Raise event method
	WRegistry* Run(WEntity* sender, WEventArgs* args);

	//-->DOC_FUNC
	// Register method
	WRegistry* Register(Annex rhs);

	//-->DOC_FUNC
	// Unegister method
	WRegistry* UnRegister(Annex rhs);

	//-->DOC_FUNC
	// Register operator
	WRegistry* operator+=(Annex rhs);

	//-->DOC_FUNC
	// Ungister operator
	WRegistry* operator-=(Annex rhs);

	std::vector<Annex*> Container(void) const;

private:
	//-->DOC_MEMBER
	// Number of registered annexes
	volatile long m_count;

	//-->DOC_MEMBER
	// Vector of registered annexes
	std::vector<Annex*> m_registered;
};

#endif // !_W_REGISTRY_H_
