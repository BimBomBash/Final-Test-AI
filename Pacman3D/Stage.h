#pragma once
#include "GameObject.h"
class MainGame;
class Stage:public GameObject
{
	void BuildMap(std::string map);
	MainGame *mainGame;
public:
	//stage settings
	int ***stageMap;
	int stories, height, width;
	float storyHeight;
	float wallHeight;
	CubeTile ****tiles;
	std::vector<Wall*>walls;
	
	Stage();
	~Stage();
	Stage(MainGame *_maingame, int _stories, int _height, int _width, std::string map);
	void PrintStage();
	void Draw();
};

