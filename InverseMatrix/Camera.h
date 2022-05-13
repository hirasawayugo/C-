#pragma once
#include "BaseNode.h"

class Camera : public BaseNode
{
public:
	Camera();
	virtual ~Camera();
public:
	bool inversion;

};

