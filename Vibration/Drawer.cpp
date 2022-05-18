#include "Drawer.h"

Drwawer::Drwawer()
{
	SetGraphMode(WIN_WIDTH + r * 2, WIN_HEIGHT + r * 2, 0);
	SetWindowSize(WIN_WIDTH + r * 2, WIN_HEIGHT + r * 2);
}

Drwawer::~Drwawer()
{
}

Vector2D Drwawer::CastWinVec(Vector2D vec)
{
	return Vector2D( vec.x + r, -vec.y + WIN_HEIGHT + r);
}

unsigned int Drwawer::Color(COLOR type)
{
	switch (type)
	{
	case Drwawer::COLOR::WHITE:
		return GetColor(255, 255, 255);
	case Drwawer::COLOR::RED:
		return GetColor(255, 0, 0);
	case Drwawer::COLOR::GREEN:
		return GetColor(0, 255, 0);
	case Drwawer::COLOR::BLUE:
		return GetColor(0, 0, 255);
	case Drwawer::COLOR::YELLOW:
		return GetColor(255, 255, 0);
	default:
		break;
	}
	return GetColor(0, 0, 0);
}

void Drwawer::Circle( const Vector2D& vec, COLOR type)
{	
	Circle(vec, (int)r, type);
}

void Drwawer::Circle(const Vector2D& vec, const int& radius, COLOR type)
{
	Vector2D cVec = CastWinVec(vec);
	DrawCircle(cVec.x, cVec.y, radius, Color(type));
}

void Drwawer::Circle(const Vector2D& vec, const int& radius, const unsigned int& color)
{
	Vector2D cVec = CastWinVec(vec);
	DrawCircle(cVec.x, cVec.y, radius, color);
}

void Drwawer::Line(const Vector2D& vec1, const Vector2D& vec2, COLOR type)
{
	Vector2D cVec1 = CastWinVec(vec1);
	Vector2D cVec2 = CastWinVec(vec2);
	DrawLine(cVec1.x, cVec1.y, cVec2.x, cVec2.y, Color(type));
}

void Drwawer::Line(const Vector2D& vec1, const Vector2D& vec2, const unsigned int& color)
{
	Vector2D cVec1 = CastWinVec(vec1);
	Vector2D cVec2 = CastWinVec(vec2);
	DrawLine(cVec1.x, cVec1.y, cVec2.x, cVec2.y, color);
}

void Drwawer::Pixel(const Vector2D& vec, COLOR type)
{
	Vector2D cVec = CastWinVec(vec);
	DrawPixel(cVec.x, cVec.y, Color(type));
}
