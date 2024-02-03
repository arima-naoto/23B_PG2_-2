#pragma once
#include "struct.h"

class Bullet
{
public:

	static bool isShot_;

	Bullet();

	~Bullet();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

