#pragma once
#include "Struct.h"

class Bullet
{
public:

	Bullet();

	void Update();

	void Draw();

public:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

	bool isShot_;

};