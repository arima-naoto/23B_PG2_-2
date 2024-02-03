#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{
public:

	Player();

	~Player();

	void Update(char *keys,char *preKeys);

	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

	Bullet* bullet;

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

