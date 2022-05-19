#include "Camera.h"
#include "CubicSpline.h"

#include <vector>

using namespace std;

Camera::Camera()
{
	angle = 0;
}

Camera::~Camera()
{
}

void Camera::Foward( const Vector2D& vec)
{
	lPos.Add(vec);
}

void Camera::Foward(const double& x, const double& y)
{
	lPos.Add(Vector2D(x, y));
}

void Camera::Rotate( const double& radian)
{
	angle += radian;
}

Vector2D Camera::GetPos() const
{
	return Vector2D(lPos.x + vVec.x, lPos.y + vVec.y);
}

double Camera::GetAngle() const
{
	return angle;
}

void Camera::Vibration(double x, double y, double currentSec)
{
	//���g����15hz
	//1����(�b)
	double oneCycleSec = 1.0 / 15.0;
	double PI2 = 2 * 3.14;
	//�덷���Ȃ������ߊ|���Z���ɂ��Ă��܂����A(�o�ߎ��� / �������� * 2��)�ł�
	vVec.x = x * sin(PI2 * currentSec / oneCycleSec);
	vVec.y = y * sin(PI2 * currentSec / oneCycleSec);
}
