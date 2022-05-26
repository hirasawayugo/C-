#pragma once
#include "Vector3D.h"

class Matrix3D
{
public:
	static const int SIZE = 4;
public:
	enum class AXIS {
		X,
		Y,
		Z,
	};
public:
	Matrix3D();
	Matrix3D(float v00,float v01,float v02,float v03,
			 float v10,float v11,float v12,float v13,
			 float v20,float v21,float v22,float v23,
			 float v30,float v31,float v32,float v33);
	Matrix3D(float* row1, float* row2, float* row3, float* row4);
	virtual ~Matrix3D( );
public:
	void Initialize();
	void SetValue(float* row1, float* row2, float* row3, float* row4);
	float (*GetValue() ) [SIZE];
	Matrix3D Inverse()const;
public:
	void Rotate( double angle, AXIS axis );
	void Move( const Vector3D& vec );
	Matrix3D& Multiply(Matrix3D& other)const;
	Matrix3D& operator*(Matrix3D& other)const;
	Vector3D& Transform(const Vector3D& vec) const;
	Vector3D& operator*(const Vector3D& vec) const;
public:
	float value[SIZE][SIZE];
};

