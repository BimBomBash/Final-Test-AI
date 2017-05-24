#pragma once
#include "GameObject.h"
class CubeTile;
class Wall : public GameObject
{
	void DrawCube(int direction);
	void DrawTube(int segments);
	CubeTile *tile;
	float height;
	float width;
	bool left, up, right, down;
public:
	Wall();
	int floorNumber;
	Wall(CubeTile *_tile, float _height, float _width, bool _left, bool _up, bool _right, bool _down);
	void Draw();
	void Update();
	~Wall();

};

