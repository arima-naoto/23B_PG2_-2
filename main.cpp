#include <Novice.h>
#include <Player.h>
#include <Enemy.h>

const char kWindowTitle[] = "GC1C_02_アリマ_ナオト";
const int Window_Width = 1280;
const int Window_Height = 720;

bool Player::isHit_ = false;

bool Bullet::isShot_ = false;

#pragma region //自作関数を作成する

//敵と弾の当たり判定用自作関数EnemyCollisionを作成
bool EnemyCollision(Vector2 obj1, Vector2 obj2,int obj1radius,int obj2radius)
{
	if(obj1.x - obj1radius <= obj2.x + obj2radius && obj2.x - obj2radius <= obj1.x + obj1radius && 
	   obj1.y - obj1radius <= obj2.y + obj2radius && obj2.y - obj2radius <= obj1.y + obj1radius)
	{
		return true;
	}

	return false;
}

//敵と自機の当たり判定用自作関数PlayerCollisionを作成
bool PlayerCollision(Vector2 obj2, Vector2 obj3, int obj2radius, int obj3radius)
{
	if (obj2.x - obj2radius <= obj3.x + obj3radius && obj3.x - obj3radius <= obj2.x + obj2radius &&
		obj2.y - obj2radius <= obj3.y + obj3radius && obj3.y - obj3radius <= obj2.y + obj2radius)
	{
		return true;
	}

	return false;
}

#pragma endregion

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, Window_Width, Window_Height);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

#pragma region //初期化処理

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

	//Playerクラスのインスタンスを作成
	Player* player = new Player();

	//Enemyクラスのインスタンスを作成
	Enemy* enemy = new Enemy();
	enemy->Initalize();

	//GameScene型変数Sceneを宣言し、TITLEで初期化する
	GameScene Scene = TITLE;

#pragma endregion

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

#pragma region //switch文を使用して、各シーンの更新処理を行う

		switch (Scene) {

		case TITLE://SceneがTITLEの時

			//自機の座標を初期化する
			player->SetPosition({ 640,550 });

			//打たれているフラグをfalseにする
			Bullet::isShot_ = false;

			//Enemyクラスの初期化を行う
			enemy->SetPosition({ 640,150 });//座標の初期化

			enemy->Hp_ = 3;//体力の初期化

			enemy->RespornTimer_ = 120;//リスポーンタイマーの初期化

			enemy->isAlive_ = true;//敵機が生きているフラグをtrueにする

			if(keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)//Enterキーが押された瞬間
			{
				Novice::StopAudio(SoundHandle);//シーンTITLEの音楽を止める

				Scene = GAME;//シーンをGAMEにする
			}

			break;

		case GAME://シーンがGAMEの時

			//Playerクラスの更新処理メンバ関数Updateを呼び出す
			player->Update(keys, preKeys,enemy);

			//enemyクラスの更新処理メンバ関数Updateを呼び出す
			enemy->Update();

			//自作関数EnemyCollisionを呼び出し、敵と弾の当たり判定を行う
			if(EnemyCollision(player->bullet->GetPos(), enemy->GetPos(), player->bullet->GetRadius(), enemy->GetRadius()))
			{
				enemy->isAlive_ = false;//敵機の生きているフラグを折る
			}

			//自作関数PlayerCollisionを呼び出し、敵と自機の当たり判定を行う
			if(PlayerCollision(enemy->GetPos(),player->GetPos(),enemy->GetRadius(),player->GetRadius()))
			{
				Player::isHit_ = true;//自機が当たったフラグを立て

				if (Player::isHit_ == true)//もし当たっていたら
				{
					Novice::StopAudio(SoundHandle1);//シーンGAME用の音楽を止め

					Scene = DEAD;//SceneをDEADにする
				}
			}

			if (enemy->Hp_ <= 0)//敵機の残機が0になったら
			{
				Novice::StopAudio(SoundHandle1);//シーンGAME用の音楽を止め
				Scene = CLEAR;//SceneをCLEARにする
			}

			break;

		case CLEAR:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)//Enterキーが押された瞬間
			{
				Novice::StopAudio(SoundHandle2);//シーンCLEAR用の音楽を止め
				Scene = TITLE;//SceneをTITLEにする
			}

			break;

		case DEAD:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == false)//Enterキーが押された瞬間
			{
				Novice::StopAudio(SoundHandle3);//シーンDEAD用の音楽を止め
				Scene = TITLE;//SceneをTITLEにする
			}

			break;

		}

#pragma endregion


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

#pragma region //描画処理

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
#pragma endregion
		
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
