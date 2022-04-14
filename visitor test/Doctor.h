#pragma once
#include "Visitor.h"
#include "ShopBase.h"

class Doctor : public Visitor
{
public:
	Doctor();
	virtual ~Doctor();
public:
	virtual void visit(ShopBase& shop);
};

