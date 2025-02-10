#pragma once
#include<Novice.h>
/// <summary>
///  タイトルシーンクラス
/// </summary>
class Title {
public:
	Title();
	~Title();
	/// <summary>
	/// タイトルシーンの更新処理
	/// </summary>
	/// <param name="keys">現在のキー入力</param>
	/// <param name="preKeys">1フレーム前のキー入力</param>
	void Update(char* keys, char* preKeys);
	/// <summary>
	/// ゲームループの描画処理
	/// </summary>
	void Draw();
	/// <summary>
	/// isPlayの取得
	/// </summary>
	/// <returns></returns>
	bool GetIsPlay();

private:
	bool isPlay;
};

