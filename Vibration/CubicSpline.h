#pragma once
#include <vector>
#include <math.h>

using namespace std;

class CubicSpline
{
public:
	CubicSpline(const vector<double> &x);
	virtual ~CubicSpline();
private:
	void InitParameter(const vector<double> &x);
public:
	void ResetParameter(const vector<double>& x);
public:
	double Calc(double t);
	
private:
	vector<double> a_;
	vector<double> b_;
	vector<double> c_;
	vector<double> d_;
	vector<double> w_;
};

