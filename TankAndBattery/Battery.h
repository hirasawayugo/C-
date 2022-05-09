#pragma once
#include <stdio.h>
#include <array>
#include "Vector2D.h"
#include "Matrix33.h"

class Battery
{
public:
	Battery(double width, double lenght);
	Battery( const Vector2D& tPos );
	virtual ~Battery();
public:
	void UpdatePos( const Vector2D& tPos);
	void Rotate(const double& radian);
	void debuglog();
private:
	Vector2D pos;
	std::array<Vector2D, 4> point;
	double angle;
private:
	double WIDTH;
	double LENGHT;
	double RIGHT;
	double LEFT;
	double FRONT;
	double BACK;
};

