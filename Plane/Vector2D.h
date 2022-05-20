#pragma once

struct Vector2D
{
	double x;
	double y;
	//���
	Vector2D()
	{
		x = 0;
		y = 0;
	}
	Vector2D(double sub_x, double sub_y) 
	{
		x = sub_x;
		y = sub_y;
	}
	//���Z
	void Add(const Vector2D& vec)
	{
		x += vec.x;
		y += vec.y;
	}
	Vector2D operator+(Vector2D vec) 
	{
		return Vector2D(x + vec.x,y + vec.y);
	}
	Vector2D operator-(Vector2D vec)
	{
		return Vector2D(x - vec.x, y - vec.y);
	}
	//����
	double Dot(const Vector2D& vec)
	{
		return (x * vec.x) + (y * vec.y);
	}
	//�O��
	double Cross(const Vector2D& vec)
	{
		return (x * vec.y) - (y * vec.x);
	}
};

