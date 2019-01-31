// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_THEME_H_
#define _W_THEME_H_

#include "WEntity.h"
#include "WDX.h"
#include "WGFXContainer.h"

class WTheme : public WEntity
{
public:
	WTheme(void);

// Themes
	void ND_DarkRed(void);
	void ND_Teal(void);
	void ND_Yellow(void);
	void ND_Green(void);
	void ND_Purple(void);
	void ND_Blue(void);
	void ND_LightGreen(void);

// Nightsky Specific Themes
	void NS_Blue(void);
	void NS_Purple(void);
	void NS_Orange(void);


// Access 
	W_COLOR ColorBack(void);
	W_COLOR ColorBackGlow(void);

	W_COLOR ColorBorder(void);
	W_COLOR ColorBorderGlow(void);

	W_COLOR ColorText(void);
	W_COLOR ColorTextGlow(void);

	W_COLOR ColorBackCircle(void);

private:
	void UpdateNormal(W_COLOR Back, W_COLOR Border, W_COLOR Text, W_COLOR Circle);
	void UpdateGlow(W_COLOR Back, W_COLOR Border, W_COLOR Text, W_COLOR Circle);

private:
	W_COLOR m_ColorBack;
	W_COLOR m_ColorBackGlow;

	W_COLOR m_ColorBorder;
	W_COLOR m_ColorBorderGlow;

	W_COLOR m_ColorText;
	W_COLOR m_ColorTextGlow;

	W_COLOR m_BackCircle;
};

#endif // !_W_THEME_H_