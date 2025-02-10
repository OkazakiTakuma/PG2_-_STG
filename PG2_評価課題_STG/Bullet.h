#pragma once
#include "Object.h"
class Bullet : protected Object {

	public:
	Bullet(Vector2 pos, float radius, Vector2 speed);
	void Update();
	void Draw();
	Vector2 GetPos();
	float GetrRadius();

};
