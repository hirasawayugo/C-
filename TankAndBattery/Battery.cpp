#include "Battery.h"

Battery::Battery()
{
	width = 0.5;
	length = 1.0;
	UpdatePos(Vector2D(0,0));
}

Battery::Battery(const Vector2D& tPos)
{
	width = 0.5;
	length = 1.0;
	UpdatePos( tPos );
}

Battery::~Battery()
{
}

void Battery::UpdatePos( const Vector2D& tPos )
{
	pos = tPos;
	frontLeft = Vector2D(-width / 2, length);
	frontRight = Vector2D(width / 2, length);
	backLeft = Vector2D(-width / 2, 0);
	backRight = Vector2D(width / 2, 0);
	frontLeft.Add(pos);
	frontRight.Add(pos);
	backLeft.Add(pos);
	backRight.Add(pos);
}

void Battery::Rotate( const double& radian )
{
	Matrix33 mat;
	mat.Rotate(radian);

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

void Battery::debuglog()
{
	double bAngle = angle * 180 / 3.14;
	printf("砲台 角度:%0.2f\n", pos, bAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", frontLeft, frontRight);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n", backLeft, backRight);
}
