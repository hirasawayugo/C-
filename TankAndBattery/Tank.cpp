#include <stdio.h>
#include "Tank.h"
#include "Matrix33.h"


Tank::Tank(double width, double lenght)
{
	WIDTH = width;
	LENGHT = lenght;
	RIGHT = WIDTH / 2;
	LEFT = -WIDTH / 2;
	FRONT = LENGHT / 2;
	BACK = -LENGHT / 2;
	SetSidePos();
	angle = 0.0;
}

Tank::~Tank()
{
}

void Tank::SetPos( const Vector2D& sPos)
{
	pos = sPos;
	SetSidePos();
	battery->UpdatePos(pos);
}

void Tank::Forward(const double power)
{
	Vector2D vec( 0, power );
	Matrix33 mat;
	mat.Rotate(angle);
	mat.Move(vec);
	SetPos(mat * pos);
	battery->UpdatePos(pos);
}

void Tank::Rotate(const double& radian)
{
	angle += radian;
	SetSidePos();
	battery->Rotate(radian);
}

Vector2D Tank::GetPos() const
{
	return pos;
}

void Tank::AddBattery( Battery *bat)
{
	battery = bat;
	battery->UpdatePos(pos);
}

void Tank::debuglog()
{
	double tAngle = angle * 180 / 3.14;
	printf("戦車 位置 X:%0.2f Y:%0.2f 角度:%0.2f\n", GetPos().x, GetPos().y, tAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", point[0].x, point[0].y, point[1].x, point[1].y);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n", point[3].x, point[3].y, point[2].x, point[2].y);
}

void Tank::SetSidePos()
{
	Matrix33 mat;
	mat.Rotate(angle);

	point[0] = Vector2D(LEFT, FRONT);
	point[1] = Vector2D(RIGHT, FRONT);
	point[2] = Vector2D(RIGHT, BACK);
	point[3] = Vector2D(LEFT, BACK);

	point[0] = mat * point[0];
	point[1] = mat * point[1];
	point[2] = mat * point[2];
	point[3] = mat * point[3];

	point[0].Add(pos);
	point[1].Add(pos);
	point[2].Add(pos);
	point[3].Add(pos);
}
