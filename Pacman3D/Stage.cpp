#include "stdafx.h"
#include <GL\glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "GameObject.h"
#include "CubeTile.h"
#include "Wall.h"
#include "Stage.h"


void Stage::BuildMap(std::string map) {

	stageMap = new int**[stories];
	tiles = new CubeTile ***[stories];
	for (int i = 0; i < stories; i++) {
		stageMap[i] = new int *[height];
		tiles[i] = new CubeTile **[height];
		for (int j = 0; j < height; j++) {
			stageMap[i][j] = new int[width];
			tiles[i][j] = new CubeTile*[width];
		}
	}

	int stringIndex = 0;

	int h = 0;
	do {
		int i = 0;
		do {
			int j = 0;
			do {
				while ((map[stringIndex] != 'O' && map[stringIndex] != 'X'&& map[stringIndex] != 'S') && stringIndex < map.length()) {
					stringIndex++;
				}
				switch (map[stringIndex])
				{
				case 'O':
					stageMap[h][i][j] = 1;
					tiles[h][i][j] = new CubeTile(j, 0 + storyHeight*h, i, 1, ROAD);
					break;
				case 'X':
					stageMap[h][i][j] = 2;
					tiles[h][i][j] = new CubeTile(j, 0 + storyHeight*h, i, 1, WALL);
					break;
				case 'S':
					stageMap[h][i][j] = 3;
					tiles[h][i][j] = new CubeTile(j, 0 + storyHeight*h, i, 1, STAIR);
					break;
				}
				tiles[h][i][j]->floorNumber = h;
				if (stringIndex < map.length() - 1) stringIndex++;
				j++;
			} while (j < width && stringIndex < map.length());
			i++;
		} while (i < height);
		h++;
	} while (h < stories);

	for (int h = 0; h < stories; h++) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (tiles[h][i][j]->type == WALL) {
					bool left = true, up = true, right = true, down = true;
					if (i == 0 || tiles[h][i - 1][j]->type != WALL) up = false;
					if (i == height-1 || tiles[h][i + 1][j]->type != WALL) down = false;
					if (j == 0 || tiles[h][i][j-1]->type != WALL) left = false;
					if (i == width-1 || tiles[h][i][j+1]->type != WALL) right = false;
					Wall *temp = new Wall(tiles[h][i][j], 1, 0.25, left, up, right, down);
					temp->floorNumber = h;
					walls.push_back(temp);
				}
			}
		}
	}
}

Stage::Stage()
{
}


Stage::~Stage()
{
}

Stage::Stage(int _stories, int _height, int _width, std::string map)
{
	stories = _stories;
	height = _height;
	width = _width;
	storyHeight = 2;
	BuildMap(map);
	currentPlayerFloor = stories;
}

void Stage::PrintStage()
{
	for (int h = 0; h < stories; h++) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)std::cout << stageMap[h][i][j];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void Stage::Draw()
{
	for (int h = 0; h < currentPlayerFloor; h++) {
		glColor3f(0.3*(h + 1), 0, 0);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)tiles[h][i][j]->Draw();
		}
	}
	for (int i = 0; i < walls.size(); i++) {
		if (walls[i]->floorNumber < currentPlayerFloor) walls[i]->Draw();
	}
}
