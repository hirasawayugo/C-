#pragma once

struct Vector3D
{
	double x;
	double y;
	double z;

	//ë„ì¸
	Vector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3D(double subX, double subY, double subZ)
	{
		x = subX;
		y = subY;
		z = subZ;

	}
	//â¡éZ
	void Add(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}
	void operator+(Vector3D& vec)
	{
		Add(vec);
	}
	//å∏éZ
	void Sub(const Vector3D& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}
	Vector3D operator-(Vector3D& vec)
	{
		return Vector3D(x - vec.x, y - vec.y, z - vec.z);
	}
	Vector3D operator*(double value)
	{
		return Vector3D(x * value, y * value, z * value);
	}
	//ì‡êœ
	double Dot(const Vector3D& vec)
	{
		return (x * vec.x) + (y * vec.y) + (z * vec.z);
	}
	//äOêœ
	Vector3D Cross(const Vector3D& vec)
	{
		double X = y * vec.z - z * vec.y;
		double Y = z * vec.x - x * vec.z;
		double Z = x * vec.y - y * vec.x;
		return Vector3D(X,Y,Z);
	}
};