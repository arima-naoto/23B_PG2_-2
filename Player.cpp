#include "Player.h"
#include "Novice.h"

Player::Player() 
{
	position_.x = 640;
	position_.y = 450;
	radius_ = 35;
	speed_ = 7;
	color_ = GREEN;

	playerbullet = new PlayerBullet();

}

Player::~Player(){
	delete playerbullet;
}

void Player::Update(char *keys, char* preKeys)
{

	if (keys[DIK_D]) {
		position_.x += speed_;
	}

	if (keys[DIK_A]) {
		position_.x -= speed_;
	}

	if (keys[DIK_W]) {
		position_.y -= speed_;
	}

	if (keys[DIK_S]) {
		position_.y += speed_;
	}

	if(keys[DIK_SPACE] && preKeys[DIK_SPACE] == false && playerbullet->isShot_ == false)
	{
		playerbullet->isShot_ = true;
		playerbullet->position_.x = position_.x;
		playerbullet->position_.y = position_.y;
	}

	playerbullet->Update();

}

void Player::Draw() 
{
	playerbullet->Draw();

	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}