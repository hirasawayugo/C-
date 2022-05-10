#pragma once
#include "Base.h"

class C : public Base
{
public:
	C();
	virtual~C();
public:
	void Log()override;
};

