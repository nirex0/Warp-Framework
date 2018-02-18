//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_ARGS_H_
#define _W_MOUSE_ARGS_H_

#include "WEventArgs.h"
#include "WDefines.h"

class WMouseArgs : public WEventArgs
{
public:
	WMouseArgs(int x, int y, WMouseKey key);
	WMouseArgs(WPoint point, WMouseKey key);
	WMouseArgs(WPoint* point, WMouseKey key);
	~WMouseArgs(void);

	WPoint* const GetPoint(void);
	WMouseKey const GetKey(void) const;
	int GetX(void) const;
	int GetY(void) const;

private:
	WPoint* m_Point;
	WMouseKey m_wmk;
};

#endif // _W_MOUSE_ARGS_H_
