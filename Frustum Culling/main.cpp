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

bool isViewing( Vector3D& point, Camera& camera) {
	//面と点の距離
	bool viewing = true;
	vector<Vector3D>plate = camera.GetPlate();
	double dis[6];
	dis[0] = planeAndPointDiff(plate[0], plate[2], plate[4], point);
	dis[1] = planeAndPointDiff(plate[3], plate[1], plate[7], point);
	dis[2] = planeAndPointDiff(plate[2], plate[0], plate[3], point);
	dis[3] = planeAndPointDiff(plate[4], plate[2], plate[5], point);
	dis[4] = planeAndPointDiff(plate[6], plate[4], plate[7], point);
	dis[5] = planeAndPointDiff(plate[0], plate[6], plate[1], point);
	for (int i = 0; i < 6; i++) {
		if (dis[i] <= 0) {
			viewing = false;
		}
	}
	return viewing;
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

	if (CheckHitKey(KEY_INPUT_Q) == 0)
	{
		Calculator calc;
		Matrix3D mat;
		mat.Rotate(calc.Radians(-1),Matrix3D::AXIS::Y);
		camera.Transform(mat);
	}

	if (CheckHitKey(KEY_INPUT_E) == 0)
	{
		Calculator calc;
		Matrix3D mat;
		mat.Rotate(calc.Radians(1), Matrix3D::AXIS::Y);
		camera.Transform(mat);
	}

	if (CheckHitKey(KEY_INPUT_UP) == 0)
	{
		Matrix3D mat;
		mat.Move(Vector3D(0,1,0));
		camera.Transform(mat);
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		Matrix3D mat;
		mat.Move(Vector3D(0, -1, 0));
		camera.Transform(mat);
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
	Vector3D point = Vector3D(0,0,50);
	Vector3D vpoint = camera.GetViewMatrix() * point;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetCameraPositionAndTarget_UpVecY(VGet(vCamera.x, vCamera.y, vCamera.z), VGet(0, 0, 0));

		Input( point, vCamera, camera );
		Matrix3D mat;
		mat.Move(point);
		vpoint = camera.GetViewMatrix() * point;

		vector<Vector3D>plate = camera.GetPlate();
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
		
		draw.Sphere(camera.GetPos(), Drwawer::COLOR::WHITE);
		//描画
		if (!isViewing(point, camera)) {
			draw.Sphere(point, Drwawer::COLOR::BLUE);
		}
		else {
			draw.Sphere(point, Drwawer::COLOR::RED);
		}
		if (!isViewing(vpoint, camera)) {
			draw.Sphere(vpoint, Drwawer::COLOR::GREEN);
		}
		else {
			draw.Sphere(vpoint, Drwawer::COLOR::YELLOW);
		}
		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}