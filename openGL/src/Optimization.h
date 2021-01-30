#pragma once

#include <xmmintrin.h>

template<int i>
inline __m128 shuf(__m128 v)
{
	return _mm_shuffle_ps(v, v, _MM_SHUFFLE(i, i, i, i));
}

void mul_mat4(const float* const A, const float* const B, float* C) 
{
	__m128 m[4];
	m[0] = _mm_load_ps(&A[12]);
	m[1] = _mm_load_ps(&A[8]);
	m[2] = _mm_load_ps(&A[4]);
	m[3] = _mm_load_ps(&A[0]);
	
	__m128 n[4];
	
	n[0] = _mm_load_ps(&B[0]);
	n[1] = _mm_load_ps(&B[4]);
	n[2] = _mm_load_ps(&B[8]);
	n[3] = _mm_load_ps(&B[12]);
	
	__m128 r[4];
	 r[0] =
		_mm_add_ps(
		  _mm_add_ps(
			_mm_mul_ps(m[0], shuf<3>(n[0])),
			_mm_mul_ps(m[1], shuf<2>(n[0]))),
		  _mm_add_ps(
			_mm_mul_ps(m[2], shuf<1>(n[0])),
			_mm_mul_ps(m[3], shuf<0>(n[0]))));

	  r[1] =
		_mm_add_ps(
		  _mm_add_ps(
			_mm_mul_ps(m[0], shuf<3>(n[1])),
			_mm_mul_ps(m[1], shuf<2>(n[1]))),
		  _mm_add_ps(
			_mm_mul_ps(m[2], shuf<1>(n[1])),
			_mm_mul_ps(m[3], shuf<0>(n[1]))));

	  r[2] =
		_mm_add_ps(
		  _mm_add_ps(
			_mm_mul_ps(m[0], shuf<3>(n[2])),
			_mm_mul_ps(m[1], shuf<2>(n[2]))),
		  _mm_add_ps(
			_mm_mul_ps(m[2], shuf<1>(n[2])),
			_mm_mul_ps(m[3], shuf<0>(n[2]))));

	  r[3] =
		_mm_add_ps(
		  _mm_add_ps(
			_mm_mul_ps(m[0], shuf<3>(n[3])),
			_mm_mul_ps(m[1], shuf<2>(n[3]))),
		  _mm_add_ps(
			_mm_mul_ps(m[2], shuf<1>(n[3])),
			_mm_mul_ps(m[3], shuf<0>(n[3]))));
		 
	_mm_store_ps(&C[0], r[0]);
	_mm_store_ps(&C[4], r[1]);
	_mm_store_ps(&C[8], r[2]);
	_mm_store_ps(&C[12], r[3]);
}