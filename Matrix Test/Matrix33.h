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
	Matrix33 operator*( Matrix33& );
private:
	float value[3][3];
};

