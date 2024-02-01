#include "Bullet.h"

Bullet::Bullet(Vector2 position,int radius,int speed,unsigned int color)
{
	position_ = position;
	radius_ = radius;
	speed_ = speed;
	color_ = color;
}

Bullet::~Bullet(){}

void Bullet::Update()
{
	if(isShot == true)
	{
		position_.y -= speed_;

		if(position_.y <= -20)
		{
			isShot = false;
		}
	}
}

void Bullet::Draw() 
{
	if(isShot == true)
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}