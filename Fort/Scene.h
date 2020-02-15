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
	
	bool initialized = false;
	
	virtual void initialize() = 0;
	virtual void render() = 0;

	virtual void keyDown(unsigned char key) = 0;
	virtual void keyboard(unsigned char key, int x, int y) = 0;
	virtual void mouseMovement(int x, int y) = 0;
	virtual void keyboardSpecial(int key, int x, int y) = 0;

	bool getInitState()
	{
		return initialized;
	}
	void setInitState()
	{
		initialized = true;
	}

private:

};
