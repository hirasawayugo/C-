#pragma once
class Matrix33
{
public:
	Matrix33( );
	virtual ~Matrix33( );
public:
	void setValue( float *x, float *y, float *z );
	float **getValue()const;
public:
	const Matrix33 operator*(const Matrix33& other)const;
private:
	float value[3][3];
};

