//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MATRIX_3_H_
#define _W_MATRIX_3_H_

#include "WVector3.h"

//Base class for a 3x3 matrix
template <typename T>
class WMatrix3 : public WEntity
{
public:
	WMatrix3& operator=(const WMatrix3& rhs)
	{
		memcpy(elements, rhs.elements, sizeof(elements));
		return *this;
	}
	
	WMatrix3& operator*=(T rhs)
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
	
	WMatrix3 operator*(T rhs) const
	{
		WMatrix3 result = *this;
		return result *= rhs;
	}
	
	WMatrix3& operator*=(const WMatrix3& rhs)
	{
		return *this = *this * rhs;
	}
	
	WMatrix3 operator*(const WMatrix3& rhs) const
	{
		WMatrix3 result;
		for (size_t j = 0; j < 3; j++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				T sum = (T)0.0;
				for (size_t i = 0; i < 3; i++)
				{
					sum += elements[j][i] * rhs.elements[i][k];
				}
				result.elements[j][k] = sum;
			}
		}
		return result;
	}
	
	static WMatrix3 Identity()
	{
		return {
			(T)1.0,(T)0.0,(T)0.0,
			(T)0.0,(T)1.0,(T)0.0,
			(T)0.0,(T)0.0,(T)1.0
		};
	}
	
	static WMatrix3 Scaling(T factor)
	{
		return{
			factor,(T)0.0,(T)0.0,
			(T)0.0,factor,(T)0.0,
			(T)0.0,(T)0.0,factor
		};
	}
	
	static WMatrix3 RotationZ(T theta)
	{
		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);
		return{
			cosTheta, sinTheta, (T)0.0,
			-sinTheta, cosTheta, (T)0.0,
			(T)0.0,    (T)0.0,   (T)1.0
		};
	}
	
	static WMatrix3 RotationY(T theta)
	{
		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);
		return{
			cosTheta, (T)0.0,-sinTheta,
			(T)0.0,   (T)1.0, (T)0.0,
			sinTheta, (T)0.0, cosTheta
		};
	}
	
	static WMatrix3 RotationX(T theta)
	{
		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);
		return{
			(T)1.0, (T)0.0,   (T)0.0,
			(T)0.0, cosTheta, sinTheta,
			(T)0.0,-sinTheta, cosTheta,
		};
	}

public:
	// [ row ][ col ]
	T elements[3][3];
};

template<typename T>
WVector3<T>& operator*=(WVector3<T>& lhs, const WMatrix3<T>& rhs)
{
	return lhs = lhs * rhs;
}

template<typename T>
WVector3<T> operator*(const WVector3<T>& lhs, const WMatrix3<T>& rhs)
{
	return{
		lhs.x * rhs.elements[0][0] + lhs.y * rhs.elements[1][0] + lhs.z * rhs.elements[2][0],
		lhs.x * rhs.elements[0][1] + lhs.y * rhs.elements[1][1] + lhs.z * rhs.elements[2][1],
		lhs.x * rhs.elements[0][2] + lhs.y * rhs.elements[1][2] + lhs.z * rhs.elements[2][2]
	};
}

typedef WMatrix3<W_FLOAT> Matrix3F;
typedef WMatrix3<W_DOUBLE> Matrix3D;
typedef WMatrix3<W_INT> Matrix3I;

#endif // !_W_MATRIX_3_H_
