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

void Tank::SetPos( const Matrix33& mat)
{
	pos = mat * pos;
	SetSidePos();
	battery.UpdatePos(pos);
}

void Tank::Rotate(const double& radian)
{
	Matrix33 mat;
	mat.Rotate(radian);
	SetSideRoate(mat);
	battery.Rotate(radian);
	angle += radian;
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

double Tank::GetAngle() const
{
	return angle;
}

void Tank::debuglog()
{
	double tAngle = GetAngle() * 180 / 3.14;
	printf("戦車 位置 X:%0.2f Y:%0.2f 角度:%0.2f\n", GetPos().x, GetPos().y, tAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", frontLeft.x, frontLeft.y,frontRight.x, frontRight.y);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n", backLeft.x, backLeft.y, backRight.x, backRight.y);
	battery.debuglog();
}

void Tank::SetSidePos()
{
	frontLeft = Vector2D(LEFT, FRONT);
	frontRight = Vector2D(RIGHT, FRONT);
	backLeft = Vector2D(LEFT, BACK);
	backRight = Vector2D(RIGHT, BACK);
	frontLeft.Add(pos);
	frontRight.Add(pos);
	backLeft.Add(pos);
	backRight.Add(pos);
}

void Tank::SetSideRoate( Matrix33& mat )
{
	Vector2D fl(LEFT, FRONT);
	Vector2D fr(RIGHT, FRONT);
	Vector2D bl(LEFT, BACK);
	Vector2D br(RIGHT, BACK);

	fl = mat * fl;
	fr = mat * fr;
	bl = mat * bl;
	br = mat * br;

	fl.Add(pos);
	fr.Add(pos);
	bl.Add(pos);
	br.Add(pos);

	frontLeft = fl;
	frontRight = fr;
	backLeft = bl;
	backRight = br;
}
