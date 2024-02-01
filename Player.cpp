#include "Player.h"

Player::Player(Vector2 position,int radius,int speed,unsigned int color)
{
	position_ = position;
	radius_ = radius;
	speed_ = speed;
	color_ = color;

	bullet = new Bullet({ 0,-10 }, 20, 10, WHITE);
}

Player::~Player(){}

void Player::Update(char *keys,char *preKeys)
{
	if (keys[DIK_D]) 
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

	Vector2 TempPlayerPosition = GetPos();

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false && Bullet::isShot == false) 
	{
		Bullet::isShot = true;
		bullet->SetPosition(TempPlayerPosition);
	}

	bullet->Update();

}

void Player::Draw()
{

	bullet->Draw();

	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}