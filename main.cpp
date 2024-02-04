#include <Novice.h>
#include <Player.h>
#include <Enemy.h>

const char kWindowTitle[] = "GC1C_02_アリマ_ナオト";
const int Window_Width = 1280;
const int Window_Height = 720;

bool Player::isHit_ = false;

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


	//=========================================================<画像の読み込み>=========================================================

	int TitleHandle = Novice::LoadTexture("./Resources/images/TitleBackGround.png");
	int LetterHandle = Novice::LoadTexture("./Resources/images/TitleLetter.png");
	int GameHandle = Novice::LoadTexture("./Resources/images/bg.png");
	int ClearHandle = Novice::LoadTexture("./Resources/images/ClearBackGround.png");
	int DeadHandle = Novice::LoadTexture("./Resources/images/DeadBackGround.png");

	//=========================================================<音声の読み込み>=========================================================

	int TitleSound = Novice::LoadAudio("./Resources/sounds/start.wav");
	int GameSound = Novice::LoadAudio("./Resources/sounds/yokoku.mp3");
	int ClearSound = Novice::LoadAudio("./Resources/sounds/fanfare.wav");
	int DeadSound = Novice::LoadAudio("./Resources/sounds/shock5.mp3");

	//音声ループ用の変数を用意
	int SoundHandle = -1;
	int SoundHandle1 = -1;
	int SoundHandle2 = -1;
	int SoundHandle3 = -1;

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

			if(keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)
			{
				Novice::StopAudio(SoundHandle);

				Scene = GAME;
			}

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
					Novice::StopAudio(SoundHandle1);
					Scene = DEAD;
				}
			}

			if (enemy->Hp_ <= 0)
			{
				Novice::StopAudio(SoundHandle1);
				Scene = CLEAR;
			}

			break;

		case CLEAR:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)
			{
				Novice::StopAudio(SoundHandle2);
				Scene = TITLE;
			}

			break;

		case DEAD:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)
			{
				Novice::StopAudio(SoundHandle3);
				Scene = TITLE;
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

		case TITLE:

			Novice::DrawSprite(0, 0, TitleHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(0, 0, LetterHandle, 1, 1, 0.0f, WHITE);

			if (Novice::IsPlayingAudio(SoundHandle) == 0 || SoundHandle == -1) {
				SoundHandle = Novice::PlayAudio(TitleSound, 1, 1.0f);
			}

			break;

		case GAME:

			Novice::DrawSprite(0, 0, GameHandle, 1, 1, 0.0f, WHITE);

			player->Draw();

			enemy->Draw();

			if (Novice::IsPlayingAudio(SoundHandle1) == 0 || SoundHandle1 == -1) {
				SoundHandle1 = Novice::PlayAudio(GameSound, 1, 1.0f);
			}

			break;

		case CLEAR:

			Novice::DrawSprite(0, 0, ClearHandle, 1, 1, 0.0f, WHITE);

			if (Novice::IsPlayingAudio(SoundHandle2) == 0 || SoundHandle2 == -1) {
				SoundHandle2 = Novice::PlayAudio(ClearSound, 1, 1.0f);
			}

			break;

		case DEAD:

			Novice::DrawSprite(0, 0, DeadHandle, 1, 1, 0.0f, WHITE);

			if (Novice::IsPlayingAudio(SoundHandle3) == 0 || SoundHandle3 == -1) {
				SoundHandle3 = Novice::PlayAudio(DeadSound, 1, 1.0f);
			}

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
