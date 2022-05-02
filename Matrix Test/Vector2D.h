#pragma once

struct Vector2D
{
	double x;
	double y;
	//‘ã“ü
	Vector2D(double sub_x, double sub_y) 
	{
		x = sub_x;
		y = sub_y;
	}
	//‰ÁZ
	void Add(Vector2D& vec)
	{
		x += vec.x;
		y += vec.y;
	}
	void operator+(Vector2D& vec) 
	{
		Add(vec);
	}
	//“àÏ
	double Dot(const Vector2D& vec)
	{
		return (x * vec.x) + (y * vec.y);
	}
	//ŠOÏ
	double Cross(const Vector2D& vec)
	{
		return (x * vec.y) - (y * vec.x);
	}
};

