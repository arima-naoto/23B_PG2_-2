#pragma once
#include "Struct.h"

class Enemy
{
public:

	void Initalize();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

	bool GetIsAlive() { return isAlive_; };

	bool SetIsAlive(bool isAlive) { return this->isAlive_ = isAlive; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

	bool isAlive_;

};