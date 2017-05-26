#pragma once
#include <vector>
class Window;
class Stage;
class Pacman;
class Ghost;
class CubeTile;
class MainGame
{
	Window * window;
	int elapsedTime;
	CubeTile * cubeTile;
	std::string ReadMap(std::string filename);

	std::string map;
	Stage *firstStage;

	//player data
	std::vector<Ghost*> ghost;
	//Ghost *ghost;
	int playerScore;
	void CheckPlayerScore();
	void SetPlayer();
	void SetGhost();
	Pacman *player;
public:
	Pacman *GetPlayer() { return player; }
	int currentPlayerFloor;
	int playerPosTileX;
	int playerPosTileY;

	MainGame(Window * _window);
	~MainGame();

	void Start();
	void ProcessInput();
	void Update(int time);
};

