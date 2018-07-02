// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MATRIX_2_H_
#define _W_MATRIX_2_H_

#include "WMath.h"
#include "WEntity.h"
#include "WVector2.h"

//Base class for a 2x2 matrix
template <typename T>
class WMatrix2 : public WEntity
{
public:
	WMatrix2& operator=(const WMatrix2& rhs)
	{
		memcpy(elements, rhs.elements, sizeof(elements));
		return *this;
	}
	
	WMatrix2& operator*=(T rhs)
	{
		for (auto& row : elements)
		{
			for (T& e : row)
			{
				e *= rhs;
			}
		}
		return *this;
	}
	
	WMatrix2 operator*(T rhs) const
	{
		WMatrix2 result = *this;
		return result *= rhs;
	}
	
	WMatrix2 operator*(const WMatrix2& rhs) const
	{
		WMatrix2 result;
		for (size_t j = 0; j < 2; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				T sum = (T)0.0;
				for (size_t i = 0; i < 2; i++)
				{
					sum += elements[j][i] * rhs.elements[i][k];
				}
				result.elements[j][k] = sum;
			}
		}
		return result;
	}
	
	static WMatrix2 Identity()
	{
		WMatrix2 i = { (T)1.0,(T)0.0,(T)0.0,(T)1.0 };
		return i;
	}
	
	static WMatrix2 Rotation(T theta)
	{
		const T cosTheta = cos(theta);
		const T sinTheta = sin(theta);
		WMatrix2 r = {
			cosTheta,	sinTheta,
			-sinTheta,	cosTheta };
		return r;
	}
	
	static WMatrix2 Scaling(T factor)
	{
		WMatrix2 s = { factor,(T)0.0,(T)0.0,factor };
		return s;
	}

public:
// [ row ][ col ]
	T elements[2][2];
};

template<typename T>
WVector2<T>& operator*=(WVector2<T>& lhs, const WMatrix2<T>& rhs)
{
	return lhs = lhs * rhs;
}

template<typename T>
WVector2<T> operator*(const WVector2<T>& lhs, const WMatrix2<T>& rhs)
{
	return {
		lhs.x * rhs.elements[0][0] + lhs.y * rhs.elements[1][0],
		lhs.x * rhs.elements[0][1] + lhs.y * rhs.elements[1][1]
	};
}

typedef WMatrix2<W_FLOAT> Matrix2F;
typedef WMatrix2<W_DOUBLE> Matrix2D;
typedef WMatrix2<W_INT> Matrix2I;

#endif // !_W_MATRIX_2_H_
