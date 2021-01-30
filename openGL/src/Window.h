#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Input.h"

class Window
{
private:
GLFWwindow* mainWindow;

GLuint WIDTH;
GLuint HEIGHT;

	static void framebuffer_size_callback(GLFWwindow* window, int w, int h)
	{
		glViewport(0, 0, w, h);
	}

public:

	Window(){}
	
	Window(GLuint width, GLuint height)
	{
		WIDTH = width;
		HEIGHT = height;
	}
	
	int Init(GLuint width, GLuint height)
	{
		WIDTH = width;
		HEIGHT = height;
		return Init();
	}
	
	int Init()
	{
		//==========Init GLFW==========
		if(!glfwInit())
		{
			std::cerr << "Failed to init GLFW" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 32);
		//=============================
		
		
		//========Create window========
		mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "openGL", nullptr, nullptr);
		if(!mainWindow)
		{
			std::cerr << "Failed to create WINDOW" << std::endl;
			glfwDestroyWindow(mainWindow);
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(mainWindow);
		glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);
		glfwSetKeyCallback(mainWindow, Input::keyCollback);
		//=============================
		
		
		//==========Init GLEW==========
		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK)
		{
			std::cerr << "Failed to init GLEW" << std::endl;
			glfwTerminate();
			return -1;
		}
		//=============================
		
		
		//========Set viewport=========
		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		
		return 0;
	}
	
	inline void SwapBuffers() const
	{
		glfwSwapBuffers(mainWindow);
	}
	
	inline bool ShouldClose() const
	{
		return glfwWindowShouldClose(mainWindow);
	}
	
	inline void ClearBuffers() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	inline GLuint GetWidth() const
	{
		return WIDTH;
	}
	
	inline GLuint GetHeight() const
	{
		return HEIGHT;
	}
	
	inline GLFWwindow* GetWindow() const
	{
		return mainWindow;
	}
	
	~Window()
	{
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
	}
};