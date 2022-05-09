#include "Battery.h"

Battery::Battery(double width, double lenght)
{
	WIDTH = width;
	LENGHT = lenght;
	RIGHT = WIDTH / 2;
	LEFT = -WIDTH / 2;
	FRONT = LENGHT / 2;
	BACK = -LENGHT / 2;
	angle = 0;
	UpdatePos(Vector2D(0,0));
}

Battery::Battery(const Vector2D& tPos)
{
	UpdatePos( tPos );
}

Battery::~Battery()
{
}

void Battery::UpdatePos( const Vector2D& tPos )
{
	pos = tPos;
	point[0] = Vector2D(LEFT, FRONT);
	point[1] = Vector2D(RIGHT, FRONT);
	point[2] = Vector2D(RIGHT, BACK);
	point[3] = Vector2D(LEFT, BACK);

	Matrix33 mat;
	mat.Rotate(angle);
	point[0] = mat * point[0];
	point[1] = mat * point[1];
	point[2] = mat * point[2];
	point[3] = mat * point[3];

	point[0].Add(pos);
	point[1].Add(pos);
	point[2].Add(pos);
	point[3].Add(pos);
}

void Battery::Rotate( const double& radian )
{
	angle += radian;
	UpdatePos(pos);
}

void Battery::debuglog()
{
	double bAngle = angle * 180 / 3.14;
	printf("砲台 角度:%0.2f\n", bAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", point[0], point[1]);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n\n", point[3], point[2]);
}
