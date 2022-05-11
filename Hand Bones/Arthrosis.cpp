#include "Arthrosis.h"

// len:�e�Ƃ̋��� fixed:�����̌Œ�p�x min�F�����v���̍ō��p�x max�F���v���̍ō��p�x
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
	if (radian > maxAngle)
	{
		radian = maxAngle;
	}
	if (radian < minAngle)
	{
		radian = minAngle;
	}
	double angle = fixedAngle + radian;
	Rotate(angle);
}