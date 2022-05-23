#include "Matrix3D.h"
#include <math.h>

Matrix3D::Matrix3D()
{
	Initialize();
}

Matrix3D::Matrix3D(float v00, float v01, float v02,float v03, float v10, float v11, float v12, float v13,
					float v20, float v21, float v22, float v23, float v30, float v31, float v32, float v33)
{
	value[0][0] = v00;
	value[0][1] = v01;
	value[0][2] = v02;
	value[0][3] = v03;
	value[1][0] = v10;
	value[1][1] = v11;
	value[1][2] = v12;
	value[1][3] = v13;
	value[2][0] = v20;
	value[2][1] = v21;
	value[2][2] = v22;
	value[2][3] = v23;
	value[3][0] = v30;
	value[3][1] = v31;
	value[3][2] = v32;
	value[3][3] = v33;
}

Matrix3D::Matrix3D(float* row1, float* row2, float* row3, float* row4)
{
	SetValue(row1, row2, row3, row4);
}

Matrix3D::~Matrix3D()
{
}

void Matrix3D::Initialize()
{
	value[0][0] = 1;
	value[0][1] = 0;
	value[0][2] = 0;
	value[0][3] = 0;
	value[1][0] = 0;
	value[1][1] = 1;
	value[1][2] = 0;
	value[1][3] = 0;
	value[2][0] = 0;
	value[2][1] = 0;
	value[2][2] = 1;
	value[2][3] = 0;
	value[3][0] = 0;
	value[3][1] = 0;
	value[3][2] = 0;
	value[3][3] = 1;
}

void Matrix3D::SetValue(float* row1, float* row2, float* row3, float* row4)
{
	for (int i = 0; i < SIZE; i++) {
		value[0][i] = row1[i];
		value[1][i] = row2[i];
		value[2][i] = row3[i];
		value[3][i] = row4[i];
	}
}
float(*Matrix3D::GetValue() )[SIZE]
{
	return value;
}

void Matrix3D::Rotate(double angle, AXIS axis)
{
	float cosV = cos(angle);
	float sinV = sin(angle);
	switch (axis)
	{
	case Matrix3D::AXIS::X:
		value[1][1] = cosV;
		value[1][2] = sinV;
		value[2][1] = -sinV;
		value[2][2] = cosV;
		break;
	case Matrix3D::AXIS::Y:
		value[0][0] = cosV;
		value[0][2] = -sinV;
		value[2][0] = sinV;
		value[2][2] = cosV;
		break;
	case Matrix3D::AXIS::Z:
		value[0][0] = cosV;
		value[0][1] = sinV;
		value[1][0] = -sinV;
		value[1][1] = cosV;
		break;
	}
}

void Matrix3D::Move(const Vector3D& vec)
{
	value[0][3] += vec.x;
	value[1][3] += vec.y;
	value[2][3] += vec.z;
}

Matrix3D& Matrix3D::Multiply(Matrix3D& other) const
{
	float(*oValue)[SIZE] = other.GetValue();
	float multValue[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			float sum = 0;
			for (int k = 0; k < SIZE; k++) {
				sum += value[i][k] * oValue[k][j];
			}
			multValue[i][j] = sum;
		}
	}
	Matrix3D* mult = new Matrix3D();
	mult->SetValue(multValue[0], multValue[1], multValue[2], multValue[3]);
	return *mult;
}
//3*3ÇÃçsóÒÇÃä|éZ
Matrix3D& Matrix3D::operator*(Matrix3D& other ) const
{
	return(Multiply(other));
}

Vector3D& Matrix3D::Transform(const Vector3D& vec)const
{
	Vector3D multVec(0,0,0);
	multVec.x = vec.x * value[0][0] + vec.y * value[0][1] + vec.z * value[0][2] + value[0][3];
	multVec.y = vec.x * value[1][0] + vec.y * value[1][1] + vec.z * value[1][2] + value[1][3];
	multVec.z = vec.x * value[2][0] + vec.y * value[2][1] + vec.z * value[2][2] + value[2][3];
	return multVec;
}

Vector3D& Matrix3D::operator*(const Vector3D& vec)const
{
	return Transform(vec);
}