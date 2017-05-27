#pragma once
#include <stack>
#include "CubeTile.h"
class MainGame;
class Ghost;
class GhostBehavior
{
protected:
	MainGame *mainGame;
	Ghost *ghost;	
public:
	std::stack<CubeTile*> targetCubes;
	bool isProcessing;
	virtual void Update();
	virtual void Check();
	GhostBehavior();
	~GhostBehavior();
};

