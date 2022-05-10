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
	//�O���[�o���̎擾
	Vector2D GetPos();
	double GetAngle();
public:
	void Log();
protected:
	//���[�J�����W
	Vector2D lPos;
	//�O���[�o�����W
	Vector2D gPos;
	//���[�J���p�x
	double lAngle;
	//�O���[�o���p�x
	double gAngle;
	Base* parent;
	std::list<Base*> children;
};