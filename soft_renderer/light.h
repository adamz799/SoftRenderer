#pragma once
#ifndef LIGHT
#define LIGHT
#include "head.h"



class PointLight {
public:
	vec4 pos;
	vec3 color;

	PointLight(){}
	PointLight(const vec3 &p,const vec3 &c) {
		pos = vec4(p, 1.f);
		color = c;
	}

};


#endif // !LIGHT
