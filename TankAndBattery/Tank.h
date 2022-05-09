#pragma once
#include <array>
#include "Vector2D.h"
#include "Matrix33.h"
#include "Battery.h"

class Tank
{
public:
	Tank( double width, double lenght );
	virtual ~Tank();
public:
	void Forward( const double power );
	void Rotate(const double& radian);
	Vector2D GetPos() const;
	void AddBattery( Battery *bat );
	void debuglog();
private:
	void SetPos(const Vector2D& sPos);
	void SetSidePos();
private:
	Vector2D pos;
	std::array<Vector2D, 4> point;
	double angle;
	Battery* battery;
private:
	double WIDTH;
	double LENGHT;
	double RIGHT;
	double LEFT;
	double FRONT;
	double BACK;
};

