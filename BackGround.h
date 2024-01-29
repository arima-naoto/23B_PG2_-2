#pragma once
#include "Struct.h"
#include "Novice.h"

class BackGround
{
public:

	virtual ~BackGround();

	virtual void Update();

	virtual void Draw();

public:

	Vector2 position_;

	int speedY_;

	unsigned int color_;

};

