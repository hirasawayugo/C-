#pragma once
#include <list>
#include "Vector2D.h"

class BaseNode
{
public:
	BaseNode();
	virtual ~BaseNode();
public:
	void AddChild(BaseNode* base );
protected:
	void Foward( const Vector2D& vec );
	void Rotate( const double& radian );
public:
	//�O���[�o���̎擾
	Vector2D GetPos();
	double GetAngle();
public:
	void Log();
protected:
	//���[�J��
	Vector2D lPos;
	double lAngle;
	//�O���[�o��
	Vector2D gPos;
	double gAngle;
	BaseNode* parent;
	std::list<BaseNode*> children;
};