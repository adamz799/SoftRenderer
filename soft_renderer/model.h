#pragma once

#ifndef MODEL
#define MODEL

#include <vector>
#include <string>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "buffer.h"
#include "vertex.h"
#include <map>
#include "shader.h"

class Mesh {
public:
	VertexData vertexData;
	std::vector<int> indices;
	std::vector<Texture*> textures;
	// 1. diffuse maps
	std::vector<Texture*> diffuseMaps;
	// 2. specular maps
	std::vector<Texture*> specularMaps; 
	// 3. normal maps
	std::vector<Texture*> normalMaps;
	// 4. height maps
	std::vector<Texture*> heightMaps;

	Mesh() = default;

	Mesh(VertexData &v, std::vector<int> &i, std::vector<Texture*> &t) {
		vertexData = v;
		indices = i;
		textures = t;
	}
	void draw(Shader &shader) {
		shader.diffuseMaps= diffuseMaps;
		shader.specularMaps= specularMaps;
		shader.normalMaps= normalMaps;
		shader.heightMaps= heightMaps;
		shader.textureList = textures;
		shader.use(vertexData, indices);
	}

private:
	
};


class Model {
public:
	Model(const std::string &path) { loadModel(path); }
	Model(const char *path) { loadModel(std::string(path)); }
	void draw(Shader &shader) {
		for (unsigned int i = 0; i < meshes.size(); ++i) {
			meshes[i].draw(shader);
		}
	}
private:
	std::vector<Mesh> meshes;
	std::string directory;
	//std::vector<Texture> textures_loaded;
	std::map<std::string, Texture> loadedTexture;

	void loadModel(const std::string &path) {
		Assimp::Importer importer;
		const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
		if (!scene || scene->mFlags&AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
			return;
		}
		directory = path.substr(0, path.find_last_of('/'));
		processNode(scene->mRootNode, scene);
		//importer.FreeScene();
	}

	void processNode(aiNode *node, const aiScene *scene) {
		for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
			aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(processMesh(mesh, scene));
		}
		for (unsigned int i = 0; i < node->mNumChildren; ++i) {
			processNode(node->mChildren[i], scene);
		}
	}

	Mesh processMesh(aiMesh*mesh, const aiScene *scene) {
		Mesh temp;
		
		temp.indices.clear();

		//indices
		for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
			for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; ++j) {
				temp.indices.push_back(mesh->mFaces[i].mIndices[j]);
			}
		}

#ifdef SIMD
		//vertex, normal, texCoords
		temp.vertexData.positions = std::vector<vec4>(mesh->mNumVertices);
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			_mm_storeu_ps(temp.vertexData.positions[i].e, { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z, 1.f });
		}

		temp.vertexData.normals = std::vector<vec4>(mesh->mNumVertices);
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			_mm_storeu_ps(temp.vertexData.normals[i].e, { mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z, 1.f });
		}

		temp.vertexData.texCoords = std::vector<vec2>(mesh->mNumVertices);
		
		if (mesh->mTextureCoords[0]) {
			for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
				temp.vertexData.texCoords[i] = vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
			}
		}
		else {
			memset((temp.vertexData.texCoords[0].e), 0, sizeof(vec2)*temp.vertexData.texCoords.size());
		}
		
		//loop is faster than memcpy.
		/*if (mesh->mTextureCoords[0]) {
			if (mesh->mNumVertices % 2 == 0) {
				for (unsigned int i = 0; i < mesh->mNumVertices; i += 2) {
					_mm_storeu_ps(temp.vertexData.texCoords[i].e, _mm_loadu_ps(&mesh->mTextureCoords[0][i].x));
				}
			}
			else {
				for (unsigned int i = 0; i < mesh->mNumVertices-1; i += 2) {
					_mm_storeu_ps(temp.vertexData.texCoords[i].e, _mm_loadu_ps(&mesh->mTextureCoords[0][i].x));
				}
				temp.vertexData.texCoords[mesh->mNumVertices - 1] = vec2(mesh->mTextureCoords[0][mesh->mNumVertices - 1].x, mesh->mTextureCoords[0][mesh->mNumVertices - 1].y);
			}

		}
		else {
			memset((temp.vertexData.texCoords[0].e), 0, sizeof(vec2)*temp.vertexData.texCoords.size());
		}*/
		/*if (mesh->mTextureCoords[0]) {
			memcpy(temp.vertexData.texCoords[0].e, &mesh->mTextureCoords[0][0].x, sizeof(vec2)*mesh->mNumVertices);				
		}
		else {
			memset((temp.vertexData.texCoords[0].e), 0, sizeof(vec2)*temp.vertexData.texCoords.size());
		}*/
#else
		//vertex, normal, texCoords
		temp.vertexData.positions = std::vector<vec4>(mesh->mNumVertices);
		temp.vertexData.normals = std::vector<vec4>(mesh->mNumVertices);
		temp.vertexData.texCoords = std::vector<vec2>(mesh->mNumVertices);

		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			temp.vertexData.positions[i] = vec4(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z, 1.f);
			temp.vertexData.normals[i] = vec4(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z, 1.f);


			if (mesh->mTextureCoords[0]) {
				temp.vertexData.texCoords[i] = vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
			}
			else {
				temp.vertexData.texCoords[i] = vec2(0.f);
			}

			// tangent			
			//vertex.tangent = glm::vec3(
			//	mesh->mTangents[i].x,
			//	mesh->mTangents[i].y,
			//	mesh->mTangents[i].z
			//);
			//// bitangent
			//vertex.bitangent = glm::vec3(
			//	mesh->mBitangents[i].x,
			//	mesh->mBitangents[i].y,
			//	mesh->mBitangents[i].z
			//);
		}
#endif // SIMD

		

		
		//std::vector<Texture> textures;
		// process materials
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		
		// 1. diffuse maps
		temp.diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		// 2. specular maps
		temp.specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		// 3. normal maps
		temp.normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		// 4. height maps
		temp.heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");

		return std::move(temp);
	}

	std::vector<Texture*> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
		std::vector<Texture*> textures;
		const unsigned int texCount = mat->GetTextureCount(type);
		for (unsigned int i = 0; i < texCount; ++i) {
			aiString str;
			mat->GetTexture(type, i, &str);
			std::string fileName = directory + '/' + std::string(str.C_Str());

			if (loadedTexture.find(fileName) == loadedTexture.end()) {
				loadedTexture[fileName] = Texture(fileName.c_str()); 
			}
			textures.push_back(&loadedTexture[fileName]);
		}
		return std::move(textures);
	}
};



#endif // !MODEL
