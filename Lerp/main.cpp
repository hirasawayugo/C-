#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include <vector>

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

	Vector2D midPoint(0, 0);
	Vector2D vec(0, 0);
	int count = 0;
	Vector2D trace[1000];
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//ブレンドした座標計算
		midPoint = calc.Lerp2D(vecList[1], vecList[2], blend);
		vec = calc.Lerp2D(vecList[0], midPoint, blend);

		blend += 0.001;
		if (blend > 1) 
		{
			blend = 0;
		}

		//曲線(跡)
		if (count != 1000) {
			trace[count] = vec;
			count++;
		}
		
		
		//描画
		for (int i = 0; i < 3; i++) {
			draw.Circle(vecList[i], Drwawer::COLOR::YELLOW);
		}
		draw.Line(vecList[1], vecList[2], GetColor(0,64,0));
		draw.Line(vecList[0], midPoint, GetColor(0, 64, 0));
		draw.Circle(midPoint, 5, GetColor(0, 127, 0));
		for (int i = 0; i < sizeof(trace) / sizeof(trace[0]); i++) {
			draw.Circle(trace[i], 1, Drwawer::COLOR::WHITE);
		}
		draw.Circle(vec, Drwawer::COLOR::WHITE);
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}