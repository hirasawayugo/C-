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

	Vector2D add(Vector2D& vec)
	{
		return (Vector2D(x + vec.x, y + vec.y));
	}

	Vector2D operator+(Vector2D& vec) 
	{
		return add(vec);
	}
};

