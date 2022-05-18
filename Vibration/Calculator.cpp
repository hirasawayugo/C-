#include <math.h>
#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::Besier(const double& start, const double& end, const double& blend)
{
	double t = blend;
	double aid;
	if (end - start == 0) aid = start * 2;
	else aid = (end - start) / 2 + start;
	return start * pow((1 - t), 2) + 2 * aid * t * (1 - t) + end * pow(t, 2);
}

double Calculator::Slope(const Vector2D& start, const Vector2D& end)
{
	return (end.y - start.y) / (end.x - start.x);
}

double Calculator::Lerp(const double& start, const double& end, const double& blend)
{
	double t = blend;
	return start + (end - start) * t;
}

Vector2D Calculator::Lerp2D(const Vector2D& start, const Vector2D& end, const double& blend)
{
	double x = Lerp(start.x, end.x ,blend);
	double y = Lerp(start.y, end.y ,blend);
	return Vector2D(x, y);
}

double Calculator::Dist(Vector2D vec1, Vector2D vec2)
{
	//2点間の距離を求める(三平方の定理)= √(x1-x2)²+ (y1-y2)²
	//斜辺(距離)
	double diff = sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
	return diff;
}

double Calculator::Angle(Vector2D vec1, Vector2D vec2)
{	
	//2点間の角度を求める(三平方の定理)= tanΘ((y1-y2) / (x1-x2) )
	//斜辺の角度
	double radian = atan((vec1.y - vec2.y) / (vec1.x - vec2.x));
	return radian;
}

double Calculator::Radians(double degree)
{
	return degree * PI / 180;
}

double Calculator::Degrees(double radian)
{
	return radian * 180 / PI;
}
