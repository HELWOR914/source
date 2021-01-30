#pragma once

#include "Vector4.h"

template<typename T>
class Matrix4
{
private:

Vector4<T> m[4];

public:
	
	Matrix4(){}
	
	Matrix4(T const& v)
	{
		m[0].x = v;
		m[1].y = v;
		m[2].z = v;
		m[3].w = v;
	}
	
	Matrix4(const Vector4<T> &v1, const Vector4<T> &v2, const Vector4<T> &v3, const Vector4<T> &v4)
	{
		m[0].x = v1.x; m[0].y = v1.y; m[0].z = v1.z; m[0].w = v1.w; 
		m[1].x = v2.x; m[1].y = v2.y; m[1].z = v2.z; m[1].w = v2.w;
		m[2].x = v3.x; m[2].y = v3.y; m[2].z = v3.z; m[2].w = v3.w;
		m[3].x = v4.x; m[3].y = v4.y; m[3].z = v4.z; m[3].w = v4.w;
	}
	
	Matrix4(T const& x1, T const& y1, T const& z1, T const& w1,
			T const& x2, T const& y2, T const& z2, T const& w2,
			T const& x3, T const& y3, T const& z3, T const& w3,
			T const& x4, T const& y4, T const& z4, T const& w4)
	{
		m[0].x = x1; m[0].y = y1; m[0].z = z1; m[0].w = w1;
		m[1].x = x2; m[1].y = y2; m[1].z = z2; m[1].w = w2;
		m[2].x = x3; m[2].y = y3; m[2].z = z3; m[2].w = w3;
		m[3].x = x4; m[3].y = y4; m[3].z = z4; m[3].w = w4;
	}
	
	Matrix4(const Matrix4 &M)
	{
		m[0] = M[0];
		m[1] = M[1];
		m[2] = M[2];
		m[3] = M[3];
	}
	
	Matrix4& operator=(const Matrix4 &M)
	{
		m[0] = M[0];
		m[1] = M[1];
		m[2] = M[2];
		m[3] = M[3];
		return *this;
	}
	
	Vector4<T> operator[](unsigned int index) const
	{
		return m[index];
	}
	
	Matrix4 operator+(const Matrix4 &M) const
	{
		return Matrix(m[0] + M[0],
					  m[1] + M[1],
					  m[2] + M[2],
					  m[3] + M[3]);
	}
	
	Matrix4 operator-(const Matrix4 &M) const
	{
		return Matrix(m[0] - M[0],
					  m[1] - M[1],
					  m[2] - M[2],
					  m[3] - M[3]);
	}
	
	Vector4<T> operator*(const Vector4<T> v) const
	{
		return Vector4<T>(m[0].x * v.x + m[1].x * v.y + m[2].x * v.z + m[3].x * v.w,
						  m[0].y * v.x + m[1].y * v.y + m[2].y * v.z + m[3].y * v.w,
						  m[0].z * v.x + m[1].z * v.y + m[2].z * v.z + m[3].z * v.w,
						  m[0].w * v.x + m[1].w * v.y + m[2].w * v.z + m[3].w * v.w);
	}
	
	Matrix4 operator*(const Matrix4 &M) const
	{
		return Matrix4(m[0].x * M[0].x   +   m[0].y * M[1].x   +   m[0].z * M[2].x   +   m[0].w * M[3].x,
					   m[0].x * M[0].y   +   m[0].y * M[1].y   +   m[0].z * M[2].y   +   m[0].w * M[3].y,
					   m[0].x * M[0].z   +   m[0].y * M[1].z   +   m[0].z * M[2].z   +   m[0].w * M[3].z,
					   m[0].x * M[0].w   +   m[0].y * M[1].w   +   m[0].z * M[2].w   +   m[0].w * M[3].w,
					   m[1].x * M[0].x   +   m[1].y * M[1].x   +   m[1].z * M[2].x   +   m[1].w * M[3].x,
					   m[1].x * M[0].y   +   m[1].y * M[1].y   +   m[1].z * M[2].y   +   m[1].w * M[3].y,
					   m[1].x * M[0].z   +   m[1].y * M[1].z   +   m[1].z * M[2].z   +   m[1].w * M[3].z,
					   m[1].x * M[0].w   +   m[1].y * M[1].w   +   m[1].z * M[2].w   +   m[1].w * M[3].w,
					   m[2].x * M[0].x   +   m[2].y * M[1].x   +   m[2].z * M[2].x   +   m[2].w * M[3].x,
					   m[2].x * M[0].y   +   m[2].y * M[1].y   +   m[2].z * M[2].y   +   m[2].w * M[3].y,
					   m[2].x * M[0].z   +   m[2].y * M[1].z   +   m[2].z * M[2].z   +   m[2].w * M[3].z,
					   m[2].x * M[0].w   +   m[2].y * M[1].w   +   m[2].z * M[2].w   +   m[2].w * M[3].w,
					   m[3].x * M[0].x   +   m[3].y * M[1].x   +   m[3].z * M[2].x   +   m[3].w * M[3].x,
					   m[3].x * M[0].y   +   m[3].y * M[1].y   +   m[3].z * M[2].y   +   m[3].w * M[3].y,
					   m[3].x * M[0].z   +   m[3].y * M[1].z   +   m[3].z * M[2].z   +   m[3].w * M[3].z,
					   m[3].x * M[0].w   +   m[3].y * M[1].w   +   m[3].z * M[2].w   +   m[3].w * M[3].w);
	}
};