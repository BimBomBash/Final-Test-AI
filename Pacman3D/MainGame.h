#pragma once

class MainGame
{
	Window * window;
	float xOldMousePosition, xNewMousePosition;
	int elapsedTime;
	CubeTile * cubeTile;

	float testRot;
public:
	void ProcessInput();
	MainGame(Window * _window);
	~MainGame();
	void Start();
	void Update(int time);
};

