#include "Enemy.h"
#include <Novice.h>
Enemy::Enemy(Vector2 pos, Vector2 speed) {
	isActive_ = true;
	pos_ = pos;
	radius_ = 16.0f;
	speed_ = speed;
	isHit_ = 0;
}
void Enemy::Move() {
	if (isActive_) {

		
		pos_.x += speed_.x;
		/// 敵の反射
		if (pos_.x + radius_ >= 1280 || pos_.x <= radius_) {
			speed_.x = -speed_.x;
		}
		if (isHit_) {
			isActive_ = false;
		}
	}
}
void Enemy::Draw() {
	if (isActive_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);
	}
}

bool Enemy::GetIsActive() { return isActive_; }

bool Enemy::SetIsHit(bool isHit) { return isHit_ = isHit; }

Vector2 Enemy::GetPos() { return pos_; }

float Enemy::GetrRadius() { return radius_; }
