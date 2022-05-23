#pragma once
#include "DxLib.h"
#include "Vector3D.h"

#include <vector>

using namespace std;

class Drwawer
{
public:
	Drwawer();
	virtual ~Drwawer();
public:
	enum class COLOR
	{
		RED,
		GREEN,
		BLUE,
		YELLOW,
		WHITE,
	};
private:
	unsigned int Color(COLOR type);
public:
	void Line(const Vector3D& vec1, const Vector3D& vec2, COLOR type);
	void Line(const Vector3D& vec1, const Vector3D& vec2, const unsigned int& color);
	void Sphere(const Vector3D& vec, COLOR type);
	void Sphere(const Vector3D& vec, double range, COLOR type);
	void Sphere(const Vector3D& vec, const unsigned int& color);
	void Plate(const vector<Vector3D> vec, COLOR type);
	void Plate(const vector<Vector3D> vec, const unsigned int& color);
	void Pixel( const Vector3D& vec, COLOR type );
private:
	double r = 10;
public:
	const int WIN_WIDTH = 800;
	const int WIN_HEIGHT = 800;
};

