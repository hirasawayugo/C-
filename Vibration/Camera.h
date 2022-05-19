#pragma once
#include "DxLib.h"
#include "Vector2D.h"
#include "Matrix33.h"

class Camera
{
public:
	Camera();
	virtual ~Camera();
public:
	void Foward( const Vector2D& vec);
	void Foward( const double& x, const double& y );
	void Rotate( const double& radian );
	Vector2D GetPos() const;
	double GetAngle() const ;
	//dir�Fx����y����(2D)�@x:x����(������)�@y:y����(������) blend:1 = 1����
	void Vibration(double x, double y, double blend);
private:
	Vector2D lPos;
	Vector2D vVec;
	double angle;
};

