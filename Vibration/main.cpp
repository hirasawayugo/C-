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

void SetVibrationData(vector<double>& x, vector<double>& y, double period, double amp, double time)
{
	double sT = x[x.size() - 1];
	double halfPer = period / 2;
	double t = sT;
	double w = y[y.size() - 1] * -1;
	//
	while (t - sT< time)
	{
		t += halfPer;
		x.push_back(t);
		t += halfPer;
		x.push_back(t);
		w += amp;
		y.push_back(w);
		y.push_back(-w);
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
	bool fin = false;

	//x = 時間(1周期) 1周期 = 10
	vector<double> sx;
	//y = 振幅(揺れの強さ)
	vector<double> sy;

	sx.push_back(0);
	sy.push_back(0);
	SetVibrationData(sx, sy, 20, 5, 200);
	SetVibrationData(sx, sy, 20, 30, 200);
	SetVibrationData(sx, sy, 20, -30, 300);
	sx.push_back(sx[sx.size() - 1]);
	sy.push_back(0);

	 CubicSpline csx(sx);
	 CubicSpline csy(sy);
	 vector<double> rx;
	 vector<double> ry;
	 double x;
	 double y;

	Vector2D vec(0, 0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (!fin) {
			x = csx.Calc(blend);
			y = csy.Calc(blend);
			rx.push_back(x);
			ry.push_back(y);

			if (blend > sx.size() - 1)
			{
				fin = true;
			}
			blend += 0.05;
		}
		
		//描画
		for (int i = 1; i < rx.size(); i++) {
			draw.Circle(Vector2D(rx[i], ry[i] + 350), 1, Drwawer::COLOR::WHITE);
			draw.Line(Vector2D(rx[i - 1], ry[i - 1] + 350), Vector2D(rx[i], ry[i] + 350), Drwawer::COLOR::WHITE);
		}
		draw.Circle(Vector2D(x, y + 350), Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}