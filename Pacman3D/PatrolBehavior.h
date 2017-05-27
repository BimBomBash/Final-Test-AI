#pragma once
#include "GhostBehavior.h"
class PatrolBehavior :
	public GhostBehavior
{
public:
	void Update() override;
	void Check() override;
	PatrolBehavior(MainGame *_mainGame, Ghost *_ghost, Pacman *_pacman);
	PatrolBehavior();
	~PatrolBehavior();
};

