#pragma once
#include "struct.h"

class Enemy
{
public:

	static bool isAlive_;

	int RespornTimer_;

	void Initalize();

	void OnCollision();

	void Update();

	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

