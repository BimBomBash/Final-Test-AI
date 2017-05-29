#pragma once
#include "GameObject.h"
#include "GhostBehavior.h"
#include "CubeTile.h"
#include "GhostBehavior.h"
#include "ChaseBehavior.h"
#include "PatrolBehavior.h"

class Ghost :
	public GameObject
{
	MainGame *mainGame;
	float speed, rotation;
	int startTime;
	bool isInStair;
	ChaseBehavior *chaseBehavior;
	PatrolBehavior *patrolBehavior;
public:
	int floor;
	GhostBehavior *behavior;
	CubeTile *currentTile;
	bool isWalking;
	CubeTile * targetCube;
	void MoveToTargetTile();
	Ghost(MainGame *_mainGame, CubeTile * startTile, int _floor);
	Ghost();
	~Ghost();

	void ToChaseBehavior();
	void ToPatrolBehavior();
	void Draw();
	void Update();
};

