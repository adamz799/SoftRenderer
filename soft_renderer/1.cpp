#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "head.h"
#include "Object.h"
#include "Camera.h"
#include "Material.h"

int nx = 1040, ny = 650;
int ns = 800;

vec3 color(const ray& r, HitableObj *world, int depth)
{
	hit_record rec;
	if (world->hit(r, 1e-5, 1e6, rec))
	{
		ray scattered;
		vec3 attenuation;
		if (depth < 20 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
		{
			return attenuation * color(scattered, world, depth + 1);
		}
		else
		{
			return vec3(0., 0., 0.);
		}
	}
	else
	{
		vec3 dir = r.direction().unit();
		float t = 0.5*(dir.y() + 1.0);
		return (1. - t)*vec3(1., 1., 1.) + t * vec3(0.5, 0.7, 1.);
	}
}

HitableList *random_scene()
{
	int n = 500;
	HitableObj **list = new HitableObj*[n + 1];

	list[0] = new Sphere(vec3(0., -1000, 0.), 1000, new Lambertian(vec3(0.75, 0.75, 0.75)));
	int i = 1;
	for (int a = -11; a < 11; ++a)
	{
		for (int b = -11; b < 11; ++b)
		{
			float choose_mat = randf();
			vec3 center(a + 0.9*randf(), 0.2, b + randf()*0.9);
			if ((center - vec3(4., 0., 2.)).length() > 0.9)
			{
				if (choose_mat < 0.75)
				{
					list[i++] = new Sphere(center, 0.2, new Lambertian(vec3(randf(), randf(), randf())));
				}
				else if (choose_mat < 0.875)
				{
					list[i++] = new Sphere(center, 0.2, new Metal(0.5*(vec3(randf(), randf(), randf())+1.), 0.5*randf()));
				}
				else
				{
					list[i++] = new Sphere(center, 0.2, new Dielectric(randf()*0.8+1.2));
				}
			}
		}
		
	}
	list[i++] = new Sphere(vec3(0., 1., 0.), 1., new Dielectric(1.5));
	list[i++] = new Sphere(vec3(-4, 1., 0.), 1., new Lambertian(vec3(0.4, 0.6, 0.3)));
	list[i++] = new Sphere(vec3(4, 1., 0.), 1., new Metal(vec3(0.9, 0.7, 0.55), 0.));

	return new HitableList(list, i);
}


int main()
{
	srand(static_cast <unsigned> (time(0)));
	FILE *f = fopen("output3.ppm", "w");
	fprintf(f, "P3\n%d %d\n255\n", nx, ny);
	//std::cout << "P3\n" << nx << " " << ny << "\n255\n";

	HitableList *world = random_scene();

	
	vec3 ori = vec3(65.,3.3,11.);
	vec3 look_at = vec3(2., 1., 0.35);
	vec3 up = vec3(0., 1., 0.);
	float focus_distance = (look_at - ori).length();
	//Camera init_camera(ori, look_at,up, 90., float(nx) / float(ny));
	FocusCamera init_camera(ori,look_at ,up , 130., float(nx) / float(ny), 0.5, focus_distance);
	for (int j = ny - 1; j >= 0; --j)
	{
		/*time_t start, stop;
		start = time(NULL);*/
		for (int i = 0; i < nx; ++i)
		{
			vec3 col(0., 0., 0.);
					
			for (int k = 0; k < ns; ++k)
			{
				float delta_i = randf();
				float delta_j = randf();
				float u = float(i + delta_i) / float(nx) * 2 - 1.;
				float v = float(j + delta_j) / float(ny) * 2 - 1.;

				ray r = init_camera.get_ray(u, v);
				col += (color(r, world, 0)-col)/(k+1);
			}
			//col /= float(ns);
			
			int ir = int(255.99*col.r());
			int ig = int(255.99*col.g());
			int ib = int(255.99*col.b());
			printf("x:%d y:%d \n", i, j);
			fprintf(f, "%d %d %d\n", ir, ig, ib);
			//stop = time(NULL);
			//printf("Use Time:%ld\n", (stop - start));
			//std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	fclose(f);
	//system("pause");
	return 0;
}