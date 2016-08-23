#ifndef _MODEL_H__
#define _MODEL_H__

#include <memory>
#include <string>
#include <vector>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GLUtils/VBO.hpp"

struct MeshPart {
	MeshPart() : first(0), count(0) {}
	glm::mat4 transform;
	unsigned int first;
	unsigned int count;
	std::vector<MeshPart> children;
};

class Model {
public:
	Model(std::string filename, bool invert=0);
	~Model();

	inline MeshPart getMesh() {return root;}
	inline std::shared_ptr<GLUtils::VBO> getVertices() {return vertices;}
	inline std::shared_ptr<GLUtils::VBO> getNormals() {return normals;}

private:
	static void loadRecursive(MeshPart& part, bool invert,
			std::vector<float>& vertex_data, const aiScene* scene, const aiNode* node);
			
	const aiScene* scene;
	MeshPart root;

	std::shared_ptr<GLUtils::VBO> normals;
	std::shared_ptr<GLUtils::VBO> vertices;

	glm::vec3 min_dim;
	glm::vec3 max_dim;

	unsigned int n_vertices;
};

#endif