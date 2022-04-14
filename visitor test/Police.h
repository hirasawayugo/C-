#pragma once
#include "Visitor.h"

class Police : public Visitor
{
public:
	Police();
	virtual ~Police();
public:
	virtual void visit(Bakery& bakery);
	virtual void visit(Postoffice& postoffice);
};

