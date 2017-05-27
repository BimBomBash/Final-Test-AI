#pragma once
#include "GhostBehavior.h"
#include  <stack>
class ChaseBehavior: public GhostBehavior
{
	void ResetDijkstra();

public:
	void Update() override;
	void Check() override;
	ChaseBehavior();
	ChaseBehavior(MainGame *_mainGame, Ghost *_ghost, Pacman *_pacman);
	~ChaseBehavior();
};

