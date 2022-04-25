#include "Matrix.h"
using namespace std;

#define MN_SIZEOF(T) (sizeof(T) / sizeof(T[0]));

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::setValue(float** s_value, int row)
{
	const int mnSize = MN_SIZEOF(s_value);

	value = new float*[mnSize];
	
	for (int i = 0; i < mnSize; i++) {
		value[i] = new float[row];
		for (int j = 0; j < row; j++)
		{
			value[i][j] = s_value[i][j];
		}
	}
}
