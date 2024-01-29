#include "BackGroundB.h"

BackGroundB::BackGroundB()
{
	position_.x = 0;
	position_.y = -720;

	speedY_ = 2;
	color_ = WHITE;

}

BackGroundB::~BackGroundB() {}

void BackGroundB::Update()
{
	position_.y += speedY_;

	if (position_.y >= 720)
	{
		position_.y = -720;
	}
}

void BackGroundB::Draw()
{

	int BackGroundHandle = Novice::LoadTexture("./Resources/images/bg.png");

	Novice::DrawSprite(position_.x, position_.y, BackGroundHandle, 1, 1, 0.0f, color_);
}