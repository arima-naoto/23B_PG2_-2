#pragma once
#include "Struct.h"
#include "PlayerBullet.h"

class Player : public PlayerBullet
{
public:

	Player();

	~Player();

	void Update(char* keys,char *preKeys);

	void Draw();

	PlayerBullet* playerbullet;

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};
