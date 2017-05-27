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
#include "CubeTile.h"


CubeTile::CubeTile()
{
	transform = new Transform();
}

CubeTile::CubeTile(float _x, float _y, float _z, float _scale, Type _type)
{
	transform = new Transform();
	transform->position = new glm::vec3(_x, _y, _z);
	transform->scale = new glm::vec3(_scale, _scale, _scale);
	type = _type;
	food = nullptr;
	downTile = nullptr;
	upTile = nullptr;
	leftTile = nullptr;
	rightTile = nullptr;
	dijkstraValue = NULL;
}

CubeTile::~CubeTile()
{
}

void CubeTile::Draw()
{
	glPushMatrix();
	if (type == STAIR) glColor3f(0, 0, 1);
	else if (type == WALL) glColor3f(0, 1, 0);
	else glColor3f(1, 0, 0);
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glTranslatef(-0.5, -0.5, -0.5);
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.5, 0);
	glVertex3d(1, 0.5, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 1);
	glVertex3d(0, 0.5, 1);
	glVertex3d(1, 0.5, 1);
	glVertex3d(1, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0, 0.5, 1);
	glVertex3d(0, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.5, 0);
	glVertex3d(1, 0.5, 1);
	glVertex3d(1, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 1);
	glVertex3d(1, 0, 1);
	glVertex3d(1, 0, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0.5, 0);
	glVertex3d(0, 0.5, 1);
	glVertex3d(1, 0.5, 1);
	glVertex3d(1, 0.5, 0);
	glEnd();
	glPopMatrix();
}

void CubeTile::Update()
{
	//glTranslatef(0, 0, -4);
	if (food != nullptr) food->Update();
	Draw();
}

void CubeTile::DeleteFood()
{
	food->wasEaten = true;
	//if (food != nullptr)
	//delete food,food=NULL;
}
