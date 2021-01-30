#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>

class perspectiveLH;
class Camera
{
private:

glm::mat4 view;
glm::mat4 projection;

glm::quat rotation;

glm::vec3 pos;

public:
	
	Camera():
	view(1.0f),
	projection(1.0f),
	pos(0.0f)
	{}
	
	inline void CreatePerspective(float angle, float aspect, float near, float far)
	{
		projection = glm::perspectiveLH(glm::radians(angle), aspect, near, far);
	}
	
	inline void CreateOtrho(float left, float right, float bottom, float top, float near, float far)
	{
		projection = glm::orthoLH(left, right, bottom, top, near, far);
	}
	
	inline void CreateOtrho(float right_left, float top_bottom, float near, float far)
	{
		projection = glm::orthoLH(-right_left, right_left, -top_bottom, top_bottom, near, far);
	}
	
	inline void GlobalTranslate(glm::vec3 v)
	{
		pos += v;
		view = glm::global_translate(view, -v);
	}
	
	inline void Rotate(float angle, glm::vec3 direction)
	{
		view = glm::rotate(view, -glm::radians(angle), direction);
	}
	
	inline void LookAt(glm::vec3 point)
	{
		view = glm::lookAtLH(pos, point, glm::vec3(0.0f, 1.0f, 0.0f));
	}
	
	inline glm::mat4 GetProjection()
	{
		return projection;
	}
	
	inline glm::mat4 GetView()
	{
		return view;
	}
	
	inline glm::vec3 GetPosition()
	{
		return pos;
	}
};