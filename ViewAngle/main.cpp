#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"

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

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	Calculator calc;
	Drwawer draw;

	Vector3D pos = Vector3D(0, 0, 0);
	double theta = calc.Radians(45);
	double range = 100;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		clsDx();
		if (CheckHitKey(KEY_INPUT_W) == 0) {
			theta += calc.Radians(0.1);
		}
		if (CheckHitKey(KEY_INPUT_S) == 0) {
			theta -= calc.Radians(0.1);
		}

		double dis = 100 * sin(theta);

		SetCameraPositionAndTarget_UpVecY(VGet(0, 0, dis), VGet(0, 0, 0));
		draw.Sphere(pos,Drwawer::COLOR::WHITE);

		printfDx("画角:%0.2f",calc.Degrees(theta));
		printfDx("距離:%0.2f",dis);

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}