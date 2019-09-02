#pragma once

#ifndef UTILS
#define UTILS
#include <math.h>
#include <stdlib.h>
#include "vec.h"
#include "Camera.h"


Matrix4x4 calViewMatrix(Camera &c) {//aspect = width/height;	
	Matrix4x4 view(0.);
	for (int i = 0; i < 3; ++i) {
		view.e[0][i] = c.U[i];
		view.e[1][i] = c.V[i];
		view.e[2][i] = c.N[i];
		view.e[i][3] = -c.origin[i];
	}
	view.e[3][3] = 1;
	return std::move(view);
}

Matrix4x4 calProjectionMatrix(Camera &c, float z_near, float z_far) {

	Matrix4x4 proj(0.f);
	
	proj.e[0][0] = 1. / c.half_width;
	proj.e[1][1] = 1. / c.half_height;
	proj.e[2][2] = 1. / (z_far - z_near);
	proj.e[2][3] = -z_near / (z_far - z_near);
	////nonlinear depth, z=1./z
	//float t =  (1. / z_far - 1. / z_near);
	//proj.e[2][2] = 1. / t;
	//proj.e[2][3] = (-1. / z_near) / t;
	proj.e[3][2] = 1;

	return std::move(proj);

}


inline float randf()
{
	return static_cast<float>(rand() / float(RAND_MAX));
}

inline int maxTri(int a, int b, int c) {
	int t;
	if (a > b) { t = a; }
	else { t = b; }
	if (t > c) { return t; }
	else { return c; }
}

inline int minTri(int a, int b, int c) {
	int t;
	if (a < b) { t = a; }
	else { t = b; }
	if (t < c) { return t; }
	else { return c; }
}

vec3 random_in_unit_disk()
{
	vec3 p;
	do {
		p = 2.*vec3(randf(), randf(), 0.) - vec3(1., 1., 0.);
	} while (dot(p, p) > 1.);
	return p;
}


inline vec3 reflect(const vec3 &in, const vec3 &n)
{
	vec3 normal = n.unit();
	return in - 2.*dot(in, normal)*normal;
}

bool refract(const vec3 &v, const vec3 &n, float ni_over_nt, vec3 & refracted)
{
	vec3 unit_v = v.unit();
	float dt = dot(unit_v, n);
	float dis = 1. - ni_over_nt * ni_over_nt*(1. - dt * dt);
	if (dis > 0)
	{
		refracted = ni_over_nt * (unit_v - n * dt) - n * sqrt(dis);
		return true;
	}
	else
	{
		if (dt < 0)
		{
			refracted = v - 2.*dt*n;
			return true;
		}
		else
		{
			return false;
			//refracted = v + 2.*dt*n;
		}
		return true;
	}
}

float schlick(float cosine, float ref_idx) {
	float r0 = (1. - ref_idx) / (1. + ref_idx);
	r0 *= r0;
	return r0 + (1 - r0)*pow((1. - cosine), 5);
}


#endif // !UTILS

