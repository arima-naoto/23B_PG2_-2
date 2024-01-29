#pragma once
#include "BackGround.h"

class BackGroundA : public BackGround
{
public:

	BackGroundA();

	~BackGroundA();

	void Update() override;

	void Draw() override;

};
