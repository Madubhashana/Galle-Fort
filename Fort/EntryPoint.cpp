/*****************************************************************************
******************************************************************************
CS 308 | Computer Graphics | Group Project
******************************************************************************
******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include "GL\glut.h"
#include "Primitives.h"
#include "Transform.h"
#include "MainScreen.h"

#pragma region Global Variables

#define PI 3.1428571428571428571428571428571

GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 3.0f;

GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

GLfloat camX = 0.0f;
GLfloat camY = 0.0f;
GLfloat camZ = 0.0f;

GLfloat windowW = 20.0f;
GLfloat windowH = 20.0f;


float lastx, lasty; //for the mouse function
//float xpos = -6.301640, ypos = 7.4, zpos = -661.658569;    //position 1
//float xpos = -477.89, ypos = 0.0, zpos = -527.83;			//position 2
float xpos = 0.0, ypos = 0.0, zpos = 0.0;			//position origin
float adX, adY, adZ = 0.0;

//Models
Model *testModel;
Model *church;
Model *clockTower;
Model *directionSign;
Model *dutchHospital;
Model *lampPost;
Model *lightHouse;
Model *monument;
Model *court;
Model *entrance;


#pragma endregion

#pragma region Initializing
void initModels()
{
	ModelLoader loader;
	testModel = loader.loadModel("church");
	//testModel->setDiffuse(.1f, .1f, .1f);
	testModel->transform.setScale(.5f);

	church = loader.loadModel("church");
	clockTower = loader.loadModel("clocktower");
	directionSign = loader.loadModel("DirectionSign");
	dutchHospital = loader.loadModel("dutchHospital");
	lampPost = loader.loadModel("lampPost");
	lightHouse = loader.loadModel("LightHouse");
	monument = loader.loadModel("Monument");
	court = loader.loadModel("court.obj");
	
	entrance = loader.loadModel("entrance.obj");
	entrance->setDiffuse(.5f, .5f, .5f);

}
void initLighting(){
	glEnable(GL_LIGHTING);
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
	glEnable(GL_LIGHT0);
}
void init(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	glLoadIdentity();
	initLighting();
	initModels();
}
#pragma endregion

#pragma region Primitive Drawings
void pointer(){
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glScaled(0.5, 0.5, 0.5);
	glPushMatrix();
	Wall(5.0, 1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	Wall(5.0, 1.0);
	glPopMatrix();
	glPopMatrix();
}
void camera(void) {
	glRotatef(rotX, 1.0, 0.0, 0.0);  //rotate our camera on teh x-axis (left and right)
	glRotatef(rotY, 0.0, 1.0, 0.0);  //rotate our camera on the y-axis (up and down)

	glTranslated(-xpos, -ypos, -zpos); //translate the screen to the position of our camera
}

void straightRoad(float X, float Z, float length, float width){
	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_QUADS);
		glVertex3d(X + width / 2, 0.009, Z);
		glVertex3d(X - width / 2, 0.009, Z);
		glVertex3d(X - width / 2, 0.009, length + Z);
		glVertex3d(X + width / 2, 0.009, length + Z);
	glEnd();
}

void turnRoad(float r, float width, float angle){
	glColor3f(0.25, 0.25, 0.25);
	float ratio = 7.0/360 ;
	glBegin(GL_QUAD_STRIP);

	for (GLfloat i = 0; i <= (ratio*angle) ; i += 0.01) {
		glVertex3f(r*cos(i), 0.01, r*sin(i));
		glVertex3f((r + width)*cos(i), 0.01, (r + width)*sin(i));
	}
	glEnd();
}

void roads(){
	//RB-1
	glPushMatrix();
		glTranslated(0.7, 0.0, -2.0);
		turnRoad(2.0, 2.3, 360);
	glPopMatrix();

	//RB-2
		glPushMatrix();
		glTranslated(-1.4, 0.0, -27.6);
		turnRoad(0.0, 3, 360);
	glPopMatrix();

	//R1
	glPushMatrix();
		glTranslated(1.0, 0.0, 0.0);
		glRotated(5.0, 0.0, 1.0, 0.0);
		straightRoad(0, -4.0, -21, 2.3);
	glPopMatrix();

	//R2
	glPushMatrix();
		glTranslated(-3.8, 0.0, -42.1);
		glRotated(91, 0.0, -1.0, 0.0);
		turnRoad(13.5, 2.3, 54);
		
		glTranslated(7.500007, 0.0, 12.599738);
		glRotated(62.0, 0.0, -1.0, 0.0);
		straightRoad(0, 0, 48, 2.3);

		glTranslated(0.0, 0.0, 47.8);
		glRotated(7, 0.0, -1.0, 0.0);
		straightRoad(0, 0, 77, 2.3);
	glPopMatrix();

	//R3
	glPushMatrix();
		glTranslated(-76.34, 0.0, -68.5);
		glRotated(105, 0.0, 1.0, 0.0);
		straightRoad(0, 0, 38, 2.3);

	glPopMatrix();
}

#pragma endregion

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera();

	glPushMatrix();
	//gluLookAt(0.0+camX, 2.0+camY, 5.0+camZ, 0,0,0,0,1.0,0);
	glTranslated(0.0, -2.0, 0.0);
	glScaled(5.0, 5.0, 5.0);

		castsel();
		ground_levels();

		/*glPushMatrix();
			glTranslated(-87 + adX, 0.0 + adY, -52 + adZ);
			pointer();
		glPopMatrix();*/

		glPushMatrix();
			glRotated(90.0, 1.0, 0.0, 0.0);
			ground();
		glPopMatrix();


		roads();

		//Entrance
		glPushMatrix();
			glTranslated(-0.18, 0.0, -13.79);
			glRotated(5, 0.0, 1.0, 0.0);
			glScaled(0.033, 0.0328, 0.0329);
			entrance->render();
		glPopMatrix();

		//clock tower
		glPushMatrix();
			glTranslated(22.1, 2.37, -14.4);
			glScaled(1.3, 1.0, 1.3);
			glRotated(5, 0.0, 1.0, 0.0);
			clockTower->render();
		glPopMatrix();

		//Light house
		glPushMatrix();
			glTranslated(-88.2, 1.9, -148);
			lightHouse->render();
		glPopMatrix();

		//Monument
		glPushMatrix();
			glTranslated(-0.4, -0.001, -2.1);
			glScaled(0.4, 0.4 , 0.4);
			monument->render();
		glPopMatrix();

		//RoadSign
		glPushMatrix();
			glTranslated(-1.7, 0.0, -27.8);
			glScaled(0.4, 0.4, 0.4);
			directionSign->render();
		glPopMatrix();

		//Court
		glPushMatrix();
			glTranslated(-83.94, 0.0, -70.1);
			glRotated(98, 0.0, 1.0, 0.0);
			glScaled(0.5, 0.5, 0.5);
			court->render();
		glPopMatrix();

		//DutchHospital
		glPushMatrix();
			glTranslated(-86.04+adX, 0.0, -101.2+adZ);
			glRotated(94.0, 0.0, -1.0, 0.0);
			glScaled(0.7, 0.7, 0.7);
			dutchHospital->render();
		glPopMatrix();

		glPushMatrix();
			//clockTower->render();
		glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

#pragma region Input
void keyboard(unsigned char key, int x, int y) {
	if (key == 'q')
	{
		rotX += 1;
		if (rotX >360)
			rotX -= 360;
	}

	if (key == 'z')
	{
		rotX -= 1;
		if (rotX < -360) rotX += 360;
	}

	if (key == 'w')
	{
		float xrotrad, yrotrad;
		yrotrad = (rotY / 180 * PI);
		xrotrad = (rotX / 180 * PI);
		xpos += float(sin(yrotrad));
		zpos -= float(cos(yrotrad));
		ypos -= float(sin(xrotrad));
		//printf("xpos: %f   ypos: %f    zpos: %f\n", xpos, ypos, zpos);
	}

	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (rotY / 180 * PI);
		xrotrad = (rotX / 180 * PI);
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		ypos += float(sin(xrotrad));
		//printf("xpos: %f   ypos: %f    zpos: %f\n", xpos, ypos, zpos);

	}

	if (key == '6')
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos += float(cos(yrotrad)) * 0.2;
		zpos += float(sin(yrotrad)) * 0.2;
	}

	if (key == '4')
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos -= float(cos(yrotrad)) * 0.2;
		zpos -= float(sin(yrotrad)) * 0.2;
	}

	if (key == '2')
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos -= float(cos(xrotrad)) * 0.2;
		xpos -= float(sin(xrotrad)) * 0.2;
	}

	if (key == '8')
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos += float(cos(xrotrad)) * 0.2;
		xpos += float(sin(xrotrad)) * 0.2;
	}
	if (key == 'd')
	{
		rotY += 1;
		if (rotY >360) rotY -= 360;
		printf("rotY: %f", rotY);

	}

	if (key == 'a')
	{
		rotY -= 1;
		if (rotY < -360)rotY += 360;
		printf("rotY: %f", rotY);

	}
	if (key == '/'){
		adZ -= 0.1;
		printf("adZ : %f\n", adZ);
	}
	if (key == '5'){
		printf("adZ : %f\n", adZ);
		adZ += 0.1;
	}
	if (key == '7'){
		adX -= 0.1;
		printf("adX : %f\n", adX);

	}
	if (key == '9'){
		adX += 0.1;
		printf("adX : %f\n", adX);

	}
	if (key == 'y'){
		adY += 0.1;
		printf("adY : %f\n", adY);

	}
	if (key == 'h'){
		adY -= 0.1;
		printf("adY : %f\n", adY);

	}

	if (key == 27)
	{
		exit(0);
	}
}
void mouseMovement(int x, int y) {
	int diffx = x - lastx;
	int diffy = y - lasty;
	lastx = x;
	lasty = y;
	rotX += (float)diffy;
	rotY += (float)diffx;
}
void keyboardSpecial(int key, int x, int y){
	if (key == GLUT_KEY_UP){
		camY = 85;
	}
	if (key == GLUT_KEY_DOWN){
		camY = -75;
	}
	if (key == GLUT_KEY_LEFT){
		camX -= 5.0;
	}
	if (key == GLUT_KEY_RIGHT){
		rotY += 5.0;
	}


	glutPostRedisplay();
}
#pragma endregion

#pragma region Update and Reshape
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60 * (float)w / h, (float)w / h, 1.0f, 800.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void changesize(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-windowW, windowW, -windowH / aspect_ratio, windowH / aspect_ratio, 20.0, -20.0);
	else
		glOrtho(-windowW * aspect_ratio, windowW*aspect_ratio, -windowH, windowH, 20.0, -20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Timer(int x){

	glutPostRedisplay();
	glutTimerFunc(60, Timer, 1);
}
#pragma endregion

int main(int argc, char* argv[])
{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
		glutInitWindowSize(1280, 760);
		glutCreateWindow("Practise Two");
		init();
	
		glutDisplayFunc(renderScene);
		glutIdleFunc(renderScene);
		glutReshapeFunc(reshape);
		glutTimerFunc(60.0, Timer, 1);
	
		glutKeyboardFunc(keyboard);
		glutSpecialFunc(keyboardSpecial);
		glutPassiveMotionFunc(mouseMovement);
	
		glutMainLoop();
}