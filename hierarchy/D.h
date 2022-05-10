#pragma once
#include "Base.h"

class D : public Base
{
public:
	D();
	virtual~D();
public:
	void Log()override;
};

