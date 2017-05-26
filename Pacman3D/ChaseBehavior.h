#pragma once
#include "GhostBehavior.h"
class ChaseBehavior: public GhostBehavior
{
	Pacman *player;
public:
	int findWay(CubeTile * prev, CubeTile *root, CubeTile *_target);
	void Update() override;
	void Check() override;
	ChaseBehavior();
	ChaseBehavior(MainGame *_mainGame, Ghost *_ghost, Pacman *_pacman);
	~ChaseBehavior();
};

