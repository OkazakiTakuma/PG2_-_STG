#pragma once
#include"Title.h"
#include"Play.h"
/// <summary>
/// ゲームループクラス
/// </summary>
class Game {
public:

	Game();
	~Game();
	/// <summary>
	/// ゲームループの更新処理
	/// </summary>
	/// <param name="keys">現在のキー入力</param>
	/// <param name="preKeys">1フレーム前のキー入力</param>
	void Update(char*keys,char*preKeys);
	/// <summary>
	/// ゲームループの描画処理
	/// </summary>
	void Draw();

protected:
	int scene;
	Title* titleScene;
	Play* playScene;
};
