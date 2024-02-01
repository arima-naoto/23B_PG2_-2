#pragma once
#include "Struct.h"

class Bullet
{
public:

	Bullet(Vector2 position,int radius,int speed,unsigned int color);

	~Bullet();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	static bool isShot;

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};