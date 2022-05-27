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

void Drwawer::Sphere(const Vector3D& vec, COLOR type)
{
	unsigned int color = Color(type);
	DrawSphere3D(VGet(vec.x,vec.y,vec.z), r, 100, color, color, true);
}

void Drwawer::Sphere(const Vector3D& vec,const unsigned int& color)
{
	DrawSphere3D(VGet(vec.x, vec.y, vec.z), r, 100, color,color, true );
}

void Drwawer::Plate(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3, const Vector3D& vec4, COLOR type)
{
	unsigned int color = Color(type);
	DrawTriangle3D(VGet(vec1.x, vec1.y, vec1.z),
		VGet(vec2.x, vec2.y, vec2.z),
		VGet(vec4.x, vec4.y, vec4.z),
		color, false);
	DrawTriangle3D(VGet(vec3.x, vec3.y, vec3.z),
		VGet(vec4.x, vec4.y, vec4.z),
		VGet(vec2.x, vec2.y, vec2.z),
		color, false);
}

void Drwawer::Plate(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3, const Vector3D& vec4, const unsigned int& color)
{
	DrawTriangle3D(VGet(vec1.x, vec1.y, vec1.z),
		VGet(vec2.x, vec2.y, vec2.z),
		VGet(vec4.x, vec4.y, vec4.z),
		color, false);
	DrawTriangle3D(VGet(vec3.x, vec3.y, vec3.z),
		VGet(vec4.x, vec4.y, vec4.z),
		VGet(vec2.x, vec2.y, vec2.z),
		color, false);
}

void Drwawer::Line(const Vector3D& vec1, const Vector3D& vec2, const unsigned int& color)
{
	DrawLine3D(VGet(vec1.x, vec1.y, vec1.z), VGet(vec2.x, vec2.y, vec2.z), color);
}
