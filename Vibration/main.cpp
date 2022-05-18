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
	bool fin = false;

	//x = ����(1����) 1���� = 10
	vector<double> sx;
	//y = �U��(�h��̋���)
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
		
		//�`��
		for (int i = 1; i < rx.size(); i++) {
			draw.Circle(Vector2D(rx[i], ry[i] + 350), 1, Drwawer::COLOR::WHITE);
			draw.Line(Vector2D(rx[i - 1], ry[i - 1] + 350), Vector2D(rx[i], ry[i] + 350), Drwawer::COLOR::WHITE);
		}
		draw.Circle(Vector2D(x, y + 350), Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}