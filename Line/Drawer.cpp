#include "Drawer.h"

Drwawer::Drwawer()
{
	SetGraphMode(WIN_WIDTH + r * 2, WIN_HEIGHT + r * 2, 0);
	SetWindowSize(WIN_WIDTH + r * 2, WIN_HEIGHT + r * 2);
}

Drwawer::~Drwawer()
{
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

void Drwawer::Line(const Vector3D& vec1, const Vector3D& vec2, COLOR type)
{
	unsigned int color = Color(type);
	DrawLine3D(VGet(vec1.x, vec1.y, vec1.z),VGet(vec2.x, vec2.y, vec2.z), color);
}

void Drwawer::Line(const Vector3D& vec1, const Vector3D& vec2, const unsigned int& color)
{
	DrawLine3D(VGet(vec1.x, vec1.y, vec1.z), VGet(vec2.x, vec2.y, vec2.z), color);
}

void Drwawer::Sphere(const Vector3D& vec, COLOR type)
{
	unsigned int color = Color(type);
	DrawSphere3D(VGet(vec.x,vec.y,vec.z), r, 100, color, color, true);
}

void Drwawer::Sphere(const Vector3D& vec, double range, COLOR type)
{
	unsigned int color = Color(type);
	DrawSphere3D(VGet(vec.x, vec.y, vec.z), range, 100, color, color, true);
}

void Drwawer::Sphere(const Vector3D& vec,const unsigned int& color)
{
	DrawSphere3D(VGet(vec.x, vec.y, vec.z), r, 100, color,color, true );
}

void Drwawer::Plate(const vector<Vector3D> vec, COLOR type)
{
	unsigned int color = Color(type);
	DrawTriangle3D(VGet(vec[0].x, vec[0].y, vec[0].z),
		VGet(vec[1].x, vec[1].y, vec[1].z),
		VGet(vec[3].x, vec[3].y, vec[3].z),
		color, false);
	DrawTriangle3D(VGet(vec[2].x, vec[2].y, vec[2].z),
		VGet(vec[3].x, vec[3].y, vec[3].z),
		VGet(vec[1].x, vec[1].y, vec[1].z),
		color, false);
}

void Drwawer::Plate(const vector<Vector3D> vec, const unsigned int& color)
{
	DrawTriangle3D(VGet(vec[0].x, vec[0].y, vec[0].z),
					VGet(vec[1].x, vec[1].y, vec[1].z),
					VGet(vec[2].x, vec[2].y, vec[2].z),
					color, true);
	DrawTriangle3D(VGet(vec[4].x, vec[4].y, vec[4].z),
					VGet(vec[2].x, vec[2].y, vec[2].z),
					VGet(vec[1].x, vec[1].y, vec[1].z),
					color, true);
}

void Drwawer::Pixel(const Vector3D& vec, COLOR type)
{
	unsigned int color = Color(type);
	DrawPixel3D(VGet(vec.x,vec.y,vec.z), color);
}
