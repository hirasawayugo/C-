#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion()
{
	createQuaternion(0,0,0,1);
}

Quaternion::~Quaternion()
{
}

Quaternion Quaternion::Inverse()
{
	double num2 = x * x + y * y + z * z + w + w;
	double num = 1 / num2;
	Quaternion in;
	in.x = -x * num;
	in.y = -y * num;
	in.z = -z * num;
	in.w = w * num;
	return in;
}

Quaternion Quaternion::multiply(Quaternion& mQuat)
{
	Quaternion sq;
	sq.x = x * mQuat.w + y * mQuat.z - z * mQuat.y + w * mQuat.x;
	sq.y = -x * mQuat.z + y * mQuat.w + z * mQuat.x + w * mQuat.y;
	sq.z = x * mQuat.y - y * mQuat.x + z * mQuat.w + w * mQuat.z;
	sq.w = -x * mQuat.x - y * mQuat.y - z * mQuat.z + w * mQuat.w;
	return sq;
}

Matrix3D Quaternion::createMatrix()
{
	Matrix3D mat;
	mat.value[0][0] = 1 - 2 * y * y - 2 * z * z;
	mat.value[0][1] = 2 * x * y + 2 * w * z;
	mat.value[0][2] = 2 * x * z - 2 * w * y;
	mat.value[1][0] = 2 * x * y - 2 * w * z;
	mat.value[1][1] = 1 - 2 * x * x - 2 * z * z;
	mat.value[1][2] = 2 * y * z + 2 * w * x;
	mat.value[2][0] = 2 * x * z + 2 * w * y;
	mat.value[2][1] = 2 * y * z - 2 * w * x;
	mat.value[2][2] = 1 - 2 * x * x - 2 * y * y;
	return mat;
}

void Quaternion::createQuaternion(Matrix3D& mat)
{
	double m11 = mat.value[0][0];
	double m22 = mat.value[1][1];
	double m33 = mat.value[2][2];
	x = sqrt(m11 - m22 - m33 + 1);
	y = sqrt(-m11 + m22 - m33 + 1);
	z = sqrt(-m11 - m22 + m33 + 1);
	w = sqrt(m11 + m22 + m33 + 1);
}

void Quaternion::createQuaternion(double sx, double sy, double sz, double sw)
{
	x = sx;
	y = sy;
	z = sz;
	w = sw;
}

void Quaternion::createQuaternion(Vector3D n, double theta)
{
	x = n.x * sin(theta / 2);
	y = n.y * sin(theta / 2);
	z = n.z * sin(theta / 2);
	w = cos(theta / 2);
}
