#include "Bullet.h"
#include <Novice.h>
Bullet::Bullet(Vector2 pos, float radius, Vector2 speed) {
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
}
void Bullet::Update() { pos_.y -= speed_.y; }
void Bullet::Draw() { Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid); }

Vector2 Bullet::GetPos() { return pos_; }

float Bullet::GetrRadius() { return radius_; }

