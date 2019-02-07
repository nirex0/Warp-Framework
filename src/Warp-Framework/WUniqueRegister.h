// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_UNIQUE_REGISTER_H_
#define _W_UNIQUE_REGISTER_H_

#include "WEntity.h"
#include "WEventArgs.h"

#include <memory>
#include <functional>

typedef std::function<void __stdcall (WEntity* sender, WEventArgs* args)> Annex;

//-->DOC_CLASS
// A class for event registry and handling (Limited to 1 Annex)
class WUniqueRegister final : public WEntity
{
public:	
	WUniqueRegister(void);
	~WUniqueRegister(void);

	//-->DOC_FUNC
	// Raise event functor
	WUniqueRegister* operator()(WEntity* sender, WEventArgs* args);

	//-->DOC_FUNC
	// Raise event method
	WUniqueRegister* Run(WEntity* sender, WEventArgs* args);

	//-->DOC_FUNC
	// Register method
	WUniqueRegister* Register(Annex intake);

	//-->DOC_FUNC
	// Unegister method
	WUniqueRegister* Unregister(void);

private:
	//-->DOC_MEMBER
	// Registered annex
	Annex* m_Register;
};

#endif // !_W_UNIQUE_REGISTER_H_
