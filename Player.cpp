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

void Player::Update(char *keys, char* preKeys,Enemy *enemy)
{
	
	if(keys[DIK_D])
	{
		position_.x += speed_;
	}

	if(keys[DIK_A])
	{
		position_.x -= speed_;
	}

	if (keys[DIK_S])
	{
		position_.y += speed_;
	}

	if (keys[DIK_W])
	{
		position_.y -= speed_;
	}

	if(keys[DIK_SPACE] && preKeys[DIK_SPACE] == false && bullet->isShot_ == false)
	{
		bullet->isShot_ = true;

		Vector2 TempPlayerPosition = GetPos();

		bullet->SetPosition(TempPlayerPosition);

	}

	bullet->Update();

	if (enemy->isAlive_ == false)
	{
		enemy->RespornTimer_--;

		if (enemy->RespornTimer_ <= 0)
		{
			enemy->isAlive_ = true;
			enemy->RespornTimer_ = 120;
			enemy->Hp_ -= 1;
		}
	}
}

void Player::Draw()
{
	bullet->Draw();

	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}