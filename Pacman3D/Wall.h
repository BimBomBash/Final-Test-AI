#pragma once
#include "GameObject.h"
#include "CubeTile.h"
class Wall : public GameObject
{
	void DrawCube(float _rotation);
	CubeTile *tile;
public:
	Wall();
	Wall(CubeTile *_tile, int _left, int _up, int _right, int _down);
	void Draw();
	void Update();
	~Wall();

};

