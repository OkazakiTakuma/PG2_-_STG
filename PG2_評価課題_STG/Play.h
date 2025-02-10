#pragma once
#include"Player.h"
#include "Enemy.h"

class Play {
public:
	Play();
	~Play();
	/// <summary>
	/// プレイシーンの更新処理
	/// </summary>
	/// <param name="keys">現在のキー入力</param>
	/// <param name="preKeys">1フレーム前のキー入力</param>
	void Update(char* keys, char* preKeys);
	/// <summary>
	/// プレイシーンの描画処理
	/// </summary>
	void Draw();
	/// <summary>
	/// isResultの取得
	/// </summary>
	/// <returns></returns>
	bool GetIsTitle();

protected:
	bool isTitle;
	Player* player;
	Enemy* enemy[2];
	Vector2 EPos[2];
	Vector2 ESpeed[2];
	int respownTImer[2];
	int timer_;
};

