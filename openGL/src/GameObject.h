#pragma once

#include "src/Transform.h"
#include "src/Texture.h"
#include "src/Mesh.h"
#include "src/Shader.h"

class GameObject
{
private:
	
Texture texture;
Shader* shader;

public:

Transform transform;

Mesh mesh;

	void SetMesh(const Mesh& mesh)
	{
		this->mesh = mesh;
	}

	void SetShader(Shader* shader)
	{
		this->shader = shader;
	}

	inline void Draw() const
	{
		shader->SetMat4("model", transform.GetMatrix());
		mesh.Draw();
	}
};