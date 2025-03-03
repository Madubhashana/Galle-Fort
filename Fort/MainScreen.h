#include <map>
#include "Primitives.h"
#include "Scene.h"

class MainScreen : public Scene
{
public:
	MainScreen(){}
	~MainScreen(){}
	
	void initialize();
	void render();
	void keyDown(unsigned char key);

	void keyboard(unsigned char key, int x, int y);
	void mouseMovement(int x, int y);
	void keyboardSpecial(int key, int x, int y);
	void Timer(int x);

	void LoadModels();
	void Trees();
	void Waves();

	void initModelsList();
	void initModels();
	void initLighting();
	void init();

	void camera(void);

private:
	//Models
	Model *testModel;
	Model *church;
	Model *Church2;
	Model *clockTower;
	Model *directionSign;
	Model *dutchHospital;
	Model *lampPost;
	Model *lightHouse;
	Model *monument;
	Model *court;
	Model *entrance;
	Model *pagoda;
	Model *library;
	Model *Museum;
	Model *Wave01;
	Model *Wave02;
	Model *Normal;
	Model *U_shape;
	Model *Turn_shape;
	Model *L_shape;
	Model *Tree;

	GLfloat moveX = 0.0f;
	GLfloat moveY = 0.0f;
	GLfloat moveZ = 3.0f;

	GLfloat moveXInv = 0.0f;
	GLfloat moveYInv = 0.0f;

	GLfloat rotX = 0.0f;
	GLfloat rotY = 0.0f;
	GLfloat rotZ = 0.0f;

	GLfloat camX = 0.0f;
	GLfloat camY = 0.0f;
	GLfloat camZ = 0.0f;


	float lastx, lasty; 
	float xpos = 0.0, ypos = 0.0, zpos = 0.0;			//position origin

	float ymax = 200.0f;
	float ymin = 2.0f;

	float adX, adY, adZ = 0.0;

	//std::vector<Model *> models;
	std::map < std::string, Model* > models;


};
