#pragma once
#include "BackGround.h"

class BackGroundB : public BackGround
{
public:

	BackGroundB();

	~BackGroundB();

	void Update() override;

	void Draw() override;

};