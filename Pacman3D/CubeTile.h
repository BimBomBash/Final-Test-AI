#pragma once
#include "GameObject.h"

enum Type
{
	ROAD,
	WALL,
	STAIR
};

class CubeTile:public GameObject
{
public:
	Type type;
	CubeTile();
	CubeTile(float _x, float _y, float _z, float _scale, Type _type);
	~CubeTile();
	void Draw();
	void Update();
};

