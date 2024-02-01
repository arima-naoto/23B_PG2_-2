#pragma once
#include "struct.h"

class Enemy
{
public:

	void Initalize();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

	bool GetAlive() { return isAlive_; };

	bool SetAlive(bool isAlive) { return this->isAlive_ = isAlive; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

	bool isAlive_;

};

