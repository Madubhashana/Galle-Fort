#include"Transform.h"
#include<iostream>

Transform::Transform()
{
	position.x = 0;
	position.y = 0;
	position.z = 0;

	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;

	scale.x = 1;
	scale.y = 1;
	scale.z = 1;
}
Transform::~Transform(){}

vec3 Transform::getPosition()
{
	return position;
}

vec3 Transform::getRotation()
{
	return rotation;
}

vec3 Transform::getScale()
{
	//return vec3();
	return scale;
}

void Transform::setPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Transform::setRotation(float x, float y, float z)
{
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
}

void Transform::setScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

void Transform::setScale(vec3 newscale)
{
	scale = newscale;
}

void Transform::setScale(float size)
{
	scale.x = size;
	scale.y = size;
	scale.z = size;
}