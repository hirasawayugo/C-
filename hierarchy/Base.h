#pragma once
#include <list>
#include "Vector2D.h"

class Base
{
public:
	Base();
	virtual ~Base();
public:
	void AddChild( Base* base );
	void ShowChildren();
	void Foward( const Vector2D& vec );
	void Rotate( const double& radian );
	//グローバルの取得
	Vector2D GetPos();
	double GetAngle();
public:
	void Log();
protected:
	//ローカル座標
	Vector2D lPos;
	//グローバル座標
	Vector2D gPos;
	//ローカル角度
	double lAngle;
	//グローバル角度
	double gAngle;
	Base* parent;
	std::list<Base*> children;
};