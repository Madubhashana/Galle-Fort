#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include "Model.h"

class ModelLoader
{
public:
	ModelLoader(){}
	~ModelLoader(){}
	Model* loadModel(std::string path);
private:

};
