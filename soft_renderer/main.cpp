#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <io.h>
#include <fcntl.h>
#include "head.h"
#include "shader.h"
#include "device.h"
#include "vertex.h"
#include "model.h"

int width = 800;
int height = 600;
Camera camera;
float z_near = 0.1f, z_far = 100.f;
bool quit = false;
int lastX = -1, lastY = -1;
bool leftMouseDown = false;

struct p
{
	int x, y;
};
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	
	//struct p p1[] = { 1,2,3,4,5,6 };
	switch (msg)
	{
	case WM_CLOSE:{
		PostQuitMessage(0);
		break;
	}
	case WM_KEYDOWN:{
		switch (wparam) {
		case 'S':{
			vec3 dir = camera.N;
			camera.origin -= dir*0.1f;
			camera.look_at -= dir*0.1f;
			camera.update();
			break;
		}
		case 'W': {
			vec3 dir = camera.N;
			camera.origin += dir * 0.1f;
			camera.look_at += dir * 0.1f;
			camera.update();
			break;
		}
		case 'A': {
			vec3 dir = camera.U;
			camera.origin -= dir * 0.1f;
			camera.look_at -= dir * 0.1f;
			camera.update();
			break;
		}
		case 'D': {
			vec3 dir = camera.U;
			camera.origin += dir * 0.1f;
			camera.look_at += dir * 0.1f;
			camera.update();
			break;
		}
		default: {
			break;
		}
		}

		

		break;
	}
	case WM_MOUSEMOVE: {
		//printf("move: %d\n", leftMouseDown);
		if (leftMouseDown) {		
			int x = (int)LOWORD(lparam);
			int y = (int)HIWORD(lparam);
			if (lastX != -1 && lastY != -1) {
				if (x == lastX && y == lastY) { break; }
				float sensitivity = 0.03f;
				float xoffset = (x - lastX) * sensitivity;
				float yoffset = (lastY - y) * sensitivity;
				float rotateAmount = sqrt(xoffset*xoffset + yoffset * yoffset);

				vec4 rotateAxis = vec4(-yoffset / rotateAmount, xoffset / rotateAmount, 0.f, 0.f).unit();
				/*printf("offset: %f,%f", xoffset / rotateAmount, yoffset / rotateAmount);
				printf("axis: %f,%f,%f\n", rotateAxis[0], rotateAxis[1], rotateAxis[2]);*/
				Matrix4x4 view = calViewMatrix(camera);
				rotateAxis = view.inverse().mul_vec(rotateAxis);

				Matrix4x4 rotateMat = identityMatrix4x4();
				vec3 axis = rotateAxis.toVec3().unit();
				matRotate(rotateMat, rotateAmount, axis);
				//printf("axis: %f,%f,%f\n", axis[0], axis[1], axis[2]);

				vec4 cameraPos((camera.origin - camera.look_at), 1.f);
				cameraPos = rotateMat.mul_vec(cameraPos);
				camera.origin = cameraPos.toVec3() + camera.look_at;
				camera.update();
			}
			lastX = x;
			lastY = y;
		}
		break;
	}
	case WM_LBUTTONDOWN: {
		leftMouseDown = true;
		//printf("down: %d\n", leftMouseDown);
		break;
	}
	case WM_LBUTTONUP: {
		leftMouseDown = false;
		lastX = -1;
		lastY = -1;
		//printf("up: %d\n", leftMouseDown);
		break;
	}
						 
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void writeToPPM(const Buffer &buffer) {
	FILE *f = fopen("SR.ppm", "w");
	fprintf(f, "P3\n%d %d\n255\n", width, height);

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			Color *p = buffer.ptr + width * j + i;
			int ir = int(p->R);
			int ig = int(p->G);
			int ib = int(p->B);
			//printf("x:%d y:%d \n", i, j);
			fprintf(f, "%d %d %d\n", ir, ig, ib);
		}
	}
	fclose(f);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow)
{
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	freopen("CONIN$", "r+t", stdin);
	//printf("11111");
	
	MSG msg;
	Device device(hinstance, width, height);
	ShowWindow(device.hwnd, SW_SHOW);
	UpdateWindow(device.hwnd);

	float vertices[] = {
		// pos					//normal			//color				//uv
		-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f, // bottom-left
		0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,  // bottom-right
		0.5f, 0.5f, -0.5f,   0.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,  // top-right
		0.5f, 0.5f, -0.5f,   0.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // top-right
		-0.5f, 0.5f, -0.5f,   0.0f, 0.0f, -1.0f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,  // top-left
		-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f,  // bottom-left	
	};

	int dataLength = 11;
	int pointAmount = sizeof(vertices) / (dataLength * sizeof(float));

	VertexData data(vertices, pointAmount, dataLength, 0, 3);
	data.setColor(vertices, pointAmount, dataLength, 6, 3);
	data.setNormal(vertices, pointAmount, dataLength, 3, 3);
	data.setTexCoords(vertices, pointAmount, dataLength, 9, 2);

	std::vector<int> indices(pointAmount);
	for (int i = 0; i < pointAmount; ++i) {
		indices[i] = i;
	}
	data.setTBN(indices);

	

	Shader shader;

	vec3 ori(0, 0.0, -4), look_at(0, 0, 0), vup(0, 1, 0);
	float v_fov = 60., aspect = float(width) / float(height);
	camera = Camera(ori, look_at, vup, v_fov, aspect);
	shader.setVPMatrix(camera, z_near, z_far);

	Buffer buffer(width, height);
	buffer.clear(0.35f);
	shader.setBuffer(buffer);

	DepthBuffer depthBuffer(width, height);
	depthBuffer.clear(2.f);
	shader.setDepthBuffer(depthBuffer);

	Texture texture("bricks2.jpg")
		, texture_normal("bricks2_normal.jpg")
		, texture_disp("bricks2_disp.jpg");
	shader.textureList.push_back(texture);
	shader.textureList.push_back(texture_normal);
	shader.textureList.push_back(texture_disp);


	//PointLight defualtLight(vec3(1.8f, 0.f, 0.5f), 0.7*vec3(0.8f, 0.65f, 0.4f));
	PointLight defualtLight1(vec3(-1.8f, 0.f, 0.2f), 0.7*vec3(0.8f, 0.65f, 0.4f));
	//fs.lightList.push_back(defualtLight);
	shader.lightList.push_back(defualtLight1);

	
	shader.setVPMatrix(camera, -0.5f, 11.f);
	shader.test_mode = TEST_COLOR;
	Matrix4x4 model = identityMatrix4x4();
	matScale(model, vec3(3.2f));
	matRotate(model, -65.f, vec3(0, 1, 0));
	matTranslate(model, vec3(-3, 0, -0.1));
	shader.setModelMatrix(model);
	shader.use(data, indices);//draw to buffer

	Color c = { 255.f,255.f,255.f };
	for (int i = 2; i < shader.indices.size(); i += 3) {
		if (shader.indices[i - 2] < 0) { continue; }
		coord v0 = shader.screenPos[shader.indices[i - 2]];
		coord v1 = shader.screenPos[shader.indices[i - 1]];
		coord v2 = shader.screenPos[shader.indices[i]];
		drawLine(buffer, v0.x, v0.y, v1.x, v1.y, c);
		drawLine(buffer, v1.x, v1.y, v2.x, v2.y, c);
		drawLine(buffer, v0.x, v0.y, v2.x, v2.y, c);
	}
	device.draw(buffer);


	model = identityMatrix4x4();
	matScale(model, vec3(3.2f));
	matRotate(model, 65.f, vec3(0.f, 1.f, 0.f));
	matTranslate(model, vec3(3.f, 0.f, -0.1f));
	shader.setModelMatrix(model);
	shader.test_mode = TEST_LIGHT;
	shader.use(data, indices);
	device.draw(buffer);

	model = identityMatrix4x4();
	matTranslate(model, vec3(0, -7.8, -100));
	matScale(model, vec3(0.035f));
	//matRotate(model, 180.f, vec3(0, 1, 0));
	
	shader.setModelMatrix(model);
	shader.test_mode = TEST_TEXTURE;

	Model nanosuit("nanosuit/nanosuit.obj");
	nanosuit.draw(shader);

	shader.test_mode = TEST_COLOR;
	model = identityMatrix4x4();
	matScale(model, vec3(3.2f));
	matRotate(model, -65.f, vec3(0, 1, 0));
	matTranslate(model, vec3(-3, 0, -0.1));
	shader.setModelMatrix(model);
	shader.use(data, indices);//draw to buffer
	c = { 255.f,255.f,255.f };
	for (int i = 2; i < shader.indices.size(); i += 3) {
		if (shader.indices[i - 2] < 0) { continue; }
		coord v0 = shader.screenPos[shader.indices[i - 2]];
		coord v1 = shader.screenPos[shader.indices[i - 1]];
		coord v2 = shader.screenPos[shader.indices[i]];
		drawLine(buffer, v0.x, v0.y, v1.x, v1.y, c);
		drawLine(buffer, v1.x, v1.y, v2.x, v2.y, c);
		drawLine(buffer, v0.x, v0.y, v2.x, v2.y, c);
	}
	device.draw(buffer);
	writeToPPM(buffer);
	while (!quit)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				quit = true;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//buffer.clear(0.f);
		//depthBuffer.clear(2.f);
		//shader.setVPMatrix(camera, z_near, z_far);
		//shader.use(data, indices);//draw to buffer
		device.draw(buffer);
	}

	device.release();
	FreeConsole();
	return 0;
}