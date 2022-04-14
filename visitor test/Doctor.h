#pragma once
#include "Visitor.h"

class Doctor : public Visitor
{
public:
	Doctor();
	virtual ~Doctor();
public:
	virtual void visit(Bakery& bakery);
	virtual void visit(Postoffice& postoffice);
};

