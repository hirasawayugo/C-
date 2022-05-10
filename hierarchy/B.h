#pragma once
#include "Base.h"

class B: public Base
{
public:
	B();
	virtual~B();
public:
	void Log()override;
};

