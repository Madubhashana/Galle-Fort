#pragma once
typedef struct vec3
{
	float x, y, z;

}vec3;

class Transform
{
public:
	Transform();
	~Transform();

	vec3 getScale();
	vec3 getPosition();
	vec3 getRotation();

	void setScale(float x, float y, float z);
	void setScale(float size);
	void setScale(vec3 newscale);

	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
private:
	vec3 position;
	vec3 rotation;
	vec3 scale;
};