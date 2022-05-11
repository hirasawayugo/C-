#pragma once
#include "Vector2D.h"
#include "BaseNode.h"

class Arthrosis:public BaseNode
{
public:
	Arthrosis(double len, double fixed, double min, double max);
	virtual ~Arthrosis();
public:
	void Move( double radian );
private:
	double fixedAngle;
	double minAngle;
	double maxAngle;
};

