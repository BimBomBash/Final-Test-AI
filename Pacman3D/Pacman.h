#pragma once
class GameObject;
enum MovingDirection {
	UP, RIGHT, DOWN, LEFT
};

class Pacman:public GameObject
{
	float speed;
	int currentFloor;
	CubeTile *prevTile;
	MovingDirection moveDir;
	float rotation;
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
	Pacman();
	Pacman(CubeTile * startTile);
	~Pacman();
};

