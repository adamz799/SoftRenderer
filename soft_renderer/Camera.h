#pragma once

#ifndef CAMERA
#define CAMREA
#include "head.h"
#include "vec.h"

class Camera {
public:
	vec3 origin;
	vec3 look_at;
	vec3 up;
	vec3 U;
	vec3 V;
	vec3 N;
	
	float fov;
	float aspect;
	float half_height ;
	float half_width ;

	Camera(){}
	Camera(vec3 &ori, vec3 &look_at_, vec3 &vup,  float v_fov, float aspect_){
		origin = ori;
		look_at = look_at_;
		up = vup;
		fov = v_fov;
		aspect = aspect_;
		update();
	}

	void update() {
		N = (look_at - origin).unit();
		U = cross(N, up).unit();
		V = cross(U, N);

		float theta = fov * M_PI / 180.;
		half_height = tan(theta / 2.);
		half_width = aspect * half_height;
	}
};

#endif // !CAMERA

