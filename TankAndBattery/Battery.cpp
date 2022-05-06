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

	Matrix33 mat;
	mat.Rotate(angle);
	frontLeft = mat * frontLeft;
	frontRight = mat * frontRight;
	backLeft = mat * backLeft;
	backRight = mat * backRight;

	frontLeft.Add(pos);
	frontRight.Add(pos);
	backLeft.Add(pos);
	backRight.Add(pos);
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
	printf("　　 前左 X:%0.2f Y:%0.2f 前右 X:%0.2f Y:%0.2f\n", frontLeft, frontRight);
	printf("　　 後左 X:%0.2f Y:%0.2f 後右 X:%0.2f Y:%0.2f\n\n", backLeft, backRight);
}
