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
#include "MainGame.h"


MainGame::MainGame(Window * _window)
{
	window = _window;
	cubeTile = new CubeTile();
	testRot = 0;
	cubeTile->transform->position->z = -6;
	//map = "OO XO | OX XO | OO XX";
	map = ReadMap("Level1.txt");
	firstStage = new Stage(3, 10, 10, map);
	firstStage->PrintStage();
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

	// write the data at the screen.
	//std::cout << data << std::endl;

	// close the opened file.
	infile.close();
	return data;
}

void MainGame::ProcessInput()
{
	SDL_Event event;

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
	}
	if (state[SDL_SCANCODE_DOWN]||state[SDL_SCANCODE_S]) {
	}
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
		if (firstStage->currentPlayerFloor<firstStage->stories)firstStage->currentPlayerFloor++;
	}
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
		if (firstStage->currentPlayerFloor>1)firstStage->currentPlayerFloor--;
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
	window->ClearWindow();
	glLoadIdentity();
	glTranslatef(0, -1, -20);
	glRotatef(30, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	glTranslatef(-(firstStage->width-1) / 2, -(firstStage->currentPlayerFloor-1)*firstStage->stories/2,-firstStage->height/2);
	firstStage->Draw();
	window->SwapWindow();
	SDL_Delay(100);
}

