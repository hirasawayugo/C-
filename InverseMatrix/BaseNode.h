#pragma once
#include <list>
#include "Vector2D.h"
#include "Matrix33.h"

class BaseNode
{
public:
	BaseNode();
	virtual ~BaseNode();
public:
	void AddChild(BaseNode* base );
	void Foward( const Vector2D& vec );
	void Rotate( const double& radian, bool inverse );
public:
	//�O���[�o���̎擾
	Vector2D GetPos();
protected:
	Matrix33 GetMatrix();
public:
	void Log();
protected:
	//���[�J��
	Vector2D lPos;
	double lAngle;

	Matrix33 mat;
	BaseNode* parent;
	std::list<BaseNode*> children;
};