#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Input
{
private:

enum States
{
	KEEPING_UP,
	KEEPING_DOWN,
	DOWN,
	UP
};

inline static States keys[512];

public:

	static void keyCollback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		switch(action)
		{
			case GLFW_PRESS:
				keys[key] = DOWN;
			return;
			
			case GLFW_RELEASE:
				keys[key] = UP;
			return;
		}
	}
	
	inline static bool GetKeyDown(GLenum key)
	{
		if(Input::keys[key] == DOWN)
		{
			Input::keys[key] = KEEPING_DOWN;
			return true;
		}
		return false;
	}
	
	inline static bool GetKeyUp(GLenum key)
	{
		if(Input::keys[key] == UP)
		{
			Input::keys[key] = KEEPING_UP;
			return true;
		}
		return false;
	}
	
	inline static bool GetKeyHoldingDown(GLenum key)
	{
		return Input::keys[key] == KEEPING_DOWN;
	}
	
	inline static bool GetKeyHoldingUp(GLenum key)
	{
		return Input::keys[key] == KEEPING_UP;
	}
};