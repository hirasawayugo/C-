#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include "Camera.h"
#include "Object.h"

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
	Calculator calc;
	bool isVibing = false;
	double currentSec = 0;
	double blendMax = 5.0;
	double time = 0.5;
	const int maxX = 20;
	const int maxY = 50;
	double xw = maxX;
	double yw = maxY;

	Camera* camera = new Camera();
	Object object;
	object.SetCamera(camera);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		clsDx();

		if (CheckHitKey(KEY_INPUT_A) == 1) {
			camera->Foward(Vector2D(-1, 0));
			printfDx("左移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			camera->Foward(Vector2D(1, 0));
			printfDx("右移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			camera->Foward(Vector2D(0, -1));
			printfDx("下移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			camera->Foward(Vector2D(0, 1));
			printfDx("上移動中\n");
		}
		if (CheckHitKey(KEY_INPUT_Q) == 1) {
			camera->Rotate(calc.Radians(-1));
			printfDx("左回転中\n");
		}
		if (CheckHitKey(KEY_INPUT_E) == 1) {
			camera->Rotate(calc.Radians(1));
			printfDx("右回転中\n");
		}

		if (CheckHitKey(KEY_INPUT_I) == 1 && !isVibing) {
			isVibing = true;
		}
		if (isVibing) {
			camera->Vibration(xw, 0, currentSec);
			//1フレーム1/60秒のため1/60秒を足す
			currentSec += 1.0 / 60.0;
			xw -= (double)maxX / (60.0 * 0.25);
			if (xw <= 0) {
				isVibing = false;
				xw = maxX;
				currentSec = 0;
			}
		}
		Vector2D pos = object.GetPos();
		//描画
		draw.Circle(pos, 100,Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}