#pragma once
#include "GameObject.h"
#include <vector>
#include "GameObject.h"
#include "CubeTile.h"
#include "Wall.h"
#include "Pacman.h"
#include "MainGame.h"
#include "Food.h"
class MainGame;
class Stage:public GameObject
{
	void BuildMap(std::string map);
	MainGame *mainGame;
public:
	//stage settings
	int playerStartFloor, playerStartY, playerStartX;
	int ***stageMap;
	int stories, height, width;
	float storyHeight;
	float wallHeight;
	CubeTile ****tiles;
	std::vector<glm::vec3*> enemyPos;
	std::vector<Wall*>walls;
	
	Stage();
	~Stage();
	Stage(MainGame *_maingame, int _stories, int _height, int _width, std::string map);
	void PrintStage();
	void Draw();
};

