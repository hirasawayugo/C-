#pragma once
#include "Vector2D.h"

class Calculator
{
public:
	Calculator();
	virtual ~Calculator();
public:
	double dist(Vector2D vec1, Vector2D vec2);
	double angle( Vector2D vec1, Vector2D vec2 );
	double Radians(double degree);
	double Degrees(double radian);
private:
	const double PI = 3.14;
};

