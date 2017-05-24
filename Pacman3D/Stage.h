#pragma once
#include "GameObject.h"
class Stage:public GameObject
{
	void BuildMap(std::string map);
public:
	//stage settings
	int ***stageMap;
	int stories, height, width;
	float storyHeight;
	CubeTile ****tiles;
	std::vector<Wall*>walls;
	//player data
	int currentPlayerFloor;
	
	Stage();
	~Stage();
	Stage(int _stories, int _height, int _width, std::string map);
	void PrintStage();
	void Draw();
};

