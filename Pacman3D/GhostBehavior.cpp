#include "stdafx.h"
#include <iostream>
#include "Ghost.h"
#include "Stage.h"
#include "MainGame.h"
#include "GhostBehavior.h"


int GhostBehavior::CalculateClosestDistance(int currentDistance, CubeTile * root, CubeTile * _target)
{
	root->dijkstraValue = currentDistance;
	int i = 100000;
	int j = 0;
	if (root == _target) {
		return 0;
	}
	if (root->rightTile != nullptr && root->rightTile->type != WALL && (root->rightTile->dijkstraValue == NULL || root->rightTile->dijkstraValue >= currentDistance + 1)) {
		i = 1 + CalculateClosestDistance(currentDistance + 1, root->rightTile, _target);
	}
	else i = 100000;
	if (root->leftTile != nullptr && root->leftTile->type != WALL && (root->leftTile->dijkstraValue == NULL || root->leftTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->leftTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->upTile != nullptr && root->upTile->type != WALL && (root->upTile->dijkstraValue == NULL || root->upTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->upTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->downTile != nullptr && root->downTile->type != WALL && (root->downTile->dijkstraValue == NULL || root->downTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->downTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->belowTile != nullptr && root->belowTile->type != WALL && (root->belowTile->dijkstraValue == NULL || root->belowTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->belowTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->topTile != nullptr && root->topTile->type != WALL && (root->topTile->dijkstraValue == NULL || root->topTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->topTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}
	return i;
}

int GhostBehavior::GetClosestDistance(int currentDistance, CubeTile * root, CubeTile * _target)
{
	for (int i = 0; i < floorY; i++) {
		for (int j = 0; j < floorX; j++) {
			mainGame->GetStage()->tiles[floor][i][j]->dijkstraValue = NULL;
		}
	}
	return GhostBehavior::CalculateClosestDistance(currentDistance, root, _target);
}

void GhostBehavior::Update()
{
	std::cout << "do nothing" << std::endl;
}

void GhostBehavior::Check()
{
}

GhostBehavior::GhostBehavior()
{
}


GhostBehavior::~GhostBehavior()
{
}
