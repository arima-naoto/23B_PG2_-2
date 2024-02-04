#include "Bullet.h"

//Bulletクラスの初期化処理
Bullet::Bullet()
{
	position_.x = 0;
	position_.y = -10;
	radius_ = 20;
	speed_ = 10;

	color_ = WHITE;
}

//デストラクタ処理
Bullet::~Bullet() {}

//Bulletクラスの更新処理
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

//Bulletクラスの描画処理
void Bullet::Draw()
{
	if (isShot_ == true)
	{
		Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
	}
}
