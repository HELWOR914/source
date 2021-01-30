#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "src/Window.h"
#include "src/Camera.h"
#include "src/GameObject.h"
#include "src/Optimization.h"
#include "src/Input.h"


void getM(glm::mat4 m)
{
	std::cout << m[0].x << '\t' << m[1].x << '\t' << m[2].x << '\t' << m[3].x << std::endl;
	std::cout << m[0].y << '\t' << m[1].y << '\t' << m[2].y << '\t' << m[3].y << std::endl;
	std::cout << m[0].z << '\t' << m[1].z << '\t' << m[2].z << '\t' << m[3].z << std::endl;
	std::cout << m[0].w << '\t' << m[1].w << '\t' << m[2].w << '\t' << m[3].w << std::endl;
}

int main(int argc, char **argv)
{
	Window window;
	window.Init(680, 480);
	
	Shader shader;
	shader.CreateFast("src/Shader.vs", "src/Shader.fs");
	
	shader.SetInt("ourTexture", 0);
	
	Texture texture;
	texture.Load("src/container.jpg");
	
	
	GLfloat vertices[]
	{
         // координаты     // текстурные координаты
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // верхняя правая вершина
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, // нижняя правая вершина
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // нижняя левая вершина
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f  // верхняя левая вершина 
    };
	
	GLuint indices[]
	{
        0, 1, 3,
        1, 2, 3
    };
	
	Mesh mesh;
	mesh.Create(vertices, sizeof(vertices), indices, sizeof(indices));
	
	Camera camera;
	
	camera.CreatePerspective(45.0f, float(680)/float(480), 0.1f, 10.1f);
	//=====
	
	GameObject obj;
	obj.SetShader(&shader);
	obj.SetMesh(mesh);
	obj.transform.Translate(glm::vec3(1.0f, -2.0f, 3.0f));
	
	
	camera.Rotate(45.0f, glm::vec3(1.0f, 1.0f, 0.0f));
	//=====
	
	//set color
	glClearColor(0.0f, 0.7f, 0.5f, 1.0f);
	
	//Main loop
	while(!window.ShouldClose())
	{
		//events
		glfwPollEvents();
		
		window.ClearBuffers();
		
		//==========Update==========
		
		shader.Use();
		
		shader.SetMat4("projection", camera.GetProjection());
		shader.SetMat4("view", camera.GetView());
		
		if(Input::GetKeyDown('A'))
		{
			std::cout << "A pressed" << std::endl;
		}
		
		if(Input::GetKeyUp('A'))
		{
			std::cout << "A released" << std::endl;
		}
		
		if(Input::GetKeyHoldingDown('A'))
		{
			std::cout << "A holding down" << std::endl;
		}
		
		texture.Use();
		obj.Draw();
		
		//==========================
		
		window.SwapBuffers();
	}
}