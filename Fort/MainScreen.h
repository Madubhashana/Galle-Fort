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

	void initModelsList();
	void initModels();
	void initLighting();
	void init();

	void pointer();
	void camera(void);
	void straightRoad(float X, float Z, float length, float width);
	void turnRoad(float r, float width, float angle);
	void roads();

private:
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

	GLfloat moveX = 0.0f;
	GLfloat moveY = 0.0f;
	GLfloat moveZ = 3.0f;

	GLfloat rotX = 0.0f;
	GLfloat rotY = 0.0f;
	GLfloat rotZ = 0.0f;

	GLfloat camX = 0.0f;
	GLfloat camY = 0.0f;
	GLfloat camZ = 0.0f;

	float lastx, lasty; //for the mouse function
	//float xpos = -6.301640, ypos = 7.4, zpos = -661.658569;    //position 1
	//float xpos = -477.89, ypos = 0.0, zpos = -527.83;			//position 2
	float xpos = 0.0, ypos = 0.0, zpos = 0.0;			//position origin
	float adX, adY, adZ = 0.0;

	//std::vector<Model *> models;
	std::map < std::string, Model* > models;


};
