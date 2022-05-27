#pragma once
#include "Matrix3D.h"

class Quaternion
{
public:
	Quaternion();
	virtual ~Quaternion();
public:
	Quaternion Inverse();
	Quaternion multiply(Quaternion& mQuat, double& theta);
	Matrix3D createMatrix();
	void createQuaternion(Matrix3D& mat);
	void createQuaternion(double sx, double sy, double sz, double sw);
public:
	double x;
	double y;
	double z;
	double w;
};

