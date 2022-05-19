#include "DxLib.h"
#include "Drawer.h"
#include "Calculator.h"
#include "Camera.h"
#include "Object.h"

#include <vector>

using namespace std;

int mStartTime = 0;         //����J�n����
static const double FPS = 60;	//�ݒ肵��FPS

void wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = 1 / FPS * 1000 - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

bool fps() {
	mStartTime = GetNowCount();
	return true;
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
	bool isVibing = false;
	double currentSec = 0;
	double blendMax = 5.0;
	double time = 0.5;
	const int maxX = 20;
	const int maxY = 50;
	double xw = maxX;
	double yw = maxY;

	Camera* camera = new Camera();
	Object object;
	object.SetCamera(camera);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		clsDx();

		if (CheckHitKey(KEY_INPUT_A) == 1) {
			camera->Foward(Vector2D(-1, 0));
			printfDx("���ړ���\n");
		}
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			camera->Foward(Vector2D(1, 0));
			printfDx("�E�ړ���\n");
		}
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			camera->Foward(Vector2D(0, -1));
			printfDx("���ړ���\n");
		}
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			camera->Foward(Vector2D(0, 1));
			printfDx("��ړ���\n");
		}
		if (CheckHitKey(KEY_INPUT_Q) == 1) {
			camera->Rotate(calc.Radians(-1));
			printfDx("����]��\n");
		}
		if (CheckHitKey(KEY_INPUT_E) == 1) {
			camera->Rotate(calc.Radians(1));
			printfDx("�E��]��\n");
		}

		if (CheckHitKey(KEY_INPUT_I) == 1 && !isVibing) {
			isVibing = true;
		}
		if (isVibing) {
			camera->Vibration(xw, 0, currentSec);
			//1�t���[��1/60�b�̂���1/60�b�𑫂�
			currentSec += 1.0 / 60.0;
			xw -= (double)maxX / (60.0 * 0.25);
			if (xw <= 0) {
				isVibing = false;
				xw = maxX;
				currentSec = 0;
			}
		}
		Vector2D pos = object.GetPos();
		//�`��
		draw.Circle(pos, 100,Drwawer::COLOR::WHITE);

		fps();
		wait();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}