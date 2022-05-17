#pragma once
#include "DxLib.h"
#include "Vector2D.h"

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
	Vector2D CastWinVec( Vector2D vec );
	unsigned int Color(COLOR type);
public:
	void Circle(const Vector2D& vec, COLOR type);
	void Circle(const Vector2D& vec, const int& radius, COLOR type);
	void Circle(const Vector2D& vec, const int& radius, const unsigned int& color);
	void Line(const Vector2D& vec1, const Vector2D& vec2, COLOR type);
	void Line(const Vector2D& vec1, const Vector2D& vec2, const unsigned int& color);
	void Pixel( const Vector2D& vec, COLOR type );
private:
	double r = 5;
public:
	const int WIN_WIDTH = 800;
	const int WIN_HEIGHT = 800;
};

