#pragma once

class Matrix
{
public:
	Matrix();
	virtual ~Matrix();
public:
	void setValue(float** value);
	float** getValue()const;
public:
	Matrix& operator*(Matrix& other)const;
private:
	float** value;
};

