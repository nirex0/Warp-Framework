// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_TEST_REGISTRY_H_
#define _W_TEST_REGISTRY_H_

#include <vector>
#include <functional>
#include <cassert>

#define WAssertion assert 

typedef std::function<bool(void)> WTest;

class WTestRegistry
{
public:
	WTestRegistry();
	WTestRegistry(const WTestRegistry& nRegistery);
	WTestRegistry(WTestRegistry&& nRegistery);
	~WTestRegistry();

	long GetCount(void) const;

	WTestRegistry* operator()();
	WTestRegistry* TestEqual();
	WTestRegistry* TestNotEqual();
	WTestRegistry* Register(WTest rhs);
	WTestRegistry* UnRegister(WTest* rhs);
	WTestRegistry* operator+=(WTest rhs);
	WTestRegistry* operator-=(WTest rhs);

private:
	volatile long m_count;
	std::vector<WTest*> m_registered;
};

#endif // !_W_TEST_REGISTRY_H_
