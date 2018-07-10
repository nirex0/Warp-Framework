// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_EVENT_BOUND_H_
#define _W_EVENT_BOUND_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void __stdcall (WEntity* sender, WEventArgs* args)> Annex;

class WEventBound : public WEntity
{
public:
	WEventBound();
	~WEventBound();

	bool Binding(void) const;
	bool Binding(bool intake);

	Annex* Function(void) const;
	Annex* Function(Annex intake);

	void operator=(Annex rhs);
	void operator()(WEntity* sender, WEventArgs* args);

	void Run(WEntity* sender, WEventArgs* args);

private:
	bool m_binding;
	Annex* m_annex;
};

#endif // !_W_EVENT_BOUND_H_