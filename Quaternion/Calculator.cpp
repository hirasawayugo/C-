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

double Calculator::Lerp(const double& start, const double& end, const double& blend)
{
	double t = blend;
	return start + (end - start) * t;
}

double Calculator::Radians(double degree)
{
	return degree * PI / 180;
}

double Calculator::Degrees(double radian)
{
	return radian * 180 / PI;
}
