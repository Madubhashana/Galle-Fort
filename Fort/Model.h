#pragma once

#include <vector>
#include <iostream>
#include "GL\glut.h"
#include "Transform.h"
#include "SOIL\SOIL.h"
#include "stb_image\stb_image.h"

class Model
{
public:
	Model(){
		diffuse[0] = .75f; diffuse[1] = .75f; diffuse[2] = .75f;
		specular[0] = 0.0f; specular[1] = .2f; specular[2] = .3f;
		shininess[0] = 0.1f; shininess[1] = .1f; shininess[2] = .1f;
	}
	~Model(){}

	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> texture;
	std::vector<std::vector<std::vector<int>>> faces;
	float diffuse[3] ;
	float specular[3] ;
	float shininess[3];	

	Transform transform;
	
	int listId;
	GLuint textureId;
	
	void initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces);

	void setDiffuse(float r,float g, float b);
	void setSpecular(float r, float g, float b);
	void setShininess(float r, float g, float b);

	void setDiffuseB(int r, int, int b);
	void setSpecularB(GLubyte r, GLubyte g, GLubyte b);
	void setShininessB(GLubyte r, GLubyte g, GLubyte b);

	void genarateList();
	
	void render();
	void draw();

	void loadTexture(const char* path);
	void printDetails();

private:
};
