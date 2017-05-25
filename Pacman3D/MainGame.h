#pragma once
class Window;
class Stage;
class Pacman;
class MainGame
{
	Window * window;
	int elapsedTime;
	CubeTile * cubeTile;
	std::string ReadMap(std::string filename);

	std::string map;
	Stage *firstStage;

	//player data
	Pacman *player;
	int playerScore;
	void CheckPlayerScore();
public:
	void SetPlayer();
	int currentPlayerFloor;
	int playerPosTileX;
	int playerPosTileY;

	MainGame(Window * _window);
	~MainGame();

	void Start();
	void ProcessInput();
	void Update(int time);
};

