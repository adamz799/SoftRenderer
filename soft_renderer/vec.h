#pragma once
#pragma once
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "head.h"
#include <intrin.h>

#define M_PI 3.142592657


#ifndef VEC2
#define VEC2

class vec2 {
public:
	float e[2];

	vec2() {}
	vec2(float a, float b) { e[0] = a; e[1] = b; }
	vec2(float a) { e[0] = a; e[1] = a; }
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float r() const { return e[0]; }
	float g() const { return e[1]; }
	int size() { return 2; }
	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }
	const vec2& operator+() const { return *this; }
	vec2 operator-() const { return vec2(-e[0], -e[1]); }
	vec2& operator+=(const vec2 &v2) { e[0] += v2[0]; e[1] += v2[1];  return *this; }
	vec2& operator+=(const float &v) { for (int i = 0; i < 2; ++i) { e[i] += v; } return *this; }
	vec2& operator-=(const vec2 &v2) { e[0] -= v2[0]; e[1] -= v2[1];  return *this; }
	vec2& operator-=(const float &v) { for (int i = 0; i < 2; ++i) { e[i] -= v; } return *this; }
	vec2& operator*=(const vec2 &v2) { e[0] *= v2[0]; e[1] *= v2[1];   return *this; }
	vec2& operator*=(const float &v) { for (int i = 0; i < 2; ++i) { e[i] *= v; } return *this; }
	vec2& operator/=(const vec2 &v2) { e[0] /= v2[0]; e[1] /= v2[1];  return *this; }
	vec2& operator/=(const float &v) { for (int i = 0; i < 2; ++i) { e[i] /= v; } return *this; }

	float length() const
	{
		return sqrt(square_length());
	}

	float square_length() const
	{
		return e[0] * e[0] + e[1] * e[1];
	}

	vec2 unit() const
	{
		float l = length();
		return vec2(e[0] / l, e[1] / l);
	}


};


inline std::istream& operator>>(std::istream &is, vec2 &t)
{
	is >> t.e[0] >> t.e[1];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, vec2 &t)
{
	os << t.e[0] << t.e[1];
	return os;
}

inline vec2 operator+(vec2 const &e, float const v)
{
	return vec2(e.x() + v, e.y() + v);
}

inline vec2 operator+(vec2 const &e, vec2 const &f)
{
	return vec2(e.x() + f.x(), e.y() + f.y());
}

inline vec2 operator-(vec2 const &e, float const v)
{
	return vec2(e.x() - v, e.y() - v);
}

inline vec2 operator-(vec2 const &e, vec2 const &f)
{
	return vec2(e.x() - f.x(), e.y() - f.y());
}

inline vec2 operator*(vec2 const &e, float const v)
{
	return vec2(e.x() * v, e.y() * v);
}

inline vec2 operator*(vec2 const &e, vec2 const &f)
{
	return vec2(e.x() * f.x(), e.y() * f.y());
}

inline vec2 operator*(float const v, vec2 const &e)
{
	return vec2(e.x() * v, e.y() * v);
}

inline vec2 operator/(vec2 const &e, float const v)
{
	if (abs(v) > 1e-6) return (vec2(e[0] / v, e[1] / v));
}

inline float dot(vec2 const &e1, vec2 const &e2)
{
	return (e1.e[0] * e2.e[0] + e1.e[1] * e2.e[1]);
}

inline float cross(vec2 const &e1, vec2 const &e2)
{
	return e1[0] * e2[1] - e1[1] * e2[0];
}


#endif // !VEC2

#ifndef VEC3
#define VEC3

class vec3 {
public:
	vec3() {}
	float e[3];
	vec3(float e0) {
		e[0] = e0; e[1] = e0;
		e[2] = e0;
	}
	vec3(float e0, float e1, float e2) {
		e[0] = e0; e[1] = e1;
		e[2] = e2;
	}
	/*vec3(const vec4 &in) {
	for(int i = 0; i < 3; ++i) {
	e[i] = in[i];
	}
	}*/
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }
	float r() const { return x(); }
	float g() const { return y(); }
	float b() const { return z(); }
	int size() { return 3; }
	const vec3& operator+() const { return *this; }
	vec3 operator-() const { return vec3(-x(), -y(), -z()); }

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3 &v2) { e[0] += v2.x(); e[1] += v2.y();  e[2] += v2.z(); return *this; }
	vec3& operator+=(const float &v) { for (int i = 0; i < 3; ++i) { e[i] += v; } return *this; }
	vec3& operator-=(const vec3 &v2) { e[0] -= v2.x(); e[1] -= v2.y();  e[2] -= v2.z(); return *this; }
	vec3& operator-=(const float &v) { for (int i = 0; i < 3; ++i) { e[i] -= v; } return *this; }
	vec3& operator*=(const vec3 &v2) { e[0] *= v2.x(); e[1] *= v2.y();  e[2] *= v2.z(); return *this; }
	vec3& operator*=(const float &v) { for (int i = 0; i < 3; ++i) { e[i] *= v; } return *this; }
	vec3& operator/=(const vec3 &v2) { e[0] /= v2.x(); e[1] /= v2.y();  e[2] /= v2.z(); return *this; }
	vec3& operator/=(const float &v) { for (int i = 0; i < 3; ++i) { e[i] /= v; } return *this; }

	float length() const
	{
		return sqrt(square_length());
	}

	float square_length() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	vec3 unit() const
	{
		float l = length();
		return vec3(e[0] / l, e[1] / l, e[2] / l);
	}


};

inline std::istream& operator>>(std::istream &is, vec3 &t)
{
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3 &t)
{
	os << t.e[0] << t.e[1] << t.e[2];
	return os;
}

inline vec3 operator+(vec3 const &e, float const v)
{
	return vec3(e.x() + v, e.y() + v, e.z() + v);
}

inline vec3 operator+(vec3 const &e, vec3 const &f)
{
	return vec3(e.x() + f.x(), e.y() + f.y(), e.z() + f.z());
}

inline vec3 operator-(vec3 const &e, float const v)
{
	return vec3(e.x() - v, e.y() - v, e.z() - v);
}

inline vec3 operator-(vec3 const &e, vec3 const &f)
{
	return vec3(e.x() - f.x(), e.y() - f.y(), e.z() - f.z());
}

inline vec3 operator*(vec3 const &e, float const v)
{
	return vec3(e.x() * v, e.y() * v, e.z() * v);
}

inline vec3 operator*(vec3 const &e, vec3 const &f)
{
	return vec3(e.x() * f.x(), e.y() * f.y(), e.z() * f.z());
}

inline vec3 operator*(float const v, vec3 const &e)
{
	return vec3(e.x() * v, e.y() * v, e.z() * v);
}

inline vec3 operator/(vec3 const &e, float const v)
{
	if (abs(v) > 1e-6) return (vec3(e[0] / v, e[1] / v, e[2] / v));
}

inline float dot(vec3 const &e1, vec3 const &e2)
{
	return (e1.e[0] * e2.e[0] + e1.e[1] * e2.e[1] + e1.e[2] * e2.e[2]);
}

inline vec3 cross(vec3 const &e1, vec3 const &e2)
{
	//left-hand
	return vec3(
		-(e1.e[1] * e2.e[2] - e1.e[2] * e2.e[1]),
		(e1.e[0] * e2.e[2] - e1.e[2] * e2.e[0]),
		-(e1.e[0] * e2.e[1] - e1.e[1] * e2.e[0])
	);
}

#endif // !VEC3


#ifndef VEC4
#define VEC4

class vec4 {
public:
	float e[4];
	vec4() = default;
#ifdef SIMD
	vec4(float a) {
		_mm_storeu_ps(e, _mm_load_ps1(&a));
	}
	vec4(float a, float b, float c, float d = 0.0f) {
		_mm_storeu_ps(e, { a,b,c,d });
	}
	
#else
	vec4(float a) { e[0] = a; e[1] = a; e[2] = a; e[3] = a; }
	vec4(float a, float b, float c, float d = 0.0f) { e[0] = a; e[1] = b; e[2] = c; e[3] = d; }

#endif // SIMD

	vec4(const vec3 &a, float b = 0.0f) { e[0] = a[0]; e[1] = a[1]; e[2] = a[2]; e[3] = b; }

	void set(float a, float b, float c, float d) { e[0] = a; e[1] = b; e[2] = c; e[3] = d; }
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }
	float w() const { return e[3]; }

	float r() const { return e[0]; }
	float g() const { return e[1]; }
	float b() const { return e[2]; }
	float a() const { return e[3]; }
	int size() { return 4; }
	const vec4& operator+() const { return *this; }
	vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

#ifdef SIMD
	vec4& operator+=(const vec4 &v2) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_loadu_ps(v2.e);
		_mm_storeu_ps(this->e, _mm_add_ps(v0, v1));
		return *this;
	}
	vec4& operator+=(const float &v) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_load_ps1(&v);
		_mm_storeu_ps(this->e, _mm_add_ps(v0, v1));
		return *this;
	}
	vec4& operator-=(const vec4 &v2) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_loadu_ps(v2.e);
		_mm_storeu_ps(this->e, _mm_sub_ps(v0, v1));
		return *this;
	}
	vec4& operator-=(const float &v) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_load_ps1(&v);
		_mm_storeu_ps(this->e, _mm_sub_ps(v0, v1));
		return *this;
	}
	vec4& operator*=(const vec4 &v2) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_loadu_ps(v2.e);
		_mm_storeu_ps(this->e, _mm_mul_ps(v0, v1));
		return *this;
	}
	vec4& operator*=(const float &v) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_load_ps1(&v);
		_mm_storeu_ps(this->e, _mm_mul_ps(v0, v1));
		return *this;
	}
	vec4& operator/=(const vec4 &v2) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_loadu_ps(v2.e);
		_mm_storeu_ps(this->e, _mm_div_ps(v0, v1));
		return *this;
	}
	vec4& operator/=(const float &v) {
		__m128 v0 = _mm_loadu_ps(e);
		__m128 v1 = _mm_load_ps1(&v);
		_mm_storeu_ps(this->e, _mm_div_ps(v0, v1));
		return *this;
	}

	float square_length() const
	{
		__m128 sums = _mm_dp_ps(_mm_loadu_ps(e), _mm_loadu_ps(e), 0xff);
		return _mm_cvtss_f32(sums);
	}

	vec4 unit() const
	{
		float l = length();
		if (abs(l) > 1e-6) {
			__m128 v0 = _mm_loadu_ps(e);
			__m128 v1 = _mm_load_ps1(&l);
			vec4 result;
			_mm_storeu_ps(result.e, _mm_div_ps(v0, v1));
			return std::move(result);
		}
		else {
			return vec4(0.0f);
		}
	}
#else
	vec4& operator+=(const vec4 &v2) { e[0] += v2.x(); e[1] += v2.y();  e[2] += v2.z(); e[3] += v2.w(); return *this; }
	vec4& operator+=(const float &v) { for (int i = 0; i < 4; ++i) { e[i] += v; } return *this; }
	vec4& operator-=(const vec4 &v2) { e[0] -= v2.x(); e[1] -= v2.y();  e[2] -= v2.z(); e[3] -= v2.w(); return *this; }
	vec4& operator-=(const float &v) { for (int i = 0; i < 4; ++i) { e[i] -= v; } return *this; }
	vec4& operator*=(const vec4 &v2) { e[0] *= v2.x(); e[1] *= v2.y();  e[2] *= v2.z(); e[3] *= v2.w(); return *this; }
	vec4& operator*=(const float &v) { for (int i = 0; i < 4; ++i) { e[i] *= v; } return *this; }
	vec4& operator/=(const vec4 &v2) { e[0] /= v2.x(); e[1] /= v2.y();  e[2] /= v2.z(); e[3] /= v2.w(); return *this; }
	vec4& operator/=(const float &v) { for (int i = 0; i < 4; ++i) { e[i] /= v; } return *this; }

	float square_length() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
	}

	vec4 unit() const
	{
		float l = length();
		if (abs(l) > 1e-6) {
			return vec4(this->e[0] / l, this->e[1] / l, this->e[2] / l, this->e[3] / l);
		}
		else {
			return vec4(0.0f);
		}
	}

#endif // SIMD


	vec3 toVec3()const {
		vec3 temp;
		for (int i = 0; i < 3; ++i) {
			temp[i] = e[i];
		}
		return std::move(temp);
	}

	float length() const
	{
		return sqrt(square_length());
	}

};

inline std::istream& operator>>(std::istream &is, vec4 &t)
{
	is >> t.e[0] >> t.e[1] >> t.e[2] >> t.e[3];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, vec4 &t)
{
	os << t.e[0] << t.e[1] << t.e[2] << t.e[3];
	return os;
}

#ifdef SIMD
inline vec4 operator+(vec4 const &e, float const v)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_load_ps1(&v);
	_mm_storeu_ps(result.e, _mm_add_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator+(vec4 const &e, vec4 const &f)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_loadu_ps(f.e);
	_mm_storeu_ps(result.e, _mm_add_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator-(vec4 const &e, float const v)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_load_ps1(&v);
	_mm_storeu_ps(result.e, _mm_sub_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator-(vec4 const &e, vec4 const &f)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_loadu_ps(f.e);
	_mm_storeu_ps(result.e, _mm_sub_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator*(vec4 const &e, float const v)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_load_ps1(&v);	
	_mm_storeu_ps(result.e, _mm_mul_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator*(vec4 const &e, vec4 const &f)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_loadu_ps(f.e);
	_mm_storeu_ps(result.e, _mm_mul_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator*(float const v, vec4 const &e)
{
	vec4 result;
	__m128 v0 = _mm_loadu_ps(e.e);
	__m128 v1 = _mm_load_ps1(&v);
	_mm_storeu_ps(result.e, _mm_mul_ps(v0, v1));
	return std::move(result);
}

inline vec4 operator/(vec4 const &e, float const v)
{
	if (abs(v) > 1e-6) {
		vec4 result;
		__m128 v0 = _mm_loadu_ps(e.e);
		__m128 v1 = _mm_load_ps1(&v);
		_mm_storeu_ps(result.e, _mm_div_ps(v0, v1));
		return std::move(result);
	}
	else {
		return vec4(0.0f);
	}
}

inline float dot(vec4 const &e1, vec4 const &e2)
{
	__m128 sums = _mm_dp_ps(_mm_loadu_ps(e1.e), _mm_loadu_ps(e2.e), 0xff);
	return _mm_cvtss_f32(sums);
}

#else
inline vec4 operator+(vec4 const &e, float const v)
{
	return vec4(e.x() + v, e.y() + v, e.z() + v, e.w() + v);
}

inline vec4 operator+(vec4 const &e, vec4 const &f)
{
	return vec4(e.x() + f.x(), e.y() + f.y(), e.z() + f.z(), e.w() + f.w());
}

inline vec4 operator-(vec4 const &e, float const v)
{
	return vec4(e.x() - v, e.y() - v, e.z() - v, e.w() - v);
}

inline vec4 operator-(vec4 const &e, vec4 const &f)
{
	return vec4(e.x() - f.x(), e.y() - f.y(), e.z() - f.z(), e.w() - f.w());
}

inline vec4 operator*(vec4 const &e, float const v)
{
	return vec4(e.x() * v, e.y() * v, e.z() * v, e.w() * v);
}

inline vec4 operator*(vec4 const &e, vec4 const &f)
{
	return vec4(e.x() * f.x(), e.y() * f.y(), e.z() * f.z(), e.w() * f.w());
}

inline vec4 operator*(float const v, vec4 const &e)
{
	return vec4(e.x() * v, e.y() * v, e.z() * v, e.w()*v);
}

inline vec4 operator/(vec4 const &e, float const v)
{
	if (abs(v) > 1e-6) return (vec4(e[0] / v, e[1] / v, e[2] / v, e[3] / v));
}

inline float dot(vec4 const &e1, vec4 const &e2)
{
	return (e1.e[0] * e2.e[0] + e1.e[1] * e2.e[1] + e1.e[2] * e2.e[2] + e1.e[3] * e2.e[3]);
}
#endif // SIMD


#endif // !VEC4



#ifndef MATRIX
#define MARTIX

bool gauss_jordan(float *a, int n) {
	//d用于全选主元过程
	//t用于存储各种临时数据
	float d, t;
	//i用于遍历时的行号
	//j用于遍历时的列号
	//p，q用于存储标号
	//js用于存储全选主元元素的行号
	//k用于表示第几次操作
	int i, j, p, q, k;
	int *js = new int[n];
	int *is = new int[n];
	int two_width = n * 2;
	float *c = new float[two_width*n];
	//构造增广矩阵

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			c[i * two_width + j] = a[i*n + j];
		}

		for (j = n; j < two_width; ++j) {
			if (j - n == i) { c[i * two_width + j] = 1; }
			else { c[i * two_width + j] = 0; }
		}
	}

	//消元过程
	for (k = 0; k < n; ++k) {
		//全选主元
		d = 0.0;
		for (i = k; i < n; ++i) {
			for (j = k; j < n; ++j) {
				t = c[i * two_width + j];
				if (fabs(t) > d) {
					d = fabs(t);
					js[k] = j;//记录列变换操作
					is[k] = i;//记录行号
				}
			}
		}

		//如果全0则奇异矩阵，无法计算		
		if (fabs(d) < 1e-6) {
			delete[] is;
			delete[] js;
			delete[] c;
			return false;
		}

		//行交换
		if (is[k] != k) {
			for (j = 0; j < two_width; ++j) {
				p = k * two_width + j;
				q = is[k] * two_width + j;
				t = c[p];
				c[p] = c[q]; c[q] = t;
			}
		}
		//列交换
		if (js[k] != k) {
			for (i = 0; i < n; ++i) {
				p = i * two_width + k;
				q = i * two_width + js[k];
				t = c[p]; c[p] = c[q]; c[q] = t;
			}
		}
		//归一化
		{
			d = c[k*two_width + k];
			for (j = k + 1; j < two_width; ++j) {
				p = k * two_width + j;
				c[p] = c[p] / d;
			}
		}
		//消元
		for (i = 0; i < n; ++i) {
			if (i != k) {
				for (j = k + 1; j < two_width; ++j) {
					p = i * two_width + j;
					q = i * two_width + k;
					c[p] = c[p] - c[q] * c[k * two_width + j];
				}
			}
		}
	}
	//恢复
	for (k = n - 1; k >= 0; --k) {
		for (j = 0; j < two_width; ++j) {//换列 : 其实是在换行
			t = c[k * two_width + j];
			c[k * two_width + j] = c[js[k] * two_width + j];
			c[js[k] * two_width + j] = t;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i * n + j] = c[i * two_width + j + n];
		}
	}
	//结束收工
	delete[] is;
	delete[] js;
	delete[] c;
	return true;

}


class Matrix3x3 {
public:
	float e[3][3];
	int width = 3;
	Matrix3x3() {}
	Matrix3x3(float **in) {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < width; ++j) {
				*(*(e + j) + i) = *(*(in + j) + i);
			}
		}
	}
	Matrix3x3(const Matrix3x3 &in) {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < width; ++j) {
				*(*(e + j) + i) = *(*(in.e + j) + i);
			}
		}
	}
	Matrix3x3 mat_mult(const Matrix3x3 &b) const {
		Matrix3x3 temp;
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < width; ++j) {
				temp.e[i][j] = 0;
				for (int k = 0; k < width; ++k) {
					temp.e[i][j] += e[i][k] * b.e[k][j];
				}
			}
		}
		return std::move(temp);
	}
	void LUdecomp(Matrix3x3 &L, Matrix3x3 &U) {
		//Matrix3x3 L, U;
		for (int r = 0; r < 3; ++r) {
			for (int i = r; i < 3; ++i) {
				U.e[r][i] = e[r][i];
				L.e[i][r] = e[i][r];
				L.e[r][i] = 0;
				U.e[i][r] = 0;
				for (int k = 0; k < r; ++k) {
					U.e[r][i] -= L.e[r][k] * U.e[k][i];
					L.e[i][r] -= L.e[i][k] * U.e[k][r];
				}
				L.e[i][r] /= U.e[r][r];
			}
		}
	}

	Matrix3x3 inverse() {
		Matrix3x3 L, U;
		LUdecomp(L, U);

		Matrix3x3 L_inv(L);
		L_inv.e[1][0] *= -1;
		L_inv.e[2][1] *= -1;
		L_inv.e[2][1] = L.e[1][0] * L.e[2][1] - L.e[2][1];

		Matrix3x3 U_inv(U);
		for (int i = 0; i < width; ++i) {
			for (int j = i; j < width; ++j) {
				U_inv.e[i][j] /= U.e[i][i];
			}
		}
		U_inv.e[0][1] *= -1;
		U_inv.e[1][2] *= -1;
		U_inv.e[0][2] = U_inv.e[0][1] * U_inv.e[1][2] - U_inv.e[0][2];

		return std::move(U_inv.mat_mult(L_inv));
	}
};

Matrix3x3 mat_mult(const Matrix3x3 &a, const Matrix3x3 &b) {
	Matrix3x3 temp;
	temp = a.mat_mult(b);
	return std::move(temp);
}


class Matrix4x4 {
public:
	float e[4][4];
	static const int width = 4;

#ifdef SIMD
	Matrix4x4() {
		for (int i = 0; i < 4; ++i) {
			_mm_storeu_ps(e[i], _mm_setzero_ps());
		}
	}
	Matrix4x4(float *in) {
		for (int i = 0; i < 4; ++i) {
			_mm_storeu_ps(e[i], _mm_loadu_ps(in + 4 * i));
		}
	}
	Matrix4x4(const Matrix4x4 &in) {
		for (int i = 0; i < 4; ++i) {
			_mm_storeu_ps(e[i], _mm_loadu_ps(in.e[i]));
		}
	}
	Matrix4x4(float val) {
		__m128 data = _mm_load_ps1(&val);
		for (int i = 0; i < 4; ++i) {
			_mm_storeu_ps(e[i], data);
		}
	}
	Matrix4x4(const vec4 &l0, const vec4 &l1, const vec4 &l2, const vec4 &l3) {
		_mm_storeu_ps(e[0], _mm_loadu_ps(l0.e));
		_mm_storeu_ps(e[1], _mm_loadu_ps(l1.e));
		_mm_storeu_ps(e[2], _mm_loadu_ps(l2.e));
		_mm_storeu_ps(e[3], _mm_loadu_ps(l3.e));
	}

	vec4 mul_vec(const vec4 &in) {
		vec4 temp;
		__m128 vec = _mm_loadu_ps(in.e);

		for (int i = 0; i < width; ++i) {
			__m128 sums = _mm_dp_ps(vec, _mm_loadu_ps(e[i]), 0xff);
			temp[i] = _mm_cvtss_f32(sums);
		}
		return std::move(temp);
	}

#else
	Matrix4x4() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				e[i][j] = 0.f;
			}
		}
	}
	Matrix4x4(float *in) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				*(*(e + j) + i) = *(in + 4 * j + i);
			}
		}
	}
	Matrix4x4(const Matrix4x4 &in) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				*(*(e + j) + i) = *(*(in.e + j) + i);
			}
		}
	}
	Matrix4x4(float val) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				*(*(e + j) + i) = val;
			}
		}
	}
	Matrix4x4(const vec4 &l0, const vec4 &l1, const vec4 &l2, const vec4 &l3) {
		for (int i = 0; i < width; ++i) {
			e[0][i] = l0[i];
			e[1][i] = l1[i];
			e[2][i] = l2[i];
			e[3][i] = l3[i];
		}
	}

	vec4 mul_vec(const vec4 &in) {
		vec4 temp;
		for (int i = 0; i < width; ++i) {
			temp.e[i] = 0;
			for (int m = 0; m < width; ++m) {
				temp.e[i] += e[i][m] * in.e[m];
			}
		}
		return std::move(temp);
	}
#endif // SIMD


	Matrix4x4 tranpose() {
		Matrix4x4 temp;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				*(*(temp.e + j) + i) = *(*(this->e + i) + j);
			}
		}
		return std::move(temp);
	}

	Matrix4x4 mat_mult(const Matrix4x4 &b) {
		Matrix4x4 temp(0.0f);
		for (int i = 0; i < width; ++i) {
			for (int k = 0; k < width; ++k) {
				for (int j = 0; j < width; ++j) {
					temp.e[i][j] += e[i][k] * b.e[k][j];
				}
			}
		}
		return std::move(temp);
	}

	void LUdecomp(Matrix4x4 &L, Matrix4x4 &U) {
		//Matrix4x4 L, U;
		for (int r = 0; r < width; ++r) {
			for (int i = r; i < width; ++i) {
				U.e[r][i] = e[r][i];
				L.e[i][r] = e[i][r];
				L.e[r][i] = 0;
				U.e[i][r] = 0;
				for (int k = 0; k < r; ++k) {
					U.e[r][i] -= L.e[r][k] * U.e[k][i];
					L.e[i][r] -= L.e[i][k] * U.e[k][r];
				}
				L.e[i][r] /= U.e[r][r];
			}
		}
	}

	Matrix4x4 inverse() {//待改
						 //Matrix4x4 t(*this);
		float temp[16];
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < width; ++j) {
				temp[i * 4 + j] = this->e[i][j];
			}
		}
		Matrix4x4 t;
		if (gauss_jordan(temp, width)) {
			for (int i = 0; i < width; ++i) {
				for (int j = 0; j < width; ++j) {
					t.e[i][j] = temp[i * 4 + j];
				}
			}
		}
		else {
			t = *this;
		}


		return t;
	}

};
#ifdef SIMD
Matrix4x4 operator+(const Matrix4x4 &a, const Matrix4x4 &b) {
	Matrix4x4 t(a);
	for (int i = 0; i < 4; ++i) {
		__m128 m0 = _mm_loadu_ps(t.e[i]);
		__m128 m1 = _mm_loadu_ps(b.e[i]);
		_mm_storeu_ps(t.e[i], _mm_add_ps(m0, m1));
	}
	return std::move(t);
}

#else
Matrix4x4 operator+(const Matrix4x4 &a, const Matrix4x4 &b) {
	Matrix4x4 t(a);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(*(t.e + i) + j) += *(*(b.e + i) + j);
		}
	}
	return std::move(t);
}
#endif // SIMD




Matrix4x4 identityMatrix4x4() {
	Matrix4x4 temp(0.f);
	for (int i = 0; i < 4; ++i) {
		temp.e[i][i] = 1.f;
	}
	return temp;
}

void matTranslate(Matrix4x4 &mat, const vec3 &offset) {
	Matrix4x4 t = identityMatrix4x4();
	for (int i = 0; i < 3; ++i) {
		t.e[i][3] += offset[i];
	}
	mat = t.mat_mult(mat);
}

void matRotate(Matrix4x4 &mat, float theta, const vec3 &axis) {
	theta = theta * M_PI / 180.;
	float cos_theta = cos(theta), sin_theta = sin(theta);
	float one_minus_cos = 1.f - cos_theta;
	vec3 u = axis.unit();
	float u_pow[3] = { u.x()*u.x(), u.y()*u.y(), u.z()*u.z() };
	float u_xy = u.x()*u.y(), u_xz = u.x()*u.z(), u_yz = u.y()*u.z();

	Matrix4x4 t = identityMatrix4x4();
	for (int i = 0; i < 3; ++i) {
		t.e[i][i] = u_pow[i] * one_minus_cos + cos_theta;
	}
	t.e[0][1] = u_xy * one_minus_cos - u.z()*sin_theta; t.e[0][2] = u_xz * one_minus_cos + u.y()*sin_theta;
	t.e[1][0] = u_xy * one_minus_cos + u.z()*sin_theta; t.e[1][2] = u_yz * one_minus_cos - u.x()*sin_theta;
	t.e[2][0] = u_xz * one_minus_cos - u.y()*sin_theta; t.e[2][1] = u_yz * one_minus_cos + u.x()*sin_theta;

	Matrix4x4 traslate = identityMatrix4x4(), traslate_inv = identityMatrix4x4();
	matTranslate(traslate, axis);
	matTranslate(traslate_inv, -axis);
	mat = traslate.mat_mult(mat);
	mat = t.mat_mult(mat);
	mat = traslate_inv.mat_mult(mat);
}

void matScale(Matrix4x4 &mat, const vec3 &scale) {
	Matrix4x4 t = identityMatrix4x4();
	for (int i = 0; i < 3; ++i) {
		t.e[i][i] *= scale[i];
	}
	mat = t.mat_mult(mat);
}

#ifdef SIMD
void applyTrans(Matrix4x4 & model_matrix, std::vector<vec4> &pointArray) {
	__m128 data[4];
	for (int j = 0; j < 4; ++j) {
		data[j] = _mm_loadu_ps(model_matrix.e[j]);
	}
	const unsigned int data_size = pointArray.size();
	for (int i = 0; i < data_size; ++i) {
		__m128 vec = _mm_loadu_ps(pointArray[i].e);
		for (int j = 0; j < 4; ++j) {
			__m128 sums = _mm_dp_ps(data[j], vec, 0xff);
			pointArray[i][j] = _mm_cvtss_f32(sums);
		}
	}
}
#else
void applyTrans(Matrix4x4 & model_matrix, std::vector<vec4> &pointArray) {
	const unsigned int data_size = pointArray.size();
	for (int i = 0; i < data_size; ++i) {
		pointArray[i] = model_matrix.mul_vec(pointArray[i]);
	}
}
#endif // SIMD


#endif // !MATRIX


