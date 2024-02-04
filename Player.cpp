#include "Player.h"

//Playerクラスの初期化処理
Player::Player()
{
	position_.x = 640;
	position_.y = 550;
	radius_ = 30;
	speed_ = 7;

	color_ = GREEN;

	//Bulletクラスのインスタンスを作成
	bullet = new Bullet();

}

//デストラクタ処理
Player::~Player()
{
	delete bullet;
}

//Playerクラスの更新処理
void Player::Update(char *keys, char* preKeys,Enemy *enemy)
{
	
	//====================================================<キー入力による更新処理>======================================================

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

	//リスポーン処理用メンバ関数OnCollisionを呼び出す
	enemy->OnCollision();
}

//Playerクラスの描画処理
void Player::Draw()
{
	bullet->Draw();

	Novice::DrawEllipse(position_.x, position_.y, radius_, radius_, 0.0f, color_, kFillModeSolid);
}