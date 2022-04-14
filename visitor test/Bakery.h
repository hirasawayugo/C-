#pragma once
#include "ShopBase.h"

class Bakery : public ShopBase
{
public:
	Bakery();
	virtual ~Bakery();
public:
	virtual void accept(Visitor& iVisitor);
};

