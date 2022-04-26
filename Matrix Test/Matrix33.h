#pragma once

constexpr int SIZE = 3;

class Matrix33
{
public:
	Matrix33( );
	virtual ~Matrix33( );
public:
	void setValue( float *x, float *y, float *z );
	float (*getValue() ) [SIZE];
public:
	Matrix33& operator*( Matrix33& other)const;
private:
	float value[SIZE][SIZE];
};

