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

	models.insert({ "Wave01", Wave01 });
}
void MainScreen::initModels()
{
	ModelLoader loader;
	testModel = loader.loadModel("church");
	testModel->setDiffuse(.1f, .1f, .1f);
	testModel->transform.setScale(.5f);
	church = loader.loadModel("church");
	clockTower = loader.loadModel("clocktower");
	directionSign = loader.loadModel("DirectionSign");
	dutchHospital = loader.loadModel("dutchHospital");
	lampPost = loader.loadModel("lampPost");
	lightHouse = loader.loadModel("LightHouse");
	monument = loader.loadModel("Monument");
	court = loader.loadModel("court.obj");
	library = loader.loadModel("library.obj");
	pagoda = loader.loadModel("pagoda.obj");
	Museum = loader.loadModel("Museum.obj");

	Wave01 = loader.loadModel("Wave01.obj");


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
void MainScreen::init(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLoadIdentity();
	initLighting();
	initModels();
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
void MainScreen::mouseMovement(int x, int y) {
	int diffx = x - lastx;
	int diffy = y - lasty;
	lastx = x;
	lasty = y;
	rotX += (float)diffy;
	rotY += (float)diffx;
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
		glTranslated(19.0, 1.8, -80.6);
		glRotated(0.8, 0.0, 0.0, 1.0);
		glScaled(6.0, 6.0, 6.0);
		pagoda->draw();
	glPopMatrix();

	//Museum
	glPushMatrix();
		glTranslated(-61.9, 0.0, -64 );
		glRotated(164+adY, 0.0, -1.0, 0.0);
		glScaled(0.012, 0.012, 0.012);
		Museum->draw();
	glPopMatrix();
}

void MainScreen::Waves(){
	//Wave set 01
	glPushMatrix();
		glTranslated(0.0+moveX, 0.0, 0.0+moveZ);
		//glRotated(5, 0.0, 1.0, 0.0);
		//glScaled(0.033, 0.0328, 0.0329);
		Wave01->render();
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

void MainScreen::keyDown(unsigned char key){

}
