#include "MainScreen.h"

#define PI 3.1428571428571428571428571428571

#pragma region Initializing

//Insert all the models to this map
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

	models.insert({ "Wave01", Wave01 });
	models.insert({ "Wave02", Wave02 });
}

void MainScreen::initModels()
{
	ModelLoader loader;
	testModel = loader.loadModel("church");
	testModel->setDiffuse(.1f, .1f, .1f);
	testModel->transform.setScale(.5f);

	church = loader.loadModel("church");
	church->setDiffuse(0.138,0.138,0.138);

	clockTower = loader.loadModel("clocktower");
	clockTower->setDiffuse(.230, .55, .64);
	//clockTower->setSpecularB(223, 159, 159);
	//clockTower->setShininessB(0.0, 0.0, 1.0);
	
	directionSign = loader.loadModel("DirectionSign");
	directionSign->setDiffuse(0.073,0.098,0.138);

	dutchHospital = loader.loadModel("dutchHospital");
	dutchHospital->setDiffuse(0.138,0.127,0.098);

	lampPost = loader.loadModel("lampPost");
	lampPost->setDiffuse(0.175,0.018,0.013);

	lightHouse = loader.loadModel("LightHouse");
	lightHouse->setDiffuse(0.400,0.398,0.388);

	monument = loader.loadModel("Monument");
	//monument->setDiffuse();

	court = loader.loadModel("court.obj");
	//court->setDiffuse();

	library = loader.loadModel("library.obj");
	//library->setDiffuse();

	pagoda = loader.loadModel("pagoda.obj");
	Museum = loader.loadModel("Museum.obj");

	Wave01 = loader.loadModel("Wave01.obj");
	Wave02 = loader.loadModel("Wave02.obj");


	entrance = loader.loadModel("entrance.obj");
	entrance->setDiffuse(.5f, .5f, .5f);
	initModelsList();
	
	
	std::map<std::string, Model*>::iterator it = models.begin();

	while (it != models.end())
	{
		//it->second = loader.loadModel(it->first);
		it->second->listId = glGenLists(1);
		it->second->genarateList();
		//it->second->printDetails();
		it++;
	}


}

void MainScreen::initLighting(){
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	GLfloat ambient[] = { .724, 0.678, 0.392, 1.0 };
	GLfloat diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat position[] = { 30, 0, -20, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	GLfloat ambient2[] = { .20, 0.20, 0.20, 1.0 };
	GLfloat diffuse2[] = { 0.048, 0.215, 0.575, 1.0 };
	GLfloat position2[] = { -30, 0, -20, 1.0 };
	GLfloat specular2[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, position2);

	//
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMateriali(GL_FRONT, GL_SHININESS, 50);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

}

void initFog()
{
	GLfloat fog_color[] = { 0.5f, 0.5, 0.5f, 0.2 };
	glFogfv(GL_FOG_COLOR, fog_color);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, -50.0f);
	glFogf(GL_FOG_END, -5000.f);
}

void MainScreen::init(){
	glClearColor(0.048f, 0.215f, .575f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FOG);

	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
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
	initLighting();
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


		if (ypos < ymin)
		{
			ypos = ymin;
		}
		if (ypos > ymax)
		{
			ypos = ymax;
		}
	}

	if (key == '6')
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos += float(cos(yrotrad)) * 0.4;
		zpos += float(sin(yrotrad)) * 0.4;
	}

	if (key == '4')
	{
		float yrotrad;
		yrotrad = (rotY / 180 * PI);
		xpos -= float(cos(yrotrad)) * 0.4;
		zpos -= float(sin(yrotrad)) * 0.4;
	}

	if (key == '2')
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos -= float(cos(xrotrad)) * 0.4;
		xpos -= float(sin(xrotrad)) * 0.4;
	}

	if (key == '8')
	{
		float xrotrad;
		xrotrad = (rotX / 180 * PI);
		ypos += float(cos(xrotrad)) * 0.4;
		xpos += float(sin(xrotrad)) * 0.4;
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


void MainScreen::LoadModels(){
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