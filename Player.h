#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Enemy.h"

#pragma region //Playerクラスの作成

class Player
{
public:

	static bool isHit_;//静的メンバ変数isHit_を宣言する

	//Playerクラスのメンバ関数の宣言

	Player();//インストラクタ

	~Player();//デストラクタ

	void Update(char *keys,char *preKeys, Enemy* enemy);

	void Draw();

	//Playerクラスのカプセル化とアクセッサの追加

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	//Bulletクラスを包含

	Bullet* bullet;

private://メンバ変数

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

