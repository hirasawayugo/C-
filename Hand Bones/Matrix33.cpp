#include "Matrix33.h"
#include <math.h>

Matrix33::Matrix33()
{
	Initialize();
}

Matrix33::Matrix33(float v00, float v01, float v02, float v10, float v11, float v12, float v20, float v21, float v22)
{
	value[0][0] = v00;
	value[0][1] = v01;
	value[0][2] = v02;
	value[1][0] = v10;
	value[1][1] = v11;
	value[1][2] = v00;
	value[2][0] = v20;
	value[2][1] = v21;
	value[2][2] = v22;
}

Matrix33::Matrix33(float* x, float* y, float* z)
{
	SetValue(x, y, z);
}

Matrix33::~Matrix33()
{
}

void Matrix33::Initialize()
{
	value[0][0] = 1;
	value[0][1] = 0;
	value[0][2] = 0;
	value[1][0] = 0;
	value[1][1] = 1;
	value[1][2] = 0;
	value[2][0] = 0;
	value[2][1] = 0;
	value[2][2] = 1;
}

void Matrix33::SetValue(float* x, float* y, float* z)
{
	for (int i = 0; i < SIZE; i++) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
	}
}
float(*Matrix33::GetValue() )[SIZE]
{
	return value;
}

void Matrix33::Rotate(double angle)
{
	//?񎟌??̂???Z?????]?Œ?
	value[0][0] = cos(angle);
	value[0][1] = -sin(angle);
	value[1][0] = sin(angle);
	value[1][1] = cos(angle);
}

void Matrix33::Move(const Vector2D& vec)
{
	value[2][1] += vec.x;
	value[2][1] += vec.y;
}

Matrix33& Matrix33::Multiply(Matrix33& other) const
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
	Matrix33* mult = new Matrix33();
	mult->SetValue(multValue[0], multValue[1], multValue[2]);
	return *mult;
}
//3*3?̍s???̊|?Z
Matrix33& Matrix33::operator*( Matrix33& other ) const
{
	return(Multiply(other));
}

Vector2D& Matrix33::Transform(const Vector2D& vec)const
{
	Vector2D multVec(0,0);
	multVec.x = vec.x * value[0][0] + vec.y * value[1][0] + value[2][0];
	multVec.y = vec.x * value[0][1] + vec.y * value[1][1] + value[2][1];
	return multVec;
}

Vector2D& Matrix33::operator*(const Vector2D& vec)const
{
	return Transform(vec);
}