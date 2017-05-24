#pragma once
#include <glm.hpp>

struct Transform {
	glm::vec3 *position;
	glm::vec3 *rotation;
	glm::vec3 *scale;
	Transform() {
		position = new glm::vec3(0, 0, 0);
		rotation = new glm::vec3(0, 0, 0);
		scale = new glm::vec3(1, 1, 1);
	}
	float DistanceXZto(glm::vec3 * a) {
		return sqrt((position-> x - a->x)*(position-> x - a->x) + (position-> z - a->z)*(position->z - a->z));
	}
};

struct Coordinate {
	float x, y, z;
	Coordinate(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
};

struct Face {
	int faceNum;
	bool four;
	int faces[4];
	Face(int _faceNum, int f1, int f2, int f3) :faceNum(_faceNum) {
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		four = false;
	}
	Face(int _faceNum, int f1, int f2, int f3, int f4) :faceNum(_faceNum) {
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		faces[3] = f4;
		four = true;
	}
};

class GameObject
{
protected:
	int object;
	float rTri = 0;
public:
	Transform *transform;
	int LoadObject(const char* _filename);
	virtual void Draw();
	virtual void Update();
	GameObject();
	~GameObject();
};

