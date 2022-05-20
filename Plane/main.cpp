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
	double angle = 0;
	double lenght = 200;
	Vector2D plate[2] = {Vector2D( 0, 0 ),Vector2D( 0,lenght)};
	Vector2D point = Vector2D(0,0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		clsDx();

		if (CheckHitKey(KEY_INPUT_A) == 1) {
			point.Add(Vector2D(-1, 0));
			printfDx("左移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			point.Add(Vector2D(1, 0));
			printfDx("右移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			point.Add(Vector2D(0, -1));
			printfDx("下移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			point.Add(Vector2D(0, 1));
			printfDx("上移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_Q) == 1) {
			angle -= 0.1;
			Matrix33 mat;
			mat.Rotate(angle);
			plate[1] = plate[0] + mat * Vector2D(0, lenght);
			printfDx("左回転中\n");
		}
		if (CheckHitKey(KEY_INPUT_E) == 1) {
			angle += 0.1;
			Matrix33 mat;
			mat.Rotate(angle);
			plate[1] = plate[0] + mat * Vector2D(0,lenght);
			printfDx("右回転中\n");
		}
		//線と点の距離
		//ax + by = c
		//(ax - by + d)/√a² + b²

		double a = plate[1].y - plate[0].y;
		double b = plate[1].x - plate[0].x;
		double d = plate[1].x * plate[0].y - plate[1].y * plate[0].x;

		double x = point.x;
		double y = point.y;

		double normal = sqrt(pow(a, 2) + pow(b, 2));

		double dis = a / normal * x - b / normal * y + d / normal;
		

		//描画
		draw.Line(plate[0] + Vector2D(400, 400), plate[1] + Vector2D(400, 400), Drwawer::COLOR::WHITE);
		if (dis < 0) {
			draw.Circle(point + Vector2D(400, 400), 10, Drwawer::COLOR::RED);
		}
		else {
			draw.Circle(point + Vector2D(400, 400), 10, Drwawer::COLOR::BLUE);
		}
		

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}