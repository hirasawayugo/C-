#include "Matrix33.h"
#include <math.h>

Matrix33::Matrix33()
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

Matrix33::Matrix33(float* x, float* y, float* z)
{
	for (int i = 0; i < SIZE; i++) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
	}
}

Matrix33::~Matrix33()
{
}

void Matrix33::setValue(float* x, float* y, float* z)
{
	for (int i = 0; i < SIZE; i++) {
		value[0][i] = x[i];
		value[1][i] = y[i];
		value[2][i] = z[i];
	}
}
float(*Matrix33::getValue() )[SIZE]
{
	return value;
}

void Matrix33::rotate(double angle)
{
	//ìÒéüå≥ÇÃÇΩÇﬂZé≤âÒì]å≈íË
	value[0][0] = cos(angle);
	value[0][1] = -sin(angle);
	value[1][0] = sin(angle);
	value[1][1] = cos(angle);

}

Matrix33& Matrix33::mult(Matrix33& other) const
{
	float(*oValue)[SIZE] = other.getValue();
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
	mult->setValue(multValue[0], multValue[1], multValue[2]);
	return *mult;
}
//3*3ÇÃçsóÒÇÃä|éZ
Matrix33& Matrix33::operator*( Matrix33& other ) const
{
	return(mult(other));
}

void Matrix33::mult( Vector2D& vec)
{
	Vector2D multVec = vec;
	vec.x = multVec.x * value[0][0] + multVec.y * value[0][1];
	vec.y = multVec.x * value[1][0] + multVec.y * value[1][1];

}

void Matrix33::operator*(Vector2D& vec)
{
	mult(vec);
}
