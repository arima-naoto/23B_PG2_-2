#pragma once
#include "Struct.h"

class Player
{
public:

	Player();

	~Player();

	void Update(char *keys);

	void Draw();

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

