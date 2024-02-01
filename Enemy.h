#pragma once
#include "Struct.h"

class Enemy
{
public:

	void Initalize(Vector2 position, int radius, int speed, unsigned int color);

	void Update();

	void Draw();

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};