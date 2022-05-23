#pragma once
#include "Vector3D.h"
class Liner
{
public:
	Liner();
	virtual ~Liner();
public:
	enum class TYPE {
		STRAIGHT,
		HALF,
		SEGMENT,
	};
public:
	void Execution(const Vector3D& pos1,const Vector3D& pos2, TYPE type);

};

