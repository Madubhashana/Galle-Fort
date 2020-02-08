#pragma once
#include <iostream>
#include <vector>
#include <GL\glut.h>
#include "Model.h"
#include "ModelLoader.h"

class Scene
{
public:
	Scene(){}
	virtual ~Scene(){}
	virtual void initialize() = 0;
	virtual void render() = 0;
	virtual void keyDown(unsigned char key) = 0;

private:

};
