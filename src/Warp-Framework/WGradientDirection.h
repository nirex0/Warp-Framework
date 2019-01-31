// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_GRADIENTDIRECTION_H_
#define _W_GRADIENTDIRECTION_H_

enum WLinearGradientDirection
{
// Default
	WLG_Invalid,

// Edge
	WLG_Left_Right,
	WLG_Right_Left,
	WLG_Top_Bottom,
	WLG_Bottom_Top,

// Corner
	WLG_TopLeft_BottomRight,
	WLG_TopRight_BottomLeft,
	WLG_BottomLeft_TopRight,
	WLG_BottomRight_TopLeft,

};

enum WLRadialGradientDirection
{
// Default
	WRG_Invalid,

// Center
	WRG_Center,

// Edge
	WRG_MiddleTop,
	WRG_MiddleLeft,
	WRG_MiddleBottom,
	WRG_MiddleRight,

// Corner
	WRG_TopLeft,
	WRG_TopRight,
	WRG_BottomLeft,
	WRG_BottomRight,



};

#endif // !_W_GRADIENTDIRECTION_H_
