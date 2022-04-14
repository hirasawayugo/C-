#pragma once
#include "Visitor.h"
#include "ShopBase.h"

class Police : public Visitor
{
public:
	Police();
	virtual ~Police();
public:
	virtual void visit(ShopBase& shop);
};

