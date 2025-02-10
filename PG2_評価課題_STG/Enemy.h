#pragma once
#include "Object.h"
class Enemy : protected Object {

	public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">初期座標</param>
	/// <param name="speed">大きさ</param>
	Enemy(Vector2 pos, Vector2 speed);
	void Move();
	void Draw();
	bool GetIsActive();
	bool SetIsHit(bool isHit);
	Vector2 GetPos();
	float GetrRadius();

protected:
	bool isHit_;
};
