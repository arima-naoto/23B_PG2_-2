#include "Player.h"

Player::Player() 
{
	position_.x = 640;
	position_.y = 550;
	radius_ = 35;
	speed_ = 7;
	color_ = GREEN;
}

Player::~Player(){}

void Player::Update(char *keys)
{
	if(keys[DIK_D])
	{
		position_.x += speed_;
	}

	if (keys[DIK_A]) 
	{
		position_.x -= speed_;
	}

	if (keys[DIK_W])
	{
		position_.y -= speed_;
	}

	if (keys[DIK_S])
	{
		position_.y += speed_;
	}
}

void Player::Draw()
{
	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}