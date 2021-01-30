#pragma once 

#include <iostream>

#include <GL/glew.h>

class Mesh
{
private:
GLuint VAO;
GLuint VBO;
GLuint EBO;
GLuint PointDrawCout;

public:
	
	void Create(GLfloat *vertices, GLuint v_size, GLuint *indices, GLuint i_size)
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		
		
		glBindVertexArray(VAO);
		
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, i_size, indices, GL_STATIC_DRAW);
			
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, v_size, vertices, GL_STATIC_DRAW);
			
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
			glEnableVertexAttribArray(0);
			
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);
			
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			
		glBindVertexArray(0);
		
		PointDrawCout = i_size / sizeof(GLuint);
	}
	
	void Draw() const
	{
		glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
};