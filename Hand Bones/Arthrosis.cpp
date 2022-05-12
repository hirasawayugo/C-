#include "Arthrosis.h"

// len:親との距離 fixed:初期の固定角度 min：反時計回りの最高角度 max：時計回りの最高角度
Arthrosis::Arthrosis(double len, double fixed, double min, double max)
{
	Foward(Vector2D(0,len));
	fixedAngle = fixed;
	minAngle = min;
	maxAngle = max;
	lAngle = fixed;
}

Arthrosis::~Arthrosis()
{
}

void Arthrosis::Move(double radian)
{
	if (lAngle + radian > maxAngle || lAngle + radian < minAngle)
	{
		radian = 0;
	}
	double angle = fixedAngle + radian;
	Rotate(angle);
}
