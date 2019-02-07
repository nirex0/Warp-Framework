// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LOGICAL_BOUND_H_
#define _W_LOGICAL_BOUND_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void(bool&)> WBinding;

//-->DOC_CLASS
// Binds a WBinding to a Bool, if the WBinding is successfully completed, the bool will be set to true, it'll be set to false otherwise
class WLogicalBound : public WEntity
{
public:
	WLogicalBound(void);
	~WLogicalBound(void);

	bool Binding(void) const;
	bool Binding(bool intake);

	WBinding* Function(void) const;
	WBinding* Function(WBinding intake);

	//-->DOC_FUNC
	// WBinding setter operator
	void operator=(WBinding rhs);

	//-->DOC_FUNC
	// Execution functor to set the bool and run the method
	void operator()(void);

	//-->DOC_FUNC
	// Execution method to set the bool and run the method
	void Run(void);

private:
	//-->DOC_MEMBER
	// The boolean of the function
	bool m_binding;
	
	//-->DOC_MEMBER
	// The WBinding of the function
	WBinding* m_annex;
};


#endif // !_W_LOGICAL_BOUND_H_