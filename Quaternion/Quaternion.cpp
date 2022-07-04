#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion()
{
	createQuaternion(0,0,0,1);
}

Quaternion::~Quaternion()
{
}

double Quaternion::Normalize()
{
	double n = x * x + y * y + z * z + w + w;
	return n;
}

double Quaternion::Normalize(Quaternion& quat)
{
	double n = x * quat.x + y * quat.y + z * quat.z + w + quat.w;
	return n;
}

Quaternion Quaternion::Inverse()
{
	double num2 = Normalize();
	double num = 1 / num2;
	Quaternion in;
	in.x = -x * num;
	in.y = -y * num;
	in.z = -z * num;
	in.w = w * num;
	return in;
}

Quaternion Quaternion::multiply(Quaternion& quat)
{
	Quaternion sq;
	sq.x = x * quat.w + y * quat.z - z * quat.y + w * quat.x;
	sq.y = -x * quat.z + y * quat.w + z * quat.x + w * quat.y;
	sq.z = x * quat.y - y * quat.x + z * quat.w + w * quat.z;
	sq.w = -x * quat.x - y * quat.y - z * quat.z + w * quat.w;
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

Quaternion Quaternion::Slerp(Quaternion& quat, double blend)
{
	Quaternion lQuat;
	double t = blend;
	double theta = acos(Dot(quat));
	double sTheta = sin(theta);
	double num1 = sin((1.0 - t) * theta) / sTheta;
	double num2 = sin(t * theta) / sTheta;
	lQuat.x = x * num1 + quat.x * num2;
	lQuat.y = y * num1 + quat.y * num2;
	lQuat.z = z * num1 + quat.z * num2;
	lQuat.w = w * num1 + quat.w * num2;
	return lQuat;
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

double Quaternion::Dot(Quaternion& quat)
{
	double a = x * quat.x;
	double b = y * quat.y;
	double c = z * quat.z;
	double d = w * quat.w;
	double cTheta = a + b + c + d;
	return cTheta;
}
