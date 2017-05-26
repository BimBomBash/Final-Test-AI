#pragma once
class MainGame;
class Ghost;
class GhostBehavior
{
protected:
	MainGame *mainGame;
	Ghost *ghost;
public:
	virtual void Update();
	virtual void Check();
	GhostBehavior();
	~GhostBehavior();
};

