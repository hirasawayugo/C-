#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include <vector>

int mStartTime = 0;         //測定開始時刻
double mCount = 0;             //カウンタ
float mFps = 0;             //fps
static const int BPM = 190;
static const int beet = 4;
static const int N = 60;//平均を取るサンプル数
static const double FPS = 60;	//設定したFPS
const int dCount = 1000;

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS / BPM - tookTime;	//待つべき時間
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
	return true;
}

void Random( Vector2D vec[4] ) {
	vec[0].x = GetRand(500) + 100;
	vec[0].y = GetRand(500) + 100;
	vec[1].x = GetRand(500) + 100;
	vec[1].y = GetRand(500) + 100;
	vec[2].x = GetRand(500) + 100;
	vec[2].y = GetRand(500) + 100;
	vec[3].x = GetRand(500) + 100;
	vec[3].y = GetRand(500) + 100;
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
	Vector2D vecList[4] = {	Vector2D(100,100), Vector2D(350,300), Vector2D(600,100) };
	Random(vecList);
	Vector2D midPoint(0, 0);
	Vector2D vec(0, 0);

	int count = 0;
	Vector2D trace[dCount];
	int sCount = GetNowCount();
	double dTime = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		for (int i = 0; i < dCount / 4; i++) {
			//ブレンドした座標計算
			midPoint = calc.Lerp2D(vecList[1], vecList[2], blend);
			vec = calc.Lerp2D(vecList[0], midPoint, blend);

			blend += 1.0 / dCount;
			//曲線(跡)
			if (count != dCount) {
				trace[count] = vec;
				count++;
			}
		}
		
		if (blend > 1) 
		{
			blend = 0;
			Random(vecList);
			dTime = ((double)GetNowCount() - (double)sCount) / 100;
		}

		if (blend == 0) {
			sCount = GetNowCount();
			count = 0;
		}
		DrawFormatString(0, 100, GetColor(255, 255, 255), "%lf", dTime);

		
		//描画
		/*for (int i = 0; i < 3; i++) {
			draw.Circle(vecList[i], Drwawer::COLOR::YELLOW);
		}
		draw.Line(vecList[1], vecList[2], GetColor(0,64,0));
		draw.Line(vecList[0], midPoint, GetColor(0, 64, 0));
		draw.Circle(midPoint, 5, GetColor(0, 127, 0));*/
		for (int i = 0; i < sizeof(trace) / sizeof(trace[0]); i++) {
			draw.Circle(trace[i], 1, Drwawer::COLOR::WHITE);
		}
		draw.Circle(vec, Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}