#include "Matrix33.h"

Matrix33::Matrix33()
{
}

Matrix33::~Matrix33()
{
}

void Matrix33::setValue(float *x, float *y, float *z)
{
	value[0][0] = x[0];
	value[0][1] = x[1];
	value[0][2] = x[2];
	value[1][0] = y[0];
	value[1][1] = y[1];
	value[1][2] = y[2];
	value[2][0] = z[0];
	value[2][1] = z[1];
	value[2][2] = z[2];
}
float** Matrix33::getValue() const
{
	return (float**)value;
}
//3*3‚Ìs—ñ‚ÌŠ|ŽZ
Matrix33 Matrix33::operator*( Matrix33& other )
{
	Matrix33 mult;
	float **mn = other.getValue();
	float **np = this->getValue();
	float **multValue = new float*[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				multValue[i][j] += mn[i][k] *
			}
		}
	}
	return mult;
}
