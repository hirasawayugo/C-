#include "DxLib.h"
#include "Drawer.h"
#include "Matrix3D.h"

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
//平面と点の距離
double planeAndPointDiff( Vector3D pos1, Vector3D pos2, Vector3D pos3, Vector3D point ) {
	//法線ベクトルn
	Vector3D n = point;
	//nの座標
	double x = n.x;
	double y = n.y;
	double z = n.z;
	//面上にある共通点を持つ2点の外積
	Vector3D line = (pos1 - pos2).Cross(pos1 - pos3);
	//面の傾きの値abc
	double a = line.x;
	double b = line.y;
	double c = line.z;
	double d = line.Dot(pos1 * -1.0);

	//法線ベクトルを正規化
	double normal = sqrt(a * a + b * b + c * c);
	//距離
	return (a * x + b * y + c * z + d) / normal;
}

double pointDiff(Vector3D pos1, Vector3D pos2) {
	double x = pos1.x - pos2.x;
	double y = pos1.y - pos2.y;
	double z = pos1.z - pos2.z;

	return sqrt(x * x + y * y + z * z);
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

	Vector3D vCamera = Vector3D(0, 0, -500);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		
		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}