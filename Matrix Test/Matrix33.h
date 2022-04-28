#pragma once
#include"Vector2D.h"

class Matrix33
{
public:
	static const int SIZE = 3;
public:
	Matrix33();
	Matrix33(float* x, float* y, float* z);
	virtual ~Matrix33( );
public:
	void setValue(float* x, float* y, float* z);
	float (*getValue() ) [SIZE];
public:
	void rotate( double angle  );
	Matrix33& mult( Matrix33& other)const;
	Matrix33& operator*( Matrix33& other)const;
	void mult(Vector2D& vec);
	void operator*(Vector2D& vec);
private:
	float value[SIZE][SIZE];
};

