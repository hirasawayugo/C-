#pragma once
#include "Matrix3D.h"
#include "Vector3D.h"
#include <vector>

using namespace std;

class Camera
{
public:
	Camera();
	virtual ~Camera();
public:
	void Transform(Matrix3D mat);
	Vector3D GetPos();
	vector<Vector3D> GetPlate();
	void AddViewAngle(double radian);
private:
	Vector3D pos;
	double angle;
	double viewAngle;
	double backLen;
	double frontLen;
	double backWidth;
	double frontWidth;
	vector<Vector3D> plate;
};

