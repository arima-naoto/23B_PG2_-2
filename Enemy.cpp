#include "Enemy.h"
#include "Novice.h"

void Enemy::Initalize(Vector2 position, int radius, int speed, unsigned int color)
{
	position_ = position;
	radius_ = radius;
	speed_ = speed;
	color_ = color;
}

void Enemy::Update()
{

	if (isAlive == true) 
	{
		position_.x += speed_;

		if (position_.x >= 1260 || position_.x <= 20)
		{
			speed_ *= -1;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive == true) 
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}