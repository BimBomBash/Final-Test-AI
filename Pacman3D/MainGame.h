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
	//Ghost *ghost;
	int playerScore;
	void CheckPlayerScore();
	void SetPlayer();
	void SetGhost();
	Pacman *player;
	std::vector<Ghost*> ghost;
public:
	Pacman *GetPlayer() { return player; }
	std::vector <Ghost*> GetGhost() { return ghost; }
	int currentPlayerFloor;
	int playerPosTileX;
	int playerPosTileY;

	MainGame(Window * _window);
	~MainGame();

	Stage *GetStage() { return firstStage;  }
	void Start();
	void ProcessInput();
	void Update(int time);
};

