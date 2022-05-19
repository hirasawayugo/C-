#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::SetCamera(Camera* c)
{
	camera = c;
}

Vector2D Object::GetPos()
{
	double angle = camera->GetAngle();
	Vector2D cPos = camera->GetPos();
	Matrix33 mat;
	mat.Rotate(angle);
	cPos = mat * cPos;

	Vector2D pos = Vector2D(lPos.x - cPos.x + 400, lPos.x - cPos.y + 400);
	return Vector2D(pos);
}
