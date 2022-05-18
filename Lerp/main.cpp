#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include <vector>

int mStartTime = 0;         //����J�n����
double mCount = 0;             //�J�E���^
float mFps = 0;             //fps
static const int BPM = 190;
static const int beet = 4;
static const int N = 60;//���ς����T���v����
static const double FPS = 60;	//�ݒ肵��FPS
const int dCount = 1000;

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS / BPM - tookTime;	//�҂ׂ�����
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
			//�u�����h�������W�v�Z
			midPoint = calc.Lerp2D(vecList[1], vecList[2], blend);
			vec = calc.Lerp2D(vecList[0], midPoint, blend);

			blend += 1.0 / dCount;
			//�Ȑ�(��)
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

		
		//�`��
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

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}