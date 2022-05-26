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
	Matrix3D GetViewMatrix();
private:
	Vector3D pos;
	Matrix3D mat;
	double viewAngle;
	double backLen;
	double frontLen;
	double backWidth;
	double frontWidth;
	vector<Vector3D> plate;
};

