#include "Enemy.h"

void Enemy::Initalize()
{
	position_.x = 640;
	position_.y = 150;
	radius_ = 20;
	speed_.x = 7;
	speed_.y = 7;

	color_ = RED;

	RespornTimer_ = 120;

	Hp_ = 3;

	isAlive_ = true;

}

void Enemy::Update()
{

	if(isAlive_ == true)
	{
		position_.x += speed_.x;
		position_.y += speed_.y;

		if(position_.x >= 1260 || position_.x <= 20)
		{
			speed_.x *= -1;
		}

		if (position_.y >= 700 || position_.y <= 20)
		{
			speed_.y *= -1;
		}

	}
}

void Enemy::Draw()
{
	if(isAlive_ == true)
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}

void Enemy::OnCollision()
{
	if (isAlive_ == false)
	{
		RespornTimer_--;

		if (RespornTimer_ <= 0)
		{
			isAlive_ = true;
			RespornTimer_ = 120;
			Hp_ -= 1;
		}
	}
}
