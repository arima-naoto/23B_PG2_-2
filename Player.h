#pragma once
#include "Object.h"

#pragma region //Objectクラスを継承したPlayerクラスを作成

class Player : public Object
{

public://メンバ関数

	Player();//インスタンス

	~Player();//デストラクタ

	void Update(char *keys);//更新処理メンバ関数

	void Draw();//描画処理メンバ関数

};

#pragma endregion

