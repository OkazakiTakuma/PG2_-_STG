#include "Game.h"
#include "Enum.h"
Game::Game() {
	scene = TITLE;
	titleScene = new Title();
	playScene = nullptr;
}

Game::~Game() {
	if (titleScene != nullptr) {
		delete titleScene;
	}
	if (playScene != nullptr) {
		delete playScene;

	}
}
	void Game::Update(char* keys, char* preKeys) {
		preKeys;
		switch (scene) {
		default:
			break;
		case TITLE:
			if (titleScene != nullptr) {
				titleScene->Update(keys, preKeys);
				/// プレイ画面への移行
				if (titleScene->GetIsPlay()) {
					delete titleScene;
					scene = PLAY;
					playScene = new Play();
				}
			}
			break;
		case PLAY:
			if (playScene != nullptr) {
				playScene->Update(keys, preKeys);
				/// タイトル画面への移行
				if (playScene->GetIsTitle()) {
					delete playScene;
					scene = TITLE;
					titleScene = new Title();
				}
			}
			break;
		}
	}

	void Game::Draw() {
		switch (scene) {
		default:
			break;
		case TITLE:
			if (titleScene != nullptr) {
				titleScene->Draw();
			}
			break;
		case PLAY:
			if (playScene != nullptr) {
				playScene->Draw();
			}
			break;
		}
	}
