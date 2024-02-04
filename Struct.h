#pragma once
#include "Novice.h"

typedef struct Vector2
{
	int x;
	int y;
}Vector2;

enum GameScene
{
	TITLE,
	GAME,
	CLEAR,
	DEAD,
};