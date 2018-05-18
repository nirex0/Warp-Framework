//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GRADIENTDIRECTION_H_
#define _W_GRADIENTDIRECTION_H_

enum WGradientDirection
{
	// Default
	Invalid,

	// Edge
	Left_Right,
	Right_Left,
	Top_Bottom,
	Bottom_Top,

	// Corner
	TopLeft_BottomRight,
	TopRight_BottomLeft,
	BottomLeft_TopRight,
	BottomRight_TopLeft
};

#endif // !_W_GRADIENTDIRECTION_H_
