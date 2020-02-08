#include "Scene.h"

class MainScreen : public Scene
{
public:
	MainScreen(){}
	~MainScreen(){}
	
	void initialize();
	void render();
	void keyDown(unsigned char key);

private:

};
