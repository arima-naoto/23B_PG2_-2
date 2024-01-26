#pragma once
#include "Struct.h"

class Bullet
{
public:

	Bullet();

	~Bullet();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	bool GetIsShot() { return isShot_; };

	bool SetIsShot(int isShot) { return this->isShot_ = isShot; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

	bool isShot_;

};