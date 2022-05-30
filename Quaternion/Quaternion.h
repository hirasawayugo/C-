#pragma once
#include "Matrix3D.h"

class Quaternion
{
public:
	Quaternion();
	virtual ~Quaternion();
public:
	Quaternion Inverse();
	Quaternion multiply(Quaternion& mQuat);
	Matrix3D createMatrix();
	void createQuaternion(Matrix3D& mat);
	void createQuaternion(double sx, double sy, double sz, double sw);
	void createQuaternion(Vector3D n, double theta);
public:
	double x;
	double y;
	double z;
	double w;
};

