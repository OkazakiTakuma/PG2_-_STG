#pragma once
#include "Object.h"
#include "Bullet.h"
class Player : protected Object {
public:
	Player();
	~Player();
	/// <summary>
	/// プレイヤーの移動処理
	/// </summary>
	/// <param name="keys">現在のキー入力</param>
	/// <param name="preKeys">1フレーム前のキー入力</param>
	void Move(char* keys, char* preKeys);
	/// <summary>
	/// プレイヤーの描画処理
	/// </summary>
	void Draw();

	// セッターとゲッター
	bool SetIsHit(bool isHit);
	bool GetIsHit();
	Vector2 GetPos();
	float GetrRadius();
	bool GetIsShoot();

	Bullet* playerBullet;
private:
	bool isShoot_;
	bool isHit_;
	float bulletRadius_;
};