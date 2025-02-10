#include "Play.h"
#include "Hit.h"
Play::Play() {
	isTitle = false;
	player = new Player;
	timer_ = 1800;
	for (int i = 0; i < 2; i++) {
		EPos[i] = {20.0f + i * 200, 400.0f + i * 100};
		ESpeed[i] = {16, 0};
		enemy[i] = new Enemy(EPos[i], ESpeed[i]);
		respownTImer[i] = 0;
	}
}

Play::~Play() {}

void Play::Update(char* keys, char* preKeys) {
	player->Move(keys, preKeys);
	for (int i = 0; i < 2; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Move();
		}
	}
	for (int i = 0; i < 2; i++) {
		if (enemy[i] != nullptr) {
			///	 当たり判定
			if (player->GetIsShoot() && enemy[i]->GetIsActive()) {
				enemy[i]->SetIsHit(
				    Hit(enemy[i]->GetPos(), Vector2(enemy[i]->GetrRadius(), enemy[i]->GetrRadius()), player->playerBullet->GetPos(),
				        Vector2(player->playerBullet->GetrRadius(), player->playerBullet->GetrRadius())));
			}
			///　当たっていたら敵を消す
			if (!enemy[i]->GetIsActive()) {
				delete enemy[i];
				enemy[i] = nullptr;
				respownTImer[i] = 60;
			}
		} else {
			if (respownTImer[i] > 0) {
				respownTImer[i]--;
			} else {
				enemy[i] = new Enemy(EPos[i], ESpeed[i]);
			}
		}
		if (enemy[i] != nullptr) {
			///	 当たり判定
			if (enemy[i]->GetIsActive()) {
				player->SetIsHit(
				    Hit(enemy[i]->GetPos(), Vector2(enemy[i]->GetrRadius(), enemy[i]->GetrRadius()), player->GetPos(),
				        Vector2(player->GetrRadius(), player->GetrRadius())));
			}
		}
		if (player->GetIsHit()) {
			isTitle = true;
		}
	}
	if (timer_ > 0) {
	timer_--;
	} else {
		isTitle = true;
	}

}

void Play::Draw() {
	player->Draw();
	for (int i = 0; i < 2; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
	}
}

bool Play::GetIsTitle() { return isTitle; }
