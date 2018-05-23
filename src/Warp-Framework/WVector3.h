//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_VECTOR_3_H_
#define _W_VECTOR_3_H_

#include "WVector2.h"

template <typename T>
class WVector3 : public WVector2<T>
{
public:
	WVector3() {}

	WVector3(T x, T y, T z)
		:
		WVector2(x, y),
		z(z)
	{}

	WVector3(const WVector3& vect)
		:
		WVector3(vect.x, vect.y, vect.z)
	{}

	template <typename T2>
	explicit operator WVector3<T2>() const
	{
		return{ (T2)x,(T2)y,(T2)z };
	}

	T LenSq() const
	{
		return sq(*this);
	}

	T Len() const
	{
		return sqrt(LenSq());
	}

	WVector3& Normalize()
	{
		const T length = Len();
		x /= length;
		y /= length;
		z /= length;
		return *this;
	}

	WVector3 GetNormalized() const
	{
		WVector3 norm = *this;
		norm.Normalize();
		return norm;
	}

	WVector3 operator-() const
	{
		return WVector3(-x, -y, -z);
	}

	WVector3& operator=(const WVector3 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	WVector3& operator+=(const WVector3 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	WVector3& operator-=(const WVector3 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	T operator*(const WVector3 &rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	WVector3 operator+(const WVector3 &rhs) const
	{
		return WVector3(*this) += rhs;
	}

	WVector3 operator-(const WVector3 &rhs) const
	{
		return WVector3(*this) -= rhs;
	}

	WVector3& operator*=(const T &rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}

	WVector3 operator*(const T &rhs) const
	{
		return WVector3(*this) *= rhs;
	}

	WVector3 operator%(const WVector3& rhs) const
	{
		return WVector3(
			y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x);
	}

	WVector3& operator/=(const T &rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}

	WVector3	operator/(const T &rhs) const
	{
		return WVector3(*this) /= rhs;
	}

	bool	operator==(const WVector3 &rhs) const
	{
		return x == rhs.x && y == rhs.y && rhs.z = z;
	}

	bool	operator!=(const WVector3 &rhs) const
	{
		return !(*this == rhs);
	}

	WVector3& Saturate()
	{
		x = std::min(1.0f, std::max(0.0f, x));
		y = std::min(1.0f, std::max(0.0f, y));
		z = std::min(1.0f, std::max(0.0f, z));
		return *this;
	}

	WVector3 GetSaturated() const
	{
		WVector3 temp(*this);
		temp.Saturate();
		return temp;
	}

	WVector3& Hadamard(const WVector3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	WVector3 GetHadamard(const WVector3& rhs) const
	{
		WVector3 temp(*this);
		temp.Hadamard(rhs);
		return temp;
	}

	T Z(void) const
	{
		return this->z;
	}

	void Z(T z)
	{
		this->z = z;
	}

public:
	T z;
};

typedef WVector3<W_FLOAT> Vector3F;
typedef WVector3<W_DOUBLE> Vector3D;
typedef WVector3<W_INT> Vector3I;

#endif // !_W_VECTOR_3_H_