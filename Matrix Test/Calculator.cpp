#include <math.h>
#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::dist(Vector2D vec1, Vector2D vec2)
{
	//2点の距離を求める(三平方の定理)= √(x1-x2)²+ (y1-y2)²
	//斜辺(距離)
	double diff = sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
	return diff;
}
