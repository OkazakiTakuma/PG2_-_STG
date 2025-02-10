#include "Player.h"
#include <Novice.h>
Player::Player() {
	isShoot_ = false;
	pos_ = {640, 600};
	radius_ = {32};
	speed_ = {10, 10};
	bulletRadius_ = {16};
	playerBullet = nullptr;
	isHit_ = false;
}

Player::~Player() {
	if (isShoot_) {
		delete playerBullet;
	}
}

void Player::Move(char* keys, char* preKeys) {
	//弾の発射処理
	if (!isShoot_ && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isShoot_ = true;
		playerBullet = new Bullet(pos_, bulletRadius_, speed_);
	}
	// 移動処理
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}
	//弾の更新処理
	if (isShoot_) {
		playerBullet->Update();
		if (playerBullet->GetPos().y <= -playerBullet->GetrRadius()) {
			delete playerBullet;
			isShoot_ = false;
		}
	}
}

void Player::Draw() {
	if (isShoot_) {
		playerBullet->Draw();
	}
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, GREEN, kFillModeSolid);
}

bool Player::SetIsHit(bool isHit) { return isHit_ = isHit; }

bool Player::GetIsHit() { return isHit_; }

Vector2 Player::GetPos() { return pos_; }

float Player::GetrRadius() { return radius_; }

bool Player::GetIsShoot() { return isShoot_; }
