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
	if (root->rightTile != nullptr && root->rightTile->type == ROAD && (root->rightTile->dijkstraValue == NULL || root->rightTile->dijkstraValue >= currentDistance + 1)) {
		i = 1 + CalculateClosestDistance(currentDistance + 1, root->rightTile, _target);
	}
	else i = 100000;
	if (root->leftTile != nullptr && root->leftTile->type == ROAD && (root->leftTile->dijkstraValue == NULL || root->leftTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->leftTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->upTile != nullptr && root->upTile->type == ROAD && (root->upTile->dijkstraValue == NULL || root->upTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->upTile, _target);
	}
	else j = 100000;
	if (j < i) {
		i = j;
	}

	if (root->downTile != nullptr && root->downTile->type == ROAD && (root->downTile->dijkstraValue == NULL || root->downTile->dijkstraValue >= currentDistance + 1)) {
		j = 1 + CalculateClosestDistance(currentDistance + 1, root->downTile, _target);
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
