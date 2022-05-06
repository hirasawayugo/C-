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
	double angle;
private:
	const double WIDTH = 0.5;
	const double LENGHT = 1.0;
	const double RIGHT = WIDTH / 2;
	const double LEFT = -WIDTH / 2;
	const double FRONT = LENGHT;
	const double BACK = 0;
};

