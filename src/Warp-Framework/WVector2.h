// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_VECTOR_2_H_
#define _W_VECTOR_2_H_

#include "WDefines.h"
#include "WEntity.h"

template <typename T>
class WVector2 : public WEntity
{
public:
	WVector2()
	{}

	WVector2(T x, T y)
		:
		x(x),
		y(y)
	{}

	WVector2(const WVector2& vect)
		:
		WVector2(vect.x, vect.y)
	{}

	template <typename T2>
	explicit operator WVector2<T2>() const
	{
		return{ (T2)x,(T2)y };
	}

	T LenSq() const
	{
		return sq(*this);
	}

	T Len() const
	{
		return sqrt(LenSq());
	}

	WVector2& Normalize()
	{
		const T length = Len();
		x /= length;
		y /= length;
		return *this;
	}

	WVector2 GetNormalized() const
	{
		WVector2 norm = *this;
		norm.Normalize();
		return norm;
	}

	WVector2 operator-() const
	{
		return WVector2(-x, -y);
	}

	WVector2& operator=(const WVector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	WVector2& operator+=(const WVector2 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	WVector2& operator-=(const WVector2 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	T operator*(const WVector2 &rhs) const
	{
		return x* rhs.x + y* rhs.y;
	}

	WVector2 operator+(const WVector2 &rhs) const
	{
		return WVector2(*this) += rhs;
	}

	WVector2 operator-(const WVector2 &rhs) const
	{
		return WVector2(*this) -= rhs;
	}

	WVector2& operator*=(const T &rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	WVector2 operator*(const T &rhs) const
	{
		return WVector2(*this) *= rhs;
	}

	WVector2& operator/=(const T &rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	WVector2 operator/(const T &rhs) const
	{
		return WVector2(*this) /= rhs;
	}

	bool operator==(const WVector2 &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const WVector2 &rhs) const
	{
		return !(*this == rhs);
	}

	WVector2& Saturate()
	{
		x = std::min(1.0f, std::max(0.0f, x));
		y = std::min(1.0f, std::max(0.0f, y));
		return *this;
	}

	WVector2 GetSaturated() const
	{
		WVector2 temp(*this);
		temp.Saturate();
		return temp;
	}

	WVector2& Hadamard(const WVector3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	WVector2 GetHadamard(const WVector3& rhs) const
	{
		WVector3 temp(*this);
		temp.Hadamard(rhs);
		return temp;
	}

	T X(void) const 
	{
		return this->x;
	}

	void X(T x) 
	{ 
		this->x = x;
	}

	T Y(void) const
	{
		return this->y;
	}

	void Y(T y)
	{
		this->y = y; 
	}

private:
	T x;
	T y;
};

typedef WVector2<W_FLOAT> Vector2F;
typedef WVector2<W_DOUBLE> Vector2D;
typedef WVector2<W_INT> Vector2I;

#endif // !_W_VECTOR_2_H_
