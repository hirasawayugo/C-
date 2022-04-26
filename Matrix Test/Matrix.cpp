#include "Matrix.h"
using namespace std;

#define MN_SIZEOF(T) (sizeof(T) / sizeof(T[0]));
#define NP_SIZEOF(T) (sizeof(T[0]) / sizeof(T[0][0]));

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::setValue(float** s_value)
{
	const int mnSize = MN_SIZEOF(s_value);
	const int npSize = NP_SIZEOF(s_value);

	value = new float*[mnSize];
	
	for (int i = 0; i < mnSize; i++) {
		value[i] = new float [npSize];
		for (int j = 0; j < npSize; j++)
		{
			value[i][j] = s_value[i][j];
		}
	}
}
