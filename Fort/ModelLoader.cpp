#include "ModelLoader.h"


Model* ModelLoader::loadModel(std::string path)
{
	std::vector<std::string> files;
	std::string line;
	Model *model = new Model();
	std::string fullPath = "Assets\\" + path;
	std::ifstream inputFile(fullPath);

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line, '\n'))
		{
			std::stringstream  inputLine(line);
			std::string parsed;

			if (std::getline(inputLine, parsed, ' '))
			{

				//	f 146 / 1 / 1 145 / 2 / 1 39 / 3 / 1 38 / 4 / 1
				if (parsed == "f")
				{
				   // 146/1/1 145/2/1 39/3/1 38/4/1
					std::vector<std::vector<int>> face_single;

					std::string index;
					std::cout << index;
					while (std::getline(inputLine, parsed, ' '))
					{	

						std::vector<int> vertex;
						// 146/1/1
						std::stringstream face(parsed);
						while (std::getline(face, index, '/'))
						{
							//Insert -1 if coardinate is not available
							if (index  == "")
							{
								vertex.push_back(-1);
								continue;
							}
							vertex.push_back(std::stoi(index));
						}
						face_single.push_back(vertex);
					}
					model->faces.push_back(face_single);
				}

				else  if (parsed == "v")
				{
					while (std::getline(inputLine, parsed, ' '))
					{
						model->vertices.push_back(std::stof(parsed));
					}
				}
				else if (parsed == "vn")
				{
					if (parsed == "")
					{
						model->normals.push_back(-1);
						continue;
					}

					while (std::getline(inputLine, parsed, ' '))
					{
						model->normals.push_back(std::stof(parsed));
					}
				}

				else if (parsed == "vt")
				{
					if (parsed == "")
					{
						model->texture.push_back(-1);
						continue;
					}

					while (std::getline(inputLine, parsed, ' '))
					{
						//Populate the texture coordinate array
						model->texture.push_back(std::stof(parsed));
					}	
				}
			}
		}
	}
	else
	{
		std::cout << "Error Loading File";
	}
	return model;
}