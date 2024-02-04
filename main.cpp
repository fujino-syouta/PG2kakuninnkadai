#include <Novice.h>
#include"Enemy.h"
#include"Player.h"
#include<math.h>
const char kWindowTitle[] = "GC1D_10_フジノショウタ";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

enum Scene {
	TITLE,
	PLAY,
	CLEAR,
	GAMEOVER
};

bool Collision(float obj1_x, float obj1_y, float obj1_r, float obj2_x, float obj2_y, float obj2_r)
{
	float a = obj2_x - obj1_x;
	float b = obj2_y - obj1_y;
	float distance = sqrtf(a * a + b * b);
	if (distance<=obj1_r+obj2_r )
	{
		 return true;
	}
	else
	{
		return false;
	}
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	Scene scene = TITLE;
	Enemy* enemy = new Enemy();//エネミークラスをポインタで
	Player* player = new Player();

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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
		switch (scene)
		{
			case TITLE:

				if (keys[DIK_RETURN])
				{
					scene = PLAY;
					enemy->Initialize();
					player->Initialize();
				}

				break;
			case PLAY:

				enemy->Update();
				player->Update( keys, preKeys);
				
				if (Collision((float)enemy->GetPosX(), (float)enemy->GetPosY(), (float)enemy->GetR(), (float)player->GetPosX(), (float)player->GetPosY(), (float)player->GetR())==true)
				{
					scene = GAMEOVER;
				}
				if (Collision((float)enemy->GetPosX(), (float)enemy->GetPosY(), (float)enemy->GetR(), (float)player->GetPosX2(), (float)player->GetPosY2(), (float)player->GetR2()) == true)
				{
					enemy->SetisAlive_(false);
					if (enemy->Getlife() == 0) {
						scene = CLEAR;
					}
				}
					break;
			case CLEAR:
				if (keys[DIK_RETURN]) 
				{
					scene=TITLE;
				}

				break;
			case GAMEOVER:
				if (keys[DIK_RETURN]) 
				{
					scene = TITLE;
				}
				break;
			default:
				break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene)
		{
			case TITLE:
				Novice::ScreenPrintf(600, 360, "RETURNでゲームスタート");
				break;
			case PLAY:
				enemy->Draw();
				player->Draw();
				break;
			case CLEAR:
				Novice::ScreenPrintf(600, 330, "CLEAR");
				Novice::ScreenPrintf(600, 360, "RETURNでタイトルに戻る");
				break;
			case GAMEOVER:
				Novice::ScreenPrintf(600, 330, "GAMEOVER");
				Novice::ScreenPrintf(600, 360, "RETURNでタイトルに戻る");
				break;
			default:
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
	return 0;
}

