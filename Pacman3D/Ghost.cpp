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
#include "MainGame.h"
#include "GhostBehavior.h"
#include "ChaseBehavior.h"
#include "PatrolBehavior.h"
#include "Ghost.h"


void Ghost::MoveToTargetTile()
{
	std::cout << "Is Moving" << std::endl;
	if (targetCube == currentTile->leftTile) {
		rotation = 90;
			std::cout << "Moving left" << std::endl;
		if (transform->position->x > currentTile->leftTile->transform->position->x) {
			transform->position->x -= speed;
			transform->position->z = currentTile->transform->position->z;
		}
		if (transform->position->x <= currentTile->leftTile->transform->position->x) {
			currentTile = currentTile->leftTile;	
			isWalking = false;
		}
	}
	else if (targetCube == currentTile->rightTile) {
		rotation = 270;
		if (transform->position->x < currentTile->rightTile->transform->position->x) {
			transform->position->x += speed;
			transform->position->z = currentTile->transform->position->z;
		}
		if (transform->position->x >= currentTile->rightTile->transform->position->x){
			currentTile = currentTile->rightTile;
			isWalking = false;
		}
	}
	else if (targetCube == currentTile->upTile) {
		rotation = 0;
		if (transform->position->z > currentTile->upTile->transform->position->z) {
			transform->position->z -= speed;
			transform->position->x = currentTile->transform->position->x;
		}
		if (transform->position->z <= currentTile->upTile->transform->position->z) {
			currentTile = currentTile->upTile;	
			isWalking = false;
		}
	}
	else if (targetCube == currentTile->downTile) {
		rotation = 180;
		if (transform->position->z < currentTile->downTile->transform->position->z) {
			transform->position->z += speed;
			transform->position->x = currentTile->transform->position->x;
		}
		if (transform->position->z >= currentTile->downTile->transform->position->z) {
			currentTile = currentTile->downTile;
			isWalking = false;
		}
	}
}

Ghost::Ghost(MainGame * _mainGame, CubeTile * startTile, int _floor)
{
	mainGame = _mainGame;
	object = LoadObject("PacmanGhost.obj");
	transform = new Transform();
	currentTile = startTile;
	floor = _floor;
	transform->position->x = currentTile->transform->position->x;
	transform->position->y = currentTile->transform->position->y;
	transform->position->z = currentTile->transform->position->z;
	speed = 0.1;
	rotation = 0;
	startTime = clock();
	isInStair = false;
	behavior = new PatrolBehavior(mainGame, this, mainGame->GetPlayer());
	targetCube = currentTile;
	isWalking = false;
}

Ghost::Ghost()
{
}


Ghost::~Ghost()
{
}

void Ghost::Draw()
{
	glPushMatrix();
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glRotatef(rotation, 0, 1, 0);
	glColor3f(1.0, 0.5, 0.5);
	//glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0.5f, 0);
	glCallList(object);
	glPopMatrix();
}

void Ghost::Update()
{
	behavior->Update();
	if (!isWalking && !behavior->isProcessing) {
		if (behavior->targetCubes.size()>1) {
			if (currentTile == behavior->targetCubes.top())behavior->targetCubes.pop();
			targetCube = behavior->targetCubes.top();
		}
	}
	if (currentTile != targetCube)
		MoveToTargetTile();
	if (mainGame->currentPlayerFloor >= floor)
		Draw();
}
