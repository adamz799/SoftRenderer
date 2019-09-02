#pragma once

#ifndef BUFFER
#define BUFFER
#include "head.h"

class Buffer {
public:
	Color *ptr;//RGB in float
	int width, height;
	Color operator[](int i) const { return ptr[i]; }
	Color& operator[](int i) { return ptr[i]; }
	
	Buffer(int _width, int _height) {
		ptr = NULL;
		try {
			ptr = new Color[_width*_height];
		}
		catch (std::bad_alloc) {
			std::cout << "Bad alloc: memory alloc failed!" << std::endl;
			ptr = NULL;
			
		}
		if (ptr) {
			memset(ptr, 0, sizeof(Color)*_width*_height);
			width = _width;
			height = _height;
		}
	}

	void resize(int _width, int _height) {
		Color *temp = ptr;
		try {
			ptr = new Color[_width*_height];
		}
		catch (std::bad_alloc) {
			std::cout << "Bad alloc: resize failed!" << std::endl;
			ptr = temp;
			return;
		}
		if (!ptr) {
			ptr = temp;
		}
		else {
			memset(ptr, 0, sizeof(Color)*_width*_height);
			width = _width;
			height = _height;
			delete[] temp;
		}
	}

	~Buffer() {
		memset(ptr, 0, sizeof(Color)*width*height);
		delete[] ptr;
		ptr = NULL;
	}

	void clear(float v) {
		int *t = (int *)&v;
		memset(ptr, *t, sizeof(Color)*width*height);
	}
};

class DepthBuffer {
public:
	float * ptr;//Depth in float
	int width, height;
	float operator[](int i) const { return ptr[i]; }
	float& operator[](int i) { return ptr[i]; }

	DepthBuffer() { ptr = NULL; width = height = -1; }
	DepthBuffer(int _width, int _height) {
		ptr = NULL;
		try {
			ptr = new float[_width*_height];
		}
		catch (std::bad_alloc) {
			std::cout << "Bad alloc: memory alloc failed!" << std::endl;
			ptr = NULL;

		}
		if (ptr) {
			std::fill(ptr, ptr+_width*_height, -2.f);
			//memset(ptr, 0, sizeof(float)*_width*_height);
			width = _width;
			height = _height;
		}
	}

	void resize(int _width, int _height) {
		float *temp = ptr;
		try {
			ptr = new float[_width*_height];
		}
		catch (std::bad_alloc) {
			std::cout << "Bad alloc: resize failed!" << std::endl;
			ptr = temp;
			return;
		}
		if (!ptr) {
			ptr = temp;
		}
		else {
			std::fill(ptr, ptr + _width * _height, -2.f);
			width = _width;
			height = _height;
			delete[] temp;
		}
	}

	~DepthBuffer() {
		
		memset(ptr, 0, sizeof(float)*width*height);
		delete[] ptr;
		ptr = NULL;
	}

	void clear(float v) {
		std::fill(ptr, ptr + width * height, v);
	}
};


class Texture {
public:
	int width, height, nrChannels;
	std::string fileName;
	std::vector<vec4> _data;


	Texture() {}
	Texture(const char* path){
		getTexture(path);
		fileName = path;
	}
	/*~Texture() {
		delete _data;
	}*/
	vec4 sample(float u, float v, int mode) {
		unsigned int x, y;
		while (u < 0.f) { u += 1.f; }
		while (u > 1.f) { u -= 1.f; }
		while (v < 0.f) { v += 1.f; }
		while (v > 1.f) { v -= 1.f; }
		u *= (width - 1);
		v *= (height - 1);
		float next_u = u - floor(u), next_v = v - floor(v);
		float current_u = 1.f - next_u, current_v = 1.f - next_v;

		x = static_cast<int>(u);
		y = static_cast<int>(v);
		if (x == width - 1 || y == height - 1) {
			return (_data)[y*width + x];
		}
		else {
			return current_u * current_v*(_data)[y*width + x]
				+ current_u * next_v*(_data)[(y + 1)*width + x]
				+ next_u * current_v*(_data)[y*width + x + 1]
				+ next_u * next_v*(_data)[(y + 1)*width + x + 1];
		}		
	}

private:
	void getTexture(const char* name) {
		stbi_set_flip_vertically_on_load(true);
		
		unsigned char *image = NULL;
		image = stbi_load(name, &width, &height, &nrChannels, 0);

		if (image == NULL) {
			std::cout << name << "\nError: Texture load failed!" << std::endl;
			return;
		}

		/*if (_data != NULL) {
			delete _data;
		}*/
		_data = std::vector<vec4>(width*height);
		

		unsigned char *char_input;
		int width_temp = width * 4;
		for (int x = 0; x < width; ++x) {
			for (int y = 0; y < height; ++y) {
				int offset = y * width + x;
				char_input = image + nrChannels * offset;
				for (int c = 0; c < nrChannels; ++c) {
					(_data)[offset][c] = static_cast<float>(*(char_input+c))/ 255.f;
				}
				if (nrChannels < 4) {
					(_data)[offset][3] = 1.f;
				}
			}
		}

		stbi_image_free(image);
	}
};

#endif // !BUFFER

