#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
#include <fstream>
#include "GameObject.h"
#include "CubeTile.h"
#include "MainGame.h"
#include "Pacman.h"


void Pacman::changeMesh()
{
	if (mouthOpened) {
		mouthOpened = false;
		object = LoadObject("PacmanMouthClose.obj");
	}
	else {
		mouthOpened = true;
		object = LoadObject("PacmanMouthOpen.obj");
	}
	startTime = clock();
}

void Pacman::checkStair()
{
	if (currentTile->type == STAIR && !isInStair) {
		isInStair = true;
		if (currentTile->belowTile!=nullptr && currentTile->belowTile->type == STAIR) MoveDown();
		else if (currentTile->topTile != nullptr && currentTile->topTile->type == STAIR) MoveUp();
	}
	if (currentTile->type != STAIR && isInStair) isInStair = false;
}

void Pacman::MoveUp()
{
	mainGame->currentPlayerFloor++;
	currentTile = currentTile->topTile;
	transform->position->y = currentTile->transform->position->y;
}

void Pacman::MoveRight()
{
	if (currentTile->rightTile != nullptr && currentTile->rightTile->type != WALL) {
		rotation = 270;
		if (transform->position->x < currentTile->rightTile->transform->position->x) {
			transform->position->x += speed;
			transform->position->z = currentTile->transform->position->z;
		}
		if (transform->position->x >= currentTile->rightTile->transform->position->x -0.25) {
			currentTile = currentTile->rightTile;
		}
	}
}

void Pacman::MoveDown()
{
	mainGame->currentPlayerFloor--;
	currentTile = currentTile->belowTile;
	transform->position->y = currentTile->transform->position->y;
}

void Pacman::MoveLeft()
{
	if (currentTile->leftTile != nullptr && currentTile->leftTile->type != WALL) {
		rotation = 90;
		if (transform->position->x > currentTile->leftTile->transform->position->x) {
			transform->position->x -= speed;
			transform->position->z = currentTile->transform->position->z;
		}
		if (transform->position->x <= currentTile->leftTile->transform->position->x + 0.25) {
			currentTile = currentTile->leftTile;
		}
	}
}

void Pacman::MoveForward()
{
	if (currentTile->upTile != nullptr && currentTile->upTile->type != WALL) {
		rotation = 0;
		if (transform->position->z > currentTile->upTile->transform->position->z) {
			transform->position->z -= speed;
			transform->position->x = currentTile->transform->position->x;
		}
		if (transform->position->z <= currentTile->upTile->transform->position->z + 0.25) {
			currentTile = currentTile->upTile;
		}
	}
}

void Pacman::MoveBackward()
{
	if (currentTile->downTile != nullptr && currentTile->downTile->type != WALL) {
		rotation = 180;
		if (transform->position->z < currentTile->downTile->transform->position->z) {
			transform->position->z += speed;
			transform->position->x = currentTile->transform->position->x;
		}
		if (transform->position->z >= currentTile->downTile->transform->position->z-0.25) {
			currentTile = currentTile->downTile;
		}
	}
}

void Pacman::Draw()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 0);
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0.5f, 0);
	glCallList(object);
	glPopMatrix();
}

void Pacman::Update()
{
	checkStair();
	if (((float)clock() - (float)startTime) / (float)CLOCKS_PER_SEC > mouthTimeIntervalinSeconds) {
		changeMesh();
	}
	Draw();
}

void Pacman::Kill()
{
	mainGame->currentPlayerFloor = startFloor;
	currentTile = spawnPosTile;
	transform->position->x = currentTile->transform->position->x;
	transform->position->y = currentTile->transform->position->y;
	transform->position->z = currentTile->transform->position->z;
	lifePoint--;
}

Pacman::Pacman()
{
	object = LoadObject("PacmanMouthOpen.obj");
	transform = new Transform();
	currentTile = new CubeTile();
}

Pacman::Pacman(MainGame *_mainGame, CubeTile * startTile)
{
	mainGame = _mainGame;
	object = LoadObject("PacmanMouthOpen.obj");
	transform = new Transform();
	currentTile = startTile;
	transform->position->x = currentTile->transform->position->x;
	transform->position->y = currentTile->transform->position->y;
	transform->position->z = currentTile->transform->position->z;
	speed = 0.1;
	rotation = 0;
	startTime = clock();
	mouthOpened = true;
	mouthTimeIntervalinSeconds = 0.1;
	isInStair = false;
	startFloor = mainGame->currentPlayerFloor;
	spawnPosTile = startTile;
	lifePoint = 3;
}


Pacman::~Pacman()
{
}
