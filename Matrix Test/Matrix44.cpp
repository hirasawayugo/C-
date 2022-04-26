#include "Matrix44.h"

Matrix44::Matrix44()
{
}

Matrix44::~Matrix44()
{
}

void Matrix44::setValue(float* x, float* y, float* z, float* w)
{
	for (int i = 0; i < SIZE; i++) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
		value[3][i] = w[i];
	}
}

float(*Matrix44::getValue())[SIZE]
{
	return value;
}

Matrix44& Matrix44::operator*(Matrix44& other) const
{
	Matrix44* mult = new Matrix44();
	float(*oValue)[SIZE] = other.getValue();
	float multValue[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int sum = 0;
			for (int k = 0; k < SIZE; k++) {
				sum += value[i][k] * oValue[k][j];
			}
			multValue[i][j] = sum;
		}
	}
	mult->setValue(multValue[0], multValue[1], multValue[2], multValue[3]);
	return *mult;
}
