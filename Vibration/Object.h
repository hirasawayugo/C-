#pragma once
#include "Vector2D.h"
#include "Matrix33.h"
#include "Camera.h"

class Object
{
public:
	Object();
	virtual ~Object();
public:
	void SetCamera(Camera* c);
	Vector2D GetPos();
private:
	Vector2D lPos;
	Camera* camera;
};

