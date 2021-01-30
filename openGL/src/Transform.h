#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "MatrixTransform.h"

class Transform
{
private:
glm::mat4 m_rotation;

public:

glm::quat rotation;
glm::mat4 matrix;

glm::vec3 position;

	Transform():
	matrix(1.0f),
	m_rotation(1.0f),
	position(0.0f)
	{}
	
	inline void RotateX(const float& angle)
	{
		m_rotation = rotate_x(glm::mat4(1.0f), angle) * m_rotation;
	}
	
	inline void RotateY(const float& angle)
	{
		m_rotation = rotate_y(glm::mat4(1.0f), angle) * m_rotation;
	}
	
	inline void RotateZ(const float& angle)
	{
		m_rotation = rotate_z(glm::mat4(1.0f), angle) * m_rotation;
	}
	
	glm::mat4 GetMatrix() const
	{
		return matrix * m_rotation;
	}
	
	void Translate(glm::vec3 v)
	{
		matrix = glm::translate(matrix, v);
		v = matrix[3];
	}
	
	void GlobalTranslate(glm::vec3 v)
	{
		matrix = glm::global_translate(matrix, v);
		position += v;
	}
	
	void SetPosition(glm::vec3 v)
	{
		position = v;
		matrix = glm::set_position(matrix, v);
	}
};