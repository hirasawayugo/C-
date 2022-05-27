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
	void Sphere(const Vector3D& vec, COLOR type);
	void Sphere(const Vector3D& vec, const unsigned int& color);
	void Plate(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3, const Vector3D& vec4, COLOR type);
	void Plate(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3, const Vector3D& vec4, const unsigned int& color);
	void Line(const Vector3D& vec1, const Vector3D& vec2, const unsigned int& color);
private:
	double r = 10;
public:
	const int WIN_WIDTH = 800;
	const int WIN_HEIGHT = 800;
};

