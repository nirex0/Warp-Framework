// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LOGICAL_BOUND_H_
#define _W_LOGICAL_BOUND_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(bool&)> WBinding;

class WLogicalBound : public WEntity
{
public:
	WLogicalBound();
	~WLogicalBound();

	bool Binding(void) const;
	bool Binding(bool intake);

	WBinding* Function(void) const;
	WBinding* Function(WBinding intake);
	
	void operator=(WBinding rhs);
	void operator()(void);

	void Run(void);

private:
	bool m_binding;
	WBinding* m_annex;
};


#endif // !_W_LOGICAL_BOUND_H_