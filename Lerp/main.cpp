#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include <vector>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	Drwawer draw;

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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
		//�u�����h�������W�v�Z
		midPoint = calc.Lerp2D(vecList[1], vecList[2], blend);
		vec = calc.Lerp2D(vecList[0], midPoint, blend);

		blend += 0.001;
		if (blend > 1) 
		{
			blend = 0;
		}

		//�Ȑ�(��)
		if (count != 1000) {
			trace[count] = vec;
			count++;
		}
		
		
		//�`��
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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}