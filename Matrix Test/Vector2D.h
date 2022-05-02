#pragma once

struct Vector2D
{
	double x;
	double y;
	//���
	Vector2D(double sub_x, double sub_y) 
	{
		x = sub_x;
		y = sub_y;
	}
	//���Z
	void Add(Vector2D& vec)
	{
		x += vec.x;
		y += vec.y;
	}
	void operator+(Vector2D& vec) 
	{
		Add(vec);
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

