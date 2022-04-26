#include "Matrix33.h"

Matrix33::Matrix33()
{
}

Matrix33::~Matrix33()
{
}

void Matrix33::setValue(float *x, float *y, float *z)
{
	for (int i = 0; i < SIZE;i++ ) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
	}
}
float(*Matrix33::getValue() )[SIZE]
{
	return value;
}
//3*3‚Ìs—ñ‚ÌŠ|ŽZ
Matrix33& Matrix33::operator*( Matrix33& other ) const
{
	Matrix33* mult = new Matrix33();
	float (*oValue)[SIZE] = other.getValue();
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
	mult->setValue(multValue[0], multValue[1], multValue[2]);
	return *mult;
}
