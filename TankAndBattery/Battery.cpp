#include "Battery.h"

Battery::Battery()
{
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
	frontLeft = Vector2D(LEFT, FRONT);
	frontRight = Vector2D(RIGHT, FRONT);
	backLeft = Vector2D(LEFT, BACK);
	backRight = Vector2D(RIGHT, BACK);
	frontLeft.Add(pos);
	frontRight.Add(pos);
	backLeft.Add(pos);
	backRight.Add(pos);
}

void Battery::Rotate( const double& radian )
{
	Matrix33 mat;
	angle += radian;
	mat.Rotate(angle);

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
	printf("砲台 角度:%0.2f\n", bAngle);
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", frontLeft, frontRight);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n\n", backLeft, backRight);
}
