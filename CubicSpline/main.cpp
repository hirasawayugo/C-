#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include "CubicSpline.h"

#include <vector>

using namespace std;

int mStartTime = 0;         //����J�n����
double mCount = 0;             //�J�E���^
float mFps = 0;             //fps
static const int N = 60;//���ς����T���v����
static const double FPS = 60;	//�ݒ肵��FPS
const int dCount = 1000;

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

bool fps() {
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
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
		
		//�`��
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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}