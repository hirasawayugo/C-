#include"Arthrosis.h"
#include "Calculator.h"
#include "Matrix33.h"

#include "DxLib.h"

Vector2D windowVec(Vector2D castVec)
{
	Vector2D origin = Vector2D(300, 300);
	return Vector2D( origin.x + castVec.x, origin.y - castVec.y);
}
void Draw( Arthrosis* art)
{
	Vector2D waVec = windowVec(art->GetPos());
	DrawPixel(waVec.x, waVec.y, GetColor(255, 255, 255));
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードの設定
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	double beforeAngle = 100;
	double addAngle = 1;
	Calculator calc;
	Arthrosis*  f[5][4] = {};
	//左手
	//手のひらを正面に想定
	// 10 = 1cm
	//起点となる手首の関節
	Arthrosis* oArt = new Arthrosis(1, 0, 0, 0);
	Arthrosis* pArt = new Arthrosis(0, 0, 0, calc.Radians(70));
	//親指の関節3つ(第1:A 第2:B 第3:C)
	f[0][0] = new Arthrosis(50, calc.Radians(-60), calc.Radians(-15), calc.Radians(80));
	f[0][1] = new Arthrosis(30, calc.Radians(40), calc.Radians(-10), calc.Radians(90));
	f[0][2] = new Arthrosis(50, calc.Radians(10), 0, 0);
	//人差し指の関節4つ
	f[1][0] = new Arthrosis(100, calc.Radians(-15), calc.Radians(-15), calc.Radians(20));
	f[1][1] = new Arthrosis(30, calc.Radians(15), 0, 0);
	f[1][2] = new Arthrosis(30, calc.Radians(2), 0, 0);
	f[1][3] = new Arthrosis(30, calc.Radians(2), 0, 0);

	//中指の関節4つ
	f[2][0] = new Arthrosis(100, 0, 0, calc.Radians(30));
	f[2][1] = new Arthrosis(30, 0, 0, 0);
	f[2][2] = new Arthrosis(40, 0, 0, 0);
	f[2][3] = new Arthrosis(30, 0, 0, 0);

	//薬指の関節4つ
	f[3][0] = new Arthrosis(90, calc.Radians(15), 0, calc.Radians(30));
	f[3][1] = new Arthrosis(30, calc.Radians(-15), 0, 0);
	f[3][2] = new Arthrosis(40, 0, 0, 0);
	f[3][3] = new Arthrosis(30, 0, 0, 0);

	//小指の関節4つ
	f[4][0] = new Arthrosis(80, calc.Radians(32), 0, calc.Radians(30));
	f[4][1] = new Arthrosis(20, calc.Radians(-32), 0, 0);
	f[4][2] = new Arthrosis(20, 0, 0, 0);
	f[4][3] = new Arthrosis(30, 0, 0, 0);

	oArt->AddChild(pArt);
	pArt->AddChild(f[0][0]);
	pArt->AddChild(f[1][0]);
	pArt->AddChild(f[2][0]);
	pArt->AddChild(f[3][0]);
	pArt->AddChild(f[4][0]);
	for (int i = 0; i < 3; i++) {
		if(i < 2)f[0][i]->AddChild(f[0][i + 1]);
		f[1][i]->AddChild(f[1][i + 1]);
		f[2][i]->AddChild(f[2][i + 1]);
		f[3][i]->AddChild(f[3][i + 1]);
		f[4][i]->AddChild(f[4][i + 1]);
	}

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 ) {
		Draw(pArt);
		for (int i = 0; i < 4; i++ ) {
			if (i < 3)Draw(f[0][i]);
			Draw(f[1][i]);
			Draw(f[2][i]);
			Draw(f[3][i]);
			Draw(f[4][i]);
		}

		if (beforeAngle == pArt->GetAngle() )
			addAngle *= -1;

		beforeAngle = pArt->GetAngle();
		pArt->Move(calc.Radians(addAngle));
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}