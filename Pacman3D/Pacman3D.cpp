// Pacman3D.cpp : Defines the entry point for the console application.
//

#define PI 3.14159265359
#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include "GameObject.h"
#include "Window.h"
#include "CubeTile.h"
#include "Wall.h"
#include "Stage.h"
#include "MainGame.h"

float rTri = 0.1;
float rQuad = 0.1;


int main(int argc, char ** argv)
{
	Window *window;
	window = new Window("3D Pacman", 900, 450);
	SDL_Event sdlEvent;
	MainGame *mainGame;
	int cube;
	time_t start = clock();
	float xLicht1 = 0;
	if (window->initiated) {
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		//(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		float col[] = { 1.0,1.0,1.0,1.0 };
		glLightfv(GL_LIGHT0, GL_SPECULAR, col);
		xLicht1 -= 50;
		GLfloat light0Position[] = { 0, 20.0, 20.0, 20.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
		mainGame = new MainGame(window);
		mainGame->Start();
		while (true) {
			int time = (int)difftime(clock(), start);
			mainGame->Update(time);
		}
	}
	return 0;
}

