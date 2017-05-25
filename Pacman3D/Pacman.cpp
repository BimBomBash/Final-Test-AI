#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "GameObject.h"
#include "CubeTile.h"
#include "Pacman.h"


void Pacman::MoveUp()
{
	std::cout << currentTile->transform->position->y << std::endl;
	currentTile = currentTile->topTile;
	transform->position->y = currentTile->transform->position->y;
	std::cout << currentTile->transform->position->y << std::endl << std::endl;
}

void Pacman::MoveRight()
{
	if (currentTile->rightTile != nullptr && currentTile->rightTile->type == ROAD) {
		std::cout << "Moving Right, MOTHERFUCKER" << std::endl;
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
	std::cout << currentTile->transform->position->y << std::endl;
	currentTile = currentTile->belowTile;
	transform->position->y = currentTile->transform->position->y;
	std::cout << currentTile->transform->position->y << std::endl << std::endl;
}

void Pacman::MoveLeft()
{
	if (currentTile->leftTile != nullptr && currentTile->leftTile->type == ROAD) {
		std::cout << "Moving Left, MOTHERFUCKER" << std::endl;
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
	if (currentTile->upTile != nullptr && currentTile->upTile->type == ROAD) {
		std::cout << "Moving Forward, MOTHERFUCKER" << std::endl;
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
	if (currentTile->downTile != nullptr && currentTile->downTile->type == ROAD) {
		std::cout << "Moving Backward, MOTHERFUCKER" << std::endl;
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
	glTranslatef(transform->position->x, transform->position->y, transform->position->z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0.5f, 0);
	glCallList(object);
	glPopMatrix();
}

void Pacman::Update()
{
	Draw();
}

Pacman::Pacman()
{
	object = LoadObject("PacmanMouthOpen.obj");
	transform = new Transform();
	currentTile = new CubeTile();
}

Pacman::Pacman(CubeTile * startTile)
{
	object = LoadObject("PacmanMouthOpen.obj");
	transform = new Transform();
	currentTile = startTile;
	//memcpy(currentTile, startTile, sizeof(CubeTile));
	transform->position->x = currentTile->transform->position->x;
	transform->position->y = currentTile->transform->position->y;
	transform->position->z = currentTile->transform->position->z;
	speed = 0.1;
	rotation = 0;
}


Pacman::~Pacman()
{
}
