#pragma once
#include <stack>
#include "CubeTile.h"
#include "Pacman.h"
class MainGame;
class Ghost;
class GhostBehavior
{
protected:
	MainGame *mainGame;
	Ghost *ghost;	
	int floor, floorX, floorY;
	Pacman *player;
	CubeTile *playerLastPos;
public:
	int CalculateClosestDistance(int currentDistance, CubeTile * root, CubeTile *_target);
	int GetClosestDistance(int currentDistance, CubeTile * root, CubeTile *_target);
	std::stack<CubeTile*> targetCubes;
	bool isProcessing;
	virtual void Update();
	virtual void Check();
	GhostBehavior();
	~GhostBehavior();
};

