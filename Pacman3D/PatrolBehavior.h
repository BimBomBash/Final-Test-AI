#pragma once
#include "GhostBehavior.h"
#include "CubeTile.h"
class PatrolBehavior :
	public GhostBehavior
{
	CubeTile *prevTile;
public:
	void Update() override;
	void Check() override;

	PatrolBehavior(MainGame *_mainGame, Ghost *_ghost, Pacman *_pacman);
	PatrolBehavior();
	~PatrolBehavior();
};

