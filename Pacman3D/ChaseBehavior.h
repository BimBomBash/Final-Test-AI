#pragma once
#include "GhostBehavior.h"
#include  <stack>
class ChaseBehavior: public GhostBehavior
{
	Pacman *player;
	int floor, floorX, floorY;
	void ResetDijkstra();
	CubeTile *playerLastPos;

public:
	int mapDistance(int currentDistance, CubeTile *root, CubeTile *_target);
	void Update() override;
	void Check() override;
	ChaseBehavior();
	ChaseBehavior(MainGame *_mainGame, Ghost *_ghost, Pacman *_pacman);
	~ChaseBehavior();
};

