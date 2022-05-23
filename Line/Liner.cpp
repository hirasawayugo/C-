#include "Liner.h"
#include "Drawer.h"

Liner::Liner()
{
}

Liner::~Liner()
{
}

void Liner::Execution( const Vector3D& pos1, const Vector3D& pos2, TYPE type)
{
	Drwawer draw;
	draw.Sphere(pos1, 3, Drwawer::COLOR::YELLOW);
	draw.Sphere(pos2, 3, Drwawer::COLOR::YELLOW);
	Vector3D pos_1 = pos1;
	Vector3D pos_2 = pos2;
	Vector3D vec = pos_2 - pos_1;
	switch (type)
	{
	case Liner::TYPE::STRAIGHT:
		for (double i = 0; i < 10; i += 0.001) {
			Vector3D L = vec * -i;
			Vector3D R = vec * i;
			Vector3D halfPos = (pos_1 + pos_2) * 0.5;
			L.Add(halfPos);
			R.Add(halfPos);
			draw.Pixel(L, Drwawer::COLOR::WHITE);
			draw.Pixel(R, Drwawer::COLOR::WHITE);
		}
		break;
	case Liner::TYPE::HALF:
		for (double i = 0; i < 10; i += 0.001) {
			Vector3D lVec = vec * i;
			lVec.Add(pos_1);
			draw.Pixel(lVec, Drwawer::COLOR::WHITE);
		}
		break;
	case Liner::TYPE::SEGMENT:
		for (double i = 0; i <= 1; i += 0.001) {
			Vector3D lVec = vec * i;
			lVec.Add(pos_1);
			draw.Pixel(lVec, Drwawer::COLOR::WHITE);
		}
		break;
	default:
		break;
	}
	return;
}
