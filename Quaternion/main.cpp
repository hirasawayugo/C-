#include "DxLib.h"
#include "Drawer.h"
#include "Object.h"
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
	SetCameraPositionAndTargetAndUpVec(VGet(0,0,-200), VGet(0,0,0), VGet(0,1,0));

	Drwawer draw;

	Object* A = new Object();
	Object* B = new Object();
	A->Addchild(B);
	B->SetPos(Vector3D(100,0,0));

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Vector3D aPos = A->GetPos();
		Vector3D bPos = B->GetPos();
		SetCameraPositionAndTargetAndUpVec(VGet(0, 0, -300), VGet(aPos.x, aPos.y, aPos.z), VGet(0, 1, 0));
		Calculator calc;
		A->Rotate(Vector3D(0,0,1), calc.Radians(1));

		draw.Sphere(aPos, Drwawer::COLOR::WHITE);
		draw.Sphere(bPos, Drwawer::COLOR::WHITE);
		unsigned int color = GetColor(255,255,255);
		draw.Line(aPos, bPos, color );
		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}