#include "Camera.h"
#include "Calculator.h"

Camera::Camera()
{
	pos = Vector3D(0, 0, 0);
	Calculator calc;
	viewAngle = calc.Radians(30);
	backLen = 300.0;
	frontLen = backLen / 4;
	backWidth = 200;
	frontWidth = backWidth / 4;

	//ÉJÉÅÉâîÕàÕê›íË
	Matrix3D lmat;
	lmat.Rotate(viewAngle, Matrix3D::AXIS::Y);
	Matrix3D rmat;
	rmat.Rotate(-viewAngle, Matrix3D::AXIS::Y);
	Vector3D topBackLeft      = lmat * Vector3D(0, backWidth / 2, backLen);
	Vector3D topFrontLeft     = lmat * Vector3D(0, frontWidth / 2, frontLen);
	Vector3D topBackRight     = rmat * Vector3D(0, backWidth / 2, backLen);
	Vector3D topFrontRight    = rmat * Vector3D(0, frontWidth / 2, frontLen);
	Vector3D bottomBackRight  = rmat * Vector3D(0, -backWidth / 2, backLen);
	Vector3D bottomFrontRight = rmat * Vector3D(0, -frontWidth / 2, frontLen);
	Vector3D bottomBackLeft   = lmat * Vector3D(0, -backWidth / 2, backLen);
	Vector3D bottomFrontLeft  = lmat * Vector3D(0, -frontWidth / 2, frontLen);
	plate.push_back(topBackLeft);
	plate.push_back(topFrontLeft);
	plate.push_back(topBackRight);
	plate.push_back(topFrontRight);
	plate.push_back(bottomBackRight);
	plate.push_back(bottomFrontRight);
	plate.push_back(bottomBackLeft);
	plate.push_back(bottomFrontLeft);
	for (int i = 0; i < 8; i++) {
		plate[i].Add(pos);
	}
}

Camera::~Camera()
{
}

void Camera::Transform(Matrix3D addMat)
{
	mat = mat * addMat;
	pos = mat * Vector3D(0,0,0);
	for (int i = 0; i < 8; i++) {
		plate[i] = addMat * plate[i];
	}
}

Vector3D Camera::GetPos()
{
	return pos;
}

vector<Vector3D> Camera::GetPlate()
{
	return plate;
}

void Camera::AddViewAngle(double radian)
{
	viewAngle += radian;
	Matrix3D lmat;
	lmat.Rotate(viewAngle, Matrix3D::AXIS::Y);
	Matrix3D rmat;
	rmat.Rotate(-viewAngle, Matrix3D::AXIS::Y);
	Vector3D topBackLeft = mat * lmat * Vector3D(0, backWidth / 2, backLen);
	Vector3D topFrontLeft = mat * lmat * Vector3D(0, frontWidth / 2, frontLen);
	Vector3D topBackRight = mat * rmat * Vector3D(0, backWidth / 2, backLen);
	Vector3D topFrontRight = mat * rmat * Vector3D(0, frontWidth / 2, frontLen);
	Vector3D bottomBackRight = mat * rmat * Vector3D(0, -backWidth / 2, backLen);
	Vector3D bottomFrontRight = mat * rmat * Vector3D(0, -frontWidth / 2, frontLen);
	Vector3D bottomBackLeft = mat * lmat * Vector3D(0, -backWidth / 2, backLen);
	Vector3D bottomFrontLeft = mat * lmat * Vector3D(0, -frontWidth / 2, frontLen);
	plate[0] = topBackLeft;
	plate[1] = topFrontLeft;
	plate[2] = topBackRight;
	plate[3] = topFrontRight;
	plate[4] = bottomBackRight;
	plate[5] = bottomFrontRight;
	plate[6] = bottomBackLeft;
	plate[7] = bottomFrontLeft;
	for (int i = 0; i < 8; i++) {
		plate[i].Add(pos);
	}
}

Matrix3D Camera::GetViewMatrix()
{
	return mat.Inverse();
}
