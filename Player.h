#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Enemy.h"

class Player
{
public:

	Player();

	~Player();

	void Update(char *keys,char *preKeys, Enemy* enemy);

	void Draw();

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	Bullet* bullet;

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

