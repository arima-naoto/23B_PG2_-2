#pragma once
#include "struct.h"

#pragma region //Bulletクラスの作成

class Bullet
{
public:

	static bool isShot_;//静的メンバ変数isShot_の宣言

	//Bulletクラスのメンバ関数の宣言

	Bullet();//インストラクタ

	~Bullet();//デストラクタ

	void Update();

	void Draw();

	//Bulletクラスのカプセル化とアクセッサの追加
	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

private://メンバ変数

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

#pragma endregion

