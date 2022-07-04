#pragma once
#include "Matrix3D.h"

class Quaternion
{
public:
	Quaternion();
	virtual ~Quaternion();
public:
	double Normalize();
	double Normalize( Quaternion& quat);
	Quaternion Inverse();
	Quaternion multiply(Quaternion& quat);
	Matrix3D createMatrix();
	Quaternion Slerp(Quaternion& quat, double blend);
	void createQuaternion(Matrix3D& mat);
	void createQuaternion(double sx, double sy, double sz, double sw);
	void createQuaternion(Vector3D n, double theta);
	double Dot(Quaternion& quat);
public:
	double x;
	double y;
	double z;
	double w;
};

