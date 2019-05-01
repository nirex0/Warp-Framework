// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_ENTITY_H_
#define _W_ENTITY_H_

//-->DOC_CLASS
// Parent of almost all warp-related classes, if you need anything extra just add it to this one
class WEntity 
{
	virtual void Free(void)
	{
		delete this;
	}
};

#endif // !_W_ENTITY_H_
