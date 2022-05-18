#pragma once
#include "Vector2D.h"

class Calculator
{
public:
	Calculator();
	virtual ~Calculator();
public:
public:
	double Besier(const double& start, const double& end, const double& blend);
	double Slope(const Vector2D& start, const Vector2D& end);
	double Lerp(const double& start, const double& end, const double& blend);
	Vector2D Lerp2D(const Vector2D& start, const Vector2D& end, const double& blend);
	double Dist(Vector2D vec1, Vector2D vec2);
	double Angle( Vector2D vec1, Vector2D vec2 );
	double Radians(double degree);
	double Degrees(double radian);
private:
	const double PI = 3.14;
};

