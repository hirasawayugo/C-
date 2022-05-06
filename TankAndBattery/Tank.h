#pragma once
#include "Vector2D.h"
#include "Matrix33.h"
#include "Battery.h"

class Tank
{
public:
	Tank();
	virtual ~Tank();
public:
	void SetPos( const Vector2D& sPos );
	void SetPos( const Matrix33& mat );
	void Rotate(const double& radian);
	void BatRotate(const double& radian);
	Vector2D GetPos() const;
	double GetAngle() const;

	void debuglog();
private:
	void SetSidePos();
	void SetSideRoate( Matrix33& mat);
private:
	Vector2D pos;
	Vector2D frontLeft;
	Vector2D frontRight;
	Vector2D backLeft;
	Vector2D backRight;
	
	double angle;
	Battery battery;
private:
	const double WIDTH = 2.0;
	const double LENGHT = 3.0;
	const double RIGHT = WIDTH / 2;
	const double LEFT = -WIDTH / 2;
	const double FRONT = LENGHT / 2;
	const double BACK = -LENGHT / 2;
};

