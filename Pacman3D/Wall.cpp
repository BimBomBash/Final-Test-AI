#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "CubeTile.h"
#include "Wall.h"


void Wall::DrawCube(int direction)
{
	glPushMatrix();
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glRotatef(90 * direction, 0, 1, 0);
	//glTranslatef(0.5, 0, 0.5);
	glTranslatef(0, 0,-width / 2);
	glScalef(0.5, height, width);
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 1, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 1);
	glVertex3d(0, 1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 1, 0);
	glVertex3d(0, 1, 1);
	glVertex3d(0, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 0, 1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 1);
	glVertex3d(1, 0, 1);
	glVertex3d(1, 0, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(0, 1, 0);
	glVertex3d(0, 1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 1, 0);
	glEnd();
	glPopMatrix();
}

void Wall::DrawTube(int segments)
{
	glPushMatrix();

	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	float angleInterval = (float)360 / (float)segments;
	for (int i = 0; i < segments; i++) {
		float Z1 = sin(angleInterval*i)*width/2;
		float X1 = cos(angleInterval*i)*width/2;
		float Z2 = sin(angleInterval*(i + 1))*width/2;
		float X2 = cos(angleInterval*(i + 1))*width/2;
		glBegin(GL_QUADS);
		glVertex3f(X1, 0, Z1);
		glVertex3f(X2, 0, Z2);
		glVertex3f(X1, height, Z1);
		glVertex3f(X2, height, Z2);
		glEnd();
	}
	glPopMatrix();
}

Wall::Wall()
{
}

Wall::Wall(CubeTile * _tile, float _height, float _width, bool _left, bool _up, bool _right, bool _down)
{
	transform = new Transform;
	transform->position = _tile->transform->position;
	tile = _tile;
	height = _height;
	width = _width;
	left = _left;
	up = _up;
	right = _right;
	down = _down;
}

void Wall::Draw()
{
	glPushMatrix();
	glColor4f(0.0, 0.0, 0.6, 0.5);
	DrawTube(10);
	if (left) DrawCube(2);
	if (up) DrawCube(1);
	if (right) DrawCube(0);
	if (down) DrawCube(3);
	glPopAttrib();
}

void Wall::Update()
{
	Draw();
}


Wall::~Wall()
{
}
