#include <stdio.h>
#include "Bakery.h"

Bakery::Bakery()
{
}

Bakery::~Bakery()
{
}

void Bakery::accept(Visitor& iVisitor)
{
	printf("いらっしゃいませ\n");
	iVisitor.visit( *this );
}
