#include "Matrix33.h"
#include <stdio.h>
#include "Calculator.h"
#include "BaseNode.h"

#include "DxLib.h"

Vector2D windowVec(Vector2D castVec)
{
	Vector2D origin = Vector2D(300, 250);
	return Vector2D(origin.x + castVec.x, origin.y - castVec.y);
}
void Draw(BaseNode* node)
{
	Vector2D waVec = windowVec(node->GetPos());
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
	Calculator calc;
	BaseNode* camera = new BaseNode();
	BaseNode* A = new BaseNode();
	BaseNode* B = new BaseNode();
	BaseNode* C = new BaseNode();
	BaseNode* D = new BaseNode();
	camera->AddChild(A);
	A->AddChild(B);
	B->AddChild(C);
	C->AddChild(D);

	A->Foward(Vector2D(0, 50));
	B->Foward(Vector2D(0, 50));
	C->Foward(Vector2D(0, 50));
	D->Foward(Vector2D(0, 50));
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		A->Rotate(calc.Radians(1), true);
		B->Rotate(calc.Radians(1), false);
		C->Rotate(calc.Radians(1), true);
		D->Rotate(calc.Radians(1), false);

		Vector2D caVec = windowVec(camera->GetPos());
		Vector2D aVec = windowVec(A->GetPos());
		Vector2D bVec = windowVec(B->GetPos());
		Vector2D cVec = windowVec(C->GetPos());
		Vector2D dVec = windowVec(D->GetPos());

		DrawPixel(caVec.x, caVec.y, GetColor(255, 255, 255));
		DrawPixel(aVec.x, aVec.y, GetColor(255, 255, 255));
		DrawPixel(bVec.x, bVec.y, GetColor(255, 255, 255));
		DrawPixel(cVec.x, cVec.y, GetColor(255, 255, 255));
		DrawPixel(dVec.x, dVec.y, GetColor(255,255,255) );
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}