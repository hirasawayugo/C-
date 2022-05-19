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
	//ü”g”‚Í15hz
	//1üŠú(•b)
	double oneCycleSec = 1.0 / 15.0;
	double PI2 = 2 * 3.14;
	//Œë·‚ğ‚È‚­‚·‚½‚ßŠ|‚¯Z‚ğæ‚É‚µ‚Ä‚¢‚Ü‚·‚ªA(Œo‰ßŠÔ / üŠúŠÔ * 2ƒÎ)‚Å‚·
	vVec.x = x * sin(PI2 * currentSec / oneCycleSec);
	vVec.y = y * sin(PI2 * currentSec / oneCycleSec);
}
