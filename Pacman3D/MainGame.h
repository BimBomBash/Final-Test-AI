#pragma once

class MainGame
{
	Window * window;
	float xOldMousePosition, xNewMousePosition;
	int elapsedTime;
	CubeTile * cubeTile;
	std::string ReadMap(std::string filename);

	float testRot;
	std::string map;
	Stage *firstStage;
public:
	void ProcessInput();
	MainGame(Window * _window);
	~MainGame();
	void Start();
	void Update(int time);
};

