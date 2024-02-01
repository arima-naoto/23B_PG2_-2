#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 更新処理用のメンバ関数Updateを作成
	/// </summary>
	void Update(char *keys,char *preKeys);

	/// <summary>
	/// 描画処理用のメンバ関数Drawを作成
	/// </summary>
	void Draw();

	Vector2 GetPos() { return position_; };

	int GetRadius() { return radius_; };

	Bullet* bullet;

private:

	Vector2 position_;

	int radius_;

	int speed_;

	unsigned int color_;

};

