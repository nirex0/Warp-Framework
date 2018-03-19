//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_VECTOR_4_H_
#define _W_VECTOR_4_H_

#include "WVector3.h"

template <typename T>
class WVector4 : public WVector3<T>
{
public:
	WVector4() {}

	WVector4(T x, T y, T z, T w)
		:
		WVector3(x, y, z),
		w(w)
	{}

	WVector4(const WVector4& vect)
		:
		WVector4(vect.x, vect.y, vect.z, vect.w)
	{}

	template <typename T2>
	explicit operator WVector4<T2>() const
	{
		return{ (T2)x,(T2)y,(T2)z,(T2)w };
	}

	T LenSq() const
	{
		return sq(*this);
	}

	T Len() const
	{
		return sqrt(LenSq());
	}

	WVector4& Normalize()
	{
		const T length = Len();
		x /= length;
		y /= length;
		z /= length;
		w /= length;
		return *this;
	}

	WVector4 GetNormalized() const
	{
		WVector4 norm = *this;
		norm.Normalize();
		return norm;
	}

	WVector4 operator-() const
	{
		return WVector4(-x, -y, -z, -w);
	}

	WVector4& operator=(const WVector4 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
	}

	WVector4& operator+=(const WVector4 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	WVector4& operator-=(const WVector4 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	T operator*(const WVector4 &rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	}

	WVector4 operator+(const WVector4 &rhs) const
	{
		return WVector4(*this) += rhs;
	}

	WVector4 operator-(const WVector4 &rhs) const
	{
		return WVector4(*this) -= rhs;
	}

	WVector4& operator*=(const T &rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		return *this;
	}

	WVector4 operator*(const T &rhs) const
	{
		return WVector4(*this) *= rhs;
	}

	WVector4 operator%(const WVector4& rhs) const
	{
		// w remains the same in this vector
		return WVector4(
			y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x
			w);
	}

	WVector4& operator/=(const T &rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		return *this;
	}

	WVector4 operator/(const T &rhs) const
	{
		return WVector4(*this) /= rhs;
	}

	bool operator==(const WVector4 &rhs) const
	{
		return x == rhs.x && y == rhs.y && rhs.z = z && rhs.w = w;
	}

	bool operator!=(const WVector4 &rhs) const
	{
		return !(*this == rhs);
	}

	WVector4& Saturate()
	{
		x = std::min(1.0f, std::max(0.0f, x));
		y = std::min(1.0f, std::max(0.0f, y));
		z = std::min(1.0f, std::max(0.0f, z));
		w = std::min(1.0f, std::max(0.0f, w));
		return *this;
	}

	WVector4 GetSaturated() const
	{
		WVector4 temp(*this);
		temp.Saturate();
		return temp;
	}

	WVector4& Hadamard(const WVector4& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}

	WVector4 GetHadamard(const WVector4& rhs) const
	{
		WVector4 temp(*this);
		temp.Hadamard(rhs);
		return temp;
	}

	T W(void) const
	{
		return this->w;
	}

	void W(T w)
	{
		this->w = w;
	}

public:
	T w;
};

typedef WVector4<float> Vector4F;
typedef WVector4<double> Vector4D;
typedef WVector4<int> Vector4I;

#endif // !_W_VECTOR_4_H_