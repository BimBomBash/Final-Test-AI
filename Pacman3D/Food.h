#pragma once
#include "GameObject.h"
class Food :public GameObject
{
public:
	bool isBig;
	bool wasEaten;
	Food();
	Food(bool _isBig, Transform *_transform);
	void Draw();
	void Update();
	~Food();
};

