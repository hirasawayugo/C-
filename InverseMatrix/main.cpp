#include "Matrix33.h"
#include <stdio.h>
#include "Calculator.h"
#include "BaseNode.h"
#include "Camera.h"

#include "DxLib.h"

Vector2D winVec(Vector2D vec)
{
	return Vector2D( 300 + vec.x, 250 - vec.y);
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
	bool beforeIn = false;
	Calculator calc;
	Camera* camera = new Camera();
	BaseNode* origin = new BaseNode();
	BaseNode* A = new BaseNode();
	BaseNode* B = new BaseNode();
	BaseNode* C = new BaseNode();
	BaseNode* D = new BaseNode();
	camera->AddChild(origin);
	origin->AddChild(A);
	A->AddChild(B);
	B->AddChild(C);
	C->AddChild(D);

	A->Foward(Vector2D(0, 30));
	B->Foward(Vector2D(0, 30));
	C->Foward(Vector2D(0, 30));
	D->Foward(Vector2D(0, 30));
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
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
			origin->Rotate(calc.Radians(-1), false);
			printfDx("左回転中\n");
		}
		if (CheckHitKey(KEY_INPUT_E) == 1) {
			origin->Rotate(calc.Radians(1),false);
			printfDx("右回転中\n");
		}
		if (CheckHitKey(KEY_INPUT_I) == 1 && !beforeIn) {
			camera->inversion = !camera->inversion;
			printfDx("反転\n");
			beforeIn = true;
		}
		else
		{
			beforeIn = CheckHitKey(KEY_INPUT_I);
		}
		origin->Rotate(calc.Radians(1), camera->inversion);
		//B->Rotate(calc.Radians(2), true);

		Vector2D oVec = winVec(origin->GetPos());
		Vector2D aVec = winVec(A->GetPos());
		Vector2D bVec = winVec(B->GetPos());
		Vector2D cVec = winVec(C->GetPos());
		Vector2D dVec = winVec(D->GetPos());

		DrawPixel(oVec.x, oVec.y, GetColor(255, 255, 0));
		DrawPixel(aVec.x, aVec.y, GetColor(255, 255, 255));
		DrawPixel(bVec.x, bVec.y, GetColor(255, 255, 255));
		DrawPixel(cVec.x, cVec.y, GetColor(255, 255, 255));
		DrawPixel(dVec.x, dVec.y, GetColor(255,255,255) );
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}