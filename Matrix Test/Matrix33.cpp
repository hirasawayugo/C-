#include "Matrix33.h"

Matrix33::Matrix33()
{
}

Matrix33::~Matrix33()
{
}

void Matrix33::setValue(float x[3], float y[3], float z[3])
{
	value[0][0] = *x;
	value[1][0] = *y;
	value[2][0] = *z;
}
float** Matrix33::getValue() const
{
	return (float**)value;
}
//3*3‚Ìs—ñ‚ÌŠ|ŽZ
Matrix33 Matrix33::operator*( Matrix33& other )
{
	Matrix33* mult = new Matrix33;
	other->getVa
	this->value;
	for (int i = 0; i < 3; i++) {

	}
	return mult;
}
