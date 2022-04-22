#include "Matrix.h"
using namespace std;

#define SIZEOF_1D (T) ( sizeof(T) / sizeof(T[0]))
#define SIZEOF_2D (T) ( sizeof(T[0]) / sizeof(T[0][0]))

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

int**Matrix::mult22(int mn[2][2], int np[2][2])
{
	int **value = new int*[2];
	for (int i = 0; i < 2; i++) {
		value[i] = new int[2];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = 0;
			for (int k = 0; k < 2; k++) {
				sum += mn[i][k] * np[k][j];
			}
			value[i][j] = sum;
		}
	}
    return value;
}

int** Matrix::mult33(int mn[3][3], int np[3][3])
{
	int** value = new int* [3];
	for (int i = 0; i < 3; i++) {
		value[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += mn[i][k] * np[k][j];
			}
			value[i][j] = sum;
		}
	}
	return value;
}

int** Matrix::mult44(int mn[4][4], int np[4][4])
{
	int** value = new int* [4];
	for (int i = 0; i < 4; i++) {
		value[i] = new int[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += mn[i][k] * np[k][j];
			}
			value[i][j] = sum;
		}
	}
	return value;
}

int** Matrix::mult(int mn[3][2], int np[2][4])
{
	int** value = new int* [3];
	for (int i = 0; i < 4; i++) {
		value[i] = new int[4];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			int sum = 0;
			for (int k = 0; k < 2; k++) {
				sum += mn[i][k] * np[k][j];
			}
			value[i][j] = sum;
		}
	}
	return value;
}
