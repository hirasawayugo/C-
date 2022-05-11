#include"Arthrosis.h"
#include "Calculator.h"

int main()
{
	Calculator calc;
	//左手
	//手のひらを正面に想定
	// 1 = 1cm
	//起点となる手首の関節
	Arthrosis* pArt = new Arthrosis(0, 0, 0, calc.Radians(70));
	//親指の関節3つ(第1:A 第2:B 第3:C)
	Arthrosis* f1A = new Arthrosis(5, calc.Radians(-60), calc.Radians(-15), calc.Radians(80));
	Arthrosis* f1B = new Arthrosis(3, calc.Radians(60), calc.Radians(-10), calc.Radians(90));
	Arthrosis* f1C = new Arthrosis(3, calc.Radians(10), 0, 0);
	//人差し指の関節4つ
	Arthrosis* f2A = new Arthrosis(10, calc.Radians(-15), calc.Radians(-15), calc.Radians(20));
	Arthrosis* f2B = new Arthrosis(3, calc.Radians(15), 0, 0);
	Arthrosis* f2C = new Arthrosis(3, calc.Radians(2), 0, 0);
	Arthrosis* f2D = new Arthrosis(3, calc.Radians(2), 0, 0);

	//中指の関節4つ
	Arthrosis* f3A = new Arthrosis(10, 0, 0, calc.Radians(30));
	Arthrosis* f3B = new Arthrosis(3, 0, 0, 0);
	Arthrosis* f3C = new Arthrosis(4, 0, 0, 0);
	Arthrosis* f3D = new Arthrosis(3, 0, 0, 0);

	//薬指の関節4つ
	Arthrosis* f4A = new Arthrosis(9, calc.Radians(15), 0, calc.Radians(30));
	Arthrosis* f4B = new Arthrosis(3, calc.Radians(-15), 0, 0);
	Arthrosis* f4C = new Arthrosis(4, 0, 0, 0);
	Arthrosis* f4D = new Arthrosis(3, 0, 0, 0);

	pArt->AddChild(f1A);
	pArt->AddChild(f2A);
	pArt->AddChild(f3A);
	pArt->AddChild(f4A);
	f1A->AddChild(f1B);
	f1B->AddChild(f1C);
	f2A->AddChild(f2B);
	f2B->AddChild(f2C);
	f2C->AddChild(f2D);
	f3A->AddChild(f3B);
	f3B->AddChild(f3C);
	f3C->AddChild(f3D);
	f4A->AddChild(f4B);
	f4B->AddChild(f4C);
	f4C->AddChild(f4D);

	pArt->Log();
	f1A->Log();
	f1B->Log();
	f1C->Log();
	puts("");
	f2A->Log();
	f2B->Log();
	f2C->Log();
	f2D->Log();
	puts("");
	f3A->Log();
	f3B->Log();
	f3C->Log();
	f3D->Log();
	puts("");
	f4A->Log();
	f4B->Log();
	f4C->Log();
	f4D->Log();

	return 0;
}