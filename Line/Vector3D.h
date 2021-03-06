#pragma once

struct Vector3D
{
	double x;
	double y;
	double z;

	//????
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
	//???Z
	void Add(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}
	Vector3D operator+(Vector3D& vec)
	{
		return Vector3D(x + vec.x, y + vec.y, z + vec.z);
	}
	//???Z
	void Sub(const Vector3D& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}
	Vector3D operator-(Vector3D vec)
	{
		return Vector3D(x - vec.x, y - vec.y, z - vec.z);
	}
	Vector3D operator*(double power)
	{
		return Vector3D(x * power, y * power, z * power);
	}
	bool operator==(Vector3D vec)
	{
		if ( x == vec.x && y == vec.y && z == vec.z) {
			return true;
		}
		return false;
	}
	//????
	double Dot(const Vector3D& vec)
	{
		return (x * vec.x) + (y * vec.y) + (z * vec.z);
	}
	//?O??
	double Cross(const Vector3D& vec)
	{
		return (x * vec.y) - (y * vec.x) - (z * vec.z);
	}
};