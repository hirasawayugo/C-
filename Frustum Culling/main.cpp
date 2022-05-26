#include "DxLib.h"
#include "Drawer.h"
#include "Camera.h"
#include "Matrix3D.h"
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
//平面と点の距離
double Distance( Vector3D pos1, Vector3D pos2, Vector3D pos3, Vector3D point ) {
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

void Input( Vector3D& point, Vector3D& vCamera, Camera& camera) {
	if (CheckHitKey(KEY_INPUT_W) == 0)
	{
		point.z -= 1;
	}
	if (CheckHitKey(KEY_INPUT_S) == 0)
	{
		point.z += 1;
	}
	if (CheckHitKey(KEY_INPUT_A) == 0)
	{
		point.x -= 1;
	}
	if (CheckHitKey(KEY_INPUT_D) == 0)
	{
		point.x += 1;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 0)
	{
		Calculator calc;
		camera.AddViewAngle(calc.Radians(1));
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		Calculator calc;
		camera.AddViewAngle(calc.Radians(-1));
	}

	if (CheckHitKey(KEY_INPUT_Q) == 0)
	{
		Calculator calc;
		Matrix3D mat;
		mat.Rotate(calc.Radians(1),Matrix3D::AXIS::Y);
		vCamera = mat * vCamera;
	}

	if (CheckHitKey(KEY_INPUT_E) == 0)
	{
		Calculator calc;
		Matrix3D mat;
		mat.Rotate(calc.Radians(-1), Matrix3D::AXIS::Y);
		vCamera = mat * vCamera;
	}
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
	SetCameraPositionAndTarget_UpVecY(VGet(vCamera.x, vCamera.y, vCamera.z), VGet(0,0,0));

	Drwawer draw;
	Camera camera;
	Vector3D point = Vector3D(1,1,1);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetCameraPositionAndTarget_UpVecY(VGet(vCamera.x, vCamera.y, vCamera.z), VGet(0, 0, 0));

		Input( point, vCamera, camera );

		//面と点の距離
		bool isIncluding = true;
		vector<Vector3D>plate = camera.GetPlate();
		double dis;
		dis = Distance(plate[0], plate[2], plate[4], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		dis = Distance(plate[3], plate[1], plate[7], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		dis = Distance(plate[2], plate[0], plate[3], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		dis = Distance(plate[4], plate[2], plate[5], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		dis = Distance(plate[6], plate[4], plate[7], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		dis = Distance(plate[0], plate[6], plate[1], point);
		if (dis <= 0) {
			isIncluding = false;
		}
		
		//箱の線
		draw.Line(plate[0], plate[2], GetColor(125, 125, 125));
		draw.Line(plate[0], plate[1], GetColor(125, 125, 125));
		draw.Line(plate[2], plate[3], GetColor(125, 125, 125));
		draw.Line(plate[1], plate[3], GetColor(125, 125, 125));
		draw.Line(plate[2], plate[4], GetColor(125, 125, 125));
		draw.Line(plate[3], plate[5], GetColor(125, 125, 125));
		draw.Line(plate[4], plate[5], GetColor(125, 125, 125));
		draw.Line(plate[4], plate[6], GetColor(125, 125, 125));
		draw.Line(plate[5], plate[7], GetColor(125, 125, 125));
		draw.Line(plate[6], plate[7], GetColor(125, 125, 125));
		draw.Line(plate[6], plate[0], GetColor(125, 125, 125));
		draw.Line(plate[7], plate[1], GetColor(125, 125, 125));

		double pDiff = pointDiff(vCamera, point);
		double cDiff = pointDiff(vCamera, camera.GetPos());
		
		if (pDiff < cDiff) {
			draw.Sphere(camera.GetPos(), Drwawer::COLOR::WHITE);
			//描画
			if (!isIncluding) {
				draw.Sphere(point, Drwawer::COLOR::BLUE);
			}
			else {
				draw.Sphere(point, Drwawer::COLOR::RED);
			}
		}
		else {
			//描画
			if (!isIncluding) {
				draw.Sphere(point, Drwawer::COLOR::BLUE);
			}
			else {
				draw.Sphere(point, Drwawer::COLOR::RED);
			}
			draw.Sphere(camera.GetPos(), Drwawer::COLOR::WHITE);
		}

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}