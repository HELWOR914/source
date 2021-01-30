#pragma once

#include "Vector3.h"

template<typename T>
class Matrix3
{
private:

Vector3<T> m[3];

public:
	
	Matrix3(){}
	
	Matrix3(T const& v)
	{
		m[0].x = v;
		m[1].y = v;
		m[2].z = v;
	}
	
	Matrix3(const Vector3<T> &v1, const Vector3<T> &v2, const Vector3<T> &v3)
	{
		m[0].x = v1.x; m[0].y = v1.y; m[0].z = v1.z;
		m[1].x = v2.x; m[1].y = v2.y; m[1].z = v2.z;
		m[2].x = v3.x; m[2].y = v3.y; m[2].z = v3.z;
	}
	
	Matrix3(T const& x1, T const& y1, T const& z1,
			T const& x2, T const& y2, T const& z2,
			T const& x3, T const& y3, T const& z3)
	{
		m[0].x = x1; m[0].y = y1; m[0].z = z1;
		m[1].x = x2; m[1].y = y2; m[1].z = z2;
		m[2].x = x3; m[2].y = y3; m[2].z = z3;
	}
	
	Matrix3(const Matrix3 &M)
	{
		m[0] = M[0];
		m[1] = M[1];
		m[2] = M[2];
	}
	
	Matrix3& operator=(const Matrix3 &M)
	{
		m[0] = M[0];
		m[1] = M[1];
		m[2] = M[2];
		return *this;
	}
	
	Vector3<T> operator[](unsigned int index) const
	{
		return m[index];
	}
	
	Matrix3 operator+(const Matrix3 &M) const
	{
		return Matrix(m[0] + M[0],
					  m[1] + M[1],
					  m[2] + M[2]);
	}
	
	Matrix3 operator-(const Matrix3 &M) const
	{
		return Matrix(m[0] - M[0],
					  m[1] - M[1],
					  m[2] - M[2]);
	}
	
	Vector3<T> operator*(const Vector3<T> v) const
	{
		return Vector3<T>(m[0].x * v.x + m[1].x * v.y + m[2].x * v.z,
						  m[0].y * v.x + m[1].y * v.y + m[2].y * v.z,
						  m[0].z * v.x + m[1].z * v.y + m[2].z * v.z);
	}
	
	Matrix3 operator*(const Matrix3 &M) const
	{
		return Matrix3(m[0].x * M[0].x   +   m[0].y * M[1].x   +   m[0].z * M[2].x,
					   m[0].x * M[0].y   +   m[0].y * M[1].y   +   m[0].z * M[2].y,
					   m[0].x * M[0].z   +   m[0].y * M[1].z   +   m[0].z * M[2].z,
					   m[1].x * M[0].x   +   m[1].y * M[1].x   +   m[1].z * M[2].x,
					   m[1].x * M[0].y   +   m[1].y * M[1].y   +   m[1].z * M[2].y,
					   m[1].x * M[0].z   +   m[1].y * M[1].z   +   m[1].z * M[2].z,
					   m[2].x * M[0].x   +   m[2].y * M[1].x   +   m[2].z * M[2].x,
					   m[2].x * M[0].y   +   m[2].y * M[1].y   +   m[2].z * M[2].y,
					   m[2].x * M[0].z   +   m[2].y * M[1].z   +   m[2].z * M[2].z);
	}
};