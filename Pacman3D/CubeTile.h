#pragma once
#include "GameObject.h"

class Food;
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
	Food *food;
	int floorNumber;
	CubeTile(float _x, float _y, float _z, float _scale, Type _type);
	~CubeTile();
	void Draw();
	void Update();
	void DeleteFood();

	CubeTile *upTile, *downTile, *leftTile, *rightTile, *topTile,*belowTile;
};

