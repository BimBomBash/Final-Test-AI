#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include "Window.h"
#include "GameObject.h"
#include "CubeTile.h"
#include "Wall.h"
#include "Stage.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Food.h"
#include "GhostBehavior.h"
#include "ChaseBehavior.h"
#include "MainGame.h"


MainGame::MainGame(Window * _window)
{
	window = _window;
	cubeTile = new CubeTile();
	cubeTile->transform->position->z = -6;
	map = ReadMap("Level1.txt");
	playerScore = 0;
	firstStage = new Stage(this, 3, 10, 10, map);
	firstStage->PrintStage();
	SetPlayer();
	SetGhost();
}

MainGame::~MainGame()
{
}

void MainGame::Start()
{
}

float DistanceFromStageCenter(float x, float z) {
	return (sqrtf((x * x)+(z * z)));
}

std::string MainGame::ReadMap(std::string filename)
{
	std::string data;

	std::ifstream infile;
	infile.open(filename);

	std::cout << "Reading from the file" << std::endl;
	infile >> data;

	char buf[256];
	while (!infile.eof()) {
		infile.getline(buf,256);
		std::string *temp = new std::string(buf);
		data += *temp;
	}

	infile.close();
	return data;
}

void MainGame::SetPlayer()
{
	currentPlayerFloor = firstStage->playerStartFloor;
	playerPosTileX = firstStage->playerStartX;
	playerPosTileY = firstStage->playerStartY;
	player = new Pacman(this,firstStage->tiles[currentPlayerFloor][playerPosTileY][playerPosTileX]);
}

void MainGame::SetGhost()
{
	for (int i = 0; i < firstStage->enemyPos.size(); i++) {
		int floor = firstStage->enemyPos[i]->x;
		int y = firstStage->enemyPos[i]->y;
		int x = firstStage->enemyPos[i]->z;
		ghost.push_back( new Ghost(this, firstStage->tiles[floor][y][x],floor));
	}
}

void MainGame::CheckPlayerScore()
{
	if (player->currentTile->type == ROAD && player->currentTile->food!= nullptr &&!player->currentTile->food->wasEaten) {
		if (player->currentTile->food->isBig) playerScore += 20;
		else playerScore += 10;
		//std::cout << playerScore << std::endl;
		player->currentTile->DeleteFood();
	}
}

void MainGame::ProcessInput()
{
	SDL_Event event;

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
		player->MoveForward();
	}
	if (state[SDL_SCANCODE_DOWN]||state[SDL_SCANCODE_S]) {
		player->MoveBackward();
	}
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
		player->MoveLeft();
	}
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
		player->MoveRight();
	}
	if (state[SDL_SCANCODE_SPACE]) {
	}

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			window->Close();
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_MOUSEBUTTONDOWN:;
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_KEYDOWN:
			break;
		case SDL_SCANCODE_X:
			break;
		case SDL_SCANCODE_Z:
			break;
		}
	}
}

void MainGame::Update(int time)
{
	elapsedTime = time;
	ProcessInput();
	CheckPlayerScore();

	window->ClearWindow();
	glLoadIdentity();
	glTranslatef(0, -1, -20);
	glRotatef(30, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	glTranslatef(-(firstStage->width-1) / 2, -(currentPlayerFloor-1)*firstStage->stories/2,-firstStage->height/2);
	if (player->lifePoint >= 0) {
		player->Update();
		for (int i = 0; i < ghost.size(); i++) ghost[i]->Update();
		firstStage->Draw();
	}
	window->SwapWindow();
	SDL_Delay(10);
}

