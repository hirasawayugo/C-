#pragma once
#include "Vector2D.h"

class Calculator
{
public:
	Calculator();
	virtual ~Calculator();
public:
	double dist( Vector2D vec1, Vector2D vec2 );
};

