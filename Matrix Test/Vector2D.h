#pragma once
#include"Matrix33.h"

struct Vector2D
{
	double x;
	double y;

	Vector2D(double sub_x, double sub_y) 
	{
		x = sub_x;
		y = sub_y;
	}

	void add(Vector2D& vec)
	{
		x += vec.x;
		y += vec.y;
	}

	void operator+(Vector2D& vec) 
	{
		add(vec);
	}

	void transform( const Matrix33& matrix ) 
	{
		Vector2D multVec(x, y);
		x = multVec.x * matrix.value[0][0] + multVec.y * matrix.value[0][1] + matrix.value[0][2];
		y = multVec.x * matrix.value[1][0] + multVec.y * matrix.value[1][1] + matrix.value[1][2];
	}

	void operator*( const Matrix33& matrix )
	{
		transform(matrix);
	}
};

