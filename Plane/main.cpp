#include "DxLib.h"
#include "Drawer.h"
#include "Matrix33.h"

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

	double angle = 0;
	double lenght = 200;
	vector<Vector3D> plate {Vector3D(-lenght,lenght,0),Vector3D(lenght,lenght,0),Vector3D(lenght,-lenght,0),Vector3D(-lenght,-lenght,0)};
	Vector3D point = Vector3D(1,1,1);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (CheckHitKey(KEY_INPUT_W) == 0)
		{
			for (int i = 0; i < 4; i++) {
				plate[i].z += 1;
			}
		}
		if (CheckHitKey(KEY_INPUT_S) == 0)
		{
			for (int i = 0; i < 4; i++) {
				plate[i].z -= 1;
			}
		}

		//面と点の距離
		//ax + by + cz = d

		//法線ベクトルn
		Vector3D n = point;
		//法線の値をabcに移行
		double a = plate[0].x;
		double b = plate[0].y;
		double c = plate[0].z;
		//面の点の座標
		double x = n.x;
		double y = n.y;
		double z = n.z;
		double d = 0;
		//double d = -(a + x + b * y + c * z);
		//法線ベクトルを正規化
		double normal = sqrt(a*a + b*b + c*c);
		//距離
		double dis =  (a * x + b * y + c * z + d )/ normal;

		//描画
		if ( dis <= 0) {
			draw.Sphere(point, Drwawer::COLOR::BLUE);
		}
		else {
			draw.Sphere(point, Drwawer::COLOR::RED);
		}
		draw.Plate(plate, Drwawer::COLOR::WHITE );
		

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}