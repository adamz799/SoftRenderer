#pragma once

#ifndef VERTEX
#define VERTEX

#include "head.h"
#include <string>
#include <iostream>
#include "vec.h"

class VertexData {
public:

	std::vector<vec4> positions;
	std::vector<vec4> normals;
	std::vector<vec4> colors;	
	std::vector<vec4> fragPosInWorlds;
	std::vector<vec4> tangents;
	std::vector<vec4> bitTangents;
	std::vector<vec4> tangentLightPos;
	std::vector<vec4> tangentViewPos;
	std::vector<vec2> texCoords;


	std::vector<vec4>* attribute[100];
	std::string attributeName[100];
	int attributeCount = 0;

	VertexData() {
		attributeCount = 0;
	}
	VertexData(const float *vertexs, int dataAmount, int dataLength, int offset , int pointLength) {
		attributeCount = 0;
		setData(positions, vertexs, dataAmount, dataLength, offset, pointLength, 4);
		addAvailbleAttribute(positions, "positions");
	}

	void setNormal(const float *vertexs, int dataAmount, int dataLength, int offset, int pointLength) {
		setData(normals, vertexs, dataAmount, dataLength, offset, pointLength, 4);
		addAvailbleAttribute(normals, "normals");
	}

	void setTexCoords(const float *vertexs, int dataAmount, int dataLength, int offset, int pointLength) {
		setData(texCoords, vertexs, dataAmount, dataLength, offset, pointLength, 2);
	}
	void setColor(const float *vertexs, int dataAmount, int dataLength, int offset, int pointLength) {
		setData(colors, vertexs, dataAmount, dataLength, offset, pointLength, 3);
		addAvailbleAttribute(colors, "colors");
	}

	void setTBN(const std::vector<int> &indices) {
		tangents = std::vector<vec4>(positions.size());
		bitTangents = std::vector<vec4>(positions.size());
		for (int i = 2; i < indices.size(); i+=3) {
			vec4 v0 = positions[indices[i - 2]],
				v1 = positions[indices[i - 1]],
				v2 = positions[indices[i]];
			vec3 edge1 = (v1 - v0).toVec3(), edge2 = (v2 - v0).toVec3();
			vec2 deltaUV1 = texCoords[i - 1] - texCoords[i - 2], deltaUV2 = texCoords[i] - texCoords[i - 2];
			vec4 tang, bitTang;
			float delta = deltaUV1.x()*deltaUV2.y() - deltaUV2.x()*deltaUV1.y();
			if (abs(delta) < 1e-6) { 
				std::cout << "Calculate TBN failed." << std::endl; 
				return; 
			}
			else {
				delta = 1.f / delta;
				tang = vec4(delta * (deltaUV2.y()*edge1 - deltaUV1.y()*edge2),0.f).unit();
				bitTang = vec4(delta * (deltaUV1.x()*edge2 - deltaUV2.x()*edge1), 0.f).unit();
				for (int j = 0; j < 3; ++j) {
					tangents[indices[i - j]] = tang;
					bitTangents[indices[i - j]] = bitTang;
				}
			}
		}
		addAvailbleAttribute(tangents, "tangents");
		addAvailbleAttribute(bitTangents, "bitTangents");
		return;
	}

	int addAvailbleAttribute(std::vector<vec4> &attri,  const char* name) {
		attributeName[attributeCount] = std::string(name);
		attribute[attributeCount++] = &attri;
		return attributeCount;
	}

private:

	/*void defaultConstruct() {
		positions= std::vector<vec4>(1);
		normals = std::vector<vec4>(1);
		colors = std::vector<vec4>(1);
		fragPosInWorlds = std::vector<vec4>(1);
		tangents = std::vector<vec4>(1);
		bitTangents = std::vector<vec4>(1);
		tangentLightPos = std::vector<vec4>(1);
		tangentViewPos = std::vector<vec4>(1);
		texCoords = std::vector<vec2>(1);
	}*/


	template <typename T>
	void setData(std::vector<T> &dataContainer, const float *vertexs, int dataAmount, int dataLength, int offset, int pointLength, int selfDataLength) {
		dataContainer = std::vector<T>(dataAmount);
		for (int i = 0; i < dataAmount; ++i) {
			for (int j = 0; j < pointLength; ++j) {
				dataContainer[i][j] = vertexs[i*dataLength + offset + j];
			}
			for (int j = pointLength; j < dataContainer[i].size(); ++j) {
				dataContainer[i][j] = 1.0f;
			}
		}
	}
};



#endif // !VERTEX