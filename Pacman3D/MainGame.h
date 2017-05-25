#pragma once
class Window;
class Stage;
class Pacman;
class MainGame
{
	Window * window;
	float xOldMousePosition, xNewMousePosition;
	int elapsedTime;
	CubeTile * cubeTile;
	std::string ReadMap(std::string filename);

	std::string map;
	Stage *firstStage;

	//player data
	Pacman *player;
	void SetPlayer();
	int playerScore;
	void CheckPlayerScore();
public:
	int currentPlayerFloor;
	int playerPosTileX;
	int playerPosTileY;

	MainGame(Window * _window);
	~MainGame();

	void Start();
	void ProcessInput();
	void Update(int time);
};

