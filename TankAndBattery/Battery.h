#pragma once
#include <stdio.h>
#include "Vector2D.h"
#include "Matrix33.h"

class Battery
{
public:
	Battery();
	Battery( const Vector2D& tPos );
	virtual ~Battery();
public:
	void UpdatePos( const Vector2D& tPos);
	void Rotate(const double& radian);
	void debuglog();
private:
	Vector2D pos;
	Vector2D frontLeft;
	Vector2D frontRight;
	Vector2D backLeft;
	Vector2D backRight;
	double width;
	double length;
	double angle;
private:
	const double RIGHT = width / 2;
	const double LEFT = -width / 2;
	const double FRONT = length;
	const double BACK = 0;
};

