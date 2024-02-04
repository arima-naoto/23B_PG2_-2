#pragma once
#include "struct.h"

class Enemy
{
public:

	void Initalize();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	int Hp_;

	int RespornTimer_;

	bool isAlive_;

private:

	Vector2 position_;

	int radius_;

	Vector2 speed_;

	unsigned int color_;

};

