﻿#include "DxLib.h"
#include "Drawer.h"
#include "Liner.h"

#include <vector>

using namespace std;

int mStartTime = 0;         //測定開始時刻
static const double FPS = 60;	//設定したFPS

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = 1 / FPS * 1000 - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

bool fps() {
	mStartTime = GetNowCount();
	return true;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	Drwawer draw;

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetCameraPositionAndTarget_UpVecY(VGet(0,0,-500), VGet(0,0,0));

	Vector3D pos1 = Vector3D(-100, 0, 0);
	Vector3D pos2 = Vector3D(0, -100, 0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Liner liner;
		liner.Execution(pos1, pos2, Liner::TYPE::STRAIGHT);
		
		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}