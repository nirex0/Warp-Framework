//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_COLOR_H_
#define _W_COLOR_H_

#include "WEntity.h"
#include "WDefines.h"

// Primary class for color

class WColor final : WEntity
{
public:
	W_DWORD val;
public:
	constexpr WColor() : val() {}
	constexpr WColor(const WColor& col) :
		val(col.val)
	{}
	constexpr WColor(WColor&& col) :
		val(col.val)
	{}
	constexpr WColor(unsigned int dw) :
		val(dw)
	{}
	constexpr WColor(W_BYTE a, W_BYTE r, W_BYTE g, W_BYTE b) :
		val((a << 24u) | (r << 16u) | (g << 8u) | b)
	{}
	constexpr WColor(W_BYTE r, W_BYTE g, W_BYTE b) :
		val((r << 16u) | (g << 8u) | b)
	{}
	WColor& operator =(WColor color)
	{
		val = color.val;
		return *this;
	}
	constexpr W_BYTE A() const
	{
		return val >> 24u;
	}
	constexpr W_BYTE R() const
	{
		return (val >> 16u) & 0xFFu;
	}
	constexpr W_BYTE G() const
	{
		return (val >> 8u) & 0xFFu;
	}
	constexpr W_BYTE B() const
	{
		return val & 0xFFu;
	}
	void A(W_BYTE x)
	{
		val = (val & 0xFFFFFFu) | (x << 24u);
	}
	void R(W_BYTE r)
	{
		val = (val & 0xFF00FFFFu) | (r << 16u);
	}
	void G(W_BYTE g)
	{
		val = (val & 0xFFFF00FFu) | (g << 8u);
	}
	void B(W_BYTE b)
	{
		val = (val & 0xFFFFFF00u) | b;
	}
};

// A set of pre-defined color prefabs
namespace WColors
{
	static const WColor White = WColor(255u, 255u, 255u, 255u);
	static const WColor Black = WColor(255u, 0u, 0u, 0u);
	static const WColor Gray = WColor(255u, 0x80u, 0x80u, 0x80u);
	static const WColor LightGray = WColor(255u, 0xD3u, 0xD3u, 0xD3u);
	static const WColor Red = WColor(255u, 255u, 0u, 0u);
	static const WColor Green = WColor(255u, 0u, 255u, 0u);
	static const WColor Blue = WColor(255u, 0u, 0u, 255u);
	static const WColor Yellow = WColor(255u, 255u, 255u, 0u);
	static const WColor Cyan = WColor(255u, 0u, 255u, 255u);
	static const WColor Magenta = WColor(255u, 255u, 0u, 255u);
}

#endif // !_W_COLOR_H_