#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Food.h"


Food::Food()
{
	object = LoadObject("PacmanFood.obj");
}

Food::Food(bool _isBig, Transform *_transform)
{
	transform = new Transform();
	transform->position->x = _transform->position->x;
	transform->position->y = _transform->position->y+0.5;
	transform->position->z = _transform->position->z;
	isBig = _isBig;
	object = LoadObject("PacmanFood.obj");
	wasEaten = false;
}


void Food::Draw()
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	if (isBig) glScalef(1.5, 1.5, 1.5);
	glCallList(object);
	glPopMatrix();
}

void Food::Update()
{
	if (!wasEaten) {
		Draw();
	}
}

Food::~Food()
{
}
