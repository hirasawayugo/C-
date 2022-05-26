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

Matrix3D Matrix3D::Inverse() const
{
	Matrix3D mat;
	
	float num1 = value[0][0];
	float num2 = value[0][1];
	float num3 = value[0][2];
	float num4 = value[0][3];
	float num5 = value[1][0];
	float num6 = value[1][1];
	float num7 = value[1][2];
	float num8 = value[1][3];
	float num9 = value[2][0];
	float num10 = value[2][1];
	float num11 = value[2][2];
	float num12 = value[2][3];
	float num13 = value[3][0];
	float num14 = value[3][1];
	float num15 = value[3][2];
	float num16 = value[3][3];
	float num17 = (float)((double)num11 * (double)num16 - (double)num12 * (double)num15);
	float num18 = (float)((double)num10 * (double)num16 - (double)num12 * (double)num14);
	float num19 = (float)((double)num10 * (double)num15 - (double)num11 * (double)num14);
	float num20 = (float)((double)num9 * (double)num16 - (double)num12 * (double)num13);
	float num21 = (float)((double)num9 * (double)num15 - (double)num11 * (double)num13);
	float num22 = (float)((double)num9 * (double)num14 - (double)num10 * (double)num13);
	float num23 = (float)((double)num6 * (double)num17 - (double)num7 * (double)num18 + (double)num8 * (double)num19);
	float num24 = (float)-((double)num5 * (double)num17 - (double)num7 * (double)num20 + (double)num8 * (double)num21);
	float num25 = (float)((double)num5 * (double)num18 - (double)num6 * (double)num20 + (double)num8 * (double)num22);
	float num26 = (float)-((double)num5 * (double)num19 - (double)num6 * (double)num21 + (double)num7 * (double)num22);
	float num27 = (float)(1.0 / ((double)num1 * (double)num23 + (double)num2 * (double)num24 + (double)num3 * (double)num25 + (double)num4 * (double)num26));

	mat.value[0][0] = num23 * num27;
	mat.value[1][0] = num24 * num27;
	mat.value[2][0] = num25 * num27;
	mat.value[3][0] = num26 * num27;
	mat.value[0][1] = (float)-((double)num2 * (double)num17 - (double)num3 * (double)num18 + (double)num4 * (double)num19) * num27;
	mat.value[1][1] = (float)((double)num1 * (double)num17 - (double)num3 * (double)num20 + (double)num4 * (double)num21) * num27;
	mat.value[2][1] = (float)-((double)num1 * (double)num18 - (double)num2 * (double)num20 + (double)num4 * (double)num22) * num27;
	mat.value[3][1] = (float)((double)num1 * (double)num19 - (double)num2 * (double)num21 + (double)num3 * (double)num22) * num27;
	float num28 = (float)((double)num7 * (double)num16 - (double)num8 * (double)num15);
	float num29 = (float)((double)num6 * (double)num16 - (double)num8 * (double)num14);
	float num30 = (float)((double)num6 * (double)num15 - (double)num7 * (double)num14);
	float num31 = (float)((double)num5 * (double)num16 - (double)num8 * (double)num13);
	float num32 = (float)((double)num5 * (double)num15 - (double)num7 * (double)num13);
	float num33 = (float)((double)num5 * (double)num14 - (double)num6 * (double)num13);
	mat.value[0][2] = (float)((double)num2 * (double)num28 - (double)num3 * (double)num29 + (double)num4 * (double)num30) * num27;
	mat.value[1][2] = (float)-((double)num1 * (double)num28 - (double)num3 * (double)num31 + (double)num4 * (double)num32) * num27;
	mat.value[2][2] = (float)((double)num1 * (double)num29 - (double)num2 * (double)num31 + (double)num4 * (double)num33) * num27;
	mat.value[3][2] = (float)-((double)num1 * (double)num30 - (double)num2 * (double)num32 + (double)num3 * (double)num33) * num27;
	float num34 = (float)((double)num7 * (double)num12 - (double)num8 * (double)num11);
	float num35 = (float)((double)num6 * (double)num12 - (double)num8 * (double)num10);
	float num36 = (float)((double)num6 * (double)num11 - (double)num7 * (double)num10);
	float num37 = (float)((double)num5 * (double)num12 - (double)num8 * (double)num9);
	float num38 = (float)((double)num5 * (double)num11 - (double)num7 * (double)num9);
	float num39 = (float)((double)num5 * (double)num10 - (double)num6 * (double)num9);
	mat.value[0][3] = (float)-((double)num2 * (double)num34 - (double)num3 * (double)num35 + (double)num4 * (double)num36) * num27;
	mat.value[1][3] = (float)((double)num1 * (double)num34 - (double)num3 * (double)num37 + (double)num4 * (double)num38) * num27;
	mat.value[2][3] = (float)-((double)num1 * (double)num35 - (double)num2 * (double)num37 + (double)num4 * (double)num39) * num27;
	mat.value[3][3] = (float)((double)num1 * (double)num36 - (double)num2 * (double)num38 + (double)num3 * (double)num39) * num27;

	return mat;
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