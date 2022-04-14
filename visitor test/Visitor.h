#pragma once
#include "Bakery.h"
#include "Postoffice.h"

class Visitor
{
public:
	Visitor();
	virtual ~Visitor( );
public:
	virtual void visit(Bakery& visitor) {};
	virtual void visit(Postoffice& visitor) {};

};