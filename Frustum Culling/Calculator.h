#pragma once

class Calculator
{
public:
	Calculator();
	virtual ~Calculator();
public:
public:
	double Besier(const double& start, const double& end, const double& blend);
	double Lerp(const double& start, const double& end, const double& blend);
	double Radians(double degree);
	double Degrees(double radian);
private:
	const double PI = 3.14;
};

