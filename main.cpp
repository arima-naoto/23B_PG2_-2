#include <Novice.h>
#include <Player.h>
#include <Enemy.h>

const char kWindowTitle[] = "GC1C_02_アリマ_ナオト";
const int Window_Width = 1280;
const int Window_Height = 720;

bool Bullet::isShot_ = false;

bool EnemyCollision(Vector2 obj1, Vector2 obj2,int obj1radius,int obj2radius)
{
	if(obj1.x - obj1radius <= obj2.x + obj2radius && obj2.x - obj2radius <= obj1.x + obj1radius && 
	   obj1.y - obj1radius <= obj2.y + obj2radius && obj2.y - obj2radius <= obj1.y + obj1radius)
	{
		return true;
	}

	return false;
}

bool PlayerCollision(Vector2 obj2, Vector2 obj3, int obj2radius, int obj3radius)
{
	if (obj2.x - obj2radius <= obj3.x + obj3radius && obj3.x - obj3radius <= obj2.x + obj2radius &&
		obj2.y - obj2radius <= obj3.y + obj3radius && obj3.y - obj3radius <= obj2.y + obj2radius)
	{
		return true;
	}

	return false;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, Window_Width, Window_Height);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy = new Enemy();
	enemy->Initalize();

	GameScene Scene = TITLE;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (Scene) {

		case TITLE:

			player->SetPosition({ 640,550 });

			Bullet::isShot_ = false;

			enemy->SetPosition({ 640,150 });
			enemy->Hp_ = 3;
			enemy->RespornTimer_ = 120;
			enemy->isAlive_ = true;

		case GAME:

			player->Update(keys, preKeys,enemy);

			enemy->Update();

			if(EnemyCollision(player->bullet->GetPos(), enemy->GetPos(), player->bullet->GetRadius(), enemy->GetRadius()))
			{
				enemy->isAlive_ = false;
			}

			if(PlayerCollision(enemy->GetPos(),player->GetPos(),enemy->GetRadius(),player->GetRadius()))
			{
				Player::isHit_ = true;

				if (Player::isHit_ == true)
				{
					Scene = DEAD;
				}
			}

			if (enemy->Hp_ <= 0)
			{
				Scene = CLEAR;
			}

			break;

		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (Scene) {

		case GAME:

			player->Draw();

			enemy->Draw();

			Novice::ScreenPrintf(0, 20, "enemy->Hp_ = %d", enemy->Hp_);

			Novice::ScreenPrintf(0, 40, "enemy->RespornTimer_ = %d", enemy->RespornTimer_);

			break;

		case CLEAR:

			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE,kFillModeSolid);

			break;

		case DEAD:

			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

			break;

		}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	delete player,enemy;
	return 0;
}
