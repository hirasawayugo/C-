#include <stdio.h>
#include "Tank.h"
#include "Matrix33.h"


Tank::Tank()
{
	angle = 0.0;
	SetSidePos();
	battery.UpdatePos(pos);
}

Tank::~Tank()
{
}

void Tank::SetPos( const Vector2D& sPos)
{
	pos = sPos;
	SetSidePos();
	battery.UpdatePos(pos);
}

void Tank::Rotate(const double& radian)
{
	angle += radian;
	SetSidePos();
	battery.Rotate(radian);
}

void Tank::BatRotate(const double& radian)
{
	Matrix33 mat;
	mat.Rotate(radian);
	battery.Rotate(radian);
}

Vector2D Tank::GetPos() const
{
	return pos;
}
void Tank::debuglog()
{
	double tAngle = angle * 180 / 3.14;
	printf("戦車 位置 X:%0.2f Y:%0.2f 角度:%0.2f\n", GetPos().x, GetPos().y, tAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", frontLeft.x, frontLeft.y,frontRight.x, frontRight.y);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n", backLeft.x, backLeft.y, backRight.x, backRight.y);
	battery.debuglog();
}

void Tank::SetSidePos()
{
	Matrix33 mat;
	mat.Rotate(angle);

	frontLeft = Vector2D(LEFT, FRONT);
	frontRight = Vector2D(RIGHT, FRONT);
	backLeft = Vector2D(LEFT, BACK);
	backRight = Vector2D(RIGHT, BACK);

	frontLeft = mat * frontLeft;
	frontRight = mat * frontRight;
	backLeft = mat * backLeft;
	backRight = mat * backRight;

	frontLeft.Add(pos);
	frontRight.Add(pos);
	backLeft.Add(pos);
	backRight.Add(pos);
}
