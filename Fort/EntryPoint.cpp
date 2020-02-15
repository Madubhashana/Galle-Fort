/*****************************************************************************
******************************************************************************
CS 308 | Computer Graphics | Group Project
******************************************************************************
******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include "GL\glut.h"
#include "Transform.h"
#include "MainScreen.h"
#include "StartMenu.h"

GLfloat windowW = 20.0f;
GLfloat windowH = 20.0f;

bool paused = false;   
bool mainScreenInit = false;


MainScreen* mainScreen;
//= new MainScreen();
StartMenu* startMenu = new StartMenu();
Scene *currentScene;

void init()
{
	startMenu->init();
	currentScene = startMenu;
}

void toggleScene()
{
	if (currentScene == mainScreen)
	{
		if (startMenu == NULL)
		{
			std::cout << "Starting Menu...";
			startMenu = new StartMenu();
			startMenu->init();
		}
		currentScene = startMenu;
		mainScreen->~MainScreen();
	}
	else if (currentScene == startMenu)
	{
		if (mainScreen == NULL)
		{
			std::cout << "Starting...";
			mainScreen = new MainScreen();
			mainScreen->init();
			mainScreenInit = true;
		}
		currentScene = mainScreen;
		startMenu->~StartMenu();
	}
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'p')
	{
		std::cout << "Please Wait" << std::endl;
		toggleScene();
	}
	if (key == 'o')
	{
		paused = true;
	}
	currentScene->keyboard(key, x, y);
}
void mouseMovement(int x, int y)
{
	currentScene->mouseMovement(x, y);
}
void keyboardSpecial(int key, int x, int y)
{
	currentScene->keyboardSpecial(key, x, y);
}
void renderScene(){
	currentScene->render();
}

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
	if (mainScreenInit)
	{
		mainScreen->Timer(x);
	}

	//glutPostRedisplay();
	glutTimerFunc(60, Timer, 1);
}
#pragma endregion

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(1280, 760);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("Galle Fort");

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