#pragma once
#include <vector>
#include "Vector3D.h"
#include "Quaternion.h"

using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
public:
	void Addchild( Object*& object );
	void SetPos(Vector3D vec);
	Vector3D GetPos();
	void Rotate( Vector3D axis, double theta);
	void Slerp(Object* o1, Object* o2, double blend);
protected:
	Vector3D pos;
	Quaternion quat;
	Object* parent;
	vector<Object*> children;
};

