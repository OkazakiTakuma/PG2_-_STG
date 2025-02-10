#include "Title.h"

Title::Title() { isPlay = false; }

Title::~Title() {}

void Title::Update(char* keys, char* preKeys) {
	if (!isPlay) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
			isPlay = true;
		}
	}
}

void Title::Draw() {
	if (!isPlay) {
		Novice::ScreenPrintf(500, 340, "SPACE TO START");
	}

}

bool Title::GetIsPlay() { return isPlay; }
