#include "StartMenu.h"

void StartMenu::initLighting(){
	/*glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat position[] = { 30, 0, -20, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, 50);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);*/
}
void StartMenu::init(){

	ModelLoader ml;
	title = ml.loadModel("txtgalle");
	title->listId = glGenLists(1);
	title->genarateList();

	starttxt = ml.loadModel("txtStart");
	starttxt->listId = glGenLists(1);
	starttxt->genarateList();


	glClearColor(0.0f, 0.172f, .230f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	glLoadIdentity();
	initLighting();
	
}
#pragma endregion

#pragma region Input
void StartMenu::keyboard(unsigned char key, int x, int y) {

}
void StartMenu::mouseMovement(int x, int y) {

}
void StartMenu::keyboardSpecial(int key, int x, int y){

}
#pragma endregion

void StartMenu::initialize()
{
	initLighting();
	init();
}

void StartMenu::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//glPushMatrix();
	//glTranslated(-0.4, 1.5, -2.1);
	////glScaled(2, 2, 2);
	//title->draw();
	//glPopMatrix();

	//BUG HERE//

	glPushMatrix();
	glTranslated(0.0, 0.0, -2.1);
	starttxt->draw();
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}

void StartMenu::keyDown(unsigned char key){

}
