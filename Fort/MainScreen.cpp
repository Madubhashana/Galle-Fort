#include "MainScreen.h"

#define PI 3.1428571428571428571428571428571

#pragma region Initializing

void MainScreen::initModelsList()
{
	//models.insert({"clockTower", clockTower	});
	models.insert({ "testModel", testModel });
	models.insert({ "church", church });
	models.insert({ "clockTower", clockTower });
	models.insert({ "directionSign", directionSign });
	models.insert({ "dutchHospital", dutchHospital });
	models.insert({ "lampPost", lampPost });
	models.insert({ "lightHouse", lightHouse });
	models.insert({ "monument", monument });
	models.insert({ "court", court });
	models.insert({ "entrance", entrance });
	models.insert({ "entrance", entrance });
	models.insert({ "library", library });
	models.insert({ "pagoda", pagoda });
	models.insert({ "Museum", Museum });
	models.insert({ "Church2", Church2 });

	models.insert({ "Wave01", Wave01 });
	models.insert({ "Wave02", Wave02 });

	models.insert({ "Normal", Normal });
	models.insert({ "U_shape", U_shape });
	models.insert({ "Turn_shape", Turn_shape });
	models.insert({ "L_shape", L_shape });

	models.insert({ "Tree", Tree });

	
}
void MainScreen::initModels()
{
	ModelLoader loader;
	testModel = loader.loadModel("church");
	testModel->setDiffuse(.1f, .1f, .1f);
	testModel->transform.setScale(.5f);

	church = loader.loadModel("church");
	church->setDiffuse(0.5, 0.5, 0.5);

	clockTower = loader.loadModel("clocktower");
	clockTower->setDiffuse(0.5, 0.5, 0.5);
	
	directionSign = loader.loadModel("DirectionSign");
	directionSign->setDiffuse(0.5, 0.5, 0.5);

	dutchHospital = loader.loadModel("dutchHospital");
	dutchHospital->setDiffuse(0.5, 0.5, 0.5);

	lampPost = loader.loadModel("lampPost");
	lampPost->setDiffuse(0.5, 0.5, 0.5);

	lightHouse = loader.loadModel("LightHouse");
	lightHouse->setDiffuse(0.5, 0.5, 0.5);

	monument = loader.loadModel("Monument");
	monument->setDiffuse(0.5, 0.5, 0.5);

	court = loader.loadModel("court.obj");
	court->setDiffuse(0.5, 0.5, 0.5);

	library = loader.loadModel("library.obj");
	library->setDiffuse(0.5, 0.5, 0.5);


	pagoda = loader.loadModel("pagoda.obj");
	pagoda->setDiffuse(0.5, 0.5, 0.5);

	Museum = loader.loadModel("Museum.obj");
	Museum->setDiffuse(0.5, 0.5, 0.5);


	Wave01 = loader.loadModel("Wave01.obj");
	Wave02 = loader.loadModel("Wave02.obj");


	Normal = loader.loadModel("Normal.obj");
	Normal->setDiffuse(0.5, 0.5, 0.5);

	U_shape = loader.loadModel("U_shape.obj");
	U_shape->setDiffuse(0.5, 0.5, 0.5);

	Turn_shape = loader.loadModel("Turn_shape.obj");
	Turn_shape->setDiffuse(0.5, 0.5, 0.5);

	L_shape = loader.loadModel("L_shape.obj");
	L_shape->setDiffuse(0.5, 0.5, 0.5);

	Tree = loader.loadModel("Tree.obj");
	Church2 = loader.loadModel("Church2.obj");


	entrance = loader.loadModel("entrance.obj");
	entrance->setDiffuse(.5f, .5f, .5f);
	initModelsList();
	
	
	std::map<std::string, Model*>::iterator it = models.begin();

	while (it != models.end())
	{
		it->second->listId = glGenLists(1);
		it->second->genarateList();
		it++;
	}


}
void MainScreen::initLighting(){
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat position[] = { 30, 0, -20, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	GLfloat ambient2[] = { .20, 0.20, 0.20, 1.0 };
	GLfloat diffuse2[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat position2[] = { -30, 0, -20, 1.0 };
	GLfloat specular2[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, position2);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, 100);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

}

void initFog()
{
	GLfloat fog_color[] = { 0.048f, 0.215f, .575f, 1.0 };
	glFogfv(GL_FOG_COLOR, fog_color);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.0025);
}

void MainScreen::init(){
	glClearColor(0.048f, 0.215f, .575f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FOG);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLoadIdentity();
	initLighting();
	initFog();
	initModels();
	setInitState();
}
void MainScreen::initialize()
{
	initModelsList();
	initModels();
	init();
}
#pragma endregion

#pragma region Camera
void MainScreen::camera(void) {
	glRotatef(rotX, 1.0, 0.0, 0.0);  //rotate our camera on teh x-axis (left and right)
	glRotatef(rotY, 0.0, 1.0, 0.0);  //rotate our camera on the y-axis (up and down)
	
	glTranslated(-xpos, -ypos, -zpos); //translate the screen to the position of our camera
}
#pragma endregion

#pragma region Input
void MainScreen::keyboard(unsigned char key, int x, int y) {
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

		if (ypos < ymin)
		{
			ypos = ymin;
		}
		if (ypos > ymax)
		{
			ypos = ymax;
		}
	}

	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (rotY / 180 * PI);
		xrotrad = (rotX / 180 * PI);
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		ypos += float(sin(xrotrad));

		if (ypos < ymin)
		{
			ypos = ymin;
		}
		if (ypos > ymax)
		{
			ypos = ymax;
		}
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

	glutPostRedisplay();

}
void MainScreen::mouseMovement(int x, int y) {
	int diffx = x - lastx;
	int diffy = y - lasty;
	lastx = x;
	lasty = y;
	rotX += (float)diffy;
	rotY += (float)diffx;
	glutPostRedisplay();
}
void MainScreen::keyboardSpecial(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT)
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos += float(cos(yrotrad)) * 0.4;
		zpos += float(sin(yrotrad)) * 0.4;
	}

	if (key == GLUT_KEY_LEFT)
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos -= float(cos(yrotrad)) * 0.4;
		zpos -= float(sin(yrotrad)) * 0.4;
	}

	if (key == GLUT_KEY_DOWN)
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos -= float(cos(xrotrad)) * 0.4;
		xpos -= float(sin(xrotrad)) * 0.4;
	}

	if (key == GLUT_KEY_UP)
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos += float(cos(xrotrad)) * 0.4;
		xpos += float(sin(xrotrad)) * 0.4;
	}
	glutPostRedisplay();
}
#pragma endregion

void MainScreen::LoadModels(){
	//Entrance
	glPushMatrix();
	glTranslated(-0.18, 0.0, -13.79);
	glRotated(5, 0.0, 1.0, 0.0);
	glScaled(0.033, 0.0328, 0.0329);
	entrance->draw();
	glPopMatrix();

	//Entrance
	glPushMatrix();
		glTranslated(-30.3 + adX, -0.01, -63.2 + adZ);
		glRotated(63+adY, 0.0, -1.0, 0.0);
		glScaled(1.3, 1.3, 1.3);
		Church2->draw();
	glPopMatrix();

	//clock tower
	glPushMatrix();
	glTranslated(22.1, 2.37, -14.4);
	glScaled(1.3, 1.0, 1.3);
	glRotated(5, 0.0, 1.0, 0.0);
	clockTower->draw();
	glPopMatrix();

	//Light house
	glPushMatrix();
	glTranslated(-88.2, 1.9, -148);
	lightHouse->draw();
	glPopMatrix();

	//Monument
	glPushMatrix();
	glTranslated(-0.4, -0.001, -2.1);
	glScaled(0.4, 0.4, 0.4);
	monument->draw();
	glPopMatrix();

	//RoadSign
	glPushMatrix();
	glTranslated(-1.6, 0.0, -27.8);
	glScaled(0.3, 0.3, 0.3);
	directionSign->draw();
	glPopMatrix();

	//Court
	glPushMatrix();
	glTranslated(-83.94, 0.0, -70.1);
	glRotated(98, 0.0, 1.0, 0.0);
	glScaled(0.6, 0.5, 0.5);
	court->draw();
	glPopMatrix();

	//DutchHospital
	glPushMatrix();
	glTranslated(-85.64, 0.0, -104);
	glRotated(91.4, 0.0, -1.0, 0.0);
	glScaled(0.8, 0.8, 0.8);
	dutchHospital->draw();
	glPopMatrix();

	//Church
	glPushMatrix();
	glTranslated(-37.34, 0.0, -92.4);
	glRotated(73.4, 0.0, -1.0, 0.0);
	glScaled(0.7, 0.7, 0.7);
	church->draw();
	glPopMatrix();

	//Library
	glPushMatrix();
	glTranslated(-35.24, 0.001, -76.5);
	glRotated(64, 0.0, -1.0, 0.0);
	glScaled(0.3, 0.3, 0.3);
	library->draw();
	glPopMatrix();


	//Pagoda
	glPushMatrix();
	glTranslated(18.0, 0.0, -80.6);
	glRotated(0.8, 0.0, 0.0, 1.0);
	glScaled(6.0, 6.0, 6.0);
	pagoda->draw();
	glPopMatrix();

	//Museum
	glPushMatrix();
	glTranslated(-61.9, 0.0, -64);
	glRotated(164 + adY, 0.0, -1.0, 0.0);
	glScaled(0.012, 0.012, 0.012);
	Museum->draw();
	glPopMatrix();

	//block1
	glPushMatrix();
	glTranslated(3.3, 0.98, -33.3);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.9, 0.0, -36.1);
	glRotated(95.4, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.3, 0.0, -40.8);
	glRotated(95.4, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.3, 0.0, -45.6);
	glRotated(95.4, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.1, 0.0, -50.0);
	glRotated(17.1, 0.0, 1.0, 0.0);
	glScaled(0.005, 0.005, 0.005);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.2, 0.0, -51.2);
	glRotated(11.9, 0.0, 1.0, 0.0);
	glScaled(0.004, 0.004, 0.004);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.3, 0.0, -51.5);
	glRotated(-4.6, 0.0, 1.0, 0.0);
	glScaled(0.005, 0.005, 0.005);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(11.11, 0.0, -50.9);
	glRotated(-15.9, 0.0, 1.0, 0.0);
	glScaled(0.005, 0.005, 0.005);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(15.6, 0.0, -48.6);
	glRotated(151.6, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(21.6, 0.98, -46.2);
	glRotated(-12.4, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(23.8, 0.0, -39.4);
	glRotated(135.7, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(26.1, 0.0, -35.2);
	glRotated(92.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10.3, 0.0, -29.9);
	glRotated(-2.1, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(18.4, 0.6, -33.9);
	glRotated(-1.8, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(21.1, 0.98, -32.0);
	glRotated(87.8, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	//block2
	glPushMatrix();
	glTranslated(-13.3, 0.3, -43.8);
	glRotated(-64.1, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7.4, 0.0, -45.9);
	glRotated(27.7, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10.6, 0.0, -44.4);
	glRotated(27.7, 0.0, 1.0, 0.0);
	glScaled(0.003, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5.6, 0.0, -42.5);
	glRotated(95.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5.1, 0.0, -38.2);
	glRotated(95.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14.5, 0.0, -36.9);
	glRotated(120.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11.3, 0.0, -33.4);
	glRotated(139.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block3
	glPushMatrix();
	glTranslated(-9.9, 0.0, -50.9);
	glRotated(26.7, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-21.2, 0.0, -50.1);
	glRotated(115.6, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16.4, 0.0, -47.4);
	glRotated(116.4, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-30, 0.0, -67.1);
	glRotated(117.0, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7.6, 0.0, -56.9);
	glRotated(107.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-12.7, 0.0, -73.9);
	glRotated(107.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0.0, -67.3);
	glRotated(107.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9.1, 0.0, -61.3);
	glRotated(107.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19.2, 0.98, -87.3);
	glRotated(196.5, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-33.1, 0.98, -81.5);
	glRotated(291.2, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14.6, 0.0, -79.7);
	glRotated(107.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15.8, 0.0, -84.9);
	glRotated(19.9, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-22.8, 0.0, -90.2);
	glRotated(116.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31.1, 0.0, -84.6);
	glRotated(26.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-26.3, 0.0, -87.2);
	glRotated(26.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-32.1, 0.0, -70.9);
	glRotated(27.4, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-35.3, 0.0, -78.0);
	glRotated(117.4, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block4
	//bottom
	glPushMatrix();
	glTranslated(-28.5, 0.0, -92.2);
	glRotated(26.7, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0.6, -99.5);
	glRotated(26.5, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(-21.9, 0.0, -104.2);
	glRotated(106.7, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-24, 0.0, -110.6);
	glRotated(107, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-25, 0.0, -114.1);
	glRotated(107, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslated(-42.41, 0.0, -96.8);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-44.9, 0.0, -103.2);
	glRotated(110.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-46.4, 0.0, -106.6);
	glRotated(20.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43.9, 0.3, -113.6);
	glRotated(-79.5, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-29.8, 0.0, -114.7);
	glRotated(10.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-36.4, 0.6, -109.9);
	glRotated(189.2, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	//block5
	//left
	glPushMatrix();
	glTranslated(-51.41, 0.0, -121.6);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51.0, 0.3, -132.1);
	glRotated(-74.3, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(-29.61, 0.0, -129.5);
	glRotated(106.9, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-45.1, 0.0, -117.9);
	glRotated(8.9, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39.4, 0.0, -118.9);
	glRotated(8.9, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31.51, 0.0, -136.5);
	glRotated(196.3, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-30.9, 0.98, -121.7);
	glRotated(101.4, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-34.5, 0.6, -123.5);
	glRotated(7.2, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-45.41, 0.0, -133);
	glRotated(14.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-40, 0.0, -134.4);
	glRotated(14.9, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-35.2, 0.0, -135.6);
	glRotated(14.2, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//triangular block
	glPushMatrix();
	glTranslated(-27.21, 0.0, -137.4);
	glRotated(106.9, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23.1, 0.0, -125.1);
	glRotated(107.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-24.7, 0.0, -129.7);
	glRotated(107.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-20.8, 0.0, -134.9);
	glRotated(132.7, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15.1, 0.0, -128.9);
	glRotated(132.3, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-18.2, 0.0, -122);
	glRotated(8.2, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-29.7, 0.0, -144.8);
	glRotated(24.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-25.2, 0.0, -140.7);
	glRotated(24.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11.4, 0.0, -126.1);
	glRotated(41.2, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9.7, 0.0, -123.3);
	glRotated(41.2, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block6
	//left
	glPushMatrix();
	glTranslated(-56.81, 0.0, -136.6);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-58.9, 0.0, -141.7);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-60.8, 0.0, -146.8);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(-34.7, 0.0, -145.3);
	glRotated(107, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-49, 0.0, -137.3);
	glRotated(14, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-42, 0.6, -143.4);
	glRotated(14.1, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-37.1, 0.0, -140.1);
	glRotated(104.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-44.5, 0.0, -152.1);
	glRotated(104.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-41.1, 0.0, -152.0);
	glRotated(91.8, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-37.7, 0.0, -152.1);
	glRotated(58.5, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-57.7, 0.0, -149.1);
	glRotated(104.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-53.7, 0.0, -150.1);
	glRotated(104.7, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-49.1, 0.0, -150.6);
	glRotated(14, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();


	//block7
	//right
	glPushMatrix();
	glTranslated(-61.81, 0.0, -135);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63.9, 0.0, -140.1);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-65.8, 0.0, -145.2);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslated(-69.6, 0.3, -146);
	glRotated(-76.5, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71.91, 0.0, -135.8);
	glRotated(100.5, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-67.1, 0.6, -136.8);
	glRotated(14.1, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	//block8
	//right
	glPushMatrix();
	glTranslated(-56.7, 0.0, -121.1);
	glRotated(110.6, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-58.8, 0.0, -126.2);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-57.0, 0.6, -120.5);
	glRotated(8.7, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslated(-69.2, 0.3, -118.6);
	glRotated(10, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-69.2, 0.0, -122.8);
	glRotated(99.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-66.2, 0.0, -127.7);
	glRotated(14, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-61.8, 0.0, -116);
	glRotated(7.3, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block9
	//right
	glPushMatrix();
	glTranslated(-49.1, 0.0, -100.5);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51.2, 0.0, -105.6);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-53.1, 0.0, -110.7);
	glRotated(110.8, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-62.3, 0.0, -111.3);
	glRotated(98.2, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-66, 0.0, -110.8);
	glRotated(98.2, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-57.8, 0.0, -111.5);
	glRotated(7.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslated(-66.1, 0.0, -103.6);
	glRotated(100, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-64.5, 0.0, -95.8);
	glRotated(11.4, 0.0, 1.0, 0.0);
	glScaled(0.004, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-56.5, 0.0, -97.3);
	glRotated(12.4, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block10
	//left
	glPushMatrix();
	glTranslated(-61.4, 0.0, -80.1);
	glRotated(101.7, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-62.3, 0.0, -84.8);
	glRotated(101.7, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63.6, 0.0, -89.8);
	glRotated(101.7, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-60.3, 0.0, -75.4);
	glRotated(16.7, 0.0, 1.0, 0.0);
	glScaled(0.004, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(-43.3, 0.0, -84.3);
	glRotated(109.4, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-46, 0.0, -91.2);
	glRotated(16.7 + adY, 0.0, 1.0, 0.0);
	glScaled(0.004, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslated(-58.7, 0.6, -87.6);
	glRotated(191.9, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-48, 0.0, -94);
	glRotated(12.2 + adY, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-53.7, 0.0, -92.7);
	glRotated(12, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-52.5, 0.6, -81.7);
	glRotated(13.8, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-56.3, 0.0, -76.6);
	glRotated(13.9, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-46.3, 0.0, -79.4);
	glRotated(15.2, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block11
	//left
	glPushMatrix();
	glTranslated(-75.3, 0.3, -109.3);
	glRotated(-82.1, 0.0, 1.0, 0.0);
	glScaled(12.04, 12.04, 12.04);
	L_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-76.6, 0.98, -74.6);
	glRotated(4.2, 0.0, 1.0, 0.0);
	glScaled(9.44, 9.44, 9.44);
	Turn_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-78.7, 0.0, -98.2);
	glRotated(92.3, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.7, 0.6, -89.7);
	glRotated(271.6, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.3, 0.6, -77.9);
	glRotated(271.6, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-78.7, 0.0, -83.9);
	glRotated(91.4, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(-74.1, 0.6, -97.7);
	glRotated(98.7, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-66.4, 0.0, -78.3);
	glRotated(100.5, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-72.1, 0.0, -108.1);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71.2, 0.0, -103.3);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-69.4, 0.0, -93.1);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-68.4, 0.0, -87.3);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-73.3, 0.0, -72);
	glRotated(14.5, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-69.2, 0.0, -73.4);
	glRotated(14.8, 0.0, 1.0, 0.0);
	glScaled(0.004, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//block12
	//right
	glPushMatrix();
	glTranslated(-77.0, 0.6, -114.5);
	glRotated(98.7, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-81.5, 0.6, -140.2);
	glRotated(98.7, 0.0, 1.0, 0.0);
	glScaled(10.84, 10.84, 10.84);
	U_shape->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74, 0.0, -120.6);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.7, 0.0, -125.6);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-77.5, 0.0, -135.2);
	glRotated(100.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-78.6, 0.0, -130.6);
	glRotated(92.4, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslated(-79.1, 0.0, -117.5);
	glRotated(88.4, 0.0, 1.0, 0.0);
	glScaled(0.016, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-78.1, 0.0, -125.9);
	glRotated(89.1, 0.0, 1.0, 0.0);
	glScaled(0.006, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslated(-76.1, 0.0, -113);
	glRotated(95.5 + adY, 0.0, 1.0, 0.0);
	glScaled(0.002, 0.006, 0.006);
	Normal->draw();
	glPopMatrix();



}
void MainScreen::Trees(){
	//Entrance
	glPushMatrix();
	glTranslated(-4.6, 1.6, -32.7);
	glRotated(25, 0.0, -1.0, 0.0);
	glScaled(10.4, 10.4, 10.4);
	Tree->draw();
	glPopMatrix();
}

void MainScreen::Waves(){
	//Wave set 01
	glPushMatrix();
		glTranslated(-52.6 + moveX, -1.0+moveY, -24.6);
		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(5, 0.0, 1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
		glPopMatrix();
	glPopMatrix();

	//Wave set 02
	glPushMatrix();
		glTranslated(-116.8 + moveX, -1.0 + moveY, -93.4);
		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(4.2, 0.0, -1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
		glPopMatrix();
	glPopMatrix();

	//Wave set 03
	glPushMatrix();
		glTranslated(-106.5 + moveX, -1.0 + moveY, -160);
			glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(34.2, 0.0, -1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
		glPopMatrix();
	glPopMatrix();


	//Wave set 04
	glPushMatrix();
		glTranslated(76.4+ moveXInv, -1.0 + moveYInv, -34.6);
		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(176.6, 0.0, 1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
		glPopMatrix();
	glPopMatrix();


	//Wave set 05
	glPushMatrix();
		glTranslated(50.4 + moveXInv, -1.0 + moveYInv, -111.4);
		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(217.5, 0.0, 1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
		glPopMatrix();
	glPopMatrix();

	//Wave set 05
	glPushMatrix();
		glTranslated(1.8 + moveXInv, -1.0 + moveYInv, -150);
		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glRotated(213.5, 0.0, 1.0, 0.0);
			glScaled(22.5, 22.0, 28.8);
			Wave02->draw();

			glTranslated(-0.2, 0.0, 0.7);
			glScaled(0.8, 0.8, 0.7);
			Wave01->draw();

			glTranslated(-0.4, 0.0, -1.9);
			Wave01->draw();
			glPopMatrix();
	glPopMatrix();
}

void MainScreen::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	camera();

	glPushMatrix();
	//gluLookAt(0.0+camX, 2.0+camY, 5.0+camZ, 0,0,0,0,1.0,0);
	glTranslated(0.0, -2.0, 0.0);
	glScaled(5.0, 5.0, 5.0);


	glPushMatrix();
	glRotated(90.0, 1.0, 0.0, 0.0);
	ground();
	ocean();
	glPopMatrix();

	castsel();
	ground_levels();
	roads();
	LoadModels();
	Waves();
	Trees();


	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void MainScreen::Timer(int x)
{
	if (moveX >= 20.0){
		if (moveY <= -0.3){
			moveX = 0.0;
			moveY = 0.0;
		}
		else{
			moveY -= 0.005;
		}
	}
	else{
		moveX += 0.1;
	}


	if (moveXInv <= -20.0){
		if (moveYInv <= -0.3){
			moveXInv = 0.0;
			moveYInv = 0.0;
		}
		else{
			moveYInv -= 0.005;
		}
	}
	else{
		moveXInv -= 0.1;
	}
	glutPostRedisplay();
}
void MainScreen::keyDown(unsigned char key){

}