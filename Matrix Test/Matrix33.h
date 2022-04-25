#pragma once
class Matrix33
{
public:
	Matrix33( );
	virtual ~Matrix33( );
public:
	void setValue( float x[3], float y[3], float z[3] );
private:
	float value[3][3];
};

