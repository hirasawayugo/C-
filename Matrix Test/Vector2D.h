#pragma once

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
};

