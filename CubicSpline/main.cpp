#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include "CubicSpline.h"

#include <vector>

using namespace std;

int mStartTime = 0;         //測定開始時刻
double mCount = 0;             //カウンタ
float mFps = 0;             //fps
static const int N = 60;//平均を取るサンプル数
static const double FPS = 60;	//設定したFPS
const int dCount = 1000;

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

bool fps() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void Random(vector<double>& vec) {
	if (vec.size() == 0) {
		for (int i = 0; i < 7; i++) {
			vec.push_back(GetRand(500) + 100);
		}
		return;
	}
	int size = vec.size();

	for (int i = 0; i < size; i++) {
		vec[i] = GetRand(500) + 100;
	}
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
	double blend = 0;
	int index = 0;
	bool finish = false;

	 vector<double> sx;
	 vector<double> sy;
	 Random(sx);
	 Random(sy);

	 CubicSpline csx(sx);
	 CubicSpline csy(sy);
	 vector<double> rx;
	 vector<double> ry;
	 double x;
	 double y;

	Vector2D vec(0, 0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		x = csx.Calc(blend);
		rx.push_back(x);
		y = csy.Calc(blend);
		ry.push_back(y);

		if (blend > 6.0)
		{
			blend = 0;
			Random(sx);
			Random(sy);
			csx.ResetParameter(sx);
			csy.ResetParameter(sy);
		}
		blend += 0.01;
		
		//描画
		for (int i = 0; i < 7; i++) {
			draw.Circle(Vector2D(sx[i], sy[i]), 5, GetColor(i * (127 / 7), i * (127 / 7),0 ));
		}
		for (int i = 0; i < rx.size() - 1; i++) {
			draw.Circle(Vector2D(rx[i], ry[i]), 1, Drwawer::COLOR::WHITE);
		}
		draw.Circle(Vector2D(x, y), Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}