#include "Player.h"
#include "Novice.h"

Player::Player(Vector2 position, int radius, int speed, unsigned int color)
{
	position_ = position;
	radius_ = radius;
	speed_ = speed;
	color_ = color;
}

Player::~Player(){}

void Player::Update(char *keys)
{
	if(keys[DIK_D])
	{
		position_.x += speed_;
	}

	if(keys[DIK_A])
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