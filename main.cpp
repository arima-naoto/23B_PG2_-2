#include <Novice.h>
#include <Enemy.h>
#include <Player.h>

const char kWindowTitle[] = "GC1C_02_アリマ_ナオト";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy = new Enemy();
	enemy->Initalize();

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

		player->Update(keys,preKeys);

		enemy->Update();
		enemy->OnCollision();

		int EnemyDistance = (player->bullet->GetPos().x - enemy->GetPos().x) *
			                (player->bullet->GetPos().x - enemy->GetPos().x) +
			                (player->bullet->GetPos().y - enemy->GetPos().y) *
			                (player->bullet->GetPos().y - enemy->GetPos().y);

		int EnemyR = enemy->GetRadius();
		int BulletR = player->bullet->GetRadius();
		bool EnemyIsAlive = enemy->GetIsAlive();

		if (EnemyDistance <= EnemyR + BulletR * EnemyR + BulletR) 
		{
			EnemyIsAlive = false;

			enemy->SetIsAlive(EnemyIsAlive);
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		enemy->Draw();

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
	delete enemy,player;
	return 0;
}
