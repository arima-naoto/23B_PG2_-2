#pragma once
#include "struct.h"

#pragma region //Enemyクラスの作成

class Enemy
{
public:

	//Enemyクラスのメンバ関数の宣言

	void Initalize();

	void Update();

	void Draw();

	void OnCollision();

	//Enemyクラスのカプセル化とアクセッサを追加

	Vector2 GetPos() { return position_; };

	void SetPosition(Vector2 position) { this->position_ = position; };

	int GetRadius() { return radius_; };

	//public型変数の宣言

	int Hp_;

	int RespornTimer_;

	bool isAlive_;

private://メンバ変数

	Vector2 position_;

	int radius_;

	Vector2 speed_;

	unsigned int color_;

};

#pragma endregion