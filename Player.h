#pragma once
#include "Struct.h"

class Player
{
public:

	Player(Vector2 position, int radius, int speed, unsigned int color);

	~Player();

	void Update(char *keys);

	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};