// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_EVENT_BOUND_H_
#define _W_EVENT_BOUND_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <vector>
#include <functional>

typedef std::function<void __stdcall (WEntity* sender, WEventArgs* args)> Annex;

//-->DOC_CLASS
// Binds an Annex to a Bool, if the Annex is successfully completed, the bool will be set to true, it'll be set to false otherwise
class WEventBound : public WEntity
{
public:
	WEventBound(void);
	~WEventBound(void);

	bool Binding(void) const;
	bool Binding(bool intake);

	Annex* Function(void) const;
	Annex* Function(Annex intake);

	//-->DOC_FUNC
	// Annex setter operator
	void operator=(Annex rhs);

	//-->DOC_FUNC
	// Execution functor to set the bool and run the method
	void operator()(WEntity* sender, WEventArgs* args);

	//-->DOC_FUNC
	// Execution method to set the bool and run the method
	void Run(WEntity* sender, WEventArgs* args);

private:
	//-->DOC_MEMBER
	// The boolean of the function
	bool m_binding;

	//-->DOC_MEMBER
	// The annex of the function
	Annex* m_annex;
};

#endif // !_W_EVENT_BOUND_H_