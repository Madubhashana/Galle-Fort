#include "MainScreen.h"

Model *cube;
Model *churc;


void MainScreen::initialize()
{
	std::string filePath = "F:\\untitled1.obj";
	ModelLoader loader;
	std::cout << "Initializing MainScreen" << std::endl;
	//cube->initialize(verts, vertexNormals, faces);
	cube = loader.loadModel(filePath);


	churc = loader.loadModel("Assets\\LampPost.obj");
}

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
void MainScreen::render(){
//	std::cout << "Rendering MainScreen" << std::endl;
	/*glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glRotatef(angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(angleY, .0f, 01.0f, 0.0f);
		glRotatef(angleZ, .0f, 0.0f, 01.0f);*/
		cube->render();
		churc->render();
	//glPopMatrix();

}

void MainScreen::keyDown(unsigned char key){
	if (key == 'a') angleX += 01.1f;
	if (key == 's') angleY += 01.1f;
	if (key == 'd') angleZ += 01.1f;
}
