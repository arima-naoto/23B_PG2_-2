#include "PlayerBullet.h"
#include "Novice.h"

PlayerBullet::PlayerBullet() 
{
	position_.x = 0;
	position_.y = -10;
	radius_ = 10;
	speed_ = 10;
	color_ = WHITE;

	isShot_ = false;

}

void PlayerBullet::Update() 
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

void PlayerBullet::Draw() 
{
	if (isShot_ == true) 
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}