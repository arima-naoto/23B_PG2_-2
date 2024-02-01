#include "Player.h"

Player::Player() 
{
	position_.x = 640;
	position_.y = 550;
	radius_ = 35;
	speed_ = 7;
	color_ = GREEN;

	bullet = new Bullet();
}

Player::~Player()
{
	delete bullet;
}

void Player::Update(char *keys,char *preKeys)
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

	bool TempIsShot = bullet->GetShot();

	Vector2 TempPlayerPosition = GetPos();

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false && bullet->SetShot(TempIsShot) == false) 
	{
		TempIsShot = true;

		bullet->SetShot(TempIsShot);

		bullet->SetPosition(TempPlayerPosition);

	}

	bullet->Update();

}

void Player::Draw()
{

	bullet->Draw();

	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}