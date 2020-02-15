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
}

void MainScreen::initModels()
{
	ModelLoader loader;
	testModel = loader.loadModel("church");
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
	//pagoda->setDiffuse();

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
void MainScreen::init(){
	glClearColor(0.1f, 0.15f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FOG);


	glLoadIdentity();
	initLighting();
	initModels();
	setInitState();
}
#pragma endregion

#pragma region Primitive Drawings
void MainScreen::pointer(){
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

void MainScreen::camera(void) {
	glRotatef(rotX, 1.0, 0.0, 0.0);  //rotate our camera on teh x-axis (left and right)
	glRotatef(rotY, 0.0, 1.0, 0.0);  //rotate our camera on the y-axis (up and down)

	glTranslated(-xpos, -ypos, -zpos); //translate the screen to the position of our camera
}

void MainScreen::straightRoad(float X, float Z, float length, float width){
	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_QUADS);
	glVertex3d(X + width / 2, 0.009, Z);
	glVertex3d(X - width / 2, 0.009, Z);
	glVertex3d(X - width / 2, 0.009, length + Z);
	glVertex3d(X + width / 2, 0.009, length + Z);
	glEnd();
}

void MainScreen::turnRoad(float r, float width, float angle){
	glColor3f(0.25, 0.25, 0.25);
	float ratio = 7.0 / 360;
	glBegin(GL_QUAD_STRIP);

	for (GLfloat i = 0; i <= (ratio*angle); i += 0.01) {
		glVertex3f(r*cos(i), 0.01, r*sin(i));
		glVertex3f((r + width)*cos(i), 0.01, (r + width)*sin(i));
	}
	glEnd();
}

void MainScreen::roads(){
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
	straightRoad(0, -4.0, -49, 2.3);
	glPopMatrix();

	//R2
	glPushMatrix();
	glTranslated(-3.8, -0.0001, -42.1);
	glRotated(91, 0.0, -1.0, 0.0);
	turnRoad(13.5, 2.3, 54);

	glTranslated(7.500007, 0.0, 12.599738);
	glRotated(62.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 48, 2.3);

	glTranslated(0.0, 0.0015, 47.8);
	glRotated(7, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 77, 2.3);
	//R10
	glTranslated(25.3, -0.0015, 2.4);
	glRotated(10.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 77, 2.0);
	//R11
	glTranslated(-0.7, -0.001, 21.8);
	glRotated(88.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 21, 2.0);
	//R8
	glTranslated(20.7, 0.0, -12.4);
	glRotated(4.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 80, 2.0);
	//R9
	glTranslated(16.7, 0.0, 12.7);
	glRotated(7.0, 0.0, 1.0, 0.0);
	straightRoad(0, 0, 44, 2.0);
	glPopMatrix();

	//R3
	glPushMatrix();
	glTranslated(-76.34, 0.0012, -68.5);
	glRotated(105, 0.0, 1.0, 0.0);
	straightRoad(0, 0, 38, 2.3);

	glTranslated(3.45, 0.0, 0.0);
	glRotated(180, 0.0, 1.0, 0.0);
	turnRoad(2.3, 2.3, 93);

	glTranslated(-0.6, 0.0, 3.4);
	glRotated(103, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 36, 2.3);

	glTranslated(0.0, 0.0, 35.8);
	glRotated(4.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 36, 2.3);

	glTranslated(-2.75, 0.0, 36);
	turnRoad(1.6, 2.3, 68);
	//R4
	glTranslated(0.9, 0.0012, 2.6);
	glRotated(74, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 37, 2.3);

	glTranslated(-11.75, 0.0, 36.6);
	turnRoad(10.6, 2.3, 55);

	glTranslated(5.805, 0.0, 10.2);
	glRotated(61, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 70, 2.3);

	glTranslated(-9.45, 0.0, 70);
	turnRoad(8.3, 2.3, 23.5);

	glTranslated(8.55, 0.0, 4.0);
	glRotated(26.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 42, 2.3);

	glTranslated(-2.75, 0.0, 42.0);
	turnRoad(1.6, 2.3, 57.5);
	//R5
	glTranslated(1.5, 0.0, 2.3);
	glRotated(61, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 11, 2.3);

	glTranslated(1.15, 0.0, 11.0);
	glRotated(88, 0.0, -1.0, 0.0);
	turnRoad(0.0, 2.3, 90.0);

	glTranslated(1.15, 0.0, -6.0);
	straightRoad(0, 0, 6, 2.3);

	glTranslated(7.65, 0.0, 0.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	turnRoad(6.5, 2.3, 133);

	glTranslated(-6.5, -0.001, 4.0);
	glRotated(139.0, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 20, 2.3);

	glTranslated(1.15, 0.0, -0.2);
	glRotated(202.0, 0.0, 1.0, 0.0);
	turnRoad(0.0, 2.3, 40.3);
	glPopMatrix();

	//R6
	glPushMatrix();
	glTranslated(6.2, 0.0, -31.7);
	glRotated(114, 0.0, 1.0, 0.0);
	turnRoad(21.0, 2.0, 62.5);

	glTranslated(22.1, -0.001, -1.0);
	glRotated(177, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 18, 2.0);

	glTranslated(-45, 0.0, -7.5);
	straightRoad(0, 0, 25, 2.0);
	//R7
	glTranslated(44.9, 0.001, 7.2);
	glRotated(100, 0.0, -1.0, 0.0);
	straightRoad(0, 0, 107, 2.0);
	glPopMatrix();
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

void MainScreen::initialize()
{
	initModelsList();
	initModels();
	initLighting();
	init();
}

void MainScreen::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	GLfloat fog_color[] = { 0.5f, 0.5, 0.5f, 0.2 };
	glFogfv(GL_FOG_COLOR, fog_color);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, -150.0f);
	glFogf(GL_FOG_END, -5000.f);


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
	glTranslated(-1.7, 0.0, -27.8);
	glScaled(0.4, 0.4, 0.4);
	directionSign->draw();
	glPopMatrix();

	//Court
	glPushMatrix();
	glTranslated(-83.94, 0.0, -70.1);
	glRotated(98, 0.0, 1.0, 0.0);
	glScaled(0.5, 0.5, 0.5);
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
	glTranslated(19.0, 1.8, -80.6);
	glRotated(0.8, 0.0, 0.0, 1.0);
	glScaled(6.0, 6.0, 6.0);
	pagoda->draw();
	glPopMatrix();


	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void MainScreen::keyDown(unsigned char key){

}
