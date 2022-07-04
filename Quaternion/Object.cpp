#include "Object.h"
#include "Matrix3D.h"

Object::Object()
{
	parent = nullptr;
}

Object::~Object()
{
}

void Object::Addchild(Object*& object)
{
	children.push_back(object);
	object->parent = this;
}

void Object::SetPos(Vector3D vec)
{
	pos = vec;
}

Vector3D Object::GetPos()
{
	Vector3D gPos = pos;
	if (parent != nullptr) {
		Matrix3D mat = parent->quat.createMatrix();
		mat.Move(parent->GetPos());
		gPos = mat * gPos;
	}
	return gPos;
}

void Object::Rotate(Vector3D axis, double theta)
{
	Quaternion rQuat;
	rQuat.createQuaternion(axis, theta);
	quat = quat.multiply(rQuat);
}

void Object::Slerp(Object* o1, Object* o2, double blend)
{
	quat = o1->quat.Slerp(o2->quat, blend);
}
