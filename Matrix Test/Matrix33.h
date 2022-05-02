#pragma once
struct Vector2D;

class Matrix33
{
public:
	static const int SIZE = 3;
public:
	Matrix33();
	Matrix33(float v00,float v01,float v02,float v10,float v11,float v12,float v20,float v21,float v22);
	Matrix33(float* x, float* y, float* z);
	virtual ~Matrix33( );
public:
	void SetValue(float* x, float* y, float* z);
	float (*GetValue() ) [SIZE];
public:
	Matrix33 Rotate( double angle  );
	Matrix33& Multiply( Matrix33& other)const;
	Matrix33& operator*( Matrix33& other)const;
public:
	float value[SIZE][SIZE];
};

