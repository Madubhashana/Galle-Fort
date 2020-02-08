#include "Model.h"

//Initializes an object using custom arrays of data
void Model::initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces)
{
	Model::vertices = vertices;
	Model::normals = normals;
	Model::faces = faces;

	//loadTexture("F:\\Untitled.png");
	genarateList();
}

//Prints object's data counts
void Model::printDetails()
{
	std::cout << "List ID: " << listId << std::endl;
	std::cout << "Vertices Count: " << vertices.size()<<std::endl;
	std::cout << "faces Count: " << faces.size() << std::endl;
	std::cout << "Normals Count: " << normals.size() << std::endl;
}

//Set Materials
void Model::setDiffuse(float r, float g, float b)
{
	Model::diffuse[0] = r;	 Model::diffuse[1] = g;   Model::diffuse[2] = b;
}
void Model::setSpecular(float r, float g, float b)
{
	Model::specular[0] = r;	 Model::specular[1] = g;  Model::specular[2] = b;
}
void Model::setShininess(float r, float g, float b)
{
	Model::shininess[0] = r; Model::shininess[1] = g; Model::shininess[2] = b;
}


//Compiles a display list for rendering
//Should be the last call before draw()
void Model::genarateList()
{
	glNewList(listId, GL_COMPILE);
	glPushMatrix();
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(diffuse[0], diffuse[1], diffuse[2]);
	glColorMaterial(GL_FRONT,GL_SPECULAR);
	glColor3f(specular[0], specular[1], specular[2]);
	glColorMaterial(GL_FRONT, GL_SHININESS);
	glColor3f(shininess[0], shininess[1], shininess[2]);

	

	//glBindTexture(GL_TEXTURE_2D,textureId);
	glScalef(transform.getScale().x, transform.getScale().y, transform.getScale().z);
	glRotated(transform.getRotation().x, 1.0f, 0.0f, 0.0f);
	glRotated(transform.getRotation().y, 0.0f, 1.0f, 0.0f);
	glRotated(transform.getRotation().z, 0.0f, 0.0f, 1.0f);
	glTranslatef(transform.getPosition().x, transform.getPosition().y, transform.getPosition().z);

	for (auto& face : faces)
	{
		glBegin(GL_POLYGON);
		for (auto& vertex : face)
		{
			//Vertex
			int v1 = (vertex[0] - 1) * 3;
			int v2 = (vertex[0] - 1) * 3 + 1;
			int v3 = (vertex[0] - 1) * 3 + 2;
			float vX = vertices[v1];
			float vY = vertices[v2];
			float vZ = vertices[v3];

			//Normal
			int vn1 = (vertex[2] - 1) * 3;
			int vn2 = (vertex[2] - 1) * 3 + 1;
			int vn3 = (vertex[2] - 1) * 3 + 2;
			float vnX = normals[vn1];
			float vnY = normals[vn2];
			float vnZ = normals[vn3];

			//int vt1 = (vertex[1] - 1) * 2;
			//int vt2 = (vertex[1] - 1) * 2 + 1;
			//float vtX = texture[vn1];
			//float vtY = texture[vn2];

			glNormal3f(vnX, vnY, vnZ);
			//glTexCoord2f(vtX,vtY);
			glVertex3f(vX, vY, vZ);
		}
		glEnd();
	}
	glPopMatrix();
	glEndList();
}

//Renders using genarated display list
void Model::draw()
{
	glCallList(listId);
}

//Renders the object in imediate mode
void Model::render()
{
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(diffuse[0], diffuse[1], diffuse[2]);
	//glColorMaterial(GL_FRONT, GL_SPECULAR);
	//glColor3f(specular[0], specular[1], specular[2]);
	//glColorMaterial(GL_FRONT, GL_SHININESS);
	//glColor3f(shininess[0], shininess[1], shininess[2]);



	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glPushMatrix();
	glScalef(transform.getScale().x, transform.getScale().y, transform.getScale().z);
	//glRotated(transform.getRotation().x, 1.0f, 0.0f, 0.0f);
	//glRotated(transform.getRotation().y, 0.0f, 1.0f, 0.0f);
	//glRotated(transform.getRotation().z, 0.0f, 0.0f, 1.0f);
	//glTranslatef(transform.getPosition().x, transform.getPosition().y, transform.getPosition().z);

	for (auto& face : faces)
	{
	glBegin(GL_POLYGON);
		for (auto& vertex : face)
		{
			//Vertex
			int v1 = (vertex[0] - 1) * 3;
			int v2 = (vertex[0] - 1) * 3 + 1;
			int v3 = (vertex[0] - 1) * 3 + 2;
			float vX = vertices[v1];
			float vY = vertices[v2];
			float vZ = vertices[v3];

			//Normal
			int vn1 = (vertex[2] - 1) * 3;
			int vn2 = (vertex[2] - 1) * 3 + 1;
			int vn3 = (vertex[2] - 1) * 3 + 2;
			float vnX = normals[vn1];
			float vnY = normals[vn2];
			float vnZ = normals[vn3];

			//int vt1 = (vertex[1] - 1) * 2;
			//int vt2 = (vertex[1] - 1) * 2 + 1;
			//float vtX = texture[vn1];
			//float vtY = texture[vn2];

			glNormal3f(vnX, vnY, vnZ);
			//glTexCoord2f(vtX,vtY);
			glVertex3f(vX, vY, vZ);
		}
	glEnd();
	}
//	glPopMatrix();
}

//TODO
//Load Textures. 
void Model::loadTexture(const char* path)
{

	//int width, height, nrChannels;
	//unsigned char *data = stbi_load("F:\\Untitled.png",&width,&height,&nrChannels,0);
	//
	//glGenTextures(1,&textureId);
	//glBindTexture(GL_TEXTURE_2D,textureId);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glGenTextures(1, &textureId);
	std::cout << "Texture ID : " << textureId <<std::endl;
	glBindTexture(GL_TEXTURE_2D, textureId);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	std::vector < unsigned char > image;
	unsigned char *data = stbi_load("F:\\Untitled.png", &width, &height, &nrChannels, 0);
	
	//image.insert(image.begin(), std::begin(data), std::end(data));
	//image = data;
	int size = sizeof(data) / sizeof(data[0]);

	if (data)
	{
		std::cout << "Loaded texture : " << size <<std::endl;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);




//	int width, height;
//	unsigned char* image = SOIL_load_image("F:\\Untitled.png", &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, 0, width, height,
//		0,GL_RGB, GL_UNSIGNED_BYTE, image);
//	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	
//	int size = sizeof(image) / sizeof(image[0]);
//	if (image)
//	{
//		std::cout << "Image Loaded : "<<size<<std::endl;
//	}
//	else
//	{
//		std::cout << "Image Could not Load"<<std::endl;
//	}
//
//	SOIL_free_image_data(image);
//	
//	
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//
//	/*int width, height;
//	unsigned char* image = SOIL_load_image(path,&width,&height,0,SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
//	SOIL_free_image_data(image);*/
//
////	glTexParameteri(GL_TEXTURE_2D, );


}
