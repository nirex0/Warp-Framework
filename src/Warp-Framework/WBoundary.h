//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_BOUNDARY_H_
#define _W_BOUNDARY_H_

#include "WThickness.h"

class WBoundary : public WThickness
{
public:
	inline bool IsColliding(WBoundary intake) const
	{
		return 
			(
			this->Left() < intake.Right() &&
			this->Right() > intake.Left() &&
			this->Top() < intake.Bottom() &&
			this->Bottom() > intake.Top() 
			);
	}
};

#endif // !_W_BOUNDARY_H_
