// © 2018 NIREX ALL RIGHTS RESERVED

#include "WTheme.h"

WTheme::WTheme(void)
{
	ND_Teal();
}

void WTheme::ND_DarkRed(void)
{

	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x12, 0x12, 0x12),
		WGraphicsContainer::Graphics()->FromRGBA(0xB5, 0x24, 0x24),
		WGraphicsContainer::Graphics()->FromRGBA(0xB5, 0x24, 0x24)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0x00, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0xEF, 0x2E, 0x2E),
		WGraphicsContainer::Graphics()->FromRGBA(0xEF, 0x2E, 0x2E)
	);
}

void WTheme::ND_Teal(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x12, 0x15, 0x1E),
		WGraphicsContainer::Graphics()->FromRGBA(0x17, 0xBF, 0x76),
		WGraphicsContainer::Graphics()->FromRGBA(0x17, 0xBF, 0x76)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x23, 0x2F),
		WGraphicsContainer::Graphics()->FromRGBA(0x1C, 0xED, 0x93),
		WGraphicsContainer::Graphics()->FromRGBA(0x1C, 0xED, 0x93)
	);
}

void WTheme::ND_Yellow(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x21, 0x21),
		WGraphicsContainer::Graphics()->FromRGBA(0xA8, 0xA8, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0xA8, 0xA8, 0x00)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x17, 0x17, 0x17),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0xFF, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0xFF, 0x00)
	);
}

void WTheme::ND_Green(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x21, 0x21),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0x9C, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0x9C, 0x00)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x17, 0x17, 0x17),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0xFF, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0xFF, 0x00)
	);
}

void WTheme::ND_Purple(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x21, 0x21),
		WGraphicsContainer::Graphics()->FromRGBA(0xAE, 0x00, 0xAE),
		WGraphicsContainer::Graphics()->FromRGBA(0xAE, 0x00, 0xAE)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x17, 0x17, 0x17),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF,0x00,0xFF),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF,0x00,0xFF)
	);
}

void WTheme::ND_Blue(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x11, 0x15, 0x21),
		WGraphicsContainer::Graphics()->FromRGBA(0x1D, 0x1D, 0xA2),
		WGraphicsContainer::Graphics()->FromRGBA(0x1D, 0x1D, 0xA2)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x23, 0x2F),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0x00, 0x00),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0x00, 0x00)
	);
}

void WTheme::ND_LightGreen(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x3C, 0x3D, 0x5B),
		WGraphicsContainer::Graphics()->FromRGBA(0x81, 0xB4, 0x79),
		WGraphicsContainer::Graphics()->FromRGBA(0x81, 0xB4, 0x79)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x21, 0x23, 0x2F),
		WGraphicsContainer::Graphics()->FromRGBA(0x6E, 0xF7, 0x59),
		WGraphicsContainer::Graphics()->FromRGBA(0x6E, 0xF7, 0x59)
	);
}

void WTheme::NS_Blue(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.5F),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0x9B, 0xFF),
		WGraphicsContainer::Graphics()->FromRGBA(0x00, 0x9B, 0xFF)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.0F),
		WGraphicsContainer::Graphics()->FromRGBA(0x8B, 0xCE, 0xF9),
		WGraphicsContainer::Graphics()->FromRGBA(0x8B, 0xCE, 0xF9)
	);
}

void WTheme::NS_Purple(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.5F),
		WGraphicsContainer::Graphics()->FromRGBA(0x8C, 0x72, 0xFF),
		WGraphicsContainer::Graphics()->FromRGBA(0x8C, 0x72, 0xFF)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.0F),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0x64, 0x41),
		WGraphicsContainer::Graphics()->FromRGBA(0xFF, 0x64, 0x41)
	);
}

void WTheme::NS_Orange(void)
{
	UpdateNormal
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.5F),
		WGraphicsContainer::Graphics()->FromRGBA(0xF1, 0xED, 0xFF),
		WGraphicsContainer::Graphics()->FromRGBA(0xF1, 0xED, 0xFF)
	);

	UpdateGlow
	(
		WGraphicsContainer::Graphics()->FromRGBA(0x02, 0x03, 0x05, 0.0F),
		WGraphicsContainer::Graphics()->FromRGBA(0x8C, 0x72, 0xFF),
		WGraphicsContainer::Graphics()->FromRGBA(0x8C, 0x72, 0xFF)
	);
}

W_COLOR WTheme::ColorBack(void)
{
	return m_ColorBack;
}

W_COLOR WTheme::ColorBackGlow(void)
{
	return m_ColorBackGlow;
}

W_COLOR WTheme::ColorBorder(void)
{
	return m_ColorBorder;
}

W_COLOR WTheme::ColorBorderGlow(void)
{
	return  m_ColorBorderGlow;
}

W_COLOR WTheme::ColorText(void)
{
	return m_ColorText;
}

W_COLOR WTheme::ColorTextGlow(void)
{
	return m_ColorTextGlow;
}

void WTheme::UpdateNormal(W_COLOR Back, W_COLOR Border, W_COLOR Text)
{
	m_ColorBack = Back;
	m_ColorBorder = Border;
	m_ColorText = Text;
}

void WTheme::UpdateGlow(W_COLOR Back, W_COLOR Border, W_COLOR Text)
{
	m_ColorBackGlow = Back;
	m_ColorBorderGlow = Border;
	m_ColorTextGlow = Text;
}
