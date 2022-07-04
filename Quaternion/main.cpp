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
	SetLightPosition(VAdd(VGet(100,500,0), VGet(0, 0, 0)));

	Drwawer draw;

	double blend = 0;
	double theta = 0;

	Object* A1 = new Object();
	Object* A2 = new Object();
	Object* B1 = new Object();
	Object* B2 = new Object();
	Object* C1 = new Object();
	Object* C2 = new Object();
	A1->Addchild(A2);
	A2->SetPos(Vector3D(-100, 0, 0));
	B1->Addchild(B2);
	B2->SetPos(Vector3D(-100, 0, 0));
	C1->Addchild(C2);
	C2->SetPos(Vector3D(-100, 0, 0));
	Calculator calc;
	B1->Rotate(Vector3D(0, 0, 1), calc.Radians(120));

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (CheckHitKey(KEY_INPUT_W) == 0) {
			theta += calc.Radians(1);
		}
		if (CheckHitKey(KEY_INPUT_S) == 0) {
			theta -= calc.Radians(1);
		}
		Vector3D a1Pos = A1->GetPos();
		Vector3D a2Pos = A2->GetPos();
		Vector3D b2Pos = B2->GetPos();
		Vector3D c2Pos = C2->GetPos();
		SetCameraPositionAndTargetAndUpVec(VGet(sin(theta) * -300, 0, cos(theta) * -300), VGet(0, 0, 0), VGet(0, 1, 0));
		C1->Slerp(A1, B1, blend);

		draw.Sphere(a1Pos, Drwawer::COLOR::WHITE);
		draw.Sphere(a2Pos, Drwawer::COLOR::BLUE);
		draw.Sphere(b2Pos, Drwawer::COLOR::RED);
		draw.Sphere(c2Pos, Drwawer::COLOR::GREEN);
		unsigned int color = GetColor(255,255,255);
		draw.Line(a1Pos, a2Pos, color);
		draw.Line(a1Pos, b2Pos, color);
		draw.Line(a1Pos, c2Pos, color);
		blend += 0.01;
		if (blend >= 1) blend = 0;
		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}