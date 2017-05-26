#pragma once
#include "GameObject.h"
#include "GhostBehavior.h"
#include "CubeTile.h"
class Ghost :
	public GameObject
{
	MainGame *mainGame;
	float speed, rotation;
	int startTime;
	int floor;
	bool isInStair;

public:
	GhostBehavior *behavior;
	CubeTile *currentTile;
	bool isWalking;
	CubeTile * targetCube;
	void MoveToTargetTile();
	Ghost(MainGame *_mainGame, CubeTile * startTile, int _floor);
	Ghost();
	~Ghost();

	void Draw();
	void Update();
};
