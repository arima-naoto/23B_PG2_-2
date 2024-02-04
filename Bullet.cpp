#include "Bullet.h"

Bullet::Bullet()
{
	position_.x = 0;
	position_.y = -10;
	radius_ = 20;
	speed_ = 10;

	color_ = WHITE;
}

Bullet::~Bullet() {}

void Bullet::Update()
{
	if (isShot_ == true)
	{
		position_.y -= speed_;

		if (position_.y <= -20)
		{
			isShot_ = false;
		}
	}
}

void Bullet::Draw()
{
	if (isShot_ == true)
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}
