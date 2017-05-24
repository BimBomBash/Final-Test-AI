#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include "Window.h"
#include "GameObject.h"
#include "CubeTile.h"
#include "MainGame.h"


MainGame::MainGame(Window * _window)
{
	window = _window;
	cubeTile = new CubeTile();
	testRot = 0;
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
	}
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
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
		}
	}
}

void MainGame::Update(int time)
{
	elapsedTime = time;
	ProcessInput();
	window->ClearWindow();
	glLoadIdentity();
	glTranslatef(0, 0, -6);
	glRotatef(testRot, 0, 1, 0);
	glColor4f(1, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3d(0, 1, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(-1, 0, 0);
	glEnd();
	testRot+=1;
	cubeTile->Draw();
	window->SwapWindow();
}

