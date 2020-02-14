#include "Scene.h"

class StartMenu : public Scene
{
public:
	StartMenu(){}
	~StartMenu(){}

	void initialize();
	void render();
	void keyDown(unsigned char key);

	void keyboard(unsigned char key, int x, int y);
	void mouseMovement(int x, int y);
	void keyboardSpecial(int key, int x, int y);

	void initLighting();
	void init();

	void drawStrokeText(char* str, int x, int y, int z);

private:
	Model* title;
	Model* starttxt;
};
