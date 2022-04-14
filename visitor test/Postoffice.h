#pragma once
#include "ShopBase.h"

class Postoffice : public ShopBase
{
public:
	Postoffice();
	virtual ~Postoffice();
public:
	virtual void accept(Visitor& iVisitor);
};

