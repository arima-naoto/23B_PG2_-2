#pragma once
#include "Struct.h"

#pragma region //Objectクラスの作成

class Object
{
protected://メンバ変数

	Vector2 position_;//座標

	int radius_;//半径

	int speed_;//移動速度

	unsigned int color_;//色

};

#pragma endregion