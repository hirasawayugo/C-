#pragma once

class Matrix44
{
private:
	static const int SIZE = 4;
public:
	Matrix44();
	virtual ~Matrix44();
public:
	void setValue(float* x, float* y, float* z, float* w );
	float(*getValue())[SIZE];
public:
	Matrix44& operator*(Matrix44& other)const;
private:
	float value[SIZE][SIZE];
};

