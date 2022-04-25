#include "Matrix33.h"

Matrix33::Matrix33()
{
	value[0][0] = 0;
	value[0][1] = 0;
	value[0][2] = 0;
	value[1][0] = 0;
	value[1][1] = 0;
	value[1][2] = 0;
	value[2][0] = 0;
	value[2][1] = 0;
	value[2][2] = 0;
}

Matrix33::~Matrix33()
{
}

void Matrix33::setValue(float *x, float *y, float *z)
{
	for (int i = 0; i < 3;i++ ) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
	}
}
float** Matrix33::getValue() const
{
	return (float**)value;
}
//3*3‚Ìs—ñ‚ÌŠ|ŽZ
Matrix33& Matrix33::operator*( const Matrix33& other ) const
{
	Matrix33* mult = new Matrix33();
	float **mn = other.getValue();
	float **np = this->getValue();
	float **multValue = new float*[3];
	for (int i = 0; i < 3; i++) {
		multValue[i] = new float[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += mn[i][k] * np[k][i];
			}
			multValue[i][j] = sum;
		}
	}
	mult->setValue(multValue[0], multValue[1], multValue[2]);
	return *mult;
}
