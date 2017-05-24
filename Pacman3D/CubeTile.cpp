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


CubeTile::CubeTile()
{
}


CubeTile::~CubeTile()
{
}

void CubeTile::Draw()
{
	glPushMatrix();
	glTranslatef(-0.5, -0.5, -0.5);
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

void CubeTile::Update()
{
	glTranslatef(0, 0, -4);
	Draw();
}
