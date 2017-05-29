#pragma once
class GameObject;
class MainGame;
enum MovingDirection {
	UP, RIGHT, DOWN, LEFT
};

class Pacman:public GameObject
{
	float speed;
	int currentFloor;
	int startFloor;
	CubeTile *prevTile;
	CubeTile *spawnPosTile;
	MovingDirection moveDir;
	float rotation;
	bool mouthOpened;
	float mouthTimeIntervalinSeconds;
	time_t startTime;
	bool isInStair;
	MainGame *mainGame;

	void changeMesh();
	void checkStair();
public:
	int lifePoint;
	CubeTile *currentTile;

	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	void MoveForward();
	void MoveBackward();
	void Draw();
	void Update();
	void Kill();
	Pacman();
	Pacman(MainGame *_mainGame, CubeTile * startTile);
	~Pacman();
};

